// Petrarch
// Merentha Lib 1.0
// skill daemon

#include <skills.h>
#include <math.h>
#include <std.h>

inherit DAEMON;

void init_skills(object ob) {
    mapping tmp_skills=([]);
    string *skills;
    int i=sizeof(skills=ALL_SKILLS);
    if (!ob) return;
    ob->set_skill_bonus("attack",0);
    while(i--) tmp_skills[skills[i]]=(["level":25,"points":0,"adjustment":0,"adj_points":0]);
    ob->set_skills( tmp_skills );
}

int skill_cost(object ob, string _class, mixed skill) {
    if(_class=="mage") 
        if(ob->query_class("mage")) {
            if (member_array(skill, MAGE_TERRIBLE_SKILLS)!=-1) return 15;
            if (member_array(skill, MAGE_BAD_SKILLS)!=-1) return 9;
            if (member_array(skill, MAGE_AVG_SKILLS)!=-1) return 3;
            if (member_array(skill, MAGE_GOOD_SKILLS)!=-1) return -3;
            if (member_array(skill, MAGE_GREAT_SKILLS)!=-1) return -10;
        }
    if(_class=="fighter") 
        if(ob->query_class("fighter")) {
            if (member_array(skill, FIGHTER_TERRIBLE_SKILLS)!=-1) return 15;
            if (member_array(skill, FIGHTER_BAD_SKILLS)!=-1) return 9;
            if (member_array(skill, FIGHTER_AVG_SKILLS)!=-1) return 3;
            if (member_array(skill, FIGHTER_GOOD_SKILLS)!=-1) return -3;
            if (member_array(skill, FIGHTER_GREAT_SKILLS)!=-1) return -10;
        }
    if(_class=="healer") 
        if(ob->query_class("healer")) {
            if (member_array(skill, HEALER_TERRIBLE_SKILLS)!=-1) return 15;
            if (member_array(skill, HEALER_BAD_SKILLS)!=-1) return 9;
            if (member_array(skill, HEALER_AVG_SKILLS)!=-1) return 3;
            if (member_array(skill, HEALER_GOOD_SKILLS)!=-1) return -3;
            if (member_array(skill, HEALER_GREAT_SKILLS)!=-1) return -10;
        }
    if(_class=="monk") 
        if(ob->query_class("monk")) {
            if (member_array(skill, MONK_TERRIBLE_SKILLS)!=-1) return 15;
            if (member_array(skill, MONK_BAD_SKILLS)!=-1) return 9;
            if (member_array(skill, MONK_AVG_SKILLS)!=-1) return 3;
            if (member_array(skill, MONK_GOOD_SKILLS)!=-1) return -3;
            if (member_array(skill, MONK_GREAT_SKILLS)!=-1) return -10;
        }
    return 0;
}

int class_adjustment(object ob, mixed skill) {
    int val;
    if (ob->query_class()) val=sizeof(explode(ob->query_class(),"/"));
    else val=1;
    if(val==4) val=5;
    else if(val==3) val=6;
    else if(val==2) val=7;
    else val=8;
    return (skill_cost(ob,"mage",skill)+
      skill_cost(ob,"fighter",skill)+
      skill_cost(ob,"healer",skill)+
      skill_cost(ob,"monk",skill) )*val/10;
}

int gender_adjustment(object ob, string skill) {
    if (ob->query_gender()=="male") {
        if (member_array(skill,  MALE_GREAT_SKILLS )!=-1) return -12;
        if (member_array(skill,  MALE_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  MALE_BAD_SKILLS )!=-1) return 8;
        if (member_array(skill,  MALE_TERRIBLE_SKILLS )!=-1) return 16;
    }
    if (ob->query_gender()=="female") {
        if (member_array(skill,  FEMALE_GREAT_SKILLS )!=-1) return -12;
        if (member_array(skill,  FEMALE_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  FEMALE_BAD_SKILLS )!=-1) return 8;
        if (member_array(skill,  FEMALE_TERRIBLE_SKILLS )!=-1) return 16;
    }
}

int race_adjustment(object ob, string skill) {
  if (ob->query_race()=="human") {
        if (member_array(skill,  HUMAN_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  HUMAN_BAD_SKILLS )!=-1) return 8;
  }
  if (ob->query_race()=="elf") {
        if (member_array(skill,  ELF_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  ELF_BAD_SKILLS )!=-1) return 8;
  }
  if (ob->query_race()=="fairy") {
        if (member_array(skill,  FAIRY_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  FAIRY_BAD_SKILLS )!=-1) return 8;
  }
  if (ob->query_race()=="gnome") {
        if (member_array(skill,  GNOME_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  GNOME_BAD_SKILLS )!=-1) return 8;
  }
  if (ob->query_race()=="giant") {
        if (member_array(skill,  GIANT_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  GIANT_BAD_SKILLS )!=-1) return 8;
  }
  if (ob->query_race()=="dwarf") {
        if (member_array(skill,  DWARF_GOOD_SKILLS )!=-1) return -6;
        if (member_array(skill,  DWARF_BAD_SKILLS )!=-1) return 8;
  }
}

int overall_skill_adjustment(object ob, string skill) {
    return 
    class_adjustment(ob, skill)+
    gender_adjustment(ob, skill)+
    race_adjustment(ob, skill)+
    ob->query_skill_adjustment(skill)+
    ob->query_level()
    ;
}

int formula(object ob, string skill) {
    int val=sizeof(explode(""+ob->query_class(),"/"));
    int lev=ob->query_skill_level(skill);
    if(!ob || !skill || !val) return 1;
    return (lev*lev)*(100+
      overall_skill_adjustment(ob, skill)
    )/100;
}

int adj_formula(object ob, string skill) {
    int lev=ob->query_skill_level(skill);
    if(!ob || !skill) return 1;
    return (lev*lev*2)/(ob->query_stat("wisdom"));
}

