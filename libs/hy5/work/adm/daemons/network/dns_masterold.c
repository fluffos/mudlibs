// Ported to ES2 mudlib by Annihilator@ES2

#include <mudlib.h>
#include <socket_err.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/socket.h>
#include <net/services.h>
#include <net/macros.h>

#define DEBUG
#define STD_SERVICE ({ "mail", "finger", "rwho_q", "tell", "gwizmsg" })
#define MY_LOG_FILE "dns_master"

inherit F_DBASE;

private int my_port, socket_id;
private mapping muds;
private mapping mud_svc;
private mapping this_host;
private mixed * bootsrv;
private int bootsrv_retry;
private int seq_ctr;
private mapping seq_entries;

#ifdef DEBUG
#  define debug(x) if(monitor) message("diagnostic", (x), monitor)
static object monitor = 0;
#else
#  define debug(x)
#endif

int startup_udp();
void send_udp(string host, int port, string msg);
void read_callback(int sock, string msg, string addr);
string start_message();

private string *muds_ip, *muds_port, *muds_name;

int check_mud(string ip, string port, string name);

void init_database();
void refresh_database();
void do_pings();
void set_mud_info(string name, mapping junk);
void zap_mud_info(string name, mapping junk);
void support_q_callback(mapping info);
private void query_services(string mud, string address, string port, string tcp);

int query_service_method(string mud, string service);
mapping query_mud_info(string name);
string get_host_name(string alias);
int get_mudresource(string mud, string resource);
int dns_mudp(string name);
mapping query_muds();
mapping query_svc();

varargs int idx_request(function f);
void sequence_callback(int idx, mixed param);
void sequence_clean_up();

#ifdef DEBUG
mixed * query_bootsrv();
void dump_sequencer();
void set_monitor(object ob);
object query_monitor();
#endif

private void restore_euid();
void aux_log(string file, string entry);
void aux_warning(string warning);
private void log(string entry);
void resolve_callback(string address, string my_ip, int key);

