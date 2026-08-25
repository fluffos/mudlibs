
#define ARMS "/baseobs/armours/"
#define WEPS "/baseobs/weapons/"

mapping shelves;

/* this can be used as a template for other shop tables */
/* The first number should be the quantity of the item you would
   like the shop to put into play per week (number bought by
   players minus number sold to the shop) The second number is
   the number cloned into the storeroom at a time.  This will
   NOT work if you have ANY items add_cloned into the storeroom
   in some other way (like in its setup()), it will just ignore
   this number in that case.  You can still set goals for all
   the items though.  If for some reason you need to use
   clone_object() in the storeroom the table can still be used
   to set a sales goal for that item, just put a "0" for the
   second number.  The format is:
   "file name"  :  ({ number sold per week , number to clone }),
/d/ss/daggerford/SHOP_TABLE.c From 1 to 21 of 68 (30%) - h for help.
   */
/* IMPORTANT! IF you want items to be add_cloned into a shop with
    a reset function, you must have a ::reset() in the function    */

create() {
     shelves = ([
          ARMS+"leather"       :   ({6 , 2 }),
          ARMS+"med_shield"    :   ({10 , 1 }),
          ARMS+"cloak"         :   ({6 , 2 }),
          ARMS+"ringmail"      :   ({7 , 1 }),
          WEPS+"dagger"        :   ({4 , 2 }),
  ]);

}
mapping query_shelves() {
    return shelves;
}
