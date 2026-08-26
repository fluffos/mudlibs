// human - large and fairly cheap
// rat   - small and cheap
// cat   - medium size, but rather expensive
// dog   - medium size and fairly cheap
#define SKIN_MAP ([ "human" : 1000, \
                    "rat"   : 30, \
                    "cat"   : 1000, \
                    "dog"   : 800, \
                    ])

/* type : ({ scraping difficulty, hair amount, tanning difficulty }) */
#define SKIN_TYPES ([ "pelt"    : ({ 3, 3, 3 }), \
                      "fur"     : ({ 4, 4, 3 }), \
                      "skin"    : ({ 2, 1, 2 }), \
                      "hide"    : ({ 4, 3, 3 }), \
                      ])
#define S_SCRAPE 0
#define S_HAIR   1
#define S_TAN    2

#define YOLK_AMOUNT_MOD 15

#define SKIN_OBJ "/obj/misc/skin"
