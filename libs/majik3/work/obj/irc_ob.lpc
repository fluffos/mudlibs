// DESCRIPTION : interface for internet relay chat
// CODER       : namhas

inherit BASE;

/* RFC 1459 ERROR REPLIES */

#define ERR_NOSUCHNICK		401
#define ERR_NOSUCHSERVER	402
#define ERR_NOSUCHCHANNEL	403
#define ERR_CANNOTSENDTOCHAN	404
#define ERR_TOOMANYCHANNELS	405
#define ERR_WASNOSUCHNICK	406
#define ERR_TOOMANYTARGETS	407
#define ERR_NOORIGIN		409
#define ERR_NORECIPIENT		411
#define ERR_NOTEXTTOSEND	412
#define ERR_NOTOPLEVEL		413
#define ERR_WILDTOPLEVEL	414
#define ERR_UNKNOWNCOMMAND	421
#define ERR_NOMOTD		422
#define ERR_NOADMININFO		423
#define ERR_FILEERROR		424
#define ERR_NONICKNAMEGIVEN	431
#define ERR_ERRONEUSNICKNAME	432
#define ERR_NICKNAMEINUSE	433
#define ERR_NICKCOLLISION	436
#define ERR_USERNOTINCHANNEL	441
#define ERR_NOTONCHANNEL	442
#define ERR_USERONCHANNEL	443
#define ERR_NOLOGIN		444
#define ERR_SUMMONDISABLED	445
#define ERR_USERSDISABLED	446
#define ERR_NOTREGISTERED	451
#define ERR_NEEDMOREPARAMS	461
#define ERR_ALREADYREGISTERED	462
#define ERR_NOPERMFORHOST	463
#define ERR_PASSWDMISMATCH	464
#define ERR_YOUREBANNEDCREEP	465
#define ERR_KEYSET		467
#define ERR_CHANNELSFULL	471
#define ERR_UNKNOWNMODE		472
#define ERR_INVITEONLYCHAN	473
#define ERR_BANNEDFROMCHAN	474
#define ERR_BADCHANNELKEY	475
#define ERR_NOPRIVILEGES	481
#define ERR_CHANOPPRIVSNEEDED	482
#define ERR_CANTKILLSERVER	483
#define ERR_NOOPERHOST		491
#define ERR_UMODEUNKNOWNFLAG	501
#define ERR_USERSDONTMATCH	502

/* RFC 1459 COMMAND RESPONSES */

#define RPL_NONE		300
#define RPL_USERHOST		302
#define RPL_ISON		303
#define RPL_AWAY		301
#define RPL_UNAWAY		305
#define RPL_NOWAWAY		306
#define RPL_WHOISUSER		311
#define RPL_WHOISSERVER		312
#define RPL_WHOISOPERATOR	313
#define RPL_WHOISIDLE		317
#define RPL_ENDOFWHOIS		318
#define RPL_WHOISCHANNELS	319
#define RPL_WHOWASUSER		313
#define RPL_ENDOFWHOWAS		369
#define RPL_LISTSTART		321
#define RPL_LIST		322
#define RPL_LISTEND		323
#define RPL_CHANNELMODEIS	324
#define RPL_NOTOPIC		331
#define RPL_TOPIC		332
#define RPL_INVITING		341
#define RPL_SUMMONING		342
#define RPL_VERSION		351
#define RPL_WHOREPLY		352
#define RPL_ENDOFWHO		315
#define RPL_NAMREPLY		353
#define RPL_ENDOFNAMES		366
#define RPL_LINKS		364
#define RPL_ENDOFLINKS		365
#define RPL_BANLIST		367
#define RPL_ENDOFBANLIST	368
#define RPL_INFO		371
#define RPL_ENDOFINFO		374
#define RPL_MOTDSTART		375
#define RPL_MOTD		372
#define RPL_ENDOFMOTD		376
#define RPL_YOUREOPER		381
#define RPL_REHASHING		382
#define RPL_TIME		391
#define RPL_USERSSTART		392
#define RPL_USERS		393
#define RPL_ENDOFUSERS		394
#define RPL_NOUSERS		395
#define RPL_TRACELINK		200
#define RPL_TRACECONNECTING	201
#define RPL_TRACEHANDSHAKE	202
#define RPL_TRACEUNKNOWN	203
#define RPL_TRACEOPERATOR	204
#define RPL_TRACEUSER		205
#define RPL_TRACESERVER		206
#define RPL_TRACENEWTYPE	208
#define RPL_TRACELOG		261
#define RPL_STATSLINKINFO	211
#define RPL_STATSCOMMANDS	212
#define RPL_STATSCLINE		213
#define RPL_STATSNLINE		214
#define RPL_STATSILINE		215
#define RPL_STATSKLINE		216
#define RPL_STATSYLINE		218
#define RPL_ENDOFSTATS		219
#define RPL_STATSLLINE		241
#define RPL_STATSUPTIME		242
#define RPL_STATSOLINE		243
#define RPL_STTASHLINE		244
#define RPL_UMODEIS		221
#define RPL_LUSERCLIENT		251
#define RPL_LUSEROP		252
#define RPL_LUSERUNKNOWN	253
#define RPL_LUSERCHANNELS	254
#define RPL_LUSERME		255
#define RPL_ADMINME		256
#define RPL_ADMINLOC1		257
#define RPL_ADMINLOC2		258
#define RPL_ADMINEMAIL		259

