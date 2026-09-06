#include <mxp.h>
#include <driver/telnet.h>

public mixed QueryMXP();

public void init_mxp() {
  // Tell the client that from now on we are sending MXP sequences
  //binary_message(({IAC, SB, TELOPT_MXP, IAC, SE}));

  // Switch to "permanent secure" mode, MXP tags now enabled
  write(process_mxp(MXPMODE(6), QueryMXP()));

  write(process_mxp(MXPTAG("!-- Set up MXP elements --"), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT RNum FLAG=\"RoomNum\" ATT=\"id\" EMPTY"), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT RName FLAG=\"RoomName\""), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT RDesc FLAG=\"RoomDesc\""), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT RExits FLAG=\"RoomExit\""), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT Prompt FLAG=\"Prompt\""), QueryMXP()));
  write(process_mxp(MXPTAG("!ELEMENT Ex \"<send>\""), QueryMXP()));
}
