/*    /std/light.c
 *    from Nightmare IV
 *    a standard lighting object
 *    created by Descartes of Borg 940427
 */

#include <std.h>
#include "light.h"

inherit WEAPON;

private int __SourceRequired, __Strength, __Fuel, __Fire, __FuelRequired;
private int __DisableCommands, __DisableWeapon, __BurntValue;
private string __CmdLight, __CmdExtinguish;
nosave private int __Lit, __TimeStamp;
nosave private mixed __PreventPut;
nosave private function __LightFunction, __ExtinguishFunction;

void create() {
    weapon::create();
    weapon::set_prevent_put( (: "check_lit" :) );
    set_vendor_type("light");
    __SourceRequired = 1;
    __Fuel = 120;
    __FuelRequired = 1;
    __Strength = 2;
    __BurntValue = 10;
    __Fire = 1;
    __CmdLight = "light";
    __CmdExtinguish = "extinguish";
}

void init() {
    weapon::init();
    if(__DisableCommands) return;
    add_action("cmd_light", __CmdLight);
    add_action("cmd_extinguish", __CmdExtinguish);
}

varargs void set_light(int strength, string lightcmd, string extcmd) {
    if(!intp(strength)) error("Bad argument 1 to set_light().\n");
    else if(lightcmd && !stringp(lightcmd))
      error("Bad argument 2 to set_light().\n");
    else if(extcmd && !stringp(extcmd))
      error("Bad argument 3 to set_light().\n");
    __Strength = strength;
    if(lightcmd) __CmdLight = lightcmd;
    if(extcmd) __CmdExtinguish = extcmd;
}

void set_strength(int x) { __Strength = x; }

int query_strength() { return __Strength; }

void set_fuel_required(int x) { __FuelRequired = x; }

int query_fuel_required() { return __FuelRequired; }

void set_source_required(int x) { __SourceRequired = x; }

int query_source_required() { return __SourceRequired; }

void set_fire(int x) { __Fire = x; }

int query_fire() { return __Fire; }

void set_fuel(int x) { __Fuel = x; }

void add_fuel(int x) {
    if(!query_fuel_required()) {
        __Fuel += x;
        if(__Fuel < 0) __Fuel = 0;
        return;
      }
    if(query_lit()) remove_call_out("go_dark");
    __Fuel += x;
    if(__Fuel < 0) {
        if(query_lit()) go_dark();
        __Fuel = 0;
        set_value(__BurntValue);
    }
    else if(query_lit()) call_out("go_dark", __Fuel);
}

int query_fuel() {
    if(!query_fuel_required()) return 1;
    if(!query_lit()) return __Fuel;
    return __Fuel - (time() - __TimeStamp);
}

void set_light_function(function f) {
    if(!functionp(f)) error("Bad argument 1 to set_light_function().\n");
    else __LightFunction = f;
}

function query_light_function() { return __LightFunction; }

void set_extinguish_function(function f) {
    if(!functionp(f)) error("Bad argument 1 to set_extinguish_function().\n");
    else __ExtinguishFunction = f;
}

function query_extinguish_function() { return __ExtinguishFunction; }

void set_lit(int x) {
    int tmp;

    if(x < 0) x = 0;
    tmp = x - __Lit;
    if(environment(this_object()))
      environment(this_object())->add_property("light", tmp);
    if(query_fire()) set_property("burning", x);
    if(__Lit && !x) {
        __Fuel -= time() - __TimeStamp;
        if(__Fuel < 1) {
            __Fuel = 0;
            set_value(__BurntValue);
        }
        remove_call_out("go_dark");
    }
    else if(x && !__Lit) {
        __TimeStamp = time();
        call_out("go_dark", query_fuel());
    }
    __Lit = x;
}

int query_lit() { return __Lit; }

void set_disable_commands(int x) { __DisableCommands = x; }

void set_disable_weapon(int x) { __DisableWeapon = x; }

void set_burnt_value(int x) { __BurntValue = x; }

int is_weapon() { return !__DisableWeapon; }

void set_prevent_put(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_prevent_put().\n");
    __PreventPut = val;
}

mixed query_prevent_put() { return __PreventPut; }

string query_short() {
   string str;

    if(!(str = weapon::query_short()) || str == "") return str;
    return sprintf("%s%s", str, (query_lit() ? " (lit)" : ""));
 }

varargs string query_long(string val) {
    string str;

    if(!(str = weapon::query_long(val)) || str == "") return str;
    else return sprintf("%s%s", str, (query_fuel() ? "" :
      sprintf("\nThe %s is out of fuel.", query_name())));
  }

