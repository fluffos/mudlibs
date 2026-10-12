/*--------------------------------------------------------------------------
 * String <-> LPC datatype converter (save_object format)
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <driver/lpctypes.h>

#undef DEBUG

/*---------------------------------------------------------------------------
 * varargs int restore_value( string str, mixed r, int delimiter )
 *  Converts string str -> lpc datatype r
 *  - returns 1 on succes, 0 on failure
 *  - the result is stored in r
 *  - both str and r have to be given by reference
 *  - the value of str is destroyed
 *  - delimiter must not be given, used for internal recursion
 *---------------------------------------------------------------------------
 */

public varargs int restore_value( string str, mixed r, int delimiter );
private int restore_array( string str, mixed r, int delimiter );
private int restore_mapping( string str, mixed r, int delimiter );

private int restore_array( string str, mixed r, int delimiter ) {
  mixed * res;
  mixed rt;

  res = ({});
  while( str[0] ) {
#ifdef DEBUG
    dtell( "nostradamus", "restore_array: '"+str+"'\n" );
#endif
    /* check for end of array */
    if ( str[0] == '}' ) {
      if ( ( str[1] == ')' ) && ( str[2] == delimiter ) ) {
	      str = str[3..];
	      r = res;
	      return 1;
      }
      else
	      return 0;
    }
    else {
      if ( restore_value( & str, & rt, ',' ) )
	      res += ({ rt });
      else
	      return 0;
    }
  }
  /* if we reach this, array is invalid */
  return 0;
}

private int restore_mapping( string str, mixed r, int delimiter ) {
  mapping res;
  mixed k, v;

  res = ([]);
  while( str[0] ) {
#ifdef DEBUG
    dtell( "nostradamus", "restore_mapping: '"+str+"'\n" );
#endif
    /* check for end of array */
    if ( str[0] == ']' ) {
      if ( ( str[1] == ')' ) && ( str[2] == delimiter ) ) {
	str = str[3..];
	r = res;
	return 1;
      }
      else
	return 0;
    }
    else {
      if ( ( restore_value( & str, & k, ':' ) ) &&
	   ( restore_value( & str, & v, ',' ) ) )
	res += ([ k : v ]);
      else
	return 0;
    }   
  }

  /* if we reach this, mapping is invalid */
  return 0;
}

public varargs int restore_value( string str, mixed r, int delimiter ) {
  int i, i2;
  mixed res;
  string wstr;

#ifdef DEBUG
  dtell( "nostradamus", "restore_value: '"+str+"'\n" );
#endif

  switch( str[0] ) {
  case '"':
    /* string */
    r = str;
    i = 1;
    i2 = 0;
    while( str[i] && str[i] != '"' ) {
      if ( str[i] == '\\' ) {
	switch( str[i+1] ) {
	case 'a' : r[i2] = '\a'; break;
	case 'b' : r[i2] = '\b'; break;
	case 'e' : r[i2] = '\e'; break;
	case 'f' : r[i2] = '\f'; break;
	case 'n' : r[i2] = '\n'; break;
	case 'r' : r[i2] = '\r'; break;
	case 't' : r[i2] = '\t'; break;
	case '"' : r[i2] = '"';  break;
	case '\\': r[i2] = '\\'; break;
	default:
	  return 0;
	}
	i+=2;
	i2++;
      }
      else {
	r[i2]=str[i];
	i++;
	i2++;
      }
    }
    if ( str[i] != '"' || str[i+1] != delimiter )
      return 0;

    str = str[i+2..];
    r = r[0..i2-1];
    return 1;

    break;
  case '(':
    /* array or mapping */
    switch( str[1] ) {
    case '{':
      /* array */
      str = str[2..];
      if ( restore_array( &str, &res, delimiter ) ) {
	r = res;
	return 1;
      }
      else
	return 0;
      break;
    case '[':
      /* mapping */
      str = str[2..];
      if ( restore_mapping( &str, &res, delimiter ) ) {
	r = res;
	return 1;
      }
      else
	return 0;
      break;
    default:
      /* invalid */
      return 0;
    }
    break;
  case '-':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case '0':
    /* number */
    if ( ( i = member( str, delimiter ) ) == -1 )
      return 0;
    else {
      wstr = str[0..(i-1)];
      str = str[(i+1)..]; 
    }

    if ( ( sscanf( wstr, "%d", i ) == 1 ) &&
	 ( to_string(i) == wstr ) ) {
      r = i;
      return 1;
    }
    else
      return 0;
    break;
  default:
    /* invalid */
    return 0;
    break;
  }
  return 0;
}

/*--------------------------------------------------------------------------
 * int save_value( mixed r, string str )
 *  Converts lpc datatype r -> string str
 *  - returns 1 on succes, 0 on failure
 *  - the result is stored in str
 *  - str has to be given by by reference and _must_ be initialized to ""
 *--------------------------------------------------------------------------
 */

public int save_value( mixed r, string str ) {
  mixed * k;
  int i, i2;
  string tx;

  switch( typeof( r ) ) {
  case T_NUMBER:
    /* integer type */
    str += to_string( r );
    return 1;
    break;
  case T_STRING:
    /* string type */
    tx = r;
    i2 = sizeof( tx );
    i = 0;
    while( i < i2 && tx[i] ) {
      switch( tx[i] ) {
      case '\a': tx[i] = 'a'; break;
      case '\b': tx[i] = 'b'; break;
      case '\e': tx[i] = 'e'; break;
      case '\f': tx[i] = 'f'; break;
      case '\n': tx[i] = 'n'; break;
      case '\r': tx[i] = 'r'; break;
      case '\t': tx[i] = 't'; break;
      case '\"': tx[i] = '"'; break;
      case '\\': break;
      default: i++; continue;
      }
      tx = tx[0..i-1]+"\\"+tx[i..];
      i+=2;
      i2++;
    }

    str += ( "\""+tx+"\"" );
    return 1;
    break;
  case T_POINTER:
    /* pointer type */
    str += "({";
    for( i2 = 0; i2 < sizeof( r ); i2 ++ ) {
      if ( ! save_value( r[i2], & str ) )
	      return 0;
      str += ",";
    }
    str += "})";
    return 1;
    break;
  case T_MAPPING:
    /* mapping type */
    str += "([";
    k = m_indices( r );
    for( i = 0; i < sizeof( k ); i ++ ) {
      if ( ! save_value( k[i], & str ) )
	return 0;
      str += ":";
      if ( ! save_value( r[k[i]], & str ) )
	return 0;
      str += ",";
    }
    str += "])";
    return 1;
    break;
  default:
    /* invalid type */
    return 0;
  }
  return 0;
}
