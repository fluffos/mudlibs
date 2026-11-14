 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Spielstatus, wer spielt, usw....
  *
  */

/* Der Spiel-Status, hauptsaechlich fuer Interaktionen am Brett */

#define GS_NOTHING                0  /* Spielfeld ist leer        */
#define GS_PREPARED               1  /* Spielfiguren aufgestellt  */
#define GS_READY                  2  /* Spieler/Farben zugeordnet */
#define GS_RUNNING                3  /* Das Spiel laeuft          */
#define GS_CONT                   4  /* Bereit zum Weiterspielen  */
#define GS_ENDED                  5  /* Das Spiel ist beendet     */

#define GS(x)                     (game_status==(x))  /* Abfrage des Status */
#define SET_GS(x)                 (game_status=(x))   /* Setzen des Status  */

/* Welche Farbe spielt gerade? 0 == Weiss, 1 == Schwarz */

#define PLAYING                   (sizeof(moves)%2)
#define NPLAYING                  ((sizeof(moves)+1)%2)

/* Gibt der Figur die Farbe des gerade [nicht] Spielenden. */

#define FIGPLAY(x)                (((x)&7)|(PLAYING<<3))
#define FIGNPLAY(x)               (((x)&7)|(NPLAYING<<3))

/* Ist die Figure eine Figur des Ziehenden? */

#define FIGTURN(x)                (PLAYING==((x)&8)>>3)
#define FIGNTURN(x)               (PLAYING!=((x)&8)>>3)


