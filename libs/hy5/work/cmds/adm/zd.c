 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "send");
       add_action("do_send", "fire");
}


void create()
{
       set_name("反隐形导弹", ({"fdaodan"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
               "这是巫师专用的反隐形导弹，专门对付那些爱隐身的巫师\n");
               set("value", 0);
               set("unit", "枚");
               set("no_get", 0);
               set("no_drop", 0);
       }
}

int do_send(string target)
{
       object me, conc;

       me = this_object();

       if (target=="firefox")
             target = this_player()->query("id");

       if(!(conc = find_player(target)))
             if(!(conc = find_living(target)))
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }

       message_vision(HIR "反隐形导弹射向$n。\n" NOR, me, conc);

       me->move(environment(conc));

       message_vision(HIR "$N飞了过来，轰地一声炸开。\n" NOR, me);

       conc->set_temp("last_damage_from", "被" + me->name() + "炸");
       CHANNEL_D->do_channel(this_object(), "rumor", sprintf("%s被反隐形导弹炸出了原形。", conc->name(1)));

       conc->set("invisibility",10);  
       conc->set("env/invisibility",0);



           find_player(target)->reincarnate();
       find_player(target)->move("/clone/misc/void");
       find_player(target)->delete_temp("apply/name");
       find_player(target)->delete_temp("apply/id");
       find_player(target)->delete_temp("apply/short");
       find_player(target)->delete_temp("apply/long");
       destruct(this_object());
       return 1;
}

