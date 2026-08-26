/**
 * This is an effect that is added to all objects in a water room unless they
 * have a race object that returns non-zero to lives_in_water().  It handles
 * making them drown, drift with the current, float and sink, and also has two
 * functions to find the buoyancy and swimming difficulty for an object, which
 * may be used by other files.  The argument of this effect is an array of two
 * integers.  The first indicates if the effectee is passively drifting (when
 * it is 0), actively swimming (when it is 1), trying deperately to get to the
 * surface (when it is -1, which should only happen briefly as they panic), or
 * being moved by something else such as a current (when it is -2, which should
 * only happen briefly as they move through the exit). The default value for
 * this should be 1.  The second member of the argument array indicates what
 * stage of drowning they have progressed to.
 * @author Bakhtosh
 * @see /std/room/basic/water.c
 * @classification "body.immersed"
 */

#include <effect.h>
#include <tasks.h>

#define ANCHOR_PROP "anchor"
#define BUOYANT_PROP "buoyancy"
#define GILLS_PROP "gills"
#define FLOATING_PROP "floating"
#define TROLL_RACE "troll"
#define LIVES_IN_WATER_PROP "lives in water"
#define LUNGS_PROP "lung capacity"
#define STAMINA_SKILL "other.points"
#define SWIMMING_SKILL "other.movement.swimming"
#define WITCH_GUILD "/std/guilds/witch"

int calc_buoyancy(object);
int swim_difficulty(object);
void set_arg(object, int*);
void flee_drowning(object, int*);

/**
 * @ignore yes
 */
string query_classification() {
  return "body.immersed";
}

/**
 * @ignore yes
 */
int *beginning(object player, int swimming, int id) {
  if (living(player) && !(player->query_property(GILLS_PROP) &&
           player->query_property(LIVES_IN_WATER_PROP))) {
    player->submit_ee("drown", 15, EE_CONTINUOUS);
  }
  if (!player->query_property(LIVES_IN_WATER_PROP)) {
    player->submit_ee("drift", 1, EE_ONCE);
    player->submit_ee("drift", 20, EE_CONTINUOUS);
  }
  return ({swimming ? 1 : 0, 0});
}

/**
 * @ignore yes
 */
int *merge_effect(object player, int *old_arg, int swimming, int id) {
  if (swimming == 2) {
    old_arg[0] = 1;
  }
  player->submit_ee(0, -1, EE_REMOVE);
  return old_arg;
}

/**
 * @ignore yes
 */
void end(object player, int *arg, int id) {
  // Currently, nothing is done when this effect is removed.
}

/**
 * This function, submitted as a continuous event in the swimming/immersion
 * effect, advances the stage of drowning which the effectee has attained (if
 * they are underwater).  As it grows higher, they receive more urgent warning
 * messages and eventually suffer penalties including, but not limited to,
 * death.  Past a certain stage, they will automatically attempt to flee.
 * @see flee_drowning
 */
