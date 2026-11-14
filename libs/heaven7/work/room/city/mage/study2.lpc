#include <mudlib.h>
#define NAME (string)this_player()->query_name()

inherit ROOM;

void reset(status arg) {
  if(!present("tenser")) {
    move_object(clone_object("room/city/monst/tenser"),this_object());
  }

  reset_doors(arg);
  load_door(({
     "file", "room/city/mage/tower3", 
     "direction", "east door",
     "long",
          "A dark door or deep red wood.\n"+
     "key id", "silver key",
     "lock id", "silver lock",
     "lock description", "A shiny silver lock that glows softly\n",
     "closed", "locked",
     "trap on",
     "trap description", 
          "The trap appears to be some kind of shocking grasp spell.\n",
     "trap damage", (20 + random(50)),
     "trap message", "Your hand receives a shocking grasp that nearly "+
     "burning it off, \nsending you into deadly convulsions!\n",
     "trap message room",
     "@@query_name:$this_player()$@@ goes into convulsions as "+
     "@@query_pronoun:$this_player()$@@ touches the door.\n",
  }));


  if(arg) return;
  set_short("Tenser's personal study");
  set_long(
     "Around the room, large trophies of various animal and monsters \n"+
     "heads adorn the walls. Were it not well known that you were in \n"+
     "a mages' study, one would believe it to be a game hunters lodge.\n"+
     "A large, high backed chair stands behind a small desk littered  \n"+
     "with papers, watching the open window.\n");


  set_weather(2,1,0);

  set_items(({
     "window",
          "The view from the window is spectacular. From here you can    \n"+
          "easily see the entire city below, especially a beautiful view \n"+
          "of the gardens.",
     "desk",
          "A small desk littered with papers",
     "papers#paper",
          "Several papers of new magical formula scrawled in Tenser's own \n"+
          "hand lie scattered across the desk",
     "chair",
          "A large leather chair, with a high back. It looks very comfortable",
     "trophies#animals#monsters#heads#wall",
          "The walls are adorned with various animal and monsters heads. \n"+
          "It appears that Tenser is quite a hunter",
  }));
}
