
inherit "/std/book_dir";

void setup() {
   set_name("book");
   set_short("Creator's Handbook");
   add_alias("handbook");
   add_plural("handbooks");
   add_adjective( ({"small", "black", "creator", "creator's"}) );

   set_long("This is a pocket size black book, which looks as if it "
       "has just been printed.\n");

   set_read_mess("The Creator's Handbook");

   set_weight(10);
   add_property( NO_RECYCLE, 1 );
   set_book_dir("/save/books/creator1/page");
   set_open_page( 0 );

} /* setup */

int do_tear( int num ) { return 0; }
