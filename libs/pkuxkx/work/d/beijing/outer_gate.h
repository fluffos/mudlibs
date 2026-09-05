
// Room: /d/beijing/outer_gate.h

#include "beijing_defs.h"
string look_gaoshi();
int do_guard(string);
int gen_killer();
void reward_shiwei(int rank, object player);
int do_allow(string name);
int do_climb(string dir);
string get_killer();

string look_gaoshi()
{
    object me = this_object();
    if (me->query("night")) {
	return "夜间不得出入城门。爬墙者格杀勿论。\n\n" +
	get_killer();
    }else{
	return "九门提督谕：近天地会匪猖獗，" +
	    "百姓凡携铁器者一概不许入京，违者格杀勿论。\n\n" +
	    get_killer();
    }
}
string get_killer()
{
        int i;
        string msg;
        object *ob = users();

        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition("bjkiller"))
                        msg += (ob[i]->short() + "\n");
        if (msg == "")
                return "";
        else
                return "现在本城正在缉拿以下人犯：\n\n" + msg + "\n";
}
void create()
{
 	mapping night_exits=([]);
	string *exit_names;
	int 	i;

	set("is_outer_gate", 1);
	set("enter_dir", GATE_ENTER_DIR);
	set("short", GATE_DESC_SHORT);
	set("gate_name", GATE_DESC_SHORT);
	set("long", GATE_DESC_LONG);
	set("exits", GATE_EXITS);

	exit_names = keys(GATE_EXITS);
	for (i=0; i<sizeof(GATE_EXITS); i++){
	    if (exit_names[i] != GATE_ENTER_DIR) {
		night_exits[exit_names[i]] = GATE_EXITS[exit_names[i]];
	    }
	}
        set("night_exits", night_exits);
        set("enter_room", GATE_EXITS[GATE_ENTER_DIR]);
        set("menlou", GATE_EXITS["up"]);

	set("objects", GATE_OBJECTS);

	set("item_desc", ([
	"gaoshi" : (: look_gaoshi :),
]));
	set("outdoors", "beijing");
	set("cost", 3);
	setup();
	remove_call_out("gen_killer");
	call_out("gen_killer", 10);
}

void fix_inside()
{
    object inner_side, me = this_object();

    inner_side = find_object(me->query("enter_room"));
    if (! inner_side) {
 	inner_side = load_object(me->query("enter_room"));
	if (! inner_side) {
	    return;
	}
    }

    if (me->query("night"))  {
	message("info", "天黑了，官兵上前把城门关上。\n",
		inner_side, 0);
	inner_side->fix_exits_for_night(1);
    } else {
	inner_side->fix_exits_for_night(0);
	message("info", "天亮啦，官兵把城门打开，发出吱的一声响。\n",
		inner_side, 0);
    }
}

int gen_killer()
{
    object env = this_object();
    object *killers ;
    object *inv, killer;
    int    i, shiwei_present = 0;

    remove_call_out("gen_killer");
    call_out("gen_killer", 10);

    killers = HELPER->obj_in_env("/d/beijing/npc/killer1.lpc", env);
    inv = all_inventory(env);
    for (i=sizeof(inv)-1; i>=0; i--)
    {
        if (userp(inv[i]) && living(inv[i]) &&
	    IS_SHIWEI(inv[i]) && inv[i]->query_temp("chaoting/can_allow"))
	{
	    if (HELPER->is_night_shift ())
	    { // night
		if (inv[i]->query_temp("chaoting/day_job"))
		{
                        if (PIN(inv[i]) <= 6)
			reward_shiwei(1, inv[i]);
			else
		    	reward_shiwei(0, inv[i]);//值白班的奖励
		}else if (inv[i]->query_temp("chaoting/night_job"))
		{
		    shiwei_present++;
		}
	    }
	    else
	     {
		if (inv[i]->query_temp("chaoting/night_job"))
		{
                        if (PIN(inv[i]) <= 6)
			reward_shiwei(2, inv[i]);
			else
		    	reward_shiwei(1, inv[i]);//值夜班的奖励
		}else if (inv[i]->query_temp("chaoting/day_job"))
		{
		    shiwei_present++;
		}
	    }
        }
    }

    if (HELPER->is_dark_time())
    {
	if (! env->query("night")) {
	    message("info", "天黑了，官兵上前把城门关上。\n", env, 0);
	    env->set("night", 1);
	    set("exits", env->query("night_exits"));
	    fix_inside();
	}
    }else{
	if (env->query("night")) {
	    env->set("night", 0);
	    set("exits", GATE_EXITS);
	    message("info",
		"天亮啦，官兵把城门打开，发出吱的一声响。\n", env, 0);
	    fix_inside();
	}
    }

    if (shiwei_present == 0) return 1;

    if (HELPER->is_night_shift())
    {	// day time
	if (killers) return 0;
	killer = new("/d/beijing/npc/killer1.lpc");
	killer->move(env);
	killer->upgrade(1);
	message_vision("$N快步走了过来。\n", killer);
    }else
    {
	if (killers) return 0;
	killer = new("/d/beijing/npc/killer1.lpc");
	killer->move(env);
	message_vision("$N快步走了过来。\n", killer);
    }
    return 2;
}

