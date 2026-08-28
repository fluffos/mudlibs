/****************************************************************
    NEW SAVE SYSTEM!
    The following is the Container code for saving whats in it,
    save() just saves the container, save(1) saves the container,
    and recursively saves all items in it as well.
****************************************************************/
#include <dirs.h>

varargs void restore(string str){
    string *k;
    int i, x;
    object o;

    if(TO->query_room() && !str){
        str = DIR_ROOM+"/"+base_name(TO);
    }
    ::restore(str);
    k = keys(objs);
    if(!sizeof(k))
        return;
    for(i=0, x = sizeof(k);i<x;i++){
        reset_eval_cost();
        o = new(objs[k[i]]);
        o->restore(k[i]);
        o->move2(this_object());
    }
    return;
}

varargs string save(int recursive){
    string type;
    int i;
    object *o2;

    if(!recursive)
        return ::save();
    o2 = all_inventory(TO);
    objs = ([]);
    for(i=0;i<sizeof(o2);i++){
        reset_eval_cost();
        if(userp(o2[i]) || o2[i]->query_property("no save"))
            continue;
        type = o2[i]->save(1);
        objs[type] = base_name(o2[i]);
    }
    return ::save();
}

int add_obj(object ob){
    string tmp;

    if(!ob || userp(ob) || ob->query_property("no save") || TO->query_property("no save"))
        return 0;
    tmp = ob->save(1);
    objs[tmp] = base_name(ob);
    save();
    return 1;
}

int remove_obj(object ob){
    string tmp;

    if(!ob || TO->query_property("no save"))
        return 0;
    tmp = ob->query_sid2();
    if(!tmp)
        return 0;
    map_delete(objs, tmp);
    save();
    return 1;
}

/****************************************************************
    END OF NEW SAVE SYSTEM!
****************************************************************/

