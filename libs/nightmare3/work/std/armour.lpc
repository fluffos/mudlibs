//      /std/armour.c
//      from the Nightmare Mudlib
//      the basic inherited armour object
//      created by Descartes of Borg 25 june 1993

#include <std.h>
#include <move.h>

inherit OBJECT;

private mapping armour_save;
private  nosave mapping armour_static;

void unwear();
void extinguish_glow();
void unequip();
void set_not_equipped();
void set_ac(int x);
void set_illuminate(int x);
void set_limbs(mixed *borg);
void set_wear(mixed val);
void set_remove(mixed val);
void set_type(string str);
int query_ac();
mixed *query_limbs();
string query_wear_string();
object query_wear_func();
string query_remove_string();
object query_remove_func();
string query_type();
object query_worn();

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("wear", "wear");
    add_action("do_remove", "remove");
    add_action("illuminate", "illuminate");
}

void create() {
    ::create();
    set_vendor_type("armour");
    armour_save = ([]);
    armour_static = ([]);
}

int wear(string str) {
    mixed *limbs;
    string ret, what, where;
    int i, j;

    if(!str) return notify_fail("Wear what?\n");
    if(!id(what = str) && sscanf(str, "%s on %s", what, where) != 2) {
        if(parse_objects(this_player(), str) != this_object()) {
            notify_fail("You don't have that!\n");
            return 0;
        }
    }
    else if(!id(what) && parse_objects(this_player(), what) != this_object()) {
        notify_fail("You don't have that!\n");
        return 0;
    }
    if(query_worn()) {
        message("my_action", "You are already wearing that!", this_player());
        return 1;
    }
    i = sizeof(limbs = query_limbs());
    while(i--) {
        if(stringp(limbs[i])) continue;
        if((j=member_array(where, limbs[i])) != -1) limbs[i] = limbs[i][j];
        else if(where) {
          message("my_action", "You cannot wear this on your "+where+".",
            this_player());
          return 1;
        }
        else {
          message("my_action", "You must specify which limb you want this "
          "on.", this_player());
          return 1;
        }
    }
    if(ret = (string)this_player()->equip_armour_to_limb(this_object(),limbs)){
        if(ret == "NO") return 1;
        message("my_action", ret, this_player());
        return 1;
    }
    if(functionp(armour_static["wear"])) {}
    else if(stringp(armour_static["wear"]))
      message("my_action", armour_static["wear"], this_player());
    else message("my_action", "You wear "+query_short()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      " wears "+(string)this_player()->query_possessive()+" "+query_short()+
      ".", environment(this_player()), ({ this_player() }));
    armour_static["worn by"] = this_player();
    armour_static["actual limbs"] = limbs;
    return 1;
}

int do_remove(string str) {
    if(!str) return notify_fail("Remove what?\n");
    if(!id(str) && parse_objects(this_player(), str) != this_object()) {
        notify_fail("You don't have that!\n");
        return 0;
    }
    if(!query_worn()) {
        message("my_action", "You are not wearing that!", this_player());
        return 1;
    }
	if(functionp(armour_static["unwear"])){
		if(!((*armour_static["unwear"])())) return 1;
	}
    unwear();
    return 1;
}

