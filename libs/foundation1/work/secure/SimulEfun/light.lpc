/*    /adm/simul_efun/light.c
 *    from Nightmare IV
 *    light SimulEfuns
 *    created by Descartes of Borg 940213
 */

#include <daemons.h>

int effective_light(object ob) {
    object *inv;
    int i, x;

    if(!objectp(ob)) error("Bad argument 1 to effective_light().\n");
    if(creatorp(ob) || (int)ob->query_level() == 1) return 1;
    x = total_light(ob) + (int)ob->query_sight_bonus();
    i = sizeof(inv = all_inventory(ob));
    while(i--) x += (int)inv[i]->query_property("light");
    return x;
}

int moon_light() { return (int)ASTRONOMY_D->query_moon_light(); }

int total_light(object ob) {
    object *inv;
    object env;
    int i, x;

    if(!objectp(ob)) error("Bad argument 1 to total_light().\n");
    if(!(env = environment(ob))) return 0;
    i = sizeof(inv = all_inventory(env));
    x = (int)env->query_property("light");
    while(i--) x += (int)inv[i]->query_property("light");
    if((int)env->query_property("indoors")) return x;
    switch((string)EVENTS_D->query_time_of_day()) {
        case "day": return x;
        case "night":
          return (x+moon_light()+(int)env->query_property("night light")-4);
        case "dawn": case "twilight": return (x-1);
        default: return x;
    }
}
