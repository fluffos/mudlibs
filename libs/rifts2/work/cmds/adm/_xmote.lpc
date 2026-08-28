/*    /cmds/adm/_xmote.c

 *    from the Nightmare Mudlib 3.2

 *    a promote/demote style command for use with the Nightmare system

 *    created by Descartes of Borg 940124

 *    UPDATE: 3/17/94

 *    changed so that it modifies the /adm/groups.db file to add the

 *    promoted player to the database if he/she is not already there

 *    -Diewarzau (DarkeMUD)

 */



#include <std.h>

#include <security.h>

#define CHANGE_GROUPS ({ "superuser", "assist", "mentor", "elder", "wizard" })





inherit DAEMON;

 

void rewrite_groups_db(string name, string pos);



int cmd_xmote(string str) {

    string pos, nom;

    object ob;

    int lev;



    if(!archp(previous_object())) return 0;

    if(sscanf(str, "%s %s", nom, str) != 2)

      return notify_fail("Usage: <xmote [player] ([level]) ([position])>\n");

    if(!(ob = find_player(nom = lower_case(nom))))

      return notify_fail(sprintf("Cannot find %s anywhere.\n",capitalize(nom)));

    if(sscanf(str, "%d %s", lev, pos) != 2) {

        if(!sscanf(str, "%d", lev)) {

            seteuid(UID_LOG);

            log_file("xmote", sprintf("%s went to position %s thanks to "

              "%s on %s.\n", nom, str, (string)previous_object()->query_name(),

              ctime(time())));

            seteuid(UID_ADVANCE);

            ob->set_position(str);

	    rewrite_groups_db((string)ob->query_name(1),pos);

            seteuid(getuid());

            message("info", sprintf("%s is now position %s", capitalize(nom),

              str), this_player());

            message("info", sprintf("You have been xmoted to %s", str), ob);

            return 1;

        }

        seteuid(UID_LOG);

        log_file("xmote", sprintf("%s went to level %d thanks to %s on %s.\n",

          nom, lev, (string)previous_object()->query_name(), ctime(time())));

        seteuid(getuid());

        ob->set_level(lev);

        message("info", sprintf("%s is now level %d.", capitalize(nom), lev),

          this_player());

        message("info", sprintf("You have been xmoted to level %d.\n",lev),ob);

        return 1;

    }

    if(!member_group((string)this_player()->query_name(), "superuser")

	&& (pos == "assist" || pos == "superuser"))

	return notify_fail("You cannot xmote someone that high.\n");

    seteuid(UID_LOG);

    log_file("xmote", sprintf("%s went to position %s and level %d thanks to "

      "%s on %s.\n", nom, pos, lev, (string)previous_object()->query_name(),

      ctime(time())));

    seteuid(getuid());

    seteuid(UID_ADVANCE);

    ob->set_position(pos);

    rewrite_groups_db((string)ob->query_name(1),pos);

    seteuid(getuid());

    ob->set_level(lev);

    message("info", sprintf("%s is now level %d and position %s.\n",

      capitalize(nom), lev, pos), this_player());

    message("info", sprintf("You are now level %d %s.\n", lev, pos), ob);

    return 1;

}



void help() {

    message("help", "Syntax: <xmote [player] ([level]) ([position])>\n\n"

      "Changes the level, position, or both of a player.", this_player());

}



void rewrite_groups_db(string name, string pos) {

    string *groups_db;

    string old_euid, group;

    int i, start;



    name = lower_case(name);

    old_euid = geteuid(this_object());

    seteuid(UID_ADVANCE);

    groups_db = explode(read_file("/adm/db/groups.db"),"\n");

    start = member_array("("+pos+")",groups_db,1);

    if(start < 0) {

	seteuid(old_euid);

	return;

    }

    if(member_array(name,explode(groups_db[start]," ")) < 0)

	groups_db[start] += " "+name;

    rm("/adm/db/groups.db");

    for(i=0;i<sizeof(groups_db);i++) {

	if(groups_db[i][0..0] == "#") continue;

	else {

	    if(sscanf(groups_db[i],"(%s)%*s", group) &&

		group != pos && member_array(group,CHANGE_GROUPS) > -1)

                groups_db[i] = replace_string(groups_db[i]," "+name,"");

	}

    }

    for(i=0;i<sizeof(groups_db);i++) {

	write_file("/adm/db/groups.db",groups_db[i]+"\n");

    }

    master()->load_groups();

    seteuid(old_euid);

    return;

}

