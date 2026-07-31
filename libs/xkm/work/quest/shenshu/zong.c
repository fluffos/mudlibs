#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("萧秋水传奇"NOR, ({ "book" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha()
{
	object me;
	int exp,pot,score,i;
	me =this_player();
	exp = 3000+random(1000);
	             pot = exp/7;
             score = random(50)+20;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
		i=random(6);
	     message_vision("$N仔细地查阅了一遍"+this_object()->query("name")+"。\n"NOR, me);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
	if (i>4) {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
	}
	else if (i>3) {
	me->add("dex",1);tell_object(me,HIM"以及一点身法。\n"NOR);
	}
	else if(i>2)	{
	me->add("str",1);tell_object(me,HIC"以及一点臂力。\n"NOR);
	}
	else if(i>1)	{
	me->add("int",1);tell_object(me,HIR"以及一点悟性。\n"NOR);
	}
	else if(i>0)	{
	me->add("con",1);tell_object(me,HIM"以及一点根骨。\n"NOR);
	}
	else {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
	}
	destruct(this_object());
return 1;
}
