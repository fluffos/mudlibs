#include <std.h>
#include <str_fmt.h>
#include <daemons.h>
inherit DAEMON;
string do_bar(int begin, int end)
{
    int i, a;
    string st;
    st = "%^BOLD%^%^BLUE%^[%^RESET%^";
    i = percent(begin, end);
    i += i;
    while(a<i)
    {
        if (a < 50)
            st += "%^GREEN%^%^BOLD%^";
        if (a > 50)
            st += "%^YELLOW%^";
        if (a > 120)
            st += "%^RED%^%^BOLD%^";
        st += "*";
        a += 10;
    } 
    if (strlen(TERMINAL_D->no_colours(st)) < 21)
        while(strlen(TERMINAL_D->no_colours(st)) < 21)
            st += "%^BLACK%^%^BOLD%^.%^RESET%^";
    st += "%^BOLD%^%^BLUE%^]%^RESET%^";
    return st;
}
object o;
void money_display();
void language_display();
void check_outlaw();
int cmd_wizscore(string str) {
    string name, title, classs, subcls, race, married, guild, sb, quests, deeds, deaths, kills, *stats, *skills;
    mapping skillnum;
    int level, hp, max_hp, mp, max_mp, sp, max_sp, exp, age;
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
    }
if (!wizardp(this_player())) {
notify_fail("nope");
return 0;
}
    if (!(string)this_player()->query_race())
    {
        write("You can not use this command until you have picked a race.");
        return 1;
    }
    stats = ({ "wisdom", "intelligence", "constitution", "charisma",
               "dexterity", "strength" });
o = find_player(str);
    skills = keys(o->query_skills());
    skillnum = o->query_skills();
    name = (string)o->query_cap_name();
    title = (string)o->query_title();
    classs = (string)o->query_class();
    subcls = (string)o->query_subclass();
    race = (string)o->query_race();
    level = (int)o->query_level();
    exp = (int)o->query_exp();
    hp = (int)o->query_hp();
    max_hp = (int)o->query_max_hp();
    mp = (int)o->query_mp();
    max_mp = (int)o->query_max_mp();
    sp = (int)o->query_sp();
    max_sp = (int)o->query_max_sp();
    quests = (string)o->query_quests();
    deeds = (string)o->query_mini_quest_map();
    deaths = (string)o->query_deaths();
    kills = (string)o->query_kills();
    married = (string)(o->query_married());
    guild = (string)(o->query_guild());
    age = time() - (int)this_player()->query_birthday();
    if(!married) married = "None";
    if(!guild) guild = "None";
    if(!race) race = "Undefined";
    if(!classs) classs = "None";
    if(!subcls) subcls = "None";
    message("info", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Score %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+", this_player());
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^BLUE%^Name     : %^RESET%^"+name, 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Title: %^RESET%^"+title, 43); 
    write(sb);
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^BLUE%^Race     : %^RESET%^"+capitalize(race), 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Level  : %^RESET%^"+level, 23);
    sb += arrange_string("%^BOLD%^%^BLUE%^Experience: %^RESET%^"+add_commas(exp), 26);
    write(sb);
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^BLUE%^Class    : %^RESET%^"+capitalize(classs), 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Gender : %^RESET%^"+capitalize(o->query_gender()), 23);
    sb += arrange_string("%^BOLD%^%^BLUE%^Alignment : %^RESET%^"+capitalize(o->query_al_title()), 25);
    write(sb);
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^BLUE%^Subclass : %^RESET%^"+capitalize(subcls), 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Age    : %^RESET%^"+(18 + (age/4320000)), 23);
    sb += arrange_string("%^BOLD%^%^BLUE%^Spouse    : %^RESET%^"+capitalize(married), 25);
    write(sb);
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^BLUE%^Guild    : %^RESET%^"+capitalize(guild), 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Deeds  : %^RESET%^"+sizeof(deeds), 23);
    sb += arrange_string("%^BOLD%^%^BLUE%^Deaths    : %^RESET%^"+sizeof(deaths), 25);
    write(sb);
    sb = arrange_string(sb, 25);
    if(o->query_recent_outlaw())
      sb = arrange_string("%^BOLD%^%^BLUE%^Outlaw   : %^RED%^YES%^RESET%^", 25);
    else
      sb = arrange_string("%^BOLD%^%^BLUE%^Outlaw   : %^RESET%^No%^RESET%^", 25);
    sb += arrange_string("%^BOLD%^%^BLUE%^Quests : %^RESET%^"+sizeof(quests), 23);
    sb += arrange_string("%^BOLD%^%^BLUE%^Kills     : %^RESET%^"+sizeof(kills), 25);
    write(sb);
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    sb = arrange_string(sb, 25);
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Hit Points     : %^RESET%^"+hp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_hp, 35);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Intoxicated : %^RESET%^ ", 14);
    sb +=  do_bar(this_player()->query_intox(), this_player()->query_healing_formula());
    write(sb);
