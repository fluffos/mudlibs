#include "priest_room.h"

void create_room() {
    set_short("The Cathedral's bell tower.");
    set_long("This is the second floor of the Cathedral's bell tower. \
Stairs spiral further up to a sturdy door, which is made of the same kind of \
maple used in the paneling here, but is slightly darker in color.");

    add_exit("down", PRIEST_ROOM_DIR "1tower");
    add_exit("up", PRIEST_ROOM_DIR "3tower");

    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD,WD_INDOORS);

    add_monster(PRIEST_MON_DIR "templar",
      "Templar quitly returns to his post.",1); 
    add_monster(PRIEST_MON_DIR "templar",
      "Templar quitly returns to his post.",1); 

    add_command("up", "block_exit");
}

status block_exit(string arg) {
    object templar;

    templar = present("templar", this_object());
    if(!templar || this_player()->query_coder_level()) return 0;
    if(this_player()->query_guild() != GN_PRIEST ||
      !this_player()->query_guild_object() ||
      this_player()->query_guild_object()->query_rank() < 2)
    {
	tell_here(":%<me.capname>% blocks %<him.gen_possessive>% way!",
	  0,0,templar,templar,this_player(),0);
	return 1;
    }
    return 0;
}
