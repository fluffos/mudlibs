/*
 *  Przykladowa lokacja wykorzystujaca funkcje zwiazane z kalendarzem
 *  mudowym, ze zmiennym opisem w zaleznosci od pory dnia, a przy okazji
 *  takze z mozliwoscia picia wody.
 *
 *  /doc/examples/lokacje/wodospad.c
 *
 *  dzielo Silvathraeca 1997
 */

inherit "/d/Ishtar/std/room";	/* Wykorzystujemy fakt, ze Ishtar jest jedna
                                   z domen posiadajacych kalendarz. */
inherit "/lib/drink_water";	/* Funkcje obslugujace picie wody */

#include <macros.h>
#include <mudtime.h>		/* Definicje zwiazane z kalendarzem mudowym */
#include <stdproperties.h>

/* Prototypy - dzieki nim mozemy odwolywac sie do funkcji przed
   ich zdefiniowaniem. */
string dlugi_opis();
string opis_wodospadu();
string opis_porostow();
int wyjscia_niestety_brak();

void
create_ishtar_room()		/* Wymog dziedziczonego obiektu */
{
    set_short("Pieczara za wodospadem");
    set_long(dlugi_opis);	/* Zmienny opis uzyskujemy dzieki VBFC. */

    add_item(({"wodospad", "strugi", "strugi wody", "okno"}),
             opis_wodospadu);
    add_item("wode", "Chlodne krople wody z wodospadu padajace na twoja "
           + "twarz chlodza przyjemnie skore. Mozesz stanac tak blisko "
           + "kaskady, ze masz mozliwosc bez trudu sie z niej napic.\n");
    add_item(({"podloge", "podloze", "spag"}), "Wygladzona podloga z "
           + "ciemnej, bazaltowej skaly pozwala na wygodne podejscie do "
           + "wodospadu. Widac, ze rzemieslnicy, ktorzy tu pracowali "
           + "wykonali naprawde dobra robote.\n");
    add_item(({"sciany", "sciane"}), "Zwieszaja sie nad toba nierowne sciany "
           + "z ciemnej, bazaltowej skaly. Na ich chropawej powierzchni "
           + "tancza refleksy swiatla zalamujacego sie na strugach wody. "
           + "Czesc scian jest mokra od tryskajacych na nie kropel, i tam "
           + "wlasnie rosna liczne kolonie porostow. Tuz obok wodospadu "
           + "zauwazasz niewielka tabliczke, zapisana drobnymi rzedami "
           + "rownych liter.\n");
    add_item(({"strop", "sufit"}), "Strop jaskini tonie w mroku wysoko nad "
           + "twoja glowa.\n");
    add_item(({"porosty", "kolonie porostow"}), opis_porostow);
    add_item(({"tabliczke", "napis", "litery"}), "Na niewielkiej tabliczce, "
           + "umocowanej na scianie tuz obok wodospadu, widnieja drobne "
           + "rzedy rownych liter, zdajacych sie swiecic krwawym blaskiem w "
           + "padajacym na nie swietle. Tworza one jakis napis.\n");

    add_cmd_item(({"tabliczke", "napis"}), "przeczytaj", "\nWszelkie "
               + "skojarzenia z Henneth Annun sa jak najbardziej "
               + "zamierzone... :)\n\n\t\t\t\t\t\tSilvathraec\n");

    add_exit("/dev/null", ({"korytarz", "w glab jaskini"}),
             wyjscia_niestety_brak);

    add_prop(ROOM_I_INSIDE, 1);
    add_prop(OBJ_I_CONTAIN_WATER, 1);	/* Patrz odpowiedni man */

    set_drink_places("z wodospadu");	/* Skad mozna napic sie wody */
}

void
init()
{
    ::init();

    init_drink_water();			/* Dodaje komende 'napij sie'. */
}

/* Opis towarzyszacy piciu wody z wodospadu. */

void
drink_effect(string str)
{
    write("Podchodzisz na tyle blisko wodospadu, aby moc zaczerpnac z niego "
        + "odrobine. Chlodne krople splywaja po twojej skorze, gdy gasisz "
        + "pragnienie lykiem swiezej, orzezwiajacej wody.\n");
    saybb(QCIMIE(this_player(), PL_MIA) + " podchodzi blisko wodospadu, by "
        + "zaczerpnac z niego lyk wody.\n");
}

/* Nazwa funkcji mowi sama za siebie... */

int
wyjscia_niestety_brak()
{
    write("Niestety, to tylko lokacja przykladowa. Reszte jaskini bedziesz "
        + "mogl" + this_player()->koncowka("", "a") + " poznac tylko w "
        + "wyobrazni...\n");
    return 1;
}

/* Dlugi opis lokacji i opis wodospadu uzalezniamy od pory dnia. W analogiczny
   sposob moglibysmy uzaleznic je od pory roku. Wszystkie niezbedne definicje
   znajduja sie w <mudtime.h>, a funkcje, ktorych mozna uzyc, to pora_dnia(),
   pora_roku() i dzien_noc() - patrz odpowiednie smany. */