#include <socket.h>

object gob;

#define irc(x) message ("0", "IRC: "+x+"\n", gob)
#define irce(x) message ("0", "Error: "+x+"\n", gob)
#define ircf(x) message ("0", "Error: "+x+"\n", gob)

object sock;

string roina;
string curchan;
string nickname = "";

string list_buf = "";
string *last_buf = ({ });
string who_buf = "";

read_func (object socket, string data, string address)
{
  string *arr, prefix, nick, user, host, command, params, tmp, buf, *arr2;

  // tell_object (find_player("namhas"), data);

  arr = explode(data, "\r\n");  

  // tell_object(gob, data);

  for (int i=0;i<sizeof(arr);i++)
    {
      if (arr[i][0..3] == "PING")
        {
          if (gob && interactive(gob)) /* kick off ld users */
            socket->send ("PONG "+arr[i][5..]+"\r\n");
        }
      else if (arr[i][0] == ':')
        {
          if (sscanf (arr[i][1..], "%s %s %s", prefix, command, params) == 3)
            {
              if (prefix)
                {
                  if (sscanf (prefix, "%s!%s@%s", nick, user, host) == 3)
                    nick = lower_case(nick);
                  else
                    nick = lower_case(prefix);
                }
            }
        }
      else
        {
          sscanf(arr[i][1..], "%s %s", command, params);
        }
/*
tell_object (gob, "nick: "+nick+" command: "+command+" params: "+params+"\n");
*/

  if (command && (command[0] == '4' || command[0] == '5'))
    {
      if (command == "451")
        {
          ircf("Your name is already in use. Read irc(1) how to specify new name.");
          gob->disable_channel ("irc");
          destruct (THOB);
        }
      else
        {
          arr2 = explode(params, " ");
          irce(implode(arr2[1..], " "));
        }
    }
  else if (to_int(command) > 0)
    {
      params = replace_string(params, ":", "");
      arr2 = explode(params, " ");

      if (to_int(command) == 332)
        {
          irc ("Topic for channel ^c1"+arr2[1]+": ^c0^cc"+implode(arr2[2..], " ") + "^c0");
        }
      if (to_int(command) == 251)
        {
          irc ("Welcome to the Internet Relay Network, "+capitalize(nickname)+"!");
          irc (implode(arr2[1..], " ") + ".");
        }
      if (to_int(command) == 352)
        {
          message("0", sprintf(
            "^cc[^c0^c1%-3s^c0^cc]^c0 ^c1%-10s^c0 %-30s %-20s\n",
            arr2[6], lower_case(arr2[5]), "" + arr2[2] + "@" + arr2[3] + ""[0..29],
            implode(arr2[8..], " ")[0..19]), gob);
        }
      /*else
        irc (params);*/

      // if (arr2[0] == gob->query_name())
      // irc(implode(arr2[1..], " "));
    }
  else if (command == "JOIN" && nick == nickname)
    {
      irc("Channel irc:^c1"+params[1..]+"^c0 is now enabled.");
    }
  else if (command == "PART" && nick == nickname)
    {
      sscanf (params, "%s %s", buf, tmp);
      irc ("Channel irc:^c1"+buf+"^c0 is now disabled.");
    }
  else if (command == "JOIN")
    { 
      irc ("^c1"+capitalize(nick)+"^c0 has joined to channel irc:^c1"+params[1..]+"^c0.");
    }
  else if (command == "PART")
    {
      sscanf (params, "%s %s", buf, tmp);
      irc ("^c1"+capitalize(nick)+"^c0 has left the channel irc:^c1"+buf+"^c0.");
    }
  else if (command == "QUIT")
    {
      irc ("^c1"+capitalize(nick)+"^c0 has left the IRC ("+params[1..]+").");
    }
  else if (command == "PRIVMSG")
    {
      sscanf (params, "%s :%s", buf, tmp);
      if (tmp[0] == 1 && tmp[<1] == 1)
        {
          // message ("0", "IRC: (ctcp) " + capitalize(nick) + " ^c1"+tmp+"^c0\n", gob);
          if (tmp[1..<2] == "VERSION")
            {
              socket->send("NOTICE "+nick+" :"+
                sprintf("\x01VERSION Majik MURPE irc client v0.6-alpha (http://majik.netti.fi)\x01\r\n")+"");

              irc ("IRC: ^c1" + capitalize(nick)+"^c0 requested your ^ccversion^c0 information.");
            }
          if (tmp[1..<2] == "FINGER")
            {
              socket->send(
                sprintf("NOTICE %s :FINGER %s (%s@majik.netti.fi) Idle %d seconds\r\n",
                nick, gob->query("real_name"), gob->query_true_name(),
                query_idle(gob)));

              irc ("IRC: ^c1" + capitalize(nick)+"^c0 requested your ^ccfinger^c0 information.");
            }
        }          
      else if (lower_case(buf) == nickname)
        {
          message ("0", capitalize(nick) + " irc-tells you '^c1"+tmp+"^c0'\n", gob);
        }
      else
        { 
          message ("0", capitalize(nick) + " ^cc[^c0^c1irc:"+buf+"^c0^cc]^c0: "+tmp+"\n", gob);
        }
    }
  else
    {/*
      irc (params);*/
    }
  }
}

