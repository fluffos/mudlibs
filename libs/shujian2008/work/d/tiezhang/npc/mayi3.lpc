//mayi3.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("黄令天", ({"huang lingtian","huang","lingtian"}));
       set("title","麻衣长老"); 
       set("nickname",HIY"铁掌四鹰"NOR);
       set("long",
    "他是一个年约六旬的老者，满头花发，两鬓斑白。\n"
    "他两侧的太阳穴高高鼓起，微闭的双目中时而闪过凌厉的眼神，似乎身怀绝技。\n"
       );

       set("gender", "男性");
       set("attitude", "peaceful");
       set("unique", 1);
       set("age", 60);
       set("shen_type", -10);
       set("str", 28);
       set("int", 23);
       set("con", 23);
       set("dex", 28);
       set("per", 20);
       set("max_qi", 1800);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 600000);
       set("score", 10000);

       set_skill("force", 120);
       set_skill("guiyuan-tunafa", 120);
       set_skill("dodge", 120);
       set_skill("literate", 120);
       set_skill("shuishangpiao", 120);
       set_skill("strike", 120);
       set_skill("tiezhang-zhangfa", 120);
       set_skill("parry", 120);
       set_skill("brush", 150);
       set_skill("yingou-bifa", 150);
        set_skill("tiezhang-xinfa", 120);

       map_skill("force", "guiyuan-tunafa");
       map_skill("dodge", "shuishangpiao");
       map_skill("strike", "tiezhang-zhangfa");
       map_skill("parry", "tiezhang-zhangfa");
       map_skill("brush", "yingou-bifa");
       prepare_skill("strike", "tiezhang-zhangfa");

       setup();
       carry_object(__DIR__"obj/mayi")->wear();
       carry_object(__DIR__"obj/bi")->wield();       
}
void init()
{
       object me, ob;
       mapping fam;

       ::init();

       ob = this_player();
       me = this_object();
       
       if (interactive(ob) 
       && !environment(ob)->query("no_fight")
       && ( (fam = ob->query("family")) && fam["family_name"] != "铁掌帮" ) 
        && (int)ob->query("combat_exp", 1) >= 10000 ) 
       {
               if( !ob->query_temp("warned") ) {
        command("say 站住！你不是铁掌帮弟子，不能在此久留！！");
        command("say 你还是速速离开此地吧，不然老朽可要对你不客气了！！");
        command("hehe");
                       ob->set_temp("warned", 1);
               }
          else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
                else {
                       command("say 你活得不耐烦了，竟敢到铁掌帮来撒野！！！\n");
                       remove_call_out("hiting_ob");
                       call_out("hiting_ob", 1, ob);
               }
       }       

}