sb = arrange_string("%^BOLD%^%^MAGENTA%^Stamina Points : %^RESET%^"+sp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_sp, 35);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Stuffed     : %^RESET%^", 14);
    sb +=  do_bar(this_player()->query_stuffed(), this_player()->query_healing_formula());
    write(sb);
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Mana Points    : %^RESET%^"+mp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_mp, 35);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Quenched    : %^RESET%^", 14);
    sb +=  do_bar(this_player()->query_quenched(), this_player()->query_healing_formula());
    write(sb);
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Encumberance   : %^RESET%^"+o->query_internal_encumbrance()+"%^BOLD%^%^BLUE%^/%^RESET%^"+o->query_max_internal_encumbrance()/2, 35);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Poisoned    : %^BLUE%^%^BOLD%^[", 17);
    if (this_player()->query_poisoning())
        sb +="%^RED%^%^BOLD%^%^FLASH%^Yes!%^RESET%^ %^BLUE%^%^BOLD%^]%^RESET%^";
    else sb += "%^RESET%^No  %^BOLD%^%^BLUE%^]%^RESET%^";
    write(sb);
    age = 0;
    level = 0;
    exp = sizeof(stats);
    while(exp--)
        age += o->query_stats(stats[exp]);
    exp = sizeof(skills);
    while(exp--)
        level += skillnum[skills[exp]]["level"];
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Stat Point Totals :%^RESET%^ "+age, 35);
    sb += "%^BOLD%^%^MAGENTA%^Skill Point Totals :%^RESET%^ "+level;
    write(sb);
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    money_display();
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    this_player()->force_me("age");
    check_outlaw();
    message("info", "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=",this_player());
    return 1;
}
void money_display() {
    string *currs;
    string borg;
    int i, tmp;
    currs = (string *)o->query_currencies();
    if((!currs || !sizeof(currs)) ) {
        message("info", "No money.", this_player());
        return;
    }
    for(borg = "%^BOLD%^%^MAGENTA%^Money : %^RESET%^", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((o->query_money(currs[i]))+" "+currs[i]);
        if(i == tmp-1) borg +=(".");
        else if(tmp > 2 && i == tmp-2) borg += (", and ");
        else if(tmp == 2) borg +=(" and ");
        else borg +=(", ");
    }
    message("info", borg, this_player());
    return;
}
void check_outlaw() {
    int drug, oth1, oth2, pk, theft;
    drug = this_player()->query_outlaw("drug");
    oth1 = this_player()->query_outlaw("other1");
    oth2 = this_player()->query_outlaw("other2");
    pk = this_player()->query_outlaw("pk");
    theft = this_player()->query_outlaw("theft");

    if(drug+oth1+oth2+pk+theft < 1)
      return;
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    write("%^RESET%^You have the following criminal record:\n");
    if(drug)
      write("    Drug offences: "+(string)drug);
    if(oth1)
      write("    Minor offences: "+(string)oth1);
    if(oth2)
      write("    Major offences: "+(string)oth2);
    if(theft)
      write("    Theft offences: "+(string)theft);
    if(pk)
      write("    Murder offences: "+(string)pk);
    write("");
}
void help() {
    write("Syntax: <score>\n\n"
      "This command gives you information about your character.\n"
      "See also: status, body, biography, skills, stats, money, inventory\n"
    );
}
