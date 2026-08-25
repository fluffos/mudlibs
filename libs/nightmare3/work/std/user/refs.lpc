// File:       /std/user/refs.c
// Mudlib:     Nightmare
// Purpose:    To store refs in (See _refs)
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:  93-06-05

nosave mapping refs;

void set_refs( mapping a ) { refs = ( mapp( a ) ? a : ([]) ); }

mapping get_refs() { return ( refs ? copy(refs) : ([]) ); }

void set_ref( string refv, mixed value )
{
  if( !refs ) refs = ([]);
  if( !refv ) refv = "default";
  if( undefinedp( value ) )
    map_delete( refs, refv );
  else
    refs[refv] = value;
}

mixed get_ref( string refv )
{
  if( !refs ) refs = ([]);
  if( !refv ) refv = "default";
  return refs[refv];
}
