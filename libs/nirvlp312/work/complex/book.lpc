/*
 * This is a generic book, i.e., it can be cloned and configured as the
 * respective wizard wants to have the particulars of his book, tome, diary,
 * history, etc. Please do not change any of _this_ code without real need.
 * If you do so, notify me as soon as possible about the why and what. As
 * i'm not as often in Tubmud as i'd like, you can tell any of the Bonn
 * wizards, i.e., Bumblebee, Foslay, Gentle, or Magor as well, although
 * Foslay would be the best alternative.
 *
 * For an example how to configure your own book, see the file
 * "/doc/info/complex/book". And please remember to read the
 * remarks at the end of that file, they're important (RTFM ;).
 *
 * At the end of this file you will find a summary of the functions in this
 * object and a short description of what they do.
 *
 * If you've got any new ideas what to do with a book, please feel free to
 * tell or mail it to me. But please don't send me any ridiculous ones or
 * ideas which make another item necessary, e.g., burning a book needs a
 * source of fire, i.e., it isn't an inherent ability of the book.
 *
 * And yes, i know, this book seems to be written on single pages, no
 * difference between the left (even) and the right (odd) side of a page.
 * This is intentional. To program a book which uses both sides of a page,
 * the effort and size of the resultant file could get out of hand. As a
 * compromise, i'd suggest that the first half of a page is considered to
 * be the left hand side, while the second half is considered to be the
 * right side of a page, or vice versa.
 *
 * Anyway, have fun with it.    :)
 *
 *                              (c) Copyright by Ela Battleaxe, Bonn 1993
 */

#pragma strong_types

#include <persistence.h>  // Coogan, 18-Jun-98

inherit "complex/item";

#define TP this_player()
#define QN query_name()
#define QP query_pronoun()
#define PO query_possessive()

void set_contents(mixed *m);
void set_details(mixed *d);
void set_looks(mixed *l);
void set_protection(status p);
void pricing();
void weighing();
int empty();
void lengthen();
void shorten();
string book_id();
int leaf(string str);
int shut(string str);
void turn_page();
void output();
int cardinal(string str);
int ordinal(string str);
string change();
void tearout();


mixed *contents;
int booksize;

/* Looks of the Book */

string *complexion = ({
        "Its just the cover of a book.\n",
        "It is just an empty cover,\n"+
        "all the pages seem to have been torn out.\n",
        "You see nothing special, just the page of a book.\n",
        "This page seems to have been torn out by brute force.\n"
        });
mixed *details, *looks;

/* Arrays used for parsing page numbers */

string *cardinals = ({
        "zero",         "one",          "two",
        "three",        "four",         "five",         "six",
        "seven",        "eight",        "nine",         "ten",
        "eleven",       "twelve",       "thirteen",     "fourteen",
        "fifteen",      "sixteen",      "seventeen",    "eighteen",
        "nineteen",     "twenty",       "twenty-one",   "twenty-two",
        "twenty-three", "twenty-four",  "twenty-five",  "twenty-six",
        "twenty-seven", "twenty-eight", "twenty-nine",  "thirty",
        "thirty-one",   "thirty-two",   "thirty-three", "thirty-four",
        "thirty-five",  "thirty-six",   "thirty-seven", "thirty-eight",
        "thirty-nine",  "forty",        "forty-one",    "forty-two",
        "forty-three",  "forty-four",   "forty-five",   "forty-six",
        "forty-seven",  "forty-eight",  "forty-nine",   "fifty"
        });
string *ordinals_n = ({
        "cover", "1st",  "2nd",  "3rd",  "4th",  "5th",  "6th",  "7th",
         "8th",  "9th", "10th", "11th", "12th", "13th", "14th", "15th",
        "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd",
        "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st",
        "32nd", "33rd", "34th", "35th", "36th", "37th", "38th", "39th",
        "40th", "41st", "42nd", "43rd", "44th", "45th", "46th", "47th",
        "48th", "49th", "50th"
        });
string *ordinals_s = ({
        "cover",         "first",          "second",
        "third",         "fourth",         "fifth",          "sixth",
        "seventh",       "eighth",         "ninth",          "tenth",
        "eleventh",      "twelfth",        "thirteenth",     "fourteenth",
        "fifteenth",     "sixteenth",      "seventeenth",    "eighteenth",
        "nineteenth",    "twentieth",      "twenty-first",   "twenty-second",
        "twenty-third",  "twenty-fourth",  "twenty-fifth",   "twenty-sixth",
        "twenty-seventh","twenty-eighth",  "twenty-ninth",   "thirtieth",
        "thirty-first",  "thirty-second",  "thirty-third",   "thirty-fourth",
        "thirty-fifth",  "thirty-sixth",   "thirty-seventh", "thirty-eighth",
        "thirty-ninth",  "fortieth",       "forty-first",    "forty-second",
        "forty-third",   "forty-fourth",   "forty-fifth",    "forty-sixth",
        "forty-seventh",  "forty-eighth",  "forty-ninth",    "fiftieth"
        });

