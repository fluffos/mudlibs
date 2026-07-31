inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIM"率意帖"NOR, ({ "shuaiyi tie", "tie", "shuaiyi" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "本");
                set("long", "这是一本率意帖，是梅庄秃笔翁最想得到的东西。\n");
               set("value", 100000);
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);
               set("material", "jade");
       }
       setup();
}

