#include <std.h>
#include <rooms.h>

inherit DAEMON;

int cmd_mudparty(string str) {
    if(!str) return notify_fail("To what end?\n");
    if(str == "join") {
        if(!((int)ROOM_PARTY->query_party_time()))
          return notify_fail("There is no party going on.\n");
        else if(!((int)ROOM_PARTY->query_entry_allowed())) 
          return notify_fail("It is too late to join that party!\n");
        this_player()->move_player(ROOM_PARTY);
    }
    else {
        if(!archp(previous_object()))
          return notify_fail("Not right now!\n");
        if((int)ROOM_PARTY->query_party_time())
          return notify_fail("There is a party already going on!\n");
        ROOM_PARTY->start_party(str);
    }
    return 1;
}

void help() {
    message("help", "Syntax: <mudparty join> or <mudparty [reason]>\n\n"
      "Allows you to join a mudwide party.  Arches may start a "
      "mudwide party by using this command and giving a reason as "
      "an argument.", this_player());
}
