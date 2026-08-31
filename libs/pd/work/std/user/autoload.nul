/*
// autoload.c: adapted from 2.4.5 code by Truilkan@TMI
// inherited by /std/player.c
//
// This version stores the filenames to be autoloaded in an array
// named auto_load.
// (2-10-92) A potential problem caused by objects using the old
// style query_auto_load() { return 1; } fixed by Buddha
//  Added logging support for autoloading errors
*/

mixed *auto_load;
mixed *bad_load;

/*
// load_autoload_obj: clones each object in the auto_load array into
// the player's inventory at login time.  Sends any stored data to
// the init_arg method
*/
#define MOVED_AREAS_FREEPK ({"keys","merkkerri","purgatory"})
#define MOVED_AREAS_NOPK ({"arlon","standard","tirun"})

mixed *query_bad_load() { return bad_load || ({}); }
void add_bad_load(mixed thing) {
  if (!sizeof(bad_load)) bad_load = ({ });
  bad_load += ({ thing });
}
void del_bad_load() { bad_load = ({ }); }
mixed *query_autoload() { return auto_load; }
void load_autoload_obj() {
  if (!sizeof(auto_load)) {
    return;
  }

  foreach (mixed thing in auto_load) {
    string file;
    mixed *argument;
    string err;
    object ob;
    if (stringp(thing)) sscanf(thing, "%s:%s", file, argument);
    else if (pointerp(thing) && sizeof(thing) == 2) {
      file = thing[0];
      argument = thing[1];
    }
    else continue;
    if (!file) continue;

    if (err = catch(ob = clone_object(file))) {
      add_bad_load(thing);
      //write("Unable to autoload: "+file+"\n");
      write_file("/load/autoload/"+this_object()->query_name(),
        ctime(time())+" "+file+": "+err+"\n\n");
      continue;
    }

    if (ob) {
      if (sizeof(argument)) {
        if (err = catch(ob->init_arg(argument))) {
          add_bad_load(thing);
          write_file("/load/autoload/"+this_object()->query_name(), ctime(time())+" "+file+": "+err+"\n\n");
          continue;
        }
      }
      ob->move(this_object());
    }
  }
}

/*
   compute_autoload_array: this method is called by ./save.c prior to each
   time the player is saved.
*/

void compute_autoload_array()
{
    object *inv, ob;
    mixed item;
    int j, ok;

    auto_load = ({});
    inv = all_inventory(this_object());
    for (j = 0; j < sizeof(inv); j++) {
	ob = inv[j];
	item = (mixed)call_other(ob, "query_auto_load");
	ok = 0;
	if (pointerp(item)) {
	    if ((sizeof(item) == 2) && stringp(item[0]))
		ok = 1;
	}
	else if (stringp(item))
	    ok = 1;
	if (!ok && item) {
	    //                        sscanf(file_name(ob), "%s#%*d", item);
	    item = base_name(ob);
	    item += ":";
	}
	if (item)
	    auto_load += ({ item });
    }
}

/* destroy_autoload_obj: this is called at logout time */

void destroy_autoload_obj()
{
    object *inv;
    int j;

    inv = all_inventory(this_object());
    for (j = 0; j < sizeof(inv); j++)
	if (inv[j]->query_auto_load())
	    inv[j]->remove();
}


