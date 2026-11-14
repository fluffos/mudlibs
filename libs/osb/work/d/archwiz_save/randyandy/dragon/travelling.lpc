/* dumy file */
#include <nightday.h>
inherit "std/room";

void create() {
	::create();
	SetIntShort("High above the world");
	SetIntLong(
"You are in the air, high above the world. There are some clouds below you.\n");
        SetIndoors(0);
}

QueryIntLong() {
	int state;
	string msg;
	state = (int)NIGHTDAY->QueryState();
	msg="You are in the air, high above the world.\n";
	msg+=(string)NIGHTDAY->StateMsg(state);
	if ((state>ND_DAWN) && (state<ND_FALL)) {
		msg+="There are some clouds below you.\n";
	} else {
		msg+="It is dark. You see nothing.\n";
	}
	return msg;
}

