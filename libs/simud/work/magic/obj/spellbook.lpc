#include <object.h>
#include <magic.h>
#include <item.h>
#include <condition.h>
#include <saveload.h>
#include <literacy.h>


int num_pages;
string *pages;	// ({ "fire ball", "frost bolt" })
int page;		// current page number

string label;
string adjective;	// randomly determined at crafting time

string query_distant() {
  if (label)
    return ::query_distant() + " {" + label + "}";
  return ::query_distant();
}

string query_plural() {
  if (label)
    return ::query_plural() + " {" + label + "}";
  return ::query_plural();
}

string * query_alt_plural() {
  if (label)
    return ::query_alt_plural() + ({ label+" spellbooks" });
  return ::query_alt_plural();
}

int on_label(string str) {
  if (label) {
    msg("The "+adjective+" spellbook is already labeled '"+label+"'!");
    return 0;
  }
  label = str;
  set_alt_name( ({ "book", adjective+" book", adjective+" spellbook", label+" book", label+" spellbook" }) );
  return 1;
}

void set_label(string str) {
  label = 0;
  on_label( str );
}

string query_label() { return label; }

// resize the array happily
void set_num_pages( int x ) {
  num_pages = x;
  pages = allocate( num_pages, pages );
}
int query_num_pages() { return num_pages; }

void set_pages( string *arr ) {
  pages = arr;
  num_pages = sizeof(pages);
}
string *query_pages() { return copy(pages); }

void set_page( int x, string str ) {
  if( x <= num_pages && x > 0 )
    pages[x-1] = str;
  else
    debug("attempt to set page "+x+" on a "+num_pages+" page book.");
}
string query_page( int x ) {
  if( x <= num_pages && x > 0 )
    return pages[x-1];
  else
    return 0;
}

int query_current_page() { return page; }
void set_current_page( int x ) {
  page = x;
  if( page > num_pages || page < 0 )
    page = 0;
}

int query_closed() { return page == 0; }
void set_closed(int closed) {
  set_current_page( closed ? 0 : 1 );
}
int on_open() {
  if( query_closed() ) {
    set_actor( this_player() );
    set_target( this_object() );
    this_player()->msg_local("~CACT~Name ~verbopen ~targ to page 1.~CDEF");
    set_current_page( 1 );
  } else {
    set_target( this_object() );
    msg("~Targ is already open to page "+page+".");
  }
  return 1;
}
int on_close() {
  if( !query_closed() ) {
    set_actor( this_player() );
    set_target( this_object() );
    this_player()->msg_local("~CACT~Name ~verbclose ~targ.~CDEF");
    set_current_page( 0 );
  } else {
    set_target( this_object() );
    msg("~Targ is already closed.");
  }
  return 1;
}


void set_adjective( string str ) {
  adjective = str;
}
string query_adjective() { return adjective; }
string random_adjective() {
  string *list = ({ "thin", "thick", "fat", "heavy", "light", "bulky",

                    "ornate", "engraved", "plain", "embossed", "jewelled",

                    "leather-bound", "copper-bound", "iron-bound",
                    "silver-bound", "lead-bound", "skin-bound",
                    "linen-bound", "silk-bound",

                    "amber", "aqua", "aquamarine", "azure", "beige", "black",
                    "blue", "brown", "burgundy", "cerulean", "chartreuse",
                    "cream", "crimson", "cyan", "dark blue", "dark brown",
                    "dark green", "dark pink", "dark violet", "grey",
                    "green", "indigo", "lavender", "light brown",
                    "magenta", "maroon", "mauve", "mustard yellow",
                    "navy blue", "olive", "orange", "pale blue", "pale brown",
                    "pale yellow", "pastel pink", "pink", "peach", "puce",
                    "purple", "powder blue", "red", "royal blue", "russet",
                    "saffron", "scarlet", "sea green", "sepia", "slate grey",
                    "tan", "taupe", "teal", "turquoise", "ultramarine",
                    "ultraviolet", "vermilion", "violet", "viridian",
                    "white", "yellow",

                    "tattered", "singed", "torn", "musty", "dusty",
                    "rusty", "frayed", "faded", "ragged", "splotchy",
                    "water-damaged", "crumbling", "shiny", "dirty",
                    "shimmering", "sparkling", "moldy", "flimsy",
                    "ancient",

                    "ominous", "vibrating", "evil", "glowing", "pulsing",
  });
  return list[random(sizeof(list))];
}

