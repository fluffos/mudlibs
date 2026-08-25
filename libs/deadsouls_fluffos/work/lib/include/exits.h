#ifndef l_exits_h
#define l_exits_h

protected void create();

mixed CanFly(object who, string dest);
mixed CanGo(object who, string str);

mixed eventFly(object who, string dir);
mixed eventGo(object who, string str);

mixed GetDoor(string dir);
string* GetDoors();
string SetDoor(string dir, string file);
string GetDirection(string dest);
object GetDummyItem(mixed id);
varargs void AddEnter(string dir, string dest, function pre, function post);
string GetEnter(string dir);
protected mapping GetEnterData(string str);
string* GetEnters();
void RemoveEnter(string dir);
void SetEnters(mapping mp);
string GetEnterMessage();
string SetEnterMessage(string str);
varargs mapping AddExit(string dir, string dest, function pre, function post);
string GetExit(string str);
protected mapping GetExitData(string str);
string* GetExits();
mapping RemoveExit(string dir);
mapping SetExits(mapping mp);
string GetGoMessage();
string SetGoMessage(string str);
string GetObviousExits();
string SetObviousExits(string str);
string GetSky();
string SetSky(string str);
string ResolveObjectName(string file);

#endif /* l_exits_h */
