// jiang-yaoting.c 江耀亭  处理玩家离婚
// by llm 99/06
#include <ansi.h>
inherit NPC;
int do_unmarry(string arg);
int zou(object me);
int do_kill();
int do_chat();

void create()
{
	set_name("江耀亭", ({ "jiang yaoting", "jiang" }));
	set("title", "汝州知府");
   set("gender", "男性");
   set("age", 43);
   set("str", 20);
   set("dex", 20);
   set("long", "他就是江耀亭，汝州现任知府，因红娘庄在其辖境，亲手负责玩家离婚之事。\n");
   set("combat_exp", 30000);
   set("shen_type", 0);
   set("attitude", "heroism");

   set_skill("unarmed", 50);
   set_skill("force", 50);
   set_skill("sword", 50);
   set_skill("dodge", 50);
   set_skill("parry", 50);
   set_temp("apply/attack", 150);
   set_temp("apply/defense", 150);
   set_temp("apply/armor", 150);
   set_temp("apply/damage", 150);

   set("neili", 500);
   set("max_neili", 500);
   set("jiali", 10);

   setup();
//   carry_object("/clone/weapon/gangjian")->wield();
   carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
   add_action("do_chat", "chat");
   add_action("do_chat","chat*");
   add_action("do_unmarry","unmarry");
   add_action("do_kill",({"kill","fight","hit","touxi"}));
}

int accept_object(object me, object ob)
{
   if (!ob->query("money_id"))
     	return notify_fail("江耀亭冷冷地看了你一眼道：“是不是活得不耐烦了，敢拿本知府开玩笑？！”\n");
  	if(ob->value() < 1000000)
	      return notify_fail("江耀亭皱了皱眉头说道：“你记性不好还是怎么着？100 gold，少一文也别想办！”\n");
	message_vision("江耀亭接过钱点点说：“好吧！我们来办理吧！”\n",me);
	this_object()->set_temp("money",me->name());
  	return 1;
}

int do_chat()
{
   object me;
   me=this_player();

   message_vision(HIW "江知府脸色一沉，惊堂木一拍喝道：“大堂之上，竟敢喧哗！来人呀！”\n"
   "“在！”两边衙役齐声应道。江耀亭一指$N喝道：“把他给我重打二十大板！”\n"NOR,me);
   call_out("zou",1,me);
   return 0;
}

int zou(object me)
{
   message_vision(HIW"一群衙役冲上前来，不由分说，把$N掀翻在地，一阵大板随即跟上……\n"NOR,me);
   tell_object(me,HIR"你刚发现不对，四肢已经被按牢在地，只觉一板板打得你痛入骨髓……\n"NOR);
	if((int)me->query("combat_exp")>10000
   	&&(int)me->query("qi")>20)
   {
		me->receive_damage("qi", 20);
		me->receive_wound("qi",  20);
   }
   else
      me->unconcious();
  	return 1;
}

int do_kill()
{
	object ob;
	int i;

	command("say 大胆，竟敢在公堂上动武，来人呀！");
	message_vision("四周的衙役立刻群起对$N发动攻击！\n", this_player());

	for(i=0; i<4; i++)
   {
		if( objectp( ob = present("ya yi " + (i+1), environment(this_object())) ) )
			ob->kill_ob(this_player());
		else
      	this_object()->kill_ob(this_player());
	}
	return 1;
}

