/**
 * Replaces all occurances of a set of strings in the input string.  Replaces
 * an individual or an array of strings with new values.  If the second
 * argument is an array of strings, then the 1st, 3rd, 5th...  elements will
 * be the strings to search for and the 2nd, 4th, 6th etc will be the strings
 * to replace with.  If three arguments are specified then the second is the string
 * to search for, the third the one to replace.
 * <p>
 * Eg:<br>
 * str = replace(str, ({ "search", "replace", "orange", "apple" });<p>
 * That will replace all occurances of "search" with "replace" and "orange"
 * with "apple".
 *
 * @param str the string to do the replacement in
 * @param bing the search or array argument
 * @param rep the replacement string, or null 
 *
 * @return the string with all the replacements done
 */
varargs string replace(string str, mixed bing, string rep) {   
  int i;

  if (pointerp(bing)) {
    for (i=0;i<sizeof(bing);i+=2) {
      if (stringp(bing[i]) && stringp(bing[i+1])) {
        str = replace_string(str, bing[i], bing[i+1]);
      }
    }
    return str;
  }
  if(!stringp(str) || !stringp(rep))
    return str;
  return replace_string(str, bing, rep);
}
