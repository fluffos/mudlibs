
#define DT ctime()[4..9]+ctime()[19..23]+ctime()[10..15]
#define DTSTAMP implode(explode(DT," "),"_")
#define DT_NOSPC delete_spaces(DT)
