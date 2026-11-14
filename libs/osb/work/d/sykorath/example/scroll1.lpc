/*
 * example2 file for 'how to use the new book'
 * introduced by Magictcs - March 98
 *
 * we just want to use SetPageContent, because a scroll has only
   one page! but we want to open/close the scroll
*/

#include <properties.h>

inherit "/d/sykorath/std/book";       // changed later

create() {
  ::create();
  SetShort("an old scroll");
  SetLong("It's an old scroll. You can open/close it and you can read it.\n");
  AddId("scroll");
  AddAdjective("old");

  // we cannot use SetReadMsg() but we can use SetPageContent() !!
  SetPageContent("This is the content of our scroll.\n"
    "You can use as many lines you want.\n");

  SetMaxPage(1);                       // the scroll has only one page
}
