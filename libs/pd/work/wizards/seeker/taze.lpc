#include <std.h>

inherit OBJECT;

void create()
{
 set_name("taze");
 set_short("tazer");
 set_long("dofijij");
 set_id ( ({ "tazer"}) );
}
 void init()
{
 ::init();
 add_action("taze", "taze");
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
