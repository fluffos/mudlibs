// Chernobog (12/15/21)
// Lopos Coppernogger

inherit WEAPONLESS;

int greeted;

void create() {
    ::create();
    set_name("Lopos Coppernogger");
    set_id(({"lopos","lopos coppernogger","Lopos","Lopos Coppernogger"}));
    set_short("%^RESET%^%^CRST%^%^C144%^Lopos Coppernogger, %^C136%^an eccentric %^C130%^gnome %^C136%^wearing %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^C184%^g%^C172%^o%^C178%^g%^C184%^g%^C172%^l%^C178%^e%^C184%^s%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C136%^This diminutive person is quite obviously a gnome, and quite probably a danger to himself and anyone in his proximity. His face is obscured by a comically %^C208%^la%^C202%^rg%^C208%^e gi%^C202%^nge%^C208%^r be%^C202%^ar%^C208%^d %^RESET%^%^C136%^and %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^C184%^g%^C172%^o%^C178%^g%^C184%^g%^C172%^l%^C178%^e%^C184%^s%^RESET%^%^C136%^, and a %^C130%^worn leather coat %^C136%^drapes over the rest of his body. There are scorches, burns, and pock marks all over his outfit, likely due to the many experiments that somehow went awry...\n%^CRST%^");
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
    force_me("pose %^RESET%^%^CRST%^%^C058%^seated at a desk%^CRST%^");
    set_emotes(4,({
        "%^RESET%^%^CRST%^%^C144%^The gnome takes out a small cloth, wiping at his goggles.%^CRST%^",
        "%^RESET%^%^CRST%^%^C091%^Lopos Coppernogger mutters to himself: %^RESET%^%^CRST%^%^C144%^\"If he's on these demiplanes, we could trap him... there.\"%^CRST%^",
        "%^RESET%^%^CRST%^%^C144%^The gnome looks over at you curiously for a moment.%^CRST%^",
        }), 0);
    greeted = 0;
}

void catch_say(string str){
   call_out("reply_func", 1, str, TP);
}

void reply_func(string str, object targ){
    if(!str) return;
    if(!objectp(targ)) return;
    
    if(((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )) && !greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^looks up from his books.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"Oh, hello! I am Lopos Coppernogger, and you're just in time to help me deal with more of my brother's meddling. You're willing to help, yes?\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^arches a large bushy eyebrow.%^CRST%^");
        greeted = 1;
        return;
    }
    
    if(((strsrch(str,"ello") != -1 ) || (strsrch(str,"Hi") != -1 ) || (strsrch(str,"reeting") != -1 )) && greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^chuckles, clasping his hands together.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"Aha, I believe we've already said our greetings. Is there something else I can help you with?\"%^CRST%^");
        return;
    }
    
    if(((strsrch(str,"yes") != -1 ) || (strsrch(str,"Yes") != -1 ) || (strsrch(str,"okay") != -1 )) && greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^claps his hands together, rubbing them eagerly.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"Excellent! Just %^C226%^open %^C202%^a %^C226%^demiplane %^C202%^here, and you'll be swept into his latest tear. Find the fragment of reality to close it up and I'll bring you right back here!\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^gestures towards the stone portal.%^CRST%^");
        return;
    }
    
    if(((strsrch(str,"no") != -1 ) || (strsrch(str,"No") != -1 )) && greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^lets his shoulders sag a bit.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"I suppose preserving reality as we know it isn't enough... perhaps a more concrete reward?\"%^CRST%^");
    }
    
    if(((strsrch(str,"elp") != -1 ) || (strsrch(str,"task") != -1 )) && greeted){
        force_me("say %^RESET%^%^CRST%^%^C202%^\"My misguided brother has been using his portal device to rip the fabric of reality apart. I need brave adventurers to follow after him into these demiplanes to retrieve the fragments to restore them.\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^gestures towards the floating stone archway.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"I can %^C226%^open %^C202%^a %^C226%^demiplane %^C202%^for you with this.\"%^CRST%^");
    }
    
    if(((strsrch(str,"reward") != -1 ) || (strsrch(str,"Reward") != -1 )) && greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^runs his fingers through his ginger beard.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"Aside from such a unique experience? I may have some coins around here for you as well, and some spare enchanting materials?\"%^CRST%^");
    }
    
    if(((strsrch(str,"technology") != -1 ) || (strsrch(str,"machinery") != -1 )) && greeted){
        force_me("say %^RESET%^%^CRST%^%^C202%^\"My brother and I worked to break down the function of these stones, incorporating the techniques into our demiplane devices. Unfortunately, I cannot replicate the work without him... he stole away with the research, and I am back to the drawing board.\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^gestures towards the books scattered across his desk.%^CRST%^");
    }
    
    if(((strsrch(str,"stones") != -1 ) || (strsrch(str,"archway") != -1 ) || (strsrch(str,"portal") != -1 )) && greeted){
        force_me("say %^RESET%^%^CRST%^%^C202%^\"Ahh... yes. A discovery deep in the Underdark, my brother and I were amazed at their function. They can be attuned to create portals between similar archways.\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^lets out a sigh as he admires the hovering stones for a moment.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"It was Warpos that first considered if the portals could be attuned to other planes. An inspiration from his dreams, he said.\"%^CRST%^");
    }
    
    if(((strsrch(str,"rother") != -1 ) || (strsrch(str,"arpos") != -1 ) || (strsrch(str,"eddling") != -1 )) && greeted){
        force_me("emote %^RESET%^%^CRST%^%^C144%^sighs, turning towards the stone portal levitating in the middle of the room.%^CRST%^");
        force_me("say %^RESET%^%^CRST%^%^C202%^\"My brother Warpos... we worked on this together, you know. So much potential, these demiplanes. Unfortunately, it seems something in the cosmos has tainted his mind. Instead, he's using this technology to rip the very fabric of reality apart!\"%^CRST%^");
        force_me("emote %^RESET%^%^CRST%^%^C144%^sighs again, giving a shake of his head.%^CRST%^");
        return;
    }
    
    if(!greeted) force_me("%^RESET%^%^CRST%^%^C144%^emote seems intent on the book in front of him.%^CRST%^");
    return;
}

void die(object ob){
	tell_room(ETO,"%^RESET%^%^CRST%^%^C144%^Lopos rolls away in desperation, plucking something from his coat as he struggles to his feet. He presses a button on the strange device and disappears in a flash of light!%^CRST%^");  
	TO->remove();
}

void reset(){
    ::reset();
    if(greeted){
        tell_room(ETO, "%^RESET%^%^CRST%^%^C144%^The gnome returns to his pile of books.%^CRST%^");
        greeted = 0;
    }
}

