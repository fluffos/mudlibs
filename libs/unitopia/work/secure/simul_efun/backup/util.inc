// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/util.inc
// Description: Diverse simul_efun Goodies fuer den alltaeglichen Gebrauch
// Author:	Freaky, Francis, Garthan
// Modified by: Kurdel (27.01.97) cond_present
//		Parsec (12.10.1999) get_unique_string
//		Freaky (12.10.1999) wizardshellp von living.inc hierher
//
// $Log: util.inc,v $
// Revision 1.27  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.26  2012-12-11 22:09:20  gnomi
// users() und query_idle() nach interactive.inc ausgelagert.
//
// Revision 1.25  2012-11-27 22:13:23  gnomi
// query_idle() fuer InterMUD-Gaeste.
//
// Revision 1.24  2011-02-04 23:19:40  gnomi
// Neue Sefuns: read/write_bits.
//
// Revision 1.23  2007/12/05 11:21:33  gnomi
// deep_present: Abkuerzung, falls 'was' bereits ein Objektpointer ist.
//
// Revision 1.22  2007/08/09 22:30:09  gnomi
// cond_deep_present: Leere Objekte beachten.
//
// Revision 1.21  2005/03/19 22:12:53  menaures
// foldl und foldr ein varargs mixed * args spendiert
//
// Revision 1.20  2004/10/15 22:16:00  gnomi
// foldl und foldr eingefuehrt.
//
// Revision 1.19  2004/08/27 13:13:53  menaures
// playerp(object ob) -> playerp(mixed ob)
// users() liefert nur noch Clones von /obj/player und /obj/newplayer
//
// Revision 1.18  2003/11/25 00:06:44  gnomi
// Shout-Log deaktiviert, uebernimmt jetzt /secure/event.
//
// Revision 1.17  2003/11/11 03:13:04  gnomi
// call_with_this_player eingebaut.
//
// Revision 1.16  2003/09/30 22:43:24  gnomi
// /obj/pplayer bei users() rausfiltern.
//
// Revision 1.15  2003/08/15 03:20:44  gnomi
// cond_deep_present: Fehler bei Gegenstaenden ohne Inhalt.
//
// Revision 1.14  2003/07/09 02:27:17  gnomi
// call_proved: AUch einen String als Objektangabe akzeptieren.
//
// Revision 1.13  2003/06/20 02:48:36  gnomi
// Doku korrigiert.
//
// Revision 1.12  2003/02/18 01:30:49  gnomi
// get_unique_string: Doppelpunkt nicht als Trenner verwenden, da dies auch ein
// Trenner beim sage-Befehl ist.
//
// Revision 1.11  2003/01/04 02:26:22  gnomi
// Neue Simul-efun call_proved.
//
// Revision 1.10  2002/11/20 04:14:15  gnomi
// cond_deep_present: Neue Betriebsart CDP_FLAT.
//
// Revision 1.9  2002/10/29 01:47:02  gnomi
// Neue sefun: cond_deep_present: Ersetzt deep_present vollstaendig und
// beinhaltet Funktionalitaet aehnlich cond_present.
//
// Revision 1.8  2002/02/24 21:25:47  gnomi
// Typo.
//
// Revision 1.7  2001/12/29 01:04:43  sissi
// player_present Doku verbessert.
//
// Revision 1.6  2001/12/16 04:20:04  gnomi
// player_present: Auch NOLIST oder HIDDEN mit Ignoranz zollen koennen.
//
// Revision 1.5  2001/12/15 11:11:25  gnomi
// player_present erhaelt weiteren Parameter.
//
// Revision 1.4  2001/04/04 20:51:11  freaky
// Doku fuer shout eingefuehrt.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

