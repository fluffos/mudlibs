// room.c - This is the room maker of the object maker.. it's a seperate
// file to make my life easier. -Chronos.
// make_room(filename) is the function that should be called to launch the room maker.

// Here are our global variables that we need to keep through the entire
// program.
string file;            // Stores the filename of what we are writing.
int MORE_CODE;          // Reminder flag that they have more coding to do!
string *exit_data = ({ }) ; // Remembers the exits for th exit_msgs.

// Prototypes.
void Prompt(string prompt, string func) ;
void finish_file();
int check(string str) ;
int Quit() ;

// The check() function checks for any of the quit phrases!
int check(string str) {
  if (!str) {
    write("[OBJMAKER] Error 802 - check() called without argument\n") ;
    return 1;
  }
  switch(str) {
    case "QUIT" :
    case "quit" :
    case "quit!" :
    case "QUIT!" :
    case "q!" :
    case "Q!" :
      return 1;
      break;
    default:
      break;
  }
  return 0 ;
}

// The Prompt() function - Used EXTENSIVELY, so we save code this way.
void Prompt(string prompt, string func) {
  if (!prompt || !func) {
    write("[OBJMAKER] Error 801 - Prompt() called without argument(s)\n") ;
    return 1;
  }
  write(prompt+"\n]");
  input_to(func) ;
  return 1;
}

// This func closes out the working file and returns the user to normal
// gameplay.
int Quit() {
  write("Aborting Object Creation.\n");
  return 1;
}    

// This function is called from the main objmaker inheritable, and SHOULD
// pass a FULL working filename to this function.
int make_room(string filename) {
  if (!filename) {
    write("[OBJMAKER] Error 101 - No filename passed to make_room()\n") ;
    return 1;
  }
  write("[Objmaker v2.0] Creating room file - \""+filename+"\" ...\n");
  write("                Type quit at any prompt to stop file creation.\n");
  file = filename ; // Now we know where we are writing.
  if (TPN == "Chronos") write_file(file, "// Coded by Chronos.\n") ;
  else write_file(file, "// Coded by "+TPN+
    " using Object Maker v2.0 by Chronos.\n");
  write_file(file, @ENDFILE
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
ENDFILE
  ) ;
  write_file(file, "  set(\"author\", \""+TP->query("name")+"\");\n") ;
  Prompt("Enter the light level of the room.", "enter_light") ;
  return 1;
}

int enter_light(string str) {
  if (!str) {
    Prompt("Enter the light level of the room.", "enter_light") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you for the light level of the room
	you are creating.  A normal room in the mud has a light
	level of 1.  A light level of 0 would be a dark room.
	It is possible to have light levels greater than or less
	than the standard levels.. It just makes the room require
	more light/darkness sources to make the room darkened or
	lightened.  Example" 3 torches would be required to make a
	room with a light level of -2 be lit enough to see.
ENDHELP
    );
    Prompt("Enter the light level of the room.", "enter_light") ;
    return 1;
  }
  write_file(file, "  set(\"light\", "+ str + ") ;\n") ;
  write("Light level set to: "+str+".\n\n") ;
  Prompt("Enter the short description for the room.", "enter_short") ;
  return 1;
}

int enter_short(string str) {
  if (!str) {
    Prompt("Enter the short description for the room.", "enter_short") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you for the short description of the
	room you are creating.  No carriage returns are necessary,
	simply put something like "An Ordinary Room."

ENDHELP
    );
    Prompt("Enter the short description for the room.", "enter_short") ;
    return 1;
  }
  write_file(file, "  set(\"short\", \""+capitalize(str)+"\");\n") ;
  write("Short description set to: "+capitalize(str)+"\n\n") ;
  write(@ENDHELP
You are now going to enter the long description for the room.
You will enter each line as it will appear in the long description.
When you are done entering a description, enter "END" or "***".

ENDHELP
  );
  write_file(file, "  set(\"long\", @ENDLONG\n") ;
  Prompt("Enter the long description for the room.", "long_loop") ;
  return 1;
}

