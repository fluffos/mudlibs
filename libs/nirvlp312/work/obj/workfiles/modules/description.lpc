/*
 * Module for descriptions.  long and short
 * Rumplemintz@Nirvana - 10-Nov-2010
 */

#pragma strong_types

private mixed short_desc;
private mixed long_desc;
private mixed extra_long_desc;
private mixed name_desc;
private mixed read_msg;
private mixed info;

varargs void set_short(mixed str) { short_desc = str; }
varargs void set_long(mixed str) { long_desc = str; }
void set_extra_long(mixed str) { extra_long_desc = str; }
void set_name(mixed name) { name_desc = name; }
string query_name() { return name_desc; }
string query_short() { return short_desc; }
string query_info() { return info; }
string query_read_msg() { return read_msg; }

string query_long() {
  if (extra_long_desc)
    long_desc = long_desc + extra_long_desc;
  write(long_desc);
}

void set_read(mixed str) { read_msg = str; }
void set_info(mixed str) { info = str; }

/* Below functions provide a way to get the name, short, and long when
 * items overload the above functions
 */

string query_real_name() { return name_desc; }
string query_real_short() { return short_desc; }
string query_real_long() {
  if (extra_long_desc)
    long_desc = long_desc + extra_long_desc;
  return long_desc;
}

string short() { return query_short(); }
varargs string long() { return query_long(); }
string extra_long() { return extra_long_desc; }
