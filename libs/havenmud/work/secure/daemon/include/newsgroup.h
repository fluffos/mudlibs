/*
 * Newsgroup daemon header file
 *
 * Created by Zaxan@Haven
 *
 * 02-Aug-2004
 */

#ifndef H_DAEMON_NEWSGROUP
#define H_DAEMON_NEWSGROUP

private int check_security(object who);
private int GroupExists(string group);
private nosave void eventLoadGroups();
private nosave void eventLoadGroup(string name);
nomask string *GetAllowedGroupList(object who);
private int sort_imm_groups(string group1, string group2);
private mixed *categorize_imm_groups(string *groups);
nomask object GetGroup(string name);
nomask mapping GetGroups();

private void eventQuit(object who);

nomask int CheckUnreadPosts(object who, string group);
nomask void CheckLogonUnreadGroups(object who);

nomask void eventMainMenu(object who);
private string print_group_line(object who, object group, int index);
private void main_menu_parse(string args, object who, string *groups);
private void main_menu_command_list(object who, string *groups);

private void eventAddGroup(object who, string group);

private void eventDeleteGroup(object who, string group);

nomask void eventChangePlayerSetting(object who, string group, int setting);
nomask void eventSettingsMenu(object who, string group);
private void settings_menu_parse(string args, object who, string group);
private void settings_menu_parse_rank_restriction(
  string args,
  object who,
  string group,
  string type
);
private void settings_menu_parse_notification(string args, object who, string group);
private void settings_menu_command_list(object who, string group);

nomask void eventReadGroup(object who, string group);
private void read_group_parse(string args, object who, string group);
private void read_group_command_list(object who, string group);
private string query_friendly_time(int time);

private varargs void eventPost(object who, string group, string subject, int followup_post);
private void end_post(object who, string group, string subject);
private void followup_include_text(string args, object who, string group, mapping post);

#endif // H_DAEMON_NEWSGROUP
