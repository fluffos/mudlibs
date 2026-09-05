/*
 * inherit/timer.c
 * A set of inheritable timer functions
 */

int query_time_left() { return find_call_out("time_out"); }

varargs string query_std_time(int time) {
  string str;

  str = "";
  if (!time) time = query_time_left();
  if (time / 604800) {
    str += (time / 604800) + " Weeks ";
    time = time % 604800;
  }
  if (time / 86400) {
    str += (time / 86400) + " Days ";
    time = time % 86400;
  }
  if (time / 3600) {
    str += (time / 3600) + " hours ";
    time = time % 3600;
  }
  if (time / 60) {
    str += (time / 60) + " minutes ";
    time = time % 60;
  }
  str += time + " seconds";
  return str;
}

varargs query_approx_time(int time) {
  string str;

  str = "";
  if (!time) time = query_time_left();
  if (time / 604800) return (time / 604800) + " Weeks";
  if (time / 86400) return (time / 86400) + " Days";
  if (time / 3600) return (time / 3600) + " hours";
  if (time / 60) {
    time /= 60;
    if (time > 45) return "three quarters of an hour";
    if (time > 30) return "half an hour";
    if (time > 15) return "quarter of an hour";
    if (time > 10) return "10 minutes";
    if (time > 5) return "5 minutes";
    if (time > 2) return "2 minutes";
    return "1 minute";
  }
  if (time > 45) return "45 seconds";
  if (time > 30) return "30 seconds";
  return "10 seconds";
}

void time_out() {
  remove_call_out("time_out");
  destruct(this_object());
}

void adj_time(int t) {
  t += query_time_left();
  remove_call_out("time_out");
  if (t < 1) t = 1;
  call_out("time_out", t);
}

