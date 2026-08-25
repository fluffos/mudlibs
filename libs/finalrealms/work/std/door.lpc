// std/room/door.c

// This object is unusual -- it affects the inventory of two objects (rooms).
// Currently, that is handled by having two nearly identical objects.
// The creation and destruction require careful handling.
// When open, it must be open on both sides.
// However, may be locked from only one side. (maybe???)

// Isthar@Aurora 16-Jun 1994, added stuff for invis players
// 1995 Jul 20 Laggard      removed defines now in room.h.
// 1995 Jul 27 Laggard      extensive revision to stop forcing room loads.

#include "parse_command.h"
#include "room.h"
#include "door.h"

// debugging logs
#define DOOR_BUG_LOG "room_doors.bug"
#define ROOM_BUG_LOG "room.bug"

// protected variables:

private string
        my_long,
        my_short,
        *my_adjectives,
        *my_plurals,
        *my_names,
        key_prop;

private mixed
        *unlock_func,
        *open_func,
        *picked;

    // file_names instead of objects allows reload when rooms clean_up.
private string room_one;    // the creating room_file_name
private string exit_one;    // the creating exit_name

private string room_two;    // the other room_file_name (set when valid)
private string exit_two;    // the other exit_name (set by other room)

private string exit_type = "door";

private int
        locked,
        diff,
        open;


int do_unlock(object *obs);

void create() {
  my_adjectives = ({ });
  my_plurals = ({ "doors" });
  my_names = ({ "door" });
  key_prop = "generic_key";
  my_long = "";
}

void set_key_prop(string p) { key_prop = p; }
string query_key_prop() { return key_prop; }

void set_difficulty(int i) { diff = i; }
int query_difficulty() { return diff; }

void set_other_id(string s) { exit_two = s; }
string query_other_id() { return exit_two; }

void set_open_func(mixed *bing) { open_func = bing; }
mixed *query_open_func() { return open_func; }

void set_unlock_func(mixed *bing) { unlock_func = bing; }
mixed *query_unlock_func() { return unlock_func; }

void set_locked(int i) { locked = i; }
int query_locked() { return locked; }

void set_open(int i) { open = i; }
int query_open() { return open; }

void init() {
  this_player()->add_command("open", this_object(), "%D");
  this_player()->add_command("close", this_object(), "%D");
  this_player()->add_command("lock", this_object(), "%D %p %I");
  this_player()->add_command("unlock", this_object(), "%D %p %I");
}

string short() {
  return my_short;
}

string pretty_short() { return short(); }

string query_plural() { return pluralize(my_short); }
string pretty_plural() { return query_plural(); }

string long() {
  string ret;

  if (open)
    ret = "The " + my_short + " is open.\n";
  else {
    ret = "The " + my_short + " is closed.\n";
    if (locked)
      ret += "The " + my_short + " is locked.\n";
  }
  return my_long+ret;
}

void set_long(string s) { my_long = s; }
string query_long() { return my_long; }

string query_short() { return my_short; }
void set_short(string str) { 
  string *bits;

  bits = explode(str, " ");
  my_adjectives += bits[0..sizeof(bits)-2];
  my_names += ({ bits[sizeof(bits)-1] });
  my_short = str;
}

int drop() { return 1; }
int get() { return 1; }


// returns the values needed for setup {Laggard}
mixed query_door_values()
{
    return ({ open, locked, key_prop, diff, exit_one, });
}


