/*    /std/Object.c
 *    from Nightmare IV
 *    object inherited by all tangible objects (ones with environments)
 *    created by Descartes of Borg 940211
 *    bug in properties fixed by Douglas Reay (Pallando @ many muds) 940601
 *    move() altered by Pallando, 940705
 */

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <config.h>
#include "Object.h"

inherit CLEAN_UP;

private int __Invis, __Value, __Mass;
private string __Material, __CapName, __VendorType;
private mixed __Short, __Long, __PreventDrop, __PreventGet, __PreventPut, __Read;
nosave private string *__Id, *__Adjectives;
nosave private int __Destroy;
nosave string __TrueName, __Creator;
nosave private object __LastLocation;
nosave private mapping __Properties;
nosave private function *__InvisTests;

void create() {
    clean_up::create();
    __Properties = ([]);
    __Adjectives = ({});
    __Id = ({});
    set_vendor_type("treasure");
  }

void init() { add_action("ReadObject", "read"); }

void reset() { /* Nothing goes here... just for design purposes */ }

int move(mixed dest) {
    object ob;
    string str;
    int x;

    if(!this_object()) return MOVE_DESTRUCTED;
    if(environment(this_object())) {
        x = (int)environment(this_object())->release_objects(this_object());
        if(!x && !archp(this_object())) return 0;
    }
    if(stringp(dest)) {
        if(!(ob = find_object(dest))) {
            if(str = catch(call_other(dest, "???"))) {
                write(str);
                return MOVE_NO_DEST;
            }
            ob = find_object(dest);
        }
    }
    else ob = dest;
    if(!ob || ob == this_object()) return MOVE_NOT_ALLOWED;
    if(living(this_object()) && living(ob) && !((int)ob->query_property("mountable")))
      return MOVE_NOT_ALLOWED;
    if(!((int)ob->receive_objects(this_object()))) return MOVE_NOT_ALLOWED;
    if(environment(this_object()))
      environment(this_object())->add_encumbrance(-query_mass());
    set_last_location(environment(this_object()));
    move_object(ob);
    if(!this_object()) return MOVE_DESTRUCTED;
    environment(this_object())->add_encumbrance(query_mass());
    return MOVE_OK;
}

int remove() {
    object env;
    int x;

    if(env = environment(this_object())) {
        env->add_encumbrance(-query_mass());
        if(!(x = clean_up::remove())) env->add_encumbrance(query_mass());
        return x;
    }
    else return clean_up::remove();
}

int allow_get(object ob) {
    mixed val;

    if(!(val = query_prevent_get()) && !query_property("keep")) return 1;
    else if(stringp(val)) {
        message("my_action", val, ob);
        return 0;
      }
    else if(functionp(val)) {
        return (int)((*val)(ob));
      }
    else if(stringp(query_property("keep"))) {
        if((string)ob->query_name() == query_property("keep")) return 1;
        message("my_action", "A magical force prevents you from taking "
          "possession of the "+query_name()+".", ob);
        message("other_action", sprintf("A magical force prevents %s "
          "from taking possession of the %s.", (string)ob->query_cap_name(),
          query_name()), environment(ob), ({ ob }));
        return 0;
      }
    return 1;
  }

int allow_drop(object ob) {
    mixed val;

    if(!(val = query_prevent_drop())) return 1;
    else if(stringp(val)) {
        message("my_action", val, ob);
        return 0;
      }
    else if(functionp(val)) {
        return (int)((*val)(ob));
      }
    else return 1;
  }

int allow_put(object ob) {
    mixed val;

    if(!(val = query_prevent_put())) return 1;
    else if(stringp(val)) {
        message("my_action", val, ob);
        return 0;
    }
    else if(functionp(val)) {
        return (int)((*val)(ob));
    }
    else return 1;
}

int id(string str) {
    if(!str) return 0;
    if(!stringp(str)) error("Bad argument 1 to id().\n");
    return (member_array(lower_case(str), query_id()) != -1);
}

string *parse_command_id_list() {
    return query_id();
}

string *parse_command_plural_id_list() {
    return map_array(query_id(), "pluralize_id", this_object());
}

string *parse_command_adjectiv_id_list() {
    return query_adjectives();
}

protected string pluralize_id(string str) { return pluralize(str); }

int ReadObject(string str) {
    mixed val;

    if(!str || !(val = query_read())) return notify_fail("Read what?\n");
    if(!id(str)) return notify_fail("You do not notice that here!\n");
    if(living(this_object())) return notify_fail("Read a living thing?\n");
    if(functionp(val)) {
        return (int)((*val)(str));
      }
    message("info", val, this_player());
    message("other_action", sprintf("%s reads the %s",
      (string)this_player()->query_cap_name(), query_name()),
      environment(this_player()), ({ this_player() }));
    return 1;
  }

void set_id(string *arr) {
    if(!pointerp(arr)) error("Bad argument 1 to set_id().\n");
    __Id = arr;
  }

string *query_id() { return (__Id + ({ query_name() })); }

void set_adjectives(string *arr) {
    if(!pointerp(arr)) error("Bad argument 1 to set_adjectives().\n");
    else __Adjectives = arr;
  }

string *query_adjectives() { return __Adjectives; }

void set_name(string str) {
    if(!stringp(str)) error("Bad argument 1 to set_name().\n");
    __TrueName = lower_case(str);
    if(!__CapName) __CapName = capitalize(str);
    if(!__Creator)
      __Creator = (previous_object() ? file_name(previous_object()) :
        "Unknown");
  }

