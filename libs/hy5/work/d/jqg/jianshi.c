// jianshi.c 剑室
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
string look_zhuo();
void create()
{
            set("short", HIW"剑室"NOR);
            set("long",@LONG
这里是剑室，只见室中壁上、桌上、架上、柜中。几间，尽皆列满兵刃，
式样繁多，十之八九都是古剑，或长逾七尺，或短仅数寸，有的铁口斑驳，有
的寒光逼人。却见屋角西壁间一大片火烧的焦痕，几张桌椅也均烧得残破。
LONG
    );
            set("item_desc", ([ 
                 "桌椅" : (: look_zhuo :),
                 "zhuoyi" : (: look_zhuo :),
                 "屋角":(: look_zhuo :),
                 "wujiao":(: look_zhuo :),
            ]));


            set("exits",([
                "south": __DIR__"lang5",
            ]));                         

            setup();
}

string look_zhuo()
{
         this_player()->set_temp("jqg/sword",1 );
         if (this_player()->is_busy())
          return "你正忙着呢。\n";

         this_player()->start_busy(2);
          return "你只见屋角里半截画幅之下露出两段剑鞘(sword)来。\n";
}

void init()
{
         object me=this_player();
         if (!me->query_temp("jqg/enter")){
         if ( me->query_skill("dodge",1) < 120){
         tell_object(me,HIR"\n你猛听得嗤嗤声响，眼前白光闪动，八柄利剑自房门上下左右挺出，纵横交错，布满入口。\n\n"NOR);
         tell_object(me,RED"你躲闪不急，身中数剑，受伤过重，已经有如风中残烛。\n"NOR);
         me->set_temp("last_damage_from", "误中机关而");
         me->die();
         }
         else {
         tell_object(me,HIR"\n你猛听得嗤嗤声响，眼前白光闪动，八柄利剑自房门上下左右挺出，纵横交错，布满入口。\n\n"NOR);
         tell_object(me,HIW"你不慌不忙，猛吸一口气，急步跳起，堪堪然躲过了门口的机关。\n\n"NOR);
         me->start_busy(2);
         me->set_temp("jqg/enter", 1);
         }
         }
         add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
         object jzj,snj,me = this_player();
         if(!me->query_temp("jqg/sword")) return 0;
         if (!arg || (arg != "sword"))
              return notify_fail("你要摘什么啊？\n");
         if (me->is_busy() || me->is_fighting())
	      return notify_fail("你正忙着哪！\n");
         if( me->query("gender") =="男性"
          && me->query("couple/couple_id")){
            jzj=new(__DIR__"npc/jzj");
          if(!clonep(jzj))
             return notify_fail("你来晚了，君子剑已给别人拿走了。\n");  
if (this_object()->query("aget1"))
{
             destruct(jzj);
             return notify_fail("你来晚了，君子剑已给别人取走了。\n");
             }

          if(clonep(jzj) && jzj->violate_unique()){
             destruct(jzj);
             return notify_fail("你来晚了，君子剑已给别人取走了。\n");
             }
            message_vision("$N伸手到壁上摘下一把君子剑。\n"NOR,me);
            jzj->move(me);
            this_object()->set("aget1",1);
            me->delete_temp("jqg/sword");
            return 1;
            }
         if( me->query("gender") =="女性"
          && me->query("couple/couple_id")){
            snj=new(__DIR__"npc/snj");
          if(!clonep(snj))
             return notify_fail("你来晚了，淑女剑已给别人拿走了。\n");  
if (this_object()->query("aget2"))
{
             destruct(snj);
             return notify_fail("你来晚了，淑女剑已给别人取走了。\n");
             }

          if(clonep(snj) && snj->violate_unique()){
             destruct(snj);
             return notify_fail("你来晚了，淑女剑已给别人取走了。\n");
             }
            message_vision("$N伸手到壁上摘下一把淑女剑。\n"NOR,me);
            snj->move(me);
            this_object()->set("aget2",1);
            me->delete_temp("jqg/sword");
            return 1;
            }
           else{
            me->delete_temp("jqg/sword");
            return notify_fail("你发现原来这把剑并不适合自己，于是把手又伸了回来。\n");
            }
}
