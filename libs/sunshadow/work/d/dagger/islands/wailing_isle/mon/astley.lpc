// Chernobog & Titania (3/2/22)
// The Wailing Isle - Bartender Captain Dick "Three Teeth" Astley

#include <std.h>
#include "../defs.h"
inherit BARKEEP;

void create() {
    ::create();
    set_name("Captain Astley");
    set_id(({"three teeth", "astley", "captain astley", "barkeep", "bartender", "Captain Astley"}));
    set_short("%^RESET%^%^CRST%^%^C149%^Old %^C150%^\"Three Teeth\"%^C149%^ Astley, the Barkeep%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C243%^Old %^C142%^\"Three Teeth\"%^C243%^ Astley has a very fitting name. He is an old, %^C247%^hollow%^C243%^ man - tall and gangly, with a face that is worse for the wear. His %^C059%^l%^C244%^o%^C059%^ng b%^C100%^e%^C059%^a%^C244%^r%^C059%^d%^RESET%^%^C243%^ is split into two %^C160%^b%^C100%^e%^C160%^ad%^C089%^e%^C160%^d%^RESET%^%^C243%^, %^C059%^gray b%^C243%^r%^C245%^ai%^C243%^d%^C059%^s%^C243%^, beneath a mouth that is empty save for %^C230%^th%^C229%^r%^C248%^e%^C228%^e r%^C227%^e%^C248%^m%^C221%^ai%^C222%^n%^C248%^i%^C223%^ng %^C229%^t%^C248%^e%^C193%^e%^C248%^t%^C228%^h%^RESET%^%^C243%^. Captain Astley is revered for his %^C090%^ruthlessness%^C243%^ which earned him great fortune and fame back in the day, enough so that he was able to retire comfortably enough to hold down this %^C160%^r%^C089%^a%^C090%^u%^C160%^co%^C089%^u%^C160%^s tavern%^RESET%^%^C243%^. An old %^RESET%^%^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t%^RESET%^%^C243%^ perches on his shoulder, its beady eyes%^C243%^ watching the room while it preens itself. The rumors are that Old Three Teeth keeps an ear out, keeping tabs on the %^C247%^reputations %^C243%^of those around the Isle.%^CRST%^\n");
    set_gender("male");
    set_alignment(9);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_currency("silver");
    set_property("no_random_treasure",1);
    set_spoken("common");
    force_me("speech wheeze out");
    force_me("pose %^RESET%^%^CRST%^%^C243%^wiping down the bar%^CRST%^");
    
    set_menu(
        ({"ale","grog","bumbo","water","stew","bread"}),
        ({"alcoholic","alcoholic","alcoholic","water","food","food"}),
        ({10,10,15,5,5,5}),
        );
    set_menu_short(({
        "%^RESET%^%^CRST%^%^C245%^a %^C095%^d%^C101%^ir%^C095%^ty gl%^C101%^as%^C095%^s%^C245%^ of %^C227%^p%^C228%^i%^C229%^s%^C230%^s %^C227%^y%^C228%^e%^C229%^l%^C230%^l%^C227%^o%^C228%^w %^C229%^a%^C230%^l%^C227%^e%^CRST%^",
        "%^RESET%^%^CRST%^%^C245%^a %^C247%^de%^C250%^nt%^C247%^ed %^C245%^me%^C247%^ta%^C250%^l s%^C247%^te%^C245%^in%^CRST%^",
        "%^CRST%^%^RESET%^%^C101%^a b%^C100%^at%^C101%^te%^C102%^re%^C100%^d w%^C101%^o%^C100%^o%^C101%^d%^C102%^e%^C101%^n m%^C100%^u%^C101%^g%^CRST%^",
        "%^RESET%^%^CRST%^%^C179%^a c%^C247%^h%^C187%^i%^C179%^pp%^C247%^e%^RESET%^%^C179%^d %^C172%^clay cup%^CRST%^",
        "%^CRST%^%^RESET%^%^C202%^a %^C136%^bowl%^C202%^ of %^C223%^f%^C216%^i%^C209%^s%^C216%^h%^C223%^y%^C202%^ smelling stew%^CRST%^",
        "%^CRST%^%^RESET%^%^C059%^a h%^C058%^a%^C059%^rd lo%^C058%^a%^C059%^f of bla%^C058%^c%^C059%^k bre%^C058%^a%^C059%^d%^CRST%^",
        }));
    set_my_mess(({
        "The watery ale leaves you wanting.",
        "The hint of citrus is a pleasant surprise.",
        "The bumbo goes down smooth.",
        "It's warm and a little gritty, but at least it's wet.",
        "It's a bit heavy on the broth.",
        "Hard and dry, just like it looks.",
        }));
    set_your_mess(({
        "drains their glass.",
        "tilts back their stein to collect every drop.",
        "polishes off their drink.",
        "drinks the glass of water.",
        "finishes off the fish stew.",
        "gags down the dry bread.",
        }));
    set_menu_long(({
        "%^CRST%^%^RESET%^%^C227%^This %^C230%^light ale%^C227%^ is served up warm in an old, %^C186%^smudged up %^RESET%^%^C227%^glass. A few %^C253%^b%^C247%^u%^C253%^bbl%^C247%^e%^C253%^s%^RESET%^%^C227%^ gather on the sides of the glass, but a frothy head is nowhere to be found.%^CRST%^",
        "%^CRST%^%^RESET%^%^C253%^The %^C247%^old %^C243%^m%^C245%^eta%^C243%^l s%^C245%^tei%^C243%^n%^RESET%^%^C253%^ is filled to the brim with some %^C178%^w%^C179%^a%^C178%^ter%^C179%^e%^C178%^d do%^C179%^w%^C178%^n r%^C179%^u%^C178%^m%^RESET%^%^C253%^ and a %^C079%^zesty hint%^C253%^ of %^C076%^li%^C046%^m%^C076%^e%^RESET%^%^C253%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C179%^This %^C100%^rum%^C179%^ drink smells quite pleasantly of %^C229%^v%^C231%^a%^C229%^nil%^C231%^l%^C229%^a%^C179%^ and %^C094%^c%^C100%^i%^C166%^n%^C094%^nam%^C100%^o%^C094%^n%^RESET%^%^C179%^, and is served in a %^C101%^worn old mug%^RESET%^%^C179%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C179%^The chipped %^C172%^clay cup%^C179%^ is filled with warm and mostly clean %^C159%^w%^C123%^a%^C253%^t%^C250%^e%^C159%^r%^RESET%^%^C179%^ sourced from %^C122%^lo%^C116%^ca%^C115%^l s%^C121%^pr%^C122%^in%^C116%^gs%^RESET%^%^C179%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C202%^Chunks of %^C195%^wh%^C230%^it%^C195%^e f%^C230%^is%^C195%^h%^RESET%^%^C202%^ sit in a %^C160%^red broth%^C202%^ along with a few %^C118%^c%^C154%^o%^C148%^l%^C136%^o%^C130%^r%^C124%^ful veg%^C130%^e%^C136%^t%^C148%^a%^C154%^b%^C118%^l%^C119%^e%^C120%^s%^RESET%^%^C202%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C059%^The bre%^C058%^a%^C059%^d is %^C058%^hard%^C059%^ but probably edible. %^C243%^You can't help but wonder if it explains Astley's missing teeth%^C059%^.%^CRST%^",
	}));
}

