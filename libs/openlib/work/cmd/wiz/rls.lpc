#include <command.h>
#include <net/daemons.h>

int
main(string args)
{
  string mudname, dir;

  if( !args || sscanf(args, "%s/%s", mudname, dir) != 2 )
    return notify_fail("usage: rls <mudname>/<path>\n"
		       "example: rls Dysfunctional Mud/stuff/things.doc\n");

  if( !(mudname = INTERMUD_D->GetMudName(mudname)) )
    return notify_fail(mud_name() + " is not aware of such a place.\n");

  SERVICES_D->eventSendFileListRequest(mudname, (dir == "" ? "." : dir));
  OOB_D->OOBBegin(mudname, 1, 0);
  printf("Remote file list request sent to %s\n", mudname);
  return 1;
}
