 /* mudlist.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 mudlist service

 Last updated: August 21st, 2006 by Tricky @ LPUniversity

 */

#ifdef CHECK_NEW_LPUNI_MUD
void addLPUniMud(string mudname, mixed *mudinfo)
{

    if(strsrch(mudinfo[5], lib_name()) != -1)
    {
        I3LOG("Notice [I3]: Found a " + lib_name() + " mud.\n");

        if(member_array(mudname, newLPUniMuds) == -1)
        {
            I3LOG("Notice [I3]: It is a new one!\n");

            if(!sizeof(newLPUniMuds)) newLPUniMuds = ({ mudname });
            else newLPUniMuds += ({ mudname });

            if(!checkNewLPUniMuds) checkNewLPUniMuds = ([ mudname: ({ ({ }), 0 }) ]);
            else checkNewLPUniMuds += ([ mudname: ({ ({ }), 0 }) ]);

            save_object(I3_DATA_FILE);
        }

    }

}
#endif

void rec_mudlist(mixed *packet)
{

    if(sizeof(packet) != 8)
    {
        I3LOG("Error [I3]: We don't like mudlist packet size. Should be 8 but is " + sizeof(packet) + "\n");

        return;
    }

    if(packet[6] == data["mudlist_id"])
        I3LOG("Warning [I3]: We don't like packet element 6 (" + packet[6] + "). It is the same as the current one. Continuing anyway.\n");

    if(packet[2] != data["router_list"][0][0])
    {
        I3LOG("Error [I3]: We don't like packet element 2 (" + packet[2] + "). It should be " + data["router_list"][0][0] + "\n");

        return;
    }

    data["mudlist_id"] = packet[6];

    foreach(mixed key, mixed val in packet[7])
    {

        if(!val && sizeof(keys(data["mudlist"])) && sizeof(data["mudlist"][key]))
        {
            I3LOG("Notice [I3]: Deleting mud '" + key + "' from the mudlist.\n");
            map_delete(data["mudlist"], key);
        }
        else
        if(val)
        {

            if(sizeof(keys(data["mudlist"])))
            {

                if(sizeof(data["mudlist"][key]))
                    I3LOG("Notice [I3]: Updating data for mud '" + key + "' in the mudlist.\n");
                else
                {
                    I3LOG("Notice [I3]: Adding mud '" + key + "' to the mudlist.\n");
#ifdef CHECK_NEW_LPUNI_MUD
                    addLPUniMud(key, val);
#endif
                }

                data["mudlist"] += ([ key: val ]);
            }
            else
            {
                I3LOG("Notice [I3]: Adding mud '" + key + "' to the mudlist.\n");
#ifdef CHECK_NEW_LPUNI_MUD
                addLPUniMud(key, val);
#endif
                data["mudlist"] = ([ key: val ]);
            }

        }

    }

    save_object(I3_DATA_FILE);
}
