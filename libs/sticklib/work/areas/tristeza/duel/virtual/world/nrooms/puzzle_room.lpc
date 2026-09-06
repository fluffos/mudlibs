#include <room.h>

#include <areas.h>

int stage;
int shaked;

object user;

void next_move();
void
create_room() {

    object game;
    set_light(LT_LIGHTS);
    set_outdoors(WD_INDOORS);

    set_short("Tomb chamber");
    set_long("It's a round chamber with glowing stones in the roof."+
      "There is a text carved in the wall and in the middle "+
      "you see a strange box attached to the floor.");

    add_item("text", "You could read it.");
    add_item("stones", "They are green glowing stones high above you.");
    add_item("glowing stones", "=stones");
    add_item("box", "It appears to be a puzzle game. Aha, put the numbers in order!");

    game = clone_object(AREA_TRISTEZA "duel/obj/puzzle2");
    game->set_trigger_fun(this_object(), "move_me");
    move_object(game, this_object());

    add_exit("east", AREA_TRISTEZA "duel/virtual/world/rooms/11_10");
    add_monster(AREA_TRISTEZA "duel/npc/pguard",
      "Guard arrives.", 1);
}

status
read_cmd(string s) {

    if(!s) return 0;

    if(s == "text") {
	write("Here rests the honorable orc mage Orcinie Magicus.\n");
	write("Who dares to enter the tomb shall be alone and lost "+
	  "forever if fails to win the spirit of Orcinie.\n");

	return 1;
    }
    else return 0;
}

void
move_me() {

    if(stage && this_player() != user) {
	write("Dark voice says: You must enter alone. Someone is there already.\n");
	return;
    }
    user = this_player();

    this_player()->tell_me("Blue light surrounds your body and the world"+
      " flips around, bends and changes to disoriented yellow bubbles."+
      "Your body shakes and disappears into black void. Pain blows you with "+
      "thousand needles stinging through your mortal flesh.");
    say(this_player()->query_name()+" vanishes with thousands of blue sparks.\n");

    this_player()->hit_player(random(30));

    if(this_player()->query_hp() < 0) {
	this_player()->tell_me("You drop down on a cold floor.");
	return;
    }
    next_move();
}

void
next_move() {

    switch(stage) {

    case 0: 
	call_out("dies", 300);
	this_player()->move_player("X#"+AREA_DUEL_ARENA+"virtual/world/nrooms/puzzle_room1");
	break;
    case 1:
	remove_call_out("dies");
	call_out("dies2", 240);
	this_player()->move_player("X#"+AREA_DUEL_ARENA+"virtual/world/nrooms/puzzle_room2");
	break;
    case 2:
	remove_call_out("dies2");
	call_out("dies3", 180);
	this_player()->move_player("X#"+AREA_DUEL_ARENA+"virtual/world/nrooms/puzzle_room3");
	break;
    case 3:
	remove_call_out("dies3");
	this_player()->move_player("X#"+AREA_DUEL_ARENA+"virtual/world/nrooms/puzzle_last");
	stage = 0;
	user = 0;

	return;
    }
    stage++;
}

void
set_stage(int s) { stage = s; }


void
dies() {

    user = 0;
    stage = 0;

    if(!this_player()) return;
    if(!interactive(this_player())) {
	this_player()->quit();
	return;
    }
    if(!environment(this_player())->query_puzzle_room()) return;
    this_player()->tell_me("A hollow voice says: Time is up mortal, you "+
      "have to do better than that!");

    this_player()->death(3); //Death by a trap.
}

void
dies2() { dies(); }

void
dies3() { dies(); }
