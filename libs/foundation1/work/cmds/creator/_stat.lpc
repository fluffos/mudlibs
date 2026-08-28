#include <std.h>
//#include <str_fmt.h>
 
inherit DAEMON;
 
object ob;
 
void show_quests(object tp);
void money_display();
void stats_display();
void skills_display();
void language_display();
 
int cmd_stat(string str) {
   string name, title, Class, race, married, guild;
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
    if(adminp(ob) && (int)ob->query_invis())
      return notify_fail("Failed to find: "+str+".\n");
   title = (string)ob->query_short();
   Class = (string)ob->query_class();
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
   if(!Class) Class = "none";
   printf("%s\n", title);
   printf("%s%s%s\n",
      arrange_string("level: "+level, 25),
      arrange_string("class: "+Class, 25),
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
  string *langs;
  string ret;
  int i, lsz;

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
    string tmp, sign;
    string *attack, *weapon, *decep, *mag;
    int i, x, skill_size, blah;

    attack = ({ "melee", "attack", "defense", "double wielding" });
    weapon = ({ "knife", "blade", "blunt", "two handed", "projectile" });
    decep = ({ "locks", "stealth", "murder", "stealing", "bargaining" });
    mag = ({ "faith", "healing", "conjuring", "magic attack",
             "magic defense"});
 
    for(i=0; i<5; i++) {
        if(i<4) message("Nwrite", arrange_string(attack[i], 17)+": ", 
                        this_player());
        else message("Nwrite", arrange_string(" ", 19), this_player());
        if(i<4) tmp = ""+(int)ob->query_base_skill(attack[i]);
        else tmp = " ";
        tmp = arrange_string(tmp, 8);
        if(i<4) {
          blah = (int)ob->query_skill_bonus(attack[i]);
          if (blah >= 0)
            sign = "+";
          else
            sign = "-";
          tmp += " ("+sign+blah+")";
        } else 
          tmp = " ";
        message("Nwrite", arrange_string(tmp, 19), this_player());
        message("Nwrite", arrange_string(weapon[i], 17)+": ", this_player());
        tmp = arrange_string(""+(int)ob->query_base_skill(weapon[i]), 8);
        blah = (int)ob->query_skill_bonus(weapon[i]);
        if (blah >= 0)
          sign = "+";
        else
          sign = "-";
        tmp += " ("+sign+blah+")";
        write(arrange_string(tmp, 19));
    }
    write("------------------------------------------------------------------------------");
    for(i=0; i<5; i++) {
        message("Nwrite", arrange_string(decep[i], 17)+": ", this_player());
        tmp = arrange_string(""+(int)ob->query_base_skill(decep[i]),8);
        blah = (int)ob->query_skill_bonus(decep[i]);
        if (blah >= 0)
          sign = "+";
        else
          sign = "-";
        tmp += " ("+sign+blah+")";
        message("Nwrite", arrange_string(tmp, 19), this_player());
        message("Nwrite", arrange_string(mag[i], 17)+": ", this_player());
        tmp = arrange_string(""+(int)ob->query_base_skill(mag[i]),8);
        blah = (int)ob->query_skill_bonus(mag[i]);
        if (blah >= 0)
          sign = "+";
        else
          sign = "-";
        tmp += " ("+sign+blah+")";
        write(arrange_string(tmp, 19));
    }
    return;
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
