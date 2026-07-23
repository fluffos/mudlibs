// By Batman @ Freedom Studio 2001/6/6

inherit NPC;
#include <ansi.h>

int chatmsg();
int mz();
int here();
int rumors();
int batman();
int maggie();
int ada();
int soledad();
int jane();
int doma();
int text_draw();
int text();
int draw();
int dragon();
int tiger();
int phoenix();
int turtle();

int sword();
int skills();
int jade();
int heal();

void create()
{
        set_name("红衣少女", ({ "red girl","red","girl" }) );
        set("gender", "女性" );
        set("age", 24);
        set("int", 30);
        set("str",60);
        set("per", 35);
        set("long",
"这是一名身着红衣的少女，她杏眼桃腮，肌肤胜雪，玉手纤纤，有一头乌
云也似的长发，一直拖至腰间。她正笑盈盈地看着你，水汪汪的眸子令你
神醉。
"
                );
        create_family("天仙阁", 2, "侍女");
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2000);

        set("max_jing", 2000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 120);
        set("combat_exp", 9999999);

        set("chat_chance", 1);
        set("chat_msg", ({
        (: chatmsg :),
        }) );

        set("inquiry", ([
                "name" : (: mz :),
                "晴儿" : (: mz :),
                "qing er" : (: mz :),
                "maggie" : (: maggie :),
                "晴晴" : (: maggie :),
                "batman" : (: batman :),
                "天下有敌" : (: tod :),
                "ada" : (: ada :),

                "soledad" : (: ada :),
                "凝兰" : (: ada :),
                "兰儿" : (: soledad :),
                "lan er" : (: soledad :),
                "颖姐" : (: jane :),
                "xiao ying" : (: jane :),
                "小玛" : (: doma :),
                "xiao ma" : (: doma :),
                "天清" : (: sword :),
                "地宁" : (: sword :),
                "字画" : (: text_draw :),
                "字" : (: text :),
                "text" : (: text :),
                "画" : (: draw :),
                "drawing" : (: draw :),
                "青龙" : (: dragon :),
                "dragon" : (: dragon :),
                "白虎" : (: tiger :),
                "tiger" : (: tiger :),
                "朱雀" : (: phoenix :),
                "phoenix" : (: phoenix :),
                "玄武" : (: turtle :),
                "turtle" : (: turtle :),

                "here" : (: here :),
                "天仙阁" : (: here :),
                "rumors" : (: rumors :),
                "武功" : (: skills :),
                "玉佩" : (: jade :),
                "朱雀玉佩" : (: jade :),
                "痛" : (: heal :),
                "疗伤" : (: heal :),
                "解毒":"中毒了么？解毒我可不会，你找颖姐吧！",
                "疗毒":"中毒了么？解毒我可不会，你找颖姐吧！",
        ]));

        setup();
        carry_object(__DIR__"obj/r_cloth")->wear();
        carry_object(__DIR__"obj/p_pei")->wear();
        carry_object(__DIR__"obj/zhuxiao")->wield();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )

        {
                remove_call_out("welcome");
                call_out("welcome", 1, ob);
        }
}

void welcome(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
        if ((string)this_player()->query("id") == "tod") 
        {
                command("say 公子爷，你回来啦！");
                message_vision("$N高兴地跳进$n的怀里。\n",this_object(),this_player());
        }
        else
        {
                if ((string)this_player()->query("id") == "maggie")
                        command("say 晴晴姐，你来啦！公子爷天天念叨着你呢！");
                else
                {
                        if ((string)this_player()->query("id") == "ada")
                                command("say 凝兰姐，你来啦！公子爷想得你紧呢！");

                        else command("say 有贵客到。");
                }
        }
}

int chatmsg()
{
        command("giggle");
}

