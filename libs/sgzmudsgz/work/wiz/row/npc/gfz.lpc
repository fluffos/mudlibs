//关夫子 by row
#include <ansi.h>
#include <mudlib.h>
#define PMAKEDOUFU PJOB+"makedoufu"
#define JOBID "makedoufu"
#define MUTONG PJMAKEDOUFU+"mutong"
#define S_ROOM "/a/huayin/vmill"
inherit LIVING;

object room;
object mutong;
void ask_soybean(object usr);
void ask_job(object usr);
void ask_pay(object usr);
void ask_meat(object usr);
void ask_cruet(object usr);
void setup()
{
	set_name("guan fuzi","关夫子");
	add_id("guan");
	add_id("fuzi");
	set_in_room_desc("\n「%^B_WHITE%^"+HIG+"翡翠豆腐"+NOR+"」关夫子(guan fuzi)");
	set_gender(1);
	set_age(45);
	add_question("job","job");
	add_question("pay","pay");
	add_question("makedoufu","makedoufu");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_question("soybean","soybean");
	add_question("cruet","cruet");
	add_ask_str("soybean","$N对$T道：关师傅，不巧黄豆用完了，能不能再给点儿？\n");
	add_ask_str("cruet","$N对$T道：关师傅，不巧卤用完了，能不能再给点儿？\n");
	add_ask_str("makedoufu","$N对$T道：关师傅，这个做豆腐，到底是怎么一回事？\n");
	add_ask_str("job","$N对$T道：这位$R，有什么我可以帮忙的吗？\n");
	add_ask_str("pay","$N对$T一拱手，道：$R，这个。。。钱的问题。。。\n");
}
string long() {
	return "一位身材高大的的中年汉子，身着麻布短褂，高高地卷着裤管\n"+
	       "子，脚踏一双草鞋，可普通的穿着遮掩不住他眉宇间一股逼人\n"+
	       "的英气，再加上颌下那飘逸的美髯，真如关公再造一般，难怪\n"+
	       "一些外乡人总是要弄错。关夫子平时在磨房里磨豆腐，他手艺\n"+
		 "一流，远近闻名(ask zhang about job)。\n";
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "job":
                ask_job(player);
                return;
        case "pay":
                ask_pay(player);
                return;
	case "soybean":
		ask_soybean(player);
		return;
	case "cruet":
		ask_cruet(player);
		return;
	  case "makedoufu":
                this_object()->simple_action("$N掳了掳颔下的长髯，道：你听仔细了。\n"+
			"先将黄豆放到石磨里磨碎研细(turn soy bean，push shimo)；\n"+
			"再将豆粉放到大锅里煮烂(turn shimo，wave fan)；\n"+
			"然后往大锅里放一点卤(turn cruet)；\n"+
			"最后将锅子里的豆浆倒入木桶冷却就可以了(turn guozi)。\n");
		    return;
        case "rumors":
                this_object()->simple_action("$N叹了口气："+
"关某足不出村已久，全不知晓外面的情形，惭愧，惭愧。\n");
                return;
        case "name":
                this_object()->simple_action("$N脸微微一红："+
"哎，我祖上姓关，贱名不提也罢。\n");
                return;
        case "here":
                this_object()->targetted_action("$N笑道："+
"此地乃是华阴唯一的磨坊，关某平时就在此做些豆腐。\n",ob);
                return;
        default:
                return;
        }
}
void ask_job(object usr)
{
        string n_id;
        int n_lasttimes,m_lasttimes;
        object ob,oc;
        n_id=usr->query_id()[0];
        if (usr->query_job(JOBID,"beg_time"))
        {
        this_object()->targetted_action(
        "$N对$T道：活儿已经交代过了，你快去做吧。\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N脸一沉：$R莫非是在戏弄与我？$T身为高官，不为国家百姓奔波，却为何四处闲逛？\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N对$T道：嗯，你今天做的豆腐够多了，可以歇息去了。\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N对$T点点头：好，这一袋黄豆先给你，你就给关某做一桶豆腐出来。\n"+
        "器皿都在这里了，你若是不明白怎么做，就问关某吧(ask guan about makedoufu)。\n"+
	"万一你还需要黄豆和卤，就向关某要吧(ask guan about soybean、ask guan about cruet)。\n",usr);
        this_object()->targetted_action(
        "$N交给$T一袋"+HIY+"黄豆"+NOR+"和一小瓶%^H_CYAN%^卤汁%^RESET%^，指了指地上的石磨(shimo)、灶头\n上的大锅子(guozi)、梁上挂着的大扇子(fan)和一旁的木桶(mutong)。\n",usr);
	usr->add_job(JOBID);
	usr->set_job(JOBID,"status","beg");
	ob=new("/sgdomain/job/makedoufu/soybean");
	oc=new("/sgdomain/job/makedoufu/cruet");
	ob->move(usr);
	oc->move(usr);
}
void award(object usr)
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action(
        "$N皱了皱眉：原来如此。\n");
        this_object()->targetted_action(
        "$N给$T一张百圆纸钱。\n",usr);
        usr->simple_action("$N高兴地跳了起来：终于有钱了！\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$N微微一笑：很好。\n");
        this_object()->targetted_action("$N给$T三十两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(30);
        ob->move(usr);
        }
}
void ask_pay(object usr)
{
        string n_id;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N一脸疑惑，对$T道：关某没让$R干过活吧？\n",usr);
           return;
        }
	room=load_object(S_ROOM);
	mutong=present("mutong", room );
	if(mutong->query_status()!=1)
	{
	this_object()->targetted_action(
	"$N对$T道：哎？你还没做完呢。\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N查看了一下木桶，满意的对$T道：做的好！\n$N高高兴兴地将木桶里的%^B_WHITE%^%^H_GREEN%^翡翠豆腐%^RESET%^收了起来。\n",usr);
	mutong->set_status();
	mutong->empty_it();
	this_object()->targetted_action(
	"$N对$T道：关某还要给你出道题。\n",usr);
	usr->finish_job(JOBID);
	ROBOT->robot_test(usr,(:award:));
}
void ask_soybean(object usr)
{
	object ob,soybean,shimo,guozi,mutong;
	int isfill1,isfill2,isfill3;
	object room;
	room = environment(this_body());
	guozi=present("guozi",room);
	shimo=present("shimo",room);
	mutong=present("mutong",room);
	if(!usr->query_job(JOBID,"beg_time"))
	{
	this_object()->targetted_action(
	"$N一脸疑惑：关某似乎没让$m$R干过活吧，这从何说起？\n",usr);
	return;
	}
	if(!objectp(guozi)||!objectp(shimo)||!objectp(mutong))
	{
	this_object()->targetted_action(
	"$N对$T一摇头：$R搞错了吧，这是在哪里呀？\n",usr);
	return;
	}
	soybean=present("soybean",usr);
	if(objectp(soybean))
	{
	this_object()->targetted_action(
	"$N对$T笑道：你不是有黄豆吗，为何又向关某要了？\n",usr);
	return;
	}
	isfill1=shimo->query_isfill();
	isfill2=guozi->query_isfill();
	isfill3=mutong->query_isfill();
	if(isfill1==1||isfill2==1||isfill3==1)
	{
	this_object()->targetted_actioin(
	"$N对$T笑道：$R你做得不错呀，已经不需要黄豆了。\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N对$T点点头：好吧，关某就再给你些黄豆，这回可别再浪费了。\n"+
	"$N递给$T一袋%^H_YELLOW%^黄豆%^RESET%^。\n",usr);
	ob=new("/sgdomain/job/makedoufu/soybean");
	ob->move(usr);
}
void ask_cruet(object usr)
{
	object ob,cruet,shimo,guozi,mutong;
	int islu;
	object room;
	room = environment(this_body());
	guozi=present("guozi",room);
	shimo=present("shimo",room);
	mutong=present("mutong",room);
	if(!usr->query_job(JOBID,"beg_time"))
	{
	this_object()->targetted_action(
	"$N一脸疑惑：关某似乎没让$m$R干过活吧，这从何说起？\n",usr);
	return;
	}
	if(!objectp(guozi)||!objectp(shimo)||!objectp(mutong))
	{
	this_object()->targetted_action(
	"$N对$T一摇头：$R搞错了吧，这是在哪里呀？\n",usr);
	return;
	}
	cruet=present("cruet",usr);
	if(objectp(cruet))
	{
	this_object()->targetted_action(
	"$N对$T笑道：你不是有卤吗，为何又向关某要了？\n",usr);
	return;
	}
	islu=guozi->query_islu();
	if(islu==1)
	{
	this_object()->targetted_action(
	"$N对$T笑道：$R你做得不错呀，已经不需要卤了。\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N对$T点点头：好吧，关某就再给你些卤，这回可别再浪费了。\n"+
	"$N递给$T一小瓶%^H_CYAN%^卤汁%^RESET%^。\n",usr);
	ob=new("/sgdomain/job/makedoufu/cruet");
	ob->move(usr);
}
