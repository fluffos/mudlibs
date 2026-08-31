
#include <std.h>

mapping Afflictions = ([]);


string *query_afflictions();
mapping query_affliction_map();
int query_is_afflicted(string aff);
mixed query_affliction(string aff);
void set_affliction(string aff, mixed val);
void add_affliction(string aff, mixed val);
void remove_affliction(string aff);

int query_blind();
void set_blind(int i);
int query_bleeding();
void set_bleeding(int i);
void add_bleeding(int i);
int query_stupor();
void set_stupor(int i);
string *query_crippled();
void set_crippled(mixed l);
int query_poisoned();
void set_poisoned(int i);
void add_poisoned(int i);
/*
int query_poisoning();
void add_poisoning(int x);
*/


void create() {
  Afflictions = ([]);
}


string *query_afflictions() { return keys(Afflictions); }

mapping query_affliction_map() { return Afflictions; }

int query_is_afflicted(string aff) {
  return member_array(aff, query_afflictions()) != -1;
}

mixed query_affliction(string aff) {
  if (query_is_afflicted(aff))
    return Afflictions[aff];
  else
    return 0;
}

void set_affliction(string aff, mixed val) {
  Afflictions[aff] = val;
}

void add_affliction(string aff, mixed val) {
  if (!query_is_afflicted(aff))
    set_affliction(aff, val);
}

void remove_affliction(string aff) { map_delete(Afflictions, aff); }


// ---------
// shortcuts for common bad things
// ---------

int query_blind() { return query_affliction("blind"); }
void set_blind(int i) { set_affliction("blind", i < 1 ? 0 : 1 ); }

int query_bleeding() { return query_affliction("bleeding"); }
void set_bleeding(int i) { set_affliction("bleeding", i < 0 ? 0 : i ); }
void add_bleeding(int i) { set_affliction("bleeding", query_bleeding() + i); }

int query_stupor() { return query_affliction("stupor"); }
void set_stupor(int i) { set_affliction("stupor", i < 1 ? 0 : 1 ); }

varargs mixed query_crippled(string limb) {
  if (stringp(limb)) {
    if (this_object()->query_is_limb(limb))
      return member_array(limb, query_crippled()) != -1;
    else
      return 0;
  }
  else
    return query_affliction("crippled") || ({});
}
void set_crippled(mixed l) {
  if (arrayp(l))
    set_affliction("crippled", l);
  else if (stringp(l))
    set_affliction("crippled", query_affliction("crippled") + ({ l }) );
}

int query_poisoned() { return query_affliction("poisoned"); }
void set_poisoned(int i) { set_affliction("poisoned", i < 0 ? 0 : i); }
void add_poisoned(int i) { set_affliction("poisoned", query_poisoned() + i); }
/*
int query_poisoning() { return query_poison(); }
void add_poisoning(int x) { add_poisoned(x); }
*/

