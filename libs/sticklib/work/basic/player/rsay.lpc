/* rsay_cmd 23.11.1992 //Frobozz */

// Modified 16-aug-95 by Doomdark.

#ifndef PLAYER_C
#include <tell_me.h>
// Prototypes:

varargs void tell_me(string s, status x, status y);
varargs string query_name(int lvl, object who);
string query_race();
#endif

string
rmumble() {
    switch (query_race()) {
    case "elf": return "something in the graceful language of Elves.";
    case "dark elf": return "something by using obscene hand signs.";
    case "half-orc": return "something in the crude and savage language of Orcs.";
    case "dwarf": return "something in the coarse language of Dwarves.";
    case "troll": return "something obscene in Trollish grunts!";
    default: return "something.";
    }
}

int
check_understanding(object who) {
    return ((string) who->query_race() == query_race()
      || (int)who->query_coder_level());
}

string
rsay(string msg) {
    string rsay;
    switch((string)this_object()->query_race()) {
    case "elf":
	rsay="Elvish";
	break;
    case "dark elf":
	rsay="Hand Cant";
	break;
    case "half-orc":
	rsay="Orcish";
	break;
    case "dwarf":
	rsay="Dwarvish";
	break;
    case "troll":
	rsay="Trollish";
	break;
    default:
	rsay ="Westron";
	break;
    }
    return sprintf("in %s: %s", rsay, msg);
}

void
rcommunicate(string who, string msg) {
    object *env;
    int i;
    env=all_inventory(environment());
    for(i=sizeof(env)-1;i>=0;i--)
	if(env[i]!=this_object())
	    if(check_understanding(env[i]))
		env[i]->tell_me(sprintf("%s %s", who, rsay(msg)), 0, TELL_TYPE_SAY);
	    else
		env[i]->tell_me(sprintf("%s %s", who, rmumble()), 0, TELL_TYPE_SAY);
}

int
rsay_cmd(string str) {
    string verb;
    string dummy;
    /* No rsay for humans or hobbits */
    if (!(dummy = query_race())
      || dummy == "human"
      || dummy == "hobbit")
	return (int)this_object()->communicate(str);
    verb = query_verb();
    if (!str) str = "";
    else {
	if(sscanf(str,"PMF_CRYPTSAY:%s",dummy)==1) return 0;
    }
    if(verb[0] == "'"[0])
	str = "/secure/simul_efun/amylaar"->extract(verb, 1) + " " + str;

    // No need. set_connection_char() takes care of it.
    //  if((int)this_object()->dump_esc(str)) return 1;

    if (sizeof(str))
	switch (str[<1]) {
    case '?': dummy = "asks"; break;
    case '!': dummy = "yells"; break;
    default: dummy = "says";
    }
    else dummy = "says";

    if((int)this_object()->query_intoxication()) 
	str = (string)this_object()->mumble(str);
    tell_me("Ok.");
    if((int)this_object()->query_ghost()) {
	rcommunicate("A hollow voice "+dummy,str);
	return 1;
    }
    rcommunicate(sprintf("%s %s", query_name(), dummy), str);
    return 1;
}
