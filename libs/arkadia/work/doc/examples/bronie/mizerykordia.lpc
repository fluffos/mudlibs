/*
 * Jest to przyklad broni z polska odmiana,
 * sporzadzony przez Technokrate.
 */

/* To nalezy umiescic w kazdym pliku broni... */

inherit "/std/weapon";
#include <stdproperties.h>
#include <macros.h>
#include <wa_types.h>
#include <ss_types.h>
#include <formulas.h>

void
create_weapon()
{
    /* Tutaj ustawiamy nazwy naszego obiektu... Mozemy sie do niego
       odwolywac, podajac ktoras z nich, lub piszac 'bron', przy czym
       w obu przypadkach mozemy dodawac przymiotniki. */

    ustaw_nazwe(({"mizerykordia", "mizerykordii", "mizerykordii",
                  "mizerykordie", "mizerykordia", "mizerykordii"}),
                ({"mizerykordie", "mizerykordii", "mizerykordiom",
                  "mizerykordie", "mizerykordiami", "mizerykordiach"}),
                PL_ZENSKI);
    dodaj_nazwy(({"sztylet", "sztyletu", "sztyletowi", "sztylet", "sztyletem",
                  "sztylecie"}),
                ({"sztylety", "sztyletow", "sztyletom", "sztylety",
                  "sztyletami", "sztyletach"}), PL_MESKI_NZYW);

    /* Tutaj ustawiamy przymiotniki. Pierwszym argumentem jest zawsze
       mianownik liczby pojedynczej rodzaju meskiego, drugim - mianownik
       liczby mnogiej rodzaju meskoosobowego. */

    dodaj_przym("ostry", "ostrzy");
    dodaj_przym("niewielki", "niewielcy");

    /* Mudlib sam wygeneruje krotka nazwe, korzystajac z ustaw_nazwe i
       dodaj_przym. Nasza bron wyglada teraz tak: niewielka ostra
       mizerykordia. */
                  
    set_long("Krotki ostry sztylet, ktorego nazwa oznacza 'ostrze "
           + "milosierdzia', uzywany jest do skracania mak konajacym.\n");

    /* A to juz standardowe dodatki... */

    set_hit(18);  /* Wspolczynnik okreslajacy prawdopodobienstwo trafienia. */
    set_pen(6);   /* Wspolczynnik okreslajacy zadawane uszkodzenia. */

    set_wt(W_KNIFE);   /* Typ broni - sztylet. */
    set_dt(W_IMPALE);  /* Bron klujaca. */

    set_hands(W_LEFT);  /* Przeznaczona dla lewej reki. */
}