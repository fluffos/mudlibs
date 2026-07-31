 // dadian.c 礼佛大殿

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","礼佛大殿");
        set("long",@LONG 
这里是雪山大轮寺大殿，虽然是远在雪山，但大殿气势确在中原也难得一
见。正面矗立一座数十尺高的金身大佛，大殿内烟雾缭绕几个喇嘛正在念佛颂
经，另外还有喇嘛有节奏的敲打法器。大殿中央有一盏长明灯，一般来此朝奉
的人都要先在此供奉(gongfeng)酥油。殿两侧是遮雨廊。绕过大佛，可以走到
却日殿去。
LONG);
        set("exits",([
                "north": __DIR__"queridian",
                "southdown":__DIR__"guangchang",
                "westdown" : __DIR__"huilang3",
                "eastdown": __DIR__"huilang4",
        ]));
        set("objects", ([
         CLASS_D("xueshan") + "/lingzhi" : 1,
         __DIR__"npc/xiangke" : 2,
        ]));
        setup(); 
}
void init() 
{ 
         add_action("do_gongfeng", "gongfeng");
}
 
int do_gongfeng()
{
          object ob, me;
          mapping fam; 
          int i, j,z;
        
          me = this_player(); 
           fam = me->query("family"); 
                   i = (int)me->query("age");  
                   j = (int)me->query("xs_gf");
                  z  = (int)me->query("xs_number");

          if( !(ob=present("su you", me)) )
           return notify_fail("你需要有酥油才能在此供奉。\n"); 

                if (fam && fam["family_name"] == "大轮寺"){
                if ( (int)me->query_skill("huanxi-chan", 1) < 90 ){
                            if (i != j && z <12){
                 me->add("xs_number",1);
                destruct(ob);
                message_vision("$N口中低声诵读密宗真言，从怀中拿出一壶酥油，浇进了长明灯里，火苗更加旺了！\n", me);
                return 1;
                }
                             if ((z ==12)&&(i==j)){
                             me->add("gf_ok",1); 
			     me->set("xs_gf",i);	
                             me->delete("xs_number");
                message_vision("$N口中低声诵读密宗真言，从怀中拿出一壶酥油，浇进了长明灯里，火苗更加旺了！\n", me);
                            write("你心中默默一算，今年的供奉已经齐了！\n", me);
                            destruct(ob);
                return 1;
                }
                            if( (j != i) && (z == 12 ) ){
                            message_vision("$N口中低声诵读密宗真言，从怀中拿出一壶酥油，浇进了长明灯里，火苗更加旺了！\n", me);
                            write("你心中默默一算，今年的供奉早已经齐了！\n", me);
                             me->add("gf_ok",1); 
			     me->set("xs_gf",i);	
                             me->delete("xs_number");
                        destruct(ob);
                return 1;
                }
                            }
                else
                message_vision("$N从怀中拿起一壶酥油，浇进了长明灯里，火苗更加旺了，然后满意的笑了笑！\n", me);
                destruct(ob);
                return 1;
                }  
                message_vision("$N从怀中拿起一壶酥油，浇进了长明灯里，火苗更加旺了！\n", me);
                destruct(ob);
	             return 1;
}
