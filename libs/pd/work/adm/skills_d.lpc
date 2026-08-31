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
  string subcl;
  string race;
  
  if(!skills) skills = ([]);
  
  if(!cl) {
    skills["melee"] =  ([ "level":0, "points":0, "max":1 ]);
    skills["attack"] = ([ "level":0, "points":0, "max":1 ]);
    skills["defense"] = ([]);
    skills["double wielding"] = ([]);
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
    skills["breath"] = ([]);
    skills["claw"] = ([]);
    skills["tail"] = ([]);
    skills["flying"] = ([]);
    skills["perception"] = ([]);
    skills["ranged"] = ([]);
  }
  
  else {

    subcl=previous_object()->query_subclass();
    race=previous_object()->query_race();
    
    if (member_array(race, ({"archangel", "demon"}) ) != -1)
      skills["flying"] = (["level": 3, "points":0, "max":6 ]);

    switch(cl) {

      case "fighter":                
      skills["melee"] = ([ "level": 4, "points": 0, "max": 8 ]);
      skills["attack"] = ([ "level": 6, "points": 0, "max": 12]);
      skills["defense"] = ([ "level": 5, "points":0, "max": 10 ]);
      skills["double wielding"] = (["level": 5, "points":0, "max": 10]);
      skills["knife"] = ([ "level": 3, "points":0, "max": 6 ]);
      skills["blunt"] = (["level": 3, "points":0, "max": 6 ]);
      skills["projectile"] = (["level":3, "points":0, "max": 6  ]);
      skills["flail"] = ([ "level": 3, "points": 0, "max": 6 ]);
      skills["blade"] = (["level": 5, "points":0, "max": 10 ]);
      skills["axe"] = (["level": 3, "points":0, "max": 6 ]);
      skills["ranged"] = (["level": 3, "points":0, "max": 6 ]);
      skills["perception"] = (["level":4, "points":0, "max": 8 ]);
      skills["bargaining"] = (["level":3, "points":0, "max":7 ]);

      switch (subcl) {

        case "paladin":
        skills["magic defense"] = (["level":4, "points":0, "max":8 ]);
        skills["magic attack"] = (["level":3, "points":0, "max":6 ]);
        skills["healing"] = (["level":3, "points":0, "max":6 ]);
        skills["faith"] = (["level":4, "points":0, "max":8 ]);
        skills["valor"] = ([ "level":5, "points":0, "max":12 ]);
        skills["blunt"] = ([ "level":5, "points":0, "max":10 ]);
        skills["projectile"] = ([ "level":5, "points":0, "max":10 ]);
        break;

        case "antipaladin":
        skills["magic defense"] = (["level":4, "points":0, "max":8 ]);
        skills["magic attack"] = (["level":4, "points":0, "max":8 ]);
        skills["healing"] = (["level":2, "points":0, "max":4 ]);
        skills["faith"] = (["level":4, "points":0, "max":8 ]);   
        skills["ferocity"] = ([ "level": 5, "points": 0, "max": 12 ]);
        skills["knife"] = ([ "level":5, "points":0, "max":10 ]);
        skills["flail"] = ([ "level":5, "points":0, "max":10 ]);
        break;
       
        case "berserker":
        skills["rage"] = ([ "level":6, "points":0, "max":12 ]);
        skills["melee"] = ([ "level": 6, "points": 0, "max": 12 ]);   
        skills["ferocity"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["double wielding"] = ([ "level": 4, "points": 0, "max": 8 ]);
        skills["axe"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["blunt"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["perception"] = ([ "level": 3, "points": 0, "max": 6 ]);
        break;
        
        case "ranger":
        skills["nature"] = ([ "level": 5, "points": 0, "max": 11 ]);
        skills["discipline"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["ranged"] = (["level":6, "points":0, "max":12 ]);
        skills["stealth"] = ([ "level":0, "points":0, "max":6 ]);
        skills["melee"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["projectile"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["perception"] = ([ "level": 5, "points": 0, "max": 10 ]);
        break;
        
        case "warrior":
        skills["discipline"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["double wielding"] = (["level": 6, "points":0, "max":12]);
        skills["knife"] = ([ "level": 6, "points":0, "max":12 ]);
        skills["blunt"] = (["level": 6, "points":0, "max": 12 ]);
        skills["projectile"] = (["level":6, "points":0, "max": 12  ]);
        skills["flail"] = ([ "level": 6, "points": 0, "max": 12 ]);
        skills["blade"] = (["level":6, "points":0, "max":12 ]);
        skills["axe"] = (["level":6, "points":0, "max":12 ]);
        skills["ranged"] = (["level":4, "points":0, "max":8 ]);
        break;

      } // end of fighter subclass switch()

      if (member_array(race, ({"centaur","weimic","raknid"}) ) != -1)
        skills["charging"] = ([ "level": 5, "points": 0, "max": 10 ]);
      else
        skills["riding"] = ([ "level": 5, "points": 0, "max": 10 ]);

      break; // end of fighter case


      case "rogue":
      skills["melee"] = (["level": 3, "points":0, "max": 7 ]);
      skills["attack"] = (["level": 5, "points":0, "max": 10 ]);
      skills["defense"] = (["level":4, "points":0, "max":8 ]);
      skills["double wielding"] = (["level":3, "points":0, "max":10 ]);
      skills["knife"] = (["level":5, "points":0, "max": 10 ]);
      skills["blunt"] = (["level":2, "points":0, "max":6 ]);
      skills["projectile"] = (["level":0, "points":0, "max":4]);
      skills["flail"] = ([ "level": 0, "points": 0, "max": 4 ]);
      skills["blade"] = (["level":0, "points":0, "max": 6]);
      skills["axe"] = (["level":0, "points":0, "max":2 ]);
      skills["ranged"] = (["level":0, "points":0, "max":4  ]);
      skills["perception"] = (["level":4, "points":0, "max": 8 ]);
      skills["bargaining"] = (["level":5, "points":0, "max":10 ]);
      skills["agility"] = (["level":5, "points":0, "max":10 ]);
      
      switch (subcl) {
        
        case "assassin":
        skills["murder"] = (["level":6, "points":0, "max":12 ]);
        skills["stealth"] = (["level":5, "points":0, "max":10 ]);
        skills["stealing"] = (["level":3, "points":0, "max":6 ]);
        skills["locks"] = (["level":4, "points":0, "max":8 ]);
        skills["agility"] = (["level":6, "points":0, "max":12 ]);
        skills["ranged"] = (["level":0, "points":0, "max":8  ]);
        break;
        
        case "thief":
        skills["attack"] = (["level":4, "points":0, "max":8 ]);
        skills["murder"] = (["level":3, "points":0, "max":6 ]);
        skills["stealth"] = (["level":5, "points":0, "max":10 ]);
        skills["stealing"] = (["level":6, "points":0, "max":12 ]);
        skills["perception"] = (["level":5, "points":0, "max":10 ]);
        skills["locks"] = (["level":6, "points":0, "max":12 ]);
        break;
        
        case "thug":
        skills["murder"] = (["level":5, "points":0, "max":10 ]);
        skills["stealth"] = (["level":4, "points":0, "max":8 ]);
        skills["stealing"] = (["level":4, "points":0, "max":8 ]);
        skills["bargaining"] = (["level":6, "points":0, "max":12 ]);
        skills["locks"] = (["level":3, "points":0, "max":6 ]);
        skills["agility"] = (["level":3, "points":0, "max":6 ]);
        skills["melee"] = (["level":6, "points":0, "max":12 ]);
        skills["blunt"] = (["level":5, "points":0, "max":10 ]);
        skills["double wielding"] = (["level":3, "points":0, "max":8 ]);
        break;
        
        case "scout":
        skills["murder"] = (["level":2, "points":0, "max":4 ]);
        skills["stealth"] = (["level":6, "points":0, "max":12 ]);
        skills["stealing"] = (["level":2, "points":0, "max":4 ]);
        skills["bargaining"] = (["level":5, "points":0, "max":10 ]);
        skills["locks"] = (["level":2, "points":0, "max":4 ]);
        skills["double wielding"] = (["level": 6, "points":0, "max":12]);
        skills["perception"] = (["level": 6, "points":0, "max":12]);
        skills["knife"] = (["level": 6, "points":0, "max":12]);
        break;

      } // end of rogue subclass switch()
      
      break; // end of rogue case

      
      case "wanderer":
      skills["melee"] = (["level": 2, "points":0, "max": 5 ]);
      skills["attack"] = (["level": 4, "points":0, "max": 8 ]);
      skills["defense"] = (["level":5, "points":0, "max": 10 ]);
      skills["blade"] = (["level":3, "points":0, "max": 6]);
      skills["double wielding"] = (["level":2, "points":0, "max":5 ]);
      skills["knife"] = (["level":5, "points":0, "max": 10 ]);
      skills["blunt"] = (["level":4, "points":0, "max":8 ]);
      skills["projectile"] = (["level":1, "points":0, "max":2]);
      skills["flail"] = ([ "level": 0, "points": 0, "max": 4 ]);
      skills["axe"] = (["level":0, "points":0, "max":4 ]);
      skills["ranged"] = (["level":0, "points":0, "max":2 ]);
      skills["bargaining"] = (["level":5, "points":0, "max":10 ]);
      skills["perception"] = (["level":5, "points":0, "max":10 ]);

      switch (subcl) {
        
        case "gypsy":
        skills["defense"] = (["level": 4, "points":0, "max": 9 ]);
        skills["double wielding"] = (["level": 3, "points":0, "max": 7 ]);
        skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
        skills["blunt"] = ([ "level": 5, "points": 0, "max": 10 ]);
        skills["entertainment"] = (["level":5, "points":0, "max":10 ]);
        skills["clairvoyance"] = (["level":6, "points":0, "max":12 ]);
        skills["euphony"] = ([ "level":3, "points":0, "max":6 ]);
        skills["stealth"] = (["level":3, "points":0, "max":6 ]);
        skills["stealing"] = (["level":3, "points":0, "max":6 ]);
        break;
        
        case "jester":
        skills["entertainment"] = (["level":6, "points":0, "max":12 ]);
        skills["euphony"] = ([ "level":3, "points":0, "max":6 ]);
        skills["stealth"] = (["level":0, "points":0, "max":8 ]);
        skills["perception"] = ([ "level":3, "points":0, "max":6 ]);
        skills["blunt"] = (["level":6, "points":0, "max":12 ]);
        break;
        
        case "bard":
        skills["entertainment"] = (["level":4, "points":0, "max":8 ]);
        skills["euphony"] = ([ "level":6, "points":0, "max":12 ]);
        skills["attack"] = (["level": 3, "points":0, "max": 6 ]);
        skills["knife"] = (["level":3, "points":0, "max": 6 ]);
        break;
        
        case "swashbuckler":
        skills["entertainment"] = (["level":3, "points":0, "max":6 ]);
        skills["blade"] = (["level":6, "points":0, "max":12 ]);
        skills["euphony"] = ([ "level":3, "points":0, "max":6 ]);
        skills["attack"] = (["level": 4, "points":0, "max": 9 ]);
        skills["riding"] = ([ "level": 4, "points": 0, "max": 8 ]);
        skills["knife"] = ([ "level": 3, "points": 0, "max": 6 ]);
        skills["double wielding"] = (["level":4, "points":0, "max":10 ]);
        skills["perception"] = ([ "level": 4, "points": 0, "max": 8 ]);
        break;

      } // end of wanderer subclass switch()

      break; // end of wanderer case


      case "mage":
      skills["melee"] = (["level":1, "points":0, "max":5 ]);
      skills["attack"] = (["level":0, "points":0, "max": 5 ]);
      skills["defense"] = (["level":1, "points":0, "max":5 ]);
      skills["double wielding"] = (["level":0, "points":0, "max":2 ]);
      skills["knife"] = (["level":0, "points":0, "max":6 ]);
      skills["blunt"] = (["level":5, "points":0, "max":10 ]);
      skills["projectile"] = (["level":0, "points":0, "max":2  ]);
      skills["flail"] = ([ "level": 0, "points": 0, "max": 6 ]);
      skills["blade"] = (["level":0, "points":0, "max":2 ]);
      skills["axe"] = (["level":0, "points":0, "max":2 ]);
      skills["ranged"] = (["level":0, "points":0, "max":2 ]);
      skills["bargaining"] = (["level":3, "points":0, "max":6  ]);
      skills["perception"] = (["level":4, "points":0, "max": 8 ]);
      
      switch (subcl) {
        
        case "sorceror":
        skills["magic defense"] = (["level" :4, "points":0, "max":8 ]);
        skills["magic attack"] = (["level": 6, "points": 0, "max":12 ]);
        skills["conjuring"] = (["level":4, "points":0, "max":8 ]);
        skills["psionics"] = (["level":6, "points":0, "max":12 ]);
        break;
        
        case "necromancer":
        skills["magic defense"] = (["level" :4, "points":0, "max":8 ]);
        skills["magic attack"] = (["level": 6, "points": 0, "max":12 ]);
        skills["conjuring"] = (["level":4, "points":0, "max":9 ]);
        skills["necromancy"] = (["level":6, "points":0, "max":12]);
        break;
        
        case "pyromancer":
        skills["magic defense"] = (["level" :4, "points":0, "max":8]);
        skills["magic attack"] = (["level": 5, "points": 0, "max":11 ]);
        skills["conjuring"] = (["level":4, "points":0, "max":8 ]);
        skills["pyromancy"] = (["level":6, "points":0, "max":12]);
        break;
        
        case "wizard":
        skills["magic defense"] = (["level" :4, "points":0, "max":8 ]);
        skills["magic attack"] = (["level": 5, "points": 0, "max":10 ]);
        skills["conjuring"] = (["level":4, "points":0, "max":9 ]);
        skills["wizardry"] = (["level":6, "points":0, "max":12]);
        break;

      } // end of mage subclass switch()
      
      break; // end of mage case


      case "clergy":
      skills["melee"] = (["level":3, "points":0, "max":6 ]);
      skills["attack"] = (["level":4, "points":0, "max":8 ]);
      skills["defense"] = (["level":4, "points":0, "max":8]);
      skills["double wielding"] = (["level":0, "points":0,"max":6]);  
      skills["knife"] = (["level":0, "points":0,"max":6 ]);
      skills["blunt"] = (["level":0, "points":0, "max": 8 ]);
      skills["projectile"] = (["level":0, "points":0, "max":6]);
      skills["flail"] = ([ "level": 4, "points": 0, "max": 8 ]);
      skills["blade"] = (["level":3, "points":0, "max":6 ]);
      skills["axe"] = (["level":0, "points":0, "max":2 ]);
      skills["ranged"] = (["level":0, "points":0, "max":2 ]);
      skills["bargaining"] = (["level":0, "points":0, "max":5 ]);
      skills["perception"] = (["level":4, "points":0, "max": 8 ]);
      skills["faith"]=(["level":6, "points":0, "max":12]);

      switch (subcl) {

        case "monk":
        skills["melee"] = (["level":6, "points":0, "max":12 ]);
        skills["attack"] = (["level":5, "points":0, "max":10 ]);
        skills["defense"] = (["level":5, "points":0, "max":10]);
        skills["projectile"] = (["level":5, "points":0, "max":10 ]);
        skills["magic defense"] = (["level":3, "points":0, "max":6 ]);
        skills["magic attack"] = (["level":3, "points":0, "max": 6 ]);
        skills["healing"] = (["level":2, "points":0, "max": 5 ]);
        break;
        
        case "cleric":
        skills["flail"] = ([ "level":5, "points":0, "max":10 ]);
        skills["magic defense"] = ([ "level": 5, "points":0, "max": 10 ]);
        skills["healing"] = ([ "level":6, "points":0, "max":12 ]);
        skills["conjuring"] = ([ "level":3, "points":0, "max":6  ]);
        skills["belief"] = ([ "level":6, "points":0, "max":12 ]);
        break;
        
        case "kataan":
        skills["double wielding"]=(["level":2, "points":0, "max":4]);
        skills["projectile"]=(["level":6, "points":0, "max":12]);
        skills["stealth"]=(["level":0, "points":0, "max":6]);
        skills["magic attack"]=(["level":3, "points":0, "max":10]);
        skills["magic defense"]=(["level":1, "points":0, "max":3]);
        skills["summoning"]=(["level":6, "points":0, "max":12]);
        skills["blade"]=(["level":0, "points":0, "max":4]);
        skills["blunt"]=(["level":0, "points":0, "max":4]);
        skills["knife"]=(["level":0, "points":0, "max":4]);
        break;
        
        case "druid":
        skills["blunt"] = (["level":5, "points":0, "max":10 ]);
        skills["magic defense"] = (["level" :6, "points":0, "max":12 ]);
        skills["magic attack"] = (["level": 4, "points": 0, "max":8 ]);
        skills["conjuring"] = (["level":3, "points":0, "max":6 ]);
        skills["nature"] = (["level":6, "points":0, "max":12 ]);
        skills["melee"] = (["level":0, "points":0, "max":8 ]);
        break;

      } // end of clergy subclass switch()
      
      break; // end of clergy case


      case "dragon":
      skills["melee"] = (["level": 5, "points":0, "max": 10 ]);
      skills["attack"] = (["level": 4, "points":0, "max": 9 ]);
      skills["defense"] = (["level": 6, "points":0, "max": 12 ]);
      skills["bargaining"] = (["level": 2, "points":0, "max":5 ]);
      skills["breath"] = (["level": 5, "points":0, "max":10 ]);
      skills["claw"] = (["level": 5, "points":0, "max":10 ]);
      skills["tail"] = (["level": 5, "points":0, "max":10 ]);
      skills["flying"] = (["level": 3, "points":0, "max":7 ]);
      skills["perception"] = (["level":4, "points":0, "max": 8 ]);

      switch (subcl) {

        case "black":
        skills["magic attack"] = (["level": 5, "points":0, "max": 10 ]);
        skills["magic defense"] = (["level": 3, "points":0, "max": 6 ]);
        skills["conjuring"] = (["level": 3, "points":0, "max": 6 ]);
        skills["wizardry"] = (["level": 5, "points":0, "max": 10 ]);
        break;
        
        case "red":
        skills["attack"] = (["level": 5, "points":0, "max": 11 ]);
        skills["breath"] = (["level": 5, "points":0, "max": 10 ]);
        skills["claw"] = (["level": 4, "points":0, "max": 9 ]);
        skills["tail"] = (["level": 4, "points":0, "max": 9 ]);
        skills["defense"] = (["level": 6, "points":0, "max": 13 ]);
        skills["melee"] = (["level": 6, "points":0, "max": 11 ]);
        break;
        
        case "white":
        skills["magic attack"] = (["level": 3, "points":0, "max": 6 ]);
        skills["magic defense"] = (["level": 4, "points":0, "max": 8 ]);
        skills["conjuring"] = (["level": 3, "points":0, "max": 7 ]);
        skills["faith"] = (["level": 5, "points":0, "max": 10 ]);
        break;
        
        case "blue":
        skills["faith"] = (["level":4, "points":0, "max": 10 ]);
        skills["magic defense"] = (["level":4, "points":0, "max": 8 ]);
        skills["healing"] = (["level":4, "points":0, "max": 8 ]);
        skills["conjuring"] = (["level":3, "points":0, "max": 6 ]);
        skills["flying"] = (["level": 2, "points":0, "max": 4 ]);
        break;

      } // end of dragon subclass switch()
      
      break; // end of dragon case


      case "vampire":
      skills["melee"] = (["level": 5, "points":0, "max": 10 ]);
      skills["attack"] = (["level": 4, "points":0, "max": 9 ]);
      skills["defense"] = (["level": 5, "points":0, "max": 11 ]);
      skills["blunt"] = (["level":2, "points":0, "max":10 ]);
      skills["projectile"] = (["level":0, "points":0, "max":2  ]);
      skills["flail"] = ([ "level": 1, "points": 0, "max": 4 ]);
      skills["blade"] = (["level":0, "points":0, "max":2 ]);
      skills["perception"] = (["level":6, "points":0, "max":12 ]);
      skills["bargaining"] = (["level": 2, "points":0, "max":5 ]);
      skills["death"] = (["level":2, "points":0, "max": 8 ]);
      skills["murder"] = (["level":1, "points":0, "max": 4 ]);
      skills["illusion"] = (["level":0, "points":0, "max": 8 ]);
      skills["nature"] = (["level":0, "points":0, "max": 5 ]);
      skills["knife"] = (["level":2, "points":0, "max": 5 ]);
      skills["axe"] = (["level":1, "points":0, "max": 4 ]);
      break;


      case "child": 
      skills["melee"] = (["level":1, "points":0, "max":8 ]);
      skills["attack"] = (["level":1, "points":0, "max":8 ]);
      skills["defense"] = (["level":1, "points":0, "max":8]);
      skills["double wielding"] = (["level":0, "points":0,"max":8]);  
      skills["knife"] = (["level":0, "points":0,"max":8 ]);
      skills["blunt"] = (["level":0, "points":0, "max": 8 ]);
      skills["projectile"] = (["level":0, "points":0, "max":8]);
      skills["flail"] = ([ "level": 0, "points": 0, "max": 8 ]);
      skills["blade"] = (["level":1, "points":0, "max":8 ]);
      skills["axe"] = (["level":0, "points":0, "max":2 ]);
      skills["ranged"] = (["level":0, "points":0, "max":8]);

      skills["perception"] = (["level":2, "points":0, "max": 4 ]);
      skills["bargaining"] = (["level":0, "points":0, "max":2 ]);
      break;

      
      default: init_skills(0);

    } // end of class switch()
    
  } // end of else

  return skills;
}

int training_formula(string cl, string subcl, int lvl, string skill) {
  int expo;
  int mult;
  string race=previous_object()->query_race();
  
  if (member_array(race, ({"archangel","demon"}) ) != -1) {
    switch(skill) {
      case "flying":
        return lvl * lvl * 3;
      default:
    }
  }
  else if (!lvl || !skill)
    return 0;

  switch (cl) {

    case "fighter":
    switch (subcl) {
      
      case "antipaladin":
      switch(skill) {
        case "attack":
        case "ferocity": case "faith":
        case "blade":
            return lvl * lvl;
        case "flail": case "knife":
            return lvl * lvl * 2;
        case "riding": case "charging":
        case "magic attack": case "magic defense":
            return lvl * lvl * 3;
        case "axe": case "projectile": case "blunt":
        case "ranged":
        case "healing":
        case "bargaining": case "perception":
            return lvl * lvl * 4;
        default:
      } // end antipaladin skill switch
      break;

      case "paladin":
      switch(skill) {
        case "attack":
        case "valor": case "faith":
        case "blade":
            return lvl * lvl;
        case "blunt": case "projectile":
            return lvl * lvl * 2;
        case "riding": case "charging":
        case "healing": case "magic defense":
            return lvl * lvl * 3;
        case "knife": case "flail": case "axe": 
        case "ranged":
        case "magic attack":
        case "bargaining": case "perception":
            return lvl * lvl * 4;
        default:
      } // end paladin skill switch
      break;

      case "berserker":
      switch(skill) {
        case "rage": case "ferocity":
            return lvl * lvl/2;
        case "melee": case "blade": case "axe":
            return lvl * lvl;
        case "defense": case "double wielding":
            return lvl * lvl * 3;
        default:
      } // end berserker skill switch
      break;

      case "ranger":
      switch(skill) {
        case "nature": case "discipline": case "ranged": 
            return lvl * lvl/2;
        case "blade": case "projectile":
        case "melee":
        case "riding": 
        case "perception":
            return lvl * lvl;
        case "stealth":
            return lvl * lvl * 3;
        default:
      } // end ranger skill switch
      break;
      
      case "warrior":
      switch(skill) {
        case "knife": case "flail": case "axe": case "blade":
        case "projectile": case "blunt": case "knife":
            return lvl * lvl/2;
        case "discipline":
        case "ranged":
            return lvl * lvl;
        default:
      } // end warrior skill switch
      break;
      
    } // end fighter subclass switch

    switch (skill) {    
      case "attack":
          return lvl * lvl/2;
      case "riding": case "charging":
      case "double wielding":
      case "defense":
          return lvl * lvl;
      case "axe": case "blade": case "projectile":
      case "blunt": case "knife": case "flail":
      case "ranged":
      case "melee":
          return lvl * lvl * 2;
      case "bargaining":
      case "perception":
          return lvl * lvl * 3;
      default:
          return lvl * lvl * lvl;
    } // end default fighter skill costs switch

    // end fighter class case
    break;


    case "clergy":
    switch (subcl) {  

      case "cleric":
      switch(skill) {
        case "belief": 
            return lvl * lvl/2;
        case "healing":
            return lvl * lvl;
        default:
      } // end cleric skill switch
      break;

      case "druid":
      switch(skill) {
        case "nature": 
            return lvl * lvl/3;
        case "faith": 
            return lvl * lvl/2;
        case "melee": 
            return lvl * lvl * 4;
        default:
      } // end druid skill switch
      break;

      case "kataan":
      switch(skill) {
        case "projectile":  
        case "summoning":
          return lvl * lvl;
        case "attack": 
          return lvl * lvl * 3/2;
        case "double wielding":
        case "stealth":
          return lvl * lvl * 5;
        case "magic defense":
        case "bargaining":
          return lvl * lvl * 8;
        default:
      } // end kataan skill switch
      break;

      case "monk":
      switch(skill) {
        case "melee":
        case "projectile":
        case "attack":
            return lvl * lvl;
        case "healing":
            return lvl * lvl * 6;
        default:
      } // end monk skill switch
      break;
      
    } // end clergy subclass switch

    switch(skill) {
      case "faith":  
      case "magic defense":
      case "defense":
          return lvl * lvl;
      case "magic attack":
      case "flail": case "blunt":
          return lvl * lvl * 2;
      case "attack":
          return lvl * lvl * 3;
      case "bargaining":
      case "perception":
          return lvl * lvl * 4;
      case "knife": case "conjuring":
          return lvl * lvl * 8;
      default:
          return lvl * lvl * lvl;
    } // end clergy default skill costs switch

    // end clergy class case 
    break;
 

    case "mage":
    switch (subcl) {

      case "necromancer":
      switch(skill) {
        case "necromancy":
          return lvl * lvl/3;
        default:
      } // end necro skills switch
      break;

      case "sorceror":
      switch(skill) {
        case "psionics":
          return lvl * lvl/3;
        default:
      } // end sorc skills switch
      break;

      case "pyromancer":
      switch(skill) {
        case "pyromancy":
          return lvl * lvl/3;
        default:
      } // end pyro skills switch
      break;

      case "wizard":
      switch(skill) {
        case "wizardry":
          return lvl * lvl/3;
        default:
      } // end wizard skills switch
      break;

    } // end mage subclasses switch

    switch(skill) {
       case "conjuring": case "magic attack": case "magic defense":
         return lvl * lvl;
       case "perception":
         return lvl * lvl * 3;
       case "knife": case "blunt": case "flail":
         return lvl * lvl * 4;
       case "attack":
       case "bargaining":
         return lvl * lvl * 8;
       default:
         return lvl * lvl * lvl;
    } // end mage default costs switch

    // end mage class case
    break;


    case "wanderer":
    switch (subcl) {
 
      case "bard":
      switch(skill) {
        case "euphony":
        case "bargaining":
        case "perception":
          return lvl * lvl/3;
        case "attack":
          return lvl * lvl * 2;
        default:
      } // end bard skills switch
      break;
      
      case "jester":
      switch(skill) {
        case "entertainment": case "blunt":
          return lvl * lvl/3;
        case "blade":
        case "stealth":
          return lvl * lvl * 4;
        default:
      } // end jester skills switch
      break;
      
      case "gypsy":
      switch(skill) {
        case "clairvoyance":
          return lvl * lvl/3;
        case "knife":
          return lvl * lvl;
        case "flail":
          return lvl * lvl * 2;
        case "blade":
        case "stealth": case "stealing":
          return lvl * lvl * 4;
        default:
      } // end gypsy skills switch
      break;
      
      case "swashbuckler":
      switch(skill) {
        case "entertainment": case "blade":
          return lvl * lvl/3;
        case "attack":
            return lvl * lvl/2;
        case "double wielding":
        case "riding":
            return lvl * lvl * 4;
        default:
      } // end swash skills switch
      break;
      
    } // end wanderer subclasses switch

    switch(skill) {
      case "defense":
          return lvl * lvl/3;
      case "bargaining":
      case "attack":
      case "euphony":
      case "entertainment":
          return lvl * lvl;
      case "blunt": case "knife": case "blade":
          return lvl * lvl * 2;
      case "melee":
          return lvl * lvl * 4;
      case "perception":
          return lvl * lvl * 5;
      case "double wielding":
          return lvl * lvl * 7;
      default:
          return lvl * lvl * lvl;
    } // end wanderer default costs switch

    // end wanderer class case
    break;
 

    case "rogue":
    switch (subcl) {

      case "assassin":
      switch(skill) {
        case "ranged":
        case "stealing":
        case "double wielding":
            return lvl * lvl * 2;
        default:
      } // end assassin skills switch
      break;

      case "scout":
      switch(skill) {
        case "knife": case "double wielding": case "perception":
            return lvl * lvl/3;
        case "murder":
            return lvl * lvl * 2;
        case "stealing": case "locks":
            return lvl * lvl * 6;
        default:
      } // end scout skills switch
      break;

      case "thief":
      switch(skill) {
        case "stealing":
            return lvl * lvl/3;
        case "agility":
            return lvl * lvl * 3;
        case "murder": case "attack":
            return lvl * lvl * 4;
        default:
      } // end thief skills switch
      break;

      case "thug":
      switch(skill) {
        case "melee":
            return lvl * lvl/2;
        case "blunt":
            return lvl * lvl;
        case "agility":
            return lvl * lvl * 10;
        default:
      } // end thug skills switch
      break;

    } // end rogue subclasses switch

    switch(skill) {
      case "stealth":
      case "murder": 
          return lvl * lvl/2;
      case "bargaining":
      case "attack":
      case "knife":
      case "locks":
      case "stealing":
          return lvl * lvl;
      case "defense":
          return lvl * lvl * 2;
      case "melee":
      case "double wielding":
      case "perception":
        return lvl * lvl * 4;
      case "blunt": case "blade":
      case "agility": 
          return lvl * lvl * 8;
      default:
          return lvl * lvl * lvl;
    } // end rogue default costs switch
    
    //end rogue class case
    break;


    case "dragon":
    switch (subcl) {

      case "black":
      switch(skill) {
        case "magic attack": case "wizardry":
            return lvl * lvl/3;
        case "magic defense": case "conjuring":
            return lvl * lvl;
        default:
      } // end black skills switch
      break;

      case "white":
      switch(skill) {
        case "faith": case "magic defense":
            return lvl * lvl/3;
        case "magic attack": case "conjuring":
            return lvl * lvl;
        default:
      } // end white skills switch
      break;

      case "blue":
      switch(skill) {
        case "faith": case "magic defense":
            return lvl * lvl/3;
        case "conjuring": case "healing":
            return lvl * lvl;
        case "flying":
            return lvl * lvl * 8;
        default:
      } // end blue skills switch
      break;

      case "red":
      switch (skill) {
        case "attack": case "defense": case "melee":
            return lvl * lvl/3;
        case "claw": case "tail": case "breath":
            return lvl * lvl;
        default:
      } // end red skills switch
      break;

    } // end dragon subclass switch
    
    switch(skill) {
      case "flying":
          return lvl * lvl;
      case "attack": case "defense": case "melee":
      case "claw": case "tail": case "breath":
          return lvl * lvl * 3;
      case "perception":
          return lvl * lvl * 5;
      case "bargaining":
          return lvl * lvl * 8;
      default:
          return lvl * lvl * lvl;
    } // end dragon default costs switch

    // end dragon class case
    break;
 
    case "vampire":
    switch (skill) {
      case "death":
      case "illusion":
        return lvl * lvl/2;
      case "attack":
      case "melee":
      case "perception":
        return lvl * lvl;
      case "defense":
      case "flying":
        return lvl * lvl * 2;
      case "blade": case "knife": case "flail":
      case "projectile": case "axe": case "blunt":
      case "ranged":
      case "bargaining":
        return lvl * lvl * 3;
      default:
        return lvl * lvl * lvl;
    }

    // end vampire class case
    break; 

    default:
      return lvl*lvl*lvl*lvl;
  } // end class switch

  // should never get here
  return 0;
}

int query_melee_ac(string cl) {
    switch(cl) {
        case "wanderer": return 19;
        case "fighter": return 20;
        case "rogue": return 18;
        case "dragon":
           if (previous_object()->query_subclass()=="red")return 21;
           return 18;
           break;
        case "clergy": 
           if (previous_object()->query_subclass()=="cleric")return 8;
           if (previous_object()->query_subclass()=="druid")return 8;
           if (previous_object()->query_subclass()=="kataan")return 10;
           if (previous_object()->query_subclass()=="monk")return 26;
          break;
        case "mage": return 6;
        case "vampire": return 20;
        default: return 1;
    }
    return 0; // should never get here
}

