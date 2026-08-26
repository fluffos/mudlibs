
#include <config.h>

inherit COMMAND_BASE;

int db;

int cmd( string who ) {
    mixed rows;
    string ret;

    db = db_connect("localhost", CONFIG_DB_ERRORS, CONFIG_DB_USER );

    if( who == "all")
        rows = db_exec( db, "select Reporter, count(*) as bing from errors "
                      "where Status = 'DENIED' group by Reporter order by bing desc");
    else
        rows = db_exec( db, sprintf("select Reporter, count(*) from errors "
            "where Reporter = '%s' and Status = 'DENIED' group by Reporter",
            who ) );

    if( intp(rows) ) {
        ret = sprintf("%-15s %s\n", "player", "reports");
        ret += implode( allocate( rows, function( int i ) {
               mixed tmp = db_fetch( db, i+1 );
               return sprintf("%-15s %s", tmp[0], ""+tmp[1] );
               } ), "\n");
        ret += "\n";
        db_close(db);
        TP->more_string(ret);
        return 1;
    }

    printf(rows);
    return 1;

} /* cmd() */
