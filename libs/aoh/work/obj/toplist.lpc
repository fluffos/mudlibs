/* The list of top players, new version by Rover */
/* [Softbyte] 11aug98: Imrpoved calls to TOPLIST_D */
#include <properties.h>
#include <daemons.h>

inherit "std/thing";

string GetAgeData()
{
string file;
  file=TOPLIST_D->QueryAgeFile();
  if (!file) return 0;
  return read_file(file);
}
string GetQPData()
{
string file;

 file=TOPLIST_D->QueryQPFile();
  if (!file) return 0;
  return read_file(file);
}

varargs void create() {
  ::create();
  SetShort("a list of the top players");
  SetLong(
          "It has two parts: The " MUDNAME " Hall of Fame, and the List of Veterans.\n\n"
          "read toplist  :- Hall of Fame\n"
          "read veterans :- List of Veterans\n"
          );
  SetHelpMsg(QueryLong());
  AddId("list");
  AddId("toplist");
  AddAdjective("top");
  AddAdjective("player");
  SetWeight(10);
  SetValue(5);
}

void init() { ::init(); add_action("read", "read"); }

int read(string str) {
  switch (str) {
    case "list" :
     write("Which part of the list you mean - the toplist or the veterans?\n");
      return 1;
    case "toplist" : {
     write(GetQPData()
            ||"The list is empty at the moment.\n");
      say(this_player()->QueryName() + " reads the top list.\n");
      return 1;
    }
    case "veterans" : {
     write(GetAgeData()
            ||"The list is empty at the moment.\n");
      say(this_player()->QueryName() + " reads the list of veterans.\n");
      return 1;
    }
  }
  return 0;
}
