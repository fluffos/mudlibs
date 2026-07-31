// logind.c

#define VISITORS "/log/mud/MUDVISITOR"
#define GIFTCARD "/log/mud/GIFTCARD"
#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
static string loginnip;
static int loginntime;

int check_legal_password(object ob,string arg);
int wiz_lock_level = WIZ_LOCK_LEVEL;
//tentop
int mad_lock = 0;
//10 
string Rname;
string *banned_name = ({
	"Äã", "Äã", "ÎÒ", "Ëû", "Ëı", "Ëü", "Ëü", "°Ö", "¡¡",
	"ÏèÉÙÒ¯", "·½ÖÛ×Ó", "²İÓã", "Ê±¿Õ", "¶¡",
        "½­ÔóÃñ", "µËĞ¡Æ½", "ÀîÅô", "ÖìéÅ»ù",
        "×Ô¼º", "Ä³ÈË", "Ê¬Ìå", "ÎÒÃÇ","ÄãÃÇ", "ËûÃÇ", "´ó¼Ò",
        "ËûÂèµÄ", "È¥ÄãµÄ", "Ã«Ôó¶«", "Î×Ê¦", "ËûÄÌÄÌµÄ",
	"ÏÉ×Ó", "ÌìÂíĞĞ¿Õ", "µÏÑô", "·ç¶ù","ĞÇĞÇ","Ğ¡ÈËÎï","²Ü±ó","ºú½õÌÎ","ÎÂ¼Ò±£","ÎÂ¼Ò±¦","±¡ÎõÀ´","ÁõÑÓ¶«","Ï°½üÆ½","Îâ°î¹ú","¼ÖÇìÁÖ","Àî³¤´º","Àî¿ËÇ¿","ºØ¹úÇ¿","ÖÜÓÀ¿µ","ÀîÔ´³±","ÍôÑó",
"ÓáÕñÉù","Àî¿ËÇ¿","ÕÅµÂ½­","ÍõáªÉ½","ÀîÔ´³±","ÕÅ¸ßÀö","ÁõÔÆÉ½"
});
string random_name(int gender) //gender ==2 ÈÕ±¾ÈË gender==1 Å®ÈË gender==0 ÄĞÈË
{
	string sname,sid;
	int i;
	string *first_name = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî",
"Öì","ÇØ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ","¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ",
"Ğ»","×Ş","Ë®","ÕÂ","ËÕ","ÅË","¸ğ","·¶","Åí","Â³","Î¤","Âí","Ãç","·½","ÈÎ","Ô¬",
"Áø","µË","±«","Ê·","ÌÆ","·Ñ","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ","Òó","ÂŞ","ºÂ","Úù",
"³£","ÀÖ","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","»Æ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ",
"Íô","Æî","Ã«","µÒ","Ã×","±´","²Ø","³É","´÷","ËÎ","Ã©","ÅÓ","¼Í","Êæ","Ïî","¶­",
"Áº","·®","ºú","Áè","»ô","Óİ","¿Â","¹Ü","Â¬","ÔÀ",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","¶«·½","ºÕÁ¬","»Ê¸¦","Î¾³Ù","×ÚÕş","Ì«Êå","¹«Ëï",
"ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä½Èİ","Ë¾Í½","Ê¦¿Õ","Î×Âí","ÍØÖº","¼Ğ¹È",
"³ş½ú","ºôÑÓ","Î¢Éú","ÁºÇğ","×óÇğ","¶«ÃÅ","Î÷ÃÅ","ÄÏ¹¬",
});
	string *second_name1 = ({
"ÖÒ","Ğ¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ğ¡","Ïş",
"¸ß","¿É","°¢","½ğ","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});
	string *second_name2 = ({
"°Ô","°×","°à","±ó","±ö","²ı","³¬","³Ï","´¨","¶¦","¶¨","¶·",
"·¨","·É","·ç","·æ","¸Ö","î¸","¹á","¹â","º£","»¢","»ª",
"ºÆ","ºê","¼Ã","¼á","½¡","½£","½­","½ø","½Ü","¿¡","¿µ",
"Á¼","÷ë","Ãñ","Ã÷","Ãù","Äş","Åà","Æô","Ç¿","ÈÙ","É½",
"Ì©","ÌÎ","Í¦","Î°","Îõ","Ïé","ĞÛ","Ğñ",
"Òã","è¤","Óğ","Óî","ÔÀ","ÖÛ",
});
	string *girl_name = ({ //Å®ĞÔ×¨ÓÃ
"°®","´º","µ¤","·¼","·Ò","·ï","¹Ã","ºì","ºç","½¿","¾ê",
"¾Õ","À¼","á°","Àö","Àò","Á«","Áá","ÁÕ","ÄÈ","ÇÙ","ÇÛ",
"Ù»","Æ¼","æÃ","Ï¼","Ïã","ÑŞ","Ñà","Ó¢","çø","Óñ","Õä",
"Öé",
});
	string *japan_name1 =({
"É½±¾","¹êÌï","×ËÈı","´óµº","ËÉÏÂ","ºáÌï","¶«Ö¥","ºò±¾","´¨Ò°","É½¿Ú",
"ÁåÄ¾","¸Ú²Ö","Ğ¡µº","¾®ÉÏ","°²ÄÎ","Ç³Ìï","×ôÌÙ","¹ãÄ©","´óÖñ","´ó´å",
"²®×ô","¸»¸Ô","¶«Ïç","²ñÌï"
});
	string *japan_name2 =({
"Ì«ÀÉ","´ÎÀÉ","ÈıÀÉ","ËÄÀÉ","ÎåÀÉ","Ê®Ò»ÀÉ","Ê®ËÄÀÉ","¶şÊ®Áù","¿¡Ê÷",
"Äş´Î","Ó¢»ú","Ò±×Ö","¿¡ĞÛ","ÄÁ·ò","¹â·ò","¾´Ò»","Ó¢ÊÀ","ÊşÊ¯","Óå¼ª",
"Ò»Ò¶","×Ó¹æ","µ¾Ôì","ÒÁ³å","ËÉÔ°","ÉîË®","´ó¹Û","·á¹ú","Ğ¢ºÍ","Ã¯",
"´¨","ÎÀ","µºÊÙ","¹âÔÆ","°²ÖÎ","É½ÀÖ","ÃÎ¶ş","³¤Ğã","³ÉÕş"
});
gender=random(3);
	switch(gender){
	case 0:
	i = random(sizeof(first_name));
	sname = first_name[i]+second_name1[random(sizeof(second_name1))]+second_name2[random(sizeof(second_name2))];
		break;
	case 1:
	i = random(sizeof(first_name));
	sname=first_name[i]+second_name1[random(sizeof(second_name1))]+girl_name[random(sizeof(girl_name))];
		break;
      	case 2:
	i = random(sizeof(japan_name1));
	sname = japan_name1[i]+japan_name2[random(sizeof(japan_name2))];
	break;
	}
	return sname;
}
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int howmany_user();
int howmany_visitor();
int howmany_card();
void set_visitor(int num);
void set_card(int num);
// tentop
int howmuch_money(object ob);

void random_gift(mapping my, int select)
{
	int i = 10, j,kar,per;
	int tmpstr, tmpint, tmpcon, tmpdex;

	tmpstr = tmpint = tmpcon = tmpdex = 10;

	switch (select) {
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"];
	}
	i = 50 - i;
	while (i--) {
		j = random(4);
		if (j == select - 1) {
			i++;
			continue;
		}
		switch (j) {
			case 0: tmpstr++; break;
			case 1: tmpint++; break;
			case 2: tmpcon++; break;
			case 3: tmpdex++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	// next 3 are randomly selected
	kar=random(21);
	if (kar>19) kar=19;
	if (kar<1 ) kar=1;
	per=20-kar;
	my["kar"] = 10 + kar;
	my["per"] = 10 + per;
}
void create() 
{
	seteuid(getuid());
	set("channel_id", "Á¬Ïß¾«Áé");
}

void logon(object ob)
{
	object *usr;
	int i, login_cnt;
        string welcome_msg;

// ·ÀÖ¹ÓĞ¶ñÒâµÄÍæ¼ÒÓÃ KMUD µÈ¹¤¾ßµ·ÂÒ
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	login_cnt = 0;
	while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
	if (login_cnt > 3) {
		destruct(ob);
		return;
	}
//welcome_msg = "/adm/etc/welcome";
//write(read_file(welcome_msg));

// Add by Yu Jue 1997.8.6
        write("\nÎÒÃÇ½¨ÒéÊ¹ÓÃ 800 * 600 µÄ·Ö±æÂÊ½øÈë"+MUD_NAME+"¡£\n");
    write(HIW"Best view with 800 * 600    "NOR);
    write("\n¿ÉÒÔÊ¹ÓÃ5555,2000,2002,2003,2004¶à¸ö¶Ë¿Ú½øÈë"+MUD_NAME+"¡£");
    write(HIW"\nCan use port 5555,2000,2002,2003,2004 telnet this Game      ¡£"NOR);
    write("\nPlease select ¹ú±êÂë ¡¼GB¡½ or ¤j¤­½X ¡¼Big5¡½ (GB/Big5):\n");
//    write("\nAre you using BIG5 font [Y|N]?");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}

	input_to("gb_big5", ob);
}

void gb_big5(string arg, object ob)
{
	int encode;
	object *usr,*usert;
	int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
        int iplimit,max_online,avg_online,ipl;
        int user_num;
//add by login
	mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output,online_num,avg_num;
        int loop, size, total, count=0, p_count=0;
//
//	if( arg[0]=='y' || arg[0]=='Y' ) ob->set_temp("big5", 1);
//	if( arg[0]=='n' || arg[0]=='N' ) ob->set_temp("big5", 0);
	if(!arg || arg=="") {
	    write("\nPlease select ¹ú±êÂë ¡¼Gb¡½ or ¤j¤­½X ¡¼Big5¡½ (Gb/Big5):");
	    input_to( "gb_big5", ob );
	    return;
	}
	else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    {
	    encode=1;
	ob->set_temp("big5", 1);
}
	else {
	    
	    write("\nPlease select ¹ú±êÂë ¡¼Gb¡½ or ¤j¤­½X ¡¼Big5¡½ (Gb/Big5):");
	    input_to( "gb_big5", ob );
	    return;
	}

	if(encode==0)
		write("\n»¶Ó­Äú½øÈë"HIG"¡¼º£ÑóV-ĞÇÔÂ´«Ææ¡½"NOR"µÄ´«ÆæÊÀ½ç¡£\n\n");
	else
{
		write("\nÅwªï±z¶i¤J"HIG"¡¼MUD¡½"NOR"ªº¶Ç©_¥@¬É¡£\n\n");
ob->set_temp("big5", 1);
}
	ob->set_encoding(encode);
if (ob->query_temp("xmud"))
    {
    write(read_file("/adm/etc/xmudwelcome"));
}
    else
   {
    write(read_file("/adm/etc/welcome"));  
}
        //write(read_file("/adm/etc/welcome"));

	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write("ÄãµÄµØÖ·ÔÚ±¾ MUD ²»ÊÜ»¶Ó­¡£\n");
		destruct(ob);
		return;
	}

//add by login
//      if( !find_object(DNS_MASTER) )
//		write("ÍøÂ·¾«Áé²¢Ã»ÓĞ±»ÔØÈë¡£\n");
        mud_list = (mapping)DNS_MASTER->query_muds();

        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
		write( MUD_NAME + "Ä¿Ç°²¢Ã»ÓĞ¸úÍøÂ·ÉÏÆäËû Mud È¡µÃÁªÏµ¡£\n");

        muds = keys( mud_list ) - ({ "DEFAULT" });

        muds = sort_array(muds, 1);
        
	output = 
"Mud                  ÖĞÎÄÃû³Æ                ¹ú¼ÊÍøÂ·Î»Ö·     ²ººÅ  ÈËÊı\n"+
"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";

	for(loop = 0, size = sizeof(muds); loop<size; loop++)
	{
		if( mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
			continue;
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
                                continue;
                }
                count = loop;
                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output += BBLU+HIW;
                else
                        output += WHT;

                if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
                        output +=  sprintf("%-43s  %-15s  %4s", 
                                upper_case(muds[loop]),
                                mud_list[muds[loop]]["hy.21sun.net"],
                                mud_list[muds[loop]]["PORT"]);
                }
                else {
                        output +=  sprintf("%-20s %-23s %-15s  %4s", 
                                upper_case(muds[loop]),
                                undefinedp(mud_list[muds[loop]]["MUDNAME"])?
                                "":mud_list[muds[loop]]["MUDNAME"],
                                //mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["hy.21sun.net"],
                                mud_list[muds[loop]]["PORT"]);
                }
                if(!undefinedp(mud_list[muds[loop]]["USERS"]))
                {
				output+=sprintf("  %-4s", mud_list[muds[loop]]["USERS"] );
				if(sscanf(mud_list[muds[loop]]["USERS"], "%d", count)==1)
					p_count+=count;
		}
                else
                                output+=sprintf("  ----", mud_list[muds[loop]]["USERS"] );

                output +=NOR"\n";
                total ++;
        }
	output += "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
	output += sprintf("¹²ÓĞ %d ¸öÕ¾µãÓë±¾Õ¾Á¬ÏßÖĞ¡£¹²ÓĞ %d ¸öÍæ¼ÒÔÚÏß¡£\n",total==0?0:total-1,p_count);
//add end			

write("\n");
write(output);
//write(HIC"ÈÎºÎÒâ¼û»ò½¨Òé£¬Çëµ½ĞÇĞÇµÄÔ¼»áÂÛÌ³·¢±í  \n"NOR);
//write("\n");
//write(output);

	UPTIME_CMD->main();

        usert=filter_array(children(LOGIN_OB), (: interactive :));
//	usr = filter_array(children(LOGIN_OB), (: interactive :));
	usr = users();
	wiz_cnt = 0;
	inv_wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
        ipl = 0;
        iplimit = 0;
	for(i=0; i<sizeof(usr); i++) {
                if( query_ip_name(usr[i])==query_ip_name(ob)) iplimit ++;
		if( !environment(usr[i]) ) login_cnt++;
	        else if( wizardp(usr[i]) && usr[i]->query("env/invisibility") ) inv_wiz_cnt++;
	        else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") ) wiz_cnt++;
		else ppl_cnt++;
	}

//Ä¿Ç°ÔİÊ±ÏŞÖÆÃ¿IP×î¶àÁ¬½Ó18 ID
        if (iplimit>22 && query_ip_name(ob) != "NATSERV")
        {
		write("¶Ô²»Æğ£¬" + MUD_NAME + "ÄãµÄIPÁ¬½Ó³¬¹ı22ÓÃ»§£¬Ğ»Ğ»Äã¶Ôº£ÑóV-ĞÇÔÂ´«ÆæµÄÖ§³Ö£¬ÎÒÃÇ»á¾¡¿ì´¦Àí¡£\n");
		destruct(ob);
		return;
        }

//Ä¿Ç°ÔİÊ±ÏŞÖÆÃ¿IP×î¶àÁ¬½Ó38 ID
        if (iplimit>22 && query_ip_name(ob) == "NATSERV")
        {
		write("¶Ô²»Æğ£¬" + MUD_NAME + "ÄãµÄIPÁ¬½Ó³¬¹ı22ÓÃ»§£¬Ğ»Ğ»Äã¶Ôº£ÑóV-ĞÇÔÂ´«ÆæµÄÖ§³Ö£¬ÎÒÃÇ»á¾¡¿ì´¦Àí¡£\n");
		destruct(ob);
		return;
        }

// ¼ÆÊı Start

/*        user_num=howmany_user();
        if(user_num!=0)
        {
            write(HIG"º£ÑóV-ĞÇÔÂ´«Ææ×Ü¹²ÓĞ£º"+HIW+chinese_number(user_num)+HIW"¸öÓÃ»§¡£\n"+NOR);
        }

        user_num=howmany_visitor();
*/
	max_online = atoi(read_file(__DIR__"maxonline",1));

	avg_online = atoi(read_file(__DIR__"avguser",1));

	if(ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt > max_online)

	   {

	   	online_num = sprintf("%d",ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt);

	   	write_file(__DIR__"maxonline",online_num,1);

	   }

	   	avg_num = sprintf("%d",max_online - 40);

	   	write_file(__DIR__"avguser",avg_num,1);


        set_visitor(user_num+1);
        if (iplimit>1)
        write(HIG"ÄúµÄµØÖ·ÒÑÓĞ£º"HIW+chinese_number(iplimit-1)+NOR+HIW"¸öÓÃ»§¡£");
// ¼ÆÊı End
//	write(HIG"×Ü¹²·ÃÎÊÈË´Î£º" HIW + chinese_number(user_num));
	write(HIG"Ä¿Ç°ÈËÊıÏŞÖÆ£º" HIW + chinese_number(MAX_USERS)+HIG +" Ê¹ÓÃMUDOS°æ±¾£º " HIW + "MUDOS pre11 \n"+NOR);
        write(HIG"ÓÎÏ·Ö÷Ò³ÍøÖ·£º"HIW"Http://www.txdx.net        "HIG"ĞÇÔÂ´«ÆæÖ÷Ò³£º"HIW"Http://www.txdx.net  \n"NOR);
//	write("\n");
//	UPTIME_CMD->main(1);
	printf(HIG"×î¸ßÔÚÏßÊıÄ¿£º"HIW"%s"HIG"ÈË                "HIG"Æ½¾ùÔÚÏßÊıÄ¿£º"HIW"%s"HIG"ÈË¹¤\n"NOR,chinese_number(max_online),chinese_number(avg_online));
	printf(HIG"ÓÎÏ·Ä¿Ç°¹²ÓĞ£º"HIW" %s "HIG"Î»ÊÀÍâ¸ßÈË¡¢"HIW"%s "HIG"Î»½­ºş¶ùÅ®ÔÚÏßÉÏ£¬ÒÔ¼°"HIW" %s"HIG" Î»³¢ÊÔÁ¬ÏßÖĞ¡£\n"NOR,
		chinese_number(wiz_cnt), 
                chinese_number(ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt), 
                chinese_number(login_cnt+inv_wiz_cnt) );

	write("ÄúµÄÓ¢ÎÄÃû×Ö(ĞÂÍæ¼Ò¿ÉÒÔÑ¡ÔñÒ»Ï²»¶µÄÃû×Ö)£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
	input_to( "get_id", ob );
}

void set_visitor(int num)
{
	if(num>0)
		write_file(VISITORS, sprintf("VISITORS %d", num), 1);
	else
		write("Î×Ê¦Çë×¢Òâ·ÃÎÊÕßÊıÄ¿²»¶Ô!\n");
	return;
}
void set_card(int num)
{
	if(num>0)
		write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
	else
		write("Î×Ê¦Çë×¢Òâ·ÃÎÊÕßÊıÄ¿²»¶Ô!\n");
	return;
}

int howmany_user()
{
	int i,j,ppl_cnt;
	string *dir , *ppls, name;
	mixed info;
	seteuid(getuid());
	ppl_cnt=0;
	dir=get_dir(DATA_DIR+"login/");
	for(i=0; i<sizeof(dir);i++)
	{
		reset_eval_cost();
		ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
		ppl_cnt+=sizeof(ppls);
	}
	return ppl_cnt;
}

int howmany_visitor()
{
	int num=0;
	string content, format;
	content=read_file(VISITORS);
	sscanf(content, "%s %d", format, num);
	if(format!="VISITORS")
		write(format+"\nÎ×Ê¦Çë×¢Òâ·ÃÎÊÕßÊıÄ¿²»¶Ô!\n");
	return num;
}
int howmany_card()
{
	int num=0;
	string content, format;
	content=read_file(GIFTCARD);
	sscanf(content, "%s %d", format, num);
	if(format!="GIFTCARD")
		write(format+"\nÎ×Ê¦Çë×¢Òâ·ÃÎÊÕßÊıÄ¿²»¶Ô!\n");
	return num;
}

void get_id(string arg, object ob)
{
	object *usr;
	int i, login_cnt;
	object ppl; 

	arg = lower_case(arg);

	if( !check_legal_id(arg)) {
		write("ÄúµÄÓ¢ÎÄÃû×Ö(ĞÂÍæ¼Ò¿ÉÒÔÑ¡ÔñÒ»Ï²»¶µÄÃû×Ö)£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
//	&& sizeof(users()) >= MAX_USERS ) {
	&& sizeof(users()) > 400 ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("¶Ô²»Æğ£¬" + MUD_NAME + "µÄÊ¹ÓÃÕßÒÑ¾­Ì«¶àÁË£¬Çë´ı»áÔÙÀ´¡£\n");
			destruct(ob);
			return;
		}
	}



/*if( (string)SECURITY_D->get_status(arg)=="(player)") {
		ppl = find_body(arg);
		if( !ppl || !interactive(ppl) ) {
			write("¶Ô²»Æğ£¬" + MUD_NAME + "ÕıÔÚ¿ª·¢¼°ÇåÀíÊı¾İÖĞ£¬3ÔÂ18ÈÕÔçÉÏ9µãÕıÊ½¿ª·Å¡£\n");
			destruct(ob);
			return;
		}
	}
*/

#endif
	if( wiz_level(arg) < wiz_lock_level ) {
		write("¶Ô²»Æğ£¬" + MUD_NAME + "Ä¿Ç°ÏŞÖÆÎ×Ê¦µÈ¼¶ " + WIZ_LOCK_LEVEL
			+ " ÒÔÉÏµÄÈË²ÅÄÜÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}	
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}


/*if (arg!="hxsd")
{
        write("\nÏµÍ³Î¬»¤ÖĞ£¬ÇëµÈ¶şĞ¡Ê±ÔÙÀ´!!\n");
         destruct(ob);
return;
}*/

	if( arg=="guest" ) {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {



                                if (ob->query("wizpwd"))
                                {
                                        write("ÇëÊäÈëÎ×Ê¦×¨ÓÃÃÜÂë£º\n");
                                        input_to("get_wizpwd", 1, ob);
                                        return;
                                }

			write("ÇëÊäÈëÃÜÂë£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}



			input_to("get_passwd", 1, ob);
			return;
		}
		write("ÄúµÄÈËÎï´¢´æµ²³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		destruct(ob);
		return;
	}

// ·ÀÖ¹Á½¸öÒÔÉÏµÄÍæ¼ÒÓÃÍ¬Ò» id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("ÓĞÆäËûÍæ¼ÒÕıÔÚÊ¹ÓÃÕâ¸ö ID£¬ÇëÖØĞÂÊäÈë¡£\n");
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}
//Í¬Ò»IP login 1ÈË
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && query_ip_number(usr[i])== query_ip_number(ob)) break;
	if (i >= 0) {
		write("ÓĞÍ¬Ò»IP,µÄÆäËûÍæ¼ÒÕıÔÚµÇÂ½ÓÎÏ·,ÇëµÈÒ»»áÔÙµÇÂ½¡£\n");
         destruct(ob);
return;
	}

// Add by Yu Jue 1998.8.24

	write("Ê¹ÓÃ " + (string)ob->query("id") + " Õâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
	input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
	string my_pass;
	string ip = query_ip_number(ob);
	int time_rl;
	int time_pwd;
	object user;
        string temps;
	write("\n");
	my_pass = ob->query("password");
        time_rl = time() - ob->query("last_on");
        time_pwd = time() - ob->query("lastpwd");

	/*if (!ob->query("wizpwd"))
	{
		temps = sprintf("ÏµÍ³Î¬»¤ÖĞ£¡\n", time_rl);
		write(temps);
			write("¶Ô²»Æğ£¬ÏµÍ³Î¬»¤ÖĞ£¡ÇëÉÔºóÔÙlogin£¬¶àĞ»ÄúµÄºÏ×÷¡£\n");
	                destruct(ob);
	                return;
	}*/

	if (time_rl >= 0 && time_rl <= 60 && !ob->query("wizpwd"))
	{
		temps = sprintf("Äã¾àÉÏ´ÎÍË³ö½ö %d Ãë?\n", time_rl);
		write(temps);
			write("¶Ô²»Æğ£¬ÎªÁË½µµÍÏµÍ³¸ººÉ£¬ÇëÉÔºóÔÙlogin£¬¶àĞ»ÄúµÄºÏ×÷¡£\n");
	                destruct(ob);
	                return;
	}
if (ob->query("last_from")==ip)
{
		if (time_pwd >= 0 && time_pwd <= 30)
	{
		temps = sprintf("Äã¾àÉÏ´Î´ò´íÃÜÂë,½ö %d Ãë?\n", time_pwd);
		write(temps);
			write("¶Ô²»Æğ£¬ÎªÁË±£Ö¤ÏµÍ³°²È«£¬ÇëÒ»·ÖÖÓºóÔÙlogin£¬¶àĞ»ÄúµÄºÏ×÷¡£\n");
	                destruct(ob);
	                return;
	}
}
	if( crypt(pass, my_pass) != my_pass )
	{
		write("ÃÜÂë´íÎó£¡\n");
		ob->set("last_from", ip);
                ob->set("lastpwd", time());
                ob->save();
		destruct(ob);
		return;
	}


	// Check if logout recently

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("confirm_relogin", ob, user);
		return;
	}


		
	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
			log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n");
	confirm_id("y", ob);
}

protected void get_wizpwd(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("wizpwd");

        if (crypt(pass, old_pass) == old_pass)
        {
                write(HIG "Éí·İÈ·ÈÏÍê³É£¬Î×Ê¦×¨ÓÃÃÜÂëÑéÖ¤Í¨¹ı£¡\n" NOR);
                write("ÇëÊäÈëÃÜÂë£º\n");
                input_to("get_passwd", 1, ob);
                return;
        } else
        {
                write("ÃÜÂë´íÎó£¡\n");
                destruct(ob);
                return;
        }
}


void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n");
		destruct(ob);
		return;
	} else {
if (user)
{
		tell_object(user, BLINK HIW"ÓĞÈË´Ó±ğ´¦( " + query_ip_number(ob)
			+ " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n"NOR);
		log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
			query_ip_name(ob), ctime(time()) ) );
}
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);	
}

