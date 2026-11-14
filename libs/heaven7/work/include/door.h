/* door.h is now redundant as door code has been added to room2. This file
   should make a socket between the old door.h and the new doors. The new 
   door functions are a little more consistent with thief skills. Bash has 
   been removed as opening doors without a key, is the realm of the thief ;)

   make_doors() is used by a "master" room, which makes "slave" doors in
   the destination rooms. If the master room is updated all slave rooms
   are updated. However, when a slave room is update the master room has
   no way of knowing this, and the reverse door exit is lost. The door is
   recovered when make_doors() is called again in the master room. Normally,
   at the next reset(1).

   For this reason it is recommended that you don't use this function. Use
   load_door() instead.  Load a door to exit to the appropriate destination,
   and in the destination room load the reverse door. Thus updating the
   room will not loose the exit.
 */

#define DOORS  /* appends " doors" to door id */
#define obj_1 "objects/dummy"
#define obj_2 "objects/dummy"
int door_seed;

void make_doors(string loc_1,
                string dir_1,
                string loc_2,
                string dir_2,
                string lock_long,
                string keyid, 
                string door_long,
                status is_closed,
                status is_locked,
                status can_lock) {  /* redundant, use keyid = "no_key" */
   reset_doors(0);
   /* this will work unless its a secret door - and its not secret */
#ifdef DOORS
   if(call_other(loc_1,"id",dir_1 +" door")
   && call_other(loc_2,"id",dir_2 +" door")) {
    return;
   }
#else
   if(call_other(loc_1,"id",dir_1) && call_other(loc_2,"id",dir_2)) return;
#endif
 
   /* no door or one room dested */
#ifdef DOORS
   call_other(loc_1, "remove_door", dir_1 +" door");
   call_other(loc_2, "remove_door", dir_2 +" door");
#else
   call_other(loc_1, "remove_door", dir_1);
   call_other(loc_2, "remove_door", dir_2);
#endif
   door_seed += 1;
   call_other(loc_1,"load_door",({
       "destination",       loc_2,
#ifndef DOORS
       "direction",         dir_1,
#else
       "direction",         dir_1 +" door",
#endif
       "key id",            keyid,
       "description",       door_long,
       "lock difficulty",   13,
       "lock id",           "lock",
       "lock description",  lock_long,
/*
       "trap description",  "You find a small poisoned dart trap.\n",     
       "trap damage",       10,
       "trap message",      "A poison dart sticks into your leg!\n",
       "trap room message", "A poison dart sticks into @@query_name:"+
                            "$this_player()$@@'s leg!\n",
 */
       ((is_closed) ? "closed" : "open"),  
       ((is_locked) ? "locked" : "unlocked"),  
       "door number",       door_seed,
   }));
   call_other(loc_2,"load_door",({
     "destination",       loc_1,
#ifndef DOORS
     "direction",         dir_2,
#else
     "direction",         dir_2 +" door",
#endif
     "key id",            keyid,  
     "description",       door_long,
     "lock difficulty",   13,
     "lock id",           "lock",
     "lock description",  lock_long,
/*
     "trap description",  "You find a small poisoned dart trap.\n",     
     "trap damage",       10,
     "trap message",      "A poison dart sticks into your leg!\n",
     "trap room message", "A poison dart sticks into @@query_name:"+
                          "$this_player()$@@'s leg!\n",
 */
     ((is_closed) ? "closed" : "open"),  
     ((is_locked) ? "locked" : "unlocked"),  
     "door number",       door_seed,
   }));
} 


status set_all(string str) {  
  string door_room, direction, lock_desc, key_id;
  int is_closed, is_locked, can_lock;

  if(!str) return 0;  
  if(sscanf(str, "%s %s %s %s %d %d %d", door_room, 
                                         direction,
                                         lock_desc,   
                                         key_id,
                                         is_closed,
                                         is_locked,
                                         can_lock) == 7) {  
    if(lock_desc == "0") lock_desc = 0;  
    call_other(this_object(),"load_door",({
     "destination",       door_room,
     "direction",         direction,
     "key id",            key_id,
     "description",       "A door leading "+ direction +".\n",
     "lock difficulty",   13,
     "lock id",           "lock",
     "lock description",  lock_desc,
     "trap description",  "You find a small poisoned dart trap.\n",     
     "trap damage",       10,
     "trap message",      "A poison dart sticks into your leg!\n",
     "trap room message", "A poison dart sticks into @@query_name:"+
                          "$this_player()$@@'s leg!\n",
     ((is_closed) ? "closed" : "open"),  
     ((is_locked) ? "locked" : "unlocked"),  
    }));
    return 1;  
  }  
  return 0;  
}  
