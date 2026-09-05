inherit NPC;
string inquiry_dao();
void create()
{
        set_name("老材", ({ "lao cai","cai" }) );
        set("gender", "男性" );
        set("nickname","老财");
        set("age", 55);
        set("long", 
                "这是一个有名的吝啬鬼，好象他整日看守着柴房也能发财似的。他无\n"
                "儿无女，光棍一条，孤苦零丁的，其实也挺可怜的，只是平常待人接\n"
                "物太过吝啬，搞的和这里的每个人关系都不是太好，只有厨娘肥肥经\n"
                "常帮他缝东缝西，拆拆洗洗，两人的关系倒还不错。\n"
           );
        set("shen_type",-1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 18);
        set("con", 18);
        set("int", 18);
        set("attitude", "friendly");
         set("count", 5);
        set("inquiry" , ([
        "柴刀" : (: inquiry_dao :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
string inquiry_dao()
{
 object me=this_player();
 object ob;
 if (present("chai dao",me))
   return "你身上带着一把，还想要！\n";

 if (!query("count")) return "我已经没有柴刀了。";
add("count",-1);
 ob=new("/d/baituo/obj/chaidao");
 ob->move(me);
 return "小心保管！\n老材递给你一把柴刀。\n";
}
