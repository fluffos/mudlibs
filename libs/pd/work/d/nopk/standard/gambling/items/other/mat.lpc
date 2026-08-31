//Coded by Ace
#include <std.h>
inherit OBJECT;

void init() {
    ::init();
    add_action("cmd_watch", "watch");
}
object *WATCHERS=({});
int check_watchers();
int tell(string str, object tp);

void create() {
    ::create();
  set_id(({"bones mat", "mat"}));
  set_name("bones mat");
  set_short("a small mat");
  set_long( "This mat is used to play the game of bones.  From here "
     "you can watch bones being played.");
  set_mass(1);
  set_value(0);
  set_prevent_get("You can't take the mat.");
}
int check_watchers() {
    for(int i=0; i<sizeof(WATCHERS); ++i)
      if(!WATCHERS[i] || !present(WATCHERS[i], environment(this_object())))
        WATCHERS-=({WATCHERS[i]});
    return 1;
}
int cmd_watch(string str) {
    if(!str) return 0;
    if(str!="bones") return 0;
    for(int i=0; i<sizeof(WATCHERS); ++i)
      if(WATCHERS[i]==this_player())
        return notify_fail("You are already watching the game.\n");
    message("info", "You are now watching the bones game.",
      this_player());
    WATCHERS+=({this_player()});
    return 1;
}
int tell(string str, object tp) {
  check_watchers();
  message("info", "%^BOLD%^%^MAGENTA%^"+str, WATCHERS, tp);
  return 1;
}

