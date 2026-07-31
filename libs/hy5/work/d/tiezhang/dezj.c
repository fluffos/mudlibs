// Room: /u/zqb/tiezhang/dezj.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "[32mµÚ¶şÖ¸½Ú[0;37;0m");
	set("long", @LONG
    ÕâÀïÒÑµ½ÁËÖĞÖ¸·åµÄ°ëÉ½ÑüÁË£¬ÓÉÓÚÌúÕÆÉ½ÅÅÁĞµÃÏóÊÖÖ¸Ò»Ñù£¬ 
Ã¿×ùÉ½·åÓÖ·ÖÈı½Ø£¬¾ÍÈçÊÖÖ¸µÄÖ¸½ÚÒ»°ã£¬Òò´ËÕâÀïÕıÊÇÎ»ÓÚµÚ¶şÖ¸½ÚµÄ
Î»ÖÃ¡£ÕâÀïÀë·å¶¥ÒÑ½ü£¬Í¸¹ıµ­µ­µÄÔÆÎí£¬ËÆÒÑ¿ÉÒÔ¿´µ½É½Â·µÄ¾¡Í·ÁË¡£
×óÇ°·½¶şÊ®ÓÚÕÉ´¦£¬ºÚ÷î÷îµÄËÆÓĞÒ»¸ö¶´Ñ¨(dong)£¬¶´¿ÚÆöÒÔÓñÊ¯£¬ĞŞ½¨
µÃ¼«ÊÇÆëÕû¡£
LONG	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sslin-5",
  "northup" : __DIR__"shanlu-8",
  "enter" : __DIR__"dong-1",
]));
     set("objects", ([
     __DIR__"npc/mayi" : 2,
    ]));
    set("item_desc", ([ 
  "dong" : "Ò»¸öºÚ÷î÷îµÄÉ½¶´¡£ºÚ°µÖĞÅ¼¶ûÓĞ¼¸µãÁ×¹âÉÁ¹ı£¬ºÃÏÅÈË£¡£¡£¡\n",
]));
	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	setup();
      //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	
	
	if (dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
	   return notify_fail("ÂéÒÂ³¤ÀÏºÈµÀ£º´ËÄËÌúÕÆ°ï½ûµØ£¬ÈÎºÎÈË²»µÃÈëÄÚ£¬·ñÔòÓĞËÀÎŞÉú£¡£¡\n");
		
        return ::valid_leave(me, dir);
}
