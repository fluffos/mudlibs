/* do we use this one ? */
/* it's just a version of guild.c */


inherit "/std/room";

#include "skills.h"
#include "tune.h"
#include "money.h"

string our_guild,
       guild_path,
       *spec;
mixed *spells,
      *memspells,
      *commands;
object teaching_person;

void check_spells_commands(string *sk, int lvl);
int query_specialization(string name);

void create() {
  spells = ({ });
  spec = ({ });
  memspells = ({ });
  commands = ({ });
  ::create();
} /* create() */

void init() {
  ::init();
  add_action("do_advance", "advance");
  add_action("do_join", "join");
  add_action("do_info", "info");
  add_action("do_cost", "cost");
  add_action("do_specialize", "specialize");
} /* init() */

void set_guild(string str) { our_guild = "/std/guilds/"+str; } 

int do_advance() 
{
  string skill;
  string *bits;
  int cost, i, xp, lvl, total_xp, p_val;
  string guild;

  lvl = (int)this_player()->query_level();
  guild=this_player()->query_guild_ob();

  if (!guild)             /* Have we joined any guild at all ? */
  {
    notify_fail("If you 'join' you can advance here.\n");
    return 0;
  }

/***** Remember to add path for specializing!!!! *******/
  /* If so, is it this_guild ? */
  if (guild != our_guild && !query_specialization(guild))
  {
    write(guild+" = guild  AND "+our_guild+" = our_guild.\n");
    notify_fail("You cannot advance here! Go to your own guild.\n");
    return 0;
  }

/* The following bit is removed awaiting code from Dan.  He'll produce code
 * to compute the actual computing of raising in skill-levels.  I've declared
 * string *bits; for dividing up the skill-bits, but can do no more since I
 * honestly don't know how it'll work.
 * 7.1.93: Put back so that we can test other things while waiting.  
 */
  xp = (int)this_player()->query_xp_cost();  /* How much xp/lvl it will cost */
  if((int)this_player()->query_xp() < xp*(lvl+1)) 
  {
      notify_fail("Your lack of experience prevents you from advancing.\n");
      return 0;
  }

/* Checks for racial max levels not yet implemented   *************
  max_lvl = (int)my_race_ob->query_max_level(guild);
  if (lvl == max_lvl) 
  {
    notify_fail("You can advance higher than "+lvl+" because you're a "+
                 my_race+".\n");
    return 0;
  }
*/

/*  Monetary payment to advance in level   */
  cost = (int)our_guild->query_advance_cost();
    /* Default cost if not defined.  Thought 500 GP/level was OK  */
  cost *= lvl;           /* Total monetary cost of advancing */
 
  p_val = (int)this_player()->query_value(); /* How much money do we have */

  if (cost > p_val)  /* What happens if we can't pay */ 
  {
     notify_fail("Due to your sad lack of money the guild refuses to train "
                 "you.  It would have cost you "+
                 MONEY_HAND->money_value_string(cost)+".\n");
     return 0;
  }
  this_player()->pay_money(MONEY_HAND->create_money_array(cost));
  this_player()->set_level(++lvl);
  this_player()->reset_all();
/*  event(this_object(), "guild_advance", bits, lvl, lvl+1); */
  this_player()->reset_all();
  write("You advance to level "+lvl+" for "+ 
        MONEY_HAND->money_value_string(cost)+".\n");
  say(this_player()->query_cap_name()+" advances "+
      this_player()->query_possessive()+" level.\n");
  return 1;
} /* do_advance() */

/*  Some of the code I planned to use for proficiencies.  Just left some of 
 * it here in case it's of any use to Dank
 */  
int train(string str) 
{
  string skill_name, sk, guild;
  int cost, lvl;

  if (!(skill_name = (string)SKILL_OB->query_skill(sk))) 
  {
    notify_fail("I am sorry but the " + sk + " skill does not exist.\n");
    return 0;
  }
  if ((guild=(string)this_player()->query_guild_ob()) != our_guild && guild) 
  {
    notify_fail("You cannot train here! Go to your own guild.\n");
    return 0;
  }
  if(!str) 
  {
    notify_fail("Syntax: train <skill>.\n");
    return 0;
  }
  if(!guild)
    cost = DEFAULT_COST; /* Cheaper training in skill for members. */
  else
    cost = (int)our_guild->query_skill_cost(skill_name);
  cost *= (int)SKILL_OB->query_skill_cost(skill_name);
} /* Will be used for proficiencies */

