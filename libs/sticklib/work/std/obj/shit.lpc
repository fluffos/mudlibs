#include <treasure.h>

void
create_treasure()
{
    set_id(({ "cow shit", "shit", "dung" }));
    set_weight(1);
    set_short("large lump of cow shit");
    set_long(
      "This is a fresh, big, smelly pile of warm dung. Why on Loob are you \
carrying this manure around???");
    set_value(10);
}

void
init_treasure()
{
    add_action("throw","throw");
}

status
throw(string str)
{
    string what,who;
    object target;

    if (!stringp(str))
	return 0;
    if (sscanf(str,"%s at %s",what,who) != 2 &&
      sscanf(str,"%s %s",what,who) != 2)
    {
	notify_fail("Throw what at whom?\n");
	return 0;
    }

    if (!id(what))
	return 0;

    target = present(who,environment(this_player()));
    if (!target)
    {
	notify_fail("Throw it at whom???\n");
	return 0;
    }
    this_player()->tell_me("Ok. You throw cow shit in "
      +target->query_name()+"'s face!");
    target->tell_me(this_player()->query_name() +
      " throws cow shit in your face! YUK!");
    environment(target)->tell_here(this_player()->query_name() +
      " throws cow shit in "+target->query_name()+"'s face!",
      ({ this_player(), target }));
    target->cow_shit_thrown_on_face(this_player());
    destruct(this_object());
    return 1;
}
