#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "兽王寝宫");
    set("long", @LONG
这里是兽族的总统领---"神兽王"休息的地方,只有神兽王和其爱将
才能入内休息.这里放着几张舒适的大床,在柔和的烛光下,你的睡意
倍增.
LONG );
        set("exits", ([                 
           "east" : __DIR__"shouwangdian",
         ]));
        set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
       set("no_clean_up", 0);
       setup();       
       replace_program(ROOM);
}
