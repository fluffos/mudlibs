// /u/chen/murong/npc/bao.c 包不同
// this is made by chen

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int auto_perform();
void create()
{
	set_name("包不同",({"bao butong","bao","butong"}));
	set("title","金凤庄庄主");
  	set("long", 
              "他就是慕容复的结拜兄弟人称非也先生的包不同。\n");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 46);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 10);
	set("combat_exp", 850000);

	set_skill("force",120);
	set_skill("dodge",120);
	set_skill("blade",180);
	set_skill("sword",120);
	set_skill("strike",120);
	set_skill("parry",120);
	set_skill("literate",120);
	set_skill("douzhuan-xingyi",120);
	set_skill("murong-shenfa",120);
	set_skill("murong-daofa",180);
	set_skill("murong-jianfa",120);
	set_skill("xingyi-zhang",120);

	map_skill("strike","xingyi-zhang");
	map_skill("force","douzhuan-xingyi");
	map_skill("parry","douzhuan-xingyi");
	map_skill("dodge","murong-shenfa");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");

	prepare_skill("strike","xingyi-zhang");

 	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
                (: auto_perform :),
	}) );

	create_family("姑苏慕容", 19, "传人");

        set("inquiry", ([
            "name" : "非也，非也，我就是姑苏慕容金凤庄庄庄主包不同。\n",
            "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
            "rumors" : "慕容公子的以彼之道，还施彼身天下闻名。\n",
            "阿朱" : "阿朱住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
            "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
            "王语嫣" : "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。\n",
            "邓百川" : "邓百川是我大哥。\n",
            "公孙乾" : "公孙乾是我二哥。\n",
            "风波恶" : "风波恶是我四弟，他就是喜欢跟别人打架。\n",
            "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
            "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
            "曼佗罗山庄" : "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。\n",
            "还施水阁" : "这是燕子坞的秘密之所在，我可不便对你说。\n",       
       ]));
	setup();
	carry_object("/d/murong/obj/qingyi")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
#include "/kungfu/class/murong/master.h"
#include "/kungfu/class/murong/auto_perform.h"