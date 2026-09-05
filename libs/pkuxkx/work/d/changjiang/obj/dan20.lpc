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
	set_name(CYN"乾坤大挪移注"NOR, ({ "danuoyi zhu","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本明教前代高手注释的『乾坤大挪移』，你可以研究(yanjiu)一下。\n");
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
    if (me->query("safari_skill/mj_dny"))
    {
        tell_object(me,"你已经掌握了『乾坤大挪移』注释中的要点。\n");
        return 1;
    }
    
    message_vision(HIR"$N"+HIR+"从书中领悟，掌握了『乾坤大挪移』的一些技巧！\n"NOR, me);
    me->set("safari_skill/mj_dny",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}