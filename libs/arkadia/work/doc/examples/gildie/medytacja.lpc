inherit "/std/room";
inherit "/lib/guild_support"; 

#include <macros.h>
#include <stdproperties.h>

void
create_room()
{ 
    set_short("Przykladowy pokoj do medytowania");
    set_long("Znajdujesz sie w kolejnym przykladowym pokoju. Ten ma ci " +
        "unaocznic, jak latwo mozna napisac pokoj z mozliwoscia medytacji, " +
        "w czasie ktorej moze ustawic sobie wspolczynniki przyrostu " +
        "lub tez sprobowac ocenic swoje cechy. Gdy ty bedziesz pisal " +
        "takie pomieszczenie w swojej gildii bedziesz musial oczywiscie " +
        "zadbac, zeby opisy mialy swoj klimat i nie sugeruj sie opisami " +
        "z tego przykladu. (popatrz na standardowe opisy w " +
        "'/lib/guild_support.c'.\n");

    add_prop(ROOM_I_INSIDE, 1);
}

void
init()
{
    ::init();
    init_guild_support();
}

void
gs_hook_start_meditate()
{
    write("To jest nasz wlasny opis pojawiajacy sie gdy gracz zaczyna "+
        "medytacje.\n");
        
   write("\n\nZas to jest standardowy opis, wpisany w "+
        "'/lib/guild_support': \n\n");
   ::gs_hook_start_meditate(); // wywolanie tej funkcji na poziome guild_support.c
}

int
gs_hook_rise()
{
    write("Przy powstawaniu postaramy sie byc nieco bardziej oryginalni "+
        "i opis pojawiajacy sie graczowi bedzie calkowicie pochodzil "+
        "z tego przykladu. Oczywiscie ty musisz zadbac, zeby u ciebie "+
        "jakos ciekawie wygladal.\n\nHmm, no a wiec, przestajesz "+
        "medytowac i wstajesz.\n");
        
    /* Musimy teraz zadbac o to, by inni rowniez widzieli, iz gracz 
     * zakonczyl medytacje.
     */
        
    say(QCIMIE(this_player(), PL_MIA) + " konczy medytacje i wstaje.\n");
}