string query_look() {
  string buf;
  buf = "This is a spellbook. It is a receptacle for storing knowledge about "+
        "spells. You cannot cast spells directly from the book, but you can "+
        "~CCOMturn a page~CDEF or ~CCOMturn to page #~CDEF in order to peruse "+
        "the book's contents until finding either a blank page onto which "+
        "to ~CCOMscribe~CDEF a new spell or a filled page from which to "+
        "~CCOMmemorize~CDEF something.";
  buf += "\n\nThis book has "+num_pages+" pages and is currently ";
  if( page )
    buf += "open to page "+page+", which "+
           (query_page(page)?"contains a spell. You could try to "+
                             "~CCOMread~CDEF the book for more information."
                            :"is blank.");
  else
    buf += "closed.";
  return buf;
}

void create() {
  ::create();
  set_num_pages( 20 );
  set_adjective( random_adjective() );
  if( member( ({'a','e','i','o','u'}), adjective[0] ) != -1 )
    set_distant("an "+adjective+" spellbook");
  else
    set_distant("a "+adjective+" spellbook");
  set_specific("the "+adjective+" spellbook");
  set_plural("spellbooks");
  set_alt_plural( ({adjective+" spellbooks", "books", adjective+" books"}) );
  set_name("spellbook");
  set_alt_name( ({adjective+" spellbook", "book", adjective+" book"}) );
  set_gettable(1);
  set_droppable(1);
  set_bulk(1);
  set_condition(query_max_condition());
  set_dest_on_break(1);
}

void init() {
  ::init();
  add_action("do_turn","turn");
}

int query_weight() { return num_pages * 25 + 150; }
int query_max_condition() { return num_pages * 10 + 100; }

int on_break() {
  object room = environment(this_object());
  if (room->query_is_living())
     room = environment(room);
  set_actor(this_object());
  msg_room(room,"~CWRN~Name ~verbburst into flames and ~verbis gone!~CDEF");
  return 1;
}

int do_turn( string args ) {
  int new_page = page + 1;
  object book;
  string bookname, buf;

  // parse and validate parameters
  if( !args || environment(this_object()) != this_player() )
    return 0;
  args = implode(explode(args,"of"),"in");
  sscanf(args, "a page in %s", bookname);
  if( !bookname )
    sscanf(args, "page in %s", bookname);
  if( !bookname )
    sscanf(args, "%s to page %d", bookname, new_page);
  if( !bookname )
    sscanf(args, "to page %d in %s", new_page, bookname);
  if( !bookname || !this_object()->id(bookname) )
    return 0;
  debug( "turn "+bookname+" to "+new_page, "magic");

  // actually perform the page turning
  set_current_page( new_page );

  // and do the messaging
  set_actor(this_player());
  set_target(this_object());
  if( page == 0 )
    buf = "~Name ~verbclose ~targ.";
  else
    buf = "~Name ~verbturn ~targ to page "+page+".";

  this_player()->msg_local("~CACT"+buf+"~CDEF");

  return 1;
}

string query_spell() { return query_page(page); }
// can only set valid spells ;)
void set_spell(string str) {
  if (MAGIC_DAEMON->query_spell(str))
    set_page(page, str);
  else
    debug("attempt to set invalid spell '"+str+"' on spellbook.");
}

// called whenever this book is read
int on_read() {
   string buf;
   if( !page ) {
      msg("The book is closed. Look at it for instructions for use.");
      return 1;
   } else
   if( !query_spell() ) {
      msg("The page is blank.");
      return 1;
   }
   // eventually probably should make this use kn.arcana and/or arcane language
   int check = this_player()->skill_check("magic.item.scroll", 30);
   buf = "The page is covered in mystic runes.";
   if ( check )
      buf += "\nIt appears to be a '"+query_spell()+"' spell.";
   else
      buf += "\nYou are unable to decipher any of the arcane writing.";
   msg(buf+"\n");
   return 1;
}
