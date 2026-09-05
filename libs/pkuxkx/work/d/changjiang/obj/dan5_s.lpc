// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_yanjiu", "yue");
	add_action("do_yanjiu", "du");
	add_action("do_yanjiu", "fan");
	add_action("do_yanjiu", "yanjiu");
}

void create()
{
	set_name(CYN"六十四路轰天雷震挡法"NOR, ({ "leizhendang miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本六十四路轰天雷震挡法的练法，塞北白家堡的家传武学，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    int exp=me->query("combat_exp");
	int level=to_int(pow(exp/100,0.333)*10);
    if (me->query_skill("leizhendang"))
    {
        tell_object(me,"你已经掌握了轰天雷震挡法的练法，入门之后要靠自己了。\n");
        return 1;
    }
    if (me->query("tqt/freetrial"))
	{
		tell_object(me,"你已经在体验一种铜雀台武功了！\n");
		return 1;
	}
	me->set("tqt/freetrial",2);//1是mark,2是skills
	me->set("tqt/free_trial","leizhendang");
	me->apply_condition("tqt_freetrial",200);
	tell_object(me,BLINK+HIR+"在体验铜雀台武功的期间，请不用使用铜雀台积分正式换购此项武功，否则可能导致新武功失效，积分被浪费！\n"+NOR);
    message_vision(CYN"$N"+CYN+"开始认真研读$n"+CYN+"，掌握了轰天雷震挡法的基本招式！\n"NOR, me,this_object());
    me->set_skill("leizhendang",level);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}