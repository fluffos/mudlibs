/*
 * example file for 'how to use the new book'
 * introduced by Magictcs - March 98
 *
 * a file bookfile.txt belongs to this example!
 * it is a lock-able diary!
 *
 */


/*
 * doc file is missing actually - sorry
 * the bookfile itself has to look like the following:


#     page     <number>
text for page <number> - multiple lines are allowed
# <number2>
text for page number2


 * Each page has to start with a '#' !!
 * after the '#' any number of spaces may follow, and a string 'page'
 * may follow.
 * spaces or 'page' are NOT (!) needed
 * after that the page-number follows
 * correct page number marks are:
 *  '#1'             -> page 1
 *  '#    3'         -> page 3
 *  '#   page    56' -> page 56
 * Don't use a page number less than one!
 *
 * The following text until the next '#' is the text for this page
 * it is shown if you try to read the book at this page.
 *
 * Don't use any '#' inside your pages !!
 * by the book (but we can change this)
 *
 * You have to call SetBookFile(string) to point to the file where the
 *     book-text is stored.
 * And you have to call SetMaxPage(int) to set the maximum of available
 *     pages.
 *
 * NOTE: please don't overload SetReadMsg() - the functionality of the book
 *       will get lost - but it is possible to overload it (for example
 *       for a book with only one side!)
*/

#include <properties.h>
#include <lock.h>

inherit "/d/sykorath/std/book";       // changed later

create() {
  ::create();
  SetShort("an old diary");
  SetLong("It's an old diary. You can open/close it and you can read it. "
    "Sometimes you have to turn the pages.\n");
  AddId("diary");
  AddAdjective("old");
  SetKeyCode("diary");
  SetKeyIds(({"diary key"}));
  SetLockState(LOCK_LOCKED);
  SetBookFile("/d/sykorath/example/bookfile.txt");
  SetMaxPage(10);
}

