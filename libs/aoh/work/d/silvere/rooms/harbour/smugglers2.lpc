// Way to the smugglers hideout.
// created:    Taurec [17-Dec-1997]


// TODO:  Without light, no following of footprints
//        NIGHTDAY
//        msg_room or show_room ?!


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
inherit BASEROOM;


//*********************
// Function Prototypes
//*********************

int is_open; // is hidden entrance to smugglers cave open or not
int follow_prints(string str);
int pull_rope(string str);
void close_opening();
int enter_cave();
string check_opening();
string check_flotsam();
string check_rope();
string check_sheet();
string check_prints();

//*******************
// PROPERTY HANDLING
//*******************

int QueryIsOpen() { return is_open; }
int SetIsOpen(int i) {


  if (i) {
    call_out("close_opening",120);
    HideExit("enter",HIDE_NOT);
  }
  is_open = i; return i;
}

//**********
//  CREATE
//**********

varargs void create()
{
   ::create();
   is_open = 0;
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"In the dunes");
   Set(P_INT_LONG,
     "You are still somewhere in the dunes. To your west, the sea of "
     "Shamyra extends into infinity. All sorts of sand-grasses, "
     "scattered thorny sandberry bushes and flotsam, partially already "
     "sunken in the sand, are all around. This would really be a neat "
     "place to take out a large towel, spread it on the sand and lie "
     "down to relax. ");
   SetExtraEntry ("hidden entrance", P_INT_LONG,
     "But still, these footprints awaken your curiousity. Something "
     "about them is really odd.\n");

   AddVItem(([
    P_IDS: ({"dunes","sandhills","hills","dune","hill","sandhill"}),
    P_ADS: ({"sandy","steep","slippery"}),
    P_LONG:
    "Large sandhills with steep walls. You wonder how many billions "
    "of billions of sandcorns are needed to form such a thing.\n"]));

   AddVItem(([
    P_IDS: ({"bush","bushes"}),
    P_ADS: ({"sandberry","scattered","thorny"}),
    P_LONG:
    "Thorny bushes with dark green foliage. Clusters of small orange "
    "berries grow on them. A very delicate jam is made out of them, "
    "but you could also eat them in raw form.\n"]));

   AddVItem(([
    P_IDS: ({"sea","shamyra","ocean"}),
    P_ADS: ({"blue","big"}),
    P_LONG:
   "The Sea of Shamyra - what a wonderful view. You envy the sailormen "
   "who travel it and discover strange new continents, small cosy palm "
   "islands, and wild native tribes...\n"]));

   AddVItem(([
    P_IDS: ({"shoe","shoes"}),
    P_ADS: ({"old"}),
    P_LONG:
     "Is there still a ripped apart foot inside?!? Ah, no, that "
     "was only a bleached piece of wood sticking in the shoe.\n"]));

   AddVItem(([
    P_IDS: ({"fishnets","planks"}),
    P_ADS: ({"old","rotten","torn"}),
    P_LONG:
     "This stuff is pretty useless unless you don't want "
     "to make a fire with it.\n"]));

   AddVItem(([
    P_IDS: ({"footprints","prints"}),
    P_ADS: ({"meandering","sandy"}),
    P_LONG: #'check_prints /*'*/]));

   AddVItem(([
    P_IDS: ({"opening","entrance"}),
    P_ADS: ({"dark","hidden"}),
    P_LONG: #'check_opening /*'*/]));

   AddVItem(([
    P_IDS: ({"flotsam"}),
    P_ADS: ({"scattered"}),
    P_LONG: #'check_flotsam /*'*/]));

   AddVItem(([
    P_IDS: ({"rope"}),
    P_ADS: ({"sunken","old"}),
    P_LONG: #'check_rope /*'*/]));

   AddVItem(([
    P_IDS: ({"sheet"}),
    P_ADS: ({"rusty","metal"}),
    P_LONG: #'check_sheet /*'*/]));

   Set(P_INT_WIZMSG,
     "Follow the footsteps to smugglers nest.\n"
     "Add Coordinates!\n");

   Set(P_INT_NOISE,
     "You hear the eternal roar of the waves that meet the beach "
     "to your west.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -260,20,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
       "You try to walk up one of the sandy hills, "
       "but it's too steep and you slide back again.\n");
   AddRoomCmd("follow","follow_prints");
   AddRoomCmd("pull","pull_rope");
   AddExit("follow",#'follow_prints /*'*/);
   AddExit("enter",#'enter_cave /*'*/);
   HideExit("enter",HIDE_ALWAYS);
}

//****************************
// FUNCTIONS FOR VITEMS LONG
//****************************

string check_prints(){
  string str;
  str = "These footprints are leading down from a large sandhill and "+
        "meander exactly to this place. ";
  if (is_open) str += "From here, they lead on towards that dark "+
                      "opening in one of the dunes.\n";
  else str += "But strangely, the prints are suddenly ending in front "+
              "of a dune. It seems as if the sand simply swallowed the "+
              "rest of the footprints.\n";
  return str;
}

string check_opening(){
  if (is_open) return
    "You wonder where this creepy dark opening leads to - Perhaps "+
    "you should just enter it and investigate it from inside.\n";
  else return 0;
}

string check_rope(){
  if (is_open) return
    "The rope is tied to a large metal sheet that was used to hide the "+
    "entrance to that strange cave in the dune. Someone removed the sheet "+
    "recently.\n";
  else return
    "That rope is covered with sand, it's almost completely sunken in it. "+
    "But the thing could still be useful. So why not just pull it out "+
    "of the sand?\n";
}

string check_sheet(){
  if (is_open) return
    "It's a large rusty metal sheet, used to close the opening that leads "+
    "into the dune here. It was pulled away and the opening was uncovered.\n";
  else return 0;
}

string check_flotsam(){
  if (is_open) return
    "Old rotten planks, torn fishnets, shoes and other unidentifiable "+
    "stuff. Nothing useful, except you like to ignite a little fire.\n";
  else return
    "Old rotten planks, torn fishnets, shoes and other unidentifiable "
    "stuff. The only thing that you could still use is that rope "
    "over there, half sunken in the sand.\n";
}

//***********
// ROOM CMDS
//***********

int follow_prints(string str)
{
   string *exp;
   notify_fail("What do you want to follow?\n",NOTIFY_NOT_VALID);
   if (!str) return 0;
   str=norm_id(str);
   str=strip_article(str);
   exp=explode(str," ");
   if (sizeof(exp)!=1) return 0;
   if ((strstr(lower_case(exp[0]),"step")==-1) &&
       (strstr(lower_case(exp[0]),"print")==-1)) return 0;
   write("You start to follow the footprints. Having passed several "
         "dunes, sand-valleys and seagull-nests, you finally come "
         "to a row of bushes. The footprints end here.\n");
   show_room(this_object(),
         CAP(NAME(TP))+" starts to stomp along the line of footprints, "
         "watching them attentively. Finally "+HESHE(TP)+" disappears "
         "behind a dune.\n",
         "You hear someone stomping away through the sand.\n",({TP}));
   show_room(SIL_HARBOUR("smugglers1"),"Suddenly, "+CAP(NAME(TP))+
         " comes along over a dune. "+CAP(HESHE(TP))+" almost crashes "
         "into the bushes and stops moving.\n",
         "You hear someone (or something?!?) stomping through the "
         "sand moving towards you. Suddenly there's silence.\n");
   TP->move(SIL_HARBOUR("smugglers1"),M_GO);
   return 1;
}

int pull_rope(string str)
{
  string *arr;
  notify_fail("What do you want to pull out of where?\n",NOTIFY_ILL_ARG);
  if (!str) return 0;
  if (!TP) return 0;
  arr = norm_id(str,1);
  if (is_open)
  {
    write("Someone already pulled the rope. The dark opening "
          "is uncovered, so why don't you just enter?\n");
    return 1;
  }

// trying to do it perfect... all 4 words must be in str, and they
// must at least be in the right following, but don't care for typo
// signs in between.

  if ((strstr(lower_case(str),"rope")!=-1)&&
      (strstr(lower_case(str),"out")!=-1)&&
      (strstr(lower_case(str),"of")!=-1)&&
      (strstr(lower_case(str),"sand")!=-1)&&
      (member(arr,"rope")<member(arr,"out"))&&
      (member(arr,"out")<member(arr,"of"))&&
      (member(arr,"of")<member(arr,"sand")))
  {
    write("You pull hard, but nothing moves. Something heavy must be "
          "connected to the other end of the rope. You concentrate to "
          "focus all your power in your arms and pull again. This "
          "time you succeed! But, oops, what's that? Seems as if you "
          "removed a huge metal sheet from a dark opening. That's "
          "why this task was so hard.\n");
    show_room(TO,
           CAP(NAME(TP))+" tries to pull that rope out of the sand. Sweat "
          "drips down from "+HISHER(TP)+" face, but finally it's done. "
          "Errmmm... huh? It seems as if "+CAP(NAME(TP))+" did not only pull "
          "that rope, "+HESHE(TP)+" has also freed the way to a hidden "
          "opening in the dune!\n","You hear someone groaning under "
          "a tremendous strain. Suddenly, there's the noise of something "
          "heavy sliding through the sand.\n",({TP}));
    is_open = 1;
    HideExit("enter",HIDE_NOT);
    SetExtraEntry("hidden entrance", P_INT_LONG,
      "But what really awakens your curiosity is the strange dark opening "
      "in one of the dunes here.\n");
    call_out("close_opening",120);
    return 1;
  }
  return 0;
}

//**************
// HIDDEN EXIT
//**************

void close_opening()
{
  show_room(this_object(),
        "Suddenly a hand comes out from the darkness of the opening "
        "and pulls the metal sheet quickly back to its original position. "
        "A flush of sand rushes down from the dune and "
        "covers the sheet completely. There's no sign of the hidden "
        "entrance now anymore.\n");
  SetExtraEntry ("hidden entrance", P_INT_LONG,
     "But still, these footprints awaken your curiousity. Something "
     "about them is really odd.\n");
  show_room(SIL_HARBOUR("smugglers3"),"You hear someone cursing: "
     "\"WHO THE HELL HAS FORGOTTEN TO CLOSE THE ENTRANCE AGAIN?!?\""
     "Suddenly an old ugly smuggler scurries to the opening without "
     "noticing you and closes the metal sheet.\n");
  is_open = 0;
  HideExit("enter",HIDE_ALWAYS);
}

int enter_cave(){
  notify_fail("Enter what?\n");
  if (!TP) return 0;
  if (!is_open) return 0;
  else {
    write("You enter the strange opening. Darkness surrounds you, as you "
          "walk through a tight tunnel into the dune. Finally you arrive "
          "in a small subterran chamber.\n\n");
    show_room(TO,CAP(NAME(TP))+" enters the opening. "+CAP(HESHE(TP))+
	  " The darkness swallows him instantly.\n",
          "You hear someone stomping away through the sand. ",({TP}));
    show_room(SIL_HARBOUR("smugglers3"),"You hear muffled noises of "
          "steps from inside the entrance-tunnel. The sound comes "
          "closer and out of a sudden, "+CAP(NAME(TP))+" appears, "
          "looking around warily.\n",
          "You hear muffled noises of steps from inside the "
          "entrance-tunnel. Someone (or something?!?) enters the chamber.\n");
    TP->move(SIL_HARBOUR("smugglers3"),M_GO);
    return 1;
  }
  return 0;
}
