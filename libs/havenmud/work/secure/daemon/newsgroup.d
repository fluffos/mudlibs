/*
 * Newsgroup daemon
 *
 * Keeps track of all newsgroups. Also used
 * by boards lib.
 *
 * Created by Zaxan@Haven
 *
 * 26-Jul-2004
 */

#include <lib.h>
#include <daemons.h>
#include <newsnotify.h>
#include <message_class.h>

#include "include/newsgroup.h"

inherit LIB_DAEMON;

// Basically the idea here is that the person changing
// the setting sees "Race Restriction", but internally
// it will call "SetRaceRestriction". The idea is that
// way, we can use a loop instead of a bunch of manual
// code.
private string *Restrictions = ({ "Race Restriction",
	                          "Town Restriction",
			          "Guild Restriction",
			          "Class Restriction",
			          "Religion Restriction",
			          "Friendly Name" });

private static mapping __Newsgroups = ([ ]);

static void create()
{
    daemon::create();
    
    SetNoClean(1);
    eventLoadGroups();
}

private int check_security(object who)
{
    if (this_player() != who)
    {
	error("Unauthorized newsgroup operation.");
	return 0;
    }

    return 1;
}

private int GroupExists(string group)
{
    if (member_array(group, keys(__Newsgroups)) == -1)
	return 0;
    else return 1;
}

private static void eventLoadGroups()
{
    string *groups;

    groups = get_dir(DIR_NEWSGROUPS + "/");

    if (!sizeof(groups)) return;

    foreach (string group in groups)
    {
	if (group[<2..] != ".o")
	    continue;

	eventLoadGroup(group);
    }
}

private static void eventLoadGroup(string name)
{
    object *existing = ({ });
    object ob = __Newsgroups[name];

    name = name[0..<3];

    // Make sure it's a valid newsgroup
    if (!unguarded( (: file_exists, DIR_NEWSGROUPS + "/" + name + __SAVE_EXTENSION__ :)))
    {
	error("No such newsgroup: "+name);
	return;
    }

    // Try to find an existing one
    existing = children(LIB_NEWSGROUP);
    foreach(object exists in existing)
    {
	if (exists->GetGroupId() == name)
	{
	    __Newsgroups[name] = exists;
	    return;
	}
    }

    ob = new(LIB_NEWSGROUP, name);
    __Newsgroups[name] = ob;
}

nomask string *GetAllowedGroupList(object who)
{
    string *groups = ({ });
    string *roomgroups = environment(who)->GetNewsgroups();

    foreach(string group in keys(__Newsgroups))
    {
	object groupob = GetGroup(group);

	if (!groupob) return ({ });

	if (member_array(group, roomgroups) == -1 && !creatorp(who) &&
		base_name(previous_object(1)) != LIB_CONNECT)
	{
	    continue;
	}

	if (groupob->check_read_access())
	{
	    groups += ({ group });
	}
    }

    if (creatorp(who))
    {
	return sort_array(groups, (: sort_imm_groups :));
    }
    else return sort_array(groups, 1);
}

// This sorts groups into a list that first has Imm-only newsgroups
// followed by Imm-post/Player-read newsgroups, followed by
// fully player-accessible newsgroups.
private int sort_imm_groups(string group1, string group2)
{
    object grp1 = GetGroup(group1);
    object grp2 = GetGroup(group2);
    int readrank1 = grp1->GetReadRankRestriction();
    int readrank2 = grp2->GetReadRankRestriction();
    int postrank1 = grp1->GetPostRankRestriction();
    int postrank2 = grp2->GetPostRankRestriction();

    if (readrank1 > 1) // Group 1 == Imm+ only
    {
	if (readrank2 > 1) // Group 2 == Imm+ only
	{
	    return strcmp(group1, group2);
	}
	else return -1; // Group2 == Player accessible in some fashion
    }
    else
    {
	if (postrank1 > 1) // Group 1 == Player read-only
	{
	    if (readrank2 > 1) // Group 2 == Imm+ only
	    {
		return 1;
	    }
	    else
	    {
		if (postrank2 > 1) // Group 2 == Player read-only
		{
		    return strcmp(group1, group2);
		}
		else
		{
		    return -1; // Group 2 == Player read/post
		}
	    }
	}
	else // Group 1 == Player read/post
	{
	    if (readrank2 > 1) // Group2 == Imm+ only
	    {
		return 1;
	    }
	    else
	    {
		if (postrank2 > 1) // Group 2 == Player read-only
		{
		    return 1;
		}
		else
		{
		    return strcmp(group1, group2); // Group 2 == Player read/post
		}
	    }
	}
    }
}

