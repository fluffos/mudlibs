string subst(string str, string patt, string repl) {
  string new;
  int index, len1, len2;
  if (str == 0) str = "";
  if (!stringp(str))
   raise_error("subst(): Bad type to argument 1.\n");
  if (!stringp(patt))
   raise_error("subst(): Bad type to argument 2.\n");
  if (!stringp(repl))
   raise_error("subst(): Bad type to argument 3.\n");
  if (strstr(str, patt) == -1)
   return str;
  return implode(explode(str,patt),repl);
}

