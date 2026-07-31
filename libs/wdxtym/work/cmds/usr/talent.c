// This program is a part of NT MudLIB

#include <ansi.h>
#ifndef F_ABILITY;
#define F_ABILITY        "/adm/daemons/abilityd"
#endif

inherit F_ABILITY;
int main(object me, string arg)
{
        string *lists,temp,id;
        int ab;
        int i, a_num, learned_energy;
        object ob;
        string arg1, myclass,str;
        int level;

        MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
        if( wizardp(me) )
        {
                if( arg && sscanf(arg, "-%s", id) == 1 )
                {
                        ob = present(id, environment(me));
                        if (!ob) ob = find_player(id);
                        if (!ob) ob = find_living(id);
                        if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄÌì¸³¼¼ÄÜ£¿\n");
                } else
                        ob = me;
        } else
                ob = me;

        ab = query("energy", ob);

        learned_energy=query("learned_energy", ob);

        if( arg && ob == me )
        {
                if( !sscanf(arg, "+ %d", a_num) )
                        return notify_fail("Ìá¸ßÌì¸³¼¼ÄÜµÄ¸ñÊ½£ºtalent + Ìì¸³¼¼ÄÜ´úºÅ \n");
                        
                if( a_num < 1 || a_num > 32 )
                        return notify_fail("Ã»ÓĞ´Ë´úÂëµÄÌì¸³¼¼ÄÜ£¨ÇëÊäÈë1-30£©\n");

                if( a_num < 33 )
                {
                        arg1 = talent_ability[a_num-1];
                        level = query("yuanshen_level", ob);
                        
                        if( a_num > (level/10 + 1) * 3 )
                                return notify_fail("ÄãµÄÔªÉñ¾³½ç»¹²»×ãÒÔÕÆÎÕ¸ü¸ßµÄÌì¸³¼¼ÄÜ¡£\n");   
     
                        if( !valid_ability_improve(ob, arg1, 2) )
                                return notify_fail("ÄãµÄÔªÉñ¾³½ç»¹²»×ãÒÔÕÆÎÕ¸ü¸ßµÄ¸ÃÏîÄÜÁ¦¡£\n");
                                
                        if( !do_ability_cost(ob, arg1, 2) )
                                return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÌì¸³µã´¢ĞîÀ´Ìá¸ß´ËÏîÄÜÁ¦¡£\n");
                                
                        improve_ability(ob, arg1, 2);
                        tell_object(ob, "¸ÃµÚ"+ (a_num) + "Ìì¸³¼¼ÄÜÌá¸ßÍê±Ï¡£\n");
                        return 1;
                }

                return 1;
        }

        
        str = ZJOBLONG;
        str +=sprintf(HIY+(ob==me?"Äã":ob->query_idname())+HIY"ÕÆÎÕµÄÌì¸³¼¼ÄÜÈçÏÂ\n"NOR);
        str +=sprintf(HIC    "ĞòºÅ              ¹¦Ğ§                      µÈ¼¶          Éı¼¶µãÊı\n"NOR);
        str +=sprintf(HIG "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n" NOR);

        for(i=0; i<sizeof(talent_ability); i++)
        str+=(sprintf(ZJURL("cmds:talent + %d")+ZJSIZE(25)"¡¾¼Óµã¡¿", (i+1)) + HIC"\n"+ get_ability_info(ob, talent_ability[i], 2) + NOR);
		//str+=(sprintf(ZJURL("cmds:talent + %d")+ZJSIZE(25)"¡¾¼Ó5µã¡¿", (i+5)) + HIC"\n"+ get_ability_info(ob, talent_ability[i], 2) + NOR);
        str +=sprintf("\n");     
     
        str +=sprintf(HIG "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n" NOR);

        str +=sprintf(HIW"ÄãÏÖÔÚ×Ü¹²»ñµÃ "HIC + ab + NOR+HIW" µãÌì¸³µã¡£\n" NOR);
        str +=sprintf(HIW"ÄãÒÑ¾­ÓÃÈ¥ÁË " RED+ learned_energy +NOR+HIW" µãÌì¸³µã£¬»¹Ê£ÏÂ "HIG+ (ab-learned_energy) + NOR+HIW" µã¿É¹©·ÖÅä¡£\n" NOR);

      str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";
	message("vision", str, me);
        return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ :     talent [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

talnet         ÈÃÄãÖªµÀÄãÄ¿Ç°ËùÕÆÎÕµÄÒ»ÇĞÌì¸³¼¼ÄÜ£¬
talent + n     Ìá¸ßµÚ£îÏîÌì¸³¼¼ÄÜµÄµÈ¼¶¡£

ÄÜÁ¦µãÖØÖÃ£º
    Íæ¼Ò¿ÉÒÔÔÚÄàÌ¶ÉÌ³Ç´¦¹ºÂòÁú¾§¿ÉÓÃÀ´ÖØÖÃÒÑ¾­·ÖÅäºÃµÄÌì¸³µã¡£
ÖØÖÃºó£¬ËùÓĞÌì¸³¼¼ÄÜ»¹Ô­ÎªÌì¸³µã¡£µÚÒ»´ÎÖØÖÃÌì¸³»áÏûºÄÒ»¸öÁú
¾§£»Ö®ºóÃ¿ÖØÖÃÒ»´Î£¬»áÔÙ¶îÍâÏûºÄÒ»¸öÁú¾§£»µÚ25´Î¼°Ö®ºóµÄÖØÖÃ
½«²»»áÔÙ¶îÍâÔö¼ÓÏûºÄ£¬¹Ì¶¨Ã¿´Î25¸öÁú¾§¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
    );

        MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
        return 1;
}
