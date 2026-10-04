#ifndef __NMSH_H
#define __NMSH_H

int Setup();
nomask protected int cmd_alias(string str);
nomask protected int cmd_cd(string str);
nomask protected int cmd_nickname(string str);
nomask protected int cmd_nmsh(string str);
nomask protected int cmd_pushd(string str);
nomask protected int cmd_popd();
nomask string write_prompt();
nomask string process_input(string str);
nomask protected void process_request(string request, string xtra);
protected int request_vis(object ob);
protected string user_name(object ob);
private int set_cwd(string str);
private void pushd(string str);
private string popd();
nomask private string do_nickname(string str);
nomask private string do_alias(string str);
nomask protected string replace_nickname(string str);
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
protected string cache_commands(string str);

#endif /* __NMSH_H */


