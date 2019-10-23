
#include "VGA/port.h"
#include "screen.h"
#include "../kernel/util.h"

int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char c, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);

void kprint_at(char* msg, int c, int r)
{
    int offset;
    if ( c >= 0 && r >= 0 )
        offset = get_offset(c, r);
    else {
        offset = get_cursor_offset();
        r = get_offset_row(r);
        c = get_offset_col(c);
    }

    int i = 0;
    while (msg[i] != 0) {
        offset = print_char(msg[i++], c, r, WHITE_ON_BLACK);
        r = get_offset_row(offset);
        c = get_offset_col(offset);
    }
}

void kprint(char* msg)
{
    kprint_at(msg, -1, -1);
}

int print_char (char c, int col, int row, char attr)
{
    unsigned char* vidmem = (unsigned char*) VIDEO_ADDRESS;
    if (!attr) attr = WHITE_ON_BLACK;

    int offset;
    if ( col >= 0 && row >= 0 ) offset = get_offset(col, row);
    else                        offset = get_cursor_offset();

    if (c == '\n') {
        row = get_offset_row(offset);
        offset = get_offset(0, row+1);
    } else {
        vidmem[offset] = c;
        vidmem[offset + 1] = attr;
        offset += 2;
    }

    /*
     * Scroll if goes past screen length
     */
    if (offset > MAX_ROWS*MAX_COLS*2)
    {
        int i;
        for (i = 1; i < MAX_ROWS; i++)
            _memcpy(get_offset(0, i)   + VIDEO_ADDRESS,
                    get_offset(0, i-1) + VIDEO_ADDRESS,
                    MAX_COLS*2);

        char* last_line = get_offset(0, MAX_ROWS-1) + VIDEO_ADDRESS;
        for (i = 0; i < MAX_COLS; i++)
            last_line[0] = 0;

        offset -= 2*MAX_COLS;
    }

    set_cursor_offset(offset);
    return offset;
}

int get_cursor_offset()
{
    /*
     * querying VGA ports for current cursor pos
     *
     * high byte for cursor offset: data 14
     * low byte for cursor offset:  data 15
     */

    // Query data 14 
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA);

    // Get high byte
    offset = offset << 8;

    // Query data 15
    port_byte_out(REG_SCREEN_CTRL, 15);
    // set lower byte
    offset += port_byte_in(REG_SCREEN_DATA);

    /*
     * offset gets calculated position
     * multiplied by size of visual character cell
     */
    return offset*2;
}

void set_cursor_offset(int offset)
{
    /*
     * Same as getting cursor object
     * but instead of querying data
     * we set data
     */
    offset /= 2;

    port_byte_out(REG_SCREEN_CTRL, 14);
                                                // only grab the upper
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
                                                // only grab the lower
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

void clear_screen()
{
    char* screen = VIDEO_ADDRESS;

    int i;
    for (i = 0; i < (MAX_ROWS * MAX_COLS); i++)
    {
        screen[i*2]     = ' ';
        screen[i*2 + 1] = WHITE_ON_BLACK;
    }

    set_cursor_offset(get_offset(0, 0));
}

int get_offset(int col, int row)    { return 2 * (row * MAX_COLS + col);    }
int get_offset_row(int offset)      { return offset / (2*MAX_COLS);         }
int get_offset_col(int offset)      
{ return (offset - (get_offset_row(offset)*2*MAX_COLS))/2; }
