int do_none();
void gift(object me,object env);
void check(object me,object here);
void resets(object env,object me,object ob);
void powerup(object me);

string *lim_f=({
		"胸脯","粉颊","粉颈","柔荑","三寸金莲","%$#$%(嘿嘿)",
});

string *lim_m=({
		"弟弟","臭脸","鸭脖","小肚子","后背","%$#$%(嘿嘿)",
});

string *w_name=({
		"拳头","双拳","双掌","左拳","右拳","左掌","右掌",
		"拳头","双拳","双掌","左拳","右拳","左掌","右掌",
});

string *end_msg=({
	CYN"$n"CYN"见$N"CYN"疏虞防范，一个绝招，将其打翻在地，动弹不得。\n"NOR,
	CYN"$n见"CYN"$N已是穷途末路，不由仰天狂笑，上前一脚踩住"CYN"$N的$1问道：你服还是不服？\n"NOR,
	CYN"$N"CYN"脱口大骂：不服，$C就是不服！\n"NOR,
	CYN"$n"CYN"热泪盈眶地说：好，好，好！$c向来是以德服人。\n"NOR,
	CYN"说罢,$n"CYN"上前一脚踩住$N"CYN"的$2，用$w"CYN"笔划着说：...你...服...是...不...服...\n"NOR,
	CYN"$N"CYN"咬了咬，涨红了脸，无奈的说：行，你狠，算我怕了你了。说罢潸然泪下。\n"NOR,
	CYN"$n"CYN"嘿嘿一笑，打了呼哨，一旁走来几个打手模样的，拖起$N"CYN"径直向外去了。\n"NOR,
	CYN"战报：$n"CYN"经过一番搏斗，将$N"CYN"打的落花流水。\n"NOR,
});

string *win_msg=({
	CYN"$n"CYN"打了个呼哨，对着周围的观众打了飞吻，道：多谢大家捧场，等偶赢了，请大家吃饭...\n"NOR,
	CYN"$n"CYN"哈哈一笑，大呼过瘾过瘾，说道：这样的对手，来他七八个不在话下...\n"NOR,
	CYN"$n"CYN"把$w"CYN"一挥，长笑一声：果真是高手寂寞的说...\n"NOR,
	CYN"$n"CYN"欢天喜地的被众人围拥着走去一旁，趁着休息时间下馆子去了...\n"NOR,
});
		
string *lost_msg=({
	CYN"$N仰天打了个哈哈，寂然说道：果真是长江后浪推前浪...\n"NOR,
	CYN"$N恨声说道：妈的，忘记买药了，真是疏忽疏忽...\n"NOR,
	CYN"$N从地上爬起来，吐了口浓痰，闷声离去...\n"NOR,
	CYN"$N爬将起身，双手叉腰，放声骂道：要杀就杀，要剁就剁，恁的怕你不成...\n"NOR,
	CYN"$N惨然一笑：技不如人，奈何奈何，再去打拼十年，到时再来再来...\n"NOR,
	CYN"$N狠声叫道：君子报仇，十年不晚，咱们梁子算是结下了，走着瞧...\n"NOR,
});

string *nocmds = ({
	"quit","fly","move","cast escape","cast jieti",
	"cast huimeng","cast townportal","cast shuidun",
	"cast tudun","cast arrest","cast drist","cast taijitu",
	"cast qimen","cast tuoqiao","cast shou","burn",
	"ji",
});	