// Splits the list of gropus into three separate
// lists.
private array categorize_imm_groups(string *groups)
{
    array ret = allocate(3);
    object grp;
    int i = 0;

    ret[0] = ({ });
    ret[1] = ({ });
    ret[2] = ({ });
    if (!sizeof(groups)) {
      return ret;
    }
    // First, Imm+ only
    grp = GetGroup(groups[i]);
    while (grp->GetReadRankRestriction() > 1)
    {
	ret[0] += ({ groups[i] });
	i++;
	grp = GetGroup(groups[i]);
    }

    // Then, player read-only
    while(grp->GetPostRankRestriction() > 1)
    {
	ret[1] += ({ groups[i] });
	i++;
	grp = GetGroup(groups[i]);
    }

    // Then, player read-write
    while(i < sizeof(groups))
    {
	ret[2] += ({ groups[i] });
	i++;
    }

    return ret;
}

nomask object GetGroup(string name)
{
    object ob = __Newsgroups[name];

    if (!ob || undefinedp(ob))
    {
	eventLoadGroup(name+".o");
    }

    ob = __Newsgroups[name];

    return ob;
}

nomask mapping GetGroups() { return __Newsgroups; }

private void eventQuit(object who)
{
    who->eventPrint("Goodbye.");
}

nomask int CheckUnreadPosts(object who, string group)
{
    object grp = GetGroup(group);

    if (grp->UserHasUnreadPosts(who->GetKeyName()))
    {
	return 1;
    }

    return 0;
}

nomask void CheckLogonUnreadGroups(object who)
{
    string *list = ({ });
    
    foreach (string group in GetAllowedGroupList(who))
    {
	if (who->GetNewsgroupNotifySetting(group) & NEWS_NOTIFY_LOGON &&
		CheckUnreadPosts(who, group))
	{
	    list += ({ group });
	}
    }

    if (sizeof(list))
    {
	who->eventPrint("");
	foreach(string group in list)
	{
	    object grp = GetGroup(group);

	    who->eventPrint("%^YELLOW%^BOLD%^You have unread posts in the "+
		    (creatorp(who) ? group : grp->GetFriendlyName())+" group.%^RESET%^");
	}
    }
}

nomask void eventMainMenu(object who)
{
    string *groups = GetAllowedGroupList(who);
    string *immgroups = ({ });
    string *msg = ({ });

    if (creatorp(who))
    {
	immgroups = categorize_imm_groups(groups);
    }

    if (!check_security(who)) return 0;

    if (!sizeof(groups))
    {
	if (!creatorp(who))
	{
	    who->eventPrint("No groups are available at this location.");
	}
	else
	{
	    who->eventPrint("No groups are available to you.");
	}
	if (!sagep(who)) return;
    }
    else
    {
	msg += ({ "The following groups are available: \n" });
    }

    if (creatorp(who))
    {
	int i=0;
	if (sizeof(immgroups[0]))
	{
	    msg += ({ "Immortal-only groups:" });
	    foreach(string g in immgroups[0])
	    {
		object grp = GetGroup(g);

		msg += ({ print_group_line(who, grp, i) });
		i++;
	    }
	}
	if (sizeof(immgroups[1]))
	{
	    msg += ({ "\nPlayer read-only groups:" });
	    foreach(string g in immgroups[1])
	    {
		object grp = GetGroup(g);

		msg += ({ print_group_line(who, grp, i) });
		i++;
	    }
	}
	if (sizeof(immgroups[2]))
	{
	    msg += ({ "\nPlayer full-access groups:" });
	    foreach(string g in immgroups[2])
	    {
		object grp = GetGroup(g);

		msg += ({ print_group_line(who, grp, i) });
		i++;
	    }
	}
    }
    else
    {
	for(int i=0; i<sizeof(groups); i++)
	{
	    object grp = GetGroup(groups[i]);

	    msg += ({ print_group_line(who, grp, i) });
	}
    }

    who->eventPage(msg, MSG_SYSTEM, (: main_menu_command_list :), who, groups);
}

