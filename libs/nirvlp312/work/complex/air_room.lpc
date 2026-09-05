/*
 * air_room.c by Alfe for Tubmud 01-Jul-11
 *
 * an air_room is part of the air space above the ground in the mud.
 * one air_room should cover a whole area of normal rooms.  some of the
 * rooms below it should be possible landing places if appropriate and
 * all of the outside rooms of the area below should call set_air_room()
 * with the object name of the proper air_room.
 */

#pragma strong_types

#include <prop/room.h>
#include <event.h>
#include <message.h>
#include <exits.h>

inherit "complex/room";

/*
 * landing_places looks as follows:
 * ([ "churchyard": "/room/church/yard/graves",
 *    "shop":       "/room/vil_road2",    // we land _before_ the shop
 *    "shore":      "/room/jetty2" ])
 */
mapping landing_places;

private void receive_move_event(mapping e,string type,int prio) {
  e[E_IN] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"fly",M_ARG,E_AGENT," in." });
  if (e[E_FROM] == this_object() && e[E_DIR] != "X") {
    switch (e[E_DIR]) {
    case "north": case "northeast": case "east": case "southeast":
    case "south": case "southwest": case "west": case "northwest":
      e[E_OUT] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"fly",M_ARG,E_AGENT," ",
                    M_ARG,E_DIR,"." });
      break;
    default:
      e[E_OUT] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"fly",M_ARG,E_AGENT,
                    " towards ",M_THE,M_ARG,E_DIR,"." });
      break;
    }
  }
}

private mixed air_long;
void set_air_long(mixed desc) { air_long = desc; }
string query_air_long() { return funcall(air_long); }

private mixed far_short;
void set_far_short(mixed desc) { far_short = desc; }
string query_far_short() { return funcall(far_short); }

private mixed far_id;
void set_far_id(mixed id) { far_id = id; }
string query_far_id() { return funcall(far_id) || ({}); }

status far_id(string s) { return member(query_far_id(),s) >= 0; }

void set_long(mixed desc) { set_air_long(desc); }
void set_air_room_long(mixed desc) { room::set_long(desc); }

string query_air_room_long() {
  string res;
  mixed h;
  res = air_long;
  mapping g;
  h = transpose_array("complex/room"::query_exit()[0..1]);
  h = filter(h,(: !catch(load_object($1[1])) :));  // remove buggies
  h = map(h,(: ({ $1[0],$1[1]->query_far_short() }) :));
  h = filter(h,(: $1[1] :));  // remove those without far_short
  if (sizeof(h)) {
    g = ([]);
    foreach (string *x in h)
      if (g[x[1]])
        g[x[1]] += ({ x[0] });
      else
        g[x[1]] = ({ x[0] });
    //h = map(g, (: sprintf("%O (%O)", $1, $2) :));
    h = m_values(map(g, (: $1 + " (" + make_list($2) + ")" :)));
    return ("You are flying in the air.\n" +
            query_air_long() +
            "If you look further you can see:\n" +
            capitalize(make_list(h)) + ".\n");
  }
  else
    return ("You are flying in the air.\n" +
            query_air_long());
}