void init(){
    object player;
    
    ::init();
    add_action("hit_fun", "hit");
    add_action("read_fun","read");
    
    player = this_player();
    if(player->id("mutt")) force_me("emoteat mutt %^RESET%^%^CRST%^%^C243%^$M chuckles as he spots the mongrel, grabbing a piece of fish from the stew and tossing it over. The mutt is quick to snatch it from the air and wolf it down.%^CRST%^");
    if(player->query("reputation wailing isle") > 49 && !player->query("wailing isle astley")) call_out("max_reward", 1, player);
}

void max_reward(object player){
    object reward;
    
    force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C243%^$M waves $N over, retrieving something from below the bar.%^CRST%^");
    force_me("say Ye remind me a bit o'... me. Well, back 'fore I settled. Here's a good luck charm that treated me right, and I'd like ye ta 'ave it.");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^lets out a shrill cry: %^RESET%^%^C255%^A good luck charm!%^CRST%^");
    reward = new(OBJ"magic_spyglass");
    reward->move(this_object());
    force_me("give spyglass to "+player->query_name()+"");
    player->set("wailing isle astley", 1);
    return;
}

int read_fun(string str){
	if(!str) return 0;
	if(str != "menu") return 0;
	
	write("%^C060%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^CRST%^");
    write("");
    write("         %^C060%^-<>- %^C243%^Drinks %^C060%^-<>-%^RESET%^");
    write("");
    write("     %^C066%^Ale             %^C250%^10 %^C255%^Silver");
    write("     %^C066%^Grog            %^C250%^10 %^C255%^Silver");
    write("     %^C066%^Bumbo	     %^C250%^15 %^C255%^Silver");
    write("     %^C066%^Water	     %^C250%^5 %^C255%^Silver");
    write("");
    write("	  %^C060%^-<>- %^C243%^Eats %^C060%^-<>-%^CRST%^");
    write("");
    write("     %^C066%^Fish Stew       %^C250%^5 %^C255%^Silver");
    write("     %^C066%^Bread           %^C250%^5 %^C255%^Silver");
    write("");
    write("%^C060%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^CRST%^");
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
    
    if(strsrch(str,"reputation") != -1 ){
        force_me("emoteat "+player->query_name()+" %^RESET%^%^CRST%^%^C243%^$M tilts his head to the side as he sizes $N up.%^CRST%^");
        switch(reputation){
            case 0..4:
                force_me("say Uh... I don't think most folks know who ye be.");
                if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^lets loose a shrill whistle: %^RESET%^%^C255%^Who are you? Who are you??%^CRST%^");
                break;
            case 5..14:
                force_me("say I've seen yer face 'round here a'fore, sure.");
                if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^lets out a caw, followed by: %^RESET%^%^C255%^Seen you a'fore, seen you a'fore!%^CRST%^");
                break;
            case 15..49:
                force_me("say Yer known ta folks 'ere, sure 'nuff. Prac'ly one o' the town.");
                if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^lets out a whistle, then prattles: %^RESET%^%^C255%^One o' the town, one o' the town!%^CRST%^");
                break;
            case 50:
                force_me("say We all know who ye be. A proper scallawag and a friend ta the Isle.");
                if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^With a flap of its wings, the %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^crows out: %^RESET%^%^C255%^Friend ta the Isle, friend ta the Isle!%^CRST%^");
                break;
            default:
                force_me("say Aye, everyone knows to keep an eye on ye...");
                if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^flaps its wings hurriedly: %^RESET%^%^C255%^Stranger danger, stranger danger!%^CRST%^");
        }
        if(quest) force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M taps a finger against his chin thoughtfully.%^CRST%^");
        switch(quest){
            case 1..2:
                force_me("say I also heard you were supposed ta be gettin' sometin' fer the lil' fishmonger.");
                break;
            case 3..4:
                force_me("say I also heard you were doin' some favor fer the ol' hoodoo voodoo lady.");
                break;
            case 5..10:
                force_me("say I also heard the wharfmaster had you signed up for somethin'.");
                break;
            case 11..12:
                force_me("say I also heard you were doin' some work fer the ol' Bear.");
                break;
            default:
                break;
        }
        return;
    }
    
    if(strsrch(str,"wailing") != -1 || (strsrch(str,"Wailing") != -1 )){
        force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M sighs, offering a vague shrug.%^CRST%^");
        force_me("say If ya can get over the keenin' of the wind, it's a decent place ta live.");
        return;
    }
    
    if(strsrch(str,"tilly") != -1 || strsrch(str,"Tilly") != -1 ){
        force_me("say The lil' fish girl? I dunno who she's sellin' fer, but there's no way she's haulin' those things out herself.");
        return;
    }
    
    if(strsrch(str,"kietta") != -1 || strsrch(str,"Kietta") != -1 ){
        force_me("say I don't traffic wit' witches... but, er, she has some o' the best 'bacco 'round.");
        return;
    }
    
    if(strsrch(str,"cragur") != -1 || strsrch(str,"Cragur") != -1 ){
        call_out("cragur_reply", 2, player);
        return;
    }
    
    if(strsrch(str,"grace") != -1 || strsrch(str,"Grace") != -1 ){
        force_me("say She's good company, eh? Worth every penny... but leave it fer the docks. Let her enjoy herself 'ere.");
        return;
    }
    
    if(strsrch(str,"brookes") != -1 || strsrch(str,"Brookes") != -1 ){
        call_out("brookes_reply", 2, player);
        return;
    }
    
    if(strsrch(str,"mae") != -1 || strsrch(str,"Mae") != -1 ){
        call_out("mae_reply", 2, player);
        return;
    }

    if(strsrch(str,"parrot") != -1 ){
        force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M offers a toothless grin as he reaches up to scratch the parrot.%^CRST%^");
        force_me("say Ol' Turnbuckle? My father found 'im as a hatchlin'... he's been wit' me all my life.");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^With a flap of wings, the %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^caws: %^RESET%^%^C255%^Taught him everything he knows!%^CRST%^");
        return;
    }

    return;
}

