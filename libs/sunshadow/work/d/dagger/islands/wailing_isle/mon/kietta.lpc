// Chernobog & Titania (2/7/22)
// The Wailing Isle - Voodoo Herbalist Kietta

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit VENDOR;

int greeted, offered, waking, choice;
int delay = COOLDOWN;

void create() {
    ::create();
    set_name("Kietta");
    set_id(({"kietta", "Kietta", "herbalist", "voodoo herbalist"}));
    set_short("%^RESET%^%^CRST%^%^C101%^Kietta, Voodoo Herbalist%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C101%^A thin veil of %^C094%^d%^C100%^us%^C094%^ky s%^C100%^ki%^C094%^n%^RESET%^%^C101%^ covers the curve of Kietta's bones beneath. Her face is marked by a %^C059%^black tattoo%^RESET%^%^C101%^ that begins at her right eye and arcs down to her cheek, ending in a slight curve where a %^C243%^cr%^C244%^es%^C245%^ce%^C246%^nt %^C245%^mo%^C244%^o%^C243%^n%^RESET%^%^C101%^ is nestled. Her face is gaunt and aged, with a squat nose and %^C102%^thick dark lips%^C101%^, and a %^C195%^b%^C253%^o%^C195%^ne ri%^C253%^n%^C195%^g%^RESET%^%^C101%^ pierces through the center of her bottom lip. Her thick hair falls in %^C102%^k%^C059%^n%^C101%^o%^C102%^tt%^C059%^y d%^C102%^re%^C059%^a%^C101%^d%^C102%^s%^RESET%^%^C101%^ of varying lengths and laced with %^C250%^br%^C248%^it%^C247%^tl%^C245%^e %^C243%^gr%^C245%^a%^C247%^y %^C250%^h%^C248%^a%^C247%^ir%^C245%^s%^RESET%^%^C101%^, some of the strands dangling down to touch the small %^C059%^obsidian shard%^C101%^ that glimmers on her brow. Her %^C245%^da%^C244%^r%^C243%^k gray %^C243%^e%^C244%^y%^C245%^es%^RESET%^%^C101%^ seem aloof, tending to gaze through people and things rather than at them directly.%^CRST%^\n");
    set_gender("female");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_items_allowed("misc");
    set_spoken("common");
    force_me("speech murmur in a calm, cool drawl");
    set_storage_room(STOR"kietta_storage");
    greeted = 0;
    offered = 0;
    waking = 0;
}

void init(){
    object player;
    
    ::init();
    add_action("hit_fun", "hit");
    add_action("test_awake", "buy");
    add_action("test_awake", "sell");
    add_action("test_awake", "list");
    add_action("test_awake", "show");
    
    player = this_player();
    if(player->id("mutt")){
        if(!greeted) force_me("emoteat mutt %^RESET%^%^CRST%^%^C101%^$M cracks an eye open, watching the mutt roam the shop as it sniffs at the various oddities.%^CRST%^");
        if(greeted) force_me("emoteat mutt %^RESET%^%^CRST%^%^C101%^A soft chuckle shakes $M as she watches the mutt roams the shop, sniffing at the various oddities.%^CRST%^");
    }
}

int test_awake(){
    if(greeted) return 0;
    
    tell_object(this_player(), "%^RESET%^%^CRST%^%^C059%^The shop keeper seems deep in meditation.%^CRST%^");
    return 1;
}

