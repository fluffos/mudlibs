/**
* @file /adm/daemons/modules/virtual/player.c
* The virtual daemon that is responsible for creating player
* objects.
*
* @created 2024-07-30 - Gesslar
* @last_modified 2024-07-30 - Gesslar
*
* @history
* 2024-07-30 - Gesslar - Created
*/

inherit STD_DAEMON;

public nomask object compile_object(string file) {
  object ob;
  string e;
  string type = query_file_name();
  string test = sprintf("^/%s/\\w+$", type);

  if(!pcre_match(file, test))
    return 0;

  e = catch(ob = new(STD_PLAYER));
  if(e || !ob) {
    log_file("VIRTUAL", e);
    debug("Error: " + e ?? "Unable to instantiate virtual player object.");
    return 0;
  }

  ob->set_virtual_master(STD_PLAYER);

  return ob;
}