void reward_shiwei(int rank, object player)
{
    int kill_num = player->query_temp("chaoting/kill_num");
    int allow_num = player->query_temp("chaoting/allow_num");

    message_vision("城门的钟敲了两下，$N的换班时间到了。\n", player);
    player->delete_temp("chaoting/start_job_time");
    player->delete_temp("chaoting/can_allow");
    player->delete_temp("chaoting/allow_num");
    player->delete_temp("chaoting/kill_num");
    HELPER->job_reward(player, rank, kill_num, allow_num);
}

int do_guard(string arg)
{
    object player = this_player();
    if (! IS_SHIWEI(player)) return 0;

    if (PIN(player) < 6)
        return notify_fail("你无聊得紧，还要来守城门？\n");
    if (player->query_temp("chaoting/can_allow"))
	return notify_fail("你已经在守门了。\n");

    if (!player->query_temp("chaoting/current_job"))
	return notify_fail("你得先去问问多大人，你今天值班的地方是那儿？\n");
    if (player->query_temp("chaoting/current_job") != query("gate_name"))
 	return notify_fail("这里不是你要守的地方。快去"+
	    player->query_temp("chaoting/current_job")+"吧。\n");
    if (player->query_temp("chaoting/day_job") && HELPER->is_sunrise() != 0)
    {
	player->delete_temp("chaoting/current_job");
	player->delete_temp("chaoting/day_job");
	return notify_fail("辰时已过你才来城门，今天就不用你守了！\n");
    }

    if (player->query_temp("chaoting/night_job") && HELPER->is_sunset() != 0)
    {
	player->delete_temp("chaoting/current_job");
	player->delete_temp("chaoting/night_job");
	return notify_fail("戌时已过你才来城门，今天就不用你守了！\n");
    }

    player->delete_temp("chaoting/current_job");
    player->set_temp("chaoting/start_job_time", time());
    player->set_temp("chaoting/can_allow", 1);
    player->set_temp("chaoting/allow_num", 0);
    player->set_temp("chaoting/kill_num", 0);
    message_vision(
	"$N一叉腰，对身旁的官兵道：今天有我在，看谁敢带家伙进城。\n",
	player);
    tell_object(player, "你也可以私放 (allow) 带兵器的人进城。\n");
    return 1;
}

void check_auto_kill(object me, object bing, object shiwei)
{
    if (!userp(me))
    {	// npc auto kill
    	if (me->query_temp("attempt_outer_gate"))
    	{
    	    if (bing)
    	    {
    	    	me->set_temp("outer_gate_killer", 1);
        		message_vision("$N对着$n大喝道：挡我者死！\n", me, bing);
        		me->kill_ob(bing);
        		bing->kill_ob(me);
    	    } 
            else if (shiwei)
    	    {
    	    	me->set_temp("outer_gate_killer", 1);
        		message_vision("$N对着$n大喝道：挡我者死！\n", me, shiwei);
        		me->kill_ob(shiwei);
        		shiwei->kill_ob(me);
    	    }
    	}
        else
        {
    	    me->set_temp("attempt_outer_gate", 1);
    	}
    }
}

