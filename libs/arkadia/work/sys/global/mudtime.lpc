/*
 *  Funkcje wspierajace uzywanie kalendarza i ruchow cial niebieskich.
 *
 *  /sys/global/mudtime.c
 *
 *  dzielo Silvathraeca 1997
 */

#pragma no_clone
#pragma no_inherit
#pragma no_shadow
#pragma save_binary
#pragma strict_types

#include <mudtime.h>

/*
 * Nazwa funkcji : pora_dnia_str
 * Opis          : Znajduje nazwe danej pory dnia.
 * Argumenty     : pora_dnia: Zgodnie z definicjami z <mudtime.h>
 */
public string
pora_dnia_str(int pora_dnia)
{
    switch (pora_dnia)
    {
        case MT_SWIT:
            return "swit";
        case MT_WCZESNY_RANEK:
            return "wczesny ranek";
        case MT_RANEK:
            return "ranek";
        case MT_POLUDNIE:
            return "poludnie";
        case MT_POPOLUDNIE:
            return "popoludnie";
        case MT_WIECZOR:
            return "wieczor";
        case MT_POZNY_WIECZOR:
            return "pozny wieczor";
        case MT_NOC:
            return "noc";
        default:
            throw("Illegal argument: pora_dnia = " + pora_dnia + ".\n");
    }
}

/*
 * Nazwa funkcji : pora_roku_str
 * Opis          : Znajduje nazwe danej pory roku.
 * Argumenty     : pora_roku: Zgodnie z definicjami z <mudtime.h>
 */
public string
pora_roku_str(int pora_roku)
{
    switch (pora_roku)
    {
        case MT_WIOSNA:
            return "wiosna";
        case MT_LATO:
            return "lato";
        case MT_JESIEN:
            return "jesien";
        case MT_ZIMA:
            return "zima";
        default:
            throw("Illegal argument: pora_roku = " + pora_roku + ".\n");
    }
}

/*
 * Nazwa funkcji : kierunek_str
 * Opis          : Znajduje nazwe kierunku geograficznego.
 * Argumenty     : pora_roku: Zgodnie z definicjami z <mudtime.h>
 */
public string
kierunek_str(int kierunek)
{
    switch (kierunek)
    {
        case MT_N:
            return "polnoc";
        case MT_NE:
            return "polnocny wschod";
        case MT_E:
            return "wschod";
        case MT_SE:
            return "poludniowy wschod";
        case MT_S:
            return "poludnie";
        case MT_SW:
            return "poludniowy zachod";
        case MT_W:
            return "zachod";
        case MT_NW:
            return "polnocny zachod";
        default:
            throw("Illegal argument: kierunek = " + kierunek + ".\n");
    }
}

/*
 * Nazwa funkcji : pora_dnia_strb
 * Opis          : Znajduje nazwe danej pory dnia.
 * Argumenty     : pora_dnia: Zgodnie z definicjami z <mudtime.h>
 */
public string
pora_dnia_strb(int pora_dnia)
{
    switch (pora_dnia)
    {
        case MT_SWIT:
            return "nad ranem, przed wschodem slonca";
        case MT_WCZESNY_RANEK:
            return "nad ranem, po wschodzie slonca";
        case MT_RANEK:
            return "rano";
        case MT_POLUDNIE:
            return "w poludnie";
        case MT_POPOLUDNIE:
            return "po poludniu";
        case MT_WIECZOR:
            return "wieczorem";
        case MT_POZNY_WIECZOR:
            return "poznym wieczorem, po zachodzie slonca";
        case MT_NOC:
            return "w nocy";
        default:
            throw("Illegal argument: pora_dnia = " + pora_dnia + ".\n");
    }
}

/*
 * Nazwa funkcji : polozenie_ciala
 * Opis          : Znajduje polozenie ciala niebieskiego poruszajcego sie w
 *                 plszczyznie ekliptyki na danej szerokosci geograficznej.
 * Argumenty     : polozenie: Polozenie ciala na polkuli polnocnej.
 *                 szerokosc: Zgodnie z definicjami z <mudtime.h>
 */
