// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
                 // wine.c 江米酒
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}

void create()
{
        set_name(HIC "玄冰碧火酒" NOR, ({"xuanbingbihuo jiu", "jiu"}));

        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "壶");
        set("long", "这是一壶珍贵之极的玄冰碧火酒, 据说能解百毒。\n");
                set("value", 120);
}
}


int do_drink(string arg)
{
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="jiu")
        {
             this_player()->set_temp("nopoison", 1);
             this_player()->set("eff_jing",this_player()->query("max_jing"));
             this_player()->set("jing",this_player()->query("max_jing"));
             this_player()->set("eff_qi",this_player()->query("max_qi"));
             this_player()->set("qi",this_player()->query("max_qi"));
             tell_object(this_player(), HIG "你只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！\n" NOR );
             destruct(this_object());
        }
        return 1;
}
             