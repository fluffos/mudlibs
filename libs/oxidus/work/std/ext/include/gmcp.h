#ifndef __GMCP_H__
#define __GMCP_H__

void gmcp(string message) ;
varargs void do_gmcp(string package, mixed data) ;
mixed gmcp_stringify(mixed data) ;
void clear_gmcp_data() ;
void set_gmcp_client(mapping data) ;
mapping query_gmcp_client() ;
void set_gmcp_supports(mapping data) ;
mapping query_gmcp_supports() ;
int query_gmcp_supported(string fullname) ;
public int gmcp_enabled() ;

#endif // __GMCP_H__
