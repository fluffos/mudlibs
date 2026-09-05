// by iceland

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <title.h>

int give_lun();
int give_lun2();

string* luns = ({
       "/d/dalunsi/npc/obj/gold-falun",
       "/d/dalunsi/npc/obj/silver-falun",
       "/d/dalunsi/npc/obj/bronze-falun",
       "/d/dalunsi/npc/obj/iron-falun",
       "/d/dalunsi/npc/obj/leaden-falun",
       });


void create()
{
        object weapon;
        set_name("金轮法王", ({ "jinlun fawang", "jinlunfawang","fawang" ,"jinlun"}));
        set("long",@LONG
他身材高瘦，脸颊深陷，双目看似无神，两边太阳穴却高高凸起，面容严肃。
他受封“蒙古国第一国师”，练得一身通天彻地的神功。
LONG
        );
        set("title", HIY "蒙古国第一国师" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 27);
        set("per", 22);
        set("max_qi", 7000);
        set("max_jing", 6500);
        set("eff_jingli", 3500);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 50);
        set("combat_exp", 2800000);
        set("score", 280000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 150);
        set_skill("force", 200);
        set_skill("longxiang-boruo", 200);
        set_skill("dodge", 280);
        set_skill("yuxue-dunxing", 280);
        set_skill("hammer", 280);
        set_skill("xiangfu-lun", 280);
        set_skill("hand",280);
        set_skill("dashou-yin",280);
        set_skill("claw",280);
        set_skill("tianwang-zhua",280);
        set_skill("parry", 280 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 10, "弟子");
        set("inquiry", ([
                "武器" : (: give_lun  :),
                "兵器" : (: give_lun  :),
                "风火轮" : (: give_lun2  :),
                
       ]));
        set("lun_count",5);
        set("lun_count2",1);
        set("class", "huanxi");
        set("chat_chance", 2);     
        set("chat_msg", ({
CYN"金轮法王傲然道：第十层龙象般若功我已融会贯通，古往今来，我是第二人！\n"NOR,
CYN"金轮法王愤愤的道：中原武人不讲规矩，仗着人多，大伙儿来个一拥而上。\n"NOR,
CYN"金轮法王愤愤的道: 哼，否则凭我一人之力当可取得武林盟主之位。\n"NOR,
}) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "shield jinlun fawang" :),
                (: perform_action, "hammer.wushuai" :), }));
        set_temp("apply/damage", 70);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 60);
        setup();
       if (clonep()){
                             weapon = new(("/d/dalunsi/npc/obj/gold-falun"));
                if (!weapon) weapon = new(("/d/dalunsi/npc/obj/silver-falun"));
                if (!weapon) weapon = new(("/d/dalunsi/npc/obj/bronze-falun"));
                if (!weapon) weapon = new(("/d/dalunsi/npc/obj/iron-falun"));
                if (!weapon) weapon = new(("/d/dalunsi/npc/obj/leaden-falun"));
                weapon->move(this_object());
                weapon->wield();
                carry_object("/d/dalunsi/npc/obj/qinxiu-jiasha")->wear();    
        }
}
void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本派弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 160) {
                command("say 我大轮寺各种武功均和内功相辅相成。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的内功吧。");
                return;
        }
        if( (string)ob->query("gender") == "无性" ){
                command ("say 施主身体残缺，虽说佛祖普渡众生，可是...");
                return;
        }

        if( (int)ob->query_con() < 30) {
               command("sigh");
               command("say"+ RANK_D->query_respect(ob) +"你悟性太差，领悟不了高深功夫。");
               command("shake");
               return;
        }

        if (!(int)ob->query_temp("win_deb")){
                command ("say 你还是先找我弟子达而巴试试你的修为吧。\n");
                return;
          } 
        command("say 我也正在找寻一个资质上佳的弟子授我衣钵。你不顾艰辛诚意拜我为师。");
        CHANNEL_D->do_channel(this_object(), "jh", "好！"+ ob->query("name") + RANK_D->query_respect(ob) + "智勇双全，可传我衣钵。");
        CHANNEL_D->do_channel(this_object(), "jh", "本座苦觅数年，终于找到传人，百年之后亦无憾矣！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY "大轮寺金轮法王座下弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

int give_lun()
{ 
       mapping fam; 
       object me, ob,lun;

       me = this_object();
       ob = this_player();
       
       if (ob->query_temp("give_lun") == 1){
               command("say 你不是刚从我这里拿了轮子吗，你当我白痴啊！");
                return 1;
        }
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "大轮寺"){
              command("say 你与本派素无来往，不知此话从何谈起？");
               return 1;}
       if ( objectp(present("iron falun", (ob))))  { 
          command("say 你身上不是已经有轮了吗？");
          return 1;  } 
        if ( objectp(present("iron falun", environment(me)))){ 
             command("say 地上不是有只轮子吗？你眼睛瞎啦？？");
             return 1;
             } 
      
        if(query("lun_count") < 1){
         command("say 你来晚了，我这里现在没有轮供你使用。");
         return 1;}
       add("lun_count",-1);       
       lun = new( luns[random(sizeof(luns))] );
       if(clonep(lun)){
         lun->move(ob);
         command("say 好吧，这只法轮你拿回去好好钻研。");
         ob->set_temp("give_lun",1);
         message_vision("$N交给$n一只法轮。\n", me, ob);
         return 1;
       }
       command("say 你来晚了，暂时我身边没有多余的法轮可以给你了。");
       return 1;

}
int give_lun2()
{ 
       mapping fam; 
       object me, ob,lun2;

       me = this_object();
       ob = this_player();
       
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "大轮寺"){
              command("say 你与本派素无来往，不知此话从何谈起？");
               return 1;}
       if ((int)ob->query_skill("longxiang-boruo", 1) < 200) {
                command("say 我大轮寺各种武功均和内功相辅相成, 你的内力修为不够，我不放心把本派宝物交给你。");
                return 1;
        }
      
        if(query("lun_count2") < 1){
         command("say 你来晚了，我这里现在没有风火轮供你使用。");
         return 1;}
       add("lun_count2",-1);       
       lun2 = new(("/d/dalunsi/npc/obj/bestfalun"));
       if( clonep(lun2)){
         lun2->move(ob);
         command("say 好吧，这是本门之宝风火轮，你拿回去好好练功，光大我门。");
         message_vision("$N交给$n一只风火轮。\n", me, ob);
         return 1;
       }
       command("say 你来晚了，风火轮已给你的师兄取走了。");
       return 1;
}

