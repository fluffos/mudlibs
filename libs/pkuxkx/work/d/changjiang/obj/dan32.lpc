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
	set_name(HIG"朝廷-文韬篇"NOR, ({ "wentao pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "据说是朝廷中各种为官之道，厚黑无耻，无所不用其极。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本文韬攻略，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query("safari_skill/ct_alert"))
    {
        tell_object(me,"你不是已经习得了这种用人之道了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("bixue-xinfa",1)<500)
    {
        tell_object(me,"你的碧血心法境界太浅，这本文韬对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了朝廷的用人之道！\n"NOR, me,this_object());
    me->set("safari_skill/ct_alert",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}