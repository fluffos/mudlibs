// Chernobog & Titania (2/7/22)
// The Wailing Isle - Fishmonger Tilly

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit VENDOR;

int greeted, shook, offered, choice;
int delay = COOLDOWN;

void create() {
    ::create();
    set_name("Tilly");
    set_id(({"tilly", "Tilly", "fishmonger"}));
    set_short("%^RESET%^%^CRST%^%^C109%^Tilly, the %^C103%^Fi%^C109%^sh%^C110%^mo%^C109%^ng%^C103%^er%^RESET%^%^C108%^ %^C103%^G%^C109%^i%^C110%^r%^C109%^l%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C109%^At a full four and a fourth feet tall, %^C070%^eight-year-old%^C109%^ Tilly has a voice that is much larger than she is. She can be heard peddling her %^C035%^fish%^C109%^ to all who pass through the marketplace, often followed by %^C058%^lewd comments%^C109%^ for those who pass without making a purchase. She has %^C250%^fair%^C109%^ but %^C231%^sp%^C230%^lo%^C182%^tc%^C230%^hy %^C231%^sk%^C230%^in%^RESET%^%^C109%^, mean %^C040%^green eyes%^C109%^ and %^C160%^b%^C088%^r%^C160%^ig%^C088%^h%^C160%^t red h%^C088%^a%^C160%^ir%^RESET%^%^C109%^ pulled into two braids. She wears a %^C243%^ra%^C245%^gg%^C247%^ed%^C243%^ gray %^C245%^d%^C247%^r%^C248%^es%^C246%^s%^RESET%^%^C109%^ covered in an %^C245%^apron%^C109%^ smeared with %^C160%^f%^C089%^i%^C160%^sh g%^C089%^u%^C160%^ts%^RESET%^%^C109%^ and other questionable substances.%^CRST%^\n");
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
    force_me("speech shout in a voice twice her size");
    set_storage_room(STOR"tilly_storage");
    greeted = 0;
    shook = 0;
    offered = 0;
    choice = random(2) + 1;
}

void init(){
    object player;
    
    ::init();
    add_action("shake_fun", "shake");
    add_action("hit_fun", "hit");
    
    player = this_player();
    if(player->id("mutt")) force_me("emoteat mutt %^RESET%^%^CRST%^%^C109%^$M lets out a squeal, running over to pet and scratch the mangy mutt.%^CRST%^");
}