private string print_group_line(object who, object group, int index)
{
    if (creatorp(who))
    {
	return sprintf("[%:2d] %:-5s %:-25s (%s)",
		    index+1,
		    (group->UserHasUnreadPosts(who->GetKeyName()) ? "(new)" : "     "),
		    group->GetGroupId()+(group->GetPostRankRestriction() > rank(who) ? " [r/o]" : ""), group->GetFriendlyName());
    }
    else
    {
	return sprintf("[%:2d] %:-5s %s",
		    index+1,
		    (group->UserHasUnreadPosts(who->GetKeyName()) ? "(new)" : "     "),
		    group->GetFriendlyName()+(group->GetPostRankRestriction() > rank(who) ? " [r/o]" : ""));
    }
}

private void main_menu_parse(string args, object who, string *groups)
{
    int groupid = to_int(args);
    string group = "";
    int unread_grp = -1;

    args = lower_case(args);

    if (groupid && !undefinedp(groupid))
    {
	args = "read "+trim(args);
    }

    if ((trim(args) == "" || trim(args) == "r"))
    {
	// Determine the next unread group
	for(int i = 0; i < sizeof(groups); i++)
	{
	    if (CheckUnreadPosts(who, groups[i]))
	    {
		unread_grp = i+1;
		break;
	    }
	}

	if (unread_grp != -1)
	{
	    who->eventPrint("Proceeding to next unread group.");
	    args = "read "+unread_grp;
	}
	else
	{
	    who->eventPrint("You have read all your news.");
	    main_menu_command_list(who, groups);
	    return;
	}
    }

    if ((args[0] == 'a' || args[0..2] == "add") && sagep(who))
    {
	if (sscanf(args, "a %s", group) == 1 ||
	    sscanf(args, "add %s", group) == 1)
	{
	    eventAddGroup(who, group);
	    return;
	}
	else
	{
	    who->eventPrint("Syntax: [a]dd <group name>");
	    main_menu_command_list(who, groups);
	    return;
	}
    }

    if ((args[0] == 'd' || args[0..5] == "delete") && sagep(who))
    {
	if (sscanf(args, "d %d", groupid) == 1 ||
	    sscanf(args, "delete %d", groupid) == 1)
	{
	    groupid -= 1;

	    if (groupid < 0 || groupid >= sizeof(groups))
	    {
		who->eventPrint("Invalid group number.");
		main_menu_command_list(who, groups);
		return;
	    }

	    if (rank(who) < GetGroup(groups[groupid])->GetPostRankRestriction())
	    {
		who->eventPrint("You are not permitted to delete this group.");
		main_menu_command_list(who, groups);
		return;
	    }

	    eventDeleteGroup(who, groups[groupid]);
	    return;
	}
	else
	{
	    who->eventPrint("Syntax: [d]elete <group #>");
	    main_menu_command_list(who, groups);
	    return;
	}
    }

    if ((args[0] == 'r' || args[0..3] == "read"))
    {
	if (sscanf(args, "r %d", groupid) == 1 ||
	    sscanf(args, "read %d", groupid) == 1)
	{
	    groupid -= 1;

	    if (groupid < 0 || groupid >= sizeof(groups))
	    {
		who->eventPrint("Invalid group number.");
		main_menu_command_list(who, groups);
		return;
	    }

	    eventReadGroup(who, groups[groupid]);
	    return;
	}
	else
	{
	    who->eventPrint("Syntax: [r]ead <group #>");
	    main_menu_command_list(who, groups);
	    return;
	}
    }

    if (args[0] == 's' || args[0..7] == "settings")
    {
	if (sscanf(args, "s %d", groupid) == 1 ||
		sscanf(args, "settings %d", groupid) == 1)
	{
	    groupid -= 1;

	    if (groupid < 0 || groupid >= sizeof(groups))
	    {
		who->eventPrint("Invalid group number.");
		main_menu_command_list(who, groups);
		return;
	    }

	    eventSettingsMenu(who, groups[groupid]);
	    return;
	}
	else
	{
	    who->eventPrint("Syntax: [s]ettings <group #>");
	    main_menu_command_list(who, groups);
	    return;
	}
    }

    if (args == "q" || args == "quit")
    {
	eventQuit(who);
	return;
    }

    who->eventPrint("Invalid choice!");
    main_menu_command_list(who, groups);
}