/* Current Page Number */

int page_number;

/* Protects the pages from being torn out */

int protection;

/* Provides paper for torn out pages */

object parchment;
string writings;
int c, maxweight, p, pcounter, ploss, price, w, weight, wloss;

/* Temporary Variables */

mixed *changes;
string *book_name, drow, eht, hunted, let, newstr, tome, t_page;
int found, i, mp, num, page, pos, ra, result, success, tc;

void configure() {
  item::configure();
  set_persistence("complex/book", PER_KEEP_VARS, ({
    "contents", "protection", "page_number", "details", "looks",
    }));
  set_id(({ "book" }));
  set_short("a book");
  set_long("An empty book.\n");
  set_contents(({ "                A really empty book\n"
                  "                ===================\n",
                        /* Page 1 */
                  "\n"
                  "                ,----------------------------------,\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                |                                  |\n"
                  "                `----------------------------------'\n"
                  "\n"
        }));
  set_details(({ }));
  set_looks(({ }));
  set_protection(0);
  set_encumbrance(1000);
  set_value(20);
}

void set_contents(mixed *cont) {
        if( !pointerp( cont ) ){
                return;
        }
        else{
                contents = cont;
                booksize = sizeof( contents );
                page_number = 0;
        }
        if( p ){
                pricing();
        }
        if( w ){
                weighing();
        }
        c = 1;
}

mixed* query_contents() {
  return contents;
}

void set_details(mixed *det)
{
        if( !pointerp( det ) ){
                return;
        }
        else{
                details = det;
        }
}

mixed* query_details()
{
        if( sizeof( details ) == ( 2 * booksize ) ){
                return details;
        }
        else{
                details = ({});
                details = allocate( 2 * booksize );
                if( !pointerp( looks ) || sizeof( looks ) != 4 ){
                        looks = ({});
                        looks = allocate( 4 );
                        looks = complexion;
                }
                details[0] = looks[0];
                details[1] = looks[1];
                for( i = 1; i < booksize; i++ ){
                        details[2*i] = looks[2];
                        details[(2*i)+1] = looks[3];
                }
                return details;
        }
}

void set_looks(mixed *lo)
{
        if( !pointerp( lo ) ){
                return;
        }
        else{
                looks = lo;
        }
}

mixed* query_looks()
{
        return looks;
}

void set_protection(status prot)
{
        if ( !intp( prot ) ){
                return;
        }
        else{
                protection = prot;
        }
}

status query_protection()
{
        return protection;
}

void set_encumbrance(int arg)
{
        item::set_encumbrance(arg);
        if( c ){
                weighing();
        }
        w = 1;
}

void set_value(int arg)
{
        item::set_value(arg);
        if( c ){
                pricing();
        }
        p = 1;
}

string cover_id() {
        book_name = query_id();
        if( pointerp( book_name ) && empty() )
                return book_name[0];
        else
                return "book";
}

void init() {
  item::init();
        add_action( "open", "open" );
        add_action( "leaf", "go" );
        add_action( "leaf", "turn" );
        add_action( "view1", "look" );
        add_action( "view2", "examine" );
        add_action( "locate", "search" );
        add_action( "peruse", "read" );
        add_action( "vandalize", "rip" );
        add_action( "vandalize", "tear" );
        add_action( "shut", "close" );
}

int open(string str)       /* verb: open */
{
        if( !str ){
                notify_fail( "Open? Open what?\n" );
                return 0;
        }
        else if( ( id( str )
        ||   present( str ) == this_object() )
        ||   ( sscanf( str, "the %s", tome ) == 1
        &&   ( id( tome )
        ||   present( tome ) == this_object() ) ) )
        {
                if( page_number > 0 ){
                        write( "It is already open.\n" );
                        say(
TP->QN+" stares at a "+cover_id()+" with a confused expression.\n"
                        );
                        return 1;
                }
                if( page_number == 0 ){
                        write( "You open the "+book_id()+".\n" );
                        say( TP->QN+" opens a "+cover_id()+".\n" );
                        lengthen();
                        page_number++;
                        return 1;
                }
        }
        else if( ( pos = strstr( str, " on " ) ) > -1
        ||       ( pos = strstr( str, " at " ) ) > -1 ){
                newstr = str[pos+4..] + " of " + str[0..pos-1];
        }
        else{
                newstr = str;
        }
        leaf( "to " + newstr );
        if( success != -1 ){
                return 1;
        }
        else
                return 0;
}

