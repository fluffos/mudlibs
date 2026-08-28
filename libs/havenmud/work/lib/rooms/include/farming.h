#ifndef l_farming_h
#define l_farming_h

nosave void create();
nosave void init();
nosave void heart_beat();

mixed CanStop(object who, string str);
mixed CanCast(object who, string str);

mixed eventCast(object who, object pole, string str);
nosave void eventCatch(object who, string farm, object pole);
mixed eventStop(object who, string str);

int SetChance(int x);
int GetChance();
mapping SetFarm(mapping mp);
mapping RemoveFarm(string farm);
mapping GetFarm();
mapping SetFarming(object who, object pole);
mapping RemoveFarming(object who);
int SetMaxFarming(int x);
int GetMaxFarming();
int SetSpeed(int x);
int GetSpeed();

#endif /* l_farming_h */
