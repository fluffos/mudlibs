 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * P_CHESS ist eine relativ lokale Property, die im Spieler aber
  * gesaved wird. Welches Bit wie was wo bedeutet - hier steht es,
  * und wie man damit umgeht, auch gleich...
  *
  */


/* Die unteren beiden Halbbytes codieren die Farbauswahl und Styles, 
 * darueber dann die anderen Einstellungen... */

#define P_CHESS              "anatol_chess"   /* ---> Spieler         */
#define PLF_COLORS            0x000F           /* welche Farben        */
#define PLF_STYLES            0x00F0           /* welcher Figurenstil  */
#define PLF_SHORT_MSG         0x0100           /* Kurze Zugmeldung     */
#define PLF_LONG_MSG          0x0200           /* Lange Zugmeldung     */
#define PLF_NOTATION_TYPE     0x0400           /* algebr. Notation?    */
#define PLF_VIEW              0x0800           /* Nach jedem Zug...    */
#define PLF_ANSI_YN           0x1000           /* Ansi ja/nein         */
#define PLF_ANSI_TTY          0x2000           /* Ansi auto            */

/*               1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *               -v- v v -v- ---v--- ---v---
 *             Ansi  | |  |  Figuren  Farben
 *                   | |  Kurz/Lang
 *                   | Algebraisch
 *                   Brettanzeige
 *
 * Die beiden Bits fuer die ANSI-Einstellung bedeuten:
 *  0 0    Keine Ansi-Farben
 *  0 1    Ansi-Farben von Bretteinstellung erzwungen
 *  1 0    P_TTY gilt und sagt: Keine Ansi-Farben 
 *  1 1    P_TTY gilt und sagt: Ansi-Farben 
 *  Das heisst, dass wenn vorne eine "1" steht, das zweite Bit beim 
 *  Auslesen von P_TTY bestimmt wird (egal was im Spieler gespeichert ist)
 */

/* Handhabe der $"%&-Spielereinstellungen */

/* Die Standardeinstellung: Spielbrett, lange Zugmeldung, Farbschema
 * 0 (irgendeine gelb-weisse Komposition mit roten und blauen Figuren),
 * Stilrichtung der Figuren 0 (Mein Erstentwurf :)). 
 * *Zuschauende* bekommen das Brett nach einem Zug aber so oder so
 * _NICHT_ automatisch zu sehen. Waere etwas rechenzeitintensiv, wenn
 * da mal 10 Leute im Raum stehen und jedesmal wegen der persoenlichen
 * Einstellungen die Strings neu zusammengesteckt werden wuerden. */

#define CHESS_DEFAULT_FLAGS     (PLF_VIEW|PLF_LONG_MSG|PLF_ANSI_TTY) 

// #define GETPLFLAGS(x)       ((int)((x)->QueryProp(P_CHESS)))
#define GETPLFLAGS(x)       (getPlayerFlags(x))
#define PLFLAG(x,y)         ((x)&(y))
#define PLCOLOR(x)          ((x)&(PLF_COLORS))
#define PLSTYLE(x)          (((x)&(PLF_STYLES))>>4)
#define SET_PLFLAGS(x,y)    ((int)(x)->SetProp(P_CHESS,y))
#define SET_PLCOLOR(x,y)    ((int)((x)->SetProp(P_CHESS,(GETPLFLAGS(x) &\
                                      (~PLF_COLORS)) |(y))))
#define SET_PLSTYLE(x,y)    ((int)((x)->SetProp(P_CHESS,(GETPLFLAGS(x) &\
                                      (~PLF_STYLES)) |(y<<4))))
#define SET_PLFLAG(x,y)     ((int)(x)->SetProp(P_CHESS,GETPLFLAGS(x)|(y)))
#define UNSET_PLFLAG(x,y)   ((int)(x)->SetProp(P_CHESS,GETPLFLAGS(x)&~(y)))
#define SAVE_PLFLAG(x)      (x)->Set(P_CHESS, SAVE, F_MODE_AS);

/* Farben und Schemata-Handling. */

#define CSCH(which, col)         (color_schemes[which][col])
#define SSCH(which, sty)         (style_schemes[which][sty])
#define CSCH_TEXT                4
#define SSCH_TEXT                7
#define COL_BG(x)                (2|(x))
#define COL_P(x)                 (x)
#define NRML                     ANSI_NORMAL

