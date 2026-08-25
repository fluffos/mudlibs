/*    /adm/simul_efun/load_object.c
 *    from Nightmare IV
 *    find and object and return it, or load an object and return it
 *    created by Descartes of Borg 940213
 */

#include <security.h>

object load_object(string str) {
    object ob;

    if(!stringp(str)) error("Bad argument 1 to load_object().\n");
    if(ob = find_object(str)) return ob;
    catch(call_other(str, "???"));
    return find_object(str);
}