void drown(object player, int *arg, int id) {
  int damage, gp_left, extra_drown, fleed = 0, drown_stage = arg[1];
  object new_env, env = environment(player);
  if (!env || !env->query_water()) {
    player->submit_ee(0, 1, EE_REMOVE);
    set_arg(player, ({arg[0], 0}));
    return;
  }
  // The dead or the netdead cannot drown.
  if (player->query_property("dead") ||
      (userp(player) && !interactive(player))) {
    return;
  }
  if (player->query_property(GILLS_PROP) ||
           load_object(player->query_race_ob())->lives_in_water()) {
    set_arg(player, ({arg[0], 0}));
    return;
  }
  if (env->query_surface()) {
    if (drown_stage < 1) {
      return;
    }
    set_arg(player, ({arg[0], 0}));
    tell_object(player, "You take a deep breath of air.\n");
    return;
  }
  // If they're just floating, they don't drown as fast.
  if (arg[0]) {
    extra_drown = 75000;
  }
  else {
    extra_drown = 50000;
  }
  extra_drown /= 1000 + player->query_skill_bonus(SWIMMING_SKILL) +
           player->query_skill_bonus(STAMINA_SKILL);
  // A living creature may be given the "lung capacity" property to represent
  // a percentage of normal human lung capacity, in order to alter the rate at
  // which they drown.  For example, a "lung capacity" property of 50 will make
  // them drown twice as fast, which a property of 300 will allow them to last
  // three times as long underwater.
  if (player->query_property(LUNGS_PROP)) {
    extra_drown *= 100;
    extra_drown /= player->query_property(LUNGS_PROP);
  }
  drown_stage += extra_drown;
  set_arg(player, ({arg[0], drown_stage}));
  if (drown_stage < 120) {
    return;
  }
  switch (drown_stage) {
  case 120..149:
    tell_object(player, "Your lungs feel a bit heavy.\n");
    if (!sizeof(player->query_hide_invis())) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ a bit "
           "uncomfortable.\n", player);
    }
    return;
  case 150..179:
    tell_object(player, "Your lungs feel quite heavy.\n");
    if (!sizeof(player->query_hide_invis())) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ somewhat "
           "uncomfortable.\n", player);
    }
    return;
  case 180..239:
    tell_object(player, "Your lungs feel very heavy.\n");
    if (!sizeof(player->query_hide_invis())) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ quite "
           "uncomfortable.\n", player);
    }
    return;
  case 240..299:
    tell_object(player, "Your lungs feel close to bursting.\n");
    if (!sizeof(player->query_hide_invis())) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ slightly "
           "blue.\n", player);
    }
    return;
  case 300..359:
    tell_object(player, "You feel a burning sensation in your lungs.\n");
    if (!sizeof(player->query_hide_invis())) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ quite "
           "blue.\n", player);
    }
    return;
  case 360..479:
    // From now on, they may try to save themselves automatically, depending on
    // their wimpy.  Npcs flee automatically once they risk losing hp.
    if (player->query_wimpy() >= 100) {
      flee_drowning(player, arg);
      new_env = environment(player);
      if (new_env->query_surface() || !new_env->query_water()) {
        return;
      }
      fleed = 1;
    }
    // If they were fully rested before going in (represented by having gp),
    // their gp can shield them from some of the damage in this stage.
    damage = drown_stage - 300;
    // Leave them with a minimum of 50 other guildpoints so that they can try
    // to swim up.
    gp_left = player->query_specific_gp("other") - 50;
    if (gp_left > 0) {
      if (gp_left >= damage) {
        tell_object(player, "Your lungs feel as though they are on fire.\n");
        player->adjust_gp(-damage);
        tell_room(env, "$C$"+player->one_short()+" $V$0=looks,look$V$ "
           "pained.\n", player);
        if (player->query_monitor()) {
          player->monitor_points();
        }
        return;
      }
      damage -= gp_left;
      player->adjust_gp(-gp_left);
    }
    damage *= 5;
    if (!fleed && (!userp(player) || 100*(player->query_hp() - damage) <
           player->query_max_hp()*player->query_wimpy())) {
      flee_drowning(player, arg);
      new_env = environment(player);
      if (new_env->query_surface() || !new_env->query_water()) {
        return;
      }
    }
    tell_object(player, "Agonising pain radiates from your lungs.\n");
    if (damage >= player->query_hp()) {
      player->attack_by(env);
    }
    player->adjust_hp(-damage);
    if (player->query_hp() > 0) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=thrashes,thrash$V$ "
           "about.\n", player);
    }
    if (player->query_monitor()) {
      player->monitor_points();
    }
    return;
  case 480..599:
    if (!userp(player) || player->query_wimpy() >= 100) {
      flee_drowning(player, arg);
      new_env = environment(player);
      if (new_env->query_surface() || !new_env->query_water()) {
        return;
      }
      fleed = 1;
    }
    // They're stubborn, or they're using something to boost their gp.  But
    // magical means can only go so far - their body needs real oxygen.
    gp_left = player->query_specific_gp("other") - 50;
    if (gp_left > 0) {
      player->adjust_gp(-gp_left);
    }
    damage = drown_stage - 300;
    damage *= 5;
    if (!fleed && 100*(player->query_hp() - damage) <
           player->query_max_hp()*player->query_wimpy()) {
      flee_drowning(player, arg);
      new_env = environment(player);
      if (new_env->query_surface() || !new_env->query_water()) {
        return;
      }
    }
    tell_object(player, "You feel everything going black.\n");
    if (damage >= player->query_hp()) {
      player->attack_by(env);
    }
    player->adjust_hp(-damage);
    if (player->query_hp() > 0) {
      tell_room(env, "$C$"+player->one_short()+" $V$0=thrashes,thrash$V$ "
           "weakly.\n", player);
    }
    if (player->query_monitor()) {
      player->monitor_points();
    }
    return;
  default:
    flee_drowning(player, arg);
    new_env = environment(player);
    if (new_env->query_surface() || !new_env->query_water()) {
      return;
    }
    tell_object(player, "You feel everything going black.\n");
    // Stop mucking about.  Just kill them.
    player->attack_by(env);
    player->do_death();
    return;
  }
}

