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
	set_name(HIR"赤炼神掌补遗"NOR, ({ "chilian buyi","buyi","book"}));
	set_weight(500);
    set("value",1);
    set("chilian_buyi",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本赤炼神掌的补遗，李莫愁所著，你可以研究(yanjiu)一下。\n");
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
    if (!me->query_skill("chilian-shenzhang"))
    {
        tell_object(me,"你没有掌握赤炼神掌的练法，赤炼神掌补遗对于你过于晦涩难懂了。\n");
        return 1;
    }
    
    tell_object(me,"将这本书带去给李莫愁，好好请教一下她吧。\n");
    return 1;		
}