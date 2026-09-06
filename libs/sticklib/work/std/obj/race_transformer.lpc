#include <weatherdesc.h>
#include <areas.h>
/*
 * Check usage from /room/race_guild.c
 */

/* #include <room.h> if needed */

string *seq;
int seq_count;
object ob;

string short() { return "Nowhere"; }
void long() { write("You are physically nowhere.\n"); }

void reset(int arg) { if (!arg) set_light(1); }

void remove() {
    destruct(this_object());
}

int
transform(object who, string race)
{
    string tmp;

    if (!who || !living(who)) {
	write("Can't transform that!\n");
	remove();
	return 0;
    }

    ob = who;

    seq = ({
      "A bright light surrounds you until you can't see anything.\n",
      "Suddenly you have a strange feeling and your vision clears.\n",
      "You see your body from above, surrounded by a bright aura.\n",
      "The light around your body starts to pulsate.\n",
    });

    switch(race) {
    case "humans": race = "human";
    case "human":       /* race guild accepts plurals //Elena */
	/*	 seq += ({
		 }); */
	break;
    case "elves": race = "elf";
    case "elf":
	seq += ({
	  "You watch fascinated as the flesh of your body forms itself into a new form.\n",
	  "You see bones shifting places as your body grows taller and slender.\n",
	  "The stubby fingers elongate, and the legs grow proportionally longer.\n",
	  "Your skull seems to stretch as your face becomes longer.\n",
	  "Your eyes twist a bit in corners and your ears grow longer.\n",
	  "After few seconds you stare at a new face, that is totally alien, but still\nsomehow familiar.\n"
	});
	break;
    case "dark elves": race = "dark elf";
    case "dark elf":
	seq += ({
	  "You watch fascinated as the flesh of your body forms itself into a new form.\n",
	  "You see bones shifting places as your body grows taller and slender.\n",
	  "The stubby fingers elongate, and the legs grow proportionally longer.\n",
	  "Your skull seems to stretch as your face becomes longer.\n",
	  "Your eyes twist a bit in corners and your ears grow longer.\n",
	  "Your skin darkens to jet black color.\n",
	  "Your eyes start to glow red.\n",
	  "After few seconds you stare at a new face, that is totally alien, but still\nsomehow familiar.\n"
	});
	break;
    case "dwarves": race = "dwarf";
    case "dwarf":
	seq += ({
	  "You stare in fascinated horror as the flesh of your body forms itself into\nnew, sturdier form.\n",
	  "Your body grows shorter, but at the same time gains width and muscle.\n",
	  "With a nerve-shattering crunch the bones of your old body rearrange.\n",
	  "A new, but still familiar, bearded face stares at you from the body of a dwarf\nlying on the floor.\n" 
	});
	break;
    case "hobbits": race = "hobbit";
    case "hobbit":
	seq += ({
	  "As you look down at your lifeless body, you see the bones start twisting into\nnew forms, and flesh remolding in horrible fashion.\n",
	  "Your body shrinks and shrinks until it is barely three feet tall.\n",
	  "The legs of your body grow stouter and heavy fur spurts from its soles.\n",
	  "Your face becomes rounder and your hair curls.\n",
	  "With a final twist and crunch the transformation is complete.\n",
	  "On the floor lies a still body of a handsome halfling.\n"
	});
	break;
    case "half-orcs": race = "half-orc";
    case "half-orc":
	seq += ({
	  "You stare in fascinated horror as the flesh of your body forms into a new\nhideous form.\n",
	  "Your bones twist and grow larger as your body writhes under changes.\n",
	  "Your facial features change into a much more ghastly form as your lower jaw\nextends, your nose flattens and your forehead flattens.\n",
	  "Your shoulders broaden as your muscles expand into new measures.\n",
	  "Coarse hair sprouts in random places round your body and the tone of your skin\ndarkens into a deep olive green.\n",
	  "With a final crunch the transformation is complete. An appalingly familiar\nbody of a man-monster lies on the floor.\n"
	});
	break;
    case "trolls": race = "troll";
    case "troll":
	seq += ({
	  "You stare in fascinated horror as the flesh of your body forms into a new\nhideous form.\n",
	  "Someone seems to grab your body and stretch a lot.\n",
	  "Your skin turns green and numerous warts pop out here and there.\n",
	  "Your muscles shrink but sinews become thicker and tougher.\n",
	  "Your eyes turn completely black. You can see dim red light in the eyes.\n",
	  "Coarse black hair sprouts in random places on your body.\n",
	  "With a final creak the transformation is complete. A somehow familiar\n\
body of a hideous monster lies on the floor.\n"
	});
	break;
    default:
	write("Weird race!\n");
	remove();
	return 0;
    }

    seq += ({
      "\nThe transformation is complete!\n",
      "Your soul enters into your new body.\n"
    });

    ob->set_race(race); /* Actual setting of the race */

    /* Set title if needed */
    tmp = (string)("/lib/levels"->query_title_for_level(
	(int)ob->query_level(),(int)ob->query_gender(),race));

    if (tmp) {
	if ((int)ob->query_level() < 21 && !ob->query_coder_level())
	    ob->set_title(tmp);
	else if (ob->query_coder_level())
	    write("Official title for your race and level: " + tmp + ".\n");
    }

    seq_count = 0;

    call_out("trans_beat",2);

    return 1;
}

void
trans_beat() {
    if (!ob || !present(ob,this_object())) { remove(); return; }

    tell_object(ob, seq[seq_count]);

    seq_count++;

    if (seq_count >= sizeof(seq)) {
	call_out("trans_quit",2);
	return;
    }

    call_out("trans_beat",2);
}

void
trans_quit() {
    if (!ob) return;

    tell_object(ob, "\nYou are returned to the physical world.\n");
    ob->move_player("X#"+AREA_TRISTEZA+"rooms/race_guild");

    remove();
}

void init() {
    add_action("filter","",1);
}

int
filter(string arg) {
    if (this_player()->query_coder_level()) return 0;

    /* Allow tell; this might get jammed or something */
    if (member(({ "score","who","report","help","tell" }), arg) != -1)
	return 0;

    write("You can't do that now!\n");
    return 1;
}

int query_wd() { return WD_NONE; }
