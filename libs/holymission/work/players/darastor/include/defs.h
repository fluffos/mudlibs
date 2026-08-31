#define PATH                    "/players/darastor/"
#define SEASIDE                 PATH+"beach_area/"
#define LIBRARY                 PATH+"library/"
#define NOTTINGHAM              PATH+"nottingham/"
#define SHERWOOD                PATH+"sherwood/"

#define TP                      this_player()
#define TO                      this_object()
#define NAME                    query_name()
#define CNAME                   capitalize(TP->NAME)
#define REPLACE_ROOM            replace_program("/room/room")
#define EXTRA_ROOM_FUNCTIONS    PATH+"extra_functions/extra_room_functions"
