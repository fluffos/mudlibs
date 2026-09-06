#include <legible.h>

int length;				// how many lines fit on a page of this item?
int num_pages;			// how many pages in this item?
int current_page;		// what page is this item open to?

struct page_struct {
   struct page_contents_struct *contents;
} *pages;

int query_is_legible() { return 1; }

int query_length() { return length; }
void set_length(int x) { length = x; }
int query_length_remaining() {
   int x, total = 0;
   for (x = 0; x < sizeof(pages[current_page].contents); x++)
      total += pages[current_page].contents[x].length;
   return total;
}


