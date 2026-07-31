#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李半仙", ({ "li banxian", "li" , "banxian"}) );
        set("long",
"李半仙是个鹤发童颜的老人！乐于助人，你可以向他打听[减叛师]的情况。\n");
        set("title", BLU"疯疯癫癫"NOR);
        set("attitude", "peaceful");
        set("combat_exp",4000000);
        set("str",60);
        set("per",10);
        set("int",80);
        set("force_factor", 100);
        set("max_force",5000);
        set("force",5000);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu-bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing-diaoshou",200);
        set_skill("lingshe-zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu-bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");
        
        set("inquiry", ([
                "减叛师记录"          :"你找对人了，就是我能给你减叛师记录(jian 判师记录)。\n",
                "叛师"          :"唉，后悔背叛师门了吧。\n",
                "叛师记录"          :"要是你以前曾经有过一次叛师师门的话，你的师傅可不愿意教你更高深的功夫！\n",
                "减叛师"          :"你找对人了，就是我能给你减叛师记录(jian 叛师记录)。\n",
                "减记录"          :"你找对人了，就是我能给你减叛师记录(jian 叛师记录)。\n",
        ]) );
        setup();


}
int accept_object(object who, object ob)
{
        int kar, per;

        if (ob->query("money_id") && ob->value() >= 1000) 
        {
                message_vision("李半仙对着$N端详了一阵。\n", who);
                per = who->query("per");
                kar = who->query("kar");
                if (per > 20) {
                        write("李半仙景仰地说：“看" + RANK_D->query_respect(who) + "相貌堂堂，天庭饱满，地廓方圆，"); 
                        if (kar > 40) write("天机不可说写,不可说.....”\n");
                        else if (kar > 30) write("真乃天人神佛之象也！”\n");
                        else if (kar > 27) write("真乃天子之象也！”\n");
                        else if (kar > 25) write("真乃绝世之材之象也！”\n");
                        else if (kar > 20) write("真乃富贵之象也！”\n");
                        else if (kar >= 17) write("一生运势平平，也算过得去了。”\n");
                        else if (kar >= 13) write("可惜冲撞了小人。”\n");
                        else write("不过你霉运当头，行事可要小心了！”\n");
                        return 1;
                }
                else if (per >= 17) {
                        write("李半仙清了清嗓子，说：“看" + RANK_D->query_respect(who) + "相貌属中上之资，"); 
                        if (kar > 40) write("天机不可说写,不可说.....”\n");
                        else if (kar > 30) write("真乃天人神佛之象也！”\n");
                        else if (kar > 27) write("真乃天子之象也！”\n");
                        else if (kar > 25) write("真乃绝世之材之象也！”\n");
                        else if (kar > 20) write("一生大富大贵，子孙多多。”\n");
                        else if (kar >= 17) write("一生运势平平，也算过得去了。”\n");
                        else if (kar >= 13) write("就可惜冲撞了小人。”\n");
                        else write("不过你霉运当头，行事可要小心了！”\n");
                        return 1;
                }
                else if (per >= 13) {
                        write("李半仙有点勉强地说：“看" + RANK_D->query_respect(who) + "相貌平平，倒也还能算是中人之资，");
                        if (kar > 40) write("天机不可说写,不可说.....”\n");
                        else if (kar > 30) write("真乃天人神佛之象也！”\n");
                        else if (kar > 27) write("真乃天子之象也！”\n");
                        else if (kar > 25) write("真乃绝世之材之象也！”\n");
                        else if (kar > 20) write("前生一定行了善事，一生大富大贵，子孙多多。”\n");
                        else if (kar >= 17) write("一生也就运势平平，只能算过得去。”\n");
                        else if (kar >= 13) write("就可惜冲撞了小人。”\n");
                        else write("你最近霉运当头，行事可要小心了！”\n");
                        return 1;
                }
                else {
                        write("李半仙很厌恶地说：“看" + RANK_D->query_respect(who) + "五官挪位，印堂发暗，");
                        if (kar > 40) write("天机不可说写,不可说.....”\n");
                        else if (kar > 30) write("真乃天人神佛之象也！”\n");
                        else if (kar > 27) write("真乃天子之象也！”\n");
                        else if (kar > 25) write("真乃绝世之材之象也！”\n");
                        else if (kar > 20) write("不过你前生一定行了善事，一生大富大贵，子孙多多。”\n");
                        else if (kar >= 17) write("倒还有些运气，也算过得去了。”\n");
                        else if (kar >= 13) write("所以你就一生坎坷，多遇小人。”\n");
                        else write("活该倒霉，当有血光之灾！”\n");
                        return 1;
                }
        }
        return 0;
}


int accept_fight(object me)
{
        command("say 李半仙说：你还不配和我过招。");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me= this_player();
        if (arg != "叛师记录") 
                return notify_fail("你要减什么？\n");
        if (me->query("betrayer",) < 1) 
                return notify_fail("你叛过师么？\n");
        if (me->query("banshi") > 2) 
                return notify_fail("你的叛师次数已经超过3次了！\n");

       if ( me->query("banshi") > 2)
           {
               message_vision("你的叛师次数已经超过3次了！！\n", this_object(), me);
                   return 1;
           }
me->save();
if ((int)me->query("combat_exp") > 500000)
{
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>1)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
}
        message_vision(MAG"$N跪在了地上，开始忏悔背叛师门的往事，后悔呀。。。后悔。。。\n\n"NOR,me);
        me->add("betrayer",-1);
        me->add("banshi", 1);
//        me->add("banshi",1);
//        me->set("title","普通百姓");
//        me->set("class","0");
//        me->delete("family");
//        me->delete("party");
        me->start_busy(2);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}

