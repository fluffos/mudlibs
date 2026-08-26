
#if !efun_defined(query_num)
private string number_as_string( int n ) {
    string ret;

    if( !n )
        return "zero";

    if( n < 20 && n > 9 )
        return ({"ten", "eleven", "twelve", "thirteen",
                 "fourteen", "fifteen", "sixteen", "seventeen",
                 "eighteen", "nineteen"})[n-10];

    ret = ({"", "", "twenty", "thirty", "forty", "fifty", "sixty",
            "seventy", "eighty", "ninety"})[n/10];

    if( ( n %= 10 ) && ret != "")
        ret += "-";

    return ret + ({"", "one", "two", "three", "four", "five",
                   "six", "seven", "eight", "nine"})[n];

} /* number_as_string() */

/**
 * This method turns a number into a string.  It returns a string of the
 * form "one hundred and twenty four".
 * The limit argument is used to set the cut off point at which it will
 * print "many".
 *
 * @param i the number to return as a string
 * @param limit the largest number to process
 * @return the number as a nice string
 */
string query_num( int n, int limit ) {
    string ret, nve;
    int i;

    if( n < 0 ) {
        nve = "minus ";
        n *= -1;
    } else {
        nve = "";
    }

    if( limit && n > limit )
        return nve + "many";

    if( n > 99999 )
        return nve + "many";

    ret = 0;

    if( ( i = n / 1000 ) ) {
        n %= 1000;
        if( !n )
            return nve + number_as_string(i) + " thousand";
        ret = number_as_string(i) + " thousand";
    }

    if( ( i = n / 100 ) ) {
        n %= 100;
        if( ret ) {
            if( !n )
                return nve + ret + " and " + number_as_string(i) + " hundred";
            ret += ", " + number_as_string(i) + " hundred";
        } else {
            if( !n )
                return nve + number_as_string(i) + " hundred";
            ret = number_as_string(i) + " hundred";
        }
    }

    if( ret )
        return nve + ret + " and " + number_as_string(n);

    return nve + number_as_string(n);

} /* query_num() */
#endif

#if !efun_defined(word_ordinal)
/**
 * This method returns the ordinal of a number as a string (ie, "first",
 * "thirtieth", etc.)
 * @param n the number for which you want the ordinal
 * @returns the ordinal of the number as a string
 * @see query_num(), ordinal()
 */
string word_ordinal( int num )  {
    string word = "";
    int part, nve;

    if( !num )
        return "zeroth";

    if( num < 0 ) {
        nve = 1;
        num *= -1;
    }

    switch( part = num % 100 )  {
        case 0:
          word = "th";
        break;
        case 1..12:
          word = ({"first", "second", "third", "fourth", "fifth", "sixth",
                   "seventh", "eighth", "ninth", "tenth",  "eleventh",
                   "twelfth"})[part-1];
          break;
        case 13..19:
          word = query_num( num % 100, 0 ) + "th";
        break;
        default:
          if( !( part % 10 ) )  {
              word = ({"twentieth", "thirtieth", "fortieth", "fiftieth",
                       "sixtieth", "seventieth", "eightieth",
                       "ninetieth"})[part/10-2];
          } else  {
              word = ({"twenty", "thirty", "forty", "fifty", "sixty",
                       "seventy", "eighty", "ninety"})[part/10-2]+"-"+
                       word_ordinal(part%10);
          }
    }

    num = ( num / 100 ) * 100;

    if( num )   {
        if( part > 0 )
            word = query_num( num, 0 ) + " and " + word;
        else
            word = query_num( num, 0 ) + word;
    }

    if( nve )
        return "minus " + word;

    return word;

} /* word_ordinal() */
#endif

