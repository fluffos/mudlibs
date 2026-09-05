//石碑
//create by zine 29/3/2011
#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name(CYN"为官之道"NOR, ({ "bei"}));
	set_weight(500000000);
	set("long", "这是一面巨大的石碑，是前代官员刻下的，你可以读读看(kan)。\n");
	set("material", "jade");
	set("unit", "面");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_put",1);
    set("no_store",1);
    
	setup();
    
}


void init()
{
    add_action("do_read","kan");
}

int reading(object me)
{
    if (!me)
    {
        return 0;
    }
    if (base_name(environment(me))!=base_name(environment(this_object())))
    {
        return 0;
    }
    if (!living(me))
    {
        return 0;
    }
    tell_object(me,HIY"财能通神这句话在官场就更恰如其分了。\n");
    tell_object(me,"六部的尚书和侍郎都会很喜欢你的礼物。\n");
    tell_object(me,"直接送钱当然也可以，不过就落入下乘了。\n");
    tell_object(me,"如果打点了一两位官员，至少有个照应，面面俱到，人脉肯定是优！\n"NOR);
    me->delete_temp("通政read");
    return 1;
}

int do_read()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        message_vision("$N刚要阅读石碑，被周围的军士赶走了。\n",me);
        return 1;
    }
    if (me->query_temp("通政read"))
    {
        tell_object(me,"毛毛躁躁不静下心来是读不到什么的。\n");
        return 1;
    }
    me->set_temp("通政read",1);
    message_vision("$N开始阅读碑刻。\n",me);
    tell_object(me,HIC"碑刻上写道：为官就是做人。\n");
    tell_object(me,"所谓政通人和，除了政绩突出，更要和官场同僚打好关系。\n"NOR);
    if (me->query("mingpin")==1)
    {
        tell_object(me,"一品官要政绩突出，至少要比上次增加四十点功勋。\n");
        tell_object(me,"如果连十六点功勋都没增长，那铁定是差评。\n");
    }
    if (me->query("mingpin")==2)
    {
        tell_object(me,"二品官要政绩突出，至少要比上次增加三十五点功勋。\n");
        tell_object(me,"如果连十四点功勋都没增长，那铁定是差评。\n");
    }
    if (me->query("mingpin")==3)
    {
        tell_object(me,"三品官要政绩突出，至少要比上次增加三十点功勋。\n");
        tell_object(me,"如果连十二点功勋都没增长，那铁定是差评。\n");
    }
    if (me->query("mingpin")==4)
    {
        tell_object(me,"四品官要政绩突出，至少要比上次增加二十五点功勋。\n");
        tell_object(me,"如果连十点点功勋都没增长，那铁定是差评。\n");
    }
    if (me->query("mingpin")==5||me->query("mingpin")==6)
    {
        tell_object(me,"低级官员虽不用参加岁考，也无法使用京城的各种便利。\n");
        tell_object(me,"加油！加油！。\n");
    }
    call_out("reading",2,me);
    return 1;
}