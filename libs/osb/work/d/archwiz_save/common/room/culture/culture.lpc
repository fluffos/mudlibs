/*
** The Nightfall Culture Center
** Author: Thragor@Nightfall, 03apr97
** Update:
*/

#include "path.h"
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <config.h>

#define STAFF OBJ("culture/cc_staff")
#define MACHINE OBJ("culture/cc_machine")
#define RING OBJ("culture/cc_ring")
#define KEY OBJ("culture/cc_key")

#define P_VIEW "CulterCenterView" // view direction in culture center
#define P_STAFF "CultureStaff"
#define P_MACHINE "CultureMachine"
#define P_RING "CultureRing"
#define P_KEY "CultureKey"

#define TP this_player()
#define ME this_object()
#define SF(x) #'x //'

inherit "/std/room";

private void eval_exits(object pl, string ex_music, string ex_joke,
			string ex_movie, string ex_exit)
{
  string view,front,right,behind,left;
  if (!pl)
    view = "east";
  else
    view = pl->Query(P_VIEW)||"east";
  front  = "in front of you";
  left   = "to the left";
  behind = "behind you";
  right  = "to the right";
  switch(view)
    {
    case "north":
      ex_music = front;
      ex_joke  = right;
      ex_movie = behind;
      ex_exit  = left;
      break;
    case "south":
      ex_music = behind;
      ex_joke  = left;
      ex_movie = front;
      ex_exit  = right;
      break;
    case "west":
      ex_music = right;
      ex_joke  = behind;
      ex_movie = left;
      ex_exit  = front;
      break;
    default:
      ex_music = left;
      ex_joke  = front;
      ex_movie = right;
      ex_exit  = behind;
      break;
    }
}

public string QueryIntLong()
{
  string res,view,ex_movie,ex_joke,ex_music,ex_exit;
  res = 
    "You've entered a room of ancient glory. Statues surround the whole room "
    "- several feet high - and stare at you through non-existing eyes.\n"
    "There are exits in four directions. ";
  eval_exits(TP,&ex_music,&ex_joke,&ex_movie,&ex_exit);
  res += (capitalize(ex_music)+" is an exit guarded by two columns which are "
	  "decorated with a treble clef on each of them. "+
	  capitalize(ex_joke)+" the columns guarding the exit carry one "
	  "big smiling mouth with marble teeth. "+
	  capitalize(ex_movie)+" the columns next to the exit are surrounded "
	  "by a strange black material, which looks like a flat ribbon but "
	  "it has many rectangular holes at one side. "+
	  "Finally there's an exit "+ex_exit+" which seems to lead back to "
	  "the street.\n");
  res += ("The ceiling is completely made of glass which builds a huge dome "
	  "above the Culture Center.\n");
  return res;
}

private string detail_staff(string what)
{
  if (Query(P_STAFF))
    return 0;
  return
    "This staff is needed to create the basics of a mud. It's the staff "
    "of a sourcerer.\n";
}

private string detail_machine(string what)
{
  if (Query(P_MACHINE))
    return 0;
  return
    "The cube looks somehow familiar to you. But it doesn't fit into "
    "this world. Ah yes. Now you got it. It's a computer! The first "
    "machine Nightfall ran on.\n";
}

private string detail_ring(string what)
{
  if (Query(P_RING))
    return 0;
  return
    "Three words are engraved into the ring: Friendship, Unity and "
    "Co-operation. These three things are essential to build and "
    "run a Multi User Dungeon.\n";
}

private string read_ring(string what)
{
  if (Query(P_RING))
    return 0;
  return
    "Friendship, Unity, Co-operation\n";
}

private string detail_key(string what)
{
  if (Query(P_KEY))
    return 0;
  return
    "The key is made of gold. It's the key to a room to place "
    "the computer for the MUD and a key to open your mind for "
    "new ideas.\n";
}

