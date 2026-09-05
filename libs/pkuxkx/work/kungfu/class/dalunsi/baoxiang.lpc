// baoxiang.c 宝象
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

string ask_miji();
string ask_jiaohuan();

void create()
{
        set_name("宝象", ({ "bao xiang", "baoxiang" ,"bao","xiang"}));
        set("long",@LONG
他是血刀老祖座下三弟子，长得肥头大耳，满面暴虐之色，
脸上油腻腻的泛着光，不象守戒修行的出家人。
LONG
        );
        set("title", HIR "大轮寺血刀老祖座下弟子" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 39);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 15);
        set("con", 25);
        set("dex", 28);
        set("max_qi", 900);
        set("eff_jing", 300);
        set("max_jing",300);
        set("neili", 1100);
        set("max_neili", 1100);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("score", 30000);
        set("unique", 1);
        set("no_get","宝象对你来说太重了。\n");

        set_skill("huanxi-chan", 80);
        set_skill("literate", 60);
        set_skill("force", 80);
        set_skill("longxiang-boruo", 80);
        set_skill("dodge", 80);
        set_skill("yuxue-dunxing", 80);
        set_skill("hand", 70);
        set_skill("dashou-yin", 70);
        set_skill("claw", 70);
        set_skill("tianwang-zhua", 70);
        set_skill("parry", 80 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "tianwang-zhua");
        map_skill("claw", "tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        set("inquiry", ([
                "血刀秘籍" : (: ask_miji :),
                "交换" : (: ask_jiaohuan :),
                "血刀老祖" : "那是我师父，奸淫捋掠样样在行，真叫人佩服！\n",
                "老祖" : "你说的是我师父血刀老祖吧？他等闲可不容易见到。\n" ,
                "奸淫" : "嘻嘻，看你也是此道中人，有机会我们配合配合。\n",
                "小妞" : "你真是我的知音，知道我兴趣所在，有什么消息我们交流交流？\n",
        ]));
        set("miji_count", 1);

        create_family("大轮寺", 12, "弟子");
        set("class", "huanxi");

        setup();
        carry_object("/d/dalunsi/npc/obj/qinxiu-jiasha")->wear();

        add_money("silver",10);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("huanxi-chan", 1) < 50) {
                command("say 欢喜禅是各项武功之本，你再勤加修炼吧。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的心法吧。");
                return;
        }

        if ((string)ob->query("class") != "huanxi") {
                message_vision("宝象看了看你头顶，又摸了摸自己的光头。",this_player());
                command("say 你还没出家，不能表示你是真心侍奉欢喜佛，我不能收你。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "如能早下决心，献身侍奉我佛再来找我吧。");
                return;
        }
        command("say 好吧，以后你就好好侍奉佛爷我吧。");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "大轮寺血刀门第六代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}
 string ask_miji()
{
        this_player()->set_temp("jiaohuan",1); 
        return  "血刀秘籍是本门一本宝书，是本门以前一位高僧笔录下来的，
内容主要是一套刀法，这套刀法狠辣凌厉...你问这个做什么？秘籍在我
这里，可我还没看完，不会给你的。\n" ;
}
 string ask_jiaohuan()
{
        if  ((int)this_player()->query_temp("jiaohuan")) {
          this_player()->set_temp("miji",1);
          return "还有什么比武功更重要的呢？你能拿什么东西和我换？";
         }
        else {
          message_vision("宝象迷惑的看了看$N。\n",this_player());
         }
}
 int accept_object(object who, object ob)
{
        object obj;
        
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");

        if ((string)ob->query("id") == "chungong tu" ) {
            if (query("miji_count") > 0) {
               command("ah");
               message_vision("宝象喜得眉开眼笑，手舞足蹈。\n",this_player());
               command("say 这可真是个宝贝！你从那里搞到的，太棒啦。");
               message_vision(
"宝象生怕$N反悔，赶紧把春宫图揣在怀中，把血刀秘籍塞在$N手中。\n",this_player());
               obj=new("/d/dalunsi/npc/obj/xuedao-miji");
               obj->move(who);
               add("miji_count", -1);
               command("say 好，就这么换了!\n");
               remove_call_out("destroying");
               call_out("destroying", 1, this_object(), ob);
                return 1;
              }
            else { 
               command("ah");
               message_vision("宝象喜得眉开眼笑，手舞足蹈。\n",this_player());
               command("say 这可真是个宝贝！你从那里搞到的，太棒啦。");
               command("say 好，就这么换了!\n");
               remove_call_out("nothing");
               call_out("nothing",2,who);
               remove_call_out("destroying");
               call_out("destroying", 1, this_object(), ob);
               return 1;
             }
          }
        else {
               command("say 这个就想换？你做白日梦!");
               remove_call_out("destroying");
               call_out("destroying", 1, this_object(), ob);
               return 0;
             }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
void nothing(object me)
{
        if (!me) return;
               message_vision("宝象伸手在怀中左掏右掏的摸了半天，什么也没掏出来。\n", me);
               command("say 遭了！我忘了血刀秘籍已经给了别人了。");
               command("say 算你倒霉，这本春宫图嘛，就先借给我看几天吧。"); 
               command("shrug");              
}
void init()
{
        object ob;
        ob = this_player();
        if((ob->query("gender")=="女性")&&((string)ob->query("family/family_name") != "大轮寺") ){
        if(ob->query("per")>=20){
        message_vision(HIY"宝象突然跳到$N面前，拦住了去路。\n"NOR,ob);
        message_vision(HIY"宝象上下打量着$N，嘿嘿淫笑了两声。\n"NOR,ob);
        command("say 这位"+RANK_D->query_respect(ob)+"别走得这么急啊，到那里去呀？");
        ob->start_busy(2);
        }
        else {
        message_vision(HIY"宝象突然跳到$N面前，拦住了去路。\n"NOR,ob);
        message_vision(HIY"宝象上下打量着$N，脸上现出失望的神色，嘴角一撇。\n"NOR,ob);
        command("say 这位"+RANK_D->query_respect(ob)+"怎么长得如此丑陋，实在令人大失所望。");
        ob->start_busy(2);
        }
    }
}

