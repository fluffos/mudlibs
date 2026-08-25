#ifndef __REMOTEPOST_H
#define __REMOTEPOST_H

string postal_check(string mud);
string next_post(string mud);
string resend_post(string mud);
void send_post(mapping borg, string mud);
int incoming_post(mapping info);
private string *local_targets(string *str);
private void save_mailqueue();
private void restore_mailqueue();
private string *convert_names(string *noms);
mapping query_mail_queue();

#endif /* __REMOTE_POST_H */
