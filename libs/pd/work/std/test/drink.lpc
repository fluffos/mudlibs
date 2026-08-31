//    originally by Descartes
//    completely rewritten by Nulvect 2008-05-03

#include <teststd.h>

inherit OBJECT;

int strength, disable, poisoned;
string my_mess, your_mess;
string emptyname, emptyfile, type;
mixed Extra;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_type(string);
void set_empty(string);
void set_empty_name(string);
void set_empty_file(string);
void set_strength(int x);
void set_dis(int x);
void set_disable(int x);
void set_extra(mixed);
void set_poisoned(int);
int query_poisoned();
int query_strength();
string query_my_mess();
string query_your_mess();
string query_type();
string query_empty();
string query_empty_name();
string query_empty_file();
mixed query_extra();
string expandos(string str);
object clone_empty();

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
    set_my_mess("You drink some $O.");
    set_your_mess("$N drinks some $O.");
    set_type("soft drink");
    set_empty_name("bottle");
}

void set_id(string *ids) { if (sizeof(ids)) ids += ({ "drink" }); ::set_id(ids); }

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

void set_type(string str) { type = str; }
string query_type() { return type; }

void set_empty(string str) { if (strsrch(str, "/") != -1) set_empty_file(str); else set_empty_name(str); }
string query_empty() { return query_empty_file() || query_empty_name(); }

void set_empty_name(string str) { emptyname = str; }
string query_empty_name() { return emptyname; }

void set_empty_file(string str) { emptyfile = str; }
string query_empty_file() { return emptyfile; }

void set_poisoned(int p) { poisoned = (p < 0 ? 0 : p); }
int query_poisoned() { return poisoned; }
void set_extra(mixed ex) { if (functionp(ex)) Extra = ex; }
mixed query_extra() { return Extra; }

object clone_empty() {
  object empty;
   
  if (emptyfile) empty = new(emptyfile);

  if (!empty && emptyname) {
    empty = new("/std/object");
    empty->set_short("an empty "+emptyname);
    empty->set_long(capitalize(indefinite_article(emptyname))+" which was used to hold something.");
    empty->set_id( ({ emptyname, "empty "+emptyname, "empty container" }));
    empty->set_value(1);
    empty->set_weight(1);
  }

  return empty;
}

int is_drink() { return 1; }

