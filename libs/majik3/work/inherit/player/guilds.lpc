/* Guild-information inheritable for player objects
 * By: dranil
 */

mapping guilds;
mapping guild_titles;

int initialize_guilds()
{
    guilds=([]);
    return 1;
}

int initialize_guild_titles()
{
    guild_titles = ([]);
    return 1;
}

mapping query_guilds()
{
    return guilds;
}

mapping query_guild_titles()
{
    return guild_titles;
}

int query_guild_level(string name)
{
    if(!guilds)
        initialize_guilds();
    if(member_array(name, keys(guilds)) >= 0)
    {
        return guilds[name];
    }
    return 0;
}

int query_guild_title(string name)
{
    if (!guild_titles)
        initialize_guild_titles();
    if(member_array(name, keys(guild_titles)) >=0)
    {
        return guild_titles[name];
    }
    return 0;
}

int add_guild(string name)
{
    if(!guilds)
        initialize_guilds();
    if(!guild_titles)
        initialize_guild_titles();

    if(member_array(name, keys(guilds)) >= 0)
        return 0;

    guild_titles[name]="";
    return guilds[name]=1;
}

int set_guild_level(string name, int level)
{
    if (!guilds)
        initialize_guilds();

    if(member_array(name,keys(guilds))==-1)
        return 0;

    return guilds[name]=level;
}

string set_guild_title(string name, string title)
{
    if (!guild_titles)
        initialize_guild_titles();

    if(member_array(name,keys(guild_titles))==-1)
        return 0;

    return guild_titles[name]=title;
}

int remove_guild(string name)
{
    if(member_array(name, keys(guilds)) >= 0)
    {
        map_delete(guild_titles, name);
        return map_delete(guilds,name);
    }
    return 0;
}



