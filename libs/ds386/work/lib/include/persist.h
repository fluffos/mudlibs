#ifndef l_persist_h
#define l_persist_h

nosave int eventConvertObject(mixed val, int recurse);
int eventLoadObject(mixed val, int recurse);

nosave mixed *AddSave(mixed *vars);
mixed *GetSave();
nosave int SetSaveRecurse(int flag);
string GetSaveString();

/* pure virtual */int eventMove(mixed dest);

#endif /* l_persist_h */
