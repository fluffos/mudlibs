 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Wie kann das Spiel enden?
  *
  * Die Idle-Zeit steht hier eigentlich nur da, weil sie nirgendwo
  * anders reinpasst.
  */

/* Wie lange darf ein Spieler idlen, bevor sein Partner die Partie
 *  * ohne Rueckfrage unterbrechen kann? */

#define MIN_IDLE_TO_SUSPEND (15*60)

/* Ein Spiel kann verschieden enden, das "Wie" wird hier definiert. */

#define CET_MATE               1    /* Schach matt                        */
#define CET_GIVINGUP           2    /* Gegner gab auf                     */
#define CET_TIMEOUT            3    /* Die Klappe des Gegners fiel        */
#define CET_STALEMATE          4    /* Keine Zugmoeglichkeit mehr (patt)  */
#define CET_REMIS_BY_PROPOSAL  5    /* Remis durch Vereinbarung (remis)   */
#define CET_REMIS_BY_REPEAT    6    /* Dreimal die selbe Stellung (remis) */
#define CET_REMIS_BY_GAME      7    /* 40 Zuege-Ende (remis)              */