// called immediately after door is cloned
void setup_door(
    string directive,
    object this_side,
    mixed other_side,
    mixed *values,
    string kind )
{
  string *bits, s;

    exit_one = directive;
    room_one = file_name(this_side);

    if ( stringp(other_side) )
    {
        room_two = other_side;
    }
    else if ( objectp(other_side) )
    {
        room_two = file_name(other_side);
    }
    else
    {
        log_file( ROOM_BUG_LOG, ctime(time())
            +" invalid door setup: " + other_side
            +", [" + directive
            +"] "
            + file_name(this_side)
            +"\n");
    }

    if ( kind )
    {
        exit_type = kind;
    }

  if (directive[0..5] == "enter ")
    my_short = directive[6..1000] +" " + exit_type;
  else
    my_short = directive + " " + exit_type;

  my_names = ({ });
  my_plurals = ({ });

  bits = explode(my_short, " ");
  my_names += ({ (s=bits[sizeof(bits)-1]) });
  my_plurals += ({ pluralize(s) });
  my_adjectives += bits;

  open = values[D_OPEN];
  locked = values[D_LOCKED];
  diff = values[D_DIFFICULTY];
  key_prop = values[D_KEY];
  exit_two = values[D_OTHER];
  picked = ({ });
}

void add_alias(string nam) {
  string *bits, s;

  bits = explode(nam, " ");
  my_names += ({ (s=bits[sizeof(bits)-1]) });
  my_plurals += ({ pluralize(s) });
  my_adjectives += bits;
}

int do_close() {
  if (!open)
    return 0;
  if (open_func) {
    if (!call_other(open_func[0], open_func[1], 0))
      return 0;
  }

  /* Ok...  now close it... */
  room_one->modify_exit(exit_one, ({ "open", 0 }));

  if (exit_two)
  {
    room_two->modify_exit(exit_two, ({ "open", 0 }));
    room_two->tell_door(exit_two, "The %D closed.\n");
  }
  return 1;
}

int do_open() {
  if (open)
    return 0;
  if (locked)
    if (!do_unlock(all_inventory(this_player())))
      return 0;
  if (open_func) {
    if (!call_other(open_func[0], open_func[1], 1))
      return 0;
  }

  /* Ok...  now open it... */
  room_one->modify_exit(exit_one, ({ "open", 1 }));

  if (exit_two)
  {
    room_two->modify_exit(exit_two, ({ "open", 1 }));
    room_two->tell_door(exit_two, "The %D opened.\n");
  }
  return 1;
}

int test_key(object ob) {
  return (int)ob->query_property(key_prop);
}

int do_lock(object *obs) {
  int ret;

  if (open)
    return 0;
  if (locked)
    return 0;
  if (unlock_func) {
    if (!(ret = call_other(unlock_func[0], unlock_func[1], 0)))
      return 0;
  }
  if (ret != 2)
    if (!sizeof(obs = filter_array(obs, "test_key", this_object())))
      return 0;

  /* Ok...  now lock it... */
  room_one->modify_exit(exit_one, ({ "locked", 1 }));

  if (exit_two)
  {
    room_two->modify_exit(exit_two, ({ "locked", 1 }));
    room_two->tell_door(exit_two, "The %D clicked.\n");
  }
  this_player()->add_succeeded(obs[0]);
  return 1;
}

int do_unlock(object *obs) {
  int ret;

  notify_fail("You cannot unlock the " + exit_type + ".\n");
  if (!locked)
    return 0;
  if (unlock_func) {
    if (!(ret = call_other(unlock_func[0], unlock_func[1], 1)))
      return 0;
  }
  if (ret != 2)
    if (!sizeof(obs = filter_array(obs, "test_key", this_object())))
      return 0;

  /* Ok...  now unlock it... */
  room_one->modify_exit(exit_one, ({ "locked", 0 }));

  if (exit_two)
  {
    room_two->modify_exit(exit_two, ({ "locked", 0 }));
    room_two->tell_door(exit_two, "The %D clicked.\n");
  }
  this_player()->add_succeeded(obs[0]);
  return 1;
}

int query_key() {
  if (key_prop != "generic_key")
    return 1;
  return 0;
}

void pick_lock(mixed pc) {
  picked += ({ ({ pc, 1 }) });
  set_locked(1);
}

void pick_unlock(mixed pc) {
  picked += ({ ({ pc, 0 }) });
  set_locked(0);
}  

string *parse_command_id_list() { return my_names; }
string *parse_command_plural_id_list() { return my_plurals; }
string *parse_command_adjectiv_id_list() { return my_adjectives; }

object query_parse_id(mixed *arr) {
  string *bits;
  mixed stuff;
  int i;

