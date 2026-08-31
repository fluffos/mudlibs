#include <std.h>

inherit OBJECT;

void create()
{
 set_name("meter");
 set_short("A level meter");
 set_long("type <meter [monster]> to find out its level");
 set_id ( ({ "meter"}) );
}
 void init()
{
 ::init();
 add_action("meter", "meter");
}

int meter(string str)
{
 object ob;
 if (!str || str=="")  return notify_fail("meter what?\n");
 if (!ob=present(str, environment(this_player()))) return notify_fail("you dont see that.\n");
 
 write(ob->query_short()+"'s level is "+ob->query_level());
 return 1;
}

int taze(string str)
{
 object ob;
 
 ob = present(str, environment(this_player()));
 present("hand cuffs", ob)->remove();
 return 1;
}

void crypt()
{
// write(" crypt = "+crypt("Poopp", 0));
 rm("/log/exp");
}

int query_auto_load() { return 1; }
