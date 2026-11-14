/* Tamedhon MUDlib
 *
 * 2007-11-02 Gralkor
 * P_CNT_STATUS wird geaendert anstelle der "opened"-Variable
 * Nun sollten die Rucksaecke richtig gehen
 *
 * Mon Jan 19 19:13:00 2004  Serii
 * (geoeffnet/geschlossen)bug entfernt
 *
 */
/* Ein Standardbehaelter, aus den man mit kleinen Aenderungen schnell
 * zu einen Lederbeutel, eine Tasche oder einen Sack zu machen. Er ist nicht
 * abschliessbar.
 *
 * Fuer abschliessbare Objekte (magisch, mit Schluessel oder was) bitte
 * 'std/truhe' benutzen! Dieses Objekt kann um einiges mehr.
 *
 * Dokumentation siehe 'man behaelter' bzw 'man truhe'
 *
 *
 * Mon Jan 12 10:52:49 2004, Samtpfote@Tamedhon
 * Bugfix/Anpassung an <container.h>
 * Offene Bugs:
 *  ( ) Man kann immer noch aus geschlossenen Rein/raus nehmen
 *      evtl ne sache in put_and_get.c!
 *  ( ) Spieler sehen Pfade bei offenen Container, die Liste wird
 *      von std/container/description::make_invlist() gemacht.
 *
 *
 * Wed Apr 21 22:12:15 1999, Shannara@Turithil
 *
 * Tue Jul 27 11:57:44 1999, Shannara@Turithil
 * bugfix
 */
#include <properties.h>
#include <container.h>
/* #include <defines.h> */

#define DB(x)	if(find_player("debugger")) \
		    tell_object(find_player("debugger"), break_string(x));

inherit "std/container";

int	opened;

/* mit dieser Funktion kann man ueberpruefen, ob das Objekt ein Behaelter ist
 * oder etwa nicht
 */
int isBehaelter() { return 1; }

/* QueryAllowed() uebergibt 1, wenn man diesen Container oeffnen UND
 * schliessen darf. Bei Bedarf ueberschreiben.
 */
int QueryAllowed() { return 1; }

/* QueryStatus() gibt den Status zurueck */
int QueryStatus()
{
    DB(sprintf("(Behaelter) Status=%i", opened));
    return opened;
}

/* Oeffnen und Schliessen der Truhe, gibt dann Zustand zurueck,
 * beruecksichtigt automatisch QueryAllowed().
 */
int Open()
{
    DB("(Behaaelter) open()");
    if((QueryStatus() == CNT_CLOSED) && QueryAllowed())
    {
	DB("(Behaelter) oeffne Behaelter");
	opened=CNT_OPENED;
	SetProp(P_TRANSPARENT, 1);
    }

    return QueryStatus();
}

int Close()
{
    DB("(Behaaelter) close()");
    if((QueryStatus() == CNT_OPENED) && QueryAllowed())
    {
	DB("(Behaelter) schliesse Behaelter");
	opened=CNT_CLOSED;
	SetProp(P_TRANSPARENT, 0);
    }

    return QueryStatus();
}

/* ------------------------------------------------------------------------ */
int open_fun(string str)
{
    if(!id(str))
    {
    	notify_fail("Was möchtest du denn öffnen?\n");
	return 0;
    }

    DB("(Behaelter) open_fun");

    if(QueryStatus() == CNT_OPENED)
    {
	notify_fail(capitalize(name(WER, 1))+" ist bereits offen!\n");
	return 0;
    }

    if(Open() == CNT_OPENED)
    {
	write("Du öffnest "+name(WEN)+".\n");
	say(capitalize(this_player()->name())+" öffnet "+name(WEN)+".\n");
	SetProp(P_CNT_STATUS, CNT_OPENED);
    }
    else
    {
	write("Irgendwie schaffst du es nicht, "+name(WEN)+" zu öffnen.\n");
    }
    return 1;
}

int close_fun(string str)
{
    if(!id(str))
    {
	notify_fail("Was möchtest du schließen?\n");
	return 0;
    }

    DB("(Behaelter) close_fun");

    if(QueryStatus() == CNT_CLOSED)
    {
	notify_fail(capitalize(name(WER, 1))+" ist schon zu!\n");
	return 0;
    }

    if(Close() == CNT_CLOSED)
    {
	write("Du schließt "+name(WEN)+".\n");
	say(capitalize(this_player()->name())+" schließt "+name(WEN)+".\n");
	SetProp(P_CNT_STATUS, CNT_CLOSED);
    }
    else
    {
	write("Irgendwie schaffst du es nicht, "+name(WEN)+" zu schließen.\n");
    }
    return 1;
}

/* ------------------------------------------------------------------------ */
string short()
{
    string	sh;

    if(QueryProp(P_INVIS)) { return 0; }
    if(sh=QueryProp(P_SHORT))
    {
	if(opened==CNT_OPENED)
	{   return sh+" (geöffnet).\n"; }
	else
	{   return sh+" (geschlossen).\n"; }
    }
    return 0;
}

varargs string long()
{
    string	lo, inv;

    lo=QueryProp(P_LONG);
    if(!QueryProp(P_TRANSPARENT))
    {
	return lo+capitalize(name(WER))+" ist geschlossen.\n";
    }

    inv=make_invlist(this_player(), all_inventory(this_object()));

    if(inv && (inv != ""))
    {	return lo+capitalize(name(WER))+" ist offen und enthält:\n"+inv; }
    else
    {	return lo+capitalize(name(WER))+" ist offen und leer.\n"; }
}

void init()
{
    ::init();

    AddCmd(({"oeffne", "öffne", "oeffnen", "öffnen"}),"open_fun");
    AddCmd(({"schliess", "schliesse", "schließ", "schließe"}),"close_fun");
}

void create()
{
    if(!clonep(this_object())) return 0;
    ::create();

    AddId("Behaelter");			/* analog zu Npc, Living, ... */
    AddId("behaelter");
    AddId("Behälter");			/* analog zu Npc, Living, ... */
    AddId("behälter");

    SetProp(P_GENDER, MALE);
    SetProp(P_NAME, "Behälter");
    SetProp(P_SHORT, "Ein Behälter");
    SetProp(P_LONG, "Ein einfacher Behälter ohne Eigenschaften.\n");
    SetProp(P_TRANSPARENT, 0);
    SetProp(P_MAX_WEIGHT, 0);		/* wieviel Gramm passen rein */
    SetProp(P_WEIGHT_PERCENT, 0);	/* wieviel % kommt nach aussen */

    Close();
}
