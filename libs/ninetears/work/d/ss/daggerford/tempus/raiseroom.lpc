/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup()
  {
  set_short("Raiseroom");
  set_save_file(ROOM +"collect");
    set_helper_name("Gilla");
set_long("You have entered a sparsely decorated room.  In fact, the"+
  " decor is very functional, with the exception of a small shrine to Tempus"+
	" in the corner.  A number of examination cots are arranged"+
	" in an orderly manner around the room.  Several serious"+
	" looking healers move about"+
	" the room, looking after their patients.  \n"+
	"A sign hangs on the wall.  \n");
  set_percentage(100);
  set_light(60);

add_item("shrine", "A small altar to Tempus sits in the corner.  There"+
	" are several lit candles around the shrine, but it"+
	" really doesn't attract your attention when you first"+
	" enter the room. \n");
add_item(({"cot", "cots"}), "Uncomfortable looking wooden tables where the"+
	" bodies are placed for examination and treatment. \n");
add_item(({"healer", "healers"}), "Stern looking individuals who spend their"+
	" days raising people from the dead.  They move about the"+
	" room, their movements fluid and purposeful.  They are busy"+
	" people, and don't look like they smile often. \n");
  add_sign("/---------------------------------------------\\\n" +
           "|                                             |\n" +
           "|          Tempus raising service.            |\n" +
           "|                                             |\n" +
           "|  You need an account here so we can charge  |\n" +
           "|  you for the raise.                         |\n" +
           "|                                             |\n" +
           "|  Use 'open' to open an account.             |\n" +
           "|                                             |\n" +
           "|  'deposit' to deposit money.                |\n" +
           "|                                             |\n" +
           "|  'balance' to see how much we have saved    |\n" +
           "|  for you.                                   |\n" +
           "|                                             |\n" +
           "|  'raise me' when you need a raise.          |\n" +
           "|  'raise <ghost>' when you shall use your    |\n" +
           "|  account to pay for someones raise.         |\n" +
           "|                                             |\n" +
           "|  A raise costs 1 platinum coin for each     |\n" +
           "|  of your experience level.                  |\n" +
           "|                                             |\n" +
           "|                                             |\n" +
           "\\---------------------------------------------/\n" );

  add_exit("west", ROOM + "tempusbb", "door");
}

void reset()
  {
  if (!helper)
    {
    helper = clone_object(CHAR + "gilla");
    helper->move(this_object());
    }
} /* void reset */ 

void dest_me()
  {
  if (helper)
    helper->dest_me();
} /* void dest me */
