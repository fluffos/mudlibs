/* Gardens of the Clerists Tower
 * Angel, October 1993.
 */

#define PATH "room/city/cleric"
inherit "inherit/room2";

reset(arg) {
  if(arg) return;

  set_weather(1, 4, 0);
  set_short("the gardens of the high clerists tower");
  set_long(
     "All about the fragrance of flowers in full bloom delight your   \n"+
     "senses. A pagoda of simple pine stands above you, prodiving a   \n"+
     "a little shelter from the sun during the day, but allowing for  \n"+
     "those who study the stars to watch them during the night. Vines \n"+
     "of ivy cling to it tightly giving the garden an old quaint look.\n");

  set_items(({
     "flowers", "Many types of flowers are grown here by the clerics",
     "pagoda",  "A frame work of wood stands about you in a simple design",

     "wood#pine#frame#frame work",
     "The pagoda appears to be made from pine, and has ivy growing all "+
     "over it",

     "ivy#vines#ivy vines",
     "Ivy grows all over the pagoda erected around the garden"
  }));

  set_night_items(({
     "moon", "The moon is full tonight",
     "stars", "The stars twinkle as you watch them"
  }));

  set_day_items(({
     "sun", "Do you want to go blind?",
     "clouds", "One of them looks like a big elephant",
     "rain", "It looks very wet"
  }));

  set_exits(({
     PATH +"/garden6", "north",
     PATH +"/garden8", "west"
  }));

  set_smell("You smell the wonderful fragrance of beautiful flowers");
}

init() {
  ::init();
  add_action("pick", "pick");
}

pick(string str) {
  if(str == "flowers" || str == "flower") {
    write("You shouldn't do that. The clerical gardiners might object.\n");
    return 1;
  }
return;
}
     