#if !efun_defined(create_table)
#define _BOLD(xxxx) ("%^BOLD%^"+ xxxx +"%^RESET%^")
/**
 * This method creates a nice table from the input array.
 * To control whether or not the results should be sorted or
 * capitalized, set the cap_flag to 1 to sort and capitalize,
 * or to 2 to only capitalize the array.
 * @param title a two element array containing the title of
 * the table, and the singular name for an array element
 * @param names the array to make the table out of
 * @param cap_flag 1 to capitalize and sort the array, 2 to
 * capitalize without sorting
 * @return a nice table
 * @example
 * write( create_table( ({"Creators", "creator"}),
 *        DOMAIN_H->query_creators(), 1 )+"\n");
 */
varargs string create_table( string *title, string *names, int cap_flag ) {
    int cols = TP->query_cols(), size;
    string ret = "%^RESET%^", bit, count;

    if( !arrayp(title) || !arrayp(names) || sizeof(title) != 2 )
        return 0;

    // Sort the list alphabetically.
    if( cap_flag < 2 )
        names = sort_array( names, 1 );

    // If specified, capitalise the array of names.
    if( cap_flag )
        names = map( names, (: CAP($1) :) );

    ret = sprintf("%|*'-'s", cols + 17,
                  "=======[ "+ _BOLD(title[0]) +" ]=======") + "\n";
    ret += sprintf("%#-*s\n", cols, implode(names, "\n"));

    if( stringp(title[1]) ) {
        count = query_num( size = sizeof(names), 100 );

        if( size == 1 )
            bit = "is only";
        else {
            if( !size )
                count = "no";
            bit = "are";
            title[1] = pluralize(title[1]);
        }

        ret += sprintf("%|*'-'s\n", cols, "[ There "+ bit +" "+
                       count +" "+ title[1] +" ]");
    } else
        ret += sprintf("%|*'-'s\n", cols, "");

    return ret;

} /* create_table() */
#endif

#if !efun_defined(time_string)
varargs string time_string( int time, int flag ) {
    int minutes, hours, days, years, i;
    string *strs = ({ }), nve;

    if( time < 0 ) {
        if( flag == 1 )
            nve = "-";
        else
            nve = "minus ";
        time *= -1;
    } else {
        nve = "";
    }

    days = time / 86400;
    time %= 86400;
    hours = time / 3600;
    time %= 3600;
    minutes = time / 60;
    time %= 60;

    if( flag == 1 )
        return nve + ( days ? days + ", " : "")+
               sprintf("%02d:%02d.%02d", hours, minutes, time );

    years = days / 365;
    days %= 365;

    if( flag ) {
        if( years )
            strs += ({ years+" year"+( years > 1 ? "s" : "") });
        if( days )
            strs += ({ days+" day"+( days > 1 ? "s" : "") });
        if( hours )
            strs += ({ hours+" hour"+( hours > 1 ? "s" : "") });
        if( minutes )
            strs += ({ minutes+" minute"+( minutes > 1 ? "s" : "") });
        if( time || !sizeof(strs) )
            strs += ({ time+" second"+( time > 1 ? "s" : "") });
    } else {
        if( years )
            strs += ({ query_num( years, 0 )+" year"+
                     ( years > 1 ? "s" : "") });
        if( days )
            strs += ({ query_num( days, 0 )+" day"+
                     ( days > 1 ? "s" : "") });
        if( hours )
            strs += ({ query_num( hours, 0 )+" hour"+
                     ( hours > 1 ? "s" : "") });
        if( minutes )
            strs += ({ query_num( minutes, 0 )+" minute"+
                     ( minutes > 1 ? "s" : "") });
        if( time || !sizeof(strs) )
            strs += ({ query_num( time, 0 )+" second"+
                     ( time > 1 ? "s" : "") });
    }

    i = sizeof( strs );
    switch( i ) {
      case 0 :
        return "";
      case 1 :
        return nve + strs[0];
      break;
      default :
        return nve + implode( strs[0..<2], ", " )+" and "+strs[<1];
      break;
    }

} /* time_string() */
#endif
