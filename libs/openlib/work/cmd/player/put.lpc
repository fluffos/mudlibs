//  put.c: puts objs into things
//  coded by Kyricc
//  24 Feb 96
//  22 Apr 96  Tim:  Put in a check of ob->move() so I could test some stuff.

#include <command.h>

int
main (string what)
{
  string where;
  object ob, destination;

  if( !what ) return notify_fail("Put what where??\n");

  if( sscanf(what, "%s in %s", what, where) == 2 ) {
    destination = present(where, this_player());
    if( !destination )
      destination = present(where, environment(this_player()));
    if( !destination )
      return notify_fail(sprintf("Cant find a %s here to put it into!\n",
                                 where));
  }

  ob = present(what, this_player());

  if( !ob ) return notify_fail("You don't have that!\n");

  if( living(destination) )
    return notify_fail("That's rude!\n"
		       "Try giving it to " + pronoun(destination, 0) + ".\n");

  if( destination == environment(ob) )
    return notify_fail("It is already there!\n");

  if( !(ob->move(destination)) ) return 0; // error message is set by move()
  write("Ok.\n");
  return 1;
}
