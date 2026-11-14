// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/connections.inc
// Description:
//
// $Log: connections.inc,v $
// Revision 1.17  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.16  2015/04/28 18:58:06  gnomi
// AUX_PORT in UNI erneut festlegen (falscher Wert von aussen)
//
// Revision 1.15  2013-03-16 15:55:31  gnomi
// RPC- und Portal-Port kann via Define AUX_PORT gesetzt werden.
//
// Revision 1.14  2012-12-09 21:20:04  gnomi
// Unterschiedliche Zertifikate fuer Telnet und Portal.
//
// Revision 1.13  2012-11-26 22:26:04  gnomi
// Unterstuetzung fuer InterMUD-Portale.
//
// Revision 1.12  2012-11-16 17:58:30  gnomi
// Auf IPv6 umgestellt.
//
// Revision 1.11  2009-04-15 13:42:31  gnomi
// TLS-Verbindungen ermoeglichen.
//
// Revision 1.10  2008/02/28 08:54:33  gnomi
// Anderer Port fuer RPC-Daemon.
//
// Revision 1.9  2008/02/25 20:47:34  gnomi
// RPC-Anbindung.
//
// Revision 1.8  2004/08/05 21:53:51  gnomi
// Keine Meldungen mehr nach /log/sys/ERQ.
// catch mit publish aufrufen.
// player_second Bescheid sagen.
//
// Revision 1.7  2002/01/12 21:23:46  gnomi
// Benachrichtung des QUEUED entfernt.
//
// Revision 1.6  2001/05/30 16:03:08  freaky
// Versionabhaengigkeiten rausgeworfen.
//
// Revision 1.5  2001/03/13 22:53:22  freaky
// einige Funktionen protected machen.
//
// Revision 1.4  2001/02/24 15:09:41  freaky
// receive_imp und send_imp nach *_udp umbenannt.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
/*
 * This function is called every time a player connects.
 * input_to() can't be called from here.
 */
protected object connect()
{
#ifndef TestMUD
#undef AUX_PORT
#endif
#ifndef AUX_PORT
#define AUX_PORT 33033
#endif
#if __EFUN_DEFINED__(query_mud_port)
    int port = efun::query_mud_port();
#else
    int port = efun::interactive_info(this_player(), II_MUD_PORT);
#endif
    if(port == AUX_PORT)
    {
#if __EFUN_DEFINED__(query_ip_number)
        string ip = efun::query_ip_number();
#else
        string ip = efun::interactive_info(this_player(), II_IP_NUMBER);
#endif
        if(member(({"127.0.0.1", "::1", "::ffff:127.0.0.1"}), ip) >= 0)
            return clone_object(RPC_CONNECTION);

#ifdef __TLS__ 
        // Ohne TLS keine Portale
        if(tls_available())
        {
            int err;

#ifdef PORTAL_CERT
            configure_driver(DC_TLS_CERTIFICATE, PORTAL_CERT);
#endif

            err = tls_init_connection();
            if(err < 0)
            {
                debug_message(tls_error(err));
                return 0;
            }
            
            return clone_object(PORTAL_CONNECTION);
        }
#endif
    }
#ifdef __TLS__ 
#ifdef Orbit
    if(port == 9988 || port == 9987)
#else
    if(port == 992 || port == 3332)
#endif
    {
	int err;
	
	if(!tls_available())
	    return 0;
	
#ifdef TELNET_CERT
        configure_driver(DC_TLS_CERTIFICATE, TELNET_CERT);
#endif

        err = tls_init_connection();
        if(err < 0)
        {
    	    debug_message(tls_error(err));
	    return 0;
	}
    }
#endif
    return clone_object(LOGIN_OB);
}

/* Diese Funktion wird aufgerufen, wenn einem Spieler die TCP-Connection
 * abbricht.
 */
protected void disconnect(object ob)
{
    PLAYER_SECOND->logout(ob->query_real_name(), ob);
    STATISTIK->logoff(ob->query_real_name());
    ob->net_dead();
}

/* Diese Funktion wird anstatt player->quit() aufgerufen */
protected void remove_player(object victim)
{
    catch(victim->quit(); publish);
    if (victim)
	destruct(victim);
}

// Incoming UDP-Paket
//
#ifdef RELAYD
int relays;
int query_relays() { return relays; }
#endif

protected void receive_udp(string host, string msg, int port)
{
#if 0
    if (find_player("freaky"))
	tell_object(find_player("freaky"),
	    sprintf("UDP:%s:%d EVAL:%d TI:%O\n",host,port,get_eval_cost(),
		this_interactive()));
#endif

   if(msg[0..2] == "RPC")
     RPC_SERVER->receive_udp(host, msg, port);
   else if(msg[0..4] == "NFTPD")
      FTP_SERVER->naseftpd_request(host,msg,port);
   else if(msg[0..4] == "ftpd:")
      FTP_SERVER->ftp_server(host,msg[5..],port);
#ifdef RELAYD
   else if(msg[0..6]=="relayd:")
      relays=to_int(msg[7..]);
#endif
   else
   {
      INETD->receive_udp(host,msg,port);
   }
}

protected int stale_erq(closure callback)
{
    int ret;

    if (find_player("freaky"))
	tell_object(find_player("freaky"),sprintf("stale_erq:%O:\n",callback));
    //ret = attach_erq_demon("",1);
    funcall(callback,-1,-1);
    return ret;
}

private void erq_stop()
{
    if (find_player("freaky"))
    	tell_object(find_player("freaky"),sprintf("ERQ-Stop\n"));
#ifdef __ERQ_MAX_SEND__ /* ERQ ist optional */
    attach_erq_demon("",0);
#endif
}
