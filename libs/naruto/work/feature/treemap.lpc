// #pragma save_binary

// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (92-05-01)
// Expanded to use a superior security system by Buddha (92-05-31)
// Temporary flag attribute system added by Watcher (93-02-21)
// Altered by Pallando @ Tabor (93-03-17)
// Changed to return current value in _set() by Annihilator (95-03-15)
// NB these functions don't have to be nomask if you prevent objects shadowing
// them in the same circumstances that shadowing query is not allowed.

// Added rebind to this_object() when a function type variable of call_other
// is set via _set(). This could avoid owner-destructed error on many case.
// By Annihilato(11/20/95)

#include <function.h>

protected nomask mixed _query( mapping map, string *parts )
{
	mixed value;
	int i, s;

	value = map;
	s = sizeof( parts );
	for( i = 0 ; i < s ; i++ ) {
		if( undefinedp( value = value[parts[i]] ) )
			break;
		if( !mapp( value ) )
			break;
	}
	return value;
}

protected nomask int _delete( mapping map, string *parts )
{
	if( sizeof( parts ) == 1 ) {
		map_delete( map, parts[0] );
		return 1;
	}
	if( !map[parts[0]] || !mapp( map[parts[0]] ) )
		return 0;
	return _delete( map[parts[0]], parts[1..sizeof(parts)-1] );
}

protected nomask mixed _set( mapping map, string *parts, mixed value )
{
	int fp;

	if( sizeof( parts ) == 1 ) {
		if( (fp = functionp(value)) && (!(fp & FP_LOCAL)) ) {
			if( fp & FP_NOT_BINDABLE )
				error("property of function type must be bindable");
			value = bind(value, this_object());
		}
		return map[parts[0]] = value;
	}

	if( !map[parts[0]] || !mapp( map[parts[0]] ) )
		map[parts[0]] = ([ parts[1] : 0 ]);

	return _set( map[parts[0]], parts[1..sizeof(parts)-1], value );
}
