#include <std.h>
#include "../serakii.h"
#define HIT_INTERVAL 4

inherit "/d/common/obj/weapon/sstaff";

int counter, charges;
string element,gem_type,glow_col;

void create(){
    ::create();
    set_name(" ");
	
	switch (random(4)){
		
		case 0:
		    //fire
		    element = "fire";
		    gem_type = "%^C160%^ru%^C088%^b%^C160%^y%^CRST%^";
			glow_col = "%^C160%^red%^CRST%^";
		break;
		case 1:
		    //cold
		    element = "cold";
		    gem_type = "%^C255%^di%^C195%^a%^C255%^mo%^C195%^n%^C255%^d%^CRST%^";
			glow_col = "%^C255%^white%^CRST%^";
		break;
		case 2:
		    //Electricity 
		    element = "electricity";
		    gem_type = "%^C243%^c%^C184%^a%^C190%^t%^C243%^s-%^C190%^e%^C243%^y%^C184%^e%^CRST%^";
			glow_col = "%^C190%^yellow%^CRST%^";
		break;
		case 3:
		    //acid
		    element = "acid";
		    gem_type = "%^C040%^e%^C022%^m%^C040%^era%^C028%^l%^C040%^d%^CRST%^";
			glow_col = "%^C040%^green%^CRST%^";
		break;
	}
	
	
    set_id(({ "sapper", "Meriphat's Sapper", "ebony shortstaff", "shortstaff", "meriphat's sapper", "mariphat's staff","staff"}));
    set_obvious_short("ebony shortstaff");
    set_short("%^C036%^Me%^C034%^r%^C036%^i%^C028%^p%^C036%^ha%^C029%^t%^C036%^'s %^C241%^S%^C243%^a%^C241%^p%^C243%^p%^C245%^e%^C241%^r%^CRST%^");
    set_long("The length of this staff is %^C240%^sleek ebony%^CRST%^ "+
	"and measures around two feet long. There are slight "+glow_col+" "+
	"runes in a %^C059%^fine script%^CRST%^ along the shaft that are "+
	"unreadable due to %^C058%^age %^CRST%^though you can feel them "+
	"thrum with %^C062%^power%^CRST%^. At the head of the staff, "+
	"clasped in %^C240%^ebony claws%^CRST%^ is a "+ gem_type +" that "+
	"likewise thrums with %^C062%^power%^CRST%^.\n");
    set_lore("%^C079%^The first professor in recorded history to be "+
	"expelled from the Library was Aleksandr Meriphat. His research "+
	"into stripping elemental resistances was groundbreaking but his "+
	"constant misuse of his study on the protections on the Caer and "+
	"library forced the Voice to remove him from the library. It is "+
	"said he constructed his tower on Graez and continues his research, "+
	"providing his impressive artificing skills to the highest "+
	"bidders.%^CRST%^\n%^C068%^- An "+
		"Incomplete History "+
		"of Serakii -%^CRST%^ %^C152%^Carrow Davin%^CRST%^\n");
    set_property("lore difficulty", 40);
    set_value(1000);
    set_hit((:this_object(),"hit_fun":));
    set_wield((:this_object(), "wield_fun":));
    set_unwield((:this_object(), "unwield_fun":));
    set_property("master weapon",1);	
    set_property("no curse", 1);
    set_property("no alter", 1);
    set_property("enchantment", 6);
    counter = 0;
}






int wield_fun(){
    object room, player;
   
    player = environment(this_object());    
    room = environment(player);
    
	tell_room(room,"%^C059%^As %^CRST%^"+player->query_cap_name()+"%^C059%^ "+
	"wields the %^C239%^ebony staff%^C059%^, %^CRST%^"+ element +"%^C059%^ "+
	"%^C227%^flares %^C059%^from the %^CRST%^"+ gem_type +"%^C059%^.%^CRST%^",player);
    tell_object(player,"%^C059%^As you wield the %^C239%^ebony staff%^C059%^ "+
	"%^CRST%^"+ element +" %^C227%^flares %^C059%^from the%^CRST%^ "+ gem_type +"%^C059%^ "+
	"and flows from it.%^CRST%^");
    return 1;
}

int unwield_fun(){
    object room, player;
   
    player = environment(this_object());    
    room = environment(player);
    
	tell_room(room,"%^C059%^The "+ element +"%^C059%^ receeds from your staff%^CRST%^",player);
    tell_object(player,"%^C059%^The "+ element +"%^C059%^ receeds from your staff%^CRST%^");
    return 1;
}


int hit_fun(object target){
    object player, room, sapper, ob;
    int damage, strength;
    string playername, targetname;
    
    sapper = this_object();
    player = environment(sapper);
    room = environment(player);
    
    if(!living(player) || !living(target) || !room) return 0;
    
    counter++;
    if(counter < HIT_INTERVAL) return 0;
    counter = 0;
    
    playername = player->query_cap_name();
    targetname = target->query_cap_name();
    strength = sapper->query_property("enchantment");
    damage = 0;
    
    switch(random(10)){
        case 0..3 : // extra hit
            tell_object(player, "%^C067%^You complete one hit "+
			"and turn the staff around with a quick backhand!%^CRST%^");
            tell_room(room, "%^C067%^With a flourish "+
			"%^CRST%^"+player->query_cap_name()+"%^C067%^ turns "+
			"and lands another blow!%^CRST%^", player,target);
            player->execute_attack();
            break;
        case 4..7 : // extra damage 
	        tell_object(player, "%^C246%^The runes on your staff glow %^CRST%^"+glow_col+"%^C246%^ and massive blast of%^CRST%^ "+element+"%^C246%^ rushes towards %^CRST%^"+targetname+"%^C246%^!%^CRST%^");
            tell_object(target, "%^C246%^ You recoil as a massive blast of%^CRST%^ "+element+" %^C246%^rushes towards you from%^CRST%^ "+playername+"%^C246%^'s staff!%^CRST%^");
            tell_room(room, "%^C246%^ %^CRST%^"+playername+"%^C246%^ steps back and%^CRST%^ "+element+" %^C246%^streams out of their staff and engulphs %^CRST%^"+targetname+"%^C246%^!%^CRST%^", player,target);
            target->cause_typed_damage(target, target->return_target_limb(), roll_dice(6,10), element);
            break;
        case 8..9 : // infect with weakness
	        tell_object(player, "%^C072%^As you strike%^CRST%^ "+targetname+" %^C072%^your staff implants weakness to %^CRST%^"+element+"%^C072%^ on them%^CRST%^");
            tell_object(target, "%^C072%^As%^CRST%^ "+playername+" %^C072%^strikes you with the staff, you feel a rush of weakness to %^CRST%^"+element+" %^C072%^rush over you!%^CRST%^");

            ob = new(OBJ"weak_rune");
			ob->set_weakness(element);
            ob->move(target);
            ob->hurt(target);
            break;
    }
    return damage;
}
