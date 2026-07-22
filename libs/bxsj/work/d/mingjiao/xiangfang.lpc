// xiangfang.c 厢房
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"厢房"NOR);
        set("long", @LONG
这里是专门供外来的宾客休息的地方，里面有几张床和一些生活用品，十
分干净舒适。
LONG);
        set("exits", ([
                "west" : __DIR__"tingtang",
        ]));    
        set("no_fight", 1);
        set("sleep_room", 1);
        set("mj_xl", "yin2");
        setup();
}

void init()
{
	object me = this_player();
	string arg = this_object()->query("mj_xl");
	if(me->query_temp("mj/xunluo")
           && !me->query_temp(arg)
           && me->query_temp("tearoom")
           && me->query_temp("shanyao")
           && me->query_temp("mj/xunluo") == 7){
              me->add_temp(arg,1);
              me->delete_temp("tearoom");
              me->delete_temp("shanyao");
	}
	if ( userp(me))
	 	me->start_busy(1);
}
