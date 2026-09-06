/*
 * Descriptions daemon
 *
 * Functions:	string query_str_desc(int x)
 *		string query_dex_desc(int x)
 *		string query_con_desc(int x)
 *		string query_int_desc(int x)
 *		string query_ab_desc(int Str, int Dex, int Con, int Int)
 *		string query_al_title(int alignment)
 *		string query_mud_name()
 *
 * varargs string hp_desc(object ob, int mode)
 *
 * string query_rnd_bleed_desc()
 */
#include <alignment.h>
#include <stats.h>
#include <mud_name.h>
#include <city_name.h>

#define MAX_AB 50
#define CMPCNT 6    /* compare count */
#define MAX_NEG (2*CMPCNT)  /* max negative adjective */



#include <conditions.h>

string *str_desc, *int_desc, *dex_desc, *con_desc;
string *comp_desc;
string *bleed_desc;
string *aa;
int *als;

nomask void
create() {
    str_desc = ({
      "scrawny", "undeveloped", "puny", "weak", "muscled", "strong",
      "giant-like", "titan-like", "collosic", "titanic" });
    con_desc = ({
      "meek", "sickly", "unhealthy", "frail", "healthy", "vigorous",
      "resistant", "invigorated", "pumped", "buff" });
    dex_desc = ({
      "sloth-like", "unresponsive", "slow", "clumsy", "agile",
      "dextrous", "fast", "quick", "nimble", "rapid" });
    int_desc = ({
      "peonic", "moronic", "stupid", "dumb", "smart", "clever",
      "intelligent", "ingenious", "visionary", "omniscient" });
    comp_desc = ({ "somewhat ", "rather ", "","quite ","very ","extremely " });

    bleed_desc = ({
      "You are unable to move and bleed slowly to death.",
      "Your mortal injuries are terribly painful.",
      "The pain is unbearable. You are weakened.",
      "You are slowly bleeding to death...",
      "You wish your wounds would stop BLEEDING so much!",
      "It's hard to breathe with blood in your throat and lungs.",
      "Isn't anyone going to help? You are terribly hurt!",
      "You are mortally wounded. You should seek help!",
      "Everything is dark. You know you will die soon."
    });

    als = ({ AL_ANGELIC * AL_RATIO / 100, AL_SAINTLY * AL_RATIO / 100,
      AL_VERY_GOOD * AL_RATIO / 100,
      AL_GOOD * AL_RATIO / 100, AL_QUITE_GOOD * AL_RATIO / 100,
      AL_VERY_NICE * AL_RATIO / 100,
      AL_NICE * AL_RATIO / 100, AL_QUITE_NICE * AL_RATIO / 100,
      AL_QUITE_NASTY * AL_RATIO / 100,
      AL_NASTY * AL_RATIO / 100, AL_QUITE_EVIL * AL_RATIO / 100,
      AL_EVIL * AL_RATIO / 100, AL_VERY_EVIL * AL_RATIO / 100,
      AL_DEMONIC * AL_RATIO / 100, AL_SATANIC * AL_RATIO / 100  });

    aa = ({  "Angelic", "Saintly", "Very Good", "Good", "Quite Good",
      "Very Nice", "Nice", "Quite Nice", "Neutral",
      "Quite Nasty", "Nasty", "Very Nasty",
      "Evil", "Very Evil", "Demonic", "Satanic" });

}

nomask string
query_str_desc(int x) {
    string dummy;
    if (x > MAX_AB) {
	x = MAX_AB;
	dummy = "more than ";
    }
    else dummy = "";
    if (x < 1) x = 1;
    x--;

    return dummy + comp_desc[(x < MAX_NEG) ? (CMPCNT - 1 - (x % CMPCNT)) : (x % CMPCNT)]
    + str_desc[x / CMPCNT];
}

nomask string
query_dex_desc(int x) {
    string dummy;
    if (x > MAX_AB) {
	x = MAX_AB;
	dummy = "more than ";
    }
    else dummy = "";
    if (x < 1) x = 1;
    x--;

    return dummy + comp_desc[(x < MAX_NEG) ? (CMPCNT - 1 - (x % CMPCNT)) : (x % CMPCNT)]
    + dex_desc[x / CMPCNT];
}

nomask string
query_con_desc(int x) {
    string dummy;
    if (x > MAX_AB) {
	x = MAX_AB;
	dummy = "more than ";
    }
    else dummy = "";
    if (x < 1) x = 1;
    x--;

    return dummy + comp_desc[(x < MAX_NEG) ? (CMPCNT - 1 - (x % CMPCNT)) : (x % CMPCNT)]
    + con_desc[x / CMPCNT];
}

nomask string
query_int_desc(int x) {
    string dummy;
    if (x > MAX_AB) {
	x = MAX_AB;
	dummy = "more than ";
    }
    else dummy = "";
    if (x < 1) x = 1;
    x--;

    return dummy + comp_desc[(x < MAX_NEG) ? (CMPCNT - 1 - (x % CMPCNT)) : (x % CMPCNT)]
    + int_desc[x / CMPCNT];
}

nomask string
query_ab_desc(int Str, int Dex, int Con, int Int)
{
    return (query_str_desc(Str) + ", " +
      query_dex_desc(Dex) + ", " +
      query_con_desc(Con) + " and " +
      query_int_desc(Int) + ".");
}

nomask void
desc_me(object ob) {
    if (!ob) ob = this_player();

    this_player()->tell_me("You are "+
      query_ab_desc((int)ob->query_stat(ST_STR),
	(int)ob->query_stat(ST_DEX),
	(int)ob->query_stat(ST_CON),
	(int) ob->query_stat(ST_INT)) );
}

