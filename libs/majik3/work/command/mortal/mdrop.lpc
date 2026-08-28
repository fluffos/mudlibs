/****
*  *    Command                         drop
* *     Description                     Drops an item to ground
**      Coder                           Dazzt
*/


int main(string str)
{
    object *inv;
    int i;

    if (!str)
    {
	message("standard", "Drop what?\n", THIS);
	return 1;
    }

    inv = all_inventory(THIS);

    for (i = 0; i < sizeof(inv); i++)
    {
	if (inv[i]->query_name() == str)
	{
	    if (inv[i]->drop(environment(THIS))) return 1;
	    else inv[i]->move(environment(THIS));

	    message("standard", capitalize(THIS->query_name()) +
	      " drops " + inv[i]->short() + ".\n",
	      environment(THIS), THIS);
	    message("standard", "You drop " + inv[i]->short() + ".\n",
	      THIS);

	    return 1;
	}
    }

    message("standard", "You don't have any " + str + ".\n", THIS);
    return 1;
}

