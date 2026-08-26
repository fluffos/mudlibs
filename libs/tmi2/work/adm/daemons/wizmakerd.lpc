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

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int promote_wiz (object ob) {

	string prev ;
	object link ;

	prev = file_name(previous_object()) ;
	if (member_array(prev,PROMOTION_ROOMS)==-1) {
		return 0 ;
	}
	link = ob->query_link() ;
	link->set("wizard", 1) ;
        ob->enable_me() ;
	ob->set("PATH", NEW_WIZ_PATH);
	return 1 ;
}

