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
	set_name(HIG"朝廷-武略篇"NOR, ({ "wulue pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "据说是官方出版的用兵要术，形胜势胜，兵家大成。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武略兵法，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query("safari_skill/ct_panlong"))
    {
        tell_object(me,"你不是已经习得了这种用兵之道了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("bixue-xinfa",1)<500)
    {
        tell_object(me,"你的碧血心法境界太浅，这本武略对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了朝廷的用兵之道！\n"NOR, me,this_object());
    me->set("safari_skill/ct_panlong",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}