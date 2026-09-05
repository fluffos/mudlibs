//忘忧水
//by male

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_drink", "drink");
}
void create()
{
        set_name(HIW"万年醉"NOR, ({"wannian zui", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", GRN"万年醉，顾名思意就是一醉万年的意思，乃酒中级品.世间少有。\n"NOR);
                set("value", 100000);
        }
        setup();
}
int do_drink(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要喝什么？\n");
   if(me->query_condition("wannianzui")>0)   return notify_fail("万年醉还在你身上发生作用呢！你想醉死啊?\n");
/*
me->add("wannianzui",1);
if(me->query("wannianzui")>50)
{
write(HIR"你喝下一瓶万年醉之后，突然感到身轻如燕，冥冥之中感觉到你的轻功有所提高！\n"NOR);
me->set("wannianzui",0);
me->add("dex",1);
me->apply_condition("wannianzui",10000);
return 1;
}
*/
message_vision(HIB"$N喝下一瓶万年醉之后，突然感到一阵醉意袭来，让人无法控制 !\n" NOR, me);
me->apply_condition("wannianzui",10000);
me->unconcious();
        destruct(this_object());
        return 1;
}
