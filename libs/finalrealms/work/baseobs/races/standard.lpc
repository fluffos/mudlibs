/* the standard race... */
/* Verkho - added the race_size func */
inherit "/std/object";
#include "light_defs.inc"
#include "race_weights.h"

#define SWIM_PROP "swimmer"
#define UBREATHE_PROP "underwater_breathing"

nosave int min_light_limit;
nosave int max_light_limit;

int race_size;
int limbs;

mixed *bits;

// Dummy for now, allows death curses etc.
// taniwha 1996
void on_death(object player,object killer)
{
}

int set_light_limits(int lower, int upper) {
    //if ((lower<LIGHT_BOUNDS_LOW) || (upper>LIGHT_BOUNDS_HIGH)) return 0;
    min_light_limit = lower;
    max_light_limit = upper;
    return 1;
}

int query_light_limith() {
    return max_light_limit;
}

int query_light_limitl() {
    return min_light_limit;
}


void set_race_size(int i) { race_size = i; }
int query_race_size() { return race_size; }
/* The amazing 'bits' array :
 * at the mo has 3 elements per bit:
 * name, alias, array
 * where the array has the form:
 * bit_come_from, weight, general_value, list_of_bits_on_this_bit
 * All incredibly gruesome hey?
 */

void add_bit(string name, string alias, mixed *varr)
{
    int i;

    i = member_array(name, bits);
    if (i >= 0) {
        if (pointerp(bits[i+1])) i--;
        bits[i] = name;
        bits[i+1] = alias;
        bits[i+2] = varr;
        return;
    }
    bits += ({ name, alias, varr });
    return;
}

void create() {
    set_long("The standard boring race.  Get a new one soon, this one is "
      "pretty sad.\n");
    reset_get();
    race_size = 4; // This is used as a standard 'human' size
    limbs = 2;
    bits = ({
      "head", "", ({ 0, 40, 0, 
        "left ear", "right ear", "left eye", "right eye", "nose", "scalp",
        "tongue", "teeth", "skull" }),
      "left ear", "ear", ({ "head", 1, 0 }),
      "right ear", "ear", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "nose", "", ({ "head", 1, 0 }),
      "scalp", "", ({ "head", 3, 0 }),
      "tongue", "", ({ "head", 2, 0 }),
      "teeth", "", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 20, 0 }),
      "left arm", "arm", ({ 0, 80, 0, "left hand" }),
      "right arm", "arm", ({ 0, 80, 0, "right hand" }),
      "torso", "chest", ({ 0, 400, 0, "heart", "liver", "left kidney",
        "right kidney", "left lung", "right lung", "spleen" }),
      "left hand", "hand", ({ "left arm", 15, 0, "left pinky", 
        "left third finger", "left index finger", "left ring finger",
        "left thumb" }),
      "right hand", "hand", ({ "right arm", 15, 0, "right pinky",
        "right third finger", "right index finger", "right ring finger",
        "right thumb" }),
      "left pinky", "finger", ({ "left hand", 1, 0 }),
      "left third finger", "finger", ({ "left hand", 1, 0 }),
      "left index finger", "finger", ({ "left hand", 1, 0 }),
      "left ring finger", "finger", ({ "left hand", 1, 0 }),
      "left thumb", "finger", ({ "left hand", 1, 0 }),
      "right pinky", "finger", ({ "right hand", 1, 0 }),
      "right third finger", "finger", ({ "right hand", 1, 0 }),
      "right index finger", "finger", ({ "right hand", 1, 0 }),
      "right ring finger", "finger", ({ "right hand", 1, 0 }),
      "right thumb", "finger", ({ "right hand", 1, 0 }),
      "heart", "", ({ "torso", 10, 0 }),
      "liver", "", ({ "torso", 5, 0 }),
      "left kidney", "kidney", ({ "torso", 5, 0 }),
      "right kidney", "kidney", ({ "torso", 5, 0 }),
      "left lung", "lung", ({ "torso", 5, 0 }),
      "right lung", "lung", ({ "torso", 5, 0 }),
      "spleen", "", ({ "torso", 5, 0 }),
      "genitals", "", ({ 0, 5, 0 }),  /* sex ????  ohhh yes*/
      "left leg", "leg", ({ 0, 300, 0, "left foot" }),
      "right leg", "leg", ({ 0, 300, 0, "right foot" }),
      "left foot", "foot", ({ "left leg", 50,  "left big toe",
        "left second toe", "left third toe",
        "left fourth toe", "left little toe" }), /* toes ... god */
      "right foot", "foot", ({ "right leg", 50, "right big toe",
        "right second toe", "right third toe",
        "right fourth toe", "right little toe" }), /* toes ... god */
      "right little toe", "toe", ({ "right foot", 1, 0 }),
      "right second toe", "toe", ({ "right foot", 1, 0 }),
      "right third toe", "toe", ({ "right foot", 1, 0 }),
      "right fourth toe", "toe", ({ "right foot", 1, 0 }),
      "right big toe", "toe", ({ "right foot", 1, 0 }),
      "left little toe", "toe", ({ "left foot", 1, 0 }),
      "left second toe", "toe", ({ "left foot", 1, 0 }),
      "left third toe", "toe", ({ "left foot", 1, 0 }),
      "left fourth toe", "toe", ({ "left foot", 1, 0 }),
      "left big toe", "toe", ({ "left foot", 1, 0 }),
    });
    ::create();
    set_name("unknown creature");
    //set_light_limits(LIGHT_STANDARD_LOW, LIGHT_STANDARD_HIGH);
}

