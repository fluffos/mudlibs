inherit "std/room";

void create() {
   ::create();
   set_property("light", 1);
   set_short( "Shadowwolf's grave");
   set_long(
      "You are in the northern reaches of the Praxis cemetary.  Old, "
      "long-abandoned graves spread out around you.  An eerie silence "
      "has settled over the area, as if it's awaiting something horrible. "
      "You see a grave here, with an antique headstone.");
   set_items(
      (["cemetary" : "All about you stretch the silent graves.  "
	  "You feel like you are being watched.",
	"grave" : "The grave is old, and grass-covered.",
	"writing" : "The engraving says: Here lies the mysterious "
	  "Shadowwolf.  He was decisively executed by mudders when "
	  "it was discovered he hung out with Knights who say NI.",
	"headstone" : "The headstone is of grey marble.  You might "
	  "be able to read the writing on it."]) );
   set_exits( 
	     (["southeast" : "/domains/Praxis/cemetary/grave_yard6",
	       "south" : "/domains/Praxis/cemetary/grave_yard2"]) );
}
void reset() {
  ::reset();
    if (!present("ghost"))
      new("/domains/Praxis/cemetary/mon/ghost8")->move(this_object());
}

void init() {
  ::init();
    add_action("read","read");
}

int read(string str) {
  if(str == "writing" || str == "headstone") {
    write (::query_long("writing"));
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}

