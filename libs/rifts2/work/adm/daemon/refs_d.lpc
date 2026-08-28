// File:        /adm/daemon/refs_d.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     interface between /std/user/refs.c and ref commands
// Credits:     see _refs.c

void set_refs( mapping refs ) { this_player()-> set_refs( refs ); }

mapping get_refs() { return (mapping)this_player()-> get_refs(); }

void set_ref( string refi, mixed val ) { this_player()-> set_ref( refi, val ); }

mixed get_ref( string refi ) { return (mixed)this_player()-> get_ref( refi ); }

mixed resolv_ref( mixed a )
{
  mixed ret;
  string refi;

  if( !stringp( a ) ) return a;
  if( !sscanf( a, "#%s", refi ) ) return a;
// Nightmare does not support cwf
// if( refi == "#" ) return (string)this_player()-> query( "cwf" );
  if( undefinedp( ret = get_ref( refi ) ) ) return a;
  return ret;
}

mixed ref_ob( mixed a )
{
  mixed tmp;

  a = resolv_ref( a );
  if( stringp( a ) && ( tmp = get_objects( a, 0, 1 ) ) ) a = tmp;
  return a;
}

// NB arrays or mappings containing arrays, mappings or
// functions are liable to confuse this function.
// This could be made a simul_efun some time.
// Fixed to handle the case ([]) and ({})  93-02-05 Pallando
mixed resolv_str( string a )
{
  mapping v_m;
  mixed v_o; //object or array of objects 
  mixed *v_a, tmp1, tmp2;
  string v_s, sa, sb, *v_sa;
  int v_i, f1, f2, ia, ib, ic, flag;

  if( !a ) return a;
  if( a == "" || a == " " || a == "  " ) return a;
  while( sscanf( a, " %s", sa ) ) a = sa;
  ib = strlen( a ) - 1;
  if( a[ib..ib] == " " ) a = a[0..(ib-1)];
  if( sscanf( a, "\"%s\"", v_s ) ) return v_s;
// If you want to make resolv_str() a simul_efun, change the next line to
// tmp1 = REFS_D->resolv_ref( a );
  tmp1 = resolv_ref( a );
  if( tmp1 != a ) return tmp1;
  if( sscanf( a, "%d.%d", f1, f2) == 2 )
    return (to_float(f1) + to_float(f2) /
            pow(10.0, to_float(strlen(replace_string(a, sprintf("%d.",f1), ""))
                               )));
  if( sscanf( a, ".%d", f2) )
    return (to_float(f2) / pow(10.0, to_float(strlen(a) - 1)));
  if( sscanf( a, "%d", v_i ) ) return v_i;
  if( v_o = get_objects( a ) ) return v_o;
  if( sscanf( a, "(: call_other,%s,%s:)", sa, sb ) == 2 )
  {
    tmp1 = resolv_str( sa );
    tmp2 = resolv_str( sb );
    if( objectp( tmp1 ) && stringp( tmp2 ) ) return (: call_other, tmp1, tmp2 :);
  }
  if( sscanf( a, "({%s})", sa ) )
  {
    a = replace_string(a, "({", "", 1, 1);
    ic = strlen(a);
    while(ic >= 3 && a[(ic-2)..(ic-1)] != "})") ic--;
    sa = a[0..(ic-3)];
    v_sa = explode( sa, "," );
    ib = sizeof( v_sa );
    v_a = ({ });
    if( ib && !v_sa[0] ) return ({ });
    for( ia = 0 ; ia < ib ; ia++ ) {
      sb = "";
      sa = replace_string(v_sa[ia], " ", "");
      flag = 0;
      if(strlen(sa) >= 2 && sa[0..1] == "({") {
	flag = 1;
	while(flag && ia < ib) {
	  sa = replace_string(v_sa[ia], " ", "");
	  if((ic = strlen(sa)) > 2 && sa[(ic-2)..(ic-1)] == "})") {
	    flag = 0;
	    sb += v_sa[ia];
	  }
	  else {
	    sb += v_sa[ia] + ", ";
	    ia++;
	  }
	}
      }
      else sb = v_sa[ia];
      v_a += ({ resolv_str( sb ) });
    }
    return v_a;
  }
  if( sscanf( a, "([%s])", sa ) )
  {
    v_m = ([]);
    v_a = explode( sa, "," );
    ib = sizeof( v_a );
    if( ib && !v_a[0] ) return ([]);
    for( ia = 0 ; ia < ib ; ia++ )
      if( sscanf( v_a[ia], "%s:%s", sa, sb ) == 2 )
        v_m[resolv_str( sa )] = resolv_str( sb );
    return v_m;
  }
  return a;
}

