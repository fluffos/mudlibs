//wiz_apply

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HBRED "ÉêÇëÎ×Ê¦·¿"NOR);
        set("long", @LONG
[1;35m Ê×ÏÈ£¬Äã±ØĞë¿¼ÂÇÇå³ş£¬³ÉÎªÒ»ÃûÎ×Ê¦´ú±íÄã½«Ô¸Òâ»¨¿ÉÄÜÕ¼È¥Äã´ó
²¿·ÖµÄĞİÏĞÊ±¼äÔÚÄà°ÍÉÏ£¬Èç¹ûÄã²»Ô¸Òâ£¬×îºÃ»¹ÊÇµ±¸öÍæ¼ÒµÄºÃ£¬ÎÒÃÇ
Ä¿Ç°ĞèÒªµÄÊÇÓÅĞãµÄÎ×Ê¦£¬¹²Í¬¿ª·¢ºÃÕâ¸ömudÎÒÃÇµÄĞèÒª
        1. Äã±ØĞëÊÇ¸ö¡¸ÀÏÁ·¡¹µÄÍæ¼Ò.
        2. Äã±ØĞëÑ§¹ı C ÓïÑÔ »ò LPC ÓïÑÔ¡£
        3. ¶ÔÎäÏÀĞ¡ËµÓĞÒ»¶¨µÄÈÏÊ¶¡£
        4. Äã±ØĞëÓĞºÍËûÈËºÏ×÷£¬²¢ÇÒÈİÈÌÅúÆÀºÍ±ğÈËĞŞ¸ÄÄãµÄ×÷Æ·µÄÑÅÁ¿¡£

   ÎÒÃÇ²¢²»´òËã¸øĞÂÎ×Ê¦ÈÎºÎÑ¹Á¦¡£ÔÚÄãÏÂ¶¨¾öĞÄÒª³ÉÎªÒ»ÃûÎ×Ê¦Ö®áá£¬
²¢ÇÒÈÏÎª×Ô¼ºÄÜ¹»Âú×ãÌõ¼şºó,

                ÇëÊäÈëÄúµÄ¡¼ÕæÊµĞÕÃû¡½£º
                ÇëÊäÈëÄúµÄ¡¼Î×Ê¦ĞÕÃû¡½£º
                ÇëÊäÈëÄúÎ×Ê¦µÄ¡¼Ó¢ÎÄĞÕÃû¡½£º
                ÇëÊäÈëÄúµÄ¡¼ĞÔ±ğ¡½£º
                ÇëÊäÈëÄúµÄ¡¼ÄêÁä¡½£º
                ÇëÊäÈëÄúµÄ¡¼e-mailµØÖ·¡½£º

                ÄãµÄÁªÏµµØÖ·ºÍµç»°£¬´«ºô£º
                ÄãµÄµ¥Î»£¨Ñ§Ğ££©£º
                ÄãÊÇ·ñÓĞ×ã¹»µÄÊ±¼äÀ´²ÎÓë±¾MUDµÄ½¨Éè£º
                ÊÇ·ñÊìÏ¤mud£º
                ÄãÊìÏ¤ÄÇ¼¸ÖÖ³ÌĞòÓïÑÔ£¨Èç£ºC,C++,JAVA,LPC £©

     [0;5;1;37m        Çë´ó¼ÒÓÃreturnÕâ¸öÃüÁîÀë¿ªÕâÀï!

LONG);
        set("exits",([]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
        call_other("/clone/board/wizapply_b", "???");
}

void init()
{
        add_action("do_return", "return");
        add_action("do_wizapply","wizapply");
}

int do_return(string arg)
{
        object me = this_player();

        message_vision(HIC"Ö»¼ûÑÛÇ°Ò»Õó"HIR"¿ñ·ç\n"NOR,me);
        message_vision(HIR"¿Õ¼äÒ»Õó×ª±ä£¬$N±»´«ËÍ»ØÀ´µÄµØ·½¡£\n"NOR,me);

        if (me->query("old_place"))     me->move(me->query("old_place"));
        else me->move("/d/city/wumiao");
        message_vision(HIR"¿Õ¼äÒ»Õó×ª±ä£¬$N±»´«ËÍµ½ÁËÁíÒ»¸ö¹ú¶È¡£\n"NOR,me);
        me->delete("old_place");
        return 1;
}

int do_wizapply(string arg)
{
        write("ÄãÒÑ¾­ÔÚÕâÀï¾Í²»±ØÔÙÓÃwizapplyÁË¡£\n");
        return 1;
}
