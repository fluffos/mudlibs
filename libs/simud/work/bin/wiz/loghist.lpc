#include <const.h>

mapping parse_array(string *array, string flag) {
  string buf;
  mapping map = ([]);
  int x = 0;
  foreach (buf : array) {
    string name, timestr, junk, ip;
    int m, d, y, h, i, s, stamp;
    sscanf(buf, "%s from %s (%s): %s", timestr, junk, name, junk);
    if (!stringp(timestr))
      continue;
    if (flag == "in")
      sscanf(junk, "Login from %s (%s)", junk, ip);

    sscanf(timestr, "%d.%d.%d %d:%d:%d", d,m,y,h,i,s);
    stamp = s + (i * 60) + (h * 60 * 60) + (d * 60 * 60 * 24) + (m * 60 * 60 * 24 * 30) + (y * 60 * 60 * 25 * 365);

    if (this_player()->query_level() >= WIZLEVEL)
       map[stamp+":"+x] = ({timestr, name, flag, ip});
    else
       map[stamp+":"+x] = ({timestr, name, flag, ""});
    x++;
    if (x > 10)
      x = 0;
  }
  return map;
}

int main(string arg) {
  string tmp, *entrylog, *exitlog, *keys, buf;
  mapping lines;

  tmp = read_file("/log/entrylog");
  entrylog = explode(tmp,"\n");
  lines = parse_array(entrylog,"in");

  tmp = read_file("/log/exitlog");
  exitlog = explode(tmp,"\n");
  lines += parse_array(exitlog,"out");

  keys = sort_array(m_indices(lines), #'<)[0..15];
  keys = sort_array(keys, #'>);

  buf = "~CTITLogin/Logout History:";
  foreach (tmp : keys) {
    string *entry = lines[tmp];
    buf += "\n~CBRT"+entry[0];
    if (entry[2] == "in")
      buf += " ~CCOMLogin:  ";
    else
      buf += " ~CDRKLogout: ";
    buf += pad(entry[1], 15, 0);
    if(entry[3])
      buf += entry[3];
  }
  msg(buf+"~CDEF");

  return 1;
}
