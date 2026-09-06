#include "priest_room.h"
inherit PRIEST_ROOM_DIR "officer_room";
#define KEY "fresco of Minx"
#define VAULT PRIEST_OBJ_DIR "vault"

void create_room()
{
    ::create_room();
    officer_title = "Elector Secularus";
    set_short("The treasury of the cathedral");
    set_long(
      "This is the office of the revered Elector Secularus of the Holy Order. \
As you move nearer the center of this magnificient room, you hear the \
faint squeaking of the hardwood floor beneath the soft woolen carpeting. \
A rich cedar wood panelling, no doubt taken from the sacred forests of \
Boccob, provides a beautiful contrast to the ivory inlays of the Cathedral \
proper. The walls are lined with paintings of the Ancient Electors, whose \
patience and wisdom amassed the Church's wealth... a wealth so vast that \
evan dragons can only dream of it. In the corner sits a mighty desk. \
Upon it sit stacks of coins, various jewels, and promissary notes from \
Guilds, nobility, and merchants from all parts of the Realm. Next to the \
desk is an immense chair, easily mistakeable for a throne... With closer \
observation, you notice that the feet of the chair have been carved in \
the shape of lion's feet. Very strange.");

    add_item("portraits","These are the pictures of the past Electors \
Secularus of the Holy Order. Most of them are lifesize profiles");
    add_item("profiles","These lifelike renderings chronicle the \
Order's financial history. The greatest Electors in Order history are \
here: Jarek- who served this office first, Keldorn- who first sold \
indulgences, Belakarus the Wise- who's very touch was said to turn all \
to gold, Tallera- she who oversaw the building of this Cathedral, \
Shadron- who raised the Church's wealth beyond measure, and Sirrus- \
who funded the Renewal.");

    if(CASH_D->query_open()){      
	move_object(clone_object(VAULT),this_object());
    }
    add_exit("south", PRIEST_ROOM_DIR "basement");
    add_command("move", "move_pic");
    add_command("close", "reset_pic");
}

move_pic(string s){
    object vault, me;

    me=this_player();

    if(!s){notify_fail("Move what?\n"); return 0;}

    if((s=="portrait") || (s=="profile")){
	notify_fail("Which one? There are over 40 portraits here!\n");
	return 0;
    }

    if(s != KEY){
	notify_fail("You try to move the "+s+" but it \n"+
	  "only moves a little out of place. You quickly \n"+
	  "straighten it, feeling foolish.\n");
	return 0;
    }

    if(s==KEY){
	if(CASH_D->query_open()){
	    notify_fail("It is already open!\n");
	    return 0;
	}

	me->tell_me("The picture slides out of the way to reveal \
a vault!");
	tell_here(me->query_name()+" slides a \
portrait out of the way, revealing a hidden vault.",me);

	vault=clone_object(VAULT);
	move_object(vault,this_object());
	CASH_D->open_close();

	return 1;
    }
}

reset_pic(string s){
    object me,box;

    me=this_player();

    if(!s){notify_fail("Close what?\n");return 0;}

    if(s=="vault"){
	if(!(CASH_D->query_open())){
	    notify_fail("What vault? You see no open vault.\n");
	    return 0;
	}

	me->tell_me("You carefully replace the portrait.");
	tell_here(me->query_name()+" closes the vault.",me);

	CASH_D->open_close();
	box=present("vault",this_object());
	if(box) destruct(box);
	return 1;
    }
}
