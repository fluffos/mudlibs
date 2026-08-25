/*    /std/clean_up.c
 *    from Nightmare IV
 *    the central object of the entire mudlib
 *    created by Descartes of Borg 940210
 */

#include <move.h>
#include "clean_up.h"

nosave private int __NoClean;

void create() {
    __NoClean = 0;
}

int clean_up() {
    object ob, env;
    object *inv;
    int i;

    if(__NoClean) return NEVER_AGAIN;
    if(!(ob = this_object()) || ob->query_auto_load()) return NEVER_AGAIN;
    if(userp(ob)) return NEVER_AGAIN;
    if(env = environment(ob)) {
        if((int)env->is_bag()) return TRY_AGAIN_LATER;
        if((int)env->query_property("storage room")) return TRY_AGAIN_LATER;
    }
    inv = deep_inventory(ob);
    if(sizeof(filter_array(inv, (: userp :)))) return TRY_AGAIN_LATER;
    if(!env) {
        catch(inv->remove());
        if(ob) ob->remove();
        if(ob) destruct(ob);
        return NEVER_AGAIN;
    }
    if(userp(env)) return TRY_AGAIN_LATER;
    return (int)env->clean_up();
}

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

int remove() {
    object env;
    object *inv;
    int i;

    if(env = environment(this_object())) {
        i = sizeof(inv = all_inventory(this_object()));
        while(i--) if(inv[i]) inv[i]->move(env);
    }
    destruct(this_object());
    return !(this_object());
}

protected void set_no_clean(int x) { __NoClean = x; }

int query_no_clean() { return __NoClean; }


