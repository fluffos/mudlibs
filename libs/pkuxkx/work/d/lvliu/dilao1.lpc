#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;

int do_perform(string arg);
int do_usearm(string arg);
int do_disusearm(string arg);

void create()
{
	set("short", HIY"五行牢狱·金牢"NOR);
	set("long",HIY"一间阴暗的地牢。四周石壁上突出许多锋锐的利刃，在这里举止行
动都要万分小心，稍不留神就会被墙上的利刃划伤。靠墙的角落里散落
着许多机关零件，有些铁皮，还有一些完整的机械臂(arms)。\n"NOR);
	set("exits", ([
	  "east" : __DIR__"path1",
	]));
	set("item_desc", ([
		"east" : "前面黑乎乎的，啥也看不见。\n",
		"arms" : HIW"地上散落着一些机械手臂，你忽然灵机一动：或许可以把它们装备起来(use arms)？\n"NOR,
	]));
	set("robot_components", 2);
	set("no_sleep_room",1);
	setup();
}

void init()
{
	object me = this_player();
	object npc, here = this_object();

	add_action("do_perform", "perform");
	add_action("do_usearm", "use");
	add_action("do_disusearm", "disuse");

	if (!objectp(me) || !userp(me)) return;
	npc = present("jiguan ren", here);
	if (!objectp(npc) || userp(npc))
	{
		npc=new(__DIR__"npc/jiguanren1");
		if (objectp(npc))
		{
			npc->move(here);
			message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
		}
		return;
	}
	message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
}

int do_usearm(string arg)
{
	int level;
	object me = this_player();
	object here = this_object();
	mapping map = me->query_skill_map();
	if (!arg || arg!="arms")
		return notify_fail("你要使用什么？\n");
	if (me->query_temp("lvliu_use_arms"))
		return notify_fail("你已经装备上机械臂了！\n");
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空去翻找机械臂！\n");
	if ((int)here->query("robot_components")<1)
		return notify_fail(HIY"你在墙角翻了翻，发现没有合用的机械臂，只好失望地站了起来！\n"NOR);
	here->add("robot_components", -1);
	message_vision(HIG"$N从地上捡起一些机械臂试了试，正好可以装备在自己手臂上！\n"NOR, me);
	tell_object(me, HIC"你获得了临时技能「钢拳铁臂」！\n"NOR);
	tell_object(me, HIG"现在你也能够用机械臂了，放胆子进攻吧！\n"NOR);
	me->set_temp("lvliu_use_arms", 1);
	level = to_int(ceil( pow( (int)me->query("combat_exp")*10, 1.0/3) ));
	if (level<50) level=50;
	me->set_temp("apply_skills/gangquan-tiebi", level);
	me->set_temp("apply_skills/unarmed", level-(int)me->query_skill("unarmed",1));
	if (undefinedp(map["unarmed"]))
		me->map_skill("unarmed", "gangquan-tiebi");
	return 1;
}

int do_disusearm(string arg)
{
	object me = this_player();
	if (!arg || arg!="arms")
		return notify_fail("你要废弃什么？\n");
	if (!me->query_temp("lvliu_use_arms"))
		return notify_fail("你根本没有装备机械臂，别瞎折腾了！\n");
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空拆卸机械臂！\n");
	me->delete_temp("lvliu_use_arms");
	message_vision(HIG"$N费劲地把手臂上的机械臂拆了下来，零件散落了一地！\n"NOR, me);
	me->delete_temp_skill("gangquan-tiebi");
	me->delete_temp_skill("unarmed");
	return 1;
}

int do_perform(string arg)
{
	object me = this_player();
	if (arg && arg != "")
	{
		if (me->is_busy()) return 0;
		message_vision(HIR"$N小心翼翼地试图施展特殊攻击，还是被墙上突出的利刃划了一下手臂，飞溅出一丛血花。\n"NOR, me);
		me->receive_wound("qi", me->query("max_qi")/20, "被地牢利刃割伤");
        COMBAT_D->report_status(me);
	}
	return 0;
}

int valid_leave(object me, string dir)
{
    if ( objectp(present("jiguan ren", environment(me))))
        return notify_fail("机关人巨大的身躯挡住了出口，在把它解决掉之前你根本出不去。\n");
	if (me->query_temp("lvliu_use_arms"))
		return notify_fail(HIY"你装备的机械臂太大了，会卡在出口的，要先拆下来(disuse arms)才能出得去。\n"NOR);
    return ::valid_leave(me, dir);
}

