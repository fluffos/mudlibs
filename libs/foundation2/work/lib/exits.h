#ifndef __EXITS_H__
#define __EXITS_H__

nosave void create();
int cmdGo(string str);
int cmdEnter(string str);
int cmdLock(string which);
int cmdUnlock(string which);
int cmdOpen(string which);
int cmdClose(string which);
mapping SetExits(mapping mp);
varargs mapping AddExit(string dir, string dest, function pre, function post);
mapping RemoveExit(string dir);
string GetExit(string dir);
string *GetExits();
mapping SetEnters(mapping mp);
varargs mapping AddEnter(string dir, string dest, function pre, function post);
mapping RemoveEnter(string dir);
string GetEnter(string dir);
string *GetEnters();
string GetDirection(string dest);
string SetDoor(string dir, string file);
string GetDoor(string dir);
string *GetDoors();

#endif /* __EXITS_H__ */
