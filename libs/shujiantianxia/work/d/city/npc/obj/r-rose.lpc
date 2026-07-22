// r-rose.c 红玫瑰
// update by cool

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED "红玫瑰" NOR, ({ "red rose", "rose" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", HIR "一朵送给情人的红玫瑰，带给你一丝温情。\n" NOR);
set("value", 15000);
//              set("wear_msg", HIM "$N嘻嘻一笑，把花儿别在发髻上，有如天女下凡。\n" NOR);
//              set("remove_msg", HIM "$N把花儿从发髻取下，深深闻了闻，揣回怀中。\n" NOR);
//              set("armor_prop/armor", 10);
        }
        setup();
}

void init()
{
       add_action("come_life","wen");
       call_out("dest", 1800);
}
        
int come_life(string arg)
{
      object me;
      me=this_player();

      if(!arg) return 0;
      if(arg == "rose" || arg == "red rose" ){
        message_vision("$N用小指轻轻捻住红玫瑰，拿起来深深地闻了闻。\n",me);
        tell_object(me, HIY "嗯。。。啊。。。好香呀！\n" NOR);
      }
      return 1;
}

void dest()
{
      object me;
      me=this_player();
        if (!me) return;
      message_vision("$N手中的红玫瑰渐渐枯萎了。\n",me);
      destruct(this_object());
}