private void main_menu_command_list(object who, string *groups)
{
    string *cmds = ({ });

    if (sagep(who))
    {
	cmds += ({ "[a]dd <group name>" });
	if (sizeof(groups))
	{
	    cmds += ({ "[d]elete <group #>" });
	}
    }
    
    cmds += ({ "[r]ead <group #>",
	       "[s]ettings <group #>",
	       "[q]uit" });
    
    who->eventPrint("\nAvailable commands: "+implode(cmds, ", "));
    message("prompt", "Command: ", who);
    input_to((: main_menu_parse :), who, groups);
}

private void eventAddGroup(object who, string group)
{
    object ob;

    if (GroupExists(group))
    {
	who->eventPrint("A group by that name already exists.\n");
	eventMainMenu(who);
	return;
    }
    
    ob = new(LIB_NEWSGROUP, group);
    ob->save_newsgroup();
    __Newsgroups[group] = ob;

    who->eventPrint("You should now configure your new newsgroup.\n");
    eventSettingsMenu(who, group);
}

private void eventDeleteGroup(object who, string group)
{
    who->eventPrint("Are you sure you want to delete the group "+group+"? [y|n]");
    message("prompt", "Command: ", who);
    input_to(function(string args, object wob, string grp)
    {
	args = lower_case(args);
	
	if (args == "y" || args == "yes")
	{
	    object ob = GetGroup(grp);
	    ob->eventDestruct();
	    map_delete(__Newsgroups, grp);
	    unguarded( (: rename, DIR_NEWSGROUPS + "/" + grp + __SAVE_EXTENSION__,
		    DIR_NEWSGROUPS + "/" + grp + ".deleted" :) );

	    wob->eventPrint("Group "+grp+" removed.\n");
	    eventMainMenu(wob);
	    return;
	}

	if (args == "n" || args == "no")
	{
	    wob->eventPrint("Canceled.\n");
	    eventMainMenu(wob);
	    return;
	}

	wob->eventPrint("Invalid choice!\n");
	eventDeleteGroup(wob, grp);
    }, who, group);
}

nomask void eventChangePlayerSettings(object who, string group, string setting)
{
    int val;

    setting = lower_case(setting);

    if (setting != "none" && setting != "logon" && setting != "all")
    {
	who->eventPrint("Invalid setting.");
	return;
    }

    switch(setting)
    {
	case "none": default:
	    val = NEWS_NOTIFY_NONE;
	    break;
	case "logon":
	    val = NEWS_NOTIFY_LOGON;
	    break;
	case "all":
	    val = NEWS_NOTIFY_ALL;
	    break;
    }

    who->SetNewsgroupNotifySetting(group, val);
    who->eventPrint("Setting changed.\n");
}

