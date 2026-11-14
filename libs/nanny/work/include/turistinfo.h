#define DATA_PATH "/open/info/"
#define BOOKLET "/players/gwendolyn/obj/booklet"
#define MYCKE 10000
#define MAZE_ROOM "/room/maze1/maze1"
#define BOOKLET_ID "the_booklet"
#define CLERK_OBJ "/obj/turistinformator"
#define CLERK_ID "turistinformator"

#define SAY my_say
#define TELL my_tell_object
#define LINE_WRAP(a) (line_break( a ) + "\n")
#define LINE_WRAP2(a) (line_break( a )[ 0..strlen( line_break( a ) ) - 2 ])

#define WIZARDP(a) ("/obj/player_checker"->wizardp(a))
#define PLAYERP(a) ("/obj/player_checker"->playerp(a))
      
void my_tell_object( mixed a, mixed b )
{ tell_object( a, LINE_WRAP(b) ); }

status query_prevent_shadow()
{ return 1; }
