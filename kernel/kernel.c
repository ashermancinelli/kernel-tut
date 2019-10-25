
#include "../drivers/VGA/port.h"
#include "../drivers/screen.h"
#include "util.h"

void main() {
    clear_screen();
    kprint("Welcome to Aos\n");
    kprint("> ");
}