nomask void eventSettingsMenu(object who, string group)
{
    object grp;
    int i = 0;
    int notify, readrank, postrank;
    string friendly_notify, friendly_read_rank, friendly_post_rank;

    if (member_array(group, GetAllowedGroupList(who)) == -1)
    {
	who->eventPrint("No such group.");
	return;
    }

    grp = GetGroup(group);
    notify = who->GetNewsgroupNotifySetting(group);
    readrank = grp->GetReadRankRestriction();
    postrank = grp->GetPostRankRestriction();
    friendly_notify = "";
    friendly_read_rank = (readrank == 7 ? "Greater Deity" : string_rank(readrank));
    friendly_post_rank = (postrank == 7 ? "Greater Deity" : string_rank(postrank));

    switch(notify)
    {
	case NEWS_NOTIFY_LOGON:
	    friendly_notify = "At logon";
	    break;
	case NEWS_NOTIFY_ALL:
	    friendly_notify = "All times";
	    break;
	case NEWS_NOTIFY_NONE:
	default:
	    friendly_notify = "Never";
	    break;
    }

    if (creatorp(who))
    {
        who->eventPrint("Available settings for "+group+":\n");
    }
    else
    {
	who->eventPrint("Available settings for "+grp->GetFriendlyName()+":\n");
    }
    who->eventPrint("Personal settings:");
    who->eventPrint(sprintf("[%:2d] %-25s [current: %s",
			i+1, "Receive Notification",
			friendly_notify+"]"));

    if (sagep(who))
    {
	who->eventPrint("\nGroup settings:");
	for (i = 0; i < sizeof(Restrictions); i++)
	{
	    string GetFunction = "Get"+implode(explode(Restrictions[i], " "), "");

	    who->eventPrint(sprintf("[%:2d] %-25s [current: %s",
			i+2,  Restrictions[i],
			call_other(grp, GetFunction))+"]");
	}
    }

    if (rank(who) >= grp->GetPostRankRestriction() && sagep(who))
    {
	who->eventPrint(sprintf("[%:2d] %-25s [current: %s\n"
		    "[%:2d] %-25s [current: %s",
		    i+2, "Read Rank Restriction",
		    friendly_read_rank+"]",
		    i+3, "Post Rank Restriction",
		    friendly_post_rank+"]"));
    }

    who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
    message("prompt", "Command: ", who);
    input_to( (: settings_menu_parse :), who, group);
}

private void settings_menu_parse(string args, object who, string group)
{
    object grp = GetGroup(group);
    int settingid = to_int(args);

    args = lower_case(args);

    if (args == "b" || args == "back")
    {
	eventMainMenu(who);
	return;
    }

    if (args == "q" || args == "quit")
    {
	eventQuit(who);
	return;
    }

    if (!settingid || undefinedp(settingid) || settingid <= 0 || 
	(sagep(who) && settingid > sizeof(Restrictions)+3) ||
	(settingid > 1 && !sagep(who)) ||
	(settingid > 7 && (grp->GetPostRankRestriction() > rank(who))))
    {
	who->eventPrint("Invalid setting number.");
	settings_menu_command_list(who, group);
	return;
    }

    switch(settingid)
    {
	case 1:
	    who->eventPrint("Select your notification preference for this group:\n\n"
		            "[1] Never\n"
			    "[2] At logon\n"
			    "[3] All times");

	    who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
	    message("prompt", "Command: ", who);
	    input_to( (: settings_menu_parse_notification :), who, group);
	    break;
	case 8: case 9:
	    who->eventPrint("Select your new rank restriction:\n");
	    for(int i = 1; i <= 7; i++)
	    {
		if (i > rank(who)) // Don't let them lock themselves out
		{
		    break;
		}
		who->eventPrint(sprintf("[%d] %s", i, (i == 7 ? "Greater Deity" : string_rank(i))));
	    }
	    who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
	    message("prompt", "Command: ", who);
	    input_to( (: settings_menu_parse_rank_restriction :), who, group,
		    (settingid == 8 ? "Read" : "Post"));
	    break;
	default:
	    message("prompt", "Enter a new value: ", who);
	    input_to(function(string args, object wob, object grp, int index)
	    {
		string SetFunction = "Set"+implode(explode(Restrictions[index], " "), "");

		call_other(grp, SetFunction, args);
		wob->eventPrint("Settings changed.\n");
		eventSettingsMenu(wob, grp->GetGroupId());
	    }, who, GetGroup(group), settingid-2);
	    break;
    }
}

