/* Written by Hamlet, August 1995.  Handles various details of our new
   god structure for the players.  player.c calls it.  Renaming/moving
   would be a BAD idea.
*/
#define MYSAVEFILE "/save/god_handler"
#include "gods.h"
#include "altar_longs.h"

string *DEVELOPERS = ({ "guilo", "krelk", "cherokee" });

nosave mapping gods;
nosave mapping sac_items;
nosave string *races;
nosave mapping race_gods;

/* This one stores the high priests.  SHOULD be the only thing saved. */
mapping highs;

void create() {
  seteuid("Room");
  if(file_size(MYSAVEFILE+".o") > 0)
    restore_object(MYSAVEFILE,1);
  if(!highs)
    highs = ([ ]);
  gods = GODS;
  sac_items = SAC_ITEMS;
  races = RACES;
  race_gods = ALLOWED_GODS;
}

void reset() {
  save_object(MYSAVEFILE,1);
}

void dest_me() {
  save_object(MYSAVEFILE,1);
  destruct(this_object());
}

int query_developer(object ob) {
  if(ob->query_lord())
    return 1;
  if(member_array(ob->query_name(),DEVELOPERS) != -1)
    return 1;

  return 0;
}

int is_deity(string which) { return gods[which]; }
int deity_gender(string which) { return gods[which]; }

mixed query_high_priest(string whichgod) { return highs[whichgod]; }
protected int set_high_priest(string whichgod, string theplayer, int gender, 
                                                                int value) {
  if(gods[whichgod]) {
    highs[whichgod] = ({ theplayer, value, time(), gender });
    save_object(MYSAVEFILE,1);
    return 1;
  }
  return 0;
}

mapping high_priests() {
  return highs;
}

/* Next few functions return data in the mappings. */
string *list_of_deities() {  return GOD_LIST;  }

string *worshipper_races(string god) {
  string *data = ({ });
  int i;
  
  if(!is_deity(god))  return data;
  
  for(i=0;i<sizeof(races);i++)
    if(member_array(god,race_gods[races[i]]) != -1)
      data += ({ races[i] });
      
  return data;
}

int race_can_worship(string god, string race) {
  if(!god || !race)  return 0;
    
  if(objectp(race))
    race = race->query_race();
    
  if(!race)  return 0;

  if(member_array(god,race_gods[race]) == -1)
    return 0;
  else
    return 1;
}

string *gods_for_race(string race) {
  string *data = ({ });
  int i;
  
  for(i=0;i<sizeof(race_gods[race]);i+=2)
    data += ({ race_gods[race][i] });
    
  return data;
}
  
int god_race_modifier(string race, string god) {
  int mod;
  
  if(!gods[god]) return 0;
  
  mod = member_array(god,race_gods[race]);
  
  if(mod == -1)
    return 0;
  else
    return race_gods[race][mod+1];
}

string *sacrificial_interests(string god) {
  return sac_items[god];
}

int query_sacrifices(object player) {
  object tp;
  
  if(objectp(player))
    return player->query_property("sacrifices");
  else {
    tp = find_player(player);
    if(tp)
      return tp->query_property("sacrifices");
    else
      return 0;
  }
}

/* This one should not be called directly, except maybe in quests.
   Use sacrifice_item() or sacrifice_xp(), if at all possible, instead.
   Racial modifiers are NOT handled in this function, use 
   god_race_modifier() where appropriate.
*/
int adjust_sacrifices(object player, int val) {
  int amt;
  string hisdeity;
    
  if(stringp(player))
    player = find_player(player);
    
  if(!player) return 0;
  
  hisdeity = player->query_deity();
  if(!hisdeity || (hisdeity == "none"))  return 0;
  
  amt = player->query_property("sacrifices");
  
  if(player->query_property("SWITCHED_DEITIES")) {
    if( (time() - (int)player->query_property("SWITCHED_DEITIES")) < 604800) 
      val /= 2;  /* One week, gods are still angry.  Less credit */
    else
      player->remove_property("SWITCHED_DEITIES");
  }
  
  amt += val;
    
  player->remove_property("sacrifices");
  player->add_property("sacrifices",amt);

  if(!highs[hisdeity] || (highs[hisdeity][1] < amt) ||
     (highs[hisdeity][0] == player->query_name()) ||
     ((time() - highs[hisdeity][2]) > 1209600) ) /* Two weeks */
    set_high_priest(hisdeity,(string)player->query_name(),
                    player->query_gender(),amt);
   
  return amt;
}

