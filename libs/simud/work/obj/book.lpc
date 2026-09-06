#include <item.h>
#include <desc.h>
#include <object.h>
#include <saveload.h>
#include <const.h>

#include <literacy.h>

ICON( '\"', 3, LAYER_ITEMS )
DISTANT("a book")
SPECIFIC("the book")
PLURAL("books")
NAME("book")
GETTABLE(1)
DROPPABLE(1)
WEIGHT(500)
BULK(1)
LOOK("A rather plain book.")

// prototypes
string query_look();
void time_out();

int loc_exists(string str);
int query_signed();
int unsign();
int has_signed(string who);
int on_sign(string by, int quality);
int query_pages();
int set_pages(int p);
int add_location(string str);
int remove_location(string str);
string query_location(string where);
int set_location(string where, string what);
int on_read(string where);
int on_write(string where);
int on_edit(mixed str);
int on_erase(string where);

// variables
object lineedit_ob;
int pages;
string *page;
mapping locations = ([ ]);
mapping readers = ([ ]);
string editing;
mapping signator = ([ ]);
int sig_quality;

// functions

string query_look() {
  string str;
  int m = sizeof(m_indices(signator));
  int n = sizeof(m_indices(locations));


  str = desc::query_look() + "\n";
  if (pages) {
    str += "It has " + pages + " pages";
    if (m)
      str += " and has been signed by " + comma_list( map(m_indices(signator), (: capitalize($1) :)) ) + ".";
    else
      str += ".";
  } else {
    if (m)
      str += "It has been signed by " + comma_list( map(m_indices(signator), (: capitalize($1) :)) ) + ".";
  }
  if (loc_exists("spine") && strlen(query_location("spine")) > 0 ) {
    str += "\nThe spine reads '" + query_location("spine") + "'";
    if (loc_exists("cover") && strlen(query_location("cover")) > 0)
      str += " and the cover reads:\n" + query_location("cover");
    else
      str += ".";
  } else {
    if (loc_exists("cover") && strlen(query_location("cover")) > 0)
      str += "\nThe cover reads:\n" + query_location("cover");
  }

  return str;
}

void time_out() {
  readers = ([ ]);
}

int loc_exists(string str) {
  if (member(m_indices(locations), str) == -1)
    return 0;
  else
    return 1;
}

int query_signed() {
  if (sizeof(m_indices(signator)) == 0)
    return 0;
  else
    return 1;
}

int unsign() {
  WIZ_CHECK

  sig_quality = 0;
  signator = ([ ]);
  msg("Unsigned " + this_object()->query_specific());
}

int has_signed(string who) {
  if (signator[who] > 0)
    return 1;
  return 0;
}

int on_sign(string by, int quality) {
  if ( has_signed(this_player()->query_name()) )
    return HAS_SIGNED;

  signator += ([ by : quality ]);
  return 1;
}

int query_pages() {
  return pages;
}

int set_pages(int p) {
  pages = p;
  page = allocate(p, "");
  return p;
}

int add_location(string str) {
  if (loc_exists(str))
    return BAD_LOCATION;

  locations += ([ str : "" ]);
}

int remove_location(string str) {
  if (!loc_exists(str))
    return BAD_LOCATION;

  locations -= ([ str ]);
}

string query_location(string where) {
  if (!loc_exists(where))
    return as_string(BAD_LOCATION);

  return locations[where];
}

int set_location(string where, string what) {
  if (!loc_exists(where))
    return BAD_LOCATION;

  locations[where] = what;
}

int on_read(string where) {
  int p = 0;

  if (!where || strlen(where) == 0) {

    remove_call_out("time_out");
    call_out("time_out", 300);

    if (readers[this_player()] == query_pages())
      readers -= ([ this_player() ]);

    if (!readers[this_player()] && loc_exists("cover"))
      readers[this_player()] = "cover";
    else if (!readers[this_player()] && loc_exists("front"))
      readers[this_player()] = "front";
    else if (!readers[this_player()])
      readers[this_player()] = 1;
    else if (readers[this_player()] == "cover" || readers[this_player()] == "front")
      readers[this_player()] = 1;
    else
      readers[this_player()]++;

    where = readers[this_player()];
  }

  if (loc_exists(where)) {
    if (strlen(query_location(where)) == 0)

      msg("The " + where + " is blank.\n");
    else
      msg("The " + where + " reads:\n" + query_location(where));

    return 1;
  }

  // if it gets down to here it must be pages
  if (pages == 0)
    return BAD_LOCATION;

  p = to_int(where);
  if (query_to_int_fail())
    return BAD_LOCATION;

  p--; // we keep track from 0, but fleshy humans start at 1
  if (p < 0 || p > pages)
    return BAD_PAGE;

  if (strlen(page[p]) == 0) {
    msg("Page " + where + " of " + this_object()->query_specific() + " is blank.\n");
  } else {
    msg("Page " + where + " of " + this_object()->query_specific() + " reads:\n" + page[p]);
  }
  return 1;
}

int on_write(string where) {
  string str;
  int p;

  if (this_object()->query_signed()) {
    return IS_SIGNED;
  }

  if (!where || strlen(where) == 0) {
    return BAD_LOCATION;
  }

  // have to save this somewhere for on_edit
  editing = where;

  if (loc_exists(where))
    str = query_location(where);
  else {
    p = to_int(where) - 1;
    if (query_to_int_fail())
      return BAD_LOCATION;

    if (p < 0 || p > pages)
      return BAD_PAGE;

    str = page[p];
  }

  lineedit_ob = clone_object( "/obj/lineedit" );
  lineedit_ob->move(this_player());
  lineedit_ob->edit_buffer(str, this_object(), "on_edit");
  return 1;
}

int on_edit(mixed str) {
  int p;

  if ( pointerp(str) ) str = implode( str,"\n" );

  destruct(lineedit_ob);


  while( strlen(str) && str[0] == '\n' ) str = str[1..];


  if (!str || str == "" || str == "0")
    return this_object()->on_erase();

  if (loc_exists(editing))
    set_location(editing, str);
  else {
    p = to_int(editing) - 1;
    if (query_to_int_fail())
      return BAD_LOCATION;

    if (p < 0 || p > pages)
      return BAD_PAGE;

    page[p] = str;
  }

  set_target(this_object());
  this_player()->msg_local("~CACT~Name ~verbfinish writing in ~targ~CDEF");
  return 1;
}

int on_erase(string where) {
  int p;

  if (this_object()->query_signed())
    return IS_SIGNED;

  if (loc_exists(where)) {
    set_location(where, "");
  } else {
    p = to_int(where) - 1; //pesky humans, counting from 1
    if (query_to_int_fail())
      return BAD_LOCATION;

    if (p < 0 || p > pages)
      return BAD_PAGE;

    page[p] = "";
  }

  return 1;
}

void create() {
  ::create();

  set_pages(8);
}
