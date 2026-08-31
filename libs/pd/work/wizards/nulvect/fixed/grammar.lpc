// sefuns related to english grammar
// Nulvect 2007-11-10

// removes "a", "an", and "the" from the front of a string
// needed due to inconsistencies among builders
string remove_article(string str) {
  string tmp;
  int i;
  if (!strlen(str)) return "";

  i = strsrch(str, " ");
  if (i == -1) return str;

  tmp = lower_case(str[0..i-1]);
  switch(tmp) {
    case "the": case "a": case "an":
      return str[i+1..<1];
    default:
      return str;
  }

  return str;
}

// these two let you consistently use the correct article in a string
string definite_article(string str) {
  return "the "+remove_article(str);
}
string indefinite_article(string str) {
  str = remove_article(str);
  return a_or_an(str)+" "+str;
}

// takes an array and spits out a list suitable for printing
varargs string list(string *items, int cons, string join) {

  if (!sizeof(items)) return "";
  if (nullp(cons)) cons = 0;
  if (nullp(join)) join = "and";

  if (cons) items = consolidate_string(copy(items));

  switch (sizeof(items)) {
    case 0: return "";
    case 1: return items[0];
    default:
      return
        implode( map( items[0..<3], (: $1+", " :) ) +
        ({ items[<2] + " "+join+" ", items[<1] }), "");
  }

  // should never get here
  return implode(items, " ");
}