private string detail_statue(string what)
{
  string res;
  if (!what) return "";
  res = "The statue is about ten feet high and made of pure marble.\n";
  if (strstr(what,"deepthought")!=-1)
    {
      if (!Query(P_STAFF))
	res+=("It shows a human being with the Staff of Source in his "
	      "right hand. This staff is needed to create the basics of "
	      "a mud.\n");
      else
	res+=("It shows a human being. Somehow you have the feeling that "
	      "there's missing something in his right hand.\n");
      if (find_player("deepthought"))
	res+=("The statue's eyes glow in a soft blue light.\n");
      else
	res+=("The statue's eyes look blind somehow.\n");
    }
  else if (strstr(what,"michael")!=-1)
    {
      if (!Query(P_MACHINE))
	res+=("The statue of Michael is a human being. His hands "
	      "hold a strange cube. There are some slots in the cube "
	      "and on the other side you see a net made of metal where "
	      "you can see the darkness inside this cube.\n");
      else
	res+=("The statue of Michael is a human being. You have the "
	      "feeling that something huge is missing between his hands.\n");
      if (find_player("michael"))
	res+=("The statue's eyes glow in a soft red light.\n");
      else
	res+=("The statue's eyes look blind somehow.\n");
    }
  else if (strstr(what,"zeus")!=-1)
    {
      if (!Query(P_RING))
	res+=("The shape of the Statue of Zeus looks quite strange. "
	      "Somehow you have the feeling it changes every time you "
	      "blink. In his right hand Zeus has a small ring which "
	      "symbolizes unity and co-operation.\n");
      else
	res+=("The shape of the Statue of Zeus looks quite strange. "
	      "Somehow you have the feeling it changes every time you "
	      "blink. You think there's something missing in his right "
	      "hand.\n");
      if (find_player("zeus"))
	res+=("The statue's eyes glow in a soft yellow light.\n");
      else
	res+=("The statue's eyes look blind somehow.\n");
    }
  else if (strstr(what,"sam")!=-1)
    {
      if (!Query(P_KEY))
	res+=("The statue of Sam somehow looks as if it is not here. "
	      "You think you can see the wall behind it. It's as if "
	      "you're looking at the wall through fog or foam of a "
	      "wild sea. In his left hand Sam carries a key.\n");
      else
	res+=("The statue of Sam somehow looks as if it is not here. "
	      "You think you can see the wall behind it. It's as if "
	      "you're looking at the wall through fog or foam of a "
	      "wild sea. His left hand looks as if it held something "
	      "in the past.\n");
      if (find_player("sam"))
	res+=("The statue's eyes glow in a soft green light.\n");
      else
	res+=("The statue's eyes look blind somehow.\n");
    }
  return res;
}

public string detail_holes(string what)
{
  if (!TP || TP->QueryRace()!="gnome")
    return "You have no idea what these holes are for.\n";
  return
    "Ah! Of course. Suddenly you active your gnomish mind and "
    "you see the sense of the holes. A toothed wheel can be "
    "used to transport this ribbon.\n";
}

public int cmd_cut(string str)
{
  if (   !TP
      || strstr(lower_case(str||""),"finger")==-1
     )
    return notify_fail("Cut what?\n",NOTIFY_NOT_OBJ),0;
  write("You cut your fingers at the sharp marble.\n");
  if (TP->QueryInvis())
    say("You hear someone screaming as if this someone got hurt.\n");
  else
    show(({(capitalize(TP->QueryName())+" cuts "+
	    TP->QueryPossessive()+" fingers at a sharp piece of marble.\n"),
	    ("You hear someone screaming as if this someone got hurt.\n")
	 })
	);
  TP->ReduceHP(5);
  return 1;
}

private int get_staff()
{
  object ob;
  if (!TP || Query(P_STAFF))
    return 0;
  ob = clone_object(STAFF);
  Set(P_STAFF,ob);
  if (ob->move(TP,M_SILENT)!=ME_OK)
    {
      ob->move(ME,M_SILENT);
      write("You take the staff but you find no place in your backpack.\n"
	    "You drop the staff to search for a place where to put it.\n");
      if (TP->QueryInvis())
	show("Suddenly a strange staff appears on the floor.\n");
      else
	show(capitalize(TP->QueryName())+" takes a staff from a statue "
	     "and drops it to the floor.\n");
    }
  else
    {
      write("You take the staff from Deepthought's statue.\n");
      if (TP->QueryInvis())
	show("Blinking you suddenly recognize that Deepthought's statue "
	     "changed somehow.\n");
      else
	show(capitalize(TP->QueryName())+" takes a staff from a statue.\n");
    }
  return 1;
}

