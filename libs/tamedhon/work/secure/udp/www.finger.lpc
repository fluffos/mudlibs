/* Tamedhon MUDlib
 *
 * /secure/udp/www.finger.c -- WWW finger
 *
 * $Date: 1997/03/16 00:43:22 $
 * $Revision: 1.1 $
 * $Log: www.finger.c,v $
 * Revision 1.2  2004/10/10 18:30:00  Querolin
 * Redesign
 *
 * Revision 1.1  1997/03/16 00:43:22  Woody
 * prepared for revision control
 *
 */

// MorgenGrauen MUDlib Contribution

#pragma strong_types
#pragma combine_strings

#include <properties.h>
#include <www.h>

string Request(mapping cmds)
{
  if(!sizeof(cmds) || !stringp(cmds[USER]))
    return ERROR("Kein Nutzer angegeben!");
  return "<H2>Wer ist "+capitalize(cmds[USER])+"?</H2><CENTER><PRE>"
        +FINGER(cmds[USER])+"</CENTER></PRE>";
}