/* Should be used when the player is sacrificing anything but xp.
   If there's an altar, make the stuff go on the altar and then use
   sacrifice_all_items().  More convenient that way.  Returns amount
   that "sacrifices" gets incremented.
*/
int sacrifice_item(object player, object theitem, string thegod) {
  string itemtype;
  int raw_credit;
  int sac_credit;
  int pos;
  
  if(!theitem) return 0;
  
  if(theitem->query_weapon())
    itemtype = "weapons";
  else if(theitem->query_armour())
    itemtype = "armours";
  else if(member_array("Some Money For Me",theitem->query_alias()) != -1)
    itemtype = "money";
  else if(theitem->query_corpse())
    itemtype = "corpses";
  else
    itemtype = "items";
    
  if(member_array(itemtype,sac_items[thegod]) == -1)
    raw_credit = 0;
  else {
    if(itemtype == "corpses")
      raw_credit = 5000 + random(5000);
    else
      raw_credit = theitem->query_value();
  }
 
  pos = member_array(thegod,race_gods[player->query_race()]);
    
  if(pos == -1) {
    if(thegod == player->query_deity())
      sac_credit = 0;
    else
      sac_credit = (raw_credit * 33) / 100;
  }
  else     
    sac_credit = (raw_credit * race_gods[player->query_race()][pos+1]) / 100;
  
  if(sac_credit) {
    if(thegod == player->query_deity())
      adjust_sacrifices(player,sac_credit);
    player->adjust_deity_status(-(sac_credit * STATUS_MULT / 500),thegod);
  }
  theitem->dest_me();
          
  return sac_credit;
}

/* This is for gods that want xp sacrificed.  The altar-room will have to
   parse the amount and that sort of thing, since they can't lay experience
   upon the altar.  MAKE SURE they're not sacrificing more than they 
   currently have.  The function will realize this and correct for it, 
   but the return value will make no sense, as it gets hit with modifiers
   and such (function returns the actual amount that "sacrifices" gets
   incremented.)
*/
int sacrifice_xp(object player, int amt, string thegod) {
  int sac_credit;
  int pos;
  
  if(amt < 0)  amt = -amt;
  if(amt > player->query_xp())
    amt = player->query_xp();
  if(amt < 0)  amt = 0;

  if(amt == 0)  return 0;
    
  player->adjust_xp(-amt);
  
  if(member_array("experience",sac_items[thegod]) == -1)
    return 0;
  
  pos = member_array(thegod,race_gods[player->query_race()]);
  
  if(pos == -1) {
    if(thegod == player->query_deity())
      return 0;
    else
      sac_credit = (amt * 33) / 100;
  }
  else 
    sac_credit = (amt * race_gods[player->query_race()][pos+1]) / 100;
  
  if(thegod == player->query_deity())
    adjust_sacrifices(player,sac_credit);
  
  player->adjust_deity_status(-(sac_credit * STATUS_MULT / 500),thegod);
      
  return sac_credit;
}

/* Cute little wrapper for sacrifice_item() that sacrifices everything
   in a certain container.  Returns amount that "sacrifices" gets 
   incremented.
*/
int sacrifice_all_items(object player, object altar, string thegod) {
  object *stuff;
  int total = 0;
  int i;
  
  if( !altar || !objectp(altar) )  return 0;
  
  stuff = all_inventory(altar);
  
  for(i=0;i<sizeof(stuff);i++)
    total += sacrifice_item(player,stuff[i],thegod);
    
  return total;
}

/* This one is called when a player types retire.  Because most of retire
   is in /secure, I threw this in /global/player.c so it ALWAYS gets called
   when they type retire, whether they actually go through with it or not.
   In other words, if they chicken out, they're still not high priest
   until they go and sacrifice something new.  Use remove_sacrifices()
   for any other purpose.
*/
int remove_high_priest(string player, string deity) {
  if(objectp(player))
    player = player->query_name();

    if(!player)  return 0;
    if(!deity)   return 0;

    if( highs[deity] &&
        (highs[deity][0] == player) ) {
      highs = m_delete(highs,deity);
      save_object(MYSAVEFILE,1);
      return 1;
    }
    return 0;
}

/* This should be called when a player changes deities or refreshes. */
/* Returns 1 if they were the high priest.  Otherwise returns 0. */
int remove_sacrifices(object player) {
  if(stringp(player))
    player = find_player(player);

  if(!player)  return 0;

  player->remove_property("sacrifices");

  return remove_high_priest(player->query_name(), player->query_deity());
}

/* Returns the long associated with a god's altar.
   N.B.:  Lathander -> Taniwha        Lolth  -> Cyrcia
          Tempus    -> Timion         Tymora -> Hokemj
          Virga   -> Raisa        Bivins -> Radix
*/
             
string altar_long(string whichgod) {
  switch(whichgod) {
    case "baldrick"  : return ALTAR_BALDRICK;
    case "timion"    : return ALTAR_TIMION;
    case "raisa"     : return ALTAR_RAISA;
    case "taniwha"   : return ALTAR_TANIWHA;
    case "hokemj"    : return ALTAR_HOKEMJ;
    case "cyrcia"    : return ALTAR_CYRCIA;
    case "radix"     : return ALTAR_RADIX;
    case "ducky"     : return ALTAR_DUCKY;
    case "grimbrand" : return ALTAR_GRIMBRAND;
    case "none"      : return ALTAR_NONE;
  };
}

/* needs alignment stuff */
