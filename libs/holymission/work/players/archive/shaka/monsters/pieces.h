#define EMPTY   0
#define KING    1
#define QUEEN   2
#define BISHOP  3
#define KNIGHT  4
#define ROOK    5
#define PAWN    6

/*Black pieces have the same value except that they're negative value
so the black KING is = -1;
  etc.etc.*/
#define WHITE 1
#define BLACK -1

/* this is an error constant which will be returned when you
query the value of a square which is out of bondaries  (exam: square(-1,10) )
*/

#define OUT_OF_BORDER 100

