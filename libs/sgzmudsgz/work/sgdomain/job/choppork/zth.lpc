//张屠户 by row
#include <ansi.h>
#include <mudlib.h>
#define PCHOPPORK PJOB+"choppork"
#define JOBID "choppork"
inherit LIVING;
void ask_job(object usr);
void ask_pay(object usr);
void ask_meat(object usr);
void setup()
{
	set_name("zhang tuhu","张屠户");
	add_id("zhang");
	add_id("tuhu");
	set_in_room_desc("「"+HIC+"华阴第一快刀"+NOR+"」张屠户(zhang tuhu)");
	set_gender(1);
	set_age(45);
	add_question("job","job");
	add_question("pay","pay");
	add_question("meat","meat");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_ask_str("meat","$N对$T道：张师傅，您给我的肉用完了，您看能不能再给些？\n");
	add_ask_str("job","$N对$T道：这位$R，$s我想找些活干。\n");
	add_ask_str("pay","$N对$T陪笑道：$R，您看。。。\n");
}
string long() {
	return "一位膀大腰圆的中年汉子，上身只披了一件褡裢，露出发达的\n"+
	       "胸肌，布满老茧的手中操着一柄雪亮的杀猪刀，他就是华阴有\n"+
	       "名的张屠户。别看他外表凶悍，但是心地善良，常给穷人们一\n"+
	       "些活干，以接济他们(ask zhang about job)。\n";
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
	  case "meat":
                ask_meat(player);
		    return;
        case "rumors":
                this_object()->simple_action("$N『嘿嘿』一笑，露出贼白的牙齿："+
"别的不知道，俺只晓得俺是华阴第一快刀。\n");
                return;
        case "name":
                this_object()->simple_action("$N大大咧咧地道："+
"俺叫张铁柱，专卖上好的猪肉，想当年俺的祖爷爷也。。。\n");
                return;
        case "here":
                this_object()->targetted_action("$N大手上下一指："+
"俺把铺子摆到这块儿来，就是因为大树底下好乘凉。\n",ob);
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
        "$N对$T道：快去干你的活吧。\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N『哈哈』大笑：别开玩笑了，$m$R想吃肉尽管吱声，俺这就给您送去。\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N对$T道：行了行了，你今天干的切猪肉的活够多的了，该歇会儿了。\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N对$T道：嗯，这么多肉俺一人还真忙不过来。俺最少要二十块猪肋排，喏，这\n"+
        "块肉给你，切得要整齐，不好的俺可不收。要是不巧肉用完了，就再问俺拿。\n"+
	  "(ask zhang about meat)\n",usr);
        this_object()->targetted_action(
        "$N交给$T一柄"+HIC+"剔骨刀"+NOR+"和一片%^B_WHITE%^%^H_RED%^大猪肋%^RESET%^。\n",usr);
        ob=new("/sgdomain/job/choppork/tigudao");
        ob->move(usr);
	  oc=new("/sgdomain/job/choppork/lmeat");
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
        "$N『嘿嘿』一笑：想蒙俺，没门。\n");
        this_object()->targetted_action(
        "$N给$T一张百圆纸钱。\n",usr);
        usr->simple_action("$N傻傻地直乐：终于有钱了！\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$N眉开眼笑：不错，不错。\n");
        this_object()->targetted_action("$N给$T十五两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(15);
        ob->move(usr);
        if(random(2)) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N又对$T道：这次活干得尤其出色，再奖励一张贴子。\n",usr);
        }
        }
}
void ask_pay(object usr)
{
        object ob;
        object tigudao,meat;
        string n_id;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N脸一沉，对$T道：你开什么玩笑？\n",usr);
           return;
        }
        ob=present("pork",usr);
        tigudao=present("tigudao",usr);
	meat=present("meat",usr);
        if(!objectp(ob))
        {
           this_object()->targetted_action(
           "$N脸一沉，对$T道：你开什么玩笑？\n",usr);
           return;
        }
        if(ob->query_count()<20)
        {
            this_object()->targetted_action(
            "$N对$T大摇其头：还不够数，你再去切些来。\n",usr);
           return;
        }
        else
        {
            this_object()->targetted_action(
            "$N接过$T递过来的%^B_WHITE%^%^H_RED%^猪肋排%^RESET%^。\n",usr);
            destruct(ob);
            if(tigudao)
                {
                this_object()->simple_action(
                "$N伸手要回了"+HIC+"剔骨刀"+NOR+"。\n");
                destruct(tigudao);
                }
		if(objectp(meat))
			{
			this_object()->simple_action(
			"$N拿回了剩下的肉。\n");
			destruct(meat);
			}
        this_object()->targetted_action(
        "$N对$T点点头，道：很好，但俺还要给你出道题考考你。\n",usr);
        usr->finish_job(JOBID);
        ROBOT->robot_test(usr,(:award:));
        }
}
void ask_meat(object usr)
{
        object ob,pork,smeat;
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N脸一沉，对$T道：想骗俺的肉？没那么容易！\n",usr);
           return;
        }
        ob=present("meat",usr);
        pork=present("pork",usr);
        if(objectp(ob)||objectp(smeat))
        {
           this_object()->targetted_action(
           "$N嘴一撇，对$T道：刚才给你的肉还没切完，怎么又向俺要了？\n",usr);
           return;
        }
	if(objectp(pork))
	{
        if(pork->query_count()>20||pork->query_count()==20)
        {
            this_object()->targetted_action(
            "$N拍拍$T的头，道：哎，你已经切完了，不必再向俺要肉了(ask zhang about pay)。\n",usr);
           return;
        }
	  else
        {
            this_object()->targetted_action(
            "$N对$T点点头，道：好吧，再给你一块，这回要小心切了，知道吗？\n"+
		"$N递给$T一块%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^。\n",usr);
            smeat=new("/sgdomain/job/choppork/smeat");
		smeat->move(usr);
        }
	}
	  else
        {
            this_object()->targetted_action(
            "$N对$T点点头，道：好吧，再给你一块，这回要小心切了，知道吗？\n"+
		"$N递给$T一块%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^。\n",usr);
            smeat=new("/sgdomain/job/choppork/smeat");
		smeat->move(usr);
        }
}