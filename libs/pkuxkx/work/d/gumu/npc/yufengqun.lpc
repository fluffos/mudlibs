// npc: yufengqun
// Jay 5/15/96

inherit NPC;

void create()
{
        set_name("玉蜂群", ({ "yufeng qun", "yufeng", "feng" }) );
        set("gender", "昆虫" );
	
        set("age", 14);
        set("long", 
            "这是一群很厉害的蜂子，见人就蛰。"
	   "\n");
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 50);
      

        set_skill("unarmed", 80);
	set_skill("force", 80);
        set_skill("dodge", 150);
	set_skill("sword",80);
	set_skill("parry",80);

        set("combat_exp", 100000);

        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
       
        setup();
        setup();
       
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
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

void greeting(object me)
{
  //  command("look " + me->query("id"));

    if ((int)me->query_skill("qufeng-shu",1)<50) {
       
       command("heng " + me->query("id"));
       message("vision", "这群玉蜂看见" + me->name() + "，忽拉拉全部向" + me->name() + "飞去。\n",
                environment(me), ({me}));
 //      me->move("/d/city/wumiao");
      		
       message("vision", me->name() +"看见一群蜂子冲了过来，自知难敌，不得不拔腿狂奔。\n", 
                environment(me), ({me}));

    }
/*    else {
    if (me->query("class") =="bonze") {
       command("say 呦，" + RANK_D->query_respect(me) 
                +"也来光顾我们丽春院啊。");
       command("say 想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
    }
    if (me->query("gender")=="女性") {
       command("say 哎呀，这年月大姑娘也逛窑子，成何体同。");
       command("sigh");
       command("say 可惜我儿子不在，不然让他伺候你。");
    }
    command("say 楼上楼下的姑娘们，客人来了！");
    }*/
    return;
}

