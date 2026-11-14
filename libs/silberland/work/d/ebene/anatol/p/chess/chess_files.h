 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       [] 
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Welche Dateien liegen wo? 
  * Wo ist die Hilfedatei, wo ist das Objekt mit den Schemata?
  *
  */

 /* 2012-01-25 Anatol          moved location to /d/ebene  */

#define CHESSDIR     "/d/ebene/anatol/p/chess/" /* Wo lebt das Projekt?     */

#define SAVEDIR      CHESSDIR "save/"           /* Partien dorthin sichern  */
#define ARCHIVEDIR   CHESSDIR "archive/"        /* Partien dorthin ablegen  */
#define LOGDIR       CHESSDIR "log/"            /* Logfiles dorthin bitte   */
#define HELPFILE     CHESSDIR "chess_help.txt"  /* Die Hilfedatei zum Spiel */
#define RULESFILE    CHESSDIR "chess_rules.txt" /* Die Worte der FIDE       */
#define SCHEMESOBJ   CHESSDIR "chess_schemes"   /* Das Objekt der Schemata  */
#define PROTOCOLOBJ  CHESSDIR "chess_protocol"  /* Das Partieprotokoll      */

#define TRACELOG(x) writelog(LOGDIR "trace",\
    sprintf("%s|%s|%s\n",dtime(time())[5..],\
      explode(file_name(this_object())+"#blue","#")[1],x),1)

#define MAX_CHESSLOG_SIZE 50000   /* siehe auch config.h */

