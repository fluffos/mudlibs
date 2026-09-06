// "..and in the space between the heavens and the corner of some
//  foreign field..."  (Pink Floyd)

inherit "/std/room";

int is_falling;   // are we still falling?

// ---------------------------------------------------------------------
// I couldn't resist, this is from Zork
// ---------------------------------------------------------------------

int down_txt()
{
  write("\nDown seems more likely.\n\n");
  return 1;
}

// ---------------------------------------------------------------------
// Create
// ---------------------------------------------------------------------

varargs void create()
{
  ::create();
  SetIntShort("Falling...");
  SetIntLong("\nYou are falling...\n\n");  // chats do the real describing

  AddExit("north", #'down_txt /*'*/);
  AddExit("south", #'down_txt /*'*/);
  AddExit("east", #'down_txt /*'*/);
  AddExit("west", #'down_txt /*'*/);
  AddExit("northwest", #'down_txt /*'*/);
  AddExit("northeast", #'down_txt /*'*/);
  AddExit("southwest", #'down_txt /*'*/);
  AddExit("southeast", #'down_txt /*'*/);
  AddExit("up", #'down_txt /*'*/);

  is_falling = 1;
}

// ----------------------------------------------------------------------
// Changes the long depending on where the player "is" (virtually)
// ----------------------------------------------------------------------

varargs string QueryIntLong()
{
  if(is_falling)
    return "\nYou are falling...\n\n";
  return
    "You lie on the deck of a ship.\n";
}

// --------------------------------------------------------------------
// I think it's kinda silly to see "There are no visible exits" while
// you're falling through the air
// --------------------------------------------------------------------

varargs string MakeExitString(int brief, string *dirs, string kind)
{
  return "";
}

// --------------------------------------------------------------------
// This run-on of call outs does the intro chats to the player
//---------------------------------------------------------------------

int step1()
{
  write(
   "You step north and realize why this is called One Step Beyond. "
   "You've just taken one step beyond the edge of the clouds....\n");
  call_out("continue2", 5);
  return 1;
}

void continue2()
{
  if(this_player())
  {
    write("\n\n\n"
     "    ....and are hanging in thin air....\n");
    call_out("continue3", 5);
  }
}

void continue3()
{
  if(this_player())
  {
    write("\n\n\n\n"
    "       ...and start to plummet towards the ground at an alarming "
    "rate...\n");
    call_out("continue4", 5);
  }
}

void continue4()
{
  if(this_player())
  {
    write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
      "                     * * W H O M P ! ! * *\n");
    call_out("continue5", 2);
  }
}

void continue5()
{
  if(this_player())
  {
    is_falling = 0;
    write("\n\n\n"
     "You look down at the crumpled remains of your corpse lying on "
     "the deck of a ship. A man in a black robe holding a scythe, a deeply "
     "cowled hood pulled far over his face, stands next to you, shaking "
     "his head slowly.\n");
    call_out("continue6", 6);
  }
}

void continue6()
{
  if(this_player())
  {
    write("\n'A LITTLE TOO QUICK, DON'T YOU THINK?'\n");
    call_out("continue7", 4);
  }
}

void continue7()
{
  if(this_player())
  {
    write(
     "\nHe turns and grins at you - that is, if a skull can be said "
     "to grin.\n");
    call_out("continue8", 5);
  }
}

void continue8()
{
  if(this_player())
  {
    write(
     "\n'YOU'D BETTER HAVE ANOTHER GO AT IT, WE DON'T WANT TO GET A "
     "BAD REPUTATION FOR OFFING NEWBIES.'\n");
    call_out("continue9", 6);
  }
}

void continue9()
{
  if(this_player())
  {
    write(
     "\nThe hooded man pulls a sand timer out of his voluminous black "
     "robes and slowly turns it over....\n");
    call_out("continue10", 4);
  }
}

void continue10()
{
  if(this_player())
  {
    write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //this_player()->move(
    call_out("continue11", 1);
  }
}


void continue11()
{
  if(this_player())
  {
    write(
 "You come to consciousness, your head pounding with a splitting headache. "
 "You pick yourself up off the deck of the ship, trying to right yourself "
 "as the ship sways on the swells of the bay. The ship appears to be "
 "approaching one of the docks in the harbour of a large city.\n");
  }
}
