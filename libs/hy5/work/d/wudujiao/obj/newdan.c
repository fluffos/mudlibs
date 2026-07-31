// newdan.c 新手上路丹
// 99-11-10 15:04 By victori

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");  
}
void create()
{
        set_name(HIC"新手上路丹"NOR, ({"new dan", "dan"}));          
        set("unit", "颗");
        set("value", 10000);
        set("long", "这是一颗天上的神仙们送给刚进入江湖的新手吃的
仙丹，据说灵验无比，人间少有。\n");
        setup();
}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if (me->query("tmarks/丹",1)>0)
                return notify_fail("搞什么啊，你吃过了还想吃？！\n");
        if (me->query("combat_exp")>0)
              return notify_fail("搞什么啊，你都不是新手了还想吃？！\n");
        else
        {
        me->set("combat_exp", 5000);                    
        me->set("potential", 5000);
        message_vision(HIW"$N吃下一颗新手上路丹，一股热流从丹田升起，顿时全身充满力量！\n"NOR,me);
        tell_object(me,HIY"冥冥中好象有人在你耳边说：“怎么样？爽吧？祝你一路好运！”\n"NOR,);
        me->set("tmarks/丹",1);
        me->start_busy(2);
        destruct(this_object());
        return 1;
}}
