// room.c - This is the room maker of the object maker.. it's a seperate
// file to make my life easier. -Chronos.


// Here are our global variables that we need to keep through the entire
// program.
string file;

// Prototypes.
void Prompt(string prompt, string func) ;
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
  file = filename ; // Now we know where we are writing.

// Time to add our comments on top.
  if (TPN == "Chronos") write_file(file, "// Coded by Chronos.\n") ;
  else write_file(file, "// Coded by "+TPN+
    " using Object Maker v2.0 by Chronos.\n");
  write_file(file, @ENDFILE
#include <mudlib.h>

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

// Note to self: Begin entering item_descriptions here.
int item_desc(string str) {   // This is a Yes or No question...
