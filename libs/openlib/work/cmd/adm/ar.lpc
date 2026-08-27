#include <command.h>
#include <net/daemons.h>

int
main(string mud)
{
  if(!mud) return notify_fail("usage: ar <mud> - send auth-req to a mud\n");
  mud = INTERMUD_D->GetMudName(mud);
  if(!mud) return notify_fail("No such mud.\n");
  SERVICES_D->eventSendAuthRequest(mud);
  return 1;
}
