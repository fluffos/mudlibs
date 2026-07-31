// port.c
// Created by robert@wllz

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
        string str;
        int i,I1,I2,I3,I4,I5;
        
        ob = filter_array(children(USER_OB),(: userp :));
        str = HIY"      ¡ó"HIC"ÒÔÏÂÎª±¾ÓÎÏ·¸÷¶Ë¿ÚÊ¹ÓÃÇé¿ö£º\n"NOR;
        for(i=0;i<sizeof(ob);i++){
                if(!environment(ob[i])) continue;
                if(query_ip_port(ob[i]) == 2000) I1++;
                 if(query_ip_port(ob[i]) == 4000) I2++;
                 if(query_ip_port(ob[i]) == 4001) I3++;
        }
        str += sprintf("\n      [1;32m2000£º[2;37;0m[37m%dÈË[2;37;0m©¦[1;32m4000£º[2;37;0m[37m%dÈË[2;37;0m©¦[1;32m4001£º[2;37;0m[37m%dÈË[2;37;0m\n",I1,I2,I3);
        str += HIC"ÎªÁË¸øÄúÌá¹©Ò»¸öÁ÷³©µÄÍøÂç»·¾³£¬½¨ÒéÑ¡ÔñÊ¹ÓÃÂÊ½ÏµÍµÄ¶Ë¿ÚÁ¬Ïß¡£\n";
        str += HIC"Ê¹ÓÃportÖ¸Áî¿É²ì¿´¸÷¶Ë¿ÚÊ¹ÓÃÇé¿ö¡£"NOR;
         write(str+"\n\n");
        return 1;
}

int help(object me)
{
        write(@HELP

Ö¸Áî¸ñÊ½£ºport

Õâ¸öÖ¸ÁîÊÇÈÃÄãÁË½âÄ¿Ç°ÓÎÏ·ÖĞ¸÷¶Ë¿ÚµÄÊ¹ÓÃ³Ì¶È¡£ÎªÁË¸øÄúÌá¹©Ò»¸öÁ÷
³©µÄÍøÂç»·¾³£¬½¨ÒéÑ¡ÔñÊ¹ÓÃÂÊ½ÏµÍµÄ¶Ë¿ÚÁ¬Ïß¡£

HELP
        );
        return 1;
}

