#include "../priest.h"
inherit PRIEST_ROOM_DIR "officer_room";

string owner_name;

void create_room(){
    ::create_room();
    officer_title = "Preceptor Templar";
    owner_name = OFFICER_D->get_officer(PT_RANK);
    if(!owner_name) owner_name = "Frank Zappa";
    else owner_name = capitalize(owner_name);
    set_short("The Office of the Templar");
    set_long(
      "This room looks like a laboratory. Next to the southern wall is a huge shelf, \
upper shelf is filled with strange substances and distilled corpses, lower \
shelf has some VERY old books, which almost grumble away. In the middle of \
this room is an old stone table, covered with icky green moss and broken \
glass. Northern wall has a large metal container which radiates cold. Eastern \
wall has a wooden cabin which contains very sharp scalpels and knives. There \
is also a small altar here and a religious statue of somekind with a silver \
plaque attached on it. You can understand only one word: Caine. Above the door \
is a golden sign with the name " + owner_name + " on it.");
    add_exit("west", PRIEST_ROOM_DIR+"basement");
    replace_program(PRIEST_ROOM_DIR "officer_room");
}
