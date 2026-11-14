//
// ----------------------------------------------------------------------------
// Datei:        testnpc.c
// Autor:        Rommy
// Datum:        02.08.2009
// ----------------------------------------------------------------------------
// Beschreibung: Ein Hund als TestNPC fuers Beispielprojekt.
//               Er kann nichts besonderes und steht im Testraum.
// ----------------------------------------------------------------------------
// Aenderungen:
// DD.MM.YYYY  <Name>  <Beschreibung>

#pragma strong_types

#include "../sys/TEST.h"

inherit "/std/npc";

#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <new_skills.h>
#include <language.h>

void create() {
    int level;
    if (!clonep(TO)) return;
    ::create();
    level = 15+random(5);
    create_default_npc(level);

    SetProp(P_NAME, "Hund");
    SetProp(P_SHORT, "Ein einfacher Hund");
    SetProp(P_NAME_ADJ, "einfach");
    AddId(({"\ntesthund","hund","FELL_WUSCHEL"}));
    AddAdjective(({"einfacher","einfachen","einfachem"}));
    SetProp(P_GENDER, MALE);
    SetProp(P_LONG,
      "Dieser Hund ist erstaunlich gross, hat lange Schlappohren, "
      "rotbraunes, wuscheliges Fell und seine schwarzen Augen blicken "
      "wachsam umher."
    );
    SetProp(P_RACE, "Hund");
    SetProp(P_ALIGN, 50 - random(250));
    SetProp(P_SIZE, 80 + random(30));
    SetProp(P_REJECT, ({ REJECT_DROP,
      Name(WER,1)+" mustert @WEN ratlos.\n"}));

    SetProp(P_MSGIN, "laeuft herein");
    SetProp(P_MSGOUT, "laeuft#");
    SetProp(P_MMSGIN, "laeuft bellend herein");
    SetProp(P_MMSGOUT, "laeuft bellend#");

    /* -------------------------------------------------------------------- */
    /* Kampf                                                                */
    /* -------------------------------------------------------------------- */

    SetProp(P_HANDS,
      ({" mit scharfen Zaehnen", QueryProp(P_HANDS)[1], DT_RIP}));
    SetProp(P_DIE_MSG, " jault noch einmal auf und stirbt.\n");
    SetProp(P_KILL_NAME, "Ein gemeiner Testhund");
    SetProp(P_NOMAGIC, 5);
    SetProp(P_WIMPY, random(30));
    SetProp(P_HEAL, 2+random(3));

    SetProp(P_RESISTANCE_STRENGTHS,([
      DT_BLUDGEON:-0.3,
      DT_FIRE:    -0.2,
      DT_MAGIC:   -0.2,
      DT_LIGHT:    0.3,
      DT_SQUEEZE:  0.2])
    );

    SetProp(P_SPELLRATE, 20);

    AddSpell(7, 300,
      Name(WER,1)+" beisst Dich.\n",
      Name(WER,1)+" beisst @WEN.\n",
      ({DT_RIP}));
    AddSpell(7, 150,
      Name(WER,1)+" bellt Dich laut an.\n",
      Name(WER,1)+" bellt @WEN laut an.\n",
      ({DT_SOUND}));

    /* -------------------------------------------------------------------- */
    /* Infos und Chats                                                      */
    /* -------------------------------------------------------------------- */

    SetChats(1 ,({
      Name(WER,1)+" bellt.\n",
      Name(WER,1)+" schnuppert am Boden.\n",
      Name(WER,1)+" beschnueffelt etwas am Boden.\n",
      Name(WER,1)+" bellt aufgebracht.\n",
      Name(WER,1)+" knurrt ein bisschen.\n"})
    );

    AddInfo(DEFAULT_INFO, ({
      "bellt.\n",
      "wackelt mit den Ohren.\n",
      "beschnueffelt seine Pfote.\n",
      "versteht die Frage nicht.\n"})
    );
    AddInfo(({"fressen","hunger","essen"}),
      "wackelt freudig mit dem Schwanz.");
    AddInfo(({"herrchen","frauchen","gassi"}),
      "Wau, wau, wau!",
      "bellt: ");


    /* -------------------------------------------------------------------- */
    /* Details                                                              */
    /* -------------------------------------------------------------------- */

    AddDetail(({"schlappohren","ohren","schlappohr","ohr"}),
      "Seine Ohren sind wie der Rest des Felles rotbraun.");

    SetProp(P_SMELL,
      "Sein Fell riecht nicht gerade angenehm.\n");
    SetProp(P_SOUND,
      "Er bellt Dir lautstark ins Ohr.\n");


    /* -------------------------------------------------------------------- */
    /* Items und Ruestung                                                   */
    /* -------------------------------------------------------------------- */

    // er hat ab und zu einen Knochen dabei
    if (random(2) == 1)
        AddItem(TEST_O"knochen", CLONE_MOVE);
}
