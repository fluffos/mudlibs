/*    /adm/SimulEfun/pointers.c
 *    from Nightmare IV
 *    SimulEfuns for testing things
 *    created by Descartes of Borg 940213
 */

#include <config.h>
#include "SimulEfun.h"
#include <council.h>

int ambassadorp(object ob) {
    if(!ob) ob = previous_object();
    return (userp(ob) && member_group(ob, "AMBASSADOR"));
}

int archp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    return (member_group(ob, "ASSIST") || member_group(ob, "SECURE"));
}

varargs int creatorp(object ob) {
    if(!ob) ob = previous_object();
    if(!ob || !userp(ob)) return 0;
    return (member_array((string)ob->query_position(), MORTAL_POSITIONS) == -1);
}

int hiddenp(object ob) {
    if(!objectp(ob)) error("Bad argument 1 to hiddenp().\n");
    return !find_object(file_name(ob));
}

int high_mortalp(object ob) {
    if(!ob) ob = previous_object();
    return (!creatorp(ob) && ((int)ob->query_level() > 19));
}

int leaderp(object ob) {
    if(!ob) ob = previous_object();
    return (userp(ob) && (member_array((string)ob->query_name(),COUNCIL)!=-1));
}
