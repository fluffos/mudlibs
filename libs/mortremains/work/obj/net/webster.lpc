// file:   obj/webster.c
// author: Truilkan@Basis
// date:   1992/10/29
// mudlib: Basis

// if you choose to use this code in your mud, please retain the above
// header.  if you write a help screen for this object, please give credit
// to the original authors (Truilkan and Jacques)

// This object obeys part of the RFC for dictionary lookups.  It provides
// an LPC object frontend (in the form of a dictionary object) to an online
// dictionary server.

// todo: parse the first line returned in order to be smart about
// interpreting results of a query (successful, failed, etc).

// Truilkan brought a copy over to the MudOS 0.9 mudlib development site,
// and converted it to our mudlib.
// Mobydick added the help call, 11-9-92

#include <mudlib.h>
#include <net/socket.h>
inherit OBJECT;

#define DISCONNECTED "a dictionary (closed)"
#define CONNECTED "a dictionary (open)"

// webster.cs.indiana.edu
//#define WEBSTER_SERVER "129.79.254.195"
// webster.acc.virginia.edu
#define WEBSTER_SERVER "128.143.22.17"

inherit "/std/socket/telnet";

void
create()
{
   telnet::create();
   set("id", ({"dictionary", "book", "webster"}) );
   set("short", DISCONNECTED);
   set("long", "Its a fine dictionary with faded gold embossing.\n"
   + "You could probably do all manner of things with it such as defining,\n"
   + "completing, and spelling words.\n");
   set_verbosity(0);
}

void
handler(string event)
{
   switch (event) {
      case "open" :
      set("short", CONNECTED);
      tell_object(environment(this_object()),
         "The dictionary creaks open.\n");
      break;
      case "close" :
      tell_object(environment(this_object()),
         "The dictionary slams shut!\n");
      set("short", DISCONNECTED);
      break;
      default:
      break;
   }
}

int
dlookup(string arg)
{
   int result;

   if (!query_connected()) {
      notify_fail("The dictionary isn't open!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " looks up a word.\n");
   telnet::send("DEFINE " + arg + "\n");
   return 1;
}

int
dopen(string arg)
{
   if (query_connected()) {
      notify_fail("It's already open!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " opens "
      + possessive(this_player()->query("gender")) + " dictionary.\n");
    return telnet::connect( (( arg = this_player()->query_env("WEBSTER") )
	  ? arg : WEBSTER_SERVER ) + " 2627");
}

int
dclose(string arg)
{
   if (!query_connected()) {
      notify_fail("It's already closed!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " closes "
      + possessive(this_player()->query("gender")) + " dictionary.\n");
   return telnet::disconnect(arg);
}

int
dskim(string arg)
{
   int result;

   if (!query_connected()) {
      notify_fail("The dictionary isn't open!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " skims the dictionary.\n");
   telnet::send("ENDINGS " + arg + "\n");
   return 1;
}

int
dspell(string arg)
{
   int result;

   if (!query_connected()) {
      notify_fail("The dictionary isn't open!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " searches for a word.\n");
   telnet::send("SPELL " + arg + "\n");
   return 1;
}

int
dcomplete(string arg)
{
   int result;

   if (!query_connected()) {
      notify_fail("The dictionary isn't open!\n");
      return 0;
   }
   say((string)this_player()->query("cap_name") + " searches for a word.\n");
   telnet::send("COMPLETE " + arg + "\n");
   return 1;
}

void
init()
{
   add_action("dlookup", "define");
   add_action("dskim", "endings");
   add_action("dopen", "open");
   add_action("dclose", "close");
   add_action("dspell", "spell");
   add_action("dcomplete", "complete");
   add_action ("help", "help") ;
}

int help (string str) {
	if (str!="dictionary" && str != "webster" && str !="book") return 0 ;
	write (
"The dictionary will let you look up words, get the spellings correct, and\n"+
"find their meanings. Handy commands are:\n\n"+
"   open book : Connect the dictionary to the word server.\n"+
"   close book : Close the connection.\n"+
"   spell <word> : If the word is spelled correctly, the dictionary returns\n"+
"	'SPELLING 1'. If the word is not found, a list of similar words is\n"+
"       printed, hopefully including the correct spelling of the word you\n"+
"	want.\n"+
"   define <word> : Give the definition of the word.\n"+
"   endings <part of word> : Give a list of words that begin with a part\n"+
"	of a word. For example, if you weren't sure if the word 'potato'\n"+
"	had an 'e' on the end, you could type 'endings potat' and get a\n"+
"	list of all words beginning with 'potat'.\n"+
"\nDictionary by Truilkan@Portals and Jacques@Portals.\n") ;
	return 1 ;
}
