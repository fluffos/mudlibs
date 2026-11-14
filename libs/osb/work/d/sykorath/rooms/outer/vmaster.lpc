// This object exists only temporarily!
// created by Magictcs - June 98

// This file provides an interface for all non existing rooms
// if the room is not exisiting, this file will check if the room
// is inside it's database and then clone a std-room

#include <properties.h>
#include <sykorath.h>

#define STDROOM      "/d/sykorath/rooms/outer/not_finished"

inherit "/obj/vmaster";

create() {
  ::create(1);
  //*****************************************************************
  // Western Street
  // from 28:60  to  48:60
  //*****************************************************************
  AddObject(OUTER("28x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":28,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("30x60") }) }) );

  AddObject(OUTER("30x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":30,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("32x60") }),
    ({  "AddExit","west",OUTER("28x60") }) }) );
  AddObject(OUTER("32x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":32,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("34x60") }),
    ({  "AddExit","west",OUTER("30x60") }) }) );
  AddObject(OUTER("34x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":34,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("36x60") }),
    ({  "AddExit","west",OUTER("32x60") }) }) );
  AddObject(OUTER("36x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street. Crossing betwen mainstreet "
                   "and orc street.\n",
       "X":36,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("38x60") }),
    ({  "AddExit","south",OUTER("orcstreet1") }),
    ({  "AddExit","west",OUTER("34x60") }) }) );
  AddObject(OUTER("38x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":38,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("40x60") }),
    ({  "AddExit","west",OUTER("36x60") }) }) );
  AddObject(OUTER("40x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":40,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("42x60") }),
    ({  "AddExit","west",OUTER("38x60") }) }) );
  AddObject(OUTER("42x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":42,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("44x60") }),
    ({  "AddExit","north",OUTER("42x58") }),
    ({  "AddExit","west",OUTER("40x60") }) }) );
  AddObject(OUTER("44x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":44,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("46x60") }),
    ({  "AddExit","west",OUTER("42x60") }) }) );
  AddObject(OUTER("46x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":46,
       "Y":60,
    ]),
    ({  "AddExit","east",OUTER("48x60") }),
    ({  "AddExit","west",OUTER("44x60") }) }) );
  AddObject(OUTER("48x60"),STDROOM, ({
    ([ P_INT_LONG: "Part of the western street.\n",
       "X":48,
       "Y":60,
    ]),
    ({  "AddExit","east",INNER("maingate") }),
    ({  "AddExit","west",OUTER("46x60") }) }) );

  //*****************************************************************
  // Eastern Street
  // from 72:58  to  88:58
  //*****************************************************************
  AddObject(OUTER("72x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":72,
       "Y":58,
    ]),
    ({  "AddExit","south",OUTER("72x60") }),
    ({  "AddExit","east",OUTER("74x58") }) }) );
  AddObject(OUTER("74x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":74,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("76x58") }),
    ({  "AddExit","west",OUTER("72x58") }) }) );
  AddObject(OUTER("76x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":76,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("78x58") }),
    ({  "AddExit","north",OUTER("76x56") }),
    ({  "AddExit","west",OUTER("74x58") }) }) );
  AddObject(OUTER("78x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":78,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("80x58") }),
    ({  "AddExit","west",OUTER("76x58") }) }) );
  AddObject(OUTER("80x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":80,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("82x58") }),
    ({  "AddExit","west",OUTER("78x58") }) }) );
  AddObject(OUTER("82x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":82,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("84x58") }),
    ({  "AddExit","west",OUTER("80x58") }) }) );
  AddObject(OUTER("84x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":84,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("86x58") }),
    ({  "AddExit","west",OUTER("82x58") }) }) );
  AddObject(OUTER("86x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":86,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("88x58") }),
    ({  "AddExit","west",OUTER("84x58") }) }) );
  AddObject(OUTER("88x58"),STDROOM, ({
    ([ P_INT_LONG: "Part of the eastern street.\n",
       "X":88,
       "Y":58,
    ]),
    ({  "AddExit","east",OUTER("east_gate") }),
    ({  "AddExit","west",OUTER("86x58") }) }) );


  //*****************************************************************
  // Northern Street
  // from 58:50  to  58:32
  //*****************************************************************
  AddObject(OUTER("58x50"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":50,
    ]),
    ({  "AddExit","north",OUTER("58x48") }) }) );
  AddObject(OUTER("58x48"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":48,
    ]),
    ({  "AddExit","north",OUTER("58x46") }),
    ({  "AddExit","west", OUTER("56x48") }),
    ({  "AddExit","south",OUTER("58x50") }) }) );
  AddObject(OUTER("58x46"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":46,
    ]),
    ({  "AddExit","north",OUTER("58x44") }),
    ({  "AddExit","south",OUTER("58x48") }) }) );
  AddObject(OUTER("58x44"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":44,
    ]),
    ({  "AddExit","north",OUTER("58x42") }),
    ({  "AddExit","east",OUTER("60x44") }),
    ({  "AddExit","south",OUTER("58x46") }) }) );
  AddObject(OUTER("58x42"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":42,
    ]),
    ({  "AddExit","north",OUTER("58x40") }),
    ({  "AddExit","south",OUTER("58x44") }) }) );
  AddObject(OUTER("58x40"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":40,
    ]),
    ({  "AddExit","north",OUTER("58x38") }),
    ({  "AddExit","south",OUTER("58x42") }) }) );
  AddObject(OUTER("58x38"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":38,
    ]),
    ({  "AddExit","north",OUTER("58x36") }),
    ({  "AddExit","south",OUTER("58x40") }) }) );
  AddObject(OUTER("58x36"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":36,
    ]),
    ({  "AddExit","north",OUTER("58x34") }),
    ({  "AddExit","south",OUTER("58x38") }) }) );
  AddObject(OUTER("58x34"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":34,
    ]),
    ({  "AddExit","north",OUTER("58x32") }),
    ({  "AddExit","south",OUTER("58x36") }) }) );
  AddObject(OUTER("58x32"),STDROOM, ({
    ([ P_INT_LONG: "Part of the northern street.\n",
       "X":58,
       "Y":32,
    ]),
    ({  "AddExit","south",OUTER("58x34") }) }) );

  //*****************************************************************
  // way to graveyard
  //*****************************************************************
  AddObject(OUTER("72x60"),STDROOM, ({
    ([ P_INT_LONG: "Way from eastern street to graveyard.\n",
       "X":72,
       "Y":60,
    ]),
    ({  "AddExit","north",OUTER("72x58") }),
    ({  "AddExit","south",OUTER("72x62") }) }) );
  AddObject(OUTER("72x62"),STDROOM, ({
    ([ P_INT_LONG: "Way from eastern street to graveyard.\n",
       "X":72,
       "Y":62,
    ]),
    ({  "AddExit","north",OUTER("72x60") }),
    ({  "AddExit","southeast",OUTER("74x64") }),
    ({  "AddExit","south",OUTER("72x64") }) }) );
  AddObject(OUTER("72x64"),STDROOM, ({
    ([ P_INT_LONG: "Way from eastern street to graveyard.\n",
       "X":72,
       "Y":64,
    ]),
    ({  "AddExit","north",OUTER("72x62") }),
    ({  "AddExit","east",OUTER("74x64") }) }) );
  AddObject(OUTER("74x64"),STDROOM, ({
    ([ P_INT_LONG: "Way from eastern street to graveyard.\n",
       "X":74,
       "Y":64,
    ]),
    ({  "AddExit","northwest",OUTER("72x62") }),
    ({  "AddExit","east",OUTER("graveyard1") }),
    ({  "AddExit","west",OUTER("72x64") }) }) );

  //*****************************************************************
  // north-east-street
  //*****************************************************************
  AddObject(OUTER("60x44"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":60,
       "Y":44,
    ]),
    ({  "AddExit","west",OUTER("58x44") }),
    ({  "AddExit","east",OUTER("62x44") }) }) );
  AddObject(OUTER("62x44"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":62,
       "Y":44,
    ]),
    ({  "AddExit","west",OUTER("60x44") }),
    ({  "AddExit","east",OUTER("64x44") }) }) );
  AddObject(OUTER("64x44"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":64,
       "Y":44,
    ]),
    ({  "AddExit","west",OUTER("62x44") }),
    ({  "AddExit","northeast",OUTER("winery") }),
    ({  "AddExit","southeast",OUTER("66x46") }) }) );
  AddObject(OUTER("66x46"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":66,
       "Y":46,
    ]),
    ({  "AddExit","northwest",OUTER("64x44") }),
    ({  "AddExit","southeast",OUTER("68x48") }) }) );
  AddObject(OUTER("68x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":68,
       "Y":48,
    ]),
    ({  "AddExit","northwest",OUTER("66x46") }),
    ({  "AddExit","southeast",OUTER("70x50") }) }) );
  AddObject(OUTER("70x50"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":70,
       "Y":50,
    ]),
    ({  "AddExit","northwest",OUTER("68x48") }),
    ({  "AddExit","southeast",OUTER("72x52") }) }) );
  AddObject(OUTER("72x52"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":72,
       "Y":52,
    ]),
    ({  "AddExit","northwest",OUTER("70x50") }),
    ({  "AddExit","southeast",OUTER("74x54") }) }) );
  AddObject(OUTER("74x54"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":74,
       "Y":54,
    ]),
    ({  "AddExit","northwest",OUTER("72x52") }),
    ({  "AddExit","east",OUTER("76x54") }) }) );

  AddObject(OUTER("76x54"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":76,
       "Y":54,
    ]),
    ({  "AddExit","west",OUTER("74x54") }),
    ({  "AddExit","south",OUTER("76x56") }) }) );
  AddObject(OUTER("76x56"),STDROOM, ({
    ([ P_INT_LONG: "Way from northern street to eastern street.\n",
       "X":76,
       "Y":56,
    ]),
    ({  "AddExit","north",OUTER("76x54") }),
    ({  "AddExit","south",OUTER("76x58") }) }) );

  //*****************************************************************
  // north-west-street
  //*****************************************************************
  AddObject(OUTER("56x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":56,
       "Y":48,
    ]),
    ({  "AddExit","east",OUTER("58x48") }),
    ({  "AddExit","west",OUTER("54x48") }) }) );
  AddObject(OUTER("54x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":54,
       "Y":48,
    ]),
    ({  "AddExit","east",OUTER("56x48") }),
    ({  "AddExit","west",OUTER("52x48") }) }) );
  AddObject(OUTER("52x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":52,
       "Y":48,
    ]),
    ({  "AddExit","east",OUTER("54x48") }),
    ({  "AddExit","west",OUTER("50x48") }) }) );
  AddObject(OUTER("50x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":50,
       "Y":48,
    ]),
    ({  "AddExit","east",OUTER("52x48") }),
    ({  "AddExit","west",OUTER("48x48") }) }) );
  AddObject(OUTER("48x48"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":48,
       "Y":48,
    ]),
    ({  "AddExit","east",OUTER("50x48") }),
    ({  "AddExit","southwest",OUTER("46x50") }) }) );
  AddObject(OUTER("46x50"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":46,
       "Y":50,
    ]),
    ({  "AddExit","northeast",OUTER("48x48") }),
    ({  "AddExit","west",OUTER("44x50") }),
    ({  "AddExit","southwest",OUTER("44x52") }) }) );
  AddObject(OUTER("44x50"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":44,
       "Y":50,
    ]),
    ({  "AddExit","east",OUTER("46x50") }),
    ({  "AddExit","west",OUTER("safe") }) }) );
  AddObject(OUTER("44x52"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":44,
       "Y":52,
    ]),
    ({  "AddExit","northeast",OUTER("46x50") }),
    ({  "AddExit","southwest",OUTER("42x54") }) }) );
  AddObject(OUTER("42x54"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":42,
       "Y":54,
    ]),
    ({  "AddExit","northeast",OUTER("44x52") }),
    ({  "AddExit","south",OUTER("42x56") }) }) );

  AddObject(OUTER("42x56"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":42,
       "Y":56,
    ]),
    ({  "AddExit","north",OUTER("42x54") }),
    ({  "AddExit","south",OUTER("42x58") }) }) );
  AddObject(OUTER("42x58"),STDROOM, ({
    ([ P_INT_LONG: "Way from western street to northern street.\n",
       "X":42,
       "Y":58,
    ]),
    ({  "AddExit","north",OUTER("42x56") }),
    ({  "AddExit","south",OUTER("42x60") }) }) );

}
