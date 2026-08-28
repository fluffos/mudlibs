#include <daemons.h>

varargs void event(string fun, int when, mixed *args, int reg) {
    object ob;
    
    ob = previous_object();
    if(!function_exists(fun, ob) || when < 60) return;
    EVENTS_D->add_events(ob, fun, when, args, reg);
}

int event_pending(object ob) {
    mapping tmp;

    tmp = (mapping)EVENTS_D->query_events();
    if(tmp[file_name(ob)]) return 1;
    else return 0;
}
