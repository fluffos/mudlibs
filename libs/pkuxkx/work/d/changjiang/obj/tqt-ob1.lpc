// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_use", "use");
}

void create()
{
	set_name(YEL"铜雀"NOR, ({ "tong que"}));
	set_weight(500);
    set("value",100000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一支做工精巧的金黄色的孔雀，使用(use)它可以延后铜雀台任务的完成时间要求。\n");
			set("unit", "支");
		}
}

int do_use()
{
   
    object me=this_player();
    if (!me->query("safari"))
    {
        tell_object(me,"你现在并不在铜雀台任务状态之下，不要暴殓天物了。\n");
        return 1;
    }
    if (!me->query("safari/duedate"))
    {
        tell_object(me,"你的铜雀台状态出错，现在无法使用铜雀。\n");
        return 1;
    }
    if (time()>=(int)me->query("safari/duedate"))
    {
        tell_object(me,"你的铜雀台任务已经失败，无法增加可完成时间。\n");
        return 1;
    }
    if (time()-(int)me->query("safari/duedate")>60*60*24)
    {
        tell_object(me,"你的铜雀台任务还有一天以上的完成时间，不要暴殓天物了。\n");
        return 1;
    }
    tell_object(me,HIY+"你使用了"+this_object()->query("name")+HIY+"，完成铜雀台的时间要求被延后了一天！\n"NOR);
    me->add("safari/duedate",60*60*24);
    message_vision("$N凭空消失了。\n",this_object());
    destruct(this_object());
    return 1;		
}