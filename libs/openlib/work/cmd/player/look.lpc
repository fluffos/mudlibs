/*  -*- LPC -*-  */
// look.c:  Look at room / item;  Tim McIntosh (astasia@iastate.edu)
//   10/16/95   Tim:  capitalizes room inventory now
//   10/18/95   Tim:  added object identifier line
//   10/25/95   Tim:  added filename identifier for ob's w/no short for wizzes
//   03/04/96   Tim:  added support to look at 'items' in rooms

#include <command.h>

int
main(string str)
{
  object room = environment(this_player());

  if( !str ) {
    if( wizardp(this_player()) )
      printf("[%s]\n", file_name(room));

    write(room->long());

    foreach(object ob in all_inventory(room)) {
      string tmp = (string) ob->short();

      if( ob == this_player() ) continue;
      if( tmp )
	write(capitalize(tmp) +"\n");
      else if( wizardp(this_player()) )
	printf("Invis Object: %s\n", file_name(ob));
    }
  } else {
    if(sscanf(str, "at %s", str) == 1) {
      object ob = present(str, room);

      if(!ob) ob = present(str, this_player());
      if(!ob) {
	if(room->exa_item(str))
	  write(room->exa_item(str));
	else
	  return notify_fail("That is not here.\n");
      } else
	write(ob->long());
    } else
      return notify_fail("Look AT something?\n");
  }
  return 1;
}

string help_desc() { return "look around room or at an object"; }

string
help()
{
  return @ENDHELP
To simply look around the room, type 'look' with no arguments.
In order to look at an object you must type 'look at' and the object's
name; for example:  look at book
ENDHELP;
}
