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
	set_name(HIG"天地会-浩然正气决"NOR, ({ "zhengqi pian","pian","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "据说是天地会陈近南从文天祥正气歌中领悟所得：天地有正气，杂然赋流形。\n");
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
    if (me->query("safari_skill/tdh_zhengqi"))
    {
        tell_object(me,"你不是已经习得了『浩然正气决』了吗？\n");
        return 1;
    }
    if ((int)me->query_skill("cangming-gong",1)<500)
    {
        tell_object(me,"你的浩气苍冥功境界太浅，这本残篇对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，领悟了浩气苍冥功中的『浩然正气决』！\n"NOR, me,this_object());
    me->set("safari_skill/tdh_zhengqi",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}