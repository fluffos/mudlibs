inherit "/std/herb";

#include <herb.h>
#include <pl.h>

create_herb()
{
/*
 * Ustawiamy ogolne nazwy naszego ziola, opisujace jego zewnetrzny wyglad
 */
    ustaw_nazwe( ({ "lisc", "liscia", "lisciowi", "lisc", "lisciem",
        "lisciu" }), ({ "liscie", "lisci", "lisciom", "liscie", "lisciami",
        "lisciach" }), PL_MESKI_NOS_NZYW);
  
/*
 * Oczywiscie przymiotniki...
 */        
    dodaj_przym("czerwony", "czerwoni");
    dodaj_przym("dlugi", "dludzy");
   
/*
 * Ustawiamy odmiane prawdziwej nazwy ziola + rodzaj
 */   
    ustaw_nazwe_ziola( ({ "blumpka", "blumpki", "blumpce", "blumpke",
        "blumpka", "blumpce" }), PL_ZENSKI); 
    
/* Ustawiamy dlugi opis, ktory sie ukarze osobom bedacym w stanie
 * zidentyfikowac nasze ziolo.
 */
    set_id_long("Lisc slynnej rosliny Blumpka, rosnacej wylacznie w "+
        "gestych i goracych lasach rownikowych. Roslina osiaga wysokosc "+
        "2 metrow, zas wlokna z jej lodygi sa uzywane do plecenia lin. "+
        "Przezuwanie jej grubych lisci ponoc przyspiesza gojenie sie "+
        "ran.\n");
        
/* Dlugi opis dla hmm, mniej oswieconych osob.
 */
    set_unid_long("Jakis dziwny, gruby, miazsisty lisc.\n"); 
    
/* 
 * Tablica 3 form czasownika do spozycia ziola we wlasciwy sposob. W naszym
 * przypadku wlasciwym sposobem, czyli takim, ktory wywoluje porzadany
 * efekt jest przezucie. Gracz zawsze moze sprobowac zjesc nasz lisc,
 * ale nie poczuje zadnego efektu.
 * Wymagana tablica powinna zawierac nastepujace formy czasownika: 
 * ({ komenda, 2 osoba, 3 osoba, bezokolicznik })
 */    
    set_ingest_verb( ({ "przezuj", "przezuwasz", "przezuwa", "przezuc" }) );
    
/* Ustawiamy teraz jak wysoko trzeba miec opanowane zielarstwo, zeby
 * moc zidentyfikowac ziolo. W naszym przypadku dajemy 15 - blumpka
 * jest dosyc znana.
 */
    set_id_diff(15);
    
/* Czas na ustalenie, jak ciezko jest znalesc blumpke. Zwazywszy na to,
 * ze roscie w gestych lasach rownikowych, jest ja raczej ciezko znalezc.
 * Stopien trudnosci odnalezienia powinien sie miescic w 
 * przedziale 1 - 10, tak wiec damy jej 7.
 */
    set_find_diff(7);

/* Jak juz wspomnielismy, przezute ziolo leczy troche rany. Troche, 
 * nie za bardzo - 10 hp.
 */
    set_effect(HERB_HEALING, "hp", 10);
    
/*
 * Jeszcze ile sekund musi uplynac, zanim ziolo sie obrobci w proch
 * z przesuszenia. Blumpka, jako lisc rosliny z wilgotego klimatu, 
 * raczej szybo traci wilgosc - 800 sekund.
 */
    set_decay_time(800);
    
 /* I cena ziola w miedzianych monetach...
  */
    set_herb_value(720);
}