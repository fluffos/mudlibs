#ifndef l_fuel_h
#define l_fuel_h

protected void create();

mixed eventDecreaseFuel(int x);
mixed eventRefuel(int x);

int GetFuelAmount();
protected int SetFuelAmount(int x);
string GetFuelType();
protected string SetFuelName(string str);
varargs string GetLong(string val);
int GetMaxFuel();
protected int SetMaxFuel(int x);
int GetRefuelable();
protected int SetRefuelable(int x);

/* pure virtual */ string GetShort();

#endif /* l_fuel_h */
