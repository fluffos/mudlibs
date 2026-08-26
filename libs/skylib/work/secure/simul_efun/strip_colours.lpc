/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */

nosave mapping term_cache;

#define TERM_HANDLER "/handlers/term"

/**
 * This method strips the colour codes out of the resultant string.
 * This is used to send strings to systems outside the mud (like
 * the web and stuff).
 * @param str the string to strip
 * @return the stripped string
 */
string strip_colours( string str ) {
    if( !mapp(term_cache) ) {
        if( catch( term_cache = TERM_HANDLER->set_term_type("dumb") ) )
            term_cache = ([ ]);
    }
  
    if( str != "%^")
        return terminal_colour( str, term_cache );

    return "";

} /* strip_colours() */
