// a maze in a small 5x5x5 cube
// made by magictcs using vmaster - 2 may 97
// nice vmaster - a maze in a single file :))
// not all rooms has to defined! (but they are defined here)
// prepared for 5x5x5

#include "cube.h"

inherit "/obj/vmaster";

create() {
  ::create(1);
  // ******************
  // first floor (z==1)
  // ******************
  AddObject("cuberoom"+111,CUBEROOM, ({
    ([ P_INT_SHORT: "The lower southwest room of the cube",
       P_INT_LONG:  "You are standing in the lowest southwest room of the "
                    "cube. A way leads north, another east.\n",
    ]), 
    ({  "AddExit","east", CUBEROOM+211 }),
    ({  "AddExit","north",CUBEROOM+121 }) }) );

  AddObject(CUBEROOM+121,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  "This is another small room of the cube.\n",
    ]), 
    ({ "AddExit","south",CUBEROOM+111 }),
    ({ "AddExit","up",   CUBEROOM+122 }) }) );

  AddObject(CUBEROOM+131,CUBEROOM, ({
    ([ P_INT_SHORT: "Another small room",
       P_INT_LONG:  "This is another small room of the cube.\n",
    ]),
    ({ "AddExit","north",CUBEROOM+141}) }) );

  AddObject(CUBEROOM+141,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+131}),
    ({ "AddExit","north",CUBEROOM+151}) }) );

  AddObject(CUBEROOM+151,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  "Another .\n",
    ]),
    ({ "AddExit","south",CUBEROOM+141}),
    ({ "AddExit","east", CUBEROOM+251}),
    ({ "AddExit","up",   CUBEROOM+152}) }) );

  AddObject(CUBEROOM+211,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  "This room has another way leading up.\n",
    ]),
    ({ "AddExit","west", CUBEROOM+111}),
    ({ "AddExit","east", CUBEROOM+311}),
    ({ "AddExit","north",CUBEROOM+221}),
    ({ "AddExit","up",   CUBEROOM+212}),
    ({ "AddExit","south",CUBE("entrance") }) }) );

  AddObject(CUBEROOM+221,CUBEROOM, ({
    ([ P_INT_SHORT: "A empty room",
       P_INT_LONG:  "A complete empty room - maybe the wizard who created "
                    "this room forgot something?\n",
       P_DETAILS:   (["wizard":"Had to be a crazy wizard!\n",
                      "something":"The wizard forgot many things to do here!\n"
                    ])
    ]),
    ({ "AddExit","south",CUBEROOM+211}),
    ({ "AddExit","north",CUBEROOM+231}) }) );

  AddObject(CUBEROOM+231,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+221}),
    ({ "AddExit","north",CUBEROOM+241}) }));

  AddObject(CUBEROOM+241,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+231}),
    ({ "AddExit","east", CUBEROOM+341}),
    ({ "AddExit","up",   CUBEROOM+242}) }) );

  AddObject(CUBEROOM+251,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+151}) }) );

  AddObject(CUBEROOM+311,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+211}),
    ({ "AddExit","east",CUBEROOM+411}) }) );

  AddObject(CUBEROOM+321,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+322}),
    ({ "AddExit","east",CUBEROOM+421}) }) );

  AddObject(CUBEROOM+331,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+332}),
    ({ "AddExit","east",CUBEROOM+431}) }) );

  AddObject(CUBEROOM+341,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+241}) }) );

  AddObject(CUBEROOM+351,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","east",CUBEROOM+451}) }) );

  AddObject(CUBEROOM+411,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+311}),
    ({ "AddExit","east",CUBEROOM+511}) }) );

  AddObject(CUBEROOM+421,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]), 
    ({ "AddExit","west", CUBEROOM+321}),
    ({ "AddExit","north",CUBEROOM+431}) }) );

  AddObject(CUBEROOM+431,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+421}),
    ({ "AddExit","west", CUBEROOM+331}) }) );

  AddObject(CUBEROOM+441,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","east",CUBEROOM+541}) }) );

  AddObject(CUBEROOM+451,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+351}),
    ({ "AddExit","east",CUBEROOM+551}) }) );

  AddObject(CUBEROOM+511,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+411}),
    ({ "AddExit","up",  CUBEROOM+512}) }) );

  AddObject(CUBEROOM+521,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",   CUBEROOM+522}),
    ({ "AddExit","north",CUBEROOM+531}) }) );

  AddObject(CUBEROOM+531,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+521}) }) );

  AddObject(CUBEROOM+541,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west", CUBEROOM+441}),
    ({ "AddExit","north",CUBEROOM+551}) }) );

  AddObject(CUBEROOM+551,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the first floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west", CUBEROOM+451}),
    ({ "AddExit","south",CUBEROOM+541}),
    ({ "AddExit","up",   CUBEROOM+552}) }) );

  // *******************
  // second floor (z==2)
  // *******************
  AddObject(CUBEROOM+112,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
       P_ITEMS:     ({({"/obj/torch",1})})
    ]), 
    ({ "AddExit","up",CUBEROOM+113}) }) );

  AddObject(CUBEROOM+122,CUBEROOM, ({
    ([ P_INT_SHORT: "A simple room in the second floor",
       P_INT_LONG:  "Only two ways lead out of this room.\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+123}),
    ({ "AddExit","down",CUBEROOM+121}),
    ({ "AddExit","east",CUBEROOM+222}) }) );

  AddObject(CUBEROOM+132,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+133}),
    ({ "AddExit","east",CUBEROOM+232}) }) );

  AddObject(CUBEROOM+142,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",CUBEROOM+143}) }) );

  AddObject(CUBEROOM+152,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+153}),
    ({ "AddExit","down",CUBEROOM+151}),
    ({ "AddExit","east",CUBEROOM+252}) }) );

  AddObject(CUBEROOM+212,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+213}),
    ({ "AddExit","down",CUBEROOM+211}) }) );

  AddObject(CUBEROOM+222,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","up",  CUBEROOM+223}),
    ({ "AddExit","west",CUBEROOM+122}),
    ({ "AddExit","east",CUBEROOM+322}) }) );

  AddObject(CUBEROOM+232,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west", CUBEROOM+132}),
    ({ "AddExit","north",CUBEROOM+242}) }) );

  AddObject(CUBEROOM+242,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+232}),
    ({ "AddExit","up",   CUBEROOM+243}) }) );

  AddObject(CUBEROOM+252,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+152}) }) );

  AddObject(CUBEROOM+312,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","east",CUBEROOM+412}) }) );

  AddObject(CUBEROOM+322,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west",CUBEROOM+222}),
    ({ "AddExit","east",CUBEROOM+422}),
    ({ "AddExit","down",CUBEROOM+321}) }) );

  AddObject(CUBEROOM+332,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","down", CUBEROOM+331}),
    ({ "AddExit","north",CUBEROOM+342}) }) );

  AddObject(CUBEROOM+342,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+332}),
    ({ "AddExit","north",CUBEROOM+352}) }) );

  AddObject(CUBEROOM+352,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","south",CUBEROOM+342}),
    ({ "AddExit","east", CUBEROOM+452}) }) );

  AddObject(CUBEROOM+412,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","north",CUBEROOM+422}),
    ({ "AddExit","west", CUBEROOM+312}) }) );

  AddObject(CUBEROOM+422,CUBEROOM, ({
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ]),
    ({ "AddExit","west", CUBEROOM+322}),
    ({ "AddExit","south",CUBEROOM+412}) }) );

