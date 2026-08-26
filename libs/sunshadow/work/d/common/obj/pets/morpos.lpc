// Chernobog (12/15/21)
// Morpos Coppernogger - Pet Pocket Dimension Creator

#include <std.h>
#include <move.h>

inherit WEAPONLESS;

int offered;

void create() {
    ::create();
    set_name("Morpos Coppernogger");
    set_id(({"morpos","morpos coppernogger","Morpos","Morpos Coppernogger"}));
    set_short("%^RESET%^%^CRST%^%^C144%^Morpos Coppernogger, %^C136%^an eccentric %^C130%^gnome %^C136%^wearing %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^C184%^g%^C172%^o%^C178%^g%^C184%^g%^C172%^l%^C178%^e%^C184%^s%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C136%^This diminutive person is quite obviously a gnome, and quite probably a danger to himself and anyone in his proximity. His face is obscured by a comically %^C214%^la%^C226%^rg%^C214%^e bl%^C226%^on%^C214%^de %^C226%^be%^C214%^ar%^C226%^d %^RESET%^%^C136%^and %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^C184%^g%^C172%^o%^C178%^g%^C184%^g%^C172%^l%^C178%^e%^C184%^s%^RESET%^%^C136%^, and a %^C130%^worn leather coat %^C136%^drapes over the rest of his body. There are scorches, burns, and pock marks all over his outfit, likely due to the many experiments that somehow went awry...\n%^CRST%^");
    set("aggressive", 0);
    set_level(20);
    set_gender("male");
    set_alignment(7);
    set_race("gnome");
    set_hd(20,0);
    set_max_hp(query_hp());
    set_mlevel("mage", 20);
    set_guild_level("mage", 20);
    set_new_exp(20, "low");
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "greater spell penetration",
        "spell power",
        "perfect caster", }));
    set_spell_chance(200);
    set_spells(({
        "fireball",
        "prismatic spray",
        "phantom guardians",
        "scintillating pattern",
        "solar siege shot",}));
    set_spoken("wizish");
    force_me("pose %^RESET%^%^CRST%^%^C058%^at a worktable%^CRST%^");
    set_emotes(4,({
        "%^RESET%^%^CRST%^%^C130%^The gnome takes out a small cloth, breathing on his goggles and wiping them clean.%^CRST%^",
        "%^RESET%^%^CRST%^%^C130%^Using delicate tools, the gnome makes a small etching onto the surface of a bracelet before copying the shape in ink on a nearby page.%^CRST%^",
        "%^RESET%^%^CRST%^%^C130%^The gnome looks over at you curiously for a moment.%^CRST%^",
        }), 0);
    offered = 0;
}

void init(){
    ::init();
    add_action("enhance_fun", "enhance");
    add_action("replace_fun", "replace");
}

void reply_func(string str, object player){
    object bracelet;
    
    if(!str) return;
    if(!objectp(player)) return;
    
    if(strsrch(str, "hi") != -1 || strsrch(str, "Hi") != -1 || strsrch(str, "ello") != -1 || strsrch(str, "reetings") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M bows his head, his beard parting in a broad grin.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"Hello there! Welcome to the pocket dimension research wing!\"%^CRST%^");
        call_out("second_greeting", 3, player);
        return;
    }
    if(strsrch(str, "pocket") != -1 || strsrch(str, "dimension") != -1 || strsrch(str, "pet") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M claps his hands together excitedly%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"I've developed a way to safely keep your dearest pets with you, even while diving into danger... or a failed experiment, yes? The bracelets are home to small pocket dimensions suited towards our lesser companions. I can even enhance them with extra pockets!\"%^CRST%^");
        if(!player->query("pet_bracelet")) call_out("make_offer", 2, player);
        return;
    }
    if((strsrch(str, "yes") != -1 || strsrch(str, "Yes") != -1) && offered && (!player->query("pet_bracelet"))){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M lets out a small cheer as he retrieves a small silver bracelet from a drawer.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"This should have space for one little companion, but I can add more for a, ah... nominal fee. Let me know if you have any problems with randomly imploding, yes?\"%^CRST%^");
        bracelet = new("/d/common/obj/pets/pet_bracelet");
        if((int)(bracelet->move(player)) != MOVE_OK){
            force_me("say %^RESET%^%^CRST%^%^C226%^\"You look a bit burdened there, let me just set this aside.\"%^CRST%^");
            force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M sets the bracelet on the workbench.%^CRST%^");
            bracelet->move(environment(player));
        }
        else{
            force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C130%^$M hands the bracelet over to $N.%^CRST%^");
            bracelet->move(player);
        }
        player->set("pet_bracelet", 1);
        bracelet->set_owner(player);
        offered = 0;
        return;
    }
    if(strsrch(str, "enhance") != -1 || strsrch(str, "bracelet") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M's head bobs up and down in a series of agreeable nods.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"Yes, yes... I can <enhance> your dimensional bracelet with more spaces, but it -is- a bit pricey. Two million is the cheapest I can go, but think of all the research you'll be funding!\"%^CRST%^");
        if(!player->query("pet_bracelet")) call_out("make_offer", 2, player);
        return;
    }
    if(strsrch(str, "lopos") != -1 || strsrch(str, "Lopos") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M glances towards the other room.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"He's an example to us all. Even with his brother ruining and stealing their work, he perseveres! I'm certain he will lead our research to new heights, and put an end to the threat of Warpos.\"%^CRST%^");
        return;
    }
    if(strsrch(str, "Warpos") != -1 || strsrch(str, "warpos") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^Glancing to either side, $M lowers his voice.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"We Coppernoggers don't usually speak ill of kin, but that one... I've never heard of family turning their back on family like him. Some of us don't believe it -is- him, not really, not anymore.\"%^CRST%^");
        return;
    }
    if(strsrch(str, "replace") != -1 || strsrch(str, "Replace") != -1){
        force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^$M arches a bushy brow.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C226%^\"You need another one? Well... I'd have to charge the materials this time. It would be three million to <replace> it.\"%^CRST%^");
        return;
    }
    
    return;
}

