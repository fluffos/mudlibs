// /d/huegelland/raballion/tunnel/room/details_e1.h
// 1998-02-25  raballion@
//             oefter auftauchende details hier zusammengefasst

// himmelsrichtungen fuer witzbolde
  AddDetail( ({ "westen", "west" }),
    "Westen liegt im Westen.");
  AddDetail( ({ "nordwesten", "nordwest" }),
    "Nordwesten liegt im Nordwesten.");
  AddDetail( ({ "norden", "nord" }),
    "Norden liegt im Norden.");
  AddDetail( ({ "nordosten", "nordost" }),
    "Nordosten liegt im Nordosten.");
  AddDetail( ({ "osten", "ost" }),
    "Osten liegt im Osten.");
  AddDetail( ({ "suedosten", "suedost" }),
    "Suedosten liegt im Suedosten.");
  AddDetail( ({ "sueden", "sued" }),
    "Sueden liegt im Sueden.");
  AddDetail( ({ "suedwesten", "suedwets" }),
    "Suedwesten liegt im Suedwesten.");

  AddDetail( ({ "richtung", "richtungen" }),
    "Naja, jetzt wird es aber arg. Dies solltest Du aber schon wissen.");

  AddDetail( ({ "tunnel", "tunnelsystem" }),
    QueryProp(P_INT_LONG) );

  AddDetail( ({"ebene"}),
    QueryProp(P_INT_LONG) );

  AddDetail( ({"ebenen"}),
    "Es gibt hier viele Ebenen im Tunnelsystem von Derlim");

  AddDetail( ({"gelegenheit"}),
    "Spaeter kommst Du schlicht nicht mehr an die Oberflaeche.");

  AddDetail( ({"oberflaeche"}),
    "Willst Du nicht lieber gleich dahin?");

  AddDetail( ({"ferne"}),
    "Du hoerst aus der Ferne leichten Laerm.");

  AddDetail( ({"laerm"}),
    "Laerm kann man hoeren, aber nicht sehen.");

// sound 
  AddSound( ({ DEFAULT_SOUND }),
    "Du hoerst aus der Ferne leichten Laerm.");
  AddSound( ({"laerm"}),
    "MMMhh. Hoert sich nach Kampflaerm an.");
  AddSound( ({"kampflaerm"}),
    "Jemand schreit auf und manchmal klirrt und scheppert etwas.");

// details die (fast) jeder sucht
  AddDetail( ({ "himmel", "sonne" }),
    "Eine Sonne gibt es hier definitiv nicht!");

