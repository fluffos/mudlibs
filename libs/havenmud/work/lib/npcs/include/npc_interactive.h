#ifndef l_interactive_h
#define l_interactive_h

nosave void create();
int inventory_accessible();
int inventory_visible();

int Setup();
void eventDescribeEnvironment(int brief);
int eventDestruct();
int eventMove(mixed dest);
void SetId(string *bogus);
string *GetId();
int id(string str);
string SetKeyName(string str);
string GetKeyName();
string GetShort();
string GetLong();
void SetCapName(string str);
string SetShort(string str);
string SetLong(string str);
string GetName();
varargs int GetInvis(object ob);
mixed *GetCommands();
string GetSpouse();
int GetRadiantLight(int ambient);

void eventLoad(mixed *value, int recurse);

/* pure virtual */ int GetEffectiveVision();

#endif /* l_interactive_h */
