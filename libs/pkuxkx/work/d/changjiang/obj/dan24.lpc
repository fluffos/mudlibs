// yhzzyahoo 2015.4.30 ,铜雀台
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
	set_name(HIR"华山武功注解"NOR, ({ "huashanwugong miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本『华山剑气两宗武功融合』的注解，你可以研究(yanjiu)一下。\n");
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
    if (me->query("safari_skill/hs_jq"))
    {
        tell_object(me,"你已经掌握了『华山武功融合』的诀窍。\n");
        return 1;
    }
    
    message_vision(HIR"$N"+HIR+"渐渐掌握了『华山武功融合』的诀窍！\n"NOR, me);
    me->set("safari_skill/hs_jq",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}