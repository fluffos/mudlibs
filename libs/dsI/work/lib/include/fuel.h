#ifndef l_fuel_h
#define l_fuel_h

nosave void create();

mixed eventDecreaseFuel(int x);
mixed eventRefuel(int x);

int GetFuelAmount();
nosave int SetFuelAmount(int x);
string GetFuelType();
nosave string SetFuelName(string str);
varargs string GetLong(string val);
int GetMaxFuel();
nosave int SetMaxFuel(int x);
int GetRefuelable();
nosave int SetRefuelable(int x);

/* pure virtual */ string GetShort();

#endif /* l_fuel_h */
