//NPC 欧阳克
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
#include "info_beauty.h"

void heal();
string ask_camel();
string ask_job();
int ask_fail();
void reward_dest(object obj,object ob);
void destroy_dest(object obj,object ob);
void destroy_staff(object obj,object ob);
void thank_dest(object obj,object ob);
void destroy_beauty(object ob);
string ask_life();

void create()

{
	seteuid(getuid());
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身白衣，轻裘缓带，神态甚是潇洒，双目斜飞，面目俊雅，却又英气逼人。\n"
                   "身上服饰打扮，俨然是一位富贵王孙。\n");
	set("title", HIG"白驼山"NOR+HIB"少庄主"NOR);
	set("nickname", HIM "玉面蛇心" NOR);
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 35);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 500000);
	set("score", 40000);

	set_skill("hand", 120);
	set_skill("dodge", 150);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("staff", 130);
	set_skill("strike", 120);
 	set_skill("training", 100);
 	set_skill("poison", 100);
            set_skill("literate", 120);

	set_skill("hamagong",160);
	set_skill("chanchu-bufa", 150);
	set_skill("shexing-diaoshou", 130);
       set_skill("shentuo-zhang", 130);
	set_skill("lingshe-zhangfa", 120);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("hand", "shexing-diaoshou");
	map_skill("strike", "hamagong");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");

	prepare_skill("strike","hamagong");

    create_family("白驼山",2,"弟子");
	set("inquiry", ([
                "骆驼" : (: ask_camel :),
              "白骆驼" : (: ask_camel :),
                "坐骑" : (: ask_camel :),
               "camel" : (: ask_camel :),
	    "白驼山庄" : "这里就是白驼山。\n",
	      "白驼山" : "这里就是白驼山。\n",
 	      "欧阳锋" : "他是我叔父,他老人家现在在白驼山。",
	        "失败" : (: ask_fail :),
                "fail" : (: ask_fail :),
  	        "工作" : (: ask_job :),
	        "job" : (: ask_job :),
	        "girl" : (: ask_life :),
		   ]));

	setup();
	set_temp("job_pos",10);
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",80);
}

      void attempt_apprentice (object ob)
{
     int exp;

   if((string)ob->query("family/family_name")!="白驼山")
   {
command("say " + RANK_D->query_respect(ob) + "若想入我白驼山，可先拜钱眼开。\n");
   return;
    }
//   if((int)ob->query("score")<400)
//   {
//  command ("say 你自问是否对本门尽力了?");
//   return;
//   }

  if((string)ob->query("family/master_name") == "欧阳锋")
   {
     command("say " + RANK_D->query_respect(ob) + "不敢当、不敢当。\n");
   return;
    }
   if((int)ob->query("shen")>-10000)
   {
    command("say 你行事不够狠毒，若" + RANK_D->query_respect(ob) + "能多杀几个人给我看看......\n");
   return;
      }
      if((int)ob->query("betrayer")>=2)
   {
   command("say 你多次判师，我怎么能够收你!\n");
   return;
    }
   if((int)ob->query("combat_exp")<50000)
    {
     command("say 你再练几年吧!");
     return;
    }

       command("say 好吧，我就收下你吧.\n");
       command("recruit " + ob->query("id"));
 exp = (int) ob->query("combat_exp");
   if (ob->query("gender") == "女性") {
	   ob->set("title" ,HIG"白驼山"NOR+HIB"女管家"NOR);}
  else if( exp<=150000 && ob->query("age") <= 20) {
       ob->set("title",HIG"白驼山"NOR+HIB"小管家"NOR);
        }
    else if (exp<=150000 && ob->query("age") >= 20) {
       ob->set("title" ,HIG"白驼山"NOR+HIB"管家"NOR);
        }
    else {
       ob->set("title",HIG"白驼山"NOR+HIB"总管"NOR);
    }
}

