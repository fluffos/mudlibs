#ifndef __LINK_INFO__
#define __LINK_INFO__

#define SERVER_NAME "Primal Darkness II, Site 1"
#define SERVER  /* If mud is a server */
#undef  LEAF    /* If mud is a leaf   */
#ifdef  SERVER
#define LISTEN_PORT 3031 /* if server, what port to listen on */
#endif  
 
#ifdef  LEAF /* if leaf, what is the servers ip and port */
#define SERVER_IP 209.85.145.196
#define CONNECT_PORT 3031
#endif

#endif /* __LINK_INFO__ */
