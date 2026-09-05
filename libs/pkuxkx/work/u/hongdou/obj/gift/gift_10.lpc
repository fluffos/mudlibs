#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

string *names = ({
       HIR"茉莉花"NOR,
       HIR"牡丹花"NOR,
       HIR"月季花"NOR,
       HIR"水仙花"NOR,
       HIR"腊梅花"NOR,
       HIR"迎春花"NOR,
       HIR"丁香花"NOR,
});


void init()
{
                   add_action("do_wen", "wen");
}

void create()
{
	set_name( names[random(sizeof(names))] , ({ "gift hua","hua" }) );
//	set_name("无名花", ({"hua", "wuming"}));
	set("no_drop","这可是节日礼物呀，丢了多可惜！\n");
        set("unit", "枚");
	set("long", HIC"这是一株充满芳香气味的鲜花，闻(wen)一闻一定有意想不到的效果。\n"NOR);
	set("value",0);
        set("no_store",1);
        setup();
}

int do_wen(string arg)
{
    object me;
    me = this_player();
//    if (!id(arg))  return notify_fail("你要吃什么？\n");
    if (!arg)  return notify_fail("你要干什么？\n");
    if((arg=="gift hua") || (arg=="hua")) 
    {
        if ( (int)me->query_condition("gift_guo" ) > 0 ) return notify_fail("你刚刚闻过，花儿香气的效力对你已经无用了\n");
        me->add("potential",50);
	
	message_vision(HIR"\n$N闻了闻花朵，顿时感到清心气爽，精神百倍！\n"NOR,me);
	tell_object(me,"\n你的潜能增长了50点!\n");
            me->apply_condition("gift_guo", 1000);
        destruct(this_object());
     }
     return 1;
}
