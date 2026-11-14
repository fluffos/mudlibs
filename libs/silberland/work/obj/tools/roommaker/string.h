/* Constants used by /obj/lib/string */

  /* stime()-formats */

#define SD_WDAY 1
#define SD_DATE 2
#define SD_TIME 4
#define SD_SDATE 8
#define SD_FULL 7

  /* Standard-SMore using this_player()'s Pagesize: */

#define SMore(text) smore(text,0,(int)this_player()->QueryProp("pagesize"))
