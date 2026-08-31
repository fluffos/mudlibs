#include <std.h>

inherit DAEMON;

int cmd_ddg(string str) {
  object ob = get_object(str);
  string* ids;
  if(str == "drop") {
    if(this_player()->query_long() == "You don't see that here.") this_player()->force_me("vis");
    this_player()->remove_disguised_short();
    this_player()->remove_disguised_id();
    this_player()->remove_disguised_name();
    this_player()->remove_disguised_long();
    return 1;
  }
  else if(str == "invis") {
    this_player()->set_name("nothing");
    this_player()->set_disguised_long("You don't see that here.");
    this_player()->force_me("invis");
    return 1;
  }
  if(!ob) return notify_fail("Could not find object.");

  if(!ob->is_room() && ob->query_id()) ids = ob->query_id();
  else if(ob->is_player()) ids = ({ ob->query_name() });
  else {
    ids = ({});
    if(ob->query_name()) {
      ids += ({ ob->query_name() });
      ids += explode(ob->query_name(), " ");
    }
    else if(ob->query_short())  ids += explode(ob->query_short(), " ");
    ids += ({ ob->query_short() });
  }
  ids = map(ids, (:lower_case($1):));

  this_player()->set_disguised_short(ob->query_short());
  this_player()->set_disguised_id(ids);
  this_player()->set_disguised_name(capitalize(ob->query_name()?ob->query_name():ob->query_short()));
  this_player()->set_disguised_long(ob->query_long());
  return 1;
}
