#ifndef l_light_h
#define l_light_h

nosave void create();

mixed direct_light_obj(object target);

mixed eventDarken();
varargs mixed eventLight(object who, object tool);

int GetLit();
nosave int SetLit(int x);
string GetShort();

/* pure virtual */ string GetKeyName();

#endif /* l_light_h */
