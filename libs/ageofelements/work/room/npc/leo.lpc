#include "/obj/living.h"
/*
 * This is the object which tries to behave like Leo the archwizard.
 * The purpose is to converse with players and give them portable castles.
 */

string next_out;
object next_dest;
int delay;

void wizard();

string short() { return "Leo the Archwizard"; }

void long() {
    write(short() + ".\n");
}

int id(string str) { return str == name; }

void reset(int arg) {
    if (arg)
	return;
    msgout = "leaves";
    msgin = "enters";
    name = "leo";
    cap_name = "Leo";
    next_out = 0;
    is_npc = 1;
    level = 40;
    alignment = 1000;
    weapon_class = WEAPON_CLASS_OF_HANDS;
    max_hp = 300;
    hit_point = 300;
    experience = 100;
    spell_points = 300;
    enable_commands();
}

void catch_tell(string str)
{
    object from;
    string a;
    string b;
    string c;
    from = this_player();

    if (!from) {
	return;	/* Not from a real player. */
    }

    if (sscanf(str, "%sello%s", a, b) == 2 ||
	sscanf(str, "%s hi%s", a, b) == 2 ||
	sscanf(str, "%s Hi%s", a, b) == 2) {
	next_out = "Leo says: Welcome, " + from->query_name() + ".\n";
        delay = 2;
	next_dest = from;
	set_heart_beat(1);
	return;
    }

    if (sscanf(str, "%smake%swizard%s", a, b, c) == 3 ||
        sscanf(str, "%swant%swizard%s", a, b, c) == 3) {
        if (from->query_level() == 20) {
	    wizard();
            return;
        }
        next_out = "Leo says: You want to be a wizard!? You have not earned it!\n";
        next_dest = from;
        delay=2;
        set_heart_beat(1);
        return;
    }

    if (sscanf(str, "%s gives %s to Leo.", a, b) == 2) {
	object ob;
	ob = present(b, this_object());

	if (!ob || !ob->id("orc slayer")) {
	    return;
	}

	next_out = "Leo says: Well done. You have fullfilled this quest.\n";
	next_dest = from;
	set_heart_beat(1);

	from->set_quest("orc_slayer");
	destruct(ob);
	return;
    }

    log_file("LEO", str + "\n");
}

/*
 * Always let the heart_beat do the talking, to simulate delay.
 */
void heart_beat()
{
    age += 1;

    if (attacker_ob) {
	spell_name = "a blazing fireball";
	spell_cost = 1;
	spell_dam = 30;
    }

    attack();

    if (random(80) == 1) {
	say("Leo smiles.\n");
    }

    if (delay > 0) {
        delay -= 1;
        return;
    }

    if (next_out) {
	tell_object(next_dest, next_out);
	next_out = 0;
    }

    if (!attacker_ob && !alt_attacker_ob) {
	set_heart_beat(0);
    }
}

void wizard() {
    write(
"You are now ready to take the step into true wizardhood. But, to do this,\n");
    write(
"you must select one wizard that will take responsibility for you.\n");
    write(
"He must also back up your claim of being a wizard, not by cheating.\n");
    write("If you have no name so far, come back here again.\n");
    write("Now give me the name: ");
    input_to("castle2");
}

void wizard2(string back_up_wiz) {
    string player_name;
    string save_name;
    int save_level;

    if (back_up_wiz == "") {
	write("Welcome back.\n");
	return;
    }

    back_up_wiz = lower_case(back_up_wiz);
    save_name = name;
    save_level = level;

    if (!restore_object("players/" + back_up_wiz)) {
	write("There is no player with that name.\n");
	return;
    }

    name = save_name;

    if (level < 20) {
	write("That player is not full wizard!\n");
	level = save_level;

	return;
    }

    level = save_level;
    player_name = this_player()->query_name();
    log_file("SPONSOR", back_up_wiz + ": " +
	this_player()->query_name() + " " + ctime(time()) + "\n");
    tell_object(this_player(),
	"Congratulations, you are now a wizard!\n");
    this_player()->set_level(21);
    this_player()->set_title(" the wizard");
}
