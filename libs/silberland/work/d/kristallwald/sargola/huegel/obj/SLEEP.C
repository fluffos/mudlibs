inherit "std/thing";
#include <properties.h>

nix();

void create()
{
   if (!is_clone(this_object())) return;
   ::create();

   SetProp(P_SHORT, 0);
   SetProp(P_WEIGHT, 0);
   AddId(({"\nsleep"}));
}


init()
{
	add_action("nix","",1);
	::init();
}
nix()
{
	write("Du schlaefst doch gerade!\n");
	return "";
}



