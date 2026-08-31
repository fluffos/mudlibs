
varargs string header_line(mixed top, int w) {
  string color = "%^RESET%^%^BLUE%^";
  int width;
  string base;

  if (!nullp(top) && intp(top))
    width = top;

  if (!nullp(w) && intp(w))
    width = w;

  if (!width || width < 75)
    width = (this_player() ? to_int(this_player()->getenv("SCREEN")) : 75);

  base =
    "=" + repeat_string("+=", to_int((width-2)/2))
  ;
  
  if (stringp(top)) {
    int len;
    len = strlen(strip_color(top)) + 4;
    top = "%^BOLD%^%^BLUE%^( %^WHITE%^"+top+" %^BOLD%^%^BLUE%^)";
    base = base[0..3] + top + color + base[len+4 .. <1];
  }

  base = color + base + "%^RESET%^"; 

  return base;

}
