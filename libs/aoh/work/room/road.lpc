/* The road for to add homes */

#include <moving.h>
inherit "/std/room";

string AddLong();

mixed *homes;

varargs void create()
{
  string *dummy;
  int     i;

  ::create();
  homes = ({});
/*
  if(file_size(object_name() + ".rc") != -1)
*/
  if(file_size(object_name() + ".rc") > 0)
    for(i = sizeof(dummy = explode(read_file(object_name() + ".rc"),"\n")-({""}));
        i--; ) {
      homes += ({explode(dummy[i]," ")});
      AddExit(homes[<1][0],homes[<1][1]);
    }
}

varargs string IntLong(mixed arg)
{
  string the_long;

  return ::IntLong(arg) + AddLong();
}

int AddHome(string exit, string path, string owner)
{
  object *inv;
  int     i;

  if(QueryExitsDest()[exit]) return 0;
  write_file(object_name() + ".rc",exit + " " + path + " " + owner + "\n");
  AddExit(exit,path);
  if(!homes) homes = ({({exit,path,owner})});
  else homes += ({({exit,path,owner})});
  for(i = sizeof(inv = all_inventory()); i--; )
    if(living(inv[i])) inv[i]->move(this_object(),M_SILENT);
  tell_room(this_object(),"To the " + exit + " the home of " +
    capitalize(owner) + " has opened.\n");
  return 1;
}

string AddLong()
{
  int    i;
  string out;

  out = "";
  for(i = sizeof(homes); i--; ) {
    switch (i) {
    case 0:
      out += "To the " + homes[i][0] + " the house of " +
        capitalize(homes[i][2]) + " can be found.\n";
      break;
    case 1:
      out += "The house of " + capitalize(homes[i][2]) +
        " lies to the " + homes[i][0] + ".\n";
      break;
    case 2:
      out += "To the " + homes[i][0] +
        " you see the entrance to the house of " +
          capitalize(homes[i][2]) + ".\n";
      break;
    }
  }
  return out;
}

int DeleteHome(string owner)
{
  string out;
  mixed  dummy;
  int    i;
  object *inv;

  if(!owner) return 0;
  if(!homes || !sizeof(homes)) return 0;
  rm(object_name() + ".rc");
  if(!sizeof(dummy = filter(homes,"exist",this_object(),owner)))
    return 0;
  homes -= dummy;
  if(i = sizeof(homes)) {
    out = "";
    for( ; i--; )
      out += implode(homes," ") + "\n";
    write_file(object_name() + ".rc",implode(homes,"\n"));
  }
  RemoveExit(dummy[0][0]);
  for(i = sizeof(inv = all_inventory()); i--; )
    if(living(inv[i])) inv[i]->move(this_object(),M_SILENT);
  tell_room(this_object(),"The home of " + capitalize(owner) +
            " is closed now.\n");
  return 1;
}

int exist(mixed home, string owner) { return home[2] == owner; }

mixed *QueryHomes() { return homes; }
