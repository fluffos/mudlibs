// yufu.c
// [小弟妹 1999/11/4]

inherit NPC;
void consider();
int accept_object(object me, object ob);

void create()
{
        set_name("渔夫", ({ "yu fu","yu" }) );
        set("gender", "男性" );
        set("age", 22);
        create_family("侠客岛", 2, "弟子");
     set("inquiry", ([
                "侠客岛" : "怎么，你想去见我的师父，想找到那地方不太容易，只可惜我的船破了。。。唉！\n",
]));
        setup();
}
int accept_object(object me, object ob)
{
        object ling1;
        object ling2;
        if (ob->query("money_id") && ob->value() >= 50000)
     tell_object(me, "渔夫笑着说到：好吧，既然是有缘人，我就送你两件信物吧。\n");
  else
   {
      tell_object(me,"渔夫皱了皱眉，说道：“我不需要钱财！”\n");
    return 0;
  }
//        return 1;

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);

        return 1;
}