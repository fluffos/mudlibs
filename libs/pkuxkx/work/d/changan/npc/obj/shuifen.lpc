
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"水粉"NOR, ({ "shui fen","shuifen","fen" }) );
        set_weight(100);
        set("unit", "把");
        set("long", "这是一包怡红院出品的水粉，你可以擦(ca)在脸上。\n");
        set("value", 0);
        set("material", "herb");
                
        setup();
}

int do_ca()
{
    int *age,myage,n;
    object me=this_player();
    n=1+random(10);
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("gender")=="男性")
    {
        tell_object(me,"大老爷们，搞这玩意儿干嘛？\n");
        return 1;
    }
    if (me->query_temp("makeup_using"))
    {
        tell_object(me,"你已经把水粉擦上了。\n");
        return 1;
    }
    if (me->query_temp("apply/age"))
    {
        myage=me->query_temp("apply/age")[0]-n;
    }
    else
    {
        myage=me->query("age")-n;
    }
    age=({myage,(int)me->query("age")});
    me->set_temp("makeup_using",1);
    message_vision("$N把水粉均匀的擦在脸上，看起来立刻年轻了"+chinese_number(n)+"岁。\n");
    me->set_temp("apply/age",age);
    return 1;
}