int do_unmarry(string arg)
{
	object me, obj,ob,*inv;
mapping my_skl;
string *skl_name;
int i,*level;

	me = this_player();
	if (me->is_busy())
		return notify_fail("江知府眉头一皱说道：“你看看你自己那个忙样！”\n");

	if( me->is_fighting() )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me);
		return notify_fail("江耀亭怒火中烧：“大胆逆贼，来来来，本官送你去阴间去离婚！”\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("江知府说道：“你先退下，等本官处理了这里捣乱的人再说！”\n");

	if( !living(this_object()) )
		return notify_fail("你还是先想办法把知府大人救醒吧。\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("知府哼了一声说道：“急什么？等本官升堂了再说！”\n");

   if(me->query_temp("unmarry"))
   	return notify_fail("江耀亭黑着脸看看你：“本官不是刚刚帮你们办过离婚手续？还来烦我！？”\n");

	if( !mapp( me->query("couple") ) || !me->query("couple/have_couple") )
	{
		if ((string)me->query("gender") == "女性")
			say("江耀亭脸一沉喝道：“大胆刁妇，你分明没有丈夫，还敢戏弄本官，来人呀！打她二十大板！”\n");
		else
			say("江耀亭脸一沉喝道：“大胆刁民，你分明没有妻室，还敢戏弄本官，来人呀！打他二十大板！”\n");
      call_out("zou",1,me);
      return 1;
	}
   if(!arg||arg!=(string)me->query("couple/couple_id"))
   	return notify_fail("江知府皱了皱眉头：你要和谁离婚？\n");
//   ob = new(LOGIN_OB);
//	ob->set("id",(string)me->query("couple/couple_id"));
//	if( !ob->restore() )
	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + ".o")<0 )
   {
       message_vision("江耀亭听了$N的陈述，仔细查看了案卷，点点头道：“既然你的爱人已经不在人世，我就给你\n"
       "单独办理离婚手续，钱也不必要交了！”然后在案卷上作了记录后，盖上了官印，对师爷招手\n"
       "道：“送一份给红娘庄！”然后又对$N说：“你走吧，你已经是单身了！”\n",me);
		CHANNEL_D->do_channel(this_object(), "mudnews",
		sprintf( "经本府明查：由于%s的配偶已经去世，他们的婚姻关系自然解除！\n", me->name()));
		me->add("couple/unmarried", 1);
      me->set("couple/have_couple",0);
        me->set("couple/couple_id", 0);
        me->set("couple/couple_name", 0);
        me->set("couple/couple_gender", 0);
      return 1;
   }
	else if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
                 || !find_player(me->query("couple/couple_id")) )
		return notify_fail("江知府懒懒地看了看你道：“你的爱人现在不在场，要两人一起来才能办离婚。”\n");

   if(query_temp("money")!=me->name()
   	&&query_temp("money")!=obj->name())
   	return notify_fail("江知府拍了拍桌子：“离婚的手续费100 gold你还没交，没钱就回去凑合着过日子，不要来烦本官！\n");

	if( (object)obj->query_temp("pending/unmarry")!=me )
	{
		me->set_temp("pending/unmarry", obj);
		message_vision(MAG "\n$N看了看$n长叹一口气道：“罢罢罢……我们还是好聚好散吧！?”\n"
			"江耀亭眯起眼睛问问$n：“你愿不愿意离婚呢？说出来，本官为你作主！”\n"NOR,me,obj);
      tell_object(obj,"如果你同意离婚，请你也对"+me->name()+ "("+(string)me->query("id")+
                       	")"+ "下一次 unmarry "+(string)me->query("id")+"  的指令。\n");
		write(MAG "现在你正等待着你的伴侣的回答...\n" NOR);
		return 1;
	}
	message_vision(MAG "\n$N对著$n哼了一声说道：“事已至今，既然无缘，咱们就各走各的路吧。”\n\n"NOR, me,obj);
   me->set_temp("unmarry",1);
   obj->set_temp("unmarry",1);
	message_vision(HIY "江耀亭看了看点点头说道：“$N和$n，既然你们都同意离婚，那本官也就给你们办了！”\n"
   	"说完，在姻缘簿上重重地划去了两个名字。\n" NOR, obj, me);
	CHANNEL_D->do_channel(this_object(), "mudnews",
	sprintf( "经本府宣判：从今天起，%s和%s的婚姻关系解除！\n", me->name(), obj->name()));

      me->set("couple/have_couple",0);
        me->set("couple/couple_id", 0);
        me->set("couple/couple_name", 0);
        me->set("couple/couple_gender", 0);

        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
                  }

        obj->set("couple/have_couple",0);
        obj->set("couple/couple_id", 0);
        obj->set("couple/couple_name", 0);
        obj->set("couple/couple_gender", 0);
//        my_skl=obj->query_skills();
//        if(mapp(my_skl)) {
//        		skl_name = keys(my_skl);
//        		level=values(my_skl);
//        		for (i=0;i<sizeof(skl_name);i++)
//{
//if (level[i]>3)
//        		obj->set_skill(skl_name[i],level[i]-2);
//}
//                  }

	return 1;
}
