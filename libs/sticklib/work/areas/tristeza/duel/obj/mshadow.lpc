/*******************************

 Map-shadow (C) Tron.

 Shadows the player when on map.

 - Macro stopper:

   makes a player to fall
   on the ground when
   moving too fast.

********************************/


#define MMOVES 6
#define MTIME  4

#define SAY(X) tell_room(environment(this_player()),X,({this_player()}))

private int moves, old_time;
private int move_time, max_moves;

private object sob;
private string *msg;


status
query_mshadow() { return 1; }

void
do_shadow(object ob) {
    msg = ({
      "You roll over several times...UUUhh...AIIIEEEUUUhhh.\n",
      "Ouch you hurt your arm.\n",
      "UUUUHHHhhh...the stars are so bright.\n",
      "You hit your leg to something hard.\n",
      "AUUUUUUhhh...that hurt!\n",
      "That hurt!\n",
    });

    if (!move_time) move_time = MTIME;
    if (!max_moves) max_moves = MMOVES;

    shadow(ob);
}

void
set_move_time(int i) {
    move_time = i;
}

void
set_max_moves(int i) {
    max_moves = i;
}

status
too_fast() {
    status ret;

    if((time() - old_time ) <= move_time) {
	moves++;
	if(moves >= max_moves) {
	    ret=1;
	    moves=-1;
	}
    }
    else moves=0;

    old_time = time();

    return ret;
}

void
move_player(mixed dir_dest, mixed optional_dest_ob) {
    if(moves < 0) {
	write(msg[random(sizeof(msg))]);
	return;
    }

    if(too_fast()) {
	write("WHOOOOOOps...YOU FALL...\n");
	SAY(this_player()->query_name()+
	  " falls down on the ground.\n");
	call_out("stand_up", 5);
	moves = -1;
	return;
    }

    sob->move_player(dir_dest, optional_dest_ob);

    if(!environment(this_player())->room_id())
	destruct(this_object());

    return;
}

void
stand_up() {
    write("You stand up again.\n");
    moves = 0;
}

