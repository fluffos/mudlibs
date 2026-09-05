#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

string *names = ({
        HIR"圣诞烧鹅"NOR,
        HIY"吐司火鸡"NOR,
        HIM"约克郡布丁"NOR,
        HIC"爱尔兰烤羊腿"NOR,
        HIB"苏格兰牛排"NOR,
        HIW"英格兰署条炸鱼"NOR,
        RED"圣诞苹果派"NOR,
        HIG"巧克力摩丝蛋糕"NOR,
        MAG"红酒吉士火腿"NOR,
});
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( names[random(sizeof(names))] , ({ "gift dish","dish" }) );
        set("unit", "盘");
        set("long", HIY"这是一盘散发着诱人香味的圣诞大餐，好好大吃(eat)一顿吧！\n"NOR);
        set("value",0);
        set("no_store",1);
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要吃什么？\n");
    if((arg=="gift dish") || (arg=="dish")) 
    {
        if ( (int)me->query("marks/xmas2001" ) > 0 ) return notify_fail("你已经吃过圣诞大餐了，吃多了不消化哦:)\n");
        me->add("potential",100);
        me->add("combat_exp",1000);
        me->add("max_neili",100);
        me->add("max_jingli",50);
        message_vision(HIG"\n$N狼吞虎咽，几口就吃完了大餐，顿时觉得身体起了变化！\n"NOR,me);
        tell_object(me,"\n你的经验增长了1000点!\n你的最大内力增长了100点!\n你的最大精力增长了50点!\n你的潜能增长了100点!\n\n");
        me->set("marks/xmas2001",1);
        destruct(this_object());
     }
     return 1;
}

