//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef conversationsModule_h
#define conversationsModule_h

private nosave string BaseConversation = "/lib/modules/conversations/baseConversation.lpc";
private nosave mapping topics = ([]);
private nosave object CurrentTopic = 0;

private mapping opinions = ([]);
private mapping spokenTopics = ([]);

/////////////////////////////////////////////////////////////////////////////
protected nomask void loadConversationData(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping sendConversation()
{
    return ([
    ]);
}

#endif
