
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "甬道");
	set ("long", @LONG

   这是一条长长的甬道，两旁点着油灯，光线虽暗，却也可辨
道路。甬道依着山腹中天然洞穴修凿而成，人工开凿处甚是狭
窄，有时却豁然开阔，只觉渐行渐低，山洞中支路开始多起来。
LONG);

 	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"yongdao5",
		"westdown":__DIR__"yongdao6",
		"southup" : __DIR__"yongdao3",
	]));

  setup();
}
void init()
{
 object me;
me=this_player();
    set("caneast",0);
if(random(me->query("kar")) > 10) {write(HIW"你突然听到东面隐隐约约的传来水声，不禁驻足倾听。\n你突然发现东面(east)有一个山窟！\n"NOR,me);me->start_busy(5);set("caneast",1);}
        add_action("do_east", "e");
        add_action("do_east", "east");
}
int do_east(string arg)
{
	object me;
	object room;
//     if(!query("caneast")) return 1;
	me = this_player();
        message_vision("$N从东面的一处山窟钻了进去。\n", me);

	room = load_object(__DIR__"firehole");
	if(room) me->move(room);
	
	return 1;
}

