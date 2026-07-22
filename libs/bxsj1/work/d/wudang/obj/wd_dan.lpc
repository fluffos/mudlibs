// OBJ : /u/lius/obj/wd_dan.c 试炼新丹
// By lius 99/9

#include <ansi.h>
inherit ITEM;

string *eat_msg = ({
HIG"\n丹丸入口即化，如饮琼浆，$N但觉一股真源由丹田而起，遍行奇经八脉，一身功力大增！\n" NOR,
HIM"\n$N吃下一颗丹丸，但觉一阴一阳两股气劲分由任督二脉缓缓上行，聚于头顶百汇大穴，\n"+
   "$N忙以自身纯正紫气相引，终于收归丹田，功力巨增！\n" NOR,
HIC"\n丹丸入肚，$N顿觉剧痛无比，浑身血脉膨胀，四肢百骸充盈欲裂，$N忙以自身内力相抗。\n"+
   "良久，但觉气息如丝，真力源源不断，功力提升不少！\n"NOR,
});

string *clr = ({RED"",GRN"",YEL"",BLU"",MAG"",CYN"",WHT"",HIR"",HIG"",HIY"",HIB"",HIM"",HIC"",HIW""});

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( (clr[random(sizeof(clr))])+ "试炼丹药" NOR, ({"wudang danyao","dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗武当炼制的丹丸，据说功能通神，返老还童。\n");
                set("value", 1000);
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西你拿不了。\n");
                set("no_give", "这样东西不可随便给人。\n");
                set("no_put", "这样东西不能放在这种东西里面。\n");
        }
        setup();
}

int do_eat(string arg)
{
	int j,z;
	string msg;
	object me = this_player();        
	
	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if(query("owner") != me->query("id"))
		return notify_fail("你从那里得来的丹药？\n");

	z = random(10) + 1;
	if ( z && me->query("combat_exp") < 2000000) {
		msg = eat_msg[random(sizeof(eat_msg))];
		j = 200 + random(100);
		message_vision(msg, me);
		me->add("combat_exp",j);
		log_file("job/liandan",sprintf("%8s%-10s武当炼丹获得了%3d点经验，现经验：%d。\n",
			me->name(),"("+me->query("id")+")",j, me->query("combat_exp")), me);
		destruct(this_object());
		return 1;
	}
	else {
		message_vision(YEL"$N服下一颗丹丸,但觉药性平平，无甚损益。\n"NOR,me);
		me->add("combat_exp",-(random(20)+10));
		destruct(this_object());
		return 1;
        }
        return 1;
}
