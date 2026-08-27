/*  -*- LPC -*-  */
// drop.c:  drop something in your inventory
//   Originally by Tim 10/11/95
//

#include <command.h>

private void do_drop(object ob, string name);

int
main(string what)
{
  string name = this_player()->query_cap_name();

  if( !what ) return notify_fail("Drop what??\n");

  if( lower_case(what) == "all" ) {
    foreach(object ob in all_inventory(this_player()))
      if( ob->drop() ) do_drop(ob, name);
  } else {
    object ob = present(what, this_player());

    if( !ob )
      return notify_fail(sprintf("You don't have %s.\n", what));

    if( !ob->drop() )
      return notify_fail("You can't drop that!\n");

    do_drop(ob, name);
  }
  return 1;
}
   
private void
do_drop(object ob, string name)
{
  string short = ob->short();

// might want an ob->on_drop() here...

  if( !(ob->move(environment(this_player()))) )
    return write("You fail\n");

  if( ob ) short = ob->short();
  say(sprintf("%s drops %s.\n", name, short));
  printf("You drop %s.\n", short);
}
