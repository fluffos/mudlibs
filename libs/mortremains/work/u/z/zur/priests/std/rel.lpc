/* rel.c
** Coded by Zur@Nightfall's Keep
**For a simple explanation
**   ([ religion : ({ major sphere access , minor sphere access }) ]);
**
** May 4, 1997 Zur added spell_levels and level_check()
*/
#include "../pr.h"
mapping Priesthood = ([
  "agriculture" : ({
                     ({"all", "creation", "divination", "summoning" }),
                     ({ "animal", "healing", "protection", "sun", "weather" })
                  }),
    
  "ancestors"   : ({
                     ({ "all", "astral", "creation", "divination", "guardian",
                     "necromantic", "protection" }),
                      ({ "charm", "healing" })
                  }),
                  
  "animals"     : ({
                     ({ "all", "animal", "charm", "divination", "protection" }),
                     ({ "combat", "creation", "healing" })
                  }),
                  
  "arts"        :({
  					 ({ "all", "astral", "creation", "divination", "elemental",
  					    "plant", "protection", "sun" }),
  					 ({ "healing", "necromantic" })
  			     }),
  			     
  "birth"       :({
                     ({ "all", "astral", "charm", "creation", "elemental", "healing"
                        "protection", "summoning", "sun" }),
                     ({ "animal", "combat", "divination", "guardian", "necromantic" })
                 }),
  
  "community"   :({
   					 ({ "all", "creation", "healing" }),
   					 ({ "combat", "protection" })
   			     }),
   			     
  "competetion" :({
  					 ({ "all", "divination", "elemental" }),
  					 ({ "combat", "healing" })
  			     }),
  			     
  "crafts"      :({
  					({ "all", "creation", "divination", "healing" }),
  					({ "elemental", "guardian", "plant", "protection", "sun" })
  			     }),
  			     
  "culture"     :({
  					({ "all", "charm", "divination" }),
  					({ "combat", "creation" })
  			     }),
  			    
  "darkness"    :({ 
                    ({ "all", "charm", "divination", "necromantic", "summoning",
                    "sun" }),
                    ({ "animal", "elemental", "guardian", "protection" })
                 }),
  
  "dawn"        :({
  					({ "all", "charm", "divination", "elemental", "healing",
  					"summoning", "sun" }),
  					({ "animal", "creation", "necromantic", "plant", "protection",
  					   "weather" })
  			     }),
  			     
  "death"       :({
  				   ({ "all", "astral", "charm", "divination", "protection" }),
  				   ({ "guardian", "necromantic", "sun", "weather" })
  				 }),
  				 
  "disease"     :({
  				  ({ "all", "animal", "healing", "summoning", "weather" }),
  				  ({ "combat", "divination", "necromantic", "protection" })
  				 }),
  				 
  "divinity"    :({
  				  ({ "all", "charm", "healing", }),
  				  ({ "combat", "creation", "divination", "protection" })
  				 }),
  				  
  "earth"       :({
  				  ({ "all", "creation", "elemental", "plant", "summoning" }),
  				  ({ "animal", "divination", "healing", "protection" })
  				 }),
  				 
  "elemental"   :({ 
                  ({ "all", "combat", "elemental" }),
                  ({ "creation", "sun", "weather" })
                 }),
                 
  "everything"  :({
  				  ({ "all", "creation", "healing" }),
  				  ({ "divination", "protection" })
  				 }),
  				 
  "evil"        :({
  				  ({ "all", "charm", "necromantic" }),
  				  ({ "animal", "protection" })
  				 }),
  				
  "fate"        :({
  				  ({ "all", "divination", "guardian", "protection", "summoning" }),
  				  ({ "combat", "necromantic","sun", "weather" })
  				 }),
  				 
  "fertility"   :({
  					({ "all", "healing", "necromantic", "plant", "summoning" }),
  					({ "animal", "charm", "creation", "divination", "protection",
  					"weather" })
  			 	 }),
  			 	 
  "fire"        :({
  				   ({ "all", "elemental", "sun" }),
  				   ({ "charm", "divination", "healing", "necromantic",
  				   "protection", "weather" }),
  				 }),
  				 
  "fortune"     :({
  				  ({ "all", "charm", "divination", "healing", "protection",
  				  "summoning" }),
  				  ({ "animal", "creation", "guardian", "plant", "sun", "weather" })
  				 }),
  
  "good"        :({
  					({ "all", "healing", "protection" }),
  					({ "charm", "divination" })
  				 }),
  "guardianship":({
  				   ({ "all", "guardian", "protection" }),
  				   ({  "necromantic","healing" })
  				 }),
  
  "healing"     :({
  				  ({ "all", "creation", "divination", "healing", "necromantic"
  				     "protection", "summoning" }),
  				  ({ "animal", "charm", "guardian", "plant", "sun", "weather" })
  				 }),
  				 
  "hunting"     :({
  					({ "all", "divination", "guardian", "protection", "summoning" }),
  					({ "animal", "healing", "plant", "weather" })
  				 }), 
  					
  "justice"     :({
  					({ "all", "divination", "necromantic" }),
  					({ "elemental", "guardian" })
  				 }),
  				 
  // The life-death-rebirth cycle.				 
  "force"       :({
  				   ({ "all", "divination", "healing", "necromantic", "plant",
  				   "summoning", "weather" }),
  				   ({ "animal", "charm", "creation", "elemental",
  				   "protection", "sun" })
  				}),
  				
  "light"       :({
  					({ "all", "charm", "divination", "healing", "sun" }),
  					({ "animal", "creation", "necromantic", "plant" })
  				}),
  					
  "lightning"   :({
  				   ({ "all", "elemental", "weather" }),
  				   ({ "divination", "plant" })
  				 }),
  				 
  "literature"  :({
  				   ({ "all", "charm", "creation", "divination", "protection",
  				      "summoning", "sun" }),
  				   ({ "animal", "elemental", "guardian", "healing", "plant" })
  				 }),
  
  "love"        :({
  				  ({ "all", "animal", "charm", "healing", "necromantic", "protection",
  				     "summoning" }),
  				  ({ "creation", "divination", "guardian", "plant", "sun", "weather" })
  				 }),
  				 
  "magic"       :({
  				  ({ "all", "astral", "charm", "divination", "elemental", "healing"
  				     "protection", "summoning" }),
  				  ({ "animal", "guardian", "necromantic", "plant", "sun", "weather" })
  				  }),
  				  
  "marriage"    :({
  				   ({ "all", "charm", "divination", "healing", "protection" }),
  				   ({ "combat", "elemental", "guardian", "sun" }),
  				 }),
  				 
  "messengers"  :({ 
  				  ({ "all", "charm", "divination", "protection", "sun" }),
  				  ({ "elemental", "guardian", "necromantic", "plant" })
  				 }),
  				 
  "metalwork"   :({
  				   ({ "all", "elemental", "sun" }),
  				   ({ "combat", "divination" })
  				 }),
  				 
  "mischief"    :({
  					({ "charm", "divination", "protection", "summoning" }),
  					({ "animal", "elemental", "guardian", "plant" })
  				 }),
  				 
  "moon"        :({
  				   ({ "all", "charm", "divination", "summoning" }),
  				   ({ "animal", "elemental", "healing" })
  				 }),
  				 
  "music"       :({
  				  ({ "all", "animal", "charm", "summoning", "sun" }),
  				  ({ "divination", "elemental", "healing", "plant" })
  				 }),
  				 
  "nature"      :({
  				  ({ "all", "animal", "elemental", "plant", "protection" }),
  				  ({  "divination", "healing", "sun", "weather" })
  				  }),
  				  
  "ocean"       :({
  				  ({ "all", "animal", "divination", "elemental", "weather" }),
  				  ({ "charm" "combat", "plant", "protection" }),
  				  }),
  				  
  "oracles"     :({
  				   ({ "all", "divination", "elemental", "healing", "summoning" }),
  				   ({ "charm", "creation", "necromantic", "sun" }),
  				 }),
  				 
  "peace"       :({
  				  ({ "all", "charm", "creation", "divination", "protection" }),
  				  ({ "animal", "guardian", "healing", "necromantic" })
  				  }),
  				  
  "prosperity"  :({
  				  ({ "all", "animal", "creation", "plant", "summoning" }),
  				  ({ "guardian", "healing", "necromantic", "protection" })
  				 }),
  // This one I will do later.				 
  //"race"        :
  				  
  "redemption"  :({
  				  ({ "all", "charm", "combat" }),
  				  ({ "divination", "healing" })
  				  }),
  				  
  "rulership"   :({
  				  ({ "all", "charm", "elemental" }),
  				  ({ "healing", "protection" })
  				 }),
  				 
  "seasons"     :({
  				  ({ "all", "creation", "elemental", "protection", "weather" }),
  				  ({ "animal", "divination", "healing", "plant" })
  				 }),
  				 
  "sites"       :({
  				  ({ "all", "healing", "protection" }),
  				  ({ "animal", "plant" })
  				 }),
  				 
  "sky"         :({
  				  ({ "all", "astral", "elemental", "protection", "weather", }),
  				  ({ "combat", "divination", "plant", "sun" })
  				  }),
  				  
  "strength"    :({
  				  ({ "all", "combat", "healing" }),
  				  ({ "elemental", "necromantic" })
  				 }),
  				  
  "sun"         :({
  					({ "all", "divination", "healing", "necromantic", "sun" }),
  					({ "charm", "elemental", "plant", "protection" })
  				 }),
  
  "thunder"     :({
  				  ({ "all", "combat", "weather" }),
  				  ({ "divination", "protection" })
  				 }),
  				 
  "time"        :({
  				  ({ "all", "astral", "divination", "healing", "necromantic" }),
  				  ({ "plant", "protection", "sun", "weather" })
  				 }),
  				 
  "trade"       :({
  				  ({ "all", "charm", "divination", "protection" }),
  				  ({ "combat", "healing", "sun", "weather" })
  				  }),
  				  
  "vegetation"  :({
  				  ({ "all", "divination", "healing", "plant", "protection",
  				     "summoning", "weather" }),
  				  ({ "animal", "combat", "creation", "guardian", "necromantic", "sun" })
  				 }),
  				 
  "war"         :({
  				  ({ "combat", "healing" }),
  				  ({ "necromantic", "protection" })
  				 }),
  				 
  "wind"        :({
  				  ({ "all", "elemental", "protection", "weather" }),
  				  ({ "divination", "guardian" })
  				 }),
  				 
  "wisdom"      :({
  				  ({ "all", "charm", "divination" }),
  				  ({ "healing", "sun" })
  				 }),

]);

