#include <command.h>

int
main(string str)
{
  string mud;
  mixed *packet;

  if(!str) return notify_fail("usage: aq <mudname>#<packet[0]>#....\n");

  packet = explode(str, "#");

  mud = (string) packet[0];
  packet = packet[1..];

  "/obj/daemon/net/inetd"->AddPacketToQueue(mud, packet);

  return 1;
}
