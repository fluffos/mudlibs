/*
Taken from Rec.games.mud.lp:
-------------------------------------------------------------------------------

While we're on the subject of cleaning the autoload stuff up, there
is no reason to stop at fixing this small but ugly cheating problem.
We have the following problems with the old autoloading routine:
a) It's necessary to preload auto load objects.
b) This still doesn't protect us against an error if things go
   wrong in another object.
c) There is no reason to store the autoload stuff in a string. That
   is a 2.4.5 leftover and there is really no reason to forbid people
   from using "^!" in a string.
d) And if we use arrays to store the set of all query_auto_load() results,
   there is still no reason to restrict the autoload data to be a string.

The following solution addresses all these problems. It is
a) compatible with the old mechanism, i.e. no need to convert .o files.
   It should run with vanilla 3.1.2 since most of the code was written
   in '91 when TUBMUD was running some 3.0.x version.
b) There is no need to preload auto load objects.
c) The catch() should make 99% sure that no nasty things can leave the
   player object "hanging in midair" during login.
d) The autoload cheating mechanism gets disabled.
e) query_auto_load() can either return strings in the old format or an
   array ({ filename, data_1, ..., data_n }) which will result in
   ({ data_1, ..., data_n }) being passed to init_arg() on login.
Well, it still isn't perfect, but it is a great deal better than the
old solution.

			  Reimer Behrends

-------------------------------------------------------------------------------

Typecasting added and edited by Frobozz 16.1.1993

*/

void load_single_auto_obj(string file, mixed argument);

mixed auto_load;	/* Special automatically loaded objects. */

void
load_auto_obj(mixed arr) {
    string file, err;
    mixed argument;
    int i;

    if (stringp(arr)) /* compatibility */
	arr = explode(arr, "^!");

    if (pointerp(arr))
	/* I changed the way for-loop is done for speed //Frobozz */
	for (i=sizeof(arr)-1; i>=0; i--) {
	    if (stringp(arr[i])) {
		if (sscanf(arr[i],"%s:%s",file,argument)!=2) {
		    file = arr[i];
		    argument = 0;
		}
	    }
	    else
	    if (pointerp(arr[i]) && sizeof(arr[i]) && stringp(arr[i][0])) {
		file = arr[i][0];
		argument = arr[i][1..sizeof(arr[i])];
	    }
	    else {
		write("Auto load array entry corrupt.\n");
		continue;
	    }
	    err = catch(load_single_auto_obj(file, argument));
	    if (err) {
		write("Couldn't load auto load object.\n");
		log_file("AUTOLOAD", file+":"+err);
		continue;
	    }
	}
}

void
load_single_auto_obj(string file, mixed argument) {
    object ob;
    ob = clone_object(file);
    ob->init_arg(argument);
    move_object(ob, this_object());
}

void
compute_auto_str() {
    object ob;
    mixed data;

    auto_load = ({});
    ob = first_inventory(this_object());
    while(ob) {
	data = 0;
	catch(data = (mixed)ob->query_auto_load());
	ob = next_inventory(ob);
	if (stringp(data) || pointerp(data))
	    auto_load += ({ data });
    }
}
