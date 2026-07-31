inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"广陵散"NOR, ({ "guangling san", "san", "guangling" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "本");
                set("long", "这是一本广陵散的乐谱，是梅庄黄忠公最想得到的东西。\n");
               set("value", 100000);
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);
               set("material", "jade");
       }
       setup();
}

