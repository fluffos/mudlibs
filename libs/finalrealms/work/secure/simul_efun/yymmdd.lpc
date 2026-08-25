// secure/simul_efun/yymmdd.i
// include in secure/simul_efun.
//
// MUDlib global functions: related date, time, and file functions.
//
// 1996 Jul 19 Laggard      split into two files for convenience.
// 1996 May 03 Laggard      based on existing functions by Moredhel and Dyraen.
//

// returns string with current numeric year, month, day, hour, minute, second;
// extracted from ctime(): "Fri May  3 08:43:19 1996".
//

/* Grabbed from RoD by Baldrick. */

string yymmddhhmmss()
{
    string date_time = ctime( time() ) ;
    int mi = 1 + member_array( date_time[ 4..6 ],
        ({  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }) );

    if ( mi < 10 )
    {
        date_time = date_time[ 22..23 ] + "0" + mi + date_time[ 8..9 ]
                + date_time[11..12] + date_time[14..15] + date_time[17..18];
    }
    else
    {
        date_time = date_time[ 22..23 ] + mi + date_time[ 8..9 ]
                + date_time[11..12] + date_time[14..15] + date_time[17..18];
    }
    return replace_string( date_time, " ", "0" );
}


// returns filename with yymmdd and appropriate version suffix.
// Note: this requires an appropriate euid for accessing the file.
//
string yymmdd_file(string filename)
{
    string date_time = yymmddhhmmss();
    string filenamedate = filename + "." + date_time[0..5];

    if ( file_size( filenamedate ) != -1 )
    {
        int i = 1;

        while( file_size( filenamedate +"v"+ i ) != -1 )
        {
            i++ ;
        }
        filenamedate += "v" + i;
    }
    return filenamedate;
}

