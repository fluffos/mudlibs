//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef guildsModule_h
#define guildsModule_h

private mapping guilds = ([]);
private int unassignedExperience;

/////////////////////////////////////////////////////////////////////////////
protected nomask void loadGuilds(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        unassignedExperience = persistence->extractSaveData("unassignedExperience", data);

        guilds = persistence->extractSavedMapping("guilds", data);

        if (sizeof(guilds))
        {
            string *guildList = keys(guilds);
            foreach(string guild in guildList)
            {
                if (member(guilds[guild], "left guild") &&
                    !guilds[guild]["left guild"])
                {
                    map_delete(guilds[guild], "left guild");
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping sendGuilds()
{
    mapping ret = ([
        "guilds": ([]),
        "unassignedExperience": unassignedExperience
    ]);

    string *guildList = keys(guilds);
    foreach(string guild in guildList)
    {
        string *keys = keys(guilds[guild]);
        if (sizeof(keys))
        {
            ret["guilds"][guild] = ([]);

            foreach(string key in keys)
            {
                ret["guilds"][guild][key] = guilds[guild][key];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removeGuildData(string guild)
{
    load_object("/lib/modules/secure/dataAccess.lpc")->removeSavedGuild(
        this_object()->RealName(), guild);
}

#endif