int long_loop(string str) {
  if (!str) {
    Prompt("Continue entering the long description.", "long_loop") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is simply writing your long description line
	by line.  When you are done, enter "END" or "***".

ENDHELP
    );
    Prompt("Continue entering the long description.", "long_loop") ;
    return 1;
  }
  if (str=="***" || str == "END") {  // Time to close out the descript.
    write_file(file, "ENDLONG\n  );\n") ;
    Prompt("Will this room have item descriptions? [Y/n]", "item_desc") ;
    return 1;
  }
  write_file(file, str+"\n") ;  // Write it..
  Prompt("", "long_loop") ;     // And loop it..
  return 1;
}

int item_desc(string str) {
  if (!str) {
    Prompt("Will this room have item descriptions? [Y/n]", "item_desc") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include item descriptions
	in the room you are creating.  Item descriptions are anything in the room
	that users can "examine" without actually existing.  They are things like
	objects in the environment that cannot be manipulated or perhaps things to
	be read, like signs.

ENDHELP
    );
    Prompt("Will this room have item descriptions? [Y/n]", "item_desc") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"item_desc\", ([\n");
	Prompt("Enter the first item to be described.", "item1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	Prompt("Will this room have item functions? [Y/n]", "item_func") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have item descriptions? [Y/n]", "item_desc") ;
	break ;
  }
  return 1;
}

int item1(string str) {
  if (!str) {
    Prompt("Enter the item to be described.", "item1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt requires the name of the item to be described.  This is
	the word that the players must "exa" to get your item description.
	You may have to define more than one item decription for an item if
	there are many ways to reference it.

ENDHELP
    );
    Prompt("Enter the item to be described.", "item1") ;
    return 1;
  }
  write_file(file, "    \""+str+"\" : ");
  Prompt("Enter the description for \""+str+"\".", "item_2") ;
  return 1;
}

int item_2(string str) {
  if (!str) {
    Prompt("Enter the description for the item.", "item_2") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt wants the description of the item defined in the previous
	prompt.

ENDHELP
    );
    Prompt("Enter the description for the item.", "item_2") ;
    return 1;
  }
  write_file(file, "\""+str+"\",\n");
  Prompt("Another item description? [Y/n]", "item_loop");
  return 1;
}

int item_loop(string str) {
  if (!str) {
    Prompt("Another item description? [Y/n]", "item_loop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include more item
	descriptions in this room you are creating.  If you are done making
	item descriptions, enter "n" for no.

ENDHELP
    );
    Prompt("Another item description? [Y/n]", "item_loop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the item to be described.", "item1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	Prompt("Will this room have item functions? [Y/n]", "item_func") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Another item description? [Y/n]", "item_loop");
	break ;
  }
  return 1;
}

int item_func(string str) {
  if (!str) {
    Prompt("Will this room have item functions? [Y/n]", "item_func") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include item functions
	in the room you are creating.  Item functions are anything in the room
	that triggers a function simply by being examined.  For instance, if you
	had a statue in a room's description, you could make the statue seem to
	come to life when examined by using an item function.. You could have
	the function clone a statue into the room and send out a message to the
	room that the statue seemed to come alive.  There are infinite uses for
	item functions.

ENDHELP
    );
    Prompt("Will this room have item functions? [Y/n]", "item_func") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"item_func\", ([\n");
	MORE_CODE = 1;
	Prompt("Enter the first item to have a function attached to it.", "itemfunc1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	Prompt("Will this room have search descriptions? [Y/n]", "search_desc") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have item functions? [Y/n]", "item_func") ;
	break ;
  }
  return 1;
}

int itemfunc1(string str) {
  if (!str) {
    Prompt("Enter the item to be the trigger for the function.", "itemfunc1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt requires the name of the item to be described.  This is
	the word that the players must "exa" to make the function execute.
	You may have to define more than one item decription for an item if
	there are many ways to reference it.

ENDHELP
    );
    Prompt("Enter the item to be the trigger for the function.", "itemfunc1") ;
    return 1;
  }
  write_file(file, "    \""+str+"\" : ");
  Prompt("Enter the name of the function to be associated with \""+str+"\".", "itemfunc2");
  return 1;
}