void second_greeting(object player){
    force_me("emoteat morpos %^RESET%^%^CRST%^%^C130%^Taking a brief look around the room, $M offers a sheepish shrug of his shoulders.%^CRST%^");
    force_me("say %^RESET%^%^CRST%^%^C226%^\"Well... it's not impressive yet, but just wait until word gets out about the dimensional bracelets we're developing!\"%^CRST%^");
    if(!player->query("pet_bracelet")) call_out("make_offer", 2, player);
    return;
}

void make_offer(object player){
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C130%^$M eyes $N shrewdly for a moment.%^CRST%^");
    force_me("say %^RESET%^%^CRST%^%^C226%^\"Actually... would you be interested in one? I could always use more help testing them!\"%^CRST%^");
    offered = 1;
    call_out("cancel_offer", 15);
    return;
}

void cancel_offer(){
    if(!offered) return;
    force_me("say %^RESET%^%^CRST%^%^C226%^\"Oh, that's fine then. I'm sure I can find other volunteers!\"%^CRST%^");
    offered = 0;
    return;
}

void replace_fun(string str){
    object player;
    player = this_player();
    
    if(!str){
        tell_object(player, "Syntax: <replace bracelet>");
        return 0;
    }
    if(str != "bracelet") return 0;
    if(!player->query_funds("gold", 3000000)){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't have enough gold.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^YELLOW%^It will cost %^MAGENTA%^3,000,000 gold %^YELLOW%^to replace your bracelet. Enter <yes> to continue, or anything else to abort.%^RESET%^");
    input_to("replace_confirmation", player);
    return 1;
}

void replace_confirmation(string str, object player){
    object bracelet, room;
    room = environment(player);
    
    if(str != "yes" && str != "y" && str != "Y"){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^Replacement purchase cancelled.%^CRST%^");
        return;
    }
    
    tell_room(room, "%^RESET%^%^CRST%^%^C130%^Morpos leaves for a moment, returning with a silver bracelet in his hands. %^C226%^\"Let's be careful with the one, hmm?\" %^RESET%^%^C130%^He sets it down on a nearby table.%^CRST%^");
    player->use_funds("gold", 3000000);
    bracelet = new("/d/common/obj/pets/pet_bracelet");
    bracelet->set_owner(player);
    bracelet->move(room);
    return;
}

int enhance_fun(string str){
    object bracelet, player;
    player = this_player();
    
    if(!str){
        tell_object(player, "Syntax: <enhance bracelet>");
        return 0;
    }
    if(str != "bracelet") return 0;
    if(!bracelet = present("pet_bracelet_x", player)){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You need to have a proper pet bracelet.%^CRST%^");
        return 1;
    }
    if(!player->query_funds("gold", 2000000)){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't have enough gold.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^YELLOW%^It will cost %^MAGENTA%^2,000,000 gold %^YELLOW%^to enhance your bracelet. Enter <yes> to continue, or anything else to abort.%^RESET%^");
    input_to("enhance_confirmation", player, bracelet);
    return 1;
}

void enhance_confirmation(string str, object player, object bracelet){
    object room = environment(player);
    
    if(str != "yes" && str != "y" && str != "Y"){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^Enhancement purchase cancelled.%^CRST%^");
        return;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C130%^Morpos takes your bracelet for a moment, turning it about in his hands with a studious intent. Taking a paintbrush, he dips it into a %^C030%^e%^C036%^e%^C042%^r%^C036%^i%^C030%^e g%^C036%^l%^C042%^owi%^C036%^n%^C030%^g p%^C036%^i%^C042%^gme%^C036%^n%^C030%^t %^RESET%^%^C130%^and begins to paint %^C039%^r%^C045%^u%^C051%^n%^C045%^e%^C039%^s %^RESET%^%^C130%^that hover above the surface of the jewelry. Nodding to himself with a satisfied grin, he passes it back to you.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C130%^Morpos takes "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C130%^'s bracelet for a moment, turning it about in his hands with a studious intent. Taking a paintbrush, he dips it into a %^C030%^e%^C036%^e%^C042%^r%^C036%^i%^C030%^e g%^C036%^l%^C042%^owi%^C036%^n%^C030%^g p%^C036%^i%^C042%^gme%^C036%^n%^C030%^t %^RESET%^%^C130%^and begins to paint %^C039%^r%^C045%^u%^C051%^n%^C045%^e%^C039%^s %^RESET%^%^C130%^that hover above the surface of the jewelry. He passes it back to "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C130%^ with a satisfied grin.%^CRST%^", player);
    player->use_funds("gold", 2000000);
    bracelet->add_slots(1);
    return;
}

void catch_say(string str){
   call_out("reply_func", 1, str, this_player());
}

void die(object ob){
	tell_room(ETO,"%^RESET%^%^CRST%^%^C130%^Morpos rolls away in desperation, plucking something from his coat as he struggles to his feet. He presses a button on the strange device and disappears in a flash of light!%^CRST%^");  
	TO->remove();
}

