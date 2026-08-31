string parse_weight( int wgt ) {
    string str;

    switch( wgt ) {
    case 0:  str = "It's weightless.";                   break;
    case 1:  str = "It weighs almost nothing.";          break;
    case 2:  str = "It's a rather light object.";        break;
    case 3:  str = "It has a good weight.";              break;
    case 4:  str = "You could call it heavy.";           break;
    case 5:  str = "It certainly is heavy.";             break;
    case 6:  str = "You could call it very heavy.";      break;
    case 7:  str = "It feels very heavy.";               break;
    case 8:  str = "It is very heavy.";                  break;
    case 9:  str = "It is VERY heavy.";                  break;
    case 10: str = "You sigh under the weight of it.";   break;
    case 11: str = "It feels extremely heavy.";          break;
    case 12: str = "It is extremely heavy.";             break;
    case 13: str = "It is EXTREMELY heavy.";             break;
    case 14: str = "Your back strains from the weight."; break;
    case 15: str = "Your back howls in pain!";           break;
    }
    if( wgt > 15 ) 
       str="Your back is ready to break from the weight!";
    if( wgt < 0 ) 
       str="It seems to float away from your hand.";
    return ( str );
}

string parse_armour( object obj ) {
    string str;
    int ac;

    str = "This is an Armour:\n";
    if( obj->query_read() ) 
       str += "You can read: " + obj->query_read() + "\n";
    str += "It has a size of: " + obj->query_size_name( obj->query_size() ) + ".\n";
    str += "It's type is: " + obj->query_type() + ".\n";
    if( obj->query_arm_light() > 0 )
       str += "It sparkles with an inner light!\n";
    if( obj->query_arm_light() < 0 ) 
       str += "It seems to absorb light!\n";
    if( obj->query_unwearable() )  
       str += "It is made for advanced beings!\n";
    ac = obj->armour_class();
    switch( ac ) {
    case 0:  str += "It doesn't protect you.";        break;
    case 1:  str += "It gives a little protection.";  break;
    case 2:  str += "It gives fair protection.";      break;
    case 3:  str += "It gives average protection.";   break;
    case 4:  str += "It gives normal protection.";    break;
    case 5:  str += "It gives good protection.";      break;
    case 6:  str += "It gives very good protection."; break;
    case 7:  str += "It gives excellent protection."; break;
    case 8:  str += "It gives amazing protection.";   break;
    case 9:  str += "It gives awesome protection.";   break;
    case 10: str += "It gives monstrous protection."; break;
    } 
    if( ac > 10 ) 
       str += "It gives illegal protection!";
    if( ac < 0 ) 
       str += "It weakens your defense!";
    return ( str );
}

string parse_container( object obj ) {
    string str;
    int wgt;

    str = "You can put things in it:\n";
    if( obj->query_of_glass() ) 
       str += "You can see through it.\n";
    if( obj->query_only_for() ) 
       str += "It will only hold " + obj->query_only_for() + ".\n";
    wgt = obj->query_max_weight();
    switch( wgt ) {
    case 0:  str += "You can barely fit an item in it.";           break;
    case 1:  str += "It can't contain more than one thing.";       break;
    case 2:  str += "You can put a light item in it.";             break;
    case 3:  str += "You can put a normal item in it.";            break;
    case 4:  str += "It may be able to contain a few items.";      break;
    case 5:  str += "It should be able to contain a few items.";   break;
    case 6:  str += "It may be able to contain some things.";      break;
    case 7:  str += "It should be able to contain some things.";   break;
    case 8:  str += "It can probably hold more than some things."; break;
    case 9:  str += "It can probably hold more than some items.";  break;
    case 10: str += "It may be able to contain many items.";       break;
    case 11: str += "It should be able to contain many items.";    break;
    case 12: str += "It can be filled with possibly many items.";  break;
    case 13: str += "It should be able to contain many items.";    break;
    case 14: str += "It should be able to hold enough items.";     break;
    case 15: str += "It can contain enough items.";                break;
    }
    if( wgt > 15 ) 
       str += "It can probably contain more than you can carry.";
    if( wgt < 0 ) 
       str += "It seems to devour items.";
    return ( str );
}

