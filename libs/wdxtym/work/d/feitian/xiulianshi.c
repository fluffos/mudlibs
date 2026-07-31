//shushan2 by yushu@SHXY 2001.2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;31mÐÞÁ·ÊÒ[2;37;0m");
  set ("long", @LONG
ÕâÀïÊÇÉñ¹Å»îÐÄÁ÷ÐÞÁ·ÊÒ£¬ÓÃÀ´Á·Ï°»îÐÄÁ÷×î¸ß½£¾öËùÓÃ£¬Ç½ÉÏÃæ¹ÒÁË¼¸
°ÑÖñ½£,Äã¿ÉÒÔÈ¡Ò»°Ñ(lianxi)Á·Ï°¡£ÍùÓÒ×ßÊÇ¼äÐÝÏ¢ÊÒÓÃÀ´¸øµÜ×ÓÐÝÏ¢Ö®ÓÃ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianting",
  "east" : __DIR__"xiuxishi",
]));
  set("outdoors", 2);

  setup();
//  replace_program(ROOM);
}

void init()
{
        add_action("do_lianxi", "lianxi");
}

int do_lianxi()
{
    object me=this_player();
          if(me->is_busy() )
          return notify_fail("ÄãÏÖÔÚÃ¦×ÅÄØ£¬ÈçºÎÁ·Ï°...\n");

        if((int)me->query_skill("parry",1)<120 )
               return notify_fail("ÄãÕÐ¼ÜÌ«µÍ£¬ÎÞ·¨Á·Ï°¡£\n");
   
        if(me->query("family/family_name") != "·ÉÌìÓù½£Á÷")
        {
        tell_object(me,"Äã²»ÊÇ·ÉÌìÓù½£Á÷µÄ£¬ÔÚÕâÀï½ÁºÍ¸öÊ²Ã´¡£\n"); 
        return 1;
        }
        if(me->query("qi") < 100)
        {
        tell_object(me,"Äã»¹ÊÇÏÈÐÝÏ¢Ò»»á¶ù°É¡£\n");     
        return 1;
        }
        message_vision("$N°´ÕÕÊ¦¸µËùÖ¸Ë«ÊÖÐéÎÕ,ÓÃÁ¦ÏòÏÂ»ÓÎè£¬Á·Ï°×î»ù±¾µÄÎÕ½£·½·¨¡£\n", me);
        me->add("qi",-10);
        me->start_busy(1);
        if(me->query("feitian/chaodao")) 
        {
        tell_object(me,"ÄãËÆºõ²»ÄÜÔÚÕâÀïÁ·Ï°µ½Ê²Ã´ÁË¡£\n");       
        return 1;
        }
        if((int)me->query_skill("huoxinliu-jianfa", 1) > 120){
        tell_object(me,HIW"Äã·´¸´Á·Ï°ÐÄÀïÒþÔ¼¶Ô[³­µ¶]ÓÐÁËÐ©Ìå»á£¡\n"NOR);
        me->add("feitian/lianxi",1);
        me->start_busy(1);
        }
        if(me->query("feitian/lianxi",1) > 200)
        {
        me->set("feitian/chaodao",1);
        tell_object(me,HIG"Äã·´¸´Á·Ï°ÖÕÓÚÌå»áµ½ËÙ¶È¸úÑÛÁ¦µÄÖØÒªÁË£¬¾õµÃ¿ÉÒÔÊ¹ÓÃ[³­µ¶]ÁË\n"NOR);
        me->delete("feitian/lianxi");
        }
        return 1;
}             
