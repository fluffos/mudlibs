#ifndef __BOOKS_H__
#define __BOOKS_H__

// Filename for textfile to be displayed as a book.
#define P_BOOK_CONTENTS "book_contents"

/* Property for height of pages. If zero, the book
 * will assume P_SCREENSIZE for textheight.
 */
#define P_BOOK_PAGE_HEIGHT "book_page_height"

/* Property for textwidth. Note, that this property
 * contains only the width of ONE page in characters.
 * There will be two pages displayed simultaneously.
 * For margins, etc. another 12 characters will be
 * needed.
 */
#define P_BOOK_PAGE_WIDTH "book_page_width"

// Two properties just for the looks :)
// the first one is the frame char (normally a hash mark #)
#define P_BOOK_FRAME_CHAR "book_frame_char"
// the second one is the fill_char (normallz a space)
#define P_BOOK_FILL_CHAR "book_fill_char"

// And now some error definitions:
#define ERR_BOOK_OTHER                 -1
#define ERR_BOOK_NO_CONTENTS           -2
#define ERR_BOOK_CONTENTS_FILE_CORRUPT -3

#endif
