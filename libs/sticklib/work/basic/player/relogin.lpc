/*
**
** /basic/player/relogin.c (c) Starbyt 290392
**
** Temporary gateway to relogin to another interactive object.
**
*/

#define load_ob "basic/player"

nomask relogin() {
    int	x;
    string	err;
    object	ob;

    if(!this_player() || this_player()!=this_object() ||
      !interactive(this_player()) || this_player()->query_coder_level()<300) return;

    err = catch(destruct(find_object(load_ob)));
    err = catch(call_other(load_ob, "???"));
    if(err) {
	write("FATAL: Error in player object: " + err + "\n");
	return 1;
    }

    err = catch(ob = clone_object(load_ob));
    if(!ob || err) {
	write("FATAL: Can't clone new player object: " + err + "\n");
	return 1;
    }

    if(!exec(ob, this_object())) {
	write("FATAL: Can't exec into " + load_ob + "!\n");
	destruct(ob);
	return 1;
    }

    write("Switched player object into new.\n");
    ob->initialize();
    destruct(this_object());
    return 1;
}


