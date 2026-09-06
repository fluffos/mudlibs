/*
	this is a wedding manual coded by Minx....
	as far as what it does try look at manual...
	as far as the code....
	this manual counts on a few things...
	1) the bride, groom, best man, maid of honor must
		be in the game when they are used in "setparty"
	2) the bride and the groom must be set before the
		ceremony...
	3) currently the bride and groom must be set in the
		code in the carriage and the c_patio

	and I think that's it....

	Mail me if you have any questions!!! > :)
			Minx
*/



#include <treasure.h>
#include "weddings.h"
#define TP this_player()
int x, m;
string groom_name, bride_name, best_name, maid_name;
object groom, bride, best, maid, dad;
string groom_outfit, bride_outfit, best_outfit, maid_outfit;

void
create_treasure(){

    set_id("manual");
    set_short("A wedding manual");
    set_long("A manual that can be used to perform all the \
different wedding functions. Try <helpmanual> to see the options.");
    dad = find_player("minx");	
}

void
init_treasure(){
    add_action("begin_cmd","begin");
    add_action("next_cmd","next");
    add_action("ceremony_cmd","ceremony");
    add_action("dress_cmd","dress");
    add_action("set_party_cmd","setparty");
    add_action("set_dress_cmd","setdress");
    add_action("help_cmd","helpmanual");
    add_action("morec_cmd","morec");
}

int get() { return 1; }
int drop() { return 1; }

help_cmd(){

    TP->tell_me("These are the available commands:\n\
setparty = sets the members of the wedding party\n\
setdress = sets the dress for the members of the party\n\
ceremony = starts a review of the ceremony script\n\
morec = gives you the next piece of the ceremony script\n\
dress = this is used to dress the wedding party.\n\
begin = this will begin the ceremony\n\
next = this will continue each step of the ceremony until it has \
ended\n\
Best Wishes,\n\
Minx");
    return 1;
}


set_party_cmd(string xx){
    string what, who;

    if (sscanf(xx,"%s %s",what,who) < 2){
	TP->tell_me("To set any of these use <setparty> \
[<bride>,<groom>,<best>or<maid>] then the player's lowercase name.");
	return 1;
    }

    if (what == "groom"){
	groom_name = who;
	TP->tell_me("The groom is: "+capitalize(groom_name)+".");
	groom = find_player(groom_name);
	return 1;
    }

    if (what == "bride") {
	bride_name = who;
	bride = find_player(bride_name);
	TP->tell_me("The bride is: "+capitalize(bride_name)+".");
	return 1;
    }

    if (what == "best") {
	best_name = who;
	TP->tell_me("The best man is: "+capitalize(best_name)+".");
	best = find_player(best_name);
	return 1;
    }

    if (what == "maid") {
	maid_name = who;
	TP->tell_me("The maid of honor \
is: "+capitalize(maid_name)+".");
	maid = find_player(maid_name);
	return 1;
    }

    return 1;

}

set_dress_cmd(string xx){
    string what, outfit;

    if (sscanf(xx,"%s %s",what,outfit) > 2 ) {
	TP->tell_me("To set any of these use <setdress> \
[<bride>,<groom>,<best>or<maid> then the exact outfit they should be \
dressed as.");
	return 1;
    }

    if (what == "groom") {
	groom_outfit = outfit;
	TP->tell_me("The groom will be dressed \
as: "+groom_outfit+".");
	return 1;
    }

    if (what == "bride") {
	bride_outfit = outfit;
	TP->tell_me("The bride will be dressed \
as: "+bride_outfit+".");
	return 1;
    }

    if (what == "best") {
	best_outfit = outfit;
	TP->tell_me("The best man will be dressed \
as: "+best_outfit+".");
	return 1;
    }

    if (what == "maid") {
	maid_outfit = outfit;
	TP->tell_me("The maid of honor will be dressed \
as: "+maid_outfit+".");
	return 1;
    }

    return 1;
}


dress_cmd(string what){

    if (what == "groom" || what == "all"){
	groom->set_disguised(1,groom_outfit);	
	TP->tell_me("The groom is now disguised as :"+
	  groom_outfit);
	groom->tell_me("You have just been disguised as :"+
	  groom_outfit+". To turn this disguise back off you just need to do \
the ordinary <disguise off>.");
	return 1;
    }

    if (what == "bride" || what == "all"){
	bride->set_disguised(1,bride_outfit);	
	TP->tell_me("The bride is now disguised as :"+
	  bride_outfit);
	bride->tell_me("You have just been disguised as :"+
	  bride_outfit+". To turn this disguise back off you just need to do \
the ordinary <disguise off>.");
	return 1;
    }

    if (what == "best" || what == "all"){
	best->set_disguised(1,best_outfit);	
	TP->tell_me("The best man is now disguised as :"+
	  best_outfit);
	best->tell_me("You have just been disguised as :"+
	  best_outfit+". To turn this disguise back off you just need to do \
the ordinary <disguise off>.");
	return 1;
    }

    if (what == "maid" || what == "all"){
	maid->set_disguised(1,maid_outfit);	
	TP->tell_me("The maid of honor is now disguised as :"+
	  maid_outfit);
	maid->tell_me("You have just been disguised as :"+
	  maid_outfit+". To turn this disguise back off you just need to do \
the ordinary <disguise off>.");
	return 1;
    }

    if (!what) TP->tell_me("Dress who?");

    return 1;
}

