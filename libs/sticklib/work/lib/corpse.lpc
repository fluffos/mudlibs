/*
 * This is a decaying corpse. It is created automatically
 * when a player or monster dies.
 */

#include <daemons.h>
#include <living_defs.h>

#define DECAY_TIME	120
// 100 normal, <100 slower, >100 faster
#define DECAY_SPEED     25

string name, orig_name, short_desc;
int mummy; /* Necros */
int decay, decay_speed, orig_level, was_player;
string orig_race; /* Added this one 31-apr-94. -Doomdark. */
object killer;
int desting;

status get() { return 1; }
status is_corpse() { return 1; }

/* Now we can make special corpses (like ones that decay slower), and they
   will still be just like the real ones 20.6.1993 //Frobozz */

query_real_corpse() { return 1; }

varargs string
query_name(object who) { return (string) this_object()->query_short(who); }

int query_weight() {
    object *inv;
    int rets, i;
    inv = all_inventory(this_object());

    // Since we're calling recount_weight while this is still in inventory
    // If we're desting, let's return 0 to ignore this.
    if (desting) return 0;

    if (inv)
	for (i = 0; i < sizeof(inv); i++) {
	    rets += inv[i]->query_weight();
	}
    if (mummy) return rets + ( 1 + orig_level / 10);
    if (orig_level)
	return rets + ( 1 + orig_level / 5 );
    return rets + 5;
}
/* Original living's values */
string query_orig_name() { return orig_name; }
int query_orig_level() { return orig_level; }
int query_mummification() { return mummy; }
int set_mummification(int x) { mummy = x; }
string query_orig_race() { return orig_race; } /* Added by Doomdark 31-apr-94. */
status query_was_player() { return was_player; }

string query_short_desc() { return short_desc; }
/* How decayed? */
int query_decay() { return decay; }
int query_decay_speed() { return decay_speed; }
/* Killer (players who go LD or logout won't be known) */
/* Why? Shouldn't we use name instead of object-pointer? -Doomdark. */
// This is really weird: if killed object was an npc, 'killer' is an object,
// but if it was a player, 'killer' contains killer's name - Chopin
object query_killer() { return killer; }

/* With this you can set the short desc of a fresh corpse,
   f.g. "Halfeaten corpse of " 23.3.1993 //Frobozz */
void set_short_desc(string str) { short_desc = str; }
void set_orig_name(string x) { orig_name = x; }
void set_orig_level(int x) { orig_level = x; }
void set_orig_race(string x) { orig_race = x; }
/* Was a player? (Needed for poison of thieves //Graah :-) */
void set_was_player(int x) { was_player = x; }
/* Use this, less call_others this way. -Doomdark 31-apr-94. */
void
set_orig_attributes(string oname, int olevel, string orace, int pl) {
    orig_name = oname;
    orig_level = olevel;
    orig_race = orace;
    was_player = pl;
}
void set_decay(int d) { decay = d; }

void
set_decay_speed(int arg) {
    if ((decay_speed = arg) <= 0)
	decay_speed = 1; // 100th of the normal decay speed
}
void set_killer(object ob) { killer = ob; }
void set_name(string n)
{
    name = n;
    call_out("decay", (DECAY_TIME*DECAY_SPEED)/decay_speed);
}

varargs string
query_short(int mode, object who)
{
    if (decay < 2) return "A pile of bones";
    if (decay < 3) return "A pile of rotting flesh";
    if (decay < 4) return
	"The somewhat decayed remains of " + capitalize(name);
    return short_desc + capitalize(name);
}

varargs string
query_long(string what, object who) {
    return (decay < 3) ?
    "These are the remains of someone or something." :
    "This is the dead body of " + capitalize(name) + "."
    ;
}

status
id(string str) {
    return str == "corpse" || str == "corpse of " + name ||
    str == "remains" || str == "pile" || str == "bones" ||
    str == "flesh" || str == "pile of bones" || str == "pile of flesh";
}

void
init() {
    add_action("search", "search");
}

void
create() {
    name = "Nobody";
    was_player = killer = 0;
    short_desc = "Corpse of ";
    decay = 5;
    decay_speed = DECAY_SPEED; // Normal decay speed
    desting = 0;
}

void decay() {
    if (mummy) return;
    decay -= 1;

    if (decay > 0) {
        if (find_call_out("decay") < 0)
            call_out("decay", (20*DECAY_SPEED)/decay_speed);
        return;
    }

    object env = environment();
    object ob;

    if (env && all_inventory(this_object())) {
        if (living(env))
            env->tell_me(query_name() + " turns to dust.");
        else
            env->tell_here(query_name() + " turns to dust.");

        while (ob = first_inventory()) {
            move_object(ob, env);

            // If the player holding the corpse is receiving new items in their inventory, update
            // their client if appropriate.
            if (env->query(LIV_IS_PLAYER) && env->query_env("gmcp")) {
                TELOPT_D->send_char_items_add(env, "inv", ob);
            }
        }

        // Update clients of players in the room that there are new items around them
        if (!living(env)) {
            foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
                if (you->query_env("gmcp")) {
                    TELOPT_D->send_char_items_list(you, "room");
                }
            }
        }

        desting = 1;

        while (env) {
            env->recount_weight();
            env = environment(env);
        }
    }

    // Remove the destructing corpse from the client information
    if (!living(env)) {
        foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
            if (you->query_env("gmcp")) {
                TELOPT_D->send_char_items_remove(you, "room", this_object());
            }
        }
    } else if (env->query(LIV_IS_PLAYER) && env->query_env("gmcp")) {
        TELOPT_D->send_char_items_remove(env, "inv", this_object());
    }

    destruct(this_object());
}

status can_put_and_get() { return 1; }

string
search_obj(object ob)
{
    int total;
    string *found, tmp;

    if (call_other(ob, "can_put_and_get")) {
	ob = first_inventory(ob);
	while(ob) {
	    if (tmp = (string) ob -> query_name()) {
		if (!total++) found = ({});
		found += ({ tmp });
	    }
	    ob = next_inventory(ob);
	}
    }
    if (found) return "and find " + implode(found, ", ", " and ") + ".";
    else return "but don't find anything.";
}

status search(string str)
{
    object ob;
    if (!str || !id(str))
	return 0;
    ob = present(str, environment(this_player()));
    if (!ob) ob = present(str, this_player());
    if (!ob) return notify_fail("Search what?\n"), 0;
    this_player() -> tell_me("You search " + str + " " + search_obj(ob));
    environment(this_player()) -> tell_here(call_other(this_player(),
	"query_name") + " searches " + str + ".", this_player());
    return 1;
}
string short() { return query_short(0, this_player()); }
int add_weight(int x) { return 1; }
