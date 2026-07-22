inherit NPC;
inherit F_VENDOR;

string ask_dan_1();
string ask_dan_2();

void create()
{
        set_name("道童", ({ "dao tong"}));
        set("long", 
                "这是一名武当派专门负责炼丹治药的小道童。\n");
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        
        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);
        set("combat_exp", 2000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set("inquiry", ([
                "药方" : "你想要知道什么药方啊？",
                "熬药" : "你想要知道什么药方啊？",
              "金创药" : (: ask_dan_1 :),
              "百草丹" : (: ask_dan_2 :),
                 "cht" : "他是武当派的掌门师尊，这你都不知道？！",
              "阿塔尔" : "他是武当派的掌门师尊，这你都不知道？！",
            "续命八丹" : "续命八丹可以使你气血充盈，精力旺盛！",
              "菩提子" : "据说吃了能使你的内力得到极大提升！",
          "白虎夺命丹" : "这可是救命的丸药啊，一般不容易得到！药方？你还去问问别人吧。",
          "玉露清心散" : "玉露清心散是慕容派的灵丹妙药，吃了能使内力和精力得到一定提高！",
          "九花玉露丸" : "九花玉露丸乃桃花岛的神药，吃了可以使人气血充盈！",
          "九转结气丸" : "据说是我派的圣药！但似乎好久没人吃到了。",
          "田七鲨胆散" : "这也是一种疗伤的灵药，吃了之后据说甭管大伤小伤全部都能治好！",
          "延年聚精丹" : "据说是我派的圣药，效果好象比九转结气丸更胜一筹，但我从来也没见过。",
          "九转还魂丹" : "你找巫师给你克隆吧！",
              "大还丹" : "你去少林寺找找吧，但据说不是少林弟子吃了也白搭。",
              "小还丹" : "你还是去向少林寺的和尚们打听一下吧！",
        ]));

        create_family("武当派", 5, "弟子");

        set("vendor_goods", ({
             ([ "name": MEDICINE_D("drug/baotai"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shouwu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/jugeng"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chuanbei"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shengdi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/mugua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/zanghonghua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/tianqi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shadan"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/xionghuang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/heye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/xuelianzi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/hugu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/fuling"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/baizhi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/renshen"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chantui"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/niuhuang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/huangqi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/gouji"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chaihu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/zhuye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/hua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/danggui"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/baiwei"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/fangfeng"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/huoxiang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/sangye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/tianhua"),"number" :10 ]),
        }));

        setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

string ask_dan_1()
{
        object ob = this_player();

        if(random(ob->query("kar",1)) > 20 && random(10) > 2 ){
            command("whisper " + ob->query("id") + " 好吧，我告诉你，你可千万不要告诉别人啊，否则……");
            command("whisper " + ob->query("id") + " 这金创药是由两份川贝，一份生地外加清水熬制而成的，");
            return "就是这样，知道了吧。";
        }
        return "对不起，掌门师尊不让我把药方泄露出去，否则我小命难保。";
}

string ask_dan_2()
{
        object ob = this_player();

        if(random(ob->query("kar",1)) > 20 && random(10) > 2){
           command("whisper " + ob->query("id")+ " 好吧，我告诉你，你可千万不要告诉别人啊，否则……");
           command("whisper " + ob->query("id")+ " 这百草丹是由两份藏红花，一份防风外加清水熬制而成的。");
           return "就是这样，知道了吧。";
        }
        return "对不起，掌门师尊不让我把药方泄露出去，否则我小命难保。";
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
