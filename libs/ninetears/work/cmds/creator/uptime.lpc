#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}


int cmd(string str, object me) {
  int tim, num;
  string *bits;

  write("\nActivo desde hace ");
  tim = uptime();
  bits = ({ });
  if (tim > 60*60*24)
    bits += ({ (num=tim/(60*60*24))+" dia"+(num==1?"":"s") });
  if (tim > 60*60 && tim%(60*60*24))
    bits += ({ (num=(tim/(60*60))%24)+" hora"+(num==1?"":"s") });
  if (tim > 60 && tim%(60*60))
    bits += ({ (num=(tim/60)%60)+" minuto"+(num==1?"":"s") });
  if (tim%60)
    bits += ({ (num=tim%60)+" segundo"+(num==1?"":"s") });
  if (sizeof(bits) > 1)
    write(implode(bits[0..sizeof(bits)-2], ", ")+" y "+
          bits[sizeof(bits)-1]+".\nMas informacion inutil "+
          query_load_average()+".\n");
  return 1;
} /* do_uptime() */


