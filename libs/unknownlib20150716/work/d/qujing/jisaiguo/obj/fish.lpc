// created 11/1/1997 by snowcat
#include <ansi.h>

inherit NPC;

mixed says ()
{
  string *msgs = ({
    "啪地一声，$N跳了起来。\n",
    "$N跳了跳。\n",
    "$N啪地一跳。\n",
    "$N一挺，跃在空中。\n",
    "$N轻轻一跃。\n",
    "$N动了动。\n",
  });
  message_vision("小鱼儿跳了一跳。\n"+msgs[random(sizeof(msgs))],this_object());
  return 1;
}

void create()
{
  set_name("鱼", ({ "fish"})); 
  set_weight(100);
  set("long","一条成精的鱼。\n");
  set("unit", "条");
  set("value",100);
  set("chat_msg",({ 
	(: says :), 
  }) );
  setup();
}
