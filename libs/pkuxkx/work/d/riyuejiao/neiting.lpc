// neiting.c	休息室
// by bing

inherit ROOM;
#include <ansi.h>
#include "/d/riyuejiao/bonus.h"

string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
        
});


void create()
{
	set("short", "内厅");
	set("long", 
@LONG  
这是白虎堂所设的日月神教弟子的休息室。屋里摆着几张
大床，桌上放着一些食物。已经有一些弟子睡了，你移动的时
侯最好轻点，别把他们吵醒了。
LONG
	);
	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"baihutang",
        "east" : __DIR__"chufang",
	]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
    set("bonus",31);
	setup();
	set("no_fight",1);
}

void init()
{
    add_action("do_duan","duan");
}

int do_duan()
{
    int i;
    object me=this_player();
    object * all=all_inventory(me);
    object shi;
    for (i=0;i<sizeof(all) ;i++ )
    {
        if (all[i]->query("owner")==me->query("id")&&
            me->query_temp("rynewbiejob/chufang/shicai")&&all[i]->query("shicai")&&
            me->query_temp("rynewbiejob/chufang/shicai")==all[i]->query("shicai"))
        {
            shi=all[i];
        }
    }
    if (!shi)
    {
        tell_object(me,"你要干嘛？\n");
        return 1;
    }
    
    message_vision("$N端上一盘"+shi->name()+"香气四溢，大家垂涎欲滴。\n",me);
    shi->delete("owner");
    shi->delete("shicai");
    shi->move(this_object());
    me->delete("rynewbiejob/chufang/start");
    bonus(me);
    return 1;
}