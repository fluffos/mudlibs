inherit "/std/board/bboard";

#include "../central.h"
#include <config.h>

#define PATH "/d/Prime/data"

void create()
{
    seteuid(getuid());
    bboard::create();
    set_attic_dir(PATH+"/attic");
    set_save_dir(PATH);
    set_save_file("player");
    set_location(START);
    set ("short.text", "The Player Board");
}