  if (arr[P_THING] == 0) {
    bits = explode(arr[P_STR], " ");
    return this_object();
  }
  if (arr[P_THING] < 0) { /* specific object case */
    arr[P_THING]++;
    if (arr[P_THING] != 0)
      return 0;
    arr[P_THING] = -10321;
    return this_object();
  }
  arr[P_THING]--; /* lots of objects case */
  if (arr[P_THING] != 0)
    return this_object();
  arr[P_THING] = -10786;
  return this_object();
}

void dest_me() {
  destruct(this_object());
  return ;
}

void dwep() {
  destruct(this_object());
  return ;
}

int move() { return 1; }


int moveing_close(object who)
{
  string oshrt;

  if (!exit_two)
  {
    // no door on other side, or move_player failed.
#ifdef DOOR_BUG_LOG
    if ( exit_type != "portal" )
    {
      log_file( DOOR_BUG_LOG, ctime(time())
            +" return door missing in "
            + room_two
            + " [" + exit_one
            + "] " + room_one
            +"\n");
    }
#endif
    return 0;
  }
  if (!room_two->call_door(exit_two, "do_close"))
    return 0;

  oshrt = (string)room_two->call_door(exit_two, "query_short");
  tell_object(who, "You close the "+oshrt+".\n");
// Isthar@Aurora 16-Jun 1994, keep hidden invis people
// Laggard@RotD not that hidden!
  if (who->query_invis() == 0)
  {
    tell_room(find_object(room_two), who->query_cap_name()+" closed the "+oshrt+".\n", ({who}));
  }
  else
  {
    tell_room(find_object(room_two), "The "+oshrt+" closed.\n", ({who}));
  }
  return 1;
}


int moveing_open(object who)
{
  if (!do_open())
    return 0;
  tell_object(who, "You open the "+my_short+".\n");
// Isthar@Aurora 16-Jun 1994, keep hidden invis people
  if (who->query_invis() == 0)
  {
    tell_room(find_object(room_one), who->query_cap_name()+" opened the "+my_short+".\n",({who}));
  }
  else
  {
    tell_room(find_object(room_one), "The "+my_short+" opened.\n", ({who}));
  }
  return 1;
}


int moveing_lock(object who)
{
  string oshrt;

  if (!exit_two)
  {
    // no door on other side, or move_player failed.
#ifdef DOOR_BUG_LOG
    if ( exit_type != "portal" )
    {
      log_file( DOOR_BUG_LOG, ctime(time())
            +" return door missing in "
            + room_two
            + " [" + exit_one
            + "] " + room_one
            +"\n");
    }
#endif
    return 0;
  }
  if (!room_two->call_door(exit_two, "do_lock", all_inventory(who)))
    return 0;

  oshrt = (string)room_two->call_door(exit_two, "query_short");
  tell_object(who, "You lock the "+oshrt+".\n");
// Isthar@Aurora 16-Jun 1994, keep hidden invis people
// Laggard@RotD not that hidden!
  if (who->query_invis() == 0)
  {
    tell_room(find_object(room_two), who->query_cap_name()+" locked the "+oshrt+".\n", ({who}));
  }
  else
  {
    tell_room(find_object(room_two), "The "+oshrt+" clicked.\n", ({who}));
  }
  return 1;
}


int moveing_unlock(object who)
{
  if (!do_unlock(all_inventory(who)))
    return 0;
  tell_object(who, "You unlock the "+my_short+".\n");
// Isthar@Aurora 16-Jun 1994, keep hidden invis people
  if (who->query_invis() == 0)
  {
    tell_room(find_object(room_one), who->query_cap_name()+" unlocked the "+my_short+".\n",({who}));
  }
  else
  {
    tell_room(find_object(room_one), "The "+my_short+" clicked.\n", ({who}));
  }
  return 1;
}


void tell_door(string str)
{
    // Laggard@RotD removed the names from the messages,
    // since this_player() isn't in the room anyway....
    tell_room(find_object(room_one), replace(str, "%D", my_short), ({ this_player() }));
}