void reset(){
    ::reset();
    force_me("emotea tilly %^RESET%^%^CRST%^%^C109%^$M returns her attention to the crawling things in the bin, hawking out offers to a few passersby.%^CRST%^");
    greeted = 0;
    shook = 0;
    offered = 0;
    choice = random(2) + 1;
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
    
    if(((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )) && !greeted){
        //tell_object(player, "Reputation: "+player->query("reputation wailing isle")+"");
        if(reputation < 0){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M ducks behind her cart, peering out at $N.%^CRST%^");
            force_me("say ...the feck do ya want, ya bleedin' sally?");
            greeted = 1;
            return;
        }
        if(reputation < 5){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M wipes a hand on her disgusting smock before holding out a diminutive hand to $N.%^CRST%^");
            force_me("say Right, a proper 'ello! Come ta buy some bloody good fish? It's fresh-ish!");
            greeted = 1;
            shook = 0;
            call_out("check_handshake", 10, player);
            return;
        }
        if(reputation < 15){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M waves $N over.%^CRST%^");
            force_me("say Welcome back fer all yer fishy needs, yeah?");
            greeted = 1;
            return;
        }
        if(reputation < 50){
            force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M flashes a toothy grin, waving a hand.%^CRST%^");
            force_me("say Look at this fecker, eh? How ya been?");
            greeted = 1;
            return;
        }
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M gives $N a rough salute accompanied by a giggle and a grin.%^CRST%^");
        force_me("say Now here's aspirations, eh? I'm gonna be like ya when I grow up!");
        greeted = 1;
        return;
    }
    
    if(((strsrch(str,"ello") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )) && greeted){
        force_me("say Yeah, yeah, we already did that part, ya feckin' barnacle!");
        return;
    }
    
    if((strsrch(str,"job") != -1 ) && greeted){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M folds her little arms across her chest, sizing $N up.%^CRST%^");
        if(quest == 1){
            force_me("say Yer already 'posed ta be finding that blowfish fer me, yeah? Er do ya plan ta give up?");
            return;
        }
        if(quest == 2){
            force_me("say Yer already 'posed ta be finding that swordfish fer me, yeah? Er do ya plan ta give up?");
            return;
        }
        if((player->cooldown("Wailing Isle jobs")) || quest){
            force_me("say Nah, I don't need yer bleedin' help right now.");
            return;
        }
        force_me("say I might have somethin' for ya...");
        call_out("offer_job", 2);
        return;
    }
    
    if((strsrch(str,"give up") != -1 ) && greeted){
        if(quest == 1 || quest == 2){
            force_me("say Well... damnit all! I'll 'ave ta find a new source.");
            player->set("wailing isle quest", 0);
            return;
        }
        force_me("say What the hells are ya botherin' me about?");
        return;
    }
    
    if(((strsrch(str,"yes") != -1 ) || (strsrch(str,"Yes") != -1 ) || (strsrch(str,"Sure") != -1 ) || (strsrch(str,"Okay") != -1 ) || (strsrch(str,"sure") != -1 ) || (strsrch(str,"okay") != -1 )) && greeted && offered && !quest && !player->cooldown("Wailing Isle jobs")){
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M nods, flashing a smile.%^CRST%^");
        force_me("say Aight, I'll be waitin'. Don't drag yer heels, ye bonnie lass.");
        offered = 0;
        if(choice == 1) player->set("wailing isle quest", 1);
        if(choice == 2) player->set("wailing isle quest", 2);
        player->add_cooldown("Wailing Isle jobs", delay);
        choice = random(2) + 1;
        return;
    }
    
    if((strsrch(str,"blowfish") != -1 ) && greeted){
        force_me("say Poisonous as all hells, that's the word. Ye can see 'em in the shallows near the pier sometimes.");
        return;
    }
    
    if((strsrch(str,"swordfish") != -1 ) && greeted){
        force_me("say I hear they're huge with a giant freakin' spear fer a nose! The billy boys see 'em at sea all the time.");
        return;
    }
    
    if((strsrch(str,"fish") != -1 ) && greeted){
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M cracks a grin as she looks over the writhing stock in her bin.%^CRST%^");
        force_me("say Caught 'em all meself. Ya could try yer hand wit' a net if Mama Bear has any made... er ya could just buy wares, eh?");
        return;
    }
    
    if((strsrch(str,"parents") != -1 ) && greeted){
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^ shrugs her little shoulders.%^CRST%^");
        force_me("say I got a mom, I guess. We have a lil' contest 'bout who can reel in more customers, aye?");
        return;
    }
    
    if(((strsrch(str,"mom") != -1 ) || (strsrch(str,"mother") != -1 )) && greeted){
        force_me("say Mine's out workin' her pole on the pier, if ye need ta be knowin'.");
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M waggles her little eyebrows in a disturbing manner.%^CRST%^");
        return;
    }
    
    if(((strsrch(str,"dad") != -1 ) || (strsrch(str,"father") != -1 )) && greeted){
        force_me("say The feck do I need one o' those fer? I got plenty askin' me ta call 'em \"daddy\" already!");
        return;
    }
    
    if((strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )) && greeted){
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M grumbles, shaking a little fist up towards the distant cliffs.%^CRST%^");
        force_me("say If only the weepin' yappy dirt would SHUT UP FOR ONCE!");
        return;
    }
    
    if((strsrch(str,"kietta") != -1 || (strsrch(str,"Kietta") != -1 )) && greeted){
        force_me("say She's a creepy witch, I tells ya! She'll put a pox on ya with her evil bleedin' eye!");
        return;
    }
    
    if((strsrch(str,"astley") != -1 || (strsrch(str,"Astley") != -1 )) && greeted){
        force_me("say He's alright, sneaks me grog sometimes... but that bloody parrot's a feckin' liar!");
        return;
    }
    
    if((strsrch(str,"grace") != -1 || (strsrch(str,"Grace") != -1 )) && greeted){
        force_me("say She's a real beaut, yeah? I hear she's got a weakness fer seamen.");
        return;
    }
    
    if((strsrch(str,"mae") != -1 || (strsrch(str,"Mae") != -1 ) || (strsrch(str,"bear") != -1 ) || (strsrch(str,"Bear") != -1 )) && greeted){
        force_me("say Ol' Mae? She's built like a feckin' giant and good with a club. Dunno why she'd rather run her lil' shop.");
        return;
    }
    
    if((strsrch(str,"cragur") != -1 || (strsrch(str,"Cragur") != -1 )) && greeted){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M narrows her eyes before glancing around furtively.%^CRST%^");
        force_me("say I dunno who yer chattering 'bout, ya barney lummoxes. Mebbe ya need ta scram.");
        return;
    }
    
    if((strsrch(str,"brookes") != -1 || (strsrch(str,"Brookes") != -1 )) && greeted){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M rolls her eyes, sticking out her belly and resting her hands at her hips.%^CRST%^");
        force_me("say Oh, look at me, I'm soooo important even though I'm just a blubbery lush... with a stick up me arse!");
        return;
    }
    
    if(((strsrch(str,"bye") != -1 ) || (strsrch(str,"laters") != -1 )) && greeted){
        if(reputation < 0){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M sticks out her tongue at $N.%^CRST%^");
            force_me("say Aren't ye a polite fecker now?");
            greeted = 0;
            return;
        }
        if(reputation < 5){
            force_me("say I'll try not ta 'ave me heart broken... NEXT!");
            force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M turns her attention to other shoppers moving along the market.%^CRST%^");
            greeted = 0;
            return;
        }
        if(reputation < 15){
            force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M slaps a hand wetly against one of the fish in her cart.%^CRST%^");
            force_me("say We'll be here if ya change yer mind, sally.");
            greeted = 0;
            return;
        }
        if(reputation < 50){
            force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M offers a little wave.%^CRST%^");
            force_me("say See ya 'round. Place would get a lil' dull without ya here.");
            greeted = 0;
            return;
        }
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M fires off another salute towards $N.%^CRST%^");
        force_me("say Don't be taking shite from any mangy bilge-licking manatee feckers!");
        greeted = 0;
        return;
    }
    
    if(!random(3) && !greeted){
        switch(random(8)){
            case 0: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M spits on the ground.%^CRST%^"); break;
            case 1: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M rolls her eyes.%^CRST%^"); break;
            case 2: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M wipes her hands on her stained smock.%^CRST%^"); break;
            case 3: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M slaps a hand on her other arm, bringing up a solitary finger.%^CRST%^"); break;
            case 4: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M balls her fists on her hips.%^CRST%^"); break;
            case 5: force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M flicks a braid over her shoulder.%^CRST%^"); break;
            case 6: force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M screws up her face, mimicking $N... unfavorably.%^CRST%^"); break;
            case 7: force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M brings up both of her fists towards $N, displaying two solitary fingers.%^CRST%^"); break;
        }
        switch(random(13)){
            case 0: force_me("say Curse ye for breathin', ye halfwit."); break;
            case 1: force_me("say Ye couldn't find the pointy end of yer sword, ye feckless maggot!"); break;
            case 2: force_me("say Ye be as witty as a drunken parrot, ye dumb bilge rat!"); break;
            case 3: force_me("say Be that a galleon! No. It be yer mother, ye wretched buffoon!"); break;
            case 4: force_me("say Ye smell of shit an' swine, ye scrappy monkey!"); break;
            case 5: force_me("say I'll cut ye, ye lice-infested, chum-smellin' sea snake!"); break;
            case 6: force_me("say Me parrot has a smaller nose than ye, ye mutinous simpleton!"); break;
            case 7: force_me("say I'll eat yer parrot an' drink yer rum, ye bloody, black-spotted swine!"); break;
            case 8: force_me("say Ye don' need a sword. Yer face be deadlier, ye feculent swabbie!"); break;
            case 9: force_me("say Yer breath be deadlier than yer sword, ye mangy blaggart!"); break;
            case 10: force_me("say Yer breath could kill a kraken, ye nattering cur!"); break;
            case 11: force_me("say I'm more scared of this 'ere dead fish than ye, ye feeble dullard!"); break;
            case 12: force_me("say Ye be as witty as this 'ere rotting fish', ye weak-kneed gob!"); break;
        }
    }
    return;
}

