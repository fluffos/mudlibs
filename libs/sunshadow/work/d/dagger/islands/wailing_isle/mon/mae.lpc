// Chernobog & Titania (2/2/22)
// The Wailing Isle - Shopkeeper Mae

#include <std.h>
#include "../defs.h"
inherit VENDOR;

int offered, choice;
int delay = COOLDOWN;

void create() {
    ::create();
    set_name("Mae");
    set_id(({"mae", "Mae", "shopkeeper"}));
    set_short("%^RESET%^%^CRST%^%^C137%^Mae %^C101%^\"The Bear\"%^C137%^, the %^C138%^Ge%^C137%^ner%^C138%^al Sho%^C137%^pkee%^C138%^per%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C103%^Mae keeps a %^C098%^careful watch%^C103%^ over her wares with her %^C098%^one good eye%^C103%^. She is a %^C102%^gruff woman%^C103%^, large in stature with %^C244%^w%^C247%^i%^C249%^l%^C250%^d %^C251%^g%^C252%^ra%^C251%^y %^C250%^h%^C249%^a%^C247%^i%^C244%^r%^RESET%^%^C103%^ that she keeps cut short, and the %^C138%^ro%^C095%^u%^C138%^gh%^C103%^ type of %^C138%^s%^C095%^k%^C138%^in%^C103%^ one only earns through decades of %^C102%^hard living%^C103%^. Word around town is that they call her %^C101%^\"The Bear\"%^C103%^ and there's little doubt she lives up to this name. Neither she nor the %^C059%^s%^C058%^p%^C059%^ik%^C058%^e%^C059%^d cl%^C058%^u%^C059%^b%^RESET%^%^C103%^ she carries look like something you'd want to cross paths with out in the wild.%^CRST%^\n");
    set_gender("female");
    set_alignment(8);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_items_allowed("misc");
    set_spoken("common");
    force_me("speech speak loudly, with a bit of grit in her voice");
    set_storage_room(STOR"mae_storage");
    offered = 0;
    choice = random(2) + 1;
}

void init(){
    object player, ship, ship_location;
    
    ::init();
    add_action("hit_fun", "hit");
    
    ship = find_object_or_load("/d/dagger/islands/wailing_isle/obj/zephyr");
    if(!environment(ship)){
        switch(random(4)){
            case 0 : ship_location = find_object_or_load("/d/shadow/virtual/sea/shadow.dock"); break;
            case 1 : ship_location = find_object_or_load("/d/shadow/virtual/sea/torm.dock"); break;
            case 2 : ship_location = find_object_or_load("/d/shadow/virtual/sea/serakii.dock"); break;
            case 3 : ship_location = find_object_or_load("/d/shadow/virtual/sea/undead.dock"); break;
        }
        ship->move(ship_location);
    }
    
    player = this_player();
    if(player->id("mutt")){
        force_me("emoteat mutt %^RESET%^%^CRST%^%^C103%^$M lets out a low growl, stepping from around the corner to shoo the mutt away.%^CRST%^");
        force_me("say Get away from there!");
    }
}

void reset(){
    ::reset();
    choice = random(2) + 1;
}

void catch_say(string str){
    if(!userp(this_player())) return;
    call_out("reply_fun", 1, str, this_player());
}

void reply_fun(string str, object player){
    int reputation, quest;
    object ob;
    reputation = player->query("reputation wailing isle");
    quest = player->query("wailing isle quest");
    
    if(!str) return;
    if(!objectp(player)) return;
    
    if(strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )){
        force_me("say You'd think you'd get used to the sound, after a lifetime... but even with that, there's something about this place. It feels like this is where you belong.");
        return;
    }
    
    if((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )){
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M offers a curt nod and a grunt.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"job") != -1 ){
        if(quest == 11){
            force_me("say You said you'd track down the Zephyr and find my cargo, didn't you?");
            return;
        }
        if(quest == 12){
            force_me("say To be blunt... where's my rum?");
            return;
        }
        if(quest == 13){
            force_me("say Hunting down that ink isn't enough?");
            return;
        }
        if((player->cooldown("Wailing Isle jobs")) || quest || reputation < 10){
            force_me("say I've heard the harbormaster has some jobs here and there, but you need to be known. He's paranoid, in his way.");
            return;
        }
        if(player->query("wailing isle betrayed mae")){
            force_me("You already taught me to lack any faith in you. Bother someone else.");
            return;
        }
        force_me("say Actually...");
        call_out("offer_job", 2);
        return;
    }
    
    if(strsrch(str,"give up") != -1 ){
        if(quest == 11){
            force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M lets out a low grumble, slamming a fist on the the counter.%^CRST%^");
            force_me("say FINE! I'll look for someone with a spine, next time.");
            player->set("wailing isle quest", 0);
            return;
        }
        if(quest == 12){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C103%^$M narrows her eyes at $N.%^CRST%^");
            force_me("say I already heard the cargo went missing. Funny how that works... but I've learned my lesson.");
            player->set("wailing isle quest", 0);
            player->set("wailing isle betrayed mae", 1);
            return;
        }
        if(quest == 13){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C103%^$M sighs at $N, pinching the bridge of her nose.%^CRST%^");
            force_me("say If you want something done right... fine.");
            player->set("wailing isle quest", 0);
            return;
        }
        force_me("say What the hells are ya botherin' me about?");
        return;
    }
    
    if(((strsrch(str,"yes") != -1 ) || (strsrch(str,"Yes") != -1 ) || (strsrch(str,"Sure") != -1 ) || (strsrch(str,"Okay") != -1 ) || (strsrch(str,"sure") != -1 ) || (strsrch(str,"okay") != -1 )) && offered && !quest && !player->cooldown("Wailing Isle jobs") && !player->query("wailing isle betrayed mae") && reputation > 9){
        if(choice == 1){
            force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M stands up, slapping a hand down on the counter.%^CRST%^");
            force_me("say Don't forget: a crate of rum from the Zephyr.");
            player->set("wailing isle quest", 11);
        }
        if(choice == 2){
            force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M passes over a small bottle full of some foul smelling liquid.%^CRST%^");
            force_me("say Remember, you'll want to pour this when you're out in deep water. Good luck getting that ink!");
            player->set("wailing isle quest", 13);
            ob = new(OBJ"kraken_bait");
            ob->move(this_object());
            force_me("give bait to "+player->query_name()+"");
        }
        offered = 0;
        player->add_cooldown("Wailing Isle jobs", delay);
        choice = random(2) + 1;
        return;
    }
    
    if(strsrch(str,"tilly") != -1 || strsrch(str,"Tilly") != -1 ){
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M lets out a sharp bark of a laugh.%^CRST%^");
        force_me("say That little brat... her mouth is the biggest in the village. And her fish stinks.");
        return;
    }
    
    if(strsrch(str,"kietta") != -1 || strsrch(str,"Kietta") != -1 ){
        force_me("say Ah, she's got some strange requests. How the hell am I supposed to find unicorn parts, hmm?");
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M laughs with a faint shake of her head.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"cragur") != -1 || strsrch(str,"Cragur") != -1 ){
        force_me("say Sometimes I wonder if there's too much orc there.");
        return;
    }
    
    if(strsrch(str,"astley") != -1 || strsrch(str,"Astley") != -1 ){
        force_me("say You'd never know he used to be feared on the seas. Now he just grumbles about the cost of running his little bar and dreaming of the old days.");
        return;
    }
    
    if(strsrch(str,"brookes") != -1 || strsrch(str,"Brookes") != -1 ){
        force_me("say Full of piss and wind. And you'd be amazed at how much of your cargo gets delayed unless you toss him a silver or two.");
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M grumbles a bit, eyeing the spiked club leaning nearby against the counter.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"grace") != -1 || strsrch(str,"Grace") != -1 ){
        force_me("say She looks delicate, but that girl's got some steel to her.");
        return;
    }
    
    if(strsrch(str,"zephyr") != -1 || strsrch(str,"Zephyr") != -1 ){
        force_me("say Ah, the Zephyr. A merchant ship that runs the shipping lanes between city ports around the Dagger and Saakrune Sea, though I hear it's from Djyaristan originally.");
        return;
    }
    
    return;
}

