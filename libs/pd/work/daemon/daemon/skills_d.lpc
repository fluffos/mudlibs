//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993
//      modified by Seeker,  March 2001
#include <security.h>
#include <save.h>
mapping m_skills;
void save_skills();
void create()
{
 m_skills = ([]);
 seteuid( UID_SECURE_DAEMONSAVE );
 if(file_exists(SAVE_SKILLS+".o")) restore_object( SAVE_SKILLS );
 seteuid( getuid() );
}
void save_skills()
{
 seteuid( UID_SECURE_DAEMONSAVE );
 save_object( SAVE_SKILLS );
 seteuid( getuid());
}
void add_skill(string *classes, string *subclasses, string name)
{
 m_skills[name] = ([ "c_elig" : classes, "sc_elig" : subclasses ]);
 save_skills();
}
string *query_skills() { return keys(m_skills); }
mapping query_skill(string skill) { return m_skills[skill]; }
mapping init_skills(string cl) {
    mapping skills;
    if(!skills) skills = ([]);
    if(!cl) {
        skills["melee"] =  ([ "level":0, "points":0, "max":1 ]);
        skills["attack"] = ([ "level":0, "points":0, "max":1 ]);
        skills["defense"] = ([]);
        skills["double wielding"] = ([]);
        skills["two handed"] = ([]);
        skills["charging"] = ([]);
        skills["riding"] = ([]);
        skills["rage"] = ([]);
        skills["discipline"] = ([]);
        skills["valor"] = ([]);
        skills["ferocity"] = ([]);
        skills["knife"] = ([]);
        skills["blunt"] = ([]);
        skills["projectile"] = ([]);
        skills["blade"] = ([]);
        skills["axe"] = ([]);
        skills["flail"] = ([]);
        skills["murder"] = ([]);
        skills["stealing"] = ([]);
        skills["bargaining"] = ([]);
        skills["locks"] = ([]);
        skills["entertainment"] = ([]);
        skills["euphony"] = ([]);
        skills["agility"] = ([]);
        skills["clairvoyance"] = ([]);
        skills["magic defense"] = ([]);
        skills["magic attack"] = ([]);
        skills["conjuring"] = ([]);
        skills["nature"] = ([]);
        skills["psionics"] = ([]);
        skills["summoning"] = ([]);
        skills["necromancy"] = ([]);
        skills["wizardry"] = ([]);
        skills["pyromancy"] = ([]);
        skills["illusion"] = ([]);
        skills["belief"] = ([]);
        skills["healing"] = ([]);
        skills["faith"] = ([]);
        skills["illusion"] = ([]);
    }
    else {
        switch(cl) {
            case "fighter":
                
                skills["melee"] = ([ "level": 10, "points": 0, "max": 10 ]);
                skills["attack"] = ([ "level": 10, "points": 0, "max": 12]);
                skills["defense"] = ([ "level": 10, "points":0, "max": 10 ]);
                skills["double wielding"] = (["level": 7, "points":0, "max":10]);
                skills["knife"] = ([ "level": 7, "points":0, "max":10 ]);
                skills["blunt"] = (["level": 7, "points":0, "max": 10 ]);
                skills["projectile"] = (["level":7, "points":0, "max": 10  ]);
                skills["flail"] = ([ "level": 7, "points": 0, "max": 10 ]);
                skills["blade"] = (["level":10, "points":0, "max":10 ]);
                skills["axe"] = (["level":7, "points":0, "max":10 ]);
                skills["two handed"] = (["level":7, "points":0, "max":10 ]);
                skills["murder"] = (["level":0, "points":0, "max": 2 ]);
                skills["stealing"] = (["level":0, "points":0, "max": 2 ]);
                skills["bargaining"] = (["level":3, "points":0, "max":7 ]);
                skills["locks"] = (["level":0, "points":0, "max":2 ]);
                skills["stealth"] = ([ "level":0, "points":0, "max":6 ]);
            if (previous_object()->query_subclass()=="paladin"||
                  previous_object()->query_subclass()=="antipaladin") {
                skills["magic defense"] = (["level":6, "points":0, "max":8 ]);
                skills["magic attack"] = (["level":6, "points":0, "max":8 ]);
                skills["healing"] = (["level":6, "points":0, "max":8 ]);
                skills["faith"] = (["level":6, "points":0, "max":8 ]);
                
               }
                skills["charging"] = ([ "level": 5, "points": 0, "max": 10 ]);
                skills["riding"] = ([ "level": 5, "points": 0, "max": 10 ]);
            if (previous_object()->query_subclass()=="berserker") {
                skills["rage"] = ([ "level":7, "points":0, "max":10 ]);
                skills["melee"] = ([ "level": 10, "points": 0, "max": 12 ]);
               }   
            if (previous_object()->query_subclass()=="ranger") {   
                skills["nature"] = ([ "level": 7, "points": 0, "max": 10 ]);
               }
                skills["valor"] = ([ "level":7, "points":0, "max":10 ]);   
                skills["ferocity"] = ([ "level": 7, "points": 0, "max": 10 ]);
                skills["discipline"] = ([ "level": 7, "points": 0, "max": 10 ]);
                break;
            case "rogue":
                skills["melee"] = (["level": 3, "points":0, "max": 7 ]);
                skills["attack"] = (["level": 10, "points":0, "max": 10 ]);
                skills["defense"] = (["level":8, "points":0, "max":8 ]);
                skills["double wielding"] = (["level":3, "points":0, "max":10 ]);
                skills["knife"] = (["level":10, "points":0, "max": 10 ]);
                skills["blunt"] = (["level":2, "points":0, "max":6 ]);
                skills["projectile"] = (["level":5, "points":0, "max":10]);
                skills["flail"] = ([ "level": 2, "points": 0, "max": 7 ]);
                skills["blade"] = (["level":0, "points":0, "max": 5]);
                skills["axe"] = (["level":0, "points":0, "max":5 ]);
                skills["two handed"] = (["level":0, "points":0, "max":5  ]);
                skills["murder"] = (["level":10, "points":0, "max":10 ]);
                skills["stealth"] = (["level":10, "points":0, "max":12 ]);
                skills["stealing"] = (["level":7, "points":0, "max":10 ]);
                skills["bargaining"] = (["level":7, "points":0, "max":10 ]);
                skills["locks"] = (["level":10, "points":0, "max":10 ]);
                skills["agility"] = (["level":10, "points":0, "max":10 ]);
                break;
            case "wanderer":
                skills["melee"] = (["level": 5, "points":0, "max": 5 ]);
                skills["attack"] = (["level": 9, "points":0, "max": 9 ]);
                skills["defense"] = (["level":8, "points":0, "max":10 ]);
                skills["double wielding"] = (["level":3, "points":0, "max":2 ]);
                skills["knife"] = (["level":3, "points":0, "max": 4 ]);
                skills["blunt"] = (["level":11, "points":0, "max":11 ]);
                skills["projectile"] = (["level":1, "points":0, "max":2]);
                skills["flail"] = ([ "level": 3, "points": 0, "max": 7 ]);
                skills["blade"] = (["level":9, "points":0, "max": 9]);
                skills["axe"] = (["level":0, "points":0, "max":5 ]);
                skills["two handed"] = (["level":2, "points":0, "max":3 ]);
                skills["murder"] = (["level":2, "points":0, "max":4 ]);
                skills["stealth"] = (["level":5, "points":0, "max":8 ]);
                skills["stealing"] = (["level":2, "points":0, "max":5 ]);
                skills["riding"] = ([ "level": 4, "points": 0, "max": 8 ]);
		if (previous_object()->query_subclass() == "gypsy")
		 skills["bargaining"] = (["level":10, "points":0, "max":10 ]);
		else skills["bargaining"] = (["level":5, "points":0, "max":7 ]);
                skills["locks"] = (["level":1, "points":0, "max":2 ]);
		if (previous_object()->query_subclass() == "jester")
                 skills["entertainment"] = (["level":10, "points":0, "max":10 ]);
		if (previous_object()->query_subclass() == "bard")
 		 skills["euphony"] = ([ "level":10, "points":0, "max":10 ]);
		else skills["euphony"] = ([ "level":4, "points":0, "max":4 ]);
		if (previous_object()->query_subclass() == "gypsy")
                 skills["clairvoyance"] = (["level":10, "points":0, "max":10 ]);
		if (previous_object()->query_subclass() == "swashbuckler")
		 skills["bargaining"] = (["level":10, "points":0, "max":10 ]);
		 skills["blade"] = (["level":10, "points":0, "max":12 ]);
                break;
            case "mage":
                skills["melee"] = (["level":1, "points":0, "max":5 ]);
                skills["attack"] = (["level":0, "points":0, "max": 5 ]);
                skills["defense"] = (["level":1, "points":0, "max":5 ]);
                skills["double wielding"] = (["level":0, "points":0, "max":1 ]);
                skills["knife"] = (["level":1, "points":0, "max":1 ]);
                skills["blunt"] = (["level":5, "points":0, "max":10 ]);
                skills["projectile"] = (["level":0, "points":0, "max":1  ]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["blade"] = (["level":0, "points":0, "max":1 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1  ]);
                skills["murder"] = (["level":0, "points":0, "max":2 ]);
                skills["bargaining"] = (["level":3, "points":0, "max":8  ]);
                skills["locks"] = (["level":0, "points":0, "max":1 ]);
                skills["magic defense"] = (["level" :10, "points":0, "max":10 ]);
                skills["magic attack"] = (["level": 10, "points": 0, "max":12 ]);
                skills["conjuring"] = (["level":10, "points":0, "max":10 ]);
           if (previous_object()->query_subclass()=="sorceror") {
                skills["psionics"] = (["level":10, "points":0, "max":10 ]);
               }
           if (previous_object()->query_subclass()=="necromancer") {
                skills["necromancy"] = (["level":10, "points":0, "max":10]);
               }
           if (previous_object()->query_subclass()=="pyromancer") {
                skills["pyromancy"] = (["level":10, "points":0, "max":10]);
               }
           if (previous_object()->query_subclass()=="wizard") {
                skills["wizardry"] = (["level":10, "points":0, "max":10]);
               }
           if (previous_object()->query_subclass()=="illusionist") {
                skills["illusion"] = (["level":10, "points":0, "max":10]);
               }
                break;
            case "clergy":
           if (previous_object()->query_subclass()=="monk") {
                skills["melee"] = (["level":10, "points":0, "max":12 ]);
                skills["attack"] = (["level":10, "points":0, "max":10 ]);
                skills["defense"] = (["level":10, "points":0, "max":10]);
                skills["double wielding"] = (["level":0, "points":0, "max":1 ]);
                skills["knife"] = (["level":0, "points":0, "max":5 ]);
                skills["blunt"] = (["level":3, "points":0, "max": 5 ]);
                skills["projectile"] = (["level":5, "points":0, "max":10 ]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["blade"] = (["level":0, "points":0, "max":3 ]);
                skills["axe"] = (["level":0, "points":0, "max":5 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1  ]);
                skills["murder"] = (["level":0, "points":0, "max":5 ]);
                skills["bargaining"] = (["level":1, "points":0, "max": 8 ]);
                skills["locks"] = (["level":0, "points":0, "max":1]);
                skills["magic defense"] = (["level":2, "points":0, "max":5 ]);
                skills["magic attack"] = (["level":2, "points":0, "max": 5 ]);
                skills["healing"] = (["level":5, "points":0, "max": 7 ]);
                skills["faith"] = (["level":10, "points":0, "max":10 ]);
                skills["conjuring"] = (["level":3, "points":0, "max": 5 ]);
           } else if (previous_object()->query_subclass()=="cleric") {
                skills["melee"] = ([ "level": 1, "points":0, "max": 5 ]);
                skills["attack"] = ([ "level":0, "points":0, "max": 7 ]);
                skills["defense"] = ([ "level":1, "points":0, "max":6 ]);
                skills["double wielding"] = (["level":0, "points":0, "max": 1 ]);
                skills["knife"] = ([ "level":5, "points":0, "max":1 ]);
                skills["blunt"] = ([ "level":5, "points":0, "max":8 ]);
                skills["flail"] = ([ "level":7, "points":0, "max":10 ]);
                skills["projectile"] = (["level":0, "points":0, "max": 0]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["blade"] = (["level":0, "points":0, "max":1 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1 ]);
                skills["murder"] = ([ "level":0, "points":0, "max":5 ]);
                skills["locks"] = (["level":0, "points":0, "max":0 ]);
                skills["bargaining"] = ([ "level":1, "points":0, "max": 8 ]);
                skills["magic defense"] = ([ "level":10, "points":0, "max": 10 ]);
                skills["magic attack"] = ([ "level":10, "points":0, "max": 10 ]);
                skills["healing"] = ([ "level":10, "points":0, "max":10 ]);
                skills["conjuring"] = ([ "level":4, "points":0, "max":10  ]);
                skills["belief"] = ([ "level":10, "points":0, "max":12 ]);
           } else if (previous_object()->query_subclass()=="kataan") {
                skills["melee"] = (["level":2, "points":0, "max":10]);
                skills["attack"]= (["level":2, "points":0, "max":10]);
                skills["defense"]= (["level":2, "points":0, "max":10]);
                skills["double wielding"]=(["level":3, "points":0, "max":8]);
                skills["knife"]=(["level":0, "points":0, "max":10]);
                skills["blunt"]=(["level":0, "points":0, "max":7]);
                skills["blade"]=(["level":1, "points":0, "max":7]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"]=(["level":2, "points":0, "max":10]);
                skills["projectile"]=(["level":10, "points":0, "max":10]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["bargaining"]=(["level":1, "points":0, "max":10]);
                skills["stealth"]=(["level":3, "points":0, "max":10]);
                skills["stealing"]=(["level":0, "points":0, "max":10]);
                skills["locks"]=(["level":6, "points":0, "max":10]);
                skills["murder"]=(["level":3, "points":0, "max":10]);
                skills["magic attack"]=(["level":3, "points":0, "max":10]);
                skills["faith"]=(["level":5, "points":0, "max":10]);
                skills["magic defense"]=(["level":1, "points":0, "max":3]);
                skills["summoning"]=(["level":7, "points":0, "max":12]);
           } else if (previous_object()->query_subclass()=="druid") {
                skills["melee"] = (["level":1, "points":0, "max":5 ]);
                skills["attack"] = (["level":0, "points":0, "max": 5 ]);
                skills["defense"] = (["level":1, "points":0, "max":5 ]);
                skills["double wielding"] = (["level":0, "points":0, "max":1 ]);
                skills["knife"] = (["level":1, "points":0, "max":1 ]);
                skills["blunt"] = (["level":5, "points":0, "max":10 ]);
                skills["projectile"] = (["level":0, "points":0, "max":1  ]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["blade"] = (["level":0, "points":0, "max":1 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1  ]);
                skills["murder"] = (["level":0, "points":0, "max":5 ]);
                skills["bargaining"] = (["level":3, "points":0, "max":8  ]);
                skills["locks"] = (["level":0, "points":0, "max":1 ]);
                skills["magic defense"] = (["level" :10, "points":0, "max":10 ]);
                skills["magic attack"] = (["level": 10, "points": 0, "max":12 ]);
                skills["conjuring"] = (["level":10, "points":0, "max":10 ]);
                skills["nature"]   = (["level":10, "points":0, "max":10 ]);
                skills["faith"]=(["level":5, "points":0, "max":10]);                    
            } else {
                skills["melee"] = (["level":7, "points":0, "max":10 ]);
                skills["attack"] = (["level":7, "points":0, "max":10 ]);
                skills["defense"] = (["level":7, "points":0, "max":10]);
                skills["double wielding"] = (["level":0, "points":0,"max":10]);  
                skills["knife"] = (["level":0, "points":0,"max":10 ]);
                skills["blunt"] = (["level":0, "points":0, "max": 10 ]);
                skills["projectile"] = (["level":0, "points":0, "max":10]);
                skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
                skills["blade"] = (["level":7, "points":0, "max":10 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":10]);
                skills["murder"] = (["level":0, "points":0, "max":1 ]);
                skills["stealing"] = (["level":0, "points":0, "max":1 ]);
                skills["bargaining"] = (["level":0, "points":0, "max":1 ]);
                skills["locks"] = (["level":0, "points":0, "max":1 ]);
            }
                break;
            case "child": 
            skills["melee"] = (["level":7, "points":0, "max":10 ]);
            skills["attack"] = (["level":7, "points":0, "max":10 ]);
            skills["defense"] = (["level":7, "points":0, "max":10]);
            skills["double wielding"] = (["level":0, "points":0,"max":10]);  
            skills["knife"] = (["level":0, "points":0,"max":10 ]);
            skills["blunt"] = (["level":0, "points":0, "max": 10 ]);
            skills["projectile"] = (["level":0, "points":0, "max":10]);
            skills["flail"] = ([ "level": 0, "points": 0, "max": 8 ]);
            skills["blade"] = (["level":7, "points":0, "max":10 ]);
            skills["axe"] = (["level":0, "points":0, "max":1 ]);
            skills["two handed"] = (["level":0, "points":0, "max":10]);
            skills["murder"] = (["level":0, "points":0, "max":1 ]);
            skills["stealing"] = (["level":0, "points":0, "max":1 ]);
            skills["bargaining"] = (["level":0, "points":0, "max":1 ]);
            skills["locks"] = (["level":0, "points":0, "max":1 ]);
                break;
            default: init_skills(0);
        }
    }
    return skills;
}
int training_formula(string cl, string subcl, int lvl, string skill) {
    if(cl == "fighter") {
        switch(skill) {
            case "attack":
                return lvl * lvl/2; break;
            case "melee": case "defense": case "double wielding":
            case "two handed": case "blade": case "axe": case "projectile":
            case "riding": case "charging": case "blunt": 
            case "discipline": case "valor": case "ferocity":
                return lvl * lvl; break; 
            case "knife": case "bargaining": case "flail":
                return lvl * lvl * lvl; break;                    
            case "healing": case "magic attack": case "magic defense":
            case "faith": 
                if (subcl=="paladin"||
                    subcl=="antipaladin")
                 return lvl * lvl * lvl/2; break;
            case "rage":
              if (subcl=="berserker")
                return lvl * lvl/2; break;
            case "nature":
              if (subcl=="ranger")
                return lvl * lvl/2; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(subcl == "cleric") {
        switch(skill) {
            case "belief": 
                return lvl * lvl/2; break;
            case "magic defense": case "healing": case "defense": case "flail": 
                return lvl * lvl; break;
            case "melee": case "blunt": case "flail": case "conjuring":
            case "magic attack":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(subcl == "druid") {
        switch(skill) {
            case "nature": 
                return lvl * lvl/3; break;
            case "magic defense": case "faith": case "defense": case "flail": 
             case "magic attack":   
                return lvl * lvl; break;
            case "melee": case "knife": case "blunt": case "conjuring":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "mage") {
        switch(skill) {
            case "psionics":
           if (subcl=="sorceror")
                return lvl * lvl/3; break;
            case "necromancy":
           if (subcl=="necromancer")
                return lvl * lvl/3; break;
            case "wizardry":
           if (subcl=="wizard")
                return lvl * lvl/2; break;
            case "illusion":
           if (subcl=="illusionist")
                return lvl * lvl/3; break;
            case "pyromancy":
           if (subcl=="pyromancer")
                return lvl * lvl/3; break;
            case "conjuring":
           if (subcl=="conjurer") 
                 return lvl * lvl/3;
                else if (subcl !="conjurer")
                  return lvl * lvl; break;                 
            case "magic attack": case "magic defense": case "blunt": case "flail":
                return lvl * lvl; break;
            case "projectile": case "melee": case "attack": case "knife":
            case "bargaining":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(subcl == "kataan") {
        switch(skill) {
            case "faith":
              return lvl * lvl/2; break;
            case "projectile": case "attack": 
            case "magic attack": case "defense": case "summoning":
              return lvl * lvl; break;
            case "two handed": case "double wielding": case "murder":
            case "locks": case "stealth": case "magic defense": case "flail":
              return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(subcl == "monk") {
        switch(skill) {
            case "melee":
                return lvl * lvl/3; break;
            case "defense": case "projectile":
            case "bargaining":  case "faith": case "attack":
                return lvl * lvl; break;
            case "knife": case "conjuring": case "healing":
            case "magic defense": case "flail":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "wanderer") {
        switch(skill) {
            case "defense":
                return lvl * lvl/2; break;
            case "clairvoyance":
                if (subcl=="gypsy") {
                  return lvl * lvl/3; break; }
            case "euphony":
                if (subcl=="bard") {
                  return lvl * lvl/2; break; }
                if (subcl=="gypsy") {
                  return lvl * lvl * lvl * lvl * (lvl/4); break; }
                else
                if (subcl=="jester") {
                  return lvl * lvl * (lvl/2); break; }
            case "entertaining":
                if (subcl=="jester") {
                  return lvl * lvl/2; break; }
            case "bargaining":
                return lvl * lvl; break;             
            case "melee": case "attack": case "knife": case "blade":
            case "locks":
                return lvl * lvl * lvl/2; break;
            case "blunt": case "projectile": case "double wielding":
            case "murder":
                return lvl * lvl * lvl; break;
            case "blade":
                if (subcl=="swashbuckler") {
                  return lvl * lvl/3; break; }
            default: return lvl * lvl * lvl * lvl; break;
      }
   }
    else {
        switch(skill) {
            case "stealth":
                return lvl * lvl/2; break;             
            case "bargaining": case "attack": case "defense": case "knife":
            case "murder": case "stealing": case "locks": case "agility": 
                return lvl * lvl; break;
            case "two handed": case "melee":
              return lvl * lvl * lvl/2; break;
            case "blunt": case "projectile": case "double wielding":
                return lvl * lvl * lvl; break;
            
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
}
int query_melee_ac(string cl) {
    switch(cl) {
        case "wanderer": return 19; break; 
        case "fighter": return 20; break;
        case "rogue": return 18; break;
        case "clergy": 
           if (previous_object()->query_subclass()=="cleric")return 8;
           if (previous_object()->query_subclass()=="druid")return 8;
           if (previous_object()->query_subclass()=="kataan")return 10;
           if (previous_object()->query_subclass()=="monk")return 26;
          break;
        case "mage": return 6; break;
        default: return 1;
    }
}
