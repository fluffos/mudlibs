/* Hamlet, Aug 1996.
   The intent was to make the intermud stuff fully configurable from
   this one file.
*/

/* Which mud is this for? */
#define FR                "FR:Illumitech"

#define LOGFILE          "INTERMUD"
#define SAVE_INTERMUD    "/net/intermud3/save/intermud"

#define FTP_PORT         0  /* We don't allow anonymous ftp (yet) */
#define HTTP_PORT        0  /* We don't have one (yet) */
#define NNTP_PORT        0  /* We don't have one */

#define IMUD_TCP_PORT    0
#define IMUD_UDP_PORT    0

#define OPEN_STATUS      "open to players"
#define ADMIN_EMAIL      "imudadm@fr.imaginary.com"

/* Below are the services we allow (and disallow) */
#undef  SERVICE_AUTH
#define SERVICE_CHANNEL
#undef  SERVICE_EMOTETO
#undef  SERVICE_FILE
#define SERVICE_FINGER
#define SERVICE_LOCATE
#undef  SERVICE_MAIL
#undef  SERVICE_NEWS
#define SERVICE_TELL
#undef  SERVICE_UCACHE
#define SERVICE_WHO


#define OTHER_SERVICES 0


/* Can players receive intermud stuff?  Whether they can SEND has to
   be coded in the mudlib.  Channel logic doesn't matter.... the
   mud's channel handler will cover that issue. 
*/
#define PLAYER_TELL
#undef  PLAYER_EMOTETO
#undef  PLAYER_MAIL

/* Are players counted in informational things?  The finger handler will
   have to deal with whether it allows players to be fingered.
*/
#define PLAYER_LOCATE
#define PLAYER_WHO

/* Do we want other mud to see who's listening to what channel? */
#undef  SHOW_CHANNEL_USERS

/* Log inter-mud channels?  Mostly for debugging/experimentation. */
#undef  LOG_CHANNELS

/* Listen to ALL intermud channels?  To see what they've got to offer. */
#undef  ALL_CHANNELS

/* Write existing channels out to a file every time. */
#define STORE_CHANNELS   "/net/intermud3/EXISTING.CHANNELS"

/* Matches object types to word-positions */
#define POSITIONS         ([ " " : "Player"     , "G" : "God"   \
                        , "D" : "Demi-god"    ,  "H" : "Alchemist"      \
                   , "T" : "Thane"    \
                     , "P" : "Patron", "B" : "Builder"   \
                         ])

/* These have to match up, of course.  The remote channel "imud_code"
   matches with the local channel "intercre", for instance.
*/
#define CHAN_TRANSLATE   ([ "remote": ({ "imud_code",     "imud_gossip"     \
                                        ,"intermud",      "discworld-admin" \
                                        ,"discworld-cre", "discworld-chat"  \
                                      }),                                   \
                            "local" : ({ "intercre",      "intergossip"     \
                                        ,"intermud",      "dwadmin"         \
                                        ,"dwcre",         "dwchat"          \
                                      })                                    \
                         ])
