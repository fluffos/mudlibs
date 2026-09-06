/* Moved to /bin/pub 22-sep-94. */
/* Graah 18-Jan-96: room extra_move_object() function :( */
/* Kieve Dec 6, 1998: added 'keep' support, and 'put all' */

#include <cmd.h>

private status put_objects(object *item_o, object container_o, object me);

#define MAX_WEIGHT_FAIL  5

varargs nomask status
put_cmd(string str, object me)
{
    int i;
    string item, s, container;
    object *item_o, *inv, *keep;
    object container_o;

    if (!me && !(me = this_player())) return 0;
    if (!str) return notify_fail("Put what?\n"), 0;
    if (!me->query_can_move())
	return 0;
    i = (int) me->test_dark();
    if (i && i > -4 && i < 4)
	return 0;

    if(sscanf(str, "%s in %s", item, container) != 2)
	return
	notify_fail("Put what (\"put <object> in <container>\")?\n"), 0;
    container = lower_case(container);
    if (sscanf(str, "the %s", s)) str = s;
    if (!(container_o = present(container, me)))
	container_o = present(container, environment(me));
    if (!container_o) {
	me -> tell_me("You can't see any \"" + container + "\" here!");
	return 1;
    }
    if (!container_o -> can_put_and_get()) {
	me -> tell_me("You can't do that.");
	return 1;
    }
    item = lower_case(item);
    if(item == "all")
    {
	item_o = all_inventory(me);
    }
    else
    {
	item_o = ({ present(item, me) });
	if (!item_o[0]) {
	    me -> tell_me("You don't have any \"" + item + "\".");
	    return 1;
	}
    }

    return put_objects(item_o, container_o, me);
}

private status put_objects(object *item_o, object container_o, object me)
{
    int i, weight_fail, weight;
    object *keep;
    string msg;

    weight_fail = 0;
    keep = me->query_keep_items();
    msg = "";

    for(i=0 ; i < sizeof(item_o) ; i++)
    {
	if (item_o[i] -> drop(0))
	    continue;
	if (item_o[i] == container_o)
	{
	    msg += "You can't put any object inside itself!\n";
	    continue;
	}
	if (item_o[i] -> prevent_insert(me, container_o))
	    continue;

	// NEW: containers can refuse from taking an item 10.6.1994
	// Frobozz
	if (container_o -> refuse_item(item_o[i], me))
	    continue;

	if(member(keep, item_o[i]) != -1)
	{
	    msg += sprintf("You keep ahold of the %s.\n",
	      item_o[i]->query_name(0, me));
	    continue;
	}

	weight = (int)item_o[i]->query_weight();
	if(container_o -> add_weight(weight))
	{
	    /* Remove the weight from the previous container. */
	    environment(item_o[i]) -> add_weight(-weight);
	    move_object(item_o[i], container_o);
	    call_other(environment(me), "extra_move_object", item_o[i],
	      container_o);
	    environment(me)->tell_here(sprintf("%s puts the %s in the %s.",
		me->query_name(0, me), item_o[i]->query_name(0, me),
		container_o->query_name(0, me)), me);
	    msg += sprintf("You put the %s in the %s.\n",
	      item_o[i]->query_name(0, me),
	      container_o->query_name(0, me));
	}
	else
	{
	    msg += sprintf("There is no room for the %s.\n",
	      item_o[i]->query_name(0, me));
	    if(++weight_fail >= MAX_WEIGHT_FAIL)
	    {
		msg += sprintf("%s must be full. Stopping.\n",
		  capitalize(container_o->query_name(0, me)));
		break;
	    }
	}
    }
    me->tell_me(msg[0..<2]);
    return 1;
}