string parse_weapon( object obj ) {
    string str;
    int wc;

    str = "This is a weapon:\n";
    if( obj->query_two_handed() ) 
       str += "This weapon requires two hands.\n";
    wc = obj->weapon_class();
    switch( wc ) {
    case 0:  str += "Couldn't cut bread dough.";               break;
    case 1:  str += "Probably too dull to hurt a fly.";        break;
    case 2:  str += "Yes, it could hurt a fly.";               break;
    case 3:  str += "Maybe as strong as your bare hands.";     break;
    case 4:  str += "Dull as a butter knife.";                 break;
    case 5:  str += "Equal to a knife.";                       break;
    case 6:  str += "Pierces as easily as a dagger.";          break;
    case 7:  str += "Useful as a vagrant's dirk.";             break;
    case 8:  str += "Has the edge of a woodsman's hand axe.";  break;
    case 9:  str += "Quick as an assassin's short sword.";     break;
    case 10: str += "Worthy to be a norseman's warhammer.";    break;
    case 11: str += "Clean as an amazon's hunting spear.";     break;
    case 12: str += "Hefty as a cavalryman's broadsword.";     break;
    case 13: str += "Trusty as a knight's longsword.";         break;
    case 14: str += "Sharp as a dwarven battle axe.";          break;
    case 15: str += "Proud as a highlander's claymore.";       break;
    case 16: str += "Easy replacement for a flamberge.";       break;
    case 17: str += "Strong as a great two-hander.";           break;
    case 18: str += "Damaging as the sharpest halberd.";       break;
    case 19: str += "Powerful enough for a wizard.";           break;
    case 20: str += "A weapon truly worthy of the Gods!";      break;
    }
    if( wc > 20 ) 
       str += "This weapon is illegal!";
    if( wc < 0 ) 
       str += "This weapon seems to be harmless!";
    return ( str );
}

string parse_drink( object obj ) {
    string str;
    int strength;

    if( obj->query_alco_drink() ) {
	str = "This is an alcoholic beverage:\n";
	if( obj->query_food() ) 
           str += "It is a tad chewy.\n";
	strength = obj->query_heal_amount();
	switch( strength ) {
	case 0..10:  str += "This is a mild alcohol.";                break;
	case 11..20: str += "It has a bit of a kick.";                break;
	case 21..30: str += "This is a strong alcohol.";              break;
	case 31..40: str += "This has a killer kick.";                break;
	case 41..50: str += "This is like being kicked by a mule!";   break;
	case 51..60: str += "It will hit you like a ton of bricks!";  break;
	}
	if( strength > 60 ) 
            str += "This has a deadly kick!";
	if( strength < 0 ) 
            str += "This is a girly drink!";
    }
    else {
	str = "This is a soft drink:\n";
	if( obj->query_poison() ) 
           str += "Consumption may be hazardous!\n";
	strength = obj->query_strength();
	switch( strength ) {
	case 0..10:  str += "This is like water.";           break;
	case 11..20: str += "This is like a fruit juice.";   break;
	case 21..30: str += "This is like a coffee or tea."; break;
	case 31..40: str += "This is as thick as milk.";     break;
	case 41..50: str += "This is like a syrup.";         break;
	case 51..60: str += "This is like drinking blood!";  break;
	}
	if( strength > 60 ) 
           str += "A triple espresso with a double cappuchino!";
	if( strength < 0 ) 
           str += "This is like drinking air!";
    }
    return ( str );
}

string parse_food( object obj ) {
    string str;
    int strength;

    str = "This is a type of food:\n";
    if( obj->query_poison() ) 
       str += "Consumption may be hazardous!\n";
    strength = obj->query_heal_amount();
    switch( strength ) {
    case 0..10:  str += "It is very light and fat-free.";       break;
    case 11..20: str += "It has some body.";                    break;
    case 21..30: str += "It is full of vitamins.";              break;
    case 31..40: str += "It is full of vitamins and minerals."; break;
    case 41..50: str += "Very high carbohydrates.";             break;
    case 51..60: str += "Very high fat content.";               break;
    }
    if( strength > 60 ) 
       str += "This is coronary causing food!";
    if( strength < 0 ) 
       str += "It is like chewing on air!";
    return ( str );
}
