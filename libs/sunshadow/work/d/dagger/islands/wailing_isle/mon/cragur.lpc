// Chernobog & Titania (2/14/22)
// The Wailing Isle - Fence Cragur

#include "../defs.h"
inherit "/std/fence";

void create() {
    ::create();
    set_name("Cragur");
    set_id(({"cragur", "Cragur", "fence"}));
    set_short("%^RESET%^%^CRST%^%^C243%^Cragur, the Fence%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C247%^This man is built solidly with %^C250%^broad shoulders%^C247%^ that put any common man to shame. His %^C243%^gr%^C245%^a%^C243%^y s%^C245%^k%^C243%^in%^RESET%^%^C247%^ allows him to all but %^C243%^disappear%^C247%^ into the %^C059%^darkness%^C247%^ of his surroundings, with %^C059%^fa%^C243%^in%^C059%^t mo%^C059%^ttl%^C243%^ed p%^C059%^a%^C243%^tch%^C059%^e%^C243%^s%^RESET%^%^C247%^ of %^C059%^c%^C243%^o%^C059%^lor%^RESET%^%^C247%^ that blend with the %^C059%^shadows%^C247%^. Thick lengths of %^C059%^black hair%^C247%^ frame a brutal face, with a %^C251%^j%^C250%^u%^C249%^tti%^C250%^n%^C251%^g jaw%^RESET%^%^C247%^ and a %^C182%^large scar%^C247%^ that slashes diagonally across his whole visage, vanishing beneath the %^C059%^black eye patch%^C247%^ covering his left eye.\n%^CRST%^");
    set_gender("male");
    set_alignment(6);
    set_race("half-orc");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_items_allowed("misc");
    set_spoken("common");
    force_me("speech rumble in a low tone");
}

void init(){
    object player;
    
    ::init();
    add_action("hit_fun", "hit");
    add_action("test_rep", "buy");
    add_action("test_rep", "fence");
    add_action("test_rep", "list");
    
    player = this_player();
    if(player->id("mutt")){
        force_me("emoteat mutt %^RESET%^%^CRST%^%^C247%^$M keeps a wary eye on the mutt.%^CRST%^");
    }
}

int test_rep(){
    object player;
    int reputation;
    player = this_player();
    reputation = player->query("reputation wailing isle");
    
    if(reputation > 14){
        force_me("say You are known.");
        return 0;
    }
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C247%^$M grunts, folding his arms across his chest.%^CRST%^");
    force_me("say Don't know you, don't know what you're wanting. Scram.");
    return 1;
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
    
    if((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )|| (strsrch(str,"eya") != -1 )){
        if(reputation < 15){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C247%^$M narrows his eyes at $N, letting out a snort.%^CRST%^");
            return;
        }
        if(reputation < 50){
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C247%^$M slowly inclines his head towards $N.%^CRST%^");
            return;
        }
        switch(player->query_gender()){
            case "male" :
                force_me("say Greetings... sir.");
                break;
            case "female" :
                force_me("say Greetings... ma'am.");
                break;
            default :
                force_me("say ...greetings.");
        }
        return;
    }
    
    if(strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M mutters under his breath.%^CRST%^");
        if(reputation > 14) force_me("say ...it's worth putting up with the cries, instead of setting up shop at Pirates' Cove.");
        return;
    }
    
    if(strsrch(str,"kietta") != -1 || (strsrch(str,"Kietta") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M offers a lone grunt.%^CRST%^");
        if(reputation > 14) force_me("say Always with the requests for unicorn horn. She's cooking up something...");
        return;
    }
    
    if(strsrch(str,"astley") != -1 || (strsrch(str,"Astley") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M narrows his eyes for a moment.%^CRST%^");
        if(reputation > 14) force_me("say The captain didn't care about my blood. Just if I was good at spilling it.");
        return;
    }
    
    if(strsrch(str,"grace") != -1 || (strsrch(str,"Grace") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^A smile almost pulls at $M's lips.%^CRST%^");
        if(reputation > 14) force_me("say So good, she'll make you forget you paid for it.");
        return;
    }
    
    if(strsrch(str,"mae") != -1 || (strsrch(str,"Mae") != -1 ) || (strsrch(str,"bear") != -1 ) || (strsrch(str,"Bear") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M lets out a snort.%^CRST%^");
        if(reputation > 14) force_me("say I heard she's killed lots of orcs, back in her venturing days. And she gives me odd looks.");
        return;
    }
    
    if(strsrch(str,"tilly") != -1 || (strsrch(str,"Tilly") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M bares his teeth for a moment.%^CRST%^");
        if(reputation > 14){
            force_me("say She could never be inconspicuous with that mouth of hers...");
            force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^Shaking his head, $M almost grins.%^CRST%^");
        }
        return;
    }
    
    if(strsrch(str,"brookes") != -1 || (strsrch(str,"Brookes") != -1 )){
        force_me("emoteat cragur %^RESET%^%^CRST%^%^C247%^$M rolls his eyes with a shake of his head.%^CRST%^");
        if(reputation > 14) force_me("say A pompous fool, but useful in his arrogance.");
        return;
    }
    
    return;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "cragur" && str != "Cragur" && str != "fence") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C247%^$M gives $N a wary look, taking a step back.%^CRST%^");
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