/**
FUNKTION: clonep
DEKLARATION: int clonep( [object ob] )
BESCHREIBUNG:
Returned 1, falls das Objekt ob mit clone_object() erschafft (gecloned) wurde,
und 0, falls es mit touch() geladen wurde.
Default fuer ob ist this_object()

ACHTUNG: clonep() bedeutet hierbei, dass geschaut wird, ob der Filename
         in der Art '/dir/file#nummer' ist. clonep() liefert also bei
	 MAP-Raeumen 0, obwohl diese von /map/map gecloned werden, und
	 dann umbenannt werden.
	 efun::clonep() liefert in diesem Fall (clone und rename) 1
	 clonep() liefert hierbei 0

Beschreibung von efun::clonep()

        The efun returns 1 if <obj> is a clone, and 0 if it is not.
        The <obj> can be given as the object itself, or by its name.
        If <obj> is omitted, the current object is tested.

GRUPPEN: simul_efun, objekt, player
VERWEISE: playerp, objectp, load_name, clone_object
*/
varargs int clonep(object ob)
{
    string file;
    int junk;

    if (!ob)
	ob = previous_object();

    return objectp(ob) && sscanf(object_name(ob),"%s#%d",file,junk) == 2;
}


/*
FUNKTION: playerp
DEKLARATION: int playerp(mixed ob)
BESCHREIBUNG:
Returned 1, wenn das ob ein Spieler ist, ansonsten 0.
GRUPPEN: simul_efun, objekt
VERWEISE: clonep
*/
int playerp(mixed ob)
{
    return objectp(ob) && MASTER_OB->playerp(ob);
}


/*
FUNKTION: wizardshellp
DEKLARATION: int wizardshellp()
BESCHREIBUNG:
Gibt den Level des Wiz-Shell-Besitzers zurueck, FALLS es sich bei
dem Objekt um eine Wizard - Shell handelt.
GRUPPEN: simul_efun, objekt
VERWEISE: playerp, clonep
*/
int wizardshellp(object ob)
{
    if (playerp(ob) && !strstr(object_name(ob),"/obj/wizard_shell#"))
        return ({int})ob->query_level();
    return 0;
}


/*
FUNKTION: get_align_string
DEKLARATION: string get_align_string(int align)
BESCHREIBUNG:
Liefert einen String zurueck, welcher Gesinnung ein Lebewesen ist.
(von "heilig" bis "daemonisch")
GRUPPEN: simul_efun, player
VERWEISE: 
*/
string get_align_string(int i)
{
    if (i > A_HEILIG)
	return "heilig";
    if (i > A_GUT)
	return "gut";
    if (i > A_NETT)
	return "nett";
    if (i >= A_MIES)
	return "neutral";
    if (i >= A_TEUFLISCH)
	return "mies";
    if (i >= A_DAEMONISCH)
	return "teuflisch";
    return "daemonisch";
}


/*
FUNKTION: shout
DEKLARATION: void shout(string str)
BESCHREIBUNG:
Der Aufruf dieser Funktion erzeugt ein Ereignis im Kanal "Gebruell",
welcher ueber den Kurier (EVENT_MASTER) verteilt wird.
GRUPPEN: simul_efun
*/
void shout(string str)
{
#if 0
   // Mal ein bisschen Aufwand, damit man auch den wirklichen Urheber eines
   // Monsterbruellers erwischt (bisher bei zwinge monstet bruelle blabla: 0
   string temp;

   if (this_player())
      temp = ({string})this_player()->query_real_name();
   if (!temp && this_interactive())
      temp = ({string})this_interactive()->query_real_name();
   if (!temp && previous_object())
      temp = ({string})previous_object()->query_real_name();
   sys_log("SHOUTS", temp + ": " + str + "\n");
#endif
   EVENT_MASTER->event("Gebruell", this_player(), str);
}

/*
FUNKTION: deep_present
DEKLARATION: object deep_present(mixed was, object wo)
BESCHREIBUNG:
deep_present sucht im Objekt 'wo' und in allen darin enthaltenen Objekten
nach 'was', wobei 'was' eine ID oder ein Objekt sein kann.

deep_present wird wie present aufgerufen, benoetigt aber immer
den zweiten Parameter.

Dies und noch mehr kann cond_deep_present. Wenn es nur mit diesen beiden
Parametern aufgerufen wird, verhaelt es sich genauso wie deep_present.

VERWEISE: cond_deep_present, present
GRUPPEN: simul_efun, objekt
*/
object deep_present(mixed was, object wo)
{
   object *inv, ob;
   int i;

