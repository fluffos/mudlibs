#ifndef __STORAGE_H
#define __STORAGE_H

int cmdPut(string str);
int cmdGet(string str);
int cmdOpen(string str);
int cmdClose(string str);
int cmdLock(string str);
int cmdUnlock(string str);
int eventPickLock();
varargs string GetLong(string str);
varargs int eventReceiveObject(object ob);
void SetCanClose(int x);
int GetCanClose();
void SetCanLock(int x);
int GetCanLock();
void SetClosed(int x);
int GetClosed();
void SetLocked(int x);
int GetLocked();
void SetKey(string str);
string GetKey();

#endif /* __STORAGE_H */
