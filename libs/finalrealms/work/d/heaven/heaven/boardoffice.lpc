/* Scribblers office.
 * Scribbler is Baldricks official writer. Usually taken care of by an NPC
 * but when Baldrick needs something written, he is a PC controlled by Baldrick.
 */

inherit "/std/room";
#include "mail.h"
object board;

void setup()
  {
  set_light(60);
  set_short("Scribblers office.");
  set_long("This is a little, scarse equipped office. Everything is done in " +
        "grey, both the chair, desk and the bed which Scribbler "+
           "sleeps in when he is not writing letters and messages for " +
           "Baldrick.\n");
  add_item("desk", "It's a simple made grey desk.");
  add_item("chair", "It's a simple made grey chair.");
  add_item("bed", "It's a simple made grey bed.");
  add_exit("baldrick", "/w/baldrick/workroom" , "door");
} /* setup */

void reset()
  {
  if (!board)
    {
    board = new("/obj/misc/board_mas3");
    board->move(this_object());
    }
} /* reset */

void init()
{
   ::init();
   add_action("mail", "mail");
}

int mail(string str)
{
object ob;

ob = clone_object("/obj/handlers/post");
ob->move(this_player());
ob->start_mail(str);
   return 1;
}

void send_message(string to)
{
   write("One of the tellers instructs a fairy, and it flies off with "+
      "your mail.\n");
   say("One off the tellers instructs a fairy to deliver "+
      this_player()->query_cap_name()+"'s mail and it flies through the
door.\n");
   if (find_living(to))
      call_out("after_call",5,to);
}

void dest_me()
  {
  if (board)
    board->dest_me();
  ::dest_me();
} /* dest me */
