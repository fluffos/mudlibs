/*    /daemon/postal/options.c
 *    from Nightmare IV
 *    IIPS options management system
 *    created by Descartes of Borg 940502
 */

#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <objects.h>
#include <security.h>
#include "options.h"

inherit DAEMON;

private mapping __MyGroups;
private mapping __Options;
nosave private string __Owner;

void create() {
    daemon::create();
    set_no_clean(1);
    __MyGroups = ([]);
    __Options = ([]);
    __Owner = 0;
}

 private int valid_access() {
    switch(base_name(previous_object(0))) {
        case OB_POSTAL: case FOLDERS_D: case LETTERS_D:
        case LOCALPOST_D: case REMOTEPOST_D: case OPTIONS_D:
          return 1;
        default: return 0;
    }
}

void assure_box_exists(string who) {
    string tmp, file;

    if(!valid_access()) return;
    if(__Owner == who) return;
    file = DIR_POSTAL+"/"+who[0..0]+"/"+who+"/postalrc"+__SAVE_EXTENSION__;
    if(unguarded((: file_exists, file :))) return;
    // DIR_POSTAL itself is assumed to already exist below (only its
    // per-letter shard and per-player subdirectory get created), which is
    // true on a long-running install where it was mkdir'd by hand once,
    // long ago, but false on a fresh checkout of this repo -- mkdir()
    // can't create a directory whose PARENT doesn't exist either, so
    // every one of these calls silently no-ops and the final
    // save_object() below fails ("Could not open .../postalrc.o.tmp for
    // a save"), caught by the CATCH() around setup() so it never crashes
    // a login, just repeats on every single one. Ensure the top level
    // exists too, not just the two levels under it.
    if(unguarded((: file_size, DIR_POSTAL :)) != -2) unguarded((: mkdir, DIR_POSTAL :));
    file = DIR_POSTAL+"/"+who[0..0];
    if(unguarded((: file_size, file :)) != -2) unguarded((: mkdir, file :));
    file = DIR_POSTAL+"/"+who[0..0]+"/"+who;
    if(unguarded((: file_size, file :)) != -2) unguarded((: mkdir, file :));
    __MyGroups = ([]);
    __Options = ([]);
    __Owner = who;
    unguarded((: save_object, file+"/postalrc" :));
}

 private void load_options(string who) {
    string file;

    if(who == __Owner) return;
    this_object()->assure_box_exists(who);
    if(__Owner == who) {
        return;
      }
    __Owner = who;
    file = DIR_POSTAL+"/"+who[0..0]+"/"+who+"/postalrc";
    unguarded((: restore_object, file :));
  }

 private void save_options() {
    string file;

    file = DIR_POSTAL+"/"+__Owner[0..0]+"/"+__Owner+"/postalrc";
    unguarded((: save_object, file :));
}

void set_option(string who, string option, mixed value) {
    if(base_name(previous_object()) != OB_POSTAL) return;
    load_options(who);
    __Options[option] = value;
    save_options();
}

mixed query_option(string who, string option) {
    string tmp;

    tmp = base_name(previous_object());
    if(tmp != OB_POSTAL && tmp != LOCALPOST_D && tmp != FOLDERS_D) return 0;
    load_options(who);
    return __Options[option];
}

mapping query_options(string who) {
    string tmp;

    tmp = base_name(previous_object());
    if(tmp != OB_POSTAL && tmp != LOCALPOST_D && tmp != FOLDERS_D) return ([]);
    load_options(who);
    return copy(__Options);
}

void set_group(string who, string group, string *members) {
    if(!valid_access()) return;
    load_options(who);
    if(!members) map_delete(__MyGroups, group);
    else __MyGroups[group] = members;
    save_options();
  }

string *query_group(string who, string group) {
    if(!valid_access()) return ({});
    load_options(who);
    return copy(__MyGroups[group]);
  }

mapping query_groups(string who) {
    if(!valid_access()) return ([]);
    load_options(who);
    return copy(__MyGroups);
  }
