/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#define GM             "guild/master"
#define CD             "sys/chatd"

#define TOTAL_HIDDEN   (dex * 45)   /*        max time hidden  */
#define ROOM           "/players/blade/guild/room"
#define ENV            environment
#define AL_STEALMONEY  -10          /*  alignment: steal money */
#define AL_STEALITEM   -50          /*             steal item  */
#define LV_STBAG        20          /* level for stealing bags */
#define SROOM "/players/blade/guild/contest/scroll_room"
#define PROOM "/players/blade/guild/contest/plunder_room"
#define THIEF this_player()

object att;
#define CHK_ATT(); \
if ((att=THIEF->query_attack()) &&\
    present(att,environment(THIEF))) {\
      write("You are much too busy to do that.\n");\
      return 1;\
}


