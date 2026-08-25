inherit "std/room";
  object coffin;

void create() {
   ::create();
     set_property("light", 0);
     set_short( "The grave");
    set_long(
	"You have foolishly climbed down into the ancient grave of one of "
      "the founders of Praxis.  You are standing on the closed lower door "
      "of a coffin.  The upper door is open and gruesomely inviting.  The "
      "soil presses in around you claustrophobicly.");
    set_items(
	(["under" : "You can't look under the coffin, you're "
	    "standing on it.",
	  "soil" : "The dirt walls of the grave are soft and "
	    "smell of the earth.",
	  "grave" : "The grave is horribly empty and sad."]) );
    set_exits( 
	      ([ "up" :	"/domains/Praxis/cemetary/grave_yard2"]) );
     coffin = new("/realms/darkone/grave/coffin");
     if(coffin) coffin->move(this_object());
}

