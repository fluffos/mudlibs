#include <npc.h>
#include <daemons.h>
#include <quests.h>
#include <generic_items.h>

// Updated 7-Sep-98 / Graah, for Sticklib-distribution

string next_out;
object next_dest;
object give_him_castle;
int delay;

void
create_monster()
{
    set_name("Leo");
    set_id(({ "leo", "archwizard", "leo the archwizard" }));
    set_race("human");
    set_short("Leo the Archwizard");
    set_long(
      "Leo is an old man, wearing white robes. He can probably throw meteor\
 warms and fireballs blindfolded, and include power word kills in\
 his speech.");
    set_level(300);
    set_hp(15000);
    set_money(100 + random(50));
    set_ep(3000000);

    set_chance(10);
    set_spell_mess1("Leo casually says a power word kill.");
    set_spell_mess2("Leo gently caresses your ears with a power word kill.");
    set_spell_dam(160);

    load_chat(5, ({
	"Leo smiles happily.",
	"Leo shuffles through his spell book.",
	"Leo mumbles: now how did that Total Destruction spell go...",
	"Leo giggles insanely.",
	"Leo casts a spell, and a goblet of wine appears into his hand.",
	"Leo finds a living rat in his pocket and is amazed.",
	"Leo writes something into his spellbook.",
	"Leo says: Hmm, I definitely need an orc slayer sword.",
	"Leo asks: Now where is that Ogre Slayer?",
	"Leo scratches his head."
      }));
}

void
catch_tell(string str)
{
    object from;
    string a;
    string b;
    string c;

    from = this_player();

    if (!from || this_player() == this_object()) return;
    /* Not from a real player. */

    if (sscanf(str, "%s hello%s", a, b) == 2 ||
      sscanf(str, "%s Hello%s", a, b) == 2 ||
      sscanf(str, "%s hi%s", a, b) == 2 ||
      sscanf(str, "%s Hi%s", a, b) == 2)
	call_out("reply_hello", 2, from);

    else if (sscanf(str, "%sgive%scastle%s", a, b, c) == 3 ||
      sscanf(str, "%swant%scastle%s", a, b, c) == 3)
	call_out("reply_castle", 2, from);

    return;
}

void
reply_hello(object who)
{
    if (!objectp(who) || environment(who) != environment())
	return;
    environment() -> tell_here("Leo says: Welcome, "
      + (string) who -> query_real_name()
      + "!", this_object());
}

void
give_object_by(object who, object what)
{
    if (who && what) call_out("reply_give", 2, ({ who, what }));
}

void
reply_give(object *x)
{
    object who, what;

    if (!pointerp(x) || sizeof(x) < 2) return;
    who = x[0];
    what = x[1];
    if (!objectp(who) || environment(who) != environment() || !what)
	return;
    if (!objectp(what)) {
	if (intp(what)) {
	    environment() -> tell_here(
	      "Leo says: Ahem... I can't be bribed! At least not by that lousy sum...");
	}
	return;
    }
    if (what->id("orc slayer")) {
	if (who -> query_quest(QUEST_ORC_SLAYER)) {
	    who -> tell_me(
	      "Leo says: Well, you have already done the quest...\n\
Leo gives the "+(string)what->query_name(0,who)+" back to you.");
	    move_object(what, who);
	} else {
	    who -> tell_me(
	      "Leo says: Well done. You have fullfilled this quest.");
	    QUEST_D->add_quest(who,QUEST_ORC_SLAYER);
	    destruct(what);
	}
	return;
    }
    if (what -> id("ogre slayer")) {
	who -> tell_me(
	  "Leo says: Actually, I wanted the Orc Slayer. But since you have already been\
 to Ogre Valley, could you bring my nephew back from there? He wanted to go\
 there after he had killed all the orcs in the Orc Valley, but has been there\
 for quite a while. I am getting a bit worried.\n\
Leo takes a piece of paper and writes something on it.\n\
Leo says: Here, give this note to him, so he will trust you.\n\
Leo drops the note and the sword.");
	move_object(what,environment());
	move_object(clone_object(GENERIC_LEO_NOTE),environment());
    }
}

/* No, not any automatic promotion any more. //Graah */
void
reply_castle(object who)
{
    if (!objectp(who) || environment(who) != environment()) return;

    if ((int) who -> query_level() < 25) who -> tell_me(
	  "Leo tells you: Well, I think you are not ready yet to become a coder in \
this MUD. But who am I to say - I don't know thow they rule those \
things here. They haven't told me!");

    else who -> tell_me(
	  "Leo tells you: Well, I think you are not ready yet to become a coder in \
this MUD. But who am I to say - I don't know thow they rule those \
things here. They haven't told me!");
}
