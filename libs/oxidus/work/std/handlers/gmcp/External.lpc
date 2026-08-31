#include <daemons.h>
#include <gmcp_defines.h>

inherit __DIR__ "gmcp_module";

void Discord(string submodule, mixed data) {
  object prev = previous_object(1);

  switch(submodule) {
    case "Hello":
      // Handle the External.Discord.Hello message
      GMCP_D->send_gmcp(prev, GMCP_PKG_EXTERNAL_DISCORD_HELLO);
      break;
    case "Get" :
      // Handle the External.Discord.Get message
      GMCP_D->send_gmcp(prev, GMCP_PKG_EXTERNAL_DISCORD_GET);
      break;
  }
}