private void settings_menu_parse_rank_restriction(string args, object who, string group, string type)
{
    int choiceid = to_int(args);

    args = lower_case(args);

    if (args == "b" || args == "back")
    {
	eventSettingsMenu(who, group);
	return;
    }

    if (args == "q" || args == "quit")
    {
	eventQuit(who);
	return;
    }

    if (!choiceid || undefinedp(choiceid) ||
	    choiceid <= 0 || choiceid > 9 ||
	    choiceid > rank(who))
    {
	who->eventPrint("Invalid choice!");
	who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
	message("prompt", "Command: ", who);
	input_to( (: settings_menu_parse_rank_restriction :), who, group, type);
	return;
    }

    // Read restriction cannot be higher than
    // the post restriction.
    if (type == "Read" && choiceid > GetGroup(group)->GetPostRankRestriction())
    {
	who->eventPrint("You cannot set the read restriction higher than the post restriction!");
	who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
	message("prompt", "Command: ", who);
	input_to( (: settings_menu_parse_rank_restriction :), who, group, type);
	return;
    }

    call_other(GetGroup(group), "Set"+type+"RankRestriction", choiceid);

    who->eventPrint("Settings changed.\n");
    eventSettingsMenu(who, group);
}

private void settings_menu_parse_notification(string args, object who, string group)
{
    int choiceid = to_int(args);
    int val;

    args = lower_case(args);

    if (args == "b" || args == "back")
    {
	eventSettingsMenu(who, group);
	return;
    }

    if (args == "q" || args == "quit")
    {
	eventQuit(who);
	return;
    }

    if (!choiceid || undefinedp(choiceid) ||
	    choiceid <= 0 || choiceid > 3)
    {
	who->eventPrint("Invalid setting number.");
	who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
	message("prompt", "Command: ", who);
	input_to( (: settings_menu_parse_notification :), who, group);
	return;
    }

    switch(choiceid)
    {
	case 1: default:
	    val = NEWS_NOTIFY_NONE;
	    break;
	case 2:
	    val = NEWS_NOTIFY_LOGON;
	    break;
	case 3:
	    val = NEWS_NOTIFY_ALL;
	    break;
    }

    who->SetNewsgroupNotifySetting(group, val);
    who->eventPrint("Setting changed.\n");
    eventSettingsMenu(who, group);
}

private void settings_menu_command_list(object who, string group)
{
    who->eventPrint("\nAvailable commands: <setting #>, [b]ack, [q]uit");
    message("prompt", "Setting: ", who);
    input_to( (: settings_menu_parse :), who, group);
}

nomask void eventReadGroup(object who, string group)
{
    object grp;
    mapping *posts;
    string *msg = ({ });
    
    if (member_array(group, GetAllowedGroupList(who)) == -1)
    {
	who->eventPrint("No such group.");
	return;
    }

    grp = GetGroup(group);
    posts = grp->GetPosts();

    if (!sizeof(posts))
    {
	who->eventPrint("There are currently no posts.");
	read_group_command_list(who, group);
	return;
    }
    else
    {
	msg += ({ (creatorp(who) ? "Group "+group : grp->GetFriendlyName())+" contains the following posts:\n" });
	for(int i = 0; i < sizeof(posts); i++)
	{
	    mapping post = posts[i];
	    int unread = 0;

	    if (member_array(who->GetKeyName(), post["read"]) == -1)
	    {
		unread = 1;
	    }

	    msg += ({ sprintf("[%:-3d] %:-5s %:-17s \"%:-27s %s", i+1,
			    (unread ? "(new)" : ""), capitalize(post["author"]+":"),
			    post["subject"]+"\"", query_friendly_time(post["time"])) });
	}

	who->eventPage(msg, MSG_SYSTEM, (: read_group_command_list :), who, group);
    }
} 