void init()
{
object me = this_player();
object env = this_object();

if ( !userp(me) )
	{
	tell_room(env,YEL"猛地冲出来几个衙役打扮的人物嚷嚷道：这里岂是畜生胡闹
的所在？！说罢，拉起"+me->name()+YEL"就走。\n"NOR);
	destruct(me);
	return;
	}
add_action("do_none","",1);
return;
}

int do_none()
{
object me = this_player();
string arg = query_verb();
if ( member_array(arg,nocmds)==-1 )
	return 0;
tell_object(me,CYN"这里可不是胡闹的地方！\n"NOR);
return 1;
}

int do_kill(string arg)
{
object ob,me,env;
int mypot,hispot;
me=this_player();
env=this_object();

if ( me->is_fighting() )
	return notify_fail(HIR"加油加油？！\n"NOR);
	
if ( !arg )
	return notify_fail(HIR"你想杀谁？\n"NOR);
	
ob=present(arg,env);
if ( !ob )
	return notify_fail(HIR"你想杀谁？\n"NOR);
if ( ob->is_fighting( ) && !ob->is_fighting(me) )
	return notify_fail(HIR"以多欺寡算什么好汉？！\n"NOR);

message("channel:chat",HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR CYN"修罗场内"+me->name()+CYN"与"+ob->name()+CYN"开始了比赛，大家加油。\n"NOR,users());
message_vision(HIW"\n你们只有五分钟的时间,速战速决吧！\n"NOR,me);
me->kill_ob(ob);
ob->kill_ob(me);
call_out("resets",600,env,me,ob);
return 0;
}	

void powerup(object me)
{
me->set("kee",me->query("max_kee")/2);
me->set("sen",me->query("max_kee")/2);
me->set("eff_kee",me->query("max_kee"));
me->set("eff_sen",me->query("max_sen"));
me->set("force",me->query("max_force"));
me->set("mana",me->query("max_mana"));
me->clean_condition();
me->delete_temp("PKfight/halt");
me->delete_temp("PKfight/paid");
me->delete_temp("PKfight/join");
}

void resets(object env,object me,object ob)
{
string name1,name2;
remove_call_out("resets");
if ( environment(me)==env && environment(ob)==env )
	{
	name1=me->query("name");
	name2=ob->query("name");
	remove_call_out("resets");
	message("chat",HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR CYN+name1+"与"+name2+"大战三百回合，不分胜负，双双离开场！\n"NOR,users());

	powerup(me);
	powerup(ob);
	me->remove_killer(ob);
	ob->remove_killer(me);
	me->move("/d/city/under");
	ob->move("/d/city/under");
	return;
	}
else   return;
}

void alternative_die (object me)
{
int i,value=80000;
string *limbs,msg,str,prefix,s1,s2,*lost_msg,*win_msg;
string my_name,his_name,limb;
object weapon,env;
object ob = me->query_temp("last_damage_from");
env = this_object();
weapon=ob->query_temp("weapon"); 

if (me->query("kee")<0) 
	me->set("kee",10);
if (me->query("eff_kee")<0) 
	me->set("eff_kee",10);
if (me->query("sen")<0) 
	me->set("sen",10);
if (me->query("eff_sen")<0) 
	me->set("eff_sen",10);

powerup(me);
me->remove_killer(ob);
ob->remove_killer(me);

msg = "";
for ( i=0;i<sizeof(end_msg);i++ )
	{
	msg+=end_msg[i];
	}
if ( env->query("short")!=RED"小阿修羅场"NOR )
	msg+=CYN"$n"CYN"顺手将$N"CYN"的$3"CYN"收进袋中。\n"NOR;

msg+=win_msg[random(sizeof(win_msg))];
msg+=lost_msg[random(sizeof(lost_msg))];
msg=replace_string(msg,"$N",HIY+me->query("name")+NOR);
msg=replace_string(msg,"$n",HIY+ob->query("name")+NOR);
if ( weapon )
	msg=replace_string(msg,"$w",HIC+weapon->query("name")+NOR);
else	{
	str=w_name[random(sizeof(w_name))];			
	msg=replace_string(msg,"$w",HIM+str+NOR);
	}

msg=replace_string(msg,"$C",RANK_D->query_self_rude(me));
msg=replace_string(msg,"$c",RANK_D->query_self(ob));
if ( me->query("gender")=="女性" )
	str = lim_f[random(sizeof(lim_f))];
else   str = lim_m[random(sizeof(lim_m))];
msg=replace_string(msg,"$2",str);
limbs=me->query("limbs");
limb=limbs[random(sizeof(limbs))];
msg=replace_string(msg,"$1",limb);
msg=replace_string(msg,"$3",MONEY_D->money_str(value));

s1 = msg;
s2 = "";
prefix=NOR HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR CYN;
while (strsrch(s1,"\n\n") != -1)
	s1 = replace_string(s1,"\n\n","\n");
if (s1[strlen(s1)-1]=='\n')
	{
	s1 = s1[0..strlen(s1)-2];
	s2 = "\n";
	}
if (strlen(s1) == 0)
	return;
s1 = replace_string(s1,"\n","\n"+prefix)+"\n";
reset_eval_cost();
message("channel:chat",prefix+s1,users()); 
env->add("num",1); //防止无人比赛的bug
env->save();
me->add_temp("PKfight/lost",1);
me->move("/d/city/under");
return;
}

int do_halt()
{
int i,num=0;
object *inv;
object env = this_object();
object me = this_player();
inv = all_inventory( env );

if ( environment(me)!=env )
	return notify_fail("什么?\n");

if ( me->query_temp("PKfight/halt") )
	return notify_fail("你在办理退出手续呢，耐心等等吧。\n");

message_vision(YEL"$N"YEL"申请退出比赛。\n"NOR,me);
me->start_busy(2);
me->set_temp("PKfight/halt",1);

for ( i=0;i<sizeof(inv);i++ )
	{
	if ( inv[i]=me ) continue;
	num++;
	}

if ( num>=1 )
	{
	powerup(me);
	message_vision(CYN"$N"CYN"见四下高手如云，不由暗咐：今次不行，苦练三年，再来试试。\n"NOR);
	me->move("/d/city/under");
	message("channel:chat",HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR HIW+me->query("name")+NOR CYN"临阵脱逃，逃出了比赛。\n"NOR,users());
	return 1;
	}
else   {
	if ( !env->query("num") ) 
		{
		powerup(me);
		message_vision(CYN"$N"CYN"见四下无人，不由暗咐：许是我太过厉害，大家都怕了我。\n"NOR);
		me->move("/d/city/under");
		message("channel:chat",HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR HIW+me->query("name")+NOR CYN"见无人应战，退出了比赛。\n"NOR,users());
		return 1;
		}
	else	{
		call_out("gift",1,me,env);
		return 1;
		}
	}
}

void gift(object me,object env)
{
int  value;
string *gift1,*gift2,*gift3,prefix,s1,s2,msg;
object gift;

gift1 = ({
	"/clone/money/zuanshi",
	"/clone/money/thousand-cash",
	"/clone/money/gold",
	"/clone/money/silver",
	"/clone/money/coin",
	"/clone/money/coin",
	"/clone/money/silver",
	"/clone/money/gold",
	"/clone/money/thousand-cash",
	"/clone/money/zuanshi",
	});
gift2 = ({
	"/d/snowtu/obj/shoes",
	"/d/snowtu/obj/pifeng",
	"/d/snowtu/obj/cloth",
	"/d/snowtu/obj/armor",
	"/d/snowtu/obj/cloth",
	"/d/snowtu/obj/pifeng",
	"/d/snowtu/obj/shoes",
	});
gift3=({
	"/d/obj/flower/flower",
	"/d/obj/flower/yehua",
	"/d/obj/flower/guihua",
	"/d/obj/flower/hua",
	"/d/obj/books-nonskill/xyj01",
	"/d/obj/books-nonskill/xyj02",
	"/d/obj/books-nonskill/xyj03",
	"/d/obj/books-nonskill/xyj04",
	"/d/obj/books-nonskill/xyj05",
	"/d/obj/books-nonskill/xyj06",
	"/d/obj/books-nonskill/xyjbook",
	"/d/obj/books-nonskill/hmeng001",
	"/d/obj/books-nonskill/hmeng002",
	"/d/obj/books-nonskill/hmeng003",
	"/d/obj/books-nonskill/hmeng004",
	"/d/obj/books-nonskill/hmeng005",
	"/d/obj/books-nonskill/hmeng006",
	"/d/obj/books-nonskill/hmeng007",
	"/d/obj/books-nonskill/hmeng008",
	"/d/obj/books-nonskill/hmeng009",
	"/d/obj/books-nonskill/hmeng010",
	"/d/obj/books-nonskill/hmeng011",
	"/d/obj/books-nonskill/hmeng012",
	"/d/obj/books-nonskill/hmeng013",
	"/d/obj/books-nonskill/hmeng014",
	"/d/obj/books-nonskill/hmeng015",
	"/d/obj/books-nonskill/hmeng016",
	"/d/obj/books-nonskill/hmeng017",
	"/d/obj/books-nonskill/hmeng018",
	"/d/obj/books-nonskill/hmeng019",
	"/d/obj/books-nonskill/hmeng020",
	"/d/obj/books-nonskill/hmeng021",
	"/d/obj/books-nonskill/hmeng022",
	"/d/obj/books-nonskill/hmeng023",
	"/d/obj/books-nonskill/hmeng024",
	"/d/obj/books-nonskill/hmeng030",
	"/d/obj/books-nonskill/hmeng031",
	"/d/obj/books-nonskill/hmeng032",
	"/d/obj/books-nonskill/hmeng033",
	"/d/obj/books-nonskill/hmeng034",
	"/d/obj/books-nonskill/hmeng035",
	"/d/obj/books-nonskill/hmeng036",
	"/d/obj/books-nonskill/hmeng037",
	"/d/obj/books-nonskill/hmeng038",
	"/d/obj/books-nonskill/hmeng039",
	"/d/obj/books-nonskill/hmeng040",
	"/d/obj/books-nonskill/hmeng0120",
});

if ( environment(me)!=env )
	return;

if ( env->query("short")==RED"小阿修羅场"NOR )
	{
	gift=new(gift3[random(sizeof(gift3))]);
	value=1+random(8);
	}
else	{
	value=80000;
	if ( random(10)==2 )
		gift=new(gift2[random(sizeof(gift2))]);
	else
		gift=new(gift1[random(sizeof(gift1))]);
	}
msg=CYN"$N"CYN"得意的打了个响指：哈哈，果然是天下无敌。\n"NOR;
msg+= CYN"$N"CYN"历经万难，终于将对手一一击倒，得到了西游记--神魔传说的奖励品：一$d$O"CYN"。\n";
msg=replace_string(msg,"$N",HIY+me->query("name")+HIY"("+me->query("id")+")"NOR);
msg=replace_string(msg,"$d",gift->query("unit"));
msg=replace_string(msg,"$O",gift->query("name"));

s1 = msg;
s2 = "";
prefix=NOR HIG"【"NOR WHT"民间传说"NOR HIG"】"NOR CYN;
while (strsrch(s1,"\n\n") != -1)
	s1 = replace_string(s1,"\n\n","\n");
if (s1[strlen(s1)-1]=='\n')
	{
	s1 = s1[0..strlen(s1)-2];
	s2 = "\n";
	}
if (strlen(s1) == 0)
	return;
s1 = replace_string(s1,"\n","\n"+prefix)+"\n";
reset_eval_cost();
message("chat",prefix+s1,users()); 

gift->move(me);
if ( !present(gift,me) )
	tell_object(me,"可惜你身上垃圾多多，没拿到奖品。\n");
me->add("balance",value); 
tell_object(me,NOR"\n你的入场费："+MONEY_D->money_str(value)+NOR",自动转入你的帐户中了。\n");
powerup(me);
me->add_temp("PKfight/win",1);
me->move("/d/city/under");
env->set("num",0);
me->save();
env->save();
return;
}