/**
 * This function makes the subject try to flee to the surface.  The first
 * member of their effect argument array for the swimming/immersion effect is
 * set to -1 while they do so to give them a little extra chance.
 * @see drown
 * @see swim_exit
 */
void flee_drowning(object player, int *arg) {
  int which, *effnums, *new_arg;
  string up, *exits;
  object env = environment(player);
  up = env->query_up_dir();
  exits = env->query_dest_dir();
  if (member_array(up, exits) == -1) {
    which = random(sizeof(exits));
    which -= which%2;
    up = exits[which];
    tell_object(player, "You panic and try to flee "+up+".\n");
    tell_room(env, "$C$"+player->one_short()+" $V$0=panics,panic$V$ and "
           "$V$0=tries,try$V$ to flee "+up+".\n", player);
  }
  else {
    tell_object(player, "You panic and try to flee for the surface.\n");
    tell_room(env, "$C$"+player->one_short()+" $V$0=panics,panic$V$ and "
           "$V$0=tries,try$V$ to flee for the surface.\n", player);
  }
  set_arg(player, ({-1, arg[1]}));
  player->exit_command(up);
  effnums = player->effects_matching(query_classification());
  if (!effnums || !sizeof(effnums)) {
    return;
  }
  new_arg = player->arg_of(effnums[0]);
  if (new_arg[0] == -1) {
    set_arg(player, ({arg[0], new_arg[1]}));
  }
}

/**
 * This function, submitted as a continuous event in the swimming/immersion
 * effect, checks to see if the effectee will have any trouble staying in their
 * water room.  If they will, it performs a skillcheck to see if they are swept
 * away, and moves them if they fail.  It handles moving due to currents,
 * floating and sinking.
 * @see add_flow
 */
