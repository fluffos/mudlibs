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
	set_name(HIG"斗转星移真解"NOR, ({ "douzhuan pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是姑苏慕容家威震江湖的绝学：斗转星移的真正秘籍。\n");
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
    if (me->query("safari_skill/mr_douzhuan"))
    {
        tell_object(me,"你不是已经掌握了斗转星移真解了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("shenyuan-gong",1)<400)
    {
        tell_object(me,"你的神元功境界太浅，这本真解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，掌握了斗转星移的真正绝学--斗转星移！\n"NOR, me,this_object());
    me->set("safari_skill/mr_douzhuan",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}