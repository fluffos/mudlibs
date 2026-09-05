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
	set_name(RED"幽冥"NOR, ({ "youming miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本失传的『幽冥』，你可以研究(yanjiu)一下。\n");
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
		tell_object(me,"只有纯星宿派弟子才能修习『幽冥』。\n");
		return 1;
	}
    if (me->query("safari_skill/xx_dushen"))
    {
        tell_object(me,"你已经学习了『毒神附体』，无法再修炼『幽冥』。\n");
        return 1;
    }
    if (me->query("safari_skill/xx_fire"))
    {
        tell_object(me,"你已经掌握了『幽冥』。\n");
        return 1;
    }
    
    message_vision(HIR"$N"+HIR+"从书中领悟，掌握了『幽冥』！\n"NOR, me);
    me->set("safari_skill/xx_fire",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}