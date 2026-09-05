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
	set_name(HIB"千蛛万毒手心法"NOR, ({ "qianzhu xinfa","xinfa","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本千蛛万毒手的心法，不知何人所著，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
    string msg;
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query_skill("qianzhu-wandu"))
    {
        tell_object(me,"你已经掌握了千蛛万毒手的练法，入门之后要靠自己了。\n");
        return 1;
    }
    
    message_vision(HIB"$N"+HIB+"开始认真研读$n"+HIB+"，掌握了千蛛万毒手的修炼方法！\n"NOR, me,this_object());
    me->set_skill("qianzhu-wandu",100);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    msg="在心法化为灰烬之前，却闪烁出一行小字：\n";
    msg+="千蛛万毒，势不可挡，修炼惟通过以自身为蛛饲方可。\n";
    tell_object(me,msg);
    destruct(this_object());
    return 1;		
}