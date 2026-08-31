inherit "room/room"; 

#include "/players/tamina/defs.h"   

object ob;
int ru_found;

void reset(int flag) 
{
  if (flag == 0)  
  {
    ru_found = 0; 
    set_light(1);
    short_desc = "In a room in the top of the NW Tower";
    long_desc = 
    "As you reach the top of the stairs, you see a room bathed completely\n"+
    "in blood-red light.  The reason for this is most probably the red-\n"+
    "stained windows lining the walls.  This room seems to be rather\n"+
    "comfortable, compared with the rest of the deserted castle.  There\n"+
    "is a bed in the far corner, a mahogony desk against one wall, and a\n"+
    "swinging wicker-chair, hanging from the ceiling.  Shelves full of\n"+ 
    "intricate little things are attached to the walls.  There is also a\n"+
    "large, wooden box lying in the corner, and a chest beside the box.\n";

    dest_dir = ({ 
     CROOMS + "nw_tower2", "down",
             });

    items = ({
    "windows",
  "The windows are so thickly stained that you cannot see through them",
    "bed",
  "A well-made, straw bed with a feather pillow at one end",
    "box",
  "A large box, full of cluttered bits and pieces",
    "chest",
  "This wooden chest is open, and shows a lot of useless odds and ends",
    "shelves",
  "These shelves are so cluttered that you can not see anything "+ 
  "without a further inspection...",
    "chair",
  "@@chk_chair@@",
      });

    if (!ob) 
    {    
      ob = CLO (CMONS + "morgan2");
      MO(ob, TO);
    }
  }
}

void init() 
{
  ::init();
  AA("do_search","search");
}

int do_search (string arg) 
{
  object ruby, neck;

  if (ob && living(ob)) 
  {
    write("Morgan growls: Do not even think of going through my possessions...\n");
    return 1;
  }
  switch (arg)  
  {
    case "shelves":
    case "shelf":
      if (ru_found)
      {
        write("You find nothing of interest in the shelves.\n");
	  say(TPN+" looks through the shelves.\n");
	return 1;
      }
      write("You manage to find a marvellous ruby !!\n");
      say(TPN+" gets a ruby from the shelves!\n");

      ruby = clone_object("players/tamina/castle/obj/quest/ruby");
      if (TR (ruby, TP))
        write("You leave it on the shelf, since you can't\n"+ 
              "carry that much weight.\n");
      else 
       ru_found = 1;
      return 1;

   case "bed":
      write("You lift up the sheets, but find nothing.\n");
      say(TPN+" searches through the bed-sheets, but finds nothing\n");
       
      return 1;

   case "box":
      write("You dip into the box full of junk, and rather surprisingly,\n"+
            "finds nothing of interest.\n");
      say(TPN+" looks through the junk in the box.\n");

       return 1;

   case "chest":
        write("You find nothing of interest in the chest.\n");
	  say(TPN+" looks in the chest.\n");
	return 1;

    default:            /* the arg should not be a search object */
       NFAIL("That is not here to search.\n");
       return 0;  
    } 
    return 1;
}

string chk_chair()
{
  if (!ob)
  {
    return 
 "The hanging wicker chair swings around aimlessly";
  }
  return
  "The hanging wicker chair swings around revealing a strange looking\n"+
  "woman, in a dark, mysterious robe";
}
