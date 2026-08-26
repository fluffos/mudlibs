/*
// File:     /adm/obj/master/access.c
// Purpose:  Convert /adm/etc/access to a form the master.c can understand
// Credits:
// 92-12-21  Huthar wrote most of this, as part of TMI-2's distribution mudlib.
//           Please retain this header if you use any of this code.
// 93-06-28  Pallando converted it to use domain_master()
*/
#include <uid.h>
inherit "/adm/obj/master/groups";

#define ACCESS_FILE "/adm/etc/access"
#define GROUP "/adm/obj/master"
#define READ 1
#define WRITE 2

// #define DEBUG

mapping access = ([]);


void error_out( string msg, int line )
{
    write( "ERROR! " + ACCESS_FILE + " contains bad " + msg + " in line " +
      line + "\n" );
}

mapping load_access()
{
    string *lines;
    string file;
    int i, j;
    string *rest;
    int setbits;
    string path;
    string tmp, name;
    
    access = ([]);
    seteuid( ROOT_UID );
    if( ( file = read_file( ACCESS_FILE ) ) == "" )
    {
        write( "Error loading access file!\n" );
        return copy( access );
    }
    
    lines = explode( file, "\n" );
    
    for( i = 0 ; i < sizeof( lines ) ; i++ )
    {
       lines[i] = remove_whitespace( lines[i] );
        if( lines[i][0] == '#' || lines[i] == "" )
            continue;
        if( !sscanf( lines[i], "(%s)%s", path, lines[i] ) )
        {
            error_out( "path", i + 1 );
            return ([]);
        }
        rest = explode( lines[i], ":" );
        for( j = 0; j <sizeof( rest ); j++ )
        {
            if( !sscanf( rest[j], "%s[%s]", name, tmp ) )
            {
                error_out( "name", i + 1 );
                return 0;
            }
            
            if( name[0] == '(' && name[strlen( name ) - 1] == ')' )
                name = "@" + name[1 .. strlen( name ) - 2];
            
            if( !access[path] )
                access[path] = ([]);
            if( !access[path][name] )
                access[path] += ([  name : 0  ]);
            
            switch( tmp )
            {
                case "w":
                    access[path][name] |= WRITE;
                    break;
                case "r":
                    access[path][name] |= READ;
                    break;
                case "wr":
                case "rw":
                    access[path][name] |= READ | WRITE;
                    break;
            }
        }
    }
    return copy( access );
}

mapping query_access( string str )
{
    return copy( access[str] );
}

int check_groups( mixed *grps, string eff_user, string path )
{
    int i, res, found;
    string tmp;
    
    for( i = 0 ; i < sizeof( grps ) ; i++ )
    {
        if( grps[i][0] != '@' )
        {
            if( grps[i] == eff_user )
            {
                found = 1;
                res |= access[path][eff_user];
            }
        } else {
            tmp = grps[i][1..strlen( grps[i] ) - 1];
            if( tmp == "all" || GROUP-> query_member_group( eff_user, tmp ) )
            {
                found = 1;
                res |= access[path][grps[i]];
            }
        }
    }
    return found ? res : -1;
}

int check_access( string str, object act_ob )
{
    string *pth;
    string eff_user, tmp;
    int res;
    
    eff_user = geteuid( act_ob );
    if( !eff_user ) return 0; // this is kind of important -Sulam
    if( sscanf( str, user_path( eff_user ) + "%s", tmp ) == 1 )
        return( READ | WRITE );
  pth = strsrch( str, "/" ) != -1 ? explode( str, "/" ) : ({str});
    if( !pth ) pth = ({ });
    
    // The following bit added by Pallando for domain-master-object hook:
    if( ( 1 < sizeof( pth ) ) && ( pth[0] == "d" ) &&
        ( tmp = domain_master( pth[1] ) )             )
    {
        if( eff_user == ROOT_UID ) return( READ | WRITE );
        if( adminp(eff_user) ) return( READ | WRITE );
        return (int)call_other( tmp, "valid_access",
	implode( pth[2 .. <1], "/" ), eff_user );
    }
    
    if( eff_user == BACKBONE_UID &&
      ( pth[0] == "obj" || pth[0] == "data" ) )
        return( READ | WRITE );
    while( 1 )
    {
        if( !sizeof( pth ) )
            str = "/";
        else
            str = "/" + implode( pth, "/" );
        if( access[str] )
        {
            res = check_groups( keys( access[str] ), eff_user, str );
            if( res >= 0 )
            {
                return res;
            }
        }
        if( str == "/" )
            break;
	pth = pth[0..<2];
    }
    return 0;
}