void drift(object player, int *args, int id) {
  int buoyancy, difficulty, traction, *effnums, *new_args;
  string up_dir, down_dir, move_dir, msgout, msgin, *exits, *tm_messes;
  object env = environment(player);
  mapping flows;
  mixed next;
  if (!env || !env->query_water()) {
    player->submit_ee(0, 1, EE_REMOVE);
    set_arg(player, ({args[0], 0}));
    return;
  }
  if (player->query_property("dead")) {
    return;
  }
  if (player->query_property(FLOATING_PROP) && env->query_surface()) {
    return;
  }
  flows = env->query_flows();
  up_dir = env->query_up_dir();
  down_dir = env->query_down_dir();
  buoyancy = calc_buoyancy(player);
  if (player->query_weight()) {
    buoyancy /= player->query_weight();
  }
  flows[up_dir] += buoyancy;
  flows[down_dir] -= buoyancy;
  if (env->query_bottom()) {
    // If it's sitting on the bottom it is less likely to be swept away.  Also,
    // it is in no danger of being swept downwards.
    traction = env->query_water_traction_bonus(player, buoyancy);
    flows = map(flows, (: $2 - $(traction) :));
    map_delete(flows, down_dir);
  }
  if (!args[0] || !living(player)) {
    exits = env->query_exits();
    flows = filter(flows, (: member_array($1, $(exits)) != -1 :));
    exits = sort_array(keys(flows),
           (: $(flows)[$1] > $(flows)[$2] ? -1 : 1 :));
    if (!sizeof(exits)) {
      return;
    }
    move_dir = exits[0];
    if (flows[move_dir] <= 0) {
      return;
    }
    if (!living(player) &&
           flows[move_dir] <= player->query_property(ANCHOR_PROP)) {
      tell_object(player, "You resist the "+move_dir+" current.\n");
      return;
    }
    exits = env->query_dest_dir();
    next = exits[member_array(move_dir, exits) + 1];
    next = load_object(next);
    if (!next) {
      return;
    }
    if (move_dir == up_dir && buoyancy > 0) {
      tell_object(player, "You float "+up_dir+".\n");
      msgout = env->query_float_out_mess();
      msgin = replace(next->query_float_in_mess(), "$F",
           env->query_origin(move_dir));
    }
    else if (move_dir == down_dir && buoyancy < 0) {
      tell_object(player, "You sink "+down_dir+".\n");
      msgout = env->query_sink_out_mess();
      msgin = replace(next->query_sink_in_mess(), "$F",
           env->query_origin(move_dir));
    }
    else {
      tell_object(player, "You drift "+move_dir+" with the current.\n");
      msgout = replace(env->query_sweep_out_mess(), ({"$T", move_dir}));
      msgin = replace(next->query_sweep_in_mess(), "$F",
           env->query_origin(move_dir));
    }
    if (!living(player)) {
      player->move(next, msgin, msgout);
      return;
    }
    env->add_exit_mess(player, msgout);
    env->add_enter_mess(player, msgin);
    set_arg(player, ({-2, args[1]}));
    player->exit_command(move_dir);
    effnums = player->effects_matching(query_classification());
    if (!effnums || !sizeof(effnums)) {
      return;
    }
    new_args = player->arg_of(effnums[0]);
    if (new_args[0] == -2) {
      set_arg(player, ({args[0], new_args[1]}));
    }
    return;
  }
  flows[up_dir] -= 50;
  flows[down_dir] -= 50;
  exits = env->query_exits();
  flows = filter(flows, (: member_array($1, $(exits)) != -1 :));
  exits = sort_array(keys(flows), (: $(flows)[$1] > $(flows)[$2] ? -1 : 1 :));
  if (!sizeof(exits)) {
    return;
  }
  move_dir = exits[0];
  if (flows[move_dir] <= 0) {
    return;
  }
  difficulty = flows[move_dir];
  difficulty *= swim_difficulty(player);
  difficulty /= 100;
  if (difficulty <= 0) {
    return;
  }
  switch (TASKER->perform_task(player, SWIMMING_SKILL, difficulty,
           TM_CONTINUOUS)) {
  case AWARD:
    tm_messes = ({"You discover an easier swimming technique.",
           "You manage to paddle where you are when you thought you'd be "
           "swept away."});
    tell_object(player, "%^YELLOW%^"+tm_messes[random(sizeof(tm_messes))]+
           "%^RESET%^\n");
  case SUCCEED:
    return;
  }
  exits = env->query_dest_dir();
  next = exits[member_array(move_dir, exits) + 1];
  next = load_object(next);
  if (!next) {
    return;
  }
  if (move_dir == up_dir && buoyancy > 50) {
    tell_object(player, "Despite your best efforts, your buoyancy drags you "
           +up_dir+".\n");
    msgout = env->query_float_out_mess();
    msgin = replace(next->query_float_in_mess(), "$F",
           env->query_origin(move_dir));
  }
  else if (move_dir == down_dir && buoyancy < -50) {
    tell_object(player, "Despite your best efforts, your weight drags you "
           +down_dir+".\n");
    msgout = env->query_sink_out_mess();
    msgin = replace(next->query_sink_in_mess(), "$F",
           env->query_origin(move_dir));
  }
  else {
    tell_object(player, "Despite your best efforts, the current drags you "
           +move_dir+".\n");
    msgout = replace(env->query_sweep_out_mess(), "$T", move_dir);
    msgin = replace(next->query_sweep_in_mess(), "$F",
           env->query_origin(move_dir));
  }
  env->add_exit_mess(player, msgout);
  env->add_enter_mess(player, msgin);
  set_arg(player, ({-2, args[1]}));
  player->exit_command(move_dir);
  effnums = player->effects_matching(query_classification());
  if (!effnums || !sizeof(effnums)) {
    return;
  }
  new_args = player->arg_of(effnums[0]);
  if (new_args[0] == -2) {
    set_arg(player, ({args[0], new_args[1]}));
  }
}

