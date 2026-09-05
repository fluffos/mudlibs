//flower
//玩具

inherit ITEM;
#include <ansi.h>

string *name=({HIR"红玫瑰"NOR,HIW"白玫瑰"NOR,HIY"菊花"NOR,WHT"茉莉花"NOR,MAG"牡丹花"NOR,BLK"黑玫瑰"NOR,});
void create()
{
        string nname=name[random(sizeof(name))];;
        set_name(nname,({"flower"}));
        set("long",
        "这是一朵美丽的"+nname+",在清风中微微的摇摆..\n"
        "你可以把它戴(dai)在头上\n");
        set("unit","朵");
        set("no_sell",1);
        set_heart_beat(1);
        setup();
}

void init()
{
        add_action("do_wear","dai");
        add_action("do_unwear","qu");
}

int do_wear()
{
        object ppl=this_player(),me=this_object();
        if(ppl->query("gender")!="女性")
        {
                tell_object(ppl,"你戴什么花啊?不害臊!\n");
                return 1;
        }
        if(objectp(ppl->query_temp("dai_flower")))
        {
                tell_object(ppl,"你已经戴了花了呀\n");
                return 1;
        }
        message_vision("$N戴上一朵"+me->name()+",越发显得娇媚可人.\n",ppl);
        ppl->set_temp("dai_flower",me);
        set("long",
        "这是一朵美丽的"+me->name()+",戴在你头上美丽极了..\n"
        "你可以把取(qu)下来.\n");
        return 1;
}

int do_unwear()
{
        object ppl=this_player(),me=this_object();
        if(!objectp(ppl->query_temp("dai_flower")))
        {
                tell_object(ppl,"你没有戴花啊.\n");
                return 1;
        }
        tell_object(ppl,"你取下了"+me->name()+"\n");
        ppl->delete_temp("dai_flower");
set("long",
	"这是一朵美丽的"+me->name()+",在清风中微微的摇摆..\n"
        "你可以把它戴(dai)在头上\n");
        return 1;
}
void heart_beat()
{
        string nname;
        object ppl,me=this_object();
        if(!objectp(ppl=environment(me))) return ;
        if(ppl->query_temp("dai_flower")!= me) return;
if(random(10) > 8)
        {
                message_vision("$N头上的"+me->name()+"发出阵阵的清香,大家都觉得$N简直迷人极了.\n",ppl);
                if(random(3) > 1)
                {
                        nname=name[random(sizeof(name))];
                        if(nname!=this_object()->name())
                        {
                                message_vision("$N头上的"+me->name()+"神奇的变成了"+nname+",真实太奇妙了!\n",ppl);
                                me->set_name(nname,({"flower"}));
                        }
                }
        }
}


