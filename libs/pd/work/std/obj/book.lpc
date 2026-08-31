#include <std.h>
#include <save.h>
#include <security.h>

inherit OBJECT;

string *pkers;

void create()
{
 ::create();
 set_name("book");
 set_short("The book of the dead");
 set_long("The book holds the names of everybody that has signed "
          "it. If you have signed the book you are eligible to pk "
          "and to be pked. You can also remove your name from the book "
          "but it will cost you your life.");
 set_id( ({ "book", "pk book" }) );
 set_prevent_get("The book slips out of your hands.");
 set_mass(1);
 set_value(1);
 seteuid( UID_DAEMONSAVE );
 restore_object(SAVE_BOOK_LIST);
 seteuid( getuid() );

 if (!pkers) pkers = ({});
}

void init()
{
 ::init();
 add_action("fsign", "sign");
 add_action("fremove", "remove");
}

int fsign(string str)
{
 if (!str || str == "") return notify_fail("Sign what?\n");
 if (this_player()->query_forced()) return notify_fail("You are being forced against your will.\n");
 if (member_array(this_player()->query_name(), pkers)!=-1) 
   return notify_fail("You already signed the book.\n");
 
 pkers += ({ this_player()->query_name() });
 seteuid( UID_DAEMONSAVE );
 save_object(SAVE_BOOK_LIST);
 seteuid( getuid() );
 write("Your name has been added to the book of the dead.");
 return 1;
}

int fremove(string str)
{
 if (!str || str == "") return notify_fail("Remove what?\n");
 if (this_player()->query_forced()) return notify_fail("You are being forced to remove your name.\n");
 
 if (member_array(this_player()->query_name(), pkers)==-1)
   return notify_fail("Your name is not in the book.\n");

 pkers -= ({ this_player()->query_name() });
 seteuid(UID_DAEMONSAVE);
 save_object( SAVE_BOOK_LIST );
 seteuid( getuid() );
 write("Ok. You have been removed from the book.");
 write("The book glows bright yellow and shoots a wave of energy at you.");
 this_player()->die();
 return 1;
}

int in_book(string name) { if (member_array(name, pkers)!=-1) return 1; 
                                                             else return 0;
                         }

