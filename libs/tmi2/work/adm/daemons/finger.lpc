//
// File : /adm/daemons/finger.c
//
// An improved interface to provide the information required by the "finger"
// command, as well as other essential information about the user, that may
// not be available when they are not logged in.
//
// This version of the finger daemon was written by Buddha@TMI-2, with some
// existing code from the old finger daemon (most of which he also did).
// This is part of the TMI-2 distribution mudlib.
// Please retain this header.
//
// Bug - bad argument 1 to extract() line 133
//   possibly caused by someone being half logged in
//   Mobydick thinks he fixed this bug, hasn't had the chance to test it.
//   2-15-93.
// Watcher eliminated references to users when the user is inhabiting a
//   monster body (3/22/93)
// Watcher added in wizard label to specific user finger (4/3/93)
// Made to respect invisible status by Spock @ TMI-2 4/4/93
// Watcher rewrote the invisible checks to use the visible() efun, added
//   the checks to the finger_all function, and added an alphabetic sort on
//   the general finger output, 4/25/93.
// 
// I fixed a problem where this_player() was used, and the call was
// from a remote mud. It might be broken on more places, but if
// the logs won't mind, i won't bother for now. Leto 011895

#include <uid.h>
#include <config.h>
#include <mudlib.h>
#include <login_macros.h>
#include <daemons.h>
#include <mailer.h>

inherit DAEMON;

#define LINE1 \
"=+=--=+=--=+=--=+=--=+=--=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=\n"
#define LINE2 \
"----------------------------------------------------------------------------\n"

// prototypes for local functions
string finger_group(string group);
int filter_users(object who);

mapping groups;

void create() {
    seteuid(ROOT_UID);
}

//  This function is called to restore the user's connection object that
//  holds the essential login information.  If the user in question is
//  currently logged in, then their current connection object is returned,
//  otherwise it is restored.  You should probably call clean_up() on the
//  object when finished, and it will either self-destruct, if not interactive
//  or associated to a body, or save and wait for further information
//  requests, if it is.
object restore_data(string name) {
    object link;

    if (find_player(name) && interactive(find_player(name))) {
        return (object)find_player(name)->query_link();
    }

    link = new(CONNECTION);
    seteuid(name);
    export_uid(link);
    seteuid(ROOT_UID);

    link->set("name", name);
    if (link->restore()) {
        return link;
    }

    // If this fails, then let's clean up afterwards...
    link->remove();
   // Some names like .foo weren't getting away.
    if(link) destruct(link);
    if(link) log_file("fingerdest",sprintf("Connection of %s not dested by finger daemon, on %s.\n", name, ctime(time())));
    return 0;
}

string finger_user(string who) {
    object link;
    mixed tmp1, tmp2, tmp3, tmp4, tmp5;
    string msg;
    mapping mail_stat;
    int hibernate;

    link = restore_data(who);
    if (!link) {
        if (sscanf(who, "(%s)", who))
            return finger_group(who);
        return "Finger: There is no such user.\n";
    }

    tmp1 = "Login name: " + who;
    tmp2 = "In real life: ";
    if (tmp3 = (string)link->RNAME)
        tmp2 += extract(tmp3, 0, 22);
    else
        tmp2 += "?";

    tmp4 = DOMAIN_D->query_domain(link);
    tmp5 = DOMAIN_D->query_domain_level(link);
    if ((tmp4 == 0) || (tmp4 == ""))
        tmp4 = "None";
    tmp4 = "Domain: " + tmp4 + " (" + tmp5 + ")";

    msg = sprintf("%-38s%-38s\n", tmp1, tmp2);
    tmp1 = user_path(who);
    if (file_size(tmp1) == -1)
        tmp1 = "(none)";
    msg += sprintf("%-38s%-38s\n", "Directory: " + tmp1, tmp4);

    msg += "Status: ";
    if (adminp((string)link->query("name")))
        msg += "Admin\n";
    else if (link->query("wizard"))
        msg += "Wizard\n";
    else
        msg += "Player\n";

    tmp1 = find_player(who);

    hibernate = (int)link->query("hibernate");

    if (hibernate && time() < hibernate)
        msg += "\n\t[In hibernation until " + ctime(hibernate) + "]\n\n";

    if (tmp1) {
        if (!filter_users(tmp1))
            tmp1 = 0;
    }

    if (!link->query("last_on"))
        msg += (tmp1 ? "On since: " : "Last on: ") + "Unavailable\n";
    else
        msg += ((tmp1 && !tmp1->query("npc")) ? "On since: " : "Last on: ") +
              ctime((int)link->query("last_on")) + " from " +
              (string)link->query("ip") + " \n";

    if (tmp1) {
        tmp1 = query_idle_string(tmp1, 1);
        if (strlen(tmp1) > 0)
            msg += tmp1 + "\n";
    }

    mail_stat = (mapping)MAILBOX_D->mail_status(who);
    if (mail_stat["unread"])
        msg += sprintf("%s has not read %d of their %d piece%s of mail.\n",
              capitalize(who), mail_stat["unread"], mail_stat["total"],
              (mail_stat["total"] == 1 ? "" : "s"));
    else {
	msg += "No unread mail" ;
   if(this_player()) {
	if (adminp(getuid(this_player()))) {
	//  msg += " ("+mail_stat["total"]+" pieces)" ;
	    msg += sprintf(" (%d piece%s)", mail_stat["total"], (mail_stat["total"] == 1 ? "" : "s"));
	}
 }
	msg += ".\n" ;
 }
    tmp1 = (string)link->query("email");
    msg += "Email address: " + tmp1 + "\n";

    tmp1 = user_path(who) + ".project";
    if (file_size(tmp1) >= 0)
        msg += "Project: " + read_file(tmp1);

    tmp1 = user_path(who) + ".plan";
    if (file_size(tmp1) >= 0) {
        msg += "Plan:\n" + read_file(tmp1);
    } else {
        msg += "No Plan.\n";
    }

    if (!find_player(who) || !interactive(find_player(who))) {
        link->remove();
        // Some names like .foo weren't getting away.
        if(link) destruct(link);
        if(link) log_file("fingerdest",sprintf("Connection of %s not dested by finger daemon, on %s.\n", link->query("name"), ctime(time())));
    }

    return "\n" + msg + "\n";
}

