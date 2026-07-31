
inherit NPC;

void create()
{
        set_name( "皇后" , ({ "queen"}));
        set("shen_type", 0);
        set("age",19);
        set("gender", "女性");
        set("per",28);
        set("long",
                "生得一张莺蛋似的脸儿，两道弯弯的乌眉，映着那黑棋子的眼睛，\n"+
"真是沉鱼落雁，闭月羞花的姿色。因为刚与皇帝举行大婚，所以\n"+
"整天笑容满面，神采飞扬。。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}



