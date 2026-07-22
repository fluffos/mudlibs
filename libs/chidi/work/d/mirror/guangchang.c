// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "ÖĞÑë¹ã³¡");
    set("long", @LONG
    ÕâÀïÊÇ³ÇÊĞµÄÕıÖĞĞÄ£¬Ò»¸öºÜ¿íÀ«µÄ¹ã³¡£¬ÆÌ×ÅÇàÊ¯µØÃæ¡£Ò»Ğ©ÓÎÊÖºÃÏĞ
µÄÈËÔÚÕâÀïÁïÁï´ï´ï£¬¾­³£ÓĞÒÕÈËÔÚÕâÀï±íÑİ¡£ÖĞÑëÓĞÒ»¿Ã´óéÅÊ÷£¬ÅÌ¸ù´í½Ú£¬¾İ
´«ÒÑÓĞÇ§ÄêµÄÊ÷Áä£¬ÊÇÕâ×ù³ÇÊĞµÄÀúÊ·¼ûÖ¤¡£Ê÷¸Éµ×²¿ÓĞÒ»¸öºÜ´óµÄ¶´(shudong)¡£
Äã¿ÉÒÔ¿´µ½±±±ßÓĞÀ´×Ô¸÷µØµÄĞĞÈËÀ´À´ÍùÍù£¬ÄÏÃæÈËÉù¶¦·Ğ£¬Ò»ÅÉ·±»ª¾°Ïó£¬¶«±ß
²»Ê±µØ´«À´ÀÊÀÊµÄ¶ÁÊéÉù£¬Î÷±ßÔò¼û²»µ½¼¸¸öĞĞÈË£¬Ò»Æ¬Ëà¾²¡£´óÊ÷ÉÏ¹ÒÒ»¿é´óÅÆ

                        ¡¡[1;33m£Î£Ï£Ô£É£Ã£Å[2;37;0m

LONG
    );
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "ÕâÊÇÒ»¸öºÚ²»ÁïäĞµÄ´ó¶´£¬ÀïÃæ²»ÖªµÀÓĞĞ©Ê²Ã´¹Å¹Ö¡£\n",
        "éÅÊ÷"  :   "Ò»¿ÃÖ¦Ò¶Ã¯Ê¢µÄ´óéÅÊ÷£¬¿´À´ËÆºõ¿ÉÒÔÅÀ(climb)ÉÏÈ¥¡£\n",
        "´óéÅÊ÷":   "Ò»¿ÃÖ¦Ò¶Ã¯Ê¢µÄ´óéÅÊ÷£¬¿´À´ËÆºõ¿ÉÒÔÅÀ(climb)ÉÏÈ¥¡£\n",
        "Ê÷"    :   "Ò»¿ÃÖ¦Ò¶Ã¯Ê¢µÄ´óéÅÊ÷£¬¿´À´ËÆºõ¿ÉÒÔÅÀ(climb)ÉÏÈ¥¡£\n",
        "tree"  :   "Ò»¿ÃÖ¦Ò¶Ã¯Ê¢µÄ´óéÅÊ÷£¬¿´À´ËÆºõ¿ÉÒÔÅÀ(climb)ÉÏÈ¥¡£\n",
    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
	"down" : __DIR__"drop",
    ]));
    setup();
}

void init()
{
        add_action("do_climb", "climb");
}
  
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if( !arg || arg!="up") return notify_fail("ÄãÒªÍùÄÄ¸ö·½ÏòÅÀ£¿\n");

    if (me->query("gender")!="Å®ĞÔ")
    message("vision",
        me->name() + "Õ½Õ½¾¤¾¤µØÀ­×Å´óéÅÊ÷µÄÅÌ¸ù£¬Æ¨¹ÉÒ»Å¤Ò»Å¤µØÍùÉÏÅÀ¡£\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "ÇáÇáÒ»Ìø£¬ÒÂÈ¹Æ®Æ®£¬ÏóÏÉ×Ó°ã·ÉÉÏ´óéÅÊ÷¡£\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "Õ½Õ½¾¤¾¤µÄ×¥×¡Ê÷¸ÉÍùÉÏÅÀÈ¥¡£\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="Å®ĞÔ")
        message("vision",
        me->name() + "Æø´­ĞêĞêµØÅÀÁËÉÏÀ´¡£\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","Ò»ÕóÇåÏã·ÉÀ´£¬Äã¶¨ÑÛÒ»¿´£¬"+
        me->name() + "ÒÑ¾­æÃæÃÓñÁ¢ÔÚÄãÑÛÇ°¡£\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "Õ½Õ½¾¤¾¤µØ´ÓÏÂÃæÅÀÁËÉÏÀ´¡£\n", environment(me), ({me}) );   
    return 1;
}
//ÊÇ¾µÏñ
int is_mirror() { return 1; }
