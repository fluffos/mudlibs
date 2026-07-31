// cracked by vikee 2/09/2002   vikee@263.net
// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;


int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output, output1, output2="";
	int loop, size, pplno, total, totmud;
	int show_all=0;

	if( !find_object(DNS_MASTER) )
		return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
           if(arg=="-a") 
	     show_all=1;
	   else if(arg=="-all") 
	     show_all=1;
	   else if(arg=="-es") 
	     show_all=2;
           else {
	        mapping mud;
		string *key;
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
			return 1;
		}
//		printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
		printf("有关 %s 的资讯：\n", arg);
		write("───────────────────\n");
		mud=copy(mud_list[arg]);
		if(!undefinedp(mud["MUDNAME"])){
		    write("中文名称："+mud["MUDNAME"]+"\n");
		    map_delete(mud,"MUDNAME");
		}
		if(!undefinedp(mud["NAME"]))
		{
		    write("名称　　："+mud["NAME"]+"\n");
		    map_delete(mud,"NAME");
		}
		if(!undefinedp(mud["MUDLIB"]))
		{
		    write("MUDLIB　："+mud["MUDLIB"]+"\n");
		    map_delete(mud,"MUDLIB");
		}
		if(!undefinedp(mud["VERSION"]))
		{
		    write("版本　　："+mud["VERSION"]+"\n");
		    map_delete(mud,"VERSION");
		}
		if(!undefinedp(mud["ENCODING"])) {
		    if(mud["ENCODING"]=="GB")
			write("编码方式：国标（ＧＢ）\n");
		    else if(mud["ENCODING"]=="BIG5")
			write("编码方式：大五（ＢＩＧ５）\n");
		    map_delete(mud,"ENCODING");
		}
		if(!undefinedp(mud["HOST"]))
		{
		    write("服务器　："+mud["HOST"]+"\n");
		    map_delete(mud,"HOST");
		}
		if(!undefinedp(mud["HOSTADDRESS"]))
		{
		    write("网路位址："+mud["HOSTADDRESS"]+"\n");
		    map_delete(mud,"HOSTADDRESS");
		}
		if(!undefinedp(mud["PORT"]))
		{
		    write("端口　　："+mud["PORT"]+"\n");
		    map_delete(mud,"PORT");
		}
		if(!undefinedp(mud["USERS"]))
		{
		    write("在线玩家："+mud["USERS"]+"\n");
		    map_delete(mud,"USERS");
		}
		if(!undefinedp(mud["TIME"]))
		{
		    write("当地时间："+mud["TIME"]+"\n");
		    map_delete(mud,"TIME");
		}
		if(!undefinedp(mud["DRIVER"]))
		{
		    write("DRIVER　："+mud["DRIVER"]+"\n");
		    map_delete(mud,"DRIVER");
		}
		if(wizardp(this_player())) {
		write("───────────────────\n");
		key=keys(mud);
		size=sizeof(key);
		while(size--)
		    write(key[size]+" ："+mud[key[size]]+"\n");
		}

		write("───────────────────\n\n");
		
		return 1;
           }
	}

	output = "\n\n"+
"   Ｍｕｄ名称              国际网路位址   埠号      当地时间     在线玩家\n"+
"─────────────────────────────────────\n";

	total = 0;
	totmud=0;
	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++) {
	        string mudname, mudtime;
		
                mudname=undefinedp(mud_list[muds[loop]]["MUDNAME"])?
		        muds[loop]:
			mud_list[muds[loop]]["MUDNAME"] +
			"("+upper_case(muds[loop])+")"; 
                if(strlen(mudname)>25) mudname=mudname[0..24];
		mudtime=mud_list[muds[loop]]["TIME"];
           
		    output1 = sprintf("%-25s %-16s%-5s %15s %5s\n", 
			mudname,
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
//			undefinedp(mud_svc[muds[loop]]) ? "  " : "□",
		        undefinedp(mud_list[muds[loop]]["TIME"])?
			"                ":
			mudtime[0..15],
			undefinedp(mud_list[muds[loop]]["USERS"]) ?
			"":""+mud_list[muds[loop]]["USERS"] );
		    if (undefinedp(mud_list[muds[loop]]["USERS"]))
			pplno = 0;
		    else
			sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);

		    /*
		    if (show_all==1 || 
			(mud_list[muds[loop]]["MUDLIB"]==
			 "A Journey to the West") )
			total += pplno;
			*/

		    if(mud_list[muds[loop]]["MUDLIB"]==
		      "A Journey to the West") {
			total+=pplno;
			totmud++;
		        output2=output1+output2; //add xyj mud at front.
		    }
                    else if(show_all==1) {
			total+=pplno;
			totmud++;
		        output2=output2+output1; //add non-xyj mud at end.
		    }
		    else if(show_all==2 && mud_list[muds[loop]]["MUDLIB"]
			    =="Eastern Stories"){
			total+=pplno;
			totmud++;
			output2=output2+output1; //add ES2 muds.
		    }
        }
	output+=output2;
	output+=
"─────────────────────────────────────\n";
	output+="共有" +
	    chinese_number(totmud) + "座泥潭，计"
	    + chinese_number(total) + "位玩家连线中。\n";

	//	Display dumped mudlist output through user's more pager
	this_player()->start_more( output );

	return 1;
}

int help()
{
        write(@HELP

指令格式：mudlist               列出连线中的西游记站点
          mudlist -es           列出连线中的所有ＥＳ２站点
          mudlist -all          列出连线中的所有Ｍｕｄ站点
          mudlist <Mud 名称>    列出指定Ｍｕｄ的信息

HELP
	);
	return 1;
}

