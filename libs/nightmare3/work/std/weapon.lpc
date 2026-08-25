#include <config.h>
#include <std.h>
#include <move.h>

 
inherit OBJECT;
 
private int __Broken;
private mapping __Weapon;
 
int cmd_wield(string str);
int cmd_unwield(string str);
void set_ac(int x);
void set_wc(int x);
void set_hit(mixed val);
void set_wield(mixed val);
void set_unwield(mixed val);
void set_type(string str);
void set_decay_rate(int x);
void add_poisoning(int x);
int query_ac();
int query_wc();
mixed query_hit();
mixed query_wield();
mixed query_unwield();
string query_type();
int query_decay_rate();
int query_poisoning();
int is_weapon();
void unequip();
void __ActuallyUnwield();
void set_not_equipped();
void decay();
 
#ifdef __OLD_ROOM_BEHAVIOUR
#include <old_weapon.h>
#endif /* __OLD_ROOM_BEHAVIOUR */

void create() {
    ::create();
    set_vendor_type("weapon");
    __Weapon = ([]);
    __Broken = 0;
}
 
void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("cmd_wield", "wield");
    add_action("cmd_unwield", "unwield");
}
 
int cmd_wield(string str) {
    object ob;
    string what, hand1, hand2, ok;
 
    if(!str) return notify_fail("Wield what?\n");
    if(sscanf(str, "%s in %s", what, hand1) != 2)
      return notify_fail("In what hand?\n");
    if(!id(what)) {
        if(!(ob = parse_objects(this_player(), what))) return 0;
        if(ob != this_object()) return 0;
        what = query_name();
    }
    if(__Broken) {
        message("my_action", "You cannot wield this when broken!",
          this_player());
        return 1;
    }
    if(query("skill level") > (int)this_player()->query_skill(query_type()))
      return notify_fail("You do not have the talent to use that weapon.\n");
    if(__Weapon["wielded"]) {
        message("my_action", "You are already wielding that!\n",this_player());
        return 1;
    }
    if(__Weapon["type"] == "two handed") {
        str = hand1;
        if(sscanf(str, "%s and %s", hand1, hand2) != 2) {
            message("my_action", "You must wield such a weapon with two hands.\n",
              this_player());
            return 1;
        }
        if(functionp(__Weapon["wield"]) && !((*__Weapon["wield"])())) return 1;
        ok = (string)this_player()->equip_weapon_to_limb(this_object(), hand1,
          hand2);
    }
    else {
        if(sscanf(hand1, "%s and %s", str, hand2) == 2) {
            message("my_action", "You must only use one hand to wield that "+
              "weapon.", this_player());
            return 1;
        }
        if(functionp(__Weapon["wield"]) && !((*__Weapon["wield"])())) return 1;
        ok  = (string)this_player()->equip_weapon_to_limb(this_object(),hand1,0);
    }
    if(ok) {
        message("my_action", ok, this_player());
        return 1;
    }
    if(stringp(__Weapon["wield"]))
      message("my_action", __Weapon["wield"], this_player());
    else message("my_action", "You wield "+query_short()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name() +
      " wields " + query_short() + ".", environment(this_player()),
      ({ this_player() }));
    __Weapon["wielded"] = this_player();
    __Weapon["limb string"] = " (wielded in " + hand1 +
      (hand2 ? " and "+hand2+")" : ")");
    return 1;
}
 
int cmd_unwield(string str) {
    object ob;
 
    if(!str) return notify_fail("Unwield what?\n");
    if(!id(str)) {
        if(!(ob = parse_objects(this_player(), str)) || (ob != this_object()))
          return notify_fail("You don't have that!\n");
        str = query_name();
    }
    if(!__Weapon["wielded"])
      return notify_fail("You are not wielding that!\n");
    if(functionp(__Weapon["unwield"]) && !((*__Weapon["unwield"])())) return 1;
    __ActuallyUnwield();
    return 1;
}
 
void set_ac(int x) { __Weapon["ac"] = x; }
 
void set_wc(int x) {
    if(x>20) log_file("illegal", file_name(this_object())+": PRIV ("+
      query_privs(this_object())+") has a wc of "+x+"\n");
    if(!__Weapon["decay rate"]) __Weapon["decay rate"] = 10000/(x+1);
    __Weapon["wc"] = x;
    if(!__Weapon["original wc"]) __Weapon["original wc"] = x;
}
 
void set_hit(mixed val) {
    __Weapon["hit"] = val; 
}
 
void set_wield(mixed val) {
    __Weapon["wield"] = val;
}
 
void set_unwield(mixed val) {
    __Weapon["unwield"] = val;
}
 
void set_type(string str) { __Weapon["type"] = str; }
 
void set_decay_rate(int x) { __Weapon["decay rate"] = x; }
 
void add_poisoning(int x) {
    if(!__Weapon["poison"]) __Weapon["poison"] = x;
    else __Weapon["poison"] += x;
    if(__Weapon["poison"] < 1) map_delete(__Weapon, "poison");
}
 
string query_short() {
    if(!__Weapon["wielded"]) return ::query_short();
    else return ::query_short() + __Weapon["limb string"];
}
 
int query_ac() { return __Weapon["ac"]; }
 
int query_wc() { return __Weapon["wc"] + query_property("enchantment"); }
 
mixed query_hit() { return __Weapon["hit"]; }
 
mixed query_wield() { return __Weapon["wield"]; }
 
mixed query_unwield() { return __Weapon["unwield"]; }
 
string query_type() { return __Weapon["type"]; }
 
object query_wielded() { return __Weapon["wielded"]; }

int query_decay_rate() { return __Weapon["decay rate"]; }
 
int query_poisoning() { return __Weapon["poison"]; }
 
int is_weapon() { return 1; }
 
void unequip() { if(__Weapon["wielded"]) __ActuallyUnwield(); }
 
void __ActuallyUnwield() {
    __Weapon["wielded"]->remove_weapon_from_limb(this_object());
    if(stringp(__Weapon["unwield"]))
      message("my_action", __Weapon["unwield"], __Weapon["wielded"]);
    else message("my_action", "You unwield "+query_short()+".",
      __Weapon["wielded"]);
    message("other_action", (string)__Weapon["wielded"]->query_cap_name() +
      " unwields "+query_short()+".", environment(__Weapon["wielded"]),
      ({ __Weapon["wielded"] }));
    set_not_equipped();
}
 
void set_not_equipped() {
    map_delete(__Weapon, "wielded");
    map_delete(__Weapon, "limb string");
}
 
void decay() {
    if(!__Weapon["wc"]) return;
    __Weapon["decay status"]++;
    if(random(100000) < __Weapon["wc"]) {
        message("environment", "Your "+query_name()+" broke!",
          query_wielded());
        unequip();
        __Broken = 1;
    }
    if(__Weapon["decay status"] == __Weapon["decay rate"]) {
        __Weapon["wc"]--;
        set("value", 20+query("value")*__Weapon["wc"]/__Weapon["original wc"]);
        message("environment", "You notice some wear on your "+
          query_short()+".", __Weapon["wielded"]);
        __Weapon["decay status"] = 0;
    }
}

void set_skill_level(int x) { __Weapon["skill level"] = x; }

int query_skill_level() { return __Weapon["skill level"]; }

int move(mixed dest) {
    int x;

    if((x = ::move(dest)) != MOVE_OK) return x;
    unequip();
    return x;
}

int remove() {
    unequip();
    return ::remove();
}

int query_broken() { return __Broken; }
