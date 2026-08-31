#include <std.h>
#include <str_fmt.h>
 
inherit DAEMON;
 
object ob;
 
void show_quests(object tp);
void money_display();
void stats_display();
void skills_display();
void language_display();
 
int cmd_stat(string str) {
   string title, classs, race, married, guild;
   int level, hp, max_hp, mp, max_mp, sp, max_sp, exp;
 
   if(!str) {
      notify_fail("stat <living>\n");
      return 0;
   }
   str = lower_case(str);
   if(!(ob = to_object(str)))
      if(!(ob = present(str, environment(this_player()))))
         if(!(ob = find_object(str))) {
      notify_fail("Failed to find: "+str+".\n");
      return 0;
   }
   if(!living(ob)) {
      notify_fail("That is not a living object.\n");
      return 0;
   }
    if(archp(ob) && (int)ob->query_invis())
      return notify_fail("Failed to find: "+str+".\n");
   title = (string)ob->query_short();
   classs = (string)ob->query_class();
   race = (string)ob->query_race();
   level = (int)ob->query_level();
   exp = (int)ob->query_exp();
   hp = (int)ob->query_hp();
   max_hp = (int)ob->query_max_hp();
   mp = (int)ob->query_mp();
   max_mp = (int)ob->query_max_mp();
   sp = (int)ob->query_sp();
   max_sp = (int)ob->query_max_sp();
   married = (string)ob->query_married();
   guild = (string)ob->query_guild();
 
   if(!married) married = "none";
   if(!guild) guild = "none";
   if(!race) race = "undefined";
   if(!classs) classs = "none";
   printf("%s\n", title);
   printf("%s%s%s\n",
      arrange_string("level: "+level, 25),
      arrange_string("class: "+classs, 25),
      arrange_string("race: "+race,25) );
   printf("%s%s%s\n",
      arrange_string("experience: "+exp, 25),
      arrange_string("alignment: "+ob->query_alignment(),25),
      arrange_string("sex: "+(string)ob->query_gender(), 25) );
   printf("%s%s%s\n",
      arrange_string(hp+"/"+max_hp+" health points", 25),
      arrange_string(sp+"/"+max_sp+" stamina points", 25),
      arrange_string(mp+"/"+max_mp+" magic points", 25) );
   printf("%s%s\n",
      arrange_string("carry: "+ob->query_internal_encumbrance(), 25) ,
      arrange_string("max carry: "+ob->query_max_internal_encumbrance(), 25) );
   printf("%s%s%s\n",
      arrange_string("quest points: "+(int)ob->query_quest_points(), 25),
      arrange_string("spouse: "+married, 25),
      arrange_string("guild: "+guild, 25) );
   if(ob->is_player()) {
      show_quests(ob);
   }
   money_display();
   language_display();
   stats_display();
   skills_display();
   return 1;
}
 
void show_quests(object tp) {
    string *quests;
    int i;
 
    quests = (string *)tp->query_quests();    message("Nwrite", "quests: ", this_player());
    for(i=0; i<sizeof(quests); i++) {
        message("Nwrite", quests[i]+" ", this_player());
    }
    message("Nwrite", "\n\n", this_player());
}
// added by Valodin to display language abilities, Aug. 27, 1993
void language_display() {
/*    langs = (string *)ob->query_all_languages();
    ret = "Languages: ";
    if(!(lsz = sizeof(langs))) ret += "None";
    else {
        for(i=0; i<lsz; i++) {
          ret += capitalize(langs[i]) + ": "+ ob->query_lang_prof(langs[i]) +
            (i== lsz -1 ? "." : (langs != lsz-2 ? ", " : ", and "));
        }
    }
    message("info", ret + "\n", this_player());
*/
}
 
void money_display() {
    string *currs;
    string borg;
    int i, tmp;
 
    currs = (string *)ob->query_currencies();
    if((!currs || !sizeof(currs)) ) {
        message("info", "No money.", this_player());
        return;
    }
    for(borg = "", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((ob->query_money(currs[i]))+" "+currs[i]);
        if(i == tmp-1) borg +=(".\n");
        else if(tmp > 2 && i == tmp-2) borg += (", and ");
        else if(tmp == 2) borg +=(" and ");
        else borg +=(", ");
    }
    message("info", borg, this_player());
    return;
}
 
