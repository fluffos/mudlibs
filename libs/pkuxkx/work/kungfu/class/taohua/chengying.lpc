#include <ansi.h>
#include <title.h>
// chengying.c  程英
inherit NPC;
inherit F_MASTER;
int ask_san();
int ask_rong();
int ask_jia();
int ask_jing();
void heal();
void create()
{
    set_name("程英",({"cheng ying","cheng"}));
    set("nickname",HIC"鬼精灵"NOR);
    set("title",GRN"桃花岛"NOR+YEL"宫主"NOR);
    set("long","她是黄药师晚年所收的弟子。她看起来闭月羞花。 \n"
            "她看起来有二十多岁。 \n"
            "但是她满面诡秘的样子，不知她想干什么。不过也难怪。 \n"
            "她毕竟是黄老邪的徒弟嘛。 \n");
    set("gender", "女性");
    set("generation",2);
    set("age", 20);
    set("attitute", "peaceful");
    set("shen-type", 1);
    set("str", 25);
    set("int", 28);
    set("con", 30);
    set("dex", 29);
    set("max_qi", 3000);
    set("qi", 3000);
    set("max_jing", 1500);
    set("jing", 1500);
    set("max_neili", 2000);
    set("neili", 2000);
    set("jiali", 150);
    set("combat_exp", 400000);
    set_skill("force", 100);
    set_skill("bihai-shengong", 120);
    set_skill("dodge", 100);
    set_skill("luoying-shenfa", 120);
    set_skill("parry",100);
    set_skill("sword",100);
    set_skill("yuxiao-jian",120);
    set_skill("hand",100);
    set_skill("fuxue-shou",120);
    set_skill("finger",100);
    set_skill("literate",120);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("parry","yuxiao-jian");
    map_skill("sword","yuxiao-jian");
    map_skill("hand","fuxue-shou");
    prepare_skill("hand","fuxue-shou");
    create_family("桃花岛",2,"弟子");
    set("san_count",1);
    set("shen_type",1);set("score",5000);setup();
    carry_object("/d/taohuadao/obj/lvshan")->wear();
    set("chat_chance",5);
    set("chat_msg", ({
                "近来怎么很少看见师傅，不知他老人家在干什么？ \n",
                "听说师母过世时，师傅曾呕了一滩血。 \n",
                "想必师傅又在创造一种怪异的武功吧。 \n",
                }));
    set("inquiry",([
                "九阴真经" : (:ask_jing:),
                "田七鲨胆散" : (: ask_san :),
                "软猬甲": (: ask_jia : ),
                "黄蓉" : ( : ask_rong :),
                ]));
}
void attempt_apprentice(object ob)
{
    if((string)ob->query("family/family_name")!="桃花岛")
    {
        command("say我不收外派弟子");
        command("say"+RANK_D->query_respect(ob)+"若想拜我，可以先到太湖的“归云庄”找陆师兄吧");
        return;
    }
    if((int)ob->query_skill("bihai-shengong",1) < 30)
    {
        command("say " + RANK_D->query_respect(ob) + "是否应该在碧海神功上多下功夫？");
        return;
    }
    if((int)ob->query("shen") < 0)
    {
        command("say 多行不义必自毙。");
        command("say " + RANK_D->query_respect(ob) + "师傅最恨那些小人了，我不想让师傅生气，你还是请回吧。");
        return;
    }
    if((int)ob->query("betrayer") > 1)
    {
        command("say " + RANK_D->query_respect(ob) + "还是请回吧。师傅恨死叛徒了。");
        return;
    }
    if((string)ob->query("gender")==("无性"))
    {
        command("say 你不男不女，怎能领悟我派的高深武功。 ");
        command("say " + RANK_D->query_respect(ob) + "还是请回吧。");
        return;
    }
    command("say 好吧" + RANK_D->query_respect(ob) + "我就收下你了。 \n");
    command("recruit " + ob->query("id"));
    if((string)ob->query("gender")!="女性")
      			ob->set("title",RED "桃花岛" NOR + HIW +" 第三代弟子" NOR);
	        else
      			ob->set("title",RED "桃花岛" NOR + YEL +" 第三代弟子" NOR);
			ob->set_title(TITLE_RANK, ob->query("title"));
    return;
}
void init()
{
    object ob;
    ::init();
    ob = this_player();
    if ((int)ob->query("PKS") > 3)
    {
        command("say 我师傅虽然人称黄老邪，可桃花岛的人从不乱杀人。 ");
        command("expell" + ob->query("id"));
    }
    add_action("do_learn", "learn");
}

int do_learn()
{
    mapping fam;
    object ob = this_player();
    if( (int)ob->query("shen") < -10000 && mapp(fam = ob->query("family") ) &&  fam["master_id"] == "cheng ying")
    {
         command("say 你屡次在外杀戮良民，败坏我的名声。我不会教你这个徒弟。 \n");
         return 1;
    }
    return 0;
}

int ask_san()
{
    mapping fam; 
    object ob;
    object me = this_player();
    if (!(fam = me->query("family") ) || (fam["family_name"]!="桃花岛"))
    {
        say("程英说道："+RANK_D->query_respect(me) + "你非本派弟子，从何提起此事？\n");
        return 1;
    }
    if ( me->query("score") < 400 )
    {
        say("程英说道：你对本派贡献不够，本派的灵药现在不能给你。\n");
        return 1;
    }
    if (query("san_count") < 1)
    {
        say("程英说道：现在我这没有田七鲨胆散。\n");
        return 1;
    }
    add("san_count",-1);
    ob = new("/d/taohuadao/obj/shadan-san");
    if (!me) return 1;
    ob->move(me);
    say("程英说道：我这包田七鲨胆散你就拿去吧。\n");
return 1;
}
int ask_jing()
{
    mapping fam;
    if (!(fam=this_player()->query("family")) || (fam["family_name"] != "桃花岛"))  
    {
        say("程英说：“你非本派弟子，从何提起此事。”\n");
        return 1;
    }
    else
    {
        say("程英说道：我这里没有九阴真经，郭大哥那好象有吧。\n");
        this_player()->set_temp("marks/经",1);
        return 1;
    }
}
int ask_jia()
{
    mapping fam;
    if (!(fam=this_player()->query("family")) || (fam["family_name"] != "桃花岛"))  
    {
        say("程英说：“你非本派弟子，从何提起此事。”\n");
        return 1;
    }
    else
    {
        say("程英说道：师傅将软猬甲给了我的师姐。\n");
        this_player()->set("marks/甲",1);
        return 1;
    }
}   
int ask_rong()
{
    mapping fam;
    if (!(fam=this_player()->query("family")) || (fam["family_name"] != "桃花岛"))  
    {
        say("程英说：“你非本派弟子，从何提起此事。”\n");
        return 1;
    }
    else
    {
        say("程英说：“她是我师姐，现在大概在清啸亭吧。”\n");
        this_player()->set_temp("marks/蓉",1);
        return 1;
    }
}

void heal()
{
    object ob=this_player();
    if(ob->query("eff_qi") < ob->query("max_qi"))
    {
        command("exert heal");
        command("enforce 100");
        return;
    }
    if(ob->query("qi") < ob->query("eff_qi"))
    {
        command("exert recover");
        return;
    }
    if(ob->query("jing") < ob->query("eff_jing"))
    {
        command("exert regererate");
        return;
    }
}
