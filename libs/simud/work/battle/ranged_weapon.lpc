inherit "/battle/weapon";

/// \todo Document this file

int range;
int ammo;
int max_ammo;
string ammo_type;

/// Object editor information.
string ranged_weapon_info() {
  return "range\nammo\nmax_ammo\nammo_type";
}

/****************************** Queries ****************************/

int query_range() { return range; }

int query_ammo() { return ammo; }
int query_max_ammo() { return max_ammo; }
string query_ammo_type() { return ammo_type; }

string query_ammo_string() {
   if (max_ammo)
      return "The "+query_weapon_type()+" has "+ammo+" of "+max_ammo+" "+ammo_type+"s remaining.";
   else
      return "The "+query_weapon_type()+" fires "+ammo_type+"s.";
}

string query_look() {
   if ( this_player() == environment(this_object()) )
      return ::query_look()+"\n"+query_ammo_string();
   else
      return ::query_look();
}

/******************************* Sets *******************************/

void set_range(int x) { range = x; }

void set_ammo(int x) {
   if (x > max_ammo)
      x = max_ammo;
   if (x < 0)
      x = 0;
   ammo = x;
}
void add_ammo(int x) { set_ammo(ammo+x); }

void set_max_ammo(int x) { max_ammo = x; }
void set_ammo_type(string x) { ammo_type = x; }

/****************************** Other *******************************/

create() {
   ::create();
   range = 2;
}
