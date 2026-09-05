#include <armor.h>
#include <ansi.h>
inherit CLOTH;
int test();
void create()
{
set_name(HIG"freecv的魔法袍"NOR,({"magic robe","robe"}));
if(clonep())
  set_default_object(__FILE__);
else
{
  set("unit","件");
}
  setup();
}
void init()
{
 add_action("test","test");
}

int test()
{
  object *sz;
  int val;
  sz = users();
  val = sizeof(sz);
  this_player()->set_temp("users",val);
  return 1;
}