/*
   Taniwha, 1997, default atatck messages
   most frequent first 
*/   
string * valid_attacks()
{

    return  ({
      "$att_name$ punches $def_name$ in the $def_part$",
      "You punch $def_name$ in the $def_part$",
      "$att_name$ punches you in the $def_part$",

      "$att_name$ kicks $def_name$ in the $def_part$",
      "You kick $def_name$ in the $def_part$",
      "$att_name$ kicks you in the $def_part$",

      "$att_name$ knees $def_name$ in the $def_part$",
      "You knee $def_name$ in the $def_part$",
      "$att_name$ knees you in the $def_part$",

      "$att_name$ headbutts $def_name$",
      "You headbutt $def_name$",
      "$att_name$ headbutts you"
    });
}


/* armor querying one... I forget what it is called */
int query_number_type(string type) {
    if (type == "ring")
        return 2;
    return 1;
}

/* number of weapons allowed to be wielded */
int query_number_wielded() {
    return 1;
}

/* the number of hands the race has */
void set_limbs(int i) {
    limbs = i;
}
int query_limbs() {
    return limbs;
}

/* race description used on the player object...
 * There will be a race varible on the player object which allows
 * the race to keep needed information on it
 */
string query_desc(object ob) { return "A small non descript person.\n"; }

/* bonuses and minuses on given skills.
 */
int query_skill_bonus(int lvl, string skill) {
    return 0; /* the standard race has no modifications */
}

/* when the player logs on this function is called.
 * it allows you to start up the player with whatever he needs.
 * EXCEPT it's not used, see start_player() below *curses*	
 */
int player_start(object player) {
    return 1;
}

/* and guess what this does?
 * Beware... If some is straight dested this will not be called,
 * So remember that you still must check your array for null members.
 */
int player_quit(object player) {
    return 1;
}

int query_dark(int i) {
    if( i < (min_light_limit-5) ) return 1; /* Can't see a thing */
    if(i < min_light_limit) return 2; /* can sorta see but not much */
    if( i < (min_light_limit+5) ) return 3; /* starting to lose it */
    if(i > (max_light_limit+ 40) ) return 6; /* blinded by the light */
    if(i > (max_light_limit + 20) ) return 5; /* dazzled */
    if(i > max_light_limit) return 4; /* squinting */
    return 0;
}

/*
 * is used by monsters...
 * You can trap this and set up anything that a monster might get at 
 * certain level in this race
 */
void set_level(int lvl, object ob) {

} /* set_level() */

mixed *query_bits()
{
    return bits;
}

mixed *query_bit(string s)
{
    int i;

    i = member_array(s, bits);
    if (i < 0) return ({ });
    if (pointerp(bits[i+1])) i--;
    return ({ bits[i], bits[i+1], bits[i+2] });
}

