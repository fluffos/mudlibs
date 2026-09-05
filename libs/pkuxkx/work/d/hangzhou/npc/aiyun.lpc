// npc: /d/hangzhou/npc/aiyun.c
// by hubo

inherit NPC;

void create()
{
        set_name("爱云残", ({ "ai yuncan", "ai", "yuncan" }) );
        set("gender", "男性" );
     set("start_room","/d/hangzhou/lvyou");
  	set("nickname", "无良导师");
        set("age", 45);
        set("long", 
            "据说爱老板曾经是某私塾的高级教师，后来体罚学生\n"
	          "被开除了，不过现在卖旅游纪念品也很是赚钱的\n");
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "爱老师" : "阁下居然知道老朽身世，来让我给你讲讲我的历史",
            "历史" : "打学生，骂学生，侮辱学生，呵呵这对我来说都是皮毛",
       ]) );

        set("shen_type",1);set("score",200);setup();
        set("shen_type",1);set("score",200);setup();
       
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}