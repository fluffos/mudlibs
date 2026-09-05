#include <ansi.h>
inherit ROOM;
void init();
int do_zou(string);
void create()
{
	set("short", "百丈涧");
	set("long", @LONG
山道到此突然消失，在你面前是一条山涧，山涧之中云雾缭绕，你根本
无法看清对面。一条铁索(tiesuo)深入云中，旁边有一块石碑(bei)。
LONG);
	set("outdoors", "lingjiu");
	set("exits", ([
		"southdown":__DIR__"ya",
	]));

	set("objects", ([
		CLASS_D("lingjiu") + "/yupopo":1,
		"/d/lingjiu/npc/dizi" : 2,
	]));
	set("item_desc", ([
		"bei":HIR"『灵鹫宫』重地,非灵鹫宫弟子不得入内！\n"NOR,
		"tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me = this_player(), room;
	if (((string)me->query("family/family_name") != "灵鹫宫")
		&& (objectp(present("yupopo", environment(me)))))
		return notify_fail
		("余婆婆伸手拦住你，说道：“你不是灵鹫宫弟子，不能进入灵鹫宫，请回！”\n");
	if (me->query_skill("dodge") < 50)
		return notify_fail("你的轻功太差,这铁索如何走的过去?\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if (!arg || arg != "tiesuo")
		return notify_fail("你要走什么？\n");
	if (!(room = find_object(__DIR__"jietianqiao")))
		room = load_object(__DIR__"jietianqiao");
	message_vision("$N踩上铁索，向山涧的对面飘然而去。\n", me);

	me->move(room);
	me->set_temp("tiesuo_1", 1);
	return 1;
}