private void read_group_parse(string args, object who, string group)
{
    object grp = GetGroup(group);
    int selection = to_int(args);
    string subject = "";
    int unread_post = -1;
    int unread_grp = -1;
    mapping *posts = grp->GetPosts();
    string *groups = GetAllowedGroupList(who);

    args = lower_case(args);

    if (selection && !undefinedp(selection))
    {
	args = "read "+trim(args);
    }

    if ((trim(args) == "" || trim(args) == "r"))
    {
	// Find next unread post
	for(int i = 0; i < sizeof(posts); i++)
	{
	    if (member_array(who->GetKeyName(), posts[i]["read"]) == -1)
	    {
		unread_post = i+1;
		break;
	    }
	}
	if (unread_post != -1)
	{
	    who->eventPrint("Proceeding to next unread post.");
	    args = "read "+unread_post;
	}
	else
	{
	    // Find next unread group
	    for(int j = 0; j < sizeof(groups); j++)
	    {
		if (CheckUnreadPosts(who, groups[j]))
		{
		    unread_grp = j+1;
		}
	    }
	    if (unread_grp != -1)
	    {
		who->eventPrint("Proceeding to next unread group.");
		main_menu_parse("read "+unread_grp, who, groups);
		return;
	    }
	    else
	    {
		who->eventPrint("You have read all your news.");
		read_group_command_list(who, group);
		return;
	    }
	}
    }

    if (args == "b" || args == "back")
    {
	eventMainMenu(who);
	return;
    }

    if (args == "q" || args == "quit")
    {
	eventQuit(who);
	return;
    }

    if ((args[0] == 'p' || args[0..3] == "post") &&
	    rank(who) >= grp->GetPostRankRestriction())
    {
	if (sscanf(args, "p %s", subject) == 1 ||
		    sscanf(args, "post %s", subject) == 1)
	{
	    if (trim(subject) == "")
	    {
		who->eventPrint("Syntax: [p]ost <subject>");
		read_group_command_list(who, group);
		return;
	    }
	    eventPost(who, group, subject);
	    return;
	}
	else
	{
	    who->eventPrint("Syntax: [p]ost <subject>");
	    read_group_command_list(who, group);
	    return;
	}
    }

    if (sizeof(grp->GetPosts()))
    {
	if (args[0] == 'r' || args[0..3] == "read")
	{
	    if (sscanf(args, "r %d", selection) == 1 ||
		    sscanf(args, "read %d", selection) == 1)
	    {
		string txt = grp->GetPostText(who->GetKeyName(), selection-1);
		
		if (!txt)
		{
		    who->eventPrint("Invalid post number.");
		    read_group_command_list(who, group);
		    return;
		}

		who->eventPrint("");
		who->eventPage(explode(txt, "\n"), MSG_SYSTEM, 
			function(object who_obj, string group_string)
			{
			    message("prompt", "Hit <enter>:\n", who_obj);
			    input_to(function(string garbage, object wob, string groupstr)
			    {
				eventReadGroup(wob, groupstr);
			    }, who_obj, group_string);
			}, who, group);
		return;
	    }
	    else
	    {
		who->eventPrint("Syntax: [r]ead <post #>");
		read_group_command_list(who, group);
		return;
	    }
	}

	if (args[0] == 'f' || args[0..7] == "followup")
	{
	    if (sscanf(args, "f %d", selection) == 1 ||
		    sscanf(args, "followup %d", selection) == 1)
	    {
		mapping post = grp->GetPost(selection-1);
		
		if (!post)
		{
		    who->eventPrint("Invalid post number.");
		    read_group_command_list(who, group);
		    return;
		}

		message("prompt", "Include text of parent post (default 'n'): ", who);
		input_to( (: followup_include_text :), who, group, post);
		return;
	    }
	    else
	    {
		who->eventPrint("Syntax: [f]ollowup <post #>");
		read_group_command_list(who, group);
		return;
	    }
	}

	if (args[0] == 'd' || args[0..5] == "delete")
	{
	    if (sscanf(args, "d %d", selection) == 1 ||
		    sscanf(args, "delete %d", selection) == 1)
	    {
		mapping post = grp->GetPost(selection-1);

		if (!post)
		{
		    who->eventPrint("Invalid post number.");
		    read_group_command_list(who, group);
		    return;
		}
		
		if (who->GetKeyName() != post["author"] && !sagep(who))
		{
		    who->eventPrint("You are not permitted to remove that post.");
		    eventReadGroup(who, group);
		    return;
		}

		grp->RemovePost(selection-1);
		who->eventPrint("Post removed.");
		eventReadGroup(who, group);
		return;
	    }
	    else
	    {
		who->eventPrint("Syntax: [d]elete <post #>");
		read_group_command_list(who, group);
		return;
	    }
	}
    }
    
    who->eventPrint("Invalid choice!");
    read_group_command_list(who, group);
}