int leaf(string str)          /* verbs: go, turn */
{
        success = -1;
        if( !str ){
                notify_fail( "Turn? Turn what?\n" );
                success = 0;
                return 0;
        }
        else if( id( str ) || present( str ) == this_object() ){
                write(
"You admire the empty back side of the "+book_id()+".\n"
                );
                say( TP->QN+" turns a "+cover_id()+" around.\n" );
                success = 0;
                return 1;
        }
        else if( str == "to cover"
        ||   str == "to the cover"
        ||   ( ( sscanf( str, "to the cover of the %s", tome )  == 1
        ||       sscanf( str, "to cover of the %s",     tome )  == 1
        ||       sscanf( str, "to the cover of %s",     tome )  == 1
        ||       sscanf( str, "to cover of %s",         tome )  == 1 )
        &&   ( id( tome )
        ||   present( tome ) == this_object() ) ) )
        {
                shut( query_id()[0] );
                shorten();
                success = 1;
                return 1;
        }
        else if(
        ( (  str == "page"
        ||   str == "the page"
        ||   str == "page forward"
        ||   str == "the page forward" ) && query_verb() == "turn" )
        ||   str == "to next page"
        ||   str == "to the next page"
        ||   ( ( sscanf( str, "to the next page of the %s", tome )  == 1
        ||       sscanf( str, "to the next page of %s",     tome )  == 1
        ||       sscanf( str, "to next page of the %s",     tome )  == 1
        ||       sscanf( str, "to next page of %s",         tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) )
        ||   ( ( sscanf( str, "the page of the %s forward", tome )  == 1
        ||       sscanf( str, "the page of %s forward",     tome )  == 1
        ||       sscanf( str, "the page of the %s",         tome )  == 1
        ||       sscanf( str, "the page of %s",             tome )  == 1
        ||       sscanf( str, "page of the %s forward",     tome )  == 1
        ||       sscanf( str, "page of the %s",             tome )  == 1
        ||       sscanf( str, "page of %s forward",         tome )  == 1
        ||       sscanf( str, "page of %s",                 tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() )
        &&   query_verb() == "turn" ) )
        {
                if( page_number < ( booksize - 1 ) ){
                        turn_page();
                        write( "You page through the "+book_id()+".\n" );
                        say( TP->QN+" leafs through a "+cover_id()+".\n" );
                        success = 1;
                }
                else {
                        write( "You close the "+book_id()+".\n" );
                        say( TP->QN+" closes a "+cover_id()+".\n" );
                        page_number = 0;
                        shorten();
                        success = 1;
                }
                return 1;
        }
        else if( ( ( str == "page back"
        ||   str == "the page back"
        ||   str == "back page"
        ||   str == "back the page" ) && query_verb() == "turn" )
        ||   str == "back to previous page"
        ||   str == "back to the previous page"
        ||   str == "to previous page"
        ||   str == "to the previous page"
        ||   ( ( sscanf( str, "back to the previous page of the %s", tome ) == 1
        ||       sscanf( str, "back to previous page of the %s", tome )  == 1
        ||       sscanf( str, "back to the previous page of %s", tome )  == 1
        ||       sscanf( str, "back to previous page of %s",     tome )  == 1
        ||       sscanf( str, "to the previous page of the %s",  tome )  == 1
        ||       sscanf( str, "to the previous page of %s",      tome )  == 1
        ||       sscanf( str, "to previous page of the %s",      tome )  == 1
        ||       sscanf( str, "to previous page of %s",          tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) )
        ||   ( ( sscanf( str, "the page of the %s back",         tome )  == 1
        ||       sscanf( str, "the page of %s back",             tome )  == 1
        ||       sscanf( str, "page of the %s back",             tome )  == 1
        ||       sscanf( str, "page of %s back",                 tome )  == 1
        ||       sscanf( str, "back the page of the %s",         tome )  == 1
        ||       sscanf( str, "back page of the %s",             tome )  == 1
        ||       sscanf( str, "back the page of %s",             tome )  == 1
        ||       sscanf( str, "back page of %s",                 tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() )
        &&   query_verb() == "turn" ) )
        {
                if( page_number > 1 ){
                        page_number--;
                        write(
"You page backwards through the "+book_id()+".\n"
                        );
                        say(
TP->QN+" leafs backwards through a "+cover_id()+".\n"
                        );
                        success = 1;
                }
                else if( page_number == 1 ){
                        write( "You close the "+book_id()+".\n" );
                        say( TP->QN+" closes a "+cover_id()+".\n" );
                        page_number = 0;
                        shorten();
                        success = 1;
                }
                else {
                        write( "The "+book_id()+" is already closed.\n" );
                        say(
TP->QN+" stares at a "+cover_id()+
" with a confused expression on "+TP->PO+" face.\n"
                        );
                        success = 0;
                }
                return 1;
        }
        else if( str == "to last page"
        ||   str == "to the last page"
        ||   ( ( sscanf( str, "to the last page of the %s", tome )  == 1
        ||       sscanf( str, "to the last page of %s",     tome )  == 1
        ||       sscanf( str, "to last page of the %s",     tome )  == 1
        ||       sscanf( str, "to last page of %s",         tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                if( page_number == ( booksize - 1 ) ){
                        write(
"You are already on the last page of the "+book_id()+".\n"
                        );
                        if( !empty() ){
                                say(
TP->QN+" stares at the page of a book with a confused expression.\n"
                                );
                        }
                        else{
                                say(
TP->QN+" stares at the interior of an empty book cover\n"+
"with a confused expression on "+TP->PO+" face.\n"
                                );
                        }
                }
                else if( page_number > 0 ){
                        page_number = booksize - 1;
                        write(
"You leaf through the "+book_id()+" until you reach the last page.\n"
                        );
                        say(
TP->QN+" pages through a "+cover_id()+" to its end.\n"
                        );
                }
                else if( page_number == 0 ){
                        write(
"You open the "+book_id()+" at the last page.\n"
                        );
                        say( TP->QN+" opens a "+cover_id()+" at its end.\n" );
                        lengthen();
                        page_number = booksize - 1;
                }
                success = 1;
                return 1;
        }
        else if(
        ( (  sscanf( str, "to the %s page", t_page )  == 1
        ||   sscanf( str, "to %s page",     t_page )  == 1 )
        &&   ( page = ordinal( t_page ) ) != -1 )
        ||   ( ( sscanf( str, "to the %s page of the %s", t_page, tome )  == 2
        ||       sscanf( str, "to the %s page of %s",     t_page, tome )  == 2
        ||       sscanf( str, "to %s page of the %s",     t_page, tome )  == 2
        ||       sscanf( str, "to %s page of %s",         t_page, tome )  == 2 )
        &&   ( id( tome ) || present( tome ) == this_object() )
        &&   ( page = ordinal( t_page ) ) != -1 )
        ||   ( ( sscanf( str, "to page %d of the %s", page, tome ) == 2
        ||       sscanf( str, "to page %d of %s",     page, tome ) == 2 )
        &&   ( id( tome ) || present( tome ) == this_object() ) )
        ||   ( ( sscanf( str, "to page %s of the %s", t_page, tome )  == 2
        ||       sscanf( str, "to page %s of %s",     t_page, tome )  == 2 )
        &&   ( id( tome ) || present( tome ) == this_object() )
        &&   ( page = cardinal( t_page ) ) > -1 )
        ||   ( sscanf( str, "to page %d%s", page, let ) == 2 && let == "" )
        ||   ( sscanf( str, "to page %s", t_page ) == 1
        &&   ( page = cardinal( t_page ) ) > -1 ) )
        {
                if( page < 0 ){
                        write(
"Page "+page+" is currently on vacation in another dimension.\n"
                        );
                        success = 0;
                }
                else if( page >= booksize ){
                        write(
"The "+book_id()+" does not have that many pages.\n"
                        );
                        say(
TP->QN+" stares at a "+cover_id()+
" with a confused expression on "+TP->PO+" face.\n"
                        );
                        success = 0;
                }
                else if( page == page_number ){
                        write(
"You are already on page "+page+" of the "+book_id()+".\n"
                        );
                        if( !empty() ){
                                say(
TP->QN+" stares at the page of a book very intently.\n"
                                );
                        }
                        else{
                                say(
TP->QN+" stares at the interior of an empty book cover very intently.\n"
                                );
                        }
                        success = 1;
                }
                else if( page_number > 0 ){
                        write(
"You turn to page "+page+" of the "+book_id()+".\n"
                        );
                        say(
TP->QN+" leafs through a "+cover_id()+" and stops suddenly.\n"
                        );
                        page_number = page;
                        success = 1;
                }
                else if( page_number == 0 ){
                        write(
"You open the "+book_id()+" at page "+page+".\n"
                        );
                        say(
TP->QN+" opens a "+cover_id()+", and leafs through it.\n"
                        );
                        lengthen();
                        page_number = page;
                        success = 1;
                }
                return 1;
        }
        success = -1;
        return 0;
}

int view1(string str)              /* verb: look */
{
        if( !str || str == "at" ){
                notify_fail( "Look at what?\n" );
                return 0;
        }
        else if( ( sscanf( str, "at the %s", tome )  == 1
        ||         sscanf( str, "at %s",     tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) )
        {
                write( query_long() );
                if( change() ){
                        write( change() );
                }
                if( page_number ){
                        write( "At the moment it is open.\n" );
                }
                say( TP->QN+" eyes a "+cover_id()+" curiously.\n" );
                return 1;
        }
        else if( str == "at page"
        ||   str == "at this page"
        ||   str == "at current page"
        ||   str == "at the page"
        ||   str == "at the current page"
        ||   ( ( sscanf( str, "at the current page of the %s", tome )  == 1
        ||       sscanf( str, "at current page of the %s",     tome )  == 1
        ||       sscanf( str, "at this page of the %s",        tome )  == 1
        ||       sscanf( str, "at the page of the %s",         tome )  == 1
        ||       sscanf( str, "at page of the %s",             tome )  == 1
        ||       sscanf( str, "at the current page of %s",     tome )  == 1
        ||       sscanf( str, "at current page of %s",         tome )  == 1
        ||       sscanf( str, "at this page of %s",            tome )  == 1
        ||       sscanf( str, "at the page of %s",             tome )  == 1
        ||       sscanf( str, "at page of %s",                 tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                if( page_number == 0 ){
                        write( query_details()[empty()] );
                        say( TP->QN+" scrutinizes the cover of a book.\n" );
                        if( empty() ){
                                say(
"All the pages seem to have been torn out of it.\n"
                                );
                        }
                }
                else if( !contents[page_number] ){
                        write( query_details()[(2*page_number)+1] );
                        say( TP->QN+" fingers the binding of a book.\n" );
                }
                else{
                        write( query_details()[2*page_number] );
                        say( TP->QN+" eyes the page of a book.\n" );
                }
                return 1;
        }
        else if( ( pos = strstr( str, "at " ) ) > -1 ){
                newstr = str[pos+3..];
        }
        else{
                newstr = str;
        }
        leaf( "to " + newstr );
        if( success == 1 ){
                if( page_number == 0 ){
                        write( query_details()[empty()] );
                        say( TP->QN+" inspects the cover of a book.\n" );
                        if( empty() ){
                                say(
"All the pages seem to have been ripped out of it.\n"
                                );
                        }
                }
                else if( !contents[page_number] ){
                        write( query_details()[2*page_number+1] );
                        say(
TP->QN+" fingers the binding of a "+cover_id()+".\n"
                        );
                }
                else{
                        write( query_details()[2*page_number] );
                        if( !empty() ){
                                say(
TP->QN+" eyes the page of a book closely.\n"
                                );
                        }
                        else{
                                say(
TP->QN+" eyes the interior of an empty book cover closely.\n"
                                );
                        }
                }
        }
        if( success != -1 ){
                return 1;
        }
        else{
                return 0;
        }
}

int view2(string str)             /* verb: examine */
{
        if( !str ){
                notify_fail( "Examine? Examine what?\n" );
                return 0;
        }
        else{
                newstr = "at " + str;
        }
        view1( newstr );
        if( success != -1 ){
                return 1;
        }
        else{
                return 0;
        }
}

int locate(string str)     /* verb: search */
{
        if( !str ){
                notify_fail( "Search? Search what?\n" );
                return 0;
        }
        else if( id( str ) || present( str ) == this_object() ){
                write( "Search the "+str+"? What for?\n" );
                say( TP->QN+" eyes a "+cover_id()+" curiously.\n" );
                return 1;
        }
        else if(
        (  sscanf( str, "the %s for %s %s %s", tome, eht, drow, hunted ) == 4
        || sscanf( str, "%s for %s %s %s",     tome, eht, drow, hunted ) == 4 )
        &&  ( ( id( tome ) || present( tome ) == this_object() )
        &&  eht == "the" ) && ( drow == "word" || drow == "words" ) )
        {
                while( strstr( hunted, " " ) == 0 ){
                        hunted = hunted[1..];
                }
                if( drow == "word" && strstr( hunted, " " ) > 0 ){
                        write(
"`"+capitalize( hunted )+"' are several words.\n"
                        );
                        say(
TP->QN+" leafs through a "+cover_id()+" with a slightly stupid expression.\n"
                        );
                        return 1;
                }
                if( drow == "words" && strstr( hunted, " " ) < 1 ){
                        write(
"`"+capitalize( hunted )+"' is only one word.\n"
                        );
                        say(
TP->QN+" leafs through a "+cover_id()+" with a slightly stupid expression.\n"
                        );
                        return 1;
                }
                else{
                        for( i = 0; i < booksize; i++ ){
                                if( contents[i]
                                &&  strstr( contents[i], hunted ) > -1 ){
                                        write(
"You've found "+eht+" "+drow+" `"+hunted+"' \
on page "+i+" of the "+book_id()+".\n"
                                        );
                                        found = 1;
                                }
                        }
                }
                if( found ){
                        say(
TP->QN+" leafs intently through a book, \
and stops suddenly, saying `gotcha'.\n"
                        );
                }
                else{
                        write(
"You close the "+book_id()+" frustratedly. You couldn't find anything.\n"
                        );
                        say(
TP->QN+" leafs intently through a "+cover_id()+",\n"+
"but closes it with a frustrated expression on "+TP->PO+" face.\n"
                        );
                        page_number = 0;
                        shorten();
                }
                found = 0;
                return 1;
        }
        else if( ( sscanf( str, "the %s for %s", tome, hunted )  == 2
        ||         sscanf( str, "%s for %s",     tome, hunted )  == 2 )
        &&   ( id( tome ) || present( tome ) == this_object() ) )
        {
                for( i = 0; i < booksize; i++ ){
                        if( contents[i] && strstr( contents[i], hunted ) > 1 )
                        {
                                write(
"You've found `"+hunted+"' on page "+i+" of the "+book_id()+".\n"
                                );
                                found = 1;
                        }
                }
                if( found ){
                        say(
TP->QN+" leafs intently through a book, \
and stops suddenly, saying `gotcha'.\n"
                        );
                }
                else{
                        write(
"You close the "+book_id()+" frustatedly. You couldn't find anything.\n"
                        );
                        say(
TP->QN+" leafs intently through a "+cover_id()+",\n"+
"but closes it with a frustrated expression on "+TP->PO+" face.\n"
                        );
                        page_number = 0;
                        shorten();
                }
                found = 0;
                return 1;
        }
        return 0;
}

int peruse(string str)           /* verb: read */
{
        if( !str ){
                notify_fail( "Read? Read what?\n" );
                return 0;
        }
        else if( id( str ) || present( str ) == this_object() ){
                write(
"The whole "+book_id()+"? Perhaps you should try it page for page.\n"
                );
                say( TP->QN+" eyes a "+cover_id()+" indecisively.\n" );
                return 1;
        }
        else if( str == "page"
        ||   str == "this page"
        ||   str == "current page"
        ||   str == "the current page"
        ||   ( ( sscanf( str, "the current page of the %s", tome ) == 1
        ||       sscanf( str, "the current page of %s",     tome ) == 1
        ||       sscanf( str, "current page of the %s",     tome ) == 1
        ||       sscanf( str, "current page of %s",         tome ) == 1
        ||       sscanf( str, "this page of the %s",        tome ) == 1
        ||       sscanf( str, "this page of %s",            tome ) == 1
        ||       sscanf( str, "page of the %s",             tome ) == 1
        ||       sscanf( str, "page of %s",                 tome ) == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                output();
                return 1;
        }
        else{
                leaf( "to " + str );
                if( success == 1 ){
                        output();
                }
        }
        if( success == -1 ){
                return 0;
        }
        else{
                return 1;
        }
}

int vandalize(string str)        /* verbs: rip, tear */
{
        if( !str ){
                notify_fail(
capitalize( query_verb() )+"? "+capitalize( query_verb() )+" what?\n"
                );
                return 0;
        }
        else if( ( id( str ) || present( str ) == this_object() )
        ||   ( ( sscanf( str, "the %s into pieces",  tome )  == 1
        ||       sscanf( str, "the %s to pieces",    tome )  == 1
        ||       sscanf( str, "%s into pieces",      tome )  == 1
        ||       sscanf( str, "%s to pieces",        tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                if( empty() ){
                        write( "The "+book_id()+" is too tough for that.\n" );
                        say(
TP->QN+" tries to tear a book cover into pieces, but fails.\n"
                        );
                }
                else{
                        write( "That would require a Harmstorfian effort.\n" );
                        say(
TP->QN+" tries to tear a book into pieces, but fails miserably.\n"
                        );
                }
                return 1;
        }
        else if( str == "out page"
        ||   str == "out this page"
        ||   str == "out current page"
        ||   str == "out the page"
        ||   str == "out the current page"
        ||   ( ( sscanf( str, "the current page out of the %s", tome )  == 1
        ||       sscanf( str, "current page out of the %s",     tome )  == 1
        ||       sscanf( str, "this page out of the %s",        tome )  == 1
        ||       sscanf( str, "the page out of the %s",         tome )  == 1
        ||       sscanf( str, "page out of the %s",             tome )  == 1
        ||       sscanf( str, "the current page out of %s",     tome )  == 1
        ||       sscanf( str, "current page out of %s",         tome )  == 1
        ||       sscanf( str, "this page out of %s",            tome )  == 1
        ||       sscanf( str, "the page out of %s",             tome )  == 1
        ||       sscanf( str, "page out of %s",                 tome )  == 1 )
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                if( empty() ){
                        write(
"Somebody must have been faster than you,\n"+
"each and every page in this book cover has been ripped out.\n"
                        );
                        say(
TP->QN+" fingers a the cover of a book with a disappointed expression.\n"
                        );
                }
                else if( page_number == 0 && !empty() ){
                        write(
"The cover of the "+book_id()+" is too tough for that.\n"
                        );
                        say(
TP->QN+" eyes a book as if "+TP->QP+" was going to rip it into pieces.\n"
                        );
                }
                else if( !contents[page_number] ){
                        write( "This page has been ripped out already.\n" );
                        say( TP->QN+" looks at a book very aggressively.\n" );
                }
                else{
                        tearout();
                }
                return 1;
        }
        else if( ( pos = strstr( str, "out " ) ) > -1 ){
                newstr = str[0..pos-1] + str[pos+4..];
        }
        else{
                newstr = str;
        }
        leaf( "to " + newstr );
        if( success == 1 ){
                if( empty() ){
                        write(
"Somebody must have been faster than you,\n"+
"each and every page in this book cover has been ripped out.\n"
                        );
                        say(
TP->QN+" fingers a the cover of a book with a disappointed expression.\n"
                        );
                }
                else if( page_number == 0 ){
                        write(
"The cover of the "+book_id()+" is too tough for that.\n"
                        );
                        say(
TP->QN+" eyes a book as if "+TP->QP+" was going to rip it into pieces.\n"
                        );
                }
                else if( !contents[page_number] ){
                        write( "This page has been ripped out already.\n" );
                        say( TP->QN+" looks at a book very aggressively.\n" );
                }
                else{
                        tearout();
                }
                return 1;
        }
        if( success != -1 ){
                return 1;
        }
        else{
                return 0;
        }
}

int shut(string str)       /* verb: close */
{
        if( !str ){
                notify_fail( "Close? Close what?\n" );
                return 0;
        }
        else if( ( id( str ) || present( str ) == this_object() )
        ||   ( sscanf( str, "the %s", tome ) == 1
        &&   ( id( tome ) || present( tome ) == this_object() ) ) )
        {
                if( page_number > 0 ){
                        write( "You close the "+book_id()+".\n" );
                        say( TP->QN+" closes a "+cover_id()+".\n" );
                        page_number = 0;
                        shorten();
                }
                else{
                        write( "The "+book_id()+" is already closed.\n" );
                        say( TP->QN+" squeezes a "+cover_id()+".\n" );
                }
                return 1;
        }
        return 0;
}

void pricing()
{
        pcounter = 0;
        for( i = 1; i < booksize; i++ ){
                if( contents[i] ){
                        pcounter++;
                }
        }
        price = query_value();
        if( pcounter ){
                ploss = price / ( 4 * pcounter );
        }
        else{
                ploss = 1;
        }
}

void weighing()
{
        pcounter = 0;
        for( i = 1; i < booksize; i++ ){
                if( contents[i] ){
                        pcounter++;
                }
        }
        maxweight = query_encumbrance();
        if( pcounter ){
                wloss = maxweight / ( 2 * pcounter );
        }
        else{
                wloss = 100;
        }
}

string book_id()
{
        book_name = query_id();
        if( pointerp( book_name ) ){
                return book_name[0];
        }
        else{
                return "book";
        }
}

int cardinal(string str)
{
        num = member(cardinals, str);
        return num;
}

int ordinal(string str)
{
        if (member(ordinals_s, str) > -1 ){
                result = member(ordinals_s, str);
                return result;
        }
        else{
                result = member(ordinals_n, str);
                return result;
        }
}

void turn_page()
{
        lengthen();
        if( page_number == 0 ){
                write( "You open the "+book_id()+".\n" );
                say( TP->QN+" opens a "+cover_id()+".\n" );
        }
        page_number++;
        shorten();
}

void output()
{
        if( !contents[page_number] ){
                write( "\n\
,--,    \n\
| /     \n\
| \\    \n\
| <     \n\
| |     \n\
|  >    \n\
| /     \n\
|/      \n\
|\\     \n\
|/      \n\
|\\     \n\
|<      \n\
| \\    \n\
| /_    \n\
`---'   \n\
\n" );
                say( TP->QN+" scrutinizes the binding of a book.\n" );
        }
        else{
                write( contents[page_number] );
                say( TP->QN+" studies the page of a book.\n" );
        }
}

void tearout()
{
        if( !this_object()->query_protection() ){
                writings = contents[page_number];
                if( writings != 0 ){
                        contents[page_number] = 0;
                }
                weight = query_encumbrance();
                if( weight - wloss > 0 ){
                        item::set_encumbrance( weight - wloss );
                }
                price = query_value();
                if( ( price - ( 2 * ploss ) ) > 0 ){
                        item::set_value( price - ( 2 * ploss ) );
                }
                parchment = clone_object( "complex/page" );
                parchment->set_contents( writings );
                parchment->set_encumbrance( wloss );
                parchment->set_value( ploss );
                transfer( parchment, TP );
                write( "You tear the page out of the "+book_id()+".\n" );
                say( TP->QN+" tears a page out of a book.\n" );
                if( empty() ){
                        set_id( ({ "book cover", "cover" }) );
                        set_short( "Book cover" );
                        set_long(
"The remains of a vandalized book, there is only the cover left.\n"
                        );
                        item::set_value( query_value() / 2 );
                }
        }
        else{
                write(
"You desperately try to tear this page out the "+book_id()+",\n"+
"but it will not budge. Some strange sort of magic, no doubt.\n"
                );
                say(
TP->QN+" tries to tear a page out a book.\n"+
"Curiously not even "+TP->PO+" greatest efforts manage to tear it loose.\n"+
"After "+TP->PO+" face has turned slightly blue,"+TP->QP+" gives up.\n"
                );
        }
        return;
}

int empty() {
        pcounter = 0;
        for( i = 1; i < booksize; i++ ){
                if( contents[i] )
                        pcounter++;
        }
  if (!pcounter)
    return 1;
  return 0;
}

void lengthen()
{
        pos = strstr( query_short(), " (open)" );
        if( page_number ){
                return;
        }
        else if( pos == -1 ){
                set_short( query_short()+" (open)" );
        }
}

void shorten()
{
        pos = strstr( query_short(), " (open)" );
        if( page_number ){
                return;
        }
        else if( pos > -1 ){
                set_short( query_short()[0..pos-1] );
        }
}

string change()
{
        tc = 0;
        mp = booksize - 1;
        for( i = 1; i < booksize; i++ ){
                if( !contents[i] ){
                        tc++;
                }
        }
        ra = ( 4 * tc ) / mp;
        changes = allocate( 5 );
        changes = ({
0,
"A few pages seem to be missing.\n",
"Some of the pages seem to have been ripped out of the "+book_id()+".\n",
"Most of the pages seem to be missing.\n",
"All the pages seem to have been ripped out of it by some brute.\n"
        });
        return changes[ra];
}

int drop(int silently)
{
        if( page_number > 0 ){
                if( !silently ){
                        tell_room( environment( TP ),
"The "+cover_id()+" closes.\n"
                        );
                }
                page_number = 0;
                shorten();
        }
        return 0;
}


/*
** Function()           Effect
**
** set_contents(cont)   enables the book to accept an array of strings which
**                      are its written contents or torn out pages in case of
**                      a 0, furthermore it activates the pricing() and/or
**                      weighing() function, if they have not been activated
**                      earlier, to establish the initial number, weight, and
**                      value of intact pages in the book
** query_contents()     enables the book to ask for the contents set earlier
** set_details(det)     enables the book to accept an array of strings which
**                      contains the individual descriptions of each page in
**                      its intact and in its torn out form
** query_details()      returns the details array and makes it accessible for
**                      the view1/2() functions to give their strings as
**                      descriptions of an individual page, if the optional
**                      details array has not been set, it checks if the
**                      optional looks array has been set, and if not, it
**                      defaults to the generic complexion array given above
** set_looks()          enables the book to accept an array of 4 strings,
**                      which describes the cover on the one hand, and the
**                      pages on the other hand, each once in intact form
**                      and once in its torn out form
** query_looks()        returns the looks array
** set_protection(prot) enables (if 0) or disables (if !0) the tearing of
**                      pages out of the book
** query_protection()   makes it possible to ask the book if the player is
**                      allowed to tear out pages or not
** set_encumbrance(arg) enables the book to accept its encumbrance and
**                      activates the weighing() function to establish the
**                      initial weight and number of non-torn out pages, if
**                      it has not been activated yet
** set_value(arg)       enables the book to accept its value and activates
**                      the pricing() function to establish the initial value
**                      and number of non-torn out pages, if it has not been
**                      activated yet
** init()               enables the activation of the following functions
** open(str)            manages the mechanics of opening the book, if the
**                      book wants to be opened at a specific page, it calls
**                      the leaf() function so that it goes to the correct
**                      page
** leaf(str)            parses the turning of pages, and activates the
**                      turn_page() function. Possible commands include:
**                      next page       previous page   last page
**                      nth page        page n          cover (page)
** view1(str)           manages the mechanics of looking at the current page,
**                      if another page wants to be looked at, it calls the
**                      leaf() function so that it goes to the correct page
**                      and then this function looks at that page
** view2(str)           manages the mechanics of examining the current page,
**                      if another page wants to be examined, it calls the
**                      leaf() function so that it goes to the correct page
**                      and then this function examines that page
** locate(str)          this function allows the player to search the book
**                      for a certain string, and manages the output of
**                      fitting messages
** peruse(str)          manages the mechanics of reading the current page, if
**                      another page wants to be read, it calls the leaf()
**                      function so that it goes to the correct page, and
**                      then this function activates the output() function
** vandalize(str)       manages the mechanics of tearing out the current page,
**                      if another page wants to be torn out, it calls the
**                      leaf() function so that it goes to the correct page
**                      and then this function activates the tearout() function
** shut(str)            manages the closing of the book
** pricing()            checks the initial value of the book and the initial
**                      number of non-torn out pages in the book and defines
**                      the value of an individual page accordingly
** weighing()           checks the initial weight of the book and the initial
**                      number of non-torn out pages in the book and defines
**                      the weight of an individual page accordingly
** book_id()            checks the id array for its 0th member, or otherwise
**                      supplies the generic "book" as a name for this object
** cover_id()           checks if the book is empty and the id array for its
**                      0th member, otherwise it supplies the generic "book"
**                      for the description used for say()'s
** cardinal(str)        checks if a string is a number (one, 2, three, 4, etc.)
** ordinal(str)         checks if a string is a number word (first, 2nd,
**                      third, 4th, etc.)
** turn_page()          manages the mechanics of turning a page in the book
** output()             gives either the picture of a torn out page or the
**                      contents of that page
** tearout()            manages the mechanics of tearing out single pages,
**                      clones the object paper, transfers the contents,
**                      and moves the page into the player's inventory
** empty()              checks the book for intact pages and returns 1 if
**                      none are found
** lengthen()           adds the string " (open)" to the short description
**                      of the book every time it is opened
** shorten()            subtracts the string " (open)" from the short
**                      description of the book every time it is closed
** change()             changes the long description of the book, according
**                      to the number of pages torn out, and whether it is
**                      open or not
** drop(silently)       makes the book close itself, when dropped, sold, or
**                      given away
*/
