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
	set_name(HIG"大智无定指谱"NOR, ({ "dazhi zhipu","zhipu","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本大智无定指的指谱，少林失传武学，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (me->query("tqt_sl_skill1"))
    {
        tell_object(me,"你不是已经掌握了『大智无定指』吗？\n");
        return 1;
    }
    if ((int)me->query_skill("yizhi-chan")<100)
    {
        tell_object(me,"你的一指禅功夫太浅，大智无定指对于你过于艰难了。\n");
        return 1;
    }
    if (me->query("tqt/freetrial"))
	{
		tell_object(me,"你已经在体验一种铜雀台武功了！\n");
		return 1;
	}
	me->set("tqt/freetrial",1);//1是mark,2是skills
	me->set("tqt/free_trial","tqt_sl_skill1");
	me->apply_condition("tqt_freetrial",200);
	tell_object(me,BLINK+HIR+"在体验铜雀台武功的期间，请不用使用铜雀台积分正式换购此项武功，否则可能导致新武功失效，积分被浪费！\n"+NOR);
    message_vision("$N开始认真研读$n，掌握了『大智无定指』的运功方法！\n"NOR, me,this_object());
    me->set("tqt_sl_skill1",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}