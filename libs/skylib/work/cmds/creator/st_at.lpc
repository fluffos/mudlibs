
#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    object *ob, thing;
    mixed ob1, thing1;
    string s, bing;
    string long_fields, temp;
    int long_length, cols;

    bing = "";
    cols = (int)TP->query_cols();
    str = (string)TP->expand_nickname( str );
    ob = WIZ_PRESENT->wiz_present( str, TP );

    if( !sizeof(ob) ) {
        write("No such object.\n");
        return 1;
    }

    foreach( thing in ob ) {
        if( !pointerp( ob1 = (mixed)thing->stats() ) ) {
            bing += "No stats available for "+
                WIZ_PRESENT->desc_f_object(thing)+".\n";
            continue;
        }

        s = "";
        long_fields = "";
        long_length = ( cols / 3 ) - 1;

        foreach( thing1 in ( pointerp(ob1[0][0] ) ? ob1[0] : ob1 ) ) {
            if( thing1[1] ) {
                temp = thing1[0]+": "+sprintf("%O", thing1[1] )+"\n";
                if( strlen(temp) > long_length )
                    long_fields += temp;
                else
                    s += temp;
            }
        }

        if( s == "" && long_fields == "")
            bing += "No stats available for "+
                WIZ_PRESENT->desc_f_object(thing)+".\n";
        else
            bing += sprintf("%-*#s\n", cols, long_fields )+
                    sprintf("%-*#s\n", cols, s );
    }

    TP->more_string( bing, "Stat");
    return 1;

} /* cmd() */
