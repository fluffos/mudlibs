// D:\xkx\d\liuxiu-shanzhuang\wxiangfang.c西厢房
// labaz  2012/10/22
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_sleep();
void wake_up(object);

void create()
{
    set("short", "西厢房");
    set("long", 
"这是柳秀山庄招待男客的厢房。房中有一张小床"+YEL"(bed)"NOR+"，锦被玉枕
都是崭新的。床旁边是一红木的五斗橱，橱里放了一些生活用具。五斗橱
旁是面铜镜，可以让你正衣冠。铜镜前方的方桌上有个翡翠的沉香炉，里
面檀香冉冉，飘向窗外。窗台放了文竹的盆景。厢房的风格和别处一样，
并不奢华，却处处透着风雅。\n"
);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "bed":HIY"这是一张小床，你可以在上面安心睡个好觉。"+HBBLU+WHT"(sleep)\n"NOR,
        ]));

    set("exits", ([
        "east" : __DIR__"zhengting",
        "north" : __DIR__"nanyushi",
        ])
     );

	set("no_fight",1);
	set("no_get",1);
	set("no_put",1);
	set("sleep_room",1);
    setup();
}

void init()
{
    add_action("do_sleep","sleep");
	add_action("show_quest", "quest");
}

int do_sleep()
{
    object who;
    string failmsg;
    who=this_player();
    
    if (0==call_other("/cmds/std/sleep","main",who))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(who,failmsg);
            return 1;
        }
    }
    
    // who->apply_condition("sleep",random(2));
    
    if ((1==check_questindex(who,"回到厢房睡一觉补充体力")) && (!living(who)))
    {
        call_out("wake_up",1,who);
    }
    return 1;
}

void wake_up(object who)
{
	if (!objectp(who)) return;
    if (!living(who))
    {
        call_out("wake_up",1,who);
        return;
    }
    set_nextquest(who, "回到厢房睡一觉补充体力", "你气色恢复，虽然被武师打败了，仍有闯荡江湖，行侠仗义的雄心。\n去正厅找庄主，问问他有关“闯荡江湖”的事。", 20, 100);
}
