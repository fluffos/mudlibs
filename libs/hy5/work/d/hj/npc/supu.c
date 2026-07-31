#include <ansi.h>
inherit NPC;
int ask_me();
string* goods = ({
       "/d/hj/obj/shoujuan",
       "/d/hj/obj/yangpi",
       __DIR__"obj/wandao",
       "/d/hj/obj/shoujuan",
       "/d/hj/obj/shoujuan",
       __DIR__"obj/bishou",
       "/d/hj/obj/jiunang",
       "/d/hj/obj/shoujuan",       
});

void create()
{
        set_name("苏普", ({ "supu"}));
        set("gender", "男性");
        set("age", 21);
        set("long", "一个年轻的哈萨克牧羊人, 哈萨克第一勇士苏鲁克的儿子。\n");
        set("attitude", "heroism");
        set("combat_exp", 70000);
        set("shen", 3000);
        set("str", 32);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 60000);
        set("max_jing", 60000);
        set("neili", 50000);
        set("max_neili", 50000);
        set_skill("unarmed", 330);
        set_skill("blade", 340);
        set_skill("parry", 340);
        set_skill("dodge", 340);
        set("inquiry", ([
            "阿曼" : "阿曼是我的心上人，我每次杀了野狼都会送她狼皮。\n",
            "李文秀" : "她的歌唱得最好听的了，有人说她比天铃鸟唱得还好。
但这几年来，我一直没听到她唱歌，一直没在见到她。\n",
            "摔跤" : (: ask_me :),
            "比试" : (: ask_me :),
            "计爷爷" : "就是计老人啊，他会酿又香又烈的美酒，会医牛羊马匹的疾病。\n",
            "苏鲁克" : "那是我阿爹，是哈萨克族的第一勇士！哈哈！\n",
        ]) );
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"苏普自豪地嚷道: 我也要学我阿爹成为哈萨克第一勇士。\n",
"苏普自言自语: 从哪儿去弄一张上等的狼皮，送给阿曼呢? \n",
        }) );
        
        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("parry", 230);
        set_skill("force", 250);
	set_skill("taixuan-gong", 250);
        set_skill("shenzhao-jing", 280);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
      set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
        
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object("/d/hj/obj/jiunang");
}

int ask_me()
{
        if ((int)this_player()->query_temp("supu_fight")) {
            command("say 我们不是比试过了吗？");
            return 1;
            } 
        if (!this_player()->query_temp("supu_accept")) {
            command("say 你凭什么和我比试呢？");
            return 1;
            } 
        else {
        message_vision("$N看了$n一眼，用不太标准的汉话说道：
我是未来的草原第一勇士，这位汉族"+RANK_D->query_respect(this_player())+"你就和我切搓(fight)几下吧？\n", this_object(), this_player());
        this_player()->set_temp("supu1", 1);
        return 1;
        }
}

int accept_fight()
{
        object me, ob;
        me = this_object();
        ob = this_player();
        if(me->query("eff_qi") < me->query("max_qi") || 
           me->query("qi") < me->query("eff_qi") ||
           me->query("neili") < me->query("max_neili")){
           message_vision(CYN"$N对$n说：我还没有休息好，你等一会儿吧。\n"NOR, ob, me);
           return 0;
           }
        if( ob->query_temp("supu1") ) {
        message_vision(CYN"$N对$n说：好吧，那我就同你切搓几招吧，点到为止。\n"NOR, ob, me);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("supu1");
        ob->delete_temp("supu_accept");
        return 1;
        }
        else return 0;
}

int checking(object me, object ob)
{
        object good;
        int my_max_qi, his_max_qi;
	int i;
	object fang;

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()){
                call_out("checking",1, me, ob);
                return 1;
                }
        if ( !present(ob, environment()) ) return 1; 
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
            message_vision(CYN"$N对$n不住地赞叹：你们汉人果然不一般，我服输了，送你一些礼物。\n"NOR, me, ob);
            good = new(goods[random(sizeof(goods))]); 
            good->move(ob);
            ob->set_temp("supu_fight", 1);
            message_vision("$N交给$n一件礼物。\n", me, ob);
        if(!ob->query("jinyong/book6") && ob->query("combat_exp",1) >= 800000 )
{
	i = 200+random(800);
	ob->set("jinyong/book6",1);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*12);
	ob->add("mpgx",10);
	ob->add("expmax",2);
 message_vision(CYN"$N对$n说到，有一个陈达海带了一伙人来找李文秀麻烦 能帮她一下吗？\n"NOR, me, ob);
	tell_object (ob,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
        ob->save();
 }
            return 1;
            }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
                message_vision(CYN"$N冲着$n一撇嘴，说道：你们汉人的武学不过如此。\n"NOR, me,ob);
                message_vision("$N对$n行了个礼，垂头丧气地离开了这里。\n",ob, me);
                ob->move("/d/hj/road");
                message_vision("$N垂头丧气地走回来。\n", ob);
                return 1;
               }
        return 1;
}

int accept_object(object who, object ob)
{
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
        if (userp(ob)) {
               command("? " + who->query("id"));
               command("say 你这汉人强盗，把人打晕想干什么？");
               this_object()->kill_ob(who);    
               return notify_fail("糟糕，穿邦了！\n");
               }


        if (!who->query_temp("killltl")){
                command("? "+(string)who->query("id"));
                command("say 大灰狼是你杀的吗？\n"NOR);                
            return 0;
        }  


        if ((string)ob->query("name") == "灰狼皮"){
                command("ah "+(string)who->query("id"));
                command("say 你杀死了大灰狼！看来你也是个勇士，要不要和我"HIY"比试"CYN"一下？\n"NOR);                
                who->set_temp("supu_accept", 1);                                
            return 1;
        }        
        
        
        command("smile "+ (string)who->query("id"));
        command("say 谢谢你啦。");
        return 0;
}