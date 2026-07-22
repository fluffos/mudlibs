// Room: /u/xdd/gumu/gmlingwu.c
// Modify by river 98/08/29

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIC"领悟室"NOR);
	set("long", @LONG
此地供各弟子打坐静修之用。地上仅有几个蒲团，几对少男少女正在闭目
领悟。东面石壁上有一方凸起，刻着不少文字(wall), 西面地上有一方凹陷，
刻着些古怪的图形(ground), 顶上有一些美女图形(top)。
LONG
	);

	set("exits", ([
		"south" : __DIR__"gmqt",
	]));

	set("item_desc", ([
		"wall" : HIC "\t内功心法...古墓子弟可研习于此. \n"NOR,
		"ground" : HIC "\t闪转腾挪之术...古墓子弟可研习于此.  \n"NOR,
		"top" : HIC "\t玉女遨游于空,逍遥穿梭,身形百变. \n"NOR,
	]));

	setup();
}

void init()
{
	add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{
	mapping fam;
	object me;
	me = this_player();

	if ( !living(me) ) return 0;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if ((int)me->query_skill("literate", 1) < 10)
		return notify_fail("你斗字不识,领悟个啥? \n");

	if ( arg =="wall" ){
		if ((int)me->query_skill("force", 1) > 50 )
			return notify_fail("石壁所述尽在你心，你无法再悟出什么新东西。\n");
		if ((int)me->query("jing") < 20 )
			return notify_fail("你觉得好累，好想睡觉. \n");
		write("你静心研习石壁的秘籍，对内功心法有些领悟。\n");
		me->receive_damage("jing", 5 + random(15));
		me->improve_skill("force", (int)(me->query_con()/2)+(int)(me->query_skill("literate")/4) );
		return 1;
	}
	if ( arg =="ground" ){
		if ((int)me->query_skill("parry", 1) > 50 )
			return notify_fail("你对着地上研习一会，只觉所述早已尽藏心胸。\n");
		if ((int)me->query("jing") < 20)
			return notify_fail("你一阵晕旋,想是用脑过度,该休息一会了. \n");
		write("你模仿地上的图形上跳下纵,修习招架闪躲。\n");
		me->receive_damage("jing", 5 + random(15));
		me->improve_skill("parry", (int)(me->query_int()/2)+(int)(me->query_skill("parry")/ 4 ));
		return 1;
	}
	if ( arg =="top" ){
		message_vision(HIY"$N开始仰视顶上美女图形。\n"NOR, me);
		if ((int)me->query_skill("force", 1) < 10){
			message_vision(HIM"$N看着美女图形开始气血上涌, 目光直勾勾,竟出现猥亵之意. \n"NOR, me);
			write(HIR"你定力不够,这样的图画还是少看为妙. \n"NOR);
			message_vision(HIR"$N忽然摇晃起来,蓦地喷出口鲜血. \n"NOR, me);
			me->receive_wound("qi", 10);
			me->unconcious();
			return 1;
		}
		if ((int)me->query_skill("dodge", 1) < 10 )
			return notify_fail("你虽能平心审视这些裸女图,却不解其中奥妙所在. \n");
		if ((int)me->query_skill("yunu-shenfa", 1) >= 1)
			return notify_fail("你已学会了玉女身法，要更上一步，只能靠自己勤加练习. \n");
		write(HIY"你静心研习顶上的美女身形，领悟到古墓派轻功身法的精髓所在,顿时茅塞顿开。\n"NOR);
		me->improve_skill("yunu-shenfa", 10);
		write(HIR"恭喜，这位" + RANK_D->query_respect(me)+"，你已经学会玉女穿梭功了。\n"NOR);
		return 1;
	}
	return 0;
}
