
#include <std.h>
#include <dragonevent.h>

inherit PERIODIC_ROOM;

void check_sound(object);
void check_die(object);

string *speech = ({
  "Time seems to stop...",
  "Your body stands rigid in pitch darkness.",
  "A murmuring can be heard in the distance.",
  (: check_sound :),
  "The noise slowly fades away.",
  "You suddenly begin to fall.",
  (: check_die :),
});

mapping speechcounters = ([
]);

int can_death_event(object ob) {
  if(DRAG_D->query_data("cavenodeaths")) {
    message("info", "%^BLUE%^Nobody will be dying in this cave today...", ob);
    return 0;
  }
  if (!ob->is_player()) return 0;

  ob->set_hp(ob->query_max_hp());

  ob->set_paralyzed(sizeof(speech)*query_period() + 14,
    "As you try to move, something pulls your "
    "arms and legs straight back down.");

  speechcounters[ob->query_name()] = 0;

  return ::receive_objects(ob);
}

int receive_objects(object ob) {
  if(!can_death_event(ob)) {
    message("info", "%^BOLD%^%^BLUE%^You feel yourself being healed...", ob);
    message("info", "%^GREEN%^You are teleported elsewhere.", ob);
    ob->move(DRAG_ROOMS+"py/entrance");
    return 0;
  }
  return 1;
}

int periodic() {
  object *players = filter(all_inventory(), (: $1->is_player() :) );
  foreach (object pl in players) {
    string name = pl->query_name();
    int count = speechcounters[name];
    mixed line;

    if (!count) count = 0;
    line = speech[count];

    if (functionp(line))
      evaluate(line, pl);
    else if (stringp(line) && strlen(line))
      message("info", line, pl);
    
    if (!pl) {
      players -= ({ pl });
      map_delete(speechcounters, name);
    }
    else speechcounters[name] = count+1;
  }
  return sizeof(players) ? 1 : 0;
}

void check_sound(object pl) {
  string msg;
  string name = pl->query_name();
  int count = DRAG_D->query_data("cavecouragedeaths:"+name);
  if (count > 5)
    msg = "The murmuring grows to an angry cacophony!";
  else if (count > 2)
    msg = "The murmuring continues for a long while.";
  else
    msg = "The murmuring seems to come from every direction.";
  message("info", msg, pl);
}

void check_die(object pl) {
  string msg;
  string name = pl->query_name();
  int count = DRAG_D->query_data("cavecouragedeaths:"+name);
  int chance = 100;
  object corpse;
  DRAG_D->set_data("cavecouragedeaths:"+name, count + 1);
  chance = 100 - (log(count+1)*40);
  if (chance < 10) chance = 10;
  pl->move(DRAG_ROOMS+"py/entrance");
  if (random(100) <= chance || DRAG_D->query_data("cavenodeaths")) {
    message("info", "The sky seems to soften and slow your descent.\n",pl);
    pl->set_paralyzed(4, "You are falling.", "You find yourself back on solid ground.");
    pl->remove_paralyzed();
  }
  else {
    message("info", "You smash into the ground and splatter all over the place!", pl);
    pl->set_hp(-1500);
    pl->die();
    corpse = present("remains", load_object(DRAG_ROOMS+"py/entrance"));
    if (corpse && corpse->query_name() == pl->query_name())
      corpse->remove();
  }
}

void create() {
  skip_obvious();
  set_period(2);
  set_short("a swirling void");
  set_long("Dizzying blackness swirls around.");
  set_properties( ([
    "no teleport" : 1, "no scry" : 1,
    "no attack" : 1, "no magic" : 1, "no steal" : 1,
    "light" : 0,
  ]) );
}

