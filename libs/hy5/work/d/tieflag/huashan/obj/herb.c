 inherit ITEM;
#include <ansi.h>
#include <condition.h>
void create()
{
  set_name(MAG"紫烟草"NOR,({"ziyan","ziyan grass"}));
  set("long", 
      "一棵通体碧绿的小草，茎叶的背面微微透着紫色。具有解毒（ｃｕｒｅ）的功能！\n");
  set("value",10000);
  set("unit","棵");
} 
void init()
{
  if(this_player()==environment())
  add_action("do_cure", "cure");
} 
int do_cure()
{
        object me;
        me = this_player();
        message_vision("$N把紫烟草细细嚼烂咽了下去！\n",me);
me->set("qi",me->query("eff_qi"));
me->set("eff_qi",me->query("max_qi"));

me->set("jing",me->query("eff_jing"));
me->set("eff_jing",me->query("max_jing"));

//        me->clear_condition();
//        me->clear_condition_type(NERVE_POISON);
        destruct(this_object());
        return 1;
}       
