#include <kernel.h>

#define CRITICAL_PROTECTIONS ({ \
		    "Glandon:", \
		    })

void notify_finish_snoop(object snooped, object snoopee)
{
  if (member(CRITICAL_PROTECTIONS,
             SECURITY->query_protection(environment(snooped),1)) > -1)
    log_file("SNOOP",ctime(time())+" "+snoopee->query_vis_name()+
		     " finished imasnooping "+snooped->query_vis_name()+
		     " in "+object_name(environment(snooped))+".\n");
}

void notify_snoop(object snooped, object snoopee)
{
  if (member(CRITICAL_PROTECTIONS,
             SECURITY->query_protection(environment(snooped),1)) > -1)
    log_file("SNOOP",ctime(time())+" "+snoopee->query_vis_name()+
		     " imasnooped "+snooped->query_vis_name()+
		     " in "+object_name(environment(snooped))+".\n");
}
