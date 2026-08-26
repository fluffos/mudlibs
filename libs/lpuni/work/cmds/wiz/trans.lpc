/*

 trans.c

 Parthenon@LPuniversity
 August 7th, 2006
 command to transport a user to your current location

 Last edited on August 7th, 2006 by Parthenon

*/

int main(string arg)
{
    object player;

    if(!arg || arg == "")
    return notify_fail("Syntax: trans <user>\n");

    if(!player = find_player(arg))
    return notify_fail(RED + "Error" + NOR + " [trans]: Cannot find that player\n");

    if(environment(player) == environment(this_player()))
    return notify_fail(RED + "Error" + NOR + " [trans]: You are already in the same room.\n");

    if(adminp(player) || devp(player) && !adminp(this_player()))
    {
    catch(tell_object(player, this_player()->query_cap_name()
        + " requests your presence in " +
        environment(this_player())->query_short() + ".\n"));

    return notify_fail(RED + "Error " + NOR +
      "[trans]: You can not transport them but your wish has been made known.\n");
    }

    if(!environment(this_player()))
    return notify_fail(RED + "Error" + NOR + " [trans]: You have no environment to transport a player to!\n");

    if(!player->move(environment(this_player())))
    return notify_fail(RED + "Error" + NOR + " [trans]: Could not move " + player->query_cap_name() + " to you.\n");

    tell_object(player, "You have been transported to " + this_player()->query_cap_name() + ".\n");
    tell_object(this_player(), "You have transport " + player->query_cap_name() + " to you.\n");

    return 1;
}

string help()
{
    return
    HIW + " SYNTAX: " + NOR + "trans <user>\n\n" +
    "This command allows you to move a user to your environment. You cannot\n" +
    "trans admins, and if you are a developer you cannot trans other developers\n";
}


