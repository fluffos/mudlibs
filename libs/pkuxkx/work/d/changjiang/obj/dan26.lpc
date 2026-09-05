// yhyzzyahoo 2015/11/19 ,铜雀台
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
	set_name(HIW"阴阳倒乱刃绝学"NOR, ({ "daoluan miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本有关阴阳倒乱刃绝技的秘籍，为绝情谷先辈所著，你可以研究(yanjiu)一下。\n");
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
    if (me->query_skill("yinyang-daoluan")<200)
    {
        tell_object(me,"你的阴阳倒乱刃等级太低，提高一些再来学习绝学吧。\n");
        return 1;
    }
    if (me->query("daoluan_perform"))
    {
        tell_object(me,"你已经掌握了「倒乱刃法」，就没必要再学习一次了。\n");
        return 1;
    }

    
    message_vision("$N开始认真研读$n，掌握了阴阳倒乱刃的「倒乱刃法」绝学！\n"NOR, me,this_object());
    me->set("daoluan_perform",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}