// This is the office of the harbourmaster.
// created:          Sonic [26-May-1997]
// last changed:     Tune  [10-jun-1997]
//                   Sonic [05-Jul-1997] added region/coordinates
//                   Chara [09-Jul-1997] room descs (what else *grin*)
//                   Sonic [10-Jul-1997] changed the window
//                   Tune  [26-Apr-1998] added desk calendar

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <macros.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>

inherit BASEROOM;

// the file of the harbour master
#define HMASTER "/d/silvere/npc/hmaster"

mapping bad_people;

int is_solved = 0;  // for the miniquest

int do_sit(string chair)
{
  notify_fail("What exactly would you like to sit on?\n", NOTIFY_ILL_ARG);

  if(!chair) return 0;

  if(strstr(chair, "chair",0)==-1)
  {
    notify_fail(
      "Do you see a "+chair+ "here that you can sit on?\n",NOTIFY_ILL_ARG);
    return 0;
  }

  msg_write(CMSG_GENERIC,
   "You sit on the chair for a moment, contemplating what it would be "
   "like to have a normal job like the harbourmaster. But with a sigh "
   "you realize you could never give up your life of high adventure, and "
   "stand up again.\n");

  msg_say(CMSG_GENERIC, CAP(NAME(TP))+" sits in the chair for a moment, then "
   "sighs and stands up again.\n");
  return 1;
}


/*
return_hmaster()
{
  object master;

  if(!master = find_living("gregore d'angelina"))
  {
    master = clone_object(HMASTER);
  }
  if(environment(master) != this_object())
  {
    master->move(this_object(), M_GO);
  }
}
*/

