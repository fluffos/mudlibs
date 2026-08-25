int *lookup_weapon_data(string name) 
{
    int i;
    int *weapon_data;

    /* The weapon_data array:
     *  1: cost in Gold's, negative value means silver.
     *  2: cost in Gold's, for a +1 enchanted item.
     *  3: Weight.
     *  4: Attack type, 1  for sharp, 2 for blunt and 3 for piercing.
     *  5: the amount of rolls...
     *  6: the dice value.
     *  7: The roll addup (damage modifier)
     *  8: The stuff the weapon is made of. Material. (forgot the darn word..)
	    1, wood 2, metal and 3 leather.
     *  A weapon will default as twohanded if it does a max damage of more than 8
     *  You have to add set_twohanded(1); to the weapon code if it shall become
     *  a twohanded sword.
    */

    switch(name) 
    {
    case "arrow":
	weapon_data=({ 4, 400, 10, 3, 1, 3, 0, 1 }); break;

    case "awl pike":
	weapon_data=({ 5, 500, 120, 1, 1, 6, 3, 1 }); break;

    case "bastard sword":
	weapon_data=({25, 2500, 100, 1, 2, 4, 0, 2 }); break;

    case "battle axe":
	weapon_data=({ 5, 500, 70,   1, 1, 8, 0 , 1 }); break;
	/* wooden shaft on a battle axe.. */

    case "bow":
	weapon_data=({ 10, 1000, 50, 2, 1, 1, 0, 1 }); break;

    case "broad sword":
	weapon_data=({25, 2500, 100, 1, 2, 4, 0, 2 }); break;

    case "club":
	weapon_data=({ 3, 300, 30,   2, 1, 6, 0, 1 }); break;

    case "dagger":
	weapon_data=({ 2, 200, 10,   3, 1, 4, 0, 2 }); break;

    case "dart":
	weapon_data=({ -5, 50, 5,    3, 1, 3, 0 ,2 }); break;

    case "dirk":
	weapon_data=({ 2, 200, 10,   3, 1, 4, 0 , 2 }); break;

    case "fauchard":
	weapon_data=({ 5, 500, 700,  1, 1, 6, 0 , 1 }); break;

    case "flail":
	weapon_data=({15, 1500, 150, 2, 1, 6, 2, 1 }); break;

    case "glaive":
	weapon_data=({ 6, 600, 800,  1, 1, 8, 1 , 1 }); break;

    case "halberd": 
	weapon_data=({10, 1000, 150, 2, 1, 5, 0 , 1 }); break;

    case "hand axe":
	weapon_data=({ 1, 100, 50,   1, 1, 3, 0 , 1 }); break;

    case "javelin":
	weapon_data=({ 1, 100, 20,   3, 1, 3, 0 , 1 }); break;

    case "knife":
	weapon_data=({ -5, 50, 10,   1, 1, 3, 0 , 2 }); break;

    case "long sword":
	weapon_data=({ 15, 1500, 40, 1, 1, 8, 0, 2 }); break;

    case "mace":
	weapon_data=({ 8, 800, 100,  2, 1, 6, 1 , 1 }); break;

    case "morning star": 
	weapon_data=({10, 1000, 120, 2, 2, 4, 1 , 1 }); break;

    case "pick":
	weapon_data=({ 8, 800, 60, 3, 1, 6, 0 , 2 }); break;

    case "pitchfork":
	weapon_data=({ 5, 500, 70, 3, 1, 6, 0 , 1 }); break;

    case "polearm":
	weapon_data=({ 8, 800, 100,  1, 2, 4, 1, 1 }); break;

    case "quarterstaff":
	weapon_data=({ 5, 500, 40,   2, 1, 6, 0 , 1 }); break;

    case "scimitar":
	weapon_data=({ 15, 1500, 40, 1, 1, 8, 0 , 2 }); break;

    case "short sword":
	weapon_data=({ 10, 1000, 30, 3, 1, 6, 0 , 2 }); break;

    case "sickle":
	weapon_data=({ 1, 100, 30,   1, 1, 3, 1 , 2 }); break;

    case "spear":
	weapon_data=({ 3, 300, 60,   3, 1, 5, 0 , 1 }); break;

    case "trident":
	weapon_data=({ 15, 1500, 50, 3, 1, 6, 1 , 1 }); break;

    case "twohanded sword":
	weapon_data=({50, 5000, 150, 1, 2, 8, 2 , 2 }); break;

    case "twohanded axe":
	weapon_data=({50, 5000, 180, 1, 2, 8, 2, 2}); break;

	// Shaper, new damage.  July 1996
    case "war hammer":
	weapon_data=({ 2, 200, 60,   2, 1, 4, 2 , 2 }); break;

    case "whip":
	weapon_data=({ -3, 30, 20,   2, 1, 2, 0 , 3 }); break;

    case "twohanded_mace":
	weapon_data=({ 12, 1300, 100,  2, 1, 11, 1 , 1 }); break;

    case "twohanded_staff":
	weapon_data=({ 8, 800, 100,   2, 1, 12, 0 , 1 }); break;

    default: break;
    }
    return weapon_data;
}
