// DarkeMUD generic weapon object.  See /doc/build/weapons for information
// on using.
// Modified by Geldron 031096 to fix bugs
// -Diewarzau 3/19/94

#include <config.h>
#include <std.h>

#define VALID_TYPES ({ "rusted", "cheap", "decent", "fine", "very fine",\
	"superb", "unsurpassed" })


inherit OBJECT;

//members and property setter/getters
private mapping __Weapon;
string _damage;
void set_damage(string roll) {_damage=roll;}
string query_damage(){return _damage;}
int _md=0;
void set_md(int i) {_md=i;}
int is_md() {return _md;}

int __Wield(string str);
int __Unwield(string str);
string query_verb();
void set_verb(string verb);
void set_hit(mixed val);
void set_wield(mixed val);
void set_unwield(mixed val);
void set_type(string str);
mixed query_hit();
mixed query_wield();
mixed query_unwield();
void set_short(string desc);
object query_wielded();
string query_type();
int is_weapon();
void unequip();
void __ActuallyUnwield();
void set_not_equipped();
#ifdef __OLD_ROOM_BEHAVIOUR
#include <old_weapon.h>
#endif /* __OLD_ROOM_BEHAVIOUR */

void create() {
    ::create();
    __Weapon = ([]);
    __Weapon["verb"] = "hit";
}

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("__Wield", "wield");
    add_action("__Unwield", "unwield");
    if(__Weapon["throwable"])
      add_action("throw_me", "throw");
}

void set_throwable(int x) { __Weapon["throwable"] = x; }

int throw_me(string arg) {
  string what, at, *wield_limbs;
  object who;
  int res, i;

  if(sscanf(arg, "%s at %s", what, at) != 2) return 0;
  if(environment(this_player())->query_property("no attack")) {
    write("Mystic forces prevent your aggression.");
    return 1;
  }
  wield_limbs = (string *)this_player()->query_wielding_limbs();
  if(!wield_limbs || !(i=sizeof(wield_limbs))) {
    write("You cannot throw a weapon with no wielding limbs!");
    return 1;
  }
  res = 0;
  while(i--)
    if(!this_player()->query_weapon(wield_limbs[i])) res = 1;
  if(!res) {
    write("You must have a free hand to throw a weapon.");
    return 1;
  }
  if(present(what, this_player()) != this_object()) return 0;
  if(time() - (int)this_player()->query("last throw") < 4) {
    write("You may only throw a weapon every other round.");
    return 1;
  }
  this_player()->set("last throw", time());
  if(this_object()->query_wielded()) {
    write("You may not throw a wielded weapon.");
    return 1;
  }
  who = present(at, environment(this_player()));
  if(!who) {
    write("There is no '"+at+"' here.");
    return 1;
  }
  if(!living(who)) {
    write("You could do that, but I doubt it would do much good.");
    return 1;
  }
  message("my_combat", "You throw " + article((string)this_object()->
					      query_name()) +
	  " at "+ (string)who->query_cap_name()+".", this_player());
  res = (skill_contest((int)this_player()->query_skill("thrown"),
		       ((int)who->query_skill("dodge") -
			to_int(percent((int)who->query_internal_encumbrance(),
				       (int)who->
				       query_max_internal_encumbrance()))),
		       1) != 1 && !who->query_paralyzed());
  res = (res || skill_contest((int)this_player()->query_skill("thrown"),
			      (int)who->query_skill("parry missile"), 1) != 1);
  who->kill_ob(this_player(), 1);
  if(res) {
    message("my_combat", "You miss pitifully.", this_player());
    message("other_combat", (string)this_player()->query_cap_name() +
	    " misses you with "+article((string)this_object()->query_name())+
	    " which "+nominative(this_player())+ " threw at you.",
	    who);
    message("other_combat", (string)this_player()->query_cap_name()+
	    " hurls "+article((string)this_object()->query_name())+
	    " at "+ (string)who->query_cap_name() + 
	    " but misses pitifully.", all_inventory(environment(this_player())),
	    ({ this_player(), who }) );
    this_object()->remove();
    return 1;
  }
  message("other_combat", (string)this_player()->query_cap_name() +
	  " hits you with "+article((string)this_object()->query_name())+
	  " which "+nominative(this_player())+ " threw at you.",
	  who);
  message("my_combat", "You hit "+objective(who)+"!", this_player());
  message("other_combat", (string)this_player()->query_cap_name()+
	  " hurls "+article((string)this_object()->query_name())+ 
	  " at "+ (string)who->query_cap_name() +
	  ", hitting "+ objective(who)+".",
	  all_inventory(environment(this_player())),
	  ({ this_player(), who }) );
  
  this_object()->remove();
  return 1;
}

string query_long(string null)
{
    string res;

    if (::query_long(null))
        res = ::query_long(null);
    /* Added by Geldron 031096, fixes a couple bugs */
    if (!res)
        res = "";
    if (stringp(query_type()))
        res += sprintf("\nThis weapon uses the skill: %s.\n",
                       query_type());    
    return res;
}

