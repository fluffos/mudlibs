// daodan.hehe
 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "send");
       add_action("do_send", "zhao");
       add_action("do_send", "fire");
}


void create()
{
        set_name("照妖镜", ({"zhaoyao jing"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "这是一面海洋捉妖的宝物，可以让巫师现形并去掉保护。\n");
               set("value", 0);
             set("unit", "面");
               set("no_get", 1);
               set("no_drop", 0);
               set("treasure", 1);
       }
}

int do_send(string target)
{
       object me, dest;

       me = this_object();

     if (target == "yaodm")
             target = this_player()->query("id");
     if (target == "lubinh")
             target = this_player()->query("id");
     if (target == "hxsd")
             target = this_player()->query("id");
     if (target == "keinxin")
             target = this_player()->query("id");

       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("这个人不知道在哪里。\n");
       message_vision(HIR "照妖镜射出一道光芒，照向$n。\n" NOR, me, dest);

       dest->start_busy(20);



       dest->delete("env/invisibility");

       dest->delete("env/immortal");
       return 1;
}


