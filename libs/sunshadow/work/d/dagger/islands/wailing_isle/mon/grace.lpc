// Chernobog & Titania (3/2/22)
// The Wailing Isle - Harlot Grace Atherton

#include <std.h>
#include "../defs.h"
inherit NPC;

int offered, choice;

void create() {
    ::create();
    set_name("Grace");
    set_id(({"grace", "grace atherton", "Grace", "Grace Atherton", "harlot"}));
    set_short("%^CRST%^%^RESET%^%^C183%^Grace Atherton%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C183%^Grace is a %^C176%^petite woman%^C183%^ in her late twenties. A %^C143%^drab %^C132%^si%^C126%^lk%^C132%^en dr%^C162%^e%^C244%^s%^C132%^s%^RESET%^%^C183%^ hangs loose from her slender frame, the %^C132%^co%^C126%^rs%^C132%^et t%^C126%^o%^C132%^p%^RESET%^%^C183%^ putting her %^C188%^ample bosom%^C183%^ on display. Her %^C094%^d%^C100%^a%^C094%^rk bro%^C100%^w%^C094%^n c%^C100%^u%^C094%^rls%^C183%^ are pulled into a loose topknot, a few strands left to fall teasingly around her comely face and along the nape of her neck. With %^C169%^full lips%^RESET%^%^C183%^, a dusting of %^C101%^freckles%^C183%^, and %^C045%^oc%^C039%^ea%^C033%^n-b%^C039%^lu%^C045%^e e%^C039%^ye%^C033%^s%^RESET%^%^C183%^, she is remarkably attractive beneath the basic %^C243%^neglect%^C183%^ of well-being that has worked its way into everything and everyone around here.%^CRST%^\n");
    set_gender("female");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_spoken("common");
    force_me("speech ha a slight slur to her words");
    force_me("pose %^RESET%^%^CRST%^%^C183%^seated at the bar%^CRST%^");
}

void init(){
    ::init();
    add_action("hit_fun", "hit");
}

void catch_say(string str){
    if(!userp(this_player())) return;
    call_out("reply_fun", 1, str, this_player());
}

void reply_fun(string str, object player){
    int reputation, quest;
    object ob;
    reputation = player->query("reputation wailing isle");
    quest = player->query("wailing isle grace");
    
    if(!str) return;
    if(!objectp(player)) return;
    
    if(strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )){
        call_out("wailing_reply", 2, player);
        return;
    }
    
    if(strsrch(str,"job") != -1 ){
        switch(quest){
            case 0:
                force_me("say Be a dear and see if my soothsayer has my salve ready for me? I'm simply enjoying myself too much here.");
                force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M raises her glass again, taking a long drink.%^CRST%^");
                player->set("wailing isle grace", 1);
                break;
            case 1:
                force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M shifts a little uncomfortably in her seat.%^CRST%^");
                force_me("say I could still use that salve from the herbalist.");
                break;
            case 2:
                force_me("say Did you lose the salve? I could really use some...");
                break;
            case 3:
                force_me("say My soothsayer claims my... affliction... comes from those who've mistreated me in the past. I just need to find someone to bring that hook from the bastard Captain Rust, and she'll cook up a voodoo hex!");
                break;
            case 4:
                force_me("say The next token I need is from another foul excuse for a man. He doesn't even rut in the proper channels, if you get my drift. I'll be needing a keepsake from Captain Rolon: his fancy silver chainmail.");
                break;
            case 5:
                force_me("say The last piece I need is a blade of beauty, from a man just as beautiful. If only his mouth wouldn't sour everything with his arrogance. He wouldn't be the first Tormish noble to enjoy a three copper upright with a doxie.");
                break;
            default:
                force_me("say No, thank you... you've already done so much for me. I'm promised that this hex will give me all the revenge I need!");
        }
        return;
    }
    
    if(strsrch(str,"lost") != -1 ){
        if(quest == 2){
            force_me("say Oh, she's in high demand out here... perhaps she'll have more the next time you're in her shop.");
            player->set("wailing isle grace", 1);
        }
        return;
    }
    
    if(strsrch(str,"tilly") != -1 || strsrch(str,"Tilly") != -1 ){
        call_out("tilly_reply", 2, player);
        return;
    }
    
    if(strsrch(str,"kietta") != -1 || strsrch(str,"Kietta") != -1 ){
        call_out("kietta_reply", 2, player);
        return;
    }
    
    if(strsrch(str,"cragur") != -1 || strsrch(str,"Cragur") != -1 ){
        force_me("say Mmmm... he's a good man to have over you. Very supportive.");
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C183%^$M offers $N a quick wink.%^CRST%^");
        return;
    }
    
    if(strsrch(str,"astley") != -1 || strsrch(str,"Astley") != -1 ){
        force_me("say The Captain is good at keeping an ear out for gossip. If you're eager to make a name for yourself, he'll know of it.");
        return;
    }
    
    if(strsrch(str,"brookes") != -1 || strsrch(str,"Brookes") != -1 ){
        force_me("say That blustering braggart, he's always pushing for a discount like the ladies should consider ourselves -lucky-...");
        return;
    }
    
    if(strsrch(str,"mae") != -1 || strsrch(str,"Mae") != -1 ){
        force_me("say Oh, she's a lifesaver. I'm not sure where we'd get the basic necessities without her.");
        return;
    }
    
    return;
}