int shake_fun(string str){
    if((str != "tilly") && (str != "fishmonger")) return 0;
    tell_object(this_player(), "%^RESET%^%^CRST%^%^C108%^Ugh... you get a handful of %^C139%^fish guts %^C108%^and %^RESET%^%^C109%^slime%^C108%^.%^CRST%^");
    shook = 1;
    return 0;
}

void check_handshake(object player){
    if(shook) return;
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M withdraws her hand and spits at $np feet.%^CRST%^");
    force_me("say Rude fecker, ain'cha?");
    return;
}

void offer_job(){
    offered = 1;
    force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M wipes her hands off on a dirty patch of her apron before folding her little arms across her chest.%^CRST%^");
    switch(choice){
        case 1 :
            force_me("say Alright, here's the job: I need someone ta find somethin' fer me. Nothin' big, just a lil' blowfish. I've got a special client lookin' ta buy. So, ya interested?");
            call_out("refuse_job", 15);
            break;
        case 2 :
            force_me("say I got a feckin' real gourmet lookin' fer a proper feast, and the chunky monkey wants a huge arse swordfish! And I'm just a lil' girl here, the feck am I supposed ta find one? Help me out?");
            call_out("refuse_job", 15);
            break;
        default :
            tell_object(this_player(), "Something is wrong, contact Chernobog!");
            break;
    }
    return;
}