int itemfunc2(string str) {
  if (!str) {
    Prompt("Enter the name of the function to be associated with the item.", "itemfunc2") ;   
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt wants the name of function to be called when the item is examined.

ENDHELP
    );
    Prompt("Enter the name of the function to be associated with the item.", "itemfunc2") ;   
    return 1;
  }
  write_file(file, "\""+str+"\",\n");
  Prompt("Another item function? [Y/n]", "itemfunc_loop");
  return 1;
}

int itemfunc_loop(string str) {
  if (!str) {
    Prompt("Another item function? [Y/n]", "itemfunc_loop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include more item
	functions in this room you are creating.  If you are done making
	item functions, enter "n" for no.

ENDHELP
    );
    Prompt("Another item function? [Y/n]", "itemfunc_loop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the item to trigger the function.", "itemfunc1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	Prompt("Will this room have search descriptions? [Y/n]", "search_desc") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Another item function? [Y/n]", "itemfunc_loop") ;
	break ;
  }
  return 1;
}

int search_desc(string str) {
  if (!str) {
    Prompt("Will this room have search descriptions? [Y/n]", "search_desc") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include search descriptions
	in the room you are creating.  Search descriptions are anything in the room
	that users can "search" without actually existing.  They are things like
	objects in the environment that cannot be manipulated or perhaps things to
	be searched, like desks or whatever.

	Search descriptions are generally used to reward players for taking the time
	to search through an area.  A default search message ("You search, but find
	nothing of interest.") is given for every item description in a room, so you
	don't have to define searches that reveal nothing.

ENDHELP
    );
    Prompt("Will this room have search descriptions? [Y/n]", "search_desc") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"search_desc\", ([\n");
	Prompt("Enter the first search word to be described.", "search1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	Prompt("Will this room have search functions? [Y/n]", "search_func") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have search descriptions? [Y/n]", "search_desc") ;
	break ;
  }
  return 1;
}

int search1(string str) {
  if (!str) {
    Prompt("Enter the search word to be described.", "search1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking for a word that can be searched in a room to provide
	additional information or whatever to the player.

ENDHELP
    );
    Prompt("Enter the search word to be described.", "search1") ;
    return 1;
  }
  write_file(file, "    \""+str+"\" : ");
  Prompt("Enter the description for \""+str+"\".", "search2") ;
  return 1;
}

int search2(string str) {
  if (!str) {
    Prompt("Enter the description for the search.", "search2") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt wants the description of the search defined in the previous
	prompt.

ENDHELP
    );
    Prompt("Enter the description for the search.", "search2") ;
    return 1;
  }
  write_file(file, "\""+str+"\",\n");
  Prompt("Another search description? [Y/n]", "search_loop");
  return 1;
}

int search_loop(string str) {
  if (!str) {
    Prompt("Another search description? [Y/n]", "search_loop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include more search
	descriptions in this room you are creating.  If you are done making
	search descriptions, enter "n" for no.

ENDHELP
    );
    Prompt("Another search description? [Y/n]", "search_loop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the search word to be described.", "search1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	Prompt("Will this room have search functions? [Y/n]", "search_func") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Another search description? [Y/n]", "search_loop");
	break ;
  }
  return 1;
}

int search_func(string str) {
  if (!str) {
    Prompt("Will this room have search functions? [Y/n]", "search_func") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include search functions
	in the room you are creating.  Search functions are anything in the room
	that triggers a function by being search.  The most common use of search
	functions is to give an object to a player by allowing them to search for
	it and discover it.. this is a great way to reward players for being
	inquisitive..

ENDHELP
    );
    Prompt("Will this room have search functions? [Y/n]", "search_func") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"search_func\", ([\n");
	MORE_CODE = 1;
	Prompt("Enter the first search word to have a function attached to it.", "searchfunc1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
      Prompt("Will this room have exits? [Y/n]", "exits") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have search functions? [Y/n]", "search_func") ;
	break ;
  }
  return 1;
}

