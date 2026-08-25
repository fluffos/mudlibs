
#include "path.h"
inherit "/std/outside";
object *monsters;
string *monlist = ({"hog","rat","bandicoo","hornet"});
string mon;
create()
{
   ::create();
   add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isle of Havmand: Jungle.");
    set_night_long("\nIsle of Havmand: Jungle.\n"
    "   It is difficult to make out details in the darkness under the jungle "
    "canopy.  The jungle smells are more obvious, and it seems to be "
    "noisier as well. You will need to be careful, because in the gloom "
    "everything appears the same. "
    "\n\n");
    add_item( ({"tree","trees"}),"The trees tower above you like a huge "
    "umbrella, blocking most of the light. Some of them have interesting "
    "moss and lichen growing on them, and they make travelling very "
    "difficult because they grow so close together. "
    "\n");
    add_item("leafmould","Fallen leaves have been collecting on the jungle "
    "floor for years. They deaden the sounds of footfalls, so you can "
    "hardly hear your own steps, let alone anything else walking along. "
    "\n");
    add_item("moss","Bright green moss covers the trunks of the trees and "
    "the occasional damp patch allows it to grow in mounds on the ground. "
    "\n");
    add_item("lichen","Straggling, pale green growths reminding you of "
    "an old man's beard. "
    "\n");
    add_item( ({"fungus","fungi"}),"Pale flesh colored fungi grow like "
    "plates from the trunks of the trees. "
    "\n");
   add_sound("jungle","You can hear rustling of leaves and birds singing. There "
      "is also the occasional dripping of water. \n\n");
    add_sound("water","When you listen carefully, you can hear the sound "
    "of water dripping from the leaves above onto the leafmould. "
    "\n");
    add_sound( ({"bird","birds"}),"You can hear faint twitters and chirps "
    "which sound like birds, and small rustling sounds which you really "
    "hope is birds foraging in the leafmould. "
    "\n");
    add_smell(({"air","jungle"}),"The harsh smell of decay and rotting vegetation fills "
    "the air. Occasionally you notice a faint salt breeze to remind you of "
    "the ocean not far away. "
    "\n");
    add_feel("tree","The bark is rough to the touch and vaguely slimey "
    "because its never quite dry. "
    "\n");
    add_feel("moss","It feels smooth and soft and very, very wet. "
    "\n");
    add_feel("lichen","The lichen feels rough and quite harsh, and "
    "disintegrates, leaving a pale green slime on your fingers. "
    "\n");
    add_feel( ({"fungus","fungi"}),"This feels truely repellant, like the "
    "week dead flesh of your grandmother. "
    "\n");
   monsters = allocate(random(JUNGLE_ANIMAL_MAX));
    mon = CHARS+monlist[random(sizeof(monlist))];

   this_object()->setup();
   reset();
}
void reset()
{
    int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
         if(!monsters[i])
         {
             monsters[i] = new(mon);
             monsters[i]->move(this_object());
        }
    }
}
void dest_me()
{
   int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
        if(monsters[i]) monsters[i]->dest_me();
    }
    monsters = 0;
    ::dest_me();
}


