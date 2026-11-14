/* SilberLand MUDlib
 *
 * /secure/master/domain.c -- domain handling of master object
 *
 * $Date: 2001/01/18 10:37:19 $
 * $Revision: 1.1 $
 * $Log: domain.c,v $
 * Revision 1.1  2001/01/18 10:37:19  Samtpfote
 * Initial revision
 *
 * Revision 1.1  1997/03/16 00:00:53  Woody
 * prepared for revision control
 *
 */

#pragma strong_types

#include "/secure/master.h"

int domain_master(string user, string domain) {
  string *domains;
  int i;
  
  if (!find_userinfo(user) ||
      !pointerp(domains=get_userinfo(user)[USER_DOMAIN+1]))
    return 0;
  return (member(domains,domain) != -1);
}

int domain_member(string user, string domain)
{
  return (file_size("/d/"+domain+"/"+user)==-2);
}

int add_domain_master(string user,string dom)
{
  string domainlord;
  mixed *domains;
  
  if ((domainlord = geteuid(PO)) != ROOTID && !IS_ARCH(domainlord) ||
      !find_userinfo(user))
    return 0;
  domains=get_userinfo(user)[USER_DOMAIN+1];
  if (domains == 0) 
    set_domains(user, ({dom}));
  else
    if (member(domains,dom) == -1)
    {
      domains += ({dom});
      set_domains(user, domains);
    }
  if (get_wiz_level(user) < LORD_LVL+5)
    update_wiz_level(user,LORD_LVL+5);
  return 1;
}

int remove_domain_master(string user,string dom)
{
  string domainlord;
  mixed *domains;
  
  domainlord = geteuid(PO);
  if (domainlord != ROOTID && !IS_ARCH(domainlord) || !find_userinfo(user) ||
      !(domains=get_userinfo(user)[USER_DOMAIN+1]) || member(domains,dom) == -1)
    return 0;
  domains -= ({dom});
  set_domains(user, domains);
  return 1;
}

string *get_domains()
{
  string *regions;
  int i;
  
  if(!(regions=get_dir("/d/*",1))) return ({});
  for (i=sizeof(regions)-1;i>=0;i--)
    if (file_size("/d/"+regions[i])!=-2) regions[i]=0;
  regions-=({0,"..","."});
  return regions;
}

string *get_domain_homes(string wiz)
{
  string *homes;
  int i;
  
  if (!wiz || wiz=="") 
    return ({});
  for (i=sizeof(homes=get_domains())-1;i>=0;i--)
    if (file_size("/d/"+homes[i]+"/"+wiz)!=-2) homes[i]=0;
  homes-=({0});
  return homes;
}