int query_wc() {
    return (query_lit() ? weapon::query_wc() + 1 : weapon::query_wc());
  }

int move(mixed dest) {
    object ob;
    int x;

    if(ob=environment(this_object())) ob->add_property("light", -query_lit());
    x = weapon::move(dest);
    environment(this_object())->add_property("light", query_lit());
    return x;
}

int remove() {
    int x;

    if(environment(this_object()))
      environment(this_object())->add_property("light", -query_lit());
    x = weapon::remove();
    if(this_object() && environment(this_object()))
      environment(this_object())->add_property("light", query_lit());
    return x;
}

protected  void go_dark() {
    object ob;

    if(ob = environment(this_object())) {
        if(living(ob)) {
            message("environment", sprintf("Your %s goes dark.", query_name()),
              ob);
            message("environment", sprintf("%s %s goes dark.",
              possessive_noun((string)ob->query_cap_name()), query_name()),
              environment(ob), ({ ob }));
        }
        else message("environment", sprintf("%s goes dark.",
          query_cap_name()), ob);
    }
    set_lit(0);
}

int check_lit(object ob) {
    if(query_lit()) {
        message("my_action", sprintf("You cannot put %s in %s right now!",
          query_short(), (string)previous_object()->query_short()), ob);
        return 0;
      }
    if(stringp(__PreventPut)) {
        message("my_action", __PreventPut, ob);
        return 0;
      }
    else if(functionp(__PreventPut)) {
        return (*__PreventPut)(ob);
      }
    return 1;
  }

int cmd_light(string str) {
    string targ, src;
    object ob;

    if(!str) return notify_fail(sprintf("%s what?\n", capitalize(__CmdLight)));
    else str = lower_case(str);
    if(query_source_required()) {
        if(sscanf(str, "%s with %s", targ, src) != 2)
          return notify_fail(sprintf("%s %s with what?\n",
            capitalize(__CmdLight), query_short()));
        if(!(ob = present(src, this_player())))
          return notify_fail(sprintf("You do not have a %s!\n", src));
        if(!((int)ob->query_property("burning")))
          return notify_fail("You must have a source which is burning!\n");
        if(effective_light(this_player()) < 0)
          return notify_fail("It is too dark.\n");
        str = targ;
    }
    if(present(str, this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object()) return 0;
    if(query_lit()) {
        message("my_action", "It is already so!", this_player());
        return 1;
    }
    if(!query_fuel() && query_fuel_required()) {
        message("my_action", sprintf("You attempt to %s %s, but fail.",
          __CmdLight, query_short()), this_player());
        message("other_action", sprintf("%s attempts to %s %s, but fails.",
          (string)this_player()->query_cap_name(), __CmdLight, query_short()),
          environment(this_player()), ({ this_player() }));
        return 1;
    }
    if(__LightFunction) {
        if(!((int)(*__LightFunction)(ob))) return 1;
    }
    else {
        message("my_action", sprintf("You work successfully to %s %s%s.",
          __CmdLight, query_short(), (ob ? sprintf(" with %s",
          (string)ob->query_short()) : "")), this_player());
        message("other_action", sprintf("%s works successfully to %s %s%s.",
          (string)this_player()->query_cap_name(), __CmdLight, query_short(),
          (src ? sprintf("with %s", (string)ob->query_short()) : "")),
          environment(this_player()), ({ this_player() }));
    }
    set_lit(query_strength());
    if(ob) ob->add_fuel(-5);
    return 1;
}

int cmd_extinguish(string str) {
    if(!str) return notify_fail(sprintf("%s what?\n", __CmdExtinguish));
    else str = lower_case(str);
    if(present(str, this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object()) return 0;
    if(!query_lit()) {
        message("my_action", sprintf("%s is already so!", query_cap_name()),
          this_player());
        return 1;
    }
    if(__ExtinguishFunction) {
          if(!((int)(*__ExtinguishFunction)())) return 1;
    }
    else {
        message("my_action", sprintf("You successfully work to %s %s.",
          __CmdExtinguish, query_short()), this_player());
        message("other_action", sprintf("%s successfully works to %s %s.",
          (string)this_player()->query_cap_name(), __CmdExtinguish,
          query_short()), environment(this_player()), ({ this_player() }));
    }
    set_lit(0);
    return 1;
}

int cmd_wield(string str) {
    if(__DisableWeapon) return 0;
    else return weapon::cmd_wield(str);
}

int cmd_unwield(string str) {
    if(__DisableWeapon) return 0;
    else return weapon::cmd_unwield(str);
}
