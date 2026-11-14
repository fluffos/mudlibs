#include <rooms.h>
#include <moving.h>
inherit "/std/room";

int rlevel, rdelta, gopen, astatus;
int puzzle_solved;

exgates() {
  return("The gates are "+ (gates_open() ? "open.\n" : "closed.\n"));
}

expanel() {
  return("There is a large wheel and a small green bulb on the panel.\n" +
		(activated() ? "The bulb is glowing.\n" : ""));
}

exlight() {
  return(activated() ? "The bulb is glowing.\n" : "The bulb is dark.\n");
}

turnit(string str) {
  if (str != "wheel") return 0;
  if (!this_player()) return 0;
  show(this_player()->QueryName()+" turns a wheel.\n");
	if (!activated()) {
		write("You turn the wheel but nothing happens.\n");
		return 1;
	}
	if (!puzzle_solved) {
		puzzle_solved = 1;
		call_other(this_player(), "AddXP", 300);
	}
	if (gates_open()) {
		write("This is hard work! Slowly the gates close.\n");
		show("The gates slowly close.\n");
		gopen = 0;
		set_heart_beat(1);
	}
	else {
		write("This is hard work! Slowly the gates open.\n");
		show("The gates slowly open.\n");
		gopen = 1;
		set_heart_beat(1);
	}
	return 1;
}

trypress(string str) {
  if (!str || !id(str)) return 0;
  write("You press and push but find nothing.\n");
  return 1;
}

m_d() {
  return (int) notify_fail("No access for tourists!\n") && 0;
}

create() {
  ::create();
  SetIntShort("Dam");
  SetIndoors(1);
  AddDetail(({"gates", "gate", "dam"}),#'exgates);
  AddDetail(({"panel", "control", "control panel"}),#'expanel);
  AddDetail(({"green", "green bulb", "bulb"}),#'exlight);
  AddDetail("wheel",
    "It looks as if it has not been turned for a long time.\n");
  AddExit("south","./dam_lobby");
  AddExit("north","./canyon");
  AddExit("west","./reservoir_north");
  AddExit("down",#'m_d);
  AddRoomCmd("turn",#'turnit);
  AddRoomCmd(({"press","push"}),#'trypress);
  reset();
}

QueryIntLong() 
{
	int reslevel, resdelta;
	string str;

	reslevel = reservoir_level();
	resdelta = reservoir_delta();
	str = 
"You are standing on top of the Great Dam, which was quite a tourist "
"attraction in times long gone. There are paths to the north, south, "
"west and a scramble down.\n";
	if (reslevel == 100)
		str += "The water level behind the dam is very high, some water is\npouring over the top of the neglected dam.\n";
	else if (reslevel > 50)
		str += "The water level behind the dam is high.\n";
	else if (reslevel > 0)
		str += "The water level behind the dam is low.\n";
	else
		str += "The reservoir behind the dam is dry except for a small stream.\nrunning through the open gates.\n";
	if (resdelta < 0) 
		str += "The level is falling. Water rushes through the open gates.\n";
	if (resdelta > 0)
		str += "The level is rising as water collects behind the closed gates.\n";
	str += "There is a small control panel here.\n";
	return str;
}

reset()
{
	::reset();
	rlevel = 100; rdelta = 0; gopen = 0; astatus = 0;
	puzzle_solved = 0;
}


/* These are the dam functions, also callable from outside */
reservoir_level() {
	return rlevel;
}
reservoir_delta() {
	return rdelta;
}
gates_open() {
	return gopen;
}
activated() {
	return astatus;
}
set_active(st) {
	astatus = st;
}


heart_beat()
{
	if (gopen) {
		rdelta = -20;
		rlevel = rlevel + rdelta;
		if (rlevel <= 0) {
			rlevel = 0;
			rdelta = 0;
			set_heart_beat(0);
			show("The reservoir is now empty and only a small stream runs through the gates.\n");
		}
		else {
			show("Water rushes through the open gates.\n");
		}
	}
	else {
		rdelta = 5;
		rlevel = rlevel + rdelta;
		if (rlevel >= 100) {
			rlevel = 100;
			rdelta = 0;
			set_heart_beat(0);
			show("As the reservoir is filled now, water starts to pour over the dam.\n");
		}
		else {
			show("Water collects behind the dam.\n");
		}
	}
}
