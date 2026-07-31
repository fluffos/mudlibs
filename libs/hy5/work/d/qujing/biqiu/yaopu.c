inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","马王药庄" );
        set ("long", @LONG



　　妙～～～～～手～～～～～回～～～～～春



LONG);


        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "south" : __DIR__"jie3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
           "/d/qujing/biqiu/npc/yaopuboss" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
