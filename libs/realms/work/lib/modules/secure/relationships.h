//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef relationshipsModule_h
#define relationshipsModule_h

private mapping relationships = ([]);
private mapping relationshipHistory = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipEntry(mapping relationship)
{
    mapping ret = relationship + ([]);

    if (member(ret, "dimensions") && mapp(ret["dimensions"]))
    {
        ret["dimensions"] = ret["dimensions"] + ([]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneHistoryEntry(mapping entry)
{
    mapping ret = entry + ([]);

    if (member(ret, "context") && mapp(ret["context"]))
    {
        ret["context"] = ret["context"] + ([]);
    }
    if (member(ret, "metadata") && mapp(ret["metadata"]))
    {
        ret["metadata"] = ret["metadata"] + ([]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipMap(mapping data)
{
    mapping ret = ([]);

    if (mapp(data))
    {
        foreach(string key in keys(data))
        {
            if (mapp(data[key]))
            {
                ret[key] = cloneRelationshipEntry(data[key]);
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipHistory(mapping data)
{
    mapping ret = ([]);

    if (mapp(data))
    {
        foreach(string key in keys(data))
        {
            ret[key] = ({ });

            if (pointerp(data[key]))
            {
                foreach(mapping historyEntry in data[key])
                {
                    ret[key] += ({ cloneHistoryEntry(historyEntry) });
                }
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void loadRelationships(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        mapping savedRelationships =
            persistence->extractSaveData("relationships", data);
        if (mapp(savedRelationships))
        {
            relationships = cloneRelationshipMap(savedRelationships);
        }

        mapping savedHistory =
            persistence->extractSaveData("relationshipHistory", data);
        if (mapp(savedHistory))
        {
            relationshipHistory = cloneRelationshipHistory(savedHistory);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping sendRelationships()
{
    return ([
        "relationships": cloneRelationshipMap(relationships),
        "relationshipHistory": cloneRelationshipHistory(relationshipHistory)
    ]);
}

#endif