void configure() {
  room::configure();
  set_short("a non-descript room in the air space","in");
  set_long((: (query_far_short()?
               ("Below you can see:\n" +
                capitalize(query_far_short())) :
               ("This is above " + query_short())) + ".\n" :));
  set_air_room_long(#'query_air_room_long);
  set_property(P_AIR_ROOM);
  set_property(P_NO_GROUND);  // we will be more specific later.
  set_property(P_OUTSIDE);
  set_property(P_DAYLIGHT);
  //set_property(P_NO_MAP);
}

varargs void set_short(string desc,string preposition) {
  room::set_short(desc,preposition || "above");
}

#define DEFAULT_LANDINGPLACE_DESC "It is a landing place; you could land" \
                                  " there to have a closer look.  Or type" \
                                  " 'look at <place>' to see what is going" \
                                  " on there.\n"

private status dummy_fail_exit(string foo, status silently) {
  if (!silently)
    write("There's no exit in that direction.\n");
  return 1;
}

void add_landing_place(mixed name, string file) {
  int k;
  if (pointerp(name)) {
    map(name,#'add_landing_place,file);
    return;
  }
  landing_places[name] = file;
  if ((k = strstr(name, " ")) > 0) { // exit contains spaces (longer than verb)
    add_exit(file, name[0..k-1],     // Coogan, 06-Aug-2002
             "hook_" + regreplace(name, " ", "_", 1),  // this is the exit
             EXIT_INVISIBLE | EXIT_LONGER_THAN_VERB);  // to be used
    add_exit("", name, #'dummy_fail_exit);  // and this one is shown in
                                         // exit_long(), but can never be used
  }
  else
    add_exit(file, name);
  add_item(name,DEFAULT_LANDINGPLACE_DESC);
  if (!stringp(query_property(P_NO_GROUND)))
    set_property(P_NO_GROUND,file);
}

void remove_landing_place(string name) {
  m_delete(landing_places,name);
  if (long(name) == DEFAULT_LANDINGPLACE_DESC)
    remove_item(name);
  remove_exit(name);
}

void set_landing_places(mixed *places) {
  mapping view;
  map(m_indices(landing_places),#'remove_landing_place);  // remove all first
  map(places,(: add_landing_place($1[0],$1[1]) :));  // set the new ones
  view = ([]);
  foreach (mixed place : places)
    if (sizeof(place) > 2)
      view[place[2]] = place[1];
    else
      view["at the " + place[0]] = place[1];
  set_view(view);
}

string obvious_exit_description(status plural) {
  return (plural? "possible landing places" : "possible landing place");
}

string *query_exit_long_commands() {
  return (room::query_exit_long_commands() -
          ({ "north", "northeast",
             "east", "southeast",
             "south", "southwest",
             "west", "northwest" }));
}

string long(string s) {
  mixed h;
  h = room::long(s);
  if (h)
    return h;
  h = transpose_array("complex/room"::query_exit()[0..1]);
  h = filter(h,(: $1[1]->far_id($2) :),s);
  return ("You could fly " + make_list(transpose_array(h)[0],0," or ") +
          " to have a closer look.\n");
}

status id(string s) {
  if (member(({ "sky", "moon", "sun", "star", "stars" }), s) > -1)
    return room::id(s);
  return (room::id(s) ||
          !!sizeof(filter(transpose_array(("complex/room"::query_exit() ||
                                           ({}))[0..1]),
                          (: $1[1]->far_id($2) :),s)));
}

private mixed desc_tree;

// m = ({});
// desc_tree = ({ ({ "nose","Nose.\n",
//                   ({ ({ "pimple","Pimple.\n" }) }) }) });
// path = "head's ";
private void set_desc_subtree(mixed *m,mixed desc_tree,string path) {
  map(desc_tree,(: (add_item(pointerp($1[0])?
                             ($1[0] + ({ $3 + $1[0][0] })) :
                             ({ $1[0],$3 + $1[0] }),$1[1]),
                    $2 = ({ $1[0],$1[1],({}) }),
                    (sizeof($1) > 2 &&
                     set_desc_subtree(&($2[2]),$1[2],
                                      $3 + (pointerp($1[0])?
                                            $1[0][0] :
                                            $1[0]) + "'s "))) :),
      &m,path);
}

varargs void set_desc_tree(mixed *m) {
  set_short(m[0]);
  set_long(m[1]);
  desc_tree = ({ m[0],m[1],({}) });
  set_desc_subtree(&(desc_tree[2]),m[2],"");
}

mixed *query_desc_tree() { return desc_tree; }

private string *directions = ({ "north","northeast","east","southeast",
                                "south","southwest","west","northwest" });

void complete_exits() {
  mixed result;
  result = "complex/room"::query_exit();
  for (int i=sizeof(directions); i-->0; ) {
    if (result &&  // has any exits at all?
        member(result[0],directions[i]) < 0) {  // doesn't have that dir yet?
      // find nearest neighbour direction:
      status done;
      done = 0;
      foreach (int j : ({ 1,7,2,6 })) {
        int neighbour;
        neighbour = member(result[0],directions[(i+j) % 8]);
        if (neighbour >= 0) {  // this one exists?
          add_exit(result[1][neighbour],
                   directions[i],
                   lambda(0,
                          ({ (#'send_message),
                             quote(({ M_WRITE,
                                      "You are blown " + result[0][neighbour] +
                                      " on your flight." })) })));
          done = 1;
          break;
        }
      }
      if (!done)  // no other exit found?
        add_exit(object_name(this_object()),
                 directions[i],
                 (: send_message(({ M_WRITE,
                                    "You are blown back on your"
                                    " flight." })) :));
    }
  }
}

void create() {
  landing_places = ([]);
  room::create();
  complete_exits();
  listen_event("move",300,#'receive_move_event);
}
