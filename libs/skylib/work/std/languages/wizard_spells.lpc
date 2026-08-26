/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: wizard_spells.c,v 1.1 1998/01/06 04:27:40 ceres Exp $
 * $Log: wizard_spells.c,v $
 * Revision 1.1  1998/01/06 04:27:40  ceres
 * Initial revision
 * 
*/
/*
 * used for wizard spells...
 * Spider writing (poke sean)
 * Who's Sean?
 */

string garble_text( mixed text, object thing ) {
  string bing;
   if ( pointerp( text ) )
    if ( ( bing = (string)text[ 0 ]->garble_text( text, thing ) ) )
      return bing;
  return "You cannot read the spidery writing.\n";
} /* garble_text() */

string magical_text( mixed text, object thing ) {
  string bing;
  if ( pointerp ( text ) )
    if ( ( bing = (string)text[ 0 ]->magic_text( text, thing ) ) )
      return bing;
    else
      return "The spell "+ text[ 1 ] +" seems to be written here in spidery "+
        "writing.\n";
  return text;
} /* magical_text() */
