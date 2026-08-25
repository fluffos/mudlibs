//	/bin/adm/_end.c
//    	from the Nightmare mudlib
//	admin command to load armageddon
//	created by Descartes of Borg

#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>

inherit DAEMON;

int cmd_end(string str) {
    object ob;

    if(!archp(previous_object())) return 0;
     if(this_player()->query_forced()) return 0;
    ob = new(OB_SHUT);
    ob->move(ROOM_START);
    SHUT_D->reboot_mud(to_int(str) ? to_int(str) : 20);
    write("Ok.\n");
    log_file("game_log", "Armageddon loaded by "+this_player()->query_name()+": "+ctime(time())+"\n");
    return 1;
}

int help()
{
    write( @EndText
Syntax: end
Effect: Starts the armageddon process.
See also: shutdown
EndText
    );
    return 1;
}
