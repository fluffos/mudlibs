inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void second(object tp);
void third(object tp);
void fourth(object tp);

void create() {
  ::create();
  set_property("indoors",0);
  set_property("no gate",1);
  set_property("light",2);
  set("short","Hidden Chamber");
  set("long","The air here is thick, as if it could be cut with a knife.  The "
    "surrounding brick walls are almost clostraphobically close.  The solid stone "
    "floor is etched in mystical runes, which all surround a solid gold pedestal in "
    "the center of this room.  A closed book lays on top of it, awaiting the next person"
    " brave enough to lift it from it's pedestal to be read.  The pedestal seems to "
    "glow, and is the source of light for this room");
  set_smell("default","The air is stale from being sealed for centuries.");
  set_listen("default","The air seems to crackle with the magical barrier surrounding it.");
  set_items((["air":"You can almost feel it squish through your fingers.",
    "walls":"As you try to get closer to the walls, you find it harder and harder "
      "to move, until you are only able to move back towards the center of the room.",
    "pedestal":"The golden pedestal is intricately inscribed with pictures of war and "
    " various symbols.  The gold seems to glow, as if white hot, but is cold to the touch.",
    "book":"The book has nothing on the cover.  You'll have to actually read it.",
    "runes":"The runes on the floor form a circle about the pedestal."]));
  new(OBJ "pedestal")->move(this_object());
}

void init() {
  ::init();
  add_action("read_it","read");
}

int read_it(string str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str != "book") {
    notify_fail("You can't read that!\n");
    return 0;
  }
  else {
    write("You open the book and begin to read...\n\n");
    call_out("second",3,this_player());
    return 1;
  }
}

void second(object tp) {
      message("info", "Long ago, the city of Tenebrae"
      " was a bustling sea port.  In fact, it became a very important city, and when "
      "war broke out among the nation of Regalar, Tenebrae became a prime target.  In "
      "a time when mages' power was matched only by other mages, they were the prime "
      "fighters in times of war.  Soon after the war began, enemy mages conjured up a "
      "spell that amplified the sun's power directly above the city.  The citizens and "
      "soldiers of Tenebrae soon began to perish from the heat.  The only way to save "
      "the city was to block out the sun.  The mages of Tenebrae gathered, and wrote a "
      "scroll with immense power that could block out the sun and save the city.  They "
      "managed to block the sun, but in doing so, made Tenebrae a dark and dismal place "
      "to do business.  It soon was forgotten.  As for the mages, they decided that the "
      "scroll was too powerful, and locked it away deep within Tenebrae Palace, sealed "
      "so that only the King could retrieve it in times of distress.", tp);
      call_out("third",6,tp);
}

void third(object tp) {
      message("info", "\n\nThe next page "
      "in the book is old and falling apart.  As if it was not originally part of the "
      "book.  As you begin to read the next page, you learn of the methods used by the "
      "mages of old, and gain some of their great wisdom of spellweaving...",tp);
      call_out("fourth",4,tp);
}

void fourth(object tp) {
      message("info", "\n\nSuddenly "
      "you find yourself torn out of the room, and back at the entrance to the palace.", tp);
    tp->move_player(ROOMS "palace01", "into thin air");
//    if (!tp->set_quest("tenebrae"))
//      return;
    tp->set_stats("wisdom",(this_player()->query_stats("wisdom")+2));
    tp->set_stats("intelligence",(this_player()->query_stats("intelligence")+2));
}
