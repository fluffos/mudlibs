/*
 * Enables to drink a vitem
 * inherit for std/room
 * std/room needs the following:
 *   AddRoomCmd("drink", "cmd_drink_vitem");
 * and overload reset() to call our reset function
 * all others is handled by vitems itself
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
nosave string *reset_drink_speed_up;

//*****************************************
// Query the internal Variable (read only!)
//*****************************************
// can be removed later?!
string *QueryDrinkResetSpeedUp() { return reset_drink_speed_up; }

/*--------------------------------------------------------------------------
 * drink a single vitem
 *
 * TODO: add 'all' handling
 *--------------------------------------------------------------------------
 */
public int cmd_drink_vitem(string str) {
  string v_id;                      // vitem to find
  mixed item;                       // item to clone
  int act,max;                      // number of items
  object ob;                        // cloned object

  // no string is given -> fast return -> handle it by std/living
  if (!str) return 0;

  if (present(str)) return 0;     // allow normal drink of other objects

  // now we check if there is a vitem available that matches to the
  // given string
  v_id=GetVItem(norm_id(str),2);
  if (!v_id) return 0;              // no vitem matched

  // we found a matching vitem!
  // let us check, if it is drink-able
  // check if property-entry P_DRINK exists
  item=VQuery(v_id,P_DRINK);

  // item:  closure|mapping

  if (!item) {                      // No 'drink-property' found
    notify_fail("It's not drinkable!\n");
    return 0;                       // set NOTIFY_NOT_VALID ?
  }

  // yeah we found the property!
  // now let us check if we can drink that item:

  act=VQuery(v_id,P_AMOUNT);        // how many objects are there?
  max=VQuery(v_id,P_MAX_AMOUNT);    // how many objects can be there?

  // is there an item left?
  if (max==0) {                     // no max amount specified!
    if (act==0) {                   // and no amount specified
      act=1;                        // max=act=1; (only filename is given)
      max=-1;                       // NOTE: if nothing than the drink is set
                                    // we will have unlimited drinks!!!
    } else {                        // no max given, but amount specified
      max=act;                      // set max amount to amount
    }
  }
  if (max==-1) {                    // unlimited objects available!
    act=1;                          // we have always one object available!
  }

  if (act<=0) {
    notify_fail("There is nothing left to drink.\n");
    return 0;                       // no item left, wait for next reset
  }

  // yeah the item is drink-able!
  // item can be mapping or closure - all other values are ignored!!
  if (mappingp(item)) {
    ob=clone_object("/std/food");   // no NEVER clone drink here !!
                                    // a vessel will be cloned too
    ob->SetProperties(item);        // item==string -> clone this object!
// TODO: problem with our std/drink -> it doesn't support PROPERTIES!
// the new drink from sonic will solve that problem!
  } else if (closurep(item)) {      // item==closure ->
    ob=funcall(item);               // should return the cloned object or 0
  }
  if (!ob) return 0;                // error message?

  // now we have a cloned object to move into the player
  // to let the player drink it!

  // fill the speed up array for making a fast reset!
  if (!reset_drink_speed_up) reset_drink_speed_up=({v_id});
  else
    // add only, if not inside the spee-up array
    if (member(reset_drink_speed_up,v_id)==-1)
       reset_drink_speed_up+=({v_id});


  // move the object to the player (needed for the eat-cmd)
  ob->AddId("__v_drink__");         // to identify our drink obj
  ob->move(TP,M_SILENT);            // move the drink into player
  TP->command_me("drink __v_drink__"); // let the player try to drink it

  // the drink may fail (player is soaked enough or he can't drink that
  // type of drink?!) --> we should destruct the drink inside the player!
  if (ob) ob->remove();

  act--;                            // reduce the number of drinks
  if (max!=-1) {                    // don't store the values back
    VSet(v_id,P_AMOUNT,act);
    VSet(v_id,P_MAX_AMOUNT,max);
  }
  return 1;
}


//*************************************
// help function for resting the vitems
//*************************************
private int reset_vitem_drink(string vi) {
  int act;
  // set actual amount to max available amount!
  act=VQuery(vi,P_MAX_AMOUNT);       // ever specified, because the drink
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

  if (!reset_drink_speed_up) return;
                            // fast, if nothing was drunken meanwhile
  filter(reset_drink_speed_up,#'reset_vitem_drink);
  // speed up the next reset, if nothing was drunken meanwhile:
  reset_drink_speed_up=0;
}

