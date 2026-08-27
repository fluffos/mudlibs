inherit "/std/room";
#include "path.h"
#include "mail.h"

void setup()
{
   set_short("Daggerford Post Office");
   set_long("This is the Post Office of Daggerford. It's well known for "+
      "its speedy delivery, due to its use of fairies as "+
      "postmen.  Type \"mail\" to enter the mail reader.  There are clerks " +
      "sitting behind the counter. You can't reach them however, due "+
      "to some kind of force-field.\n");
   
   set_light(85);
   add_exit("south", ROOM+"wall18", "door");
   add_exit("west", ROOM+"wall17", "door");
   
   add_item("counter", "A large imposing counter stretching accross the length "+
      "of the room.  It looks like the post office caters for "+
      "more people than use it, you can tell by the way the "+
      "forty tellers behind the counter are avidly watching "+
      "a snail crawl across the counter.\n");
   add_item("snail", "A small common garden snail.  You have no idea how it "+
      "survived long enough in Anhk Morpok to get here.\n");
   add_item("teller", "The tellers are all watching a snail crawl "+
      "across the counter.\n");
   add_item("sign", "A small faded sign above the demons cage.  It has these "+
      "words written on it in an acient script. \"Adventurers "+
      "are called on to gather together the instuments of "+
      "power to sedate a great beast that lives in the land.  "+
      "The weapons need for this battle are an ancient coin, "+
      "a strange fish, anhk river water, a mystical shell, "+
      "the great cauldron, its lid and a clear ladel.  Once "+
      "these items of power have been gathered they must "+
      "be taken to the picnic area outside Ankh-Morpork, "+
      "whereapon the shell must be blown to call forth "+
      "the creatures.\"\n");
}

void init()
{
   ::init();
   add_action("mail", "read");
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
      this_player()->query_cap_name()+"'s mail and it flies through the door.\n");
   if (find_living(to))
      call_out("after_call",5,to);
}

void after_call(string to)
{
   object ob;
   
   ob = find_living(to);
   if (!ob)
      return ;
   if (environment(ob) == this_object())
      say("The fairie returns through the door and gives a note to "+to+
      ".\n", this_player());
   else {
      tell_room(environment(ob), "A fairy flies over to "+to+" says something "+
         "and flies off again.\n", ({ ob }));
      call_out("come_back",5);
   }
   tell_object(ob, "A fairy flies over to you and informs you that "+
      "you've got mail.\n");
}

void come_back()
{
   tell_room(this_object(),"A fairie returns from it's post-round.\n");
}