/****** xxxxx
  AddRoom("cubemaze",({4,3,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,3,2}),"north",({4,4,2}));

  AddRoom("cubemaze",({4,4,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,4,2}),"up",({4,4,3}));
  AddExit("cubemaze",({4,4,2}),"south",({4,3,2}));

  AddRoom("cubemaze",({4,5,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,5,2}),"west",({3,5,2}));
  AddExit("cubemaze",({4,5,2}),"up",({4,5,3}));

  AddRoom("cubemaze",({5,1,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,1,2}),"down",({5,1,1}));
  AddExit("cubemaze",({5,1,2}),"north",({5,2,2}));

  AddRoom("cubemaze",({5,2,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,2,2}),"south",({5,1,2}));
  AddExit("cubemaze",({5,2,2}),"north",({5,3,2}));
  AddExit("cubemaze",({5,2,2}),"down",({5,2,1}));

  AddRoom("cubemaze",({5,3,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,3,2}),"up",({5,3,3}));
  AddExit("cubemaze",({5,3,2}),"south",({5,2,2}));

  AddRoom("cubemaze",({5,4,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,4,2}),"north",({5,5,2}));

  AddRoom("cubemaze",({5,5,2}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the second floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,5,2}),"up",({5,5,3}));
  AddExit("cubemaze",({5,5,2}),"down",({5,5,1}));
  AddExit("cubemaze",({5,5,2}),"south",({5,4,2}));

  // ******************
  // third floor (z==3)
  // ******************
  AddRoom("cubemaze",({1,1,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,1,3}),"north",({1,2,3}));
  AddExit("cubemaze",({1,1,3}),"down",({1,1,2}));

  AddRoom("cubemaze",({1,2,3}),CUBEROOM,
    ([ P_INT_SHORT: "",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,2,3}),"south",({1,1,3}));
  AddExit("cubemaze",({1,2,3}),"down",({1,2,2}));

  AddRoom("cubemaze",({1,3,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,3,3}),"east",({2,3,3}));
  AddExit("cubemaze",({1,3,3}),"down",({1,3,2}));

  AddRoom("cubemaze",({1,4,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,4,3}),"east",({2,4,3}));
  AddExit("cubemaze",({1,4,3}),"north",({1,5,3}));
  AddExit("cubemaze",({1,4,3}),"down",({1,4,2}));

  AddRoom("cubemaze",({1,5,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,5,3}),"east",({2,5,3}));
  AddExit("cubemaze",({1,5,3}),"south",({1,4,3}));
  AddExit("cubemaze",({1,5,3}),"down",({1,5,2}));

  AddRoom("cubemaze",({2,1,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,1,3}),"east",({3,1,3}));
  AddExit("cubemaze",({2,1,3}),"up",({3,1,4}));
  AddExit("cubemaze",({2,1,3}),"down",({3,1,2}));

  AddRoom("cubemaze",({2,2,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,2,3}),"down",({2,2,2}));

  AddRoom("cubemaze",({2,3,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,3,3}),"west",({1,3,3}));
  AddExit("cubemaze",({2,3,3}),"up",({2,3,4}));

  AddRoom("cubemaze",({2,4,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,4,3}),"west",({1,4,3}));
  AddExit("cubemaze",({2,4,3}),"north",({2,5,3}));

  AddRoom("cubemaze",({2,5,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,5,3}),"west",({1,5,3}));
  AddExit("cubemaze",({2,5,3}),"east",({3,5,3}));
  AddExit("cubemaze",({2,5,3}),"south",({2,4,3}));
  AddExit("cubemaze",({2,5,3}),"up",({2,5,4}));

  AddRoom("cubemaze",({3,1,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,1,3}),"west",({2,1,3}));
  AddExit("cubemaze",({3,1,3}),"east",({4,1,3}));

  AddRoom("cubemaze",({3,2,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,2,3}),"up",({3,2,4}));

  AddRoom("cubemaze",({3,3,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,3,3}),"north",({3,4,3}));
  AddExit("cubemaze",({3,3,3}),"up",({3,3,4}));

  AddRoom("cubemaze",({3,4,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,4,3}),"south",({3,3,3}));
  AddExit("cubemaze",({3,4,3}),"up",({3,4,4}));

  AddRoom("cubemaze",({3,5,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,5,3}),"west",({2,5,3}));

  AddRoom("cubemaze",({4,1,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,1,3}),"west",({3,1,3}));
  AddExit("cubemaze",({4,1,3}),"east",({5,1,3}));
  AddExit("cubemaze",({4,1,3}),"up",({4,1,4}));

  AddRoom("cubemaze",({4,2,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,2,3}),"east",({5,2,3}));

  AddRoom("cubemaze",({4,3,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,3,3}),"north",({4,4,3}));

  AddRoom("cubemaze",({4,4,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,4,3}),"south",({4,3,3}));
  AddExit("cubemaze",({4,4,3}),"up",({4,4,4}));
  AddExit("cubemaze",({4,4,3}),"down",({4,4,2}));

  AddRoom("cubemaze",({4,5,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,5,3}),"down",({4,5,2}));
  AddExit("cubemaze",({4,5,3}),"east",({5,5,3}));

  AddRoom("cubemaze",({5,1,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,1,3}),"west",({4,1,3}));
  AddExit("cubemaze",({5,1,3}),"up",({5,1,3}));

  AddRoom("cubemaze",({5,2,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,2,3}),"west",({4,2,3}));
  AddExit("cubemaze",({5,2,3}),"north",({5,3,3}));

  AddRoom("cubemaze",({5,3,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,3,3}),"south",({5,2,3}));
  AddExit("cubemaze",({5,3,3}),"north",({5,4,3}));
  AddExit("cubemaze",({5,3,3}),"down",({5,3,2}));

  AddRoom("cubemaze",({5,4,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,4,3}),"south",({5,3,3}));
  AddExit("cubemaze",({5,4,3}),"up",({5,4,4}));

  AddRoom("cubemaze",({5,5,3}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the third floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,5,3}),"west",({5,4,3}));
  AddExit("cubemaze",({5,5,3}),"down",({5,5,2}));


  // *******************
  // fourth floor (z==4)
  // *******************
  AddRoom("cubemaze",({1,1,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,1,4}),"up",({1,1,5}));
  AddExit("cubemaze",({1,1,4}),"north",({1,2,4}));

  AddRoom("cubemaze",({1,2,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,2,4}),"south",({1,1,4}));
  AddExit("cubemaze",({1,2,4}),"east",({2,2,4}));

  AddRoom("cubemaze",({1,3,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,3,4}),"up",({1,3,5}));

  AddRoom("cubemaze",({1,4,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,4,4}),"north",({1,5,4}));
  AddExit("cubemaze",({1,4,4}),"east",({2,4,4}));

  AddRoom("cubemaze",({1,5,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,5,4}),"up",({1,5,5}));
  AddExit("cubemaze",({1,5,4}),"south",({1,4,4}));

  AddRoom("cubemaze",({2,1,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,1,4}),"down",({2,1,3}));

  AddRoom("cubemaze",({2,2,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,2,4}),"west",({1,2,4}));
  AddExit("cubemaze",({2,2,4}),"north",({2,3,4}));
  AddExit("cubemaze",({2,2,4}),"up",({2,2,5}));

  AddRoom("cubemaze",({2,3,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,3,4}),"up",({2,3,5}));
  AddExit("cubemaze",({2,3,4}),"down",({2,3,3}));
  AddExit("cubemaze",({2,3,4}),"south",({2,2,4}));

  AddRoom("cubemaze",({2,4,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,4,4}),"west",({1,4,4}));

  AddRoom("cubemaze",({2,5,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,5,4}),"east",({3,5,4}));
  AddExit("cubemaze",({2,5,4}),"down",({2,5,3}));

  AddRoom("cubemaze",({3,1,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,1,4}),"north",({3,2,4}));

  AddRoom("cubemaze",({3,2,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,2,4}),"up",({3,2,5}));
  AddExit("cubemaze",({3,2,4}),"down",({3,2,3}));
  AddExit("cubemaze",({3,2,4}),"south",({3,1,4}));

  AddRoom("cubemaze",({3,3,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,3,4}),"down",({3,3,3}));
  AddExit("cubemaze",({3,3,4}),"east",({4,3,4}));

  AddRoom("cubemaze",({3,4,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,4,4}),"down",({3,4,3}));
  AddExit("cubemaze",({3,4,4}),"north",({3,5,4}));

  AddRoom("cubemaze",({3,5,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,5,4}),"west",({2,5,4}));
  AddExit("cubemaze",({3,5,4}),"south",({3,4,4}));

  AddRoom("cubemaze",({4,1,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,1,4}),"up",({4,1,5}));
  AddExit("cubemaze",({4,1,4}),"down",({4,1,3}));
  AddExit("cubemaze",({4,1,4}),"north",({4,2,4}));

  AddRoom("cubemaze",({4,2,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,2,4}),"north",({4,3,4}));
  AddExit("cubemaze",({4,2,4}),"south",({4,1,4}));

  AddRoom("cubemaze",({4,3,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,3,4}),"west",({3,3,4}));
  AddExit("cubemaze",({4,3,4}),"south",({4,2,4}));

  AddRoom("cubemaze",({4,4,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,4,4}),"up",({4,4,5}));
  AddExit("cubemaze",({4,4,4}),"down",({4,4,3}));
  AddExit("cubemaze",({4,4,4}),"north",({4,5,4}));

  AddRoom("cubemaze",({4,5,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,5,4}),"up",({4,5,5}));
  AddExit("cubemaze",({4,5,4}),"down",({4,5,3}));
  AddExit("cubemaze",({4,5,4}),"south",({4,4,4}));

  AddRoom("cubemaze",({5,1,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,1,4}),"up",({5,1,5}));
  AddExit("cubemaze",({5,1,4}),"down",({5,1,3}));

  AddRoom("cubemaze",({5,2,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,2,4}),"up",({5,2,5}));
  AddExit("cubemaze",({5,2,4}),"north",({5,3,4}));

  AddRoom("cubemaze",({5,3,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,3,4}),"north",({5,4,4}));
  AddExit("cubemaze",({5,3,4}),"south",({5,2,4}));

  AddRoom("cubemaze",({5,4,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,4,4}),"down",({5,4,3}));
  AddExit("cubemaze",({5,4,4}),"south",({5,3,4}));

  AddRoom("cubemaze",({5,5,4}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 4th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,5,4}),"west",({4,5,4}));
  AddExit("cubemaze",({5,5,4}),"up",({5,5,5}));


  // ********************
  // the 5th floor (z==5)
  // ********************
  AddRoom("cubemaze",({1,1,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,1,5}),"east",({2,1,5}));
  AddExit("cubemaze",({1,1,5}),"down",({1,1,4}));

  AddRoom("cubemaze",({1,2,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,2,5}),"north",({1,3,5}));

  AddRoom("cubemaze",({1,3,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,3,5}),"north",({1,4,5}));
  AddExit("cubemaze",({1,3,5}),"south",({1,2,5}));
  AddExit("cubemaze",({1,3,5}),"down",({1,3,4}));

  AddRoom("cubemaze",({1,4,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,4,5}),"north",({1,5,5}));
  AddExit("cubemaze",({1,4,5}),"south",({1,3,5}));

  AddRoom("cubemaze",({1,5,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({1,5,5}),"east",({2,5,5}));
  AddExit("cubemaze",({1,5,5}),"south",({1,4,5}));
  AddExit("cubemaze",({1,5,5}),"down",({1,5,4}));

  AddRoom("cubemaze",({2,1,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,1,5}),"west",({1,1,5}));
  AddExit("cubemaze",({2,1,5}),"north",({2,2,5}));

  AddRoom("cubemaze",({2,2,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,2,5}),"down",({2,2,4}));
  AddExit("cubemaze",({2,2,5}),"south",({2,1,5}));

  AddRoom("cubemaze",({2,3,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,3,5}),"down",({2,3,4}));
  AddExit("cubemaze",({2,3,5}),"north",({2,4,5}));

  AddRoom("cubemaze",({2,4,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,4,5}),"east",({3,4,5}));
  AddExit("cubemaze",({2,4,5}),"south",({2,3,5}));

  AddRoom("cubemaze",({2,5,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({2,5,5}),"west",({1,5,5}));
  AddExit("cubemaze",({2,5,5}),"east",({3,5,5}));

  AddRoom("cubemaze",({3,1,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,1,5}),"east",({4,1,5}));

  AddRoom("cubemaze",({3,2,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,2,5}),"down",({3,2,4}));
  AddExit("cubemaze",({3,2,5}),"north",({3,3,5}));

  AddRoom("cubemaze",({3,3,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,3,5}),"east",({4,3,5}));
  AddExit("cubemaze",({3,3,5}),"south",({3,2,5}));

  AddRoom("cubemaze",({3,4,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,4,5}),"west",({2,4,5}));
  AddExit("cubemaze",({3,4,5}),"north",({3,5,5}));

  AddRoom("cubemaze",({3,5,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({3,5,5}),"south",({3,4,5}));
  AddExit("cubemaze",({3,5,5}),"west",({2,5,5}));

  AddRoom("cubemaze",({4,1,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,1,5}),"west",({3,1,5}));
  AddExit("cubemaze",({4,1,5}),"down",({4,1,4}));

  AddRoom("cubemaze",({4,2,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,2,5}),"east",({5,2,5}));
  AddExit("cubemaze",({4,2,5}),"north",({4,3,5}));

  AddRoom("cubemaze",({4,3,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,3,5}),"west",({3,3,5}));
  AddExit("cubemaze",({4,3,5}),"east",({5,3,5}));
  AddExit("cubemaze",({4,3,5}),"south",({4,2,5}));

  AddRoom("cubemaze",({4,4,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,4,5}),"north",({4,5,5}));
  AddExit("cubemaze",({4,4,5}),"down",({4,4,4}));

  AddRoom("cubemaze",({4,5,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({4,5,5}),"down",({4,5,4}));
  AddExit("cubemaze",({4,5,5}),"south",({4,4,5}));

  AddRoom("cubemaze",({5,1,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,1,5}),"down",({5,1,4}));

  AddRoom("cubemaze",({5,2,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,2,5}),"north",({5,3,5}));
  AddExit("cubemaze",({5,2,5}),"west",({4,2,5}));
  AddExit("cubemaze",({5,2,5}),"down",({5,2,4}));

  AddRoom("cubemaze",({5,3,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,3,5}),"west",({4,3,5}));
  AddExit("cubemaze",({5,3,5}),"south",({5,2,5}));

  AddRoom("cubemaze",({5,4,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,4,5}),"north",({5,5,5}));

  AddRoom("cubemaze",({5,5,5}),CUBEROOM,
    ([ P_INT_SHORT: "A room in the 5th floor",
       P_INT_LONG:  ".\n",
    ])   );
  AddExit("cubemaze",({5,5,5}),"south",({5,4,5}));
  AddExit("cubemaze",({5,5,5}),"down",({5,5,4}));
*/
}