int startup_udp()
{
	int err_no;
	
	if (socket_id)
	return 0;
	
	socket_id = socket_create(DATAGRAM, "read_callback", "close_callback");
	
	if (socket_id < 0)
	{
		log("Failed to acquire socket.\n");
		return 0;
	}
	err_no = socket_bind(socket_id, my_port);
	while( err_no == EEADDRINUSE )
	{
		my_port++;
		err_no = socket_bind(socket_id, my_port);
	}
	if( err_no <= 0 )
	{
		log( sprintf("Failed to bind socket of UDP services, error = %d.\n", err_no));
		socket_close(socket_id);
		return 0;
	}
	return 1;
}
void send_udp(string host, int port, string msg)
{
	int sock;
	
	if (!ACCESS_CHECK(previous_object())&&
	file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
	return;
	
	if(sscanf(msg,"||TIME:%*s")==0)
	msg=replace_string(msg,"||NAME:",
	"||TIME:"+ctime(time())+"||NAME:",1);
	
	if(sscanf(msg,"||USERS:%*s")==0)
	msg=replace_string(msg,"||NAME:",
	"||USERS:"+sizeof(users())+"||NAME:",1);
	debug("DNS: Sending " + msg);
	sock = socket_create(DATAGRAM, "read_callback", "close_callback");
	
	if (sock <= 0)
	{
		log("Failed to open socket to " + host + " " + port + "\n");
		return;
	}
	socket_write(sock, msg, host + " " + port);
	socket_close(sock);
}
void read_callback(int sock, string msg, string addr)
{
	string func, rest="", *bits, name, arg;
	mapping args;
	int i;
	
	debug("DNS: Got " + msg);
	if( !sscanf(msg, "@@@%s||%s@@@%*s", func, rest))
	{
		if (!sscanf(msg, "@@@%s@@@%*s", func))
		return;
		rest = "";
	}
	sscanf(addr, "%s %*s", addr);
	if(strlen(rest)<2) 
	return;
	
	bits = explode(rest, "||");
	args = allocate_mapping(sizeof(bits)+3);
	
	i = sizeof(bits);
	while (i--)
	if (bits[i] && sscanf(bits[i], "%s:%s", name, arg) == 2)
	args[name] = arg;
	args["HOSTADDRESS"] = addr;
	
	if (args["NAME"])
	{
		args["NAME"]= htonn(args["NAME"]);
		args["ALIAS"] = htonn(args["NAME"]);
	}
	if(!check_mud(addr,"",""))
	{
		return;
	}
	if (mapp(muds[args["NAME"]]))
	muds[args["NAME"]][DNS_NO_CONTACT] = 0;
	debug("DNS: got message "+mapp(muds[args["NAME"]])+
	" "+args["NAME"]+"\n");
	
	if (mapp(muds[args["NAME"]]))
	{
		if(!undefinedp(args["TIME"]) && args["TIME"])
		muds[args["NAME"]]+=(["TIME":args["TIME"]]);
		
		if(!undefinedp(args["USERS"]) && args["USERS"])
		muds[args["NAME"]]+=(["USERS":args["USERS"]]);
	}
	if (file_size(AUX_PATH + func + ".c") > 0)
	(AUX_PATH + func)->incoming_request(args);
}
int query_udp_port()
{
	return my_port;
}
string query_mud_name()
{
	return INTERMUD_MUD_NAME;
}
void send_shutdown()
{
	string *mud_names;
	int i;
	
	if(!muds || sizeof(muds)==0)
	return;
	
	mud_names = keys(muds);
	i = sizeof(mud_names);
	while (i--)
	SHUTDOWN->send_shutdown(muds[mud_names[i]]["HOSTADDRESS"],
	muds[mud_names[i]]["PORTUDP"]);
	socket_close(socket_id);
	CHANNEL_D->do_channel(this_object(), "sys", "送出网路关闭讯息。\n");
}
string start_message()
{
	return sprintf( "||MUDNAME:%s||NAME:%s||VERSION:%s||MUDLIB:%s||HOST:%s||PORT:%d"
	"||PORTUDP:%d||TCP:%s",
	MUD_NAME, Mud_name(),
	MUDLIB_VERSION,
	MUDLIB_NAME,
	query_host_name(),
	mud_port(), my_port,
	TCP_SERVICE_LEVEL);
}
void init_database()
{
	int i;
	string message, *list;
	
	if( MUDLIST_A->query_db_flag() )
	{
		call_out("refresh_database", REFRESH_INTERVAL);
		call_out("sequence_clean_up", 4 * SERVICE_TIMEOUT);
		do_pings();
		return;
	}
	message = sprintf("@@@%s%s@@@\n", DNS_STARTUP, start_message());
	list = values( LISTNODES );
	i = sizeof( list );
	while( i-- )
	{
		sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
		send_udp(bootsrv[0], bootsrv[1], message);
		MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
	}
	call_out("init_database", 60);
	return;
}
void refresh_database()
{
	int i;
	string *list;
	
	while(find_call_out("refresh_database") != -1){ }
	
	call_out("refresh_database", REFRESH_INTERVAL);
	list = values( LISTNODES );
	i = sizeof( list );
	while( i-- )
	{
		sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
		MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
	}
}
void do_pings()
{
	int i;
	string *mud_names;
	
	if(find_call_out("do_pings") != -1)
	return;
	
	call_out("do_pings", PING_INTERVAL);
	mud_names = keys(muds);
	i = sizeof(mud_names);
	while (i--)
	{
		if(undefinedp(mud_svc[mud_names[i]]))
		continue;
		
		muds[mud_names[i]] [DNS_NO_CONTACT]++;
		PING_Q->send_ping_q(muds[mud_names[i]]["HOSTADDRESS"],
		muds[mud_names[i]]["PORTUDP"]);
		
		if (muds[mud_names[i]][DNS_NO_CONTACT] >= MAX_RETRYS)
		zap_mud_info(mud_names[i], 0);
	}
}
void set_mud_info(string name, mapping junk)
{
	string tcp;
	int new_mud;
	int svc;
	
	if( !(ACCESS_CHECK(previous_object()))&&
	file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
	return;
	
	name = htonn( name );
	while( name[strlen(name)-1] == '.' ) name = name[ 0..strlen(name)-2 ];
	
	if (name == mud_nname())
	return;
	
	if(undefinedp(junk["PORTUDP"])||
	undefinedp(junk["HOSTADDRESS"])||
	undefinedp(junk["NAME"]) ||
	!check_mud(junk["HOSTADDRESS"], junk["PORTUDP"],junk["NAME"]))
	{
		return;
	}
	junk["NAME"] = htonn(junk["NAME"]);
	junk["ALIAS"] = nntoh( junk["NAME"] );
	
	if( (undefinedp(muds[name]) ||
	undefinedp(muds[name]["TIME"]))&&
	!undefinedp(junk["TIME"]) )
	CHANNEL_D->do_channel(this_object(), "sys",
	junk["MUDNAME"]+"("+junk["NAME"]+")   "+
	junk["HOSTADDRESS"]+" "+junk["PORT"]+" 加入互连。");
	
	if (!undefinedp(mud_svc[name]))
	{
		muds[name] = junk;
		return;
	}
	if (!undefinedp(muds[name]))
	this_object()->aux_log("dns_mud_conv", "Udp contact from: "+name+"\n");
	
	if (!junk["TCP"]) junk["TCP"] = TCP_NONE;
	muds[name] = junk;
	tcp = junk["TCP"];
	switch (tcp)
	{
		case TCP_ALL:
		             mud_svc[name] = ([
		                               "mail"     :  SVC_TCP,
		                               "finger"   :  SVC_TCP | SVC_UDP | SVC_KNOWN,
		                               "tell"     :  SVC_TCP | SVC_UDP | SVC_KNOWN,
		                               "rwho_q"   :  SVC_UDP,
		                               "gwizmsg"  :  SVC_UDP,
		                               ]);
		             break;
		case TCP_ONLY:
		              mud_svc[name] = ([
		                                "mail"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
		                                "finger"   :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
		                                "tell"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
		                                "rwho_q"   :  SVC_NO_UDP,
		                                "gwizmsg"  :  SVC_NO_UDP,
		                                ]);
		             break;
		case TCP_SOME:
		              mud_svc[name] = ([
		                                "mail"     :  SVC_UNKNOWN,
		                                "finger"   :  SVC_UDP,
		                                "tell"     :  SVC_UDP,
		                                "rwho_q"   :  SVC_UDP,
		                                "gwizmsg"  :  SVC_UDP,
		                                ]);
		             break;
		default:
		              mud_svc[name] = ([
		                                "mail"     :  SVC_NO_TCP,
		                                "finger"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		                                "tell"     :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		                                "rwho_q"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		                                "gwizmsg"  :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		                                ]);
		             break;
	}
	if (tcp != TCP_ONLY)
	query_services(name, junk["HOSTADDRESS"], junk["PORTUDP"], tcp);
}
void zap_mud_info(string name, mapping junk)
{
	map_delete(muds, name);
	map_delete(mud_svc, name);
}
void support_q_callback(mapping info)
{
	string cmd;
	string mud;
	
	if (!ACCESS_CHECK(previous_object()))
	return;
	
	if (!info || !info["CMD"] || !info["NAME"] || !strlen(info["CMD"])
	||   !strlen(info["NAME"]))
	return;
	
	mud = htonn( info["NAME"] );
	
	if (undefinedp(muds[mud]))
	return;
	
	if (undefinedp(mud_svc[mud])) mud_svc[mud] = ([]);
	
	if(!info["SUPPORTED"] && !info["NOTSUPPORTED"])
	return;
	
	if (info["CMD"] == "tcp")
	{
		cmd = info["PARAM"];
		
		if (mud_svc[mud][cmd] & (SVC_UDP | SVC_NO_UDP))
		mud_svc[mud][cmd] |= SVC_KNOWN;
		
		if (info["SUPPORTED"])
		{
			mud_svc[mud][cmd] |= SVC_TCP;
			mud_svc[mud][cmd] &= ~SVC_NO_TCP;
		}
		else
		{
			mud_svc[mud][cmd] |= SVC_NO_TCP;
			mud_svc[mud][cmd] &= ~SVC_TCP;
			
			if(!(mud_svc[mud][cmd] & SVC_KNOWN))
			SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
			muds[mud]["PORTUDP"], info["PARAM"]);
		}
	}
	else
	{
		cmd = info["CMD"];
		
		if (mud_svc[mud][cmd] & (SVC_TCP | SVC_NO_TCP))
		mud_svc[mud][cmd] |= SVC_KNOWN;
		
		if (info["SUPPORTED"])
		{
			mud_svc[mud][cmd] |= SVC_UDP;
			mud_svc[mud][cmd] &= ~SVC_NO_UDP;
		}
		else
		{
			mud_svc[mud][cmd] |= SVC_NO_UDP;
			mud_svc[mud][cmd] &= ~SVC_UDP;
			
			if(!(mud_svc[mud][cmd] & SVC_KNOWN))
			SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
			muds[mud]["PORTUDP"], "tcp", info["CMD"]);
		}
	}
	return;
}

