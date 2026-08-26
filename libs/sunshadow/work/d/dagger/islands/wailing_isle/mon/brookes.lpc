// Chernobog & Titania (2/21/22)
// The Wailing Isle - Harbormaster Mister Brookes

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit VENDOR;

int offered, choice;
int delay = COOLDOWN;

void create() {
    ::create();
    set_name("Mister Brookes");
    set_id(({"brookes", "Brookes", "mister brookes", "Mister Brookes", "harbormaster"}));
    set_short("%^CRST%^%^RESET%^%^C062%^Mister Brookes, the H%^C067%^a%^C069%^r%^C068%^b%^C062%^orma%^C068%^s%^C069%^t%^C067%^e%^C062%^r%^RESET%^%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^CRST%^%^RESET%^%^C057%^This %^C055%^rotund figure%^C057%^ jostles his way through the crowded docks, attempting to look %^C055%^official%^C057%^ in a %^C059%^black uniform%^C057%^ that is far too small for his bulging frame. %^C247%^Wiry spectacles%^C057%^ cross his nose, shielding his pinched %^C100%^brown eyes%^C057%^. Tufts of %^C100%^brown hair%^C057%^ blow in the %^C067%^sea breeze%^C057%^ as he bellows out orders, when he isn't surreptitiously sipping %^C101%^rum%^C057%^ from a %^C055%^hidden flask%^RESET%^%^C057%^. He seems to be the man to talk to for those looking for a %^C055%^job%^C057%^.\n%^CRST%^");
    set_gender("male");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_items_allowed("misc");
    set_spoken("common");
    set_storage_room(STOR"brookes_storage");
    offered = 0;
    choice = random(3) + 1;
}

void init(){
    object player, ship, ship_location;
    
    ::init();
    add_action("hit_fun", "hit");
    add_action("test_rep", "list");
    add_action("test_rep", "buy");
    add_action("test_rep", "sell");
    add_action("test_rep", "show");
    
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
    if(player->id("mutt")) force_me("emoteat mutt %^RESET%^%^CRST%^%^C057%^$M gives the mutt an errant kick, sending it whimpering away as it cowers.%^CRST%^");
    if(player->query("wailing isle quest") == 8) call_out("shadow_complete", 1, player);
    if(player->query("reputation wailing isle") > 49 && !player->query("wailing isle brookes")) call_out("max_reward", 1, player);
}

void reset(){
    ::reset();
    offered = 0;
    choice = random(3) + 1;
}

int test_rep(){
    object player;
    int reputation;
    player = this_player();
    reputation = player->query("reputation wailing isle");
    
    if(reputation > 49){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M glances around before beckoning $N closer.%^CRST%^");
        force_me("say This is my personal stockpile, and not for just anyone.");
        return 0;
    }
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M lets out an alcohol-ridden belch before waving $N off.%^CRST%^");
    force_me("say What do I look like? I'm busy!");
    return 1;
}

void max_reward(object player){
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M catches sight of $N, stowing away his flask and waving $O over.%^CRST%^");
    force_me("say You're a proper scoundrel to have around here... so I wanted let you in on some of my private stash of goods that come through. Just between us important nobs, hmm?");
    player->set("wailing isle brookes", 1);
    player->set_mini_quest("The Wailing Isle: A pirate's life for me...", 1, "%^RESET%^%^CRST%^%^C255%^The Wailing Isle: %^RESET%^%^C100%^A %^C144%^pirate's %^C100%^life for me...%^CRST%^");
    return;
}

void catch_say(string str){
    if(!userp(this_player())) return;
    call_out("reply_fun", 1, str, this_player());
}

