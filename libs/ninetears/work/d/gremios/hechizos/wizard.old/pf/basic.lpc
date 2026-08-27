/* My basic spell object for the wizards guild... */

/*
 * Spells.  How I will handle them and how many legs they have.
 * I would like to make the spell system based upon spell books
 * which the mages store at thier places in the unseen university
 * (Unless they are stupid of course :).  You have a certain amount
 * of power and you can remember the rituals for up to this amount
 * of power, otherwise the spells are too strong for you and take
 * over your mind (well a chance of this and a chance of just brain
 * damage and a few other thingys too :).  Of course you should be
 * warned that being a mage is dangerous thing to be.  This should all
 * be explained to you when you join the guild for the first time
 * and are taught your first rituals.
 *
 * The spells should be thought of as just that.  Rituals.  There should
 * be spell components for each one and the actuall casting should be
 * a short script like thing you run though.  In some cases the material
 * compents wil be consumed in others you just need them to be their.
 * Depending on your proficeny in the art depends on how quickly you
 * can preform the rituals.  Of course not wearing the proper wizard
 * garb can have a detrimental effect on the casting.  Basicly the
 * elements being controlled just arent impressed with a wizard that
 * doesnt have a hat.
 *
 * All components for spells will be checked for with a find_match and
 * dested or whatever as nessessary.
 */
#define ESCAPED_SPELL "/std/spells/wizard/escaped"

mixed *ritual;   /*
                  * An array of arrays of messages containg what we
                  * should say for each bit of the ritual.
                  */
string *consumables,
       *needed,
       skill_used,
       spell_type, /* This is the type used after casting...  */
       info,       /* Help message. */
       name;
int learn_lvl,
    teach_lvl,
    skill_threshold, /* At this skill bonus the time required is as
                      * specified etc */
    point_cost,   /* How many guild points it uses... */
    power_level,  /* This is the power of the spell.  How powerful it is... */
    duration,     /* Duration of the effects. */
    directed,     /* Directed at someone. */
    multiple,     /* Multiple targets?    */
    failure,      /* Wonderful failure rate. */
    fixed_time,   /* Fixed casting time. */
    casting_time; /* Time it takes to cast (remember there are 30 time
                   * points in one "round"/heart_beat). */

void create() {
  consumables = ({ });
  needed = ({ });
  ritual = ({ });
  this_object()->setup();
} /* create() */

void print_ritual_messages(int i, int j, object ob, object *obs);

int cast_spell(string str) {
  object *obs;
  int time, bonus, amt;

  if ((int)this_player()->query_spell_effect("spell")) {
    notify_fail("You are already casting a spell!\n");
    return 0;
  }
  if (directed) {
    sscanf(str, "at %s", str);
    sscanf(str, "on %s", str);
    if (!sizeof(obs = find_match(str, environment(this_player())))) {
      notify_fail("There is no "+str+" to cast "+name+" on.\n");
      return 0;
    }
    if (!multiple && sizeof(obs) > 1) {
      notify_fail("You cannot cast "+name+" on multiple targets.\n");
      return 0;
    }
    time = sizeof(obs)+sizeof(obs)-1;
  } else
    time = 1;
/* Modify the casting time according to the components. */
  if (!(time *= (int)this_object()->check_components())) {
/* Finds the components to make sure we have em... */
    notify_fail("You appear to be missing some of the materials needed "
                "to cast "+name+".\n");
    return 0;
  }
  bonus = (int)this_player()->query_skill(skill_used);
  if (bonus < skill_threshold) /* Ok...  need more time and guild points */
    time *= (skill_threshold - bonus)/30;
  if (this_player()->query_gp() < time*point_cost) {
    notify_fail("Not enough guild points to cast "+name+" requires "+
                (time*point_cost)+".\n");
    return 0;
  }
  this_player()->adjust_gp(-(time*point_cost));
  if (fixed_time)
    this_player()->adjust_time_left(-(amt = casting_time));
  else
    this_player()->adjust_time_left(-(amt = time*casting_time));
  this_player()->set_interupt_command("interupted_casting", this_object(),
                              ({ bonus, obs, 1 }) );
/* Add with basicly infinite duration.  Will remove ourselves. */
  this_player()->add_spell_effect(100, "spell", name, this_object(),
    "casting_heart_beat", ({ amt, obs }));
  this_player()->add_property("spell done", 0);
  print_ritual_messages(0, 0, this_player(), obs);
  return 1;
} /* cast_spell() */

string create_spell_mess(string str, object ob, object *obs) {
  string *mess, de;
  int j;

  mess = explode(str, "$");
  de = "";
  for (j=0;j<sizeof(mess);j++)
    switch (mess[j]) {
      case "tp_name" :
        de += (string)ob->query_cap_name();
        break;
      case "tp_poss" :
        de += (string)ob->query_possessive();
        break;
      case "tp_pro" :
        de += (string)ob->query_pronoun();
        break;
      case "ob_name" :
        de += query_multiple_short(obs);
        break;
      case "ob_poss" :
        if (sizeof(obs) == 1)
          de += "their";
        else
          de += (string)obs[1]->query_possessive();
        break;
      default :
        de += mess[j];
        break;
    }
  return de;
} /* create_spell_mess() */

void print_ritual_messages(int start, int end, object ob, object *obs) {
  mixed *mess;
  int i;

  if (end >= sizeof(ritual)) end = sizeof(ritual)-1;
  for (i=start;i<=end;i++) {
    mess = ritual[i][random(sizeof(ritual[i]))];
    write(create_spell_mess(mess[0], ob, obs));
    say(create_spell_mess(mess[1], ob, obs));
  }
} /* print_ritual_messages() */

