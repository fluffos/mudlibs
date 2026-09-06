
// This is the office of the city elder
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [28-Apr-1999]  Added description, details
//                Auryn    [01-May-1999]  added npc


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

void notify_enter(mixed from, int method, mixed extra)
{
   if(present("elder",this_object()))
   {
      if (this_player())
         tell_object(this_player(), "The elder looks up at you, smiles "
            "and says: 'Hello, how can I help you?'\n");
	      tell_room(this_object(),
            "The elder greets "+capitalize(({string})this_player()->QueryName())+".\n",
            ({ this_player() }) );
   }
   ::notify_enter(from, method, extra);
}


int leave_office(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!TP)  return 0;

   if(!str) return 0;
   if(strstr(lower_case(str),"office")!=-1 ||
      strstr(lower_case(str),"room")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You leave the office.\n");
      TP->move(SIL_WEST("cityinfo1"),M_GO,"west");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Elder office");
   Set(P_INT_LONG,
"This is the office where Ciaran Hargall, one of the City Elders, works. "
"Here, you can ask for information concerning the history and sights of "
"Silvere. The office is comfortably furnished. A large desk is standing "

"near the window. Behind it is a chair where Ciraran is usually sitting. "
"Two more chairs are standing in front of the desk, so that visitors "
"may sit when talking to Ciaran. The floor is mostly covered with a woven "
"rug. A painting is hanging on the wall opposite the desk. A blue painted "
"door leads back to the street.\n");

   Set(P_INT_WIZMSG,
" WEST (or LEAVE): leave the office and return to the city.\n");

   AddVItem(
            ([ P_IDS: ({"desk"}),
            P_ADS: ({"wooden","large"}),
            P_LONG:
            "A large desk is standing next to the window. It is made of "
            "polished oak wood and looks quite old. Its surface is covered "
            "with piles of paper and writing implements, all neatly arranged "
            "and ordered.\n"
             ]) );

   AddVItem(
            ([ P_IDS: ({"wood","oak"}),
            P_ADS: ({"polished","old"}),
            P_LONG: "The desk is a rather massive looking piece of furniture. "
            "The wood has darkened with age and is polished to a silken "
            "sheen.\n",
            P_SMELL: "The wood smells very faintly of the beeswax that has "
            "been used to polish it.\n"
             ]) );

   AddDetail(({"piles","paper","papers"}),"Neatly stacked papers cover "
          "most of the desk's surface. It seems that the City Elder is a "
          "rather busy man - and also a very tidy one.\n");

   AddDetail(({"implements","writing implements","quills","bottle","ink"}),
             "Some quills and a bottle of ink are placed on the desk.\n");

   AddDetail("window","The window looks out onto Park Lane. It is hung with "
          "pretty curtains. A flower pot is standing on the window sill.\n");

   AddDetail( ({"lane","park lane","street"}),"Through the window, you can "
            "see the street that brought you here.\n");

   AddVItem(
            ([ P_IDS:({"curtain","curtains"}),
            P_ADS: ({"pretty"}),
            P_LONG:
            "The curtains are bright yellow and decorated with a floral "
            "design in blue.\n"
             ]) );

   AddDetail(({"design", "blossoms","floral design"}),
             "Blue blossoms have been embroidered on the curtains. They "
             "look very pretty.\n");

   AddDetail(({"sill","window sill"}),"A potted flower is standing on the "
              "window sill.\n");

   AddDetail(({"pot","flower pot"}),"A simple earthenware flowerpot "
             "holding a miniature rosebush.\n");

   AddVItem(
            ([ P_IDS: ({"rose","flower","plant","bush","rosebush","roses"}),
            P_ADS: ({"potted","miniature","small","little","tiny"}),
            P_LONG:
            "The little bush is in full bloom. Tiny white roses blossom "
            "between dark green leaves, filling the air with a very faint "
            "fragrance.\n",
            P_SMELL: "A faint, sweet fragrance emanates from the roses.\n"
             ]) );

   AddDetail("leaves","The rosebush has dark green leaves.\n");


   AddDetail( ({"chair","chairs"}),"A wooden chair is standing behind "
           "the desk. Two more are placed in front of it. Feel free to "
           "sit down if there is still an empty one.\n");

   /* Add a function here to actually make sitting down possible... */

   AddVItem(
            ([ P_IDS: ({"rug","carpet"}),
            P_ADS: ({"woven","woolen"}),
            P_LONG: "A bright blue carpet woven from wool covers most "
            "of the floor.\n"
             ]) );


   AddDetail(({"painting","picture"}),"The painting shows a view over the "
       "harbour of Silvere as seen from the harbour tower.\n");

   AddDetail("harbour","You can't see the harbour from here, it's only a "
             "picture!\n");

   AddDetail("door","The door is painted blue and leads back outside.\n");

Set(P_INT_SMELL,"You notice a faint trace of rose scent in the air. As you "
       "look around, you see a small potted rosebush on the window sill.\n");


   AddRoomCmd("leave",#'leave_office /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -170,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("west", SIL_WEST("cityinfo1"));
AddItem("/d/silvere/npc/elder", REFRESH_HOME);
}
