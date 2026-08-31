#include <std.h>
#include <tirun.h>

inherit ROOM;

int goEnter(string str);
object rk;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 3);
    set_property("no castle", 1);
    set("short", "In a shack");
    set_long("The room is a very small area in which a strange object %^GREEN%^%^BOLD%^glows%^RESET%^ "
             "and fills the room with a eerie light. There is a chair right next to the rift which"
             " is occupied by a mystic man. The rift has a variety of colours swirling around and is"
             " very attractive.");

    set_listen("default", "A strange buzzing sound fills the air");

    set_exits( 
              (["out" : ROOMS"beach5"]) );

        set_heart_beat(1);
}

int reset()
{
 ::reset();

 if (!present("rift keeper")) rk=new(MOB"riftkeeper")->move(this_object());
if (!present("rift")) new(OBJ"rift")->move(this_object());
}

int init()
{
 ::init();

 add_action("goEnter", "enter");

}


int goEnter(string str)
{

 if (!str || str=="" || str!="rift")
   {
     message("info", "Enter what?", this_player());
     return 1;
   }


if (!present("rift keeper"))
  {
    message("info", "Hah! no way your entering an unstable rift and drifting off into nothingness!", this_player());
    return 1;
  }
if (this_player()->query_stats("strength") < 18)
  {
   message("info","You are not strong enough to enter the rift.", this_player());
   return 1;
  }
if (this_player()->query_stats("charisma") < 14)
  {
   message("info","You are not good looking enough to enter the rift.", this_player());    
   return 1;
  }
if (this_player()->query_stats("dexterity") < 18)
  {
   message("info","You are not dexterous enough to enter the rift.", this_player());    
   return 1;
  }
if (this_player()->query_stats("constitution") < 18)
  {
   message("info","You are not healthy enough to enter the rift.", this_player());    
   return 1;
  }
if (this_player()->query_stats("wisdom") < 18)
  {
   message("info","You are not wise enough to enter the rift.", this_player());    
   return 1;
  }
if (this_player()->query_stats("intelligence") < 18)
  {
   message("info","You are not smart enough to enter the rift.", this_player());    
   return 1;
  }

 message("info", "You step into the portal and begin to spin through a world of colours,\nand land in a world totally different.", this_player());
 present("rift keeper", this_object())->force_me("say I am far too old and tired to hold this rift open, I am sorry.");
 return 1;

}
void heart_beat()
{
if (random(100) > 90)
    {
             message("room", "The rift flickers and expands quickly before returning to normal.", this_object());  
      }
}