int searchfunc1(string str) {
  if (!str) {
    Prompt("Enter the search word to be the trigger for the function.", "searchfunc1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt requires the name of the search to be described.  This is
	the word that the players must "search" to make the function execute.
	You may have to define more than one search decription for an search if
	there are many ways to reference it.

ENDHELP
    );
    Prompt("Enter the search word to be the trigger for the function.", "searchfunc1") ;
    return 1;
  }
  write_file(file, "    \""+str+"\" : ");
  Prompt("Enter the name of the function to be associated with \""+str+"\".", "searchfunc2");
  return 1;
}

int searchfunc2(string str) {
  if (!str) {
    Prompt("Enter the name of the function to be associated with the search.", "searchfunc2") ;   
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt wants the name of function to be called when the search is executed.

ENDHELP
    );
    Prompt("Enter the name of the function to be associated with the search.", "searchfunc2") ;   
    return 1;
  }
  write_file(file, "\""+str+"\",\n");
  Prompt("Another search function? [Y/n]", "searchfunc_loop");
  return 1;
}

int searchfunc_loop(string str) {
  if (!str) {
    Prompt("Another search function? [Y/n]", "searchfunc_loop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to include more search
	functions in this room you are creating.  If you are done making
	search functions, enter "n" for no.

ENDHELP
    );
    Prompt("Another search function? [Y/n]", "searchfunc_loop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the search to trigger the function.", "searchfunc1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	Prompt("Will this room have exits? [Y/n]", "exits") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Another search function? [Y/n]", "searchfunc_loop") ;
	break ;
  }
  return 1;
}

int exits(string str) {
  if (!str) {
    Prompt("Will this room have exits? [Y/n]", "exits") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to add exits to your room.

ENDHELP
    );
    Prompt("Will this room have exits? [Y/n]", "exits") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"exits\", ([\n");
	Prompt("Enter the first direction for an exit.", "exit1");
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	Prompt("Are there going to be any objects loaded into the room? [Y/n]","objects") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have exits? [Y/n]", "exits") ;
	break ;
  }
  return 1;
}

int exit1(string str) {
  if (!str) {
    Prompt("Enter the exit direction.", "exit1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking for the direction of the exit being defined.

ENDHELP
    );
    Prompt("Enter the exit direction.", "exit1") ;
    return 1;
  }
  write_file(file, "    \""+str+"\" : ");
  exit_data += ({ str }) ;
  Prompt("Enter the filename of the destination [\"'s are not included!].", "exit2") ;
  return 1;
}

int exit2(string str) {
  if (!str) {
    Prompt("Enter the filename of the destination. [\"'s are not included!]", "exit2") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt requires the filename of the destination of the exit
	being defined.  It does not include the "'s around the exit, as
	it is encouraged to use #define's for pathnames on this mud.
	If you don't understand coding portably, please reference the
	document in the /doc directory called coding_portably.

ENDHELP
    );
    Prompt("Enter the filename of the destination. [\"'s are not included!]", "exit2") ;
    return 1;
  }
  write_file(file, ""+str+",\n");
  Prompt("Add another exit? [Y/n]", "exit_loop");
  return 1;
}

int exit_loop(string str) {
  if (!str) {
    Prompt("Add another exit? [Y/n]", "exit_loop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to add another exit to
	the room you are creating.  If you are done adding exits, simply type
	"n".

ENDHELP
    );
    Prompt("Add another exit? [Y/n]", "exit_loop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the direction of the exit.", "exit1") ;
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	Prompt("Do you want to add any special exit messages? [Y/n]", "exitmsg") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Add another exit? [Y/n]", "exit_loop");
	break ;
  }
  return 1;
}

