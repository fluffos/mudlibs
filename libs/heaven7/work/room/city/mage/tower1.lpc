#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "file", "room/city/mage/guild", 
     "direction", "west door",
     "long",
          "A dark door bearing spidery runes on a golden plaque:\n"+
          "\tThe Apprentice's Study.\n",
     "key id", "city key",
  }));

  if(arg) return;
  set_short("the tower of high magic");
  set_long(
     "A long spiral staircase of black iron extends downward  \n"+
     "into the darkness below. A pair of torches burn brightly\n"+
     "either side of the west door, sending shadows dancing   \n"+
     "over the walls in a ghostly display of macarbe theatrics.\n");
  set_items(({
     "stairs#staircase",
          "A stairwell of cold black iron, descending downward",
     "torch#torches",
          "A pair of torches burning brightly",
     "shadow#shadows",
          "The seem to have a life of their own...",
     "walls#wall",
          "The walls are of a cold grey stone, possibly made by magical means",
     "stone",
          "No dwarf chiselled this stone",
  }));
  set_listen("You can hear the torch flames flutter.\n");
  set_smell("You can smell the burning of pitch on the torches.\n");
  set_exits(({
     "room/city/mage/tower2", "down",
  }));
  set_weather(2,1,0);    
  enable_commands();
}

void heart_beat() {
  string *messages;
  messages = ({
     "The torches flicker\n",
     "The torches splutter.\n",
     "The torches cast dancing shadows across the walls.\n",
     "The torches flutter.\n",
     "The torch light dances around the room.\n",
  });
  if(!random(10))
    tell_room(this_object(), messages[random(sizeof(messages))]);
}
