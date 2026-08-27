#include <command.h>

mapping cbmap = ([]);

int
main(string addr)
{
  if(!addr || addr == "")
    return notify_fail("usage: nslookup <address>\n");

  cbmap += ([
	     resolve(addr, "callback") : this_player()
	     ]);

  write("Query sent.\n");
  return 1;
}

void
callback(string address, string resolved, int key)
{
  tell_object(cbmap[key],
	      sprintf("nslookup report:\n"
		      "ip: %s\n"
		      "name: %s\n",
		      resolved,
		      address));
}