private int get_machine()
{
  object ob;
  if (!TP || Query(P_MACHINE))
    return 0;
  ob = clone_object(MACHINE);
  Set(P_MACHINE,ob);
  if (ob->move(TP,M_SILENT)!=ME_OK)
    {
      ob->move(ME,M_SILENT);
      write("You take the cube but you find no place in your backpack.\n"
	    "You drop the cube to search for a place where to put it.\n");
      if (TP->QueryInvis())
	show("Suddenly a strange cube appears on the floor.\n");
      else
	show(capitalize(TP->QueryName())+" takes a cube from a statue "
	     "and drops it to the floor.\n");
    }
  else
    {
      write("You take the cube from Michael's statue.\n");
      if (TP->QueryInvis())
	show("Blinking you suddenly recognize that Michael's statue "
	     "changed somehow.\n");
      else
	show(capitalize(TP->QueryName())+" takes a cube from a statue.\n");
    }
  return 1;
}

private int get_ring()
{
  object ob;
  if (!TP || Query(P_RING))
    return 0;
  ob = clone_object(RING);
  Set(P_RING,ob);
  if (ob->move(TP,M_SILENT)!=ME_OK)
    {
      ob->move(ME,M_SILENT);
      write("You take the ring but you find no place in your backpack.\n"
	    "You drop the ring to search for a place where to put it.\n");
      if (TP->QueryInvis())
	show("Suddenly a strange ring appears on the floor.\n");
      else
	show(capitalize(TP->QueryName())+" takes a ring from a statue "
	     "and drops it to the floor.\n");
    }
  else
    {
      write("You take the ring from Zeus' statue.\n");
      if (TP->QueryInvis())
	show("Blinking you suddenly recognize that Zeus' statue "
	     "changed somehow.\n");
      else
	show(capitalize(TP->QueryName())+" takes a ring from a statue.\n");
    }
  return 1;
}

private int get_key()
{
  object ob;
  if (!TP || Query(P_KEY))
    return 0;
  ob = clone_object(KEY);
  Set(P_KEY,ob);
  if (ob->move(TP,M_SILENT)!=ME_OK)
    {
      ob->move(ME,M_SILENT);
      write("You take the key but you find no place in your backpack.\n"
	    "You drop the key to search for a place where to put it.\n");
      if (TP->QueryInvis())
	show("Suddenly a strange key appears on the floor.\n");
      else
	show(capitalize(TP->QueryName())+" takes a key from a statue "
	     "and drops it to the floor.\n");
    }
  else
    {
      write("You take the key from Sam's statue.\n");
      if (TP->QueryInvis())
	show("Blinking you suddenly recognize that Sam's statue "
	     "changed somehow.\n");
      else
	show(capitalize(TP->QueryName())+" takes a key from a statue.\n");
    }
  return 1;
}

public int cmd_get_take(string str)
{
  if (!TP || !str)
    return 0;
  str = lower_case(str);
  if (!sizeof(regexp(({str}),("(\\<deepthought\\>)|(\\<michael\\>)|(\\<sam\\>)|"
			  "(\\<zeus\\>)|(\\<statue\\>)"))))
    return 0;
  if (sizeof(regexp(({str}),"\\<staff\\>")))
    return get_staff();
  else if (sizeof(regexp(({str}),
			 "(\\<cube\\>)|(\\<computer\\>)|(\\<machine\\>)"
                        )
                 )
          )
    return get_machine();
  else if (sizeof(regexp(({str}),"\\<ring\\>")))
    return get_ring();
  else if (sizeof(regexp(({str}),"\\<key\\>")))
    return get_key();
  return 0;
}

public void reset()
{
  object ob,env;
  string *props;
  int i;
  
  (::reset());
  if (Query(P_STAFF) || Query(P_MACHINE) || Query(P_RING) || Query(P_KEY))
    tell_room(ME,("A strange magic runs through the room. After one second "
		  "it is gone, but you have the feeling something has "
		  "changed.\n"));
  props = ({P_STAFF,P_MACHINE,P_RING,P_KEY});
  for(i=sizeof(props);i--;)
    if (   (ob = Query(props[i]))
	&& (env = environment(ob))
	&& !interactive(env)
       )
      {
        ob->remove();
        if (ob) destruct(ob);
      }
    else
      Set(props[i],0);
}

public void notify_enter(mixed from,int method,mixed extra)
{
  object pl;
  (::notify_enter(from,method,extra));
  pl = previous_object();
  if (!pl || !living(pl))
    return;
  if (objectp(from))
    from = object_name(from);
  if (!from || getuid(load_object(from))!="archwiz")
    pl->Set(P_VIEW,"east");
  else
    switch(explode(from,"/")[<1])
      {
      case "musicroom":
	pl->Set(P_VIEW,"south");
	break;
      case "jokeroom":
	pl->Set(P_VIEW,"west");
	break;
      case "movieroom":
	pl->Set(P_VIEW,"north");
	break;
      default:
	pl->Set(P_VIEW,"east");
      }
  
}

