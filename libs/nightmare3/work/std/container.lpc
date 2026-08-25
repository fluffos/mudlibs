/*    /std/container.c
 *    from Nightmare IV
 *    object inherited by all objects with inventories
 *    created by Descartes of Borg 940212
 */

#include <std.h>
#include <config.h>
#include "container.h"

inherit OBJECT;

nosave private int __Encumbrance, __MaxEncumbrance;

varargs int receive_objects(object ob) {
    if(!ob) ob = previous_object();
    if((int)ob->query_mass() + query_encumbrance() > query_max_encumbrance())
      return 0;
    return 1;
}

int release_objects(object ob) { return 1; }

string describe_living_contents(object *exclude) {
    object *inv;
    mapping list;
    string *shorts;
    string tmp, ret;
    int i, x;

    if(!(i = sizeof(inv = query_living_contents() - exclude))) return "";
    list = allocate_mapping(i);
    while(i--) {
        if((int)inv[i]->query_invis()) {
            if(creatorp(inv[i])) continue;
            else if(random(101) < (int)this_player()->query_level())
              tmp = "a shadow";
            else continue;
        }
        else if(!(tmp = (string)inv[i]->query_short()))
          tmp = (string)inv[i]->query_name();
        if(!tmp) continue;
        if(!list[tmp]) list[tmp] = ({ inv[i] });
        else list[tmp] += ({ inv[i] });
    }
    i = sizeof(shorts = keys(list));
    ret = "";
    while(i--) {
        if((x=sizeof(list[shorts[i]])) < 2)
          ret = sprintf("%s%s\n", ret, capitalize(shorts[i]));
        else ret = sprintf("%s%s\n", ret,
          capitalize(consolidate(x, shorts[i])));
    }
    return ret;
}

string describe_item_contents(object *exclude) {
    object *inv;
    mapping list;
    string ret, tmp;
    string *shorts;
    int i, x;

    list = allocate_mapping(i=sizeof(inv=query_item_contents()-exclude));
    while(i--) {
        if((int)inv[i]->query_invis()) continue;
        if(!(tmp = (string)inv[i]->query_short()))
          tmp = (string)inv[i]->query_name();
        if(!tmp || tmp == "") continue;
        if(!list[tmp]) list[tmp] = ({ inv[i] });
        else list[tmp] += ({ inv[i] });
    }
    if(!(i = sizeof(shorts = keys(list)))) return "";
    if((x=sizeof(list[shorts[--i]])) == 1) ret = capitalize(shorts[i]);
    else ret = capitalize(consolidate(x, shorts[i]));
    if(!i) return sprintf("%s %s here.", ret, (x<2 ? "is" : "are"));
    else if(i==1)
      return sprintf("%s and %s are here.", ret,
        consolidate(sizeof(list[shorts[0]]), shorts[0]));
    else {
        while(i--) {
            if(!i) ret = sprintf("%s, and ", ret);
            else ret = sprintf("%s, ", ret);
            ret = sprintf("%s%s", ret, consolidate(sizeof(list[shorts[i]]),
              shorts[i]));
        }
    }
    return sprintf("%s are here.", ret);
}

void add_encumbrance(int x) {
    if(x + query_encumbrance() > query_max_encumbrance()) return;
    if((__Encumbrance += x) < 0) __Encumbrance = 0;
}

int query_encumbrance() { return __Encumbrance; }

void set_max_encumbrance(int x) { __MaxEncumbrance = x; }

int query_max_encumbrance() { return __MaxEncumbrance; }

float query_encumbered() {
    return percent(query_encumbrance(), query_max_encumbrance());
}

object *query_living_contents() {
    return filter_array(all_inventory(this_object()), "filter_living",
      this_object());
}

object *query_item_contents() {
    return filter_array(all_inventory(this_object()),"filter_items",
      this_object());
}

protected int filter_living(object ob) { return living(ob); }

protected int filter_items(object ob) { return !living(ob); }