mapping spell_levels = 
([
   0 : 1,
   1 : 1,
   2 : 1,
   3 : 2,
   4 : 2,
   5 : 3,
   6 : 3,
   7 : 4,
   8 : 4,
   9 : 5,
  10 : 5,
  11 : 6,
  12 : 6,
  13 : 6,
  14 : 7
]);

mapping get_spheres(){ return Priesthood; }

int level_check(int level, int spellLevel)
{
   if(level > 14 || level == -1)// level should only == -1 for a wizard.
      return 1;
   if(spellLevel > spell_levels[level])
   {
     return 0;
   }
  return 1;
}
    
    
    
    
int check_sphere(object player, string *spellData, int level)
{
  string rel;
  int size;
  mixed *values;
  if(!spellData || !pointerp(spellData) ||
                !player->query("religion")) return 0;
  
  size = sizeof(spellData);
  rel = player->query("religion");
  values = Priesthood[rel];
  if(!values) return 0;
  while(size--)
  {
     // Major spheres
     if(member_array(spellData[size], values[0]) != -1)
      return 1;
     //Minor spheres
     if(member_array(spellData[size], values[1]) != -1)
     {
       if(level > 3) return -1;
       else
       return 1;
     }
      
  }
  return 0;
}

mixed *spells(){ return efun::get_dir("/u/d/dude/", 1); }
  
  
  
  
  
  
  
  
  
