/*
 * _newsadm.c
 * Mobydick's hackup newsgroup maintenance interface for TMI-2.
 */

#include <newsreader.h>
#include <daemons.h>
#include <mudlib.h>

// newsgroup names are in the form tree.branch (where branch may be
// further divided). This is the list of legitimate trees.

#define TREES ({ "news", "code", "tmi", "mud" })

// The EUID that is authorized to add and remove groups.

#define MAINTAINER "mobydick"

inherit DAEMON ;

// Used to check whether a newsgroup name has a valid format.

int valid_group_name (string str) {

    string tree, branch ;

    if (sscanf(str,"%s.%s",tree,branch)!=2) return 0 ;
    if (member_array(tree,TREES)==-1) return 0 ;
    return 1 ;
}

int cmd_newsadm (string str) {
    notify_fail ("Usage: newsadm [-r] <group name>\n") ;
    if (!str) {
	write ("Currently valid groups: "+identify(NEWS_D->get_groups())+"\n") ;
	return 1 ;
    }
    if (geteuid(previous_object())!=MAINTAINER) {
	write ("Only the news maintainer can add and remove groups.\n") ;
	return 1 ;
    }
    if (str[0..1]=="-r") {
	str = str[3..<1] ;
	if (!NEWS_D->query_group(str)) {
	    write ("That group does not exist.\n") ;
	    return 1 ;
	}
	NEWS_D->remove_group(str) ;
	write ("Group "+str+" removed.\n") ;
	return 1 ;
    }
    if (!valid_group_name(str)) {
	write ("That is not a legitimate group name.\n") ;
	return 1 ;
    }
    if (NEWS_D->query_group(str)) {
	write ("That group already exists.\n") ;
	return 1 ;
    }
    NEWS_D->add_group(str) ;
    write ("Group "+str+" added.\n") ;
    return 1 ; 
}

// Help added by Dalto@TMI-2, 12-14-94
string help() {
   return(@HELP

Syntax: newsadm [-r] <group>

   The newsadm command is used for adding and removing groups from the
newsreader. It adds groups by default. If you wish to remove a group specify
the -r flag. If no group is named, the names of current groups are listed.

HELP
);
}
