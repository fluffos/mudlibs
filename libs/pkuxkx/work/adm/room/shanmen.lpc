//Made by goodtaste
//wanluntai.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", BLU"山门"NOR);
        set("long", "杀手帮大门，门上有三个大字:"+RED"\n\n\n\t\t杀    手     帮"NOR+"\n\n \n    由此再往北就是江湖上最神秘的门派杀手帮的所在地了
"
        );
       
       
        set("outdoors", "pker");
        set("exits", ([
                "south" : "/d/pker/shanlu1",
                "north" : "/d/pker/wanluntai",
                ]));
          set("objects", ([
         
                   "/d/pker/npc/dizi" : 4,
           ]));
   setup();
       // replace_program(ROOM);
}

void init()
{
   int count1;
   string count2;

   object me,ob;
   count2 = read_file("/kungfu/class/pker/COUNT", 1, 1);
   count1 = atoi(count2);
   ob=this_object();
   me=this_player();
  
   count1=count1+1;
   if(count1>=50000)
{
   count1=0;
   message("vision",HIR"世事沧桑，脚下的这片土地上留下过多少武林前辈的鲜血与荣耀！如今，你，新的一代!\n"NOR,me);
}
   remove_call_out("msg");
   call_out("msg",1,me,ob,count1);
  
   
}

int msg(object me,object ob,int count1)
{  
  
  
if(me->query_temp("xia"))
       {
        
      
       
        message("vision",HIR"天下争雄瞩我辈，一入江湖岁月摧."NOR+HIY"你是第"NOR+(string)count1+HIY"位踏入此地的英雄!\n"NOR,me);
        me->delete_temp("xia");
       seteuid(ROOT_UID);
        
        write_file("/kungfu/class/pker/COUNT","0"+count1,1);
        
       }
     return 1;
}
   


