// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* Note: this is now a wrapper for the efun, allowing "on the fly"
 * modification */
#define VOWELS ({'a', 'e', 'i', 'o', 'u'})

//:MODULE
//
//The grammar module contains a number of functions for producing high
//quality english output.

// punctuate Written by Rust.

//:FUNCTION punctuate
//Adds a period to a sentence if needed.
string punctuate( string str )
{
    int         last_char;

    if(!stringp(str) || !strlen(str))
        return "";

    while ( strlen(str) && str[<1] == ' ' )
        str = str[0..<2];
    if ( !strlen(str) )
        return "";

    last_char = str[<1];
    if( ( last_char >= 'a' && last_char <= 'z' ) ||
      ( last_char >= 'A' && last_char <= 'Z' ) )
        return str+".";

    return str;
}

//:FUNCTION number_of
//Handles the common operation: "0 bogs", "1 bog", "2 bogs", ...
//number_of(num, what)
varargs string number_of(int num, string what, string unit) {
    if (!unit) return chinese_number(num) + what;
    else return chinese_number(num) + unit + what;
}

//:FUNCTION number_word
//
//number_word(1) == "one", etc.  number_word(10) == "10" and similarly
//for numbers greater than 10, which is consistent with most English
//style guidelines
string number_word(int num) {
    return chinese_number(num);
}
