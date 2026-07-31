 // bat_drug.c
#include <weapon.h> 
inherit THROWING; 
void create()
{
        set_name("解药", ({ "bat drug", "drug" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
      set("long",
           "这是一包用来解蝙蝠毒的药\n"
            "可以用(cure)来解蝙蝠毒!\n");
                set("unit", "包");
                set("base_unit", "份");
                set("base_weight", 10);
                set("base_value", 10);
        }
        set_amount(1);
        ::init_throwing(1, 0);
} 
void init()
{
  if(this_player()==environment())
  add_action("do_cure","cure");
} 
int do_cure()
{
  object me;
  me = this_player();
 if  (((int) me->query_condition("bat_poison")) <= 0)
  return notify_fail("你没有中蝙蝠毒。\n");
  message_vision("$N服下解药，顿时感觉好多了。",me);
        me->apply_condition("bat_poison",
                (int)me->query_condition("bat_poison") - 1);
  if((int) (me->query_condition("bat_poison")))
      message_vision("但是$N中的蝙蝠毒并没有完全清除。\n",me);
  else
        message_vision("$N终于清除了体内所有的蝙蝠毒！\n",me);
  add_amount(-1); 
  return 1;
}    
