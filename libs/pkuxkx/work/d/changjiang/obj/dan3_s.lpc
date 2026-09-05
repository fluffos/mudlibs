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
	set_name(HIW"燕青拳心法"NOR, ({ "yanqing xinfa","xinfa","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本燕青拳的心法，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    
    if (me->query_skill("yanqing-quan",1)<200)
    {
        tell_object(me,"你的燕青拳造诣太低，无法通读心法。\n");
        return 1;
    }
    if (me->query("yanqing"))
    {
        tell_object(me,"你已经掌握了燕青拳的精义。\n");
        return 1;
    }
	if (me->query("tqt/freetrial"))
	{
		tell_object(me,"你已经在体验一种铜雀台武功了！\n");
		return 1;
	}
	me->set("tqt/freetrial",1);//1是mark,2是skills
	me->set("tqt/free_trial","yanqing");
	me->apply_condition("tqt_freetrial",200);
	tell_object(me,BLINK+HIR+"在体验铜雀台武功的期间，请不用使用铜雀台积分正式换购此项武功，否则可能导致新武功失效，积分被浪费！\n"+NOR);
    message_vision(YEL"$N开始认真研读$n"+YEL+"，对燕青拳的理解更进一层，施展起来再无困惑！\n"NOR, me,this_object());
    me->set("yanqing",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}