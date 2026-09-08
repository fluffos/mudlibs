// This is the office of the harbourmaster.
// created: [tune] 12-jun-97
// changed: [Sonic] 05-jul-1997, added coordinates/regions

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>

inherit BASEROOM;

string vitem_telescope_long( string what, string v_id ) {
  string * ads;
  mixed tmp, *who;
  string *rooms, res;
  int x, tmp2;

  /* redefine the silly what */
  ads = VQuery( v_id, P_LAST_ADS );
  what = (sizeof(ads)?(implode(ads, " ")+" "):"")+VQuery( v_id, P_LAST_ID );

  /* now check for the preposition used */
  if ( VQuery( v_id, P_LAST_PREP ) == "through" ) {
    /* check day or night */
    if( !({int})NIGHTDAY->IsDay() )
      return "It is too dark outside too see anything of interest.\n";

    rooms = ({ SIL_HARBOUR("quay1_1"), SIL_HARBOUR("quay1_2"),
               SIL_HARBOUR("quay1_3"), SIL_HARBOUR("quay2_1"),
               SIL_HARBOUR("quay2_2"), SIL_HARBOUR("quay2_3") });
    who = ({});
    for(x = 0; x < sizeof(rooms); x++) {
      if(tmp = find_object(rooms[x]))
        who += all_inventory(tmp);
    }
    if(sizeof(who))
      who = filter_objects(who, "QueryIsLiving");

    res =
      "You put your eye to the " + what + ". The view from the "
      "office window swims into focus at an alarming size! The area "
      "around the docks can be seen in clear detail. ";

    if(tmp2 = sizeof(who)) {
      res += "You can discern the figure" +(tmp2 > 1 ? "s" : "")+" of ";
      for(x = 0; x < sizeof(who); x++)
        who[x] =  ({string})who[x]->Query(P_NAME);
    }
    res += implode_list( who );
    return res;
  }
  else {
    return
      "A long, polished tube of brass, with glass fitted into both "
      "ends. The contraption is set up on a stand fixed to the floor "
      "before the window. It points out to the harbour and the open "
      "sea beyond the towers.\n";
  }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);

   Set(P_INT_SHORT,"Upstairs in the Harbourmaster's Office");
   Set(P_INT_LONG,
      "A tiny room above the office. Big window looking out on "
      "the harbour. A telescope is set up, pointing out towards "
      "the harbour.\n");

   Set(P_INT_WIZMSG,
      " %^BOLD%^*** Sorry, no details yet. ***%^RESET%^\n"
      " Down: Back to the office of the harbourmaster.\n");

   AddVItem( ([
              P_ADS : ({ "brass" }),
              P_IDS : ({ "telescope", "spy glass", "tube" }),
              P_PREPS : ({ "through" }),
              P_LONG : #'vitem_telescope_long /*'*/
   ]) );

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -200,0,10 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into a wall.\n");

   AddExit("down", SIL_HARBOUR("harbourmaster"));
}
