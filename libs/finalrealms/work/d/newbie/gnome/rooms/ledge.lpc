inherit "/std/outside";
#include "path.h"

int found;
object staff;
object chainmail;
void setup ()   {
    set_short("Macedonia:  Ledge");
    set_light(40);
    set_long("Macedonia:  Ledge\n\n"
      "   You are standing on a narrow ledge half way up the cliff. "
      "The view from here is everything that you anticipated, and a whole lot "
      "more.... \nSlightly to your left a huge waterfall cascades over the "
      "top of the cliff and splashes awesomely almost within reach of your "
      "outstretched hands. The river heads northward, neatly "
      "dissecting the landscape with the trees of the Whispering Woods "
      "on the eastern side, and a mountain range on the far side. "
      "\nAt your feet you notice the skeletal remains of some poor "
      "creature who was unable to find a way off this ledge, and you become "
      "aware once more of how very small and narrow this ledge really is. "
      "\n\n");
    add_item("waterfall","Coming from the top of the cliff, "
      "is a huge waterfall.  As the water falls to the "
      "ground, its course is somewhat changed by coming "
      "in contact with the cliff.  When it reaches the "
      "river, there is a fine mist of water sprayed "
      "over the area.\n");
    add_item(({"skeleton","skeletal remains","remains"}), "A pile "
      "of bones is about all that is left of this poor adventurer who never "
      "managed to find his way home. You hope you are more fortunate.\n");
    add_item(({"river","gnude river","gnude"}),"This is the gentle "
      "flowing Gnude River.  Although it is so gentle, it is "
      "too deep to wade in and to wide to swim across\n");
    add_item(({"mountain","range","mountain range"}),"Far in the "     
      "distance you can see the Mithril Mountains.  The "
      "base of the mountains is pretty clear but the peaks "
      "are somewhat covered by the clouds.\n");
    add_item(({"forest","woods"}),"From here, you can see the edge of "
      "the forest.  Due to its density, you can not see far "
      "into it.\n");
    add_item("cliff","This is a very steep cliff which looks next to "
      "impossible for a young adventurer like yourself to "
      "climb.  Also, about half way up this cliff, there is "
      "a small ledge.  You think to yourself that if you could "
      "get up there, the scenery must be beautiful.\n");
    add_item("ledge","This is a small ledge about half way up the "
      "cliff.\n");
    add_property("no_undead", 1);
    add_exit("down",VALLEY+"gnome16","path");
}

void init()
{
    add_action("do_search","search");
    ::init();
}

int do_search(string str)
{
    switch(found)
    {
    case 0:
	{
	    write("You search the skeletal remains and discover a mildewy "
	      "old staff.\n");
	    say(this_player()->query_cap_name()+" searches the skeleton.\n",this_player());
	    found = 1;
	    staff = new("baseobs/weapons/quarterstaff");
	    staff->set_short("Mildewed Staff");
	    staff->set_long("This staff is covered in pale green mildew, "
	      "but looks as though it could be a fairly useful and solid "
	      "weapon once the mildew has been cleaned off. You start "
	      "to rub it clean with your hands.\n");
	    staff->move(this_object());
   return 1;
	}
    case 1:
	found = 2;
	chainmail = new("/baseobs/armours/elfinchain");
	chainmail->set_short("Tarnished chainmail");
	chainmail->set_long("The chainmail seems sound despite it lying here "
	  "apparently for a long time. Looks like it'll clean up "
	  "quite nicely in time.\n");
         chainmail->set_value(5000);
	chainmail->move(TO);
	say("There's a clinking sound from the mildewed remains.\n",({ 0 }));
    write("You hear a clink as you search round.\n");
   return 1;
    default:
   return ::do_search(str);
    }
}
