#ifndef l_lamp_h
#define l_lamp_h

nosave void create();
nosave void heart_beat();

mixed direct_light_obj();

mixed eventDarken();
varargs mixed eventLight(object who, object tool);

int GetBurnRate();
nosave int SetBurnRate(int x);
int GetRadiantLight(int ambient);
string GetShort();
varargs string GetLong(string unused);

#endif /* l_lamp_h */
