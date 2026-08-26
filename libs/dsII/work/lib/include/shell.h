#ifndef l_shell_h
#define l_shell_h

nosave void create();

int SetCaliber(int x);
int SetMillimeter(int x);
int SetPistolType(string str);
int SetAmmoType(string str);
string GetType();
int GetCaliber();
int GetMillimeter();
string GetAmmoType();

#endif /* l_shell_h */
