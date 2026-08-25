/* This is a testversion. I have to see if the spellfunctions is needed
   here at all..
   Seems likt it's not..
   Wonder about the command stuff....
   Commands is needed, but I think I'll change the names to remove
   the similarity to add_command for players..
   Usage now is: add_guild_command..
   Baldrick march '94..
*/

inherit "/std/object";
inherit "/std/basic/cute_look";
#include "skills.h"
#include "commands.h"
#include "tune.h"

/* Hrmf.. why is the spells mentioned here at all ??? I wonder if it may be
   out of date...
   Baldrick..
   */

string *guild_commands,main_skill;
string needed_align;
int heal_loop, level;

int query_dice();
void new_levels(int lvl, object ob);

void create() {
  guild_commands = ({ });
  ::create();
}
int query_channel() { return 1; }


string help() { return read_file("/doc/helpdir/guilds"); }

void set_needed_align(string bing)
  {
  needed_align = bing;
  return;
}

string query_needed_align() { return needed_align; }

int query_legal_race(string race) { return 1; }

int query_legal_weapon(string str) { return 1; }

int query_legal_armour(string str) { return 1; }

string query_spell_directory() { return 0; }

mixed query_legal_spheres() { return ({ }); }

int query_max_skill_level(string skill)
  {
  if((int)this_object()->query_level() * 3 < 300)
  return (int)this_object()->query_level() * 3;
  return 300;
}

int query_valid_melee_weapon(object ob) { return 1;} // Added 1 nov 93 Chrisy cuz sum1 4got it :)

int query_number_worn(string str) { return 1; } // Added 1 nov 93 Chrisy cuz sum1 4got it

string query_main_skill() {return main_skill;}
  
void set_main_skill(string str)
  {
  main_skill = str;
  return;
}

int add_guild_command(string name, int add_if_player) 
  {
  if (member_array(name, guild_commands) != -1)
    return 0;
  guild_commands += ({ name, ({ add_if_player }) });
  return 1;
}

/* Not sure why this is needed.. */
int remove_guild_command(string name) 
  {
  int i;
  if ((i = member_array(name, guild_commands)) == -1)
    return 0;
  guild_commands = delete(guild_commands, i, 1);
  return 1;
}

int do_command(string name, mixed param) 
  {
  mixed *tmp;

  if (member_array(name, guild_commands))
    return 0;
  tmp = (mixed *)COMMAND_SERVER->query_command(name);
  return (int)call_other(tmp[0], tmp[1], param);
}

string *query_guild_commands() { return guild_commands; }

int query_skill_cost(string skill) { return 0; }

/*  Simply how much money the guild will charge to train you  */
int query_advance_cost() { return DEFAULT_COST; }

/* Seems we won't use this one, but check *bits of skills instead */
int query_xp_cost() { return DEFAULT_XP_COST; }
int query_max_level() { return 300; }
int query_dice() { return 8; }

/*  Instead of the titles we've been using so far we might want to just
 * let the guild titles consist of <level> <guild>.  At least this will be
 * the standard.  If that's not acceptable, just mask this function.
 */
string query_title(object player) 
{
  return "the "+number_as_place(player->query_level())+" Level "+capitalize(query_short());
}

/*
 * cant think of anything I want to do here at the moment...
 * This is where you would set up any shadows you want on the player
 * object (for instance kits/specializations).  The only thing we'll
 * do here in the inheritable guild is to add known guild_commands and spells
 * for monsters (who'll more often have guild_commands and spells than a guild
 * who'll give it to them.
 */

void start_player(object pl) 
  {
  int i;

  level = (int)pl->query_level();
  if (!pointerp(guild_commands))
    guild_commands = ({ });
  for (i=0;i<sizeof(guild_commands);i+=2)
    if (guild_commands[i+1][0] || !interactive(pl))
      pl->add_known_command(guild_commands[i]);
}

/* Not something players should be able to do until we add dual class humans.
 * Up until then we leave the function open so that lords can call it
 * instead of set_guild_ob() which they often seem to bungle.
 * We will stop removing spells when dual class is implemented
 */
void leave_guild() 
  {
  "/global/spells"->reset_spells();
  }

/* What happens when you advance in level */
void new_levels(int lvl, object ob) 
{
int i,bonus,stat;
//int skill_index;
  level = lvl;

  if (!(lvl%5))
    {
    for (i=0;i<random(3)+1;i++)
      {
      bonus=random(5);
      if((ob->query_max_skill_level(main_skill) < (lvl +
         bonus)) && (ob->query_skill_level(main_skill) <
         (lvl*3)))
        ob->add_skill_level(main_skill,bonus);
      }
    write("You didn't earn any new skills as this bit ain't written yet.\n");
    }
  if (!(lvl%10))
    {
    if(random(100) < 25){
      stat=random(6);
      switch(stat){
      case 1 : 
        if(ob->query_str() < 19)
         ob->adjust_str(1);
         break;
         case 2:
           if(ob->query_int() <18)
             ob->adjust_int(1);
         break;
         case 3:
           if(ob->query_dex() < 18)
             ob->adjust_dex(1);
         break;
         case 4:
           if (ob->query_con() < 18)
             ob->adjust_con(1);
         break;
         case 5:
           if (ob->query_wis() < 18)
             ob->adjust_wis(1);
         break;
         case 6:
           if (ob->query_cha() <18)
             ob->adjust_cha(1);
           break;
         default :
         break;
         }
         }
         }
  ob->reset_all();
}

int query_level(object ob) {
  return level;
}

int query_dual_wield_penalty(object me, object w1, object w2)
{
  return 50;
}
