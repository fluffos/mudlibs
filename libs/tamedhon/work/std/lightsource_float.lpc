// Tamedhon Mudlib
//
// float lightsource by Aloy
// std/lightsource_float.c -- standard light source
//
// $Date: 2005/03/24 19:24:58 $
/* $Revision: 2.2 $
 * $Log: lightsource.c,v $
 * Revision 2.2  1997/06/25 11:20:43  Saxxon
 * function added 'silent_estinguish'
 *
 * Revision 2.1  1997/06/25 11:20:43  Woody
 * Bugfixing
 *
 * Revision 2.0  1997/03/13 03:00:23  Woody
 * prepared for revision control
 *
 * Revision 1.1  96/05/25  18:00:00  Woody
 * short() Aenderungen wieder retour
 *
 * Revision 1.0  22/02/96  23:00:00  Hadra
 * short() geaendert
 */

inherit "std/thing" ;

#include <properties.h>
#include <language.h>
#include <defines.h>

#define TRUE  1
#define FALSE 0
#define bool  int
#define QSP        (PL->QueryProp(P_SP))

#define DFLT_FUEL       20 // 20 Sekunden
#define DFLT_LIGHTDESC  "brennend"
// Facken anzuenden kostet 5 MP (Death@AnderLand, 11.3.1995)
#define SPELL_POINTS 5

// So ergibt sich die Moeglichkeit sie wieder auzufuellen
#define CALL_OUT_TIME   100

#undef DEBUG

int  fuel, max_fuel;
bool lighted;
int  call_time;
float lightval = 0.0;

void test_remove();
void set_lightval(float val);
bool get_lighted();

ENVCHECKPROC

void create()
{
  thing::create() ;

  SetProp( P_NAME, "Lichtquelle" ) ;
  SetProp( P_SHORT, "Eine Lichtquelle" ) ;
  SetProp( P_LONG, "Du siehst nichts besonderes.\n" ) ;
  SetProp( P_GENDER, FEMALE ) ;
  SetProp( P_FUEL, DFLT_FUEL ) ;
  SetProp( P_LIGHTDESC, DFLT_LIGHTDESC ) ;
  SetProp( P_DO_DESTRUCT, TRUE ) ;
  SetProp( P_VALUE, 2 ) ;
  set_lightval(1.0);

  AddId( "Lichtquelle" ) ;
  AddCmd(({"zuende", "zünde"}),"light");
  AddCmd(({"loesche", "lösche"}),"extinguish");

  ENVCHECK
}

void set_lightval(float val)
{
  lightval = val;
}

bool get_lighted()
{
  return lighted;
}

/*
 * Lichtquelle anzuenden
 */
bool light( string str )
{
  string tmp ;

  _notify_fail( "Zünde was an?\n" ) ;

  if( (!str) || (!sscanf( str, "%s an", tmp )) || (!id( tmp )) )
    return FALSE ;

  if( environment() != PL ) // Player hat es nicht
  {
    _notify_fail( "Erstmal musst Du " + name( WEN, 0 ) + " haben.\n" ) ;
    return FALSE ;
  }

  if( lighted )
  {
    _notify_fail( CAP( name( WER, 1 ) ) + " brennt schon.\n" ) ;
    return FALSE ;
  }

  if( fuel <= 0 )
  {
    _notify_fail( CAP( name( WER, 1 ) ) + " ist abgebrannt.\n" ) ;
    test_remove() ;
    return FALSE ;
  }

  if(QSP < SPELL_POINTS)
  {
    _notify_fail("Du hast nicht genügend Magiepunkte zum Anzünden.\n") ;
    return FALSE ;
  }

  lighted = TRUE ;
  call_time = (fuel < CALL_OUT_TIME)? fuel : CALL_OUT_TIME ;
  call_out( "out_of_fuel", call_time ) ;

  if( set_light(lightval) == lightval)
    write( "Mit einem kleinen Feuerball zündest Du "+name( WEN, 0 )+" an.\n"
    +"Du kannst wieder etwas sehen.\n" ) ;
  else
    write( "Mit einem kleinen Feuerball zündest Du "+name( WEN, 0 )+" an.\n" ) ;
  say( PL->Name(WER)
      + " zündet " + name( WEN, 0 ) + " mit einem kleinen Feuerball an.\n" ) ;
  PL->restore_spell_points(-SPELL_POINTS);

  return TRUE ;
}

