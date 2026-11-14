// made by magictcs - 12 jun 1997
// part of the library of inner city

// clone the object in the library (or somewhere else)
// call following functions: (for example for the voodoo doll file)
// ob->SetThemeShort("doll")
// ob->SetThemeLong("How to make a voodoo doll")
// ob->SetFile("/d/beyond/doc/player/vdoll.txt")

#include <properties.h>
#include <sykorath.h>

inherit "/std/thing";
inherit "/lib/string";

string file;                // contains the filename to be read
string theme_short;         // contains a short description of the contents
string theme_long;          // contains a longer description of the contents

//******************
// property handling
//******************
string SetFile(string filename) { file=filename; return file; }
string QueryFile() { return file; }
string SetThemeShort(string s) { theme_short=s; return theme_short; }
string QueryThemeShort() { return theme_short ; }
string SetThemeLong(string l) { theme_long=l; return theme_long; }
string QueryThemeLong() { return theme_long; }

//************
// read scroll
//************
// used by readscroll (smore)
void close_scroll() {
  if (TP) {
    show(NAME+" closes the scroll.\n");
    write("You close the scroll.\n");
  }
}

// tricky for using the smore function
string readscroll() {
  string ret;
  ret="You open the scroll.\n"
      "You read the scroll.\n";
  ret+=read_file(file,1);
  smore(ret,TP->QueryPageSize(),TO,"close_scroll");
  return "\n";         // needed for the SetReadMsg :(
}

//******************************
// short and long are overloaded
//******************************
string QueryLong() {
  return
  "The scroll contains information about:\n"
  "-> "+theme_long+" <-.\n"
  "You can read it.\n";
}

string QueryShort() {
  return "a scroll of "+add_a(theme_short);
}

//*******
// create
//*******
create() {
  ::create();
  theme_short="";
  theme_long="";
  file="";
  AddId(({"scroll","libscroll"}));
  SetWeight(20);
  SetValue(5);
  SetReadMsg(#'readscroll);
}

