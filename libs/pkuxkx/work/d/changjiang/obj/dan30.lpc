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
	set_name(HIG"峨嵋九阳功-残篇"NOR, ({ "jiuyanggong pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是郭襄祖师对九阳功的一些研究残篇，从上面似乎不能学到九阳功的真谛。\n");
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
    if (me->query("safari_skill/em_jyg"))
    {
        tell_object(me,"你不是已经习得了九阳功的些许奥秘了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("linji-zhuang",1)<500)
    {
        tell_object(me,"你的临济十二庄境界太浅，这本残篇对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，初窥一些峨眉九阳功的门径，向峨眉高人们请教下也许能有更大收获！\n"NOR, me,this_object());
    me->set("safari_skill/em_jyg",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}