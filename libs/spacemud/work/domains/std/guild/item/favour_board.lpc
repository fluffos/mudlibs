/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_WIDGETS;

string guild;
mapping contrib;

#define MAX_ON_BOARD 20

void setup(string g)
{
   set_id("favour board", "board");
   set_attached(1);
   guild = g;
}

int sort_contrib(string id1, string id2)
{
   if (contrib[id1] > contrib[id2])
      return -1;
   if (contrib[id1] < contrib[id2])
      return 1;
   return 0;
}

string *contributors()
{
   if (!contrib)
      return ({});
   return sort_array(keys(contrib), ( : sort_contrib:))[0..MAX_ON_BOARD];
}

string long()
{
   string long_desc = "";
   int total = GUILD_D->query_favour_score(guild);
   mapping buff_list = GUILD_D->query_buff_list();

   contrib = GUILD_D->query_favour_contribution(guild);
   long_desc += simple_divider();
   long_desc += "    %^YELLOW%^" + upper_case(guild) + " - Favour Board Top " + MAX_ON_BOARD + "%^RESET%^.\n\n";

   foreach (string p in contributors())
   {
      long_desc += sprintf("%20s  %d\n", p, contrib[p]);
   }
   long_desc += "\n     Available favour  " + total + "\n";

   foreach (int tier in sort_array(keys(buff_list), 1))
   {
      mapping guilds = buff_list[tier];
      if (guilds[guild])
      {
         long_desc += "\n    %^YELLOW%^ACTIVE TIER " + tier + " BUFFS:%^RESET%^\n";
         foreach (string name, int expire in guilds[guild])
         {
            long_desc += sprintf("%20s for %20s more.\n", name, time_to_string(expire - time()));
         }
         long_desc += "\n";
      }
   }
   long_desc += simple_divider();
   long_desc += "Leader: " + capitalize(GOVERNANCE_D->query_leader(guild)) + "  Managers: " +
                implode(map(GOVERNANCE_D->query_managers(guild), (
                                                                     : capitalize($1)
                                                                     :)),
                        " ") +
                "\n";

   return long_desc;
}