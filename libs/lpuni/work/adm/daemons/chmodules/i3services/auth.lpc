 /* auth.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 auth service

 */

void send_auth_mud_req(string t_mudname)
{
    send_packet( ({
      "auth-mud-req",
      5,
      mud_name(),
      0,
      t_mudname,
      0
    }) );
}

void rec_auth_mud_req(mixed *packet)
{
    string orig = packet[O_MUD];
    string *session_names = keys(data["session_keys_by_name"]);
    int *session_keys = keys(data["session_keys_by_session"]);
    int session_key;

    //I3LOG("Notice [I3]: " + sprintf("%O", packet) + "\n");

    /* Simple hash */
    session_key = 0;
    for(int i = 0; i < strlen(orig); i++) session_key += (orig[i] + ((i / 2) + 1));
    session_key = (session_key * 1000) + random(720217) + (time() ^ 0x55AA55AA);

    while(member_array(session_key, session_keys) != -1)
        session_key--;

    if(member_array(orig, session_names) != -1)
        map_delete(data["session_keys_by_session"], data["session_keys_by_name"][orig]["session_key"]);

    I3LOG("Notice [I3]: Registering '" + orig + "' with session key: " + session_key + "\n");

    if(!data["session_keys_by_name"]) data["session_keys_by_name"] = ([ ]);

    data["session_keys_by_name"][orig] = ([
      "registered": time(),
      "session_key": session_key,
    ]);

    if(!data["session_keys_by_session"]) data["session_keys_by_session"] = ([ ]);

    data["session_keys_by_session"][session_key] = orig;

    save_object(I3_DATA_FILE);

    send_packet( ({
      "auth-mud-reply",
      5,
      mud_name(),
      0,
      orig,
      0,
      session_key
    }) );
}

void rec_auth_mud_reply(mixed *packet)
{
    I3LOG("Notice [I3]: '"+ packet[O_MUD] +"' registered your mud with the session_key: " + packet[6] + "\n");
}
