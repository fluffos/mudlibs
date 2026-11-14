 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Um in der Zug-Integer komfortabel die Zugeigenschaften setzen zu 
  * koennen, braucht es auch ein paar schnuckelige Defines... 
  *
  * Ein Spielzug setzt sich aus verschiedenen Eigenschaften zusammen, die
  * waehrend des Spielverlaufs teilweise redundant sind, fuer die Ausgabe
  * des Zuges in textueller Form jedoch benoetigt werden. Da wir 32 Bit 
  * einer Integer zur Verfuegung haben, duerfen wir da ruhig ein wenig 
  * freizuegiger sein.
  * 
  * Remisangebote muessen im Protokoll vermerkt werden, daher sind sie 
  * hier... 
  *
  * Startfeld           6 bits 
  * Zielfeld            6 bits  (Wenn Start==Ziel==Ecke ==> Rochade)
  * Algebr. Notation    2 bits  (gesetzt: anzeigen)
  * bewegter Figurtyp   4 bits  (BSLTDK + Farbe)
  * algebr. Notation    2 bits  (nix, nur Buchstabe, nur Zahl, beide)
  * Bewegungsart        2 bit   (ziehen, schlagen, schlagen e.p.)
  * Schach geboten?     1 bit   (0 od 1)
  * Remis angeboten?    1 bit   (0 od 1)
  * Bauernwandlung      3 bits  (SLTD) (Faulheit... 2 wuerden auch reichen)
  * --------------------------------------------------
  * Insgesamt          23 bits
  *
  * Die Figurenfarbe muss auch rein, egal ob man (theoretisch) das aus
  * der Anzahl der Zuege herauslesen koennte oder nicht. :)
  * 
  * *sniff* hne Redundanzen koennte man das auf 15 Bits quetschen...
  *
  * Das alles kann man dann aus einer einzigen Integer herauslesen ;o)
  *  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
  *              ----- - - --- --- ----------- ----------- -------
  *                Wan | | Art  |    Endfeld    Startfeld    |
  *                dlu | |      |_Algebr. Notation           |_Figurtyp
  *                ng. | |_Schach
  *                    |_Remis
  *
  */


  /* Bits setzen... */

#define SMV_FIGURE(mov, x)           mov|=(x)        /* Gezogene Figur       */
#define SMV_FROM(mov,x)              mov|=((x)<<4)   /* Von...               */
#define SMV_TO(mov, x)               mov|=((x)<<10)  /* Nach...              */
#define SMV_NOTATION(mov,x)          mov|=((x)<<16)  /* algebr. Not. Buchst. */
#define SMV_TYPE(mov,x)              mov|=((x)<<18)  /* Gangart e.p.? roch?  */
#define SMV_CHECK(mov)               mov|=(1<<20)    /* Schachgebot          */
#define SMV_WANT_REMIS(mov)          mov|=(1<<21)    /* Remis angeboten?     */
#define SMV_PAWN_PROMOTION(mov,x)  mov|=((x)<<22)  /* Bauerwandel in?      */

  /* *grmpf* Wer A sagt, muss auch B sagen und so gibt es natuerlich auch
   *  * die #defines, die aus der Integer die entsprechenden Werte holen. */

#define QMV_FIGURE(mov)             ((mov)&15)
#define QMV_FROM(mov)               (((mov)&1008)>>4)
#define QMV_TO(mov)                 (((mov)&64512)>>10)
#define QMV_NOTATION(mov)           (((mov)&196608)>>16)
#define QMV_TYPE(mov)               (((mov)&786432)>>18)
#define QMV_CHECK(mov)              (((mov)&1048576)>>20)
#define QMV_WANT_REMIS(mov)         (((mov)&2097152)>>21)
#define QMV_PAWN_PROMOTION(mov)   (((mov)&29360128)>>22)

  /* Dort, wo mehrere Bits verschiedene Zustaende markieren, sind dann noch
   *  * einmal weitere #defines zu haben... */

#define MVT_GO                0
#define MVT_STRIKE            1
#define MVT_PASSING_STRIKE    2
#define MVT_CASTLING          3
