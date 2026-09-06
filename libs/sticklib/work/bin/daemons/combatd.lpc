/*
 * Combat daemon
 *
 * Miscellaneous functions to make combat more colorful.
 *
 * status is_valid_target(object ob):
 * - Collect all the monsters we must NEVER be able to hit here.
 *
 */

#include <tell_me.h>
#include <npc_defs.h>

nomask void
create()
{
}

/* Describe hit, npc hitting npc/player */
nomask void
npc_hit_desc(object me, object ob, int dmg)
{
    string snd, how, what, txt;

    if (!ob || ob->query_ghost() || !me || dmg < 1) return;

    how = what = 0;

    if (dmg == 1)
    {
	switch (random(6)) {
	case 0: how = " in the side"; break;
	case 1: how = " on the head"; break;
	case 2: how = " in the chest"; break;
	case 3: how = " in the stomach"; break;
	case 4: how = " on the arm"; break;
	default: how = " on the leg"; break;
	}
	what = "tickles";
    } else if (dmg < 3) {
	how = "";
	what = "grazes";
    } else if (dmg < 4) { 
	switch (random(6)) {
	case 0: how = " in the side"; break;
	case 1: how = " on the head"; break;
	case 2: how = " in the chest"; break;
	case 3: how = " in the stomach"; break;
	case 4: how = " on the arm"; break;
	default: how = " on the leg"; break;
	}
	what = "scratches";
    } else if (dmg < 6) {
	how = " lightly";
	switch (random(3)) {
	case 0: what = "hits"; break;
	case 1: what = "strikes"; break;
	default: what = "beats";
	}
    } else if (dmg < 9) {
	how = "";
	switch (random(3)) {
	case 0: what = "hits"; break;
	case 1: what = "strikes"; break;
	default: what = "beats";
	}
    } else if (dmg < 13) {
	how = " hard";
	switch (random(3)) {
	case 0: what = "hits"; break;
	case 1: what = "strikes"; break;
	default: what = "beats";
	}
    } else if (dmg < 20) {
	how = " very hard";
	switch (random(3)) {
	case 0: what = "hits"; break;
	case 1: what = "strikes"; break;
	default: what = "beats";
	}
    } else if (dmg < 27) {
	how = " extremely hard";
	switch (random(3)) {
	case 0: what = "hits"; break;
	case 1: what = "strikes"; break;
	default: what = "beats";
	}
    } else if (dmg < 35) {
	how = " with a bone crushing sound";
	what = "smashes";
    } else if (dmg < 47) {
	how = " spraying blood everywhere";
	what = "slaughters";
    } else if (dmg < 60) {
	how = " into tiny fragments";
	what = "massacres";
    } else if (dmg < 80) {
	how = " into finely ground minced meat";
	what = "devastates";
    } else {
	how = " with a colossal strike";
	what = "utterly obliterates";
    }

    if (!(txt = (string)me->query_name(0, ob)))
	txt = "Someone";

    // Sound effects! Only StickMUD has these!!! /Graah
    if (dmg > 15 && random(100) < 9)
    {
	snd = ({
	  "POW", "SMASH", "THUD", "CRUSH", "CRUNCH",
	  "KLANG", "BANG", "MOTOON", "KAKKULA-RAPSIS", "BATAM",
	  "SHLING", "BOOM", "THUMP", "AARGH", "CRACK",
	  "PA-TAW", "KABOOM", "PLURTS", "VIRP" })[random(19)] + "! ";
    }
    else snd = "";

    if (me->query(NPC_CONTROLLED))
	me->tell_me(snd + "You" +
	  (what ? " " + what[0..sizeof(what)-2] : "") + " " +
	  (string)ob->query_name(0, me) + how + ".");

    if (ob)
	ob->tell_me(sprintf("%s%s %s you%s%s",
	    snd, txt, what, how, (random(2) ? "." : "!")), TELL_TYPE_HIT_BY);

    if (environment(me))
	environment(me)->tell_here(sprintf("%s%s %s %s%s%s",
	    snd, txt, what, (string)ob->query_name(), how,
	    (random(2) ? "." : "!")), ({ ob, me }) );
}



/* Is this crap used??? */
status
is_valid_target(object ob)
{
    string sh;

    if (!living(ob) ||
      (string)ob->query_name() == "Leo")
	return 0;

    if (((string)ob->query_real_name() == "guest") ||
      ((sh = (string)ob->short()) &&
	(sh == "Tim the Sorcerer" ||
	  sh == "Santa Claus" ||
	  sh == "A strange distortion shimmering in the air" ||
	  sh == "Wizard (grey)")))
	return 0;
    if(ob->query_ghost()) return 0; // Starks

    return 1;
}