void reset(){
    ::reset();
    force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M closes her eyes, inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
    greeted = 0;
    offered = 0;
    waking = 0;
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
    
    if(((strsrch(str,"ello") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )) && greeted){
        force_me("say Yes, yes... I be hearing you.");
        return;
    }
    
    if((strsrch(str,"job") != -1 ) && greeted){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M turns her eyes on $N, narrowing them skeptically.%^CRST%^");
        if(quest == 3){
            force_me("say Be you forgetting dat you promised to be gattering de bone dust? Or will you give up?");
            return;
        }
        if(quest == 4){
            force_me("say De great willow be waiting, just as I be waiting for de powerful reagent.");
            return;
        }
        if((player->cooldown("Wailing Isle jobs")) || quest){
            force_me("say De spirits say your path lay elsewhere, for now.");
            return;
        }
        force_me("say Dere be a matter, yes...");
        call_out("offer_job", 2);
        return;
    }
    
    if((strsrch(str,"give up") != -1 ) && greeted){
        if(quest == 3 || quest == 4){
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M purses her lips, letting out a quiet sigh with a shake of her head.%^CRST%^");
            force_me("say You be abandoning de will of de spirits.");
            player->set("wailing isle quest", 0);
            if(objectp(ob = present("unicorn_bait", player))){
                force_me("say I be taking dis back den.");
                force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M snaps her fingers and $np runed vial disappears.%^CRST%^");
                ob->remove();
            }
            return;
        }
        force_me("say What would you be giving up now?");
        return;
    }
    
    if(((strsrch(str,"yes") != -1 ) || (strsrch(str,"Yes") != -1 ) || (strsrch(str,"Sure") != -1 ) || (strsrch(str,"Okay") != -1 ) || (strsrch(str,"sure") != -1 ) || (strsrch(str,"okay") != -1 )) && greeted && offered && !quest && !player->cooldown("Wailing Isle jobs")){
        if(choice == 1 ){
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M nods, flashing a smile.%^CRST%^");
            force_me("say Dis be good news. May de spirits see you trough and back wit de dust.");
            player->set("wailing isle quest", 3);
            offered = 0;
            player->add_cooldown("Wailing Isle jobs", delay);
        }
        if(choice == 2 && reputation > 9 ){
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M flashes a smile and bows her head.%^CRST%^");
            force_me("say Here be de proper bait fer such prey. Go to de Moonstone Vale where de fey spill into our world, and sprinkle de blood at de base of de great willow tree.");
            ob = new(OBJ"unicorn_bait");
            ob->move(this_object());
            force_me("give blood to "+player->query_name()+"");
            player->set("wailing isle quest", 4);
            offered = 0;
            player->add_cooldown("Wailing Isle jobs", delay);
        }
        
        return;
    }
    
    if((strsrch(str,"unicorn") != -1 ) && greeted){
        force_me("say Unicorns? Dey be full of power, especially in de horn. Full of de life energies.");
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M lets out a long sigh.%^CRST%^");
        if(reputation < 10){
            force_me("say It be some time since I be having powdered horn in me collection.");
            return;
        }
        if(quest == 4){
            force_me("say You have not yet returned de horn from de Moonstone Vale. Are you giving up on de spirits now?");
            return;
        }
        if(quest || player->cooldown("Wailing Isle jobs")){
            force_me("say It be some time since I be having powdered horn in me collection. Maybe you be helping me wit dis when ye aren't so preoccupied?");
            return;
        }
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M studies $N shrewdly for a moment, brushing her thumbs over her fingertips.%^CRST%^");
        call_out("offer_unicorn", 2);
        return;
    }
    
    if((strsrch(str,"bone dust") != -1 ) && greeted){
        force_me("say De dust from any restless dead be good as a focus for summoning de spirits. It be bound with energies of de dead.");
        return;
    }
    
    if((strsrch(str,"incense") != -1 ) && greeted){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M breathes in deeply, wafting the smoke towards her face.%^CRST%^");
        force_me("say It calms de mind, and is a bridge for de higher thoughts.");
        return;
    }
    
    if((strsrch(str,"mushroom") != -1 ) && greeted){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M smiles, revealing a couple blackened teeth.%^CRST%^");
        force_me("say Dere be some dat open de world to you. And some dat show you de horrors dat lay hidden. Dey be for dose who de spirits favor.");
        return;
    }
    
    if((strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )) && greeted){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M smiles softly, turning to glance at the cliffs through a window.%^CRST%^");
        force_me("say You can hear de cries of de spirits on de wind here. It be a sacred place, de Isle, a place where de barrier between de living and de dead be weak. And de Isle, it calls...");
        return;
    }
    
    if((strsrch(str,"salve") != -1 ) && greeted){
        if(player->query("wailing isle grace") == 1){
            force_me("say Ah, de spirits be telling me Grace be in de trouble again. Remind de girl to look before she leap, next time.");
            force_me("emoteat "+player->query_name()+" $M retrieves a small tin from a battered drawer.%^CRST%^");
            ob = new(OBJ"salve");
            ob->move(this_object());
            force_me("give salve to "+player->query_name()+"");
            player->set("wailing isle grace", 2);
            return;
        }
        force_me("say De girls along de wharf be keeping me busy making salves. A hazard of de profession, alas.");
        return;
    }
    
    if((strsrch(str,"tilly") != -1 || (strsrch(str,"Tilly") != -1 )) && greeted){
        force_me("say Ahh, dat girl certainly be full of de spirit. A pity her mout be running off from her.");
        return;
    }
    
    if((strsrch(str,"astley") != -1 || (strsrch(str,"Astley") != -1 )) && greeted){
        force_me("say Many of de spirits be knowing him... him being de last dey saw in life.");
        return;
    }
    
    if((strsrch(str,"grace") != -1 || (strsrch(str,"Grace") != -1 )) && greeted){
        force_me("say Light and dark be swirling in her dear heart. She be a complex one, seeking de wisdom of de spirits often.");
        return;
    }
    
    if((strsrch(str,"mae") != -1 || (strsrch(str,"Mae") != -1 )) && greeted){
        force_me("say She be lacking some of de more exotic reagents I be needing, but a good woman oderwise.");
        return;
    }
    
    if((strsrch(str,"cragur") != -1 || (strsrch(str,"Cragur") != -1 )) && greeted){
        force_me("say Shunned by many for de taint in him blood... but useful, for finding strange and rare tings.");
        return;
    }
    
    if((strsrch(str,"brookes") != -1 || (strsrch(str,"Brookes") != -1 )) && greeted){
        force_me("say A man who be full of himself, drinking him courage and ignoring de warnings of de spirits.");
        return;
    }
    
    if(((strsrch(str,"bye") != -1 ) || (strsrch(str,"laters") != -1 )) && greeted){
        if(reputation < 0){
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M doesn't bother to reply, closing her eyes and inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
            greeted = 0;
            waking = 0;
            return;
        }
        if(reputation < 5){
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M watches suspiciously before closing her eyes, inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
            greeted = 0;
            waking = 0;
            return;
        }
        if(reputation < 15){
            force_me("say Let me know if you be needing anyting.");
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M closes her eyes, inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
            greeted = 0;
            waking = 0;
            return;
        }
        if(reputation < 50){
            force_me("say De spirits guide your path.");
            force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M closes her eyes, inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
            greeted = 0;
            waking = 0;
            return;
        }
        force_me("say Ye be tied to de spirits of de Isle... and dey be watching out for you.");
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M bows her head and closes her eyes, inhaling deeply of the wafting incense as she returns to her meditations.%^CRST%^");
        greeted = 0;
        waking = 0;
        return;
    }
    
    if(!greeted){
        if(reputation < 5){
            switch(waking){
                case 0 : 
                    force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M hums lightly to herself, her eyes closed in meditation.%^CRST%^");
                    waking++;
                    break;
                case 1 : 
                    force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M frowns, her brow furrowing in irritation.%^CRST%^");
                    waking++;
                    break;
                case 2 : 
                    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M blinks her eyes open, taking a moment to focus on $N.%^CRST%^"); 
                    force_me("say Ah, de spirits and I welcome you to me shop.");
                    greeted = 1;
                    break;
            }
            return;
        }
        if(reputation < 15){
            switch(waking){
                case 0 :
                    force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M hums lightly to herself, her eyes closed in meditation.%^CRST%^");
                    waking++;
                    break;
                case 1 :
                    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M blinks her eyes open, taking a moment to focus on $N.%^CRST%^"); 
                    force_me("say Welcome back, traveler. How may de spirits and I be helping you?");
                    greeted = 1;
                    break;
            }
            return;
        }
        if(reputation < 50){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M blinks her eyes open, a smile gracing her lips as she focuses on $N.%^CRST%^"); 
            force_me("say De spirits be guiding you back, me dear one.");
            greeted = 1;
            return;
        }
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M breaks into a grin, even before opening her eyes to focus on $N.%^CRST%^");
        force_me("say I be knowing dat voice even in me dreams. De spirits smile on you again.");
        greeted = 1;
        if(player->query("reputation wailing isle") > 49 && !player->query("wailing isle kietta")) call_out("max_reward", 1, player);
        return;
    }
    
    return;
}

