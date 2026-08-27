string query_idle_string( object player, int verbose ) {
        int time, tmp;
        string line;

        if( ! player ) return 0;
        if( ! interactive( player ) )
                return ( verbose ? "Linkdead" : "LD" );

        line = ""; time = query_idle( player );
        if( time < 60 ) return "";

        tmp = time / 86400;
        if( tmp )
        {
                if( ! verbose ) return tmp + "d";
                else line += tmp + " day" + ( tmp > 1 ? "s " : " " );
        }

        tmp = ( time % 86400 ) / 3600;
        if( tmp )
        {
                if( ! verbose )
                {
                        if( tmp > 9 ) return tmp + "h";
                        else line = tmp + ":";
                }
                else line += tmp + " hour" + ( tmp > 1 ? "s " : " " );
        }

        tmp = ( time % 3600 ) / 60;
        if( tmp )
        {
                if( ! verbose )
                {
                        if( strlen( line ) > 0 && tmp < 10 ) line += "0";
                        line += tmp + "m";
                }
                else line += tmp + " minute" + ( tmp > 1 ? "s " : " " );
        }

        if( verbose ) line += "Idle Time";
        return line;
}