int mz()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                set("title",HIR"千娇百媚"NOR);
                set_name("晴儿",({"qing er","qing"}));
                command("say 公子爷又拿晴儿寻开心了。好坏，好坏哟~~~ \n");
                message_vision("$N倚偎在$n怀里撒起娇来。\n", this_object(), me);
        }
        else
        {

                if ((string)me->query("id") == "maggie")
                {
                        command("say 晴晴姐，你来找妹子玩么？"); 
                        set("title",HIR"千娇百媚"NOR);
                        set_name("晴儿",({"qing er","qing"}));
                }
                else
                {
                        if ((string)me->query("id") == "ada")
                        {
                                command("say 凝兰姐找妹子玩么？");
                                set("title",HIR"千娇百媚"NOR);
                                set_name("晴儿",({"qing er","qing"}));
                        }
                        else command("say 人家的名字是公子爷给取的，只有公子爷能叫！");
                }
        }
        return 1;
}

int here()
{
        command("xixi");

        command("say 这里就是咱们公子爷的天仙阁呀！");
        return 1;
}

int rumors()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod")
        {
                command("say 听说公子爷又在外面认识了好多漂亮的女孩子，是不是真的呀？");
                message_vision("$N小嘴一嘟，满脸的不高兴。\n", this_object());
        }
        else
                command("say 好像没有耶！" + RANK_D->query_respect(me) + "有什么有趣的事能说给人家听的吗？");
        return 1;
}

int batman()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 

        {
                command("say 哦！你说的就是那个整天钻在女孩子堆里的小子呀？");
                message_vision("$N对着$n笑得花枝乱颤。\n", this_object(), me);
        }
        else
        {
                if ((string)me->query("id") == "maggie")
                        command("say 嘻嘻！晴晴姐，你找我们公子爷呀！"); 
                else
                {
                        if ((string)me->query("id") == "ada") 
                                command("say 嘻嘻！凝兰姐还是掂记着我们公子爷的呀！");
                        else
                        {
                                command("say 放肆，我们公子爷的名讳是你叫的嘛？");
                                message_vision("$N很生气的看着$n。\n", this_object(), me);
                        }
                }
        }
        return 1;
}

int maggie()

{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                command("say 公子爷又在想晴晴姐姐啦！嘻嘻，羞羞！\n");
                message_vision("$N顽皮地用手指在$n的脸上刮来刮去。\n", this_object(), me);
        }
        else
        {
                if ((string)me->query("id") == "maggie") 
                        command("say 嗯…啊…你说的是那个住在隔壁，叫我们公子爷日思夜想的大美女么？嘻！");
                else
                {
                        command("say 你找晴晴姐姐呀！她就住在隔壁，不过我是不会告诉你怎么过去的。");
                        message_vision("$N把头一撇，只顾看窗外的风景。\n", this_object(), me);
                }
        }
        return 1;
}

int ada()
{

        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 公子爷想凝兰姐姐啦！为什么不去找她呢？凝兰姐可是个好女孩哟！\n");
        else
        {
                if ((string)me->query("id") == "ada")
                        command("say 凝兰姐呀！虽然你好些天没来了，小妹也不会就忘了你呀！"); 
                else
                {
                        command("say 你找凝兰姐姐呀！她就住在隔壁，不过只有公子爷知道怎么去她房里哟！");
                        message_vision("$N发出一阵银铃般的笑声。\n",this_object());
                }
        }
        return 1;
}

int soledad()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 
                command("say 哟！公子爷连兰儿也认不出了，兰儿又要哭鼻子了呀！\n");

        else
                command("say 嘻嘻，兰儿就是我们中的一个，你猜得出是哪个吗？");
        return 1;
}

int jane()
{
        object me, ob, obj;
        me = this_player();
        ob = this_object();
        if (present("white girl", environment(ob)) || present("xiao ying", environment(ob)))
                command("say 颖姐不是在那儿嘛！");
        else
        {
               if ((string)me->query("id") == "tod")
                {
                        command("say 颖姐吗？");
                        message_vision("$N喊道：颖姐~~公子爷找你呐！\n“来啦！”一名白衣女子飘然而至。\n", ob);
                }
                else
                {
                        command("say 嘻嘻，你找颖姐吗？");
                        message_vision("$N喊道：颖姐~~\n“来啦！”一名白衣女子飘然而至。\n",ob);

                }
               if (((obj = find_living("white girl")) || (obj = find_living("white girl"))) && (sizeof(children("/u/tod/npc/jane")) > 1))
                {
                        message_vision("$N急急忙忙地离开了。\n", obj);
                        obj->move(environment(ob));
                }
                else
                {
                        obj=new(__DIR__"jane");
                        obj->move(environment(ob));
                }
        }
        return 1;
}

