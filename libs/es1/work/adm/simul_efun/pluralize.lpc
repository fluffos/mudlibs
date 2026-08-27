/*
// file:    pluralize.c
// purpose: this file does the brunt of the pluralization work.
// author:  Pinkfish 
// history: written by pinkfish one day, and modified for the TMI
//   distribution mudlib by Buddha on 3-14-92.  No changes were needed. ;-)
*/
/*
 * NB: it is always preferable for objects to set their plural using
 *     "set_plural()" (on std/object), but if the relevant programmer hasn't
 *     done so, "query_plural()" (also on std/object) calls this efun for
 *     a hopefully reasonable approximate.  objects should _always_ call
 *     call "query_plural()" to get the plural form of an object's "short()",
 *     failure to do so is treason, and subject to punishment by summary
 *     execution.  The Computer is your friend.
 */

#define VOWELS ({'a', 'e', 'i', 'o', 'u'})
 
string pluralize(string str) {
  string pre, suf;
  mixed rel, two;
  int i;

  if (!stringp(str)) return ""; 
  if (strlen(str) <= 1) return "";

  /*
   * first, get rid of determiners.  pluralized forms never have them ;)
   */  
  sscanf(str, "a %s", str);
  sscanf(str, "an %s", str);
  sscanf(str, "the %s", str);
  sscanf(str, "A %s", str);
  sscanf(str, "An %s", str);
  sscanf(str, "The %s", str);

  /*
   * Deal with "sword of power" -> "swords of power" types (Watcher 09/92)
   */
   if(sscanf(str, "%s of %s", pre, suf) == 2)
      return pluralize(pre) + " of " + suf;
 
  /*
   * only pluralize the last word, ie: lose adjectives.
   */
  rel = explode(str, " ");
  if (!rel) {
    pre = "";
    rel = str;
  } else {
    pre = implode(rel[0..sizeof(rel)-2], " ");
    if (sizeof(rel) > 1)
      pre += " ";
    rel = rel[sizeof(rel)-1];
  }
  /*
   * trap the exceptions to the rules below and special cases.
   */
  switch (rel) {
    case "fish" :
    case "deer" :
    case "sheep" :
      return pre+rel;
    case "child" :
      return pre+rel+"ren";
    case "tooth" :
      return pre+"teeth";
    case "ox" :
    case "vax" :
      return pre+rel+"en";
    case "bus" :
      return pre+rel+"es";
  }
  i = strlen(rel)-1;
  /*
   * now handle "rules" ... god I hate english!!
   */
  /*
   * *x -> *xes (fox -> foxes)
   * *s -> *ses (pass -> passes)
   * *ch -> *ches (church -> churches)
   * *sh -> *shes (brush -> brushes)
   */
  two = rel[i-1..i];
  if ((rel[i] == 's') || (rel[i] == 'x') || 
      (two == "ch") || (two == "sh"))
    return pre+rel+"es";
  /*
   * *ff -> *ves (staff -> staves)
   * *fe -> *ves (knife -> knives)
   */
  if ((two == "ff") || (two == "fe"))
    return pre+rel[0..i-2]+"ves";
  /*
   * *f -> *ves (half -> halves)
   * *ef -> *efs (chef -> chefs) (really a rule for a special case)
   */
  if (rel[i] == 'f') {
    if (rel[i-1] == 'e')
      return pre+rel+"s";
    return pre+rel[0..i-1]+"ves";
  }
  /*
   * *y -> *ies (gumby -> gumbies)
   */
  if (rel[i] == 'y' && (member_array(rel[i - 1], VOWELS) == -1))
    return pre+rel[0..i-1]+"ies";
  /*
   * *us -> *i (virus -> viri)
   */
  if (two == "us")
    return pre+rel[0..i-2]+"i";
  /*
   * *man -> *men (foreman -> foremen)
   */
  if (rel[i-2..i] == "man")
    return pre+rel[0..i-3]+"men";
  /*
   * *is -> *es (this is from gordons pluralize ... )
   */
  if (two == "is")
    return pre+rel[0..i-2]+"es";
  /*
   * *o -> *s (also from gordon)
   */
  if (rel[i] == 'o')
    return pre+rel[0..i-1]+"s";
  /*
   * default: (* -> *s)
   */
  return pre+rel+"s";
} /* end of pluralize() */

// mudlib: Basis
// note:   heavily based on Pinkfish's pluralizer (but simplified since this
//         one isn't meant to handle nouns or articles etc)

string pluralize_verb(string rel)
{
   string two;
   int i, ch, len;

   if (!stringp(rel) || ((len = strlen(rel)) < 2)) {
      return ""; 
   }
    // trap the exceptions to the rules below and special cases.
   switch (rel) {
   case "half" :
      return "halves";
   case "fish" :
      return rel;
   }
   i = len - 1;
   ch = rel[i];
   //
   // *x -> *xes (fox -> foxes)
   // *s -> *ses (pass -> passes)
   // *ch -> *ches (church -> churches)
   // *sh -> *shes (brush -> brushes)
   two = rel[(i - 1) .. i];
   if ((ch == 's') || (ch == 'x') || (two == "ch") || (two == "sh")) {
      return rel + "es";
   }
   if (two == "is") {
      return rel + "ses";
   }
   if (two == "iz") {
      return rel + "zes";
   }
   // *ife -> *ives (knife -> knives)
   if (rel[(i - 2) .. i] == "ife") {
      return rel[0 .. (i - 2)] + "ves";
   }
   // *y -> *ies (gumby -> gumbies)
   if ((ch == 'y') && (member_array(rel[i - 1], VOWELS) == -1)) {
      return rel[0 .. (i - 1)] + "ies";
   }
   // default: (* -> *s)
   return rel + "s";
}

