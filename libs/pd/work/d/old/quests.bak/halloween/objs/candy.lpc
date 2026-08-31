// The candy you will get for halloween....

#include <std.h>
#include <halloween.h>

inherit FOOD;

mapping candys = 
 ([ "a peice of watermelon candy" : 
     ([ "id":({"watermelon candy"}),
        "long": "The peice of watermelon candy looks delicious."
      ]),  
    "a bag of M&M's" :
     ([ "id":({"m&m's", "m&ms", "bag of m&m's", "bag of m&ms", "bag" }),
        "long": "The candy that melts in your mouth, not in your hand."
     ]),
    "a huge chocolate bar" :
     ([ "id":({"chocolate bar", "huge chocolate bar", "bar" }),
        "long": "This chocolate bar was made with the finest cocoa in the land."
     ]),
    "a bag of Skittles" :
     ([ "id": ({"bag of skittles", "skittles", "bag" }),
        "long": "Taste the rainbow."
     ]),
    "a peice of salt water taffy" :
     ([ "id": ({"salt water taffy", "taffy" }),
        "long" : "The salt water taffy screams, \"eat me!!!!\""
     ]),
    "a carmel apple" :
     (["id": ({"carmel apple", "apple"}),
       "long" : "The apple is covered in carmel. mMmMmmmMmm."
     ]),
    "a three musketeers bar" :
     (["id": ({"three musketeers bar", "musketeers bar", "bar" }),
       "long": "The musketeers wonder if your gonna eat it or not."
     ]),
    "a peice of peanut brittle" :
     (["id": ({"peice of peanut brittle", "peanut brittle", "brittle"}),
       "long": "It is a bar with peanuts in it."
     ]),
    "a bag of gummy bears":
     (["id": ({"bag of gummy bears", "gummy bears", "bears", "bag"}),
       "long": "A bag filled with gummy bears. Yummmy!"
     ]),
     "a box of nerds":
     (["id": ({"box of nerds", "box", "nerds"}),
       "long": "A box filled with little nerdies."
     ]),
     "cotton candy":
     (["id": ({"cotton candy"}),
       "long": "The cotton candy is %^MAGENTA%^%^BOLD%^pink%^RESET%^."
     ]),
     "A bag of jelly beans":
     (["id": ({"bag of jelly beans", "jelly beans", "bag"}),
       "long": "The bag is full of different color jelly beans"
     ])
          
 ]);

void create()
{
 int i;
 string *shorts;
set_name("candy");
i = random(sizeof(shorts = keys(candys)));
set_short(shorts[i]);
set_long( candys[ shorts[i] ]["long"] );
set_id( candys[ shorts[i] ]["id"] += ({ "candy" }));
set_weight(1);
set_value(0);
set_strength(5);
set_my_mess("You eat "+query_short()+" and smile.");
set_your_mess("eats "+query_short()+" and smiles.");
}