int illuminate(string str) {
    int heure;

    if(!query_property("magic item") ||
      member_array("illuminate", query_property("magic item")) == -1) return 0;
    if(!str || !id(str)) {
        notify_fail("Illuminate what?\n");
        return 0;
    }
    heure = 5*((int)this_player()->query_stats("wisdom")) +
      (int)this_player()->query_skill("conjuring");
    if(heure < 20) heure = 20;
    if((int)this_player()->query_mp() < heure/10) {
        write("Too low on magic power.\n");
        return 1;
    }
    this_player()->add_mp(-(heure/10));
    write("Your "+query_name()+" begins to glow.\n");
    say(this_player()->query_cap_name()+"'s "+query_name()+" begins to
glow.\n");
    environment(this_object())->add_property("light",
      (armour_static["lit"] = 1+random(3)));
    call_out("extinguish_glow", heure);
    return 1;
}

void unwear() {
    if(stringp(armour_static["unwear"]))
      message("my_action", armour_static["unwear"], armour_static["worn by"]);
    else message("my_action", "You remove your "+query_short()+".",
      armour_static["worn by"]);
    armour_static["worn by"]->remove_armour_from_limb(this_object(),
      armour_static["actual limbs"]);
    message("other_action", (string)armour_static["worn by"]->query_cap_name()+
      " removes "+(string)armour_static["worn by"]->query_possessive()
      +" "+query_name()+".", environment(armour_static["worn by"]),
      ({ armour_static["worn by"] }));
    map_delete(armour_static, "worn by");
    map_delete(armour_static, "actual limbs");
}

void extinguish_glow() {
    if(!this_object()) return;
    if(!armour_static["lit"]) return;
    if(living(environment(this_object()))) {
        tell_object(environment(this_object()),"The magic glow of your
"+query_name()+" fades away.\n");
        tell_room(environment(environment(this_object())),
environment(this_object())->query_cap_name()+"'s "+query_name()+
          "magic glow fades away.\n", ({environment(this_object()) }) );
    }
    else tell_room(environment(this_object()), "The magic glow of the "+
      query_name()+" fades away.\n");
    environment(this_object())->add_property("light", -armour_static["lit"]);
    map_delete(armour_static, "lit");
}

void unequip() { if(armour_static["worn by"]) unwear(); }

void set_not_equipped() {
    if(query_worn()) map_delete(armour_static, "worn by");
    if(armour_static["actual limbs"]) map_delete(armour_static, "actual limbs");}

int remove() {
    if(armour_static && armour_static["lit"]) {
      if(environment(this_object()))
        environment(this_object())->add_property("light",-armour_static["lit"]);
        map_delete(armour_static, "lit");
    }
    unequip();
    return ::remove();
}

int move(mixed dest) {
    int x;

    if(armour_static["lit"])
      environment(this_object())->add_property("light", -armour_static["lit"]);
    x = ::move(dest);
    if(armour_static["lit"])
      environment(this_object())->add_property("light", armour_static["lit"]);
    if(x == MOVE_OK) unequip();
    return x;
}

void set_ac(int x) { armour_save["ac"] = x; }

void set_illuminate(int x) { set_property("magic item", ({ "illuminate" })); }

void set_limbs(mixed *borg) { armour_save["possible limbs"] = borg; }

void set_wear(mixed val) {
    armour_static["wear"] = val;
}

void set_remove(mixed val) {
    armour_static["unwear"] = val;
}

void set_type(string str) { armour_save["type"] = str; }

int query_ac() { return armour_save["ac"] + query_property("enchantment"); }

mixed *query_limbs() { return armour_save["possible limbs"]; }

mixed query_wear() { return armour_static["wear"]; }

mixed query_unwear() { return armour_static["unwear"]; }

string query_type() { return armour_save["type"]; }

object query_worn() { return armour_static["worn by"]; }


string query_short() {
    if(!armour_static["worn by"]) return ::query_short();
    else return ::query_short()+" (worn)";
}

string query_long(string str) {
    string ret;
    int i;
    if(!armour_static["worn by"]) return ::query_long(str);
    else {
        ret = ::query_long(str);
        i = sizeof(armour_static["actual limbs"]);
        ret += "Worn on: "+armour_static["actual limbs"][--i];
        if(i>-1) while(i--) ret += ", "+armour_static["actual limbs"][i];
        ret += ".\n";
        return ret;
    }
}

string *query_actual_limbs() { return armour_static["actual limbs"]; }

int is_armour() { return 1; }

void set_struck(mixed val) {
    armour_static["struck"] = val;
}

mixed query_struck() { return armour_static["struck"]; }
