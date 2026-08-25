/* Unix-style wildcards.  Thrown up by Hamlet, Aug 1997 */

string wild2regexp(string pattern, int sloppy) {
  string tmp;
  int a, b;

  if(!strlen(pattern)) 
    return "^$";

  tmp = implode(explode(pattern, " ") - ({ "" }), " ");

  if(!strlen(tmp))
    return "^$";

  /* Escape things that have special meaning in regexp but not
     as wildcards.
  */
  tmp = replace_string(tmp, ".", "\\.");
  tmp = replace_string(tmp, "+", "\\+");
  tmp = replace_string(tmp, "$", "\\$");
//tmp = replace_string(tmp, "{", "\\{");
//tmp = replace_string(tmp, "}", "\\}");
  
  /* Next bit is a silly hack because I suspect it's faster than a loop */
  tmp = replace_string(tmp, "[^", "!@#(");
  tmp = replace_string(tmp, "^", "\\^");
  tmp = replace_string(tmp, "!@#(", "[^");
  
  /* next, translate wildcards into regexp syntax */
  tmp = replace_string(tmp, "*", ".*");
  tmp = replace_string(tmp, "?", ".");
  /* note that [] doesn't need changed */

  /* Unlike regular expressions, spaces and commas denote a list of things */
  tmp = replace_string(tmp, " ", "|");
  tmp = replace_string(tmp, ",", "|");

  tmp = "^" + tmp;

  if(!sloppy) /* If we're being strict, We force matched termination */
    tmp += "$";

  return tmp;
}

/* This one works in the same way as regexp() but with unix-type
   wildcards instead.  (flag & 1) still means return indices in
   the return.  (flag & 2) still means reverse the matching.
   (flag & 4) means sloppy end-of-string stuff.
*/
mixed wildcard(mixed junk, string pattern, int flag) {
  string tmp = wild2regexp(pattern, (flag & 4));

  return regexp(junk, tmp, flag);
}
