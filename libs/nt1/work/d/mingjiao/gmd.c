// gmd.c  ¹âÃ÷¶¥
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"¹âÃ÷¶¥"NOR);
       set("long", @LONG
ÕâÀï¾ÍÊÇÃ÷½Ì¹âÃ÷¶¥¡£Äã×ßµ½ÕâÀï¾Í¿É¿´¼ûÈı¸öÏÊºìÉ«´ó×Ö¡£Ã÷½Ì£¬
ÉÙÁÖ£¬Ø¤°ïÖĞÃ÷½ÌÊÇ×î´óµÄ½Ì£¬ÉÙÁÖÊÇ×î´óµÄÃÅÅÉ£¬¶øØ¤°ïÔòÊÇ×î´ó°ïÅÉ¡£
Ã÷½Ì×ÔÓÉ²¨Ë¹×Ü½Ì´«ÖÁÖĞÔ­ÒÑÓĞ°Ù¶àÄêµÄÀúÊ·ÁË¡£Ã÷½ÌÊ¼ÖÕ¶¼ÒÔ·´Ôª¿¹ºú£¬
ĞĞÉÆÈ¥¶ñ¼°³ı±©°²Á¼Îª×ÔÒÑµÄ×ÚÖ¼¡£µ«ÓÉÓÚÃ÷½ÌÌ«´ó£¬ÃÅÏÂ½ÌÖÚÄÑÃâİ¹İ¬
²»Æë£¬ÖÁÊ¹±»ÃûÃÅÕıÅÉ³ÆÎªÄ§½Ì¡£ÕıÖĞÑëÒ»ÃæºìÉ«»ğÑæµÄ´óÆì¡£±±±ßÊÇÁ·
Îä³¡£¬ÄÏ±ßÊÇ¾ŞÄ¾ÆìµÄËùÔÚµØ¡£[1£»31m¹âÃ÷¶¥[2£»37£»0m
LONG );
	set("exits", ([
		"northup" : __DIR__"wu3",
		"southdown" : __DIR__"muqi",			
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/yin" : 1,
                CLASS_D("mingjiao") + "/wulu" : 1,
                __DIR__"npc/m-dizi" : 2,
	]));
        set("outdoors", "mingjiao");
        set("valid_startroom", 1);
        set("coor/x",-290);
  set("coor/y",170);
   set("coor/z",110);
   set("coor/x",-290);
 set("coor/y",170);
   set("coor/z",110);
   setup();        
        call_other("/clone/board/mingjiao_b","???");
}
