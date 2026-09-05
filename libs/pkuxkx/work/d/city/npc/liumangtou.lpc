// liumangtou.c 流氓头

inherit NPC;

void create()
{
	set_name("流氓头", ({ "liumang tou", "liumang", "liu" }));
	set("gender", "男性");
	set("age", 25);
	set("long", "他长得奸嘴猴腮的，一看就不像是个好人。\n");
	
	set("combat_exp", 7000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

        set("inquiry", ([
                "name" : "大爷我的名字是你叫得的么！",
                "here" : "此地是扬州，大爷我的地盘。",
                "rumors" : "听说最近砸场子的少了，银子都不好收了。",
                "银子" : "在老子的地盘上开店，每月交例银五十两，否则，嘿嘿！",
                "例银" : "在老子的地盘上开店，每月交例银五十两，否则，嘿嘿！",
                "流氓" : "我是流氓，我怕谁？",
                "香蕉" : "香蕉大人令人景仰不已啊！",
                "地盘" : "上个月跟那群叫化子打了一架，地盘又被抢去一块，哼，走着瞧！",
                "叫化子" : "那群叫化子也真奇怪，一个个穿的破破烂烂的，打起架来还真有两下子。",
                "窑子" : "每次咱收了例银就去丽春院转转，不过就是没几个瞧得上眼的。",
                "倩儿" : "方圆千里以内著名的美女，口水～～～～",
		"砸场子" : "我们帮内的事，你别管。",
        ]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
