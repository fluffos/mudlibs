inherit ROOM;

int pushed; // the push flag, = 1 if the boulder has been moved.

void create() {
  seteuid(getuid());
  set("light", 1);
  set( "short", "A small crevice." );
  set( "long", @ENDLONG
You find yourself in a small crevice  you notice the wall to the north, it appears 
very soft.
ENDLONG
  );
  set("item_desc", ([
    "wall" : "You have a feeling that there could be something behind this wall, why 
not try to [scrape wall] to scape some of the dirt away?.\n",
    ]) );
  ::create();


}

void init() {
  add_action("scrape wall", "scrape wall");
}

int scrape wall(!scrape) {
  if (!scrape wall) {
    write("Scrape what?\n");
    return 1; }
  }
  
  if (scraped == 1 ||scrape != "rock" && scrape != "stone") {
    write("Push what?\n");
    return 1;
  }
  
  write("You scrape the wall away and find a ring!\n");
  say(TPN + " seems to have found something in the wall!\n");


  
  set("item_desc/boulder", "This wall has been scraped away.\n");
  
  set( "long", @ENDLONG
You find yourself in a small crevice  you notice the wall to the north, it appears 
to have been searched.
ENDLONG
  );
  
  add_object("shield", ARMOR(newbie_shield));
  
  scraped = 1;
  return 1;
}
