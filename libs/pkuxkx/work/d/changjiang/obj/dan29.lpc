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
	set_name(HIG"雪山剑法-月剑秘籍"NOR, ({ "yuejian pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是白自在晚年潜心研究雪山剑法，对雪山剑法修改后的杰作。\n");
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
    if (me->query("safari_skill/xs_yuejian"))
    {
        tell_object(me,"你不是已经掌握了月剑的奥秘了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("xueshan-neigong",1)<500)
    {
        tell_object(me,"你的雪山内功境界太浅，这本真解对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，掌握了雪山剑法的最后绝技--月剑！\n"NOR, me,this_object());
    me->set("safari_skill/xs_yuejian",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}