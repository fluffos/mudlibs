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
	set_name(HIG"太极神功-蓄力篇"NOR, ({ "xuli pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本张三丰所著的太极神功心得，记载着太极神功『太极蓄力』的进修方法，你可以研究(yanjiu)一下。\n");
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
    if (me->query("safari_skill/wd_taiji"))
    {
        tell_object(me,"你不是已经掌握了太极神功『太极蓄力』了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("taiji-shengong",1)<500)
    {
        tell_object(me,"你的太极神功境界太浅，『太极蓄力』对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，掌握了太极神功『太极蓄力』的运功方法！\n"NOR, me,this_object());
    me->set("safari_skill/wd_taiji",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}