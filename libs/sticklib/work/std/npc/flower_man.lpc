/* Fixed some typos and added a weak solution for the good old church vs.
   monsters fight 22.12.1991 //Frobozz */
/* Fixed route in new village 27.8.1992 //Elena */

/* Since we don't have separate login object we are loosing
   target object on the way if player recovers link death.
   So, I added some lines here and there to fix the problem.
   //Tron.
 */

// Tidied up little. -+ Doomdark +-

#include <daemons.h>
#include <living_defs.h>
#include <npc.h>
#include "/areas/tristeza/DEFS.h"

#define HIM who->query_objective()

object who, where, sender, flowers;
string target_name, sender_name;
string rname;
int create_time;

void
set_sender(object obj)
{
    sender = obj;
}

void
set_sender_name(string str)
{
    sender_name = str;
}

void
set_who(object obj)
{
    who = obj;
    rname = (string) obj->query_real_name(obj); // ++Tron.
}

void
set_target_name(string str)
{
    target_name = str;
}

void
set_flowers(object obj)
{
    flowers = obj;
}

void
reset_monster()
{
    if (time() > (create_time + 300))
	destruct(this_object());
}

void
create_monster()
{
    create_time = time();
    set_name("delivery man");
    set_id(({ "deliverer", "man", "mudional delivery man" }));
    set_short("A Mudional Delivery man");
    set_level(19);
    set_ep(1);	// No exp to cheaters.
    set_long(
      "He is dressed in a white floral uniform that is incredibly clean. It is\
 quite obvious that he takes his job very seriously. Please dont try\
 to kill him. Good help is so hard to find these days. He looks at you\
 and says: 'These flowers will get through no matter what!'");
    set_wc(30);
    set_ac(30); /* Was 10 */
    set_hp(250);
    call_out("first_step",10);
}

status
check()
{
    object snd;
    if (!environment())
	destruct(this_object());
    else if (!who) {
	// Check if player changed object. ++Tron.
	if (!(who = find_player(rname))) {
	    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
		if (you->query_env("gmcp")) {
		    TELOPT_D->send_char_items_remove(you, "room", this_object());
		}
	    }

	    destruct(this_object());
	} else {
	    where = environment(who);
	    return 1;
	}
    } else {
	where = environment(who);
	return 1;
    }
    if (sender)
	sender -> tell_me(
	  "Delivery man tells you: Unfortunately I have been unable to deliver\
 flowers you sent to " + rname+". I'm really sorry...");
    return 0;
}

status
check2()
{
    if (environment(who) == environment()) {
	call_out("seventh_step", 4);
	return 0;
    }
    return 1;
}

void
first_step()
{
    if (!check()) return;

    environment() -> tell_here(
      "Delivery man says: Ok. I'm off with my delivery for "+target_name+".", this_object());

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_add(you, "room", this_object());
	}
    }

    if (check2())
	call_out("second_step",10);
}

void
second_step()
{
    if (!check() || !check2()) return;

    environment() -> tell_here("Delivery man leaves.", this_object());

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(you, "room", this_object());
	}
    }

    move_object(this_object(), CITY_DIR+"S3_7");

    environment() -> tell_here("Delivery man arrives.\n\
Delivery man says: Have you seen "+target_name+"? I have a delivery for " +
      HIM + ".", this_object());

    if (check2())
	call_out("third_step", 10);
}

void
third_step()
{
    if (!check() || !check2()) return;

    environment()->tell_here("Delivery man pulls out his map.\n\
Delivery man leaves.", this_object());

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_add(you, "room", this_object());
	}
    }

    move_object(this_object(), PUB);

    environment()->tell_here("Delivery man arrives.\n"+
      "Delivery man says: I have a package for "+target_name+
      ". Have you seen " + HIM + " around?", this_object());
    if (check2())
	call_out("fourth_step", 10);
}

