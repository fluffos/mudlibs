//	File	:  /adm/daemons/converter.c
//  	Creator	:  Buddha@TMI  (01/93)
//	Updated	:  Watcher@TMI (02/28/93) to switch wizard flag location
//
//	This daemon converts player data from one system setting to
//	another system.  Modify it to suit your needs.

#include <config.h>
#include <login.h>
#include <login_macros.h>
#include <daemons.h>
#include <mudlib.h>
#include <uid.h>
#include <priv.h>

void create() { seteuid(ROOT_UID); }
void clean_up() { destruct(this_object()); }

void fix_user(string name) {
	object user, body;
	string new_dir, old_file;

	// this is here to stop user files from being deleted, dont
	// remove it unless you know what you are doing.
	return;

	old_file = PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION;
	if (file_size(old_file) < 0) return;
	new_dir = user_data_dir(find_object_or_load(USER_OB), name);
	mkdirs(new_dir);
	rename(old_file, new_dir + "/" + name + SAVE_EXTENSION);
	user = new(CONNECTION);
	user->set("name", name);
	user->set("body", USER_OB);
	seteuid(name);
	export_uid(user);
	seteuid(getuid());
	user->restore_body();
	body = (object)user->BODY_OB;
	user->set("password", (string)body->query("password"));
	body->delete("password");
	user->set("email", (string)body->query("email"));
	body->delete("email");
	user->set("real_name", (string)body->query("real_name"));
	body->delete("real_name");
	// the remove() in these ought to make them save...
	body->remove();
	user->remove();
}
	
	
void switch_wizard_flag() {
 
   if(!previous_object()->query("wizard"))  return;
 
   //  Switch wizard flag from user body to connection object
 
   previous_object()->query_link()->set("wizard", 1);
   previous_object()->delete("wizard");
 
   //	Save both objects with updated data
 
   previous_object()->query_link()->save_data();
   previous_object()->save_data();
 
}
	

void lock_health() {

   if((int)previous_object()->query_permission("max_hp") != 3)
     previous_object()->set("max_hp", (int)previous_object()->query("max_hp"),
	LOCKED);
 
   if((int)previous_object()->query_permission("max_sp") != 3)
     previous_object()->set("max_sp", (int)previous_object()->query("max_sp"),
	LOCKED);
 
}
 
 
void fix_skill_name () {
	previous_object()->init_skills() ;
	previous_object()->remove_skill("Magic item use") ;
	previous_object()->set_skill("Wilderness", 0, "dexterity") ;
}
