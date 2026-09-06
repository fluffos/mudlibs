/* Some defines to make the house-related files consitent */

// houses directory
#define HOUSES(x)               "/p/houses/"
#define HOUSEROOMS(x)           HOUSES("rooms/")

// other defines
#define CERT_DUMMY              "/obj/houses/cert_dummy"
#define PROPERTYFILE            "/log/houses/POOL"
#define POOLFILE                "/obj/houses/proppool"

// some macros
#define TP this_player()
#define TO this_object()
#define TI this_interactive()
#define NAME this_player()->QueryName()
#define RNAME this_player()->QueryRealName()
#define PO previous_object()
#define CAP(x) capitalize(x)

