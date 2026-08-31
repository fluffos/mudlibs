#include <std.h>
#include <tirun.h>

inherit OBJECT;

void create() {
    ::create();
    set_short("Old, tattered book");
    set_name("diary");
    set_id(({"book", "diary", "old book"}));
    set_long("This old book seems to have been the diary of Mr. Lomack, as his name is scrawled on the inside of the cover.");
    set_weight(2);
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str) {
  if(!str)
    return notify_fail("Read what?\n");

  switch(str) {
    case "page 1":
      write("Tathsun 5, 31 BN\n\n    After many months of research, I have come up with the final plan.  I will soon be able to transform common animals into extraordinary creatures!  I will begin research at once, using my own funds.");
      break;
    case "page 2":
      write("Tathsun 12, 31 BN\n\n    I have only had mild success..   But the small triumphs have only spurred me on more.  Funds are running low, I may need to stop working if things continue like this.");
      break;
    case "page 3":
      write("Tathsun 19, 31 BN\n\n    Failure.  The small changes I have managed have resulted in pitiful creatures.  The fantastic monsters of my dreams cannot be realized.  I will retire to my books.");
      break;
    case "page 4":
      write("Rikitu 14, 31 BN\n\n    Great news!  I was out amongst the commonfolk of the city, when a shady figure approached me with an offer I couldnt refuse!  He sold to me the legendary Book of Life, which contains accounts of some of the most extravagant creatures!  I will go back to work at once.");
      break;
    case "page 5":
      write("Rikitu 20, 31 BN\n\n    I have done it!  If only a small success, I have transformed a young creature into the chimaera that was spoken of in the Book of Life!  It is a lovely animal, both intelligent and strong.  Unfortunately, I have used all of my money to move this far.  I will search for someone to fund me, showing them the potential I have only begun to uncover.");
      break;
    case "page 6":
      write("Fyllun 10, 31 BN\n\n    Only one benefactor has been found.  And even they demand that it work on adult specimines.  I have run out of mature test subjects, though.  This is quite a predicament.");
      break;
    case "page 7":
      write("Fyllun 14, 31 BN\n\n    This has to be it!  I completed the calculations, and it all works out!  This formula will work.  It must.  It must...  because I will be the last test subject.  Neigh!  The first Chimaera!");
      break;
    case "page 8":
      write("The page is blank, except for a few scribbles:\n\n                  ..failed in the...\n\n        ..antidote..\n                   ..forgot combination...\n\n  The rest of the paper is illegable.");
      break;
    default: return notify_fail("Syntax: <read page #>\n");
  }
  return 1;
}
