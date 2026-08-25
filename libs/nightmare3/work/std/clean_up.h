#ifndef __CLEAN_UP_H
#define __CLEAN_UP_H

#define NEVER_AGAIN               0
#define TRY_AGAIN_LATER           1

int clean_up();
int move(mixed dest);
int remove();
protected void set_no_clean(int x);
int query_no_clean();

#endif /* __CLEAN_UP_H */