void refuse_job(){
    if(offered){
        force_me("say Fine, ferget I said a feckin' word.");
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M hawks and spits off to the side.%^CRST%^");
        offered = 0;
    }
    return;
}

void receive_given_item(object ob){
    object player, reward;
    int reputation, xp_reward, quest;
    string *ids;
    player = this_player();
    ids = ob->query_id();
    quest = player->query("wailing isle quest");
    reputation = player->query("reputation wailing isle");
    
    if(player->query_hidden() || player->query_invis()){
        force_me("emoteat tilly %^RESET%^%^CRST%^%^C109%^$M drops it to the ground.%^CRST%^");
        force_me("say What feckin' ghost be tryin' to give me cursed items? I ain't the fool!");
        force_me("drop "+ids[0]+"");
        return;
    }
    
    if((ob->id("quest_item_blowfish")) && (quest == 1)){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M gingerly takes the fish from $N and stows it in a small compartment in her cart.%^CRST%^");
        force_me("say Feckin' hells, yer a prompt sumbitch. I'm gonna remember this!");
        ob->remove();
        if(reputation < 14){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        //tell_object(player, "Reputation: "+player->query("reputation wailing isle")+"");
        //tell_object(player, "Quest Marker: "+player->query("wailing isle quest")+"");
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M snatches something from the corner of her cart and hands it over to $N.%^CRST%^");
        force_me("say It's like... a gift? Whatever, just take it, I don't want it.");
        reward = new(OBJ"jar_of_nasty");
        reward->move(this_object());
        force_me("give jar to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return;
    }
    if((ob->id("quest_item_swordfish")) && (quest == 2)){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M grunts as she takes the fish from $N, heaving it onto her cart.%^CRST%^");
        force_me("say The feck kinda monster is this? I think the sailors be tellin' stories about lengths, ha!");
        ob->remove();
        if(reputation < 14){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle quest", 0);
        
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C109%^$M snatches something from the corner of her cart and hands it over to $N.%^CRST%^");
        force_me("say It's like... a gift? Whatever, just take it, I don't want it.");
        reward = new(OBJ"jar_of_nasty");
        reward->move(this_object());
        force_me("give jar to "+player->query_name()+"");
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return;
    }
    
    force_me("say Why'd I want somefin' like that? Feck off wi' it.");
    force_me("give "+ids[0]+" to "+player->query_name()+"");
    return;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "tilly" && str != "Tilly" && str != "fishmonger") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C109%^$M gives $N a wary look, taking a step back.%^CRST%^");
        return 0;
    }
    this_player()->set("reputation wailing isle", -10);
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

