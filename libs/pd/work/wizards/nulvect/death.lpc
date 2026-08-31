
// definition of ROOMS_ and SQUARE_LOC macros:
#include <rooms.h>

// definition of Death struct:
#include <death_cl.h>

// for WAR_D, VAMPIRE_D, PLAYER_D, ADVANCE_D:
#include <daemons.h>


// how many deaths to store full information
#define MAX_RECENT_DEATHS 3


int query_ghost();
void set_ghost(int x);
void revive();
void return_to_death_site();
varargs void die(mixed source);
mapping apply_death_penalties(int perc);
void add_recent_death(class Death d);
class Death *query_recent_deaths();


class Death *RecentDeaths;
int ghost;


int query_ghost() { return ghost; }
void set_ghost(int x) {
  if (!this_object()->query_undead())
    ghost = x;
}

void revive() {
  object to = this_object();
  message("my_action", "You return from the dead!", to);
  message("other_action", to->query_cap_name()+ " returns from the dead!",
      environment(to), to);
  to->new_body();
  to->set_hp(5);
  to->set_ghost(0);
  to->fix_vital_bonus();
  to->save_player(to->query_name());
}

void return_to_death_site() {
  class Death d;
  int s;
  string room;

  if ((s=sizeof(RecentDeaths)) > 0 && d=RecentDeaths[s-1] && d->room &&
      strsrch(d->room, "#") == -1 && load_object(d->room)) {
	room = d->room;
  }
  else {
    room = SQUARE_LOC;
  }

  this_object()->move(room);
}

