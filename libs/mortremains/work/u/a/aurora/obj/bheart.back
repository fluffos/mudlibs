
//commbadge.c
//as modified from glowstone.c
//created by Shadrach
//(c) 1994 R. Voss
//all rights reserved
//this code may not be distributed in public or private
//without the express permission of it's creator.
//permission was granted by Shadrach/R. Voss to Aurora/A. Cail
//to use commbadge.c code for a similar object of similar
//intent.

// Debugging by beans@circle_of_ourobouros

//for a full listing of credits see /wizards/shadrach/misc/glowstone.c

#include <std.h>

inherit OBJECT;
inherit "/cmds/creator/_xwho.c";
 
      mixed *query_auto_load(){
          return({"/wizards/aurora/obj/bheart.c", ({}) });
      }
 
void create() {
  ::create();
      seteuid(getuid());
      set_name("bheart");
      set_id( ({ "bheart", "heart", "bleeding heart", "bleedingheart", }) );
      set_short("A Bleeding Heart");
      set_long("Aww...how sad.  This bleeding heart\n"
      "reminds you of some depressing, lonely times.\n"
      "\nType 'help bheart' for a list of commands.\n"
      "\n");
      set_weight(10);
      set_value(0);

}


     int arrival() {
          int x;
          object group;

     for(x=0;x<sizeof(users());x++){
          group = users()[x];
       if(present("bheart", group) && (string)this_player()->query_cap_name() != "Someone"){
       tell_player(group, "~#~ "+(string)this_player()->query_cap_name()+" has Entered Circle ~#~\n");

     }
     }
}
      int quit() {
       int x;
       object group;
       
       for(x=0;x<sizeof(users());x++){
          group = users()[x];
      
      if(present("bheart", group)){
       tell_player(group, "~#~ "+(string)this_player()->query_cap_name()+" has Left Circle. ~#~\n");
     }
     }

      return 0;
     }

    void init() {

      add_action("quit","quit");
      add_action("cmd_who","scan");
      add_action("drop","drop");
      add_action("stonecry","bh");
      add_action("stonecryemote","bhe");
      add_action("updatestone","udbheart");
      add_action("whostone","whoheart");
      add_action("stonehelp","help");
      add_action("dest","dest");
      arrival();

}

      int drop(string str) {
      if(str == "bheart"){
      write("That is your bleeding heart, why would you want to drop it?");
          return 1;
          }
      if(str == "bleeding heart"){
      write("I'm sorry, but Aurora wouldn't like that!");
          write("You cannot drop it.");
          return 1; 
          }
      }

      int dest(string str) {
      if(str == "bheart"){
          write("You cannot do that!");
          return 1;
          }
      if(str == "heart") {
          write("You cannot do that!");
          return 1;
          }
      if(str == "bleeding heart"){
          write("You cannot do that!");
          return 1;
          }
      return 0;
      }

     int stonehelp(string str) {
      if(str == "bheart"){
          write(
"                         BLEEDING HEART HELP\n"+
"|====================|====================|====================|\n"+
"|COMMAND             |ARGUMENT            |DESCRIPTION         |\n"+
"|====================|====================|====================|\n"+
"|help                |bheart               |This help screen.   |\n"+
"|bh                  |<message>           |Private chat channel|\n"+
"|                    |                    |for the lonesome.   |\n"+
"|bhe                 |<emote message>     |Emote over the heart|\n"+
"|                    |                    |channel.            |\n"+
"|udbheart             |                    |Updates your heart  |\n"+
"|                    |                    |to the most recent  |\n"+
"|                    |                    |version.            |\n"+
"|whobheart            |                    |Shows all who have  |\n"+
"|                    |                    |a bleeding heart        |\n"+
"|scan                |                    |An advanced form of |\n"+
"|                    |                    |the basic who       |\n"+
"|                    |                    |command.            |\n"+
"|==============================================================|\n"+
"Bleeding Heart Version 1.0                                   1122.95\n"+
"\n");
     return 1;
     return 0;
      }
}
      int whostone() {
          int x;
          object group;

      write("The following people have a Bleeding Heart:");
      for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("bheart", group)){
      write(" "+group->query_true_name());
      }
    }
      return 1;
   }

     int stonecry(string str) {

int y, x;
object group;

  if(!str){
    if(!present("nobheart", this_player())){
      write("You are now blocking Bleeding Heart messages.\n");
      set_id( ({"heart", "bheart", "bleeding heart", "bleedingheart", "nocomm"}) );
    }
    else{
      set_id( ({"heart", "bheart", "bleeding heart", "bleedingheart"}) );
      write("You are no longer blocking Bleeding Heart Messages.\n");
    }
  }
  else {
    if(present("nobheart", this_player())){
      write("You are no longer blocking Bleeding Heart messages.\n");
      y=1;   
    }
    set_id( ({"heart", "bheart", "bleeding heart", "bleedingheart"}) );
    for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("bheart", group)){
        if(!present("nobheart", group)){
       tell_player(group, "~#~ "+(string)this_player()->query_cap_name()+" sends: "+str+" ~#~\n");
        }
      }
    }
    return 1;
  }
}
int stonecryemote(string str) {
  int x;
  object group;
    for(x=0;x<sizeof(users());x++){
    group = users()[x];
    if(present("bheart", group) && (!present("nobheart", group))){
       tell_player(group, "~#~ "+(string)this_player()->query_cap_name()+" "+str+" ~#~\n");
    }
  }
  return 1;
}

      int updatebheart() {

       write("A new Bleeding Heart is presented to you.");
      new("/wizards/aurora/obj/bheart.c")->move(this_player());
      this_object()->remove();
      return 1;
   }
 
 
