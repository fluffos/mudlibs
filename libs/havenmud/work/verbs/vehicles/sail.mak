/*    /verbs/rooms/go.c
 *    from the Dead Soulsr2 Object Library
 *    go STR
 *    go into STR
 *    created by Descartes of Borg 951104
 */

#pragma save_binary

#include <lib.h>
#include <vehicle.h>
#include <damage_types.h>
#include <daemons.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("sail");
    SetSynonyms( ({ "dock" }) );
    SetRules("STR");
    SetErrorMessage("Sail the ship where??");
    SetHelp("Syntax: <sail DIRECTION>\n"
	    "Moves your ship towards the direction you specify. "
	    "\nSee also: climb, enter, jump, go, <help ships>");
}

mixed can_sail_str(string str) {
  object ship = environment(this_player());
  object who = this_player();
  string tmp;
  if (who->GetSleeping()) return "You are asleep!";
  if (who->GetParalyzed()) return "You are paralyzed!";
  if (who->GetStaminaPoints() < 25) return "You are too tired.";
  if( !ship ) return "You are nowhere.";
  if (!(ship->GetProperty("PROP_VEHICLE"))) return "You are not in a vehicle!";
  if ((tmp = ship->CanPilot(who, str)) != 1) return tmp;
  if (ship->GetCrystals() < 1) return "You don't have enough stores to sail out!";
  return (mixed)environment(ship)->CanGo(ship, str);
}

mixed do_sail_str(string str) {
    object ship = environment(this_player());
    object who = this_player();
    int success;
    int enemies = 0;
    int con = 5;
    object *e = ({ });
    object *eP = ({ });
    e = ship->GetShipEnemies();
    if (!e) e = ({ });
    foreach(object ee in e) {
      if (!ee) continue;
      if (environment(ee) != environment(ship)) {
        e -= ({ ee });
      }
    }
    eP = e->GetPilot();
    eP = filter(eP, (: $1 :) );
    con = environment(ship)->GetSailingDifficulty();
    con *= ship->GetVehicleSize(); 
    if (WEATHER_D->GetRaining(environment(ship)->GetDomain()) == 10) {
      who->eventPrint("Sailing in such weather is more difficult!");
      con *= 2;
    }
    if (who->GetTestChar()) debug("Sailing Difficulty: " + con + " (base " + environment(ship)->GetSailingDifficulty() + ", Size: " + ship->GetVehicleSize() + ", Rain: " + 
                                  (WEATHER_D->GetRaining(environment(ship)->GetDomain()) == 10 ? "Yes" : "No") );
    foreach(object ep in eP) { enemies += ep->GetSkillLevel("sailing"); }
    success = who->eventCheckSkill("sailing", enemies + con, 0,  enemies);
    if (who->GetTestChar()) if (enemies) debug("success: " + success + " eP->sailing: " + enemies);
    if (who->GetSkillLevel("sailing") <= 50) {
    	if (userp(who)) who->AddStaminaPoints(-25 + who->GetSkillLevel("sailing")/2);
    	}
    send_messages("sail",
      "$agent_name $agent_verb the ship " + str + ".", 
      this_player(), 0, ship);
    if (success < 0) {
    	switch(random(100)) {
    		case 0..50:
    		  ship->eventPrint(who->GetCapName() + " hits some floating debris.");
    		  ship->eventReceiveDamage(0, BLUNT, absolute_value(success) * 5);
    
    		  break;
    		case 51..80:
    		  who->eventPrint("The ship fails to respond to your commands.");
    		  ship->eventPrint("The ship doesn't move.");
    
    		  return 1;
    		  break;
    		case 81..95:
    		  who->eventPrint("The ship hits a large amount of debris.");
    		  ship->eventReceiveDamage(0, BLUNT, absolute_value(success) * 25);
    
    		  break;
    		
    		case 96..100:
                  who->eventPrint("%^BOLD%^RED%^You've managed to damage the sails!%^RESET%^");
                  ship->eventPrint("%^BOLD%^RED%^The sails have been damaged!%^RESET%^");
    		  ship->AddDamagedSystem("sails");
    		  break;
    		}
    	}
    	if (success <= 0) {
    	  if (!enemies) who->eventPrint("The ship doesn't move.");
    	  if (enemies) who->eventPrint("You fail to evade the ship's enemies.");
    
    	return 1;
    	}
      ship->AddCrystals(-1);
      
    	return (mixed)environment(ship)->eventGo(ship, str);
}
