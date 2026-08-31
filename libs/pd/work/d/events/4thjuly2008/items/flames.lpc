
#include <std.h>
#include <id4.h>

#define HP 7000000

inherit OBJECT;

mapping hit = ([]);
object *hitting = ({});
void set_hit(string n, int x) { hit[n] = x; }
mapping query_hit() { return hit; }

void create() {
  ::create();
  set_name("flame");
  set_id( ({ "flames", "ball of flame" }) );
  set_short("a giant ball of flame");
  set_long("This giant fire ball acts as a prison for the dragon that can "
           "just be seen in its depths.");
  set_prevent_get("It is far too large.");
  set_weight(5000);
  set_heart_beat(2);
}

void heart_beat() {
  object env = environment();
  object *tokens;
  object dragon;
  if (!env) return;
  if (random(1000) < 10) message("info", "%^BOLD%^%^BLUE%^The dragon yells: Don't step into the flames!", env);
  foreach (object p in hitting) {
    int hp, maxhp;
    string name;
    if (!p || environment(p) != env) {
      hitting -= ({ p });
      continue;
    }
    hp = p->query_hp();
    maxhp = p->query_max_hp();
    name = p->query_name();

    message("info", "%^ORANGE%^The flames burn you badly!", p);
    if (!random(5))
      message("info", "%^ORANGE%^The flames burn "+p->query_cap_name()+
	" badly!", env, p);

    p->do_damage(p->return_limb(), hp/3);
    if (!hit[name]) hit[name] = 0;
    hit[name] += hp/3;

    if (hp < maxhp/10) {
      message("info", "%^YELLOW%^Your body suddenly trembles from the pain "
	              "and you fall back onto the floor.", p);
      message("info", "%^YELLOW%^"+p->query_cap_name()+
	              " trembles in pain and falls back onto the floor.",
		      env, p);
      hitting -= ({ p });
    }

    if (hp < 1) p->set_hp(1);

    if (hit[name] >= HP) {
      if (p->query_race() == "dragon" ||
	  (sizeof(tokens = children(ITEMS+"token")) &&
	  sizeof(filter(tokens, (: $1->query_owner() == $2 :), p))) ) {
	hit[name] = 0;
	return;
      }
      set_heart_beat(0);
      dragon = new(MOBS+"blue_dragon");
      dragon->move(env);
      dragon->set_person(name);
      dragon->set_people(keys(hit));
      dragon->start();
      remove();
      return;
    }

  }
}

void init() {
  ::init();
  add_action("do_step", "step");
}

int do_step(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);

  if (!tp || !to || !env || env != environment(tp)) return 0;

  if (tp->query_busy())
    return notify_fail("You are busy.\n");

  if (!str) return notify_fail("Step where?\n");
  if (regexp(str, "(in|into) (the )?(flame|fire)")) {
    if (member_array(tp, hitting) != -1)
      return notify_fail("You are already in the flames.\n");
    hitting += ({ tp });
    message("info", "You step forward into the flames.", tp);
    message("info", tp->query_cap_name()+" steps forward into the flames.",
      env, tp);
    tp->set_disable(1);
    return 1;
  }
  else if (regexp(str, "out( (of )?the )?(flame|fire)?")) {
    if (member_array(tp, hitting) == -1)
      return notify_fail("You are not in the flames.\n");
    hitting -= ({ tp });
    message("info", "You step back out of the flames.", tp);
    message("info", tp->query_cap_name()+" steps back out of the flames.",
      env, tp);
    tp->set_disable(1);
    return 1;
  }

  return notify_fail("Step where?\n");
}

