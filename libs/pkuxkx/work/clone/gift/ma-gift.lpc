#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIC"风之翼"NOR, ({ "wind ring","ring"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "crystal");
                set("value", 300000);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_put",1);
                set("no_get",1);
                set("no_store",1);
                set("no_give_user",1);
                set("armor_prop/armor", 80);
                set("armor_prop/strength", 5);
                set("armor_prop/intelligence", 5);
                set("long","一枚漂亮的戒指，镶着一颗紫色的水晶,似乎拥有无尽的魔力。\n"); 
        }
        setup();
}


int query_autoload() { return 1; }

void destruct_me(object where, object me)
{
  message_vision("$n慢慢地随风飘去……\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}
