/*
 * /bin/daemons/deathd.c
 *
 * Dying is supposed to be funny!
 *
 * Call function die(object ob) to do some stunt at death. Like
 * "Graah says: Aarrgh, and dies."
 *
 * Added some randomness //Frobozz
 */
#include <tell_me.h>

inherit "/lib/find_name";

#define TR(x) environment(ob)->tell_here(x, 0, TELL_TYPE_DEATH, ({ ob }))
#define ARB(x) (x)[random(sizeof(x))]
#define DIES ARB(({ "dies","deceases","demises","departs","passes away" }))

void
die(object ob)
{
    string n, his;

    if (!ob) return 0;

    n = find_name(ob, 1);
    his = (string)ob->query_possessive();

    switch(random(27)) {
    case 1:
	TR("The last attack was just too much for " + n + ", who "+DIES+".");
	break;
    case 2:
	TR("All damage and no heal makes " + n + " a very dead " +
	  ((int)ob->query_gender() == 2 ? "girl" : "boy") + "!");
	break;
    case 3..10:
	TR(n + ARB(({
	      " answers the final summons.",
	      " answers the last call.",
	      " beams up.",
	      " is no more.",
	      " bites the big one.",
	      " climbs the golden staircase.",
	      " crosses over the great divide.",
	      " drops off the hooks.",
	      " goes on to a better world.",
	      " kisses the dust.",
	      " joins the angels.",
	      " has the strange feeling (the body seen from above and so on...you know).",
	      " lies down the knife and fork.",
	      " gives up the ghost.",
	      ", with this much punishment, finds living too difficult and is gone.",
	      " is totally worn out and "+DIES+".",
	      ", with fatal injuries, croaks.",
	      " declines from this world.",
	      " departs from this life.",
	      " expires for now.",
	      " is languished.",
	      " "+DIES+". See you in next incarnation.",
	      " pops off. The bigger they are, the harder they fall.",
	      " snuffs it.",
	      " starts the great journey over the Astral Plane.",
	      " slips the cable. The end.",
	      " stops. Permanently.",
	      " declines from this world.",
	      " "+DIES+".",
	      ARB(({ " falls down"," collapses" }))+", twitches for a couple of seconds and then lays still.",
	      " gasps once, then "+ARB(({ "falls down","collapses" }))+" and "+DIES+".",
	      ARB(({ " falls down"," collapses" }))+", dead.",
	      " says: Aarrgh, and "+DIES+".",
	      " sways for a while, looking for a place to die. And then dies.",
	      " dies standing, then "+ARB(({ "falls down","collapses" }))+".",
	      ARB(({ " falls down"," collapses" }))+" into a messy pile of remains.",
	      " screams: Aargh, they got me! And then "+DIES+".",
	      " is finished.",
	      " whispers: \"Bury my heart at Wounded Knee\", then "+DIES+"."
	    })));
	break;
    case 11:
	TR("Rest in pieces, " + n + "! Totally extinct.");
	break;
    case 12:
	TR(n + " breathes " + his + " last.");
	break;
    case 13:
	TR(n + " decides to begin " + his + " decaying process.");
	break;
    case 14..16:
	TR(n + " decides to withdraw into " +
	  ARB(({ "Happy Hunting Grounds", "Hades",
	      "Nirvana", "Limbo", "Abyss",
	      "Acheron", "Manala", "Tuonela",
	      "Hell", "Land of the Living Death" })) + ". Bye-bye!");
	break;
    case 17:
	TR("All this damage was too much for poor " + n +
	  ", who kicks the bucket.");
	break;
    case 18:
	TR(n + " is now a late " + n + ".");
	break;
    case 19:
	TR("Another one (" + n + ") bites the dust!");
	break;
    case 20:
	TR(n + " hastily writes " + his +
	  " last will and testament, and "+DIES+".");
	break;
    case 21:
	TR(n + " quickly writes a letter to " + his +
	  " " + ({ "family", "old mother" })[random(2)] + " , then "+DIES+".");
	break;
    case 22:
	TR(n + " dies with " + his + " boots on.");
	break;
    case 23:
	TR(n + " coils up " + his + " ropes.");
	break;
    default:
	TR(n + " ceases to exist, leaving just a " +
	  ARB(({ "bloody ", "mangled ", "crushed ", "deformed ",
	      "disfigured ", "hacked ", "maimed ",
	      "mutilated ", "twisted ", "wrecked ", "" })) +
	  ARB(({ "corpse", "cadaver", "deader", "stiff" }))+".\n");
	break;
    }
}
