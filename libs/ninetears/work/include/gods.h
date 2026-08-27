/* Some stuff to keep track of gods so we can centralize. */
#define GOD_LIST ({"baldrick","leviathan","raisa","taniwha","hokemj",\
                   "cyrcia","radix","ducky","grimbrand","tyrael",\
		"barthleby","ninguna"})
                   
#define GODS   ([  "baldrick" : 1 , "leviathan" : 1 , "raisa" : 2 ,\
                   "taniwha" : 1 , "hokemj" : 1 , "cyrcia" : 2 ,\
                   "radix" : 1 , "ducky" : 1, "grimbrand" : 1 ,\
                   "tyrael" : 1, "barthleby" : 1, "ninguna" : 1\
               ])

/* Things that may be sacrificed to a given god. */
/* NOTE TO ME:  make corpses good/evil/neutral */
/*              same with decrapitated heads */
/*              Add FOOD as a choice          */
/* Taniwha, hokemj should include FOOD later */
#define SAC_ITEMS ([  "baldrick"  : ({ "armours", "weapons", "items", "money",\
                                       "corpses", "experience" })\
                    , "leviathan"    : ({ "weapons", "armours" })\
                    , "raisa"     : ({ "money", "corpses" })\
                    , "taniwha"   : ({ "weapons", "items" })\
                    , "hokemj"    : ({ "items", "money" })\
                    , "cyrcia"    : ({ "corpses", "items" })\
                    , "radix"    : ({ "items", "money" })\
                    , "ducky"     : ({ "corpses", "experience", "money" })\
                    , "grimbrand" : ({ "corpses", "weapons" })\
                    , "tyrael"    : ({ "weapons", "items", "corpses", "experience" })\
                    , "barthleby"    : ({ "weapons", "armours", "items", "money", "experience" })\
                    , "ninguna"      : ({ })\
                  ])

/* Need to have a list of races to index on in some code. */
#define RACES ({"drow","duergar","enano","elfo","gnomo","goblin","halfling",\
 "medio-elfo","medio-orco","humano","hombre-lagarto","orco","duck"})
                
/* gods each race is allowed to worship along with the 'sacrifice modifier'
   associated (it's a percent).
*/                  
#define ALLOWED_GODS ([  "drow"       : ({ "cyrcia", 125, "radix", 75,     \
                                           "ducky", 100, "tyrael", 125 }) \
                       , "duergar"    : ({ "grimbrand", 125, "ducky", 100, \
                                           "cyrcia", 75, "tyrael", 100 }) \
                       , "enano"      : ({ "raisa", 125, "leviathan", 90, \
                                           "taniwha", 90, "ducky", 75, \
					"barthleby", 100 }) \
                       , "elfo"        : ({ "hokemj", 125, "taniwha", 90, \
                                           "radix", 90, "ducky", 75, \
					"barthleby", 110 }) \
                       , "gnomo"      : ({ "taniwha", 125, "raisa", 95, \
                                           "barthleby", 110 }) \
                       , "goblin"     : ({ "ducky", 125, "grimbrand", 90,  \
                                           "cyrcia", 75, "tyrael", 90 }) \
                       , "halfling"   : ({ "radix", 125, "hokemj", 90,     \
                                           "barthleby", 100 }) \
                       , "medio-elfo"   : ({ "taniwha", 105, "hokemj", 95, \
                                           "barthleby", 110, "raisa", 85, \
                                           "leviathan", 90, "ducky", 100 })   \
                       , "medio-orco"   : ({ "leviathan", 110, "grimbrand", 90, \
                                           "ducky", 110, "tyrael", 100 }) \
                       , "humano"      : ({ "barthleby", 125, "taniwha", 100,\
                                           "ducky", 100, "leviathan", 100,    \
                                           "radix", 100, "raisa", 100,     \
                                           "hokemj", 100, "grimbrand", 100,\
                                           "tyrael", 75 }) \
                       , "hombre-lagarto" : ({ "tyrael", 100, "leviathan", 90, \
                                           "radix", 90, "ducky", 75 })     \
                       , "orco"        : ({ "ducky", 125, "grimbrand", 80, \
                                           "tyrael", 110 }) \
                       , "duck"       : ({ "baldrick", 100, "taniwha", 100,\
                                           "ducky", 150, "leviathan", 100,    \
                                           "radix", 100, "raisa", 100,     \
                                           "hokemj", 75, "grimbrand", 100, \
                                           "cyrcia", 75 })                 \
                       , "skaven"     : ({ "cyrcia", 50, "grimbrand", 50,  \
                                           "ducky", 100 })                 \
                       , "chicken"    : ({ "radix", 150 })                 \
                       , "medio-drow"  : ({ "radix", 130 , "cyrcia", 75 }) \
                       , "ilythiiri"  : ({ "cyrcia", 100,"grimbrand", 100, \
                                           "radix", 80 })                  \
                       , "varniad"    : ({ "taniwha", 150 })               \
                       , "celery"     : ({ "taniwha", 100, "baldrick", 100,\
                                           "radix", 120 })                 \
                       , "kender"     : ({ "baldrick", 100, "bivins",150,  \
                                           "taniwha",80,"radix",120 })     \
                       , "newt"       : ({ "baldrick", 150,"taniwha",150,  \
                                           "raisa",100})                   \
                       , "frog"       : ({ "raisa", 150,"leviathan",100,      \
                                           "taniwha",90,"radix",100})      \
                       , "troll"      : ({ "baldrick", 50,"cyrcia",75,     \
                                           "bivins", 50, "grimbrand", 100})\
                       , "vampire"    : ({ "ducky", 150,"grimbrand",100,   \
                                           "cyrcia", 100})                 \
                       , "giant"      : ({ "leviathan", 80,"baldrick", 100,   \
                                           "radix", 100,"grimbrand", 50})  \
                     ])

/* This is the multiplier that gets done to the sacrifice value when it's
   being sent to adjust_god_status().  Taniwha understands.
*/                     
#define STATUS_MULT 2
