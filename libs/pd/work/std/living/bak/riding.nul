
// code to handle riding and being ridden

#define RIDABLE_TYPES ({\
  "horse", "centaur", "dragon", \
  "equine", "hornedequine", "pegasus", \
  "pegataur", "raknid", "weimic", \
  "unicorn", \
})

private static object Riding;
private static object *Rider;
private static int MaxRiders;
private static int Rideable;
private static int RideAllow;
private static mixed RideAllowFunc;
private static string MountMsg;
private static string UnmountMsg;

void set_riding(object ob);
void remove_riding();
object query_riding();
void set_mounting(object ob);
object query_mounting();

void set_rider(object ob);
void add_rider(object ob);
void remove_rider(object ob);
object query_rider();
object *query_riders();
void set_mounted(object ob);
object query_mounted();

void set_max_riders(int x);
int query_max_riders();

void set_ridable(int x);
void set_rideable(int x);
int query_rideable();
int query_ridable();
int query_rideallow(object ob);
int query_allowmount(object ob);
int query_allowedmount(object ob);

void set_mount_message(string msg);
void set_unmount_message(string msg);
string query_mount_message();
string query_unmount_message();

string query_riders_list();

void create() {
  Riding = 0;
  Rider = ({});
  Rideable = 0;
  RideAllow = 0;
  RideAllowFunc = 0;
  MountMsg = 0;
  UnmountMsg = 0;
}

void set_riding(object ob) { if (!Riding) Riding = ob; }
void remove_riding() { Riding = 0; }
object query_riding() { return Riding; }
void set_mounting(object ob) { set_riding(ob); }
object query_mounting() { return query_riding(); }

void set_rider(object ob) {
  if (sizeof(Rider) < query_max_riders())
    Rider += ({ ob });
}
void add_rider(object ob) { set_rider(ob); }
void remove_rider(object ob) { Rider -= ({ ob }); }
object query_rider() { return sizeof(query_riders()) ? query_riders()[0] : 0; }
object *query_riders() {
  Rider = filter(Rider, (: objectp($1) :) );
  return copy(Rider);
}
void set_mounted(object ob) { set_rider(ob); }
object query_mounted() { return query_rider(); }

void set_max_riders(int x) { MaxRiders = x; }
int query_max_riders() {
  if (!MaxRiders) {
    if (this_object()->query_race() == "dragon")
      return 2;
    else
      return 1;
  }
  return MaxRiders;
}

// is it physically possible to ride me??
// set_rideable is just for mobs
void set_ridable(int x) { set_rideable(x); }
void set_rideable(int x) { Rideable = x; }
int query_ridable() { return query_rideable(); }
int query_rideable() {
  object to = this_object();
  string race;
  if (Rideable) return 1;
  if (userp(to))
    race = to->query_race();
  else
    race = to->query_body_type();
  return member_array(race, RIDABLE_TYPES) != -1;
}

// is ob allowed to ride me??
// set_rideallow is just for mobs
void set_rideallow(mixed f) {
  if (intp(f))
    RideAllow = f;
  if (functionp(f))
    RideAllowFunc = f;
}
int query_rideallow(object ob) {
  object to = this_object();
  if (!userp(to)) {
    if (functionp(RideAllowFunc))
      return (*RideAllowFunc)(ob);
    else
      return RideAllow;
  }
  else {
    mixed tmp;
    if (userp(ob))
      tmp = ob->query_name();
    else
      tmp = ob;
    return
      member_array(tmp, to->query_allow("mount")) != -1 ||
      member_array("all", to->query_allow("mount")) != -1;
  }
}
int query_allowmount(object ob) { return query_rideallow(ob); }
int query_allowedmount(object ob) { return query_rideallow(ob); }

void set_mount_message(string msg) { MountMsg = msg; }
void set_unmount_message(string msg) { UnmountMsg = msg; }
string query_mount_message() { return MountMsg; }
string query_unmount_message() { return UnmountMsg; }

string query_riders_list() {
  object *r;
  string *l;
    
  switch ((int)sizeof(r = query_riders())) {
    case 0:
    return "";

    case 1:
    return r[0]->query_cap_name();
    
    default:
    l = r->query_cap_name();
    
    l = map(l[0..<3], (: $1 = $1+", " :) ) +
      ({ l[<2] + " and ", l[<1] });
  
    return implode(l, "");
  }   
  
  return "";
}
