// Room layout: Fig Garden, Northwest Corner of the Palace [Outside]
// created: by  Mistral and Joan  [25-Nov-1997]
// changed: Sonic [25-Nov-1997]
// special thanks to Magictcs for guidance and corrections


#include <nightday.h>
#include "silvere.h"
#include <properties.h>
#include <moving.h>
#include <config.h>
#include <rooms.h>
#include <msgclass.h>
#include <macros.h>

// allows easy change later:
#define FIG "/d/silvere/obj/food/fig"

inherit SILBASEROOM;

int is_fig;


// add property handling for figs:
// (allows handling by the xtool using xcall or xprops)
int QueryFigs() { return is_fig; }
int SetFigs(int f) { is_fig=f; return is_fig; }


string cl_tree_long()
{
   string longdes;

   longdes="The tree is laden with figs. ";


   if (is_fig)
   {
      longdes+=
      "One or two figs look ripe enough to eat. Perhaps "
      "you should pick them. ";
   }
   else
   {
      longdes+="There are no more ripe figs left. ";
   }
   longdes+=
      "The mature trees promise a constant harvest of "
      "ripening figs..\n";

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

   if(({int})NIGHTDAY->IsDay() )
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
   Set(P_INT_SHORT,"Palace Fig Garden");
   Set(P_INT_LONG,
"Small clusters of big leaved fig trees are scattered across "
"neatly trimmed lawn. Tiny well coiffed hedges border the west "
"and north exits of the tiny garden. The pretty little garden "
"continues to the east. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
      " North: Palace avenue (Northwest Corner).\n"
      " East:  The fig garden continues to the east.\n"
      " West:  The palace avenue.\n");

   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "To the south, the rear palace wall borders the tiny "
   "fig garden. It continues to border the garden to the east.\n");

   AddDetail( ({"grass","emerald grass","soft grass"}),"The soft "
   "grass offers a comfortable place to sit for a while and "
   "meditate.\n");

   AddDetail( ({"road","avenue","path"}),"As you look out from the "
   "tiny fig garden you can see the elegant lime trees border the "
   "smooth brownstone avenue gently curving to the east, west "
   "and south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");


   AddDetail( ({"fig tree","fig trees","grove","fig grove"}),
   "Twenty five fig trees make up this tiny grove. The fig "
   "are laden with various stages of ripening figs. The big "
   "leaves protect the delicate figs from harsh sun and weather."
   "Perhaps you should examine the figs more closely.");

   AddDetail( ({"fig","figs"}),
   "You closely at the clusters of figs. Some are ripe and ready "
   "to eat. Some still need to mature. They all smell delicious. "
   "Perhaps you should examine the the ripe figs more closely.");

   AddDetail( ({"ripe fig","ripe figs"}),
   "Fat and perfect these figs are begging you to eat them. Maybe "
   "you could try and pick a fig from the tree.");

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

   SetIntSmell("Fresh ripening figs scent fill the air with "
               "their sweet aroma.\n");

   Set(P_TIME_MSG,
   ([
     DAY_DEFAULT_MSG:
       "Seagulls glide high overhead and mourning doves coo "
       "as they forage for food beneath the tender fig trees.",
     NIGHT_DEFAULT_MSG:
       "Lights from the palace dapple though the delicate figs "
       "trees making shadows dance merrily upon the soft grass."
   ]));

   AddVItem(
   ([ P_IDS : ({ "tree"}) ,
      P_ADS : ({ "fig" }) ,
      P_LONG :  #'cl_tree_long /*'*/,
   ]) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot and knock yourself near "
"to simple and back again.\n");

   AddExit("northwest", SIL_CENTER("outside30"));
   AddExit("east",SIL_CENTER("garden2"));
   AddExit("west", SIL_CENTER("outside31"));
   AddExit("north", SIL_CENTER("outside29"));

   // you can pick 5 figs :)
   is_fig = 5;

   AddRoomCmd("pick", "cmd_pick");
   AddRoomCmd("sit", "cmd_sit");
   AddRoomCmd("meditate", "cmd_meditate");
   AddRoomCmd("search", "cmd_search");
}

// pick (a|the) (ripe) fig from (a|the) (fig) tree
// can be extended very easily
int cmd_pick(string str)
{
  string *arr;
  object fig;

  // no string is given
  if(!str)
  {
    notify_fail("Pick a fig from the tree!\n", NOTIFY_ILL_ARG);
    return 0;
  }

  // normalize the string (remove additional spaces and white spaces)
  str=norm_id(str);

  // split the string into two parts at from
  // the spaces are needed around 'from'!!
  arr=explode(str," from ");

  // no 'from' found :((
  if (sizeof(arr)!=2) {
    notify_fail("You can pick a fig from the tree....\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // arr[0] contains now something like: "a ripe fig"
  // arr[1] contains now something like: "the fig tree"
  // now check them if both are correct:

  // first check arr[0], but first strip the article if there is one:
  if (member(({"fig","ripe fig"}),strip_article(arr[0]))==-1) {
    notify_fail("What do you want to pick from where?\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // now check arr[1] (and strip the article first):
  if (member(({"tree","fig tree"}),strip_article(arr[1]))==-1) {
    notify_fail("From where do you want to pick "+arr[0]+"?\n",
        NOTIFY_NOT_VALID);
    return 0;
  }

  // is there a fig left?
  // add some more??
  if(!is_fig) {
    write("You look for a ripe fig, but you can't find one. "
      "There are no ripe figs left. Another will ripen soon. You are "
      "sure of it.\n");
    return 1;
  }

  // heya - all is correct now :)
  // the parsing is okay, ripe figs are available
  msg_room( ENV(TP), CMSG_ROOM|MMSG_SEE,
            ({
             NAME(TP)+" picks a fig from the tree.\n",
             "Someone picks a fig from the tree.\n"
            }), TP );

  write("You pick a fig from the tree. Don't forget to take it, else "
  "the birds will eat it.\n");

  // now clone the fig and move it to the room:
  fig = clone_object(FIG);

  // normally the move should be checked, something may be wrong while
  // moving (mostly weight problems)
  // but not in this case!, a room should be able to hold any item you
  // move into! (if an object is moved silently to a player - it has to be
  // checked)
  fig->move(this_object(), M_SILENT);

  // one fig is moved:
  is_fig-- ;

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

// restore the 5 figs
void reset() {
  ::reset();
/*
  if (is_fig!=5) {
    msg_room(....,"Some figs ripe on the tree....\n");
  }
*/
  is_fig=5;
}