private void

query_services(string mud, string address, string port, string tcp)
{
#ifdef PREF_MAIL
        if (!(mud_svc[mud]["mail"] & SVC_KNOWN))
        {
#if PREF_MAIL & SVC_TCP
        
        if (tcp == TCP_SOME && !(mud_svc[mud]["mail"] & (SVC_TCP | SVC_NO_TCP)))
        SUPPORT_Q->send_support_q(address, port, "tcp", "mail");
#elif PREF_MAIL & SVC_UDP
        
        if (!(mud_svc[mud]["mail"] & (SVC_UDP | SVC_NO_UDP)))
        SUPPORT_Q->send_support_q(address, port, "mail");
#endif
}
#endif
#ifdef PREF_FINGER
  if (!(mud_svc[mud]["finger"] & SVC_KNOWN))
    {
#if PREF_FINGER & SVC_TCP
      if (tcp == TCP_SOME && !(mud_svc[mud]["finger"] & (SVC_TCP | SVC_NO_TCP)))
   SUPPORT_Q->send_support_q(address, port, "tcp", "finger");
#endif
    }
#endif

#ifdef PREF_TELL
  if (!(mud_svc[mud]["tell"] & SVC_KNOWN))
    {
#if PREF_TELL & SVC_TCP
      if (tcp == TCP_SOME && !(mud_svc[mud]["tell"] & (SVC_TCP | SVC_NO_TCP)))
   SUPPORT_Q->send_support_q(address, port, "tcp", "tell");
#endif
    }
#endif

return;
}
int query_service_method(string mud, string service)
{
	mud = htonn(mud);
	
	if (undefinedp(muds[mud]))
	return SVC_UNKNOWN;
	
	if (undefinedp(mud_svc[mud]))
	return SVC_TCP | SVC_NO_UDP | SVC_KNOWN;
	
	if (undefinedp(mud_svc[mud][service]))
	{
		if(member_array(service, STD_SERVICE) != -1)
		query_services(mud, muds[mud]["HOSTADDRESS"], muds[mud]["PORTUDP"],
		muds[mud]["TCP"]);
		return SVC_UNKNOWN;
	}
	return mud_svc[mud][service];
}
mapping query_svc_entry(string mud)
{
	return mud_svc[mud];
}
string get_host_name(string name)
{
	name = htonn(name);
	
	if (name == mud_nname())
	return this_host["HOSTADDRESS"];
	
	if (undefinedp(muds[name]))
	return 0;
	
	return muds[name]["HOSTADDRESS"];
}
mapping query_mud_info(string name)
{
	mapping m;
	string str;
	
	name = htonn(name);
	
	if(name == mud_nname())
	return this_host + ([ "TIME" : ctime(time()) ]) +
	(["USERS" : ""+sizeof(users()) ]);
	return muds[name];
}
int dns_mudp(string name)
{
	name = htonn( name );
	return undefinedp(mud_svc[name]) ? (name == mud_nname() ? 1 : 0) : 1;
}
mapping query_muds()
{
	return muds + ([ mud_nname():this_host+
	([ "TIME":ctime(time()) ])+
	(["USERS" :""+ sizeof(users()) ]) ]);
}
mapping query_svc()
{
	return mud_svc;
}
varargs int idx_request(function f)
{
	if (file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
	return 0;
	
	seq_ctr++;
	seq_entries[seq_ctr] = ({ geteuid(previous_object()), f, time() });
	return seq_ctr;
}
void idx_callback(int idx, mixed param)
{
	mixed *entry;
	
	if (!ACCESS_CHECK(previous_object()))
	return;
	
	if (undefinedp(seq_entries[idx]))
	return;
	
	entry = seq_entries[idx];
	map_delete(seq_entries, idx);
	
	seteuid(entry[0]);
	(*entry[1]) (param);
	
	restore_euid();
}
void sequence_clean_up()
{
	int i, now;
	int *indexes;
	
	if(find_call_out("sequence_clean_up") != -1)
	return;
	
	indexes = keys(seq_entries);
	now = time();
	i = sizeof(indexes);
	while (i--)
	
	if( now - seq_entries[indexes[i]][2] > SERVICE_TIMEOUT )
	{
		seteuid(seq_entries[indexes[i]][0]);
		(*seq_entries[indexes[i]][1]) (0);
		restore_euid();
		map_delete( seq_entries, indexes[i] );
	}
	call_out("sequence_clean_up", SEQ_CLEAN_INTERVAL);
}
#ifdef DEBUG
mixed *query_bootsrv()
{
	return bootsrv;
}
void dump_sequencer()
{
	printf("counter: %d\n\n%O\n", seq_ctr, seq_entries);
}
void dump_svc()
{
	printf("%O\n", mud_svc);
}
void dump_mud_keys()
{
	printf("%O\n", keys(muds));
}
void dump_svc_keys()
{
	printf("%O\n", keys(mud_svc));
}
void set_monitor(object ob)
{
	string euid;
	
	monitor = ob;
}
object query_monitor()
{
	return monitor;
}
#endif

private void restore_euid()
{
	seteuid(ROOT_UID);
}
void aux_log(string file, string entry)
{
	if(!ACCESS_CHECK(previous_object()))
	return;
	
	restore_euid();
	log_file(file, sprintf("%s: %s\n", ctime(time()), entry));
}
void aux_warning(string warning)
{
	if(!ACCESS_CHECK(previous_object()))
	return;
	
	log("dns_warning: "+warning);
}
private void log(string entry)
{
	string temp;
	log_file(MY_LOG_FILE, sprintf("%s: %s\n", ctime(time()), entry));
}
void resolve_callback(string address, string my_ip, int key)
{
	this_host["HOSTADDRESS"] = my_ip;
}
void create()
{
	mapping static_db;
	int i, j;
	string *list;
	string *strs;
	string ip, port, *listkey;
	restore_euid();
	
	set("channel_id", "网路精灵(Internet)");
	
	list=values(LISTNODES);
	listkey=keys(LISTNODES);
	
	j=sizeof(list);
	muds_ip=({});
	muds_port=({});
	muds_name=({});
	
	if(j>0)
	for(i=0;i<j;i++)
	{
		if(sscanf(list[i], "%s %s", ip, port)==2)
		{
			muds_ip+=({ip});
			muds_port+=({port});
			muds_name+=({htonn(listkey[i])});
		}
	}
	my_port = SRVC_PORT_UDP(mud_port());
	muds = allocate_mapping(MUDS_ALLOC);
	mud_svc = allocate_mapping(MUDS_ALLOC);
	seq_ctr = 0;
	seq_entries = ([]);
	bootsrv = MUDLIST_DNS;
	bootsrv_retry = 0;
	MUDLIST_A->clear_db_flag();
	
	this_host = ([
	"MUDNAME"     : MUD_NAME,
	"NAME"        : Mud_name(),
	"ALIAS"       : Mud_name(),
	"MUDLIB"      : MUDLIB_NAME,
	"VERSION"     : MUDLIB_VERSION,
	"HOST"        : query_host_name(),
	"HOSTADDRESS" : 0, 
	"PORT"        : "" + mud_port(),
	"PORTUDP"     : "" + my_port,
	"TIME"        : ctime(time()),
	"TCP"         : TCP_SERVICE_LEVEL,
	"USERS"      : ""+sizeof(users()),
	]);
	resolve(query_host_name(), "resolve_callback");
	
	if (startup_udp()) init_database();
}
void remove()
{
	send_shutdown();
}
int check_mud(string ip, string port, string name)
{
	int i=sizeof(muds_ip);
	name=htonn(name);
	
	while(i--)
	if(ip==muds_ip[i] &&  (name=="" || name==muds_name[i]))
	return 1;
	return 0;
}