varargs void die(mixed source) {
  object to = this_object();
  object env = environment(to);
  object atck;
  string myrace, hisrace;
  string area, deathroom;
  string desc, zone;
  string mymsg, roommsg, allmsg;
  int pk, perc, nocorpse, score;
  mixed *conflict;
  class Death death;
  mapping penalties;
  mixed *deathsource;

  // the %s is replaced with query_cap_name()
  string *death_messages = ({
    "Silence overcomes the land as %s dies.",
    "A scream is heard across the land as %s dies.",
    "The world darkens for a moment as %s dies.",
    "You hear a terrible howl as %s is slain.",
    "A flash of lightning marks the death of %s.",
    "No stuck pig has squealed like %s in death.",
  });


  if (to->query_arena()) {
    ROOM_ARENA->arena_die(to);
    return;
  }

  if (wizardp(to) && !to->query_killable()) {
    message("death", "You are immortal and cannot die.", to);
    to->set_hp(to->query_max_hp());
    return;
  }

  // in living.c
  deathsource = to->find_death_source(source);
  atck = deathsource[0];
  desc = deathsource[1];
  zone = deathsource[3];

  to->dismount_all(to->query_cap_name()+" falls from your back.",
    to->query_cap_name()+" bucks you off.");

  if (atck) {
    conflict = WAR_D->query_conflict(to, atck);
  }

  if (conflict) {
    perc = conflict[2];

    // conflict[0] is the alliance this player belongs to
    switch (conflict[0]) {
      case "holy forces":
      case "abyssal forces":
	score = WAR_D->query_score(conflict[0])["total"] || 0;

	// should never happen
	if (score < 0)
	  score = 0;

	// if 0, the opposing alliance is already beating us
	if (score == 0) {
	  // just increase their score
	  WAR_D->add_score(conflict[1], "total", 1);
	}
	// if we have points, we're ahead right now
	else {
	  // remove one point from us
	  WAR_D->add_score(conflict[0], "total", -1);
	}
      break;
      default:
    }
  }

  myrace = to->query_race();
  if (atck)
    hisrace = atck->query_race();
  else
    hisrace = "";

  if (to->query_subrace() == "vampire") {
    if (VAMPIRE_D->query_sunlight(to)) {
      perc = 170;
    }
    else {
      perc = 80;
    }
    deathroom = 0;
    nocorpse = 1;
    mymsg =
      read_file("/news/vampdeath")+"\n"
      "%^BOLD%^%^RED%^"
      "A blinding flash of pain sears through your body."
      "%^RESET%^\n"
    ;
    roommsg =
      "%^BOLD%^%^RED%^A flash of crimson lightning erupts around "+
      to->query_cap_name()+"!%^RESET%^";
    ;
    allmsg =
      "%^BOLD%^%^RED%^" +
      sprintf( death_messages[random(sizeof(death_messages))],
	  to->query_cap_name() ) +
      "%^RESET%^"
    ;
  }
  else if (myrace == "archangel" && hisrace != "demon" &&
    to->query_alignment() > random(6000)) {
      perc = 65;
      deathroom = ROOM_DEATH_ANGEL;
      nocorpse = 1;
      mymsg =
	"%^YELLOW%^Your body is engulfed in a bright light and "
	"skyrockets into the heavens.%^RESET%^"
      ;
      roommsg =
	"%^YELLOW%^"+to->query_cap_name()+"'s body is engulfed in a bright light "
	"and skyrockets into the heavens.%^RESET%^"
      ;
      allmsg =
	"%^BOLD%^%^WHITE%^A hushed silence fills the realms at the "
	"loss of "+to->query_cap_name()+".%^RESET%^"
      ;
      to->set_paralyzed(30+random(30),
	"Your body is recovering from severe shock."
      );
  }
  else if (myrace == "demon" && hisrace != "archangel" &&
    (to->query_alignment() * -1) > random(6500)) {
      perc = 55;
      deathroom = ROOM_DEATH_DEMON;
      nocorpse = 1;
      mymsg =
	"%^BOLD%^%^BLACK%^Your body is engulfed in deep shadow "
	"and vanishes into the Abyss.%^RESET%^"
      ;
      roommsg =
	"%^BOLD%^%^BLACK%^"+to->query_cap_name()+"'s body is engulfed in "
	"deep shadow and vanishes into the Abyss.%^RESET%^"
      ;
      allmsg =
	"%^MAGENTA%^An unearthly howl splits the air as "
	""+to->query_cap_name()+" vanishes into the Abyss.%^RESET%^"
      ;
      to->set_paralyzed(50+random(50),
	"Your body is recovering from severe shock."
      );
  }
  else {
    int x;
    string *d;
    if (!perc) perc = 100;
    x = sizeof( d = get_dir("/news/death/") );
    deathroom = ROOM_DEATH;
    mymsg =
      read_file("/news/death/"+d[random(x)])+"\n"
      "You die.\n"
      "You feel the sensations of nothingness as "
      "you rise above your corpse.\n"
    ;
    roommsg =
      to->query_cap_name()+" dies a horrible death."
    ;
    allmsg =
      "%^BOLD%^%^RED%^" +
      sprintf( death_messages[random(sizeof(death_messages))],
	  to->query_cap_name() ) +
      "%^RESET%^"
    ;
    to->set_ghost(1);
  }

  // do this here to make sure death messages aren't blocked by sleep
  to->set_rest_type(0);

  message("death", mymsg, to);
  message("death", roommsg, env, to);
  if (!member_group(to->query_name(), "usertest"))
    message("death", allmsg, users(), ({ env, to }) );

  // checks for pk
  if (atck) {
    if (userp(to) && userp(atck)) {

      if (to->query_recent_outlaw()) {
	to->set_recent_outlaw(0);
	message("info", "For killing this outlaw, you receive "+
	  (to->query_level()*2000)+" gold.", atck);
	atck->add_money("gold", to->query_level()*2000);
	pk = 0;
      }

      else if (conflict)
	pk = 0;

      else {
	switch(zone) {
	  case "nopk":
	  case "pk":
	  default:
	    pk = 1;
	    break;

	  case "freepk":
	    pk = 0;
	}
      }
    }
    else
      pk = 0;

    if (pk) {
      perc = perc * 60 / 100;
      atck->add_outlaw("pk", 1);
      atck->set_last_pk(to->query_name());
      atck->set_last_pk_time(time());

      area = explode(base_name(env), "/")[1];
      if (area == zone)
	area = explode(base_name(env), "/")[2];
      log_file("pk", atck->query_name()+" PKed "+to->query_name()+" on "+
	""+ctime(time())+" AREA="+area+"\n");
    }
  }

  // death penalties happen here
  penalties = apply_death_penalties(perc);

  // make_corpse cares about this
  if (nocorpse || to->query_undead())
    to->set_property("no corpse", 1);

  // make_corpse is in living.c
  //
  // TODO: figure out how to do this right... also called in living::die()
  penalties["inventory"] = to->make_corpse();

  to->set_hp(5);
  to->set_sp(5);
  to->set_mp(5);
  to->set_poisoned(0);
  to->set_bleeding(0);
  to->new_body();
  to->fix_vital_bonus(to->query_level());
  to->set_recent_outlaw(0);

  death = new(class Death);
  death->time = time();
  death->room = file_name(env);
  death->pk = pk;
  death->desc = desc;
  death->penalties = penalties;
  if (conflict)
    death->war = conflict[0] + ", " + conflict[1];
  if (atck)
    death->killer = remove_article(strip_color(atck->query_name()));
  add_recent_death(death);

  if (deathroom) {
    to->move(deathroom);
    to->describe_current_room(1);
  }

  to->save_player(to->query_name());
  PLAYER_D->add_player_info();
}

