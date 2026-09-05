#include <ansi.h>

#define NDLOG "nd-daem.log"

#define DAWN    6
#define DAY     8
#define DUSK    18
#define NIGHT   20

int      data;
object   ob;

void chg_data(int cond)
{
 string msg;

 data=cond;

 log_file(NDLOG,
    " "+(string)this_object()->query_data_string()+"\n");
 switch(data)
 {
  case DAWN:
   msg="(msg) Far away, a rooster crows.\n"+
       "A "+HIY+"sunrise"+NORM+" is dawning upon Nirvana.\n";
   break;
  case DAY:
   msg="(msg) Daylight has spread all across Nirvana.\n";
   break;
  case DUSK:
   msg="(msg) The sun begins its slow descent back beneath the heavens.\n"+
       "The sky settles into dusk.\n";
  case NIGHT:
   msg="(msg) "+HIK+"Night"+NORM+" has fallen upon Nirvana.\n";
   break;
 }

  emit_channel("msg", msg);

/*
  if(ob=find_player("vertebraker"))
   tell_object(ob, msg);
*/
  call_out("call_time", 2);
}

void call_time()
{
 int hr, min, x, y;
 log_file(NDLOG,
  ctime());
 sscanf(ctime()[11..15],"%d:%d",hr,min);
 if(hr == DAWN || hr == DAY || hr == DUSK || hr == NIGHT)
 {
  data=hr;
  return;
 }
 if(hr > NIGHT || hr < DAWN)
 {
  data = NIGHT;
  y = DAWN;
 }
 else if(hr < DAY)
 {
  data = DAWN;
  y = DAY;
 }
 else if(hr < DUSK)
 {
  data = DAY;
  y = DUSK;
 }
 else
 {
  data = DUSK;
  y = NIGHT;
 }
 if(hr > NIGHT) hr = (-(24-hr));
 x = (((60-min)*60)+((y-hr-1)*3600));
 if(ob=find_player("vertebraker"))
  tell_object(ob, "changing in "+x+" ("+(x/3600)+"h)\n");
 log_file(NDLOG,
   " changing in "+x+"\n");
 call_out("chg_data", x, y);
}

void reset(status x)
{
 if(x) return;
 call_out("call_time", 1);
}

int query_data()
{
 return data;
}

string query_data_string()
{
 switch(data)
 {
  case DAWN:  return "dawn";
  case DAY:   return "day";
  case DUSK:  return "dusk";
  case NIGHT: return "night";
 }
}

status print_data()
{
 write("data: "+data+"\n");
 write("ds:   "+query_data_string()+"\n");
 return 1;
}

