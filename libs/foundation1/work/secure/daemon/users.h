#ifndef __USERS_H
#define __USERS_H

void change_password(string who, string passwd);
void xmote(string who, string pos, int lev);
void suicide(string who);
private void delete_user(string who);
void setup();
int remove();

#endif /* __USERS_H */
