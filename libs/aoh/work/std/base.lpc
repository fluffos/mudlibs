//---------------------------------------------------------------------------
// std/base.c
//
// The core of all objects.
// It contains the property handling and destructing.
// 04-Oct-01 [n] Updated to new LDMud Driver
//
// [n] Nostradamus
//---------------------------------------------------------------------------

#include <driver/functionlist.h>
#include <properties.h>
#include <moving.h>

#define ENV	environment()
#define THIS	this_object()

//--- global variables ------------------------------------------------------

private nosave string Pcreator, Pcreatori;
private nosave int Pinherited, Pcloned, Pcreatime, Pisvirtual;
private nosave mapping Pprops;

//--- shadow control --------------------------------------------------------

public int prevent_shadow( object by )
{
   string fname = object_name( THIS );

   if ( clonep( THIS ) )
     return 0;
   return (   fname[0..4] == "/std/"
           || fname[0..4] == "/obj/"
           || fname[0..4] == "/lib/"
           || fname[0..5] == "/room/"
           || fname[0..7] == "/secure/"
           || fname[0..5] == "/mail/"
           || fname[0..5] == "/news/"
          );
}

//--- property querying and setting -----------------------------------------

public varargs mixed Query( string pn, int sc )
{
  mixed ret;

  if ( !sc && call_resolved( &ret, THIS, "Query" + pn ) )
    return ret;
  return Pprops ? Pprops[ pn ] : 0;
}

public varargs mixed QueryProp( string pn, int sc )
{
  return Query( pn, sc );
}

public varargs mixed Set( string pn, mixed arg, int sc )
{
  mixed ret;

  if (!Pprops)
    Pprops = ([P_CLEAN_UP: 1]);
  if ( !sc && call_resolved( &ret, THIS, "Set" + pn, arg ) )
    return ret;
  if ( arg )
    Pprops[ pn ] = arg;
  else
    Pprops = m_delete( Pprops, pn );
  return arg;
}

public varargs mixed SetProp( string pn, mixed arg, int sc )
{
  return Set( pn, arg, sc );
}

public int Exists( string pn, int sc )
{
  mixed ret;

  return ( !sc && function_exists( "Query" + pn, THIS )
                   ? 1
                   : m_contains( &ret, Pprops, pn ) );
}

public int ExistsProp( string pn, int sc )
{
   return Exists( pn, sc );
}

//--- grant access to ALL properties of an object ---------------------------

// NOTE: we do not know, if the actual object has turned some softcoded
//       properties into hardcoded properties. So we HAVE to use
//       the Query- and Set() function to get/set the correct
//       values. So these functions have an VERY high evaluation cost.

private void filter_hardcoded( string func, mapping map )
{

  if ( func[0..4] == "Query" )
  {
    mixed tmp;

    if( func != "QueryAttr" && func != "QueryProp" && func != "QueryProperties"
      && func != "Query"
        && func != "QueryAttribute"
        && func != "QueryBaseAttr"
        && func != "QueryBaseAttribute"
       && !m_contains( &tmp, map, func[5..] )
      )
      map[func[5..]] = ({mixed})call_other( THIS, func );
  }
}

public mapping QueryProperties( void )
{
  mapping map = ([ ]) + Pprops;
  filter( functionlist( THIS ), #'filter_hardcoded /*'*/, &map );
  return map;
}

public mapping SetProperties( mapping props )
{
  mixed * ind = m_indices( props );
  mixed * val = m_values( props );
  int s;

  for( s = sizeof( props ); s--; val[ s ] = Set( ind[ s ], val[ s ] ) );
  return mkmapping( ind, val );
}

//--- object destruction ----------------------------------------------------

// optional argument added as vitems did not work properly...
// someone checks this...Softbyte 11nov97
public varargs int remove( int arg )
{
  if ( THIS )
  {
    if( ENV && !({int})ENV -> prevent_leave( THIS, M_DESTRUCT, 0 ) )
    {
      ENV -> notify_leave( 0, M_DESTRUCT, 0 );
    }
    destruct( THIS );
  }
  return 1;
}

//---------------------------------------------------------------------------

public int clean_up( int ref )
{
  if ( Query( P_CLEAN_UP ) )
    remove();
  return THIS && 1;
}

//--- Better memory usage ---------------------------------------------------

public string replace_pgm( void )
{
  mixed *arr;
  object ob;
  int s;

  if ( Pinherited || Pcloned || clonep() ) // member( object_name( THIS ), '#' ) >= 0 )
    return 0;

  // Check all non-"create" functions if they are inherited.
  arr = functionlist( THIS, 3 );
  s = sizeof( arr ) - 1;
  do
  {
    if ( !( arr[ s ] & NAME_INHERITED ) && arr[s - 1] != "create" )
      return 0;
    s -= 2;
  } while ( s > 0 );

  // Check if we have just one direct papa.
  arr = inherit_list();
  s = sizeof( arr ) - 1;
  if ( s && ( ob = find_object( arr[1] ) ) && s == sizeof( inherit_list( ob ) ) )
  {
    replace_program( object_name( ob ) );
    return object_name( ob );
  }
  return 0;
}

//--- creator tracking ------------------------------------------------------

public /* nomask */ string QueryCreator( void )
{
  return Pcreator;
}

public /* nomask */ int QueryCreationTime( void )
{
  return Pcreatime;
}

public /* nomask */ string QueryICreator( void )
{
  return Pcreatori;
}

public /* nomask */ int QueryInherited( void )
{
  return Pinherited;
}

public /* nomask */ int QueryCloned( void )
{
  return Pcloned;
}

public /* nomask */ int SetCloned( int i )
{
  object o = previous_object();

  if ( o && THIS && o != THIS
         && object_name( THIS ) == blueprint( THIS )
         && object_name( THIS ) == blueprint( o )
     )
  {
    Pcloned = -1;
  }
  return Pcloned;
}

public /* nomask */ int QueryIsVirtual( void )
{
  return Pisvirtual;
}

public /* nomask */ int SetIsVirtual( int i )
{
  object o = previous_object();

  if ( o && getuid( o ) == ROOTID )
    Pisvirtual = 1;
  return Pisvirtual;
}

public void create( void )
{
  Pcreator = to_string( previous_object() || "<unknown>" );
  Pcreatori = to_string( this_interactive() || "<unknown>" );
  Pprops = ([P_CLEAN_UP: 1]);  // No use to have extra code for Pprops = 0
  Pcreatime = time();
  Pisvirtual = 0;
}

public void create_inh( void )
{
  Pinherited = 1;
  Pcloned = 0;
  create();
}

public void create_clone( void )
{
  Pinherited = 0;
  Pcloned = 1;
  blueprint() -> SetCloned(-1);
  create();
}

public void create_obj( void )
{
  Pcloned = 0;
  /* Pinherited = 0; */
  /* Sometimes an object is first loaded, then inherited.
   * It even makes sense sometimes.
   */
  create();
}