int
do_irc (string channel, string str)
{
  string msg, cmd, *arr;

  write (file_name(gob) + "\n");
  write (gob->query_name() + "\n");
  write (sprintf("%O",sock) + "\n");

  if (!str)
    {
      notify_fail ("Usage: "+channel+" [message / who / last]\n");
      return 0;
    }

  sock->send ("JOIN "+channel+"\r\n");

  if (lower_case(str) == "who")
    {
      sock->send ("WHO "+channel+"\r\n");
      return 1;
    }

  if (lower_case(str) == "last")
    {
      return 1;
    } 

  if (lower_case(str) == "off")
    {
      sock->send ("PART "+channel+"\r\n");
      return 1;
    }

  sock->send("PRIVMSG "+channel+" : "+str+"\r\n");
  tell_object (gob, capitalize(nickname) + " ^cc[^c1"+channel+
    "^c0^cc]^c0: "+str+"\n");

  return 1;
}

send (string str)
{
  sock->send(str);
  return;
}

close_func ()
{
  gob->disable_channel ("irc");
  destruct (THOB);
}

int
main (object ob, string str)
{
  gob = ob;

  if (sock)
    sock->remove();

  /* irc.netti.fi 192.89.123.15 6667
     irc.clinet.fi 194.100.0.6 6667 */

  sock = new (SOCKET, SKT_STYLE_CONNECT, "192.89.123.15 6667",
         (: read_func :), (: close_func :));

  if (!sock)
    return 1;

  if (!str)
    str = gob->query_name();

  nickname = str;

  sock->send ("PASS majik"+random(100)+"\r\n");
  sock->send ("NICK "+nickname+"\r\n");
  sock->send ("USER "+gob->query_name()+" * * :"+gob->query("real_name")+"\r\n");
  sock->send ("JOIN #majik\r\n");

  curchan = "#majik";
  gob->enable_channel ("irc");

  return 1;
}
