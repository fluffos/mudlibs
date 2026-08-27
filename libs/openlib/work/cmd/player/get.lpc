/*  -*- LPC -*-  */
// get.c:  get an object and place in your inventory
//   Originally by Tim 10/11/95
//

#include <command.h>

private void do_get(object ob, object source, string name);

int
main(string what)
{
  string name = this_player()->query_cap_name();
  object source;
  string from;

  if( !what ) return notify_fail("Get what??\n");

  if(sscanf(what, "%s from %s", what, from) == 2) {
    source = present(from, this_player());
    if( !source )
      source = present(from, environment(this_player()));
    if( !source )
      return notify_fail(sprintf("Can't find %s here to get it from!\n",
				 from));
  } else
    source = environment(this_player());

  if( lower_case(what) == "all" ) {
    foreach(object ob in all_inventory(source))
      if( ob->get() ) do_get(ob, source, name);
  } else {
    object ob = present(what, source);

    if( !ob ) {
      if(source)
	return notify_fail(sprintf("Can't find %s in %s.\n", what, from));
      else 
	return notify_fail(sprintf("Can't find %s here.\n", what));
    }

    if( !ob->get() )
      return notify_fail("You can't get that!\n");

    do_get(ob, source, name);
  }
  return 1;
}

private void
do_get(object ob, object source, string name)
{
  string  short = ob->short();     // ob not guaranteed to exist after move

  // don't know if we'll want to do a ob->on_get() or just do all in init()

  if( !(ob->move(this_player())) )
    return write("You fail.\n");

  if( ob ) short = ob->short();

  if( source != environment(this_player()) ) {
    say(sprintf("%s gets %s from %s.\n", name, short, source->short()));
    printf("You get %s from %s.\n", short, source->short());
  } else {
    say(sprintf("%s gets %s.\n", name, short));
    printf("You get %s.\n", short);
  }
}
