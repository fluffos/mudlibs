#include <uid.h>
#include <mudlib.h>

int experience;
int band_xp;

int query_band_exp() {
  if ((string)this_object()->query("leader") !=
      (string)this_object()->query("name"))
 return find_player(this_object()->query("leader"))->query_band_exp();
 return band_xp;
}

int band_share(int x) {
  if (!intp(x)) return 1;
  if (!this_object()->query("leader")) return -1;
  experience += x;
  return 0;
}

int add_band_exp(int x) {
  if (!intp(x)) return 1;
  band_xp += x;
  return 0;
}
int
add_exp(int e) {
/*
  if(this_player() && this_player() != this_object() && 
   (int)((object)this_player()->query_link())->query("wizard")
*/
  if (userp(this_player()))
   log_file("add_exp", "[ " + ctime(time()) + " ] " + 
     this_player()->query("cap_name") + " added "+e+
     " experience points to " + this_object()->query("cap_name") +
    ".\n");
 if (this_object()->query("leader")) {
     find_player(this_object()->query("leader"))->add_band_exp(e);
  return 0;
 }
  experience += e;
  return experience;
}

int
query_exp() {
    if (experience<0) experience = 0;
  return experience;
}

void
set_exp(int e) {
  if(geteuid(previous_object()) != ROOT_UID)
    return;
  if (file_name(previous_object()) != "/adm/daemons/guild_d")
  log_file("SETXP", ctime(time()) + "   " +
      (string)TP->query("cap_name") +
  " had "+ possessive(TP->query("gender")) +
  " experience set to "+ e + ".\n");
  experience = e;
}

