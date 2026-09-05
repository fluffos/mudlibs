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
	set_name(HIG"蛤蟆功乱解"NOR, ({ "hamagong pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是欧阳锋在得到九阴真经以后对蛤蟆功的改进，但是因为当时欧阳锋神经错乱，所以注解出来的只能是乱解。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query("safari_skill/bts1"))
    {
        tell_object(me,"你不是已经掌握了蛤蟆功乱解了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("hamagong",1)<500)
    {
        tell_object(me,"你的蛤蟆功境界太浅，这本乱解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，掌握了蛤蟆功另外一路诡异的运功方法-蛤蟆吐息！\n"NOR, me,this_object());
    me->set("safari_skill/bts1",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}