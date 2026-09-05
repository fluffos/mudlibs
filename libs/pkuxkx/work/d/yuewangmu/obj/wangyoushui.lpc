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
        set_name(HIW"忘忧水"NOR, ({"wangyou shui", "shui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", GRN"这就是一瓶忘忧水,玉制的瓷瓶上刻有一行小字:世间本无事,庸人自扰之.\n"NOR);
                set("value", 100);
        }
        setup();
}
int do_drink(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要喝什么？\n");
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));   
message_vision(HIY"$N喝下一瓶忘忧水，感到现在已心如止水 !\n" NOR, me);
                 me->set("attitude","peaceful");
      set("bellicosity", 0);
me->set("shaqi",0);
        destruct(this_object());
        return 1;
}
