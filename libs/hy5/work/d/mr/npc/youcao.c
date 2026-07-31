// /u/beyond/mr/npc/youcao.c 幽草
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("幽草", ({ "you cao", "cao", "you" }));
        set("gender", "女性");
        set("age", 20);      
	set("title",GRN"丫鬟"NOR);
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
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("yanling-shenfa",70);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
     
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt1")->wear();
        set("inquiry", ([
            "name" : "我就是曼佗罗山庄的丫鬟幽草。\n",
            "here" : "这里是曼佗罗山庄，难道你没有听说过？\n",
            "rumors" : "花肥房的严妈妈经常用人做花肥，千万别让他看见你。\n",
            "阿朱" : "阿朱住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
            "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
            "王语嫣" : "王姑娘是我家小姐。\n",
            "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
            "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
            "曼佗罗山庄" : "这里就是曼佗罗山庄了。\n",
            
       ]));                 
        set("chat_chance",20);
       set("chat_msg",({
                "幽草自言自语到：“千万别让严妈妈看见你，要不会把你作成花肥的。”\n",
                
        }) );        
}