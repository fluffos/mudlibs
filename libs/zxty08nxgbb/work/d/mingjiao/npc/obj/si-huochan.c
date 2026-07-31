// si-huochan.c

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"死火蟾"NOR, ({"si huochan", "corpse"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
//                 set("value", 5000);
                set("ty_gift", 5000);
        }
        setup();
}

int do_eat(string arg)
{
       
        if (!id(arg))
      return notify_fail("你要吃什么？\n");
 if ( this_object()->query("zhuren") != this_player()->query("id") )
        return notify_fail("这个火蟾不是你杀的，你吃个什么劲??\n");
if ( this_player()->query("ty_dan/shc") < time() )
         {
              this_player()->add("max_neili", random(1000));
   this_player()->set("ty_dan/shc",time()+42000);
                 message_vision(HIY "$N吃下一只死火蟾，顿然间只觉一股的真气直冲顶门...\n" NOR, this_player());
     destruct(this_object());
       return 1;
         }
 message_vision(HIG "$N吃下一只死火蟾，但是好象由于吃的太多了，没什么大感觉!\n" NOR, this_player());
   this_player()->set("ty_dan/shc",time()+42000);

        destruct(this_object());
        return 1;
}


