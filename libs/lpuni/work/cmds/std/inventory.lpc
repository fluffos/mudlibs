/* inventory.c

 Tacitus @ LPUniversity
 28-OCT-05
 Standard command

*/

int main(string args)
{
    object *inventory;
    int i;

    inventory = all_inventory(this_player());
    if(sizeof(inventory) < 1) return(notify_fail("You are not currently carrying anything.\n"));
    write("You are carrying the following " + (sizeof(inventory) == 1 ? "item:\n" : sizeof(inventory) + " items:\n"));
    for(i = 0; i < sizeof(inventory); i ++)
    printf(" %s\n", inventory[i]->query_short());
    return 1;
}

string help()
{
    return(HIW + " SYNTAX: " + NOR + "inventory\n\n"
      "This command displays a list of everything that is currently\n"
      "in your inventory.\n");
}
