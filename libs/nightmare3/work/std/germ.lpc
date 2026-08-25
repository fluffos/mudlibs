
/*    /std/germ.c
 *    from Nightmare IV
 *    germs which cause disease
 *    created by Descartes of Borg to silence whining mortals 940905
 */

#include <std.h>
#include "germ.h"

inherit OBJECT;

private int __Communicable, __LifeSpan;
private string __Type;
nosave private int __LastHeartBeat, __Creation;
nosave private function __Infect;
nosave private mixed __Cure;

void create() {
    Object::create();
    __Creation = time();
    __LastHeartBeat = time();
    set_invis(1);
    set_mass(0);
    set_value(0);
    set_prevent_drop("");
    set_prevent_get("");
    set_prevent_put("");
}

void init() {
    int x;

    Object::init();
    if(environment(this_object()) == this_player()) return;
    if(query_heart_beat()) return;
    set_heart_beat(5);
    x = time() - __LastHeartBeat;
    __LastHeartBeat = time();
    if(!__Communicable) return;
    x = x/5;
    if(x > 7) x = 7;
    while(x--) multiply();
}

void init_args(mixed *args) {
    __Communicable = args[0];
    __LifeSpan = args[1];
    __Type = args[2];
    set_heart_beat(5);
}

void heart_beat() {
    object *obs, *boo;
    object ob;

    __LastHeartBeat = time();
    if(!environment(this_object())) {
        set_heart_beat(0);
        return;
    }
    if(living(environment(this_object())) && environment(environment())) {
        suffer(environment());
        if(!environment()) {
            if(this_object()) this_object()->remove();
            return;
        }
        if(__Communicable) multiply();
        obs = all_inventory(environment(environment())) - ({environment()});
    }
    else {
        if(__LastHeartBeat - __Creation > __LifeSpan) {
            this_object()->remove();
            return;
        }
        if(!sizeof(users() & all_inventory(environment()))) {
            set_heart_beat(0);
            return;
        }
        if(__Communicable) multiply();
        obs = all_inventory(environment());
    }
    if(!__Communicable) return;
    if(__Communicable > random(1000)) {
        boo = sort_array(filter_array(obs, "filter_living",  this_object()),
          "sort_weak", this_object());
        if(sizeof(boo)) ob = obs[0];
        else return;
        new(base_name(this_object()))->infect(ob);
    }
}

int filter_living(object ob) { return living(ob); }

int sort_weak(object a, object b) {
    int x, y;

    x = (int)a->query_stats("constitution") + (int)a->query_sp();
    y = (int)b->query_stats("constitution") + (int)b->query_sp();
    if( x > y ) return -1;
    else if( y > x ) return 1;
    else return 0;
}

void multiply() {
    object ob;

    if(__Communicable > random(10000)) {
        ob = environment();
        if(environment(ob) && random(100) > 50) ob = environment(ob);
        new(base_name(this_object()))->move(ob);
    }
}

int infect(object ob) {
    if((int)ob->resist_infection(this_object())) return 0;
    if(__Infect && !((*__Infect)(ob))) return 0;
    __Creation = time();
    if(!query_heart_beat()) set_heart_beat(5);
    this_object()->move(ob);
    return 1;
}

int cure(int x) {
    if(intp(__Cure)) __Cure -= x;
    else if(functionp(__Cure)) {
        if(!((*__Cure)(x))) return 0;
        else __Cure = 0;
    }
    else error("Bad argument 1 to cure().");
    if(__Cure > 0) return 0;
    this_object()->remove();
    return 1;
}

void suffer(object ob) { }

void set_communicable(int x) {
    if(x > 50) x = 50;
    __Communicable = x;
}

int query_communicable() { return __Communicable; }

void set_cure(mixed val) {
    if(!intp(val) && !functionp(val)) error("Bad argument 1 to set_cure().");
    __Cure = val;
}

mixed query_cure() { return __Cure; }

void set_infect(function f) {
    if(!functionp(f)) error("Bad argument 1 to set_infect().");
    __Infect = f;
}

function query_infect() { return __Infect; }

void set_life_span(int x) {
    if(x > 600) x = 600;
    __LifeSpan = x;
}

int query_life_span() { return __LifeSpan; }

void set_type(string str) { __Type = str; }

string query_type() { return __Type; }

mixed *query_auto_load() {
    return ({ base_name(this_object()), ({ __Communicable, __LifeSpan,
      __Type }) });
}

string *query_id() { return ({ "germ" }) + Object::query_id(); }

int is_germ() { return 1; }
