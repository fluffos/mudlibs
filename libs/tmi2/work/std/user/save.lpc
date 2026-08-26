// Save.c
// Part of the TMI distribution mudlib.
// Please give credit where it is due and thank us, whoever we are...
//
// This file is responsible for the saving and restoring functions of
// the user object.  It should only be changed very carefully as this
// area is a sensitive one and inexperienced hands may introduce
// unnoticed security holes. ;-)


#include <uid.h>
#include <config.h>


// This one is called at login, to restore player data from saved file.
// Return 0 for no save file, which means a new player.
// Otherwise, restore player variables and return 1.
//
// You can't restore something if you're just anybody.
// The caller should be able to set stuff, if it has root access, and if
// the player already has the uid/euid, then obviously it's not new.


nomask int restore_body() {
	if (base_name(previous_object()) != CONNECTION &&
	    getuid(previous_object()) != ROOT_UID)  return 0;
	seteuid(geteuid(previous_object()));
	if (!geteuid())  return 0;
	return restore_object(user_data_file(this_object())+__SAVE_EXTENSION__);
}


// This is a new substitute for save_player(), which was really dumb 
// because there's no need to know someone's name to tell them to save...
// a wasted call_other

nomask void save_data() {
	string euid;
 
	euid = geteuid();
 
	if (!euid) seteuid(getuid());
	if (!euid || euid == "Logon" || euid == ROOT_UID) return;
 
	this_object()->compute_autoload_array(); /* Tru - 92/02/11 */
 
	assure_user_save_dir(this_object());
	save_object(user_data_file(this_object())+__SAVE_EXTENSION__);
}


// This is just a pointer now so old code won't break yet, just get logged.

void save_player(string name) {
	if (previous_object())
		log_file("save_player", file_name(previous_object()) + "\\n");
	save_data();
}

nomask
void save_me() { 
	save_data();
}

