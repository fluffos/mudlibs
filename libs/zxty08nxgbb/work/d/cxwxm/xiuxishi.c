// marry 8,14
inherit ROOM;
#include <ansi.h>


void create()
{
    set("short",HIC"休息室"NOR);
    set("long", 
"这是专供弟子休息的大屋。屋里放着一大排床，挤挤地占掉了屋子的一大半\n"
"地方。屋角很整齐地放了一些日常生活用具。中央放着几张桌子，上面摆着麻将\n"
"和围棋供弟子们娱乐。\n\n"
);
set("exits", ([
    "north"  : __DIR__"dayuan",
]));
    
       set("sleep_room","1") ;
        set("no_fight", "1");
        set("no_steal", "1");
    setup();
    replace_program(ROOM);
}
