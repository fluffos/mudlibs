//      /std/food.c
//      from the Nightmare mudlib
//      inheritable food item
//      created by Descartes of Borg October 1992
//    completely rewritten by Nulvect 2008-05-03

#include <teststd.h>

inherit OBJECT;

int strength, disable, poisoned;
string my_mess, your_mess;
mixed Extra;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_strength(int x);
void set_dis(int x);
void set_disable(int x);
void set_extra(mixed);
void set_poisoned(int);
int query_poisoned();
int query_strength();
string query_my_mess();
string query_your_mess();
mixed query_extra();
string expandos(string str);

string expandos(string str) {
  mapping rep = ([
    "N" : (: (this_player() ? this_player()->query_cap_name() : "") :),
    "P" : (: (this_player() ? this_player()->query_possessive() : "") :),
    "AN" : (: (this_object() ? indefinite_article(strip_color(this_object()->query_short())) : "") :),
    "O" : (: (this_object() ? strip_color(this_object()->query_short()) : "") :),
  ]);

  foreach (string key, mixed f in rep)
    str = replace_string(str, "$"+key, evaluate(f));

  return str;
}

void create() {
    ::create();
    set_strength(1);
    set_poisoned(0);
    set_disable(1);
    set_my_mess("You eat $AN.");
    set_your_mess("$N eats $AN.");
}

void set_id(string *ids) { if (sizeof(ids)) ids += ({ "food" }); ::set_id(ids); }

void set_dis(int x) { disable = x; }  
void set_disable(int x) { set_dis(x); }

void set_strength(int x) {
    strength = x;
}

void set_my_mess(string str) {
    my_mess = str;
}

void set_your_mess(string str) {
    if (strsrch(str, "$") == -1) str = "$N "+str;
    your_mess = str;
}

string query_my_mess(string str) { return expandos(my_mess); }
string query_your_mess(string str) { return expandos(your_mess); }

int query_strength() {
    return strength;
}

void set_poisoned(int p) { poisoned = (p < 0 ? 0 : p); }
int query_poisoned() { return poisoned; }
void set_extra(mixed ex) { if (functionp(ex)) Extra = ex; }
mixed query_extra() { return Extra; }

int is_food() { return 1; }

