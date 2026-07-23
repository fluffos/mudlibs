int do_food (string arg)
{
int i,rev,exp;
string title,name,msg,sx,id,id2,add_sx;
object hs,shuijing,me;
hs = this_object();
me = this_player();

if (! living(me) || !id(arg) 
  || environment(me)!=environment(hs) 
  || hs->query("owner")!=me->query("id") )
	return notify_fail("你要喂养什么？\n");

if ( !shuijing=present("shui jing",me) ) 
	return notify_fail("你的魔法水晶不够了。\n");

if ( hs->query("lvl")>=27 )
        return notify_fail(hs->name()+"已经是终极形态，不需要再喂养了。\n");

if ( me->query("mana")<500 )
	return notify_fail("你的法力不足。\n");

if ( me->is_busy() && !wizardp(me) )
	return notify_fail("你现在正忙着呢。\n");
	
/*
-------------------------------------------------------------------------------------------------
					幻	兽	升	级	
-------------------------------------------------------------------------------------------------
*/
msg=HIW+"
$N把$n双眼微闭，集中精神在双掌之间，口中念道：“在天的见证之下，集勇气、
智慧、与美丽于一身的强大生物，幻兽呀！请你以最深的灵性，倾听我的倾诉，
我"+me->query("name")+"将与你缔结永生的血之盟约，终此生惟有
你与我为终生之盟友，契。” \n"NOR;
exp=shuijing->query("exp");
hs->add("exp",exp);
me->add("mana",-100-random(400));
if ( hs->query("exp") >=100 ) //升级
	{
	msg+=HIW+"
短短三分钟不到，$n已成长了将近原来的三倍大。而$N似乎已无力为继，轻哼一声，
双手发出的白光逐渐淡化，消失。随着$N双手白光消失，$n也停止生长。\n"NOR;

	hs->set("exp",0);
	hs->add("lvl",1);
	hs->add("max_kee",20);
	hs->add("max_sen",20);
	hs->set("kee",(int)hs->query("max_kee"));
	hs->set("sen",(int)hs->query("max_sen"));
	hs->set("eff_kee",(int)hs->query("max_kee"));
	hs->set("eff_sen",(int)hs->query("max_sen"));
	tell_object(me,BLINK+HIY+"\n你的"+hs->query("name")+"升为"+chinese_number(hs->query("lvl"))+"级！\n"NOR);
	
	if ( hs->query("lvl")==27 ) //终极形态
		{
                if ( hs->query("dc")>0 )
			{
			title=col+"太初"NOR"·";
			hs->set("shuxing","太初");
			me->set("shuxing","太初");
			hs->add("ll",15); //力量 影响物理攻击
			hs->add("jl",15); //精力 影响法术攻击
		}
		else 	{
			title=col+"太始"NOR"·";
			hs->set("shuxing","太始");
			me->set("shuxing","太始");
			hs->add("qz",15); //强壮 影响所加气血
			hs->add("mj",15); //敏捷 影响所加防御
			}
		if ( random(5)==2 )
			{
			i=(random(sizeof(end_name2)/4))*4;
			name=end_name2[i+1];
			id=end_name2[i+2];
			id2=end_name2[i+3];
			title+=end_name2[i];
			}
		else   {
			i=(random(sizeof(end_name1)/3))*3;
			name=end_name1[i];
			id=end_name1[i+1];
			id2=end_name1[i+2];
			}
		msg+=HIB+"\n"+
hs->name()+"在强光之中，渐渐化作一个魔茧，最终"NOR+HIW+name+NOR HIB"从魔茧中破茧而破！\n"NOR;
		hs->set_name(name,({id,id2}));
		hs->set("title",col+title+NOR);
		}
				
	else if ( hs->query("lvl")==18 ) //转换形态为三，追加属性
		{
		switch(random(10))
			{
			case 1 :
				add_sx="暗黑";
			break;
			default : {
				add_sx=shuxing[random(sizeof(shuxing))];
				if ( !add_sx ) return notify_fail("ERROR!\n");
				}
			break;
			}
       	switch(add_sx) //"土","风","火","雷","水","光","暗黑"
			{
			case "土" : 
				hs->add("dc",0); 
			break;
			case "风" : 
				hs->add("dc",1); 
			break;
			case "火" : 
				hs->add("dc",1); 
			break;
			case "雷" : 
				hs->add("dc",1); 
			break;
			case "水" : 
				hs->add("dc",0); 
			break;
			case "光" : 
				hs->add("dc",0); 
			break;
			case "暗黑" : 
				hs->add("dc",1); 
			break;
			}

		me->set("shuxing",add_sx+(string)me->query("shuxing"));
		hs->set("shuxing",(string)me->query("shuxing"));
		i=(random(sizeof(new_name)/3))*3;
		name=new_name[i];
		id=new_name[i+1];
		id2=new_name[i+2];
		title=col+"二阶"+hs->query("shuxing")+"性幻兽"NOR;		
		msg+=HIM+"\n"+
hs->name()+"在强光之中，渐渐化作一个魔茧，最终"NOR+HIW+name+NOR HIM"从魔茧中破茧而破！\n"NOR;
		hs->set_name(name,({id,id2}));
		hs->set("title",col+title+NOR);
		}

	else if ( hs->query("lvl")==9 ) //转换形态为二，不追加属性
		{
       	switch( hs->query("shuxing") ) //"土","风","火","雷","水","光","暗黑"
			{
			case "土" : {
				i=(random(sizeof(tu_name)/3))*3;
				name=tu_name[i];
				id=tu_name[i+1];
				id2=tu_name[i+2];
				hs->add("qz",2); //强壮 影响所加气血
				hs->add("mj",3); //敏捷 影响所加防御
				hs->add("ll",1); //力量 影响物理攻击
				hs->add("jl",1); //精力 影响法术攻击
				}
			break;
			case "风" : {
				i=(random(sizeof(feng_name)/3))*3;
				name=feng_name[i];
				id=feng_name[i+1];
				id2=feng_name[i+2];
				hs->add("qz",1); //强壮 影响所加气血
				hs->add("mj",1); //敏捷 影响所加防御
				hs->add("ll",2); //力量 影响物理攻击
				hs->add("jl",3); //精力 影响法术攻击
				}
			break;
			case "火" : {
				i=(random(sizeof(huo_name)/3))*3;
				name=huo_name[i];
				id=huo_name[i+1];
				id2=huo_name[i+2];
				hs->add("qz",1); //强壮 影响所加气血
				hs->add("mj",1); //敏捷 影响所加防御
				hs->add("ll",3); //力量 影响物理攻击
				hs->add("jl",2); //精力 影响法术攻击
				}
			break;
			case "雷" : {
				i=(random(sizeof(tu_name)/3))*3;
				name=lei_name[i];
				id=lei_name[i+1];
				id2=lei_name[i+2];
				hs->add("qz",1); //强壮 影响所加气血
				hs->add("mj",1); //敏捷 影响所加防御
				hs->add("ll",3); //力量 影响物理攻击
				hs->add("jl",3); //精力 影响法术攻击
				}
			break;
			case "水" : {
				i=(random(sizeof(shui_name)/3))*3;
				name=shui_name[i];
				id=shui_name[i+1];
				id2=shui_name[i+2];
				hs->add("qz",3); //强壮 影响所加气血
				hs->add("mj",2); //敏捷 影响所加防御
				hs->add("ll",1); //力量 影响物理攻击
				hs->add("jl",1); //精力 影响法术攻击
				}
			break;
			case "光" : {
				i=(random(sizeof(light_name)/3))*3;
				name=light_name[i];
				id=light_name[i+1];
				id2=light_name[i+2];
				hs->add("qz",3); //强壮 影响所加气血
				hs->add("mj",3); //敏捷 影响所加防御
				hs->add("ll",1); //力量 影响物理攻击
				hs->add("jl",1); //精力 影响法术攻击
				}
			break;
			case "暗黑" : {
				i=(random(sizeof(dark_name)/3))*3;
				name=dark_name[i];
				id=dark_name[i+1];
				id2=dark_name[i+2];
				hs->add("qz",1); //强壮 影响所加气血
				hs->add("mj",1); //敏捷 影响所加防御
				hs->add("ll",2); //力量 影响物理攻击
				hs->add("jl",2); //精力 影响法术攻击
				}
			break;
			}
		msg+=HIY+"\n"+
hs->name()+"在强光之中，渐渐化作一个魔茧，最终"NOR+HIW+name+NOR HIY"从魔茧中破茧而破！\n"NOR;
		title=col+"二阶"+hs->query("shuxing")+"性幻兽"NOR;		
		hs->set_name(name,({id,id2}));
		hs->set("title",col+title+NOR);
		}
	hs->save();
	}
else  {  //不升级
	msg+=HIW+"\n
$n亲密的舐着$N的掌心。$N嘴角含笑，再度凝神，更强盛的白光自眉间射出。\n"NOR;
	switch( hs->query("shuxing") ) //"土","风","火","雷","水","光","暗黑"
		{
		case "土" : {
			hs->add("qz",2); //强壮 影响所加气血
			hs->add("mj",3); //敏捷 影响所加防御
			hs->add("ll",1); //力量 影响物理攻击
			hs->add("jl",1); //精力 影响法术攻击
			}
		break;
		case "风" : {
			hs->add("qz",1); //强壮 影响所加气血
			hs->add("mj",1); //敏捷 影响所加防御
			hs->add("ll",2); //力量 影响物理攻击
			hs->add("jl",3); //精力 影响法术攻击
			}
		break;
		case "火" : {
			hs->add("qz",1); //强壮 影响所加气血
			hs->add("mj",1); //敏捷 影响所加防御
			hs->add("ll",3); //力量 影响物理攻击
			hs->add("jl",2); //精力 影响法术攻击
			}
		break;
		case "雷" : {
			hs->add("qz",1); //强壮 影响所加气血
			hs->add("mj",1); //敏捷 影响所加防御
			hs->add("ll",3); //力量 影响物理攻击
			hs->add("jl",3); //精力 影响法术攻击
			}
		break;
		case "水" : {
			hs->add("qz",3); //强壮 影响所加气血
			hs->add("mj",2); //敏捷 影响所加防御
			hs->add("ll",1); //力量 影响物理攻击
			hs->add("jl",1); //精力 影响法术攻击
			}
		break;
		case "光" : {
			hs->add("qz",3); //强壮 影响所加气血
			hs->add("mj",3); //敏捷 影响所加防御
			hs->add("ll",1); //力量 影响物理攻击
			hs->add("jl",1); //精力 影响法术攻击
			}
		break;
		case "暗黑" : {
			hs->add("qz",1); //强壮 影响所加气血
			hs->add("mj",1); //敏捷 影响所加防御
			hs->add("ll",2); //力量 影响物理攻击
			hs->add("jl",2); //精力 影响法术攻击
			}
		break;
		}
	}
msg+="\n"NOR;
message_vision(msg,me,hs);
me->start_busy(1+random(3));
//destruct(shuijing);
me->save();
hs->save();
return 1;
}

