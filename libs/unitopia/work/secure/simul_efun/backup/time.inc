// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/time.inc
// Description: Funktionen zum Zeithandling
// Author:	Freaky, Francis
// Modified:    Monty (01.08 96): spiel_kurz_datum
//              Sissi (15.05.99): Ueberlaufproblem geloest, alles in
//                                ein konsistentes Schema gepresst.
//		Freaky (16.05.1999) short(v)timestr: Jahr wird mit fuehrender
//			0 angegeben (statt 01.01. 0: 01.01.00)
//		Freaky (20.12.1999) vclock() repariert
//
// $Log: time.inc,v $
// Revision 1.24  2009-07-30 16:50:36  gnomi
// Keine VL-Sommerzeit mehr.
//
// Revision 1.23  2009-04-28 09:45:21  gnomi
// strfvtime() eingebaut.
//
// Revision 1.22  2009-04-16 21:49:51  gnomi
// array_to_time/vtime eingebaut, wenn mktime() verfuegbar ist.
//
// Revision 1.21  2008/01/16 09:54:13  gnomi
// short_format_seconds(0) = "0s"
//
// Revision 1.20  2005/10/20 19:33:53  gnomi
// Indexing past string end.
//
// Revision 1.19  2003/07/31 00:51:05  menaures
// Verweis auf uhrzeit() entfernt
//
// Revision 1.18  2003/06/20 17:32:40  menaures
// Fehlender mm.yy Punkt bei short[v]timestr
//
// Revision 1.17  2003/06/20 02:48:57  gnomi
// Funktionen nutzen jetzt localtime() statt ctime() zu parsen.
//
// Revision 1.16  2003/01/24 01:28:51  gnomi
// file_time: Wenn es nicht um /var/players geht, die Rechte von PO nehmen.
//
// Revision 1.15  2002/11/20 04:15:09  gnomi
// Enzy-Deklaration von short(v)timestr korrigiert.
//
// Revision 1.14  2002/03/10 02:23:20  gnomi
// Typo in Enzy-Doku.
//
// Revision 1.13  2002/03/07 08:34:38  gnomi
// Neue Efuns: timearray/vtimearray
//
// Revision 1.12  2001/12/15 11:11:52  gnomi
// Doku geaendert (Verweise auf Konstanten in simul_efuns.h).
// Alte Funs entfernt.
//
// Revision 1.11  2001/05/10 00:27:53  sissi
// only auch fuer vtimestr und timestr.
//
// Revision 1.10  2001/03/14 17:31:07  freaky
// deprecated Funktion member-array durch member ersetzt.
//
// Revision 1.9  2001/02/28 00:33:15  freaky
// bugfix in short_format_seconds()
//
// Revision 1.8  2001/02/24 23:25:54  sissi
// short_format_seconds und short_format_vseconds hinzugefuegt.
//
// Revision 1.7  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

private static string *wtage = ({ "Sonntag", "Montag", "Dienstag", "Mittwoch",
	    "Donnerstag", "Freitag", "Samstag" });
private static string *monate = ({ "Januar", "Februar", "Maerz", "April",
	    "Mai", "Juni", "Juli", "August", "September", "Oktober",
	    "November", "Dezember" });

/*
FUNKTION: time_to_vtime
DEKLARATION: int time_to_vtime(int time)
BESCHREIBUNG:
Rechnet Realzeit (time(), sec seit 1970) in Spielzeit (vtime(), sec seit 0) um.
VERWEISE: vtime_to_time, time, vtime
GRUPPEN: simul_efun, zeit
*/
int time_to_vtime(int t)
{
    return t - BIRTHDAY;
}

/*
FUNKTION: vtime_to_time
DEKLARATION: int vtime_to_time(int vtime)
BESCHREIBUNG:
Rechnet Spielzeit (vtime(), sec seit 0) in Realzeit (time(), sec seit 1970) um.
VERWEISE: time_to_vtime, time, vtime
GRUPPEN: simul_efun, zeit
*/
int vtime_to_time(int z)
{
    return z + BIRTHDAY;
}

