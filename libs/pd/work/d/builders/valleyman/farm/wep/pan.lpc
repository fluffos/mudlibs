#include <farm.h>
inherit WEAPON;

create() {
    ::create();
   set_id(({ "pan", "fryingpan", "frying pan" }));
   set_name("fryingpan");
   set_short("a frying pan");
   set_long("A metal frypan. Looks heavy");
   set_weight(10);
   set_curr_value("copper", 10);
   set_wc(1);
   set_ac(1);
   set_type("blunt");
   set_wield("The frypan is heavy in your hands");
   set_unwield("You are glad to be rid of the oil");
}

void init()
{
 ::init();
 add_action("frypan", "frypan");
}

int frypan(string str)
{
 object ob;
 if (this_player()->is_player()) return 0;
 if (!str || str=="") return 0;
 ob = find_player(str);
 if (!ob) return 0;
 write("You fry-pan "+ob->query_cap_name());
 message("info", this_player()->query_cap_name()+" hits you with her frying pan.", ob);
 message("info", this_player()->query_cap_name()+" hits "+ob->query_cap_name()+" with her frying
pan.", environment(ob), ({ this_player(), ob }));
 ob->set_paralyzed("You were confused by the whack from the frypan.", 1);
 
}

