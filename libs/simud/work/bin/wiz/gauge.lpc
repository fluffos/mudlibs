#include <profile.h>
#include <const.h>

int main(string arg) {
  mixed data;
  int result;

  WIZ_CHECK;

  if(!arg) {
    return notify_fail("==> [Format] gauge <command>\n");
  }

  PROF(GAUGE,
       result = command(arg,this_player());
       );

  data = PROFILED->query_last_exec_data();
  msg(arg+":");
  msg("   Eval Cost: "+data[PROF_EVALC]);
  msg("   Real Time: "+PROFILED->tdelta_to_string(data[PROF_TDELTA])+
      " seconds");
  return 1;
}



