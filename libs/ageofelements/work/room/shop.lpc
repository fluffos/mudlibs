inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("The shop");

    set_description(
	"You are in a shop. You can buy or sell things here. Commands are: "
	"'buy item', 'sell item', 'sell all', 'list', 'list weapons', "
	"'list armours' and 'value item'. There is an opening to the "
	"north, and some shimmering blue light in the doorway. To the west "
	"you see a small room."
      );

    set_exits( ([
	"south": "/room/vill_road2"
	, "west": "/room/storage"
      ]) );

    set_commands( ([
	"sell": "sell_cmd"
	, "value": "value_cmd"
	, "buy": "buy_cmd"
	, "north": "north_cmd"
	, "list": "list_cmd"
      ]) );
}

object find_item_in_player(string i) {
    object ob;

    ob = first_inventory(this_player());

    while (ob) {
        if (ob->id(i)) {
	    return ob;
	}

	ob = next_inventory(ob);
    }

    return 0;
}

int do_sell(object ob) {
    int value, do_destroy;

    value = ob->query_value();

    if (!value) {
	write(ob->short() + " has no value.\n");
	return 1;
    }

    if (environment(ob) == this_player()) {
        int weight;

	if (ob->drop()) {
	    write("I can't take it from you!\n");
	    return 1;
	}

        weight = ob->query_weight();
	this_player()->add_weight(- weight);
    }

    if (value > 2000) {
	do_destroy = 1;
    }

    if (value > 1000) {
	write("The shop is low on money.\n");
	value = 1000;
    }

    write(sprintf("You get %d gold coins.\n", value));
    say(sprintf("%s sells %s.\n", this_player()->query_name(), ob->short()));

    this_player()->add_money(value);

    add_worth(value, ob);

    if (do_destroy) {
	write("The valuable item is hidden away.\n");
	destruct(ob);
	return 1;
    }

    "room/store"->store(ob);

    return 1;
}

int sell_cmd(string item) {
    object ob;

    if (!item) {
	return notify_fail("Sell what?\n"), 0;
    }

    if (item == "all") {
	object next;

	ob = first_inventory(this_player());

	while (ob) {
	    next = next_inventory(ob);

	    if (!ob->drop() && ob->query_value()) {
		write(ob->short() + ":\t");
		do_sell(ob);
	    }

	    ob = next;
	}

	write("Ok.\n");
	return 1;
    }

    ob = present(item, this_player());

    if (!ob) {
	ob = present(item, this_object());
    }

    if (!ob) {
	write(sprintf("No such item (%s) here.\n", item));
	return 1;
    }

    do_sell(ob);

    return 1;
}

int value_cmd(string item) {
    int value;
    object name_of_item;

    if (!item) {
	return notify_fail("Value what?\n"), 0;
    }

    name_of_item = present(item);

    if (!name_of_item) {
	name_of_item = find_item_in_player(item);
    }

    if (!name_of_item) {
	if ("room/store"->value(item)) {
	    return 1;
	}

	write(sprintf("No such item (%s) here or in the store.\n", item));
	return 1;
    }

    value = name_of_item->query_value();

    if (!value) {
	write(sprintf("%s has no value.\n", item));
	return 1;
    }

    write(sprintf("You would get %d gold coins.\n", value));
    return 1;
}

int buy_cmd(string item) {
    if (!item) {
	return notify_fail("Buy what?\n"), 0;
    }

    "room/store"->buy(item);
    return 1;
}

int north_cmd() {
    if (this_player()->query_level() < 20) {
	write("A strong magic force stops you.\n");
	say(sprintf("%s tries to go through the field, but fails.\n"
	    , this_player()->query_name()));
	return 1;
    }

    write("You wriggle through the force field.\n");
    this_player()->move_player("north#room/store");
    return 1;
}

int list_cmd(string arg) {
    "room/store"->inventory(arg);
    return 1;
}
