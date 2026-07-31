// qqchi.c 裘千尺
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_dan();
string ask_dan2();
void create()
{
        set_name("裘千尺", ({ "qiu qianchi", "qiu", "qianchi"}));
        set("nickname", HIY"铁掌莲花"NOR);
        set("title",HIW"绝情谷女主人"NOR);
        set("long","一个半身赤裸的秃头婆婆盘膝坐在地下，满脸怒容，凛然生威。\n"); 
        set("gender", "女性");
        set("age", 55);
        set("attitude", "friendly");

        set("unique", 1);
        set("shen_type", -20);
        set("str", 35);
        set("int", 30);
        set("con", 28);
        set("dex", 5);
        set("per", 8);

        set("max_qi", 16000);
        set("max_jing", 16000);
        set("neili",29500);
        set("max_neili", 29500);
        set("eff_jingli",22000);
        set("jiali", 40);
        set("combat_exp", 1900000);
        set("score", 2000);

        set_skill("force", 330);
        set_skill("guiyuan-tunafa", 330);
        set_skill("dodge", 330);
        set_skill("shuishangpiao", 230);
        set_skill("strike", 330);
        set_skill("tiezhang-zhangfa", 330);
        set_skill("parry", 330);
        set_skill("literate", 100);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([ 
               "绝情丹" : (: ask_dan :),
               "公孙止" : (: ask_dan2 :),

        ]));
        setup();
}

void kill_ob(object me,object weapon,object ob)
{
        me=this_player();
        weapon = me->query_temp("weapon");
        ob=this_object();
        command("sneer " + me->query("id"));
        if( weapon ){
          message_vision(HIW"\n$N突然波的一声，口中飞出一物 ，铮的一响，打在$n手中所握的那柄"+weapon->name()+HIW"刃上。\n"NOR,ob,me);
          weapon->move(environment(ob));
          me->start_busy(2);
          message_vision(HIR"\n$N只觉手臂剧震，五指竟然拿捏不住，当的一声，"+weapon->name()+HIR"落在地下。\n"NOR,me);
          }
        else {
          message_vision(HIW"\n$N口中枣核钉已疾射而出，破空之声有如尖啸，直指$n小腹，去势当真是悍猛无伦。\n"NOR,ob,me);
          me->start_busy(2);
          message_vision(HIR"\n$N“啊”的一声高叫，弯腰捧腹，俯下身去。\n"NOR,me);
          me->set("eff_qi", me->query("eff_qi")/2);
          me->set("qi",me->query("eff_qi"));
          }
         if(!ob->is_killing(me->query("id")))
          ::kill_ob(me);
}

string ask_dan()
{
         if(this_player()->query_temp("jqg/chi"))
             return "这位"+RANK_D->query_respect(this_player())+"，我不是已经告诉你，绝情丹所藏之处了么？";
          this_player()->set_temp("jqg/chi", 1);
          return "你我在此相遇亦算有缘，绝情谷唯一一颗绝情丹我藏在大厅第五块青砖下。";
}
string ask_dan2()
{

          this_player()->set_temp("book1041", 1);
          return "公孙止这个狗贼，我一定要杀了他报仇。";
}