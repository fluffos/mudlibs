// venenum

#include <std.h>
inherit MONSTER;

int killable=0;
int reward=0;

void create() {
    ::create();
    set_name("devereux");
    set_short("Lady Devereux");
    set_id(({"devereux"}));
    set_level(60);
    set_class("vampire");
    set_subclass("vampire");
    set_race("vampire");
    set_body_type("undead");
    set_gender("female");
    set_long("This tall, raven haired female stands at an impressive six foot ten, dwarfing most humans. Thin in build, her frail arms conceal an unearthly strength, capable of breaking down solid oak doors and smashing holes in solid stone. Her skin is a deathly pale, almost decrepid, her canine teeth noticably elongated compared to her other teeth.");
    call_out("welcome", 10);
}

int is_invincible() {

    if(killable == 0){
	message("say", "Lady Devereux simply raises an eyebrow at you.", this_player());
	this_object()->force_me("say Do you want me to help you, or not?");
	killable++;
	return 1;
    }
    if(killable == 1){
	message("say", "Lady Devereux frowns, bearing her long fangs.", this_player());
	this_object()->force_me("say This is your last warning! Attempt such folly with me again and you shall be dealt with!");
	killable++;
	return 1;
    }
    if(killable == 2){
	message("say", "Lady Devereux shrugs her shoulders, waving an arm towards you.", this_player());
	this_object()->force_me("say A pity. We could have accomplished much together.");
	message("say", "Lady Devereux blasts you with a flare of light from her eyes, knocking you into unconsciousness. You never wake up from this nightmare. Your blood is tasty.", this_player());
	this_player()->die();
	killable = 0;
	return 1;
    }
    else{return 1;}
}

void catch_tell(string str) {
    string a, b;

    if(this_player() != this_object()) 
    {

	if(sscanf(str, "%squest%s", a, b) == 2) {
	    this_object()->force_me("say I need you to recover the heart of my husband. He broke into my lair in the hope of destroying me... but he failed. I poisoned him before he escaped this tomb, his creation, and he may have gotten anywhere before he died. His body may be anywhere on the entire realm. But if you recover his heart and bring it to me, then I will reward you with a %^BOLD%^%^RED^%blood kiss%^RESET%^... the highest honour a mortal can be given. You will become one of our kind... a %^BOLD%^%^RED%^vampire%^RESET%^, to serve under me! Simply tell me when you are %^BOLD%^%^RED%^ready%^RESET%^, and I will transport you from this place to begin your search. Return here when you have the %^BOLD%^%^RED%^heart%^RESET%^ and let me know. Bear in mind that he was very ill and probably did not leave this city.");
	    return 1;
	}

	if(sscanf(str, "%svampire%s", a, b) == 2) {
	    this_object()->force_me("emote just grins.");
	    return 1;
	}

	if(sscanf(str, "%sblood kiss%s", a, b) == 2) {
	    this_object()->force_me("say Yes, a %^BOLD%%^RED%^blood kiss%^RESET%^. With this you become one of my kind... a %^BOLD%^%^RED%^vampire. If you wish to have one, I have a %^BOLD%^%^RED%^quest%^RESET%^ for you to undertake, if you so wish.");
	    return 1;
	}
	if(sscanf(str, "%sready%s", a, b) == 2) {
	    this_object()->force_me("say Go now, bring me the heart of Lord Devereux!");
	    this_player()->move("/d/nopk/tirun/square");
	    return 1;
	}

	if(sscanf(str, "%si am his lackey%s", a, b) == 2) {
	    this_object()->force_me("say Then die, fool!");
	    message("say", "Lady Devereux tears out your heart, devouring it in front of your eyes.", this_player());
	    this_player()->die();
	    return 1;
	}
	if(sscanf(str, "%slackey%s", a, b) == 2) {
	    this_object()->force_me("emote scowls.");
	    this_object()->force_me("say Don't say it... if you say %^BOLD%^%^RED%^I am his lackey%^BOLD%^%^RED%^ I swear, you'll meet the same end as my husband...");
	    return 1;
	}
	if(sscanf(str, "%snot%s", a, b) == 2) {
	    this_object()->force_me("emote nods.");
	    this_object()->force_me("say Very well, then. I will believe you. If I may ask, then, why are you here? Do you seek a %^BOLD%^%^RED%^blood kiss%^RESET%^? Such things are not given out lightly.");
	    return 1;
	}

	if(sscanf(str, "%sheart%s", a, b) == 2) {
	    this_object()->force_me("emote salivates slightly, leaning towards you.");
	    this_object()->force_me("say You have the heart?! Give it to me, give it to me now!");
	    call_out("heart1", 10);
	    return 1;
	}

	if(sscanf(str, "%sreward%s", a, b) == 2) {
	    if (reward == 1)
	    {
		this_object()->force_me("emote nods her head slowly.");
		this_object()->force_me("say Then we shall begin. %^BOLD%^%^RED%^Accept%^RESET%^ I shall administer the bite. Beware, there is no returning from that point... you will become my undead servant, a vampire, and you will will never be mortal again. If this is what you want, %^BOLD%^%^RED%^accept%^RESET%^, or else %^BOLD%^%^RED%^refuse%^RESET%^");
		return 1;
	    }
	}

	if(sscanf(str, "%saccept%s", a, b) == 2) {
	    if (reward == 1)
	    {
		this_object()->force_me("emote sinks her fangs into your body!");
		this_object()->force_me("emote begins to drain the blood out from your body. You feel lightheaded, then swoon. You do not feel any different at all. Your vision goes blurry and dark. Still there are no changes. As you slip into unconsciousness, you feel you may have been tricked.");
		this_player()->die();
		return 1;
	    }
	}

	if(sscanf(str, "%srefuse%s", a, b) == 2) {
	    if (reward == 1)
	    {
		this_object()->force_me("emote nods her head slowly.");
		this_object()->force_me("say Then be gone.");
		this_player()->move("/d/nopk/tirun/square");
		return 1;
	    }
	}
    }
}

int welcome(){
    message("say", "Lady Devereux snarls, hissing and bearing her teeth.", environment(this_player()));
    this_object()->force_me("say Wha... wha... who?!");
    call_out("welcome2", 10);
}

int welcome2(){
    message("say", "Lady Devereux calms, glaring at you.", environment(this_player()));
    this_object()->force_me("say Who are you? My husband's lackey? I swear to you, you will meet the same fate as he if you say you are his %^BOLD%^%^RED%^lackey%^RESET%^! If you are %^BOLD%^%^RED%^not%^RESET%^, speak now!");
}

int heart1(){
    if (present("heart_of_lord_devereux", this_player()))
    {
	message("say", "Lady Devereux snatches the heart from you, devouring it messily. Blood pours down her chin, over her black robes, and when it is all done she pants heavily, grinning at you.", environment(this_player()));
	this_object()->force_me("say Delicious. Ever were the fool, dearest!");
	call_out("heart2",10);
    }
    else
    {
	message("say", "Lady Devereux snarls.", environment(this_player()));
	this_object()->force_me("say IDIOT! Do not test my patience! Return with the heart, or I shall claim yours!");
    }
}

int heart2(){

    message("say", "Lady Devereux grins over to you, raising an eyebrow curiously.", environment(this_player()));
    this_object()->force_me("say I guess you were wanting your %^BOLD%^%^RED%^reward%^RESET%^ now, then?");
    reward = 1;
    call_out("heart2",10);

}