public int
polozenie_ciala(int polozenie, int szerokosc)
{
    switch (szerokosc)
    {
        case MT_BIEGUN_N:
        case MT_POLKULA_N:
            switch (polozenie)
            {
                case MT_E:
                    return MT_E;
                case MT_SE:
                    return MT_SE;
                case MT_S:
                    return MT_S;
                case MT_SW:
                    return MT_SW;
                case MT_W:
                    return MT_W;
                case MT_POD_HORYZONTEM:
                    return MT_POD_HORYZONTEM;
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_ROWNIK:
            switch (polozenie)
            {
                case MT_E:
                case MT_SE:
                    return MT_E;
                case MT_S:
                    return MT_ZENIT;
                case MT_SW:
                case MT_W:
                    return MT_W;
                case MT_POD_HORYZONTEM:
                    return MT_POD_HORYZONTEM;
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_POLKULA_S:
        case MT_BIEGUN_S:
            switch (polozenie)
            {
                case MT_E:
                    return MT_E;
                case MT_SE:
                    return MT_NE;
                case MT_S:
                    return MT_N;
                case MT_SW:
                    return MT_NW;
                case MT_W:
                    return MT_W;
                case MT_POD_HORYZONTEM:
                    return MT_POD_HORYZONTEM;
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        default:
            throw("Illegal argument: szerokosc = " + szerokosc + ".\n");
    }
}

/*
 * Nazwa funkcji : polozenie_ciala_long
 * Opis          : Znajduje polozenie ciala niebieskiego poruszajcego sie w
 *                 plszczyznie ekliptyki na danej szerokosci geograficznej.
 * Argumenty     : polozenie: Polozenie ciala na polkuli polnocnej.
 *                 szerokosc: Zgodnie z definicjami z <mudtime.h>
 */
public string
polozenie_ciala_long(int polozenie, int szerokosc)
{
    switch (szerokosc)
    {
        case MT_BIEGUN_N:
            switch (polozenie)
            {
                case MT_E:
                    return "tuz nad wschodnim horyzontem";
                case MT_SE:
                    return "tuz nad poludniowo-wschodnim horyzontem";
                case MT_S:
                    return "tuz nad poludniowym horyzontem";
                case MT_SW:
                    return "tuz nad poludniowo-zachodnim horyzontem";
                case MT_W:
                    return "tuz nad zachodnim horyzontem";
                case MT_POD_HORYZONTEM:
                    return "pod horyzontem";
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_POLKULA_N:
            switch (polozenie)
            {
                case MT_E:
                    return "tuz nad wschodnim horyzontem";
                case MT_SE:
                    return "nad poludniowo-wschodnim horyzontem";
                case MT_S:
                    return "wysoko nad poludniowym horyzontem";
                case MT_SW:
                    return "nad poludniowo-zachodnim horyzontem";
                case MT_W:
                    return "tuz nad zachodnim horyzontem";
                case MT_POD_HORYZONTEM:
                    return "pod horyzontem";
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_ROWNIK:
            switch (polozenie)
            {
                case MT_E:
                    return "tuz nad wschodnim horyzontem";
                case MT_SE:
                    return "wysoko nad wschodnim horyzontem";
                case MT_S:
                    return "wysoko w zenicie";
                case MT_SW:
                    return "wysoko nad zachodnim horyzontem";
                case MT_W:
                    return "tuz nad zachodnim horyzontem";
                case MT_POD_HORYZONTEM:
                    return "pod horyzontem";
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_POLKULA_S:
            switch (polozenie)
            {
                case MT_E:
                    return "tuz nad wschodnim horyzontem";
                case MT_SE:
                    return "nad polnocno-wschodnim horyzontem";
                case MT_S:
                    return "wysoko nad polnocnym horyzontem";
                case MT_SW:
                    return "nad polnocno-zachodnim horyzontem";
                case MT_W:
                    return "tuz nad zachodnim horyzontem";
                case MT_POD_HORYZONTEM:
                    return "pod horyzontem";
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        case MT_BIEGUN_S:
            switch (polozenie)
            {
                case MT_E:
                    return "tuz nad wschodnim horyzontem";
                case MT_SE:
                    return "tuz nad polnocno-wschodnim horyzontem";
                case MT_S:
                    return "tuz nad polnocnym horyzontem";
                case MT_SW:
                    return "tuz nad polnocno-zachodnim horyzontem";
                case MT_W:
                    return "tuz nad zachodnim horyzontem";
                case MT_POD_HORYZONTEM:
                    return "pod horyzontem";
                default:
                    throw("Illegal argument: polozenie = " + polozenie
                        + ".\n");
            }
        default:
            throw("Illegal argument: szerokosc = " + szerokosc + ".\n");
    }
}

/*
 * Nazwa funkcji : faza_ksiezyca_long
 * Opis          : Znajduje wyglad ksiezyca w danej fazie.
 * Argumenty     : faza: Zgodnie z definicjami z <mudtime.h>.
 *                 mia: Nazwa ksiezyca w mianowniku.
 *                 dop: Nazwa ksiezyca w dopelniaczu.
 */
public string
faza_ksiezyca_long(int faza, string mia, string dop)
{
    switch (faza)
    {
        case MT_PELNIA:
            return "okragla tarcza " + dop + " w pelni";
        case MT_PO_PELNI:
            return mia + ", niedawno bedacy w pelni";
        case MT_PIERWSZA_KWADRA:
            return mia + " w pierwszej kwadrze";
        case MT_PRZED_NOWIEM:
            return "cienki sierp starego " + dop + ", zblizajacego sie juz "
                 + "do nowiu";
        case MT_NOW:
            return "czarna plama";
        case MT_PO_NOWIU:
            return "cienki sierp mlodego " + dop + ", wychodzacego z nowiu";
        case MT_OSTATNIA_KWADRA:
            return mia + " w ostatniej kwadrze";
        case MT_PRZED_PELNIA:
            return mia + ", zblizajacy sie wlasnie do pelni";
        default:
            throw("Illegal argument: faza = " + faza + ".\n");
    }
}