ceremony_cmd(){
    TP->tell_me("Let's run through the ceremony!!! Hmmm... \
let's pretend to have a Flinstone Wedding!!!\n\
Use the command <morec> when you want to continue to the next part \
of the ceremony explaination.");
    return 1;
}

morec_cmd(){

    if (m == 0){
	TP->tell_me("First you must set the wedding party... Your \
commands would be: <setparty groom fred>, <setparty bride wilma>, \
<setparty best barney>, <setparty maid betty>. Very IMPORTANT \
note: these players must be in the game when this is done.");
	m ++;
	return 1;
    }

    if (m == 1){		
	TP->tell_me("Then you must pick out what everyone in the \
wedding party will be disguised as.\n\
Your commands would be: <setdress bride Lady Wilma, the blushing \
bride>, <setdress groom King Fred, the dapper groom>, <Baron \
Barney, the best man>... I think you get the picture.\n\
Don't forget you may want to set your disguise as well.\n\
Note: The best way to chose the disguises is to make sure that they \
all begin with a capital.");
	m ++;
	return 1;
    }

    if (m == 2){
	TP->tell_me("Next you will set the wedding party's \
disguises for the event. This can be done \
using: <dress groom>, <dress bride> etc. Or you can use the command: \
<dress all> if everyone is present.");
	m ++;
	return 1;
    }

    if (m == 3){
	TP->tell_me("When you are ready for the ceremony to start \
the command to use is <begin>. To proceed through the ceremony the \
command to use is <next>. This command will bring about the next part of \
the ceremony. You will be prompted about what will happen next and \
what to expect. At the same time the bride and groom are prompted as to \
what they have to do.");
	m ++;
	return 1;
    }

    if (m ==4){
	TP->tell_me("Couple more things...\n\
The best way to see the ceremony is to set yourself as the bride and the \
groom and then take a run through the ceremony, starting with <begin> \
and continuing until the service is over with <next>. You will be a \
total of three characters, but you'll get the idea. Note: Coders you \
will have to recompile the chapel after doing this so that all the \
variables get set back for the actual ceremony.");
	m ++;
	return 1;
    }

    if (m == 5){
	TP->tell_me("Since this service is still pretty new and \
I'm still open to ideas, if you have any suggestions please mail me.");
	m ++;
	return 1;
    }

    if (m == 6){
	TP->tell_me("That's all for now. Thank you for playing.");
	m = 0;
	return 1;

    }

}
begin_cmd(){
    object here;
    x = 0;
    here=environment(TP);		
    here->tell_here((string)this_player()->query_name()+" says: \
Please be seated.\n\
A hush falls over the crowd.");
    return 1;
}

next_cmd(){
    object here, patio, carriage;
    here=environment(TP);

    if (x == 0){
	here->tell_here((string)this_player()->query_name()+" \
turns to "+capitalize(groom_name)+" and says: \
Do you, "+capitalize(groom_name)+", take "+capitalize(bride_name)+
	  " to be your mudly married wife, to have and to hold, to love, cherish and \
respect, whether in sickness or health, fully healed or mortally wounded, \
as long as you both shall mud.");
	groom->tell_me("This is where you say 'I do'.");
	TP->tell_me("NOTE: Wait for the groom to say I do.");
	x ++;
	return 1;
    }

    if (x == 1){
	here->tell_here((string)this_player()->query_name()+" \
turns to "+capitalize(bride_name)+" and says: \
Do you, "+capitalize(bride_name)+", take "+capitalize(groom_name)+
	  " to be your mudly married husband, to have and to hold, to love, cherish \
and respect, whether in sickness or health, fully healed or mortally \
wounded, as long as you both shall mud.");
	bride->tell_me("This is where you say 'I do'.");
	TP->tell_me("NOTE: Wait for the bride to say I do");
	x ++;
	return 1;
    }

    if (x == 2){
	here->tell_here((string)this_player()->query_name()+" \
smiles happily and looks at both "+
	  capitalize(groom_name)+" and "+
	  capitalize(bride_name)+" and says: You may present the wedding \
rings to each other.");
	TP->tell_me("NOTE: Wait for the two of them to present the \
rings.");
	x ++;
	return 1;
    }

    if (x == 3){
	here->tell_here((string)this_player()->query_name()+" \
says: I now pronounce you, husband and wife. "
	  +capitalize(groom_name)+", you may kiss the bride");
	TP->tell_me("NOTE: The next step will be to pass out rice.");
	x ++;
	return 1;
    }

    if (x == 4){
	here->tell_here("The music swells as the bride and groom \
stare into each others eyes. Someone hands you a bag of rice to <toss> \
at the happy couple.");
	x ++;
	TP->tell_me("NOTE: The next step will be to add the exit.");
	here->toss_cmd("set");
	return 1;
    }

    if (x == 5){
	here->tell_here("Two huge doors swing open, revealing \
the garden patio where the small reception will be held.");
	here->tell_here("Everyone is invited to enjoy champagne and \
cake out on the <patio>.");
	call_other(WEDDING+"c_patio","????");
	patio=find_object(WEDDING+"c_patio");
	here->add_exit("patio",WEDDING+"c_patio");
	TP->tell_me("NOTE: You have now completed the wedding.");
	x++;
	return 1;
    }

    if (x > 5){
	TP->tell_me("The wedding is over.");
	return 1;
    }
    return 1;
}		







