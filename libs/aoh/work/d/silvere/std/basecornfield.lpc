// This is the standard room for the cornfield newbie area
// created:          Tune     [13-May-1999]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>
#include <msgclass.h>
#include <config.h>


inherit BASEROOM;

mixed pick_corn(string str);
string corn_long();
object pick_corn_vitem();

string v_corn;

varargs void create()
{
   ::create(1);

   Set(P_INDOORS, 0);

   SetIntShort("In the midst of a large cornfield");
   SetIntLong(
     "A large cornfield. Tall stalks block the view in most directions.\n");

   AddVItem(
    ([ P_IDS : ({ "bramble", "brambles" }),
       P_ADS : ({ "thick", "prickly" }),
       P_LONG : "Thick patches of thorny brambles grow in clumps throughout "
                "the large field. Sadly, the field has not been tended to very "
                "well in recent years.\n"
     ]) );

   v_corn = AddVItem(
    ([ P_IDS:  ({ "corn", "maize", "stalk", "stalks", "cornstalks", "cornstalk"}),
       P_SHORT: "corn",
       PV_ITEM_LOCATION: #'pick_corn_vitem /*'*/,
       PV_SILENT_GET: 1,
       P_LONG: #'corn_long /*'*/,
       P_AMOUNT: random(4)+1,
       PV_NONE_LEFT: "There doesn't seem to be any corn left on the "
                     "stalks around you.\n",
       P_SMELL: "Makes you think of roasted sweet corn on the cob.\n"
    ]) );

   SetIntSmell("Freshly turned earth, and a slightly salty breeze from the sea.\n");

   Set(P_INT_MAP,"cornfield");

   Set(P_HELP_MSG,
      "This is an area where newbie players can improve their weaponry skills.");

   Set(P_REGION, REGION_COAST|REGION_PLAIN);
   Set(P_REGION, REGION_COAST|REGION_PLAIN|REGION_SPECIAL1);

   Set(P_NOWAY_MSG,
     "Thick cornstalks and prickly brambles block your passage in that direction.\n");

   // adds the following commands to the vitem "corn" (for getting)
   AddRoomCmd( ({"pick","gather", "pluck"}), "cmd_get_vitem");
}

// ----------------------------------------------------------------
//  Our corn vitem long, season dependant (would be nice to have
//  seasonal vitems!)
// ----------------------------------------------------------------


string corn_long()
{
   switch( ({int})NIGHTDAY->QuerySeason() )
   {

      case WINTER: return
         "The silvery, dried-out stalks stand forlornly in the fields, "
         "waiting expectantly for the season of "+SPRING_NAME+".\n";
      case SPRING: return
         "The tender young cornstalks, filled with budding young new "
         "corn, are a bright splash of green and gold against the "
         "freshly plowed brown fields.\n";
      case SUMMER: return
          "Towering emerald cornstalks hide a bounty of golden-white "
          "ears of corn, nearly ready for the collecting during "
          + AUTUMN_NAME + ".\n";
      case AUTUMN: return
          "Now that " + AUTUMN_NAME + " is upon the land, the fragrant golden "
          "corn is ready to be gathered and stored in cellars for the "
          "long months of " + WINTER_NAME + " which lie ahead.\n";
      default: return
          "Golden ears of corn, hidden away inside the green stalks.\n";
    }
    return "Golden ears of corn, hidden away inside the green stalks.\n";
}

// ------------------------------------------------------------------
//  Picking corn
//  - should catch all possible commands:
//  - pick corn, pick maize, pick ear of corn, pick corn from stalk
// ------------------------------------------------------------------

mixed pick_corn(string str)
{
  object ob;

  if(!str)
  {
    notify_fail("What would you like to do?\n");
    return 0;
  }

  str = norm_id(str);
  str = strip_article(str);

  if(!match_id(str, ({ "corn", "maize", "corn from stalk", "maize from stalk" }), ({ "ear of"}) ))
  {
    notify_fail("There don't seem to be any "+str+" here.\n");
    return 0;
  }

  msg_write(CMSG_ROOM, "You pluck an ear of corn from a nearby stalk.\n");
  msg_say(CMSG_ROOM,  NAME(TP)+" picks an ear of corn from one of the nearby stalks.\n");

  ob = clone_object("/d/silvere/obj/food/corn");
  //ob->move(this_player(), M_SILENT);

  return ob;
}

// ------------------------------------------------------------------
//  Picking corn
//  for the corn vitem
// ------------------------------------------------------------------


object pick_corn_vitem()
{
  object ob;
  string s;

  msg_write(CMSG_ROOM, "You pluck an ear of corn from a nearby stalk.\n");
  msg_say(CMSG_ROOM,  NAME(TP)+" picks an ear of corn from one of the nearby stalks.\n");

  ob = clone_object("/d/silvere/obj/food/corn");

  switch( ({int})NIGHTDAY->QuerySeason() )
  {
     case WINTER: s = "A shriveled, dried-up ear of red corn, "
                      "really only good for feeding the pigs or "
                      "setting the corn to seed.\n";
                  break;
     case SPRING: s = "A tender, pale ear of baby corn.\n";
                  break;
     case SUMMER: s = "A fragrant, golden ear of corn, nearly ripe.\n";
                  break;
     case AUTUMN: s = "A sweet, golden perfectly ripe ear of corn.\n";
                  break;
      default:    s = "An ear of corn";
  }

  ob->Set(P_LONG, s);

  return ob;
}


