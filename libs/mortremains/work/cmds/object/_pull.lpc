/*
** File: _pull.c   (A command)
** Author: Cyanide@Nightfall's Keep
** Date: 22 May 1997
** Note: The concept of this command was originally from 
**       Chronos@Against the Fall of Darkness. May his mud rest in peace.
*/

int cmd_pull(string);      /* Prototypes */
string help();

int cmd_pull (string str) {
    string str2;
    object ob, targ;

    if (!str) {
   write("Usage: pull <object> from <player>\n") ;
	return 1;
    }

    if (sscanf(str, "%s from %s", str, str2) != 2) {
     write("Usage: pull <object> from <player>\n") ;
	return 1;
    }

    targ = present(str2, environment(this_player()) );
    if (!targ)
	targ = find_player(str2);
    if (!targ) {
	write("There is no "+capitalize(str2)+" present.\n");
	return 1;
    }

    if (adminp(targ) && !adminp(TP)) {
	write("You cannot pull something from an admin!\n");
	return 1;
    }

    ob = present(str, targ);
    if (!ob) {
	write("There is no "+str+" present in "+capitalize(str2)+".\n");
	return 1;
    }

    ob->move(this_player());
    tell_object(targ, this_player()->query("cap_name")+" just removed "+
      ob->query("short")+" from your inventory.\n");
    write("You pull "+ob->query("short")+" from "+targ->query("cap_name")
      +".\n");
    return 1;
} //end cmd_pull()

string help() {
    string help;

    help = 
    "With this command, you can pull a choice item from any target's\n"+
    "inventory, be they player, monster, or wizard. Players and wizards\n"+
    "can be anywhere on the mud, but monsters must be in the room.\n";

    return help;
}
