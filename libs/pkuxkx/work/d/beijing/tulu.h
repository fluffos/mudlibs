//ROOM: tulu.h
#include <ansi.h>
void create()
{
        set("short", YEL"土路"NOR);
        set("long", TULU_DESC_LONG);

        set("outdoors", "beijing");
        set("exits", TULU_EXITS);

        setup();
        replace_program(ROOM);
}