void confirm_id(string yn, object ob)
{
if (query_ip_name(ob)==loginnip
&& (time() - loginntime) <= 1)
{
        write("\n±¾MUD×¢²áÍ¬Ò»IPĞÂÍæ¼Ò60ÃëÄÚÖ»ÄÜ½øĞĞÒ»´Î!!,ÇëÉÔºóÔÙ×¢²á!\n");
        destruct(ob);
return;
}
if (ob)
{
loginnip=query_ip_name(ob);
loginntime=time();
}
	if( yn=="" ) {
		write("Ê¹ÓÃÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}

		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("ºÃ°É£¬ÄÇÃ´ÇëÖØĞÂÊäÈëÄúµÄÓ¢ÎÄÃû×Ö£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}
        write( @TEXT
[2J
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤
[41;33m		ĞÇÔÂ´«ÆæĞÂÈË×¢²áÏòµ¼¡ª¡ªµÚÒ»²½			[2;37;0m
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[2;37;0m
[35m
ÇëÊäÈëÄúµÄ¸ßĞÕ´óÃû£¬ÓÉÓÚÕâ¸öÃû×Ö´ú±íÄãµÄÈËÎï£¬¶øÇÒÒÔºó²»ÄÜ¸ü¸Ä£¬
Îñ±ØÉ÷ÖØÔñÃû£¨²»ÑÅ¹ÛµÄĞÕÃû½«±»É¾³ı£©¡£Áí£ºÇë²»ÒªÑ¡Ôñ½ğÓ¹Ğ¡ËµÖĞ
ÒÑÓĞÈËÎïĞÕÃû¡£
[37m
[31m
Èç¹ûÄãÓĞÀ§ÄÑÊäÈëÖĞÎÄÃû×Ö£¬ÇëÖ±½ÓÇÃ»Ø³µ¼ü£Û£Ò£Å£Ô£Õ£Ò£Î£İ¡£
[37m
TEXT
	);
	write("ÄúµÄÖĞÎÄÃû×Ö(Ê¹ÓÃBig5µÄÍæ¼Ò¿ÉÇëÇóÎ×Ê¦ĞŞ¸Ä)£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
	input_to("get_name", ob);
}

string display_attr(int gift)
{
	if (gift > 24) return HIY + gift + NOR;
	if (gift < 16) return CYN + gift + NOR;
	return "" + gift;
}

private void get_resp(string arg, object ob)
{
        if( arg=="" ) {
                write(WHT"ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("get_resp", ob);
                return;
        }

        if( arg[0]=='y' || arg[0]=='Y' )
	{
        ob->set("name", Rname);
        write( @TEXT
[2J
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤
[44;33m		ĞÇÔÂ´«ÆæĞÂÈË×¢²áÏòµ¼¡ª¡ªµÚ¶ş²½			[2;37;0m
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[2;37;0m
[35m
      ĞÂÈË×¢²áµÄµÚ¶ş²½ÊÇÉè¶¨ºÃÄãµÄÃÜÂë£¬Çë²»ÒªÒÔÎªÉè¶¨Ò»¸öÃÜÂë
  ÊÇºÜ¼òµ¥µÄÊÂ£¬ÃÜÂë¹ØÏµµ½ÄãÉú´æµÄ°²È«£¬¼ÙÈçÃÜÂë¸øÈËµÁÓÃµÄ»°£¬
  ÕâÊÇÒ»¼ş·Ç³£Î£ÏÕµÄÊÂ£¬²»ÒªÒÔÎªÕâ²»¿ÉÄÜ·¢Éú¡£ËùÒÔÄãÒ»¶¨ÒªÈÏÕæ
  ÏëÒ»¸ö²»ÈİÒ×±»²Âµ½µÄÃÜÂë²ÅºÃÅ¶£¡
[32m
      ÎªÁË±£»¤Íæ¼Òµµ°¸µÄ°²È«£¬ĞÇÔÂ´«ÆæµÄÃÜÂë¼à²âÏµÍ³·Ç³£ÑÏ¸ñ£¬
  ÆäÖĞµÄÒªÇóÈçÏÂ£º
[36m
  Ò»¡¢ÃÜÂëÖÁÉÙÁù¸ö×Ö·ûÒÔÉÏ¡£
  ¶ş¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸ö´óĞ´×ÖÄ¸¡£
  Èı¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸öĞ¡Ğ´×ÖÄ¸¡£
  ËÄ¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸öÊı×Ö¡£
  Îå¡¢ÃÜÂë²»ÄÜÓëÄãµÄÓ¢ÎÄÃû×Ö¹ıÓÚÏàÏñ¡£
  [33m
  Çë°´ÕÕÒÔÉÏÒªÇóÉè¶¨ÄãµÄÃÜÂë£¬Èç¹ûÄãÔÚÒÔºóµÄÓÎÏ·¹ı³ÌÖĞ²»É÷¶ªÊ§
  ÁËÃÜÂë£¬Çë·¢ËÍE-mailÖÁhxsd@citiz.netÒÔÈ¡»ØÃÜÂë¡£
  [37m
TEXT
        );
        write(WHT"ºÃµÄ£¬ÏÂÃæÇëÉè¶¨ÄúµÄÃÜÂë£º"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        input_to("new_password", 1, ob);
	return;
	}
        else 
	if( arg[0]=='n' || arg[0]=='N')
	{
	Rname = random_name(random(2));
//	Rname = random_name();
        write(WHT"ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿"NOR);
        printf( HIY" -- %s £º"NOR, Rname);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}

        input_to("get_resp", ob);
	return;
	}
        else {
                write(WHT"¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÂúÒâ(y)²»ÂúÒâ(n)£º "NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("get_resp", ob);
                return;
        }


}

private void get_name(string arg, object ob)
{
	string name;
        if( arg =="")
        {
	Rname = random_name(random(2));
//	Rname = random_name();
        write("¿´À´ÄúÒª¸öËæ»ú²úÉúµÄÖĞÎÄÃû×Ö£®£®\n");
        write("ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿");
        printf( HIY" -- %s £º"NOR, Rname);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        input_to("get_resp", ob);
	}
	else {
        if( !check_legal_name(arg) ) {
		write("ÄúµÄÖĞÎÄÃû×Ö(Ê¹ÓÃBig5µÄÍæ¼Ò¿ÉÇëÇóÎ×Ê¦ĞŞ¸Ä)£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("get_name", ob);
                return;
        }

//        printf("%O\n", ob);
        ob->set("name", arg);
        write( @TEXT
[2J
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤
[44;33m		ĞÇÔÂ´«ÆæĞÂÈË×¢²áÏòµ¼¡ª¡ªµÚ¶ş²½			[2;37;0m
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[2;37;0m
[35m
      ĞÂÈË×¢²áµÄµÚ¶ş²½ÊÇÉè¶¨ºÃÄãµÄÃÜÂë£¬Çë²»ÒªÒÔÎªÉè¶¨Ò»¸öÃÜÂë
  ÊÇºÜ¼òµ¥µÄÊÂ£¬ÃÜÂë¹ØÏµµ½ÄãÉú´æµÄ°²È«£¬¼ÙÈçÃÜÂë¸øÈËµÁÓÃµÄ»°£¬
  ÕâÊÇÒ»¼ş·Ç³£Î£ÏÕµÄÊÂ£¬²»ÒªÒÔÎªÕâ²»¿ÉÄÜ·¢Éú¡£ËùÒÔÄãÒ»¶¨ÒªÈÏÕæ
  ÏëÒ»¸ö²»ÈİÒ×±»²Âµ½µÄÃÜÂë²ÅºÃÅ¶£¡
[32m
      ÎªÁË±£»¤Íæ¼Òµµ°¸µÄ°²È«£¬ĞÇÔÂ´«ÆæµÄÃÜÂë¼à²âÏµÍ³·Ç³£ÑÏ¸ñ£¬
  ÆäÖĞµÄÒªÇóÈçÏÂ£º
[36m
  Ò»¡¢ÃÜÂëÖÁÉÙÁù¸ö×Ö·ûÒÔÉÏ¡£
  ¶ş¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸ö´óĞ´×ÖÄ¸¡£
  Èı¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸öĞ¡Ğ´×ÖÄ¸¡£
  ËÄ¡¢ÃÜÂëÖĞ±ØĞë°üº¬ÖÁÉÙÒ»¸öÊı×Ö¡£
  Îå¡¢ÃÜÂë²»ÄÜÓëÄãµÄÓ¢ÎÄÃû×Ö¹ıÓÚÏàÏñ¡£
  [33m
  Çë°´ÕÕÒÔÉÏÒªÇóÉè¶¨ÄãµÄÃÜÂë£¬Èç¹ûÄãÔÚÒÔºóµÄÓÎÏ·¹ı³ÌÖĞ²»É÷¶ªÊ§
  ÁËÃÜÂë£¬Çë·¢ËÍE-mailÖÁhxsd@citiz.netÒÔÈ¡»ØÃÜÂë¡£
  [37m
TEXT
        );
        write(WHT"ºÃµÄ£¬ÏÂÃæÇëÉè¶¨ÄúµÄÃÜÂë£º"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        input_to("new_password", 1, ob);
		}
}

void new_password(string pass, object ob)
{
	write("\n");
       if( !check_legal_password(ob,pass)) {
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
}
	if( strlen(pass)<5 ) {
		write("ÃÜÂëµÄ³¤¶ÈÖÁÉÙÒªÎå¸ö×ÖÔª£¬ÇëÖØÉèÄúµÄÃÜÂë£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
	input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}

		input_to("new_password", 1, ob);
		return;
	}

	write(@TEXT
[2J
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤
[45;33m		ĞÇÔÂ´«ÆæĞÂÈË×¢²áÏòµ¼¡ª¡ªµÚÈı²½			[2;37;0m
[33m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[2;37;0m
[35m

Ò»¸öÈËÎïµÄÌì¸³¶ÔÓÚËû»òËıËùĞŞÏ°µÄÎäÒÕÏ¢Ï¢Ïà¹Ø¡£ÏÀ¿ÍĞĞÖĞµÄÈËÎï´ó¶à¾ßÓĞ
ÒÔÏÂËÄÏîÌì¸³£º

[36m
	ëöÁ¦£ºÓ°Ïì¹¥»÷ÄÜÁ¦¼°¸ººÉÁ¿µÄ´óĞ¡¡£
	ÎòĞÔ£ºÓ°ÏìÑ§Ï°Îä¹¦ÃØ¼®µÄËÙ¶È¼°Àí½âÊ¦¸µµÄÄÜÁ¦¡£
	¸ù¹Ç£ºÓ°ÏìÌåÁ¦»Ö¸´µÄËÙ¶È¼°Éı¼¶ºóËùÔö¼ÓµÄÌåÁ¦¡£
	Éí·¨£ºÓ°Ïì·ÀÓù¼°¶ã±ÜµÄÄÜÁ¦¡£
[33m
        Äú¿ÉÒÔ×Ô¼ºÖ¸¶¨ÆäÖĞÒ»ÏîµÄÖµ£¬»òÕßÊäÈë 0 ½»ÓÉÏµÍ³Ëæ»ú²úÉú¡£
        ÊäÈë5 ¿ÉÒÔÖ¸¶¨È«²¿4ÏîÊôĞÔ ×ÜºÍ²»³¬¹ı80 µ¥Ïî²»³¬¹ı30 ²»Ğ¡ÓÚ10¡£
        Ñ¡Ïî5 ÊäÈëÊ¾Àı ëöÁ¦ ÎòĞÔ ¸ù¹Ç Éí·¨ ÊäÈë20 20 20 20 
        ÇëÊäÈëÄúµÄÑ¡Ôñ(0-5)£º
[37m
TEXT);

ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        input_to("select_gift", ob);
}

void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
                if (select!=5) random_gift(my, select);
		printf("\nëöÁ¦[%s]£¬ÎòĞÔ[%s]£¬¸ù¹Ç[%s]£¬Éí·¨[%s]\n",
	                display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]));
                write("ÄúÍ¬ÒâÕâÒ»×éÌì¸³Âğ£¿");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("get_gift", ob, my, select);
                return;
	}
        write("\nÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        input_to("get_email", ob, my);
}

void select_gift(string yn, object ob)
{
        int i;
        mapping my = ([]);

        if (!sscanf(yn, "%d", i) || i < 0 || i > 5) {
                write("\nÊäÈë´íÎó£¬ÇëÖØĞÂÑ¡Ôñ£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("select_gift", ob);
                return;
        }
        if (i) {
if (i<5)  write("\nÇëÊäÈëÄúÏëÒªµÄÊıÖµ(10-30)");
if (i==5)  write("\nÇëÊäÈëÄúÏëÒªµÄÊıÖµ(ëöÁ¦ ÎòĞÔ ¸ù¹Ç Éí·¨) Ê¾Àı:20 20 20 20");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
                input_to("set_gift", ob, my, i);
        } else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
        int i;
        int a,b,c,d;
        
        //write("yn"+yn+"I"+i+"select"+select+"\n");
//         destruct(ob);
//return;
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
        if (select<5)
{
        if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
                write("\nÊıÖµ´íÎó£¬µ¥Ïî²»³äĞí³¬¹ı30Ğ¡ÓÚ10 ÇëÖØĞÂÊäÈë£º");
ob->add_temp("input",1);
         	  destruct(ob);
		  return;
}
 
        switch (select) {
                case 1: my["str"] = i; break;
                case 2: my["int"] = i; break;
                case 3: my["con"] = i; break;
                case 4: my["dex"] = i;
        }
                get_gift(" ", ob, my, select);
                //input_to("set_gift", ob, my, select);
                return;
        }

if (select==5)
{

	     if (sscanf(yn,"%d %d %d %d",
		a,b,c,d) != 4){
        	  write(yn);
        	  write("\n×¢²áĞÅÏ¢´íÎó!!ÊäÈë¸ñÊ½Îª ëöÁ¦ ÎòĞÔ ¸ù¹Ç Éí·¨!\n");
         	  destruct(ob);
		  return;
                  }
	    if ((a<10) || (a>30) || (b<10) || (b>30) || 
	    	(c<10) || (c>30) || (d<10) || (d>30) ||
	    	((a+b+c+d)!=80)) {
        	  write("\nÌì¸³Êı¾İ´íÎó!!×ÜºÍ±ØĞëÎª80 µ¥Ïî²»³äĞí³¬¹ı30Ğ¡ÓÚ10 !\n");
         	  destruct(ob);
		  return;
		}
	
my["str"] = a;
my["int"] = b;
my["con"] = c;
my["dex"] = d;	
//write("yn"+yn+"I"+i+"select"+select+"\n");
        	  //write("\nÌì¸³Êı¾İ"+a+","+b+","+c+","+d+",\n");
                get_gift(" ", ob, my, select);
                return;
}


        switch (select) {
                case 1: my["str"] = i; break;
                case 2: my["int"] = i; break;
                case 3: my["con"] = i; break;
                case 4: my["dex"] = i;
                case 5: break;
        }
        
        
        get_gift(" ", ob, my, select);
}

void get_email(string email, object ob, mapping my)
{
	object user;
	string id,address;	

	write("\n");
	if (email == "" || strsrch(email, "@") == -1||
		sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1)
	{
		write("µç×ÓÓÊ¼şµØÖ·ĞèÒªÊÇ id@address µÄ¸ñÊ½¡£\n");
		write("ÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
}

		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
	input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
	write("\n");
	if( gender=="" ) {
		write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "ÄĞĞÔ");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Å®ĞÔ" );
	else {
		write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
         destruct(ob);
return;
}
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

        if (!ob) return 0;
	if (!ob->query("body")) return 0;
	user = new(ob->query("body"));
	if(!user) {
		write("ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÊ¹ÓÃÕßÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

init_new_player(object user)
{
	user->set("title", "ÆÕÍ¨°ÙĞÕ");
	user->set("birthday", time() );
	user->set("potential", 99);
        user->set("food", (user->query("str")+10)*10);
        user->set("water", (user->query("str")+10)*10);

	user->set("channels", ({ "chat", "rumor", "party", "es" }) );
//	user->set("balance", 1000);
}

		
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, mailbox, gift, fly, login_ob,weapon;
	string startroom,filen;
        object link_ob;
        int card_num;
    int i,temp,maxexp;
    int lvl, level,j,exp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;        
string wiz_status;



         object newob,oldob;
       
        string mission, wname, wmin, file,mission2;
        string *wmission;
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	user->set_encoding(ob->query_encoding());
//	user->set_temp("big5", ob->query_temp("big5"));
    //by mol

        if (ob->query_temp("big5")) 
                user->set_temp("big5", 1);
     if (ob->query_temp("xmud"))
    	user->set_temp("xmud", 1);

	exec(user, ob);


	write("\nÄ¿Ç°È¨ÏŞ£º" + wizhood(user) + "\n");
	user->setup();
	if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
	        user->set("food", user->max_food_capacity());
        	user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	// Use condition to auto save user file
	user->apply_condition("autosave", 1);
	
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);
	gift = new("/clone/book/rules");
	gift->move(user);
  
          if(user->query("hyvip") >=1 )
        {
                  fly=new("/clone/misc/flyhy");
          	    fly->move(user);
        }
        else if(!user->query("flybag") && (user->query("age") < 80)  && (!user->query("zhuanshen")) )
        {
                  fly=new("/clone/misc/fly");
          	    fly->move(user);
        }



 if (userp(user) )
{
exp = (int)user->query("combat_exp", 1);
level = (int)user->query("levels", 1);
if (! level || level < 1) 
{
user->set("levels", 1);
	level = 1;	
}
//tell_userject(user, level);
if (exp> 10000)
{
for (i = level; ;i++) {
if ((i + 1) * (i + 1) * (i + 1) > (exp / 1000))
   {
                                        lvl = i;
                                        break;
   }
}

                
                        if (lvl > level)
                        {
                                j = lvl - level;
                                user->set("levels", lvl);
                                user->add("combat_exp", 10000 * j);
                                user->add("potential", 8000 * j);
                                user->add("max_neili", 100 * j);
                                if (exp> 600000)  
{
	                        user->add("mpgx", 10 * j);
                                tell_object(user, HIY "Ö»¼ûÒ»µÀºì¹â·É½øÄãµÄÌåÄÚ£¬ÄãµÄÈËÎïµÈ¼¶ÌáÉıÁË"+j+"¼¶£¡\n" +
                                        "´Ë´ÎÉı¼¶£¬Äã»ñµÃÁË" + chinese_number(10000 * j) +
                                        "µã¾­Ñé¡¢" + chinese_number(8000 * j) +
                                        "µãÇ±ÄÜ¡¢" + chinese_number(100 * j) +
                                        "µãÄÚÁ¦ÉÏÏŞºÍ" + chinese_number(10 * j) +
                                        "µãÃÅÅÉ¹±Ï×£¡\n" NOR);
}
else
{
                                tell_object(user, HIY "Ö»¼ûÒ»µÀºì¹â·É½øÄãµÄÌåÄÚ£¬ÄãµÄÈËÎïµÈ¼¶ÌáÉıÁË"+j+"¼¶£¡\n" +
                                        "´Ë´ÎÉı¼¶£¬Äã»ñµÃÁË" + chinese_number(10000 * j) +
                                        "µã¾­Ñé¡¢" + chinese_number(8000 * j) +
                                        "µãÇ±ÄÜ¡¢" + chinese_number(100 * j) +
                                        "µãÄÚÁ¦ÉÏÏŞ£¡\n" NOR);

}
                       
                        }

}	       
}


//	if (user->query("weapon/type")) {
//		switch((string)user->query("weapon/type"))
//		{
//			case "½£":
//			weapon = new("/d/npc/m_weapon/weapon/m_sword");
//			weapon->move(user);
//			break;
//			case "µ¶":
//			weapon = new("/d/npc/m_weapon/weapon/m_blade");
//			weapon->move(user);
//			break;
//			case "±Ş":
//			weapon = new("/d/npc/m_weapon/weapon/m_whip");
//			weapon->move(user);
//			break;
//			case "ÕÈ":
//			weapon = new("/d/npc/m_weapon/weapon/m_staff");
//			weapon->move(user);
//			break;
//			case "¹÷":
//			weapon = new("/d/npc/m_weapon/weapon/m_club");
//			weapon->move(user);
//			break;
//			default:
//		}
//	}
   //    if(this_player()->quary(age)>==15)
    //    {
      //  if (!user->query("giftcard"))
   //   if(!user->query("giftcard") && (user->query("age") >= 15) )
      //  {
      //          card_num=howmany_card();
      //          set_card(card_num+1);
	//        gift = new("/clone/misc/card");
        //	gift->move(user);
        //        user->set("giftcard", card_num);
       // }
  //      }
//	if (wizhood(user) == "(player)")
	{
		if (user->query("class")=="bonze")
		{
			if (user->query("gender")=="Å®ĞÔ")
			{
				cloth = new("/clone/cloth/ni-cloth.c");
				shoe = new("/clone/cloth/ni-xie.c");
			}
			else
			{
				cloth = new("/clone/cloth/seng-cloth.c");
				shoe = new("/clone/cloth/seng-xie.c");
			}
		}
		else
		{
			if (user->query("class")=="taoist")
			{
				if ( user->query("gender")=="Å®ĞÔ")
				{
					cloth = new("/clone/cloth/daogu-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
				else
				{
					cloth = new("/clone/cloth/dao-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
			}
			else
			{
				if ( user->query("gender")=="Å®ĞÔ")
				{
					shoe = new("/clone/cloth/female-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/female1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/female2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/female3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/female4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/female5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/female6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/female7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/female8-cloth.c");
					}
				}
				else
				{
					shoe = new("/clone/cloth/male-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/male1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/male2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/male3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/male4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/male5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/male6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/male7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/male8-cloth.c");
					}
				}
			}
		}
		cloth->move(user);
		cloth->wear();
		shoe->move(user);
		shoe->wear();
	}

	if( !silent ) {
		if (ob->query("registered") == 0) 
			write(read_file(UNREG_MOTD));
		else 
			write(read_file(MOTD));
		if( ob->query("new_mail") ) {
			write(GRN+"\nÂÌÁÖÓÊ²îÅÜÀ´¶ÔÄãËµ£ºÕâÊÇÈË¼ÒÁô¸øÄúµÄĞÅ£¡\n\n"+NOR);
			user->set("new_mail", 0);
		}
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom")) )
			startroom = START_ROOM;

		if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n",
			({user}));
	}
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
//	login_ob->set("last_on", time());
//	login_ob->set("last_from", query_ip_name(user));
	login_ob->save();

        write(HIW"\nÄãÉÏ´Î¹âÁÙº£ÑóV-ĞÇÔÂ´«Ææ ÊÇ " + HIG +ctime(login_ob->query("last_on"))+ NOR + " ´Ó " + HIR +login_ob->query("last_from") + NOR + " Á¬½ÓµÄ¡£\n\n"NOR);
        if( login_ob->query("new_mail") )
        {
                write( HIY + "\nÓĞÄúµÄĞÅ£¡¿ì¿´ÄúµÄĞÅÏä°É£¡\n\n" + NOR);
                login_ob->set("new_mail", 0);
        }
        destruct(login_ob);

	wiz_status = SECURITY_D->get_status(user);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)ÓÉ%sÁ¬Ïß½øÈë¡£¹²Çå³ı " + reclaim_objects() + " ¸ö±äÊı¡£\n", user->name(),user->query("id"), query_ip_name(user)) );
}
	UPDATE_D->check_user(user);
        user->set_temp("temp_exp",user->query("combat_exp"));
        user->set_temp("temp_time",time());
        user->set_temp("mud_age",user->query("mud_age"));
         if( user->query("lastChangeSize") != file_size("/doc/help/whatsnew") ) {
		user->set("lastChangeSize", file_size("/doc/help/whatsnew"));
		write(BLINK HIW"\n º£ÑóV-ĞÇÔÂ´«Ææ ÓĞ×îĞÂ±ä¶¯£¡ÇëÓÃ help whatsnew À´²é¿´¡£\n\n"NOR);
	}
//if(wizardp(user)) {

//Èı×ªÏŞÖÆ        
if (user->query("str")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",80);
}
if (user->query("dex")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",80);
}
if (user->query("int")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",80);
}
if (user->query("con")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",80);
}
if (user->query("per")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",80);
}
if (user->query("kar")> 80 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",80);
}
//4×ª
if (user->query("str")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",110);
}
if (user->query("dex")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",110);
}
if (user->query("int")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",110);
}
if (user->query("con")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",110);
}
if (user->query("per")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",110);
}
if (user->query("kar")> 110 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",110);
}

//5×ª
if (user->query("str")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("str",120);
}
if (user->query("dex")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("dex",120);
}
if (user->query("int")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("int",120);
}
if (user->query("con")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("con",120);
}
if (user->query("per")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("per",120);
}
if (user->query("kar")> 120 && user->query("4zhuan") && user->query("5zhuan"))
{
           user->set("kar",120);
}
//4×ª ,5×ª EXPÏŞÖÆ
	if (user->query("expmax",1)<0)
		user->set("expmaxp",0);
	if (user->query("expmax",1)>500)
		user->set("expmaxp",500);
		
if (user->query("4zhuan") || user->query("5zhuan"))
{
	
maxexp=6000000+(user->query("expmax",1)*500000);
if ( user->query("5zhuan") && maxexp < 1) 
maxexp=5000000+(user->query("expmax",1)*200000);

if (user->query("combat_exp",1)> maxexp && maxexp>10000)
{
user->set("combat_exp",maxexp);
}
write(HIR"Ä¿Ç°¾­ÑéÉÏÏŞ:"+maxexp+"!\n"NOR);
}

//}
	if(wizardp(user)) {
                if( !ob->query("wizpwd") )
{
     write(HIR"¡í"WHT"¡º"HIG"ÇëÓÃWIZPWDÉè¶¨ÏàÓ¦µÄWIZÃÜÂë"WHT"¡»"NOR"");
}

	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
		CHANNEL_D->do_channel( this_object(), "wiz",
			sprintf(NOR "%s" HIY " ´Ó " HIG "%s" HIY " ½øÈëÁ¬Ïß¡£", user->short(1), query_ip_name(user)) );
}
   	     tell_object(user, BLINK HIG"ÉÏ´ÎÁ¬ÈëÊ±¼ä( " + ctime(ob->query("last_on"))
			+ " )ÇëĞ£¶Ô¡£\n"NOR);
   	     tell_object(user, BLINK HIG"ÉÏ´ÎÁ¬ÈëIPµØÖ·( " + ob->query("last_from")
			+ " )ÇëĞ£¶Ô¡£\n"NOR);

        	if ( wizhood(user)=="(admin)")	{
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(HIW"ÓĞÎ×Ê¦ÓĞ·Ç·¨Ğ´²Ù×÷£¬Á¢¼´²é¿´ /log/FILES ¡£\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
				write(HIW"ÓĞÎ×Ê¦ĞŞÊ¹ÓÃ¹ıcall£¬Á¢¼´²é¿´ /log/static/CALL_PLAYER ¡£\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(HIW"ÓĞĞÂÎÄ¼şupdate´íÎó£¬Á¢¼´²é¿´ /log/log ¡£\n"NOR);
			}
			if( user->query("wiz_check/PURGE_PLAYER") != file_size("/log/static/PURGE") ) 
			{
				user->set("wiz_check/PURGE_PLAYER", file_size("/log/static/PURGE"));
				write(HIW"ÓĞÈËÊ¹ÓÃ¹ıPURGE´íÎó£¬Á¢¼´²é¿´ /log/static/PURGE ¡£\n"NOR);
			}
			if( user->query("wiz_check/promotion_PLAYER") != file_size("/log/static/PURGE") ) 
			{
				user->set("wiz_check/promotion_PLAYER", file_size("/log/static/promotion"));
				write(HIW"ÓĞÈËÊ¹ÓÃ¹ıÈ¨ÏŞÃüÁî£¬Á¢¼´²é¿´ /log/static/promotion ¡£\n"NOR);
			}
		}
    if (user->query_temp("xmud"))
    {
          user->force_me("xnventory");
          user->force_me("xp");
          user->force_me("xkan");
          user->force_me("unset brief");
    }
write("$#$\n");
		return;
	} 
	else
        {
                if ( user->query("mud_age") <= 0)
                       {
		user->set("last_on", time());
		user->set("last_from", query_ip_name(user));
		user->set("env/showmap",1);
		user->save();
             message("channel:chat",HIW"¡¾½­ºşÍ¨¸æ¡¿£º"HIW"ÈÈÁÒ»¶Ó­ĞÂÍæ¼Ò  "
             +user->query("name")+"("+user->query("id")+")À´µ½"+MUD_NAME+"£¡Çë¸÷Î»¶à¶à¹ØÕÕ£¡\n"NOR,users());
                        } 
                        else
                        {
             message("channel:chat",HIW"¡¾½­ºşÍ¨¸æ¡¿£º"
             +user->query("name")+"("+user->query("id")+")ÔÙ´ÎÀ´µ½ÁËº£ÑóV-ĞÇÔÂ´«Ææ£¬»¶Ó­Äã»ØÀ´£¡\n"NOR,users());
   	     tell_object(user, BLINK HIG"ÉÏ´ÎÁ¬ÈëÊ±¼ä( " + ctime(ob->query("last_on"))
			+ " )ÇëĞ£¶Ô¡£\n"NOR);
   	     tell_object(user, BLINK HIG"ÉÏ´ÎÁ¬ÈëIPµØÖ·( " + ob->query("last_from")
			+ " )ÇëĞ£¶Ô¡£\n"NOR);

             user->delete("vendetta/authority");
//           user->set("food",ob->max_food_capacity());
//           user->set("water",ob->max_water_capacity());
if (user->query("food")<100)
{
           user->add("food",50);
}
if (user->query("water")<100)
{
           user->add("water",50);
}
//             message("channel:chat",HIW"¡¾½­ºşÍ¨¸æ¡¿£º"
//             +user->query("name")+"("+user->query("id")+")ÓÉÓÚsaveµÄËğ»µ,ÏÖÔÚÓÃ10.24µÄsave»Ö¸´,Íæ¼Òµ½gc,ÓÃyaoshu¿ÉµÃÒ»¶¨µÄ²¹³¥£¡\n"NOR,users());
                        }

	}
//by mol
    if (user->query_temp("xmud"))
    {
          user->force_me("xnventory");
          user->force_me("xp");
          user->force_me("xkan");
          user->force_me("unset brief");
    }
//write("$#$\n");
//by mol
"/cmds/usr/news"->check_news(user);
 
 if (!user->query("env/bweapon"))
 {
 filen = "/p/residence/banding/"+user->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");

 for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
 if( i>=15 ) continue;
         if (newob=new(wmin))
        {
       newob->move(user);
      }
}
}
write("$#$\n");
	return;
}

varargs void reconnect(object ob, object user, int silent)
{
string temps;
	object userp;
	int time_rl;
string wiz_status;
        
        userp = find_body(user->query("id"));
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	ob->set_encoding(ob->query_encoding());
	ob->set("last_on", time());
	ob->save();
    //by mol
    if (ob->query_temp("xmud"))
    	user->set_temp("xmud", 1);
    else
    	user->delete_temp("xmud");

	exec(user, ob);

    //by mol

//        time_rl = time() - user->query("last_on");
//	if (time_rl >= 0 && time_rl <= 10)
//	{
//		temps = sprintf("Äã¾àÉÏ´ÎÍË³ö½ö %d Ãë?\n", time_rl);
//		write(temps);
//			write("¶Ô²»Æğ£¬ÎªÁË½µµÍÏµÍ³¸ººÉ£¬ÇëÉÔºóÔÙlogin£¬¶àĞ»ÄúµÄºÏ×÷¡£\n");
//	                destruct(userp);
//	                return 0;
//	}
	user->set("last_on", time());
	user->reconnect();
	if( !silent ) {
		tell_room(environment(user), user->query("name") + "ÖØĞÂÁ¬Ïß»Øµ½Õâ¸öÊÀ½ç¡£\n",
		({user}));
	}
	wiz_status = SECURITY_D->get_status(user);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%sÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£", user->query("name"), query_ip_name(user)) );
}
	UPDATE_D->check_user(user);
    if (user->query_temp("xmud"))
    {
          user->force_me("xnventory");
          user->force_me("xp");
          user->force_me("xkan");
          user->force_me("unset brief");
    }
write("$#$\n");
}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	

	if( id=="all"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃall×÷Îªid¡£\n");
	return 0;
	}
	if( id=="corpse"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃcorpse×÷Îªid¡£\n");
	return 0;
	}
	if( id=="admin"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃadmin×÷Îªid¡£\n");
	return 0;
	}
	if( id=="guest"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃguest×÷Îªid¡£\n");
	return 0;
	}
	if( id=="root"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃroot×÷Îªid¡£\n");
	return 0;
	}
	if( id=="gold"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃgold×÷Îªid¡£\n");
	return 0;
	}
	if( id=="bing"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃbing×÷Îªid¡£\n");
	return 0;
	}
	
	if( id=="killer"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃkiller×÷Îªid¡£\n");
	return 0;
	}
	if( id=="none"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃnone×÷Îªid¡£\n");
	return 0;
	}
	if( id=="silver"){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃsilver×÷Îªid¡£\n");
	return 0;
	}
	if( strsrch(id, "none")>=0){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃnone×÷Îªid¡£\n");
	return 0;
	}
	if( strsrch(id, "robber")>=0){
		write("¶Ô²»Æğ£¬²»ÄÜÊ¹ÓÃrobber×÷Îªid¡£\n");
	return 0;
	}
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 12 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
			return 0;
		}

	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	

	if( (strlen(name) < 4) || (strlen(name) > 10 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇ 2 µ½ 5 ¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
//		if( name[i]<=' ' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
			return 0;
		}
//		if( i%2==0 && !is_chinese(name[i..<0]) ) {
//			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
//			return 0;

		if( (strsrch(name, "¡¡") >= 0) ||
		    (strsrch(name, "°Ö") >= 0)) {
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃÒıÆğÎó»áµÄµ¥×Ö¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
// add for ten top. 
int set_madlock(int setmark)
{
	if( wiz_level(this_player(1)) < wiz_level("(arch)") )
		return 0;
	if( setmark == 1 ) mad_lock = 1;
	else mad_lock = 0;
	return 1;
}

int get_madlock()
{
	return mad_lock;
}
int howmuch_money(object ob)
{
	int total;
	int total2;
	object gold, silver, coin;

	total = 0;
	total2 = 0;

	gold = present("gold_money",ob);
	silver = present("silver_money",ob);
	coin = present("coin_money",ob);

	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	total2 = (int)ob->query("balance");
	if (!total2 || total2 < 0) {
		ob->set("balance", 0);
	}
	total=total+total2;
	return total;
}
// 10
int check_legal_password(object ob,string pass)
{
        int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
        i = strlen(pass);
        if( strlen(pass) <= 5)   {
                write(WHT"¶Ô²»Æğ£¬ÄãµÄÃÜÂë±ØĞë×îÉÙÁù¸ö×Ö·û¡£\n\n");
                return 0;
        }
	id= ob->query("id");	
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write(WHT"¶Ô²»Æğ£¬ÄãµÄÃÜÂëºÍÄãµÄÓ¢ÎÄÃû×ÖÌ«ÏóÁË¡£\n"NOR);
                return 0;
        }

        while(i--) {
                if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

        }
	if( bigletter == 0 || smlletter == 0 || 
	bigletter+smlletter == strlen(pass))
{
        write(WHT"ÄúµÄÃÜÂë±ØĞè°üº¬´óĞ´" + RED"ºÍ" + WHT"Ğ¡Ğ´Ó¢ÎÄ×ÖÄ¸"
		+ RED"ºÍ" + WHT"ÆäËüÌØÊâ·ûºÅ£¨Êı×Ö£¬±êµã£©¡£\n"NOR);
	return 0;
}
        return 1;
}
