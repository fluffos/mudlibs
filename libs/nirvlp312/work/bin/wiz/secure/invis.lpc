#include "/sys/security.h"

int cmd_invis(string str)
{
  int invis, level;
  string cap_name;
     
  level = (int)this_player()->query_level();
  if (level < INVIS) return 0;
  if (str)
     sscanf(str,"%d",invis);
  else
     invis = 100;
  if (level < 99999 && invis < 0)
    return 0;
  if (!invis) return 0;
  if (invis >= 100 && level < ALL_POWER)
     invis=100;
  if (invis >= INV7 && level < CINV7) invis = INV7 - 1;
  if (invis >= INV6 && level < CINV6) invis = INV6 - 1;
  if (invis >= INV5 && level < CINV5) invis = INV5 - 1;
  if (invis >= INV4 && level < CINV4) invis = INV4 - 1;
  if (invis >= INV3 && level < CINV3) invis = INV3 - 1;
  if (invis >= INV2 && level < CINV2) invis = INV2 - 1;
  if (invis >= INV1 && level < CINV1) invis = INV1 - 1;
  cap_name = (string)this_player()->query_name();
  this_player()->set_invis(invis);
  write("You are now invisible = "+invis+".\n");
  if (invis < INVIS_ACTION) 
    this_player()->remote_say(cap_name+" disappears.\n");
  if (invis >= SOMEONE) cap_name = "Someone";
  return 1;
}

