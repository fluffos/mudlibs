#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    set("nickname", HIW "铁仙姑"NOR);
    set("gender", "女性");
    set("class","huashan");
    create_family("华山派", 16, "掌门");
    set("student_title","弟子");
    set("age", 59);
    set("str", 45);
    set("int", 30);
        set("per", 3);
    set("con", 25);
      set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
            set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    
    setup();
    carry_object("/d/tieflag/qianfo/npc/obj/black_suit")->wear(); 
} 
void init()
{
        ::init();
        add_action("do_open","open");
} 
void apprentice_me(object player)
{
        object kumei;
        kumei = this_object();
        message_vision("$N冷笑一声：“你居然能跟到这里来了。\n",kumei);
        message_vision("$N似乎在打量$n。\n\n",kumei,player);
        message_vision(YEL"突然你听到黑衣人用冷森森的声音对$n说：“你知道了太多的秘密，恐怕不能
再让你活着走出这里。你要指望活下去，只有拜入我门下，严遵师令，不可
泄露半点机密。”（ａｃｃｅｐｔ　ｙｅｓ／ｎｏ）\n"NOR,kumei, player);
        set("marks/inquiry",1);
        add_action("do_accept","accept");
        call_out("auto_kill",60,player);
}  
void auto_kill(object player)
{
        object kumei;
        kumei = this_object();
        delete("marks/inquiry");
        if(interactive(player) && present(player, environment(kumei))){
                message_vision("$N阴森森地说道：“容不得你犹豫了。”\n",kumei);
                call_out("check_status",2,player);
                kumei->kill_ob(player);
                kumei->command("perform zhaixin");
        } else {
                message_vision("$N哼了一声，双足一点，飞掠而去。”\n",kumei);
                destruct(kumei);
        }
}  
void check_status(object player)
{
        object kumei;
   kumei = this_object();
        if (interactive(player) && present(player,environment(kumei))){
                message_vision("\n$N不可置信地看着$n道：“你竟能躲过我这一招！！她一定是瞒下了心法要诀。。。
好，今天就暂且放过你。”\n",kumei,player);
        }
        message_vision("$N哼了一声，双足一点，飞掠而去。”\n",kumei);
        destruct(kumei);
}  
int do_accept(string arg)
{
        object player,kumei;
        player = this_player();
        kumei = this_object();
        if (arg != "yes" && arg != "no"){
                return 0;
        }
        if (!query("marks/inquiry")){
                return 0;
        }
        remove_call_out("auto_kill");
        delete("marks/inquiry");
        if (arg == "yes")
        {
                player->set("marks/忠诚",-1);
                tell_object(player,"你看看周围，一片静寂，没有半点声音。你心想，还是先活下去吧。 \n");
                message_vision("$N说道：“好，我愿拜你为师。”\n",player);
                kumei->command("remove suit");
                message_vision("$N满意地笑了起来，“我知道你不会让我失望的。”\n",kumei );
                call_out("after_apprentice",2,player);
        } else if (arg == "no") {
                message_vision("\n$N退了一步，摇摇头说：“我拜得天，拜得地！怎么能拜你这样鬼鬼祟祟的人为师！？”\n",player);
                message_vision("黑衣人狞笑道：“好！看招！！”\n", player);
                call_out("check_status", 2 , player);
                player->set("marks/忠诚",1);
                kumei->kill_ob(player);
                kumei->command("perform zhaixin");
        }
        return 1;
}  
void after_apprentice(object player)
{
        object kumei;
        kumei = this_object();
        if (player && present(player,environment())){
                if (player->query("class") == "huashan"){
                        message_vision("$N道：“好！好！，以后要将本门发扬光大。”\n",kumei);
                } else {
                        message_vision("$N道：“你现在还不是可造之才。但看在你忠心可鉴的份上，你走吧！”\n",kumei);
                }
        }
        message_vision("$N双足一点，飞掠而去。\n”",kumei);
        destruct(kumei);
} 
int do_open(string arg)
{
        object player;
        player = this_player();
        if(arg != "幔布" && arg != "curtain") {
                return 0;
        }
        message_vision("$N冷冷地瞪了$n一眼，道：“你想干什么？”\n",this_object(),player);
        return 1;
}  
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        if(killer->query("marks/忠诚")== -1) killer->set("marks/kill_kumei", 1);
    ::die();
} 