bool extinguish(string str )
{
  int time ;

  _notify_fail( "Welche Lichtquelle möchtest Du löschen?\n" ) ;

  if( (!str) || (!id( str )) )
    return FALSE ;

  if( !lighted )
  {
    _notify_fail( CAP( name( WER, 1 ) ) + " brennt gar nicht.\n" ) ;
    return FALSE ;
  }

  if( environment() != PL )
  {
    _notify_fail( "Erstmal musst Du " + name( WEN, 0 ) + " haben.\n" ) ;
    return FALSE ;
  }

  if( ( time = remove_call_out( "out_of_fuel" ) ) == -1 )
    time = 0 ;

  fuel -= (call_time - time) ;
  lighted = FALSE ;

  if ( set_light(-lightval) == 0 )
  {
    write( "Es wird dunkel.\n" ) ;
    say( PL->Name(WER) + " macht das Licht aus.\n" ) ;
  }
  else
  {
    write( "Ok.\n" ) ;
    say( PL->Name(WER) + " löscht " + name( WEN, 0 ) + " aus.\n" ) ;
  }

  if( fuel <= 0 ) test_remove() ;
  return TRUE ;
}

bool silent_extinguish()
{
  int time ;
  if( ( time = remove_call_out( "out_of_fuel" ) ) == -1 )
    time = 0 ;
  fuel -= (call_time - time) ;
  set_light(-lightval);
  lighted = FALSE ;
  if( fuel <= 0 ) test_remove() ;
  return TRUE ;
}

int out_of_fuel()
{
  <float|int> res;

  fuel -= call_time;

  if( fuel > 0 )
  {
    call_out( "out_of_fuel", call_time );
    return 1;
  }

  res = set_light(-lightval);
  lighted = FALSE;

  if (environment()==this_player()) {
    if (res == 0) {
      write( CAP( name( WER, 1 ) ) + " erlischt und es wird dunkel.\n" );
      say( "Es wird dunkel als " + PL->name(WESSEN) + " " + QueryProp(P_NAME)
    + " erlischt.\n" );
    } else {
      write( CAP( name( WER, 1 ) ) + " erlischt.\n" );
      say( CAP( name( WER, 0 ) ) + " erlischt.\n" );
    }
  }
  test_remove();
  return 1;
}

void test_remove()
{
  if( QueryProp( P_DO_DESTRUCT ) )
    remove() ;
}

// Brennstoff nachfuellen
void AddFuel( int f )
{
  fuel += f ;
}

// Property - Funktionen

void _set_lighted( bool l )
{
  lighted = l ;
}

bool _query_lighted()
{
  return lighted ;
}

void _set_fuel( int f )
{
  if (f>max_fuel) max_fuel=f;
  fuel = f ;
}

int _query_fuel()
{
  int tmp;

  if ((tmp=find_call_out("out_of_fuel"))>=0)
    return fuel-call_time+tmp;
  else
    return fuel;
}

mixed _query_lightdesc()
{
  string *tmp;
  int n,i;

  tmp=Query(P_LIGHTDESC);
  if (!pointerp(tmp)) return tmp;
  n=sizeof(tmp);
  i=n*_query_fuel()/max_fuel;
  if (i>=n) i=n-1;
  return tmp[i];
}

/*
 * short() ueberladen
 */
string short()
{
  string s;
  string desc;

  if(!(s=QueryProp(P_SHORT)) || QueryProp(P_INVIS))
    return 0;
  return s + ( (lighted)? (" ("+QueryProp( P_LIGHTDESC ) +").\n") : ".\n" );
}
