 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Koordinaten, Figuren, Schachbrett... nichts geht ohne Defines.
  *
  */

/* Wo auch immer: Nur drei Bits fuer die Bestimmung des Figurtyps. Nimmt
 * man die Farbe der Figur noch dazu, braucht man je Feld 4 bits, bei 8
 * Feldern je Zeile reichen dann 8 ints, um alle 64 Felder darzustellen. */

#define B            1                        /* Bauer               */
#define S            2                        /* Springer            */
#define L            3                        /* Laeufer             */ 
#define T            4                        /* Turm                */
#define D            5                        /* Dame                */
#define K            6                        /* Koenig              */

/* Um das Programm leserlich zu halten, verwenden wir am besten auch noch
 * schoene #defines fuer die Koordinaten. Wer kann mit einem Zug 10-43 
 * schon was anfangen? Eben. ;) */

#define Ca          0
#define Cb          1
#define Cc          2
#define Cd          3
#define Ce          4
#define Cf          5
#define Cg          6
#define Ch          7

#define C1          0
#define C2          1
#define C3          2
#define C4          3
#define C5          4
#define C6          5
#define C7          6
#define C8          7

/* Um aus die sechs Bit zusammenzulegen und wieder auseinanderzupfiemeln,
 * dies hier *seufz */

#define XY(x,y)             ((x)|(y)<<3)   /* Koordinate bilden          */
#define X(x)                ((x)&7)        /* Spalte (!) extrahieren a-h */
#define Y(x)                (((x)>>3)&7)   /* Zeile extrahieren 1-8      */

/* Vorsicht vor Seiteneffekten.... */

#define STRCOORD(x)  sprintf("%c%c",'a'+((x)&7),'1'+((x)>>3))

/* Damit laesst sich dann auch gut auf board[] zugreifen... */

#define BOARD(sp,ze)            (board[sp+(ze<<3)])
#define SET_BOARD(sp,ze,w)      (board[sp+(ze<<3)]=w)