int __Wield(string str)
{
    object ob;
    function *funx;
    int i;
    string what, hand1, hand2, ok;

    if (!str)
        return notify_fail("Wield what?\n");
    if (sscanf(str, "%s in %s", what, hand1) != 2)
        return notify_fail("In what hand?\n");
    if (!id(what))
    {
        if (!(ob = parse_objects(this_player(), what)))
            return 0;
        if (ob != this_object())
            return 0;
        what = query_name();
    }

    if (__Weapon["wielded"])
    {
        message("my_action", "You are already wielding that!\n", this_player());
        return 1;
    }
    if (__Weapon["type"][0..9] == "two handed")
    {
        str = hand1;
        if (sscanf(str, "%s and %s", hand1, hand2) != 2)
        {
            message("my_action", "You must wield such a weapon with two hands.\n",
                    this_player());
            return 1;
        }
        if (functionp(__Weapon["wield"]) && !((*__Weapon["wield"])()))
            return 1;
        if (pointerp(__Weapon["wield"]))
        {
            funx = __Weapon["wield"];
            i = sizeof(funx);
            while (i--)
                if (!(*funx[i])())
                    return 1;
        }
        ok = (string)this_player()->equip_weapon_to_limb(this_object(), hand1,
                                                         hand2);
    }
    else
    {
        if (sscanf(hand1, "%s and %s", str, hand2) == 2)
        {
            message("my_action", "You must only use one hand to wield that " + "weapon.", this_player());
            return 1;
        }
        if (pointerp(__Weapon["wield"]))
        {
            funx = __Weapon["wield"];
            i = sizeof(funx);
            while (i--)
                if (!(*funx[i])())
                    return 1;
        }
        if (functionp(__Weapon["wield"]) && !((*__Weapon["wield"])()))
            return 1;
        ok = (string)this_player()->equip_weapon_to_limb(this_object(), hand1, 0);
    }
    if (ok)
    {
        message("my_action", ok, this_player());
        return 1;
    }
    if (stringp(__Weapon["wield"]))
        message("my_action", __Weapon["wield"], this_player());
    else
        message("my_action", "You wield " + query_short() + ".", this_player());
    message("other_action", (string)this_player()->query_cap_name() + " wields " + query_short() + ".", environment(this_player()),
            ({this_player()}));
    __Weapon["wielded"] = this_player();
    __Weapon["limb string"] = " (wielded in " + hand1 +
                              (hand2 ? " and " + hand2 + ")" : ")");
    return 1;
}

int __Unwield(string str) {
    object ob;
    function *funx;
    int i;

    if(!str) return notify_fail("Unwield what?\n");
    if(!id(str)) {
	if(!(ob = parse_objects(this_player(), str)) || (ob != this_object()))
	    return notify_fail("You don't have that!\n");
	str = query_name();
    }
    if(!__Weapon["wielded"])
	return notify_fail("You are not wielding that!\n");
    if(functionp(__Weapon["unwield"]) && !((*__Weapon["unwield"])())) return 1;
    if(pointerp(__Weapon["unwield"])) {
	funx = __Weapon["unwield"];
	i = sizeof(funx);
	while(i--)
	    if(!(*funx[i])()) return 1;
    }
    __ActuallyUnwield();
    return 1;
}

string query_verb() { return __Weapon["verb"]?__Weapon["verb"]:"hit"; }

void set_verb(string verb) {
    __Weapon["verb"] = verb;
}

void set_hit(mixed val) {
    if(!val) __Weapon["hit"] = 0;
    if(!functionp(val) && !pointerp(val) && !stringp(val)) return;
    if(functionp(val)) __Weapon["hit"] = bind(val, this_object());
    else
    __Weapon["hit"] = val; 
}

void set_wield(mixed val) {
    if(!stringp(val) && !functionp(val) && !pointerp(val)) return;
    __Weapon["wield"] = val;
}

void set_unwield(mixed val) {
    if(!functionp(val) && !stringp(val) && !pointerp(val)) return;
    __Weapon["unwield"] = val;
}

void set_type(string str) { __Weapon["type"] = str; }

string query_short() {
    string tmp;

    tmp = ::query_short();
    if(!__Weapon["wielded"]) 
        return tmp;
    else 
        return tmp + __Weapon["limb string"];
}

string actual_short_desc() {
  if(__Weapon["short desc"])
  return __Weapon["short desc"];
  else return query("short desc");
}

void set_short(string desc) {
  __Weapon["short desc"] = desc;
  set("short desc", desc);
  ::set_short((: call_other, this_object(), "actual_short_desc" :));
}

mixed query_hit() { return __Weapon["hit"]; }

mixed query_wield() { return __Weapon["wield"]; }

mixed query_unwield() { return __Weapon["unwield"]; }

string query_type() { return __Weapon["type"]; }

object query_wielded() { return __Weapon["wielded"]; }

int is_weapon() { return 1; }

void unequip() { 
  if(__Weapon["wielded"]) {
    if(functionp(__Weapon["unwield"]))
      evaluate(__Weapon["unwield"]);
    else if(pointerp(__Weapon["unwield"]))
      map_array(filter_array(__Weapon["unwield"],
			     (: functionp :)),
		(: evaluate :));
  }
  __ActuallyUnwield();
}

void __ActuallyUnwield() {
    if(!__Weapon["wielded"]) return;
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