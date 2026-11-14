/* Tamedhon MUDLIB
 * einige 'Sicherungen' und Aenderungen gegenueber den Standardworkroom
 * Samtpfote@Tamedhon
 *
 * $Date: 2000/06/03 23:01:32 $
 * $Revision: 1.1 $
 * $Log: workroom.c,v $
 * Revision 1.1  2000/06/03 23:01:32  Samtpfote
 * Initial revision
 *
 */


#include <properties.h>
#include <wizlevels.h>
#include <moving.h>

inherit "std/room";

int etwas_nehmen(string str)
{
    if(!IS_LEARNER(this_player()) && 
       !this_player()->QueryProp(P_TESTPLAYER))
    {
	say(sprintf("%s versuchte, '%s' zu nehmen!\n",
	      capitalize(this_player()->query_real_name()),
	      str), ({ this_player() }) );

	write("Nope, das darfst Du *hier* nur als Magier oder "+
	      "Testspieler!\n");
	return 1;
    }
 return 1;
}


void create()
{
	string		wizname;

    ::create();
	
	wizname=capitalize(getuid(this_object()));
	
	SetProp(P_LIGHT, 1);
	SetProp(P_INT_SHORT, "Der Arbeitsraum von "+wizname);
	SetProp(P_INT_LONG, 
	  break_string("Das ist der Arbeitsraum von "+wizname+". Er ist noch "+
		"recht kahl und gestaltlos."));
	
    AddCmd(({"nimm","steck","stecke","hol","hole"}), "etwas_nehmen");
} 
