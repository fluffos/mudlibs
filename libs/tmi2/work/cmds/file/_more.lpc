/*
// The new more command.
// Much more efficient, we hope.
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_more(string str) {
   seteuid( geteuid( this_player() ) );
  return (int)this_player()->more(str);
  seteuid( getuid() ); // This line isn't reached?
}

string help() {
	return (
"Usage: more <filename>\n\n"+
"The more command prints files to the screen in 20-line chunks. Between\n"+
"each 20-line segment, the \"More-\" prompt appears. The following commands\n"+
"can be issued at that prompt:\n\n"+
"space: show current 20 lines again\n"+
"return: show the next 20 lines\n"+
"u: back up 20 lines\n"+
"b: back up 20 lines\n"+
"d: go down 20 lines\n"+
"b #: go back # lines\n"+
"d #: go down # lines\n"+
"#: go to absolute line #\n"+
"q: Escape from the file\n"+
"/str: Go to the next occurence of <str> in the file\n"+
"?: display help\n"+
"!cmd: Execute <cmd> as if typed at the game prompt\n"+
"m#        : set a 'mark' at this point.\n"+
"g#        : return to a previously defined mark.\n"+
"p#        : set page length.\n"+
"e<file>   : more <file>.\n") ;
}
