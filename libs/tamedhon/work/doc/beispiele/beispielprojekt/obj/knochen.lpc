//
// ----------------------------------------------------------------------------
// Datei:        knochen.c
// Autor:        Rommy
// Datum:        02.08.2009
// ----------------------------------------------------------------------------
// Beschreibung: Ein (ziemlich nutzloser) Knochen.
//               Der testnpc.c hat ihn.
// ----------------------------------------------------------------------------
// Aenderungen:
// DD.MM.YYYY  <Name>  <Beschreibung>
//

#pragma strong_types

#include "../sys/TEST.h"

inherit "/std/thing";

#include <properties.h>
#include <thing.h>
#include <language.h>

void create() {
    if (!clonep(TO)) return;
    ::create();
    SetProp(P_NAME, "Knochen");
    SetProp(P_NAME_ADJ, "alt");
    SetProp(P_GENDER, MALE);
    SetProp(P_SHORT, "Ein alter, abgenagter Knochen");
    SetProp(P_LONG,
      "Ein alter, abgenagter Knochen. Er sieht ziemlich gross aus. Stammt "
      "er vielleicht von einem Zwerg oder Hobbit?");
    AddId(({"knochen","\ntestknochen"}));
    SetProp(P_VALUE, 5);
    SetProp(P_WEIGHT, 90 + random(20));
    SetProp(P_MATERIAL, ([MAT_BONE:100]));
    SetProp(P_NOSELL, 1);   // man kann ihn nicht verkaufen
    SetProp(P_INFO,
      "Dieser Knochen ist garantiert nicht magisch.\n");

    SetProp(P_SMELL,"Er riecht nicht.\n");
    SetProp(P_SOUND,break_string(
      "Der Knochen gibt keine Geraeusche von sich. Ist wohl auch "
      "besser so."));
}
