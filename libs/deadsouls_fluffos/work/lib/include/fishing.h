#ifndef l_fishing_h
#define l_fishing_h

protected void create();
protected void init();
protected void heart_beat();

mixed CanStop(object who, string str);
mixed CanCast(object who, string str);

mixed eventCast(object who, object pole, string str);
protected void eventCatch(object who, string fish, object pole);
mixed eventStop(object who, string str);

int SetChance(int x);
int GetChance();
mapping SetFish(mapping mp);
mapping RemoveFish(string fish);
mapping GetFish();
mapping SetFishing(object who, object pole);
mapping RemoveFishing(object who);
int SetMaxFishing(int x);
int GetMaxFishing();
int SetSpeed(int x);
int GetSpeed();

#endif /* l_fishing_h */
