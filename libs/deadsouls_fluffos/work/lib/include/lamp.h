#ifndef l_lamp_h
#define l_lamp_h

protected void create();
protected void heart_beat();

mixed direct_light_obj();

mixed eventDarken();
varargs mixed eventLight(object who, object tool);

int GetBurnRate();
protected int SetBurnRate(int x);
int GetRadiantLight(int ambient);
string GetShort();
varargs string GetLong(string unused);

#endif /* l_lamp_h */

