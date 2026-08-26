/*
**  FILE:    _asummon.c (admin version of _summon.c)
**  PURPOSE: Admin version of "summon". Usually used upon
**       people who are in trouble...
**
**  CHANGES:
**  08-27-96    Cyanide    Created the file out of necessity.
**  08-27-96    Chronos    Modified for efficiency and color. :D
*/

#include <mudlib.h>

#define SYNTAX "Usage: asummon <target>\n"
#define T_NAME target->query("cap_name")

inherit DAEMON;

int cmd_asummon(string str) {
    object target;
    string x,y;

    if (!str || !adminp(TP)) {
	write (SYNTAX);
	return 1;                 
    }
    str = lower_case(str);
    target = find_living(str);
    if (!target) {
	write ("That person is not currently logged on.\n");
	return 1;
    }

    if (adminp(target)) {
	write("You cannot asummon other admin.\n");
	return 1;
    }
    // Chronos redid this part for efficiency.
    if (present(str, environment(TP))) {
	write ("That player is already in the same room as you.\n");
	return 1;
    }
    switch(random(16)+1) {
    case 1: x="$N vanishes in a poof of purple smoke!";
	y="$N appears in a poof of purple smoke!";
	break;
    case 2: x="$N suddenly disappears in a shower of sparks!";
	y="$N suddenly appears in a shower of sparks!";
	break;
    case 3: x="There is a clap of thunder, and $N disappears.";
	y="There is a clap of thunder, and $N appears.";
	break;
    case 4: x="$N suddenly fades from sight.";              
	y="$N suddenly fades into view.";
	break;
    case 5: x="A large bubble suddenly encases $N and pops.";
	y="A large bubble suddenly appears and pops, leaving $N before you.";
	break;
    case 6: x="$N is carried away by a couple small men.";
	y="A couple small men carry $N into the room.";
	break;
    case 7: x="$N suddenly melts into the ground.";
	y="$N suddenly forms from the ground.";
	break;
    case 8: x="$N is suddenly thrown from the room.";
	y="$N is suddenly thrown into the room.";
	break;
    case 9: x="$N suddenly floats out of the room.";
	y="$N suddenly floats into the room.";
	break;
    case 10: x="There is a bright flash of light and $N is gone.";
	y="There is a bright flash of light and $N stands before you.";
	break;
    case 11: x="A small whirlwind rushes into the room and carries $N away.";
	y="A small whirlwind rushes into the room and drops $N before you.";
	break;
    case 12: x="Two large hands appear from out of nowhere and grab $N."+
	" They dissappear.";
	y="Two large hands suddenly drop $N before you.";
	break;     
    case 13: x="The ground cracks open and swallows $N completely.";
	y="$N falls before you.";   break ;
    case 14: x="Two skeletal hands burst from the ground and drag $N "+
	"down with them!";
	y = "Two skeletal hands punch through the ground and toss $N up before you.";
	break ;
    case 15: x = "Large flying monkeys swoop down and carry $N away!";
	y = "Large flying monkeys swoop down and drop $N before you."; break ;
    default: x="A large black sphere suddenly forms around $N, then vanishes.";
	y="A large black sphere suddenly forms before you and "+
	"vanishes, leaving $N before you.";
	break;
    }
    x = replace_string(x,"$N", T_NAME);
    y = replace_string(y,"$N", T_NAME);
    message("movement", wrap(x), environment(target), ({ target }) );
    message("movement", wrap(y), environment(TP) ) ;
    tell_object(target, "You are suddenly sucked away to a different place...\n");
    target->move(environment(this_player()));
    return 1;
}


string help() {
    return (SYNTAX + "" + @HELP
The asummon command will essentially do what the original summon
oncedid - bring a player (or wizard) to the presence of the
summoning admin.
HELP
    );
}                                

/* EOF */
