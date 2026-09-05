#pragma strong_types  // Coogan, 08-May-2002

#ifndef TESTMUD
#include <kernel.h>
#include <names.h>

inherit ACCESS;

int when;

void reset(int arg) {
  if (arg ||
      this_player() ||
      object_name(previous_object())!="kernel/master" ||
      query_host_name()!=HOME_HOST)
    return;
  log_file("REBOOT",
           ctime(time()) + ": Driver rebooted (version " + version() + ").\n");
  when = time();
  unguarded(1, #'save_object, "/save/reboot_time");
}
#endif

