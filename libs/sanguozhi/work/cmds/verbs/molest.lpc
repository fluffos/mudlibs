// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/* Included for historical reasons - ie: practically every Infocom game
 * with the notable exception of Nord and Bert included support for it.

*/

#include <mudlib.h>
#include <setbit.h>

inherit VERB_OB;

string can_molest_obj(object ob) {
    if (ob && ob->is_living())
        return "现在，现在，好好玩。\n";
    else
        return "多么令人怀疑的举动啊。\n";
}

mixed * query_verb_info()
{
    return ({ ({ "OBJ" }) });
}
