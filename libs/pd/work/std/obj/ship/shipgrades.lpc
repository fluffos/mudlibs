//  Ship Upgrades Simulator
#include <security.h>
#define MIN_HP 20
#define MAX_SPEED 4
#define MAX_ARMOUR 3
#define MAX_CANNONS 2
#define SEP "**************************************************************"
int speed, armour, cannons, hp, *sunk;
void save();
int query_speed() { return (MAX_SPEED-speed); }
int query_actual_speed() { return speed; }
int query_armour() { return armour; }
int query_cannons() { return cannons; }
int query_hp() { return hp; }
int query_max_hp() { return armour*MIN_HP; }
void set_speed(int i) { speed=i; save(); }
void set_armour(int i) { armour=i; save(); }
void set_cannons(int i) { cannons=i; save(); }
void set_hp(int i) { hp=i; save(); }
void add_hp(int i) { hp=hp+i; save(); if(hp> query_max_hp()) this_object()->sink(); save(); }
string get_status_string() {
    string tmp;
    int i,i2;
    tmp=SEP+"\n";
    switch(query_speed()) {
    case 0: tmp += "Your ship has extra-large sails for maximum speed.\n"; break;
    case 1: tmp += "Your ship has large sails for fast speed.\n"; break;
    case 2: tmp += "Your ship has medium sails for moderate speed.\n"; break;
    case 3: tmp += "Your ship has small sails for slow speed.\n"; break;
    case 4: tmp += "Your ship has small sails for slow speed.\n"; break;
    default: tmp += "Unknown Speed Rating.\n"; break;
    }
    switch(query_armour()) {
    case 0: tmp += "Your ship has no armour.\n"; break;
    case 1: tmp += "Your ship has light armour.\n"; break;
    case 2: tmp += "Your ship has medium armour.\n"; break;
    case 3: tmp += "Your ship has heavy armour.\n"; break;
    default: tmp += "Unknown Armour Rating.\n"; break;
    }
    switch(query_cannons()) {
    case 0: tmp += "Your ship is weaponless.\n"; break;
    case 1: tmp += "Your ship has one cannon.\n"; break;
    case 2: tmp += "Your ship has two cannons.\n"; break;
    case 3: tmp += "Your ship has three cannons.\n"; break;
    default: tmp += "Unknown Cannon Rating.\n"; break;
    }
    sscanf(percent(query_hp(), query_max_hp())+"", "%d.%d", i, i2);
    if(i>=100) tmp += "%^BOLD%^%^RED%^Your ship is utterly destroyed and will be sinking at any moment.%^RESET%^"; else
    if(i > 90) tmp += "%^BOLD%^%^RED%^Your ship is mortally damaged.%^RESET%^"; else
    if(i > 60) tmp += "Your ship is severly damaged."; else
    if(i > 30) tmp += "Your ship damaged.\n"; else
    if(i > 10) tmp += "Your ship is partially damaged."; else
    if(i>1) tmp += "Your ship is hardly scratched."; else
	tmp += "Your ship is not damaged.";
    tmp += "  ("+i+"% damaged)";
    tmp += "\n"+SEP+"\n";
    return tmp;
}
varargs void load(string s) {
    restore_object("/adm/save/boats/"+s);
    this_object()->create();
}
void create() {
    if(!armour) armour=1;
}
void save() { 
    seteuid("BoatSave"); 
    save_object("/adm/save/boats/"+this_object()->query_owner()); 
    seteuid(geteuid());
}
void set_sunk(int *i) { sunk=i; save(); }
int *query_sunk() { return sunk; }
