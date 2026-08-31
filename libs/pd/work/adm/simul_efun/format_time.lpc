
varargs string format_time(int secs, string units) {
  string ret = "";
  string *order = ({ "y", "w", "d", "h", "m", "s" });

  if (!secs) return "";
  if (!units) units = "ywdhms";

  units = lower_case(units);

  foreach (string unit in order) {
    int tmp;
    string label;

    if (strsrch(units, unit) == -1) continue;

    switch(unit) {
      case "y":
        label = "year";
        tmp = secs / 31536000;
        secs %= 31536000;
      break;

      case "w":
        label = "week";
        tmp = secs / 604800;
        secs %= 604800;
      break;

      case "d":
        label = "day";
        tmp = secs / 86400;
        secs %= 86400;
      break;

      case "h":
        label = "hour";
        tmp = secs / 3600;
        secs %= 3600;
      break;

      case "m":
        label = "minute";
        tmp = secs / 60;
        secs %= 60;
      break;

      case "s":
        label = "second";
        tmp = secs;
      break;
    }

    if (tmp) {
      if (tmp != 1) label = pluralize(label);
      ret += tmp + " " + label + " ";
    }
  }

  if (!ret) ret = "";
  else ret = ret[0..<2]; // remove the trailing space

  return ret;
}

