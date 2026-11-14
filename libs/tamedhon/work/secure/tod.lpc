/* SilberLand MUDlib
 *
 * /secure/tod.c -- time-of-day (?)
 *
 * $Date: 1997/03/15 23:49:09 $
 * $Revision: 1.1 $
 * $Log: tod.c,v $
 * Revision 1.1  1997/03/15 23:49:09  Woody
 * prepared for revision control
 *
 */

/*
NAME:
	string time2string( strinmg format, int time )
ARGUMENTE:
	format: String, der das Format der Zeitausgabe festlegt.
	time: Eine Anzahl von Sekunden, die ausgegeben werden soll.
ERGEBNIS:
	Zeit in string-Form.
FUNKTION:
	Der Formatstring wird zurueckgegeben, wobei bestimmte Ersetzungs-
	symbole durch passende Daten, die aus der Zeit berechnet werden,
	ersetzt werden. Die Ersetzungssymbole funktionieren aehnlich
	denen aus 'printf' bekannten Symbolen. Insbesonder kann eine
	Feldbreite mit angegeben werden.

	Folgende Ersetzungssymbole sind erlaubt:
		%%	wird durch ein Prozent (%) ersetzt.
		%d,%h,%m,%s
			werden durch die Anzahl der Tage, Stunden, Minuten
			oder Sekunden ersetzt. Die Werte fuer Minuten und
			Sekunden liegen zwischen 0 und 59, der Wert fuer
			Stunden zwischen 0 und 23.
		%D	wird durch die Worte 'Tag' oder 'Tage' ersetzt,
			je nachdem welchen Wert %d haette.
		%H,%M,%S
			werden durch die Worte 'Stunde(n)', 'Minute(n)'
			bzw. 'Sekunde(n)' ersetzt.
		%X	wird durch die groesste Zeiteinheit ersetzt, die
			nicht Null ist.
		%x	wird durch den numerischen Wert dieser Zeiteinheit
			ersetzt.
			
BEISPIELE:
	time2string( "%m %M", 60 ) -> "1 Minute"
	time2string( "%m %M", 120 ) -> "2 Minuten"
	time2string( "%d:%02h:%02m:%02s", 10000 ) -> "0:02:46:40"
	time2string( "%x %X", 3600 ) -> "1 Stunde"
	time2string( "%x %X", 360000 ) -> "4 Tage"
SIEHE AUCH:
	"printf"
*/
string time2string( string format, int time )
{
  int days,hours,mins,secs,i,ch;
  string *parts, fmt;

  secs = time % 60;
  mins = (time/60) % 60;
  hours = (time/3600) % 24;
  days = (time/86400);

  parts = regexplode( format, "\(%\(-|\)[0-9]*[dhmsxDHMSX]\)|\(%%\)" );
  for( i=1; i<sizeof(parts); i+=2 )
  {
    fmt = parts[i][0..<2];
    ch = parts[i][<1];
    if( ch=='x' )
    {
      if( days>0 ) ch='d';
      else if( hours>0 ) ch='h'; else ch = (mins>0) ? 'm' : 's';
    } else if( ch=='X' )
    {
      if( days>0 ) ch='D';
      else if( hours>0 ) ch='H'; else ch = (mins>0) ? 'M' : 'S';
    }
    switch( ch )
    {
      case 'd': parts[i] = sprintf( fmt+"d", days ); break;
      case 'h': parts[i] = sprintf( fmt+"d", hours ); break;
      case 'm': parts[i] = sprintf( fmt+"d", mins ); break;
      case 's': parts[i] = sprintf( fmt+"d", secs ); break;
      case 'D':
        parts[i] = sprintf( fmt+"s", (days==1) ? "Tag" : "Tage" );
        break;
      case 'H':
        parts[i] = sprintf( fmt+"s", (hours==1) ? "Stunde" : "Stunden" );
        break;
      case 'M':
        parts[i] = sprintf( fmt+"s", (mins==1) ? "Minute" : "Minuten" );
        break;
      case 'S':
        parts[i] = sprintf( fmt+"s", (secs==1) ? "Sekunde" : "Sekunden" );
        break;
      case '%':
        parts[i] = "%";
        break;
      }
    }
    destruct(this_object()); // better debugging :-)
    return implode( parts, "" );
}

