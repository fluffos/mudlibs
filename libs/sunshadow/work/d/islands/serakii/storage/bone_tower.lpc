
//Tower of Bone

#include <std.h>
#include "../serakii.h"

inherit CVAULT ;

int has_a_clue, items;
object ob;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_name("room in a tower of bone");
    set_short("room in a tower of bone");
    set_long("You stand in a large room in the tower of %^C189%^bone%^CRST%^. The walls around you are formed of %^C189%^bone%^CRST%^, completely smooth and %^C195%^bleached white%^CRST%^. The floor is set in interlocking tiles of different %^C245%^shades of stone%^CRST%^ forming beautiful yet random patterns. The ceiling is high above you and the whole room is lit with a series of %^C206%^delicate lanterns%^CRST%^ that hang on the walls, basking the room in %^C204%^pale pink light%^CRST%^. Solid %^C058%^tall mahogany book cases%^CRST%^ line the walls and are packed with %^C059%^scrolls %^CRST%^and %^C058%^books%^CRST%^. The whole area smells faintly of %^C126%^lilacs %^CRST%^and from around every corner you hear %^C062%^children giggling%^CRST%^. Overall the whole area seems extremely well cared for.\n");
	has_a_clue = 0;
    set_items(([
        ({"wall","walls"}) : "The walls of the tower are pure %^C193%^bleached bone%^CRST%^. It is not a collection of %^C193%^bones %^CRST%^either, it is as if the whole tower is a single %^C193%^bone %^CRST%^that has been carved and polished.",
        ({"floor","tiles"}) : "The floor is tiled with different %^C245%^shades of stone%^CRST%^, forming a chaotic yet fascinating pattern. It has been placed with care and obvious craftsmanship.",
        ({"lights","lanterns"}) : "Delicate lanterns made of %^C231%^silver %^CRST%^and %^C086%^glass %^CRST%^hang from the walls and cast a %^C206%^magical pink light%^CRST%^ across the room.",
        ({"books","bookcases"}) : "%^C058%^Dark mahogany bookcases%^CRST%^ line the walls and are filled with %^C059%^scrolls %^CRST%^and %^C058%^books%^CRST%^. You could probably %^C137%^>search<%^CRST%^ them for something interesting.",
    ]));

    set_smell("default","%^C129%^You smell sweet lilac.%^CRST%^");
    set_listen("default","%^C075%^You hear giggling.%^CRST%^");

    set_search("default","Where do you want to search?");
    set_search("bookcases",(:TO,"search_bookcases":));

}

void reset() {
   ::reset();
   items = 1;
   }


int search_bookcases(string str) {
    if (!items) {
        tell_object(TP,"It seems like someone has searched "+
        "here already.");
      return 1;
    }
	if (has_a_clue == 0) {
    switch(random(100)) {
      case 0..40:
	  ob = new("/d/magic/scroll");
      ob->set_spell(random(4)+4);
      ob->move(ETP);
      tell_object(TP,"%^C064%^You find a scroll tucked between two books.%^RESET%^");
      tell_room(ETP,"%^C064%^"+TP->QCN+" %^C064%^pulls a scroll from between two books.%^RESET%^",TP);
      break;

      case 41..70:
	  ob = new("/d/magic/scroll");
      ob->set_spell(random(2)+6);
      ob->move(ETP);
      tell_object(TP,"%^C065%^You find a scroll tucked behind a book.%^RESET%^");
      tell_room(ETP,"%^C065%^"+TP->QCN+" %^C065%^pulls a scroll behind a book.%^RESET%^",TP);
      break;

      case 71..80:
		ob = new("/d/magic/scroll");
		ob->set_spell(random(2)+8);
		ob->move(ETP);
		tell_object(TP,"%^C071%^You open a book and a scroll falls from its pages.%^RESET%^");
		tell_room(ETP,"%^C071%^"+TP->QCN+" %^C071%^opens a book and a scroll falls from its pages.%^RESET%^",TP);
      break;

    default:
        tell_object(TP,"%^C059%^You don't find anything worth taking "+
	    "from this bookcase.");
        tell_room(ETP,"%^C059%^"+TP->QCN+" %^C059%^can't seem to find "+
        "anything in the bookcase.%^RESET%^",TP);
      break;
      }
    items = 0;
    return 1;
}

switch(has_a_clue){
	
	case 1:
		ob = new(OBJ"bone_book_1");
		ob->move(ETP);
		tell_object(TP,"%^C136%^You pull a book that looks interesting from the bookcase.%^RESET%^");
		tell_room(ETP,"%^C136%^"+TP->QCN+" %^C136%^pulls an interesting looking book out of the bookcase.%^RESET%^",TP);
	break;

	case 2:
		ob = new(OBJ"bone_book_2");
		ob->move(ETP);
		tell_object(TP,"%^C136%^You pull a book that looks interesting from the bookcase.%^RESET%^");
		tell_room(ETP,"%^C136%^"+TP->QCN+" %^C136%^pulls an interesting looking book out of the bookcase.%^RESET%^",TP);
		
	break;

	case 3:
		ob = new(OBJ"bone_book_3");
		ob->move(ETP);
		tell_object(TP,"%^C136%^You pull a book that looks interesting from the bookcase.%^RESET%^");
		tell_room(ETP,"%^C136%^"+TP->QCN+" %^C136%^pulls an interesting looking book out of the bookcase.%^RESET%^",TP);

	break;
	
	case 4:
		ob = new(OBJ"bone_book_4");
		ob->move(ETP);
		tell_object(TP,"%^C136%^You pull a book that looks interesting from the bookcase.%^RESET%^");
		tell_room(ETP,"%^C136%^"+TP->QCN+" %^C136%^pulls an interesting looking book out of the bookcase.%^RESET%^",TP);
	break;
	
    items = 0;
    return 1;
}

}