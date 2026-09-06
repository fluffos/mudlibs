#include <room.h>
#include "weddings.h"
#define TP this_player()
#define TO this_object()
inherit "basic/misc/emote";  
object groom, bride, suite, patio;
string groom_name, bride_name;

void
create_room(){
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(ROOM_WD,WD_INDOORS);
    set_short("A special horse drawn carriage");
    set_long("This is the horse drawn carriage that will whisk \
the bride and the groom awat to the honeymoon suite.");
    set_exits((["town":"/room/church"]));
    set(SKIP_EXITS);
    set_commands(([
	"carriage":"carriage_cmd",
	"carry":"carry_cmd",
	"emote":"emote_cmd"
      ]));
    groom = find_player("blix");
    bride = find_player("nuts");
}

status
id(string str){ return str == "carriage"; }

carriage_cmd(){
    string name;
    patio = find_object(WEDDINGS+"c_patio");

    // Only the bride and groom can enter the carriage...

    if ( TP != groom && TP != bride ){
	TP->tell_me("The carriage is only for the bride and \
the groom.");
	return 1;
    }

    // Moving the bride or groom to the carriage and having them wave bu-bye
    patio->tell_here(capitalize(TP->query_name())+" steps into the \
carriage, waving good-bye to you and the remaining guests.",TP);
    TP->tell_me("You step into the carriage.");
    move_object(TP, TO);

    // Starting the carriage ride when both bride and groom arrive
    if(present(groom,TO) && present(bride,TO)){
	patio->tell_here("The driver starts the carriage on \
it's way. The happy couple wave good-bye to you and the remaining \
guests.");

	// Moving the carriage OUT of the patio, so that the guests don't see 
	// it after is has supposedly left > :)
	suite = clone_object(WEDDING+"suite");
	move_object(TO,suite);
	TO->set_long("Every inch of the carriage's interior is \
covered with deep red velvet, the color of love and romance. Just the \
look of this carriage puts you in the mood. You can hardly wait to \
get to the honeymoonsuite. Note: the emergency exit is <town>.");

	// Starting the carriage ride...
	pull_out();
	return 1;
    }

    return 1;
}

query_couple(){
    return ({groom,bride});
}


pull_out(){

    tell_here("The driver pokes his head into the carriage and says: \
Now that you are both here, we can be on our way. I hope you enjoy the \
ride.");

    call_out("drive_msg",6,0);

}

drive_msg(int x){

    switch(x){

    case 0:
	tell_here("You lurch forward in your seat as the carriage \
pulls away from the reception. All of your guests can still be seen on \
the patio waving good-bye and wishing you all the best.");
	call_out("drive_msg",5, 1);
	break;

    case 1:
	tell_here("The driver says: Just sit back and relax. \
It'll only take a few minutes to get to the honeymoon suite. There is a \
bottle of champagne somewhere back there, if you would care for a glass.");
	call_out("drive_msg",30,2);
	break;

    case 2:
	tell_here("The driver says: We are almost half way there.");
	call_out("drive_msg",30,3);
	break;

    case 3:
	tell_here("The driver says: It's just around the corner.");
	call_out("drive_msg",10,4);
	break;

    case 4:
	tell_here("The driver says: We are here.\n\
And the carriage comes to a stop.");
	call_out("drive_msg",3,5);
	break;

    case 5:
	tell_here("The driver opens the carriage door.");
	call_out("drive_msg",3,6);
	break;

    case 6:
	groom->tell_me("You step out of the carriage first. You \
then take the hand of your blushing bride and help her out of the \
carriage.");
	bride->tell_me("Your husband steps out of the carriage first \
and then he takes your hand and helps you out.");
	tell_here("You are standing in front of a beautiful \
building made from white marble. The dominate feature is the two huge \
carved pillars. There are several vines of blooming ivy wrapped around \
each one.");
	TO->set_short("In front of a honeymoon suite");
	TO->set_long("You are standing in front of a beautiful \
building made from white marble. The dominate feature is the two huge \
carved pillars. There are several vines of blooming ivy wrapped around \
each one.");
	call_out("drive_msg",5,7);
	break;

    case 7:
	tell_here("The driver tips his hat to you, hops back on the \
carriage and drives off. In a fading voice you hear: Best of luck."); 
	call_out("drive_msg",3,8);
	break;

    case 8:

	groom->tell_me("The tall wooden doors before you lead to the \
honeymoon suite. You must carry your new bride across the threshold. \
Please use <carry> to do this.");
	bride->tell_me("The tall wooden doors before you lead to the \
honeymoon suite. The butterflies in your stomach seem to being performing a \
frenzied mating dance.");
	break;
	return 1;
    }
}

carry_cmd(){
    move_object(groom, suite);
    move_object(bride, suite);
    groom->tell_me("You open the door and carry "+
      capitalize(bride->query_name())+" across the threshold. The beauty of the \
honeymoon suite takes your breath away.");
    groom->tell_me("This is a message from Minx: Ignore the following \
Error Message.");
    bride->tell_me(capitalize(groom->query_name())+" throws the door open, \
sweeps you up into his arms and carries you across the threshold. The beauty \
of the honeymoon suite takes you breath away."); 
    destruct(TO);
    return 1;
}
