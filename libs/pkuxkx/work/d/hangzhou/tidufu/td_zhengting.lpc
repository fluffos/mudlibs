// Room: /hangzhou/td_zhengting.c
// hubo 2008/4/19

#include <ansi.h>

inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
        set("short", "正厅");
        set("long", @LONG
这里就是杭州提督府的正厅，豪华气派，是提督大人办公的地方，李可秀坐在
公堂之上，几个清兵站立两旁。
LONG);
       
        set("exits", ([     
                "east" : __DIR__"td_dadao2",
                "north" : __DIR__"td_zoulang1",
                "south" : __DIR__"td_zoulang2",
                
]));
    
     set("objects", ([
		"/d/hangzhou/npc/likexiu" : 1,
		"/d/hangzhou/npc/qingbing" : 4,
        ]));     
   setup();
}

void init()
{
        mapping fam;
        object ob;
        if( interactive(ob = this_player()) )
        {
           if( (mapp(fam = ob->query("family"))
                &&  fam["family_name"] == "红花会"
                &&  ob->query_temp("tidufu/xianjing") == 1 ))
                      {
                      	message_vision(HIY"李可秀冷笑着看着$N说：文泰来真是好诱饵呀，又抓到个红花会的探子，推出去砍了！\n"NOR,ob);
                      	
                      	message_vision(HIY"$N高声喊道：清狗，杀了我一个，还有后来人！！！\n"NOR,ob);
                      	
                      	ob->delete_temp("tidufu");
                        ob->delete_temp("last_damage_from");
                        ob->set_temp("death_msg", "被清廷诱捕杀");
                      	ob->die();
                      	return;
                      }
           if( (mapp(fam = ob->query("family"))
                &&  fam["family_name"] != "红花会"
                &&  ob->query_temp("tidufu/xianjing") == 1 ))
                
                     {
                        message_vision(HIY"李可秀盯着$N仔细看看说道：抓错了，不是红花会的，打一顿扔出去！\n"NOR,ob);
                        
                        message_vision(HIY"几个清兵冲上来把$N一顿胖揍：看你还敢进来不！\n"NOR,ob);
                        
                        ob->delete_temp("tidufu");
                        ob->move(__DIR__"tidufu");
                        ob->unconcious();
                        
                        
                        return;
                     }
            else         
             return 0;
        }
}
