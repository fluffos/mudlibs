/*-----------------------------------------------------------------------------\
| Pfadfinderfee Navi - Settings                        (C) by Hotaru, 01.08.01 |
\-----------------------------------------------------------------------------*/

// File paths
#define NAVI_LIB "/d/ebene/hotaru/npc/navi/navi.lib"
#define NAVI_LOG "wiz/hotaru/navi.log"

// Explore delays for DelayExploreMode()
#define EXP_DELAY_CLONE 200  // time to begin exploring after cloning
#define EXP_DELAY_GREET 160  // time to begin exploring after greeting a newbie
#define EXP_DELAY_HELP  120  // time to begin exploring after helping somebody
#define EXP_DELAY_MEET   40  // time continue exploring after meeting somebody
#define EXP_DELAY        25  // walk delay when in explore mode
#define MAX_MEET_WAIT     2  // max. number of player meeting delays in one room

// Lock delays for AddLock()
#define LOCK_INTRO      160  // lock time after introducing a newbie
#define LOCK_FIGHT      120  // lock time after a fight
#define LOCK_GREET      100  // lock time after greeting a newbie
#define LOCK_ASK         30  // lock time after answering a question
#define LOCK_GOAWAY       8  // lock time after "go away"
#define LOCK_SCHMOLL      1  // schmoll lock :o)

// Error constants for CannotHelp()
#define ERR_SILENT        0
#define ERR_SAY           1
#define ERR_TELL          2
#define ERR_NOLEVEL       3

// Rooms that should not be visited
#define StopRooms \
  ({ \
    "/d/wasser/stahldorn/knarkh/*", \
    "/d/ebene/Midas/room/kanal/*", \
    "/d/ebene/ronja/feenquest/lab/*" \
  })

// Areas that Navi can lead someone to
#define areas \
  ([ \
    "anfaengerpark": ({"anfaengerpark", "Anfaengerpark",  "zum",  "im"}), \
    "kapelle":       ({"kapellen",      "einer Kapelle",  "zu",   "in"}), \
    "laden":         ({"laeden",        "einem Laden",    "zu",   "in"}), \
    "post":          ({"post",          "Post",           "zur",  "auf der"}), \
    "gilde":         ({"gilden",        "einer Gilde",    "zu",   "in"}), \
    "max":           ({"max",           "Max, dem Wirt",  "zu",   "bei"}), \
    "pier":          ({"pier",          "Pier",           "zur",  "auf der"}), \
    "hafen":         ({"pier",          "Pier",           "zur",  "auf der"}), \
    "silberwald":    ({"silberwald",    "Silberwald",     "zum",  "im"}), \
    "bauernhof":     ({"bauernhof",     "Bauernhof",      "zum",  "auf dem"}), \
    "burg sturmfels":({"sturmfels",     "Burg Sturmfels", "zur",  "auf der"}), \
    "sturmfels":     ({"sturmfels",     "Burg Sturmfels", "zur",  "auf der"}), \
    "paladinburg":   ({"sturmfels",     "Burg Sturmfels", "zur",  "auf der"}), \
    "palaburg":      ({"sturmfels",     "Burg Sturmfels", "zur",  "auf der"}), \
    "feenschloss":   ({"feenschloss",   "Feenschloss",    "zum",  "im"}), \
    "schloss":       ({"feenschloss",   "Feenschloss",    "zum",  "im"}), \
    "feen":          ({"feenschloss",   "Feenschloss",    "zum",  "im"}), \
    "midas":         ({"midas",         "Midas",          "nach", "in"}), \
    "felonia":       ({"felonia",       "Felonia",        "nach", "in"}), \
    "zwergenstadt":  ({"felonia",       "Felonia",        "nach", "in"}), \
    "zwergen":       ({"felonia",       "Felonia",        "nach", "in"}), \
    "elessar":       ({"elessar",       "Elessar",        "nach", "in"}), \
    "elfendorf":     ({"elessar",       "Elessar",        "nach", "in"}), \
    "elfen":         ({"elessar",       "Elessar",        "nach", "in"}), \
    "derlim":        ({"derlim",        "Derlim",         "nach", "in"}), \
    "hobbingen":     ({"derlim",        "Derlim",         "nach", "in"}), \
    "hobbits":       ({"derlim",        "Derlim",         "nach", "in"}), \
    "dhrkion":       ({"dhrkion",       "Dhrkion",        "nach", "in"}), \
    "dunkelelfen":   ({"dhrkion",       "Dhrkion",        "nach", "in"}), \
    "kyranda":       ({"kyranda",       "Kyranda",        "nach", "in"}), \
    "ogerhoehle":    ({"ogerhoehle",    "Ogerhoehle",     "zur",  "in der"}), \
    "ogerlager":     ({"ogerhoehle",    "Ogerhoehle",     "zur",  "in der"}), \
    "ogern":         ({"ogerhoehle",    "Ogerhoehle",     "zur",  "in der"}), \
    "trollager":     ({"trollager",     "Trollager",      "ins",  "im"}), \
    "trolllager":    ({"trollager",     "Trollager",      "ins",  "im"}), \
    "trollen":       ({"trollager",     "Trollager",      "ins",  "im"}), \
    "fischerdorf":   ({"fischerdorf",   "Fischerdorf",    "ins",  "im"}), \
    "sternenwald":   ({"sternenwald",   "Sternenwald",    "zum",  "im"}) \
  ])
