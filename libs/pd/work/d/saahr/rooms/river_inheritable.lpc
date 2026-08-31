
#include <std.h>
#include <rooms.h>
#include <saahr.h>

#define RES "%^RESET%^"
#define CURRENTCOL "%^BOLD%^%^CYAN%^"
#define DEF_CURRENT_TIME 8

inherit ROOM;
inherit PERIODIC;
inherit SWIM_CODE;

int current_time;
int current_counter;

int periodic();
void set_current_time(int x);
string query_long();

void create() {
  room::create();
  periodic::create();
  set_properties((["water":1, "indoors":0, "light":2, "night light":0]));
  set_short("in a river");
  set_listen("default", "The water roars in your ears.");
  set_current_time(DEF_CURRENT_TIME);
  //load_object(RIVER_DAEMON)->add_room(this_object());
}

void init() {
  room::init();
  periodic::init();
  swim_code::init();
}

int remove() {
  //load_object(RIVER_DAEMON)->remove_room(this_object());
  return room::remove();
}

void set_exits(mapping exits) {
  room::set_exits(exits);
  add_invis_exit("upriver");
  add_invis_exit("downriver");
}

string query_long() { return "%^CYAN%^"+(room::query_long())+"%^RESET%^"; }

//void set_current_time(int x) { current_time=intp(x)?x:DEF_CURRENT_TIME; }
void set_current_time(int x) { set_period(x/2 || DEF_CURRENT_TIME); }

int periodic() {
  object *ai;
  object next;

  //if (++current_counter < current_time) return;

  //current_counter=0;

  if ((next = load_object(query_exit("downriver"))) == load_object(ROOM_VOID))
    return;

  ai = all_inventory(this_object());

  foreach (object what in ai) {

    if (living(what)) {
      message("info", CURRENTCOL+"The current pushes you down river."+RES,what);
      message("mout", CURRENTCOL+"The current pushes "+what->query_cap_name()+
        " down river."+RES,this_object(),what);
      what->move(next);
      what->describe_current_room(1);
      message("min", CURRENTCOL+what->query_cap_name()+" is washed in on the current."+RES,
        next, what);
    }

    else {
      message("info", CURRENTCOL+"The current pushes some objects down river."+RES,
        this_object());
      what->move(next);
      message("info", CURRENTCOL+"Some objects float in on the current."+RES,
        next);
    }
  }

  return (sizeof(ai) ? 1 : 0);
  
}

