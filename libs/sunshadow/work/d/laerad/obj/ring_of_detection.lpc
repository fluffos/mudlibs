#include <std.h>
inherit ARMOUR;

int charges, detecting;

void create(){
    ::create();
    set_id(({"ring", "gray ring", "grey ring", "ring of detection"}));
    set_name("ring of detection");
    set_obvious_short("an ordinary gray ring");
    set_short("ring of detection");
    set_long("%^RESET%^%^BOLD%^This ring appears to be fashioned from a cheap band of steel. The simple worksmanship has imbued the ordinary band of metal with only one frill: the single groove that runs around the outside of the entire circumference. The groove of the ring appears to be filled with an almost indistinguishable amount of some mercurial substance. If one squints and looks close enough they could see tiny movements of images ghosting across the surface of the thin rivulet.\nThere is something inscribed on the inside of the ring.%^RESET%^");
    set_lore("%^RESET%^%^CYAN%^The ring of detection is rumored to have been created by the ailing Arch Mage Dophiriciese. In the last years of his life he contracted a terrible wasting disease during his studies and could not venture forth from his tower for fear of spreading the illness to others. Several townsfolk from the local village that the mage had watched over for years volunteered to help him find the ingredients that he needed to cure his illness.  The townsfolk, however, lacked the magical aptitude to see the properties of the items that Dophiriciese needed.  Never one to give up without trying, the Arch Mage created many of these rings and gave them to the villagers so that they could help him find his antidote. The rest of the story, along with Dophiriciese's fate has been lost to time.%^RESET%^");
    set_type("ring");
    set_weight(1);
    set_value(500);
    set_language("common");
    set_read("You need only <gaze> upon the reagents to detect their magical properties.");
    set_limbs(({"right hand", "left hand"}));
    charges = (random(16)+5);
    detecting = 0;
    set_property("treasure_type", "20B");
    set_remove((:this_object(), "remove_fun":));
}

void init(){
    ::init();
    add_action("detect_stuff", "gaze");
}

int detect_stuff(string str){
    object player = this_player();
    
    if(str) return 0;
    if (player->query_bound() || player->query_unconscious()){
        player->send_paralyzed_message("info", player);
        return 1;
    }
    if(charges == 0){
        message("info", "The ring seems to be depleted.", player);
        return 1;
    }
    if(!query_worn()){
        message("info", "You must be wearing the ring.", player);
        return 1;
    }
    if(detecting){
        message("info", "Your ring is already active.", player);
        return 1;
    }

    message("environment", "%^RESET%^%^CRST%^%^C255%^%^You start to detect the %^C033%^a%^C039%^u%^C045%^r%^C039%^a%^C033%^s %^RESET%^%^C255%^of magic around you.%^CRST%^", player);
    player->set_detecting_magic(1);
    detecting = 1;
    call_out("detect_end", 600, player);
    charges -= 1;
    return 1;    
}

void detect_end(object player){
    message("environment", "%^RESET%^%^CRST%^%^C255%^Your vision returns to normal, and the world seems a little less vibrant.%^CRST%^", player);
    player->set_detecting_magic(0);
    detecting = 0;
    return;
}

int remove_fun(){
    object player = environment(this_object());
    if(detecting){
        message("environment", "%^RESET%^%^CRST%^%^C255%^Your vision returns to normal, and the world seems a little less vibrant.%^CRST%^", player);
        player->set_detecting_magic(0);
        detecting = 0;
        remove_call_out("detect_end");
    }
    return 1;
}

