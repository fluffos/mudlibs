/* The player sheet from the FR: Illumitech, pasted in by Baldrick.
 * 26 sept '93
 */

// Converted to the new command handler system by Morgoth 1/Mar/95
// - cleaned the code a bit :)
// - fixed 'money carried' to show the right amount
// - changed it to use query_al instead of query_alignment, was
//   showing wrong values.
// - Moved back to FR, added the FR'ish stuff to this one.

// Radix added Group name, Jan 1996
// Radix added Race group name, Apr 1996
// Radix removed the spell and command lists, July 1996

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
   position = 0;
}

string query_usage()
{
   return "sheet";
}

string query_short_help()
{
   return "Returns misc information and stats on a player.";
}

protected int cmd (string str, object me)
{
   int i;
   string info;
   object guild;
   object group;
   object race_group;

        if (me->query_dead())
          {
     write("You are just a disembodied spirit, you do not need to know"
                " this.\n");
          return 0;
          }

   guild = me->query_guild_ob();
   group = me->query_group_ob();

   info = "";
   info += "Name : "+me->query_cap_name()+"\n";
   info += "Race : "+me->query_race()+"\n";
   info += "Sex  : "+me->query_gender_string()+"\n";
   if (guild)
         info += "Guild          : "+guild->query_short()+"\n";
   else
      info += "Guild          : No guild.\n";
   info += "Race Group     : "+me->query_race_group_name()+"\n";
   info += "Interest Group : "+me->query_group_name()+"\n";
   info += "Level: "+me->query_level()+"\n";
   info += "Deity: "+capitalize(me->query_deity())+"\n";
   info += "Wimpy: "+me->query_wimpy()+" %\n";
// info += "Set alignment : "+ me->query_playerset_alname()+"\n";
   info += "Alignment    : "+me->query_align_name()+"\n";
   info += "Intoxication : "+me->volume_string()+".\n";
   info += "Money carried : "+me->query_value()/100+" GP\n";
   info += "Strength      : "+stat_string(me->query_str())+"\n";
   info += "Dexterity     : "+me->query_dex()+"\n";
   info += "Constitution  : "+me->query_con()+"\n";
   info += "Intelligence  : "+me->query_int()+"\n";
   info += "Wisdom        : "+me->query_wis()+"\n";
   info += "Charisma      : "+me->query_cha()+"\n";
   info += "Hit Points    : "+me->query_hp()+" ("+me->query_max_hp()+")\n";
   info += "Guild Points  : "+me->query_gp()+" ("+me->query_max_gp()+")\n";
   info += "Social        : "+me->query_social_points()+" ("+
               me->query_max_social_points()+")\n";
   info += "Experience    : "+me->query_xp()+"\n";
   info += "Encumbrance   : "+me->query_loc_weight()+
               " ("+me->query_max_weight()+")\n";
   printf("%-#*s\n", me->query_cols(), info);
   write("\n");
// Removed, Radix, caused spam
// me->show_spells("");
// me->list_commands();
   write("Type \"spells\" or \"commands\" for a list of spells "
      "and commands respectively.\n");
   return 1;
}