void max_reward(object player){
    object reward;
    string owner;
    
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C101%^$M beckons $N closer, retrieving a small parcel from beneath the counter.%^CRST%^");
    force_me("say Me darling, you be deserving of some of me more powerful charms... and so here be a compass for you. Touch de needle of de compass, and it be bringing you back 'ere to us.");
    reward = new(OBJ"voodoo_compass");
    reward->move(this_object());
    owner = player->query_name();
    reward->set_owner(owner);
    force_me("give compass to "+owner+"");
    player->set("wailing isle kietta", 1);
    return;
}

void offer_job(){
    offered = 1;
    choice = 1;
    force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M touches her fingertips to the small gem at her forehead for a thoughtful moment.%^CRST%^");
    force_me("say Dere be questions I have for de spirits dat surround us. But I lack de proper focus for me meditations: Bone dust from de restless dead... will you be de one to deliver it?");
    call_out("refuse_job", 15);
    return;
}

void offer_unicorn(){
    offered = 1;
    choice = 2;
    force_me("say De spirits feel you be able, and a strong lure I be having. Will you go to de Moonstone Vale and bring back de horn of a unicorn?");
    call_out("refuse_job", 15);
    return;
}

void refuse_job(){
    if(offered){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M turns her attention to a few hanging bundles of herbs.%^CRST%^");
        force_me("say Dere will be oters. You can avoid de call for now.");
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
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M carefully sets it on the counter.%^CRST%^");
        force_me("say Spirits, I only be accepting dis gift if you reveal yourself to me.");
        force_me("drop "+ids[0]+"");
        return;
    }
    
    if((ob->id("bone dust")) && (quest == 3)){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M accepts the small pouch of dust with a bow of her head.%^CRST%^");
        force_me("say Dis one accepts your benevolence.");
        ob->remove();
        if(reputation < 14){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M ducks below the counter to retrieve a small pot, opening it up carefully.%^CRST%^");
        force_me("say Dis will open your mind to tings unseen. May it lead you to hidden wisdom.");
        reward = new(OBJ"mushroom");
        reward->move(this_object());
        force_me("give mushroom to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("quest_item_horn")) && (quest == 4)){
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M accepts the horn, holding it up to the light and admiring it with a sly grin.%^CRST%^");
        force_me("say And now me rituals wit de spirits be getting stronger.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        
        force_me("emoteat kietta %^RESET%^%^CRST%^%^C101%^$M ducks below the counter to retrieve a small pot, opening it up carefully.%^CRST%^");
        force_me("say Dese will open your mind to tings unseen. May dey lead you to hidden wisdom.");
        reward = new(OBJ"mushroom");
        reward->move(this_object());
        force_me("give mushroom to "+player->query_name()+"");
        reward2 = new(OBJ"mushroom");
        reward2->move(this_object());
        force_me("give mushroom to "+player->query_name()+"");
        reward3 = new(OBJ"mushroom");
        reward3->move(this_object());
        force_me("give mushroom to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("quest_item_ink"))){
        force_me("say Hmm... I could use dis, but I already have a deal wit Mae.");
        force_me("give "+ids[0]+" to "+player->query_name()+"");
        return 1;
    }
    
    force_me("say I tink you have a greater need for dis.");
    force_me("give "+ids[0]+" to "+player->query_name()+"");
    return 1;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "kietta" && str != "Kietta" && str != "herbalist" && str != "voodoo herbalist") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C101%^$M gives $N a wary look, taking a step back.%^CRST%^");
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

