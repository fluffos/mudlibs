/*
 * Enables to get a vitem
 * inherit for std/room
 * std/room needs the following:
 *   AddRoomCmd("get", "cmd_get_vitem");
 *   AddRoomCmd("take","cmd_get_vitem");
 * and you need to overload reset() of room to call the reset function
 *   of vget.c!
 * all others is handled by vitems itself
 *
 * TODO: the command handling itself should be moved to the std/living
 *       instead of the std/room !
 */

#include <properties.h>
#include <moving.h>
#include <npc.h>

//********
// defines
//********
#define TP this_player()
#define TO this_object()

//******************************
// Prototypes for vitems
// defines in /std/room/vitems.c
//******************************
public varargs mixed GetVItem(string str,mixed prop,mapping vi);
public mixed VQuery(string id,string prop);
public mixed VSet(string id,string prop,mixed val);

//*******************
// internal variables
//*******************
// don't save the internal variables (save_object/restore_object)
nosave string *reset_speed_up;

//*****************************************
// Query the internal Variable (read only!)
//*****************************************
// can be removed later?!
string *QueryResetSpeedUp() { return reset_speed_up; }

/*--------------------------------------------------------------------------
 * output the noget msg
 *--------------------------------------------------------------------------
 */
private int send_no_get_msg(mixed noget,string str) {
  if (intp(noget)) {              // integer != 0 -> default msg
    write("You can't get "+str+".\n");
    show(({string})TP->QueryName()+" fails to get something.\n");
    return 1;
  }
  if (stringp(noget)) {           // use string as failure msg
    write(noget);
    return 1;
  }
  if (pointerp(noget)) {          // array of strings
    switch (sizeof(noget)) {
      case 2: write(funcall(noget[0]));    // interactive player
              say(funcall(noget[1]));      // all others
              return 1;
      default:
              write(funcall(noget[0]));    // interactive player
              return 1;
    }
  }
  // NOSTY - verify
  return 0;
}


/*--------------------------------------------------------------------------
 * get a single vitem
 *
 * TODO: add 'all' handling
 *--------------------------------------------------------------------------
 */
public int cmd_get_vitem(string str) {
  string v_id;                      // vitem to find
  mixed item;                       // item to clone
  int act,max;                      // number of items
  object ob;                        // cloned object
  mixed noget;                      // noget property

  // no string is given -> fast return -> handle it by std/living
  if (!str) return 0;

  // the following:
  // 'if (present..' - can be removed if the command for "get/take"
  // is moved to std/living
  // do we need now 'search' instead of 'present' ?
  if (present(str)) return 0;     // allow normal get

  // now we check if there is a vitem available that matches to the
  // given string
  v_id=GetVItem(norm_id(str),2);
  if (!v_id) return 0;              // no vitem matched

  // let us check, if the item has a P_NOGET property set!
  noget=VQuery(v_id,P_NOGET);       // do we have a noget property set?
  if (noget)                        // yes we have one
    return send_no_get_msg(noget,str);

  // we found a matching vitem!
  // let us check, if it is get-able
  // check if property-entry PV_ITEM_LOCATION exists
  item=VQuery(v_id,PV_ITEM_LOCATION);

  // item:  "location",actual,maximum

  if (!item) {                      // No 'get-property' found
    notify_fail("That one can't be get!\n"); // or similar?
            // notify_fail(string) with return 0 is overloaded by the
            //std/living command get/take !!
    return 0;                       // set NOTIFY_NOT_VALID ?
  }

  // yeah we found the property!
  // now let us check if we can get that item:

  act=VQuery(v_id,P_AMOUNT);        // how many objects are there?
  max=VQuery(v_id,P_MAX_AMOUNT);    // how many objects can be there?

  // is there an item left?
  if (max==0) {                     // no max amount specified!
    if (act==0) {                   // and no amount specified
      act=1;                        // max=act=1; (only filename is given)
      max=1;
    } else {                        // no max given, but amount specified
      max=act;                      // set max amount to amount
    }
  }
  if (max==-1) {                    // unlimited objects available!
    act=1;                          // we have always one object available!
  }

  if (act <= 0)
  {
      mixed nf;

      nf = funcall(VQuery(v_id, PV_NONE_LEFT));
      notify_fail(nf || ("There is no "+VQuery(v_id, P_SHORT)+" left to take.\n"), NOTIFY_NOT_VALID);
      return 0;
  }

  // yeah the item is getable!
  // item can be string or closure - all other values are ignored!!
  if (stringp(item)) {
    ob=clone_object(item);          // item==string -> clone this object!
  } else if (closurep(item)) {      // item==closure ->
    ob=funcall(item);               // should return the cloned object or 0
  }
  if (!ob) return 0;                // error message?

  // now we have a cloned object to move into the player (or the room, if he
  // can't hold it!)

  // fill the speed up array for making a fast reset!
  if (!reset_speed_up) reset_speed_up=({v_id});
  else
    // add only, if not inside the spee-up array
    if (member(reset_speed_up,v_id)==-1) reset_speed_up+=({v_id});

  // move the object to the player
  // use the std/npc->Take() ?

  // first move the item to the room, use M_SILENT
  ob->move(TO,M_SILENT);           // M_NOCHECK ?

  // now move the cloned object from the room into the player
  if (({int})ob->move(TP,M_GET) != ME_OK) {
    write("You can't hold it!\n");
  } else if (!VQuery(v_id, PV_SILENT_GET)) {
    // query_verb() allows commands for "pick","pull" and so on....
    // tomap them to a gettake-command!
    write("You "+query_verb()+" "+add_a(str)+".\n");
    show(({string})TP->QueryName()+" takes something.\n");
  }
  act--;                            // reduce the number of objects
  if (max!=-1) {                    // don't store the values back
    VSet(v_id,P_AMOUNT,act);
    VSet(v_id,P_MAX_AMOUNT,max);
  }
  return 1;
}


//*************************************
// help function for resting the vitems
//*************************************
private int reset_vitem_get(string vi) {
  int act;
  // set actual amount to max available amount!
  act=VQuery(vi,P_MAX_AMOUNT);       // ever specified, because the get/take
                                     // had set the value!
  VSet(vi,P_AMOUNT,act);
  return 0;                          // no - never include it into the new
                                     // array by filter!
}

//**********************************
// reset items, which are taken away
//**********************************
void reset() {
  // we use a special array that holds the vitem#number string
  // of the touched vitems.
  // we don't need to reset each vitem, only the touched ones!
  // this will speed up the reset muchmore than any walk_mapping or so!

  // we use filter (fast!!) - return value ignored, we don't need it

  if (!reset_speed_up) return;        // fast, if nothing was got meanwhile
  filter(reset_speed_up,#'reset_vitem_get);
  // speed up the next reset, if none was taken meanwhile:
  reset_speed_up=0;
}