void reply_fun(string str, object player){
    int reputation, quest;
    reputation = player->query("reputation wailing isle");
    quest = player->query("wailing isle quest");
    
    if(!str) return;
    if(!objectp(player)) return;
    
    if((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )){
        if(reputation < 10){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M gives $N the briefest of glances.%^CRST%^");
            force_me("say Can't you see I'm busy here? If you're looking for work, you'll need to compete with the doxies.");
            return;
        }
        if(reputation < 50){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C247%^$M narrows his eyes, resting a hand against his sizable bulk as he looks $N over.%^CRST%^");
            force_me("say I've started hearing about you... Could be some jobs coming along, if you want to get in with the right nobs.");
            return;
        }
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C247%^$M tugs at a forelock, inclining his head.%^CRST%^");
        force_me("say Greetings, one nob to the other, hmm?");
        return;
    }
    
    if(strsrch(str,"job") != -1 ){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M mutters a curse under his breath before turning towards $N.%^CRST%^");
        if(reputation < 10){
            force_me("say Do I look like I need the help of random wanderers? Go ask the little fish girl, maybe she's too young to be wary of strangers.");
            return;
        }
        switch(quest){
            case 5 :
                force_me("say You were supposed to collect those tax records, aye?");
                return;
                break;
            case 6 :
                force_me("say Did you lose the tax records?");
                return;
                break;
            case 7 :
                force_me("say Have you taken care of that cargo in Shadow yet?");
                return;
                break;
            case 8 :
                force_me("say I heard you took care of that cargo. Well done.");
                return;
                break;
            case 9 :
                force_me("say I seem to be lacking a new set of navigational charts... have you found the Zephyr yet?");
                force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M gives $N a pointed look.");
                return;
                break;
            case 10 :
                force_me("say Tell me you didn't lose those damned charts.");
                return;
                break;
        }
        if((player->cooldown("Wailing Isle jobs")) || quest){
            force_me("say No, nothing at the moment.");
            return;
        }
        force_me("say Perhaps I might have something, now that I think of it...");
        call_out("offer_job", 2);
        return;
    }
    
    if(strsrch(str,"give up") != -1 ){
        if(quest > 4 && quest < 11){
            force_me("say I knew better than to rely on you...");
            force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M grumbles, turning away and sneaking a sip from his flask.");
            player->set("wailing isle quest", 0);
            return;
        }
        force_me("say Well, the Isles are a good place for that, too.");
        return;
    }
    
    if(((strsrch(str,"yes") != -1 ) || (strsrch(str,"Yes") != -1 ) || (strsrch(str,"Sure") != -1 ) || (strsrch(str,"Okay") != -1 ) || (strsrch(str,"sure") != -1 ) || (strsrch(str,"okay") != -1 )) && offered && !quest && !player->cooldown("Wailing Isle jobs") && reputation > 9){
        offered = 0;
        if(choice == 1){
            player->set("wailing isle quest", 5);
            force_me("say Word is they keep the records locked up in a reinforced cabinet. I don't care if you go quietly, or smash your way in. If you want that kind of attention, it's on you.");
        }
        if(choice == 2){
            player->set("wailing isle quest", 7);
            force_me("say Watch yourself, hmm? I don't think the Shadow guards will turn a blind eye to this.");
        }
        if(choice == 3){
            player->set("wailing isle quest", 9);
            force_me("say You'll have to track down the ship, of course. And be careful! Best be quick... like the wind?");
            force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M chuckles to himself.%^CRST%^");
        }
        player->add_cooldown("Wailing Isle jobs", delay);
        choice = random(3) + 1;
        return;
    }
    
    if(strsrch(str,"wailing") != -1 || strsrch(str,"Wailing") != -1 ){
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M glances up towards the cliffs rising up, looming over the small village.%^CRST%^");
        force_me("say Full of superstitious nonsense. They always come back... ha!");
        return;
    }
    
    if(strsrch(str,"tilly") != -1 || strsrch(str,"Tilly") != -1 ){
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M huffs, letting out a derisive snort.%^CRST%^");
        force_me("say Might be she'll grow as pretty as her mother, if that mouth doesn't get her killed first.");
        return;
    }
    
    if(strsrch(str,"kietta") != -1 || strsrch(str,"Kietta") != -1 ){
        force_me("say That damned witch. Claims she peddles in cures and spirits, but it's all superstition... don't believe in her so-called hexes!");
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M scratches at himself a bit nervously, all the same.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"cragur") != -1 || strsrch(str,"Cragur") != -1 ){
        force_me("say I'd love to know who sources that half-breed. He'd do better to get in line with a proper nob like me.");
        return;
    }
    
    if(strsrch(str,"astley") != -1 || strsrch(str,"Astley") != -1 ){
        force_me("say A has-been who dreams of the old days. Frankly, he's only good for serving drinks, and even those taste like watered down garbage!");
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M steals a sip from his flask before tucking it away.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"grace") != -1 || strsrch(str,"Grace") != -1 ){
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M gets a wistful gleam in his eyes.%^CRST%^");
        force_me("say Ah... one of the best. I fancy she considers herself lucky to be one of my favorites.");
        return;
    }
    
    if(strsrch(str,"mae") != -1 || strsrch(str,"Mae") != -1 ){
        force_me("say That old woman spends too much time arguing about the cost of business. Though... the club is a good negotiator.");
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M glances towards the town with a distant look in his eyes.%^CRST%^");
        return;
    }
    
    return;
}

