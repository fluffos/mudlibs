/*
 * Copyright (c) 1991 Chalmers Computer Society
 *
 * This code may not be copied or used without the written permission
 * from Chalmers Computer Society.
 */

#pragma save_binary

inherit "/std/scroll";
#include <stdproperties.h>
#include <pl.h>
#include "/config/sys/local.h"

create_scroll()
{
    seteuid(getuid(this_object()));
    add_prop(OBJ_I_NO_DROP, "Nie wyrzucaj tej kartki, gdyz zawiera cenne " +
	"informacje!\n");
    ustaw_nazwe( ({ "kartka", "kartki", "kartce", "kartke", "kartka", 
        "kartce" }), ({ "kartki", "kartek", "kartkom", "kartki",
        "kartkami", "kartkach" }), PL_ZENSKI );
    dodaj_przym( "bialy", "biali" );
    set_long("Jest to biala kartka zapisana gestym malym druczkiem. Na "+
        "samej gorze\nwidnieje duzy, czerwony napis 'KONIECZNIE " +
        "PRZECZYTAJ'.\n");
    set_autoload();
    set_file(APPRENTICE_SCROLL_FILE);
}

void
init()
{
    ::init();
    add_action("czytaj", "czytaj");
}

int
czytaj(string str)
{
    write("Komendy na Arkadii wystepuja w formie dokonanej. Proponuje uzyc "
        + "'przeczytaj'.\n");
    return 1;
}