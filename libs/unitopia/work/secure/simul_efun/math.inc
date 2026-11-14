// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/math.inc
// Description: Mathematische simul_efuns
// Author:	Francis
//
// $Log: math.inc,v $
// Revision 1.5  2013-03-16 16:33:03  gnomi
// Indexing past string end.
//
// Revision 1.4  2009-04-15 13:44:10  gnomi
// Typo.
//
// Revision 1.3  2001/12/23 11:37:28  gnomi
// str2int: Man kann nun Zahlen verschiedener Basen umwandeln.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

/*
FUNKTION: str2int
DEKLARATION: int str2int(string str, int &value, int base = 10)
BESCHREIBUNG:
str2int wandelt einen String in einen Integer um, und liefert in der
Referenz 'value' diesen Integerwert.
Wenn ein Wert > 0 returned wird, konnte der String nicht vollstaendig
umgewandelt werden wobei der Wert die Stelle anzeigt, an der der
Fehler liegt (1. Buchstabe = 1).
Bsp:
   fehler=str2int("123", &i)    -> i==123; fehler==0;
   fehler=str2int("123abc", &i) -> i==123; fehler==4;
   fehler=str2int("abc", &i)    -> i==0;   fehler==1;
Als Basis wird sofern nicht angegeben 10 genommen.
VERWEISE: to_int, to_float, to_string
GRUPPEN: simul_efun, typen
*/
varargs int str2int(string str, int f, int base) {
    string tmp;
    int i;

    f = 0;
    
    if(!base || base==10)
    {
	if (sscanf(str,"%d%s",f,tmp) && tmp=="")
	    return 0;
	if (tmp)
    	    return strstr(str,tmp)+1;
	else
	    return 1;
    }
    while(i < sizeof(str))
    {
        int c=str[i++];
	if(c>='a' && c<='z')
	    c-='a'-10;
	else if(c>='A' && c<='Z')
	    c-='A'-10;
	else if(c>='0' && c<='9')
	    c-='0';
	else
	    return i;
	
	if(c>=base)
	    return i;
	f = f*base+c;
    }
    return 0;
}

/*
FUNKTION: round
DEKLARATION: int round(float op)
BESCHREIBUNG:
Rundet ein Float-Argument und gibt es als Integer zurueck.

Beispiele:
                round(36.8)             -->      37
                round(-45.4)            -->     -45

GRUPPEN: simul_efun, rechnen
VERWEISE: abs
*/
int round(float op){return to_int(op+(0.5*(op<0.0?-1:1)));}

/*
FUNKTION: xy2pol
DEKLARATION: int *xy2pol(int x, int y)
BESCHREIBUNG:
Transformiert kartesische Koordinaten in Polar-Koordinaten.
Zurueckgegeben wird ein Feld mit zwei Elementen, die
den Winkel und den Radius enthalten.

Uebersteigt der Wert von   x*x+y*y   die Grenzen der Integer-Variablen,
so wird statt einem Feld einfach nur 0 zurueckgeliefert !
GRUPPEN: simul_efun, rechnen
VERWEISE: pol2xy
*/
int *xy2pol(int ix, int iy) {
	float x, y, dist, fgrad;
	int grad;

    x = (float)ix;
    y = (float)iy;

    dist = sqrt(x*x + y*y);
    if (dist <= 0.0)
	return ({ 0 , 0 });
    fgrad = 180.0 * asin(x/dist) / PI;
    if (y < 0.0)
	fgrad = 180.0 - fgrad;
    grad = round(fgrad);
    grad = (grad+360) % 360;

    return ({ grad, round(dist) });
}

/*
FUNKTION: pol2xy
DEKLARATION: int *pol2xy(int grad, int dist)
BESCHREIBUNG:
Transformiert Polar-Koordinaten in kartesische Koordinaten.
Der Nullpunkt fuer den Winkel ist hierbei die Nord-Richtung.

Die Funktion gibt ein Feld mit zwei Elementen zurueck,
die die X- und die Y-Koordinate enthalten.

Ist der Radius kleiner Null bzw uebersteigt er den Werte-Bereich
der Integer-Variablen, so wird statt einem Feld einfach der Wert 0
zurueckgeliefert.
GRUPPEN: simul_efun, rechnen
VERWEISE: xy2pol
*/
int *pol2xy(int igrad, int idist) {
	float grad, dist;
	int x, y;

    grad = (float)igrad;
    dist = (float)idist;

    if (dist <= 0.0)
	return ({ 0, 0 });

    return ({
	round( dist * sin(grad*PI/180.0) ), 
	round( dist * cos(grad*PI/180.0) )
	   });
}

