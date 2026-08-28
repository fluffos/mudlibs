/*
 * A command that protects auto-loading crash items.
 * Three maximum.
 *
 * Diewarzau 8/3/96
 * DarkeLIB 1.0
 */

int cmd_protect(string str) {
  object *inv, ob;

  if(!str) {
    write("Items Protected:\n"+repeat_string("-=", 35));
    inv = filter_array(all_inventory(this_player()),
		       (: call_other :), "query_short");
    inv = filter_array(inv, (: ((string)$1->query($2) == $3) :),
		       "protected by", (string)this_player()->query_name());
    if(!sizeof(inv)) {
      write("None.");
      return 1;
    }
    map_array(inv, (: write((string)$1->query_short()) :));
    if(sizeof(inv) > 3)
      write("%^RED%^%^BOLD%^WARNING!!!%^RESET%^  More that 3 items are "
	    "protected.  Only the first 3 will save.");
    return 1;
  }
  ob = present(str, this_player());
  if(!ob) {
    write("You do not have '"+article(str)+"'.");
    return 1;
  }
  if(ob->query_auto_load()) {
    write("You cannot protect auto loading objects.\n"+
	  "They are already crash-safe.");
    return 1;
  }
  if((string)ob->query("protected by") == (string)this_player()->
     query_name()) {
    write((string)ob->query_short()+" is no longer crash-safe.");
    ob->set("protected by", 0);
    return 1;
  }
  else {
    if(ob->query_property("no save")) {
      write("That item may not be crash-protected.");
      return 1;
    }
    write((string)ob->query_short()+" is now crash-safe.");
    ob->set("protected by", (string)this_player()->query_name());
    return 1;
  }
}

int help() {
  message("help",
	  "This command is used to make items crash-safe.  The first "
	  "THREE crash-safe items in your inventory will automatically "
	  "come back after a crash regardless.  If you have more than "
	  "three crash-safe items in your inventory, there is no way to "
	  "control which ones will be saved, though you are informed which "
	  "ones are saved every time your character autosaves.\n\n"
	  "Syntax:\n"
	  "protect (no args) - tells which items are crash-safe.\n"
	  "protect <item> - toggles crash-safe on/off for that item.\n",
	  this_player());
  return 1;
}

