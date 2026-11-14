//
// ----------------------------------------------------------------------------
// Datei:        milchkaennchen.c
// Autor:        Rommy
// Datum:        15.08.2009
// ----------------------------------------------------------------------------
// Beschreibung: Ein Milchkaennchen zum Trinken.
//               Beispiel fuer ein Getraenk.
// ----------------------------------------------------------------------------
// Aenderungen:
// DD.MM.YYYY  <Name>  <Beschreibung>
//

#pragma strong_types

#include "../sys/TEST.h"

inherit "/std/food";

#include <properties.h>
#include <food.h>
#include <language.h>

private int inhalt;   // 0, falls das Kaennchen leer ist.

void create() {
    if (!clonep(TO)) return;
    ::create(({"trink","trinke"})); // <- Getraenke soll man trinken koennen
    SetProp(P_NAME, "Milchkaennchen");
    SetProp(P_NAME_ADJ, "gefuellt");
    SetProp(P_GENDER, NEUTER);
    SetProp(P_SHORT, "Ein gefuelltes Milchkaennchen");
    SetProp(P_LONG,
      "Ein kleines Eimerchen aus Eisen mit einem wackeligen Henkel. "
      "Darin befindet sich Milch frisch vom Bauern, die bestimmt "
      "unglaublich gesund ist.");
    AddId(({"milchkaennchen","milch","eimerchen","eimer","kaennchen",
            "\nMilchkaennchen"}));
    SetProp(P_VALUE, 30);
    SetProp(P_WEIGHT, 950 + random(100));
    SetProp(P_MATERIAL, ([MAT_MILK:92,MAT_IRON:8]));
    SetProp(P_NOSELL, BS(Name(WER,1)+
      " wuerde im Lager des Haendlers nur schlecht werden."));
    SetProp(P_INFO,
      "Milch macht muede Magier munter!\n");

    SetProp(P_SMELL,"Duftet fein nach frischer Milch. Mjam!\n");
    SetProp(P_SOUND,"Was erwartest Du? Milch sprudelt doch nicht!\n");

    SetProp(P_FOOD_INFO,([
      F_HEAL:({5,0}),  // Wieviel (LP,MP) heilt es?
      F_SOAK:  1,      // Essen-Saettigung
      F_DRINK: 5,      // Trink-Saettigung
      //F_POISON: 0,   // Vergiftet nicht
      //F_ALCOHOL: 0,  // Alkoholgehalt hier 0
      F_MSG:"Du trinkst einen Schluck frische Milch aus dem Kaennchen.\n",
      F_MSG_ROOM:"trinkt einen Schluck frische Milch aus dem Kaennchen.\n",
      F_VERB:"trinken" // default "essen". Was willst Du ____?
    ]));

    inhalt = 5;  // 5 mal trinken, bevor das Kaennchen leer ist

    // TODO Details ;)
}

// Wird aufgerufen, wenn der Spieler es isst/trinkt.
// Vorher wird geprueft, ob der Spieler es essen/trinken darf 
// (noch genuegend Platz im Bauch?)
void BeimEssen() {
    inhalt--;
    if (inhalt==3) {
        write("Das Kaennchen ist jetzt nurnoch halbvoll.\n");
        SetProp(P_NAME_ADJ,"halbvoll");
        SetProp(P_SHORT, "Ein halbvolles Milchkaennchen");
    } else if (inhalt==1) {
        write("Das Kaennchen ist jetzt fast leer.\n");
        SetProp(P_NAME_ADJ,"kaum gefuellt");
        SetProp(P_SHORT, "Ein kaum gefuelltes Milchkaennchen");
    }

}

// wird nach BeimEssen() aufgerufen
// wenn 0 returnt wird, wird das Milchkaennchen zerstoert
int second_life(object player) {
    if (inhalt==0) {
        write(BS(
          "Du hast das Kaennchen leergetrunken und wirfst es weg."));
        say(BS(TP->Name(WER,1)+
          " hat das Kaennchen leergetrunken und wirft es weg."));
    }
    return inhalt;
}

