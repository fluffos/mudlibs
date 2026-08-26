/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: common.c,v 1.1 1998/01/06 04:27:40 ceres Exp $
 * $Log: common.c,v $
 * Revision 1.1  1998/01/06 04:27:40  ceres
 * Initial revision
 * 
*/
/*
 * The standard language unit.
 */

string long() {
  return 
"This is the normal language spoken by most creatures.\n";
}

mixed garble_tell(string start, string mess) {
  int i;
  string ret;

  ret = "";
  for (i=0;i<strlen(mess);i++)
    if (mess[i] != ' ')
      ret += "*";
    else
      ret += " ";
  return ({ start, ret });
}

mixed garble_shout(string start, string mess) {
  int i;
  string ret;

  ret = "";
  for (i=0;i<strlen(mess);i++)
    if (mess[i] != ' ')
      ret += "*";
    else
      ret += " ";
  return ({ start, ret });
}

mixed garble_say(string start, string mess) {
  int i;
  string ret;

  ret = "";
  for (i=0;i<strlen(mess);i++)
    if (mess[i] != ' ')
      ret += "*";
    else
      ret += " ";
  return ({ start, ret });
}
