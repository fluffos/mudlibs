#include <ansi.h>
#include <mudlib.h>

inherit OBJECT;

mixed *races;

void create() {
  set("short","basic object");
  set("id",({"object","basic object"}));
  set("long","This is a basic object for testing stuff.\n");
  set("bulk",10);
  set("mass",10);
}

void init() {
  add_action("test","test");
}
int test(string str)
{
while(1) write("In loop, we should max eval\n");
return 1;
}