    if (!wo)
	return 0;
    if (objectp(was))
	return (member(all_environment(was)||({}), wo)>=0)?was:0;
    if (ob = present(was, wo))
	return ob;
    if (!(inv = all_inventory(wo)))
	return 0;
    for(i = 0; i < sizeof(inv); i++)
	if (ob = deep_present(was, inv[i]))
	    return ob;
}


/*
FUNKTION: cond_present
DEKLARATION: object cond_present(string was, object wo, mixed fun, [ mixed args])
BESCHREIBUNG:
cond_present (conditional present) sucht im Objekt 'wo' nach dem ersten
Objekt ob mit der id 'was', welches beim Aufruf von ob->fun(arg1, arg2, ...)
einen Wert != 0 zurueckgibt.
args koennen beliebig viele Parameter arg1, arg2, ... sein.
fun kann auch eine Closure sein, die dann mit ob als erstem Parameter und
arg1, arg2, ... als restliche Parameter aufgerufen wird.
Ist fun weder ein String noch eine Closure, liefert es present(was, wo)
zurueck.
Ist die id 'was' 0 oder "", dann wird nicht auf die id geachtet.

Anwendungsbeispiele:

Eine Fackel im Fackelhalter, hidden_until_next_move
Ist eine Fackel im Fackelhalter:
   if (cond_present("fackel",this_object(),"query_invis"))
(In den Raum gelegte sichtbare Fackeln stoeren so nicht.)
Besser noch den Fackelhalter zum echten Container machen ...

Hat der Spieler einen bestimmten Schutzmantel angezogen (!) gegen
Hitze/Kaelte/Saeure ... ?
   if (cond_present("schutzmantel",this_player(),"query_worn"))
Inkorrekt ist das naheliegende
   if ((mantel = present("schutzmantel", this_player())) &&
	    mantel->query_worn())
es koennte ja von zwei Maenteln erst der zweite angezogen sein.

Hat ein Spieler ein reissfestes Seil aus Leder?
   cond_present("seil", player, "material", "leder")

Hat ein Spieler eine Waffe mit Wirkung gegen das Monster dabei?
   cond_present("waffe", this_player(), "query_extra_damage", monster, player)

Ist hier jemand oder etwas im Raum aggressiv ?
   cond_present(0, room, "query_aggressive")

Gibts ein Lebewesen im Raum?
   cond_present(0, room, #'living)


Dies und noch mehr kann cond_deep_present.
cond_deep_present(was, wo, CDP_FLAT, fun, ...) verhaelt sich voellig identisch.

VERWEISE: cond_deep_present, present
GRUPPEN: simul_efun
*/
varargs object cond_present(string was, object wo, varargs mixed args)
{
   closure cl;
   object *obs;
   int i,end;

   if (stringp(args[0]))
      cl = #'call_other;
   else if (closurep(args[0]))
   {
      cl = args[0];
      args = args[1..];
   }
   else
      return present(was, wo);
   if (!wo)
      return 0;
   end = sizeof(obs = all_inventory(wo));
   if (was && was!="")
   {
      for(i = 0; i < end; i++)
         if (obs[i]->id(was) && apply(cl, obs[i], args))
            return obs[i];
   }
   else
      for(i = 0; i < end; i++)
         if (apply(cl, obs[i], args))
            return obs[i];
}

