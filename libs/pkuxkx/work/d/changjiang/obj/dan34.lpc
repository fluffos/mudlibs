// yhzzyahoo @2015.7.26 ,铜雀台
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
	set_name(HIG"辟邪剑法-突刺篇"NOR, ({ "tuci pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是辟邪剑法某个绝招的注解，可以加深你对这个绝招的理解。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本主角，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query("safari_skill/riyue_tuci"))
    {
        tell_object(me,"你不是已经学会了这个绝招的真正奥秘吗？\n");
        return 1;
    }
    if ((int)me->query_skill("kuihua-shengong",1)<500)
    {
        tell_object(me,"你的葵花神功境界太浅，这本注解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了这个绝招的真正奥秘！\n"NOR, me,this_object());
    me->set("safari_skill/riyue_tuci",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}