/*
FUNKTION: vtime
DEKLARATION: int vtime()
BESCHREIBUNG:
Liefert die Anzahl der Sekunden seit dem UNItopia besteht.
GRUPPEN: simul_efun, zeit
VERWEISE: time, vtime_to_time, time_to_vtime
*/
int vtime()
{
    return time_to_vtime(time());
}

/*
FUNKTION: vtimestr
DEKLARATION: varargs string vtimestr(int vtime, int only)
BESCHREIBUNG:
Liefert einen String der Form Mittwoch 31. Maerz 12 18:47:15
in Spielzeit, das Analogon fuer Realzeit heisst timestr().
Wenn only == TIMESTR_ONLY_TIME, wird lediglich die Uhrzeit geliefert.
Wenn only == TIMESTR_ONLY_DATE, wird nur das Datum geliefert.
Mit only == TIMESTR_ALL oder wenn dieser Parameter weggelassen wird,
wird Uhrzeit und Datum geliefert. Diese Werte sind in simul_efuns.h definiert.
GRUPPEN: simul_efun, zeit
VERWEISE: vtime, strfvtime, timestr, ctime, time, vtimearray, array_to_vtime
*/
varargs string vtimestr(int clock, int only)
{
    int *t, vier_jahre;

    vier_jahre = clock / SEC_IN_28_YEARS;
    clock %= SEC_IN_28_YEARS;
    t = localtime(clock*TIMEWARP);
    
    if(t[TM_ISDST]) // Sommerzeit rausrechnen
    {
        if(t[TM_HOUR])
	    t[TM_HOUR]--;
	else
	    t = localtime(clock*TIMEWARP - 3600);
    }

    if (only == TIMESTR_ONLY_TIME)
        return sprintf("%02d:%02d:%02d",t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
    if (only == TIMESTR_ONLY_DATE)
	return sprintf("%s %d. %s %d", wtage[t[TM_WDAY]], t[TM_MDAY],
		    monate[t[TM_MON]], t[TM_YEAR]-1970+28*vier_jahre);
    return sprintf("%s %d. %s %d %02d:%02d:%02d", wtage[t[TM_WDAY]],
	    t[TM_MDAY], monate[t[TM_MON]], t[TM_YEAR]-1970+28*vier_jahre,
	    t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
}

/*
FUNKTION: shortvtimestr
DEKLARATION: varargs string shortvtimestr(int spiel_zeit, int full_year, int only)
BESCHREIBUNG:
Liefert einen String mit dem Datum in der Form: TT.MM.JJ hh.mm.ss,
spiel_zeit ist dabei die Anzahl der Sekunden seit 0, in Spielzeit (vtime()).
Wenn full_year ungleich 0 ist, wird die Jahreszahl nicht auf zwei Ziffern
gekuerzt.
Wenn only == TIMESTR_ONLY_TIME, wird lediglich die Uhrzeit geliefert.
Wenn only == TIMESTR_ONLY_DATE, wird nur das Datum geliefert.
Mit only == TIMESTR_ALL oder wenn dieser Parameter weggelassen wird,
wird beides geliefert. Diese Werte sind in simul_efuns.h definiert.
Das Analogon fuer Realzeit ist shorttimestr().
GRUPPEN: simul_efun, zeit
VERWEISE: time, vtime, vtimestr, strfvtime, shorttimestr
*/
varargs string shortvtimestr(int clock, int full_year, int only)
{
    int *t, vier_jahre;
    string jahr;

    vier_jahre = clock / SEC_IN_28_YEARS;
    clock %= SEC_IN_28_YEARS;
    t = localtime(clock*TIMEWARP);

    if(t[TM_ISDST]) // Sommerzeit rausrechnen
    {
        if(t[TM_HOUR])
	    t[TM_HOUR]--;
	else
	    t = localtime(clock*TIMEWARP - 3600);
    }

    if (only == TIMESTR_ONLY_TIME)
        return sprintf("%02d:%02d:%02d",t[TM_HOUR], t[TM_MIN], t[TM_SEC]);

    jahr = to_string(t[TM_YEAR]-1970+28*vier_jahre);
    if (only == TIMESTR_ONLY_DATE)
	return sprintf("%02d.%02d.%s", t[TM_MDAY], t[TM_MON]+1,
		full_year?jahr:jahr[<2..<1]);
    return sprintf("%02d.%02d.%s %02d:%02d:%02d", t[TM_MDAY], t[TM_MON]+1,
	    full_year?jahr:jahr[<2..<1], t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
}

/*
FUNKTION: vclock
DEKLARATION: int vclock()
BESCHREIBUNG:
Liefert einen Integer im Format: hhmmss mit der Spieluhrzeit
GRUPPEN: simul_efun, zeit
VERWEISE: clock, time, timestr, vtime, vtimestr
*/
int vclock()
{
    int *ti;
    int clock = (vtime() % SEC_IN_28_YEARS) * TIMEWARP;
    
    ti = localtime(clock);

    if(ti[TM_ISDST]) // Sommerzeit rausrechnen
    {
        if(ti[TM_HOUR])
	    ti[TM_HOUR]--;
	else
	    ti = localtime(clock - 3600);
    }

    return ti[TM_HOUR] * 10000 +
	   ti[TM_MIN]  * 100 +
	   ti[TM_SEC];
}

/*
FUNKTION: format_vseconds
DEKLARATION: string format_vseconds(int seconds)
BESCHREIBUNG:
Liefert fuer seconds einen String der Form:
'x Tage x Stunden x Minuten x Sekunden'
wobei die Ausgabe in Spielzeit ist.
GRUPPEN: simul_efun, zeit
VERWEISE: time, format_seconds, short_format_seconds, short_format_vseconds
*/

/*
FUNKTION: short_format_vseconds
DEKLARATION: string short_format_vseconds(int seconds)
BESCHREIBUNG:
Liefert fuer seconds einen String der Form:
'xd xh xm xs'
wobei die Ausgabe in Spielzeit ist.
GRUPPEN: simul_efun, zeit
VERWEISE: time, format_seconds, short_format_seconds, format_vseconds
*/
string format_seconds(int seconds);
string short_format_seconds(int seconds);
string format_vseconds(int seconds)
{
    return format_seconds(seconds * TIMEWARP);
}
string short_format_vseconds(int seconds)
{
    return short_format_seconds(seconds * TIMEWARP);
}

/*
FUNKTION: timestr
DEKLARATION: varargs string timestr(int clock, int only)
BESCHREIBUNG:
Gibt einen deutschsprachigen String mit dem Datum und der Uhrzeit zurueck,
welchem clock entspricht. Das Argument clock sollte die Anzahl an Sekunden
seit dem 1. Januar 1970 00:00:00 sein (wird von time() geliefert). Das
Wenn only == TIMESTR_ONLY_TIME, wird lediglich die Uhrzeit geliefert.
Wenn only == TIMESTR_ONLY_DATE, wird nur das Datum geliefert.
Mit only == TIMESTR_ALL oder wenn dieser Parameter weggelassen wird,
wird Uhrzeit und Datum geliefert. Diese Werte sind in simul_efuns.h definiert.
Analogon fuer Spielzeit ist vtimestr().
GRUPPEN: simul_efun, zeit
VERWEISE: time, ctime, strftime, vtimestr, shorttimestr, timearray, array_to_time
*/
varargs string timestr(int clock, int only)
{
    int *t;

    t = localtime(clock);

    if (only == TIMESTR_ONLY_TIME)
        return sprintf("%02d:%02d:%02d",t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
    if (only == TIMESTR_ONLY_DATE)
	return sprintf("%s %d. %s %d", wtage[t[TM_WDAY]], t[TM_MDAY],
		    monate[t[TM_MON]], t[TM_YEAR]);
    return sprintf("%s %d. %s %d %02d:%02d:%02d", wtage[t[TM_WDAY]],
	    t[TM_MDAY], monate[t[TM_MON]], t[TM_YEAR],
	    t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
}

/*
FUNKTION: shorttimestr
DEKLARATION: varargs string shorttimestr(int clock, int full_year, int only)
BESCHREIBUNG:
Liefert einen String mit dem Datum in der Form: TT.MM.JJ hh.mm.ss
clock ist dabei die Anzahl der Sekunden seit 1970 (time()).
Wenn full_year ungleich 0 ist, wird die Jahreszahl nicht auf die letzten
zwei Stellen gekuerzt.
Wenn only == TIMESTR_ONLY_TIME, wird lediglich die Uhrzeit geliefert.
Wenn only == TIMESTR_ONLY_DATE, wird nur das Datum geliefert.
Mit only == TIMESTR_ALL oder wenn dieser Parameter weggelassen wird,
wird beides geliefert. Diese Werte sind in simul_efuns.h definiert.
Das Analogon fuer Spielzeit ist shortvtimestr().
GRUPPEN: simul_efun, zeit
VERWEISE: time, timestr, strftime, vtime, vtimestr, shortvtimestr
*/
varargs string shorttimestr(int clock, int full_year, int only)
{
    int *t;
    string jahr;

    t = localtime(clock);

    if (only == TIMESTR_ONLY_TIME)
        return sprintf("%02d:%02d:%02d",t[TM_HOUR], t[TM_MIN], t[TM_SEC]);

    jahr = to_string(t[TM_YEAR]);
    if (only == TIMESTR_ONLY_DATE)
	return sprintf("%02d.%02d.%s", t[TM_MDAY], t[TM_MON]+1,
		full_year?jahr:jahr[<2..<1]);
    return sprintf("%02d.%02d.%s %02d:%02d:%02d", t[TM_MDAY], t[TM_MON]+1,
	    full_year?jahr:jahr[<2..<1], t[TM_HOUR], t[TM_MIN], t[TM_SEC]);
}

/*
FUNKTION: clock
DEKLARATION: int clock()
BESCHREIBUNG:
Liefert einen Integer im Format: hhmmss mit der Realuhrzeit
GRUPPEN: simul_efun, zeit
VERWEISE: vclock, time, timestr, vtime, vtimestr
*/
int clock()
{
    int *ti;
    
    ti = localtime(time());
    return ti[TM_HOUR] * 10000 +
	   ti[TM_MIN]  * 100 +
	   ti[TM_SEC];
}

/*
FUNKTION: format_seconds
DEKLARATION: string format_seconds(int seconds)
BESCHREIBUNG:
Liefert einen String der Form:
'x Tage x Stunden x Minuten x Sekunden'
GRUPPEN: simul_efun, zeit
VERWEISE: time, format_vseconds, short_format_seconds, short_format_vseconds
*/
/*
FUNKTION: short_format_seconds
DEKLARATION: string short_format_seconds(int seconds)
BESCHREIBUNG:
Liefert einen String der Form:
'xd xh xm xs'
GRUPPEN: simul_efun, zeit
VERWEISE: time, format_vseconds, short_format_vseconds, format_seconds
*/
string format_seconds(int rest)
{
    int tmp;
    string format;

    format = "";
    tmp = rest / 86400;
    if (tmp)
    {
	if (tmp == 1)
	    format += "1 Tag ";
	else
	    format += tmp + " Tage ";
	rest %= 86400;
    }
    tmp = rest / 3600;
    if (tmp)
    {
	if (tmp == 1)
	    format += "1 Stunde ";
	else
	    format += tmp + " Stunden ";
	rest %= 3600;
    }
    tmp = rest / 60;
    if (tmp)
    {
	if (tmp == 1)
	    format += "1 Minute ";
	else
	    format += tmp + " Minuten ";
	rest %= 60;
    }
    if (rest)
    {
	if (rest == 1)
	    format += "1 Sekunde";
	else
	    format += rest + " Sekunden";
    }
    // Wenn die Sekunden genau aufgehen, steht ein Space am Ende!
    if (sizeof(format) && format[<1] == ' ')
	format = format[0..<2];
    return format;
}
string short_format_seconds(int rest)
{
    int tmp;
    string format;

    format = "";
    tmp = rest / 86400;
    if (tmp)
    {
	format += tmp + "d ";
	rest %= 86400;
    }
    tmp = rest / 3600;
    if (tmp)
    {
	format += tmp + "h ";
	rest %= 3600;
    }
    tmp = rest / 60;
    if (tmp)
    {
	format += tmp + "m ";
	rest %= 60;
    }
    if (rest || !sizeof(format))
    {
	format += rest + "s";
    }
    // Wenn die Sekunden genau aufgehen, steht ein Space am Ende!
    if (format[<1] == ' ')
	format = format[0..<2];
    return format;
}

/*
FUNKTION: real_time_diff
DEKLARATION: int real_time_diff(int zeit_von, int zeit_bis)
BESCHREIBUNG:
Liefert aus zwei Spielzeiten (Format: hhmmss)
die Differenz in realen Sekunden zurueck.
Ist der zweite Parameter kleiner als der erste, so wird
ein Spieltag (!) hinzuaddiert.
Anwendung zB bei call_outs.

Beispiel:
       real_time_diff(11259,20011)  -->  314

VERWEISE: vtime, vclock, clock
GRUPPEN: simul_efun, zeit
*/
int real_time_diff(int t1, int t2)
{
    int vd;

    vd = ((t2 % 100) + ((t2 / 100) % 100) * 60 + (t2 / 10000) * 3600) -
	 ((t1 % 100) + ((t1 / 100) % 100) * 60 + (t1 / 10000) * 3600);
    if (vd < 0)
	vd += 86400;
    return vd / TIMEWARP;
}

/*
FUNKTION: file_time
DEKLARATION: int file_time(string file)
BESCHREIBUNG:
Liefert das File-Datum des Files <file>
VERWEISE: file_size, timestr, ctime
GRUPPEN: simul_efun, zeit, file
*/
int file_time(string file)
{
    int *dir;
    
    if(strstr(file,"/var/players/"))
    {
	object to = this_object();
	set_this_object(previous_object());
	dir = get_dir(file,4);
	set_this_object(to);
    }
    else
	dir = get_dir(file, 4);
    
    if (sizeof(dir) == 1)
	return dir[0];
    return -1;
}

/*
FUNKTION: query_up_time
DEKLARATION: int query_up_time()
BESCHREIBUNG:
Gibt die Zeit in Sekunden seit dem letzten System-Start zurueck.
GRUPPEN: simul_efun, zeit
VERWEISE: time
*/
int query_up_time()
{
    return time() - get_extra_wizinfo(0)["start"];
}

/*
FUNKTION: timearray
DEKLARATION: int* timearray(int clock)
BESCHREIBUNG:
Gibt das Datum und die Uhrzeit in einem Array zurueck, welche clock entspricht.
Dabei ist clock die Zahl der Sekunden seit dem 1. Januar 1970 00:00:00 (wird
durch time() geliefert). Das Array enthaelt folgende Elemente:

    timearray(clock)[TM_SEC]:   Sekunden (0-59)
    timearray(clock)[TM_MIN]:   Minuten (0-59)
    timearray(clock)[TM_HOUR]:  Stunden (0-23)
    timearray(clock)[TM_MDAY]:  Tag des Monats (1-31)
    timearray(clock)[TM_MON]:   Monat (1-12)
    timearray(clock)[TM_YEAR]:  Jahr
    timearray(clock)[TM_WDAY]:  Tag in der Woche (Sonntag:0, Montag: 1,...)
    timearray(clock)[TM_YDAY]:  Tag im Jahr (0-365)

Diese Defines gibt es in time.h.
GRUPPEN: simul_efun, zeit
VERWEISE: time, timestr, strftime, array_to_time, vtimearray
*/
int *timearray(int clock)
{
    mixed *t = localtime(clock);
    t[TM_MON]++;
    return t[0..TM_YDAY];
}


/*
FUNKTION: vtimearray
DEKLARATION: int* vtimearray(int clock)
BESCHREIBUNG:
Gibt das Datum und die Uhrzeit in einem Array zurueck, welche der in clock
dargestellten Spielzeit entspricht. (clock wird durch vtime() geliefert.)
Das Array enthaelt folgende Elemente:

    vtimearray(clock)[TM_SEC]:   Sekunden (0-59)
    vtimearray(clock)[TM_MIN]:   Minuten (0-59)
    vtimearray(clock)[TM_HOUR]:  Stunden (0-23)
    vtimearray(clock)[TM_MDAY]:  Tag des Monats (1-31)
    vtimearray(clock)[TM_MON]:   Monat (1-12)
    vtimearray(clock)[TM_YEAR]:  Jahr
    vtimearray(clock)[TM_WDAY]:  Tag in der Woche (Sonntag:0, Montag: 1,...)
    vtimearray(clock)[TM_YDAY]:  Tag im Jahr (0-365)

Diese Defines gibt es in time.h.
GRUPPEN: simul_efun, zeit
VERWEISE: vtime, vtimestr, strfvtime, array_to_vtime, timearray
*/
int *vtimearray(int clock)
{
    int vc = (clock%SEC_IN_28_YEARS)*TIMEWARP;
    mixed *t = localtime(vc);

    if(t[TM_ISDST]) // Sommerzeit rausrechnen
    {
        if(t[TM_HOUR])
	    t[TM_HOUR]--;
	else
	    t = localtime(vc - 3600);
    }

    t[TM_MON]++;
    t[TM_YEAR] += 28*(clock/SEC_IN_28_YEARS)-1970;
    return t[0..TM_YDAY];
}

#if __EFUN_DEFINED__(mktime)
/*
FUNKTION: array_to_time
DEKLARATION: int array_to_time(int* arr)
BESCHREIBUNG:
Liefert zu einem Array (wie es von timearray() geliefert wurde)
die zugehoerige Anzahl an Sekunden seit 1970.
GRUPPEN: simul_efun, zeit
VERWEISE: time, timestr, timearray, array_to_vtime
*/
int array_to_time(int* arr)
{
    int *t = arr + ({0});
    int *tb;
    int res;
    
    t[TM_MON]--;
    
    res= mktime(t);
    tb = localtime(res);
    if(tb[TM_ISDST])
    {
	t[TM_ISDST] = 1;
	return mktime(t);
    }
    
    return res;
}

/*
FUNKTION: array_to_vtime
DEKLARATION: int array_to_vtime(int* arr)
BESCHREIBUNG:
Liefert zu einem Array (wie es von vtimearray() geliefert wurde)
die zugehoerige Anzahl an Sekunden, seit UNItopia besteht.
GRUPPEN: simul_efun, zeit
VERWEISE: vtime, vtimestr, vtimearray, array_to_time
*/
int array_to_vtime(int* arr)
{
    int *t = arr + ({0});
    int *tb;
    int res;
    int y28;
    
    y28 = t[TM_YEAR] / 28;
    t[TM_YEAR] = t[TM_YEAR] % 28 + 1970;
    t[TM_MON]--;
    
    res= mktime(t);
    tb = localtime(res);
    if(tb[TM_ISDST])
    {
	t[TM_ISDST] = 1;
	t[TM_HOUR] += 1;
	res = mktime(t);
    }
    
    return res/TIMEWARP + y28*SEC_IN_28_YEARS;
}
#endif

#if __EFUN_DEFINED__(strftime)
/*
FUNKTION: strfvtime
DEKLARATION: string strftime([string fmt] [, int clock] [, int localized])
BESCHREIBUNG:
Liefert die Spielzeit als formatierten String zurueck. Das Format kann
vom Benutzer mit Hilfe von Platzhaltern im Formatstring angegeben werden.
clock ist dabei die Anzahl der Sekunden seit 0, in Spielzeit (vtime()).

Alle moeglichen Platzhalter im Formatstring sind in der Hilfe zu
strftime() dokumentiert.
GRUPPEN: simul_efun, zeit
VERWEISE: strftime, vtime, vtimestr, vtimearray, array_to_vtime
*/
string strfvtime(varargs mixed *args)
{
    string fmt, res;
    int clock, sommerzeit;
    int *t;
    
    if(sizeof(args) && stringp(args[0]))
    {
	fmt = args[0];
	args = args[1..];
    }
    else
	fmt = "%c";

    if(sizeof(args) && intp(args[0]))
    {
	clock = args[0];
	args = args[1..];
    }
    else
	clock = vtime();

    t = localtime((clock%SEC_IN_28_YEARS)*TIMEWARP);

    if(t[TM_ISDST]) // Sommerzeit rausrechnen
    {
	clock -= 400; // 1 VL-Stunde
	t = localtime((clock%SEC_IN_28_YEARS)*TIMEWARP);
	if(!t[TM_ISDST])
	{
	    // Fuer die eine Stunde, wenn die Zeit von
	    // Winter- auf Sommerzeit vorspringt.
	    sommerzeit=1;
	    clock += 400;
	}
    }

    // Wir muessen die Jahreszahlen rausfischen:
    fmt = implode(map(regexplode(fmt, "%[^EO0]|%[EO0].|\e"),
    ([
	"\e": "\e\e",
	"%c": sommerzeit?"%a %d %B \e1%Y\e0 \e5%H\e0:%M:%S":"%a %d %B \e1%Y\e0 %X",
	"%C": "\e3%Y\e0",
	"%D": "%m/%d/\e2%Y\e0",
	"%G": "\e1%Y\e0",
	"%g": "\e2%Y\e0",
	"%x": "%d.%m.\e1%Y\e0",
	"%y": "\e2%Y\e0",
	"%Y": "\e1%Y\e0",
	"%z": "",
	"%Z": "",
	"%Ec": sommerzeit?"%a %d %B \e1%Y\e0 \e5%H\e0:%M:%S":"%a %d %B \e1%Y\e0 %X",
	"%EC": "\e3%Y\e0",
	"%Ex": "%d.%m.\e1%Y\e0",
	"%Ey": "\e2%Y\e0",
	"%EY": "\e1%Y\e0",
	"%Oy": "\e2%Y\e0",
	"%z": "+0100",
	"%Z": "+CET",
    ]) + (sommerzeit?
    ([
	"%H": "\e5%H\e0",
	"%I": "\e5%I\e0",
	"%k": "\e4%k\e0",
	"%l": "\e4%l\e0",
	"%r": "\e5%I\e0:%M:%S %p",
	"%R": "\e5%H\e0:%M",
	"%T": "\e5%H\e0:%M:%S",
	"%X": "\e5%H\e0:%M:%S",
	"%Er": "\e5%I\e0:%M:%S %p",
	"%ER": "\e5%H\e0:%M",
	"%ET": "\e5%H\e0:%M:%S",
	"%EX": "\e5%H\e0:%M:%S",
	"%OH": "\e5%H\e0",
	"%OI": "\e5%I\e0",
	"%Ok": "\e4%k\e0",
	"%Ol": "\e4%l\e0",
	"%Or": "\e5%I\e0:%M:%S %p",
	"%OR": "\e5%H\e0:%M",
	"%OT": "\e5%H\e0:%M:%S",
    ]):([]))),"");

if(this_player() && "gnomi"==({string})this_player()->query_real_name())
    printf("Sommerzeit: %Q\n", sommerzeit);
    
    res = strftime(fmt, (clock%SEC_IN_28_YEARS)*TIMEWARP, args...);
    return regreplace(res, "\e\e|\e[1-5][0-9]*\e0",
	function string(string txt) : int diff = 28*(clock/SEC_IN_28_YEARS) - 1970
	{
	    int nr;
	    
	    if(txt == "\e\e")
	        return "\e";
	    
	    nr = to_int(txt[2..<3]) + diff;
	    switch(txt[1])
	    {
	        case '1': // vierstelliges Jahr
		    return sprintf("%d", nr);
		case '2': // zweistelliges Jahr
		    return sprintf("%02d", nr%100);
		case '3': // Jahrhundert
		    return sprintf("%d", nr/100);
	        case '4': // Stundenzahl
		    return sprintf("%d", nr - diff - 1);
	        case '5': // zweistellige Stundenzahl
		    return sprintf("%02d", nr - diff - 1);
	    }
	    
	    return "";
	}, 1);
}
#endif