/*
FUNKTION: cond_deep_present
DEKLARATION: varargs object cond_deep_present(string was, object wo, int flags, mixed fun, varargs mixed args)
BESCHREIBUNG:
cond_deep_present (conditional deep present) sucht im Objekt 'wo' und in 
allen darin enthaltenen Objekten nach dem ersten Objekt ob mit der id 'was',
welches beim Aufruf von ob->fun(arg1, arg2, ...) einen Wert != 0 zurueckgibt.

args koennen beliebig viele Parameter arg1, arg2, ... sein.
fun kann auch eine Closure sein, die dann mit ob als erstem Parameter und
arg1, arg2, ... als restliche Parameter aufgerufen wird.
Ist fun weder ein String noch eine Closure, liefert es einfach das erste
gefundene Objekt mit der id 'was' zurueck.
Ist die id 'was' 0 oder "", dann wird nicht auf die id geachtet.

In flags kann angegeben werden, in welcher Reihenfolge die Suche stattfinden
soll (Defines in simul_efuns.h):

	CDP_DEPTH_FIRST		Zuerst in die Tiefe gehen.
	CDP_BREADTH_FIRST	Das Objekt mit der geringsten Tiefe nehmen.
	CDP_FLAT                Nicht in die Tiefe gehen. (gleiche Verhalten
	                        wie cond_present.)

Wurde weder CDP_DEPTH_FIRST, CDP_BREADTH_FIRST noch CDP_FLAT gewaehlt, so wird
der Suchalgorithmus von deep_present genutzt: Erst in allen Objekten innerhalb
von 'wo' suchen, dann rekursiv in den einzelnen Containern von 'wo' suchen.

VERWEISE: cond_present, present
GRUPPEN: simul_efun
*/
varargs object cond_deep_present(string was, object wo, int flags, mixed fun, varargs mixed args)
{
    mixed stack;
    
    if(stringp(fun))
    {
	args = ({fun}) + args;
	fun = #'call_other;
    }
    else if(!closurep(fun))
	fun = 1;
    
    if(!wo)
	return 0;

    switch(flags & CDP_TRAVERSE_BITS)
    {
	case CDP_DEPTH_FIRST:
	    stack = ({first_inventory(wo)})-({0});
	    while(sizeof(stack))
	    {
		if((!was || stack[0]->id(was)) && apply(fun, stack[0], args))
		    return stack[0];
		stack = ({first_inventory(stack[0]), next_inventory(stack[0])}) - ({0}) + stack[1..<1];
	    }
	    break;
	case CDP_BREADTH_FIRST:
	    stack = ({first_inventory(wo)})-({0});
	    while(sizeof(stack))
	    {
		if((!was || stack[0]->id(was)) && apply(fun, stack[0], args))
		    return stack[0];
		stack = (({next_inventory(stack[0])}) + stack[1..<1] + ({first_inventory(stack[0])})) - ({0});
	    }
	    break;
	case CDP_FLAT:
	    foreach(object ob: all_inventory(wo))
		if((!was || ob->id(was)) && apply(fun, ob, args))
		    return ob;
	    break;
	default:
	    stack = ({ wo });
	    while(sizeof(stack))
	    {
		mixed inv = all_inventory(stack[0]);
		foreach(object ob:inv)
		    if((!was || ob->id(was)) && apply(fun, ob, args))
			return ob;
		stack = inv + stack[1..<1];
	    }
	    break;
    }
}

/*
FUNKTION: player_present
DEKLARATION: varargs object player_present(object room, int flags)
BESCHREIBUNG:
Mit dieser Funktion kann man abfragen, ob ein (interaktiver) Spieler sich
in einem Raum befindet.
Wenn kein Argument uebergeben wird, wird this_object() genommen.
Die Funktion liefert den 1. Spieler, der gefunden wird (ansonsten 0)
Mit dem Parameter flags kann man die Menge der betroffenen Spieler
eingrenzen oder erweitern. Es kann eine Kombination (Veroderung) aus den
folgenden in simul_efuns.h definierten Konstanten sein:
  PPRESENT_NO_WIZARDS   Goetter nicht beachten
  PPRESENT_ONLY_LISTED	Spieler mit V_NOLIST-Unsichtbarkeit nicht beachten.
  PPRESENT_NO_HIDDEN	Spieler mit V_HIDDEN-Unsichtbarkeit nicht beachten.
  PPRESENT_NO_SHIMMER   Spieler mit V_SHIMMER-Unsichtbarkeit (z.B. Engel)
                        nicht beachten
  PPRESENT_NO_INVIS     Spieler mit V_INVIS-Unsichtbarkeit (meist Goetter)
                        nicht beachten
  PPRESENT_STATUES      Auch Statuen beachten.
Standardmaessig werden alle interaktiven Spieler (keine Statuen) unabhaengig
von ihrem Level und Sichtbarkeit beachtet.
Das #include <simul_efuns.h> nicht vergessen.
VERWEISE:
GRUPPEN: simul_efun, player
*/
varargs object player_present(object room, int flags)
{
    for (object ob = first_inventory(room || previous_object()); ob;
	    ob = next_inventory(ob))
	if ((interactive(ob) ||
		((flags&PPRESENT_STATUES) && query_once_interactive(ob))) &&
	    !((flags&PPRESENT_NO_WIZARDS) && wizp(ob)) &&
	    !((flags&PPRESENT_ONLY_LISTED) && (({int})ob->query_invis()&V_ATOM_NOLIST)) &&
	    !((flags&PPRESENT_NO_HIDDEN) && IS_HIDDEN(ob)) &&
	    !((flags&PPRESENT_NO_SHIMMER) && IS_INVIS(ob)) &&
	    !((flags&PPRESENT_NO_INVIS) && (({int})ob->query_invis()&V_ATOM_NOSHIMMER)))
		return ob;
}


