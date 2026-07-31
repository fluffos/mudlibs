//by mei

inherit NPC;

int ask_huolong();
string ask_hanyu();

void create()
{
        set_name("谢长风", ({ "xie changfeng" , "xie" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 46);
        set("long", "他实际上只有四十来岁，岁月的流逝和生活的磨难使他看\n"+
                    "起来已有六十多了。每当他完成一件精美的作品的最后一\n"+
                    "笔时，浑浊的眼眸就会闪出一丝亮光，一双巧手稳如磬石。\n");
        set("inquiry", ([
                "海洋之心" : "它是我先祖传下来的手艺，唉，不知道会不会从我这里失传啊。\n",
                  "火龙鞭" : (: ask_huolong :),
                "千年寒玉" : (: ask_hanyu :),
        ]));

        set("combat_exp", 2500);
        set("attitude", "friendly");
  
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int ask_huolong()
{
        object obj,ob = this_object();
        object me=this_player();
        
    if (present("huolong bian",me)){
        command("say 这位"+RANK_D->query_respect(me)+"不是已经得到火龙鞭了吗？");
        return 1;
    }
        if ( me->query("make_bian")){
            if (time() > me->query("make_bian")){
                message_vision("$N从腰间解下一条火龙鞭交给$n。\n",ob,me);
                obj=new("/clone/weapon/huolong-bian");
                obj->move(me);
                me->delete("make_bian");
                return 1;
            }else{
                message_vision(CYN+"$N说道：你的火龙鞭还没做好，晚点再来吧。\n",ob);
                return 1;
            }
        }else
        message_vision("$N浑浊的眼眸突然闪出一丝亮光，整个人“嗖”的一声跳了起来。\n"+
                       "大声叫道：“你怎么知道我会造火龙鞭的？你有千年寒玉吗？”\n", ob);
           return 1;   
}
string ask_hanyu()
{
        object ob = this_object();
        object me = this_player();
        
    if (present("huolong bian",me))
        return "这位"+RANK_D->query_respect(me)+"不是已经得到火龙鞭了吗？";
    message_vision("$N颓然倒在椅子上，叹道：“唉！千年寒玉。我们谢家不知死了多少人，还是得不到它啊！”\n", ob);
    command("cry xie changfeng");
    return "这位" + RANK_D->query_respect(me) + "，如果想找千年寒玉，去昆仑找吧！";
}
int accept_object(object me, object ob)
{
    if (userp(ob))  return 0;
    if (present("huolong bian",me)) return 1;
        if ( ob->id("han yu") ) {
                message_vision("$N捧着寒玉，激动得眼泪不住地往下流，咽呜着说道：\n"+
                               "多谢这位" + RANK_D->query_respect(me) + "，我终于见到寒玉了。\n"+
                               "不过做火龙鞭除了寒玉外，还要雪蚕丝和火龙筋。\n", this_object(),me);
                me->set_temp("tmark/鞭1", 1);
                return 1;
        }
        if ( ob->id("rousisuo") && me->query_temp("tmark/鞭1")) {
                message_vision("$N看了看$n送来的蚕丝，点了点头，说道：很好！很好！\n",this_object(),me);
                me->set_temp("tmark/鞭2", 1);
        }
        if ( ob->id("huolong jin") && me->query_temp("tmark/鞭1")) {
                message_vision("$N看了看$n送来的火龙筋，点了点头，说道：很好！很好！\n",this_object(),me);
                me->set_temp("tmark/鞭3", 1);
        }
        if (me->query_temp("tmark/鞭1") && me->query_temp("tmark/鞭2") && me->query_temp("tmark/鞭3")){
                message_vision("$N对着$n微一含颚，说道：很好！这位"+RANK_D->query_respect(me)+",明天这个时候来取鞭吧。\n",this_object(),me);
                me->delete_temp("tmark");
                me->set("make_bian",time()+86400);
        }
        return 1;
}

