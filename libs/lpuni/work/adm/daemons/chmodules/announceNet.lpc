/* chdmod_announce.c

 Tacitus @ LPUniversity
 28-JUNE-06
 Announce channel module

*/

string *history;

void create()
{
     CHAN_D->registerModule("announceNet", file_name(this_object()));

     CHAN_D->registerCh("announceNet", "announce");
     history = ({});
}

int rec_msg(string chan, string usr, string msg)
{
     object ob;

     switch(msg) /* We could do some neat stuff here! */
     {
          case "/last" : {

               ob = find_player(usr);

               if(!sizeof(history)) tell_object(ob,
                "AnnounceNet: Channel " + chan + " has no history yet.\n");
               else tell_object(ob,
                    implode(history[(sizeof(history) - 15)..(sizeof(history) - 1)], ""));

               return 1;
          }
     }

    if(!adminp(usr)) return 0;

    CHAN_D->rec_msg(chan,  "[%^MAGENTA%^"  + capitalize(chan) + NOR + "] " + HIW
        + capitalize(usr) + NOR + ": " + msg + "\n");

    history += ({ ctime(time()) + " [%^MAGENTA%^" + capitalize(chan) + NOR + "] "
            + HIW + capitalize(usr) + NOR + ": " + msg + "\n" + NOR });

    return 1;
}

void announce_login(string user)
{
    CHAN_D->rec_msg("announce",
         "[%^MAGENTA%^Announce%^RESET%^]%^RED%^ System%^RESET%^: "
             + capitalize(user) + " has logged into "
            + mud_name() + ".\n");
    history += ({ ctime(time())
        + " [%^MAGENTA%^Announce%^RESET%^]%^RED%^ System%^RESET%^: "
             + capitalize(user) + " has logged into "
            + mud_name() + ".\n" });
}

void announce_logoff(string user)
{
    CHAN_D->rec_msg("announce",
         "[%^MAGENTA%^Announce%^RESET%^]%^RED%^ System%^RESET%^: "
             + capitalize(user) + " has left "
            + mud_name() + ".\n");
    history += ({ ctime(time())
        + " [%^MAGENTA%^Announce%^RESET%^]%^RED%^ System%^RESET%^: "
             + capitalize(user) + " has left "
            + mud_name() + ".\n" });
}

int isAllowed(string channel, string usr, int flag)
{
    return 1;
}

