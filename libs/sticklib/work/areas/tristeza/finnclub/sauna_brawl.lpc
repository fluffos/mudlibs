/* room/finnclub/sauna_brawl.c */

/* Non-lethal combat */

/* #define SAUNA_ONLY */

#include <conditions.h>
#include <stats.h>
#include "../DEFS.h"

#define TP this_player()
#define TOBJ this_object()
#define ENV environment()
#define OENV environment(opp)
#define HIS(x) ((x)->Possessive())
#define HIM(x) ((x)->Objective())
#define OPN opp->query_name()
#define MYN me->query_name()

object me, opp, opp_brawl;
int opphp; /* subdual hit points */
int ml,ol;

get() { return 1; }
drop() { return 1; }
id(str) { return str == "sauna_brawl"; }
long(arg) { write("Ooh, how clever you are.\n"); return 1; }

init() {
    if (environment(TOBJ) != TP) return;
    add_action("stop","stop");
}

stop() {
    /* Not yet possible */
    return 0;
}

start_brawl(ob) {
    me = environment();
    if (!me || opp || !ob) {
	destruct(this_object());
	return;
    }
    opp = ob;
    opphp = (opp->query_level()/2 + opp->query_stat(ST_CON) + 25);

    ml = me->query_level() / 2; if (ml > 15) ml = 15;
    ol = opp->query_level() / 2; if (ol > 15) ol = 15;

    if (opp->query_race() == "half-orc") {
	opphp += opp->query_stat(ST_CON);
	ol += 2;
    }

    call_out("spank_beat",1);
}

/* Saunatappelu */
brawl_round() {
    string aim,aims,which,where,how;
    int h, i;

    h  = (ml + me->query_stat(ST_STR) + me->query_stat(ST_DEX)) / 5 +
    random(17);
    if (me->query_coder_level())
	h += me->query_coder_level() / 50;
    h -= ((ol + opp->query_str() + opp->query_dex()) / 5 +
      random(17));

    i = random(3);
    aims = ({ "aims", "swings", "targets" })[i];
    aim  = ({ "aim", "swing", "target" })[i];
    which = ({ "right ", "left ", "" })[random(3)] +
    ({ "fist", "knee", "heel", "foot" })[random(4)];
    where = ({ "right eye", "left eye", "jaw", "mouth", "neck",
      "kidneys", "groin", "stomach", "solar plexus", "right side",
      "left side", "knee", "right cheek", "left cheek" })[random(14)];

    tell_object(me, "You " + aim + " your " + which + " at " +
      OPN + "'s " + where + ".\n");
    tell_object(opp, MYN + " " + aims + " " + HIS(me) + " " +
      which + " at " + OPN + "'s " + where + ".\n");
    tell_room(OENV,MYN + " " + aims + " " +
      HIS(me) + " " + which + " at " + OPN + "'s " +
      where + ".\n", ({ me, opp }));

    if (h < 0) {
	switch(random(3)) {
	case 0:
	    tell_object(me, "It was a total miss! Your cheeks are burning.\n");
	    tell_object(opp,MYN + " misses you totally and blushes.\n");
	    tell_room(OENV,MYN + " misses " + OPN +
	      " totally and blushes.\n", ({me, opp}));
	    return; break;
	case 1:
	    i = random(3);
	    aim = ({ "fumble badly","miss by a mile",
	      "slip and almost fall" })[i];
	    aims = ({ "fumbles badly","misses by a mile",
	      "slips and almost falls"})[i];
	    tell_object(me, "You " + aim + ".\n");
	    tell_room(OENV,MYN + " " + aims + ".\n", ({me}));
	    return; break;
	default:
	    tell_object(me, "You miss.\n");
	    tell_room(OENV,MYN + " misses.\n", ({me}));
	    return; break;
	}
    }

    /* It hits */

    switch(h) {
    case 0:
	tell_object(me,"You barely tickle " + OPN + ".\n");
	tell_object(opp,MYN + " barely tickles you.\n");
	tell_room(OENV, MYN + " barely tickles " + OPN + ".\n",({me, opp}));
	break;
    case 1:
	tell_object(me,"You just touch " + OPN + " lightly.\n");
	tell_object(opp,MYN + " just touches you lightly.\n");
	tell_room(OENV,MYN + " just touches " + OPN + " lightly.\n",
	  ({me,opp}));
	break;
    case 2:
	tell_object(me,"You barely hit " + OPN + ".\n");
	tell_object(opp,MYN + " barely hits you.\n");
	tell_room(OENV,MYN + " barely hits " + OPN + ".\n",({me,opp}));
	break;
    case 3..16:
	i = random(7);
	aims = ({"beats","hits","spanks","grazes","blows",
	  "slaps","smacks"})[i];
	aim = ({"beat","hit","spank","graze","blow","slap","smack"})[i];
	how = ({ "lightly", "moderately", "hard", "strongly", "very hard",
	  "powerfully", "extremely hard" }) [(h-3) / 2];
	tell_object(me,"You " + aim + " " + OPN + " " + how + ".\n");
	tell_object(opp,MYN + " " + aims + " you " + how + ".\n");
	tell_room(OENV,MYN + " " + aims + " " + OPN + " " + how + ".\n",
	  ({me,opp}));
	break;
    default:
	i = random(4);
	aim = ({ "massacre", "demolish", "destruct", "crush" })[i];
	aims = ({ "massacres", "demolishes", "destructs", "crushes" })[i];

	i = (h-17) / 3; if (i > 4) i = 4; else if (i < 0) i = 0;
	how = ({ "small fragments", "a bloody pulp",
	  "small quivering bits of flesh", "blood and guts",
	  "a small wet spot on the floor" }) [i];

	tell_object(me,"You " + aim + " " + OPN + " into " + how + "!\n");
	tell_object(opp,MYN + " " + aims + " you into " + how + "!\n");
	tell_room(OENV,MYN + " " + aims + " " + OPN + " into " + how + "!\n",
	  ({me,opp}));
	break;
    }

    opphp -= h;

    if (where == "groin" && opp->query_gender() == 1) {
	tell_object(opp, "AARGHGHH! That REALLY hurt your family jewels!!!\n");
	tell_object(me,OPN + " screams loudly! That must have HURT!\n");
	tell_room(OENV, OPN + " screams loudly! That must have HURT!\n",
	  ({me,opp}));
	opphp -= 2;
    }

    if (opphp < 0) {
	tell_object(me,OPN + " falls down!!! YOU WON!!!\n");
	tell_object(opp,"That was too much. You fall down unconscious.\n"+
	  "You have lost the match. What a shame!\n");
	tell_room(OENV,OPN + " falls down, and the winner is " + MYN + "!\n",
	  ({me,opp}));
	opp->set_condition(C_UNCONSCIOUS, 1);

	remove_call_out("spank_beat");
	destruct(opp_brawl);
	destruct(this_object());
	return;
    }
}

spank_beat() {
#ifdef SAUNA_ONLY
    if (!opp || !me || !present(opp, environment(me)) ||
      "/"+object_name(environment(me)) != CITY_PATH+"finnclub/sauna") {
#else
	if (!opp || !me || !present(opp, environment(me))) {
#endif
	    opp = me = 0;
	    destruct(TOBJ);
	    return;
	}

	call_out("spank_beat",1);

	opp_brawl = present("sauna_brawl", opp);
	if (!opp_brawl) {
	    opp_brawl = clone_object(CITY_PATH+"finnclub/sauna_brawl");
	    move_object(opp_brawl, opp);
	    opp_brawl->start_brawl(me);
	}

	if (me->query_can_move()) brawl_round();
    }
