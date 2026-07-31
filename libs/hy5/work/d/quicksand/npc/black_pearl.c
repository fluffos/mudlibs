 // TIE@FY3
inherit NPC;
int give_letter();
void create()
{
        set_name("黑珍珠", ({ "black pearl", "pearl" }) );
        set("title", "大漠飞鹰");
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "黑发，黑纱，黑袍，黑靴，黑鞭\n"
                );
       set("chat_chance", 2);
        set("chat_msg", ({
                "黑珍珠说道：看到小楚没有？我有一封重要的书信要给他！\n",
        }) ); 
        set("inquiry", ([
                "书信": (: give_letter :),
                "letter": (: give_letter :)
        ]) );
        set("attitude", "peaceful");
        set_skill("whip", 100);
        set_skill("thunderwhip", 100);
        set("combat_exp", 120000);
        setup();
        carry_object(__DIR__"obj/shenxue")->wear();
        carry_object(__DIR__"obj/baojia")->wear();
        carry_object(__DIR__"obj/zhiai")->wear();
        carry_object(__DIR__"obj/sidai")->wield();
}
int give_letter()
{
        object obj;
if( !query("given"))
        {
command("say 既然你你愿意帮忙将此信送给小楚，那就拿去吧！可别丢了！\n");
obj = new(__DIR__"obj/letter");
obj->move(this_player());
set("given",1);
        }
else
{
command("say 咦？我那封信怎么不见了？是不是你偷了？还给我！\n");
        fight_ob(this_player());
}
        return 1;
} 
void reset()
{
delete("given");
}      
