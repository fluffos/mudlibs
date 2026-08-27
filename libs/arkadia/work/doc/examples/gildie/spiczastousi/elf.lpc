inherit "/std/room";

#include "defs.h"

create_room()
{
    set_short("Gildia elfow");
    set_long("Znajdujesz sie w gildii elfow. Wstukaj 'zapisz sie' jesli "+
        "chcesz sie zapisac, albo 'wypisz sie' jesli chcesz.. no wlasnie. "+
        "Mozesz rowniesz 'sprawdzic' wszystkie gildie, ktorych jestes " +
        "czlonkiem.\n");
}

/* Prototypy */
czy_podoba_mi_sie_ten_gracz_w_mojej_gildii(object gracz);
czy_podobaja_mi_sie_inne_gildie_w_ktorych_jest_gracz(object gracz);

init()
{
    ::init();
    add_action("join", "zapisz");
    add_action("leave", "wypisz");
    add_action("list", "sprawdz");
}

int
join(string str)
{
    object shadow;
    int result;

    if (!str || str != "sie")
    {
         notify_fail("Kogo chcesz zapisac?\n");
         return 0;
    }

    notify_fail("Nie spelniasz wymagac, jakich oczekujemy od naszych "+
        "czlonkow.\n");
        
    if (!czy_podoba_mi_sie_ten_gracz_w_mojej_gildii(this_player()))
	return 0;

    notify_fail("Juz sie przylaczyl" + this_player()->koncowka("es", "as") +
        " do innej gildii, ktorej czlonkowie nie sa tu mile widziani.\n");
        
    if (!czy_podobaja_mi_sie_inne_gildie_w_ktorych_jest_gracz(this_player()))
	return 0;

    notify_fail("Z przyczyn obiektywnych nie mozesz sie do nas przylaczyc.\n");
    
    shadow = clone_object(SHADOW);
    
    if ((result = shadow->shadow_me(this_player(), GUILD_TYPE, 
        GUILD_STYLE, GUILD_NAME)) != 1)
    {
    /* result = -1 (brak nazwy), -2 (zly typ), -3 (brak stylu),
                -4 (gildie, w ktorych jest gracz nie chca tej gildii.)
		-5 (klopoty z zalozeniem shadowa. ) */
    /* shadow_me() zapewne zatroszczy sie o stosowny komunikat bledu */

        shadow->remove_object();
        
	return 0;
    }
    dump_array(result);
    
    this_player()->add_cmdsoul(SOUL);
    this_player()->update_hooks();

    write("Od teraz jestes jednym ze Spiczastouchych!\n");
    return 1;
}

int
leave(string str)
{
    if (!str || str != "sie")
    {
         notify_fail("Kogo chcesz wypisac?\n");
         return 0;
    }

    
    if (this_player()->query_guild_name_race() != GUILD_NAME)
    {
        notify_fail("Alez ty nie jestes czlonkiem naszej gildii!\n");
	return 0;
    }

    if (this_player()->remove_guild_race())
    {
        this_player()->remove_cmdsoul(SOUL);
        this_player()->update_hooks();
	write("Wypisal" + this_player()->koncowka("es", "as") + " sie " +
	    "z naszej ukochanej gildii...\n");
    }
    else
	write("Wystapil jakis dziwny blad i chyba musisz sie jeszcze "+
	   "z nami troche pomeczyc. Proponuje napsac list do kogos "+
	   "odpowiedzialnego za to stowarzyszenie.\n");

    return 1;
}

int
czy_podoba_mi_sie_ten_gracz_w_mojej_gildii(object gracz)
{
    string rasa;
    
    rasa = gracz->query_race_name();
    if ( (rasa != "elf") && (rasa != "elfka"))
    {
	notify_fail("To stowarzyszenie jest dostepne tylko dla elfow.\n");
	return 0;
    }

    if (gracz->query_guild_member(GUILD_NAME))
    {
	notify_fail("Alez juz jestes jedn" + gracz->koncowka("ym", "a") +
	    " z nas.\n");
	return 0;
    }

/* Tu mozesz sprawdzic czy gracz rozwiazal questa wejsciowego, lub 
    czy spelnia jakiekolwiek inne wymagania... */
    
    return 1;
}

int
czy_podobaja_mi_sie_inne_gildie_w_ktorych_jest_gracz(object gracz)
{
    if (gracz->query_guild_member(GUILD_TYPE))
    {
	notify_fail("Alez juz jestes czlonkiem innej gildii rasowej!\n"); 
	return 0;
    }

    return 1;
}

list()
{
    string str;

    str = this_player()->list_mayor_guilds();
    if (str)
	write("Jestes czlonkiem nastepujacych gildii:\n" + str);
    else
	write("Nie jestes czlonkiem zadnej gildii.\n");

    return 1;
}

