
#include "../drivers/port.h"
#include "../drivers/screen.h"

void main() {
//     char* video_memory = (char*) 0xb8000;
//     *video_memory = 'G';
    clear_screen();
    kprint_at("X", 5, 5);
    kprint_at("X", 15, 15);
}
