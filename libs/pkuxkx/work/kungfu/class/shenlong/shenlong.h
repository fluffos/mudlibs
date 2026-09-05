// shenlong.h for join shenlongjiao
#include <ansi.h>;
#include <title.h>
int do_join(string arg)
{
        object me, ob, obj ;
        string men;
        mapping party;

        me = this_object () ;
        ob = this_player () ;

        if( !arg || arg!="shenlongjiao" )
                return notify_fail("你要加入什么组织？\n"); 

        if ((int)ob->query("shen") > 1000)
        {
        message_vision(HIR"$N对$n大怒道：还想入教？一看你就不是好人! \n"NOR,me,ob);
                return 1;
        }

//      if( !mapp(party = ob->query("party")) || party["party_name"] != HIY "神龙教" NOR )
        if(  ob->query("party") && ob->query("party/party_name") != MAG "神龙教" NOR )
        {
                message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我神龙教。\n",me,ob);
                return 1;
        }
        if( ob->query("party/party_name") == HIY "神龙教" NOR )
        {
                message_vision("$N摇摇头，对$n说道：你已经是我神龙教的人了。\n",me,ob);
                return 1;
        }
        
        if(mapp(ob->query("family")))
                        {
         message_vision("$N摇摇头，对$n说道：你已经加入其他门派了，不能再入我神龙教。\n",me,ob);
                return 1;
                        }
                        
        if(ob->query("dex")<20)
                        {
         message_vision("$N摇摇头，对$n说道：我们神龙岛整天和神龙为伍，你的身板还不够灵巧。\n",me,ob);
                return 1;
                        }

        if(ob->query("combat_exp")>=100000 && ob->query("reborn/chushi")<1)
                        {
         message_vision("$N摇摇头，对$n说道：不敢，您还是走吧，神龙岛地方小，哪里容得下您？\n",me,ob);
                return 1;
                        }
        
        if ( (string)ob->query("gender") == "女性" ) men=HIR"赤";
        else
        {
                switch (random(4))
                {
                case 0 : men=HIC"青"; break;
                case 1 : men=HIW"白"; break;
                case 2 : men=BLK"黑"; break;
                default: men=HIY"黄"; break;
                }
        }
        party = allocate_mapping(5);
        party["party_name"] = MAG "神龙教" NOR;
        party["rank"] = men+"龙使"NOR"座下教众";
        party["level"] = 1;
        party["tasks"] = 0;
        party["enter_time"] = time();
        ob->set("party", party);
	      ob->set("family", (["family_name": "神龙教",]));
        ob->set("title",MAG "神龙教" NOR+men+"龙使"NOR"座下教众");
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        ob->set("class","shenlong");
        command("smile");
        write("\n");
        message_vision("$N对$n说道：你就暂时在"+men+"龙使"NOR+"座下效力吧！\n", me, ob);

        return 1;
}


