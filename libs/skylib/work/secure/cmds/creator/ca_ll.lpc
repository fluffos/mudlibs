/* call command, trial out by Turrican for a commands daemon. */

#include <creator.h>
#include <parser.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    mixed args, file, f, argv, ret;
    string *s, s1, s2, fn, os, obvarname;
    object *ov, fish, shad, ob;

    notify_fail("USAGE : call [obvar=]lfun(arg[,arg[,arg...]]) object[s]\n");
    if( !str )
        return 0;

    obvarname = (string)0;
    sscanf( str, "%s=%s", obvarname, str );
    s = explode("&"+str+"&", ")");

    if( sizeof(s) < 2 || sscanf( s[0], "%s(%s", s1, s2 ) != 2 )
        return 0;

    fn = replace( s1[1..], " ", "");
    s[0] = s2;
    args = PARSER->parse_args( implode(s, ")"), ")");
    if( !args )
        return 1;

    argv = args[0];
    os = args[1][0..<2];

    while( strlen(os) && os[0] == ' ')
        os = os[1..];

    if( !os || os == "")
        return notify_fail("You need to specify the object to call the "
            "function on.\n");

    notify_fail("Can't find object "+os+".\n");
    ov = WIZ_PRESENT->wiz_present( os, TP );
    ov = filter( ov, (: reference_allowed( $1, $( TP ) ) :) );

    if( !sizeof(ov) )
        return 0;

    if( sizeof(argv) < 6 )
        argv += allocate( 6 - sizeof(argv ) );

    foreach( ob in ov ) {
        fish = ob;
        while( shad = shadow( fish, 0 ) ) {
            fish = shad;
            if( f = function_exists( fn, fish ) )
                file = f;
        }

        if( !file )
            file = function_exists( fn, ob );

        if( file ) {
            if( ob != TP && ob->query_property("player") ) {
                unguarded( (: write_file, "/secure/log/"+( liaisonp(TP) ?
                    "CALL_LIAISONS.log" : "CALL_CREATORS.log" ),
                    sprintf("%s: %s (%O) called %s(%s) on %s (%O)\n",
                    ctime(time()), TP->query_name(), TP, fn,
                    implode( argv - ({ 0 }), ", "), ob->query_name(),
                    ob ) :) );

                user_event("inform", sprintf("%s called %s(%s) on %s",
                    TP->query_name(), fn, implode( argv - ({ 0 }), ", "),
                    ob->query_name() ), "calls");
            }

            ret = call_other( ob, fn, argv[0], argv[1],
                     argv[2], argv[3], argv[4], argv[5] );

            printf("*** function on '%s' found in %s ***\n",
                WIZ_PRESENT->desc_object(ob), file );
            write( sprintf("$P$Call result$P$Returned: %O\n", ret ) );
            if( obvarname ) {
                if( objectp(ret) )
                    TP->set_obvar( obvarname, ret );
            }
        } else {
            printf("*** function on '%s' Not found ***\n",
                WIZ_PRESENT->desc_object(ob));
        }
        file = 0;
    }

    return 1;

} /* cmd() */
