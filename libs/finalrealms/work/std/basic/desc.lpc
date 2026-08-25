inherit "/std/basic/label"; 

nosave string short_d,
       plural_d,
       long_d;

// Maybe I'm going insane, but this is the THIRD time I'm having
// to do this here...  Radix Jan 12, *1997*
void set_short(string str)
{
   if(stringp(str))
      str = replace_string(str,"\n","");
   short_d = str;
}
void set_long(string str) { long_d = str; }
void set_main_plural(string str) { plural_d = str; }

string query_short() { return short_d; }
string query_long() { return long_d; }
string query_main_plural() { return plural_d; }

string short(int dark) {
  return short_d; 
}

string pretty_short(int dark) {
  return (string)this_object()->short();
}

string long(string str, int dark) {
  if (!long_d)
    return "You see nothing particularly interesting.\n";
  return long_d;
}

string query_plural() {
  if (!plural_d)
    if (!short(0))
      return 0;
    else
      return pluralize(short(0));
  return plural_d;
}

mixed pretty_plural() {
  return query_plural();
}

