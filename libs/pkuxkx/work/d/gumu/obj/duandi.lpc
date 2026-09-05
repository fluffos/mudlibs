#include <ansi.h>
#include "/d/gumu/bonus.h"
inherit ITEM;

void create()
{
    set_name("短笛", ({"duan di","di"}) );
    set_weight(1000);
    set("unit", "支");
	set("value", 20);
    set("long", "这是一支短笛，可以吹奏乐曲。\n");
    set("material", "jade");
    setup();
}

void init()
{
    add_action("do_blow","blow");
}

int yinfeng(object me)
{
    int exp,pot;
    string msg;
    if (me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree")>5+random(10))
    {
        exp=(int)me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree")*((int)me->query("combat_exp")+30000)/5000;
        pot=10+random(exp);
        me->delete_temp("gmnewbiejob/yangfeng_yinfeng_degree");
        me->set_temp("gmnewbiejob/yangfeng_tiqu_degree",1);
        message_vision("大群大群的蜜蜂出现了，开始筑巢了，稍等片刻你就可以开始提取(tiqu)花蜜了。\n",me);
        me->set_temp("gmnewbiejob/yangfeng_finish_time",time());
        msg=HIW"在劳作中，你增加了经验EXP点，潜能POT点！\n"NOR;
		bonus(me,3,exp,pot,0,msg);
        return 1;
    }
    me->add_temp("gmnewbiejob/yangfeng_yinfeng_degree",1);
    tell_object(me,"你吹奏了半天，半只蜜蜂也没有出现，不禁有些气馁。\n");
    return 1;
}

int do_blow(string arg)
{
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    message_vision(HIM"$N开始吹奏短笛，发出一些奇怪的韵律。\n"NOR,me);
    me->add_busy(2+random(2));
    if (me->query("family/family_name")=="古墓派"
    &&time()-(int)me->query_temp("gmnewbiejob/yangfengtime")<=120
    &&base_name(environment(me))=="/d/gumu/caodi3"
    &&me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree"))
    {
        if (me->query_temp("gmnewbiejob/yangfeng_tiqu_degree"))
        {
            tell_object(me,"你已引来了蜜蜂，可以开始提取花蜜了。\n");
            return 1;
        }
        call_out("yinfeng",2+random(2),me);
        return 1;
    }
    if (me->query("family/family_name")=="古墓派"
    &&time()-(int)me->query_temp("gmnewbiejob/yangfengtime")>120
    &&base_name(environment(me))=="/d/gumu/caodi3"
    &&me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree"))
    {
        tell_object(me,"你已经出墓很久，去看看小龙女还有什么别的事情需要你帮助吧。\n");
        return 1;
    }
    if (me->query("family/family_name")=="古墓派"
    &&base_name(environment(me))!="/d/gumu/caodi3"
    &&me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree"))
    {
        tell_object(me,"此地似乎不宜驯养玉蜂。\n");
        return 1;
    }
    return 1;
}