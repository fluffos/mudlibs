#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("");
    set_short("");
    set_long("Several glowing blue blades.");
    set_id(({ "__psiblades__","__blah__" }));
    set_weight(0);
    set_curr_value(0);
}
object ob;
string target;
string playermessage;
string roommessage;

int startblades(int strength)
{
    object room,o,tp;
    int i;

    tp=environment(this_object());
    ob=tp->query_current_attacker();
    room=environment(tp);

    if (strength == 0)
    {
	write("%^BOLD%^%^CYAN%^The bright blue energy blades wink out.%^RESET%^");
	this_object()->remove();
	return 1;
    }

    if (ob)
    {
	message("flame","%^BOLD%^%^CYAN%^The shards of energy spark as they slice into "+ob->query_cap_name()+".%^RESET%^",tp);
	message("flame","%^BOLD%^%^CYAN%^Bright blue shards of pure energy slice into you.%^RESET%^",ob);
	message("flame","%^BOLD%^%^CYAN%^Bright blue shards of pure energy slice into "+ob->query_cap_name()+".%^RESET%^",environment(ob),({tp,ob}));
	ob->add_hp(-strength);
    }
    strength--;
    call_out("startblades",10,strength);
    return 1;
}
