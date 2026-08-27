#ifndef _DAEMON_H
#define _DAEMON_H

void create();
int remove();
void Destruct();
nomask int query_prevent_shadow();
void clean_up(int inh);
nomask void SetNoClean(int i);

#endif
