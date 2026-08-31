/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#ifndef GM
#define GM             "guild/master"
#endif
#define GUILD          "thief"
#ifndef CD
#define CD             "sys/chatd"
#endif
#define DIR            GM->query_dir(1) + "/"
#define TOTAL_HIDDEN   (dex * 45)   /*        max time hidden  */
#define ROOM           DIR + "rooms/joinroom"
#ifndef ENV
#define ENV            environment
#endif
#define AL_STEALMONEY   -10         /*  alignment: steal money */
#define AL_STEALITEM    -50         /*             steal item  */
#define THIEF this_player()
#define LV_STBAG        20          /* level for stealing bags */
#ifndef TP
#define TP              this_player()
#endif
#define ROOMDIR         DIR + "rooms/"
#define BINDIR          DIR + "bin/"
#define OBJDIR          DIR + "obj/"
#define MONDIR          DIR + "mon/"
#define POIDIR          DIR + "poison/"
#define TDIR            DIR + "thieves/"
#define SROOM           ROOMDIR + "scroll_room"
#define PROOM           ROOMDIR + "plunder_room"
object att;
#define CHK_ATT(); \
if ((att=THIEF->query_attack()) &&\
    present(att,environment(THIEF))) {\
      write("You are much too busy to do that.\n");\
      return 1;\
}