void offer_job(){
    offered = 1;
    force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M leans forward against the counter, glancing about the shop for a wary moment.%^CRST%^");
    switch(choice){
        case 1 :
            force_me("say Rum has been hard to source, but I heard there's a shipment of it aboard a ship called the Zephyr. I'm not sure where she's docked, but you seem like the type that can get around. Can I count on you for a favor?");
            break;
        case 2 :
            force_me("say Kietta's looking for a special kind of ink from a special source, and I can't get away for the hunting. If I give you the bait, can you bring it in? I'll give you a cut of money for the work.");
            break;
        default :
            message("debug", "Something went wrong, please contact Chernobog.", environment(this_object()));
    }
    call_out("refuse_job", 15);
    return;
}

void refuse_job(){
    if(offered){
        force_me("say Nevermind then.");
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M pushes away from the counter with a grunt.%^CRST%^");
        offered = 0;
    }
    return;
}

void receive_given_item(object ob){
    object player, reward, reward2, reward3;
    int reputation, xp_reward, quest;
    string *ids;
    player = this_player();
    ids = ob->query_id();
    quest = player->query("wailing isle quest");
    reputation = player->query("reputation wailing isle");
    
    if(player->query_hidden() || player->query_invis()){
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M tosses it on the counter.%^CRST%^");
        force_me("say I'm not going to play these games. Show yourself if you want to deal.");
        force_me("drop "+ids[0]+"");
        return;
    }
    
    if((ob->id("quest_item_crate")) && (quest == 12)){
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M easily hoists up the crate and sets it behind the counter.%^CRST%^");
        force_me("say It's one thing to hope, another to trust. Here... a token of gratitude.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C103%^$M kneels down to crack open the case, grabbing a pair of bottles and passing them over to $N%^CRST%^");
        reward = new(OBJ"rum_bottle");
        reward->move(this_object());
        force_me("give rum bottle to "+player->query_name()+"");
        reward = new(OBJ"rum_bottle");
        reward->move(this_object());
        force_me("give rum bottle to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("quest_item_ink")) && (quest == 13)){
        force_me("emoteat mae %^RESET%^%^CRST%^%^C103%^$M accepts the leaking gland, dropping it into an empty crate.%^CRST%^");
        force_me("say That should keep her stocked for a bit, I think! And I feel like you need this, after going through all that.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C103%^$M tosses a small pouch towards $N.%^CRST%^");
        this_object()->add_money("gold", 20000);
        force_me("give 20000 gold coins to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    
    force_me("say I don't think I have any use for that.");
    force_me("give "+ids[0]+" to "+player->query_name()+"");
    return 1;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "mae" && str != "Mae" && str != "shopkeeper") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C103%^$M gives $N a wary look, taking a step back.%^CRST%^");
        return 0;
    }
    this_player()->set("reputation wailing isle", -10);
    return 0;
}

void die(){
    object room, npc;
    object* attackers;
    int i;
    
    npc = this_object();
    room = environment(npc);
    attackers = npc->query_attackers();
    
    for(i = 0; sizeof(attackers), i < sizeof(attackers); i++){
        if (!objectp(attackers[i])) continue;
        if (userp(attackers[i])) {
            attackers[i]->set("reputation wailing isle", -10);
            continue;
        }
        continue;
    }
    ::die();
}

