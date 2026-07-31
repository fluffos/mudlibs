//LUCAS 2000-6-18
#include <ansi.h>

inherit ITEM;

int do_drink(string);
void init();

void init()
{
  add_action("do_drink", "drink");
}

void create()
{
  set_name( HIR "怪蛇血" NOR , ({"she xue", "blood"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "管");
    set("long", "一管怪蛇的血液,很是腥臭,看起来绿油油的。\n");
    set("value", 1000);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_drink(string arg)
{
  object me = this_player();
  if (arg!="blood" && arg!="she xue")   return 0;
        if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N吃下一怪蛇的血液，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
return 1;
	}
        me->apply_condition("medicine", 30);
  
  me->add("max_neili", 5);
  message_vision(HIR "$N只觉一股热线从咽喉直通到腹中,然后丹田就象有一团火般烧了起来。\n" NOR, me);
  destruct(this_object());
  return 1;
}

