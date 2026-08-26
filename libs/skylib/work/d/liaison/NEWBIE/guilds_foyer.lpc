/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: guilds_foyer.c,v 1.3 2000/06/23 19:25:50 pinkfish Exp $
 *
 */
/* Added no teleport property- 26-06-98- Shalla */

#include "path.h"
inherit "/std/outsides/woodland";
inherit PATH+"common";

void setup() {
  set_zone( "Newbie" );
  set_short( "Garden of Guilds" );
  set_light( 100 );
  add_property("no teleport", 1);

  set_day_long( "This is a pleasant garden with trees, shrubs and flowers.  "
                "There are six gazebos in the garden each with a wrought "
                "iron gate with a coat of arms on it.  Each "
                "gazebo is dedicated to one of the Discworld guilds, which "
                "are "+ GUILDS +".  "
                "To look at the gates themselves - use "
                "'look wizard' or 'look witch' or to enter one of the "
                "gazebos, use 'wizard', 'witch' or whichever is appropriate.\n"
                "There is also a sign attached to a post in the centre of the "
                "garden.\n" );
  
  set_night_long("This is an octagonal garden with a fence around it.  "
                 "Someone has placed braziers around the garden to provide "
                 "light.  There "
                 "are six gazebos in the garden each with a wrought iron gate "
                 "with a coat of arms on it.  Each "
                 "gazebo is dedicated to one of the Discworld guilds, which "
                 "are "+ GUILDS +".  "
                 "To look at the gates themselves - use "
                 "'look wizard' or 'look witch' or to enter one of the "
                 "gazebos, use 'wizard', 'witch' or whichever is "
                 "appropriate.\n"
                 "There is also a sign attached to a post in the centre of "
                 "the garden.\n" );

  add_item("gazebo", "There are a number of gazebos here each dedicated to "
           "a different guild.");
  
  add_sign("This is a simple white sign attached to a post.\n",
       " _______________________________________________________________ \n"
       "//                                                              \\ \n"
       "|| Each player will usually join a guild so that they can learn  |\n"
       "|| skills and commands and so advance their abilities.  Being in |\n"
       "|| a guild also gives character to your character.               |\n"
       "|| To find out more about the different guilds take each of the  |\n"
       "|| guild gates from this garden.  When you are in Ankh-Morpork   |\n"
       "|| you will find that each guild has a headquarters where you    |\n"
       "|| may join.                                                     |\n"
       "|| Take care with your choice of guild since you will not be able|\n"
       "|| to change it.                                                 |\n"
       "\\\\______________________________________________________________/ \n"
           , 0, "sign" );

/* Make it so you cannot godmother out of here */
  add_property("no godmother", 1);

  add_exit( "foyer", PATH + "foyer", "gate" );

  add_night_item("brazier", "Basically this is a torch on a pole.\n");
  
  add_room_chats(({"An elderly man dressed in a blue robe and wearing "
                     "a large pointy hat enters from the wizards "
                     "gazebo and leaves south.\n",
                     "An elderly man dressed in a blue robe and wearing "
                     "a large pointy hat enters from the south "
                     "and leaves for the wizards gazebo.\n",
                     "A small woman dressed in a black cloak and wearing "
                     "a large pointy hat enters from the witches "
                     "gazebo and leaves south.\n",
                     "A small woman dressed in a black cloak and wearing "
                     "a large pointy hat enters from the south "
                     "and leaves for the witches gazebo.\n",
                     "A burly man dressed head to toe in armour and "
                     "carrying a large sword enters from the warriors "
                     "gazebo and leaves south.\n",
                     "A burly man dressed head to toe in armour and "
                     "carrying a large sword enters from the north "
                     "and leaves for the warriors gazebo.\n",
                     "A saintly looking woman walks in from the north, "
                     "smiles benevolently at you, and leaves for the "
                     "priests gazebo.\n",
                     "A saintly looking woman enters from the priests gazebo, "
                     "smiles benevolently at you, and leaves  "
                     "south.\n",
                     "A shadowy figure enters from the assassins "
                     "gazebo and leaves for the foyer.\n",
                     "A shadowy figure enters from the foyer "
                     "and leaves for the assassins gazebo.\n",
                     "A weaselly, furtive man sneaks in from the foyer "
                     "and leaves for the thieves gazebo.\n",
                     "A weaselly, furtive man sneaks in from the thieves "
                     "gazebo and leaves for the foyer.\n"}));

} /* setup() */

// Dont ever let it get too dark here.
int query_light() {
  int light;

  light = ::query_light();
  if(light < 40)
    light = 40;

  return light;
}