private void read_group_command_list(object who, string group)
{
    object grp;
    mapping *posts;
    int postrank;
    string *cmds = ({ });
    
    grp = GetGroup(group);
    posts = grp->GetPosts(); 
    postrank = grp->GetPostRankRestriction();

    if (sizeof(posts))
    {
	cmds += ({ "[r]ead <post #>" });
    }

    if (rank(who) >= postrank)
    {
	cmds += ({ "[p]ost <subject>",
		   "[f]ollowup <post #>",
		   "[d]elete <post #>" });
    }

    cmds += ({ "[b]ack", "[q]uit" });

    who->eventPrint("\nAvailable commands: "+implode(cmds, ", "));
    message("prompt", "Command: ", who);
    input_to( (: read_group_parse :), who, group);
}

private string query_friendly_time(int time)
{
    return ctime(time);
}

private varargs void eventPost(object who, string group, string subject, int followup_post)
{
    string file = DIR_TMP + "/" + who->GetKeyName();
    int include_original = 0;

    if (file_exists(file) && followup_post)
    {
	include_original = 1;
    }

    if (file_exists(file) && !followup_post)
	rm(file);
   
    who->eventPrint("New post by %^YELLOW%^"+capitalize(who->GetKeyName())+"%^RESET%^");
    who->eventPrint("Subject: %^CYAN%^"+subject+"%^RESET%^");
    if (include_original && creatorp(who))
    {
	who->eventPrint("To begin typing your message, type 'i <enter>'");
    }
    who->eventPrint("To save"+(include_original && creatorp(who) ? " after typing your message" : "")+", type '. <enter> x <enter>'");
    who->eventPrint("To cancel"+(include_original && creatorp(who) ? " anytime while typing your message" : "")+", type '. <enter> Q <enter>'\n");
    who->eventEdit(file, (: end_post, who, group, subject :));
}

private void end_post(object who, string group, string subject)
{
    string file = DIR_TMP + "/" + who->GetKeyName();
    string post = read_file(file);
    object grp = GetGroup(group);

    if (!post)
    {
	who->eventPrint("Post aborted.\n");
	eventReadGroup(who, group);
	return;
    }

    rm(file);
    grp->AddPost(who->GetKeyName(), subject, post);
    who->eventPrint("Message posted!\n");
    
    foreach(object user in users())
    {
	if (user == who) continue;

	if (user->GetNewsgroupNotifySetting(group) & NEWS_NOTIFY_ONLINE)
	{
	    user->eventPrint((creatorp(user) ? "%^YELLOW%^BOLD%^" : "" )+ "A new post has been made to the "+
		    (creatorp(user) ? grp->GetGroupId() : grp->GetFriendlyName())+
		    " group.%^RESET%^");
	}
    }
    
    eventReadGroup(who, group);
}

private void followup_include_text(string args, object who, string group, mapping post)
{
    string file = DIR_TMP + "/" + who->GetKeyName();
    string msg = "";

    args = lower_case(args);

    if (args == "y" || args == "yes")
    {
	if (creatorp(who)) msg += "\n";
	msg += capitalize(post["author"]) + " once wrote...\n> ";
	msg += implode(explode(post["post"], "\n"), "\n> ")+"\n";
	if (!creatorp(who)) msg += "\n";
	write_file(file, msg);
    }
    else if (args != "" && args != "n" && args != "no")
    {
	message("prompt", "Include text of parent post (default 'n'): ", who);
	input_to( (: followup_include_text :), who, group, post);
	return;
    }

    eventPost(who, group, "RE: "+post["subject"], 1);
}
