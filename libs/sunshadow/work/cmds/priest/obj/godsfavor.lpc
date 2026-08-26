//Added Auppenser, Sune, Beshaba, and Shaundakul - Cythera 8/05
//Added Silvanus - N, 3/13.
#include <std.h>
#include <priest.h>

inherit OBJECT;

#define ACTIVETEMPLES ({ "jarmila", "kreysneothosies", "lord shadow", "nimnavanon", "lysara", "callamir", "nilith", "kismet", "the faceless one", "cevahir", "seija", "khyron", "ashra", "edea", "cacia" })
object ob;

void create(){
    ::create();
    set_name("godsfavor");
    set("id", ({ "remotexoli"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
}

void init(){
    ::init();
    add_action("now","now");
}


int clean_up(){
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}


void dest_effect(){
    destruct(TO);
}


void remove(){
    if(objectp(PO)){
        if(!avatarp(PO) && (strsrch(base_name(PO),"_gods") == -1)) { return; }
    }
    destruct(TO);
}


int save_me(string file){
    return 1;
}


int now(string str){
    string where, temple, diety, playername;
    int mypower,startpower,endpower,bonus;
    object player, room;
    player = this_player();
    playername = player->query_cap_name();
    room = environment(player);
    diety = player->query_diety();

    if(member_array(diety,ACTIVETEMPLES) != -1){
        temple = "Temple of "+capitalize(diety);
        diety = replace_string(diety," ","_");
        where = "/d/magic/temples/"+diety+"/"+diety;
    }
    else{
        tell_object(player,"You need to follow a god to be saved by one.");
        dest_effect();
        return 0;
    }
    if(environment(player)->query_property("no teleport")){
        tell_object(player,"Even "+diety+" is unable to save you from here.");
        dest_effect();
        return 0;
    }
    //teleport proof stuff by ~Circe~ 6/20/08
    //new property to be used for areas protected from teleport 
    //but not foolproof
    if(where && (where->query_property("teleport proof") || room->query_property("teleport proof") || !where->is_room())){
        startpower = room->query_property("teleport proof");
        endpower = where->query_property("teleport proof");
        bonus = player->query_stats("wisdom");
        bonus = bonus -10;
        if((object *)player->query_attackers() != ({})){
            mypower = (int)player->query_level("cleric") + bonus + random(6);
        }else{
            mypower = (int)player->query_level("cleric") + bonus + random(6) + 5;
        //making it easier to teleport out if you aren't in combat
        }
        if((mypower < startpower) || (mypower < endpower)){
            tell_object(player,"Even "+diety+" is unable to save you from here.");
            dest_effect();
            return 0;
        }
    }
    if(room->is_temple() && (string)room->query_diety() == diety){
        tell_object(player,"You are already in your temple!");
        dest_effect();
        return 1;
    }
    switch(lower_case(diety)){
        case "pan":
            tell_object(player,"You must have a god to use this spell.");
            dest_effect();
            break;
        case "akadi":
            tell_object(player,"%^BOLD%^%^WHITE%^You hear soothing whispers in"+
                " the wind and feel lighter than air as you become one with"+
                " the winds of Akadi and are swept away!");
            tell_room(room, "%^BOLD%^%^WHITE%^A cyclone of wind"+
                " suddenly errupts around "+playername+" and "+player->query_possessive()+" "+
                "body seems to soften and is dispersed in a cloudlike whisp of"+
                " air before being swept away by the wind!", ({player}));
            tell_room(find_object_or_load(where),"%^BOLD%^%^WHITE%^A hazy cyclone"+
                " suddenly sweeps into the area, dispersing as it arrives to reveal"+
                " the wispy shape of "+playername+".",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^WHITE%^The winds slow and you sigh wistfully"+
                " as your body begins to take shape again as you are released from"+
                " Akadi's embrace.");
            dest_effect();
            break;
        case "anhur":
            tell_object(player,"%^BOLD%^%^RED%^You hear the steady beat of "+
                "the drums of war rise around you as a %^BLUE%^war banner "+
                "%^RED%^whips about on the wind, wrapping itself around you!%^RESET%^");
            tell_room(EETO, "%^BOLD%^%^RED%^The steady beat of the drums "+
                "of war rise suddenly in the air as a %^BLUE%^war banner "+
                "%^RED%^whips about on the wind, wrapping itself around "+
                ""+playername+"!%^RESET%^", ({player}));
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^A "+
                "%^RED%^war banner%^BLUE%^ suddenly appears in midair, "+
                "whipping on the wind as it unfurls to reveal "+playername+"!%^RESET%^",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLUE%^The strong wind blows again, "+
                "ripping the %^RED%^war banner %^BLUE%^from you as it "+
                "leaves you at the altar of %^RED%^Anhur%^BLUE%^!%^RESET%^");
            dest_effect();
            break;
        case "auppenser":
            tell_object(player,"%^BOLD%^%^CYAN%^Shards of %^WHITE%^c%^RED%^r%^YELLOW%^y"+
                "%^GREEN%^s%^BLUE%^t%^MAGENTA%^a%^RESET%^%^CYAN%^l%^MAGENTA%^s%^BOLD%^"+
                "%^CYAN%^ fly through the air and forms a protective coccon around you."+
                "   A %^RESET%^%^ORANGE%^bronze%^BOLD%^%^CYAN%^ light bursts forth "+
                "within the crystal and you feel yourself pulled away.");
            tell_room(room,"%^BOLD%^%^CYAN%^Shards of %^WHITE%^c%^RED%^"+
                "r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a%^RESET%^%^CYAN%^l"+
                "%^MAGENTA%^s%^BOLD%^%^CYAN%^ fly through the air and forms "+
                "a protective coccon around "+playername+".   A %^RESET%^%^ORANGE%^"+
                "bronze%^BOLD%^%^CYAN%^ light bursts forth "+
                "within the crystal, taking it and "+playername+" with it!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A %^BOLD%^"+
                "%^WHITE%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a"+
                "%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^ appears in a burst of "+
                "%^RESET%^%^ORANGE%^bronze%^BOLD%^%^CYAN%^ lights.  The crystal"+
                " cracks and falls apart, revealing "+playername+"!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^CYAN%^You feel a %^RESET%^%^ORANGE%^bronze"+
                "%^BOLD%^%^CYAN%^ light wash over you and reflect off the facets "+
                "of the %^BOLD%^%^WHITE%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a"+
                "%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^.  The crystal cracks and"+
                " falls apart, leaving you before the altar of Auppenser!");
            dest_effect();
            break;
        case "auril":
            tell_object(player,"%^BOLD%^%^CYAN%^You feel your blood run like ice as "+
                "Auril's killing frost envelops you and all goes dark!");
            tell_room(room, "%^BOLD%^%^CYAN%^A sheet of frost spreads"+
                " along "+playername+"'s body, encasing "+player->query_objective()+" before"+
                " bursting violently outward leaving slowly descending snowflakes "+
                "where "+player->QS+" once stood!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A pillar of ice"+
                " climbs upward from the floor, cracks spreading across its length"+
                " before shattering to reveal a frost covered "+playername+".",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^CYAN%^You feel the cold touch of your goddess"+
                " stir you to life.  Flexing your limbs you burst free from your icy embrace.");
            dest_effect();
            break;
        case "bane":
            tell_object(player,"%^BOLD%^%^GREEN%^Your vision flares green and your form"+
                " flickers as the %^BLACK%^Black hand %^GREEN%^reclaims you!");
            tell_room(room,"%^BOLD%^%^GREEN%^Green fire bursts from"+
                " "+playername+"'s eyes as "+player->query_possessive()+" form shimmers %^BLACK%^wraithlike"+
                " %^GREEN%^before vanishing completely!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A peel of thunder"+
                " echoes throughout the temple as %^GREEN%^shimmering green flames"+
                " %^BLACK%^burst to life before the altar revealing the kneeling "+
                "form of "+playername+"!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLACK%^You feel the overwhelming presence of"+
                " the Black Hand within the blinding %^GREEN%^flames %^BLACK%^forcing"+
                " you to your knees.  The %^GREEN%^flames %^BLACK%^slowly flicker and"+
                " die, leaving you before the mighty likeness of your lord.");
            dest_effect();
            break;
        case "beshaba":
            tell_object(player,"%^BOLD%^%^MAGENTA%^A whirling mass of %^BOLD%^%^BLACK%^"+
                "gloomwing moths%^BOLD%^%^MAGENTA%^ encircle you.  You feel "+
                "yourself being pulled away as a wild laughter echoes around you!");
            tell_room(room,"%^BOLD%^%^MAGENTA%^A whirling mass of "+
                "%^BOLD%^%^BLACK%^gloomwing moths%^BOLD%^%^MAGENTA%^ encircles"+
                " "+playername+", hiding "+player->QCN+" from sight as a wild laughter "+
                "echoes around you.  The moths dissolve away and "+playername+" is gone!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^RED%^A whirling mass of "+
                "%^BOLD%^%^BLACK%^gloomwing moths%^BOLD%^%^RED%^ appears in "+
                "the temple.  A crackling red burst of light shoots out of "+
                "the mass of moths.  The moths fades away and "+playername+" appears!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^RED%^Your vision is clouded by some "+
                "%^BOLD%^%^BLACK%^whirling%^BOLD%^%^RED%^ shapes.  A burst of "+
                "crackling red light blinds you momentarily as the shapes fade"+
                " away.  Slowly you open your eyes and find yourself before Beshaba's altar!");
            dest_effect();
            break;
        case "cyric":
            tell_object(player,"%^BOLD%^%^BLACK%^You hear a sinister whispering in "+
                "your ear as you fade from sight.");
            tell_room(room,"%^RESET%^%^BLUE%^"+playername+" dissolves in "+
                "a whirl of %^BOLD%^%^WHITE%^"+(player->query_race())+" skulls, "+
                "%^RESET%^%^BLUE%^leaving nothing behind but two %^BOLD%^%^BLACK%^"+
                "black eyes %^RESET%^%^BLUE%^that fade slowly!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A whirl of "+
                "%^WHITE%^"+(player->query_race())+" skulls %^BLACK%^appears before "+
                "the altar and fades quickly, leaving "+playername+" kneeling.",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^BLUE%^The strength of %^BOLD%^%^BLACK%^Cyric"+
                " %^RESET%^%^BLUE%^rips from your body, leaving you kneeling before "+
                "his altar with a vision of %^BOLD%^%^BLACK%^two black eyes %^RESET%^"+
                "%^BLUE%^searing into your mind.");
            dest_effect();
            break;
        case "grumbar":
            tell_object(player,"%^RESET%^%^ORANGE%^You call the favor of Grumbar and feel"+
                " yourself sink into the earth as it welcomes you home.");
            tell_room(room,"%^RESET%^%^ORANGE%^Rich brown earth rises at "+
                "the feet of "+playername+", and "+player->QS+" sinks quickly from sight!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^"+playername+" bursts"+
                " forth from the earth and lands kneeling before the altar.",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^ORANGE%^The embrace of the earth releases you,"+
                " leaving you kneeling before the altar of your lord.");
            dest_effect();
            break;
        case "helm":
            tell_object(player,"%^BOLD%^%^BLUE%^You see an unblinking eye before you and "+
                "feel the strong will of Helm envelope you, whisking you from harm!");
            tell_room(room,"%^BOLD%^%^BLUE%^An unblinking eye appears in "+
                "the air before "+playername+" and "+player->query_subjective()+" is gone in a flash of "+
                "brilliant light!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^A %^YELLOW%^flash "+
                "%^BLUE%^of %^YELLOW%^light %^BLUE%^blinds you briefly!  As you open "+
                "your eyes again, you see "+playername+" kneeling before the altar.",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLUE%^The Guardian's watchful eye leaves you "+
                "kneeling before his altar, safe from harm.");
            dest_effect();
            break;
        case "istishia":
            tell_object(player,"%^BOLD%^%^CYAN%^You suddenly stop breathing as you feel "+
                "your body become water and you melt away.");
            tell_room(room,"%^BOLD%^%^CYAN%^"+playername+"'s skin glitters "+
                "iridescently before "+player->QS+" liquifies and fades from view!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^"+playername+" suddenly"+
                " solidifies before the altar, gasping for breath!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^CYAN%^Your body returns with a jolt, and you "+
                "find yourself gasping for breath before the altar of Istishia!");
            dest_effect();
            break;
        case "kelemvor":
            tell_object(player,"%^RESET%^You hear a wailing wind and your vision fades "+
                "as you feel yourself whisked away!");
            tell_room(room,"A wailing wind rises as "+playername+" suddenly"+
                " seems to be nothing more than a skull barely visible beneath a "+
                "deeply hooded robe.  The wind gusts violently, and "+playername+" is gone!",player);
            tell_room(find_object_or_load(where),""+playername+" begins to manifest slowly,"+
                " surrounded by the translucent image of a ghostly shroud.  The shroud"+
                " fades, leaving "+playername+" kneeling before the altar!",player);
            player->move_player(where);
            tell_object(player,"You feel the strength of Kelemvor coursing through you as you"+
                " appear kneeling before his altar.");
            dest_effect();
            break;
        case "kossuth":
            tell_object(player,"%^BOLD%^%^RED%^Flames spring up around you, and you feel "+
                "yourself being whisked away!");
            tell_room(room,"%^BOLD%^%^RED%^A pillar of flame rises at "+
                "once, immolating "+playername+" at its center!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^RED%^A pillar of flame "+
                "drops from the sky, leaving "+playername+" prostrate before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^RED%^Your breath rushes out of you as you land"+
                " prostrate before the altar of Kossuth, the flames dissipating around you.");
            dest_effect();
            break;
        case "lathander":
            tell_object(player,"%^RESET%^%^ORANGE%^You feel yourself surrounded by an "+
                "almost tangible %^YELLOW%^ray %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight"+
                " %^RESET%^%^ORANGE%^that leaves you insubstantial for a moment!");
            tell_room(room,"%^RESET%^%^ORANGE%^A ray of %^YELLOW%^sunlight"+
                " %^RESET%^%^ORANGE%^rises from "+playername+"'s feet and swirls upwards "+
                "around "+player->query_objective()+".  When it clears, "+player->query_subjective()+" is gone!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^A %^YELLOW%^"+
                "swirling beam %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight %^RESET%^"+
                "%^ORANGE%^races to the floor, leaving "+playername+" in its wake!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^ORANGE%^You feel yourself being whisked away,"+
                " and when your vision clears, you are standing before the altar"+
                " of Lathander!");
            dest_effect();
            break;
        case "loviatar":
            tell_object(player,"%^RESET%^%^BLUE%^Several grinning %^BOLD%^%^BLACK%^imps"+
                " %^RESET%^%^BLUE%^appear before you, and you feel the blessed sting"+
                " of their lashes as you're dragged through a portal!");
            tell_room(room,"%^RESET%^%^BLUE%^Several grinning "+
                "%^BOLD%^%^BLACK%^imps %^RESET%^%^BLUE%^appear and lash out "+
                "with whips, ensnaring "+playername+" and dragging "+player->query_objective()+" through"+
                " an %^BOLD%^%^BLACK%^inky black portal!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^BLUE%^A gaping "+
                "%^BOLD%^%^BLACK%^black portal %^RESET%^%^BLUE%^opens in the "+
                "temple, and grinning %^BOLD%^%^BLACK%^imps %^RESET%^%^BLUE%^shove"+
                " "+playername+" through, leaving "+player->query_objective()+" prostrate before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^BLUE%^The %^BOLD%^%^BLACK%^imps %^RESET%^"+
                "%^BLUE%^release their hold and shove you through the open %^BOLD%^"+
                "%^BLACK%^portal, %^RESET%^%^BLUE%^leaving you prostrate before "+
                "the altar of Loviatar!");
            dest_effect();
            break;
        case "malar":
            tell_object(player,"%^BOLD%^%^BLACK%^You hear a guttural growl as jaws "+
                "suddenly close around you and a great black feline jerks you away!");
            tell_room(room,"%^RESET%^%^RED%^A great %^BOLD%^%^BLACK%^"+
                "black feline %^RESET%^%^RED%^with %^BOLD%^bloody claws %^RESET%^"+
                "%^RED%^appears suddenly and grabs "+playername+" in its great jaws "+
                "before disappearing with "+player->query_objective()+"!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^RED%^A great %^BOLD%^"+
                "%^BLACK%^black feline %^RESET%^%^RED%^with %^BOLD%^bloody claws"+
                " %^RESET%^%^RED%^appears suddenly and drops "+playername+" onto the "+
                "ground before the altar before the cat disappears again!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLACK%^The great jaws open, leaving you on"+
                " the ground before the altar of Malar before the cat disappears!");
            dest_effect();
            break;
        case "mask":
            tell_object(player,"%^BOLD%^%^BLACK%^You hear a low chuckle and feel the"+
                " presence of Mask as you disappear into your own shadow!");
            tell_room(room,"%^BOLD%^%^BLACK%^With a confident smirk,"+
            " "+playername+" melds into "+player->query_possessive()+" own shadow and vanishes from sight!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^You suddenly "+
                "notice "+playername+" is kneeling before the altar.  Hmm...was "+
                ""+player->QS+" there before?",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLACK%^You step smoothly from the shadows,"+
                " kneeling before the altar of Mask as if you've been there "+
                "all along.");
            dest_effect();
            break;
        case "mielikki":
            tell_object(player,"%^BOLD%^%^GREEN%^A sudden wind answers your prayers, "+
                "bringing with it a swirl of leaves that whisk you away to safety!");
            tell_room(room,"%^BOLD%^%^GREEN%^A brisk wind rises, "+
                "bringing a swirl of leaves centered around "+playername+".  When the"+
                " wind dies and the leaves fall, "+playername+" is gone!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^GREEN%^Winds whip "+
                "around you as a whirl of leaves enters the temple, spinning away"+
                " and leaving "+playername+" before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^GREEN%^A warm voice brings whispered "+
                "blessings to your ears before you are left kneeling before the"+
                " altar of Mielikki!");
            dest_effect();
            break;
        case "mystra":
            tell_object(player,"%^BOLD%^%^RED%^At your urgent prayers, a %^RESET%^"+
                "%^RED%^delicate red mist %^BOLD%^%^RED%^rolls into the area, "+
                "taking you away!");
            tell_room(room,"%^RESET%^%^RED%^A delicate red mist "+
                "rolls into the area, blanketing all within its path.  When it"+
                " clears, "+playername+" is gone!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^RED%^A deep red "+
                "mist forms before the altar amid whispers of the arcane before"+
                " it disappates, leaving "+playername+" behind!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^RED%^The intricate words of ages old "+
                "spells come unbidden to your mind before they leave you standing"+
                " before the altar of Mystra!");
            dest_effect();
            break;
        case "torm":
            tell_object(player,"%^BOLD%^%^CYAN%^You see a translucent protective "+
                "sphere form around you before you feel yourself being torn away!");
            tell_room(room,"%^BOLD%^%^CYAN%^A protective sphere forms"+
                " around "+playername+", and "+player->query_subjective()+" disappears as you watch!",player);
            tell_room(find_object_or_load(where),"%^YELLOW%^A brilliant flash of"+
                " light dazzles your eyes before you focus on "+playername+" kneeling"+
                " before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^YELLOW%^Your eyes are dazzled by a brilliant light"+
                " before they clear and you find yourself kneeling before the "+
                "altar of Torm!");
            dest_effect();
            break;
        case "oghma":
            tell_object(player,"%^BOLD%^%^BLUE%^Answering your fervent prayers, a "+
                "magnificent %^CYAN%^blue-green owl %^BLUE%^seemingly made of "+
                "pure energy swoops in on the wings of awe-inspiring music to "+
                "carry you away!");
            tell_room(room,"%^BOLD%^%^BLUE%^A magnificent %^CYAN%^"+
                "blue-green owl %^BLUE%^seemingly made of pure energy swoops in "+
                "on the wings of awe-inspiring music to carry "+playername+" away!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^An amazing owl"+
                " made of %^CYAN%^blue-green energy %^BLUE%^swoops in suddenly "+
                "and places "+playername+" gently before the altar before flying out"+
                " again!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLUE%^The %^CYAN%^owl %^BLUE%^places you "+
                "gently before the altar of Oghma before swooping out of the "+
                "temple, leaving its song in your heart!");
            dest_effect();
            break;
        case "selune":
            tell_object(player,"%^BOLD%^You whisper fervently to your goddess and "+
                "feel her loving embrace whisk you away to safety!");
            tell_room(room,"%^BOLD%^"+playername+" whispers an urgent "+
                "prayer and disappears suddenly, leaving behind a few moonmotes"+
                " fluttering to the ground!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^A few dazzling moonmotes"+
                " dance on the air in front of the altar before "+playername+" suddenly"+
                " appears, shrouded in brilliant moonlight!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^Selune whispers soft blessings into your ears"+
                " as she returns you to the sanctity of her temple, leaving you "+
                "before the altar with a moonmotes dancing around you.");
            dest_effect();
            break;
        case "shar":
            tell_object(player,"%^BOLD%^%^BLACK%^Your prayers bring the velvety caress"+
                " of Shar, who shields you in her darkness as you are spirited away!");
            tell_room(room,"%^BOLD%^%^BLACK%^A shroud of tangible "+
                "darkness blossoms into existance, shielding "+playername+" from view."+
                "  When the area lightens again, "+playername+" is nowhere to be found!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A tangible field"+
                " of darkness coalesces before the altar and solidifies into"+
                " "+playername+"!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLACK%^The blessed caress of Shar leaves you "+
                "feeling a strong sense of loss as you appear before her altar.");
            dest_effect();
            break; 
        case "shaundakul":
            tell_object(player,"%^CYAN%^A gust of wind blows through the area.  The winds"+
                " pick you up and carry you away!");
            tell_room(room,"%^CYAN%^A gust of wind blows through the area."+
                "  The winds pick up "+playername+", and carry "+player->query_objective()+" away!",player);
            tell_room(find_object_or_load(where),"%^CYAN%^A gust of wind blows "+
                "into the temple and gently sets "+playername+" down before the altar"+
                " of Shaundakul!",player);
            player->move_player(where);
            tell_object(player,"%^CYAN%^The winds carry you along quickly, the terrain"+
                " and landscape below you whizzing by.  The winds begin to decrease"+
                " in intensity, gently lowering you before the altar of Shaundakul.");
            dest_effect();
            break;
        case "silvanus":
            tell_object(player,"%^RESET%^%^GREEN%^From the ground beneath your feet, "+
                "vines suddenly snake up and around your form to steal you away!");
            tell_room(room,"%^RESET%^%^GREEN%^Vines suddenly snake up "+
                "from the ground to entangle "+playername+".  They disintegrate a matter "+
                "of seconds later, and "+playername+" is gone!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^GREEN%^A thrum of power "+
                "carries on the wind, as vines snake up from the earth and unfold to "+
                "reveal "+playername+"!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^ORANGE%^An oak leaf tumbles past you and to "+
                "the ground, as the vines unfold to leave you within the sanctuary of "+
                "the Oakfather once more.");
            dest_effect();
            break;
        case "sune":
            tell_object(player,"%^RED%^A whirling tendril of flames burst into "+
                "existence and starts to wrap around you.  The sweet perfume"+
                " of fragrant roses fills your senses as you feel the flames"+
                " pulling you inwards.");
            tell_room(room,"%^RED%^A whirling tendril of flames"+
                " burst into existence and starts to wrap around "+playername+".  "+
                "The fragrant perfume of roses fills the area as the flames "+
                "vanish in a flash, taking "+player->query_objective()+" with them!",player);
            tell_room(find_object_or_load(where),"%^RED%^The fragrant aroma"+
                " of roses fills the temple as a mass of whirling flames burst"+
                " into existence.  The flames start to unwrap, leaving "+playername+" "+
                "before the altar of Sune!",player);
            player->move_player(where);
            tell_object(player,"%^RED%^Waves of bliss wash over your mind as the"+
                " fragrance of roses fills your senses.  The flames about you"+
                " start to unwrap, leaving you before the radiant beauty of "+
                "Sune Firehair's altar!");
            dest_effect();
            break;
        case "talos":
            tell_object(player,"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^"+
                "strikes from the sky, leaving you feeling the blissful energy of the storm!");
            tell_room(room,"%^YELLOW%^A bolt of %^BLACK%^black lightning"+
                " %^YELLOW%^strikes "+playername+", leaving nothing at all behind!",player);
            tell_room(find_object_or_load(where),"%^YELLOW%^A bolt of %^BLACK%^black "+
                "lightning %^YELLOW%^strikes the floor of the temple, leaving "+playername+" "+
                "before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^YELLOW%^The energy fades, and you feel a final pulse "+
                "that leaves you before the altar of Talos!");
            dest_effect();
            break;
        case "tempus":
            tell_object(player,"%^RESET%^%^RED%^As you call for aid, you hear the din of "+
                "battle rise around you.  Suddenly, a spectral warhorse charges into the"+
                " area and speeds away with you before your vision fades!");
            tell_room(room,"%^RESET%^%^RED%^The din of battle fills the air"+
                " as a spectral war horse rides into the area, speeding away with"+
                " "+playername+" into nothingness!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^RED%^The sound of hooves "+
                "rises over a sudden din of battle as a warhorse appears from nowhere and"+
                " lowers "+playername+" to the ground before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^RED%^Your vision clears once more, and you find"+
                " yourself being lowered to the ground before the altar of Tempus before"+
                " the horse fades again!");
            dest_effect();
            break;
        case "tymora":
            tell_object(player,"%^BOLD%^%^MAGENTA%^You hear an innocent %^YELLOW%^golden giggle"+
                " %^MAGENTA%^and find yourself surrounded by a shimmering %^WHITE%^silver"+
                " sheen %^MAGENTA%^that speeds you away towards safety!");
            tell_room(room,"%^BOLD%^%^MAGENTA%^You hear an innocent "+
                "%^YELLOW%^golden giggle %^MAGENTA%^as "+playername+" just vanishes "+
                "from sight!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^MAGENTA%^A shimmering "+
                "%^WHITE%^silver coin %^MAGENTA%^appears before the altar and grows "+
                "into the image of "+playername+" before it fades, leaving "+player->query_objective()+" behind!",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^MAGENTA%^You appear before the altar of Tymora"+
                " as you hear a playful voice singing before it fades away!");
            dest_effect();
            break;
        case "tyr":
            tell_object(player,"%^YELLOW%^As the prayer to Tyr leaves your lips, you hear"+
                " a resounding gong and are spirited away to safety!");
            tell_room(room,"%^YELLOW%^"+playername+" vanishes as the exultant "+
                "stroke of a gong resounds all around you accompanied by a wordless chorus"+
                " of chanting voices!",player);
            tell_room(find_object_or_load(where),"%^YELLOW%^You hear the chanting of "+
                "unseen voices before a gong suddenly sounds and "+playername+" appears before"+
                " the altar!",player);
            player->move_player(where);
            tell_object(player,"%^YELLOW%^With the robust crash of a gong, you are suddenly"+
                " within the temple just before the altar of Tyr!");
            dest_effect();
                break;
        case "jarmila":
            tell_object(player,"%^RESET%^%^ORANGE%^You feel yourself surrounded by an "+
                "almost tangible %^YELLOW%^ray %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight"+
                " %^RESET%^%^ORANGE%^that leaves you insubstantial for a moment!");
            tell_room(room,"%^RESET%^%^ORANGE%^A ray of %^YELLOW%^sunlight"+
                " %^RESET%^%^ORANGE%^rises from "+playername+"'s feet and swirls upwards "+
                "around "+player->query_objective()+".  When it clears, "+player->query_subjective()+" is gone!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^A %^YELLOW%^"+
                "swirling beam %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight %^RESET%^"+
                "%^ORANGE%^races to the floor, leaving "+playername+" in its wake!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^ORANGE%^You feel yourself being whisked away,"+
                " and when your vision clears, you are standing before the altar"+
                " of Jarmila!");
            dest_effect();
            break;
        case "lysara":
            tell_object(player,"%^CYAN%^The sweet %^BOLD%^%^MAGENTA%^scent %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^li%^RED%^%^MAGENTA%^l%^RED%^i%^MAGENTA%^es %^RESET%^%^CYAN%^fills the %^BOLD%^air%^RESET%^%^CYAN%^, and you hear a %^BOLD%^%^BLACK%^bell %^RESET%^%^CYAN%^begin to %^BOLD%^toll%^RESET%^%^CYAN%^, as a %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form behind you. The faint outline of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne%^RESET%^s %^CYAN%^and %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^s can be seen within the %^BOLD%^%^WHITE%^mist%^RESET%^%^CYAN%^. You feel the %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^wrap around you in a %^BOLD%^comforting %^RESET%^%^CYAN%^embrace, suffusing your %^BOLD%^%^MAGENTA%^soul %^RESET%^%^CYAN%^with %^BOLD%^%^WHITE%^calm %^RESET%^%^CYAN%^and %^BOLD%^peace%^RESET%^%^CYAN%^.");
            tell_room(room,"%^CYAN%^The %^BOLD%^%^MAGENTA%^aroma %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^li%^RED%^l%^MAGENTA%^i%^RED%^e%^MAGENTA%^s %^RESET%^%^CYAN%^fills the %^BOLD%^air%^RESET%^%^CYAN%^, and you can hear a %^BOLD%^%^BLACK%^bell %^RESET%^%^CYAN%^begin to toll, as a %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form behind "+playername+". A faint outline of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^s can be seen within the %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^as it begins to %^BOLD%^wrap %^RESET%^%^CYAN%^around "+playername+", pulling "+player->query_subjective()+" into it.",player);
            tell_room(find_object_or_load(where),"%^CYAN%^A %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form in the center of the %^BOLD%^t%^RESET%^%^CYAN%^e%^BOLD%^m%^RESET%^%^CYAN%^p%^BOLD%^l%^RESET%^%^CYAN%^e, the faint outline of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and "+playername+" beginning to form. "+playername+" steps out of the %^BOLD%^%^WHITE%^mist%^RESET%^%^CYAN%^, with only the faint %^BOLD%^%^MAGENTA%^scent %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^l%^RED%^i%^MAGENTA%^l%^RED%^i%^MAGENTA%^es %^RESET%^%^CYAN%^is left behind.",player);
            player->move_player(where);
            tell_object(player,"%^CYAN%^The feeling of %^BOLD%^%^WHITE%^calm %^RESET%^%^CYAN%^and %^BOLD%^peace %^RESET%^%^CYAN%^begins to leave you as the %^BOLD%^embrace %^RESET%^%^CYAN%^of the %^BOLD%^%^WHITE%^mist %^BLACK%^evaporates%^RESET%^%^CYAN%^, to leave you standing in the temple of %^BOLD%^L%^RESET%^%^CYAN%^y%^BOLD%^s%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^CYAN%^a");
            dest_effect();
            break;   
        case "nimnavanon":
            tell_object(player,"%^RESET%^%^GREEN%^As %^WHITE%^you %^GREEN%^end the spell, calling on the %^BOLD%^%^WHITE%^aid %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon%^RESET%^%^GREEN%^, %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^ %^GREEN%^and %^ORANGE%^s%^GREEN%^hr%^ORANGE%^u%^GREEN%^b%^ORANGE%^s %^GREEN%^begin to %^YELLOW%^grow %^RESET%^%^GREEN%^from the %^ORANGE%^ground %^GREEN%^around you. Within seconds, you are covered in a sheltered %^WHITE%^cocoon %^GREEN%^of %^BOLD%^p%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^s and are drawn into the ground.");
            tell_room(room,"%^RESET%^%^GREEN%^"+playername+" calls to the %^BOLD%^%^WHITE%^aid %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon%^RESET%^%^GREEN%^, and shrubs and %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^%^GREEN%^begin to %^YELLOW%^grow %^RESET%^%^GREEN%^from the %^ORANGE%^ground %^GREEN%^to cover their entire body, before they pull the p%^BOLD%^l%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^tl%^BOLD%^i%^RESET%^%^GREEN%^k%^BOLD%^e %^RESET%^cocoon %^GREEN%^into the %^ORANGE%^ground.",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^GREEN%^Suddenly, a %^WHITE%^cocoon %^GREEN%^of %^BOLD%^p%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^s in the shapes of different s%^ORANGE%^h%^GREEN%^ru%^ORANGE%^b%^GREEN%^s and %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^es %^BOLD%^g%^RESET%^%^GREEN%^rows from the %^ORANGE%^earth%^GREEN%^.  And, as they seem to withdraw, they leave "+playername+" standing in front of the %^BOLD%^Altar %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^GREEN%^As the the sh%^ORANGE%^r%^GREEN%^u%^ORANGE%^b%^GREEN%^s and %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^%^GREEN%^lets go of your body, you find yourself in the %^BOLD%^Temple %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon!");
            dest_effect();    
            break;
        case "lord_shadow":
            tell_object(player,"%^BOLD%^%^BLACK%^You end y%^WHITE%^o%^BLACK%^u%^WHITE%^r d%^RESET%^%^RED%^ark %^WHITE%^chanting%^BOLD%^%^BLACK%^, and you feel the bl%^RESET%^a%^BOLD%^%^BLACK%^c%^RESET%^k%^BOLD%^%^BLACK%^nes%^RESET%^s %^BOLD%^%^BLACK%^around you grow th%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r and th%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r, %^WHITE%^w%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^p%^WHITE%^p%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g around you like the %^WHITE%^chill %^RESET%^%^CYAN%^embrace %^BOLD%^%^BLACK%^of d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h. You can feel your %^RESET%^%^RED%^life %^BOLD%^%^BLACK%^stop, your %^RED%^heart %^BLACK%^cease beating, and you are unable to %^CYAN%^draw %^BLACK%^breath. Dark spots form in your %^ORANGE%^vision%^BLACK%^, and you can only think of one thing, the %^WHITE%^greatness %^BLACK%^of L%^RESET%^o%^BOLD%^%^BLACK%^rd Sh%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w.");
            tell_room(room,"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^terrible %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^ss begins to form around "+playername+".C%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^w%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ng s%^RESET%^h%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^s %^BOLD%^%^BLACK%^of the deepest t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rr%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^r begin to wrap around "+playername+". You can see how a %^MAGENTA%^scream %^BLACK%^almost forms, and then "+playername+" appears to %^WHITE%^freeze %^BLACK%^in d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h's %^CYAN%^icy %^WHITE%^grip%^BLACK%^. The s%^RESET%^h%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^s %^BOLD%^%^BLACK%^seem to %^RESET%^%^MAGENTA%^devour %^BOLD%^%^BLACK%^"+playername+", and within a %^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ar%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^be%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^, "+playername+" is no more.",player);
            tell_room(find_object_or_load(where), "%^BOLD%^%^BLACK%^The sound of m%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^f%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^l %^WHITE%^keening %^BOLD%^%^BLACK%^starts to fill the %^WHITE%^temple%^BLACK%^, followed by a m%^RESET%^a%^BOLD%^%^BLACK%^ss of d%^RESET%^a%^BOLD%^%^BLACK%^rk%^RESET%^n%^BOLD%^%^BLACK%^es%^RESET%^s %^BOLD%^%^BLACK%^and t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nd%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^s of s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^e. From the m%^RESET%^a%^BOLD%^%^BLACK%^ss of sh%^RESET%^ad%^BOLD%^%^BLACK%^ows "+playername+" takes a deep %^CYAN%^breath%^BLACK%^, and mutters ""%^MAGENTA%^%^RESET%^Thank you, Lord Shadow%^BOLD%^%^MAGENTA%^",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^BLACK%^Suddenly, your %^ORANGE%^vision %^BLACK%^clears, your %^RED%^heart %^BLACK%^pumps and your %^CYAN%^lungs %^BLACK%^fill with %^WHITE%^air%^BLACK%^. You look around and find yourself in the %^WHITE%^Temple %^BLACK%^of L%^RESET%^o%^BOLD%^%^BLACK%^rd Sh%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w");
            dest_effect();  
            break;
        case "nilith":
            tell_object(player,"%^ORANGE%^Y%^BOLD%^%^BLACK%^ou f%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^a cold a%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ra upon yo%^RESET%^%^ORANGE%^u %^BOLD%^%^BLACK%^as a din of unea%^RESET%^%^ORANGE%^%^BOLD%^%^BLACK%^th%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^y w%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^ispers s%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^rroun%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^you, as a grey mi%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^t en%^RESET%^%^ORANGE%^ve%^BOLD%^%^BLACK%^lopes you a%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d p%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^lls you to so%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^ewhere else%^RESET%^");
            tell_room(room,"%^BOLD%^%^BLACK%^S%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^im%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^er%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ng sp%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ral %^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^nti%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^ies %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^rl ar%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^un%^RESET%^%^ORANGE%^d%^WHITE%^ "+playername+"%^BOLD%^%^BLACK%^ and%^RESET%^%^ORANGE%^ en%^BOLD%^%^BLACK%^gu%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^f them. As the mist d%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^s,%^RESET%^ "+player->QS+" %^BOLD%^%^BLACK%^is %^WHITE%^gone!%^RESET%^",player);
            tell_room(find_object_or_load(where),"%^ORANGE%^s%^BOLD%^%^BLACK%^pec%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^ra%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^en%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^it%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^es swir%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^up fr%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^m the fl%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^or, le%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^vi%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^g %^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n "+playername+" i%^BOLD%^%^BLACK%^n it's w%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke !",player);
            player->move_player(where);
            tell_object(player,"%^ORANGE%^T%^BOLD%^%^BLACK%^he m%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^st ob%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^cur%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^s your vision, and you feel a %^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^old tug on your soul. Wh%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n the mist dissipates, you find y%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ur%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^elf in the temple of N%^RESET%^i%^BOLD%^l%^RESET%^i%^BOLD%^t%^BLACK%^h%^RESET%^");
            dest_effect();
            break;
        case "kismet":
            tell_object(player,"%^BOLD%^You end your prayer to %^MAGENTA%^Kismet%^WHITE%^, and a %^BLACK%^s%^WHITE%^h%^BLACK%^i%^RESET%^m%^BOLD%^m%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^i%^WHITE%^n%^RESET%^g %^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^e%^BOLD%^nt%^RESET%^%^CYAN%^a%^BOLD%^gr%^RESET%^%^CYAN%^a%^BOLD%^m %^WHITE%^starts to %^ORANGE%^glow %^WHITE%^beneath your feat and around you. In a b%^RESET%^r%^BOLD%^ight %^CYAN%^flash %^WHITE%^of %^ORANGE%^light %^WHITE%^you %^BLACK%^vanish");
            tell_room(room,"%^BOLD%^A %^ORANGE%^glowing %^CYAN%^p%^RESET%^%^CYAN%^e%^BOLD%^nt%^RESET%^%^CYAN%^a%^BOLD%^gr%^RESET%^%^CYAN%^a%^BOLD%^m %^WHITE%^starts to form %^RESET%^%^CYAN%^beneath %^BOLD%^%^WHITE%^and around "+playername+" , and in a %^CYAN%^flash %^WHITE%^of %^ORANGE%^bright lights%^WHITE%^, he %^BLACK%^vanishes!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^A %^ORANGE%^bright %^CYAN%^flash %^WHITE%^of %^RESET%^light %^BOLD%^expands from the center of the %^MAGENTA%^t%^RESET%^%^MAGENTA%^e%^BOLD%^m%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^, and when the %^ORANGE%^light %^WHITE%^vanishes "+playername+" is %^BLACK%^left %^WHITE%^behind.",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^You are %^CYAN%^pulled %^WHITE%^by the %^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^a%^RESET%^%^MAGENTA%^v%^BOLD%^e%^WHITE%^, and within a %^RED%^h%^RESET%^%^RED%^e%^BOLD%^art%^RESET%^%^RED%^b%^BOLD%^e%^RESET%^%^RED%^a%^BOLD%^t %^WHITE%^you %^CYAN%^m%^RESET%^%^CYAN%^a%^BOLD%^te%^RESET%^%^CYAN%^r%^BOLD%^ia%^RESET%^%^CYAN%^l%^BOLD%^iz%^RESET%^%^CYAN%^e %^BOLD%^%^WHITE%^within the Temple of %^MAGENTA%^K%^RESET%^%^MAGENTA%^i%^BOLD%^sm%^RESET%^%^MAGENTA%^e%^BOLD%^t");
            dest_effect();
            break; 
        case "callamir":
            tell_object(player,"%^BOLD%^%^CYAN%^You throw a pair of %^WHITE%^dice %^CYAN%^to the ground and they come up as %^WHITE%^two sixes%^CYAN%^. With a smile on your %^RED%^lips %^CYAN%^your body begins to become %^RESET%^i%^CYAN%^n%^WHITE%^s%^CYAN%^u%^WHITE%^b%^CYAN%^s%^WHITE%^t%^CYAN%^a%^WHITE%^nt%^CYAN%^i%^WHITE%^a%^CYAN%^l %^BOLD%^and you %^BLACK%^vanish %^CYAN%^from %^ORANGE%^sight!");
            tell_room(room,"%^BOLD%^%^CYAN%^"+playername+" tosses a pair of %^WHITE%^dice %^CYAN%^onto the ground, and as they %^RESET%^%^MAGENTA%^roll %^BOLD%^%^CYAN%^to a halt, they show %^WHITE%^two sixes%^CYAN%^. With that, his body begins to %^RESET%^%^CYAN%^d%^WHITE%^i%^CYAN%^s%^WHITE%^a%^CYAN%^p%^WHITE%^p%^CYAN%^e%^WHITE%^a%^CYAN%^r %^BOLD%^from %^ORANGE%^sight!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A %^ORANGE%^bright %^BLUE%^light %^CYAN%^flares to %^WHITE%^life%^CYAN%^, and from within the %^ORANGE%^light%^CYAN%^, first a pair of %^WHITE%^dice %^CYAN%^roll over the temple floor, showing %^WHITE%^two sixes%^CYAN%^.  Almost immediately afterwards, "+playername+"  steps out from within the %^ORANGE%^light%^CYAN%^, looking around with a %^MAGENTA%^smile%^CYAN%^.",player);
            player->move_player(where);
            tell_object(player,"%^BOLD%^%^CYAN%^You feel the pull of C%^WHITE%^a%^CYAN%^ll%^WHITE%^a%^CYAN%^m%^WHITE%^i%^CYAN%^r as your %^BLACK%^tr%^RESET%^a%^BOLD%^%^BLACK%^nsp%^RESET%^o%^BOLD%^%^BLACK%^rt%^RESET%^e%^BOLD%^%^BLACK%^d %^CYAN%^over a vast distance. As you come to a %^ORANGE%^halt%^CYAN%^, you see the %^WHITE%^temple %^CYAN%^of C%^WHITE%^a%^CYAN%^ll%^WHITE%^a%^CYAN%^m%^WHITE%^i%^CYAN%^r and on the floor, %^WHITE%^two dice %^CYAN%^with the sixes up.");
            dest_effect();
            break;    
        case "khyron":
            tell_object(player,"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^strikes from the sky, leaving you feeling the blissful energy of the storm!");
            tell_room(room,"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^strikes "+playername+", leaving nothing at all behind!",player);
            tell_room(find_object_or_load(where),"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^strikes the ground of the shrine, leaving "+playername+" before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^YELLOW%^The energy fades, and you feel a final pulse that leaves you before the altar of Ryorik!");
            dest_effect();
            break;        
        case "cevahir":
            tell_object(player,"%^RESET%^%^RED%^As you call for aid, you hear the din of battle rise around you. Suddenly, a spectral warhorse charges into the area and speeds away with you before your vision fades!");
            tell_room(room,"%^RESET%^%^RED%^The din of battle fills the air as a spectral war horse rides into the area, speeding away with "+playername+" into nothingness!",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^RED%^The sound of hooves rises over a sudden din of battle as a warhorse appears from nowhere and lowers "+playername+" to the ground before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^RED%^Your vision clears once more, and you find yourself being lowered to the ground before the altar of Varda before the horse fades again!");
            dest_effect();
            break;      
        case "the_faceless_one":
            tell_object(player,"%^BOLD%^%^BLACK%^You hear a sinister whispering in your ear as you fade from sight.");
            tell_room(room,"%^RESET%^%^BLUE%^"+playername+" dissolves in a whirl of %^BOLD%^%^WHITE%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^o%^BOLD%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^l%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%^e%^BOLD%^r p%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^a%^BOLD%^ls%^RESET%^ %^RESET%^%^BLUE%^leaving nothing behind but two %^BOLD%^%^BLACK%^black eyes %^RESET%^%^BLUE%^that fade slowly!",player);
            tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A whirl of %^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^o%^BOLD%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^l%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%^e%^BOLD%^r p%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^a%^BOLD%^ls %^BOLD%^%^BLACK%^appears before the altar and fades quickly, leaving "+playername+" kneeling.",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^BLUE%^The strength of %^BOLD%^%^BLACK%^The Faceless One %^RESET%^%^BLUE%^rips from your body, leaving you kneeling before his altar with a vision of %^BOLD%^%^BLACK%^two black eyes %^RESET%^%^BLUE%^searing into your mind.");
            dest_effect();
            break;
        case "kreysneothosies":
            tell_object(player,"%^BOLD%^%^CYAN%^You see a translucent protective sphere form around you before you feel yourself being torn away!");
            tell_room(room,"%^BOLD%^%^CYAN%^A protective sphere forms around "+playername+", and "+player->QS+" disappears as you watch!",player);
            tell_room(find_object_or_load(where),"%^YELLOW%^A brilliant flash of light dazzles your eyes before you focus on "+playername+" kneeling before the altar!",player);
            player->move_player(where);
            tell_object(player,"%^YELLOW%^Your eyes are dazzled by a brilliant light before they clear and you find yourself kneeling before the altar of Kreysneothosies!");
            dest_effect();
            break;   
        case "ashra":
            tell_object(player,"%^RESET%^%^CRST%^%^C091%^The %^C059%^sh%^C243%^ad%^C059%^ow%^C243%^s %^C103%^pool %^RESET%^%^C091%^about your feet before splashing upwards around you!%^CRST%^");
            tell_room(room,"%^RESET%^%^CRST%^%^C091%^The %^C059%^sh%^C243%^ad%^C059%^ow%^C243%^s %^C103%^pool %^RESET%^%^C091%^around "+playername+"%^RESET%^%^CRST%^%^C091%^'s feet before splashing upwards! "+capitalize(player->query_subjective())+"%^RESET%^%^CRST%^%^C091%^ is gone when they fall and dissipate.%^CRST%^",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^CRST%^%^C091%^The %^C059%^sh%^C243%^ad%^C059%^ow%^C243%^s %^C103%^pool %^RESET%^%^C091%^and rise up, revealing "+playername+"%^RESET%^%^CRST%^%^C091%^ as they fall and dissipate.%^CRST%^",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^CRST%^%^C091%^As the %^C059%^sh%^C243%^ad%^C059%^ow%^C243%^s %^RESET%^%^C091%^fall, you find yourself in the temple of Ashra.%^CRST%^");
            dest_effect();
            break;
        case "edea":
            tell_object(player,"%^RESET%^%^CRST%^%^C144%^A %^C214%^s%^C220%^e%^C226%^ari%^C220%^n%^C214%^g l%^C220%^i%^C226%^g%^C220%^h%^C214%^t %^RESET%^%^C144%^fills your eyes, briefly %^C255%^blinding %^C144%^you!%^CRST%^");
            tell_room(room,"%^RESET%^%^CRST%^%^C144%^A %^C214%^s%^C220%^e%^C226%^ari%^C220%^n%^C214%^g l%^C220%^i%^C226%^g%^C220%^h%^C214%^t %^RESET%^%^C144%^radiates from "+playername+"%^RESET%^%^CRST%^%^C144%^, temporarily %^C255%^blinding %^C144%^you! "+capitalize(player->query_subjective())+"%^RESET%^%^CRST%^%^C144%^ is gone when the light fades.%^CRST%^",player);
            tell_room(find_object_or_load(where),"%^RESET%^%^CRST%^%^C144%^A %^C214%^s%^C220%^e%^C226%^ari%^C220%^n%^C214%^g l%^C220%^i%^C226%^g%^C220%^h%^C214%^t %^RESET%^%^C144%^appears, revealing "+playername+"%^RESET%^%^CRST%^%^C144%^ as the light fades.%^CRST%^",player);
            player->move_player(where);
            tell_object(player,"%^RESET%^%^CRST%^%^C144%^As the %^C214%^l%^C220%^i%^C226%^g%^C220%^h%^C214%^t %^RESET%^%^C144%^fades, you find yourself in the temple of Edea.%^CRST%^");
            dest_effect();
            break;
        case "seija":
            tell_object(player, "%^RESET%^%^CRST%^%^C160%^Ten%^C166%^dri%^C178%^l%^C166%^s %^C178%^of %^C166%^f%^C178%^l%^C166%^a%^C160%^me%^RESET%^%^C100%^ rise, pulled upward by a %^C051%^v%^C255%^or%^C051%^t%^C255%^e%^C051%^x%^C100%^ of %^C252%^wi%^C255%^n%^C252%^d%^C100%^ and %^C130%^s%^C095%^a%^C130%^n%^C136%^d%^RESET%^%^C100%^ to engulf you, just before a %^C027%^la%^C033%^rg%^C039%^e w%^C045%^av%^C039%^e wa%^C033%^sh%^C027%^es%^C100%^ you away.%^CRST%^");
            tell_room(room, "%^RESET%^%^CRST%^%^C160%^Ten%^C166%^dri%^C178%^l%^C166%^s %^C178%^of %^C166%^f%^C178%^l%^C166%^a%^C160%^me%^RESET%^%^C100%^ rise, pulled upward by a %^C051%^v%^C255%^or%^C051%^t%^C255%^e%^C051%^x%^C100%^ of %^C252%^wi%^C255%^n%^C252%^d%^C100%^ and %^C130%^s%^C095%^a%^C130%^n%^C136%^d%^RESET%^%^C100%^ to engulf "+playername+"%^RESET%^%^CRST%^%^C100%^, just before a %^C027%^la%^C033%^rg%^C039%^e w%^C045%^av%^C039%^e wa%^C033%^sh%^C027%^es%^C100%^ them away.%^CRST%^",player);
            tell_room(find_object_or_load(where), "%^RESET%^%^CRST%^%^C100%^The %^C027%^la%^C033%^rg%^C039%^e w%^C033%^a%^C027%^ve%^RESET%^%^C100%^ deposits "+playername+" on the %^C095%^gr%^C101%^o%^C136%^u%^C101%^n%^C095%^d%^C100%^.  %^C166%^F%^C172%^l%^C184%^a%^C178%^m%^C172%^e%^C166%^s%^RESET%^%^C100%^ swirl about them, drying them and their things just before a %^C045%^t%^C251%^or%^C255%^r%^C252%^en%^C045%^t%^C051%^ %^C100%^of %^C254%^wi%^C252%^n%^C254%^d%^RESET%^%^C100%^ snuffs them out.%^CRST%^", player);
            player->move_player(where);
            tell_object(player, "%^RESET%^%^CRST%^%^C100%^The %^C027%^la%^C033%^rg%^C039%^e w%^C033%^a%^C027%^ve%^RESET%^%^C100%^ deposits you on the %^C095%^gr%^C101%^o%^C136%^u%^C101%^n%^C095%^d%^C100%^.  %^C166%^F%^C172%^l%^C184%^a%^C178%^m%^C172%^e%^C166%^s%^RESET%^%^C100%^ swirl about you, drying you and your things just before a %^C045%^t%^C251%^or%^C255%^r%^C252%^en%^C045%^t%^C051%^ %^C100%^of %^C254%^wi%^C252%^n%^C254%^d%^RESET%^%^C100%^ snuffs them out.%^CRST%^");
            dest_effect();
            break;
        default:
            tell_object(player,"You are suddenly whisked away as you call to "+diety+".");
            tell_room(room,""+playername+" calls to "+diety+" and suddenly disappears!",player);
            tell_room(find_object_or_load(where),""+playername+" suddenly appears before the altar!",player);
            player->move_player(where);
            dest_effect();
            break; 
    }
    return 1;
}

