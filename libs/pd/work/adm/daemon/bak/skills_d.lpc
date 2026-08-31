//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993

mapping init_skills(string cl) {
    mapping skills;
    if(!skills) skills = ([]);
    if(!cl) {
        skills["melee"] = ([ "level": 1, "points": 0, "max": 1 ]);
        skills["attack"] = ([ "level":0, "points":0, "max":1 ]);
        skills["defense"] = ([]);
        skills["double wielding"] = ([]);
        skills["knife"] = ([]);
        skills["blunt"] = ([]);
        skills["projectile"] = ([]);
        skills["blade"] = ([]);
        skills["axe"] = ([]);
        skills["two handed"] = ([]);
        skills["murder"] = ([]);
        skills["stealing"] = ([]);
        skills["bargaining"] = ([]);
        skills["locks"] = ([]);

        skills["magic defense"] = ([]);
        skills["magic attack"] = ([]);
        skills["healing"] = ([]);
        skills["faith"] = ([]);
        skills["conjuring"] = ([]);

    }
    else {
        switch(cl) {
            case "fighter":
                
                skills["melee"] = ([ "level": 10, "points": 0, "max": 10 ]);
                skills["attack"] = ([ "level": 10, "points": 0, "max": 10]);
                skills["defense"] = ([ "level": 10, "points":0, "max": 10 ]);
                skills["double wielding"] = (["level": 3, "points":0, "max":10]);
                skills["knife"] = ([ "level": 1, "points":0, "max":10 ]);
                skills["blunt"] = (["level": 1, "points":0, "max": 10 ]);
                skills["projectile"] = (["level":0, "points":0, "max": 10  ]);
                skills["blade"] = (["level":10, "points":0, "max":10 ]);
                skills["axe"] = (["level":1, "points":0, "max":10 ]);
                skills["two handed"] = (["level":3, "points":0, "max":10 ]);
                skills["murder"] = (["level":0, "points":0, "max": 10 ]);
                skills["stealing"] = (["level":0, "points":0, "max": 10 ]);
                skills["bargaining"] = (["level":3, "points":0, "max":10 ]);
                skills["locks"] = (["level":0, "points":0, "max":2 ]);
                skills["stealth"] = ([ "level":0, "points":0, "max":10 ]);
                if (previous_object()->query_subclass()=="paladin"||
                    previous_object()->query_subclass()=="antipaladin") {
                skills["magic defense"] = (["level":7, "points":0, "max":10 ]);
                skills["magic attack"] = (["level":7, "points":0, "max":10 ]);
                skills["healing"] = (["level":7, "points":0, "max":10 ]);
                skills["faith"] = (["level":7, "points":0, "max":10 ]);
               }
                skills["charging"] = ([ "level": 1, "points": 0, "max": 10 ]);
                skills["riding"] = ([ "level": 1, "points": 0, "max": 10 ]);
                skills["rage"] = ([ "level":10, "points":0, "max":10 ]);

                if (previous_object()->query_subclass()=="ranger")   
                skills["nature"] = ([ "level": 7, "points": 0, "max": 10 ]);
                break;
            case "kataan":
                skills["melee"] = (["level":2, "points":0, "max":10]);
                skills["attack"]= (["level":2, "points":0, "max":10]);
                skills["defense"]= (["level":2, "points":0, "max":10]);
                skills["double wielding"]=(["level":3, "points":0, "max":10]);
                skills["knife"]=(["level":0, "points":0, "max":10]);
                skills["blunt"]=(["level":0, "points":0, "max":10]);
                skills["blade"]=(["level":1, "points":0, "max":10]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"]=(["level":1, "points":0, "max":10]);
                skills["projectile"]=(["level":7, "points":0, "max":10]);
                skills["bargaining"]=(["level":1, "points":0, "max":10]);
                skills["stealth"]=(["level":3, "points":0, "max":10]);
                skills["stealing"]=(["level":0, "points":0, "max":10]);
                skills["locks"]=(["level":6, "points":0, "max":10]);
                skills["murder"]=(["level":3, "points":0, "max":10]);
                skills["magic attack"]=(["level":3, "points":0, "max":10]);
                skills["faith"]=(["level":5, "points":0, "max":10]);
                skills["magic defense"]=(["level":1, "points":0, "max":3]);
                skills["summoning"]=(["level":7, "points":0, "max":10]);                
     /*         skills["healing"]=(["level":0, "points":0, "max":0]);    */
     /*         skills["conjuring"]=(["level":0, "points":0, "max":0]);  */
             
                break;
            case "rogue":
                skills["melee"] = (["level": 10, "points":0, "max": 10 ]);
                skills["attack"] = (["level": 10, "points":0, "max": 10 ]);
                skills["defense"] = (["level":10, "points":0, "max":10 ]);
                skills["double wielding"] = (["level":3, "points":0, "max":10 ]);
                skills["knife"] = (["level":10, "points":0, "max": 10 ]);
                skills["blunt"] = (["level":2, "points":0, "max":10 ]);
                skills["projectile"] = (["level":5, "points":0, "max":10]);
                skills["blade"] = (["level":0, "points":0, "max": 10]);
                skills["axe"] = (["level":0, "points":0, "max":10 ]);
                skills["two handed"] = (["level":0, "points":0, "max":10  ]);
                skills["murder"] = (["level":10, "points":0, "max":10 ]);
                skills["stealth"] = (["level":10, "points":0, "max":10 ]);
                skills["stealing"] = (["level":7, "points":0, "max":10 ]);
                skills["bargaining"] = (["level":7, "points":0, "max":10 ]);
                skills["locks"] = (["level":10, "points":0, "max":10 ]);
/*
                skills["magic defense"] = ([ "level": 0, "points":0, "max":0 ]);
                skills["magic attack"] = (["level":0, "points":0, "max":0 ]);
                skills["healing"] = (["level":0, "points":0, "max":0 ]);
                skills["faith"] = (["level":0, "points":0, "max":0 ]);
                skills["conjuring"] = (["level":0, "points":0, "max":0 ]);
*/
  if (previous_object()->query_subclass()=="bard" ||
      previous_object()->query_subclass()=="jester") 
                skills["entertaining"] = (["level":10, "points":0, "max":10 ]);
  if (previous_object()->query_subclass()=="bard")
                skills["euphony"] = ([ "level":10, "points":0, "max":10 ]);
  if (previous_object()->query_subclass() == "assassin" ||
      previous_object()->query_subclass() == "thief")
                skills["agility"] = ([ "level":10, "points":0, "max":10 ]);
                break;
            case "mage":
                skills["melee"] = (["level":1, "points":0, "max":5 ]);
                skills["attack"] = (["level":0, "points":0, "max": 5 ]);
                skills["defense"] = (["level":1, "points":0, "max":5 ]);
                skills["double wielding"] = (["level":0, "points":0, "max":1 ]);
                skills["knife"] = (["level":1, "points":0, "max":1 ]);
                skills["blunt"] = (["level":5, "points":0, "max":10 ]);
                skills["projectile"] = (["level":0, "points":0, "max":1  ]);
                skills["blade"] = (["level":0, "points":0, "max":1 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1  ]);
                skills["murder"] = (["level":0, "points":0, "max":5 ]);
                skills["stealing"] = (["level":0, "points":0, "max":1 ]);
                skills["bargaining"] = (["level":3, "points":0, "max":10  ]);
                skills["locks"] = (["level":0, "points":0, "max":1 ]);
                skills["magic defense"] = (["level" :10, "points":0, "max":10 ]);
                skills["magic attack"] = (["level": 10, "points": 0, "max":10 ]);
                skills["healing"] = (["level":10, "points":0, "max":10 ]);
                skills["faith"] = (["level":10, "points":0, "max":10 ]);
                skills["conjuring"] = (["level":10, "points":0, "max":10 ]);
                skills["psionics"] = (["level":10, "points":0, "max":10 ]);
                skills["nature"]   = (["level":10, "points":0, "max":10 ]);
                if (previous_object()->query_subclass()=="necromancer")
                skills["necromancy"]= (["level":10, "points":0, "max":10]);
                break;
            case "monk":
                skills["melee"] = (["level":10, "points":0, "max":10 ]);
                skills["attack"] = (["level":10, "points":0, "max":10 ]);
                skills["defense"] = (["level":10, "points":0, "max":10]);
                skills["double wielding"] = (["level":0, "points":0, "max":1 ]);
                skills["knife"] = (["level":0, "points":0, "max":5 ]);
                skills["blunt"] = (["level":3, "points":0, "max": 5 ]);
                skills["projectile"] = (["level":5, "points":0, "max":10 ]);
                skills["blade"] = (["level":0, "points":0, "max":3 ]);
                skills["axe"] = (["level":0, "points":0, "max":5 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1  ]);
                skills["murder"] = (["level":0, "points":0, "max":5 ]);
                skills["stealing"] = (["level":0, "points":0, "max":1 ]);
                skills["bargaining"] = (["level":1, "points":0, "max": 10 ]);
                skills["locks"] = (["level":0, "points":0, "max":1]);
                skills["magic defense"] = (["level":2, "points":0, "max":5 ]);
                skills["magic attack"] = (["level":2, "points":0, "max": 5 ]);
                skills["healing"] = (["level":5, "points":0, "max": 7 ]);
                skills["faith"] = (["level":10, "points":0, "max":10 ]);
                skills["conjuring"] = (["level":3, "points":0, "max": 5 ]);
                break;
            case "cleric":
                skills["melee"] = ([ "level": 1, "points":0, "max": 5 ]);
                skills["attack"] = ([ "level":0, "points":0, "max": 5 ]);
                skills["defense"] = ([ "level":1, "points":0, "max":5 ]);
                skills["double wielding"] = (["level":0, "points":0, "max": 1 ]);
                skills["knife"] = ([ "level":5, "points":0, "max":1 ]);
                skills["blunt"] = ([ "level":5, "points":0, "max":10 ]);
                skills["projectile"] = (["level":0, "points":0, "max": 0]);
                skills["blade"] = (["level":0, "points":0, "max":1 ]);
                skills["axe"] = (["level":0, "points":0, "max":1 ]);
                skills["two handed"] = (["level":0, "points":0, "max":1 ]);
                skills["murder"] = ([ "level":0, "points":0, "max":5 ]);
                skills["stealing"] = ([ "level":0, "points":0, "max":1 ]);
                skills["locks"] = (["level":0, "points":0, "max":0 ]);
                skills["bargaining"] = ([ "level":1, "points":0, "max": 10 ]);
                skills["magic defense"] = ([ "level":10, "points":0, "max": 10 ]);
                skills["magic attack"] = ([ "level":10, "points":0, "max": 10 ]);
                skills["healing"] = ([ "level":10, "points":0, "max":10 ]);
                skills["faith"] = (["level":10, "points":0, "max":10 ]);
                skills["conjuring"] = ([ "level":4, "points":0, "max":10  ]);
                skills["belief"] = ([ "level":10, "points":0, "max":10 ]);
                break;
            case "dragon":
                  skills["melee"] = (["level":10, "points":0, "max":10]);
                  skills["attack"] = (["level":10, "points":0, "max":10]);
                  skills["defense"] = (["level":20, "points":0, "max":10]);
                  skills["charging"] = (["level":5, "points":0, "max":5]);
                 skills["claw"] = (["level":5, "points":0, "max":10]);
                  skills["tail"] = (["level":7, "points":0, "max":10]);
                  skills["breath"] = (["level":5, "points":0, "max":10]);
                  skills["magic defense"] = (["level":5, "points":0, "max":8]);
                  skills["healing"] = (["level":5, "points":0, "max":5]);
                  skills["bargaining"] = (["level":5, "points":0, "max":10]);
                  skills["stealth"] = (["level":5, "points":0, "max":5]);
                  break;
            case "child": 
            skills["melee"] = (["level":7, "points":0, "max":10 ]);
            skills["attack"] = (["level":7, "points":0, "max":10 ]);
            skills["defense"] = (["level":7, "points":0, "max":10]);
            skills["double wielding"] = (["level":0, "points":0,"max":10]);  
            skills["knife"] = (["level":0, "points":0,"max":10 ]);
            skills["blunt"] = (["level":0, "points":0, "max": 10 ]);
            skills["projectile"] = (["level":0, "points":0, "max":10]);
            skills["blade"] = (["level":7, "points":0, "max":10 ]);
            skills["axe"] = (["level":0, "points":0, "max":1 ]);
            skills["two handed"] = (["level":0, "points":0, "max":10]);
            skills["murder"] = (["level":0, "points":0, "max":1 ]);
            skills["stealing"] = (["level":0, "points":0, "max":1 ]);
            skills["bargaining"] = (["level":0, "points":0, "max":1 ]);
            skills["locks"] = (["level":0, "points":0, "max":1 ]);
/*
            skills["magic defense"] = (["level":0, "points":0, "max":1]);
            skills["magic attack"] = (["level":0,"points":0, "max": 1 ]);
            skills["healing"] = (["level":0, "points":0, "max": 1 ]);
            skills["faith"] = (["level":0, "points":0, "max":1 ]);
            skills["conjuring"] = (["level":0, "points":0, "max": 1]);
*/
                break;
            default: init_skills(0);
        }
    }
    return skills;
}

int training_formula(string cl, int lvl, string skill) {
    if(cl == "fighter") {
        switch(skill) {
            case "charging":
              return lvl*lvl; break;
            case "riding": 
              return lvl*lvl; break;
            case "melee": case "attack": case "defense": case "double wielding":
            case "two handed": case "blade": case "rage": case "axe": 
            case "projectile": case "flail":
                return lvl * lvl; break;
            case "knife": case "blunt": case "bargaining": case "murder":
            case "stealing":
                return lvl * lvl * lvl; break;
                     
              case "healing": case "magic attack": case "magic defense":
              case "faith":  
                if (this_player()->query_subclass()=="paladin"||
                    this_player()->query_subclass()=="antipaladin")
                 return lvl * lvl * 8; break;

              case "nature":
                if (this_player()->query_subclass()=="ranger") 
                 return lvl * lvl * 7; break;

            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "cleric") {
        switch(skill) {
            case "magic defense": case "healing": case "faith": case "belief": 
                return lvl * lvl; break;
            case "melee": case "defense": case "knife": case "blunt": 
            case "conjuring":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "mage") {
        switch(skill) {
            case "magic attack": case "magic defense": case "conjuring": case "blunt":
            case "psionics": case "nature": case "necromancy": 
                return lvl * lvl; break;
            case "projectile": case "melee": case "attack": case "knife":
            case "bargaining":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "kataan") {
        switch(skill) {
            case "projectile": case "attack": case "faith":
            case "magic attack": case "defense": case "summoning":
              return lvl * lvl; break;
            case "two handed": case "double wielding": case "murder":
            case "locks": case "stealth":
              return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "monk") {
        switch(skill) {
            case "melee": case "defense": case "projectile":
            case "bargaining":  case "faith": case "attack":
                return lvl * lvl; break;
            case "knife": case "conjuring": case "healing": case "magic defense":
                return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "dragon") {
         switch(skill) {
          case "melee": case "defense": case "attack" : case "bargaining":
                 return lvl * lvl; break;
          case "breath": case "tail": case "claw": case "charging":
                  return lvl * lvl * lvl; break;
          default: return lvl * lvl * lvl * lvl; break;
        }
    }
 
else {
        switch(skill) {
            case "stealth": case "melee": case "attack": case "defense": case "knife":
            case "bargaining": case "murder": case "stealing": case "locks":
                return lvl * lvl; break;
            case "blunt": case "projectile": case "double wielding":
                return lvl * lvl * lvl; break;
            case "euphony":  case "agility": case "entertain":
              return lvl*lvl*lvl/2;
            
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
}

int query_melee_ac(string cl) {
    switch(cl) {
        case "fighter": return 15; break;
        case "monk": return 20; break;
        case "kataan": return 11; break;
        case "rogue": return 20; break;
        case "cleric": return 5; break;
        case "mage": return 8; break;
        case "dragon" : return 20; break;
        default: return 1;
    }
}

