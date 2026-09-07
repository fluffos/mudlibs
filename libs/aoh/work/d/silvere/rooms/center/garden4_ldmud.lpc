// Room layout: pomegranate Garden, NE Corner of the Palace [Outside]
// created: by  Mistral and Joan  [25-Nov-1997]
// last changed: Joan [12-Dec-1997]

#include <nightday.h>
#include "silvere.h"
#include <properties.h>
#include <moving.h>
#include <config.h>
#include <rooms.h>
#include <msgclass.h>
#include <macros.h>

// allows easy change later:
#define POMEGRANATE "/d/silvere/obj/food/pomegranate"

inherit SILBASEROOM;

int is_pomegranate;


// add property handling for pomegranates:
// (allows handling by the xtool using xcall or xprops)
int Querypomegranates() { return is_pomegranate; }
int Setpomegranates(int f) { is_pomegranate=f; return is_pomegranate; }


string cl_tree_long()
{
   string longdes;

   longdes="The tree is laden with pomegranates. ";


   if (is_pomegranate)
   {
      longdes+=
      "One or two pomegranates look ripe enough to eat. Perhaps "
      "you should pick them. ";
   }
   else
   {
      longdes+="There are no more ripe pomegranates left. ";
   }
   longdes+=
      "The mature trees promise a constant harvest of "
      "ripening pomegranates..\n";

   return longdes;
}

string QueryIntNoise()
{
   string *tmp;

   tmp = ({
   "A distant shout from the city reaches your ears.\n",
   "The clickety clack coach of wheels intrude into palace solitude.\n",
   "You hear a horse clip clop along in the distance.\n",
   "A chapel bell rings in the distance.\n",
   "You hear a frog singing nearby.\n",
   "The wind whispers echos of the sad story of Xalandre's "
   "lost love...\n",
   });

   if(({int})NIGHTDAY->IsDay())
      tmp +=
      ({
         "Jays gaily chatter and mourning doves coo while mocking "
         "birds scold you for coming to near.\n"
      });

   else
      tmp +=
      ({
         "Cicadas and crickets chirp merry night symphonies all around "
         "you.\n",
         "An owl calls out from somewhere in the trees.\n"
      });

   return random_select(tmp);
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Palace pomegranate Garden");
   Set(P_INT_LONG,
"Small clusters of sweet pomegranate trees are scattered across the "
"neatly trimmed lawn. Tiny well coiffed hedges border the west "
"and northern exits of the tiny garden. The pretty little garden "
"continues to the west. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
      " North: Palace avenue (Northeast Corner).\n"
      " West:  The pomegranate garden continues to the west.\n"
      " East:  The palace avenue.\n");

   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "To the south, the rear palace wall shelters the tiny "
   "pomegranate garden.\n");

   AddDetail( ({"grass","emerald grass","soft grass"}),"The soft "
   "grass offers a comfortable place to sit for a while and "
   "meditate.\n");

   AddDetail( ({"road","avenue","path"}),"As you look out from the "
   "tiny pomegranate garden you can see the elegant lime trees border the "
   "smooth brownstone avenue gently curving to the west and south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");


   AddDetail( ({"pomegranate tree","pomegranate trees","grove",
   "pomegranate grove"}),
   "Twenty five pomegranate trees make up this tiny grove. The pomegranate "
   "are laden with various stages of ripening pomegranates. The big "
   "leaves protect the delicate pomegranates from harsh sun and weather. "
   "Perhaps you should examine the pomegranates more closely.");

   AddDetail( ({"pomegranate","pomegranates"}),
   "You closely at the clusters of pomegranates. Some are ripe and ready "
   "to eat. Some still need to mature. They all smell delicious. "
   "Perhaps you should examine the the ripe pomegranates more closely.");

   AddDetail( ({"ripe pomegranate","ripe pomegranates"}),
   "Fat and perfect these pomegranates are begging you to eat them. Maybe "
   "you could try and pick a pomegranate from the tree.");

   AddDetail( ({"limes","lime"}),"You can't see them from here.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food beneath the shrubs.\n");

   AddDetail( ({"birds","little birdies","bird"}),
   "Little birdies scamper beneath the trees. They playfully fly "
   "around the trees and then suddenly dart through the branches "
   "in daring displays of precision flying.\n");

   AddDetail( ({"hedge","tiny hedge"}), "These are elven leaf hedges. "
   "They are meticulously coiffed. It is rumored, elven leaf hedges "
   "are the perferred homes of hedgehogs.\n");

   SetIntSmell("Fresh ripening pomegranates scent fill the air with "
               "their sweet aroma.\n");

   Set(P_TIME_MSG,
   ([
     DAY_DEFAULT_MSG:
       "Seagulls glide high overhead and mourning doves coo "
       "as they forage for food beneath the tender pomegranate trees.",
     NIGHT_DEFAULT_MSG:
       "Lights from the palace dapple though the delicate pomegranates "
       "trees making shadows dance merrily upon the soft grass."
   ]));

   AddVItem(
   ([ P_IDS : ({ "tree"}) ,
      P_ADS : ({ "pomegranate" }) ,
      P_LONG :  #'cl_tree_long /*'*/,
   ]) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot and knock yourself near "
"to simple and back again.\n");

   AddExit("west",SIL_CENTER("garden3"));
   AddExit("northeast", SIL_CENTER("outside20"));
   AddExit("east", SIL_CENTER("outside19"));
   AddExit("north",SIL_CENTER("outside21"));

   // you can pick 5 pomegranates :)
   is_pomegranate = 5;

   AddRoomCmd("pick", "cmd_pick");
   AddRoomCmd("sit", "cmd_sit");
   AddRoomCmd("meditate", "cmd_meditate");
   AddRoomCmd("search", "cmd_search");
}