/*
 * mode 0 : "He/She/It is in some condition" (default)
 * mode 1 : "You are in some condition"
 *
 */

#define HP_DESC_NO 17

nomask varargs string
hp_desc(object ob, int mode)
{
    int hp, mhp, x;

    hp  = (int)ob->query_hp();
    mhp = (int)ob->query_max_hp();

    /* Kludge with players, as they might have negative hp */
    if (!ob->query_npc()) {
	hp  += mhp / 3;
	mhp += mhp / 3;
    }

    if (hp < 0) hp = 0;

    x = (hp * HP_DESC_NO) / mhp;

    if (x < 0) x = 0;
    if (x > (HP_DESC_NO - 1)) x = (HP_DESC_NO - 1);

    if (mode == 1) {
	return "You " + ({
	  "are at death's door",
	  "are barely alive",
	  "are in critical condition",
	  "are mortally wounded",
	  "are bleeding awfully from many wounds",
	  "are seriously injured",
	  "are badly injured",
	  "are seriously wounded",
	  "are badly wounded",
	  "are wounded",
	  "are somewhat wounded",
	  "are badly bruised",
	  "are bruised",
	  "have some minor scratches and bruises",
	  "have some minor scratches",
	  "are fine",
	  "are in an excellent condition"
	})[x] + ".\n";
    }

    return capitalize((string)ob->query_pronoun()) + " " + ({
      "is at death's door",
      "is barely alive",
      "is in critical condition",
      "is mortally wounded",
      "is bleeding awfully from many wounds",
      "is seriously injured",
      "is badly injured",
      "is seriously wounded",
      "is badly wounded",
      "is wounded",
      "is somewhat wounded",
      "is badly bruised",
      "is bruised",
      "has some minor scratches and bruises",
      "has some minor scratches",
      "is fine",
      "is in an excellent condition"
    })[x] + ".\n";

}

nomask string
ac_desc(object ob)
{
    int a;

    a = (int)ob->query_ac() / 4;

    if (a < 0) a = 0;
    if (a > 9) a = (10 + ((a - 10) / 3));
    if (a > 15) a = 15;

    return capitalize((string)ob->query_pronoun()) + " has " +
    ({
      "a really poor defence.\n",
      "a poor defence.\n",
      "an average defence.\n",
      "a good defence.\n",
      "a very good defence.\n",
      "an excellent defence.\n",
      "an extremely good defence.\n",
      "a mighty defence.\n",
      "a magical defence!\n",
      "an invincible defence!\n",
      "a defence like a yard thick steel plates!\n",
      "a defence like four yards of solid steel!\n",
      "a defence like a yard of solid Adamantium!\n",
      "a defence like four yards of solid Adamantium!\n",
      "a defence like TWENTY YARDS OF SOLID ADAMANTIUM!\n",
      "a defence that goes beyond all description!!!\n",
    })[a];
}

nomask string
wc_desc(object ob)
{
    int a;

    a = (int)ob->query_wc() / 5;

    if (a < 0) a = 0;
    if (a > 8) a = (9 + (a - 8) / 3);
    if (a > 12) a = 12;

    return capitalize((string)ob->query_pronoun()) + " " +
    ({
      "is harmless.\n",
      "is mostly harmless.\n",
      "is an average opponent.\n",
      "is a good fighter.\n",
      "is a dangerous opponent.\n",
      "is a deadly opponent.\n",
      "is a lord-killer opponent.\n",
      "is a BIG lord-killer opponent.\n",
      "is a killer machine!\n",
      "could kill a major dragon with one hit!\n",
      "could kill SEVEN dragons with one hit!\n",
      "could destroy a MOUNTAIN with one hit!\n",
      "could shred a CODER in one round!!!\n",
    })[a];
}

string
query_rnd_bleed_desc()
{
    return bleed_desc[random(sizeof(bleed_desc))];
}

//
// Enhanced alignment title 7-Jul-96 by Graah!
//
string
query_al_title(int alignment)
{
    int a, d;

    for (a = 0, d = -1; a < 14; a++)
	if (alignment > als[a])
	{
	    d = a;
	    break;
	}

    if (d == -1) d = 15;

    if (alignment < (3 * als[14])) return "Utterly " + aa[15];
    else if (alignment < (2 * als[14])) return "Extremely " + aa[15];
    else if (alignment < (15 * als[14] / 10)) return "Very " + aa[15];
    else if (alignment > (3 * als[0])) return "Utterly " + aa[0];
    else if (alignment > (2 * als[0])) return "Extremely " + aa[0];
    else if (alignment > (15 * als[0] / 10)) return "Very " + aa[0];

    return aa[d];
}

void
table()
{
    int i;

    for (i = 1; i < 52; i++)
	this_player()->tell_me(i + ": " + query_ab_desc(i,i,i,i));
}

// Better make it a shared global array, no need to rememer exact
// desc amount... can use sizeof. Besides, no need to re-construct
// the array _every time_ function is called.
string *mud_descs = ({
  MUD_NAME,
  MUD_NAME ": Nightmare on Main Street",
  MUD_NAME " II: Thousand and One Banishments",
  MUD_NAME " III: The Coder Wars",
  MUD_NAME " IV: The New Hope",
  MUD_NAME " V: " CITY_NAME " Strikes Back",
  MUD_NAME " VI: Return of the Lag",
  MUD_NAME " VII: Return of the Addicts",
  MUD_NAME " VIII: The Guild Wars",
  MUD_NAME " IX: The Whinefree Generation",
  "Raiders of the Lost " MUD_NAME,
  "Grossed Swords",
});

nomask string
query_mud_name()
{
    return mud_descs[random(sizeof(mud_descs))];
}