int exitmsg(string str) {
  if (!str) {
    Prompt("Will this room have special exit msgs? [Y/n]", "exitmsg") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you if you would like to add special exit msgs to
	any of the exits in the room.

ENDHELP
    );
    Prompt("Will this room have special exit msgs? [Y/n]", "exitmsg") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	write_file(file, "  set(\"exit_msg\", ([\n");
	write(@ENDWORK
=------------------------------------------------------------------------------------=
   You are going to be prompted with each of the room's defined exits in the order
 in which they appear in the file.  If you do not wish to add a exit message for that
   exit, simply press enter and pass it up.  Don't forget to use $N in place of the
		   name of the person who is leaving the room.
=------------------------------------------------------------------------------------=
ENDWORK
	);
	write("Direction: "+exit_data[0]+".\n]");
	input_to("emsg",0) ; 
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	Prompt("Are there going to be any objects loaded into the room? [Y/n]", "objects") ;
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Will this room have exits? [Y/n]", "exits") ;
	break ;
  }
  return 1;
}

// Remember that if you hit return, it skips that direction and goes to the next one.

int emsg(string str, int x) {
  if (str) write_file(file, "\""+str+"\",\n");
  x++;
  if (x>sizeof(exit_data)) {
    Prompt("Are there going to be any objects loaded into the room? [Y/n]", "objects") ;
    return 1;
  }
  write("Direction: "+exit_data[x]+".\n]");
  input_to("emsg",x) ;
  return 1;
}

int objects(string str) {
  if (!str) {
    Prompt("Are there going to be any objects loaded into the room? [Y/n]", "objects") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is simply asking you if you are going to be adding objects
	into the room via the objects property.  Remember that even monsters can
	be loaded into a room through the objects property.

ENDHELP
    );
    Prompt("Are there going to be any objects loaded into the room? [Y/n]", "objects") ;
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter an id of the first object to be loaded.", "obj1") ;
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	finish_file();
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Add another exit? [Y/n]", "exit_loop");
	break ;
  }
  return 1;
}

int obj1(string str) {
  if (!str) {
    Prompt("Enter the id of the object to be loaded.", "obj1") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you for an id of the object you are trying to
	load into the room.

ENDHELP
    );
    Prompt("Enter the id of the object to be loaded.", "obj1") ;
    return 1;
  }
  write_file(file, "  \""+str+"\" : ");
  Prompt("Enter the filename of the object.", "obj2") ;
  return 1;
}

int obj2(string str) {
  if (!str) {
    Prompt("Enter the filename of the object.", "obj2") ;
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is asking you for the filename of the object you want
	to load into the room.

ENDHELP
    );
    Prompt("Enter the filename of the object.", "obj2");
    return 1;
  }
  write_file(file, "\""+str+"\",\n");
  Prompt("Add another object to the room? [Y/n]", "objloop");
  return 1;
}

int objloop(string str) {
  if (!str) {
    Prompt("Add another object to the room? [Y/n]", "objloop");
    return 1;
  }
  if (check(str)) return Quit();
  if (str=="help" || str=="?" || str=="HELP") {
    write(@ENDHELP

	This prompt is simply asking you if you will be adding any more objects
	to your room.  If you are finished, simply type "n".

ENDHELP
    );
    Prompt("Add another object to the room? [Y/n]", "objloop");
    return 1;
  }  
  switch(str) {
    case "y" : case "Y":  case "yes":  case "YES":
	Prompt("Enter the id of the object to be loaded.", "obj1") ;
	break ;
    case "n" : case "N":  case "no" :  case "NO":
	write_file(file, "  ]) ) ;\n");
	finish_file();
	break ;
    default: 
	write("! Valid responses to this prompt are: y, yes, n, no, ?, help, quit, and q!\n");
	Prompt("Add another object to the room? [Y/n]", "objloop") ;
	break ;
  }
  return 1;
}

void finish_file() {
  write("[Objmaker] Finishing the file...");
  write_file(file, "  ::create();\n  reset();\n}\n") ;
  write("Done.\n");
  if (MORE_CODE) write(" ** Remember - you still have more code to finish before this room is complete.\n");
  TP->command("update "+file);
  return ;
}
