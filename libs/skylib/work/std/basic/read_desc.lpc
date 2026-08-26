/**
 * This method keeps track of all the messages on the object for
 * reading etc.  Keeps track of the language, the text and the
 * size.
 * @author Pinkfish
 */
#include <language.h>

inherit "/std/basic/desc";

private nosave mixed _read_mess = ({ });
private nosave int _max_size = 100;
private nosave int _cur_size;
nosave mapping describe;

/**
 * This method sets the maximum amount of writing that can be
 * placed onto the object.
 * @param siz the maximum size
 * @see query_max_size()
 * @see add_read_mess()
 */
void set_max_size(int siz) { _max_size = siz; }

/**
 * This method returns the current maximum text size of the object.
 * @return the current maximum text size
 * @see set_max_size()
 * @see add_read_mess()
 */
int query_max_size() { return _max_size; }

/** @ignore yes */
private int internal_text_size( string lang, string str, int size ) {
    return size * ( sizeof(str) *
        (int)LANGUAGE_H->query_language_size( lang ) / 10 );
} /* internal_text_size() */

/**
 * This method sets the size of the current amount of writing
 * on the object.
 * @see set_max_size()
 * @see add_read_mess()
 * @see query_cur_size()
 * @param siz the new current size
 */
void set_cur_size(int siz) { _cur_size = siz; }

/**
 * This method returns the size of the current amount of writing
 * on the object.
 * @see set_max_size()
 * @see add_read_mess()
 * @see set_cur_size()
 * @return the current amount of writing on the object
 */
int query_cur_size() {
    int i, j;

    if( _cur_size < 1 && ( j = sizeof( _read_mess ) ) ) {
        for( i = 0, _cur_size = 0; i < j; i++ )
            _cur_size += internal_text_size( _read_mess[i][READ_LANG],
                _read_mess[i][READ_MESS], _read_mess[i][READ_SIZE] );
    }

    return _cur_size;

} /* query_cur_size() */

/**
 * Calling this is very rude unless you are creating the object as it
 * erases all of the writing off it!
 */
varargs void set_read_mess( mixed str, string lang, int size ) {
    _cur_size = 0;

    if( pointerp( str ) ) {
        _read_mess = str;
    } else {
        if( !lang )
            lang = "common";

        if( !size )
            size = 1;

        _read_mess = ( str ? ({ ({ str, 0, lang, size }) }) : ({ }) );
    }
} /* set_read_mess() */

/**
 * This method returns the current read messae array on the object.
 * The returned array consists of an array of arrays.  The internal
 * array has 4 elements, the first is the text of the message
 * the second is the type of the message, the third is the language
 * and the last element is the size of the writing.
 *<p>
 * The defines in the file /include/language.h should be used
 * for the indexes into this array.
 * @return the read message array
 * @see add_read_mess()
 * @see set_max_size()
 * @see /include/language.h
 */
mixed query_read_mess() { return copy( _read_mess ); }

/**
 * This method queries whether or not the specified text
 * fits on this object.  The arguments to this function are
 * identical to those of add_read_mess().
 * @return 1 if the text fits on the object, 0 if not
 */
int test_add_read_mess( string str, string type, string lang, int size ) {
    // Use query_cur_size() so that _cur_size will be accurate,
    // as it is not saved - Sandoz.
    if( query_cur_size() >= _max_size )
        return 0;

    if( !sizeof(str) )
        return 1;

    if( !size )
        size = 1;

    if( !lang )
        lang = "common";

    return ( _cur_size + internal_text_size( lang, str, size ) <= _max_size );

} /* test_add_read_mess() */

/**
 * This method adds a new read message onto the object.
 * <p>
 * The str bit is the actual string to add, it is the message which
 * will get printed. The type is the type of the writing, like "spidery
 * writing" or "charcoal based letters".  The language is the
 * language in which it is written and the size is the size of the
 * letters (standard handwriting should be of size 1).
 * The size is used to see if the writing can fit on the page.
 * <p>
 * If no language is given, the default is "common".  If no type is
 * given, then no type bit is printed and if no size is specified then
 * a size of 1 is the default.
 * <p>
 * This also adjusts the size of stuff on the object.  If too much
 * is attempted to be written on the object, the remainder will be
 * cut off.
 * @param str the text of the message
 * @param type the type of the message
 * @param lang the language the message is in
 * @param size the size of the message
 * @return the text that was successfully written onto the object
 * @see query_read_mess()
 * @see set_max_size()
 * @see /handlers/language->query_language_size()
 * @see /handlers/language->squidge_text()
 */
varargs string add_read_mess( string str, string type, string lang, int size ) {
    int i;

    // Use query_cur_size() so that _cur_size will be accurate,
    // as it is not saved - Sandoz.
    if( query_cur_size() >= _max_size || !sizeof(str) )
        return "";

    if( !size )
        size = 1;

    if( !lang )
        lang = "common";

    i = internal_text_size( lang, str, size );

    if( _cur_size + i > _max_size ) {
        str = (string)LANGUAGE_H->squidge_text( lang, str,
            ( _max_size - _cur_size - size ) * 10 / size );

        if( !i = strlen(str) )
            return "";

        _cur_size += internal_text_size( lang, str, size );

    } else {
        _cur_size += i;
    }

    _read_mess += ({ ({ str, type, lang, size }) });

    return str;

} /* add_read_mess() */