int do_ring(string what)
{
   object master;
   string name;

   notify_fail("What exactly do you like to ring?\n",NOTIFY_ILL_ARG);

   if(!what) return 0;

   if(strstr(what, "bell", 0) == -1)
   {
      notify_fail(
        "Do you see a " +what+ " here that you can ring?\n",NOTIFY_ILL_ARG);
      return 0;
   }

   name = ({string})this_player()->QueryRealName();

   msg_write(CMSG_EMOTE,
      "You ring the brass bell, which tolls with a pure, ringing "
      "tone in the small office.\n\nDONG DONG!\n\n");
   msg_say(CMSG_EMOTE,
      CAP(name)+" rings the brass bell hanging on the wall.\n"
      "DONG DONG!\n");

  if(!master = find_living("gregore d'angelina"))
  {
     master = clone_object(HMASTER);
  }

  // is he already in the office?
  if(environment(master) != this_object())
     call_out( #'call_other /*'*/, 6, master, "move", this_object(), M_GO);
  else if(bad_people[name] >= 1)
  {
     call_out( #'msg_write /*'*/, 2, CMSG_EMOTE,
       "Gregore grabs ahold of your collar and heaves you out of his "
       "office with an astonishing strength for a man of his age.\n");
     call_out( #'msg_room /*'*/, 2, this_object(), CMSG_EMOTE,
        "Gregore grabs ahold of " + CAP(add_gen(name)) + " collar and "
        "heaves " + HIMHER(TP) + " out of the office with an astonishing "
        "strength for a man of his age.\n", TP);
     call_out( #'msg_room /*'*/, 3, this_object(), CMSG_SAY,
       "'I am no patient man, and I will no be telling ye again to "
       "keep yer grubby fingers from me things!'\n");
     call_out( #'call_other /*'*/, 4, TP, "move", SIL_HARBOUR("entrance"),
        M_SILENT );
     call_out( #'msg_write /*'*/, 5, CMSG_GENERIC,
        "You find yourself on the doorstep of the harbour "
        "master's office, and should perhaps wait a bit before you "
        "return.");

     bad_people[name] = -1;   // can't come back for a while!
  }
  else
  {
     call_out( #'msg_write /*'*/, 2, CMSG_EMOTE,
       "Gregore glares at you with fire in his eyes, quite plainly warning "
       "you to not meddle with his belongings.\n");
     msg_say( CMSG_EMOTE,
        "Gregore glares at " + CAP(name) + " with fire in his "
        "eyes, quite plainly as a warning to not meddle with his "
        "belongings.\n");
     bad_people[name] = bad_people[name] + 1;
  }
  return 1;
}

string read_desk_calendar()
{
   mixed *date;

   date = ({mixed *})NIGHTDAY->QueryDate();
   return
     "The calendar claims that today is the "
     + otoa(date[0], 1) + " day of " + date[1] + " "
     + date[2] + ".\n";
}

varargs void create()
{
   string desk_id;

   ::create();
   Set(P_INDOORS,1);

   Set(P_INT_SHORT, "The Office of the Harbourmaster");
   Set(P_INT_LONG,
    "The office of the harbourmaster gives you the impression of "
    "everything being in place. A large desk dominates the room, "
    "and a wooden chair rests behind it. On the wall behind the desk "
    "is a huge parchment map. Smaller maps are tucked into cubbyholes "
    "beneath it. A shiny brass bell hangs near the door, and a barometer "
    "is on the wall next to it. A figurehead is mounted above the door "
    "and smiles benignly on all in the room. Two windows as well as the "
    "open door give the harbourmaster a view of what is going on around "
    "him. A staircase leads to the second floor.\n");

   Set(P_INT_WIZMSG,
    "This is the office of the harbourmaster. Only exit to the south. "
    "If you need a cellar or an upper level, feel free.\n");

   desk_id = AddVItem(
    ([ P_IDS: "desk",
       P_ADS: ({"large", "mahogany", "wooden" }),
       P_PREPS: ({ "on" }),
       P_LONG:
    "The desk is large and solid looking. Its mahogany is well polished "
    "and shines with a warm red glow. A few papers lie on it in neat "
    "piles. An inobtrusive desk calendar sits off to one side.\n"
    ]) );

   AddVItem(
    ([ P_IDS: "calendar",
       P_ADS: ({ "desk" }),
       P_READ_MSG: #'read_desk_calendar,
       P_LONG: #'read_desk_calendar
     ]), desk_id );

   AddDetail("wooden chair",
    "This wooden chair is simple in design, but looks comfortable and "
    "well-used.\n");

   AddDetail("shiny brass bell",
    "The brass bell shines with a polished gleam. A rope hangs from the "
    "clapper. This bell is to alert the harbourmaster that he has "
    "visitors, if he is busy elsewhere.\n");

   AddDetail("rope",
    "A simple rope which allows you to ring the bell.\n");

   AddDetail("clapper",
    "A tiny teardrop-shaped piece of metal which hangs from the "
    "inside of the bell cavity.\n");

   AddVItem(
    ([ P_IDS : ({ "map", "parchment" }),
       P_ADS : ({ "large", "parchment", "detailed" }),
       P_LONG : ({
        "This is a large and detailed map of the harbour and its "
	  "surrounding area.\n" }),
       P_READ_MSG :
        "Written accross the top in the elegant, oldhand style is: 'Executed "
        "and Charted on the Royal Order of her most Excellence, the "
        "Lu'meyna of Silvere'.\n"
    ]) );

   AddVItem(
    ([ P_IDS : ({ "figurehead", "xalandre" }),
     P_ADS : ({ "carved", "mounted" }),
     P_LONG : ({
      "This is a figurehead carved in the shape of the goddess Xalandre. "
      "Legend has it that it adorned the prow of the "
      "last vessel the harbourmaster commanded. The ship was dashed "
      "against the rocks during a violent storm and most of the men were "
      "lost. Miraculously, however, the captain was lifted from the sea "
      "by a beautiful mermaid and deposited on the shore. When he awoke "
      "he was clutching this figurehead. The harbourmaster doesn't comment "
      "on whether the story is true or not, but that was his last voyage, "
      "and he has kept the figurehead near him ever since.\n" }),
     ]) );

   AddDetail(({"cubbyhole","cubbyholes", "compartments"}),
    "These are small compartments which hold various maps and charts "
    "of oceans, the stars, as well as pictures of ships.\n");

   AddDetail(({"paper", "papers"}),
    "Notes and official business relating to the running of the harbour. "
    "The harbourmaster would definitely notice anything out of place, "
    "so you do not touch them.\n");

   AddDetail("wooden floor",
    "Some sand has been tracked across the wood floor from outside.\n");

   AddDetail(({"wall", "walls"}),
    "The walls are made of wood, and seem to hold up the roof "
    "quite nicely.\n");

   AddDetail("wooden spiral staircase",
    "A wooden spiral staircase leads up to the second floor.\n");

   AddDetail("ceiling",
    "The ceiling is made of sturdy planks, and seems to be well-"
    "constructed.\n");

   AddDetail("sand",
    "A sprinkling of sand has been tracked across the floor.\n");

   AddWindow( "large window",
              "These large windows let sunlight and fresh air in, and "
              "provide a view of the surrounding area.\n",
              SIL_HARBOUR("street1"),
              ([ P_IDS : ({ "windows" }) ]) );

   SetIntNoise("You hear the splashing of waves and the cawing of "
    "seagulls.\n");

   SetIntSmell("You smell the fresh scent of the sea mixed with "
    "warm tar and dead fish.\n");

   // the barometer was invented in 1643 in Florence (almost medieval)

   AddDetail("barometer",
    "A shiny wooden plaque. Affixed vertically to the plaque is a long "
    "glass tube, filled with some silvery liquid.  Numbers line the sides "
    "of the tube. Seamen evidently use this strange device to forcast "
    "the weather.\n");

   AddReadMsg(({"barometer","tube"}),
    "The numbers are extremely difficult to read, having been scratched "
    "and faded over the years.\n");  // TODO!

   AddDetail("polished wooden plaque",
    ({
    "Just a simple polished square of wood with beveled edges. The "
    "wood gleams reddish under a thick coat of beeswax.\n",

    "A very faint engraving can be detected under the protective "
    "coating of wax:\n"
    "       ~ Captain of the Balclutha, Royal Trading Vessel ~\n"
    }) );

   AddReadMsg("plaque",
    "A very faint engraving can be detected under the protective "
    "coating of wax:\n"
    "       ~ Captain of the Balclutha, Royal Trading Vessel ~\n");


   AddDetail("glass tube",
    "The glass tube hangs on the wooden plaque from a gimbel. "
    "Seamen say that the greyish liquid in the tube rises when the "
    "weight of the air decreases, and that they can then predict the "
    "weather, but everyone knows that sailors are crazy.\n");

  AddDetail("gimbel",
   "A gimbel is a contraption for hanging things so they they always "
   "stay upright and vertical, or plumb. It consists of a special "
   "hanging ring to let the glass tube pivot or swing.\n");

   AddDetail( ({"liquid", "mercury", "silvery liquid", "grey liquid" }),
   ({
    "A dullish, leaden-grey liquid metal.\n",
    "Not exceptionally good for your health, so don't drink it...\n"
    }));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -200,0,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into a wall.\n");

   AddExit("south",SIL_HARBOUR("entrance"));
   AddExit("up", SIL_HARBOUR("harbourmaster2"));

   AddRoomCmd("ring", "do_ring");

   AddRoomCmd("sit", "do_sit");

   bad_people = ([ ]);
}
