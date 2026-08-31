object it;

init() {
  if(this_player()!=this_object()) return;
  add_action("drop_thing", "drop");
  add_action("pick_up", "get");
  add_action("give_object", "give");
}

drop_one_item(ob) {
    int weight;
    if(call_other(ob, "drop", 0)) return 0;
    weight=call_other(ob, "query_weight", 0);
    if(!weight) weight=0;
    add_weight(-weight);
    move_object(ob, environment(this_object()));
    return 1;
}

drop_all() {
    object ob;
    object next_ob;
    ob=first_inventory(this_object());
    while(ob) {
	string out;
	next_ob=next_inventory(ob);
	it=call_other(ob, "short", 0);
	if(drop_one_item(ob)) {
	    out = it + ".\n";
	    say(cap_name + " drops " + out);
	}
	ob = next_ob;
    }
}

nosave get_all(from) {
    object ob, next_ob;
    ob = first_inventory(from);
    while(ob) {
	string item;
	next_ob = next_inventory(ob);
	item = call_other(ob, "short", 0);
	if (item && call_other(ob, "get", 0)) {
	    int weight;
	    weight = call_other(ob, "query_weight", 0);
	    if (add_weight(weight)) {
		move_object(ob, this_object());
		say(cap_name + " takes: " + item + ".\n");
	    }
	    it = item;
	}
	ob = next_ob;
    }
}

pick_up(str) {
    string item;
    string container;
    object item_o;
    object container_o;
    int weight;
    if (!str) return 1;
    if (str == "all") {
	get_all(environment());
	return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
	pick_item(str);
	return 1;
    }
    container_o = present(lower_case(container));
    if (!container_o) return 1;
    if (!call_other(container_o, "can_put_and_get", 0)) return 1;
    item_o = present(item, container_o);
    if (!item_o) return 1;
    if (!call_other(item_o, "get", item)) return 1;
    weight = call_other(item_o, "query_weight", 0);
    if (!add_weight(weight)) return 1;
    call_other(container_o, "add_weight", -weight);
    move_object(item_o, this_object());
    say(cap_name + " takes " + item + " from " + container + ".\n");
    return 1;
}

nosave pick_item(obj) {
    object ob;
    int i;
    obj = lower_case(obj);
    if (environment()->id(obj)) return 1;
    ob = present(obj, environment());
    if (!ob) return 1;
    if (environment(ob) == this_object()) return 1;
    if (call_other(ob, "get", 0) == 0) return 1;
    i = call_other(ob, "query_weight", 0);
    if (add_weight(i)) {
	move_object(ob, this_object());
	say(cap_name + " takes " + obj + ".\n");
	it = obj;
	return 1;
    }
    return 1;
}

nosave drop_thing(obj) {
    string tmp;
    string tmp2;
    int i;
    if (!obj) return 1;
    if (obj == "all") {
	drop_all(1);
	return 1;
    }
    if (sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
	put(obj);
	return 1;
    }
    if (obj == "money" || obj == "all money") {
	drop_all_money(1);
	return 1;
    }
    tmp = obj;
    obj = present(lower_case(obj), this_object());
    if (!obj) return 1;
    if (drop_one_item(obj)) {
	it = tmp;
	say(cap_name + " drops the " + tmp + ".\n");
    }
    return 1;
}

nosave give_object(str) {
    string item, dest;
    object item_ob, dest_ob;
    int weight;
    int coins;

    if (!str) return 0;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	item = 0;
    else if ( sscanf(str, "1 coin to %s", dest) == 1)
	coins = 1;
    else if ( sscanf(str, "coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "one coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) return 1;
    dest = lower_case(dest);
    if (item) {
	item = lower_case(item);
	item_ob = present(item, this_object());
	if (!item_ob) return 1;
	it = item;
	if (environment(item_ob) == this_object() &&
	    call_other(item_ob, "drop", 0) == 1) {
	    return 1;
	} else {
	    if (!call_other(item_ob, "get")) return 1;
	}
    }
    dest_ob = present(dest, environment(this_object()));
    if (!dest_ob) return 1;
    if (!living(dest_ob)) return 1;
    if (!item) {
	if (coins <= 0) return 0;
	if (money < coins) return 1;
	money -= coins;
	if(call_other(dest_ob, "add_money", coins))
		tell_object(dest_ob, cap_name + " gives you " + coins +
		    " gold coins.\n");
	return 1;
    }
    weight = call_other(item_ob, "query_weight", 0);
    if (!call_other(dest_ob, "add_weight", weight)) return 1;
    add_weight(-weight);
    move_object(item_ob, dest_ob);
    say(cap_name + " gives " + item + " to " + capitalize(dest) + ".\n");
    return 1;
}
