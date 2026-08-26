/**
 * Channels "borrowed" from the Nightmare mudlib by Sibbis 12/10/1994
 * Converted to Divided Sky - Shaydz
 */

private nosave string *channels;

/**
 * This method returns the channels this player has.
 * @return an array of channel names the player has
 */
string *query_channels() { return channels; }

private void register_channels() {
    string *orgs;

    channels = ({"chat", "singing", "newbie"});

    if( adminp(TO) )
        orgs = ORGS_H->query_orgs();
    else
        orgs = ORGS_H->query_my_orgs( TO->query_name() );

    if( sizeof(orgs) )
        foreach( string org in orgs )
            channels += ({ ORGS_H->query_channel(org) });

    if( creatorp(TO) ) {
        string name;

        channels += ({"cre", "intercre", "intergossip", "nipples",
                      "killers", "nscre", "nschat", "skylib"});

        if( lordp(TO) )
            channels += ({"lord"});

        if( seniorp(TO) )
            channels += ({"senior"});

        // 0 name for admin, as to get all domains/projects.
        if( !adminp(TO) )
            name = TO->query_name();

        channels += DOMAIN_H->query_domains(name) - ({"playtesters"});

        if( !DOMAIN_H->query_member("learning", TO->query_name() ) ||
            sizeof( DOMAIN_H->query_domains( TO->query_name() ) ) > 1 ) {
            channels += ({"playtesters"});
        }

    } else {
        if( playtesterp(TO) )
            channels += ({"playtesters"});
        if( TO->query_property("player_killer") )
            channels += ({"killers"});

    }

    CHANNEL_H->add_user(channels);

} /* register_channels() */

/** @ignore yes */
void channel_commands() {
    if( interactive(TO) )
        register_channels();
} /* channel_commands() */
