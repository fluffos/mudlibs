//Room: lgfang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"练功房"NOR);
	set("long", @LONG
这是一间用花岗岩砌成的石屋。室内一个大炉中燃了木炭，煮着热气腾腾
的一镬东西，镬旁有两个黑衣小童，一个在使劲地推拉着风箱，另一个在用铁
铲翻炒镬中之物，听这沙沙之声，所炒的似是铁沙。几名帮中弟子闭目盘膝坐
在锅前，或对着腾上的热气吐呐，或插指于镬中苦练。
LONG
	);
	set("exits", ([
		"east" : __DIR__"guangchang",
	]));
	set("item_desc", ([
		"huo" : "这是一口巨大的铁锅，锅中盛满铁沙，下面燃着炭火，是帮主练铁掌用的。\n",
	]));
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}

int do_chazhi(string arg)
{
	object me = this_player();

	if (!living(me)) return 0;
	if (!living(this_player()) || arg != "huo" ){
		write("你想往哪儿插?\n");
		return 1;
	}
	if (me->query("family/family_name") != "铁掌帮")
		return notify_fail("你非本帮弟子，不能在此练功！\n");
	if ((int)me->query_skill("strike", 1) < 30) {
		write("你将双手插入镬中，显然，你受不了这铁沙的温度。\n");
		write("你觉得一股热气直逼上来，焦燥难当！\n");
		me->unconcious();
		return 1;
	}
	if ((int)me->query_skill("strike", 1) > 120)
		return notify_fail("你将双手插入镬中，发现铁沙的温度对你来说太低，已毫无意义了。\n");
	if ((int)me->query("qi") < 40){
		me->receive_damage("qi",10);
		write("你觉得一股热气直逼上来，焦燥难当！\n");
		me->unconcious();
          	return 1;
	}
	me->receive_damage("qi", 20+ random(20));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N将双手反复插进镬中的铁沙里。\n", me);
	if (random(2)) write("灼热的铁沙将你的双手烫得通红，你觉得双手变得强壮有力。\n");
	return 1;
}
