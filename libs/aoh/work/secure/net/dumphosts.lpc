#include <secure/udp.h>

dump()
{
    mapping hosts;
    string *muds;
    int i;

    seteuid(getuid());
    hosts = "/secure/net/inetd"->query("hosts");
    rm("/log/inetd_hosts");
    log_file("inetd_hosts","#\n# Intermud Hosts on "+ctime(time())+".\n#\n");
    for (i = sizeof(muds = m_indices(hosts)); i--;) {
    	log_file("inetd_hosts",hosts[muds[i]][HOST_NAME]+":"+hosts[muds[i]][HOST_IP]+":"+
		hosts[muds[i]][HOST_UDP_PORT]+":*:*\n");
    }
}

