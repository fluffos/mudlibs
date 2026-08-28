/****
****    File                            /command/mortal/i.c
***     Description                     Displays items character is carrying
**      Coder                           Dazzt
*/

#define pline(x) message("0", x, THIS);

int main ()
{
	string *numbers = ({ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" });
    object *inv;
	string *names;
	mapping inventory;
    int i, szi, *w1;
    float w2;
    string buf;

    inv = all_inventory(THIS);
	inventory = ([ ]);
	
	/* count the items we have */
	
	for (i = 0, szi = sizeof(inv); i < szi; i++)
	{
		if (!inv[i]->query_is_worn()) /* exclude worn items */
		{
			if (!inventory[inv[i]->short()])
				inventory[inv[i]->short()] = 1;
			else
				inventory[inv[i]->short()] += 1;
		}
	}
	
	if (szi == 0)              /* if we don't have items */
	{
          pline ("You are not carrying anything.\n");
          return 1;
	}


        w1 = all_inventory(THIS)->query_weight();
        for (int j=0;j<sizeof(w1);j++)
        w2 += w1[j];

        w2 = w2 / 1024.0;

        pline ("You are carrying ^cc"+sprintf("%1.1f", w2)+"^c0 kg of equipment:\n");

	names = keys(inventory);
        buf = "";
	for (i = 0, szi = sizeof(names); i < szi; i++)
	{
		switch(inventory[names[i]])
		{
			case 1 : 
			  buf += capitalize(names[i]) + "\n";
			  break;
			case 2..10 : 
                          buf += numbers[inventory[names[i]]-1] + " " + pluralize(names[i]) + "\n";
 			  break;
			default : /* uncountable amount [ > 10 :) ] */
                          buf += "many " + pluralize(names[i]) + "\n"; 
			  break;
		}
	}

    pline (sprintf("%#-78s\n", buf));
			
    return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "Inventory command. Shows what you currently have in your " 
       + "inventory. Each player can only carry a certain amount of "
       + "Items based on their weight and players strength and "
       + "encumberance.";
}

query_see_also ()
{
  return "eq(1), health(1)";
}

query_position ()
{
  return POS_RESTING;
}