/*
FUNKTION: Name
DEKLARATION: string Name(object ob)
BESCHREIBUNG:
Liefert einen Cap-Namen des Objektes ob. (fuer Debugzwecke geeignet)
Entweder query_real_name, oder query_name oder query_short,
ansonsten den Filenamen des Objektes
GRUPPEN: simul_efun, objekt
VERWEISE:
*/
string Name(object ob) {
    string tmp;

    if (!objectp(ob))
        return "0";
    tmp=({string})ob->query_real_name();
    if (stringp(tmp) && tmp!="")
        return capitalize(tmp);
    tmp=({string})ob->query_name();
    if (stringp(tmp) && tmp!="")
        return capitalize(tmp);
    tmp=({string})ob->query_short();
    if (stringp(tmp) && tmp!="")
        return capitalize(tmp);
    return "OBJ("+object_name(ob)+")";
}


/*
FUNKTION: arr_delete
DEKLARATION: mixed *arr_delete(mixed *array, int index)
BESCHREIBUNG:
Loescht aus dem Array <array> das Feld mit dem Index <index> und
returned das neue Array.
VERWEISE: m_delete
GRUPPEN: simul_efun, array
*/
mixed *arr_delete(mixed *arr, int i) {
    int s;

    if ((s=sizeof(arr)) && i<s && i>=0)
        arr[i..i]=({});
    return arr;
}


/*
FUNKTION: query_real_player_level
DEKLARATION: int query_real_player_level(object player)
BESCHREIBUNG:
Liefert den Level eines Spielers (wenn 'ob' einer ist)
ansosnten 0
GRUPPEN: simul_efun, player
VERWEISE: playerp
*/
int query_real_player_level(object player)
{
    return playerp(player) && player->query_level();
}

/*
FUNKTION: get_unique_string
DEKLARATION: string get_unique_string()
BESCHREIBUNG:
Funktion liefert einen einmaligen String.
Jeder spaetere Aufruf dieser Funktion liefert garantiert einen
anderen String, auch nach Neustart des Systems.
GRUPPEN: simul_efun
VERWEISE:
*/
string get_unique_string()
{
    return time() + "#" + global_info["unique_count"]++;
}

