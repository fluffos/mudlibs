inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "ÈýÇåºþ");
        set("long",
"[1;32mºþË®Çå³ºÍ¸Ã÷£¬²»Ê±¿ÉÒÔ¿´µ½¼¸Î²ÓãÌøÉÏË®Ãæ¡£ºþË®¾¡Í·ÊÇ\n"
"Ò»¸ö´óÆÙ²¼¡£ÔÚÕâÀï¿ÉÒÔÌýµ½ÆÙ²¼´ÓÉ½ÉÏÖ±³å¶øÏÂ£¬·¢³öµÄºäºäÀ×Éù¡£ºþ\n"
"±ßÒ»¿é¾ÞÊ¯£¬ÉÏÐ´£¢ÈýÇåºþ£¢¡£ÕâÀï·ç·Ç³£´ó£¬´µµÃÈËµÃÒÂÉÀÁÔÁÔ×öÏì¡£\n"
);
   set("exits", ([ 
      "northeast" : __DIR__"lake1",
   ]));

        set("no_magic", 1);
	setup();
}

void kite_notify(object obj, int i)
{
   object  me, room;
   int j;
        
   me = this_player();
   message_vision("Í»È»Ò»ÕóÎ¢·ç·÷¹ý"+obj->name()+"»º»ºµÄÉýÁËÆðÀ´£¬Ô½À´Ô½¸ß¡£\n\n" , me);
   switch( random(2) ) {
   case 0:
      tell_object(me, me->name()+"ÊÖÖÐµÄ"+obj->name()+"Ô½·ÉÔ½¸ß¡£ \n");
      message_vision("Ö»ÌýÒ»ÕóÇåÔÃµÄÉÚÒô´Ó¸ß¿Õ´«¹ý£¡ \n", me);
      call_out("boat_come", 2, me);
   break;
   case 1:
      message_vision("Ò»Õó¾¢·ç´µ¹ý£¬$NÊÖÖÐµÄÏß¶ÏÁË£¬"+obj->name() 
+"Ô½À´Ô½¸ß£¬ÂýÂýµÄ²»¼ûÁË¡£ \n",me);
      destruct(obj);
      break;
   }
   return; 
}

void boat_come(object me)
{
   object  boat, *inv, ob;
   int i;
        

   if (query("exits/down")) return ;
   if (!objectp(boat=find_object(__DIR__"boat")))
      boat=load_object("/u/night/room/boat");
   inv=all_inventory(boat);
   for(i=0; i<sizeof(inv); i++) {
      ob = inv[i];
      if(living(ob)){
         message("vision","°ëÉÎ£¬ºþÉÏ»¹ÊÇÃ»ÓÐË¿ºÁ¶¯¾²¡£\n",this_object()); 
         return;
      }
   }
   message("vision","¹ýÁË°ëÉÎ£¬Ò»Ò¶Ð¡ÖÛ»º»ºµØ´ÓÎíÖÐµ´³ö£¬¿¿µ½ÁËºþ±ß¡£\n",this_object()); 
    boat->set("exits/up",__DIR__"lake2");
  set("exits/down",__DIR__"boat");
   call_out("boat_leave",10,boat);
   return ;
}

void boat_leave(object boat)
{
        if (query("exits/down")) delete("exits/down");
        if (boat->query("exits/up")) boat->delete("exits/up");
        message("vision","Ò»ÕóÎ¢·ç·÷¹ý£¬Ð¡´¬µ´ÀëÁË°¶±ß¡£\n",this_object()); 
        message("vision","Ò»ÕóÎ¢·ç·÷¹ý£¬Ð¡´¬µ´ÀëÁË°¶±ß¡£\n",boat); 
        return;
}

int valid_leave(object me, string dir)
{
   object *inv, boat, ob;
   int i;

   if (userp(me) && dir == "down") {
      boat=find_object(__DIR__"boat");
      if (!objectp(boat))
         boat=load_object(__DIR__"boat");
         inv=all_inventory(boat);
            for(i=0; i<sizeof(inv); i++) {
               ob = inv[i];
               if(living(ob)){
                  tell_object(me, "´¬Ì«Ð¡ÁË£¬Ö»ÄÜ³Ë×øÒ»¸öÈË¡£\n");      
                  return notify_fail("");
               }
           }
   }
   return 1;
}

