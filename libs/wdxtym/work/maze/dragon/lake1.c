inherit ROOM; 
#include <ansi.h> 
void create()
{
    set("short", "ÈýÇåºþ");
    set("long",
"[1;32mºþË®Çå³ºÍ¸Ã÷£¬²»Ê±¿ÉÒÔ¿´µ½¼¸Î²ÓãÌøÉÏË®Ãæ¡£ºþË®¾¡Í·ÊÇ\n"
"Ò»¸ö´óÆÙ²¼¡£ÔÚÕâÀï¿ÉÒÔÌýµ½ÆÙ²¼´ÓÉ½ÉÏÖ±³å¶øÏÂ£¬·¢³öµÄºäºäÀ×Éù¡£ºþ\n"
"±ßÒ»¿é¾ÞÊ¯£¬ÉÏÐ´£¢ÈýÇåºþ£¢¡£[2;37;0m\n"
);
    set("item_desc", ([
	"ÇåÌ¶":  "ÇåÌ¶Ã÷³º¼ûµ×£¬ÀïÃæÐ¡ÓãÐ¡Ïº½ÔÈô¿ÕÓÎÎÞËùÒÀ¡£\n",
	"pond":  "ÇåÌ¶Ã÷³º¼ûµ×£¬ÀïÃæÐ¡ÓãÐ¡Ïº½ÔÈô¿ÕÓÎÎÞËùÒÀ¡£\n",
      ]));
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"taolin", 
	"northwest" : __DIR__"pond", 
	"southwest" : __DIR__"lake2", 
	"west" : __DIR__"lake",
      ]));
}

void fish_notify(object obj, int i)
{
    object me, room, fish, *inv, bait;

    me = this_player();

    switch (i) { 
    case 0:
	bait = present("qiu yin", obj);
	if(!objectp(bait)) {
	    message("vision",me->name() + "ÌÍ³öÁË" + obj->name() + "ÓÖ·ÅÁË»ØÈ¥¡£\n", environment(me), me);
	    tell_object(me, obj->name() + "ÉÏÃ»ÓÐ¶üÔõÃ´¿ÉÒÔµöÓãÄØ£¿ \n");
	}
	else {
	    message_vision("$N»Ó¶¯ÁËÒ»ÏÂ£¬" + obj->name() + "ÔÚ¿ÕÖÐ»®ÁËÒ»µÀÆ¯ÁÁµÄ»¡Ïß£¬Óã¹³ÂäÈëÁËË®ÖÐ¡£ \n" , me);
	    destruct(bait);
	    remove_call_out("do_fishing");              
	    call_out("do_fishing", 5, me);
	}
	break;
    }
    return;
}

void do_fishing(object me)
{
    object       fish;

    if(me && environment(me) == this_object()) {
	message_vision("$NºÜ¿ìÓÖ³¶¶¯ÁËÒ»ÏÂÓã¸Ë£¬ " , me);
	switch (random(3)) {
	case 0:
	    message_vision("È´Ê²Ã´¶¼Ã»µöÉÏÀ´£¡ \n", me);
	    break;
	case 1:
	    message_vision("Óã¹Ö±»µöÉÏÀ´À²£¡£¡£¡£¡ \n", me); 
	    fish = new("/quest/tulong/obj/fish1");
	    me->set_temp("m_success/Óã¹Ö",1);
	    fish->move(environment(me));
	    remove_call_out("kill_me");
	    call_out("kill_me", 1, me);         break;
	case 2:
	    message_vision("Óã¹³ÉÏµö×ÅÒ»Ìõ´óÓã£¡£¡ \n", me);
	    fish = new("/quest/tulong/obj/fish");
	    fish->move(me);
	    break;
	}
    }
    return;
}