mixed query_possible_bits(string s)
{
    int i;
    string *poss;

    poss = ({ });
    for (i = 0; i < sizeof(bits); i+=3) {
        if (bits[i] == s || bits[i+1] == s) poss += ({ bits[i] });
    }
    return poss;
}
int query_max_level(string guild){
    return 100;
}

void start_player(object ob) {
    string p_race;
    if(ob)
    {
        p_race = ob->query_race();
        ob->add_language(p_race);
    }
    else return;
    switch(p_race) {
    case "elf":
    case "drow":
        ob->set_weight(ELF_WEIGHT);      		
        break;
    case "dwarf":
    case "duergar":
        ob->set_weight(DWARF_WEIGHT);
        break;
    case "gnome":
        ob->set_weight(GNOME_WEIGHT);
        break;
    case "halfling":
        ob->set_weight(HALFLING_WEIGHT);
        break;
    case "orc":
        ob->set_weight(ORC_WEIGHT);
        break;
    case "goblin":
        ob->set_weight(GOBLIN_WEIGHT);
        break;
    case "lizard-man":
        ob->set_weight(LIZARD_MAN_WEIGHT);
        break;
    case "half-elf":
        ob->set_weight(HALF_ELF_WEIGHT);
        ob->add_language("human");
        ob->add_language("elf");
        break;
    case "half-drow":
        ob->set_weight(HALF_ELF_WEIGHT);
        ob->add_language("human");
        ob->add_language("drow");
        break;
    case "half-orc":
        ob->set_weight(HALF_ORC_WEIGHT);
        ob->add_language("human");
        ob->add_language("orc");
        break;
    case "human":
        ob->set_weight(HUMAN_WEIGHT);
        break;
    default:
        ob->set_weight(1700);
        break;
    }
}
/* determines time out of water for aquatic races, -1 for non aquatic */
int query_aquatic(object player)
{
    return -1;
}   
int query_swim_stamina(object player)
{
    if( player->query_property("free_action") )
        return player->query_property("free_action");
    return (player->query_con()*10)+player->query_property(SWIM_PROP);
}
int query_underwater_breathing(object player)
{
    if( player->query_property("free_action") )
        return player->query_property("free_action");
    return (player->query_con()*5)+player->query_property(UBREATHE_PROP);	
}

// this is cumulative each race hb. So dropping encumb does help
// but ... not a lot.
int adjust_stamina(object player, int stam)
{   
    int maxe,enc;
    if(!stam)
    {
        stam = player->query_con() * 10;
    }
    maxe = player->query_max_weight();
    enc  = player->query_loc_weight();
    enc += maxe/10; /* minimum load for being wet */
    switch(enc)
    {
    case 0:
        stam = 1;
        break;
    case 1:
        stam = (stam * 75)/100;
        break;
    case 2:
        stam = (stam * 85)/100;
        break;
    case 3:
        stam = (stam * 95)/100;
        break;              	
    case 4..20:
        stam += enc/3;
        break;
    default:
        stam += 7;
        break;
    }   
    return stam;	

}
void ashore(object player)
{
    if(player->query_property("swimming") || player->query_property("drowning"))
    {
        tell_object(player,"You haul in great lungfulls of air, just glad to be ashore again.\n");	
        player->remove_timed_property("swimming");
        player->remove_property("swimming");
        player->remove_timed_property("drowning");
        player->remove_property("drowning");
        if( player->query_static_property("seatmp") )
        {
            player->remove_static_property("seatmp");   
            player->remove_static_property("noguild");   
            player->remove_static_property("nocast");   
        }
    }
}
void awater(object player)
{
    if(player->query_property("gasping"))
    {
        tell_object(player,"You relax as your flesh draws life giving oxygen from the water.\n");
        player->remove_timed_property("gasping");
        player->remove_property("gasping");
    }
}    	
void gasping(object player)
{
    int stamina;
    stamina = this_object()->query_aquatic(player);
    if(stamina == -1) return;	
    if(!player->query_property("gasping"))
    {
        player->add_property("gasping",1);
        player->add_timed_property("gasping",2,stamina);  
    }
    switch(player->query_property("gasping"))
    {	
    case 1:
        player->adjust_hp(-10,this_object());
        tell_object(player,"%^RED%^You weaken as you struggle for oxygen in this dessicated hell.%^RESET%^\n");
        break;
    case 2:
        tell_object(player,"%^RED%^You galp frantically as you fight to draw oxygen from the air.%^RESET%^\n");
        break;
    }   	    	
}

