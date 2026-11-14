#pragma no_clone
#pragma no_inherit
#pragma no_shadow
#pragma strong_types

#include <properties.h>

private string ulog = "";

void WaitForQuarterHour();

void create(){
  if (sizeof(explode(object_name(this_object()),"#"))>1)
  {
    destruct(this_object());
    return;
  }
  WaitForQuarterHour();
}

void QuarterReached()
{
  int std;
  int min;
  string ct, str, format;
  object *u;
  int i;

  sscanf((ct=ctime(time()))[11..15],"%d:%d", std, min);

  if (min <= 2)
  {
  	u=users();
	for (i=sizeof(u)-1;i>=0;i--)
	{
	  format=u[i]->QueryProp(P_CLOCKMSG)||"Du hörst die Uhr schlagen: Es ist jetzt %d Uhr.\n";
	  if (strstr(format,"%d",0)==-1)
	  	str=format;
	  else
	  	str=sprintf(format,std);
	  if (str!="") tell_object(u[i],str);
	}
  }
  str = "";
  if (min < 10)
  {
    log_file("USER_STATISTIK", ulog);
    ulog = sprintf("\n%s%02d: ",(!std?("# "+ct+":\n"):""),std);
  }
  ulog += sprintf("%4d",sizeof(users()));
  WaitForQuarterHour();
}

void WaitForQuarterHour()
{
  while(remove_call_out("QuarterReached")!=-1);
  call_out("QuarterReached",900-(time() % 900));
}
