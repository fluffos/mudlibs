// File:       /std/user/refs.c
// Mudlib:     Nightmare
// Purpose:    To store refs in (See _refs)
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:  93-06-05

nosave mapping refs;

void set_refs( mapping a ) { refs = ( mapp( a ) ? a : ([]) ); }

mapping get_refs() { return ( refs ? copy(refs) : ([]) ); }

void set_ref( string refi, mixed value )
{
  if( !refs ) refs = ([]);
  if( !refi ) refi = "default";
  if( undefinedp( value ) )
    map_delete( refs, refi );
  else
    refs[refi] = value;
}

mixed get_ref( string refi )
{
  if( !refs ) refs = ([]);
  if( !refi ) refi = "default";
  return refs[refi];
}
