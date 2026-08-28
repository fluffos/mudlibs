// Guilds-command by Dranil
/* Title-command by dranil */


main(string arg)
{
    string *guilds;
    string buf="";
    int index;
    if(sizeof(arg))
        sscanf(arg,"%d",index);

    if(!sizeof(THIS->query_guild_titles()))
    {
        write("You haven't joined in any guilds.\n");
        return 1;
    }

    guilds=sort_array(keys(THIS->query_guild_titles()),0);

    if (index > 0 && index <= sizeof(guilds))
    {
        set_title(index-1);
        return 1;
    }

    buf += "You have joined in following guilds:\n";

    for (int i=0; i < sizeof(guilds); i++)
    {
        buf += sprintf("%2d. %-30s ^c1%-20s^c0\n",i+1,  guilds[i], THIS->query_guild_title(guilds[i]) );
    }
    buf += "\nTo set your title, to one on the list, type:";
    buf += "\nguilds <listnumber>\n";
    write (buf);
    return 1;
}


int set_title(int index)
{
    string *guilds;

    guilds=sort_array(keys(THIS->query_guild_titles()),0);

    THIS->set("title",THIS->query_guild_title(guilds[index]) );

    write ("You are known as: " + THIS->short()+ "\n\n");

    return 1;
}

query_author ()
{
  return "dranil";
}

query_synopsis ()
{
  return "guilds [n]";
}

query_help ()
{
  return "This command displays you the guilds you are in. By specifying " 
       + "number as argument you can change your title, according to the "
       + "guild you want.";
}

query_see_also ()
{
  return "title(2)";
}

query_position ()
{
  return POS_RESTING;
}

