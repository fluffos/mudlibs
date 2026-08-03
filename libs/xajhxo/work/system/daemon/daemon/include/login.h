#ifndef __LOGIN_H
#define __LOGIN_H

void create(); 
void logon( object );
private void GetIdentify( string, object );
private void get_passwd( string, object );
private void confirm_relogin( string, object, object );
private void confirm_id( string, object );
private void get_name( string, object );
private void new_password( string, object );
private void confirm_password(string pass, object ob);
private void get_email(string email, object ob);
private void get_gender(string gender, object ob, object user);
object make_body(object ob);
private void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int set_wizlock(int level);
private string select_start_room();
private void log_login( object, object, string );
private int select_max_age(object user);

#endif /* __LOGIN_H */
