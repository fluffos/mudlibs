// lookwall.h
// By haiyan

#include <ansi.h>

int do_look(string arg);
int do_look(string arg)
{
     object me = this_player();
     int cost;

     if( !arg || arg != "shibi" )   return 0;

     write("\n∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　侠客行　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　赵客缦胡缨，吴钩霜雪明。银鞍照白马，飒沓如流星。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　十步杀一人，千里不留行，事了拂衣去，深藏身与名。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　闲过信陵饮，脱剑膝前横。将炙啖朱亥，持觞劝侯嬴。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　三杯吐然诺，五岳倒为轻。眼花耳热后，意气素霓生。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　救赵挥金锤，邯郸先震惊，千秋二壮士，烜赫大梁城。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷　纵死侠骨香，不惭世上英，谁能书阁下，白首太玄经。　∷∷∷\n");
     write("∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n");
     write("∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n\n");
     write("    下方刻着一幅图，图中是一个书生，他左手持扇，右手飞掌，神\n");
     write("态甚是优雅潇洒……旁有一行注解云：须从威猛刚硬处着手。另有无\n");
     write("数小字，密密麻麻。\n\n");

     if(me->query("taixuan"))    return 1;

     if(! me->query_temp("xiakedao/think"))    return 1;

     if ((int)me->query_skill("literate", 1) > 100)
     {
           write("你摇头晃脑地读着石壁上的诗句：“赵客缦胡缨，吴钩霜雪明……”。\n\n");
           write(HIY"你读了一会，哼哼道：“这首诗写得也太普通了，还没我自己写得好。”\n"NOR);
           return 1;
     }

     if ( ! ultrap(me) )
     {
           write("你默默念诵着石壁上的诗句：“银鞍照白马，飒沓如流星……”。\n\n");
           write(HIY"你默诵了一会，觉得自己对武学的研究太过肤浅，一时之间难以领会其中奥妙。\n"NOR);
           return 1;
     }

     cost = me->query("int") - 20;
     if (cost < 2)  cost = 2;
     if (cost > 8)  cost = 8;

     if (random(cost) == 0)
     {
           me->set("taixuan", "force");
           write("你默默念诵着石壁上的诗句：“三杯吐言诺……"
                 "意气素霓生……喧赫大梁城……”。\n\n");
           write(HIY"你又将石壁上的图案仔细看了看，似乎觉得图案中包含"
                 "着一套高深的武功，却又一时说不上来。\n只觉一股真气在"
                 "全身经脉缓缓流动。\n"NOR);
     }  else
     {
           switch(random(3))
           {
                case 0:
                     me->set("taixuan", "sword");
                     write("你默默念诵着石壁上的诗句：“十步"
                           "杀一人……脱剑膝前横……救赵挥金锤……”。\n\n");
                     write(HIY"你又将石壁上的图案仔细看了看，似乎觉得图案中包含"
                           "着一套高深的武功，却又一时说不上来。\n"
                           "只觉手指微颤，似乎急欲寻一把剑来挥舞一番。\n"NOR);
                     break;
                case 1:
                     me->set("taixuan", "dodge");
                     write("你默默念诵着石壁上的诗句：“千里"
                           "不留行……事了拂衣去……深藏身与名……”。\n\n");
                     write(HIY"你又将石壁上的图案仔细看了看，似乎觉得图案中包含"
                           "着一套高深的武功，却又一时说不上来。\n"
                           "只觉全身似乎变轻许多。\n"NOR);
                     break;
                case 2:
                     me->set("taixuan", "unarmed");
                     write("你默默念诵着石壁上的诗句：“闲过"
                           "信陵饮……五岳倒为轻……纵死侠骨香……”。\n\n");
                     write(HIY"你又将石壁上的图案仔细看了看，似乎觉得图案中包含"
                           "着一套高深的武功，却又一时说不上来。\n"
                           "只觉全身关节一阵“噼噼叭叭”暴响。\n"NOR);
                     break;
           }
    }
    return 1;
}

