#include <ansi.h>
inherit"obj/treasure";

id(str) { return str =="hall"; }

short() {
  if(this_player())
/* Added check so that wizards could see as well - Rumplemintz, 28-Sep-09 */
    if(this_player()->query_level() < 8 ||
       this_player()->query_level() > 20) {
   return HIM+"The Hall of Apprentices ["+NORM+"enter hall"+HIM+"]"+NORM; } }

long(str) {
  if(this_player()->query_level() < 8 ||
     this_player()->query_level() > 20) {
  write("This is the Hall of Apprentices.\n"+
        "New players come here to choose equipment and to prepare\n"+
        "for battle. Enter if you are level 7 or lower.\n");
    return 1; }
  else {
    write("There is no "+str+" here.\n"); return 1; }
}

get(){
return 0;
}
init() {
  add_action("enter_hall","enter");
}

enter_hall(str) {
  if (this_player()->query_level() > 8 &&
      this_player()->query_level() < 21) return 0;  /* Added - Rumplemintz */
                                                    /* 2-Oct-09            */
  if(str && str == "hall") {
   this_player()->move_player("into the Hall of Apprentices#players/softly/nhall/rooms/n1");
    return 1; }
  else { notify_fail("Enter what?\n"); return 0; } }