int doma()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 小玛不就在那儿嘛！公子有事自个儿和她说吧！");
        else
                command("say 嘻嘻，小玛就是我们中的一个，你猜得出是哪个吗？");

        return 1;
}

int text_draw()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                command("say 知道啦！公子爷的字画最宝贝，我不动就是啦！");
                message_vision("$N顽皮地扮了个鬼脸。\n",this_object());
        }
        else
                command("say 字画吗？我只伺侯公子爷的起居，那些是兰儿管的事儿。");
        return 1;
}

int text()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 公子爷写的是什么呀？好深奥哟！");

        else
                command("say 那是我们公子爷的墨宝。");
        return 1;
}

int draw()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 
        {
                command("say 公子爷画得真好看，改天也替人家画一幅。");
                message_vision("$N冲$n摆了个姿势。\n", this_object(), me);
        }
        else command("say 嘻嘻，那是我们公子画的。");
        return 1;
}

int dragon()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 

                command("say 那到底有什么秘密呀？公子爷告诉人家嘛~~~~~~");
        else command("say 这是我们天仙阁的秘密，不--告--诉--你--");
        return 1;
}

int tiger()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 那到底有什么秘密呀？公子爷告诉人家嘛~~~~~~");
        else command("say 这是我们天仙阁的秘密，不--告--诉--你--");
        return 1;
}

int phoenix()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 那到底有什么秘密呀？公子爷告诉人家嘛~~~~~~");
        else command("say 这是我们天仙阁的秘密，不--告--诉--你--");
        return 1;

}

int turtle()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 那到底有什么秘密呀？公子爷告诉人家嘛~~~~~~");
        else command("say 这是我们天仙阁的秘密，不--告--诉--你--");
        return 1;
}

int sword()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 公子爷忘了带佩剑嘛？");
        else
                command("say 那是我们公子爷的佩剑，你可别打主意。");
        return 1;
}


int skills()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 人家很乖，天天都有练哦！");
        else
                command("say 人家的武功都是公子爷教的，公子爷的武功最好了。");
        return 1;
}

int jade()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say 公子爷送的东西，人家自然天天带在身上喽！");
        else command("say 嘻嘻！那是公子爷送给人家的。");
        return 1;
}

int accept_fight(object me)
{

        if ((string)me->query("id") == "tod")
        {
                command("say 嘻嘻！公子爷是不是又想趁机吃人家豆腐呀？");
                message_vision("$N倚偎在$n怀里撒起娇来。\n",this_object(),me);
        }
        else
        {
                if ((string)me->query("gender")=="男性") 
                {
                        command("say 哼！你准是想趁机吃人家豆腐，人家才不上当呢！");
                        message_vision("$N狠狠地白了$n一眼。\n", this_object(), me);
                }
                else command("say 会痛耶！人家不想打嘛！");
        }
        return 0;
}

void attempt_apprentice(object me)
{
        if ((string)me->query("id") == "batman") 
        {
                command("say 公子爷又取笑人家了。");
                message_vision("$N被$n吓了一跳。\n", this_object(), me);

        }
        else command("say 天仙阁的武功可不外传哦！");
}

int heal()
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if (((int)me->query("eff_qi") < (int)me->query("max_qi"))
                || ((int)me->query("eff_jing") < (int)me->query("max_jing")))
                {
                        command("say 受伤了么？我瞧瞧。");
                        message_vision(HIW"$N把$n扶到石台上一阵摆弄。\n"NOR, ob, me);
                        me->set("eff_jing", me->query("max_jing"));
                        me->set("jing", me->query("max_jing"));
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi", me->query("max_qi"));
                        tell_object(me, HIG"虽然手法怪异，却让你觉得说不出的受用。\n"NOR);
                }       
        else command("say 人家看你无病无伤的，少来这里骗人。");
        return 1;

}