string query_name() { return __TrueName; }

void set_cap_name(string str) {
    if(!stringp(str)) error("Bad argument 1 to set_cap_name().\n");
    else __CapName = str;
  }

string query_CapName() { return __CapName; }

string query_cap_name() {
    if(query_invis()) return "A shadow";
    else return query_CapName();
  }

void set_short(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_short().\n");
    __Short = val;
  }

string query_short() {
    if(!__Short) return 0;
    if(functionp(__Short))
      return (string)((*__Short)());
    else if(stringp(__Short)) return __Short;
    else error("Illegal function pointer.\n");
  }

void set_long(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_long().\n");
    __Long = val;
  }

varargs string query_long(string str) {
    if(!__Long) return "";
    if(functionp(__Long))
      return (string)((*__Long)(str));
    else if(stringp(__Long)) return __Long;
    else error("Illegal function pointer.\n");
  }

varargs void set_read(mixed val, mixed unused) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_read().\n");
    else __Read = val;
}

varargs mixed query_read(string str) { return __Read; }

void set_mass(int x) {
    if(x < 0) x = 0;
    __Mass = x;
}

int query_mass() { return __Mass; }

void add_mass(int x) {
    if(__Mass + x < 0) x = - __Mass;
    if(environment(this_object()))
      environment(this_object())->add_encumbrance(x);
    __Mass -= x;
}

void set_destroy() { __Destroy = 1; }

int query_destroy() { return __Destroy; }

void set_value(int x) {
    if(!intp(x)) error("Bad argument 1 to set_value().\n");
    else __Value = x;
  }

int query_value() { return __Value; }

protected void set_last_location(object ob) { __LastLocation = ob; }

object query_last_location() { return __LastLocation; }

void hide(int x) { set_hide(x); }

void set_invis(mixed val) {
    if(intp(val)) __Invis = val;
    else if(functionp(val)) {
        if(!__InvisTests)  __InvisTests = ({ val });
        else __InvisTests += ({ val });
    }
    else error("Bad argument 1 to set_invis().\n");
}

varargs int query_invis(object ob) {
    int i;

    if(__Invis || !__InvisTests) return __Invis;
    if(!ob) ob = (this_player() ? this_player() : previous_object());
    i = sizeof(__InvisTests);
    while(i--) {
        if((int)((*__InvisTests[i])(this_object(), ob))) return 1;
    }
    return 0;
}

void remove_invis_test(function f) {
    int i;

    if(!__InvisTests) return;
    if(!functionp(f)) error("Bad argument 1 to remove_invis_test().\n");
    i = sizeof(__InvisTests);
    while(i--) {
        if(!__InvisTests[i])
          __InvisTests = exclude_array(__InvisTests, i);
        else continue;
        break;
    }
    if(!sizeof(__InvisTests)) __InvisTests = 0;
}
function *query_invis_test() {
   if(!__InvisTests) return ({ });
   return __InvisTests;
}

void set_material(string str) {
    if(!stringp(str)) error("Bad argument 1 to set_material().\n");
    else __Material = lower_case(str);
  }

string query_material() { return __Material; }

void set_vendor_type(string str) {
    if(!stringp(str)) error("Bad argument 1 to set_vendor_type().\n");
    else __VendorType = str;
}

string query_vendor_type() { return __VendorType; }

void set_prevent_get(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_prevent_get().\n");
    __PreventGet = val;
  }

mixed query_prevent_get() { return __PreventGet; }

void set_prevent_drop(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_prevent_drop().\n");
    __PreventDrop = val;
  }

mixed query_prevent_drop() { return __PreventDrop; }

void set_prevent_put(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to set_prevent_put().\n");
    __PreventPut = val;
}

mixed query_prevent_put() { return __PreventPut; }

void set_properties(mapping borg) { __Properties += borg; }

mapping query_properties() { return __Properties; }

void set_property(string prop, mixed val) {
    __Properties[prop] = val;
  }

mixed query_property(string prop) { return __Properties[prop]; }

void add_property(string prop, mixed val) {
    if(__Properties[prop]) __Properties[prop] += val;
    else __Properties[prop] = val;
  }

void remove_property(string prop) {
    if(undefinedp(__Properties[prop])) return;
    else map_delete(__Properties, prop);
  }

/* ******************************************************************* */
/*          CUT HERE IF NO OLD FUNCTION CALLS EXIST                    */

string special_long(string str);


#ifdef __OLD_OBJECT_BEHAVIOUR

void set(string key, mixed val) {
    if(key == "night long") {
        set_long( (: special_long :) );
        set_property("night long", val);
        return;
      }
    if(key == "day long") {
        set_long( (: special_long :) );
        set_property("day long", val);
        return;
    }
    key = replace_string(key, " ", "_");
    call_other(this_object(), "set_"+key, val);
  }

mixed query(string key) {
    if(key == "night long") return query_property("night long");
    key = replace_string(key, " ", "_");
    return (mixed)(call_other(this_object(), "query_"+key, key));
  }

int get() { return allow_get(this_player()); }

int drop() { return !allow_drop(this_player()); }

string special_long(string str) {
    return (query_night() ? query_property("night long") : query_property("day long"));
}

void set_weight(int x) { set_mass(x); }

int query_weight() { return query_mass(); }

#endif /* __OLD_OBJECT_BEHAVIOUR */
