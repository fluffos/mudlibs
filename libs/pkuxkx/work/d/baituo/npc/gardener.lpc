// guafu.cc
inherit NPC;
void create()
{
        set_name("花匠", ({ "gardener","hua jiang" }) );
        set("gender", "男性" );
        set("age", 67);
        set("long", "这是一位饱经风霜的老人，他看起来貌不惊人，但是似乎有着不同寻\n"
                   +"常的经历！但是这样一位老人为什么会在白驼山庄做花匠呢？\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 30);
        set("dex", 30);
        set("con", 20);
        set("int", 20);
        set("kar", 22);
        set("attitude", "friendly");
        set("chat_chance",5);
        set("chat_msg",({
            "老花匠在这里走来走去，不紧不慢的侍弄这些牡丹花。\n",
            "老花匠抬头看看天空，又不紧不慢的干自己的活计去了。\n",
           }) ); 
  //这个npc要加个秘密，可以问并完成一定的东东，奖励本书什么的 :-)
        setup();
        carry_object("/clone/misc/cloth")->wear();

}
