// Room: sroad5.c

inherit ROOM;  
#include <ansi.h> 
int pick(string);

void create()
{
        set("short","山路");
        set("long",@LONG
越往上走，寒气愈甚，霜雪漫天纷纷而下。极目远望，只见
满天雪白，万物晶莹。不远处似乎有个湖泊，山泉瀑布奔腾入湖，
绿树丛中馥郁的鲜花争妍斗艳，让你不由得加快脚步。路旁结满
了一条条冰柱（ice），倒垂而下，锋利尖锐，有时凌霄弟子练剑
之时也将其作为兵器使用。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "southdown"  : __DIR__"sroad4",
            "north"  : __DIR__"sroad6",
        ]));
        set("item_desc", ([
            "ice" : "这是一条晶莹剔透的冰柱，你可以试着扳(pick)下来看看。\n",
        ]) );
         set("objects", ([
              __DIR__"npc/shipopo" : random(2),
         ]));

        set("no_clean_up", 0);
	set("ice_count", 5);
        setup();
} 

void init()
{
 add_action("do_pick","pick");
}

void reset_ice()
{
	set("ice_count", 5);
	delete("ice_call_out");
}
int do_pick(string arg)
{
	object me = this_player();

	if (arg == "ice") {
		if (query("ice_count")) {
			message_vision(HIW"$N小心翼翼地从路旁的树上扳了一条冰柱下来。\n"NOR, me);
			add("ice_count", -1);
			new(__DIR__"obj/ice")->move(me);
			return 1;
		}
		else {
			if (!query("ice_call_out")) {
				remove_call_out("reset_ice");
				set("ice_call_out", 1);
				call_out("reset_ice", 600);
			}
			return notify_fail("冰柱已经被扳完了。\n");
		}
	}
	return 0;
}