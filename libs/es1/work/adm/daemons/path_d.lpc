// all functions do firse when the player enter ES, added by Kyoko.
// changed the PATH property to an array, to speedup command hooking
#include <uid.h>
#include <config.h>
#include <daemons.h>

void create()
{
	// To pass check on modifying PATH property.
	seteuid( getuid() );
}

void assign_path(object player)
{
	// updated by Kyoko, to differ cmds path between wizs and archwizs.	
	// cleaned up by Annihilator, removed all variable usage to speedup.
	if( member_group(getuid(player), "admin") )
		player->set("PATH",NEW_ADM_PATH);
	else 
	switch( (string)DOMAIN_D->query_domain_level(previous_object()->query_link()) ) {
		case "god": 		player->set("PATH", NEW_ADM_PATH);		break;
		case "archwizard":	player->set("PATH", NEW_ARCH_PATH);		break;
		case "sage":		player->set("PATH", NEW_SAGE_PATH);		break;
		case "adept":		player->set("PATH", NEW_ADEPT_PATH);	break;
		case "wizard":		player->set("PATH", NEW_WIZ_PATH);		break;
		case "apprentice":	player->set("PATH", NEW_NEWBIE_PATH); 	break;
		default:			player->set("PATH", USER_CMDS);
	}
}

int add_path(object player, string path)
{
    string *curpath;
    
    if( geteuid(previous_object()) != ROOT_UID &&
    	geteuid(previous_object()) != "Mage" &&
    	geteuid(previous_object()) != "Adventurer" &&
    	geteuid(previous_object()) != "Healer" &&
    	geteuid(previous_object()) != "Knight" &&
    	geteuid(previous_object()) != "Scholar" &&
    	geteuid(previous_object()) != "Monk" &&
    	geteuid(previous_object()) != "Thief" &&
    	geteuid(previous_object()) != "Psyche" &&
        geteuid(previous_object()) != "Killer" &&
    	geteuid(previous_object()) != "NONAME" ) return 0;

    curpath = player->query("PATH");
    if( sizeof(curpath) && member_array(path, curpath) != -1 )
    	return 1;
    if( !sizeof(curpath) ) curpath = ({path});
    else curpath += ({ path });
	return (int)player->set("PATH", curpath);
}

int delete_path(object player, string path)
{
    string *curpath;
    
    if( geteuid(previous_object()) != ROOT_UID &&
    	geteuid(previous_object()) != "Mage" &&
    	geteuid(previous_object()) != "Adventurer" &&
    	geteuid(previous_object()) != "Healer" &&
    	geteuid(previous_object()) != "Knight" &&
    	geteuid(previous_object()) != "Scholar" &&
    	geteuid(previous_object()) != "Monk" &&
    	geteuid(previous_object()) != "Thief" &&
    	geteuid(previous_object()) != "Psyche" &&
    	geteuid(previous_object()) != "NONAME" )
    return 0;

    curpath = player->query("PATH");
    if( !sizeof(curpath) || member_array(path, curpath) == -1 )
    	return 1;
    curpath -= ({ path });
	return (int)player->set("PATH", curpath);
}
