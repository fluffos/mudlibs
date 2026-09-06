#include <properties.h>

// prototypes of functions:
public void AddRoomCmd(mixed cmd, mixed func);      // from /std/room


// time to store the last clean/create of rooma
int creation_time;

// simplest... add more messages
int clean_room(string str) {
  if (!str) return 0;
  if (str=="room") {
    write("You clean the room.\n");
    creation_time = time();
    return 1;
  }
  return 0;
}

// called in creation of room
create() {
  creation_time = time();
  AddRoomCmd("clean",#'clean_room);
}

// usage:    @@DustMsg@@   inside the IntLong of the room (anywhere)
string DustMsg() {
  int diff_time;
  diff_time = time() - creation_time;
  switch(diff_time) {
    case 0..10:
         return "The room was freshly cleaned some time ago.\n";
         break;
    case 11..20:
         return "Some dust is on the floor.\n";
         break;
    case 21..30:
         return "A lot of dust is on the floor.\n";
         break;
    default:
         return "It's a really dirty room.\n";
  }
}