string
dlugi_opis()
{
    string oswietlenie;

    switch (pora_dnia())
    {
        case MT_WCZESNY_RANEK:
        case MT_RANEK:
        case MT_POLUDNIE:
            oswietlenie = "Sala jest pograzona w lekkim polmroku, jednak "
                        + "przycmione swiatlo dobiega zza wodnej kurtyny.";
            break;
        case MT_POPOLUDNIE:
            oswietlenie = "Sala rozjasniona jest swiatlem bijacym zza wodnej "
                        + "kurtyny, rozszczepiajacym sie w strugach wody na "
                        + "niezliczone barwy teczy.";
            break;
        case MT_WIECZOR:
            oswietlenie = "Sala rozjasniona jest czerwonym swiatlem bijacym "
                        + "zza wodnej kurtyny, docierajacym do wszystkich "
                        + "zakatkow. Mieszaja sie z nim roztanczone, teczowe "
                        + "refleksy, napelniajac to miejsce tajemnicza, "
                        + "mistyczna atmosfera.";
            break;
        case MT_POZNY_WIECZOR:
            oswietlenie = "Sala rozswietlona jest bladym, delikatnym "
                        + "blaskiem splywajacym ze scian, choc zza wodnej "
                        + "kurtyny przebija takze lekka czerwonawa poswiata.";
            break;
        case MT_NOC:
        case MT_SWIT:
            oswietlenie = "Sala rozswietlona jest bladym, delikatnym "
                        + "blaskiem splywajacym ze scian.";
    }

    return "Pieczara rozszerza sie tu znacznie, tworzac obszerna komnate, "
         + "wypelniona ogluszajacym szumem roztrzaskujacej sie, spadajacej "
         + "wody. Po jej zachodniej stronie otwiera sie spore okno, "
         + "wychodzace na wewnetrzna strone majestatycznego wodospadu, co "
         + "jakis czas przeslanianego klebami wodnego pylu. " + oswietlenie
         + " Widok ten kontrastuje wrecz oszalamiajaco z reszta jaskini, "
         + "pograzona w ciszy i mroku.\n";
}

string
opis_wodospadu()
{
    string oswietlenie;

    switch (pora_dnia())
    {
        case MT_WCZESNY_RANEK:
        case MT_RANEK:
        case MT_POLUDNIE:
            oswietlenie = "Zza wodnej kurtyny dobiega przycmione swiatlo, "
                        + "sugerujac ze na zewnatrz trwa dzien.";
            break;
        case MT_POPOLUDNIE:
            oswietlenie = "Zza wodnej kurtyny bije jasne swiatlo dnia, "
                        + "rozszczepiajac sie w strugach wody na "
                        + "niezliczone barwy teczy. Slonce musi znajdowac "
                        + "sie po zachodniej stronie nieba.";
            break;
        case MT_WIECZOR:
            oswietlenie = "Zza wodnej kurtyny bije czerwone swiatlo "
                        + "zachodzacego slonca, docierajac do wszystkich "
                        + "zakatkow sali. Mieszajace sie z nim roztanczone, "
                        + "teczowe refleksy napelniaja ja tajemnicza, "
                        + "mistyczna atmosfera.";
            break;
        case MT_POZNY_WIECZOR:
            oswietlenie = "Zza wodnej kurtyny dobiega lekka, czerwonawa "
                        + "poswiata, sugerujac ze slonce nie moglo zajsc "
                        + "zbyt dawno.";
            break;
        case MT_NOC:
        case MT_SWIT:
            oswietlenie = "Wodna kurtyna oswietlona jest tylko bladym, "
                        + "delikatnym blaskiem splywajacym ze scian. Na "
                        + "zewnatrz musi trwac noc.";
    }

    return "Wodospad wypelnia cale okno w zachodniej scianie komnaty. "
         + "Ogromne masy wody roztrzaskuja sie tuz przy tobie, napelniajac "
         + "sale ogluszajacym rykiem i klebami wodnego pylu. " + oswietlenie
         + " Choc mozesz stanac praktycznie tuz przy kaskadzie, przytlacza "
         + "cie ona swa potega.\n";
}

/* Opis porostow bedzie zalezny od pory dnia w nieco prostszy sposob. */

string
opis_porostow()
{
    string oswietlenie = dzien_noc() ? "W swietle dnia prawdopodobnie nie "
                       + "zauwazyl" + this_player()->koncowka("bys", "abys")
                       + " tego, ale " + "swieca one bladym, delikatnym "
                       + "blaskiem." : "W swietle dnia miejsca te wyraznie "
                       + "odrozniaja sie zywa, zielonkawa barwa.";

    return "Porosty grupuja sie glownie na tych scianach, ktore sa wilgotne "
         + "od niezliczonych kropel wody tryskajacej z wodospadu. "
         + oswietlenie + "\n";
}

/* Nasza lokacja jest INSIDE, wiec standardowo gracz nie zauwaza w niej
   wschodow i zachow slonca. Poniewaz jednak okno w jaskini wychodzi na
   zachodnia strone, zmienimy to nieco. */

void
zachod_slonca(object gracz)
{
    if (CAN_SEE_IN_ROOM(gracz))
        gracz->catch_msg("Wodospad rozjarza sie krwawym blaskiem, "
                       + "przemieszanym z teczowymi refleksami swiatla "
                       + "rozszczepionego w strugach wody. Tancza one przez "
                       + "chwile po scianach jaskini, by po chwili zgasnac, "
                       + "pograzajac ja w lekkim polmroku. Na zewnatrz "
                       + "musialo wlasnie zajsc slonce.\n");
}