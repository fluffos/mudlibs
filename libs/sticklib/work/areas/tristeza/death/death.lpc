// death.c
// Mrpr 901120
// Original is obviously from LPmud 1.0...
// Cleaned up by Graah, and we are going to make it shout something funny
// occasionally.
// New: his scythe and robe are now real objects. Nice quest for
//   lords: try to steal them.
// Moved scythe and robe to separate files 10.5.1992 //Frobozz

#include <npc.h>
#include <areas.h>

object scythe,robes;

void
init_monster()
{
    add_action("take_it","take");
    add_action("take_it","get");
    add_action("take_it","steal");

    if (!scythe || environment(scythe) != this_object() &&
      !present("death_scythe", this_player())) {
	scythe=clone_object(AREA_TRISTEZA+"death/scythe");
	move_object(scythe,this_object());
	wield(scythe, 1);
    }
}

void
reset_monster()
{
    if (!scythe || environment(scythe) != this_object()) {
	scythe=clone_object(AREA_TRISTEZA+"death/scythe");
	move_object(scythe,this_object());
	wield(scythe, 1);
    }
    if (!robes || environment(robes) != this_object()) {
	robes=clone_object(AREA_TRISTEZA+"death/robe");
	move_object(robes,this_object());
	wear(robes, 1);
    }
}

void
create_monster()
{
    set_name("death");
    set_id(({ "moot", "scythe", "robe" })); /* ME m(w)t */
    set_living_name("death");
    set_level(500);
    set_race("immortal");
    set_short("Death, clad in black");
    set_long(
      "Death seems to have taken Jane Fonda's exercise and diet program much \
too seriously. An unclear case of Anorexia Nervosa. It carries a wicked- \
looking scythe and is dressed in a black hooded robe that suits him \
quite well. There's something about his eyes as well, or maybe the \
lack of eyes, that you feel you'd better not investigate too closely.");

    call_out("remark",2000 + random(300) + random(240));

    set_spell_chance(25);
    set_spell_mess2("Death stares at you and your heart nearly stops.");
    set_spell_mess1("Death is getting angry.");
    set_spell_dam(100);

    set_ep(5000000); /* This cannot be gained anyway. */
    reset_monster();
}

/* Immune to all attacks. Much easier to implement now, isn't it! */
status
query_is_immune_vs_ob(object ob, int type)
{
    return 1;
}

/* Yes, very easy! Especially when it does not work. */
/* This does. */
varargs int
hit_player(int dam, int t, mixed hc, object enemy)
{
    return 0;
}

/* Now you can look at scythe and robe without "Scythe/Robe is carrying:"
   message //Frobozz */
status
can_put_and_get(string str)
{ 
    if (id(str) && str != "scythe" && str != "robe")
	return 1;
    return 0;
}

varargs string
query_long(string str, object who)
{
    /* Now you CAN look at scythe and robe //Frobozz */
    if (str == "scythe" && scythe && environment(scythe) == this_object())
	// Some checks were needed. -+ Doomdark +-
	return
	"An extermely sharp scythe. It's so sharp that gusts of wind actually try\
 to turn away from the edge rather than be sliced in two by the wicked-looking\
 blade. It does strange things with light as well as unlucky\
 photons halve their amplitudes when they hit the blade.";
    if (str == "robe" && robes && environment(robes) == this_object()) return
	"A black hooded robe with numerous pockets. It wouldn't certainly fit you\
 very well however. It seems to have been tailored for a very lean\
 customer. VERY lean indeed...";
    return ::query_long(str, who);
}

status
take_it(string str)
{
    string name;
    int extra;
    object ob;

    if (!str) return 0;

    if (sscanf(lower_case(str),"%s from death",name)) str = name;

    name = capitalize((string) this_player()->query_real_name());
    extra = random(90) + 50;

    if (str != "scythe" && str != "robe") return 0;

    if (!this_player()->query_ghost()) {
	if(query_verb() == "get" || query_verb() == "take") return 0;
	if (!(ob = present(str,this_object()))) {
	    this_player()->tell_me("Death seems to have lost his " + str + " already.");
	    return 1;
	}
	if (this_player()->query_quests("golem_quest") ||
	  present("death_scythe", this_player())) {
	    this_player()->tell_me("You failed to steal that.");
	    return 1;
	}
	this_player()->tell_me("Ok. You manage to get the " + str + " from Death!");
	if (!this_player()->add_weight((int) ob -> query_weight())) {
	    this_player()->tell_me("Oops, the " + str + " was too heavy\
 and you dropped it.");
	    environment()->tell_here((string) this_player()->query_name()
	      + " dropped the " + str + ".", this_player());
	    move_object(ob,environment());
	} else move_object(ob, this_player());
	environment()->tell_here("Death looks confused.\n\
Death says: HUH? WHAT'S THIS?");
	return 1;
    }
    this_player()->tell_me(
      "You take a firm grip on the " + str + " and try to pull it towards\
 you.\nDeath frowns, raps you smartly across your fingers with a bony\
 hand and says: STUPID MORTAL. YOU JUST EARNED " + extra + " EXTRA YEARS\
 IN PURGATORY!");
    return 1;
}

void
remark_someone(object ob)
{
    string tmp,name;
    int x;

    if (!ob) return;

    name = upper_case((string) ob->query_real_name());

    x = random(4);

    switch(x)
    {
    case 1:
	tmp = "MY DEAR FRIEND " + name + ", YOU HAVEN'T " +
	"VISITED ME FOR A LONG TIME!";
	break;
    case 2:
	tmp = "I HOPE YOU ARE GOING TO VISIT ME SOON, MY DEAR " + name + "!";
	break;
    case 3:
	tmp = "I AM LONELY! PERHAPS YOU, " + name +
	", WILL COME TO ME SOON!";
	break;
    case 4:
	tmp = "WELL WELL, MY ORACLE HERE SAYS THAT YOU, " + name +
	", MIGHT GET THE STRANGE FEELING IN NEAR FUTURE...";
    default:
	return;
    }

    ob->tell_me("Death tells you: " + tmp);
}

void
remark()
{
    int i, s;
    object *ob;

    /* Was far too often (too few players) //Frobozz */
    /* Yes, and still too often //Graah */
    call_out("remark", 5000 + random(1200) + random(1200));

    ob = users();

    for(i = 0, s = sizeof(ob); i < s; i++) {
	if (!ob[i]->query_coder_level()) {
	    if (!random(s + 2)) {
		remark_someone(ob[i]);
		break;
	    }
	}
    }
}

void
catch_tell(string str)
{
    object who;
    string whom,what;

    who = this_player(); if(!who) return;

    if (sscanf(str,"%s tells you: %s",whom,what)!=2) return;

    if (random(100) < 50)
	who->tell_me("Death tells you: DO NOT EVER SPEAK TO ME AGAIN!");
    else
	who->tell_me("Death tells you: HOW DARE YOU TO SPEAK TO ME!");
}
