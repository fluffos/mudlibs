//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef racesModule_h
#define racesModule_h

private string race;
private string apparentRace;

/////////////////////////////////////////////////////////////////////////////
protected nomask void loadRaces(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        race = persistence->extractSaveData("race", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping sendRaces()
{
    return ([
        "race": race
    ]);
}

#endif
