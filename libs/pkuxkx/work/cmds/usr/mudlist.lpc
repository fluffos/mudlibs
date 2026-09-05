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
   int loop, size, pplno, total,count;
   int show_all=0;

   if( !find_object(DNS_MASTER) )
     return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

   //   Obtain mapping containing mud data
   mud_list = (mapping)DNS_MASTER->query_muds();

   // so we recognise ourselves as a DNS mud
   mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

   if(!mud_list)
     return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

   //   Get list of all mud names within name server
   muds = keys( mud_list ) - ({ "DEFAULT" });

   //   Place mudlist into alphabetical format
   muds = sort_array(muds, 1);

   //    If mudname provided, search server's database for a match
   //   and display its cooresponding address
        show_all=1;

        if( arg ) arg = upper_case(arg);
        if(arg && arg != "" && arg != "ALL" && arg != "ES" ) {
                arg = htonn(arg);
                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
                        return 1;
                }
                if( wizardp(me) && !me->query("env/debug") )
                        printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
                else
                        printf("\n有关 %s 的资讯：\n"
                                "──────────────────\n"
                                "中文名称：  %s\n"
                                "语言：      %s\n"
                                "版本：      %s\n"
                                "MudOS：     %s\n"
                                "Mudlib：    %s\n"
                                "主机：      %s\n"
                                "端口：      %s\n"
                                "状态：      %s\n"
                                "在线玩家：  %s\n"
                                "当地时间：  %s\n"
                                "──────────────────\n\n",
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "不详":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "不详":(mud_list[arg]["ENCODING"]=="GB"?"简体汉字":"繁体汉字"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "不详":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "不详":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "不详":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "连线":"断开",
                                undefinedp(mud_list[arg]["USERS"])?
                                "不详":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "不详":mud_list[arg]["TIME"],
                                );
                return 1;
        }

   output = "\n\n"+
"  Ｍｕｄ名称             国际网路位址     埠号      当地时间     在线玩家\n"+
"─────────────────────────────────────\n";

   total = 0;
   //   Loop through mud list and store one by one
   for(loop = 0, size = sizeof(muds); loop<size; loop++) {
           string mudname, mudtime;
     
                mudname=undefinedp(mud_list[muds[loop]]["MUDNAME"])?
             upper_case(muds[loop]):
        mud_list[muds[loop]]["MUDNAME"] +
        "("+upper_case(muds[loop])+")"; 
                if(strwidth(mudname)>25) mudname=mudname[0..24];
     mudtime=mud_list[muds[loop]]["TIME"];
           
         output1 = sprintf("%-24s %-17s%-5s %15s %5s\n", 
        mudname,
        mud_list[muds[loop]]["HOSTADDRESS"],
        mud_list[muds[loop]]["PORT"],
//        undefinedp(mud_svc[muds[loop]]) ? "  " : "□",
             undefinedp(mud_list[muds[loop]]["TIME"])?
        "                ":
        mudtime[0..15],
        undefinedp(mud_list[muds[loop]]["USERS"]) ?
        "":""+mud_list[muds[loop]]["USERS"] );
         if (undefinedp(mud_list[muds[loop]]["USERS"]))
        pplno = 0;
         else
        sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);
         if ((show_all==1) || 
        (mud_list[muds[loop]]["MUDLIB"]==
         "A Journey to the West") )
        total += pplno;
         if(mud_list[muds[loop]]["MUDLIB"]==
           "A Journey to the West")
           output2=output1+output2; //add xyj mud at front.
                    else if(show_all==1)
           output2=output2+output1; //add non-xyj mud at end.
    count++;
        }
   output+=output2;
   output+=
"─────────────────────────────────────\n";
//   output+="共有 " + sprintf("%d %d", total,count) + " 位使用者连线中。\n";
output+=sprintf("共有%s座泥潭，计%s位玩家连线中。",chinese_number(count),chinese_number(total));
   //   Display dumped mudlist output through user's more pager
   this_player()->start_more( output );

   return 1;
}

int help()
{
        write(@HELP

指令格式：mudlist               列出连线中的西游记站点
          mudlist -a            列出连线中的所有Ｍｕｄ
          mudlist <Mud 名称>    列出指定Ｍｕｄ的信息

HELP
   );
   return 1;
}

