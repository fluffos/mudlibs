// wizmakerd.c
// This daemon is called by the room in which players apply to be promoted
// to wizard. If a player has satisfactorily completed the wiz requirements,
// he goes to the application room (/d/Fooland/hall2 in the default lib) and
// applies. That room checks his qualifications and calls promote_wiz in the
// daemon. The daemon verifies that it was called from an acceptable room
// and if so, promotes the wizard.
// This rather elaborate scheme is for security reasons: a lot of
// wizards have access to domain files and you don't want any domain room
// to be able to promote to wizard. So we keep this daemon running with a
// hardcoded list of acceptable rooms, in a secure directory.
// Written by Mobydick@TMI-2, 12-3-92.

// We give full wizard powers right away. You may want to NOT give /cmds/xtra
// to newbie wizards: that way they can read the doc files without being
// able to clone, dest, or otherwise interfere. Depends how you want things
// to be run at your MUD: if you don't give /cmds/xtra right away you need
// to set up some policy about when you do give it.
// 93-07-22 Pallando moved the define of NEW_WIZ_PATH to config.h

#define PROMOTION_ROOMS ({ "/d/Fooland/hall2" })
#define WIZ_LIST        "/adm/etc/wiz_list"

#include <config.h>
#include <mudlib.h>
#include <uid.h>
#include <daemons.h>

inherit DAEMON;
inherit SAVE;

void read_wiz_list();
string *wiz_list;

void create()
{
	seteuid(ROOT_UID);
	set_persistent(1);
	save::create();
	read_wiz_list();
}

void read_wiz_list()
{
	string *lines, *names;
	int i, j;
	lines = explode( read_file(WIZ_LIST), "\n" );
	if( !lines ) return;
	for( i=0; i<sizeof(lines); i++ ) {
		names = explode( lines[i], ":" );
		if( !names ) continue;
		for( j=0; j<sizeof(names); j++ )
			if( !wiz_list )
				wiz_list = ({ names[j] });
			else if( member_array(names[j], wiz_list) == -1 )
				wiz_list += ({ names[j] });
	}
	return;
}

int add_wiz_list(string name)
{
	if( geteuid(previous_object()) != ROOT_UID &&
		!member_group(geteuid(previous_object()), "admin") ) return 0;
	if( member_array(name, wiz_list) != -1 ) return 0;
	wiz_list += ({ name });
	save_data();
	return 1;
}

int remove_wiz_list(string name)
{
	if( geteuid(previous_object()) != ROOT_UID &&
		!member_group(geteuid(previous_object()), "admin") ) return 0;
	if( member_array(name, wiz_list) == -1 ) return 0;
	wiz_list -= ({ name });
	save_data();
	return 1;
}

int in_wiz_list(string name)
{
	if( member_array(name, wiz_list) == -1 ) return 0;
	return 1;
}

string *query_wiz_list()
{
	return wiz_list;
}

// Here are belong to daemons.
int promote_wiz(object ob)
{
	string prev;
	object link;

	prev = file_name(previous_object()) ;
	if( member_array(prev,PROMOTION_ROOMS)== -1 ) return 0;
	link = ob->query_link();
	link->set("wizard", 1);
	ob->enable_me();
	ob->set("PATH", NEW_NEWBIE_PATH);
	return 1;
}

int reset_access(object link)
{
	object player;
	string name, level;
	mixed *path;
	int lvl;
	
	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	level = DOMAIN_D->query_domain_level(link);
	name = link->query("name");
	player = find_player(name);
	if( !player ) {
		player = link->query("body_ob");
		if( !player ) {
			link->restore_body();
			player = link->query("body_ob");
		}
	}
	
    if( member_group( geteuid(player), "admin" ) )
        path = NEW_ADM_PATH;
    else if( level == "archwizard" ) {
        path = NEW_ARCH_PATH;
        lvl  = NEW_ARCH_LEVEL;
	} else if( level == "sage" ) {
		path = NEW_SAGE_PATH;
		lvl  = NEW_SAGE_LEVEL;
	} else if( level == "adept" ) {
		path = NEW_ADEPT_PATH;
		lvl  = NEW_ADEPT_LEVEL;
	} else if( level == "wizard" ) {
		path = NEW_WIZ_PATH;
		lvl  = NEW_WIZ_LEVEL;
	} else if(  level == "apprentice" ) {
		path = NEW_NEWBIE_PATH;
		lvl  = NEW_NEWBIE_LEVEL;
	} else {
		path = USER_CMDS;
		lvl  = NEW_USER_LEVEL;
 	}
	
	seteuid(ROOT_UID);
	player->set("PATH", path );
	player->set_level(lvl);
	player->save_data();
	link->save_data();
	return 1;
}
