/*
** Tsath, 2020
**
** Guild member include for ADVERSARY
**
*/

inherit M_ACTIONS;

string *member_of = ({});
mapping guild_cmds = ([]);
int special_percent_chance = 10;

void understand_cmds(object *o);

void set_which_guild(string guild)
{
   member_of += ({guild});
   understand_cmds(CMD_D->query_guild_cmds(guild));
}

void set_special_chance(int sc)
{
   special_percent_chance = sc;
}

int query_special_chance()
{
   return special_percent_chance;
}

string *guilds_belong()
{
   return member_of;
}

void rehash_cmds()
{
   guild_cmds = ([]);
   foreach (string g in member_of)
   {
      understand_cmds(CMD_D->query_guild_cmds(g));
   }
}

int member_of(string guild)
{
   return member_array(guild, member_of) != -1;
}

mapping query_guild_cmds()
{
   return guild_cmds;
}

void do_special()
{
   int reflex = this_object()->query_reflex();
   int *keys = filter_array(keys(guild_cmds), ( : $1 <= $(reflex) :));
   object target = this_object()->get_target();
   object spec;
   // TBUG("Target: " + target + " Reflex: " + reflex + " Keys: " + sizeof(keys));
   if (sizeof(keys) && target)
   {
      spec = guild_cmds[choice(keys)];
      // Woops, missing spec, rehash our cmds
      // TBUG("Special: " + spec);
      if (!spec)
      {
         rehash_cmds();
      }
      spec->spend_reflex(this_object());
      spec->special(this_object(), target);
   }
}

void understand_cmds(object *cmds)
{
   foreach (object cmd in cmds)
   {
      string name = cmd->query_name();
      int cost = cmd->query_reflex_cost();
      int target_req = cmd->query_target_required();

      // Assume all the ones with target_req are good for combat
      if (target_req)
      {
         guild_cmds[cost] = cmd;
      }
   }
}