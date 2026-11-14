// made by magictcs using vmaster - 10 aug 97
// very easy to create a large sea with many rooms :)

#include "sea.h"

inherit "/obj/vmaster";

create() {
  ::create(1);
  //********************
  // the beach (4 rooms)
  //********************
// TODO: change the long descriptions a little bit!!!
  // room: beach1
  AddObject(BEACH+1,BEACH, ({
    ([ P_INT_LONG:  "This is a part of a north-south beach. To the west lies "
                    "a huge sea, The whole sea is under the earth in a very "
                    "large grotto.\n",
    ]),
    ({  "AddExit","south",BEACH+2}),
    ({  "AddExit","west",SEA+82}) }) );
  // room: beach2
  AddObject(BEACH+2,BEACH, ({
    ([ P_INT_LONG:  "This is a part of a north-south beach. To the west lies "
                    "a large sea, The whole sea is under the earth in a very "
                    "large grotto.\n",
    ]),
    ({  "AddExit","north",BEACH+1}),
    ({  "AddExit","south",BEACH+3}),
    ({  "AddExit","west",SEA+83}) }) );
  // room: beach3
  AddObject(BEACH+3,BEACH, ({
    ([ P_INT_LONG:  "This is a part of a north-south beach. To the west lies "
                    "a large sea, The whole sea is under the earth in a very "
                    "large grotto.\n",
    ]),
    ({  "AddExit","north",BEACH+2}),
    ({  "AddExit","south",BEACH+4}),
    ({  "AddExit","west",SEA+84}) }) );
  // room: beach4
  AddObject(BEACH+4,BEACH, ({
    ([ P_INT_LONG:  "This is a part of a north-south beach. To the west lies "
                    "a large sea, The whole sea is under the earth in a very "
                    "large grotto.\n",
    ]),
    ({  "AddExit","north",BEACH+3}),
    ({  "AddExit","west",SEA+85}) }) );


  //*************************
  // the sea (over the water)
  //*************************
// TODO: update P_INT_LONG of the sea rooms
  // column 8
  // x=8, y=2..6
  // room: sea82
  AddObject(SEA+82,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "AddExit","west",SEA+72}),
    ({  "AddExit","south",SEA+83}),
    ({  "AddExit","east",BEACH+1}) }) );
  // room: sea83
  AddObject(SEA+83,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "AddExit","west",SEA+73}),
    ({  "AddExit","north",SEA+82}),
    ({  "AddExit","south",SEA+84}),
    ({  "AddExit","east",BEACH+2}) }) );
  // room: sea84
  AddObject(SEA+84,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "AddExit","west",SEA+74}),
    ({  "AddExit","north",SEA+83}),
    ({  "AddExit","south",SEA+85}),
    ({  "AddExit","east",BEACH+3}) }) );
  // room: sea85
  AddObject(SEA+85,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "AddExit","west",SEA+75}),
    ({  "AddExit","north",SEA+84}),
    ({  "AddExit","south",SEA+86}),
    ({  "AddExit","east",BEACH+4}) }) );
  // room: sea86
  AddObject(SEA+86,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "AddExit","west",SEA+76}),
    ({  "AddExit","north",SEA+85}) }) );

  // column 7
  // x=7, y=1..8
  // room: sea71
  AddObject(SEA+71,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+71}),
    ({  "AddExit","south",SEA+72}) }) );
  // room: sea72
  AddObject(SEA+72,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+72}),
    ({  "AddExit","west",SEA+62}),
    ({  "AddExit","north",SEA+71}),
    ({  "AddExit","east",SEA+82}),
    ({  "AddExit","south",SEA+73}) }) );
  // room: sea73
  AddObject(SEA+73,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+73}),
    ({  "AddExit","west",SEA+63}),
    ({  "AddExit","north",SEA+72}),
    ({  "AddExit","east",SEA+83}),
    ({  "AddExit","south",SEA+74}) }) );
  // room: sea74
  AddObject(SEA+74,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+74}),
    ({  "AddExit","west",SEA+64}),
    ({  "AddExit","north",SEA+73}),
    ({  "AddExit","east",SEA+84}),
    ({  "AddExit","south",SEA+75}) }) );
  // room: sea75
  AddObject(SEA+75,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+75}),
    ({  "AddExit","west",SEA+65}),
    ({  "AddExit","north",SEA+74}),
    ({  "AddExit","east",SEA+85}),
    ({  "AddExit","south",SEA+76}) }) );
  // room: sea76
  AddObject(SEA+76,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+76}),
    ({  "AddExit","west",SEA+66}),
    ({  "AddExit","north",SEA+75}),
    ({  "AddExit","east",SEA+86}),
    ({  "AddExit","south",SEA+77}) }) );
  // room: sea77
  AddObject(SEA+77,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+77}),
    ({  "AddExit","west",SEA+67}),
    ({  "AddExit","north",SEA+76}),
    ({  "AddExit","south",SEA+78}) }) );
  // room: sea78
  AddObject(SEA+78,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+78}),
    ({  "AddExit","west",SEA+68}),
    ({  "AddExit","north",SEA+77}) }) );

  // column 6
  // x=6, y=2..8
  // room: sea62
  AddObject(SEA+62,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+62}),
    ({  "AddExit","east",SEA+72}),
    ({  "AddExit","south",SEA+63}) }) );
  // room: sea63
  AddObject(SEA+63,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+63}),
    ({  "AddExit","west",SEA+53}),
    ({  "AddExit","north",SEA+62}),
    ({  "AddExit","east",SEA+73}),
    ({  "AddExit","south",SEA+64}) }) );
  // room: sea64
  AddObject(SEA+64,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+64}),
    ({  "AddExit","west",SEA+54}),
    ({  "AddExit","north",SEA+63}),
    ({  "AddExit","east",SEA+74}),
    ({  "AddExit","south",SEA+65}) }) );
  // room: sea65
  AddObject(SEA+65,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+65}),
    ({  "AddExit","west",SEA+55}),
    ({  "AddExit","north",SEA+64}),
    ({  "AddExit","east",SEA+75}),
    ({  "AddExit","south",SEA+66}) }) );
  // room: sea66
  AddObject(SEA+66,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+66}),
    ({  "AddExit","west",SEA+56}),
    ({  "AddExit","north",SEA+65}),
    ({  "AddExit","east",SEA+76}),
    ({  "AddExit","south",SEA+67}) }) );
  // special room - dive to tube to treasure room
  // room: sea67
  AddObject(SEA+67,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+67}),
    ({  "AddExit","west",SEA+57}),
    ({  "AddExit","north",SEA+66}),
    ({  "AddExit","east",SEA+77}),
    ({  "AddExit","south",SEA+68}) }) );
  // room: sea68
  AddObject(SEA+68,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+68}),
    ({  "AddExit","west",SEA+58}),
    ({  "AddExit","north",SEA+67}),
    ({  "AddExit","east",SEA+78}) }) );

  // column 5
  // x=5, y=3..8
  // room: sea53
  AddObject(SEA+53,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+53}),
    ({  "AddExit","west",SEA+43}),
    ({  "AddExit","east",SEA+63}),
    ({  "AddExit","south",SEA+54}) }) );
  // room: sea54
  AddObject(SEA+54,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+54}),
    ({  "AddExit","west",SEA+44}),
    ({  "AddExit","north",SEA+53}),
    ({  "AddExit","east",SEA+64}),
    ({  "AddExit","south",SEA+55}) }) );
  // room: sea55
  AddObject(SEA+55,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+55}),
    ({  "AddExit","west",SEA+45}),
    ({  "AddExit","north",SEA+54}),
    ({  "AddExit","east",SEA+65}),
    ({  "AddExit","south",SEA+56}) }) );
  // room: sea56
  AddObject(SEA+56,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+56}),
    ({  "AddExit","west",SEA+46}),
    ({  "AddExit","north",SEA+55}),
    ({  "AddExit","east",SEA+66}),
    ({  "AddExit","south",SEA+57}) }) );
  // room: sea57
  AddObject(SEA+57,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+57}),
    ({  "AddExit","west",SEA+47}),
    ({  "AddExit","north",SEA+56}),
    ({  "AddExit","east",SEA+67}),
    ({  "AddExit","south",SEA+58}) }) );
  // room: sea58
  AddObject(SEA+58,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+58}),
    ({  "AddExit","north",SEA+57}),
    ({  "AddExit","east",SEA+68}) }) );

  // column 4
  // x=4, y=1..7
  // special room: flow (in)
  // room: sea41
  AddObject(SEA+41,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+41}),
    ({  "AddExit","south",SEA+42}) }) );
  // room: sea42
  AddObject(SEA+42,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+42}),
    ({  "AddExit","west",SEA+32}),
    ({  "AddExit","north",SEA+41}),
    ({  "AddExit","south",SEA+43}) }) );
  // room: sea43
  AddObject(SEA+43,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+43}),
    ({  "AddExit","west",SEA+33}),
    ({  "AddExit","north",SEA+42}),
    ({  "AddExit","east",SEA+53}),
    ({  "AddExit","south",SEA+44}) }) );
  // room: sea44
  AddObject(SEA+44,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+44}),
    ({  "AddExit","west",SEA+34}),
    ({  "AddExit","north",SEA+43}),
    ({  "AddExit","east",SEA+54}),
    ({  "AddExit","south",SEA+45}) }) );
  // room: sea45
  AddObject(SEA+45,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+45}),
    ({  "AddExit","west",SEA+35}),
    ({  "AddExit","north",SEA+44}),
    ({  "AddExit","east",SEA+55}),
    ({  "AddExit","south",SEA+46}) }) );
  // room: sea46
  AddObject(SEA+46,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+46}),
    ({  "AddExit","west",SEA+36}),
    ({  "AddExit","north",SEA+45}),
    ({  "AddExit","east",SEA+56}),
    ({  "AddExit","south",SEA+47}) }) );
  // room: sea47
  AddObject(SEA+47,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+47}),
    ({  "AddExit","west",SEA+37}),
    ({  "AddExit","north",SEA+46}),
    ({  "AddExit","east",SEA+57}) }) );

  // column 3
  // x=3, y=2..7
  // room: sea32
  AddObject(SEA+32,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+32}),
    ({  "AddExit","west",SEA+22}),
    ({  "AddExit","east",SEA+42}),
    ({  "AddExit","south",SEA+33}) }) );
  // room: sea33
  AddObject(SEA+33,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+33}),
    ({  "AddExit","west",SEA+23}),
    ({  "AddExit","north",SEA+32}),
    ({  "AddExit","east",SEA+43}),
    ({  "AddExit","south",SEA+34}) }) );
  // room: sea34
  AddObject(SEA+34,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+34}),
    ({  "AddExit","west",SEA+24}),
    ({  "AddExit","north",SEA+33}),
    ({  "AddExit","east",SEA+44}),
    ({  "AddExit","south",SEA+35}) }) );
  // room: sea35
  AddObject(SEA+35,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+35}),
    ({  "AddExit","west",SEA+25}),
    ({  "AddExit","north",SEA+34}),
    ({  "AddExit","east",SEA+45}),
    ({  "AddExit","south",SEA+36}) }) );
  // room: sea36
  AddObject(SEA+36,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+36}),
    ({  "AddExit","west",SEA+26}),
    ({  "AddExit","north",SEA+35}),
    ({  "AddExit","east",SEA+46}),
    ({  "AddExit","south",SEA+37}) }) );
  // room: sea37
  AddObject(SEA+37,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+37}),
    ({  "AddExit","west",SEA+27}),
    ({  "AddExit","north",SEA+36}),
    ({  "AddExit","east",SEA+47}) }) );

  // column 2
  // x=2, y=1..8
  // room: sea21
  AddObject(SEA+21,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+21}),
    ({  "AddExit","west",SEA+11}),
    ({  "AddExit","south",SEA+22}) }) );
  // room: sea22
  AddObject(SEA+22,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+22}),
    ({  "AddExit","west",SEA+12}),
    ({  "AddExit","north",SEA+21}),
    ({  "AddExit","east",SEA+32}),
    ({  "AddExit","south",SEA+23}) }) );
  // room: sea23
  AddObject(SEA+23,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+23}),
    ({  "AddExit","north",SEA+22}),
    ({  "AddExit","east",SEA+33}),
    ({  "AddExit","south",SEA+24}) }) );
  // room: sea24
  AddObject(SEA+24,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+24}),
    ({  "AddExit","north",SEA+23}),
    ({  "AddExit","east",SEA+34}),
    ({  "AddExit","south",SEA+52}) }) );
  // room: sea25
  AddObject(SEA+25,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+25}),
    ({  "AddExit","north",SEA+24}),
    ({  "AddExit","east",SEA+35}),
    ({  "AddExit","south",SEA+26}) }) );
  // room: sea26
  AddObject(SEA+26,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+26}),
    ({  "AddExit","west",SEA+16}),
    ({  "AddExit","north",SEA+25}),
    ({  "AddExit","east",SEA+36}),
    ({  "AddExit","south",SEA+27}) }) );
  // room: sea27
  AddObject(SEA+27,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+27}),
    ({  "AddExit","west",SEA+17}),
    ({  "AddExit","north",SEA+26}),
    ({  "AddExit","east",SEA+37}),
    ({  "AddExit","south",SEA+28}) }) );
  // room: sea28
  AddObject(SEA+28,SEA, ({
    ([ P_INT_LONG:  "Lost on a large sea.\n",
    ]),
    ({  "SetDown",DIVE+28}),
    ({  "AddExit","west",SEA+18}),
    ({  "AddExit","north",SEA+27}) }) );

  // column 1
  // x=1, y=1,2,6,7,8



  //*******************************
  // the underwater part of the sea
  //*******************************

  //*****************
  // first dive stage
  //*****************

  // column 7
  // x=7, y=1..8
  AddObject(DIVE+72,DIVE, ({
    ({  "SetUp",SEA+72})
    }) );

}
