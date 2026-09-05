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
	set_name(HIR"降龙十八掌掌谱"NOR, ({ "xianglong zhangpu","zhangpu","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本洪老前辈手写的降龙十八掌心法，你可以研究(yanjiu)一下。\n");
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
    if (me->query_skill("xianglong-zhang",1)<200)
    {
        tell_object(me,"你的降龙十八掌造诣太低，无法通读心法。\n");
        return 1;
    }
    if (me->query("player_special_contribute/gb"))
    {
        tell_object(me,"你已经掌握了降龙十八掌的精义。\n");
        return 1;
    }
    message_vision(HIR"$N开始认真研读$n"+HIR+"，降龙十八掌融会贯通，天下无敌！\n"NOR, me,this_object());
    me->set("player_special_contribute/gb",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}