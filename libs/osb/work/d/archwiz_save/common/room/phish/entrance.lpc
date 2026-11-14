/*  -*- LPC -*-  */
#include <moving.h>
#include "path.h"
inherit "/std/room";
#define QC "/obj/quest_control"
#define LOG PHISH("questlog")

int clean;

create()
{
  ::create();
  SetIntLight(10);
  SetIntShort("entrance to Phish's castle");
  AddDetail( ({"entrance","room","hall","entrance hall"}),
"This is the entrance hall to a very untidy castle. It must have been long "
"ago since the last janitor cleaned up this mess.\n");
  AddDetail( ({"castle","phish's castle"}),
"It is the most untidy castle of whole Nightfall. Phish seeks for a nice "
"person to clean it for him.\n");
  AddDetail( ({"phish"}),
	    "Phish is not here, but he is the owner of this castle.\n");
  AddDetail( ({"mess","chaos","rubbish","garbage","dust","remains"}),
	    "You never thought a wizard could have such an untidy castle.\n");
  AddDetail( ({"floor","ground"}),
"You can't see that here... it is covered with tons of rubbish.\n");
  AddDetail( ({"ceiling"}),"Probably the only clean thing in this castle.\n");
  AddDetail( ({"wall","walls"}),"They are dusty.\n");
  AddDetail( ({"stuff"}),"If only you could find it in this mess...\n");
  AddExit("south","./hilltop");
  AddExit("north","./hall");
  AddExit("west","./westroom");
  reset();
}

reset()
{
  ::reset();
  clean=0;
  SetIntLong(
"This is entrance of phish's castle. There is an undescribable mess "
"everywhere. Phish is a new wizard and he doesn't manage the creation "
"of objects very good. Remains of his unsuccessful attempts cover the "
"floor. There could be some interesting stuff within all this mess, "
"but you would have to clean the room first before you could find "
"anything.\n");
}

init()
{
  ::init();
  add_action("clean","clean");
}

clean(string str)
{
  object obj1,obj2;

  if (!this_player()) return 0;
  if(!present("pbroom",this_player())){
    write("You need something to clean the room with.\n");
    return 1;
  }
  if (clean == 1)
    {
      write ("The room is already clean an shiny.\n");
      return 1;
    }
  
  else{
    clean = 1;
    write("You clean the room... its a hard work...\n");
    write("As you work you find some objects...\n");
    obj1 = clone_object(PHISH("spear"));
    obj1 ->move(this_object(),M_SILENT);
    obj2 = clone_object(PHISH("emerald"));
    obj2 ->move(this_object(),M_SILENT);
    show(this_player()->QueryName()+" cleans the floor.\n",this_player());
    SetIntLong( "This is the entrance of the castle\n" +
	       "It is clean and shiny thanks to " +
	       this_player()->QueryName() +
	       " who took\nthe time to clean it up.\n"
	       );
    if(QC->QueryQuestSolved("clean_phishs_castle",this_player()) == 0){
      QC->SetPlayerQuest("clean_phishs_castle",this_player());
      shout(this_player()->QueryName()+" has cleaned Phish's Castle!\n");
      write("You feel more experienced now.\n");
      write_file(LOG,this_player()->QueryName()+" Phish's Castle:"+ctime(time())+"\n");
    }
    return 1;
  }
}
