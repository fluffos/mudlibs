/* Hamlet, Feb 1996.  -- This gets called to do the xfinger command.
   Hamlet, Jun 1997.  -- reworked to use inquired.  Doesn't need cloned
                         any more.  Simplified, cleaned the code, etc.
*/

#include <inquire_err.h>
#include <socket.h>

#define INTERNIC "rs.internic.net"

mapping servers;
mapping fds;

void whois_cb(int fd, int success, mixed response, 
              string wordip, string numericip);

void do_whois(object me, string data, string server) {
  int ret, fast;
  string dom;

  if(catch(load_object(INQUIRED))) {
    tell_object(me, "Inquired seems to be broken.  Have someone fix it.\n");
    return;
  }  

  if(!data)  data = "";

  if(!strlen(server))
    if(strsrch(data, ".") > -1) {
      dom = explode(data, ".")[<1];
      if(servers[dom])
        server = servers[dom];
      else
        server = servers["EUROPE"];
    }

  if(!strlen(server))
    server = servers["default"];      
  else { /* weird cases */
    if( (server == servers["nz"]) && (data[<3..<1] == ".nz") )
      data = "nz " + data[0..<4];
    else if( server == servers["jp"] )
      data += "/e";
    else if( (server == servers["dk"]) && (data[<3..<1] == ".dk") )
      data = data[0..<4];
  }

  ret = INQUIRED->inquire( server, 43, STREAM, data, (: whois_cb :) );

  if(ret <= 0)
    tell_object(me, "whois: "+ inquire_error(ret) + "\n");
  else {
    tell_object(me, "Please wait...\n");
    fds[ret] = me;
  }
}

void whois_cb(int fd, int success, mixed response, 
              string wordip, string numericip) {
  string header;

  if(!fds[fd])
    return;

  header = "\n[" + wordip + "]\n";

  if(success <= 0)
    tell_object(fds[fd], header + "whois: " + response + "\n"); 
  else
    tell_object(fds[fd], header + response + "\n");
                   
  map_delete(fds, fd);
}         

private void create() {
  seteuid("Network stuff");
  fds = ([ ]);
  servers = ([ "net" : INTERNIC, "edu" : INTERNIC, "com" : INTERNIC
              ,"org" : INTERNIC, "gov" : INTERNIC
              ,"us"  : "nii.isi.edu",   "mil" : "nic.ddn.mil"
              ,"mx"  : "whois.nic.mx", "au" : "whois.aunic.net"
              ,"se"  : "whois.sunet.se", "jp" : "whois.nic.ad.jp"
              ,"uk"  : "www.nic.uk", "nz" : "waikato.ac.nz"
              ,"dk"  : "whois.uni-c.dk"
              ,"EUROPE" : "whois.ripe.net"
              ,"default" : "ds.internic.net", "internic" : INTERNIC 
            ]);
}

mapping get_servers() {  return copy(servers);  }
