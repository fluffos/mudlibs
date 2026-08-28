#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>

inherit DAEMON;

int cmd_home(string str) {
    object ob, prev;
    string who;

    prev = environment(this_player());
    if(!str) who = (string)this_player()->query_name();
    else who = lower_case(str);
    str = user_path(who);
    if(ob = (object)this_player()->query_property("workroom")) {
        if(ob == prev) return notify_fail("You twitch.\n");
        if((int)this_player()->move(ob) == MOVE_OK) {
            this_player()->describe_current_room(1);
            if(hiddenp(this_player()) || this_player()->query_invis())
              return 1;
            message("mmout", (string)this_player()->query_mhome(), prev);
            message("mmin", (string)this_player()->query_mmin(), ob, 
              ({ this_player() }));
            return 1;
        }
    }
    if(!ob) {
      if(!(ob = load_object(str+"workroom")) &&
        str == user_path((string)this_player()->query_name())) {
        ob = new(OB_WORKROOM);
        this_player()->set_property("workroom", ob);
      }
      else if(!(ob = load_object(str+"workroom"))) {
        if(!(ob = find_player(who)) || !(ob=(object)ob->query_property("workroom")))
          return notify_fail(capitalize(who)+" has no active workroom.\n");
      }
      else {
        if(file_name(prev) == str+"workroom")
          return notify_fail("You twitch.\n");
        if((int)this_player()->move(ob) == MOVE_OK) {
            this_player()->describe_current_room(1);
            if(hiddenp(this_player()) || this_player()->query_invis())
              return 1;
            message("mmout", (string)this_player()->query_mhome(), prev);
            message("mmin", (string)this_player()->query_mmin(),
              environment(this_player()), ({ this_player() }));
            return 1;
        }
        return notify_fail("You stay where you are.\n");
      }
    }
    if(ob == prev) return notify_fail("You twitch.\n");
    if((int)this_player()->move(ob) == MOVE_OK) {
        this_player()->describe_current_room(1);
        if(hiddenp(this_player()) || this_player()->query_invis()) return 1;
        message("mmout", (string)this_player()->query_mhome(), prev);
        message("mmin",(string)this_player()->query_mmin(),ob,({this_player()}));
        return 1;
    }
    return notify_fail("You stay where you are.\n");
}
