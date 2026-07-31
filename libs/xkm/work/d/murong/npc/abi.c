// /u/chen/murong/npc/abi.c 阿碧
//by chen

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("阿碧", ({ "a bi", "a", "bi" }));
        set("gender", "女性");
        set("age", 20);      
        set("title","慕容复贴身丫鬟");
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("per", 30);
        set("combat_exp", 13000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);

        set_skill("cuff", 80);
        set_skill("parry",80);
        set_skill("murong-shenfa",80);
        set_skill("dodge", 80);
        set_skill("force",80);
        set_skill("douzhuan-xingyi",80);

        map_skill("force","douzhuan-xingyi");
        map_skill("dodge","murong-shenfa");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
     
        carry_object("/d/murong/obj/shoe")->wear();
        carry_object("/d/murong/obj/red_silk")->wear();
        carry_object("/d/murong/obj/skirt1")->wear();
        set("inquiry", ([
            "name" : "我是慕容公子的贴身丫鬟，叫做阿碧，好久没有见到慕容公子了。\n",
            "here" : "这里是听香水榭，是慕容老爷照顾我给我安排的住处。\n",
            "rumors" : "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。\n",
            "曼佗罗山庄" : "离这里不远，有一小筑,名为听雨居，只要弹动琴弦，就可乘船前往。\n",
            "慕容复" : "慕容复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。\n",
            "听雨居" : "顺着小径一直往东走，就是听雨居了。\n",
 ]));   
                 set("chat_chance",5);
         set("chat_msg",({
"阿碧痴痴的说：“公子爷不知现在在哪，一切可好。”\n",
                            
        }) );

}
