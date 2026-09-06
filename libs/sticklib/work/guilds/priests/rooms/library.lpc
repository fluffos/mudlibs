/*
*
*   Library of the Priests Guild
*       -July 10, 1994
*          -Kel
*
*/

#include "priest_room.h"

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);

    set_short("The Library of the Cathedral");
    set_long(
      "The absolute silence here reminds you that you are in one of the most \
sacred and holy of places. This library contains the accumulated wisdom \
and knowledge of the Holy Order which has been passed down through millenia \
uncounted by faithful scribes serving the Order. The vibrant feeling of \
power seems to eminate from the thousands of tomes lining the shelves which \
cover almost every inch of the walls. The few open spots on the walls \
reveal a rich burl-oak paneling. The soft grey wool carpeting whispers beneath \
your feet as you walk here. A large Codex sits on a stand in the center of \
the room. Many tables and chairs are available to ease your studies. A \
portrait of Anitra hangs here, wreathed in black crepe.");

    add_item("codex","A large leather bound tomb. It is lying open on a stand. \
Maybe you could try to read it.");
    add_item(({"book", "books"}),"Thousands of books cover these walls. If only \
you knew the name of the title you wished to read. Perhaps you should check \
the codex.");
    add_item(({"anitra", "portrait", "portrait of anitra"}) ,"A painting of \
Anitra: Gone from us in these worlds, but not from our minds and hearts.");

    add_exit("north",PRIEST_ROOM_DIR "relaxation");
    add_exit("vote",PRIEST_ROOM_DIR "voter");

    add_monster(PRIEST_MON_DIR "zagyg", "Zagyg arrives.", 1);
    add_permanent(PRIEST_OBJ_DIR "top_priest_board");
}


read_cmd(string str)
{
    int index;
    string fname,tmp;

    if(!IS_PRIEST(this_player())){
	notify_fail("Something seems to be affecting your mind! \n"
	  "Your vision blurs momentarily and you are blinded for a few terrifying seconds."
	  "\n\nYour focus returns-  What were you trying to do anyway?\n");
	return 0;
    }

    if(!str){
	notify_fail("Read what?? A title would be nice.\n");
	return 0;
    }

    fname=str+".text";
    index=member(get_dir(PRIEST_DIR "library/"), fname);
    if(index > -1){
	tmp=read_file(PRIEST_DIR "library/"+fname);
	this_player()->more(explode(tmp,"\n"));
	return 1;
    }
    else{
	notify_fail("You search but are unable to find that title.\n");
	return 0;
    }
}
