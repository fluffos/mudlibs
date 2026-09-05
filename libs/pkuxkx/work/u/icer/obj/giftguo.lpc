#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

string *names = ({
        HIR"欢乐果"NOR,
        HIY"忘忧果"NOR,
        HIM"吉庆果"NOR,
        HIC"甜蜜果"NOR,
        HIB"长寿果"NOR,
        HIW"福禄果"NOR,
});


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( names[random(sizeof(names))] , ({ "gift guo","guo" }) );
        set("unit", "枚");
        set("long", HIC"这是一枚充满芳香气味的果实，吃(eat)下去一定有意想不到的效果。\n"NOR);
        set("value",0);
        set("no_store",1);
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要吃什么？\n");
    if((arg=="gift guo") || (arg=="guo")) 
    {
        if ( (int)me->query("kaizhan/gift_guo" ) > 0 ) return notify_fail("你已经吃过仙果了，难道还想成仙吗？\n");
        me->add("potential",100);
        me->add("combat_exp",1000);
        me->add("max_neili",20);
        me->add("max_jingli",20);
        message_vision(HIG"\n$N吃下果子，顿时感到清心气爽，精神百倍！\n"NOR,me);
        tell_object(me,"\n你的经验增长了1000点!\n你的最大内力增长了20点!\n你的最大精力增长了20点!\n你的潜能增长了100点!\n\n");
        me->set("kaizhan/gift_guo",1);
        destruct(this_object());
     }
     return 1;
}

