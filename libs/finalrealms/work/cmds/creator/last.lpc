// Externalized from /global/last.c  - Only for creators
// Radix : Jan 21, 1996
// Made it a bit more accurate (now includes seconds)
// Radix : Aug 22, 1996

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
   position = 1;
}

string mtime(int i) {
  string str;

  str = ctime(i);
  return str[0..strlen(str)-6];
}
string stime(int i) {
  return ctime(i)[11..18];
}

string ntime(int i) {
  return sprintf("%02d:%02d", (i/3600), (i/60)%60);
}


protected int cmd(mixed str, object me)
{
  string file, s1, s2, s3, s4, s5, *sarr;
  int time, t2, i;
  int lines, fsize;

  if (!str || str == "") {
    notify_fail("Usage: last -N <name>\n");
    return 0;
  }
  me->set_trivial_action();
  if (sscanf(str, "-%s %s", s1, str) == 2)
    sscanf(s1, "%d", lines);
  if (str == "reboot") {
    fsize = file_length("/log/REBOOT");
    if (lines)
      file = read_file("/log/REBOOT", fsize-lines, fsize);
    else
      file = read_file("/log/REBOOT");
    sarr = explode(file, "\n");
    for (i=0;i<sizeof(sarr);i++)
      if (sscanf(sarr[i], "%s[%d]%s", s1, time, s2) == 3)
        tell_object(me,sprintf("%15-s %s\n", "reboot", mtime(time)));
    return 1;
  }
  fsize = file_length("/log/ENTER");
  if (lines)
    file = read_file("/log/ENTER", fsize-lines, fsize);
  else
    file = read_file("/log/ENTER");
  str = (string)me->expand_nickname(str);
  while (sscanf(file, "%sEnter : "+str+"%s[%d]%s",s1, s3, time, s2) == 4) {
    file = s2;
    if (sscanf(file, "%sExit  : "+str+"%s[%d]%s", s1, s5, t2, s2) != 4)
      if (!find_player(str))
        tell_object(me,sprintf("%15-s %s - Destd (??:??)\n", str, mtime(time)));
      else
        tell_object(me,sprintf("%15-s %s - Not logged off\n", str, mtime(time)));
    else {
      if (sscanf(file, "%sEnter : "+str+"%s", s3,s4) == 2)
        if (strlen(s1) > strlen(s3)) {
          tell_object(me,sprintf("%15-s %s - %s (%s)\n", str, mtime(time), "Destd", "??:??"));
          continue;
        }
      tell_object(me,sprintf("%15-s %s - %s (%s)\n", str, mtime(time), stime(t2), ntime(t2-time)));
      file = s2;
    }
  }
  tell_object(me,ctime(time())+"\n");
  return 1;
}
