#include <uid.h>

int cmd_ageother(string tmp) {
  int age;
  object target;

  seteuid(ROOT_UID);
  if (!tmp) {
    write("Usage: ageother <days>\n");
    return 1;
 }

  if (sscanf(tmp, "%d %d", tmp, age) != 2) {
    write("Usage: ageother <target> <days>\n");
    return 1;
  }

  write (tmp +" "+ age +"\n");
  target = find_living(tmp);
  if (!target) {
    write("That person is not currently logged on.\n");
    return 1;
  }

  target->set("age", age * 86400 );
  write("Okay.\n");
  return 1;
}

int help() {
  write(@ENDHELP
Usage: ageother <days>

This command will make you EXACTLY x days old.  Exciting, isn't it?
Another useful admin utility brought to you by Chronos.
ENDHELP
  );
  return 1;
}
