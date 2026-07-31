#include <ansi.h>
inherit ROOM;
string *s1 = ({ "ÎÊ","²Ô","Ã£","´ó","µØ","Ë­","Ö÷","³Á","¸¡","Êý","·ç","Á÷",
                "ÈË","Îï","»¹","¿´","½ñ","³¯","½­","É½","Èç","´Ë","¶à","½¿"});
void create()
{
        set("short", YEL"É½×¯ÕýÌü"NOR);
        set("long",
"ÄãÈËÉÐÎ´µ½£¬Ò»Ë¿µ­µ­µÄÇåÏãÒÑ×ÔÇßÈëÄãµÄÐÄÆ¢¡£×ß½ø´óÌü£¬Ó­ÃæÊÇ\n"
"Ò»·ù¼«´óµÄÆÃÄ«É½Ë®£¬Ä«¼£×ÝºáÁÜÀì£¬±Ê·æá¿áÉÓÐÖÂ¡£»­ÃæÉÏ»æµÄÊÇÉ½ºÓ\n"
"Éçð¢Í¼£¬¶«ÆðÃ£Ã£´óº££¬Î÷ÖÁ°¨°¨Ñ©É½£¬ÆøÊÆ²»·²£¬ÁîÈË¶ÙÉúÑöÖ¹Ö®¸Ð£¬\n"
"ÅÔ±ßÊÇÒ»·ù¶ÔÁª£º¡¸ÎÊ²ÔÃ£´óµØË­Ö÷³Á¸¡[2;37;0mÊý·çÁ÷ÈËÎï»¹¿´½ñ³¯\n"
"¡¹[2;37;0m[2;37;0mºáÅú£º½­É½Èç´Ë¶à½¿[2;37;0mÕû×ù´óÌüËäÈ»¸»Àö\n"
"ÌÃ»Ê£¬ÆøÊÆ»Öºê£¬¿ÉÊÇÄã×Ü¸Ð¾õÓÐµã²»Ì«Ð­µ÷µÄµØ·½¡£ËÆºõºÍÄãÒ»Â·Ëù¼û\n"
"ËùÎÅ²»Ì«ÏàÏó¡£ÄãÊÇ²»ÊÇÓ¦¸ÃºÃºÃ(think)ÄØ£¬È»ºóÔÙ½øÈ¥£¿\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"dynamic/jiuqu16",
          "north" : __DIR__"neishi",
        ]));
        set("no_magic", "1");

        setup();
}

int init()
{
        add_action("do_think","think");
        add_action("do_uncover","uncover");
}

int do_think(string arg)
{
        object me;

        me = this_player();
        if( random(me->query("int"))<20 )
        {
                write("ÄãÏë°¡Ïë£¬½á¹ûÏëÆÆÁËÄÔ´ü£¬°×°×µÄÄÔ½¬Á÷ÁËÒ»µØ¡£\n");
                me->receive_damage("jing",100);
        }
        else
        {
                write("ÄãÃÆÍ·¿àË¼£¬Í»È»·¢ÏÖµØÉÏÓÐÒ»¿é·½×©(brick)ËÆºõ±ßÔµÌØ±ðµÄ¹â
»¬¡£ºÃÏó¿ÉÒÔ(uncover)\n");
                me->set_temp("marks/xanadu_hall1",1);
        }
        return 1;
}

int do_uncover(string arg)
{
          object me;
        int i,j,k,l;

        me = this_player();
        if(!arg || arg != "brick" || !me->query_temp("marks/xanadu_hall1") )//|| wizardp(me) )
                return 0;
        message_vision(GRN"$NÐ¡ÐÄÒíÒíµØ°ÑµØ°å×©½Ò¿ª£¬Ö»Ìý¡°¶£¡±µÄÒ»ÉùÇáÏì...\n"NOR,me);
       if( random(10) > 5 ) {
        message_vision(RED"Ò»ÅîÅ£Ã«Ï¸ÕëÏò$NÉäÀ´£¬ÕýºÃÃüÖÐ£¬Ö»ÌýÄãÒ»Éù²Òº¿£¬Ï¸ÕëÒÑÔÚÄãÐØÇ°¶Ô´©¶ø¹ý¡£\n"NOR,me);
                me->receive_wound("qi",random(me->query("kar"))*50);
                COMBAT_D->report_status(me,me,1);
         }
        else
         message_vision(RED"Ò»ÅîÅ£Ã«Ï¸ÕëÏò$NÉäÀ´£¬$NÇáËÉµÄ¶ãÁË¿ªÈ¥¡£\n"NOR,me);
         if( me->query("qi") > 100 )
                {
                        me->delete_temp("marks/xanadu_hall1");
                        i=random(9);
                        j=random(9);
                        k=random(6);
                        l=random(6);
                        me->set_temp("marks/xanadu_hall2",l*1000+k*100+j*10+i);
 write("Äã¾ª»ê¸¦¶¨£¬·¢ÏÖµØ°å·­ÆðÀ´µÄ±³Ãæ¿Ì×ÅÒ»ÐÐÐ¡×Ö£º"+s1[i]+s1[9+j]+s1[18+k]+s1[18+l]+"\n");


                }
        return 1;
}