void interupted_casting(int amt, mixed *args) {
  int bonus, casted, done;
  mixed *obs;

  done = (int)this_player()->query_property("spell done");
  this_player()->remove_property("spell done");
  if (amt > 0)
    this_player()->remove_spell_effect(name);
  else {
/*
 * ok!  We can now actually cast the spell.  Brilliant!  First check for
 * failure.
 */
    bonus = args[0];
    obs = args[1];
    casted = args[2];
/*
 * Ok...  Now failure.  There should ALWAYS be some chance of failing
 * (evil laugh).
 */
    this_player()->remove_spell_effect(name);
    if (!this_object()->consume_consumables()) /* Definate fail if you
                                                * lost some of the consumables..
      bonus = 0;                                */
    if (pointerp(obs))
      bonus = bonus / sizeof(obs);
/* Force the rest of the ritual messages to be printed */
    print_ritual_messages(done+1, sizeof(ritual)-1, this_player(), obs);
    if ((bonus >= failure && random(100) == 1) ||
        (bonus < failure && random(100) > bonus*100/failure)) {
/* We failed...  Wheee! :) */
      this_object()->do_spell_failure();
      return ;
    }
    bonus = args[0];
/* Other wise... we cast the spell. */
    this_player()->add_spell_effect(duration, spell_type, name, this_object(),
                                    "effect_heart_beat", ({ bonus, obs, 1 }));
    return ;
  }
} /* interupted_casting() */

void casting_heart_beat(object attacker, mixed *args, int no_rnds) {
  int i,
      done,
      end;

  i = (int)this_player()->query_time_left();
  done = (int)this_player()->query_property("spell done");
  end = ((args[0]+i)*sizeof(ritual))/args[0];
  print_ritual_messages(done+1, end,
                        this_player(), args[1]);
  this_player()->add_property("spell done", end);
} /* casting_heart_beat() */

/* Component handling code. */
int check_components() {
  int i;

  for (i=0;i<sizeof(consumables);i++)
    if (!sizeof(find_match(consumables[i], this_player())))
      return 0;
  for (i=0;i<sizeof(needed);i++)
    if (!sizeof(find_match(needed[i], this_player())))
      return 0;
  return 1;
} /* check_components() */

int consume_components() {
  int ret;
  object *obs;
  int i, j;

  ret = 1;
  for (i=0;i<sizeof(consumables);i++) {
    if (!sizeof(obs = find_match(consumables[i], this_player()))) {
      ret = 0;
      break;
    }
    for (j=0;j<sizeof(obs);j++)
      obs[j]->dest_me();
  }
  return ret;
} /* consume_components() */

int do_spell_failure() {
  return 0;
} /* do_spell_failure() */

/* The one that got away.... */
void create_lost_spell() {
  object sp;
  string *bits;

  sp = clone_object(ESCAPED_SPELL);
  bits = explode(name, " ");
  sp->set_name(bits[sizeof(bits)-1]);
  sp->add_adjective(bits[0..sizeof(bits)-2]);
  sp->long(
"A writhing mass of pure energy, it suddenly darts forward in small fast "
"moveing jumps.  You cannot make out a real form from the mass, it moves "
"around flows too much for you to be certain of much about it.  Except that "
"it looks unhappy.\n");
  sp->set_power(power_level); /* More powerful spells...  are nastier :) */
/* Spells do differnt things depending on type */
  sp->set_spell_type(spell_type);
  sp->set_short("pure energy");
  sp->add_alias("energy");
  sp->add_adjective("pure");
  sp->move(environment(this_player()));
} /* escaped_spell() */

/* all the (un)interesting set stuff */
string query_name() { return name; }
void set_name(string str) { name = str; }

int query_power_level() { return power_level; }
void set_power_level(int i) { (power_level = i); }

int query_duration() { return duration; }
void set_duration(int i) { duration = i; }

string query_info() { return info; }
void set_info(string str) { info = str; }

void set_ritual(mixed *rit) { ritual = rit; }
mixed *query_ritual() { return ritual; }

void set_consumables(string *str) { consumables = str; }
string *query_consumables() { return consumables; }

void set_needed(string *str) { needed = str; }
string *query_needed() { return needed; }

void set_skill_used(string str) { skill_used = str; }
string query_skill_used() { return skill_used; }

void set_spell_type(string str) { spell_type = str; }
string query_spell_type() { return spell_type; }

void set_learn_lvl(int lvl) { learn_lvl = lvl; }
int query_learn_lvl() { return learn_lvl; }

void set_teach_lvl(int lvl) { teach_lvl = lvl; }
int query_teach_lvl() { return teach_lvl; }

void set_skill_threshold(int thres) { skill_threshold = thres; }
int query_skill_threshold() { return skill_threshold; }

void set_point_cost(int co) { point_cost = co; }
int query_point_cost() { return point_cost; }

void set_directed(int dir) { directed = dir; }
int query_directed() { return directed; }

void set_multiple(int mul) { multiple = mul; }
int query_multiple() { return multiple; }

void set_failure(int fail) { failure = fail; }
int query_failure() { return failure; }
 
void set_casting_time(int tim) { casting_time = tim; }
int query_casting_time() { return casting_time; }

void set_fixed_time(int tim) { fixed_time = tim; }
int query_fixed_time() { return fixed_time; }
