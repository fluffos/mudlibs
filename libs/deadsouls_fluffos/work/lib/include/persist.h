#ifndef l_persist_h
#define l_persist_h

protected int eventConvertObject(mixed val, int recurse);
int eventLoadObject(mixed val, int recurse);

protected mixed *AddSave(mixed *vars);
mixed *GetSave();
protected int SetSaveRecurse(int flag);
string GetSaveString();

/* pure virtual */int eventMove(mixed dest);

#endif /* l_persist_h */