void tilly_reply(object player){
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C183%^$M lets out a faint sigh.");
    force_me("say She's a good girl, just trying to earn her way. Leave off her.");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^With a flap of wings, the %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^caws: %^RESET%^%^C255%^She's a good girl!%^CRST%^");
    return;
}

void kietta_reply(object player){
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C183%^$M shifts a bit uncomfortably in her seat.");
    force_me("say She's a peach with her medicines. And her soothsaying...");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^Flapping its wings quickly, the %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^caws: %^RESET%^%^C255%^Her soothsaying!%^CRST%^");
    return;
}

void wailing_reply(object player){
    force_me("say There's something to the Isle, yeah? Even when we leave... we always find ourselves back here.");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^caws, offering a low, mournful whistle: %^RESET%^%^C255%^We always come back!%^CRST%^");
    return;
}

void receive_given_item(object ob){
    object player, reward, reward2, reward3;
    int reputation, xp_reward, quest;
    string *ids;
    player = this_player();
    ids = ob->query_id();
    quest = player->query("wailing isle grace");
    reputation = player->query("reputation wailing isle");
    
    if((ob->id("quest_item_salve")) && (quest == 2)) {
        force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M glances around furtively before secreting the tin away.%^CRST%^");
        force_me("say Thanks, hon, I appreciate it!");
        ob->remove();
        if(reputation < 14){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        else tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        if(reputation > 49) reputation = 50;
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle grace", 3);
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("bloodstained hook")) && (quest == 3)) {
        force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M blinks wide as she accepts the hook.%^CRST%^");
        force_me("say You're amazing! I hope you made the dirty bastard bleed!");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        if(reputation > 49) tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle grace", 4);
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("shiny chain")) && (quest == 4)) {
        force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M folds the chain mail on her lap, running a hand over the silver links.%^CRST%^");
        force_me("say Far too pretty for a man like that. I hope you bent him over proper.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        if(reputation > 49) tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle grace", 5);
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    if((ob->id("Duel")) && (quest == 5)) {
        force_me("emoteat grace %^RESET%^%^CRST%^%^C183%^$M turns the blade this way and that, admiring it in the candlelight.%^CRST%^");
        force_me("say By far, the more impressive tip the man possessed.");
        ob->remove();
        if(reputation < 50){
            reputation++;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
        }
        if(reputation > 49) tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
        player->set("reputation wailing isle", reputation);
        player->set("wailing isle grace", 6);
        
        xp_reward = exp_for_level(player->query_level() + 1) / 8;
        player->add_exp(xp_reward);
        tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" xp.%^CRST%^\n");
        return 1;
    }
    
    force_me("say I don't think I need this, hon.");
    force_me("give "+ids[0]+" to "+player->query_name()+"");
    return 1;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "grace" && str != "Grace" && str != "harlot" && str != "grace atherton" && str != "Grace Atherton") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C183%^$M gives $N a wary look, taking a step back.%^CRST%^");
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

