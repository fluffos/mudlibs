#ifndef _H_GLS_
#define _H_GLS_
#endif

//#define NAME          0
#define X               0
#define Y               1
#define EXIT_SIZE       2
#define LEN(n)          all_rooms[n][2]
#define EXIT(n)         n + EXIT_SIZE + 1
#define NUM_PLAYER(n)   LEN(n) + EXIT_SIZE + 1
#define PLAYER(n,m)     m + NUM_PLAYER(n) + 1

#define INTERRUPTION    ","
#define CENTER_OB       "/d/city/guangchang"
#define GLS_HOST        "localhost 8589"

#define COMBINE(n,m)    n + INTERRUPTION + implode(m,INTERRUPTION)

#define TYPE_MAP        0x6F //111
#define TYPE_GET        OxDE //222


