#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}


protected int cmd(string str, object me) {
  int tim, num;
  string *bits;

  write("Up for ");
  tim = uptime();
  bits = ({ });
  if (tim > 60*60*24)
    bits += ({ (num=tim/(60*60*24))+" day"+(num==1?"":"s") });
  if (tim > 60*60 && tim%(60*60*24))
    bits += ({ (num=(tim/(60*60))%24)+" hour"+(num==1?"":"s") });
  if (tim > 60 && tim%(60*60))
    bits += ({ (num=(tim/60)%60)+" minute"+(num==1?"":"s") });
  if (tim%60)
    bits += ({ (num=tim%60)+" second"+(num==1?"":"s") });
  if (sizeof(bits) > 1)
    write(implode(bits[0..sizeof(bits)-2], ", ")+" and "+
          bits[sizeof(bits)-1]+".\nMore useless info "+
          query_load_average()+".\n");
  me->set_trivial_action();
  return 1;
} /* do_uptime() */


