#define F_ROOM_RESET_USED        1
#define F_ROOM_INIT_USED         2

private nosave int flags;
private nosave int lumens;
private nosave mixed brief;
private nosave mixed description;
private nosave mapping exits;
private nosave mapping items;
private nosave mapping commands;
private nosave object *permanent_objects;
private nosave string *permanent_names;
private nosave mixed *transient_objects;

int
query_lumens()
{
    return lumens;
}

void
set_lumens(int arg)
{
    lumens = arg;
}

string
query_brief()
{
    if (closurep(brief)) {
	return funcall(brief);
    }

    return brief;
}

void
set_brief(mixed arg)
{
    if (!stringp(arg) && !closurep(arg)) {
	return;
    }

    brief = arg;
}

string
query_description()
{
    if (closurep(description)) {
	return funcall(description);
    }

    return description;
}

void
set_description(mixed arg)
{
    if (!stringp(arg) && !closurep(arg)) {
	return;
    }

    description = arg;
}

mapping
query_exits()
{
    return exits;
}

void
set_exits(mapping arg)
{
    if (!arg) {
	exits = 0;

	return;
    }

    if (!mappingp(arg) || !sizeof(m_indices(arg))) {
	return;
    }

    exits = deep_copy(arg);
}

mixed
query_exit(string arg)
{
    if (!arg || !exits || !sizeof(exits)) {
	return 0;
    }

    return exits[arg];
}

void
add_exit(string dir, mixed room)
{
    if (!stringp(dir) || (!stringp(room) && !closurep(room))) {
	return;
    }

    if (!exits) {
	exits = ([ dir: room ]);
    } else {
	exits[dir] = room;
    }
}

void
remove_exit(string arg)
{
    if (exits && mappingp(exits)) {
	exits = m_delete(exits, arg);
    }

    if (!sizeof(exits)) {
	exits = 0;
    }
}

mapping
query_items()
{
    mapping ret = deep_copy(items);

    if (ret && mappingp(ret) && sizeof(ret)) {
	string synonym;

	foreach (string key, string val : ret) {
	    if (sscanf(val, "=%s", synonym) == 1 && member(ret, synonym)) {
		ret[key] = ret[synonym];
	    }
	}
    }

    return ret;
}

void
set_items(mapping arg)
{
    if (!arg) {
	items = 0;

	return;
    }

    if (!mappingp(arg) || !sizeof(m_indices(arg))) {
	return;
    }

    items = deep_copy(arg);

    foreach (mixed item : m_indices(arg)) {
	if (pointerp(item) && sizeof(item)) {
	    string synonym;

	    foreach (mixed element : item) {
		if (stringp(element)) {
		    if (!synonym) {
			synonym = element;
			items[element] = arg[item];
		    } else {
			items[element] = sprintf("=%s", synonym);
		    }
		}
	    }

	    m_delete(items, item);
	}
    }
}

mixed
query_item(string arg)
{
    string synonym;

    if (!arg || !items || !sizeof(items)) {
	return 0;
    }

    if (stringp(items[arg])
	&& sscanf(items[arg], "=%s", synonym) == 1
	&& member(items, synonym)) {
	return items[synonym];
    }

    return items[arg];
}

void
add_item(mixed item, mixed desc)
{
    if (!stringp(desc) && !closurep(desc)) {
	return;
    }

    if (!items) {
	items = ([ item: desc ]);
    } else {
	items[item] = desc;
    }

    if (pointerp(item) && sizeof(item)) {
	string synonym;

	foreach (mixed element : item) {
	    if (stringp(element)) {
		if (!synonym) {
		    synonym = element;
		    items[element] = item[element];
		} else {
		    items[element] = sprintf("=%s", synonym);
		}
	    }
	}

	m_delete(items, item);
    }
}

void
remove_item(string arg)
{
    if (items && mappingp(items)) {
	m_delete(items, arg);
    }

    string synonym = sprintf("=%s", arg);

    foreach (string key, mixed val : items) {
	if (stringp(val) && val == synonym) {
	    m_delete(items, key);
	}
    }

    if (!sizeof(items)) {
	items = 0;
    }
}

mapping
query_commands()
{
    return commands;
}

void
set_commands(mapping arg)
{
    if (!arg) {
	commands = 0;
    }

    if (!mappingp(arg) || !sizeof(m_indices(arg))) {
	return;
    }

    commands = deep_copy(arg);
}

mixed
query_command(string arg)
{
    if (!arg || !commands || !sizeof(commands)) {
	return 0;
    }

    return commands[arg];
}

void
add_command(string cmd, mixed func)
{
    if (!stringp(cmd) || (!stringp(func) && !closurep(func))) {
	return;
    }

    if (!mappingp(commands)) {
	commands = ([ cmd: func ]);
    } else {
	commands[cmd] = func;
    }
}

void
remove_command(string arg)
{
    if (commands && mappingp(commands)) {
	commands = m_delete(commands, arg);
    }

    if (!sizeof(commands)) {
	commands = 0;
    }
}

