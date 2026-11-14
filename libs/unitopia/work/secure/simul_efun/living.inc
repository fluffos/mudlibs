// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/living.inc
// Description: Living-routinen
// Author:	Freaky (10.09.94) von Amylaar uebernommen und angepasst
// Modified by:	Freaky (28.10.94) start_simul_efun umbenannt in create
// 		Freaky (21.02.96) player_exists weniger Checks
//		Freaky (12.10.1999) global_info eingefuehrt und
//			wizardshellp nach util.inc verschoben
//
// $Log: living.inc,v $
// Revision 1.7  2012-11-16 18:07:04  gnomi
// find_player(): An playerp() statt query_once_interactive() orientieren.
//
// Revision 1.6  2006/12/30 01:01:34  menaures
// Reset anstelle von Callout-Schleife
//
// Revision 1.5  2005/12/06 07:51:54  gnomi
// set_living_name ist nicht mehr protected (wegen 3.3.712 Build 2248).
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

/* --- Globale Variablen: --- */
private static mapping living_name_m, name_living_m;

/* --- Initialisierung: --- */
protected void living_create()
{
    living_name_m = global_info["living_name"] ||= m_allocate(0, 1);
    name_living_m = global_info["name_living"] ||= m_allocate(0, 1);
}

protected void living_reset()
{
    /* There might be destructed objects as keys. */
    m_indices(living_name_m);

    if (find_call_out("clean_name_living_m") < 0)
    {
	call_out("clean_name_living_m", 1,
                 m_indices(name_living_m), sizeof(name_living_m));
    }
}

static void clean_name_living_m(string *keys, int left)
{
    // TODO: Was ist das denn...

    int i, j;
    mixed a;

    if (left)
    {
	if (pointerp(a = name_living_m[keys[--left]]) && member(a, 0)>=0 )
       	{
	    i = sizeof(a);
	    do
	    {
		if (a[--i])
		    a[<++j] = a[i];
	    } while (i);
	    name_living_m[keys[left]] = a = j > 1 ? a[<j..] : a[<1];
	}
	if (!a)
	    m_delete(name_living_m, keys[left]);
	call_out("clean_name_living_m", 1, keys, left);
    }
}

/* --- Simul-Efuns: --- */
#if 0
mapping query_living_name_m() { return living_name_m; }
mapping query_name_living_m() { return name_living_m; }
#endif

/*
FUNKTION: find_player
DEKLARATION: object find_player(string name)
BESCHREIBUNG:
Findet den Spieler mit dem Namen 'name'
Die Funktion liefert das Player-Objekt des Spielers.
'name' muss dabei der Name sein, der mit set_living_name() gesetzt wurde.
VERWEISE: set_living_name, find_living, find_object
GRUPPEN: simul_efun, player, objekt
*/
object find_player(string name)
{
    mixed *a, r;
    int i;

    if (pointerp(r = name_living_m[name]))
    {
	if ( !(r = (a = r)[0]) || !MASTER_OB->playerp(r))
       	{
	    for (i = sizeof(a); --i;)
	    {
		if (a[<i] && MASTER_OB->playerp(a[<i]))
	       	{
		    r = a[<i];
		    a[<i] = a[0];
		    return a[0] = r;
		}
	    }
	    return 0;
	}
	return r;
    }
    return r && MASTER_OB->playerp(r) && r;
}

/*
FUNKTION: set_living_name
DEKLARATION: void set_living_name(string name)
BESCHREIBUNG:
Mit dieser Funktion kann man den Namen eines Lebewesens setzen,
so dass das Lebewesen spaeter mit find_living(name) gefunden werden
kann. Der Name wird in einen Hash-Table eingetragen.
Die Funktion kann nur auf Lebewesen angewandt werden, die mit
enable_commands() als solche gekennzeichnet wurden.
In /i/monster/monster und /obj/monster wird dies bei NPCs automatisch gemacht.

Jedes Lebewesen kann nur einen Namen bekommen, der im Hash-Table
eingetragen wird.
Der Name sollte klein geschrieben sein, da es sonst zu Fehlern kommen kann.

ACHTUNG: Nicht verwenden, sondern stattdessen set_npc_name() verwenden.

VERWEISE: lfun::set_npc_name, find_living, enable_commands, find_player, query_living_name
GRUPPEN: simul_efun, monster
*/
void set_living_name(string name)
{
    string old;
    mixed a;
    int i;

    if (old = living_name_m[previous_object()])
    {
	if (pointerp(a = name_living_m[old]))
       	{
	    a[member(a, previous_object())] = 0;
	}
       	else
       	{
	    m_delete(name_living_m, old);
	}
    }
    living_name_m[previous_object()] = name;
    if (a = name_living_m[name])
    {
	if (!pointerp(a))
       	{
	    name_living_m[name] = ({a, previous_object()});
	    return;
	}
	/* Try to reallocate entry from destructed object */
	if ((i = member(a, 0)) >= 0)
       	{
	    a[i] = previous_object();
	    return;
	}
	name_living_m[name] = a + ({previous_object()});
	return;
    }
    name_living_m[name] = previous_object();
}

/*
FUNKTION: query_living_name
DEKLARATION: string query_living_name(object ob)
BESCHREIBUNG:
Liefert den mit 'set_living_name' gesetzten Namen.
VERWEISE: set_living_name, find_living, find_player, find_object
GRUPPEN: simul_efun, monster
*/
string query_living_name(object ob)
{
    return living_name_m[ob];
}

/*
FUNKTION: find_living
DEKLARATION: object find_living(string name)
BESCHREIBUNG:
Diese Funktion sucht das Lebewesen mit dem Namen 'name' und liefert
dessen Objekt-Pointer. 'name' muss hierbei der Name sein,
der mit set_living_name() gesetzt murde.

Beispiel:
  object ob;
  ob = find_living("detlef");

VERWEISE: set_living_name, find_player, find_object, query_living_name
GRUPPEN: simul_efun, monster
*/
object find_living(string name)
{
    mixed *a, r;
    int i;

    if (pointerp(r = name_living_m[name]))
    {
	if ( !living(r = (a = r)[0]))
       	{
	    for (i = sizeof(a); --i;)
	    {
		if (living(a[<i]))
	       	{
		    r = a[<i];
		    a[<i] = a[0];
		    return a[0] = r;
		}
	    }
	}
	return r;
    }
    return living(r) && r;
}


/*
FUNKTION: player_exists
DEKLARATION: int player_exists(string name)
BESCHREIBUNG:
Schaut nach, ob es einen Spieler mit diesem Namen gibt.
VERWEISE:
GRUPPEN: simul_efun, player
*/
 
int player_exists(string name)
{
    if (stringp(name) && member(name,'.') == -1 && member(name,' ') == -1)
       	// && strlen(name) >= 3)
    {
	name = lower_case(name);
	return file_size(PLAYER_FILE(name) + ".o") > 0;
    }
}

/*
FUNKTION: query_livings
DEKLARATION: object *query_livings()
BESCHREIBUNG:
Liefert alle Objekte, die einen Living-Namen haben.
VERWEISE: set_living_name
GRUPPEN: simul_efun, monster
*/
object *query_livings()
{
    return m_indices(living_name_m);
}
