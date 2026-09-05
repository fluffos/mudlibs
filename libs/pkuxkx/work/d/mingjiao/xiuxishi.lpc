//ROOM : xiuxishi.c
//by yuer
//last edit by black,禁止打架，偷盗
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", WHT "休息室" NOR);
        set("long", @LONG
这里是明教弟子起居的地方。靠墙一溜摆着几张木床，床
上铺的是棉被。使人一看就想睡觉。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                  "south" : __DIR__"zoulang1",
        ]));
        
    set("no_fight",1);
    set("no_steal",1);
	set("hsz_no_task",1);
        setup();
        replace_program(ROOM);
}

