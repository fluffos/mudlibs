/* Some stuff to keep track of gods so we can centralize. */
#define GOD_LIST ({"baldrick","timion","raisa","taniwha","hokemj",\
                   "cyrcia","radix","ducky","grimbrand","none"})
                   
#define GODS   ([  "baldrick" : 1 , "timion" : 1 , "raisa" : 2 ,\
                   "taniwha" : 1 , "hokemj" : 1 , "cyrcia" : 2 ,\
                   "radix" : 1 , "ducky" : 1, "grimbrand" : 1 ,\
                   "none" : 1\
               ])

/* Things that may be sacrificed to a given god. */
/* NOTE TO ME:  make corpses good/evil/neutral */
/*              same with decrapitated heads */
/*              Add FOOD as a choice          */
/* Taniwha, hokemj should include FOOD later */
#define SAC_ITEMS ([  "baldrick"  : ({ "armours", "weapons", "items", "money",\
                                       "corpses", "experience" })\
                    , "timion"    : ({ "weapons", "armours" })\
                    , "raisa"     : ({ "money", "corpses" })\
                    , "taniwha"   : ({ "weapons", "items" })\
                    , "hokemj"    : ({ "items", "money" })\
                    , "cyrcia"    : ({ "corpses", "items" })\
                    , "radix"    : ({ "items", "money" })\
                    , "ducky"     : ({ "corpses", "experience", "money" })\
                    , "grimbrand" : ({ "corpses", "weapons" })\
                    , "none"      : ({ })\
                  ])

/* Need to have a list of races to index on in some code. */
#define RACES ({"drow","duergar","dwarf","elf","gnome","goblin","halfling",\
                "half-elf","half-orc","human","lizard-man","orc","duck"})
                
/* gods each race is allowed to worship along with the 'sacrifice modifier'
   associated (it's a percent).
*/                  
#define ALLOWED_GODS ([  "drow"       : ({ "cyrcia", 125, "radix", 75,     \
                                           "ducky", 100 })                 \
                       , "duergar"    : ({ "grimbrand", 125, "ducky", 100, \
                                           "cyrcia", 75 })                 \
                       , "dwarf"      : ({ "raisa", 125, "timion", 90,     \
                                           "taniwha", 90, "ducky", 75 })   \
                       , "elf"        : ({ "hokemj", 125, "taniwha", 90,   \
                                           "radix", 90, "ducky", 75 })     \
                       , "gnome"      : ({ "taniwha", 125, "raisa", 95,    \
                                           "baldrick", 90 })               \
                       , "goblin"     : ({ "ducky", 125, "grimbrand", 90,  \
                                           "cyrcia", 75 })                 \
                       , "halfling"   : ({ "radix", 125, "hokemj", 90,     \
                                           "baldrick", 90 })               \
                       , "half-elf"   : ({ "taniwha", 105, "hokemj", 95,   \
                                           "baldrick", 95, "raisa", 85,    \
                                           "timion", 90, "ducky", 100 })   \
                       , "half-orc"   : ({ "timion", 110, "grimbrand", 90, \
                                           "ducky", 110, "baldrick", 95 }) \
                       , "human"      : ({ "baldrick", 100, "taniwha", 100,\
                                           "ducky", 100, "timion", 100,    \
                                           "radix", 100, "raisa", 100,     \
                                           "hokemj", 100, "grimbrand", 100,\
                                           "cyrcia", 75 })                 \
                       , "lizard-man" : ({ "baldrick", 120, "timion", 90,  \
                                           "radix", 90, "ducky", 75 })     \
                       , "orc"        : ({ "ducky", 125, "grimbrand", 80,  \
                                           "cyrcia", 75 })                 \
                       , "duck"       : ({ "baldrick", 100, "taniwha", 100,\
                                           "ducky", 150, "timion", 100,    \
                                           "radix", 100, "raisa", 100,     \
                                           "hokemj", 75, "grimbrand", 100, \
                                           "cyrcia", 75 })                 \
                       , "skaven"     : ({ "cyrcia", 50, "grimbrand", 50,  \
                                           "ducky", 100 })                 \
                       , "chicken"    : ({ "radix", 150 })                 \
                       , "half-drow"  : ({ "radix", 130 , "cyrcia", 75 })  \
                       , "ilythiiri"  : ({ "cyrcia", 100,"grimbrand", 100, \
                                           "radix", 80 })                  \
                       , "varniad"    : ({ "taniwha", 150 })               \
                       , "celery"     : ({ "taniwha", 100, "baldrick", 100,\
                                           "radix", 120 })                 \
                       , "kender"     : ({ "baldrick", 100, "bivins",150,  \
                                           "taniwha",80,"radix",120 })     \
                       , "newt"       : ({ "baldrick", 150,"taniwha",150,  \
                                           "raisa",100})                   \
                       , "frog"       : ({ "raisa", 150,"timion",100,      \
                                           "taniwha",90,"radix",100})      \
                       , "troll"      : ({ "baldrick", 50,"cyrcia",75,     \
                                           "bivins", 50, "grimbrand", 100})\
                       , "vampire"    : ({ "ducky", 150,"grimbrand",100,   \
                                           "cyrcia", 100})                 \
                       , "giant"      : ({ "timion", 80,"baldrick", 100,   \
                                           "radix", 100,"grimbrand", 50})  \
                     ])

/* This is the multiplier that gets done to the sacrifice value when it's
   being sent to adjust_god_status().  Taniwha understands.
*/                     
#define STATUS_MULT 2