int do_join(string str) 
{
  string guild;
  string race;
  guild = (string)this_player()->query_guild_ob();
  race  = (string)this_player()->query_race();

  if(guild == our_guild) 
  {
    notify_fail("You're already in this guild.\n");
    return 0;
  }

  if(guild) 
  {
    notify_fail("You cannot join a guild while a member of another.\n");
    return 0;
  }

  if(!our_guild->query_legal_race(race))
  {
    notify_fail("Sorry, but a "+race+" can't become a "+
     our_guild->query_name()+".\n");
    return 0;
  }

  write("You will only ever get to join one guild.  Are you sure? ");
  input_to("join2");
  return 1;
} /* do_join() */

/*  Not quite finished converting this.  Waiting for Dank's skills system */
int join2(string str) {
  mixed skills;
  int i;

  str = lower_case(str);
  if (str[0] != 'n' && str[0] != 'y') {
    write("I do not understand.  Yes or no? ");
    input_to("join2");
    return 1;
  }
  if (str[0] == 'n') {
    write("Ok, not joining the "+ our_guild->query_name()+" guild.\n");
    return 1;
  }
  this_player()->set_guild_ob(our_guild);
  this_player()->race_guild_commands();
write("You are now a member of the "+our_guild->query_cap_name()+"'s guild.\n");
  say(this_player()->query_cap_name()+" joins the "+our_guild->query_name()+
          " guild.\n");
  event(this_object(), "guild_join");
  event(users(), "inform", this_player()->query_cap_name()+" is now a member "
            "of "+our_guild->query_name(), "join");

  skills = (mixed *)this_player()->query_skills();
  for (i=0;i<sizeof(skills);i+=SKILL_ARR_SIZE) {
/* This will only set up the outer skill-bits (str, dec, con etc.) */
    check_spells_commands(skills[i+SKILL_NAM..i+SKILL_NAM],
                          skills[i+SKILL_LVL]);
  }
  this_player()->set_level(1);
  return 1;
} /* join2() */

/* This is not supposed to be possible until we allow for dual-classes.
 * I moved the leave code here since I felt you should have to be in the 
 * room of your guild when you leave.  It's easily moved back to the guild-
 * object if most of you prefer it that way.  
 */
int do_leave(string str) 
{
  if(str != "guild") {
    notify_fail("Syntax : leave guild\n");
    return 0;
  }
  if ((string)this_player()->query_guild_ob() != our_guild) {
    notify_fail("How can you leave a guild if you aren't in it.\n");
    return 0;
  }
  if ((int)this_player()->query_level() > 5) {
    notify_fail("You are too high a level to leave this guild.\n");
    return 0;
  }
  write("Are you sure you want to leave the guild (Y/N) : ");
  input_to("confirm_leave");
  return 1;
} /* do_leave() */

void confirm_leave(string str) {
  str = lower_case(str);
  if(str != "y") {
    write("You are still in the guild.\n");
    return;
  }
  write("You left your guild.\n");
  call_other(our_guild, "leaving_guild");
  this_player()->set_guild_ob(0);
  this_player()->set_guild_data(0);
  this_player()->guild_commands();
  this_player()->save_me();
} /* confirm_leave() */

/*  Will have to be rewritten a lot if we choose tell players how much xp 
 * they'll need to advance in each skill/subskill
 */
int do_cost() 
{
  string guild, cost;
  int xp_cost, lvl;

  guild = (string)this_player()->query_guild_ob();
  xp_cost = (int)our_guild->query_xp_cost();
  cost = MONEY_HAND->money_value_string((int)our_guild->query_advance_cost());
  lvl = this_player()->query_level();

  if(!guild)
  {
    notify_fail("If you join this guild you will have to earn "+
     xp_cost+" XP, and expect to pay "+cost+" to reach 2nd level.\n");
    return 0;
  }
    
  if (guild != our_guild) 
  {
    notify_fail("You are not a member of this guild.\n");
    return 0;
  }

/* Checks for racial max levels not yet implemented   *************
  max_lvl = (int)my_race_ob->query_max_level(guild);
  if (lvl == max_lvl)
  {
    notify_fail("You can advance higher than "+lvl+" because you're a "+
                 my_race+".\n");
    return 0;
  }
*/

  write("You will need "+xp_cost*lvl+" XP and "+cost+
        " to advance to level "+(lvl+1)+".\n");
  return 1;
} /* do_cost() */

/* The same goes for do_info() as for do_cost() of course */
int do_info() 
{
  write(our_guild->long());
  do_cost();
  return 1;
} /* do_info() */

/*
 * From here on are the changes to make level gaining hopefully more
 * realistic...  (Note the more :)
 */
void add_spell(string name, string *path, int lvl) {
  spells += ({ name, path, lvl });
} /* add_spell() */

void add_command(string name, string *path, int lvl) {
  commands += ({ name, path, lvl });
} /* add_command() */

int query_specialization(string name)
{ 
  if(member_array(name,spec) != -1)
    return 1;
  return 0;
}

