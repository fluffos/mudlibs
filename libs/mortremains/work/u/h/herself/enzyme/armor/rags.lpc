
#include "mudlib.h"
#include "area.h"
inherit ARMOR;

void create(){
    set("id" , ({"rags" , "set of rags"}) );
    set("author" , "enzyme");
    set("short" , "a set of rags");
    set("long" , wrap(
	"These simple rags appear to be the same clothes that some "+
	"poor wretched soul was burried in. From the obvious condition "+
	"they are in, these rags are very old indeed. It is doubtful "+
	"if they would even provide any protection.  "
      ));
    set("mass" , 1);
    set_armor_type("clothing");
    set("size" , 6);
    set("value" , 5);
}
void init() {
    if(!living(environment(this_object())))
	call_out("remove" , 1);
}
void remove(){
    object ob = environment(this_object());
    if (ob)
	tell_room(ob,
	  "The rags crumble to dust and blow away.\n");
    ::remove();
}