void sinking(object player)
{
    int stamina,dur;
    string col;

    col = "%^BOLD%^%^BLUE%^";

    stamina = this_object()->query_swim_stamina(player);
    if(stamina == -1) return;
    if(player->query_property("swimming") == 0)
    {
        player->add_property("swimming",1);
        player->add_timed_property("swimming",2,stamina);  
    }
    if(player->query_property("free_action"))
    {
        tell_object(player, "%^CYAN%^Strange, you haven't the urge or need "+
          "to breathe.%^RESET%^\n");
        return;
    }
    else {
        dur = player->query_time_remaining("swimming");
        dur = adjust_stamina(player,dur);
        //tell_object(player,"Dur = "+dur+" ");
        if(player->query_property("swimming") == 2)
            player->add_timed_property("swimming",2,dur);
        if(dur < 196) col = "%^YELLOW%^";
        if(dur < 64)  col = "%^RED%^";    
    }
    switch(player->query_property("swimming"))
    {	
    case 1:
        environment(player)->DO_SINK(player,environment(player));
        this_object()->drowning(player); // so they don't bob up and avoid death if it's due
        break;
    case 2:
        tell_object(player,col+"You struggle to stay afloat.%^RESET%^\n");
        break;
    }   	    	
}
void drowning(object player)
{
    int stamina,swim,dur;
    string col;

    col = "%^BOLD%^%^BLUE%^";
    stamina = this_object()->query_underwater_breathing(player);
    if(stamina == -1) return;
    if(!player->query_property("drowning"))
    {
        player->add_property("drowning",1);
        player->add_timed_property("drowning",2,stamina);  
    }
    if(player->query_property("free_action"))
    {
        tell_object(player, "%^CYAN%^Strange, you haven't the urge or need "+
          "to breathe.%^RESET%^\n");
        return;
    }
    switch(player->query_property("drowning"))
    {	
    case 1:
        environment(player)->DO_DROWN(player,environment(player));
        break;
    case 2:
        dur = player->query_time_remaining("drowning");
        if(dur < 128) col = "%^YELLOW%^";
        if(dur < 64)  col = "%^RED%^";    

        tell_object(player,
          col+"   O%^RESET%^\n"+
          col+"   0%^RESET%^\n"+
          col+"  o%^RESET%^\n"+
          col+" o%^RESET%^\n"+
          col+".%^RESET%^\n"
        );
        break;
    }   	    	
}
void werewolf(object player)
{		
    if(player->query_race() == "werewolf") return;
    if(player->query_property("JUST_CHANGED")) return;
    if(player->query_property("WEREWOLF") )
    {
        if(player->query_property("wolfbane") ) return;
        //Taniwha DUH, day of month
        //if("/obj/handlers/weather"->query_day(ENV(player)) ) return;
        // query_moon == 0 -> full moon
        if(!"/obj/handlers/weather"->query_moon())
        {
            player->add_property("old_race",player->query_race());
            player->set_race_ob("/std/races/werewolf");
            player->add_timed_property("JUST_CHANGED",1,100);
        }
    }  
}
protected flushit(object player)
{
    player->remove_property("gasping");
    player->remove_timed__property("gasping");
    player->remove_property("swimming");
    player->remove_timed_property("swimming");
    player->remove_property("drowning");
    player->remove_timed_property("drowning");
}
void race_heartbeat(object player)
{

    if(!player) return;
    if(!ENV(player)) return;
    if(player->query_dead())
    {
        flushit(player);
        return;
    }
    switch(ENV(player)->query_property("location"))
    { 
    default:
    case "outside":
        werewolf(player);
        this_object()->ashore(player);
        this_object()->gasping(player);
        break;		
    case "inside":	
        this_object()->ashore(player);
        this_object()->gasping(player);
        break;
    case "sea_surface":
        this_object()->surface(player);
        this_object()->sinking(player);			
        this_object()->awater(player);
        break;
    case "underwater":
        this_object()->drowning(player);
        this_object()->awater(player);
        break;
    } 		 
}

