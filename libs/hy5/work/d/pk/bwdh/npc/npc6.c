//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("小张无忌", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    set("title",HIG "明教"HIM"教主"NOR);
    set("gender", "男性");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 36);
    set("int", 36);
    set("con", 30);
    set("dex", 30);

    set("qi", 4050);
    set("max_qi", 4050);
    set("jing", 4050);
    set("max_jing", 4050);
    set("neili", 18000);
    set("max_neili", 18000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("cuff", 250);
    set_skill("jiuyang-shengong", 300);
    set_skill("qiankun-danuoyi", 300);
    set_skill("qishang-quan", 300);
    set_skill("shenghuo-shengong", 300);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");

    create_family("明教",34, "教主");

    set("chat_chance",2);
    set("chat_msg",({
 "张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
        "张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
        "张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield ling") :),
                (: command("unwield ling") :),
                (: command("wield ling") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
    set("inquiry",([
	  "明教" :     "明教正在编写之中，请君稍候。\n",
          "金毛狮王" : "那是我义父谢大侠的职司。\n",
          "谢逊" :     "他就是我义父的大号。\n",
          "张翠山" :   "你想找我父亲有事麽? \n",
          "殷素素" :   "我妈是明尊座下紫微堂主。\n",
          "张三丰" :   "我太师父近来可好? \n",
          "赵敏" :     "人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?\n",
          "小昭" :     "小昭我可一直念着她的好处。\n",
          "周芷若" :   "找她就去峨嵋山, 别来烦我。\n",
    ]));
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
    add_money("silver",70);
}

