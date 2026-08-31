///std/drink.c
//from the Nightmare mudlib
//inheritable drink code
//created by Descartes of Borg October 1992

#include <teststd.h>

inherit OBJECT;

string my_mess, your_mess, type, emptyname, emptyfile;
int strength, poison, disable;
mixed Extra;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_empty_name(string str);
void set_empty_file(string);
void set_poisoned(int);
void set_disable(int);
void set_extra(mixed);
int query_poisoned();
object clone_empty(object tp);
void set_strength(int x);
int query_strength();
void set_type(string str);
string query_type();
string query_my_mess();
string query_your_mess();
string query_empty_name();
string query_empty_file();

string expandos(string str) {
  mapping rep = ([
    "N" : (: (this_player() ? this_player()->query_cap_name() : "") :),
    "P" : (: (this_player() ? this_player()->query_possessive() : "") :),
    "AN" : (: (this_object() ? indefinite_article(strip_color(this_object()->query_short())) : "")
:),
    "O" : (: (this_object() ? strip_color(this_object()->query_short()) : "") :),
  ]);

  foreach (string key, mixed f in rep)
    str = replace_string(str, "$"+key, evaluate(f));

  return str;
}

void create() {
  ::create();
  set_my_mess("You drink some $O.");
  set_your_mess("$N drinks some $O.");
  set_strength(1);
  set_poison(0);
  set_disable(1);
  set_empty_name("bottle");
  set_type("soft drink");
}

void set_empty_name(string str) { emptyname = str; }
string query_empty_name() { return emptyname; }
void set_empty_file(string str) { emptyfile = str; }
string query_empty_file() { return emptyfile; }

void set_strength(int x) { strength = x; }
int query_strength() { return strength; }

void set_my_mess(string str) { my_mess = str; }
string query_my_mess() { return expandos(my_mess); }

void set_your_mess(string str) { your_mess = str; }
string query_your_mess() { return expandos(your_mess); }

void set_type(string str) { type = str; }
string query_type() { return type; }

int drink(string str) {
   if(!id(str)) return 0;
   if(this_player()->query_current_attacker()) {
      notify_fail("You are too busy to drink anything now!\n");
      return 0;
   }
   /* Plura 930202 */
   if(environment(this_object()) != this_player()) {
      notify_fail("You must get it first.\n");
      return 0;
   }
   if(this_player()->query_disable())
      return notify_fail("You are too busy to take a drink right now!\n");
   if(query("type") == "soft drink") {
      if(!this_player()->add_quenched(query("strength"))) {
         notify_fail("You are too bloated to drink that!\n");
         return 0;
      }
   }
   else if(query("type") == "caffeine") {
      if((int)this_player()->query_intox() > query("strength")*9) {
         notify_fail("You do not feel the need for that right now.\n");
         return 0;
         }
      if(!this_player()->add_quenched(query("strength"))) {
         notify_fail("You are too bloated to drink that!\n");
         return 0;
         }
      this_player()->add_intox(-query("strength")/2);
   }
   else if(query("type") == "alcoholic") {
      if(!this_player()->add_intox(query("strength"))) {
         notify_fail("You are just about to pass out as it is.\n");
         return 0;
         }
   }
   this_player()->heal(query("strength")*2);
   write(my_mess);
   this_player()->set_disable();
   say(this_player()->query_cap_name()+" "+your_mess, this_player());
   clone_empty(this_player());
   remove();
   return 1;
}

object clone_empty() {
  object empty;
   
  if (emptyfile) empty = new(emptyfile);
  else if (emptyname) {
    empty = new("/std/object");
    empty->set_short("an empty "+emptyname);
    empty->set_long(capitalize(indefinite_article(emptyname))+" which was used to hold something.");
    empty->set_id( ({ emptyname, query_short(), indefinite_article(emptyname), "empty container" }) );
    empty->set_value(1);
    empty->set_weight(1);
  }

  return empty;
}
