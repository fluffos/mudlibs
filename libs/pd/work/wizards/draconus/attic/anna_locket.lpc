#include <std.h>

inherit ARMOUR;

int locket;

void create() {
    ::create();
    set_id(({"locket","anna locket"}));
    set_name("locket");
    set_short("%^YELLOW%^Anna's Locket%^RESET%^");
    set_long((:this_object(),"look_locket":));
    set_mass(10);
    set_value(0);
    set_ac(0);
    set_limbs(({"head"}));
    set_property("no steal", 1);
}

void init() {
    ::init();
    add_action("open_locket","open");
    add_action("close_locket","close");
}

int query_auto_load() { return 1; }

int open_locket(string str) {
    if (!str || !id(str)) return 0;
    if (locket) {
	write("The locket is already open.");
	return 1;
    }
    write("%^BOLD%^You rub your locket softly.");
    say("%^BOLD%^"+this_player()->query_cap_name()+" rubs "+
      this_player()->query_possessive()+" locket softly.");
    call_out("open_locket2", 5, this_player());
    return 1;
}

int open_locket2(object tp) {
    tell_object(tp,
      "%^BOLD%^You slowly open your locket.");
    tell_room(environment(tp), "%^BOLD%^"+tp->query_cap_name()+
      " slowly opens "+tp->query_possessive()+" locket.", ({tp}));
    call_out("open_locket3", 5, tp);
    return 1;
}

int open_locket3(object tp) {
    tell_object(tp,
      "%^BOLD%^CYAN%^The ghost of Dennis appears and envelops you completely.");
    tell_room(environment(tp),
      "%^BOLD%^CYAN%^The ghost of "+tp->query_cap_name()+"'s lost love "+
      "appears and envelopes "+tp->query_objective()+" completely.", ({tp}));
    locket = 1;
    return 1;
}

int close_locket(string str) {
    if (!str || !id(str)) return 0;
    if (!locket) {
	write("The locket is not open.");
	return 1;
    }
    write("%^BOLD%^CYAN%^As you close your locket, the ghost of "+
      "Dennis returns to its home.");
    say("%^BOLD%^CYAN%^As "+this_player()->query_cap_name()+" closes "+
      this_player()->query_possessive()+" locket, the ghost of "+
      this_player()->query_possessive()+" long lost love returns to its home.");
    locket = 0;
    return 1;
}

string look_locket() {
    string res = "This locket is made of pure gold and was hand "+
    "carved by Dennis.  It was a gift to his beloved wife, Anna.\n";
    if (locket)
	res += "It is open.";
    else
	res += "It is closed.";
    return res;
}
