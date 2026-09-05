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
	set_name(HIR"赤炼神掌秘籍"NOR, ({ "chilian miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本赤炼神掌的秘籍，李莫愁所著，你可以研究(yanjiu)一下。\n");
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
    if (me->query_skill("chilian-shenzhang"))
    {
        tell_object(me,"你已经掌握了赤炼神掌的练法，入门之后要靠自己了。\n");
        return 1;
    }
    
    message_vision(HIR"$N"+HIR+"开始认真研读$n"+HIR+"，掌握了赤炼神掌的基本招式！\n"NOR, me,this_object());
    me->set_skill("chilian-shenzhang",5);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}