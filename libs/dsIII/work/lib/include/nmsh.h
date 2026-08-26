#ifndef __NMSH_H
#define __NMSH_H

int Setup();
nomask nosave int cmd_alias(string str);
nomask nosave int cmd_cd(string str);
nomask nosave int cmd_nickname(string str);
nomask nosave int cmd_nmsh(string str);
nomask nosave int cmd_pushd(string str);
nomask nosave int cmd_popd();
nomask string write_prompt();
nomask string process_input(string str);
nomask nosave void process_request(string request, string xtra);
nosave int request_vis(object ob);
nosave string user_name(object ob);
nosave private int set_cwd(string str);
nosave private void pushd(string str);
nosave private string popd();
nomask nosave private string do_nickname(string str);
nomask nosave private string do_alias(string str);
nomask nosave string replace_nickname(string str);
void reset_prompt();
string query_cwd();
string GetPrompt();
int query_mp();
int query_max_mp();
int query_hp();
int query_max_hp();
int query_sp();
int query_max_sp();
string get_path();
string GetClient();
varargs int GetInvis(object ob);
string GetKeyName();
nosave string cache_commands(string str);

#endif /* __NMSH_H */


