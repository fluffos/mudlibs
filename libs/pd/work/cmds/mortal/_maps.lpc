#include <std.h>
inherit DAEMON;
int cmd_maps(string str) {
  if(str == "on") {
    this_player()->set_maps(1);
    write("Mapping on.\n");
    return 1;
  }
  if(str == "off") {
    this_player()->set_maps(0);
    write("Mapping off.\n");
    return 1;
  }
  return notify_fail("Syntax:  <maps [on\\off]>\n");
}
int help() {
    write(
      "Syntax: <maps [on\\off]>\n"
      "\nTurns room mapping on and off. The brackets leading away from the center "
      "bracket are the directions you can go. A + above the center bracket means there "
      "is an up exit. A - below the center bracket means there is a down exit. The "
      "%^RED%^X%^RESET%^ is where you are on the map. A %^GREEN%^*%^RESET%^ in a "
      "direction brackets means someone or something is in that direction.\n"
       "\n"
      "Eaxample:\n"
      "               + \n"
      "         [ ]-[%^RED%^X%^RESET%^]-[ ] \n"
      "             -| \n"
      "             [%^GREEN%^*%^RESET%^] \n"
       "\n"
      "In this example, there are five exits: west, south, east, up, and down. \n"
      "Something or someone is in the room to the south.\n"
    );
    return 1;
}
