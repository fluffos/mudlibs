// This function returns a string containing the formatted output
// of someones inventory. Neatly split up into wielded objects,
// held objects, worn objects and carried objects. And money.
// 'Someone' includes players, npc and corpses.
//
// A few extra lines here and we can have info like:
//   - Which hand something is held/wielded in.
//   - If the object is 1 handed, 2 handed, etc etc
//
//
// 'self' is true if someone is looking at himself. (Basically
// changes a few minor things like:
//    - 'You' instead of 'Playername'
//    - Show exact amount of money instead of the usual messages
//     like 'His purse is fit to burst!'
//

// Tyrael - May'02 - Anyadido codigo para localizacion y redefinidos
// los tipos y nombres de tipos de armaduras en /table/armour_table.c

#define ARMOUR_TABLE "/table/armour_table"

string query_living_contents(int self)
{
    string s, ret, *strs;
    object *wpn, *worn, *carry, *conts, money, *held, *tmp_conts;
    int coins, i, col, j;

    s = "";
    strs = conts = tmp_conts = ({ });

    // Get all objects in inventory and filter out the hidden 
    // ones, i.e. the ones without a short() or short() == ""
    tmp_conts = all_inventory(this_object());
    for(i=0; i<sizeof(tmp_conts); i++)
	if((ret = (string)tmp_conts[i]->short()) && (ret != ""))
	    conts += ({ tmp_conts[i] });

	// Get held and worn objects, also get money.
	// These are later subtracted from the 'full inventory' array
	// resulting in all carried objects.
    held = (object *)this_object()->query_held_ob();
    worn = (object *)this_object()->query_worn_ob();
    money = present("Some Money For Me", this_object());

    // This is a bit messy innit? -A
    if (!pointerp(worn))
	worn = ({ });
    else
	worn -= ({ 0 });

    // This is a bit messy as well, but we can't trust our input.
    if (!pointerp(held))
	held = ({ });
    else
	held -= ({ 0 });

    // The quick and dirty way... -A 
    // Get wielded objects and subtract them from the 'held object' array
    wpn = (object *)this_object()->query_weapons_wielded();
    if (!wpn) wpn = ({ });
    held -= wpn;

    if (sizeof(wpn))
	if(ret = query_multiple_short(wpn))
	    strs += ({ "Empunyando : ", capitalize(ret) + ".\n"});

    if (sizeof(held))
	if(ret = query_multiple_short(held))
	    strs += ({ "Llevando   : ", capitalize(ret) + ".\n"});

    if((j = sizeof(worn))) {
	int x, y, tt, pt = -1;
	string tmp1, tmp2;
	object *obs = ({ });

  	worn = sort_array(worn,"sort");
	strs += ({"Vistiendo  :\n"});
	// por alguna razon ha fallado el q_m_s() sobre 1 solo objeto
	for (x = 0; x < j; x++) {
		if ((tt = worn[x]->query_armour_type()) == pt) {
			obs += ({ worn[x] });
			if (x + 1 < j)
				continue;
			if (sizeof(obs) > 1)
				tmp2 = CAP(query_multiple_short(obs));
			else
				tmp2 = CAP(obs[0]->query_short());
			strs += ({ tmp1 + tmp2 + ".\n"});
			break;
		}
		if ((y = sizeof(obs))) {
			if (y > 1)
				tmp2 = CAP(query_multiple_short(obs));
			else
				tmp2 = CAP(obs[0]->query_short());
			strs += ({ tmp1 + tmp2 + ".\n" });
		}
		pt = tt;
		tmp1 = sprintf(" * %7s : ",ARMOUR_TABLE->query_type_name(tt));
		if (x + 1 == j) {
			strs += ({ tmp1 + CAP(worn[x]->query_short()) + ".\n" });
			break;
		}
		obs = ({ });
		obs += ({ worn[x] });
	}
    }
/*
	if(ret = query_multiple_short(worn))
	    strs += ({ "Vistiendo  : ", capitalize(ret)  + ".\n" });
*/

	// Could be done higher up (before the weapon array gets set) to 
	// save an array subtraction.
    carry = conts - worn - ({ money }) - held - wpn; 

    if(sizeof(carry)) {
	/*if(ret = (string)this_object()->query_contents(0, carry))
	    strs  += ({ "Cargando   : ", ret });*/
	ret = CAP(query_multiple_short(carry));
	strs += ({ "Cargando   : "+ret+".\n" });
    }

    if(this_player())
	col = (int)this_player()->query_cols()-11;
    else col = 78;
/*    for(i=0; i<sizeof(strs); i+=2) {
	s += sprintf("%s%-=*s", strs[i], col, strs[i+1]);
    }*/
	for (i=0; i<sizeof(strs); i++)
		s += sprintf("%s", strs[i]);

    // Display the money at the end, output depends on who's looking.
    if(self) {
	if(money) ret = (string)money->short(0);
	else ret = 0;
	if(!sizeof(strs)) s = "Estas con las manos vacias.\n";
	s += "Tu bolsillo contiene " + (ret?ret:"solo telaranyas") + ".\n";
    } else if(money) {
	coins = (int)money->query_number_coins();    
	s += capitalize((string)this_object()->query_possessive()) + " bolsillo ";
	switch(coins) {
	case 0..10:    s += "esta lleno de telaranyas!\n"; break;
	case 11..100:  s += "tiene algunas monedas.\n"; break;
	case 101..300: s += "esta repleto de monedas.\n"; break;
	default:       s += "esta a punto de rebentar!\n";
	}
    }
    return s;
}

int sort(object s1, object s2)
{
  if (s1->query_armour_type()>s2->query_armour_type()) return 1;
  if (s1->query_armour_type()<s2->query_armour_type()) return -1;
  return 0;
}