#ifndef __DOOR_H__
#define __DOOR_H__

nosave void create();

varargs int eventOpen(object by, object agent);
varargs int eventClose(object by, object agent);
varargs int eventLock(object by, object agent);
varargs int eventUnlock(object by, object agent);
int eventRegisterSide(string dir);

nosave int SetClosed(int x);
int GetClosed();
nosave int SetLocked(int x);
int GetLocked();
mapping SetSide(string side, mapping mp);
int SetLockable(string side, int x);
int GetLockable(string side);
string SetId(string side, string id);
string GetId(string side);
mixed SetShort(string side, mixed short);
string GetShort(string side);
mixed SetLong(string side, mixed long);
string GetLong(string side);
string *SetKeys(string side, string *cles);
string *GetKeys(string side);
object *GetRooms(string side);

#endif /* __DOOR_H__ */

