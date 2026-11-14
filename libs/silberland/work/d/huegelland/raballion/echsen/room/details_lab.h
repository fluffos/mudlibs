// /d/huegelland/raballion/echsen/room/details_lab.h
// 2004-07-15  raballion@
//             oefter auftauchende details hier zusammengefasst

  AddDetail( ({ "tunnel", "tunnelsystem", "lab", "labyrinth", "tunnellabyrinth" }),
    QueryProp(P_INT_LONG) );

  AddDetail( ({"raum", "hier"}),
    QueryProp(P_INT_LONG) );

  AddDetail( ({"moos", "moose", "flechte", "flechten"}),
    "Sie wachsen hier fast ueberall und sind glitschig und feucht.");

  AddDetail( ({"balken", "stuetzbalken", "querbalken", "verstrebung", "verstrebungen" }),
    "Alles sehr solide Arbeit und verhindert das Einstuerzen der Tunnel.");

  AddDetail( ({"arbeit", "arbeiten"}),
    "Du bewunderst sie ehrlich.");

  AddDetail( ({"einsturz", "einstuerzen"}),
    "Da waerst du platt, wenn das passieren wuerde.");

  AddDetail( ({"decke", "decken"}),
    "Sie ist ueber Dir und manchmal tropft etwas von oben herunter. Nebenbei bemerkt wachsen dort Moose und Flechten.");

  AddDetail( ({"boden"}),
    "Ist unter dir und du stehts darauf.");

  AddDetail( ({"tropfen"}),
    "Tropfen tropfen von der Decke und verursachen ein tropfendes Geraeusch.");

  AddDetail( ({"geraeusch", "geraeusche"}),
    "Waere lauschen nicht besser?");

  AddDetail( ({"gestein", "gesteine"}),
    "Ist um Dich herum.");

// sound
  AddSound( ({ DEFAULT_SOUND, "geraeusch", "geraeusche" }),
    "Manchmal tropft etwas von der Decke.");
  AddSound( ({"tropfen"}),
    "MMMhh. Sie tropfen von der Decke. *Plopf, Plopf,...*");

// details die (fast) jeder sucht


