#ifndef __NMSH_H
#define __NMSH_H

void setup();
nomask  protected int cmd_alias(string str);
nomask  protected int cmd_cd(string str);
nomask  protected int cmd_history(string str);
nomask  protected int cmd_nickname(string str);
nomask  protected int cmd_nmsh(string str);
nomask  protected int cmd_pushd(string str);
nomask  protected int cmd_popd(string str);
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
nomask  protected string replace_null(string str);
nomask private void add_history_cmd(string str);
nomask  protected string replace_nickname(string str);
void reset_history();
void reset_prompt();
string query_cwd();
int query_history_size();
string query_prompt();
int query_mp();
int query_max_mp();
int query_hp();
int query_max_hp();
int query_sp();
int query_max_sp();
string get_path();
string query_client();
varargs int query_invis(object ob);
string query_name();

#endif /* __NMSH_H */