public void notify_leave(mixed to, int method, mixed extra)
{
  (::notify_leave(to,method,extra));
  if (previous_object()) previous_object()->Set(P_VIEW,0);
}

public void create()
{
  (::create());
  SetIntShort("Culture Center");
  // SetIntLong() done by QueryIntLong()
  Set(P_CANSEE,1);
  SetIndoors(0); // The sun shines in from above (or the moon ;-) )
  AddDetail(({"room","room of ancient glory","center","culture center"}),
	    "The room is completely made of marble except the ceiling and "
	    "some decor. The floor is made of huge plates of marble in "
	    "different colours.\n");
  AddDetail("statues",
	    "They represent the creators of this Mud. There's one statue of "
	    "Deepthought, one statue of Michael, one of Zeus and "
	    "one statue of Sam.\n");
  AddDetail(({"deepthought","statue of deepthought",
	      "michael","statue of michael",
	      "zeus","statue of zeus",
	      "sam","statue of sam"}),
	    SF(detail_statue));
  AddDetail(({"staff","staff of source","staff of sourcerer",
	      "staff of deepthought"}),
	    SF(detail_staff) );
  AddDetail(({"cube","strange cube","computer","machine"}),
	    SF(detail_machine));
  AddDetail(({"ring","small ring","ring of zeus"}),
	    SF(detail_ring));
  AddReadMsg(({"ring","small ring","ring of zeus","words","three words",
	       "words on ring"}),
	     SF(read_ring));
  AddDetail(({"key","golden key","key of sam"}),
	    SF(detail_key));
  AddDetail("exits",
	    "The exits lead into four directions.\n");
  AddDetail(({"treble clef","clef"}),
	    "Bards know this sign quite well. They paint it at least once "
	    "a day on a piece of paper.\n");
  AddDetail(({"column","columns"}),
	    "The columns are made of marble.\n");
  AddDetail(({"smiling mouth","mouth","marble teeth","teeth"}),
	    "The mouth grins at you with its marble teeth. If you would see "
	    "this mouth in a face, you would be sure, that this someone is "
	    "laughing at (or about?) you.\n");
  AddDetail(({"material","strange black material","black material",
	      "strange material","ribbon","flat ribbon"}),
	    "Well, it's marble, too. But the first time you looked at it "
	    "you've been quite unsure about this. The marble is very thin "
	    "and you could cut your fingers at the edge of the marble.\n");
  AddDetail(({"holes","rectangular holes"}),
	    SF(detail_holes));
  AddDetail(({"marble"}),
	    "The whole room is made of marble.\n");
  AddDetail("street",
	    "You better go there, as you can see only a small part of the "
	    "street from here.\n");
  AddDetail(({"ceiling","dome"}),
	    "You can see the sky through the ceiling.\n");
  AddDetail("glass",
	    "This glass must have cost a lot. Perhaps it got payed by some "
	    "rich players in Nightfall.\n");
  AddDetail("floor",
	    "The floor is made of huge plates of marble in different colours.\n"
	    "While the rest of the room is made of white marble, the floor "
	    "has a frame of black marble and inside this frame are "
	    "four squares made of blue marble, yellow marble, red marble "
	    "and green marble.\n");
  AddDetail(({"green marble","yellow marble","red marble","blue marble"}),
	    "A part of the floor is made of this marble.\n");
  AddDetail("white marble",
	    "Nearly the whole room is made of white marble.\n");
  AddDetail(({"black marble","frame"}),
	    "The frame on the ground is made of black marble.\n");
  AddExit("north","./musicroom");
  AddExit("east","./jokeroom");
  AddExit("south","./movieroom");
  AddExit("west",CITY("pubstreet"));
  AddRoomCmd("cut",SF(cmd_cut));
  AddRoomCmd(({"get","take"}),SF(cmd_get_take));
  AddItem("/std/board",
	  REFRESH_HOME,
	  ([
	    P_SHORT:"The Party Board",
	    P_LONG:("Here you can leave notes about next planned parties or "
		    "write your suggestions and ideas about further "
		    "Nightfall parties.\n\Try \"help board\"!\n"),
	    "Groups":({"rec.party"})
	  ]) );
}
