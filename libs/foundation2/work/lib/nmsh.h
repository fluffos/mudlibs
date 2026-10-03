#ifndef __NMSH_H
#define __NMSH_H

int Setup();
nomask protected int cmd_alias(string str);
nomask protected int cmd_cd(string str);
nomask protected int cmd_history(string str);
nomask protected int cmd_nickname(string str);
nomask protected int cmd_nmsh(string str);
nomask protected int cmd_pushd(string str);
nomask protected int cmd_popd(string str);
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
nomask private string do_history(string str);
nomask protected string replace_null(string str);
nomask private void add_history_cmd(string str);
nomask protected string replace_nickname(string str);
void reset_history();
void reset_prompt();
string query_cwd();
int query_history_size();
string GetPrompt();
string GetCapName();
string get_path();
string GetClient();
varargs int GetInvis(object ob);
string GetKeyName();
protected string cache_commands(string str);

#endif /* __NMSH_H */
