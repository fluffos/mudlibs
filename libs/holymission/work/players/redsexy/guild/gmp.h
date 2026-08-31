#define GM         "guild/master"
#define GD         GM->query_number("summoner")

#define PATH       GM->query_dir(GD) + "/"
#define ROOM       PATH + "rooms/"
#define OBJS       PATH + "objects/"
#define CRTS       PATH + "creatures/"
#define SPELL      PATH + "spell/"
#define BIN        PATH + "bin/"
#define HELP       PATH + "help/"
#define GLD        "PATH"

#define LOGS       "/log"
#define CD         "sys/chatd"

#define max_stats  GM->query_levels(GD)
#define sanctuary  ROOM + "roof"
