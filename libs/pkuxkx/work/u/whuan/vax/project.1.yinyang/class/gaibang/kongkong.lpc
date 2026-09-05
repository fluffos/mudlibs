// kongkong.cg.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void consider();
void create()
{
        seteuid(getuid());
        set_name("空空儿", ({ "kong kong","beggar","qi gai","kong" }) );
        set("title", MAG "妙手神丐" NOR);
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个满脸风霜之色的老乞丐。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);
        set("max_qi", 1500);
        set("max_jing", 100);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 110);
        set("shen_type", 0);
        set("startroom","/d/city/lichunyuan");
        set("thief", 0);
        set("combat_exp", 50000);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("sword", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
        set_skill("stealing", 130);
        set_skill("begging", 130);
        set_skill("checking", 110);
        set_skill("huntian-qigong", 70);
        set_skill("jiaohua-xinfa", 70);
        set_skill("xianglong-zhang", 70);
        set_skill("xiaoyaoyou", 80);
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        prepare_skill("strike", "xianglong-zhang");
        create_family("丐帮", 19, "八袋长老");
        set("chat_chance", 20);
        set("chat_msg", ({
                "空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
                "空空儿懒洋洋地打了个哈欠。\n",
        "空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
                (: random_move :)
        }) );
        setup();
        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
        add_money("silver", 10);
}
void attempt_apprentice(object ob)
{
        mapping fam;
        object obj;
        string title1;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
            if(!ob->query("is_beggar"))
            {
           if(ob->query("combat_exp")<2000)
        {
              command("say 好吧，希望" + RANK_D->query_respect(ob) +
                "能好好学习本门武功，将来在江湖中闯出一番作为。");
                command("recruit " + ob->query("id"));
                ob->set("class", "beggar");
                if(!present("budai", this_player()))
                {
                obj=new("/d/gaibang/obj/gaibang-bag");
                this_player()->set("dai", 1);
                obj->move(ob);
                }
        this_player()->set("title",MAG "丐帮" NOR + YEL +"一袋" NOR + MAG "弟子" NOR);
                this_player()->set("is_beggar", 1);
        }
        else
           {
   command("say "+ RANK_D->query_respect(ob) + "既然有名师指点，又何必来拜我叫化子呢。");
         return;
           }
                }
            else
            {
      command("say "+ RANK_D->query_respect(ob) + "以前曾是丐帮弟子，既然判出本帮，何必又回来呢！");
                return;
            }
        }
        else
        {
                title1=this_player()->query("title");
                command("say 好吧，希望" + RANK_D->query_respect(ob) +
                "能好好学习本门武功，将来在江湖中闯出一番作为。");
                command("recruit " + ob->query("id"));
                this_player()->set("title", title1);
        }
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("stealing");
                call_out("stealing", 1, ob);
        }
}
void stealing(object ob)
{
        mapping fam;
        if( !ob || environment(ob) != environment()
                || ((fam = ob->query("family")) && fam["family_name"] == "丐帮")
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;
        switch( random(5) ) {
                case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       break;
                case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));
                       break;
                case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));
                       break;
                case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));
                       break;
                case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));
                       break;
        }
}
int accept_object(object me, object obj)
{
        if (obj->query("money_id") && obj->value() >= 1) {
                 command("smile");
         command("say 多谢啦 ! 其实我还是有点钱的，这次只不过试试你罢了!");
                 command("give 10 silver to " + me->query("id"));
        }
        else {
                 command("shake");
                 command("say 这种东西鬼才要 ! 滚一边去 !");
                 command("give " + obj->query("id") + " to " + me->query("id"));
//               obj->move(this_player());
        }
        return 1;
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}
