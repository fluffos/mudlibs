/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: drunk.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: drunk.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
/*
 * drunk.c - Shadow for drunk effect.  Handles the slurred speech.
 */

inherit "/std/effect_shadow";

string mangle_speech( string s ) {
    string s1;

    s1 = player->mangle_speech( s );
    return replace( stringp(s1)?s1:s,
                   ({ "s", "sh", "r", "rr", "ing", "in'", "x", "xsh",
                        "S", "SH", "R", "RR" }));
} /* mangle_speech() */
