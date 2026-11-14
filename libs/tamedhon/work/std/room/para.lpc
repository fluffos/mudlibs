// This may look like C code, but it is really -*- C++ -*-

#pragma strong_types
#define NEED_PROTOTYPES
#include <properties.h>
#include <moving.h>

int paramove() {
  int para;
  string sname,dname;
  object dest;
  
  if (!(para=this_player()->QueryProp(P_PARA)) || !intp(para) ||
      sizeof(regexp(({sname=object_name(this_object())}),"\\^[0-9]*$")))
    return 0;
  dname=sprintf("%s^%d",sname,para);
  if (!(dest=find_object(dname))) {
    catch(call_other(dname,"???"));
    if (!(dest=find_object(dname)))
      return 0;
  }
  if (this_player()->move(dest,M_GO|M_SILENT|M_NO_SHOW)<=0)
    return 0;
  return 1;
}