int do_allow(string name)
{
    object me = this_player(), obj;

    if (! me->query_temp("chaoting/can_allow"))
	return 0;

    if (! name || name=="" )
        return notify_fail("你想让谁进城？\n");

    if (!objectp(obj = present(name, environment(me))))
         return notify_fail("这里没有这个人。\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("看清楚点，这不是活人。\n");

    if (!living(obj))
	return notify_fail("等醒了再说吧。\n");

	if (!me->is_fighting())
	{
    message_vision("$N对着$n大大咧咧地说道："
        "今天官爷心情好，就破例让你进城吧。\n", me, obj);
    	}
    	else if(obj->is_fighting() && obj->query_temp("outer_gate_killer"))
    	{
    		message_vision("$N对着$n说道：算了，算了，好汉不吃眼前亏，就放你进城去吧。”\n", me, obj);
    		if(me->is_fighting(obj)) me->remove_enemy(obj);
    		obj->remove_all_enemy();
    obj->set_temp("outer_gate_allowed", 1);
    me->set_temp("chaoting/allow_num", me->query_temp("chaoting/allow_num") + 1);
    		obj->do_move();
    		return 1;
    	}
    	else return notify_fail("你还是先解决眼前的敌人再说吧。\n");
    obj->set_temp("outer_gate_allowed", 1);
    me->set_temp("chaoting/allow_num", me->query_temp("chaoting/allow_num") + 1);
    return 1;
}

int valid_leave(object me, string dir)
{
    object *inv, *env, shiwei, bing;
    mapping myfam, mygen;
    int i, shiwei_num, bing_present = 0, shiwei_present = 0;
    myfam = (mapping)me->query("family");
    env = all_inventory(environment(me));
	  shiwei_num = 0;
    
    for (i=sizeof(env)-1; i>=0; i--) {
	    if (userp(env[i]) && living(env[i]) &&
	      IS_SHIWEI(env[i]) && env[i]->query_temp("chaoting/can_allow"))
				shiwei_num ++;
	}
	  
    shiwei_num = random(shiwei_num);
    for (i=sizeof(env)-1; i>=0; i--) 
    {
        if( living(env[i]) && env[i]->query("id") == "guan bing" )
        {
            if (!bing_present)
            {
                bing_present = 1;
                bing = env[i];
            }
            continue;
        }
	    
	    if (userp(env[i]) && living(env[i]) &&
	        IS_SHIWEI(env[i]) && env[i]->query_temp("chaoting/can_allow"))
	    {
            shiwei_present=1;
            if (!shiwei_num) 
            {
                shiwei = env[i];
                break;
            } 
            else shiwei_num--;
        }
    }

    if (IS_SHIWEI(me) && me->query_temp("chaoting/can_allow"))
	    return notify_fail("你还没完成守门的任务呢，怎么能离开？\n");

    if (!IS_SHIWEI(me) && dir == GATE_ENTER_DIR)
    {
      inv = all_inventory(me);

	    if ((!bing_present && !shiwei_present) ||	// no guard
            me->query_temp("outer_gate_allowed") ||       // allowed
            me->query("special_skill/sociability") ||
            me->query("id") == "hao mao" ) //毫毛请进
	    {
		    me->delete_temp("outer_gate_allowed");
		    me->delete_temp("attemp_outer_gate");
		    return ::valid_leave(me, dir);
	    }

      for(i=sizeof(inv)-1; i>=0; i--) {
//大宗师可以携带兵器入城，不进行兵器检查 by seagate@pkuxkx
        if (inv[i]->query("weapon_prop") && 
        	  inv[i]->query("equipped") &&
        	  !me->query("reborn/all")){
          if(bing_present && shiwei_present) {
            message_vision("官兵拦住$N说道：看告示了没有？" + "您想进带着"+
			        inv[i]->query("name")+"进城呐？先问问"+
			        shiwei->query("name")+"大人吧！\n", me);
		        check_auto_kill(me, bing, shiwei);
            return notify_fail("官兵拦住了你。\n");
		      }
		      else if (bing_present) {
		        message_vision("官兵拦住$N说道：站住，把" +
			        inv[i]->query("name")+"留下再说！\n", me);
		        
		        check_auto_kill(me, bing, shiwei);
            return notify_fail("官兵拦住了你。\n");
		      }
		      else{  // only shiwei present
		        message_vision("$N拦住$n说道：想进城先得过我这关吧？\n"+ "瞧瞧，带着" +
			        inv[i]->query("name")+"就想往里闯？\n", shiwei, me);
		        
		        check_auto_kill(me, bing, shiwei);
            return notify_fail("官兵拦住了你。\n");
		      }
        }
      }
    }

    if ((bing_present || shiwei_present) && dir == "up")
    {
      if (me->query("class") != "officer" && !me->query("special_skill/sociability"))
    	  return notify_fail("官兵拦住了你:“闲杂人等不得上城楼。”\n");//不是朝廷官员
    	
    	if (me->query("pin") == 9 && !me->query_temp("chaoting/xuncheng"))
     	  return notify_fail("官兵拦住了你:“低等士兵不得上城楼。”\n");//没有巡城任务的低等士兵
    }

    me->delete_temp("attemp_outer_gate");
    me->delete_temp("outer_gate_allowed");
    return ::valid_leave(me, dir);
}

void finish_climb(object player)
{
    int dodge;
    object inner_side;

    if (objectp(player)&&!living(player)) return;
    dodge =  player->query_skill("dodge");
    if (player->query("jing")<200)
    {
    	message_vision("$N想提气跳跃，无奈精神无法集中，只好作罢。\n", player);
    	return;
    }

    if (dodge < 50) {
	message_vision("$N爬了几尺，手上一个不稳跌了下来，摔得鼻青脸肿。\n",player);
	player->receive_wound("qi", 50, "摔下城墙");
	player->receive_damage("qi", 100, "摔下城墙");
	return;
    }
    if (dodge < 100) {
	message_vision("$N费了半天的劲，却没爬到墙头就跌了下来。\n", player);
	player->receive_damage("qi", 100, "摔下城墙");
	player->receive_wound("qi", 100, "摔下城墙");
	return;
    }
    if (dodge < 150) {
	message_vision("$N左支右撑，呼哧呼哧的爬上了城墙。\n", player);
	player->add("jing", -200);

    }else if (dodge < 250) {
	message_vision("$N施展轻功，几下就爬上了城墙。\n", player);
	player->add("jing", -100);
    }else {
	message_vision("$N周身真气流转，提了一口气，转眼就上了城头。\n",
	player);
	player->add("jing", -50);
    }
    inner_side = find_object(this_object()->query("menlou"));
    if (! inner_side) {
        inner_side = load_object(this_object()->query("menlou"));
	if (! inner_side) {
	    message_vision("Please report: outer_gate.h BUG: "
	    "inner_side is NULL.\n", player);
	    return;
	}
    }
    player->move(inner_side);
//    message_vision("\n$N一纵身，从城墙上跳了下来。\n", player);
}

int do_climb(string arg)
{
    object me=this_object(), player=this_player();
    object *inv, shiwei, bing;
    int    i, bing_present, shiwei_present;

    if (player->is_busy()) return notify_fail("你正忙着呢。\n");
    if (! arg || arg!="wall") return notify_fail("你要往哪儿爬？\n");
    if (! me->query("night"))
	return notify_fail("大白天的这么多人，你也好意思爬墙？\n");
    if ( me->query("class") == "officer")
	return notify_fail("身为朝廷官员，你也好意思爬墙？\n");

    bing_present = objectp(bing = present("guan bing", environment(player)));
    shiwei_present = 0;
    inv = all_inventory(environment(player));
    for (i=sizeof(inv)-1; i>=0; i--)
    {
        if (userp(inv[i]) && living(inv[i]) &&
	    IS_SHIWEI(inv[i]) && inv[i]->query_temp("chaoting/can_allow"))
	    {
	    shiwei_present=1;
	    shiwei = inv[i];
	    break;
        }
    }

    if (! bing_present && !shiwei_present) {
        player->start_busy(6);
	message_vision("\n$N手脚并用，开始往城墙上爬上去。\n", player);
	call_out("finish_climb", 4, player);
	return 1;
    }
	return notify_fail("官兵的眼皮底下你也敢爬墙？\n");
}
