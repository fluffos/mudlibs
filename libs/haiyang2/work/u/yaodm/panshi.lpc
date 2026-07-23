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
        set_name(HIW"判师镜"NOR, ({"panshi jing"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "这是一面海洋判门派的宝物，可以帮助您判师。\n");
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


       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("这个人不知道在哪里。\n");
       message_vision(HIR "判师镜射出一道光芒，照向$n，将$n里里外外全部清洗干净\n" NOR, me, dest);


dest->set("title","普通百姓");
dest->set("class","0");
dest->delete("family");
dest->delete("party");


       dest->delete("env/invisibility");

       dest->delete("env/immortal");
       return 1;
}


