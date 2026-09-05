// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
#include "checking.h"
#include "/d/menggu/shediao_bonus.h"
inherit NPC;

void create()
{
	set_name("黑雕", ({"hei diao","diao"}));
	set("rance", "野兽");
	set("age", 50);
    set("combat_exp", 15000);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
    set("is_heidiao",1);
	set("uni_target","zine");
    setup();
}
	
int shoot(string arg)
{
    object me=this_player();
    if (!me->query_temp("shediaoquest/shediao_step5"))
    {
        tell_object(me,"射雕英雄是你这种人可以觊觎的吗？\n");
        return 1;
    }
    else if (!arg||(arg!="hei diao"&&arg!="diao"))
    {
        tell_object(me,"让你射雕你就射雕，别乱射其他东西！\n");
        return 1;
    }
    
}

void unconcious()
{
    die();
}

void die()
{
    int e_reward;
    object ob=this_object(),pl;
    message_vision("$N中箭后挣扎几下，一头从空中栽了下来。\n",this_object());
    if (ob->query("killed_by"))
    {
        pl=ob->query("killer_by");
    }
    if (pl&&pl->query_temp("shediaoquest/shediao_step5"))
    {
        pl->delete_temp("shediaoquest");
        pl->set("shediaoquest/shediao",1);
        tell_object(pl,"从此，你被草原上的牧民称为射雕英雄。甚得铁木真喜爱。\n");
        message_vision("$N被射下后，众人齐声喝彩。\n",ob);
        e_reward=bonus(pl,1400);
        pl->add("combat_exp",e_reward);
        tell_object(pl,HIC"完成射雕主线任务【射雕英雄】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
    }
    destruct(this_object());
    return;
}