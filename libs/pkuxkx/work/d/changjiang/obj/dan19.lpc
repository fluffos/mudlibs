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
	set_name(BLU"毒神"NOR, ({ "dushen miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本失传的『毒神附体』，你可以研究(yanjiu)一下。\n");
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
	if (me->query("chushi")||me->query("family/family_name")!="星宿派")
	{
		tell_object(me,"只有纯星宿派弟子才能修习『毒神附体』。\n");
		return 1;
	}
    if (me->query("safari_skill/xx_fire"))
    {
        tell_object(me,"你已经掌握了『幽冥火焰』，无法再学习『毒神附体』。\n");
        return 1;
    }
	if (me->query("safari_skill/xx_dushen"))
    {
        tell_object(me,"你已经掌握了『毒神附体』。\n");
        return 1;
    }
    
    message_vision(HIR"$N"+HIR+"从书中领悟，掌握了『毒神附体』！\n"NOR, me);
    me->set("safari_skill/xx_dushen",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}