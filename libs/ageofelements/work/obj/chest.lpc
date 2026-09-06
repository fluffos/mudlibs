int local_weight;
int chest_is_open;
nosave mixed *transient_objects;

void init() {
    add_action("open", "open");
    add_action("close", "close");
}

int id(string str) { return str == "chest"; }

string short() {
    return "chest";
}

void long() {
    write("A chest that seems to be of a high value.\n");
    if (chest_is_open)
	write("It is open.\n");
    else
	write("It is closed.\n");
}

int query_value() { return 200; }

int query_weight() { return 8; }

int get() { return 1; }

int can_put_and_get() { return chest_is_open; }

void add_weight(int w) {
    if (w + local_weight > 8)
	return 0;
    local_weight += w;
}

int close(string str)
{
    if (!id(str))
        return 0;
    chest_is_open = 0;
    write("Ok.\n");
    return 1;
}

int open(string str)
{
    if (!id(str))
        return 0;
    chest_is_open = 1;
    write("Ok.\n");
    return 1;
}

void reset(int arg) {
    if (arg)
	return;
    chest_is_open = 0;
}

varargs void
add_transient_object(mixed arg, string handlemsg, int reset_chance)
{
    object ob;

    if (!stringp(arg) && !pointerp(arg) && !objectp(arg)) {
	return;
    }

    // Accept add_transient_object(object) and optionally write the appearmsg
    // and calculation to determine if it is moved to the mpnster, however this
    // monster inheritable will *not* manage their resets.
    if (objectp(arg)) {
	ob = arg;
    }

    if (reset_chance && reset_chance < random(101)) {
	; // Do nothing
    } else {
	if (stringp(arg)) { // A simple file name
	    catch (ob = clone_object(arg));
	} else if (pointerp(arg)) { // A more complex array
	    catch (ob = clone_object(arg[0])); // First element must be the file name
	}

	if (!ob) {
	    return; // Cloning failed?
	}

	if (pointerp(arg)) { // Process call_other's
	    for (int i = 1, int s = sizeof(arg); i < s; i++) {
		if (!pointerp(arg[i])) {
		    continue;
		}

		if (sizeof(arg[i]) < 2) {
		    call_other(ob, arg[i][0]);
		} else {
		    apply(#'call_other, ob, arg[i][0], arg[i][1..<1]);
		}
	    }
	}

	if (!transient_objects) {
	    transient_objects = ({});
	}

	transient_objects += ({({ ob, arg, handlemsg, reset_chance })});
    }

    if (ob) {
	move_object(ob, this_object());
    }

    if (ob && handlemsg) { // Sometimes init() can destroy objects
	say(sprintf("%s\n", handlemsg), ob);
    }
}

void
reset_transient_objects()
{
    foreach (mixed transient_data : transient_objects) {
	if (!pointerp(transient_data)) {
	    continue;
	}

	object ob = transient_data[0];
	mixed object_info = transient_data[1];
	string handlemsg = transient_data[2];
	int reset_chance = transient_data[3];

	if (!object_info || (!stringp(object_info) && !pointerp(object_info))) {
	    transient_data = 0;
	    continue;
	}

	// Check if the object is resettable (in this reset)
	if (reset_chance && reset_chance < random(101)) {
	    continue; // Do nothing
	}

	// If the object is here, do nothing
	if (ob && environment(ob) == this_object()) {
	    continue;
	}

	int new_clone;

	if (!ob || !ob->is_npc()) {
	    new_clone = 1;

	    if (stringp(object_info)) {
		catch (ob = clone_object(object_info));
	    } else if (pointerp(object_info)) {
		catch (ob = clone_object(object_info[0]));
	    }
	}

	if (!ob) {
	    continue; // Cloning failed?
	}

	if (new_clone) {
	    if (pointerp(object_info)) { // Process call_other's
		for (int i = 1, int s = sizeof(object_info); i < s; i++) {
		    if (!pointerp(object_info[i])) {
			continue;
		    }

		    if (sizeof(object_info[i]) < 2) {
			call_other(ob, object_info[i][0]);
		    } else {
			apply(#'call_other, ob, object_info[i][0], object_info[i][1..<1]);
		    }
		}
	    }

	    transient_data[0] = ob;
	}

	if (!new_clone && ob && present(ob, environment(ob))) {
	    // Return to this monster.
	    move_object(ob, this_object());
	}

	if (ob && handlemsg) { // Sometimes init() can destroy objects
	    say(sprintf("%s\n", handlemsg), ob);
	}
    }

    transient_objects -= ({ 0 });
}
