/**
 * Make a book with all the files in a dir.
 * @author Pinkfish
 */

inherit BOOK_OBJ;

/**
 * Sets the directory to look for the book pages in.  It scans every
 * file in this dir to get the pages for the book.
 * This sets the default paper to /obj/misc/nroff_paper.c
 * @param dir the directory in which to search
 * @see /std/stationery/nroff_paper.c
 * @example
 * inherit "/std/book_dir";
 *
 * void setup() {
 *    ...
 *    set_book_dir("/save/books/dead/dead_page");
 *    ...
 * } /\* setup() *\/
 */
void set_book_dir( string dir ) {
    int i, max;

    set_no_pages(10);
    max = 10;
    i = 1;

    set_default_page_object(STD_STATIONERY_DIR "/nroff_paper");
    while( file_size(dir+i) > 0 ) {
        set_open_page(i);
        query_current_page_clone()->set_file_name(dir+i);
        i++;
        if( i >= max ) {
            max += 10;
            set_no_pages(max);
        }
    }

    // Reduce the number of pages down.
    set_no_pages(i-1);
    set_open_page(0);

} /* set_book_dir() */