int do_watch(string arg)
{
int qz,mj,ll,jl,lvl,exp;
string msg,sx;
object me=this_player();
object hs=this_object();
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
exp=hs->query("exp"); //经验值
sx=hs->query("shuxing");

if ( !arg || !id(arg) )
        return notify_fail("你要看什么?\n");


msg=HIY"\n
=======================================================\n\n
\t"+hs->query("long")+NOR HIY"\n
=======================================================\n"NOR;
msg+=HIG"〖名称〗"NOR"："+HIW""+hs->name()+"("+hs->query("id")+")"NOR HIG"\n
〖经验〗"NOR"： "HIW+exp+"/100"+"("+(exp*100)/100+"%)\n"NOR;
msg+=HIG"〖等级〗"NOR"："+HIW""+lvl+" 级\n"NOR HIG"〖属性〗"NOR"："HIC+sx+NOR+"\n";
msg+=HIG"〖敏捷〗"NOR"："HIC+mj+NOR"\t"HIG"〖强壮〗"NOR"："HIC+qz+NOR"\n";
msg+=HIG"〖力量〗"NOR"："HIC+ll+NOR"\t"HIG"〖精力〗"NOR"："HIC+jl+NOR HIY"\n
=======================================================\n\n"NOR;
tell_object(me,msg+NOR);
return 1;
}