string ask_camel()
{
        object ob, me=this_player();

        if (me->query("family/family_name")!="白驼山") {
                command("say 你是哪里来的" + RANK_D->query_rude(me) +
                        "到我们庄来混食？快给我滚！");
                command("kick " + me->query("id"));
                return ("小心我宰了你！");
        }

        if (me->query_temp("白骆驼") || present("camel",me) || me->query_temp("mark/驼")){
                return("你不是有坐骑了吗？");
        }

	if (query("camel_count") > 5)
                return("骆驼都让你师兄弟们骑走了，"+ RANK_D->query_respect(me)+
                       "要回山，等他们回来在说吧。");

        ob=new("/d/baituo/npc/camel");
        ob->move(environment(me));
        ob->set_lord(me);
	 add("camel_count", 1);
        me->set_temp("mark/驼", 1);
                command("nod");
                say("欧阳克从身边的树丛里牵出一匹骆驼来交给你。\n");
		return(RANK_D->query_respect(me) + "路上小心，早去早归！");
}

int ask_fail()
{
        object ppl=this_player(),me=this_object();
		int sc=random(10)+1;
        if(!ppl->query_temp("baituo/feeding"))
        {
                write ("我没有让你去牧蛇啊，你记错了吧？\n");
                return 1;
        }
        write("欧阳克叹了口气，说道：算了，这次就饶了你吧！\n");
        ppl->delete_temp("baituo/feeding");
        ppl->add("score",-sc);
        tell_object(ppl,"你对"+ppl->query("family/family_name")+"的忠诚度降低了"+chinese_number(sc)+"点。\n");
        return 1;
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

string ask_job()
{
	mapping job_stat;
	object ob2;
	object ob = this_player();
	object me = this_object();
	object guaishe,staff,here=environment(me);
	int good_skill;

	job_stat = ob->query_temp("baituo/feeding");

	if ( ob->query("family/family_name") != "白驼山" )
		return RANK_D->query_rude(ob)+"莫非别有用心！\n";

	if( ob->is_busy() ){
		command("hmm "+ob->query("id"));
		return "你还在忙着干别的事呢！\n";
	}

	if( job_stat ){
		command("hmm "+ob->query("id"));
		return "你还没干完活呢!\n";
	}
        if( ob->query_skill("training",1) < 10 ) {
		return "你的驯兽术等级太低，我派的怪蛇可不能交给你。\n";
	}
         if( ob->query("max_jingli") < 50 ) {
                return "你的精力不足，无法控制怪蛇。\n";
        }
	if( ob->query("score") >= 1500)
	{
		command("ah " + ob->query("id"));
		return "你现在已经没有必要干这种工作了！\n";
	}

	ob->start_busy(random(4));

        good_skill = (int)( pow(ob->query("combat_exp")*10,0.33333) * 0.6 )  ;

       if( ob->query("combat_exp") > 20000 && ( ob->query_skill("force",1) < good_skill ) ) {
                command("say 你去好好练习一下基本内功吧！");
                return "基本功扎实才能练成本派的独门绝技蛤蟆功！\n";
		}

	if( ob->query("combat_exp") > 5000 &&
	ob->query("max_neili") < ob->query_skill("force") * 5 ) {
		command("say 你内力不够，去好好打坐一下吧！");
		return "内力越高，蛤蟆功的威力就越大。\n";
		}

          if( ob->query("family/master_name") == "欧阳锋" ) {
		return "你现在已经可以独立饲养怪蛇了。\n";
		}

	if ( me->query_temp("job_pos") == 0 ) {
		if(random(12) == 1)
		me->set_temp("job_pos",1);

		return "现在没什么事，你自个儿晃荡去吧。\n";
	}

	me->add_temp("job_pos", -1);

	command("nod");
	command("say 好，我这里有一只奇毒的怪蛇，"+ob->query("name")+"你拿去好好调养。");
	command("say 这怪蛇吃鸟类、吸人血。越是所谓名门正派的高手的气血越是滋养怪蛇。");
	command("hehe");
	command("say 它吃饱了以後，就会乖乖的爬进蛇杖里成为天下最厉害的兵器。");

       ob2 = new(__DIR__"obj/guaishe");
       ob2->move(ob);
       ob2->set_owner(ob);
       tell_object(ob,"欧阳克给你一只"+ob2->query("name")+"。\n");
       ob2->set("master_id",ob->query("id"));

       staff = new(__DIR__"obj/gshezhan");
       staff->move(ob);
       tell_object(ob,"欧阳克给你一把"+staff->query("name")+"。\n");
       ob->set_temp("baituo/feeding",1);
       staff->set("master_id",ob->query("id"));
       return "千万别弄丢了！\n";
}
int accept_object(object me, object obj)
{
		object ob = this_player();
		int reduce, bonus = 100;
		int sc, pot, exp, rep, shen;
        	string beauty;

		if (obj->query("id") == "guai she")
		{
			call_out("destroy_dest", 1, obj, ob);
			return 1;
		}

		if ( obj->query("id") == "guai shezhang")
		{
			ob->start_busy(1);
			if ( ob->query("family/family_name") == "白驼山" ) {
				if( obj->query("snake")>0 )
					call_out("reward_dest", 1, obj, ob);
				else
					call_out("destroy_staff", 1, obj, ob);
			}
			else {
				call_out("thank_dest", 1, obj, ob);
			}
			return 1;
		}

		if(stringp(beauty = ob->query("baituo/beauty")))
		{
			if(obj->query("money_id") && obj->value() >= 2500)
             		{
				message_vision("$N叹道：罢了罢了，这么点小事都办不成！\n", this_object());
                   		ob->delete("baituo/beauty");
                   		return 1;
             		}
			if(obj->name() != ob->query("baituo/beauty"))
             		{
				message_vision("$N大怒道：滚！我要的不是这个人！\n", this_object());
                   		return 0;
             		}
			if(userp(obj))
             		{
				message_vision("$N大怒道：想用这套来蒙骗我，门都没有！\n", this_object());
                   		return 0;
             		}
			if(!obj->is_character())
             		{
				message_vision("$N大怒道：这种烂东西你留着自己用吧！\n", this_object());
                   		return 0;
             		}
        		if( obj->query("gender") != "女性" )
             		{
				message_vision("$N大怒道：本少爷对人妖没兴趣！\n", this_object());
                   		return 0;
             		}

        		reduce = ((int)obj->query("eff_qi")*100)/(int)obj->query("max_qi");
        		if ( reduce < 20 )
             		{
				message_vision("$N大怒道：都伤的只剩下半条命了，你自己留着慢用吧！\n", this_object());
                   		return 0;
             		}

        		if (reduce == 100) bonus = 120;
        		exp = info_beauty[beauty] * bonus;
        		pot = exp / 8;

			if(ob->query("family/family_name") == "白驼山")
			{
				if(ob->query("combat_exp") < 10000)
				{
					sc = 1;
					shen = 100;
					exp = exp / 100;
					pot = exp / 8;
				}
				else if(ob->query("combat_exp") < 100000)
				{
					sc = 2 + random(4);
					shen = 500;
					exp = exp * (2 + random(2))/100;
					pot = exp /8;
				}
				else if(ob->query("combat_exp") < 500000)
				{
					sc = 4 + random(8);
					shen = 800;
					exp = exp * (3 + random(3))/100;
					pot = exp /8;
				}
				else
				{
					sc = 8 + random(12);
					shen = 1200;
					exp = exp * (4 + random(5))/100;
					pot = exp /8;
				}
       				ob->add("score", sc);
	   			ob->add("combat_exp", exp);
	   			ob->add("potential", pot);
	   			ob->add("shen", - shen);
       				tell_object(ob,"你对"+ob->query("family/family_name")+"的忠诚度提高了"+chinese_number(sc)+"点。\n");
       				tell_object(ob,"你的经验增加了" + chinese_number(exp) + "点。\n");
       				tell_object(ob,"你的潜能增加了" + chinese_number(pot) + "点。\n");
       				tell_object(ob,"你的道德下降了。\n");
       				ob->delete("baituo/beauty");
       				call_out("destroy_beauty", 1, obj);
       				return 1;
			}
			else
			{
				if(ob->query("combat_exp") < 10000)
				{
					rep = 50;
					shen = 100;
					exp = exp / 100;
					pot = exp / 8;
				}
				else if(ob->query("combat_exp") < 100000)
				{
					rep = 30 + random(70);
					shen = 500;
					exp = exp * (2 + random(2)) / 100;
					pot = exp /8;
				}
				else if(ob->query("combat_exp") < 500000)
				{
					rep = 80 + random(220);
					shen = 800;
					exp = exp * (3 + random(3)) / 100;
					pot = exp /8;
				}
				else
				{
					rep = 200 + random(300);
					shen = 1200;
					exp = exp * (4 + random(5)) / 100;
					pot = exp /8;
				}
       				ob->add("repute", - rep);
	   			ob->add("combat_exp", exp);
	   			ob->add("potential", pot);
	   			ob->add("shen", - shen);
       				tell_object(ob,"你的经验增加了" + chinese_number(exp) + "点。\n");
       				tell_object(ob,"你的潜能增加了" + chinese_number(pot) + "点。\n");
       				tell_object(ob,"你的道德下降了。\n");
       				tell_object(ob,"你的江湖声望下降了。\n");
       				ob->delete("baituo/beauty");
       				call_out("destroy_beauty", 1, obj);
       				return 1;
			}
		}

		command( "hmm" );
		command( "say 你给我这东西做什麽？" );

		return 0;
}

void reward_dest(object obj,object ob)
{
        int sc = random(6) + 5;
        int exp, pot;
        if (obj->query("master_id") != ob->query("id"))
        	command("say 你拿着别人的蛇杖作什么！？");
	else {
		command( "pat "+ob->query("id"));
		command( "say "+ob->query("name")+"干的还不错，这样多干活，将来本少爷一定会赏你的！\n");
		if(ob->query("gender") == "女性" )
		command( "kiss1 " + ob->query("id") );
	       ob->add("score",sc);
	       tell_object(ob,"你对"+ob->query("family/family_name")+"的忠诚度提高了"+chinese_number(sc)+"点。\n");
	       pot = sc * sc * (random(5) + 1);
		   ob->add("potential", pot);
	       tell_object(ob,"你的潜能提高了" + chinese_number(pot) + "点。\n");
		   exp = sc * sc * (random(ob->query("kar"))+1);
		   if (exp > 2000) exp = 2000;
		   ob->add("combat_exp",exp);
	       tell_object(ob,"你的经验值提高了" + chinese_number(exp) + "点。\n");

		if(ob->query_temp("baituo/feeding",1) )
		{
			ob->delete_temp("baituo/feeding");
			add_temp("job_pos", -1);
		}
	}
      	destruct(obj);
}


void destroy_staff(object obj,object ob)
{
	command( "hmm" );
	command( "kick "+ob->query("id") );
	command( "say 怎么就这样还给我？蛇呢？小心少爷我赏你一蛇杖！" );
	command( "angry" );

	destruct(obj);
}

void destroy_dest(object obj,object ob)
{
	command( "hmm" );
	command( "kick "+ob->query("id") );
	command( "say 怎么就这样还给我？应该喂饱变成蛇杖再交给我。小心少爷我赏你给蛇吃！" );
	command( "angry" );

	if(ob->query_temp("baituo/feeding",1) )
	{
		ob->delete_temp("baituo/feeding");
		add_temp("job_pos", -1);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "ah");
	command( "say 本少爷的蛇杖？多谢啦！\n");
	destruct(obj);
}

string ask_life()
{
        object me = this_player();
        string *beautys, beauty;

        if( is_fighting() || is_busy())
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        if ( me->query("combat_exp") < 5000 )
        {	command("shake "+me->query("id"));
        	return "你才这两下子恐怕无法胜任这事。";
        }
        if ( me->query("combat_exp") > 800000 )
        {	command("shake "+me->query("id"));
        	return "你经验太高，没必要作这个了。";
        }

        if( stringp(me->query("baituo/beauty")))
        {
        command("slap " + me->query("id"));
        return "先把上一个任务完成了再说，实在做不了就给钱取消吧。";
        }

        if( time() < (int)query("baituo/joytime"))
        {
        if (random(2))
        {        command("lazy");
                 return "我最近对此没有兴趣。";
        }
        command("shake");
        return "我这里没事干了，你下去吧。";
        }

        beautys = keys(info_beauty);
        beauty = beautys[random(sizeof(beautys))];

        command("hehe " + me->query("id"));
        me->set("baituo/beauty", beauty);
        set("baituo/joytime", time() + 60 + random(20));
        return "最近我想" + beauty + "这娘们想得睡不着觉？你去把她抓来给我解解馋。";
}
void destroy_beauty(object ob)
{
	 destruct(ob);
}
