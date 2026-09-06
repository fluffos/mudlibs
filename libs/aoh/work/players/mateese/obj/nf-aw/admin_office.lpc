inherit "d/archwiz/common/std/room";
#include <properties.h>



object 	board;



void create() {
	
	::create();
	
	SetIntShort("Special workroom for the Administrators");
	SetIntLong(
"This room is reserved for Deepthought and Zeus for special jobs. " +
"Here they can look for the real problems the wizards might have.\n");
	AddExit("south",        "/d/archwiz/common/lpc/office");	
	/* SetIntLight(1); */

	reset();
		
}



void reset() {

	::reset();

	if(!board) {
		board = clone_object("d/archwiz/common/std/board");
		board->SetBoardFile(file_name(this_object()) + "_board");
		board->SetBoardName("Administration");
		board->move(this_object());
	}

}


