#ifndef l_meal_h
#define l_meal_h

nosave void create();
mixed direct_drink_obj();
mixed direct_drink_from_obj();
mixed direct_eat_obj();

nosave void eventDecay();
int SetDecayTime(int x);
int GetDecayTime();
mixed eventDrink(object who);
mixed eventEat(object who);
mixed eventPoison(object who, object agent, int x);

string SetEmptyItem(string file);
string GetEmptyItem();
string SetEmptyName(string str);
string GetEmptyName();
mixed SetEmptyShort(mixed str);
mixed GetEmptyShort();
mixed SetEmptyLong(mixed str);
mixed GetEmptyLong();
int SetLit(int x);
int GetLit();
int SetMealType(int x);
int GetMealType();
int SetStrength(int x);
int GetStrength();
int SetPortions(int);
varargs int AddPortion(int, object);
int GetPortions();
varargs void SetMealMessages(mixed *val...);
mixed *GetMessages();
int GetValue();

// mahkefel: store fish support
// for ships.
mixed direct_store_obj();

#endif /* l_meal_h */
