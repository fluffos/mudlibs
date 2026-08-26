/* edemote.c

 Parthenon @ LPUniversity
 26-JUN-2006
 LPUni emote editor command

*/

/* Last updated: July 16th, 2006 by Tacitus */



int main(string arg)
{
    object emote_client;
    int selection;
    string emote;

    if(!isMember(query_privs(previous_object()), "soul"))
    return(notify_fail("Error [soul]: Access denied.\n"));

    emote_client = clone_object(OBJ_SOUL_TOOL);
    emote_client->move(this_player());

    if(stringp(arg))
    {
    if(sscanf(arg, "%d %s", selection, emote) == 2)
    {
        switch(selection)
        {
        case 1:
        emote_client->get_emote_name(emote);
        return 1;
        case 2:
        emote_client->remove_emote(emote);
        return 1;
        }
    }

    else
    {
        emote_client->menu_selection(arg);
        return 1;
    }
    }

    else
    {
    emote_client->main_menu();
    return 1;
    }//END IF
}

string help()
{
    return(
      " SYNTAX: edemote\n\n"+
      "This command launches the soul emotes editor which will allow\n"+
      "you to create new emotes, delete existing emotes, see the\n"+
      "existing emotes and their syntax or remove all emotes from the\n"+
      "system. \n\nYou must be a member of the 'soul' group to use this command.\n");
}
