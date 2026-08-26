// Petrarch
// Merentha Lib 1.0

#include <std.h>
inherit BAR;

void create() {
::create();
  set_short("Enkidu's Bar");
  set_long("This is the main eatery of the courtyard.  All types of \
food and drink are sold here for people passing through.");
  set_smells((["default":"The smell of food fills the air."]));
  set_items(([
"food":"There are many types of food here.",
"drink":"There are several jugs of different drinks here.",
]));
  set_exits((["north":"/domains/Cabeiri/square"]));
  set_currency("gold");
  set_menu(([
"foods":([
  "steak":([
            "strength":10,
            "name":"steak",
            "short":"a juicy steak dinner",
            "long":"The steak is well done.  It is covered in mushrooms.",
            "id":({"steak", "steak dinner"}),
            "weight":1,
          ]),
  "salad":([
            "strength":8,
            "name":"salad",
            "short":"a fresh green salad",
            "long":"The salad has lettuce, tomatoes and celery in it.",
            "id":({"salad", "green salad", "fresh salad", "fresh green salad"}),
            "weight":1,
          ]),
       ]),
"drinks":([
  "water":([
            "strength":2,
            "name":"water",
            "short":"a skin of water",
            "long":"This is a leather skin filled with water.",
            "id":({"water", "skin", "skin of water"}),
            "weight":1,
          ]),
  "juice":([
            "strength":4,
            "name":"juice",
            "short":"a skin of juice",
            "long":"This is a leather skin full of apple juice.",
            "id":({"juice", "apple juice"}),
            "weight":1,
          ]),
       ])
]));

}

