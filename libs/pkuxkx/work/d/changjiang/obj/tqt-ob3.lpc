// yhzzyahoo 4.11 2015 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_shiyong", "shiyong");
}

void create()
{
	set_name(YEL"孔雀石"NOR, ({ "que shi"}));
	set_weight(500);
    set("value",100000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一支巧夺天工的石头，五彩斑斓极像孔雀开屏，使用(shiyong)它可以减少铜雀台任务的冷却时间。\n");
			set("unit", "支");
		}
}

int do_shiyong()
{
   
    object me=this_player();
    if (me->query("safari"))
    {
        tell_object(me,"你还在铜雀台任务状态之下，不要暴殓天物了。\n");
        return 1;
    }
    if (time()-((int)me->query("safari_init_time"))>3*60*60*24)
    {
        tell_object(me,"你的铜雀台任务已经冷却完毕，不要暴殓天物了。\n");
        return 1;
    }
	if ((int)me->query("safari_init_time")>3600*24)
		{
		if (time()-((int)me->query("safari_kqs_time"))>3600*24)
			{
		    tell_object(me,HIY+"你使用了"+this_object()->query("name")+HIY+"，铜雀台的冷却时间被减少了一天！\n"NOR);
			me->add("safari_init_time",-3600*24);
			me->set("safari_kqs_time",time());
			message_vision("$N凭空消失了。\n",this_object());
			destruct(this_object());
			}
		else
			{
			tell_object(me,"无法在同一天内使用多个孔雀石。\n");
			}
		}
	else
	{
        tell_object(me,"因为某些奇怪的原因，无法使用孔雀石。\n");
	}
    return 1;		
}