//
// ----------------------------------------------------------------------------
// Datei:        kammer.c
// Autor:        Rommy
// Datum:        02.08.2009
// ----------------------------------------------------------------------------
// Beschreibung: Kammer im Beispielprojekt
// ----------------------------------------------------------------------------
// Aenderungen:
//

#include "../sys/TEST.h"

inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>

void set_details();

void create() {
    ::create();

    /* -------------------------------------------------------------------- */
    /* Raum Beschreibung                                                    */
    /* -------------------------------------------------------------------- */

    SetProp(P_INT_LONG,
      "Eine leere Kammer ohne Beschreibung, weil Rommy zu faul war, sich "
      "eine tolle, einzigartige Umgebung auszudenken, in der ein Testhund "
      "und ein Testknochen als Anschauungsbeispiel existieren kann. Eine "
      "Treppe fuehrt nach oben. Man kann sie hinaufsteigen."
    );

    /* -------------------------------------------------------------------- */
    /* Raum Properties                                                      */
    /* -------------------------------------------------------------------- */

    SetProp(P_LIGHT, 1);
    SetProp(P_INDOORS, 1);
    SetProp(P_INT_SHORT, "Eine versteckte Kammer");
    SetProp(P_ENVIRONMENT, ([ENV_TEMPERATURE: 17+(random(3)),
        ENV_TERRAIN: TT_CAVE]));

    /* -------------------------------------------------------------------- */
    /* Ausgaenge                                                            */
    /* -------------------------------------------------------------------- */

    AddExit("norden", ANSCHLUSS);

    /* -------------------------------------------------------------------- */
    /* Raumkommandos                                                        */
    /* -------------------------------------------------------------------- */

    // Treppe hinauf steigen
    AddCmd(({"steige","steig"}), "steigen");

    /* -------------------------------------------------------------------- */
    /* Items und NPCs                                                       */
    /* -------------------------------------------------------------------- */

    AddItem(TEST_N"testnpc", REFRESH_DESTRUCT);


    set_details();
}


int steigen(string arg) {
    notify_fail("Was willst Du hinaufsteigen?\n");
    if (arg != "treppe hinauf"
     && arg != "treppe rauf"
     && arg != "treppe hoch"
     && arg != "treppe nach oben")
        // false syntax
        return 0;

    // richtige Syntax
    write("Du steigst die Testtreppe hinauf.\n");
    TP->move("/gilden/abenteurer", M_GO,0,
      "steigt die Testtreppe hinauf",
      "kommt herein");
    return 1;
}


void set_details() {
    /* -------------------------------------------------------------------- */
    /* Raumdetails                                                          */
    /* -------------------------------------------------------------------- */
    AddDetail(({"boden"}),
      "Grober, grauer, erdiger Steinboden. Gluecklicherweise ist er so "
      "eben, dass Du Dir keine Gedanken machen musst, wo Du hintrittst.");

    // TODO viel mehr Details :)

    /* Gerueche */
    AddSmell(DEFAULT_SMELL,
      "Modrig und kalt.");

    /* Toene und so */
    AddSound(DEFAULT_SOUND,
      "Es ist erschreckend still.");
}
