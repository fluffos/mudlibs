//by kiden@pkuxkx

inherit ROOM;
#include <room.h>
#include <ansi.h>
#include <title.h>
void create ()
{
  set ("short", HIW+"昆仑之颠"+NOR);
  set ("long", @LONG
                                  
                                  !
                                 /^\
                               /     \
                |           | (       ) |           |
               /^\ |       /^\ \     / /^\       | /^\
               |O|/^\     (   )|-----|(   )     /^\|O|
               |_||-| |^-^|---||-----||---|^-^| |-||_|
               |O||O| |/^\|/^\||  |  ||/^\|/^\| |O||O|
               |-||-| ||_|||_||| /^\ |||_|||_|| |-||-|
               |O||O| |/^\|/^\||(   )||/^\|/^\| |O||O|
               |-||-| ||_|||_||||   ||||_|||_|| |-||-|
                   飞雪连天射白鹿   笑书神侠倚碧鸳

LONG);

  set("exits", ([ /* sizeof() == 3 */
      "down" : "/d/city/guangchang",
      ]));
     set("objects", ([

//             __DIR__"jinyong/npc/jinyong" : 1,
      ]));
     set("no_die", 1); 
     set("no_clean_up", 1);
   setup();
}

void init()
{
        object xian;
            if(userp(this_player()))                                                                 
        {                                                                                        
          if(this_player()->query("reborn/all") )                                                   
                  return;                                                                        
           else                                                                                   
           {                                                                                      
          if((int)this_player()->query("reborn/stage_20")==1 &&
             (int)this_player()->query("reborn/stage_19")==1 &&
             (int)this_player()->query("reborn/stage_18")==1 &&
             (int)this_player()->query("reborn/stage_17")==1 && 
             (int)this_player()->query("reborn/stage_16")==1 &&
             (int)this_player()->query("reborn/stage_15")==1 &&
             (int)this_player()->query("reborn/stage_14")==1 &&
             (int)this_player()->query("reborn/stage_13")==1 &&
             (int)this_player()->query("reborn/stage_12")==1 &&
             (int)this_player()->query("reborn/stage_11")==1 &&
             (int)this_player()->query("reborn/stage_10")==1 &&
             (int)this_player()->query("reborn/stage_9")==1 &&
             (int)this_player()->query("reborn/stage_8")==1 &&
             (int)this_player()->query("reborn/stage_7")==1 &&
             (int)this_player()->query("reborn/stage_6")==1 &&
             (int)this_player()->query("reborn/stage_5")==1 &&
             (int)this_player()->query("reborn/stage_4")==1 &&
             (int)this_player()->query("reborn/stage_3")==1 &&
             (int)this_player()->query("reborn/stage_2")==1 &&
             (int)this_player()->query("reborn/stage_1")==1   )                                            
            {         

                   this_player()->set("reborn/all",1);                                              
                   this_player()->set("grandmaster",1);
                   if (!wizardp(this_player()))
                   {
                       CHANNEL_D->do_channel(this_object(), "jh", "金庸(Jin yong):"+this_player()->name()+ "经历磨难终于到达昆仑之颠！", -1); 
                   }
                   
                   this_player()->add("combat_exp", 1000000);                                    
                   this_player()->add("potential", 500000);
                   this_player()->add("str",3);
                   this_player()->add("con",3);
                   this_player()->add("int",3);
                   this_player()->add("dex",3);                                      
                   this_player()->add("per",3);
                   this_player()->add("spi",3);
                   this_player()->add("kar",3);
				   this_player()->set("biography/jienan",time());//个人传记记录过劫难时间ZINE
                   this_player()->set("job_title",HIY"武学大宗师"NOR);
//title系统记录玩家title by seagate@pkuxkx
	                 this_player()->set_title(TITLE_GRANDM, HIY"武学大宗师"NOR);
                   tell_object(this_player(),"你得到了一百万经验值和五十万潜能的奖励！\n");
                   tell_object(this_player(),"你的各项先天属性增加了三点！\n");
                   xian=load_object("/d/city/npc/xian");
                   if (xian) //加个广告
                   {
                       xian->adv_tell(this_player());
                   }
                   xian=load_object("/d/luoyang/npc/du");
                    if (xian) //加个广告
                   {
                       xian->adv_tell(this_player());
                   }
            }
            }
          }
}  
