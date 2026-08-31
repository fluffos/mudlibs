#include <std.h>
inherit OBJECT;

void create()
{
 ::create();
   set_name("sign");
   set_short("A sign");
   set_long("A sign against pouting");
   set_prevent_get("No frickin pouting.  Put the sign down!");
   set_value(0);
   set_id(({ "sign" }));
}

int read(string str)
{
  if(str == "sign")
  {
	message("info", "No pouting in here!", this_player());
	return 1;
  }
  return 0;
}

int dest(string str)
{
  if(str == "sign")
  {
	message("info","NO POUTING!!!", this_player());
	return 1;
  }
  return 0;
}


void init()
{
 ::init();
   add_action("read", "read");
   add_action("dest","dest");
}
