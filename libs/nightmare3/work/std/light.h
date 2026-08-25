#ifndef __LIGHT_H
#define __LIGHT_H

varargs void set_light(int strength, string lightcmd, string extcmd);
void set_strength(int x);
int query_strength();
void set_fuel_required(int x);
int query_fuel_required();
void set_source_required(int x);
int query_source_required();
void set_fire(int x);
int query_fire();
void set_fuel(int x);
void add_fuel(int x);
int query_fuel();
void set_light_function(function f);
function query_light_function();
void set_extinguish_function(function f);
function query_extinguish_function();
void set_lit(int x);
int query_lit();
void set_disable_commands(int x);
void set_disable_weapon(int x);
void set_burnt_value(int x);
int is_weapon();
void set_prevent_put(mixed val);
mixed query_prevent_put();
string query_short();
varargs string query_long(string val);
int query_wc();
int move(mixed dest);
int remove();
protected  void go_dark();
int check_lit(object ob);
int cmd_light(string str);
int cmd_extinguish(string str);
int cmd_wield(string str);
int cmd_unwield(string str);

#endif /* __LIGHT_H */
