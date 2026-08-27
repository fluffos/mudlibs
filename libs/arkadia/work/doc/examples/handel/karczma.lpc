/*
 * Przykladowa karczma.
 */
 
inherit "/std/room"; /* obiekt jest lokacja */
inherit "/lib/pub"; /* obiekt spelnia funkcje karczmy */

#include <stdproperties.h>
#include <macros.h>

void
create_room()
{
    set_short("Karczma przykladowa.\n");
    set_long("Jestes w przykladowej karczmie. Nad lada wisi mala "+
        "tabliczka.\n");
    
    add_item("lade", "Ohh.. to jest przyklad.. nie chce mi sie tego "+
        "wszystkiego opisywac...\n");
            
    add_item(({ "tabliczke", "menu" }), "Spelnia ona zapewne funkcje menu. Warto "+
        "by ja przeczytac.\n");
        
    add_cmd_item( ({ "tabliczke", "menu" }), ({ "czytaj", "przeczytaj" }),
        "@@menu");
        
    add_prop(ROOM_I_INSIDE, 1);

/* Oto co oznaczaja poszczegolne argumenty dla add_drink() */
/*
 * Nazwa funkcji : add_drink
 * Opis          : Dodaje trunek serwowany na miejscu i (lub) na wynos.
 * Argumenty     : nazwy_dop - Nazwa lub nazwy trunku w dopelniaczu w lp
 *		   nazwy_bie - Nazwa lub nazwy trunku w bierniku w lp
 *		   picie_tu  - Opis przy piciu (Xxx wychyla 'kufel jasnego piwa')
 *		   short_dop - Krotki opis trunku w dopelniaczu.
 *		   adj	     - Tablica z parami przymiotnikow
 * 		   vol	     - Ile % alkoholu jest w plynie
 *		   porcja    - Ile ml napoju sprzedaje sie w porcji na miejscu
 *		   obj_pojemn- W ilu litrowych pojemnikach sprzedaje sie na wynos
 * 		   cena	     - Cena litra napoju.
 *		   rodzaj    - Rodzaj gramatyczny nazwy napoju
 *		   opis_pojemn-Opcjonalny opis pojemnika, w jakim trunek
 *			       jest sprzedawany. 
 */
    

/* Zwykle piwo, sprzedawane w 5-litrowych beczkch oraz w kuflach na miejscu.
   Ponadto beczki w ktorych jest sprzedawne sa 'firmowe'. 
 */
    add_drink("piwa", "piwo", "kufel jasnego, miejscowego piwa",
    		"ciemno-bursztynowego, wspaniale pieniacego sie piwa",
    		({ ({ "jasny", "miejscowy" }), ({ "jasni", "miejscowi" }) }),
    		5, 250, 5, 80, PL_NIJAKI_NOS, "Jest to niewielka debowa " +
    		"beczulka, noszaca znak firmowy krolewskiego browaru Judamii.");

/* A tu mamy wino, ktore jest na tyle dobore, ze nie sprzedaje sie go 
   w beczkach na wynos (swiadczy o tym 0, jako pojemnosc pojemnika) 
 */
    add_drink("wina", "wino", "kieliszek czewonego wytrawnego wina",
    		"", ({ ({ "czerowny", "wytrawny" }), ({ "czerwoni", 
    		"wytrawni" }) }), 12, 100, 0, 600, PL_NIJAKI_NOS);


/* UWAGA: Przy trunkach trzeba pamietac, ze cena jest podawana za litr,
	  a np. piwo u nas jest sprzedawane w kuflach cwierclitrowych.
	  Oznacza to, ze cene nalezy pomnozyc przez ilosc cieczy w porcji
	  i podzielic przez 1000. Dla piwa to bedzie: 80 * 250 / 1000 = 20.
	  Czyli cena kufla piwa wynosi 20.
	  
  UWAGA2: Napoje sa sprzedawane na wynos w dwoch rodzajach pojemnikow.
  	  Jesli pojemnosc sie poda w przedziale 1-4 litry, to beda sprzedane
  	  w buklaku. Jesli powyzej - w beczulce. Nalezy to uwzglednic w
  	  Menu. Do ceny za napoj doliczane jest (30 + 4*pojemnosc) 
  	  miedziakow za buklak i (140 + 10*pojemnosc) za beczulke.
 */



    
/* Oto co oznaczaja poszczegolne argumenty dla add_food() */ 
/*
 * Nazwa funkcji : add_food
 * Opis		 : Dodaje do menu posilek do zjedzenia 'na miejscu'.
 * Argumenty     : nazwa     - Nazwa lub nazwy jedzenia w bierniku lp
 *		   adj	     - Tablica z parami przymiotnikow
 *		   ilosc     - Ilosc zarcia (jego waga w gramach)
 *		   cena      - Cena zarcia (koszt kupna)
 *		   rodzaj    - Rodzaj gramatyczny nazwy jedzenia
 *		   short     - Krotki opis w bierniku lp (opcjonalne)
 */

    add_food( "stek", 0, 300, 30, PL_MESKI_NOS_ZYW,
              "miske z ryzem i soczystym stekiem");




/*
 * Nazwa funkcji : add_wynos_food
 * Opis		 : Dodaje do menu posilek do zjedzenia 'na wynos'.
 * Argumenty     : nazwy     - Odmiana nazw jedzenia w lp
 *		   pnazwy    - Odmiana nazw jedzenia w lmn
 *		   adj	     - Tablica z parami przymiotnikow
 *		   ilosc     - Ilosc zarcia (waga)
 *		   cena      - Cena zarcia (koszt kupna)
 *		   long      - Dlugi opis
 *		   rodzaj    - Rodzaj gramatyczny nazwy jedzenia
 *		   decay     - Czas psucia sie, ususzania sie, itp.
 *			       w sekundach (0 - nie psuje sie)
 *		   decay_adj - Tablica z para przymiotnikow, gdy jedzenia
 *			       nie da sie zjesc (standardowo - 'zepsuty')
 *				(opcjonalne)
 *		   short     - Odmiana krotkiego opisu w lp (opcjonalne)
 *		   pshort    - Odmiana krotkiego opisu w lmn (opcjonalne)
 */
 
 /* Zwykla kielbaska. Jak wiekszosc zarc na wynos, i ta sie psuje.
    Dlugi opis nie jest zbyt ambitny, mozna by sie lepiej postarac. :-)
  */
    add_wynos_food( ({ "kielbasa", "kielbasy", "kielbasie", "kielbase", 
	"kielbasa", "kielbasie" }), ({ "kielbasy", "kielbas", "kielbasom", 
	"kielbasy", "kielbasami", "kielbasach" }), ({ ({ "jalowcowy" }),
	({ "jalowcowi" }) }), 300, 45, "Pojedynczy kawalek kielbasy, z " +
	"charakterystyczna, silna wonia jalowca zen dochodzaca.\n",
	PL_ZENSKI, 600, ({ "zepsuty", "zepsuci" }));
}

void
init()
{
    ::init(); /* Musi byc ZAWSZE wywolane w kazdym inicie. */
    init_pub(); /* dodaje komendy 'kup' i 'zamow' */
}

string
menu()
{
    say(QCIMIE(this_player(), PL_MIA) + " czyta tabliczke.\n");
    return
    "\nTabliczka wyglada nastepujaco:\n\n"+
    "\t\tMENU:\n"+
    "Jedzenie:\n"+
    " Stek z ryzem:			30 miedziakow\n" +
    " Kielbasa jalowcowa:		45 miedziakow\n\n" +
    "Napoje:\n"+
    " Miejscowe, jasne piwo:		20 miedziakow\n" +
    " Czerwone, wytrawne wino:		60 miedziakow\n\n" +
    " Oprocz tego, nasze piwo mozna nabyc w 5-litrowych beczulkach, za " +
    "jedyne 590 miedziakow.\n";

}