mapping apply_death_penalties(int perc) {
  object to = this_object();
  int level = to->query_level();
  int level_loss, exp_loss, skill_loss, stat_loss;
  int exp_total;
  mapping skills, stats;
  mapping losses = ([]);

  // -- calculate losses only -- //

  if (level <= 5) {
    level_loss = 0;
    // lose 0 - 20% of current exp
    exp_loss = to->query_exp() * ((level-1)*5) / 100;
    skill_loss = random(level+5);
    stat_loss = 0;
  }
  else if (level <= 10) {
    level_loss = 0;
    // lose 25 - 45% of current exp
    exp_loss = to->query_exp() * ((level-1)*5) / 100;
    skill_loss = 3+random(level-3);
    // lose 1 stat max, and only 1 in 5 chance
    stat_loss = !random(5);
  }
  else if (level <= 20) {
    level_loss = 0;
    // lose about 50 - 75% of current exp
    exp_loss = to->query_exp() * ((level-1)*26/10) / 100;
    skill_loss = 5 + level/4 + random(level/4);
    // 0 - 3, with 3 being very rare
    stat_loss = (1+random(21)) / 7;
  }

  else {
    switch (level) {
      case 1..20:   level_loss = 0; break; // should never hit this one
      case 21..35:  level_loss = 1; break;
      case 36..50:  level_loss = 2; break;
      case 51..70:  level_loss = 3; break;
      case 71..100: level_loss = 4; break;
      default:      level_loss = 5;
    }

    // lose exp equal to the amount needed for level_loss levels
    // so if your current level cost you 500,000 use that as base exp loss
    // regardless of how much exp you have currently
    // level loss will be increased as needed later
    for (int i = level; i > level - level_loss; i--) {
      int tmp = ADVANCE_D->query_level_cost(i);
      exp_total += tmp;
    }

    // just calculating - don't add query_exp() to this!
    exp_loss = exp_total - random(exp_total/7) + random(exp_total/7);
    skill_loss = 5 + level/4 + random(level/3);
    stat_loss = random(level/12 + 4);
  }

  // -- increase or decrease the loss by a percentage -- //

  // float math to avoid overflowing MAX_INT!!
  exp_loss = to_int(exp_loss * to_float(perc) / 100);
  skill_loss = skill_loss * perc / 100;
  stat_loss = stat_loss * perc / 100;


  // -- apply exp/level losses -- //

  while (exp_loss > 0 && exp_loss > to->query_exp()) {
    exp_loss -= to->query_exp();
    losses["exp"] += to->query_exp();

    // if we need to lose more exp than we have, lower our level by 1
    // and set our current exp to the cost for the previous level,
    // then continue removing exp
    // any levels that should not be able to be lost by dying should
    // have their exp loss calculated above as a percentage of current exp
    to->set_exp( ADVANCE_D->query_level_cost( to->query_level() ) );
    to->set_level( to->query_level() - 1 );
    losses["level"] += 1;
  }
  if (exp_loss) {
    to->add_exp(-exp_loss);
    losses["exp"] += exp_loss;
    exp_loss = 0;
  }

  if (to->query_level() < 20)
    to->setenv("TITLE", (string)ADVANCE_D->get_new_title(to));

  // this lowers skills to the max for the current level
  // doing this before losing skills == more skill loss
  to->fix_skills();


  // -- apply skill losses -- //

  skills = copy(to->query_skills());
  skills = filter(skills, (: $2["level"] > 5 :) );

  while (skill_loss > 0 && sizeof(skills) > 0) {
    string skill = keys(skills)[random(sizeof(skills))];
    int amt = random(5)+1;

    if (amt > skill_loss) amt = skill_loss;

    skill_loss -= amt;
    skills[skill]["level"] -= amt;
    skills[skill]["points"] = 0;

    if (!losses[skill]) losses[skill] = 0;
    losses[skill] += amt;

    // each loop, make sure there are no skills in the list that
    // are <= 5
    skills = filter(skills, (: $2["level"] > 5 :) );
  }

  // adding two mappings: right side of + sign overrides left side
  to->set_skills( to->query_skills() + skills);


  // -- apply stat losses -- //

  stats = copy(to->query_base_stats());
  stats = filter(stats, (: $2 > 1 :) );

  while (stat_loss > 0 && sizeof(stats)) {
    string stat = keys(stats)[random(sizeof(stats))];

    stat_loss -= 1;
    stats[stat] -= 1;

    if (!losses[stat]) losses[stat] = 0;
    losses[stat] += 1;

    stats = filter(stats, (: $2 > 1 :) );
  }

  to->set_base_stats(stats);


  return losses;
}

void add_recent_death(class Death d) {
  if (!RecentDeaths)
    RecentDeaths = ({ });
  RecentDeaths += ({ d });
  if (sizeof(RecentDeaths) > MAX_RECENT_DEATHS)
    RecentDeaths = RecentDeaths[<MAX_RECENT_DEATHS..<1];
}

class Death *query_recent_deaths() { return copy(RecentDeaths); }