/**
 * @ignore yes
 */
void set_arg(object player, int *arg) {
  int *effects = player->effects_matching(query_classification());
  if (!effects || !sizeof(effects)) {
    return;
  }
  player->set_arg_of(effects[0], arg);
}

/**
 * This function calculates the total buoyancy of the specified object.  It is
 * an absolute value for the buoyancy force acting on them, so it should be
 * divided by their complete weight to find the relative buoyancy.  It is
 * adjusted according to their race (trolls are denser), guild (witches float),
 * the salinity of the water (brine is denser), their buoyancy property and the
 * amount that they are carrying.
 * @param player the object for which the buoyancy should be found
 * @return the buoyancy force acting on the object
 * @see query_complete_weight
 */
int calc_buoyancy(object player) {
  int weight, buoyancy, personal, baggage;
  if (!player) {
    return 0;
  }
  if (!living(player)) {
    weight = player->query_complete_weight();
    buoyancy = player->query_property(BUOYANT_PROP);
    if (weight == 0) {
      return 1000*buoyancy - 1;
    }
    return 1000*buoyancy - 500*weight;
  }
  if (player->query_property("dead")) {
    return 0;
  }
  personal = 10;
  if (player->query_race() == TROLL_RACE) {
    personal -= 2000;
  }
  if (player->query_guild_ob() == WITCH_GUILD) {
    personal += to_int(20.0*sqrt(to_float(player->query_level())));
  }
  if (environment(player)) {
    personal += environment(player)->query_salinity()/2;
  }
  weight = player->query_weight();
  buoyancy = player->query_property(BUOYANT_PROP);
  baggage = player->query_loc_weight();
  return 1000*buoyancy + personal*weight - 500*baggage;
}

/**
 * This function is used to adjust the difficulty of any attempt at swimming by
 * a living object.  It returns an integer greater than or equal to 100.  The
 * difficulty of any skillcheck involves their swimming skill should be
 * multiplied by this value and then divided by 100.  This handles adjustments
 * to account for burdening and held or worn items.
 * @param player the object to take the skillcheck
 * @return the adjustment factor for the difficulty of the skillcheck
 * @see perform_task
 */
int swim_difficulty(object player) {
  int handiness, difficulty;
  object *tmp;
  
  if (!player || !living(player)) {
    return 0;
  }
  if (player->query_property("dead")) {
    return 0;
  }
  // Give them a base value for being able to move their body.
  handiness = 20;
  // Give them a bonus for having feet, reduced according to the weight of any
  // boots they're wearing.
  tmp = player->query_wearing();
  if (tmp && sizeof(tmp)) {
    tmp = filter(uniq_array(tmp),
           (: member_array($1->query_type(), ({"shoe", "boot", "chausse",
           "overshoe"})) != -1 :));
  }
  if (!sizeof(tmp)) {
    handiness += 40;
  } else {
    handiness += 600/(15 + implode(map(tmp, (: $1->query_weight() :)),
           (: $1 + $2 :)));
  }
  // Give them a bonus for each arm with something in it, depending on the
  // weight of the item they're holding.  Yes, this setup will penalise them a
  // bit extra for holding something two-handed.
  tmp = player->query_holding();
  if(tmp) {
    tmp = filter(tmp, (: $1 :));
    if(tmp)
      handiness += implode(map(uniq_array(tmp),
                               (: 180/(10+$1->query_weight()) :)),
                           (: $1 + $2 :));
  }
  // Give them a bonus for any free limbs, better than they could get with
  // something in their hand...
  handiness += 20*player->query_free_limbs();
  // Don't let them get past the maximum value for an unencumbered human.
  if (handiness > 100) {
    handiness = 100;
  }
  difficulty = 10000/handiness;
  difficulty *= 200 + player->query_burden();
  difficulty /= 200;
  return difficulty;
}

/**
 * @ignore yes
 */
int survive_death() {
  return 1;
}
