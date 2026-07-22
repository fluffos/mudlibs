// Room: /d/hainan/cave3
inherit ROOM;

void create ()
{
  set ("short", "Âä±Ê¶´");
  set ("long", @LONG
ÑÛÇ°µÄµØĞÎÍ»È»¿ªÀ«ÆğÀ´,ÄãÖ±ÆğÑü,·¢ÏÖ×Ô¼ºÔÚÒ»¸öÊıÕÉ¸ßµÄÉ½¶´
ÖĞ,ÑÒ±Ú´¹Ö±,Ê¯ºÚ·¢ÁÁ,´Ó¶´¶¥´¹ÏÂÁ½ÌõÊ¯Í·,ĞÎ×´¿áËÆ´óºÅÃ«±Ê,´Ó±Ê¶Ë
²»¶ÏÓĞ[33mÈªË®[37mÉø¶øÂ©ÏÂ.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "ÈªË®" : "¿´²»µ½Ë®µÄÔ´Í·,ËÆºõÖ±½Ó´ÓÊ¯±ÊÖĞÉø³öÀ´,¿´À´Ê®·ÖÇå³º,²»·Á
ºÈ¼¸¿Ú(drink water)
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cave1",
  "northdown" : __DIR__"cave4",
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if (sss!="water") 
   return 0;
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"Äã±¥ÕÇµÄ¶Ç×Ó²»ÔÊĞíÄãÕâÃ´×ö£¡\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"´Õµ½±Ê¶ËÇ°,ºÈÁË¼¸¿ÚÉ½Èª. \n");
 tell_object(ob,"ÄãÅõÆğÉ½Èª,ÃÀÃÀµÃºÈÁËÁ½¿Ú,ÕæÌğÄÄ.... \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

 }
