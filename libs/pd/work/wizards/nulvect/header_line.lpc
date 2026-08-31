
varargs string header_line(string top) {
  string color = "%^RESET%^%^BLUE%^";
  string base =
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
  ;
  
  if (!nullp(top)) {
    int len;
    len = strlen(top) + 4;
    top = "%^BOLD%^%^BLUE%^( %^WHITE%^"+top+" %^BOLD%^%^BLUE%^)";
    base = base[0..3] + top + color + base[len+4 .. <1];
  }

  base = color + base + "%^RESET%^"; 

  return base;

}