// pick (a|the) (ripe) pomegranate from (a|the) (pomegranate) tree
// can be extended very easily
int cmd_pick(string str)
{
  string *arr;
  object pomegranate;

  // no string is given
  if(!str)
  {
    notify_fail("Pick a pomegranate from the tree!\n", NOTIFY_ILL_ARG);
    return 0;
  }

  // normalize the string (remove additional spaces and white spaces)
  str=norm_id(str);

  // split the string into two parts at from
  // the spaces are needed around 'from'!!
  arr=explode(str," from ");

  // no 'from' found :((
  if (sizeof(arr)!=2) {
    notify_fail("You can pick a pomegranate from the tree....\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // arr[0] contains now something like: "a ripe pomegranate"
  // arr[1] contains now something like: "the pomegranate tree"
  // now check them if both are correct:

  // first check arr[0], but first strip the article if there is one:
  if (member(({"pomegranate","ripe pomegranate"}),strip_article(arr[0]))==-1) {
    notify_fail("What do you want to pick from where?\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // now check arr[1] (and strip the article first):
  if (member(({"tree","pomegranate tree"}),strip_article(arr[1]))==-1) {
    notify_fail("From where do you want to pick "+arr[0]+"?\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // is there a pomegranate left?
  // add some more??
  if(!is_pomegranate) {
    write("You look for a ripe pomegranate, but you can't find one. "
      "There are no ripe pomegranates left. Another will ripen soon. You are "
      "sure of it.\n");
    return 1;
  }

  // heya - all is correct now :)
  // the parsing is okay, ripe pomegranates are available
  msg_room( ENV(TP), CMSG_ROOM|MMSG_SEE,
            ({
             NAME(TP)+" picks a pomegranate from the tree.\n",
             "Someone picks a pomegranate from the tree.\n"
            }), TP );

  write("You pick a pomegranate from the tree. Don't forget to take it, else "
  "the birds will eat it.\n");

  // now clone the pomegranate and move it to the room:
  pomegranate = clone_object(POMEGRANATE);

  // normally the move should be checked, something may be wrong while
  // moving (mostly weight problems)
  // but not in this case!, a room should be able to hold any item you
  // move into! (if an object is moved silently to a player - it has to be
  // checked)
  pomegranate->move(this_object(), M_SILENT);

  // one pomegranate is moved:
  is_pomegranate-- ;

  return 1;
}

int cmd_sit(string str)
{

  if(!str)
  {
     notify_fail("Sit on what?\n");
     return 0;
  }

  str = norm_id(str);

  if(str != "on grass" && str != "on ground" && str != "on soft grass")
  {
    notify_fail("Sit on what?\n");
    return 0;
  }

  write("You sit on the soft green grass.\n");
  msg_say( CMSG_SAY, NAME(TP) + " sits on soft green grass.\n", TP );

  return 1;
}

int cmd_search(string str)
{
   notify_fail("Search what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"hedge")!=-1)
   {
      write(
         "You search the hedge, but guess what happens: you don't "
         "find anything of interest. Not even a hedgehog appears. "
         "That's a perfect case of bad luck...\n");
      msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" searches the hedge. After a few moments, "
         +HESHE(TP)+" stands up and looks quite dissapointed.\n",
         ({ TP}) );
      return 1;
   }
}

int cmd_meditate(string str)
{
   notify_fail(
      "Your relax on the soft green grass, cross your legs, and began "
      "to chant quietly to yourself....ah silly stababan mem... erska "
      "sokorgarianan...allla womsesy...omstomsoby skeeseh geriam.. "
      "toboray quandirstum.....seviam...seviat...sevias...quantiumin.."
      "ammenanian...sepliast...Huh? Where did you learn that? You "
      "scared yourself and wake up! You are sweating and shivering!\n",
      NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"grass")!=-1 ||
      strstr(lower_case(str),"ground")!=-1)
   {
      write("You relax on the grass and meditate.\n");
      msg_say( CMSG_SAY,
         CAP(NAME(TP)) + " relaxes on the grass and begins to mumble.\n",
         TP);
      return 1;
   }
   notify_fail("Duh, Meditate how?\n", NOTIFY_ILL_ARG);
   return 0;
}

// restore the 5 pomegranates
void reset() {
  ::reset();
/*
  if (is_pomegranate!=5) {
    msg_room(....,"Some pomegranates ripe on the tree....\n");
  }
*/
  is_pomegranate=5;
}