void add_specialization(string name) 
{ 
    spec += ({ name });
}  /* add_specialization() */

int do_specialize(string name)
{
  string path;
  if((string)this_player()->query_guild_ob() != our_guild) 
  {
    notify_fail("You can't specialize in this guild since you're not a "
                "member.\n");
    return 0;
  }

  if((int)this_player()->query_level() != 1)
  {
    notify_fail("You can't specialize after you've already advanced in "
                "level.\n");
    return 0;
  }

  if (query_specialization(name))
  {
    path = "/std/race"->query_guild_path(name);
    tell_room(this_player(), this_player()->query_cap_name()+" specialices "
      "and becomes a "+name+".\n", this_player());
    write("You're accepted as a "+name+" specialist.  CONGRATULATIONS!!!\n");
    this_player()->set_guild_ob(path); 
    return 1;
  }
  notify_fail("That's not a valid specialization.\n");
  return 0;
}  /* do_specialize() */

void set_teaching_person(object ob) { teaching_person = ob; }
object query_teaching_person() { return teaching_person; }

void check_spells_commands(string *path, int lvl) {
  int i, j;

  if (!teaching_person || member_array(this_player(), 
      (object *)teaching_person->query_attacker_list()) != -1)
    return ;

  for (i=0;i<sizeof(spells);i+=3)
    for (j=0;j<sizeof(spells[i+1]);j++)
      if (j >= sizeof(path)) {  /* got through the skill path ok */
        if (spells[i+2] <= lvl)
           teaching_person->init_command("teach "+spells[i]+" to "+
                                         this_player()->query_name());
      } else
        if (spells[i+1][j] != path[j])
          break;

  for (i=0;i<sizeof(commands);i+=3)
    for (j=0;j<sizeof(commands[i+1]);j++)
      if (j >= sizeof(path)) {  /* got through the skill path ok */
        if (commands[i+2] <= lvl)
           teaching_person->init_command("teach "+commands[i]+" to "+
                                         this_player()->query_name());
      } else
        if (commands[i+1][j] != path[j])
          break;
} /* check_spell_commands() */

mixed * query_spells() { return spells + ({ }); }
mixed * query_commands() { return commands + ({ }); }

/* This is not pretty, but I added it in case Dank feel like giving the players
 * some info of how much xp it will cost to advance in skills.
 */
string rec_cost_old(mixed *arr, string path, int depth) {
  int i;
  int cost;
  string str, lpath;

  str = "";
  for (i=0;i<sizeof(arr);i+=SKILL_ARR_SIZE) {
    lpath = path + "." + arr[i];
    cost = (int)SKILL_OB->query_skill_cost((lpath)[1..500]);
    cost *= (int)our_guild->query_skill_cost((lpath)[1..500]);
    str += sprintf("%*'| 's%-*'.'s costs %d xp.\n", (depth-1)*2, "",
             20-(depth-1)*2, arr[i],
             cost*STD_COST*(((int)this_player()->query_skill(lpath)
                  /LEVEL_DIV)+1));
    if (this_player()->query_skill(lpath) >= depth*5)
      str += rec_cost_old(arr[i+SKILL_BIT], path+"."+arr[i], depth+1);
  }
  return str;
} /* rec_cost_old() */

string rec_cost(mixed *arr, string path, int depth, string g_o)
{ /* use lots of variables...so we only work things out minimum times */
  int i, depth_gap, ndots;
  int cost, lvl, max_lvl;
  string str, lpath;

  str = "";
  depth_gap = (depth - 1) * 2;
  ndots = 18 - depth_gap;

  for (i=0;i<sizeof(arr);i+=SKILL_ARR_SIZE) {
    if (path != "")
      lpath = path + "." + arr[i];
    else
      lpath = arr[i];
    lvl = (int)this_player()->query_skill(lpath);
    if (!g_o)
      max_lvl = 5;
    else
      max_lvl = (int)g_o->query_skill_max_level(lpath);
    if(lvl >= max_lvl) {
      str += sprintf("%*'| 's%-*'.'s %3d/%3d  mastered\n", depth_gap, "",
                     ndots, arr[i], lvl, max_lvl);
    } else {
      if (!g_o)
        cost = DEFAULT_COST;
      else
        cost = (int)g_o->query_skill_cost(lpath);
      cost *=  (int)SKILL_OB->query_skill_cost(lpath);
      cost *= (STD_COST/5)*((lvl/LEVEL_DIV)+1);
      str += sprintf("%*'| 's%-*'.'s %3d/%3d %6d xp\n", depth_gap, "",
               ndots, arr[i], lvl, max_lvl, cost);
    }
    if (lvl >= depth*5)
      str += rec_cost(arr[i+SKILL_BIT], lpath, depth+1, g_o);
  }
  return str;
} /* rec_cost() */

