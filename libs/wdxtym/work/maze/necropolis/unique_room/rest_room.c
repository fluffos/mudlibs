#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIB"残注"NOR);
        set("long", @LONG
残注��
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
        
        set("objects",([
                "/maze/necropolis/obj/coffin2":1,
        ]));
        setup();
        // replace_program(ROOM);
}
