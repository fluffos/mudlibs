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
	set_name(HIG"葵花宝典-归冥篇"NOR, ({ "guiming pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是葵花神功归冥状态的进入方法，天下武功，唯快不破。\n");
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
    if (me->query("safari_skill/riyue_guiming"))
    {
        tell_object(me,"你不是已经学会了这个方法了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("kuihua-shengong",1)<500)
    {
        tell_object(me,"你的葵花神功境界太浅，这本注解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了葵花神功进入归冥状态的办法！\n"NOR, me,this_object());
    me->set("safari_skill/riyue_guiming",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}