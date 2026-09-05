// /u/beyond/mr/npc/obj/yuxi.c
// this is made by beyond
// update beyond
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIM"鸳"+HIC+"鸯"+HIG+"刀"NOR, ({ "yuanyang dao", "yuanyang blade", "dao" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "对");
               set("long", "这是一对鸳鸯刀，听说其中隐藏着一个秘密。\n");
               set("value", 40000);
               set("no_put",1);
               set("is_yuxi",1);//不让乱拿
               set("material", "steel");
       }
       setup();
       call_out("dest",300);
}

int dest()
{
    if (this_object())
    {
        message_vision("鸳鸯刀失去了刀身上的光华。\n",this_object());
        destruct(this_object());
    }
    return 1;
}

