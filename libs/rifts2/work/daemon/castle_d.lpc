//  Castle update daemon...extremely simple.
//  Diewarzau
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <dirs.h>

void save_castles();

mapping castles = ([]);

void save_castles() {
    seteuid(UID_DAEMONSAVE);
    save_object(DIR_DAEMONS_SAVE+"/castles");
    seteuid(getuid());
    return;
}

void create() {
    seteuid(getuid());
    if(!event_pending(this_object())) {
        this_object()->check_upkeep();
        event("check_upkeep", 86400, 0, 1);
    }
    restore_object(DIR_DAEMONS_SAVE+"/castles");
    return;
}

int no_dest(object item) {
    if(item->query_is_locker()) {
        return 0;
    }
    return 1;
}

void update_room(object what) {
    int i;
    object *inv;
    string name;

    if(!what->is_castle())
        return;
    inv = filter_array(all_inventory(what), "no_dest", this_object());
    i = sizeof(inv);
    while(i--)
        inv[i]->move(ROOM_VOID);
    SAVE_ITEMS_D->update_lockers(what);
    name = base_name(what);
    seteuid(getuid(this_object()));
    seteuid(UID_ROOT);
    destruct(what);
    seteuid(getuid());
    i = sizeof(inv);
    while(i--)
        inv[i]->move(name);
    return;
}

void check_upkeep() {

    
    string *dir, file;
    string owner, *remv;
    mixed *cdata;
    object *inv, room;
    int idx;

    /*
        removed until we get this thing working.
    */
    return;
    dir = ({});
    remv = ({});
  foreach(owner, cdata in castles) {
    if(cdata[1] >= time()) continue;

    dir += ({ owner });
    message("info", "A gang of dwarves appears and tears down the castle with "+
        "blinding speed!", load_object(cdata[2]));
    for(idx = 1; idx <= cdata[0]; idx++) {
      room = load_object(sprintf("/d/damned/virtual/%s_room_%d.castle", owner, idx));
      if(!room) continue;
      inv = filter_array(all_inventory(room), (: living :));
      map_array(inv, (: call_other :), "move", cdata[2]);
      map_array(inv, (: message($2, $3, $1) :), "info",
          "The castle is torn down by dwarves, and you escape just in time!");
      seteuid(UID_ROOT);
      destruct(room);
      seteuid(UID_DAMNED_DATA);
    }
    remv += ({ sprintf("/d/damned/virtual/%s_room_1.castle", owner) });
    call_other(cdata[2], "remove_exit", "castle");
  }
  foreach(file in dir) map_delete(castles, file);

  seteuid(UID_DAMNED_DATA);
  dir = read_database("/d/damned/data/world_items.db");
  foreach(file in remv) {
    idx = sizeof(dir);
    while(idx--) {
      if(strsrch(file, dir[idx]) != -1)
        dir = exclude_array(dir, idx);
    }
  }
  save_castles();
  return;
}

void add_upkeep(string owner, int time) {
    if(!castles)
        return;
    if(!castles[owner] || !pointerp(castles[owner]))
        return;
    castles[owner][1] += time;
    save_castles();
    return;
}

void add_room_to_castle(string owner) {
    if(!castles)
        return;
    if(!castles[owner] || !pointerp(castles[owner]))
        return;
    castles[owner][0]++;
    save_castles();
    return;
}

int upkeep_cost(string owner) {
    float upkeep;

    if(!castles)
        return 0;
    if(!castles[owner] || !pointerp(castles[owner]))
        return 0;
    upkeep = 4000.0 + 10000.0 * to_float(castles[owner][0]);
    return to_int(upkeep * currency_rate("gold"));
}

int time_left(string owner) {
    if(!castles)
        return 0;
    if(!castles[owner] || !pointerp(castles[owner]))
        return 0;
    return castles[owner][1] - time();
}

void register_castle(string owner, string wfile) {
    if(!castles)
        castles = ([]);
    castles[owner] = allocate(3);
    castles[owner][0] = 1;
    castles[owner][1] = time()+ 2594000;
    castles[owner][2] = wfile;
    save_castles();
    return;
}

int is_registered(string owner) {
    if(!castles || !castles[owner])
        return 0;
    return 1;
}
