// SN:>:W]N<nRFc@GNYn:
// File(/data/room/xiaodongxi/tingtao.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ÌýÌÎ¸ó");
	set ("long", @LONG
´©¹ýÏôÏôµÄÖñÁÖÉî´¦¾ÍÀ´µ½ÁËÌýÌÎ¸ó¡£ÔÚÕâÀï·ç·÷ÖñÒ¶µÄÕóÕóÌÎ
ÉùÌýµÄ·Ç³£ÕæÇÐ£¬ÁîÈËÐÄÐØ¿ªÀ«£¬ÐÄ¿õÉñâù£¬ÊÇ²ÎÎòÎä¹¦µÄºÃËùÔÚ¡£
Ã¿µ±ÔÂÔ²Ö®Ê±£¬Ð¡Ì«±£±ã»áÀ´´ËÍÂ¹ÊÄÉÐÂ£¬ÎüÈ¡ÌìµØÖ®¾«»ª£¬ÐÞÁ¶·¨
Á¦¡£[2;37;0m
LONG );

	set("exits", ([
                "west" : __DIR__"zhulin",
	]));

        set("sleep_room", 1);
        setup();

        set("research_improve", 15);  //15% improved
    
        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}