void
add_permanent_object(string arg)
{
    if (!stringp(arg)) {
	return;
    }

    if (!pointerp(permanent_names)) {
	permanent_objects = ({});
	permanent_names = ({});
    }

    object ob = clone_object(arg);
    move_object(ob, this_object());

    permanent_objects += ({ ob });
    permanent_names += ({ arg });
}

void
reset_permanent_objects()
{
    int s, i, k;

    if (pointerp(permanent_names) && (s = sizeof(permanent_names))) {
	i = 0;

	while (i < s) {
	    if (!permanent_objects[i]) {
		permanent_objects[i] = clone_object(permanent_names[i]);
		k++;
	    }

	    i++;
	}

	if (k || first_inventory() != permanent_objects[0]) {
	    i = s;

	    while ((--i) >= 0) {
		move_object(permanent_objects[i], this_object());
	    }
	}
    }
}

varargs void
add_transient_object(mixed arg, string appearmsg, int reset_chance)
{
    object ob;

    if (!stringp(arg) && !pointerp(arg) && !objectp(arg)) {
	return;
    }

    // Accept add_transient_object(object) and optionally write the appearmsg
    // and calculation to determine if it is moved to the room, however the
    // this room inheritable will *not* manage their resets.
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

	transient_objects += ({({ ob, arg, appearmsg, reset_chance })});
    }

    if (ob) {
	move_object(ob, this_object());
    }

    if (ob && appearmsg) { // Sometimes init() can destroy objects
	say(sprintf("%s\n", appearmsg), ob);
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
	string appearmsg = transient_data[2];
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

	if (!new_clone && ob && ob->is_npc()
	    && (ob->query_attack() || ob->query_master())) {
	    continue;
	}

	// Return to this room.
	move_object(ob, this_object());

	if (ob && appearmsg) { // Sometimes init() can destroy objects
	    say(sprintf("%s\n", appearmsg), ob);
	}
    }

    transient_objects -= ({ 0 });
}

varargs int
move(string dir, string room)
{
    if (!this_player()) {
	return 0;
    }

    if (!dir) {
	dir = query_verb();
    }

    if (!room && (!exits || !(room = exits[dir]))) {
	return 0;
    }

    this_player()->move_player(dir, room);
    return 1;
}

int
id(string arg)
{
    if (items && arg && items[arg]) {
	return 1;
    }

    return 0;
}

void
create()
{
    if (function_exists("reset_room", this_object())) {
	flags |= F_ROOM_RESET_USED;
    }

    this_object()->create_room();

    if (function_exists("init_room", this_object())) {
	flags |= F_ROOM_INIT_USED;
    }
}

void
reset()
{
    if (flags & F_ROOM_RESET_USED) {
	this_object()->reset_room();
    }

    // reset_room() may call destruct()
    if (!this_object()) {
       return;
    }

    // Clone and replace missing permanent objects
    if (pointerp(permanent_names)) {
	reset_permanent_objects();
    }

    // Reset transient objects
    if (pointerp(transient_objects)) {
	reset_transient_objects();
    }
}

void
init()
{
    add_action("command_driver", "", 1);

    if (flags & F_ROOM_INIT_USED) {
	this_object()->init_room();
    }

    if (!this_player()) {
	return;
    }
}

void
heart_beat()
{
}

int
search_cmd(string arg)
{
    tell_object(this_player()
	, "You search around, but did not find any interesting discoveries.\n");

    return 1;
}

int
listen_cmd(string arg)
{
    tell_object(this_player()
	, "You listen intently, but did not hear any interesting sounds.\n");

    return 1;
}

int
smell_cmd(string arg)
{
    tell_object(this_player()
	, "You sniff vigorously, but did not detect any interesting scents.\n");

    return 1;
}

int
command_driver(string arg)
{
    string verb;
    mixed func;
    int ret;

    verb = query_verb();

    if (commands && widthof(commands) && (func = commands[verb])) {
	// Convert to a closure if not already done so.
	if (stringp(func)) {
	    func = symbol_function(func, this_object());
	    commands[verb] = func;
	}

	ret = funcall(func, arg, this_player());

	if (ret) {
	    return ret;
	}
    }

    if (exits && (func = exits[verb])) {
	if (closurep(func)) {
	    func = funcall(func, arg, this_player());

	    if (!stringp(func) && !objectp(func)) {
		return func;
	    }
	}

	ret = move(verb, func);

	if (ret) {
	    return ret;
	}
    }

    if (verb == "search") {
	return search_cmd(arg);
    }

    if (verb == "listen" || verb == "hear") {
	return listen_cmd(arg);
    }

    if (verb == "smell") {
	return smell_cmd(arg);
    }

    if (this_player()->is_npc()) {
	func = symbol_function("command_driver", this_player());
	ret = funcall(func, arg, this_player());

	if (ret) {
	    return ret;
	}
    }

    return 0;
}
