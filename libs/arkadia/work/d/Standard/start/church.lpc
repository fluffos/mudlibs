#pragma strict_types
#pragma no_clone

inherit "/std/room";

#include "/sys/stdproperties.h"
#include "/sys/macros.h"

void
create_room()
{
    add_prop(OBJ_S_WIZINFO, "@@wizinfo");
    set_short("Lokalna swiatynia");

    set_long("Jestes w lokalnej swiatyni. Co prawda nic tu nie ma, " +
	     "ale to wazne miejsce bo tu startuja wszyscy nowi gracze. "+
	     "W kierunku poludniowym jest poczta. Oprocz tego jest " +
	     "tu teleporter, ktorym czarodzieje moga sie dostac w tylko sobie "+
	     "znane miejsce.\n");

    add_item("teleporter", "Teleporter sluzy do przenoszenia czarodziei "
                         + "w im tylko znane miejsce.\n");

    add_exit("/d/Standard/start/mailroom", "poludnie");
    add_exit("/d/Standard/wiz/wizroom", ({"teleporter", "przez teleporter"}),
             "@@czy_nie_wiz", 0);

    add_prop(ROOM_I_INSIDE,1);
}

int
czy_nie_wiz()
{
    if (!this_player()->query_wiz_level())
    {
        write("Teleporter dziala tylko dla czarodziei.\n");
        return 1;
    }
    return 0;
}

string
wizinfo()
{
    return "This is the starting location for all players in the standard "+
  	   "distribution of this mudlib. It should be replaced as soon "+
	   "as possible by the local administrator.\n";
}

void
init()
{
    ::init();
    add_action("czytaj", "czytaj");
    add_action("spojrz", "spojrz");
    add_action("spojrz", "sp");
    add_action("obejrzyj", "obejrzyj");
    add_action("obejrzyj", "ob");
}

int
czytaj(string str)
{
    write("Komendy na Arkadii wystepuja w formie dokonanej. Proponuje uzyc "
        + "'przeczytaj'.\n");
    return 1;
}

int spojrz(string str)
{
    if ((str == "tablica" || str == "na tablica") && present("tablica"))
    {
        write("Skladnia komend na Arkadii jest taka jak w jezyku polskim. "
            + "Proponuje uzyc 'spojrz na tablice' lub 'obejrzyj tablice'.\n");
        return 1;
    }
    return 0;
}

int obejrzyj(string str)
{
    if (str == "tablica" && present("tablica"))
    {
        write("Skladnia komend na Arkadii jest taka jak w jezyku polskim. "
            + "Proponuje uzyc 'obejrzyj tablice' lub 'spojrz na tablice'.\n");
        return 1;
    }
    return 0;
}