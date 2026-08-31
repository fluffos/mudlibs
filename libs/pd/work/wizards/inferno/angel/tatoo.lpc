#include <std.h>
inherit OBJECT;

void remove_me() { if (this_object()) remove(); }

void create() {
    ::create();
    set_name("mark");
    set_short("");
    set_id( ({ "halo_burn_mark" }));
    set_long("A burnt mark seared permanently into your forehead.");
    set_weight(0);
}

int query_auto_load() { return 1; }

int drop() { return 1; }

int bury() { return 1; }

int move(string str) { 
  int m;
  if (environment() && environment(this_object())->is_living())
    return 0;
  else {
    m = ::move(str);
    if (environment(this_object())->is_living() &&
        present("halo_burn_mark 2",environment(this_object())) )
          call_out("remove_me",1);
    return m;
  }
}

string extra_look() {
    string ob;
    object o;
    ob = environment(this_object())->query_cap_name();
    o = environment();
    return "%^BOLD%^%^RED%^"+ob+" has a burn mark the shape of a circlet across "+o->query_possessive()+" forehead and temples. "
    "\n%^BOLD%^%^WHITE%^An inscription in the burn reads: Annar Tilin%^RESET%^\n";
}