void offer_job(){
    offered = 1;
    switch(choice){
        case 1 :
            force_me("say I have clients who sometimes ship through Torm, but have accrued a backlog of tax owed to the crown. They would like those records... expunged. Are you able to retrieve them from the tax office near the Tormish docks?");
            call_out("refuse_job", 10);
            break;
        case 2 :
            force_me("say Some cargo that was intended to make its way here instead found itself headed to Shadow. I need someone who can ruin it to send a message. A big one, with fire and smoke. Can I count on you to do that?");
            call_out("refuse_job", 10);
            break;
        case 3 :
            force_me("say A little bird has told me that the captain of the Zephyr has come into possession a map of new trade routes that the merchants of Torm will be utilizing. Those are quite valuable to the right buyers, and I think you could profit as well. Can you retrieve those charts?");
            call_out("refuse_job", 10);
            break;
        default :
            tell_object(this_player(), "Something is wrong, contact Chernobog!");
            break;
    }
    return;
}

void shadow_complete(object player){
    int reputation, xp_reward, quest;
    quest = player->query("wailing isle quest");
    reputation = player->query("reputation wailing isle");
    
    if(quest != 8) return;
    
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M lets out a low whistle as he catches sight of $N.%^CRST%^");
    force_me("say ...I'm impressed. I swear I can smell the smoke from here.");
    if(reputation < 50){
        reputation++;
        tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
    }
    else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
    if(reputation > 49) reputation = 50;
    player->set("reputation wailing isle", reputation);
    player->set("wailing isle quest", 0);
    //tell_object(player, "Reputation: "+player->query("reputation wailing isle")+"");
    //tell_object(player, "Quest Marker: "+player->query("wailing isle quest")+"");
        
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M withdraws a small pouch and tosses it to $N.%^CRST%^");
    force_me("say Take this and be off with you.");
    this_object()->add_money("gold", 20000);
    force_me("give 20000 gold coins to "+player->query_name()+"");
        
    xp_reward = exp_for_level(player->query_level() + 1) / 8;
    player->add_exp(xp_reward);
    tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
    return;
}

void receive_given_item(object ob){
    object player;
    int reputation, xp_reward, quest;
    string *ids;
    player = this_player();
    ids = ob->query_id();
    quest = player->query("wailing isle quest");
    reputation = player->query("reputation wailing isle");
    
    if(player->query_hidden() || player->query_invis()){
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M drops it to the ground as he looks about warily.%^CRST%^");
        force_me("say Someone playing tricks? Highly improper!");
        force_me("drop "+ids[0]+"");
        return;
    }
    
    if((ob->id("quest_item_taxes")) && (quest == 6)){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M arches a brow, giving the papers a cursory inspection before stowing them away.%^CRST%^");
        force_me("say Well done. My clients will be happy to know their problems don't exist anymore.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        //tell_object(player, "Reputation: "+player->query("reputation wailing isle")+"");
        //tell_object(player, "Quest Marker: "+player->query("wailing isle quest")+"");
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M withdraws a small pouch and tosses it to $N.%^CRST%^");
        force_me("say Take this and be off with you.");
        this_object()->add_money("gold", 20000);
        force_me("give 20000 gold coins to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("quest_item_map")) && (quest == 10)){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M arches a brow, giving the charts a cursory inspection before stowing them away.%^CRST%^");
        force_me("say Excellent. The bidding for these will be fierce.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        //tell_object(player, "Reputation: "+player->query("reputation wailing isle")+"");
        //tell_object(player, "Quest Marker: "+player->query("wailing isle quest")+"");
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C057%^$M withdraws a small pouch and tosses it to $N.%^CRST%^");
        force_me("say Take this and be off with you.");
        this_object()->add_money("gold", 20000);
        force_me("give 20000 gold coins to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    
    force_me("say I've no interest in that right now.");
    force_me("give "+ids[0]+" to "+player->query_name()+"");
    return 1;
}

void refuse_job(){
    if(offered){
        force_me("say Nevermind, I'll find someone with a bit more spine.");
        force_me("emoteat brookes %^RESET%^%^CRST%^%^C057%^$M lets out a growl, turning his attention to a ship being unloaded and shouting out commands.%^CRST%^");
        offered = 0;
    }
    return;
}
    
int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "brookes" && str != "Brookes" && str != "mister brookes" && str != "Mister Brookes" && str != "harbormaster") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C057%^$M gives $N a wary look, taking a step back.%^CRST%^");
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

