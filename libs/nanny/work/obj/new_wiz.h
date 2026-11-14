#define WIZ_ROOM "/obj/new_wiz_line_room"
#define WIZ_PLAYER "obj/new_wiz_line_player"
#define VOID "/room/void"
#define CHURCH "/room/church"

#define WIZ_COMMAND  "wiz"
#define BASE_CHANNEL "basic"
#define TOGGLE_CHANNEL "wiz"

#define SEC_CHECK    (this_player()->query_level() > 22 )
#define POWER_REST_CHAN  ({ "30", "elder" })
#define SUPER_REST_CHAN  ({"25","arch"})
#define REST_CHAN  ({"all","23","idi"})
#define SKILLED_CHAN ({"22","skilled"})
