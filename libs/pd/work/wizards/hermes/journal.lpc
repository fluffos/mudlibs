#include <std.h>
#include <hermes.h>
inherit OBJECT;
void create() {
    ::create();
    set_short("Torn up journal");
    set_name("journal");
    set_id(({"book", "diary", "journal"}));
    set_long("This must have been left by the former owner of the house. Maybe you should read it?");
    set_weight(2);
}
void init() {
  ::init();
  add_action("read", "read");
}
int read(string str) {
  if(!str)
    return notify_fail("Read what?\n");
  if (str = "journal" || str = "diary" || str = "book") 
  {
       write(
       "Truly remarkable! Paging through the book, you find what appears to be a meticulously kept journal of an exiled angel named Ilithyd\n"
       "As your eyes scan over the crumbling paper, a story unfolds. Ilithyd describes the demon Asmodeus, the foul one; who tricked the Gods into believing ill of Ilithyd.\n"
       "Thusly exiling him to Distopia. The journal goes on to describe how Ilithyd set up residence in this very house, "
       "his plots to prove his innocence to the Gods and his ultimate desire to return to the heavens.\n\n");
       
       write(
       "Pages and pages of sketches, notes, plans... All becoming more confused, jumbled.. Even the script, which was at first clear and crisp - now blurs together...\n"
       "The entries, more scattered.. It quickly becomes impossible to find any sense in the later entries.\n"
	   "Throughout the entire journal, even the jumbled bits .. One theme remains true. Ilithyd must have hated the woods to the south of his home.\n"
	   "The journal states repeatedly that a demon had taken up residence there amongst the trees, and the foul being was determined to taunt Ilithyd for the rest of his days.\n"
	   "Paranoia clouds many of those passages as he rants on and on about the demon's taunting behaviour. Everything that goes badly is blamed on the demon.\n"
	   "As you flip to the last page of the journal's stained pages, one strikingly clear passage is printed.\n\n"
	   "I cannot stand any more of this foul demon's taunting games! I go tonight to the woods, to end this. To slay him. I will bring his head on a pike back to the heavens! That lowly servant of Asmodeus's .. Then shall I be justly praised.\n\n"
		"There is nothing more written.");
	}
 else
 return notify_fail("Read what?\n");
}
