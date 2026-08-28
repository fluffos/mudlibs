#include <std.h>
#include <str_fmt.h>

inherit DAEMON;

object ob;

void show_quests(object tp);
void money_display();
void stats_display();
void skills_display();
void spells_display();

int cmd_stat(string str)
{
   string name, title, class_str, race, married;
   int level, hp, max_hp, mp, max_mp, sp, max_sp, exp,sdc,max_sdc;

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
   class_str = (string)ob->query_class();
   race = (string)ob->query_race();
   level = (int)ob->query_level();
   exp = (int)ob->query_exp();
   hp = (int)ob->query_hp();
   max_hp = (int)ob->query_max_hp();
   sdc = ob->query_sdc();
   max_sdc = ob->query_max_sdc();
   mp = (int)ob->query_ppe();
   max_mp = (int)ob->query_max_ppe();

   married = (string)ob->query_married();

   if(!married) married = "none";
   if(!race) race = "undefined";
   if(!class_str) class_str = "none";
   printf("%s\n", title);
   printf("%s%s%s\n",
      arrange_string("level: "+level, 25),
      arrange_string("class: "+class_str, 25),
      arrange_string("race: "+race,25) );
   printf("%s%s%s\n",
      arrange_string("experience: "+exp, 25),
      arrange_string("alignment: "+ob->query_alignment(),25),
      arrange_string("sex: "+(string)ob->query_gender(), 25) );
   printf("%s%s%s\n",
      arrange_string(hp+"/"+max_hp+" HP", 25),
      arrange_string(sdc+"/"+max_sdc+" SDC", 25),
      arrange_string(mp+"/"+max_mp+" magic points", 25) );
   printf("%s%s\n",
      arrange_string("carry: "+ob->query_internal_encumbrance(), 25) ,
      arrange_string("max carry: "+ob->query_max_internal_encumbrance(), 25) );
   printf("%s%s%s\n",
      arrange_string("quest points: "+(int)ob->query_quest_points(), 25),
      arrange_string("spouse: "+married, 25),
      "" );
   if(ob->is_player()) {
      show_quests(ob);
   }
   write("------------------------------------------------------------------------");
//   property_display();
   money_display();

   stats_display();
   skills_display();
   if(ob->query_all_spells()) spells_display();
   return 1;
}
#if 0
void property_display() {
    mapping props;
    write("Properties Defined:");
}
#endif
void show_quests(object tp) {
    string *quests;
    int i;

    quests = (string *)tp->query_quests();    message("Nwrite", "quests: ", this_player());
    for(i=0; i<sizeof(quests); i++) {
        message("Nwrite", quests[i]+" ", this_player());
    }
    message("Nwrite", "\n\n", this_player());
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
    string *skills, *list, which_skill, file, dev_str;
    int i;

    seteuid(getuid());
    skills = (string *)ob->query_all_skills();
    if(!skills || !sizeof(skills))
	return;
    skills = sort_array(skills,"alphabetize",this_object());
    list = ({});
    for(i=0;i<sizeof(skills);i++) {
		list += ({ sprintf("%-20s %3d%1s  ",skills[i],
		(int)ob->query_skill(skills[i]),"%") });
    }
    message("info","Skills:
------------------------------------------------------------------------"
	,this_player());
    this_player()->more(explode(format_page(list, 2),"\n\n"));
}

void spells_display()
{
      string *skills, *list, which_skill, file, dev_str;
    int i;

    seteuid(getuid());
    skills = (string *)ob->query_all_spells();
    skills = sort_array(skills,"alphabetize",this_object());
    list = ({});
    for(i=0;i<sizeof(skills);i++)
        list += ({ sprintf("%-27s *%1d",capitalize(skills[i]),
            (int)ob->query_spell_level(skills[i])) });
    message("info","Spells:\n"+
    "------------------------------------------------------------------------"
	,this_player());
    this_player()->more(explode(format_page(list, 2),"\n"));
}

void stats_display() {
    int i, stats_size;
    string *stats;

    stats = ({ "iq", "me", "ma", "ps",
      "pp", "pe", "pb", "spd" });
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
