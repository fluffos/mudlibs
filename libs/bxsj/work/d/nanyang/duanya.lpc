// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断崖");
	set("long", @LONG
前面是一处十分陡峭的断崖，险峻异常，难以爬越(pa)。这里离黄河不远，
黄河流淌到这里，河床宽阔。黄色的河水在静静地向东流去，使人忘记它发洪
水时的狂威。
LONG
	);
	set("outdoors", "黄河");
	set("exits", ([
		"north" : __DIR__"yidao4",
	]));
	setup();
}

void init()
{
	add_action("do_pa", ({ "climb", "pa" }));
}

int do_pa(string arg)
{
	object me;
	object *inv;

	me = this_player();

	if ( !arg ) return 0;
	if (arg != "ya" && arg!="up")
		return notify_fail("你要往那里爬？\n");

	if (!living(me)) return 0;

	inv = filter_array(deep_inventory(me), (: userp :));
	if (sizeof(inv) || !me->query_temp("gb_job2")) {
		message_vision("$N气喘嘘嘘，感到无法爬上去，摔了下来！\n", me);
		me->set_temp("last_damage_from", "从断崖上掉下来摔");
		me->receive_wound("qi", 50+random(50));
		return 1;
	}
	if (me->query_skill("dodge",1) < 80){
		message_vision(HIR"$N想要爬上山顶，无奈轻功不够，摔了下来！\n"NOR, me);
		me->set_temp("last_damage_from", "从断崖上掉下来摔");
		me->receive_wound("qi", 50+random(50));
		return 1;
	}
	message_vision("$N扒住突出的岩石，施展轻功爬了上去。\n", me);
	me->move("/d/gb/yading");
	tell_room(environment(me), me->name() + "从下面爬了上来。\n", ({ me }));
	return 1;
}
