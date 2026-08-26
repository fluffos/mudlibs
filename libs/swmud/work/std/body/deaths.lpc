#include <daemons.h>

int query_max_health();
int query_experience();
void set_experience(int value);
void set_primary_level(int value);
int query_primary_level();
string query_primary_guild();
string query_name();
string query_race();
void receive_private_msg(string message);
void refresh_stats();

int deaths;
int pk_deaths;
int last_pk_death;
mapping killed_by = ([ ]);
mapping killed_where = ([ ]);

void save_me();

protected void add_a_death()
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("add a death to " + this_object()->short(), previous_object(-1)); }

   deaths++;
   save_me();
}

protected void death_penalty()
{
   int experience = query_experience();
   int new_exp = experience;
   int level = query_primary_level();
   object killer = previous_object();
   string killed_message = "";

   if (killer && killer->is_body() && (killer != this_object()) && (environment(killer) != this_object()))
   {
      int killer_level = killer->query_primary_level();
      string killer_message = "You have killed " + query_name() + ", who is ";
      killed_message += "You were killed by " + killer->query_name() + ", who is ";
      last_pk_death = time();
      pk_deaths++;

      if (killer_level > level)
      {
         int percent_lost = 50 - ((killer_level - level) * 5);
         int required_experience;

         killed_message += (killer_level - level) + " levels higher than you.\n";
         killer_message += (killer_level - level) + " levels lower than you.\n";

         if (query_race() != "ithorian")
         {
            if (percent_lost < 1) { percent_lost = 1; }

            new_exp = floor(experience * ((100.0 - percent_lost) / 100.0));

            if (query_primary_guild() == "jedi")
            {
               if (level < 20)
               {
                  required_experience = EXP_D->get_required_exp("ronin jedi", level + 1);
               }
               else
               {
                  required_experience = EXP_D->get_required_exp("secondary", level + 1);
               }
            }
            else
            {
               required_experience = EXP_D->get_required_exp("primary", level + 1);
            }

            if ((experience >= floor(required_experience * 0.5))
               && (new_exp < floor(required_experience * 0.5)))
            {
               new_exp = floor(required_experience * 0.5);
            }
            else if (experience < floor(required_experience * 0.5))
            {
               new_exp = experience;
            }

            killer->add_experience(experience - new_exp);
         }
         else if (this_object()->is_unjustified_ithorian_target(killer))
         {
            new_exp = 0;
            killer->add_experience(experience);
         }
      }
      else if (killer_level < level)
      {
         int percent_lost = 50 + ((level - killer_level) * 5);

         killed_message += (level - killer_level) + " levels lower than you.\n";
         killer_message += (level - killer_level) + " levels higher than you.\n";

         if (query_race() != "ithorian")
         {
            if (percent_lost > 50) { percent_lost = 50; }

            new_exp = floor(experience * ((100.0 - percent_lost) / 100.0));

            if (level < 50)
            {
               int required_experience;

               if (query_primary_guild() == "jedi")
               {
                  if (level < 20)
                  {
                     required_experience = EXP_D->get_required_exp("ronin jedi", level + 1);
                  }
                  else
                  {
                     required_experience = EXP_D->get_required_exp("secondary", level + 1);
                  }
               }
               else
               {
                  required_experience = EXP_D->get_required_exp("primary", level + 1);
               }

               if ((experience >= floor(required_experience * 0.5))
                  && (new_exp < floor(required_experience * 0.5)))
               {
                  new_exp = floor(required_experience * 0.5);
               }
               else if (experience < floor(required_experience * 0.5))
               {
                  new_exp = experience;
               }
            }

            killer->add_experience(experience - new_exp);
         }
         else if (this_object()->is_unjustified_ithorian_target(killer))
         {
            new_exp = 0;
            killer->add_experience(experience);
         }
      }
      else
      {
         killed_message += "equal in level.\n";
         killer_message += "equal in level.\n";

         if (query_race() != "ithorian")
         {
            new_exp = experience / 2;

            if (level < 50)
            {
               int required_experience;

               if (query_primary_guild() == "jedi")
               {
                  if (level < 20)
                  {
                     required_experience = EXP_D->get_required_exp("ronin jedi", level + 1);
                  }
                  else
                  {
                     required_experience = EXP_D->get_required_exp("secondary", level + 1);
                  }
               }
               else
               {
                  required_experience = EXP_D->get_required_exp("primary", level + 1);
               }

               if ((experience >= floor(required_experience * 0.5))
                  && (new_exp < floor(required_experience * 0.5)))
               {
                  new_exp = floor(required_experience * 0.5);
               }
               else if (experience < floor(required_experience * 0.5))
               {
                  new_exp = experience;
               }
            }

            killer->add_experience(experience - new_exp);
         }
         else if (this_object()->is_unjustified_ithorian_target(killer))
         {
            new_exp = 0;
            killer->add_experience(experience);
         }
      }

      killer_message += "You have gained " + (experience - new_exp) + " experience points.\n\n";
      tell(killer, killer_message);
   }
   else if (killer && (killer != this_object()) && (environment(killer) != this_object()))
   {
      killed_message += "You were killed by " + killer->in_room_desc() + ".\n";

      foreach (object thing in deep_inventory(this_object()))
      {
         if (thing->query_durability() > 1)
         {
            thing->decrease_durability(thing->query_durability_points());
         }
      }

      killed_message += "The durability of your items has been decreased.\n";
   }

   if (new_exp != experience)
   {
      set_experience(new_exp);

      killed_message += "You had " + experience + " experience points and are left with " + new_exp + ", losing " + (experience - new_exp) + ".\n\n";
   }

   receive_private_msg(killed_message);

   if (level > 1)
   {
      load_object("/d/buffs/bacta_immersion");
      this_object()->add_buff(new("/d/buffs/bacta_immersion", 10 + (level * 2)));

      load_object("/std/effect/bacta_immersion");
      new("/std/effect/bacta_immersion", 10 + (level * 2), level * 60)->move(this_object());
   }
}

int query_deaths()
{
   return deaths;
}

void set_deaths(int new_deaths)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s deaths to " + new_deaths, previous_object(-1)); }

   if (new_deaths >= 1)
   {
      deaths = new_deaths;
      save_me();
   }
}

int query_pk_deaths()
{
   return pk_deaths;
}

void set_pk_deaths(int new_pk_deaths)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s pk deaths to " + new_pk_deaths, previous_object(-1)); }

   if (new_pk_deaths >= 1)
   {
      pk_deaths = new_pk_deaths;
      save_me();
   }
}

void set_last_pk_death(int time)
{
   last_pk_death = time;
}

int query_last_pk_death()
{
   return last_pk_death;
}

void reset_deaths()
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("reset " + this_object()->short() + "'s deaths", previous_object(-1)); }

   deaths = 0;
   pk_deaths = 0;
   save_me();
}

mapping query_killed_by()
{
   return killed_by;
}

mapping query_killed_where()
{
   return killed_where;
}

void set_killed_by(int time, string name, string where)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + " killed by " + name + " at " + where + " on " + ctime(time), previous_object(-1)); }

   killed_by[time] = name;
   killed_where[time] = where;
}

void reset_killed_by()
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("reset " + this_object()->short() + "'s killed by info", previous_object(-1)); }

   killed_by = ([ ]);
   killed_where = ([ ]);
}