void
fourth_step()
{
    if (!check() && !check2()) return;

    environment()->tell_here("Delivery man sigh deeply.\n\
Delivery man leaves.", this_object());

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(you, "room", this_object());
	}
    }

    move_object(this_object(), GENERAL_SHOP);

    environment() -> tell_here("Delivery man arrives.\n\
Delivery man says: Is "+target_name+" in here? I have a delivery for " +
      HIM + " and can't seem to locate "+HIM+" anywhere.", this_object());

    if (check2())
	call_out("fifth_step", 10);
}

void
fifth_step()
{
    if (!check() && !check2()) return;

    environment()->tell_here("Delivery man says: I think I've found "+HIM+"!\n\
Delivery man smiles happily.\nDelivery man leaves.", this_object());

    if (object_name(where) == "room/church" || object_name(where) == "/room/church")
	// For future compatibility. -+ Doomdark +-
	who -> tell_me(
	  "Delivery man tells you: I have a special delivery for you. Could you go south\
 for a moment? I will be there in a few seconds.");
    else
	who -> tell_me(
	  "Delivery man tells you: I have a special delivery for you. I'll be there in\
 a few seconds. Could you please stay there?");
    call_out("sixth_step", 5);
}

void
sixth_step()
{
    if (!check() && !check2()) return;
    who -> tell_me("Delivery man tells you: I'm almost there. Just one\
 more second.");

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(you, "room", this_object());
	}
    }

    move_object(this_object(), where);

    environment()->tell_here("Delivery man arrives.", this_object());

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_add(you, "room", this_object());
	}
    }

    call_out("seventh_step", 3);
}

void
seventh_step()
{
    if (!check()) return;

    if (where != environment()) {
	foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	    if (you->query_env("gmcp")) {
		TELOPT_D->send_char_items_remove(you, "room", this_object());
	    }
	}

	move_player("", where);

	foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	    if (you->query_env("gmcp")) {
		TELOPT_D->send_char_items_add(you, "room", this_object());
	    }
	}
    }

    environment()->tell_here(
      "Delivery man says: At last I've tracked you down, "+target_name+".\n\
Delivery man says: I have a delivery of flowers from "+sender_name+".\n\
Delivery man gives a bunch of flowers to "+target_name+".",
      ({ who, this_object() }));

    who->tell_me(
      "Delivery man says: At last I've tracked you down, "+target_name+".\n\
Delivery man says: I have a delivery of flowers from "+sender_name+".\n\
Delivery man gives a bunch of flowers to you.");

    if (flowers) {
	move_object(flowers, who);

	if (who->query(LIV_IS_PLAYER) && who->query_env("gmcp")) {
	    TELOPT_D->send_char_items_add(who, "inv", flowers);
	}
    }

    call_out("eighth_step", 3);
}

void
eighth_step()
{
    object ob;
    if (!check()) return;

    if (where != environment()) {
	foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	    if (you->query_env("gmcp")) {
		TELOPT_D->send_char_items_remove(you, "room");
	    }
	}

	move_player("", where);

	foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	    if (you->query_env("gmcp")) {
		TELOPT_D->send_char_items_add(you, "room");
	    }
	}
    }

    environment()->tell_here("Delivery man says: Dont forget to look\
 at the card.\n\
Delivery man waves at you.\n\
Delivery man leaves.");
    if (sender) // ++Tron.
	sender -> tell_me(
	  "Delivery man tells you: Your package has been delivered to "+target_name+".");
    while (ob = first_inventory(this_object()))
	destruct(ob);

    foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
	if (you->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(you, "room", this_object());
	}
    }

    destruct(this_object());
}

string query_ctrl() { return "flower shop"; }

// To allow entrance to many places... -+ Doomdark +-

void killed_by(object ob) {
    string name;
    if(ob)
	if(interactive(ob))
	    name=(string)ob->query_real_name();
	else
	    name=object_name(ob);
    log_file("FLOWER",name+" killed delivery man at "+ctime(time())+"\n");
}