void cragur_reply(object player){
    force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M arches a brow with a hooting laugh.");
    force_me("say I dunno about that, but he's solid ta have in a fight. Give him an axe and he's right at home!");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^With a flap of wings, the %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^caws: %^RESET%^%^C255%^Give him an axe!%^CRST%^");
    return;
}

void brookes_reply(object player){
    force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M nods a few times at that.");
    force_me("say He's got some connections, aye, but he's no better'n the rest of us. That's why I water down his grog!");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^lets out a shrill caw: %^RESET%^%^C255%^Water down his grog!%^CRST%^");
    return;
}

void mae_reply(object player){
    force_me("emoteat astley %^RESET%^%^CRST%^%^C243%^$M grumbles a little under his breath.");
    force_me("say I still think she overcharges fer the rum... and -that's- a necessity!");
    if(random(2)) tell_room(environment(player), "%^RESET%^%^CRST%^%^C243%^The %^C040%^p%^C041%^a%^C190%^r%^C184%^r%^C088%^o%^C160%^t %^RESET%^%^C243%^whistles a couple times, almost like a laugh: %^RESET%^%^C255%^What a cheapskate!%^CRST%^");
    return;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "three teeth" && str != "astley" && str != "captain astley" && str != "barkeep" && str != "bartender" && str != "Captain Astley") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C243%^$M gives $N a wary look, taking a step back.%^CRST%^");
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