/*
FUNKTION: call_proved
DEKLARATION: mixed call_proved(string fn|object ob|object *ob, string fun|mapping fun|mixed *fun, varargs mixed *par)
BESCHREIBUNG:
call_proved ist eine Erweiterung von call_other, welche einen Fehler wirft,
wenn die Funktion fun nicht aufrufbar ist (d.h. entweder existiert sie nicht
oder ist static oder private, und ein Shadow mit dieser Funktion ist auch nicht
uebergeworfen).

Gegenueber call_other kann man als Funktion auch Mappings der Form:
    ([
        "funktion1": ({ arg1, arg2, ...}), // Bei mehreren Argumenten
        "funktion2": arg1,                 // Bei einem nicht-Array-Parameter
    ])
oder Arrays der Form:
    ({
	({ "funktion1", arg1, arg2, ... }),
	...
    })
uebergeben.

Das Ergebnis fuer jedes Objekt ist ein Mapping ([ "funktionsname": ergebnis ])
bzw. ein Array mit den Ergebnissen jeder Funktion.
VERWEISE: call_other, call_resolved, call_with_this_player
GRUPPEN: Objekt
*/
mixed call_proved(mixed ob, mixed fun, varargs mixed *par)
{
    object to = this_object();
    mixed res;
    
    set_this_object(previous_object());
    if(stringp(ob))
	ob = load_object(ob);
    
    if(stringp(fun))
    {
	if(objectp(ob))
	{
	    if(!apply(#'call_resolved,&res, ob, fun, par))
		raise_error(sprintf("Function '%s' does not exist in %s.\n",
		    fun, object_name(ob)));
	}
	else if(pointerp(ob))
	{
	    res = allocate(sizeof(ob));
	    for(int i=0;i<sizeof(ob);i++)
	    {
		if(!apply(#'call_resolved, &(res[i]), ob[i], fun, par))
		    raise_error(sprintf("Function '%s' does not exist in %s.\n",
			fun, object_name(ob[i])));
	    }
	}
	else
	    raise_error("Bad argument 1 to call_proved()\n");
    }
    else if(mappingp(fun))
    {
	if(sizeof(par))
	    raise_error("Too many arguments to call_proved.\n");
	if(widthof(fun)!=1)
	    raise_error("Wrong width of argument 2 to call_proved.\n");
	if(objectp(ob))
	{
	    res = copy(fun);
	    foreach(string f, mixed p: fun)
	    {
		res[f]=0;
		if(!apply(#'call_resolved, &(res[f]), ob, f, p))
		    raise_error(sprintf("Function '%s' does not exist in %s.\n",
			f, object_name(ob)));
	    }
	}
	else if(pointerp(ob))
	{
	    res = allocate(sizeof(ob));
	    for(int i=0;i<sizeof(ob);i++)
	    {
		res[i] = copy(fun);
		foreach(string f, mixed p: fun)
		{
		    res[i][f]=0;
		    if(!apply(#'call_resolved, &(res[i][f]), ob[i], f, p))
			raise_error(sprintf("Function '%s' does not exist in %s.\n",
			    f, object_name(ob[i])));
		}
	    }
	}
	else
	    raise_error("Bad argument 1 to call_proved()\n");
    }
    else if(pointerp(fun))
    {
	if(sizeof(par))
	    raise_error("Too many arguments to call_proved.\n");
	if(objectp(ob))
	{
	    res = allocate(sizeof(fun));
	    for(int j=0;j<sizeof(fun);j++)
	    {
		if(!apply(#'call_resolved, &(res[j]), ob, fun[j][0], fun[j][1..<1]))
		    raise_error(sprintf("Function '%s' does not exist in %s.\n",
			fun[j][0], object_name(ob)));
	    }
	}
	else if(pointerp(ob))
	{
	    res = allocate(sizeof(ob));
	    for(int i=0;i<sizeof(ob);i++)
	    {
		res[i] = allocate(sizeof(fun));
		for(int j=0;j<sizeof(fun);j++)
		{
		    if(!apply(#'call_resolved, &(res[i][j]), ob[i], fun[j][0], fun[j][1..<1]))
			raise_error(sprintf("Function '%s' does not exist in %s.\n",
			    fun[j][0], object_name(ob)));
		}
	    }
	}
	else
	    raise_error("Bad argument 1 to call_proved()\n");
    }
    else
	raise_error("Bad argument 2 to call_proved()\n");

    set_this_object(to);
    return res;
}

/*
FUNKTION: call_with_this_player
DEKLARATION: mixed call_with_this_player(string fun|closure cl, varargs mixed *args)
BESCHREIBUNG:
call_with_this_player ruft die Funktion 'fun' im aktuellen Objekt oder
die Closure cl mit den angegebenen Parametern auf.
Dabei wird fuer diesen Aufruf this_player() auf das aktuelle Objekt (falls
es lebt) oder 0 (falls es nicht lebt) gesetzt.
VERWEISE: call_other, call_proved, funcall, apply
GRUPPEN: Monster
*/
mixed call_with_this_player(mixed fun, varargs mixed *args)
{
    object to = this_object();
    object old_tp = this_player();
    mixed ret;

    efun::set_this_player(living(previous_object()) && previous_object());
    set_this_object(previous_object());	// Damit auch static-Funs gehen.

    if(stringp(fun))
        ret = apply(#'call_other, previous_object(), fun, args);
    else
        ret = apply(fun, args);

    set_this_object(to);
    efun::set_this_player(old_tp);
    return ret;
}

// So, mal ein paar Funktionen aus der funktionalen Programmierung... 

/*
FUNKTION: foldl
DEKLARATION: mixed foldl(mixed *array, mixed startwert, closure funktion, ...)
BESCHREIBUNG:

Diese Funktion geht das Array von links nach rechts durch, ruft

    funktion(startwert, element, ...)

fuer jedes Element auf und uebernimmt das Ergebnis als Startwert fuer
das naechste Element. Der letzte ermittelte Wert wird zurueckgeliefert.


BEISPIEL: Um die Summe aller Gegenstaende in 'ob' zu ermitteln:

    foldl(all_inventory(ob), 0, (: $1 + $2->query_weight() :))
    
Als Array werden alle Gegenstaende uebermittelt, Startwert ist 0, als
neuer Wert wird immer das Gewicht das jeweiligen Gegenstands ermittelt.

Hinweis:
Bei foldr() wird das Array nicht nur in der Gegenrichtung durchlaufen,
sondern auch die ersten beiden Parameter an die Closure vertauscht.
VERWEISE: foldr, map, filter, funcall, apply
GRUPPEN: simul_efun, array
*/
mixed foldl(mixed *array, mixed startwert, closure func, varargs mixed * args)
{
    mixed wert = startwert;

    foreach(mixed elem: array)
	wert = apply(func, wert, elem, args);

    return wert;
}

/*
FUNKTION: foldr
DEKLARATION: mixed foldr(mixed *array, mixed startwert, closure funktion, ...)
BESCHREIBUNG:

Diese Funktion geht das Array von rechts nach links durch, ruft

    funktion(element, startwert, ...)

fuer jedes Element auf und uebernimmt das Ergebnis als Startwert fuer
das naechste Element. Der letzte ermittelte Wert wird zurueckgeliefert.


BEISPIEL: Um die Summe aller Gegenstaende in 'ob' zu ermitteln:

    foldr(all_inventory(ob), 0, (: $1->query_weight() + $2 :))
    
Als Array werden alle Gegenstaende uebermittelt, Startwert ist 0, als
neuer Wert wird immer das Gewicht das jeweiligen Gegenstands ermittelt.

Hinweis:
Bei foldl() wird das Array nicht nur in der Gegenrichtung durchlaufen,               
sondern auch die ersten beiden Parameter an die Closure vertauscht.
VERWEISE: foldl, map, filter, funcall, apply
GRUPPEN: simul_efun, array
*/
mixed foldr(mixed *array, mixed startwert, closure func, varargs mixed * args)
{
    mixed wert = startwert;
    
    for(int i=sizeof(array); i--; )
	wert = apply(func, array[i], wert, args);
    
    return wert;
}

/*
FUNKTION: read_bits
DEKLARATION: int read_bits(string str, int start, int length)
BESCHREIBUNG:
Liest aus dem Bitstring eine Zahl ab Bitposition start aus.
*/
int read_bits(string str, int start, int length)
{
    int result = 0;
    start += length;

    while(length--)
        result = (result<<1) + test_bit(str, --start);
    return result;
}

/*
FUNKTION: write_bits
DEKLARATION: string write_bits(string str, int start, int length, int number)
BESCHREIBUNG:
Schreibt die Zahl number in den Bitspring an Position start
und liefert den neuen String zurueck.
*/
string write_bits(string str, int start, int length, int number)
{
    string result = str;

    while(length--)
    {
        if(number&1)
            result = set_bit(result, start++);
        else
            result = clear_bit(result, start++);
        number >>= 1;
    }

    return result;
}
