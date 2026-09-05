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
	set_name(HIG"奇门八卦阵-布阵"NOR, ({ "buzhen pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是奇门八卦阵布阵的方法，乃黄药师在奇门八卦方面一生的心血。\n");
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
    if (me->query("safari_skill/thd_buzhen"))
    {
        tell_object(me,"你不是已经学会了奇门八卦阵的布阵方法了么？\n");
        return 1;
    }
    if ((int)me->query_skill("qimen-baguazhen",1)<400)
    {
        tell_object(me,"你的奇门八卦阵境界太浅，这本注解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了奇门八卦阵的布阵方法！\n"NOR, me,this_object());
    me->set("safari_skill/thd_buzhen",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}