/**
 * This method removes a piece of writing off the object.
 * <p>
 * If you know the actual message or the language or the type you can remove
 * that message.
 *<p>
 * Using the type and or language is a very dodgy way of doing this.  Using
 * a combination is much better.
 * <p>
 * Any of the parameters set to a non-zero value will be used for the search.
 * @param str the text string
 * @see /handlers/language->query_language_size()
 * @see add_read_mess()
 * @see query_read_mess()
 * @param type the type of the text
 * @param lang the language it is written in
 * @return 0 if the text was not found, 1 if it was
 */
int remove_read_mess( string str, string type, string lang ) {
    int i;

    for( i = 0; i < sizeof(_read_mess); i++ ) {
        if( str && _read_mess[i][READ_MESS] != str )
            continue;
        if( type && _read_mess[i][READ_TYPE] != type )
            continue;
        if( lang && _read_mess[i][READ_LANG] != lang )
            continue;
        // Use query_cur_size() so that _cur_size will be accurate,
        // as it is not saved - Sandoz.
        _cur_size = query_cur_size() - internal_text_size(
            _read_mess[i][READ_LANG], _read_mess[i][READ_MESS],
            _read_mess[i][READ_SIZE] );
        _read_mess = delete( _read_mess, i, 1 );
        return 1;
    }

    return 0;

} /* remove_read_mess() */

/**
 * This method returns the read message for the object.  This is what should
 * be displayed to the player if they attempt to read this object.
 * @return the read message, 0 if there is none
 */
string query_readable_message( object player, int dummy ) {
    string message, type, lang, *sigs;
    mixed mess, bit, read_mess;

    if( !sizeof( read_mess = query_read_mess() ) )
        return 0;

    message = "";
    sigs = ({ });

    foreach( bit in read_mess ) {
        mess = bit[ READ_MESS ];
        type = bit[ READ_TYPE ];
        lang = bit[ READ_LANG ];

        if( functionp( mess ) )
            mess = evaluate( mess );

        if( stringp( mess ) && sscanf( mess, "$$%s$$", mess ) ) {
            if( !mess = unguarded( (: read_file, mess+".txt" :) ) )
                mess = "Warning: text file cannot be read!";
        }

        if( type == "signature") {
            sigs += ({ mess });
            continue;
        }

        mess = LANGUAGES->garble_text( lang, mess, TO, TP );

        if( !LANGUAGES->query_language_magic( lang ) ) {
            mess = "Text "+( type == "printing" ? "printed" : "written")+
                ( type && type != "printing" ? " in "+type : "")+
                ( lang ? " in "+lang : "")+":\n"+
                indent( mess, 3, TP->query_cols() )+"\n";
        }
        message += mess;
    }

    if( sizeof(sigs) )
        message += "\n"+( query_group(TO) ? "They bear ": "It bears ")+
            query_multiple_short(sigs)+".\n";

    return message;

} /* query_readable_mesage() */

/**
 * This method returns the short description to use with the reading.
 * It will go: You read <read short>:
 * <p>
 * It will automaticly add a $name$ onto the end of the string for you.
 * This will be replaced with the correct a/the short for the message
 * which is printed.
 * @param player the player reading the message
 */
string query_read_short( object player, int dummy ) {
    string id, *read_mess;

    if( !sizeof( read_mess = query_read_mess() ) )
        return 0;

    if( id = TO->query_property("read id") )
        id += " $name$";
    else
        id = "$name$";

    return id;

} /* query_read_short() */

/**
 * This method adds details for an item.
 * @param d_name the name(s) of the detail
 * @param mess the descripton of the item
 */
void add_detail( mixed d_name, string mess ) {
    if( pointerp(d_name) ) {
        foreach( string detail in d_name )
            add_detail( detail, mess );
        return;
    }

    if( !describe )
        describe = ([ ]);

    describe += ([ d_name: mess ]);

} /* add_detail() */

/**
 * This method returns the current value of the detail for an item.
 * @param str the detail to get
 * @return the detail for an item
 */
string query_detail( string str ) {
    string key, name, *bits, *adjs;

    if( !mapp(describe) )
        return 0;

        if( describe[str] )
            return describe[str];

    bits = explode( str, " ");
    adjs = bits[0..<2];
    str = bits[<1];

    foreach( key in keys(describe) ) {
        bits = explode( key, " ");
        name = bits[<1];
        if( str == name || str == pluralize(name) ) {
            if( !sizeof(adjs) )
                return describe[key];
            if( !sizeof( bits = bits[0..<2] ) )
                continue;
            if( !sizeof( filter( adjs, (: member_array( $1, $2 ) == -1 :),
                bits ) ) )
                return describe[key];
        }
    }

    return 0;

} /* query_detail() */
