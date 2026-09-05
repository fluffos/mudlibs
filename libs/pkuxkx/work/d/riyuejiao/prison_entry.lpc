//yading.c	黑木崖顶
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_map();
void create()
{
	set("short","监狱入口");
	set("long",@LONG 
这是一座修在悬崖峭壁上的监狱，用来拷问各色混入黑木崖的奸细。几个狱
卒正在喝酒法呆。墙角堆了许多食盒(he)，墙上挂着一幅监狱地图(map)。
LONG
	);
	set("exits", ([
		//"east"	: __DIR__"wanghaishi",
		//"west"	: __DIR__"xiuxishi",
		"north"	: __DIR__"yading",
        "south" : __DIR__"guodao1",
	]));
    set("no_task",1);
	set("objects", ([
                __DIR__"npc/yuzu": 1,
        ]));
	set("item_desc",([
  	"map" : (:look_map:),
    "he" : "一堆食盒，准备发放给狱中的囚犯。你可以把它拿(na)起来。\n",
  ]));
	
	setup();
}

void init()
{
    add_action("do_na","na");
}

int do_na()
{
    object me=this_player();
    object fan;
    if (me->query("family/family_name")!="日月神教")
    {
        tell_object(me,"那么想吃囚饭？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/start")!=1)
    {
        tell_object(me,"狱卒没让你去送饭啊？\n");
        return 1;
    }
    fan=new(__DIR__"obj/shihe");
    fan->move(me);
    message_vision("$N拿起一个"+fan->name()+"。\n",me);
    return 1;
}

string look_map()
{
    string msg;
    msg=HIW"   黑木崖监狱总图\n\n"NOR;
    msg+="       子││丑\n";
    msg+=" 辰 午   ││   申 戌\n";
    msg+="──── ┘└ ────\n";
    msg+="──── ┐┌ ────\n";
    msg+=" 巳 未   ││   酉 亥\n";
    msg+="       寅││卯\n";
    return msg;
}

int valid_leave(object me,string dir)
{
    if (me->query("cantleave"))
    {
        return notify_fail("不许离开！\n");
    }
    return ::valid_leave(me,dir);
}