string finger_group(string group) {
    int i, j;
    string msg;
    object link;
    mixed tmp1, tmp2, tmp3, tmp4, tmp5;
    string *group2;

    groups = master()->query_groups();
    if (!group || undefinedp(groups[group]))
        return "Finger: There is no such group.\n";

    /*
     * special case: filter root members out of admin group
     */
//    if (group == "admin")
//        groups["admin"] = filter_array(groups["admin"], "filter_root", this_object());

    group2 = groups[group];
    j = group2 ? sizeof(group2) : 0;

    msg = LINE1;
    if (j == 0) {
        msg += "[" + capitalize(mud_name()) + "] No members of " +
              capitalize(group) + " group (" + ctime(time()) + ").\n";
    } else {
        msg += "[" + capitalize(mud_name()) + "] " + j +
              (j == 1 ? " user" : " users") + " " +
              "in " + capitalize(group) + " group (" + ctime(time()) + ").\n";
        msg += LINE2;
        msg += sprintf("%-12s%-20s%-14s%-28s", "Login", "Real Name",
              "Domain", "On\n");
        msg += LINE2;
        group2 = sort_array(group2, "do_alpha", this_object());
        for (i = 0; i < j; i++) {
            tmp1 = group2[i]; /* logid id */
            link = find_player(tmp1);
            if (link)
                link = link->query_link();
            else
                link = restore_data(tmp1);
            if (!link)
                continue; /* no such user */

            tmp2 = (string)link->RNAME; /* real name */

            tmp3 = DOMAIN_D->query_domain(link);
            if ((tmp3 == 0) || (tmp3 == ""))
                tmp3 = "None";

            tmp4 = find_player(tmp1);
            if (!tmp4 || !filter_users(tmp4))
                tmp5 = "Last  ";
            else
                tmp5 = "Since ";
            if (!link->query("last_on"))
                tmp5 += "(Unavailable)";
            else
                tmp5 += ctime((int)link->query("last_on"));

            msg += sprintf("%-12s%-20s%-14s%28s",
                  capitalize((string)tmp1),
                  capitalize(extract((string)tmp2, 0, 18)),
                  capitalize((string)tmp3),
                  (string)tmp5 + "\n");

            if (!find_player(tmp1))
                link->remove();
        }
    }

    return msg + LINE1;
}

string finger_all() {
    object *who, link;
    int i, j;
    string msg;

    who = users();
    who = filter_array(who, "filter_users", this_object());

    who = sort_array(who, "sort_users", this_object());
    j = who ? sizeof(who) : 0;

    msg = LINE1;
    if (j == 0) {
        msg += "[" + capitalize(mud_name()) + "] No one is presently " +
              "connected (" + ctime(time()) + ").\n";
    } else {
        msg += "[" + capitalize(mud_name()) + "] " + j +
              (j == 1 ? " user" : " users") + " " +
              (j == 1 ? "is " : "are ") + "presently connected (" +
              ctime(time()) + ").\n";
        msg += LINE2;
        msg += sprintf("%-12s%-20s%-14s%-7s%-21s", "Login", "Real Name",
              "Position", "Idle", "Where\n");
        msg += LINE2;
    }
    for (i = 0; i < j; i++) {
        link = (object)who[i]->query_link();
        if (!link || !link->RNAME)
            continue;

        msg += sprintf("%-12s%-20s%-14s%-7s%-21s",
              capitalize((string)link->NAME),
              capitalize(extract((string)link->RNAME, 0, 18)),
              capitalize((string)DOMAIN_D->query_domain_level(link)),
              query_idle_string(who[i], 0),
              extract(query_ip_name(who[i]), 0, 20) + "\n");
   }

   return msg + LINE1;
}

//  This function filters out any invisible and monster-inhabiting users.
int filter_users(object who) {
    if (!this_player() && who->query("invisible"))
        return 0;
    else if (!visible(who, this_player()))
        return 0;

    return !((int)who->query("npc"));
}

// This function filters out root members from admin group
int filter_root(string who) {
    if (member_array(who, groups["root"]) > -1)
        return 0;
    return 1;
}

//  This function sorts the members in alphabetical order.
int do_alpha(string str1, string str2) {
    return strcmp(str1, str2);
}

//  This function sorts the users in alphabetical order.
int sort_users(object one, object two) {
    return strcmp((string)one->NAME, (string)two->NAME);
}
