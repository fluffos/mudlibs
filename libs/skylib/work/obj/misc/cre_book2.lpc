
inherit "/std/book_dir";

void setup() {
    set_name("book");
    set_short("Command Summary");
    add_alias("summary");
    add_plural("summaries");
    add_adjective( ({"small", "black", "command"}) );

    set_long("This is a pocket size black book, which looks as if it "
        "has just been printed.\n");

    set_read_mess("The Creator's Command Quick Reference.");
    set_no_pages(8);
    set_weight(11);

    add_property(NO_RECYCLE, 1 );
    set_book_dir("/save/books/creator2/page");
    set_open_page( 0 );

} /* setup */

int do_tear( int num ) { return 0; }
