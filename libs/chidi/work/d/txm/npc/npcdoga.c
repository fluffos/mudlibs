#include <ansi.h>

inherit BHNPC;
inherit F_MASTER;

void greeting(object);
void init();
int ask_me();
string  ask_zhuanshi();
void create()
{
        set_name("逍遥哥", ({ "npc doga", "xiaoyao", "ge"}));
        set("long",
            "他神情落魄，衣襟边幅不修，满头乌黑长发随风飘荡。\n"+
            "从他身上你丝毫看不出他深藏不漏的绝世武学，\n"+
            "但从他开阖的双眼间，精光爆射，顿时让人尊肃三分。\n");
        set("gender", "男性");
        set("age", 35);
        set("shen_type",1);
        set("no_suck",1);
        set("attitude", "peaceful");
        set("nickname", HIW "人生难得几逍遥" NOR);

        set("str", 500);
        set("int", 500);
        set("con", 500);
        set("dex", 500);
        set("per", 50);
        set("jh_dj/dj", 100);

        set("qi", 2800000);
        set("max_qi", 2800000);
        set("jing", 1800000);
        set("max_jing", 180000);
        set("neili", 210000000);
        set("max_neili", 20000);
        set("jiali", 10000);

        set("combat_exp", 2000000000);
        set("score", 0);
        set_skill("force", 10000);
        set_skill("dodge", 10000);
        set_skill("parry", 10000);
        set_skill("sword", 10000);
        set_skill("club", 10000);
        set_skill("axe", 10000);
        set_skill("claw", 10000);
        set_skill("cuff", 10000);
        set_skill("unarmed",10000);
        set_skill("blade",10000);
        set_skill("hammer",10000);
        set_skill("hand",10000);
        set_skill("staff",10000);
        set_skill("strike",10000);
        set_skill("whip",10000);        
        set_skill("taoism", 10000);
        set_skill("finger", 10000);
        set_skill("qimen-flee", 1500);
        set_skill("literate", 5000);
        set_skill("throwing", 10000);
        //set_skill("hubo", 10000);
        set_skill("beiming-shengong", 5000);
        set_skill("dagger", 10000);
        set_skill("taiji-shengong", 5000);
        set_skill("huagong-dafa", 5000);
        set_skill("taiji-jian", 5000);
        set_skill("damo-force", 5000);
        set_skill("piaomiao-shenfa", 5000);
        set_skill("shaolin-shenfa", 5000);
        set_skill("tiyunzong", 5000);
        set_skill("wudu-yanluobu", 5000);
        set_skill("taiji-quan", 5000);
        set_skill("zuixian-steps", 5000);
        set_skill("pixie-jian",5000);
        set_skill("liumai-shenjian",5000);
        set_skill("tiandao-blade",5000);
        set_skill("jiuyang-shengong",5000);
        set_skill("taixuan-gong",5000);

        map_skill("unarmed", "taiji-quan");
        map_skill("force", "damo-force");
        map_skill("dodge", "pixie-jian");
        map_skill("parry", "tiandao-blade");
        map_skill("blade", "tiandao-blade");
        create_family("铁血盟",1,"盟主");
        set("inquiry", ([
                "天刀" : (: ask_me :),
                "转世" : (: ask_zhuanshi :),
        ]));
        setup();
        carry_object("/d/txm/obj/jinpao")->wear();
 carry_object("/d/txm/obj/tiandao")->wield();
}

void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "铁血盟") 
             {
               message_vision("逍遥哥对$N满意的点了点头。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("逍遥哥冲着$N微笑说：你可是想来加入我铁血盟的吗？\n",ob);
               return;
              }
}
void attempt_apprentice(object ob)
{          if ((int)ob->query("zhuanshi/times")<2)
        {
                command("say 想学我的神功？你还不够资格，"
                        "等你2转后再说吧！");
                return;
        }

        
        if ((int)ob->query_skill("blade", 1) < 400) {
                command("say 本门的武功若无刀法根基，如何能提高？"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在基本刀法上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 1000000) {
                command("say 本门最忌无耻之徒，快滚吧！");
                command("say 你这种败类，" + RANK_D->query_respect(ob) +
                        "快滚吧！");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say 本门武功非绝世容貌不可习得！");
                command("say 你还是去美容后在来吧!");
                return;
        }
        if ((int)ob->query("kar") < 30) {
                command("say 本门武功要一定的福缘才可以习得！");
                command("say 你还是去遇些机缘后在来吧!");
                return;
        }
 
        if (ob->query_int() < 60) {
                command("shake"+ ob->query("id")); 
                command("say 要想修到最高境界，你的悟性还不够。");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return;
        }
  if (ob->query_con() < 60) {
                command("shake"+ ob->query("id")); 
                command("say 要想修到最高境界，你的根骨还不够。");
                command("say " + RANK_D->query_respect(ob) + "的根骨还大有潜力可挖，还是请回吧。");
                return;
        }
  if ((int)ob->query("combat_exp") < 200000000) {
                command("shake"+ ob->query("id")); 
                command("say 要想修到最高境界，你的经验还不够。");
                command("say " + RANK_D->query_respect(ob) + "的经验还大有潜力可挖，还是请回吧。");
                return;
        }
       command("recruit " + ob->query("id"));
       command("chat 哈哈！终于我后继有人了！");
       command("chat 好！记住我的弟子以后一定是江湖的统治者呦！");
                return;
}
       


int ask_me()
{
        object me,ob;
        object wuqi;
        me = this_player();
        ob = this_object(); 
        if (((me->query ("family/family_name"))!="铁血盟")|| (me->query("shen",1) < 50000000) || (ob->query_temp("没有")))
      {
       command("say 这兵器杀气太重，不适合你用！");
      }
      else
      {
       command("say 看到你对本门忠心耿耿，你就拿去试试！");
       wuqi=new("/d/txm/obj/tiandao");
       wuqi->move(me);     
       add_temp("没有",1);
      }
      return 1;
}
string  ask_zhuanshi()
 {
        object me = this_player();
        int zstimes=me->query("zhuanshi/times");
        if (zstimes<1)
              command("say 兔崽子，还没断奶呢就来烦我，去找四小宗师去！");
        else{
        if (zstimes>=10)
              command("say 你想干什么！最高只能十转！");
        else{
        if (me->query("combat_exp")<zstimes*200000000)
              command("say 就这么点经验也想来转世!");
        else
            {
             if (me->query_skill("dodge")>=1000*(zstimes+1)&&me->query_skill("force")>=1000*(zstimes+1)&&me->query_skill("unarmed")>=1000*(zstimes+1)&&me->query_skill("literate",1)>=1000*zstimes)
              {  command("say 好吧，让我送你一程。");
                 me->set_temp("askge",1);
                me->move("/u/luoyun/zhuanshi/youmingdian");
              }
             else
                 {
            command("say 你的技能等级不够！");
 message_vision(
"               "+RED"$N的轻功激发等级为"+me->query_skill("dodge")+"。\n
               "RED"$N的内功激发等级为"+me->query_skill("force")+"。\n
               "RED"$N的拳脚激发等级为"+me->query_skill("unarmed")+"。\n
               "RED"$N的读书写字等级为"+me->query_skill("literate",1)+"。\n"NOR,me);
                 }
           }
           }
}
} 