void skills_display() {
  int max;
  string out = "";
  string *col1 = ({}), *col2 = ({});
  string *attack = ({
    "attack", "charging", "defense", "double wielding", "melee", "rage", "riding",
  });
  string *weapon = ({
    "axe", "blade", "blunt", "flail", "knife", "projectile", "ranged",
    "breath", "claw", "tail",
  });
  string *decept = ({
    "agility", "bargaining", "discipline", "entertainment", "euphony",
    "ferocity", "flying", "locks", "murder", "perception", "stealing",
    "stealth", "valor",
  });
  string *magic = ({
    "belief", "clairvoyance", "conjuring", "faith", "healing", "illusion",
    "magic attack", "magic defense", "nature", "necromancy", "psionics",
    "pyromancy", "summoning", "wizardry",
  });

  foreach (string sk in attack)
    if (!ob->skill_exists(sk))
      attack -= ({ sk });
  foreach (string sk in weapon)
    if (!ob->skill_exists(sk))
      weapon -= ({ sk });
  foreach (string sk in decept)
    if (!ob->skill_exists(sk))
      decept -= ({ sk });
  foreach (string sk in magic)
    if (!ob->skill_exists(sk))
      magic -= ({ sk });

  max = sizeof(attack);
  if (sizeof(magic) > max) max = sizeof(magic);

  for (int i = 0; i < max; i++) {
    int bonus;
    string m = " ";
    if (i > sizeof(attack)-1)
      col1 += ({ repeat_string(" ", 39) });
    else {
      bonus = ob->query_skill_bonus(attack[i]);
      if (ob->query_base_skill(attack[i]) == ob->query_max_skill(attack[i])*ob->query_level()/2) m = "max";
      else m = " ";
      col1 += ({
        arrange_string(
          arrange_string(attack[i], 16)+": "+
          arrange_string(ob->query_base_skill(attack[i])+"", 5)+" "+
          arrange_string(m, 4)+
          "("+(bonus >= 0 ? "+" : "-")+bonus+")",
          39
        )
      });
    }

    if (i > sizeof(magic)-1)
      col2 += ({ " " });
    else {
      if (ob->query_base_skill(magic[i]) == ob->query_max_skill(magic[i])*ob->query_level()/2) m = "max";
      else m = " ";
      bonus = ob->query_skill_bonus(magic[i]);
      col2 += ({
        arrange_string(
          arrange_string(magic[i], 16)+": "+
          arrange_string(ob->query_base_skill(magic[i])+"", 5)+" "+
          arrange_string(m, 4)+
          "("+(bonus >= 0 ? "+" : "-")+bonus+")",
          39
        )
      });
    }

  }

  col1 += ({ repeat_string("-", 39) });
  col2 += ({ repeat_string("-", 39) });

  max = sizeof(decept);
  if (sizeof(weapon) > max) max = sizeof(weapon);

  for (int i = 0; i < max; i++) {
    int bonus;
    string m = " ";
    if (i > sizeof(decept)-1)
      col1 += ({ repeat_string(" ", 39) });
    else {
      bonus = ob->query_skill_bonus(decept[i]);
      if (ob->query_base_skill(decept[i]) == ob->query_max_skill(decept[i])*ob->query_level()/2) m = "max";
      else m = " ";
      col1 += ({
        arrange_string(
          arrange_string(decept[i], 16)+": "+
          arrange_string(ob->query_base_skill(decept[i])+"", 5)+" "+
          arrange_string(m, 4)+
          "("+(bonus >= 0 ? "+" : "-")+bonus+")",
          39
        )
      });
    }

    if (i > sizeof(weapon)-1)
      col2 += ({ " " });
    else {
      bonus = ob->query_skill_bonus(weapon[i]);
      if (ob->query_base_skill(weapon[i]) == ob->query_max_skill(weapon[i])*ob->query_level()/2) m = "max";
      else m = " ";
      col2 += ({
        arrange_string(
          arrange_string(weapon[i], 16)+": "+
          arrange_string(ob->query_base_skill(weapon[i])+"", 5)+" "+
          arrange_string(m, 4)+
          "("+(bonus >= 0 ? "+" : "-")+bonus+")",
          39
        )
      });
    }

  }

  max = sizeof(col1);
  for (int i = 0; i < max; i++)
    out += col1[i] + col2[i] + "\n";

  message("info", out, this_player() );

}
 
void stats_display() {
    int i, stats_size;
    string *stats;
 
    stats = ({ "strength", "constitution", "dexterity", "charisma",
      "intelligence", "wisdom" });
    stats_size = sizeof(stats); /* speed patch by Val */
    for(i = 0; i < stats_size; i += 3) {
        message("Nwrite", arrange_string(stats[i], 13)+": ", this_player());
        message("Nwrite", (int)ob->query_stats(stats[i])+"     ", 
                this_player());
        if(i+1 >= stats_size) message("Nwrite", "\n", this_player());
        else {
            message("Nwrite", arrange_string(stats[i+1], 13)+": ", 
                    this_player());
            message("Nwrite", (int)ob->query_stats(stats[i+1])+"     ", 
                    this_player());
        }
        if(i+2 >= stats_size) message("Nwrite", "\n", this_player());
        else {
            message("Nwrite", arrange_string(stats[i+2], 13)+": ", 
                    this_player());
            message("Nwrite", (int)ob->query_stats(stats[i+2])+"     ",
                    this_player());
        }
        message("Nwrite", "\n", this_player());
    }
   message("Nwrite", "\n", this_player());
   return;
}
void help() {
    message("help",
      "Syntax: <stat [player]>\n\n"
      "Gives you vital information about a player or monster.", this_player());
}
