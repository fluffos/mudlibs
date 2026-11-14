#include <mudlib.h>
inherit GUILD;

object staff;

void reset(status arg) {
    if(!guild_master) {
     guild_master = clone_object("inherit/monster");
     move_object(guild_master,this_object());
     guild_master->set_name("tesmond");
     guild_master->set_short("Tesmond of the Ways");
     guild_master->set_long(
          "Tesmond is a small man. He looks quite ancient,\n"+
          "yet his eyes are forever young. He carries\n"+
          "himself with a quiet dignity, showing that he\n"+
          "is wise and purposeful.\n");
     guild_master->set_gender(1);
     guild_master->set_race("human");
     guild_master->set_level(100);
     guild_master->add_class("fighter");
     guild_master->load_a_chat(25,({ 
     "Tesmond says: I am the greatest fighter "+
         "who has ever lived.\n",
         "Tesmond looks at you with a casual "+
         "disregard.\n",
         "Tesmond seems to sidestep half your "+
         "blows",
       }));
     guild_master->set_magic_resist(50);
     guild_master->set_spells(({
         "name",       "lightning hands",
         "level",      15,
         "damage",     40,
         "immune",     "lightning",
         "msg target", "You feel an electric shock as @@query_name:"+
         "$this_player()$@@ hits you.\n",
         "msg_room",    "@@query_name:$this_object()$@@ is thrown back by "+
         "an electric shock as @@query_name:"+
         "$this_player()$@@ hits "+
         "@@query_possessive:$this_object()$@@.\n",
         "msg caster",  "Your hands tingle when you hit "+
         "@@query_name:$this_object()$@@.\n",
       }));
    }
    if(!staff) {
     remove_call_out("summon_staff");
     staff = clone_object(MAGIC_WEAPON);
     move_object(staff, guild_master);
     staff->set_name("quarterstaff");
     staff->set_alt_name("staff");
     staff->set_short("Master Staff");
     staff->set_long("The staff vibrates with a magical dweomor.\n");
     staff->adj_light(10);
     staff->set_info("The staff has 2 power runes written on it.\n"+
       "One reads \"suith\", the other \"delan\".\n");
     staff->set_material("wood");
     staff->set_class(({ "fighter", }));
     staff->set_weight(3);
     staff->set_value(15000);
     staff->set_enchanted(1);
     staff->set_protection("fire");
     staff->set_cast_level(30);
     staff->set_charges(100);
     staff->set_max_charges(100);
     staff->set_wc(18);
     staff->set_spells(({ "suith", "fire ball",
         "delan", "cure light wounds",
       }));
     staff->set_info("@@query_charges_string:$this_object()$@@"+
       "@@query_class_string:$this_object()$@@"+
       "@@query_protection_string:$this_object()$@@"+
       "@@query_level_string:$this_object()$@@"+
       "The word 'suith' will activate a 'Fire Ball' spell.\n"+
       "The word 'delan' will activate a 'Cure Light Wounds'.\n");
     command("wield staff", guild_master);
    }
    else if(find_call_out("summon_staff") == -1) {
     call_out("summon_staff", 7200);
    }
    if(arg) return;
    set_short("the training room");
    set_long(
      "About the walls hang swords and shields and strange devices of \n"+
      "combat and seige warfare. This is a place where grand fighters \n"+
      "and warriors from all over the lands come to train in weapons  \n"+
      "and enhance their skill at arms. By the doorway is a sign of \n"+
      "bronze.\n");

    set_items(({
     "walls#wall",
     "The walls are made of stone, giving you a sense of antiquity",

     "swords",
     "The gleaming blades seem ancient, yet still sharp enough to kill "+
     "the unwary man",

     "shields#shield",
"There was once a pattern worked into the surface, but it has been worn down\n"+
     "through years of use",

     "devices#device","These are unfamiliar, but seem deadly nonetheless",
     "doorway","The doorway is large, but easily defendable",
     "place","This is the training room",
      }));

    set_exits(({   "room/city/arena/arena1", "west",  }));
    set_weather(2, 0, 0);
    set_guild_name("No"); /* normal guild */
    set_classes(({
     "general",        ({
       "climb", "swim",
     }),

     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity", 
       "combat",   "constitution", "charisma",
     }),


     "fighter",        ({
       "multi attack", "multi opponent", "two weapon",
       "unarmed",     "armouring",      "weapon smith",
     }),

     /* these are alternatives....
        "thief",          ({
                      "stealth", "locks", "steal", "backstab",
                    "appraisal", "traps",
                    }),

        "cleric",         ({
                      "healing sphere", "necromancy sphere", "combat sphere",
                      "stellar sphere", "protection sphere", "nature sphere",
                      "divination sphere",
                    }),

        "mage",           ({
                      "illusion", "charm", "conjuration", "abjuration",
                      "necromancy", "evocation", "divination", "alteration",
                    }),
      */
      }));
    set_exp(({
     0,    1014,    1522,    2283,    3425,    5138,
     7707,   11561,   17341,   26012,   39018,   58527,
     87791,  131687,  197530,  296296,  444444,  666666,
     1000000, 1500000, 2000000, 2500000, 3000000, 3500000,
     4000000, 4500000, 5000000, 5500000, 6000000, 6500000,
      }));
    set_skill_exp(({
     30,      50,      75,     100,     175,     250,
     400,     600,     900,    1200,    2000,    3000,
     4500,    6500,   10000,   15000,   20000,   30000,
     50000,   75000,  100000,  125000,  150000,  175000,
     200000,  225000,  250000,  275000,  300000,  325000,
      }));
    set_titles(({ 
     ({}), /* no neuter characters now but possible */


     /* male titles */ 
     ({
       "the Utter Newbie",
       "the Simple Wanderer",
       "the Prominent Wanderer",
       "the Simple Rover",
       "the Prominent Rover",
       "the Famed Rover",                                
       "the Amateur Fighter",                    
       "the Skilled Fighter",                                  
       "the Expert Fighter",                      
       "the Great Fighter",                                  
       "the Famed Fighter",                     
       "the Amateur Warrior",                              
       "the Skilled Warrior",                 
       "the Expert Warrior",                                 
       "the Great Warrior",                     
       "the Famed Warrior",                                 
       "the Lesser Champion",                 
       "the Renowned Champion",                              
       "the Famed Champion",                    
       "the Amateur Swordsman",                      
       "the Lesser Swordsman",        
       "the Prominent Swordsman",                  
       "the Great Swordsman",         
       "the Master Swordsman",                   
       "the Renowned Swordsman",      
       "the Famed Swordsman",                      
       "the Lesser Mercenary",               
       "the Prominent Mercenary",                          
       "the Great Mercenary",                
       "the Master Mercinary",                               
       "the Master Mercinacy"
     }),

     /* female titles */
     ({
       "the Utter Newbie",
       "the Simple Wandereress",
       "the Prominent Wandereress",
       "the Simple Rover",
       "the Prominent Rover",
       "the Famed Rover",                                
       "the Amateur Fighter",                    
       "the Skilled Fighter",                                  
       "the Expert Fighter",                      
       "the Great Fighter",                                  
       "the Famed Fighter",                     
       "the Amateur Warrior",                              
       "the Skilled Warrior",                 
       "the Expert Warrior",                                 
       "the Great Warrior",                     
       "the Famed Warrior",                                 
       "the Lesser Champion",                 
       "the Renowned Champion",                              
       "the Famed Champion",                    
       "the Amateur Swordswoman",                    
       "the Lesser Swordswoman",        
       "the Prominent Swordswoman",                  
       "the Great Swordswoman",         
       "the Master Swordswoman",                   
       "the Renowned Swordswoman",      
       "the Famed Swordswoman",                      
       "the Lesser Mercenary",               
       "the Prominent Mercenary",                          
       "the Great Mercenary",                
       "the Master Mercinary"                               
     }),
      }));

    /*** get a new pretitle one in four levels after 30 ***/
    set_pretitles(({
     ({}), /* no neuter pretitles */

     /* male pretitles */
     ({
       "Captain",
       "Major",
       "Colonel",
       "General",
       "Marshall",
       "Knight Marshall",
       "Sir",
       "Lord",
       "Baronet",
       "Baron",
       "Viscount",
       "Count",
       "Marquis",   
       "Duke",
       "Grand Duke",
       "Archduke",
       "Prince",
       "Crown Prince",
       "King",
       "Emperor",
       "Overlord",
     }),

     /* female pretitles */
     ({
       "Captain",
       "Major",
       "Colonel",
       "General",
       "Marshall",
       "Knight Marshall",
       "Madame",
       "Lady",
       "Baronet",
       "Baroness",
       "Viscountess",
       "Countess",
       "Marquise",   
       "Duchess",
       "Grand Duchess",
       "Archduchess",
       "Princess",
       "Crown Princess",
       "Queen",
       "Empress",
       "Overlady",
     }),
      }));
}


void summon_staff() {
    if(!staff) return;
    tell_object(environment(staff),"Tesmond summons his staff.\n");
    destruct(staff);
    reset(1);
}

void init() {
    if(guild_master) {
     object attacker;

     if((attacker = (object)guild_master->query_primary_attack())) {
         if(present(attacker, this_object())) {
          call_out("no_guild_mess",1,this_player());
          return;
         }
     }
    }
    ::init();
}

void no_guild_mess(object ob) {
    tell_object(ob,"Tesmond is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}

