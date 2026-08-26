//Modified for fighter update - Octothorpe 6/22/09
//typos fixed by Circe 4/4/05.  Suspect there are still more.
//changed by Circe 5/14/04.  Adding in fighting styles.
//  /cmds/fighter/_flash.c
//  surprise maneuver for dextrous fighters

#include <std.h>
inherit DAEMON;

int abs(int x) {if(x < 0) return 0-x;
    else return x;}

int cmd_flash(){
    string mystyle;
    object ob, player, room;
    int temp1, temp2, which, diff, bonus, level;
    object *weapon;
    
    player = this_player();
    mystyle = player->query_fighter_style();
    room = environment(player);

    if(player->query_ghost()) {
        notify_fail("You are dead and cannot do that.\n");
        return 0;
    }
    if(player->query_disable()) return 1;
    if(undefinedp(player->get_static("flashed")) || (player->get_static("flashed") < time())){
        player->set_static("flashed",time()+random(3)+3);
    }
    else{ 
        player->use_stamina(10);
        tell_object(player, "You're only exhausting yourself, best to wait a moment.");
        return 1;
    }
    if(room->query_property("no attack")){
        notify_fail("You cannot do that here.\n");
        return 0;
    }
    if(player->query_bound() || player->query_tripped() || player->query_paralyzed()){
        player->send_paralyzed_message("info",player);
        return 1;
    }
    if(!(ob = (object)player->query_current_attacker())){
        notify_fail("You are not in battle.\n");
        return 0;
    }
    if(!player->is_class("fighter")){
        write("You are not a fighter and cannot do that.");
        return 1;
    }
    
    temp1 = random(20);
    temp2 = random(20);
    if(temp1 < player->query_stats("strength")) temp1 = temp1;
    else temp1 = 0;  
    if(temp2 < ob->query_stats("strength")) temp2 = temp2;
    else temp2 = 0;
    
    diff = abs((random(player->query_stats("strength"))) - (random(ob->query_stats("strength"))));
    level = player->query_class_level("fighter");
    weapon = player->query_wielded();
   
    if(!sizeof(weapon)) return notify_fail("You need a weapon to use flash.\n");
    if(ob->query_property("weapon resistance")){
        if((weapon == ({}))) diff = 0;
        else if(weapon[0]->query_property("enchantment") < ob->query_property("weapon resistance")) diff = 0;
    }

    if(temp1 > temp2){
        if(level > 0) which = 0;
        if(level > 5) which = random(2);
        if(level > 15) which = random(3);
        if(level > 25) which = random(4);
        if(level > 35) which = random(5);
        TP->set_static("flashed",time()+random(6)+random(6));
        if(which == 0){
            switch(mystyle){
                case "peasant": 
                    tell_object(player,"%^YELLOW%^You turn quickly and plant your elbow in "+ob->query_cap_name()+"'s ribs!");
                    tell_object(ob,"%^YELLOW%^"+player->query_cap_name()+" turns and elbows you quickly in the ribs!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" turns quickly and elbows "+ob->query_cap_name()+" in the ribs!",({player,ob}));
                    break;
                case "swashbuckler":
                    tell_object(player,"%^YELLOW%^With a flourish you whirl, raking your weapon across "+ob->query_cap_name()+"'s face!");
                    tell_object(ob,"%^YELLOW%^With a flourish, "+player->query_cap_name()+" whirls, raking your face with "+player->query_possessive()+" weapon!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" whirls around with a flourish, raking "+player->query_possessive()+" weapon across "+ob->query_cap_name()+"'s face!",({player,ob}));
                    break;
                case "thug":
                    tell_object(player,"%^YELLOW%^Seeing an opening, you rake "+ob->query_cap_name()+"'s eyes!");
                    tell_object(ob,"%^YELLOW%^"+player->query_cap_name()+" rakes your eyes, leaving you in pain!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" rakes "+ob->query_cap_name()+"'s eyes quickly!",({player,ob}));
                    break;
                case "soldier":
                    tell_object(player,"%^YELLOW%^With a well-practiced flick of your wrist, you slam your weapon into "+ob->query_cap_name()+"!");
                    tell_object(ob,"%^YELLOW%^With a smooth flick of "+player->query_possessive()+" wrist, "+player->query_cap_name()+" slams "+player->query_possessive()+" weapon into you!");
                    tell_room(room,"%^YELLOW%^With a smooth flick of "+player->query_possessive()+" wrist, "+player->query_cap_name()+" slams "+player->query_possessive()+" weapon into "+ob->query_cap_name()+"!",({player,ob}));
                    break;
                case "dervish":
                    tell_object(player,"%^YELLOW%^Gathering energy, you twirl suddenly, striking "+ob->query_cap_name()+" twice quickly!");
                    tell_object(ob,"%^YELLOW%^"+player->query_cap_name()+" twirls suddenly, striking you with blinding speed!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" twirls suddenly, striking "+ob->query_cap_name()+" with blinding speed!",({player,ob}));
                    break;
                default:
                    tell_object(player,"%^BOLD%^%^YELLOW%^You swiftly grab your opponent and toss "+ob->query_objective()+" easily to the ground.%^RESET%^");
                    tell_object(ob,"%^BOLD%^%^YELLOW%^You are grabbed by "+player->query_cap_name()+" and thrown to the ground!%^RESET%^");
                    tell_room(room,"%^BOLD%^%^YELLOW%^"+player->query_cap_name()+" grabs "+ob->query_cap_name()+" and hurls "+ob->query_objective()+" to the ground!%^RESET%^",({player,ob}));
                     break;
            }
            if(level > 20) ob->cause_typed_damage(ob, ob->return_target_limb(), diff + random(16), weapon[0]->query_damage_type());
            ob->cause_typed_damage(ob, ob->return_target_limb(), diff, weapon[0]->query_damage_type());
        }
        if(which == 1){
            switch(mystyle){
                case "peasant":
                    tell_object(player,"%^BOLD%^%^BLUE%^You dodge quickly from one side to the other, confusing "+ob->query_cap_name()+"!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" dodges quickly from side to side, confusing you!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" dodges quickly from side to side, confusing "+ob->query_cap_name()+"!",({player,ob}));
                    break;
                case "swashbuckler":
                    tell_object(player,"%^BOLD%^%^BLUE%^You quickly flash a length of silk in front of "+ob->query_cap_name()+"'s face, confusing "+ob->query_objective()+"!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^From out of nowhere a length of silk flies into your face, leaving you confused!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" quickly flash a length of silk in front of "+ob->query_cap_name()+"'s face, confusing "+ob->query_objective()+"!",({player,ob}));
                    break;
                case "thug":
                    tell_object(player,"%^BOLD%^%^BLUE%^You toss debris into "+ob->query_cap_name()+"'s eyes, leaving "+ob->query_objective()+" confused!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" tosses debris into your eyes, confusing you!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" tosses debris into "+ob->query_cap_name()+"'s eyes, leaving "+ob->query_objective()+" confused!  What a dirty trick!",({player,ob}));
                    break;
                case "soldier":
                    tell_object(player,"%^BOLD%^%^BLUE%^You feint to the right, then attack from the left, leaving "+ob->query_cap_name()+" confused!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" feints right, then you feel an attack from the right, leaving you confused!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" feints to the right, then attacks from the left, leaving "+ob->query_cap_name()+" confused!",({player,ob}));
                    break;
                case "dervish":
                    tell_object(player,"%^BOLD%^%^BLUE%^You spin quickly, ending up behind "+ob->query_cap_name()+", leaving "+ob->query_objective()+" confused!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" suddenly spins out of sight, leaving you confused!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" suddenly spins behind "+ob->query_cap_name()+", leaving "+ob->query_objective()+" looking confused!",({player,ob}));
                    break;
                default:
                    tell_object(player,"%^BOLD%^%^BLUE%^You dodge quickly to the side, and dash about your opponent, confusing "+ob->query_objective()+".%^RESET%^");
                    tell_object(ob,"%^BOLD%^%^BLUE%^Your opponent dashes around you in a blaze, you are momentarily confused!%^RESET%^");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" dashes around "+ob->query_cap_name()+" in a blaze! "+ob->query_cap_name()+" looks confused!%^RESET%^",({player,ob}));
                    break;
            }
            if(level > 20) ob->set_paralyzed(random(8)+4+bonus,"You are momentarily confused!");
            ob->set_paralyzed(random(4)+4+bonus,"You are momentarily confused!");
        }
        if(which == 2){
            switch(mystyle){
                case "peasant":
                    tell_object(player,"%^BOLD%^%^GREEN%^You clap both of "+ob->query_cap_name()+"'s temples, stunning "+ob->query_objective()+"!");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" claps your temples, leaving your ears ringing!");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" claps "+ob->query_cap_name()+"'s temples, leaving "+ob->query_objective()+" dazed!",({player,ob}));
                    break;
                case "swashbuckler":
                    tell_object(player,"%^BOLD%^%^GREEN%^You flip quickly through the air, striking "+ob->query_cap_name()+"'s chin as you pass!");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" flips through the air, somehow smacking your chin with "+player->query_possessive()+" weapon!");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" flips through the air, somehow smacking "+ob->query_cap_name()+"'s chin with "+player->query_possessive()+" weapon!",({player,ob}));
                    break;
                case "thug":
                    tell_object(player,"%^BOLD%^%^GREEN%^With a vicious kick, you buckle "+ob->query_cap_name()+"'s kneecap!");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" kicks you hard in the kneecap, sending you to the ground!");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" kicks "+ob->query_cap_name()+" hard in the kneecap, sending "+ob->query_objective()+" to the ground!",({player,ob}));
                    break;
                case "soldier":
                    tell_object(player,"%^BOLD%^%^GREEN%^In a fluid, disciplined move, you slam the butt of your weapon into "+ob->query_cap_name()+"'s sternum!");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" slams the butt of "+player->query_possessive()+" weapon into your sternum!");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" slams the butt of "+player->query_possessive()+" weapon into "+ob->query_cap_name()+"'s sternum!",({player,ob}));
                    break;
                case "dervish":
                    tell_object(player,"%^BOLD%^%^GREEN%^You circle "+ob->query_cap_name()+" and strike the base of "+ob->query_possessive()+" neck!");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" circles, and you suddenly feel a hard blow against the base of you neck!");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" circles "+ob->query_cap_name()+" and strikes the base of "+ob->query_possessive()+" neck!",({player,ob}));
                    break;
                default:
                    tell_object(player,"%^BOLD%^%^GREEN%^You smack your opponent on the head, dazing "+ob->query_objective()+".%^RESET%^");
                    tell_object(ob,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" strikes you stoutly, knocking you into a daze.%^RESET%^");
                    tell_room(room,"%^BOLD%^%^GREEN%^"+player->query_cap_name()+" strikes "+ob->query_cap_name()+" stoutly in the head!%^RESET%^",({player,ob}));
                    break;
            }
            ob->set_paralyzed(random(4)+6+bonus,"You are stunned from the blow!");
            if(level > 30) player->cause_damage_to(ob,ob->return_target_limb(),diff+random(16));
        }
        if(which == 3){
            switch(mystyle){
                case "peasant":
                    tell_object(player,"%^BOLD%^%^BLUE%^You plant your foot behind "+ob->query_cap_name()+"'s leg and push hard against "+ob->query_possessive()+" chest, sending "+ob->query_objective()+" sprawling on the ground!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" shoves hard against your chest, and you feel yourself trip over something, landing sprawled on the ground!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" plants "+player->query_possessive()+" foot behind "+ob->query_cap_name()+"'s leg and pushes hard against "+ob->query_possessive()+" chest, sending "+ob->query_objective()+" sprawling on the ground!",({player,ob}));
                    break;
                case "swashbuckler":
                    tell_object(player,"%^BOLD%^%^BLUE%^You flip high in the air, planting your feet on "+ob->query_cap_name()+"'s shoulders and knocking "+ob->query_objective()+" to the ground before flipping lightly to the ground again!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" suddenly flips in the air, landing on your shoulders and sending you to the ground hard!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" flips high in the air, planting "+player->query_possessive()+" feet on "+ob->query_cap_name()+"'s shoulders and knocking "+ob->query_objective()+" to the ground before flipping lightly to the ground again!",({player,ob}));
                    break;
                case "thug":
                    tell_object(player,"%^BOLD%^%^BLUE%^You elbow "+ob->query_cap_name()+" in the stomach, then bring your knee crashing into "+ob->query_possessive()+" nose when "+ob->query_subjective()+" doubles over!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" elbows you hard in stomach, sending you doubling over! Before you can react, "+player->query_subjective()+" smashes your nose with "+player->query_possessive()+" knee!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" elbows "+ob->query_cap_name()+" in the stomach, then brings "+player->query_possessive()+" knee crashing into "+ob->query_possessive()+" nose when "+ob->query_subjective()+" doubles over!",({player,ob}));
                    break;
                case "soldier":
                    tell_object(player,"%^BOLD%^%^BLUE%^You lunge forward, sweeping "+ob->query_cap_name()+"'s foot with your weapon!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^You feel something sweep your foot, then find yourself flat on your back, looking up at "+player->query_cap_name()+"!");
                    tell_room(room,"%^BOLD%^%^BLUE%^With a fluid, practiced motion, "+player->query_cap_name()+" lunges forward and sweeps "+ob->query_cap_name()+"'s feet out from under "+ob->query_objective()+"!",({player,ob}));
                    break;
                case "dervish":
                    tell_object(player,"%^BOLD%^%^BLUE%^You leap into the air, spinning and kicking "+ob->query_cap_name()+"'s head with the back of your heel, sending "+ob->query_objective()+" to the ground!");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" leaps into the air, spinning and kicking your head with the back of "+player->query_possessive()+" heel, sending "+ob->query_objective()+" to the ground in pain!");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" leaps into the air, spinning and kicking "+ob->query_cap_name()+"'s head with the back of "+player->query_possessive()+" heel, sending "+ob->query_objective()+" to the ground!",({player,ob}));
                    break;
                default:
                    tell_object(player,"%^BOLD%^%^BLUE%^You launch yourself at your opponent and tackle "+ob->query_objective()+" to the ground!%^RESET%^");
                    tell_object(ob,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" tackles you to the ground, knocking the wind out of you!%^RESET%^");
                    tell_room(room,"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" tackles "+ob->query_cap_name()+" to the ground, knocking the wind out of "+ob->query_objective()+"!%^RESET%^",({player,ob}));
                    break;
            }
            ob->set_tripped(1,"You are trying to catch your breath and stand!");
            player->cause_damage_to(ob,ob->return_target_limb(),diff+random(16));
        }
        if(which == 4){
            switch(mystyle){
                case "peasant":
                    tell_object(player,"%^YELLOW%^You place a swift punch beneath "+ob->query_cap_name()+"'s chin as you strike "+ob->query_objective()+" with your weapon as well!");
                    tell_object(ob,"%^YELLOW%^You feel a quick punch beneath your chin as "+player->query_cap_name()+"'s weapon strikes you as well!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" punches "+ob->query_cap_name()+"'s chin swiftly as "+player->query_subjective()+" strikes "+ob->query_objective()+" with "+player->query_possessive()+" weapon as well!",({player,ob}));
                    break;
                case "swashbuckler":
                    tell_object(player,"%^YELLOW%^You duck and roll along the ground, bringing your weapon up between "+ob->query_cap_name()+"'s legs!");
                    tell_object(ob,"%^YELLOW%^"+player->query_cap_name()+" suddenly ducks and rolls along the ground as you feel a sharp pain between your knees!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" ducks and rolls along the ground, bringing "+player->query_possessive()+" weapon up between "+ob->query_cap_name()+"'s legs!  OUCH!",({player,ob}));
                    break;
                case "thug":
                    tell_object(player,"%^YELLOW%^With a smirk, you headbutt "+ob->query_cap_name()+" furiously!");
                    tell_object(ob,"%^YELLOW%^With a smirk, "+player->query_cap_name()+" headbutts you furiously!");
                    tell_room(room,"%^YELLOW%^With a smirk, "+player->query_cap_name()+" headbutts "+ob->query_cap_name()+" furiously!",({player,ob}));
                    break;
                case "soldier":
                    tell_object(player,"%^YELLOW%^With a quick sprint, you dash weapon first into "+ob->query_cap_name()+"!");
                    tell_object(ob,"%^YELLOW%^With a quick sprint, "+player->query_cap_name()+" dashes weapon first into you!");
                    tell_room(room,"%^YELLOW%^With a quick sprint, "+player->query_cap_name()+" dashes weapon first into "+ob->query_cap_name()+"!",({player,ob}));
                    break;
                case "dervish":
                    tell_object(player,"%^YELLOW%^You strike "+ob->query_cap_name()+", then whirl suddenly, striking "+ob->query_objective()+" again!");
                    tell_object(ob,"%^YELLOW%^"+player->query_cap_name()+" strikes you, then whirls suddenly, striking you again!");
                    tell_room(room,"%^YELLOW%^"+player->query_cap_name()+" strikes "+ob->query_cap_name()+", then whirls suddenly, striking "+ob->query_objective()+" again!",({player,ob}));
                    break;
                default:
                    tell_object(player,"%^BOLD%^%^YELLOW%^You jump into the air, twist your body into a flip, and land feet first into your opponent's chest!%^RESET%^");
                    tell_object(ob,"%^BOLD%^%^YELLOW%^"+player->query_cap_name()+" leaps into the air and lands a flying kick deep into your chest.%^RESET%^");
                    tell_room(room,"%^BOLD%^%^YELLOW%^"+player->query_cap_name()+" leaps into the air and lands a flying kick deep into "+ob->query_cap_name()+"'s chest.%^RESET%^",({player,ob}));
                    break;
            }
            player->cause_damage_to(ob,ob->return_target_limb(),diff+random(24));
            ob->set_paralyzed(random(6)+6+bonus,"You are stunned from the blow!");
        }
        player->set_disable(3,ob);  // was 5, changing to use stamina if try too soon above *Styx*
    }
    else tell_object(player, "You don't see an opening, and circle about as you look for an angle.");
    
    return 1;
}

void help(){
    write("
%^RESET%^%^CYAN%^NAME%^RESET%^

flash - surprise a random opponent with a combat trick

%^CYAN%^SYNOPSIS%^RESET%^

flash

%^CYAN%^DESCRIPTION%^RESET%^

This will randomly perform one of a number of combat tricks against a random opponent. The first trick learned at level 1 is a simple attack, though you will gain others that cause trips and paralyzation at fighter levels 5, 15, 25, and 35. Using this is a free action, but using it too rapidly will result in extra stamina loss and failure.

Your combat style will affect the flavor of these combat tricks, but all styles have the same mechanical results.

%^CYAN%^SEE ALSO%^RESET%^

styles

Syntax: <flash>
    ");
}

