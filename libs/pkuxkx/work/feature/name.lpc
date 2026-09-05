// name.c
// Modified by iszt@pkuxkx, 2007-03-26, short() and long()
// seagate@pkuxkx 2010/11/11 支持多title，支持多重假面，对玩家的原始名字进行保护。
// seagate@pkuxkx 2010/12/04 
// 1.增加mask_id()函数提供对id的提取支持，并用该函数修改short()和name_id()函数
// 2.修改long()函数，当有apply/long的时候先提取short()再加上apply/long，而不是以前的直接提取apply/long
// 3.修改set_face函数，对于除了name和id以外的其他属性使用mapping others提供支持，同步修改mask_act()和restore_face()函数
// 4.mask_act函数提供由于set_face修改以后的扩展支持，并且自动组织apply/short属性
// 5.增加gender()函数提供一站式的性别信息提取，方便针对面具的虚假信息提供
// seagate@pkuxkx 2010/12/09
// 1.用户增加属性multi_title，提供show_title()函数支持此属性
// 2.short()函数支持show_title()的头衔显示，存在此函数的时候替换掉title和job_title的头衔显示

#include <ansi.h>
#include <dbase.h>
#include <condition.h>
#include <title.h>

nosave string *my_id;
//my_title是一个title类型:title名称的键值对
//my_face是自己的脸谱集合，其中origin代表原始脸谱
//fact代表真实脸谱，mask代表当前最外层的虚假脸谱
//其他键值类型分别对应不同的虚假脸谱设置的属性，
//由具体脸谱技能或者脸谱物件来决定，同样一种类型
//将会同时只能存在一种脸谱。
//脸谱属性有name，id，long，age，previous，
//另外mask键值由额外的mask属性代表当前脸谱来自哪个
//虚假脸谱键值，方便揭开脸谱的时候将两个属性一起删除。
mapping my_title,my_face;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	  &&	sizeof(applied_id) ) 
	if( member_array(str, applied_id)!=-1 )
		return 1;
	else
		return 0;

	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
	return 1;
	else
	return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	  &&	sizeof(applied_id) )
	return applied_id;
	else
	return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	int size = 0;
	object link_ob;
	//在name()里调用不存在的函数会crash.一般name.c都会和dbase.c同时被继承
	//所以没有问题，但是如果直接call name.c的函数，这里就会出错
	//注意，即使你call name.c->otherfoo()，mudos也会主动调用name()

	if(function_exists("query",this_object(),0) == 0)
	{
		return file_name(this_object());
	}
	if( !raw )
	{
		mask = query_temp("apply/name");
		if(!undefinedp(mask)) size = sizeof(mask);
		if(size > 0)
			return mask[size-1];
	}
	if( stringp(str = query("name")) )
	{
		if(userp(this_object()) && this_object()->is_realuser())
		{
    		return HIY"Ｖ"NOR+str;
		}
		return str;
	}
	else
		return file_name(this_object());
}

//新的获得虚假id的函数，原因是id()已经被使用作业id检验函数
//by seagate@pkuxkx
varargs string mask_id(int raw)
{
	string *id, n_id;
	
	if ( !raw )
	{
		if ( stringp(n_id=query_temp("apply/id")) )
			return n_id;
		else if ( pointerp(id = query_temp("apply/id")) &&	
			        sizeof(id) )
			return id[0];
		else 
			return query("id");
	}
	else
		return query("id");
}

//title头衔显示部分增加对my_title的支持（show_title()函数）
//by seagate@pkuxkx 2010/12/09
varargs string short(int raw)
{
	string job_title, title, nick, str, str1, *mask;
	string force, n_title;
	mapping msg;
	object me = this_object();

//修改获得id的函数，改从apply/id取修改为通过parse_command_id_list()函数间接获得，假定该函数返回值的第一个id就是真实id。
//by seagate@pkuxkx
  if( !stringp(str = query("short")) )
    str = name(raw) + "(" + capitalize(mask_id()) + ")";

	if( !me->is_character() )
		return str;

	if( !raw && stringp(query_temp("apply/short")) )
		return query_temp("apply/short");
	else
	{
		if( stringp(nick = query("nickname")) )
			str = sprintf("「%s」%s", nick, str);

    n_title=show_title();
    
		//added by aiai for createmenpai
		if (  query("menpai/gen") == 1 )
			str = sprintf("%s%s%s",HIY+query("family/family_name")+HIR"主人"NOR,(nick?"":" "), str);
		else if (  query("menpai") )
			str = sprintf("%s%s%s",HIY+query("family/family_name")+HIR"使者"NOR, (nick?"":" "), str);
		else if ( n_title )
			str = sprintf("%s%s%s", n_title,(nick?"":" "), str);
		else if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);
		if( stringp(job_title = query("job_title")) && !n_title )
			str = sprintf("%s %s",job_title, str); 
	}

	if( !raw )
	{
		if ((int)query_temp("pending/exercise")) {
			force = me->query_skill_mapped("force");
			if (force) msg = SKILL_D(force)->exercise_msg(me);
			
			if (!msg || undefinedp(msg["status_msg"]))
				str = name(raw) + "正盘膝坐在地下修炼内力。";
			else
				str = msg["status_msg"];
		}
		else if ((int)query_temp("pending/respirate"))
			str = name() + "正盘膝坐在地下吐纳炼精。";
		else if ((int)query_temp("pending/xiulian"))
			str = name() + "正坐在地下修炼内功。";

		if( me->is_ghost() )
			str = HIB "(鬼气) " NOR + str;
    
    if (userp(me) && me->query_condition("bjkiller"))
      str = HIR "(朝廷通缉要犯) " NOR + str;
		
		if( query_temp("netdead") && me->query("noDeadNetnoIdle") != "Pkuxkx" ||
			( wizardp(me) && me->query("env/lost_connect") ) )
			str += HIG " <断线" + chinese_number((time() - query_temp("netdead"))/60+1) + "分钟>" NOR;
		
		if(( interactive(me)
		&&	query_idle( me ) > 120 
		&&	me->query("noDeadNetnoIdle") != "Pkuxkx") 
		||	(wizardp(me) && me->query("env/is_idle")) )
			str += HIM " <发呆" + chinese_number((query_idle(me))/60-1) + "分钟>" NOR;
		
		if( in_input() )
			str += HIC " <输入文字中>" NOR;
		
		if(query("disable_type") && !living(me) )
			str += HIR + " " + query("disable_type") + NOR;
		
		if( in_edit() )
			str += HIY " <编辑档案中>" NOR;
		
		if ( me->is_fighting() )
			str += HIR " <战斗中>" NOR;
		if (query_temp("vein_through"))
			str += HIW " <通脉中>" NOR;
		if (query_temp("alchemy/ongoing")+1>=time())
			str += YEL " <炼药中>"NOR;
		if (query_temp("weapon_cast/ongoing")+1>=time())
			str += RED " <锻造中>"NOR;
	  if(query_temp("cs/teamname"))
		  str += query_temp("cs/teamname");
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;

//修改apply/long的规则，不存放short描述，short描述仍旧需要从short函数提取，否则准确性上存在bug。
//by seagate@pkuxkx
	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = short(raw) + "\n" + mask[sizeof(mask)-1];
	else
	{
		str = short(raw) + "\n";
		if( stringp(query("long")) )
			str += query("long");
	}

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}

//增加对性别的虚假支持
varargs string gender(int raw)
{
	string *gender, n_gender;
	
	if ( !raw )
	{
		if ( stringp(n_gender=query_temp("apply/gender")) )
			return n_gender;
		else if ( pointerp(gender = query_temp("apply/gender")) &&	
			        sizeof(gender) )
			return gender[sizeof(gender)-1];
		else 
			return query("gender");
	}
	else
		return query("gender");
}

string replace_color(string arg)
{
	int i,wordln;
	string str,str1;
	i = 0;
	str = arg;

	str = replace_string(str,"$BLK$","");
	str = replace_string(str,"$RED$","");
	str = replace_string(str,"$GRN$","");
	str = replace_string(str,"$YEL$","");
	str = replace_string(str,"$BLU$","");
	str = replace_string(str,"$MAG$","");
	str = replace_string(str,"$CYN$","");
	str = replace_string(str,"$WHT$","");
	str = replace_string(str,"$HIR$","");
	str = replace_string(str,"$HIG$","");
	str = replace_string(str,"$HIY$","");
	str = replace_string(str,"$HIB$","");
	str = replace_string(str,"$HIM$","");
	str = replace_string(str,"$HIC$","");
	str = replace_string(str,"$HIW$","");
	str = replace_string(str,"$NOR$","");
	str = replace_string(str,"$BNK$","");   
	str = replace_string(str,"$REV$","");
	str = replace_string(str,"$U$","");

	arg = replace_string(arg, "$BNK$", BNK);		
	arg = replace_string(arg, "$REV$", REV);


	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$U$", U);
	arg = replace_string(arg,"\\$","$");
	arg = arg + NOR;
	return arg;
}

varargs string name_id(int raw)
{
	if (raw)
	{
		return sprintf("%s(%s)", name(raw), capitalize(mask_id(1)));
	}
	else 
	{
//修改获得id的函数，改从apply/id取修改为通过parse_command_id_list()函数间接获得，假定该函数返回值的第一个id就是真实id。
//by seagate@pkuxkx
		return sprintf("%s(%s)", name(raw), 
		capitalize(mask_id(0)));
	}
}

//设置头衔，title_type必须在<title.h>和check_title函数中有定义，可以是一个头衔或者一组头衔，
//如果title为空则删除头衔
//check_key是替换关键字，在title_type为一组头衔的时候有效，表示对一组头衔进行头衔替换的时候
//具有该关键字的头衔优先被替换掉。
// create_time表示头衔创建的时间，预设值以后有用
//设置成功返回1，失败返回0
nomask varargs int set_title(mixed title_type, string title, mixed check_key, int create_time)
{
	int lp, lp2, ff;
    ff = -1;
	
	if ( !mapp(my_title) )
		my_title=([]);
//不输入头衔类型直接返回失败	
	if ( !title_type || 
		   (!stringp(title_type) &&
		    !arrayp(title_type) &&
		    (arrayp(title_type) &&
		     !stringp(title_type[0]))) )
		error("未输入头衔类型或者头衔类型输入有误。\n");
	
	if ( stringp(title_type) )
	{
//头衔类型在预定义值中不存在则直接返回失败		
	  if ( stringp(title_type) && !check_title(title_type) )
		  error("输入的头衔类型未定义。\n");
	
	  if ( !title )
		  map_delete(my_title,title_type);
	  else
		  my_title[title_type]=title;
  }
  else
  {
  	if ( !check_key ) 
  	{
  		if ( !title )
  		{
  			for(lp=0;lp<sizeof(title_type);lp++)
  			{
  				if ( !check_title(title_type[lp]) )
  					error("输入的头衔类型未定义。\n");
  			  map_delete(my_title,title_type[lp]);
  			}
  		}
  		else
  		{
            for(lp=0;lp<sizeof(title_type);lp++)
            {
                if ( !check_title(title_type[lp]) )
                    error("输入的头衔类型未定义。\n");
                if (my_title[title_type[lp]]==title) return 1;
                if (ff==-1 && !my_title[title_type[lp]]) ff = lp;
            }
            if (ff!=-1) my_title[title_type[ff]] = title;
            else my_title[title_type[sizeof(title_type)-1]] = title;
  		}
  	}
  	else 
  	{
  		if ( !stringp(check_key) &&
  			   !arrayp(check_key) &&
  			   (arrayp(check_key) &&
  			    !stringp(check_key[0])) )
  	    error("替换关键字只能是字符或者字符串阵列。\n");
  	  for(lp=0;lp<sizeof(title_type);lp++)
  		{
  			if ( !check_title(title_type[lp]) )
  					error("输入的头衔类型未定义。\n");
  			if ( !my_title[title_type[lp]] ||
  				   lp==sizeof(title_type)-1 )
  			{
  				my_title[title_type[lp]]=title;
  				break;
  			}
  			else if ( my_title[title_type[lp]]==title )
  				break;
  			if ( stringp(check_key) &&
  				   strsrch(my_title[title_type[lp]], check_key )>=0 )
  			{
  				my_title[title_type[lp]]=title;
  				break;
  			}
  			if ( arrayp(check_key) ) 
  			{
  				for(lp2=0;lp2<sizeof(check_key);lp2++)
  				{
  					if ( strsrch(my_title[title_type[lp]], check_key[lp2])>=0 )
  					{
  						my_title[title_type[lp]]=title;
  				    return 1;
  				  }
  				}
  			}
  		}
  	}
  }

	return 1;
}

//获得头衔类型对应的汉字解释
nomask string check_title(string title_type)
{
//头衔定义mapping
  mapping ttype_name=([
  TITLE_RANK   : HIW"社会阶层头衔"NOR,
  TITLE_MASTER : HIR"掌门大弟子头衔"NOR,
  TITLE_GROUP  : HIB"流派阶层头衔"NOR,
  TITLE_MJOB1  : YEL"主流任务头衔"NOR,
  TITLE_MJOB2  : YEL"主流任务头衔"NOR,
  TITLE_MJOB3  : YEL"主流任务头衔"NOR,
  TITLE_QUEST1 : WHT"普通任务头衔"NOR,
  TITLE_QUEST2 : WHT"普通任务头衔"NOR,
  TITLE_QUEST3 : WHT"普通任务头衔"NOR,
  TITLE_QUEST4 : WHT"普通任务头衔"NOR,
  TITLE_QUEST5 : WHT"普通任务头衔"NOR,
  TITLE_QUEST6 : WHT"普通任务头衔"NOR,
  TITLE_QUEST7 : WHT"普通任务头衔"NOR,
  TITLE_QUEST8 : WHT"普通任务头衔"NOR,
  TITLE_QUEST9 : WHT"普通任务头衔"NOR,
  TITLE_QUEST10 : WHT"普通任务头衔"NOR,
  TITLE_TOP1   : HIC"排行榜头衔"NOR,
  TITLE_TOP2   : HIC"排行榜头衔"NOR,
  TITLE_TOP3   : HIC"排行榜头衔"NOR,
  TITLE_TOP4   : HIC"排行榜头衔"NOR,
  TITLE_TOP5   : HIC"排行榜头衔"NOR,
  TITLE_TOP6   : HIC"排行榜头衔"NOR,
  TITLE_TOP7   : HIC"排行榜头衔"NOR,
  TITLE_TOP8   : HIC"排行榜头衔"NOR,
  TITLE_TOP9   : HIC"排行榜头衔"NOR,
  TITLE_TOP10  : HIC"排行榜头衔"NOR,
  TITLE_COMP   : CYN"比武头衔"NOR,
  TITLE_USER   : GRN"用户自定义头衔"NOR,
  TITLE_HONOR  : HIM"荣誉头衔"NOR,
  TITLE_GRANDM : HIY"武学大宗师头衔"NOR,
  TITLE_OTHER  : "其他头衔",
  TITLE_BANG   : "榜单头衔",
  TITLE_SONG1  : HBRED+HIC+"大宋差遣官头衔"NOR,
  TITLE_SONG2  : HBRED+HIW+"大宋散阶官头衔"NOR,
  TITLE_SONG3  : HBRED+MAG+"大宋加官头衔"NOR,
  TITLE_SONG4  : HBRED+HIB+"大宋特殊头衔"NOR,
  TITLE_SONG5  : HBRED+HIG+"大宋爵位头衔"NOR,
  TITLE_FAMILY : HIR"纯门派头衔"NOR,
  ]);
  return ttype_name[title_type];
}

//获得定义好的头衔，如果未输入头衔类型则默认返回社会阶层头衔。
nomask varargs string get_title(string title_type)
{
	if ( !mapp(my_title) )
		return 0;
	
	if ( !title_type )
		return my_title[TITLE_RANK];
	else
		return my_title[title_type];
}

//获得所有头衔列表
nomask mapping list_title()
{	
	return my_title;
}

//获得头衔显示内容
//新设用户属性multi_title存放title类型
nomask string show_title()
{
	string *titleArray;
	
	if ( !query("multi_title") || 
		   !pointerp(query("multi_title")) )
		return 0;
  else
  	titleArray=query("multi_title");
	if (sizeof(titleArray)==3&&stringp(titleArray[0]))
		return titleArray[0]+" "+get_title(titleArray[1])+" "+get_title(titleArray[2]);
	else if ( sizeof(titleArray)==2 )
		return get_title(titleArray[0])+" "+get_title(titleArray[1]);
	else if ( sizeof(titleArray) )
		return get_title(titleArray[0]);
	else
	  return 0;
}

//设置脸谱信息，成功返回1，失败返回0
//face_type代表脸谱类型，其中FACE_ORIGIN为原始脸谱，存放LOGIN_OB信息，FACE_FACT为真实脸谱，存放USER_OB信息，
//其他任意设置都是虚假脸谱，不同的虚假脸谱会叠加，相同的虚假脸谱会覆盖，但是如果不是和最上层的虚假脸谱相同
//则禁止，也就是说同一种面具或者说易容术不允许在多层脸谱系统中同时占用两层。
//name为名字，id为用户id，可以是string或者array，complex是虚假脸谱的复杂度，复杂度是衡量虚假脸谱级别的一个
//指标，复杂度越高的脸谱识别难度越高。虚假脸谱必须设置complex，作为基准的真实脸谱和原始脸谱不需要设置这个变量。
//others中包括关键字包括long--描述，age--年龄，gender--性别，class--bonze，taoist，officer中三选一，如果不是则
//为百姓，空则继承身体的class，shen--道德，title--头衔，family--门派
nomask varargs int set_face(string face_type, string name, mixed id, int complex, mapping others)
{
	string long,m_class,gender,title,family;
	int age,shen;
	
	if ( !my_face )
		my_face=([]);
	
	if ( others ) {
		if( stringp(others["long"]) )
			long=others["long"];
		
		if( intp(others["age"]) )
			age=others["age"];
		
		if( stringp(others["gender"]) )
			gender=others["gender"];

		if( stringp(others["class"]) )
			m_class=others["class"];
		
		if( intp(others["shen"]) )
			shen=others["shen"];

		if( stringp(others["title"]) )
			title=others["title"];
		
		if( stringp(others["family"]) )
			family=others["family"];
	}
	
	if ( !face_type )
		error("脸谱类型是必输项，不允许为空。\n");
	else if ( !strcmp(face_type,FACE_ORIGIN) && my_face[FACE_ORIGIN] )
		return 0;
	else if ( !strcmp(face_type,FACE_MASK) )
	  error("虚假脸谱设置的时候不能直接修改FACE_MASK对应的脸谱类型，请设置除预设脸谱类型以外的类型就会自动配置FACE_MASK脸谱属性。\n");
	else if ( !name )
		error("脸谱设置的时候名字不能为空。\n");
	else if ( !strcmp(face_type,FACE_ORIGIN) && 
		        ( !id || !stringp(id) ) )
		error("设置原始脸谱的时候id不能为空或者不能为非字符串类型。\n");
	else if ( id && !stringp(id) && 
		        ( !arrayp(id) || ( arrayp(id) && !stringp(id[0]) ) ) )
		error("id只能是字符串或者字符串阵列。\n");
	
	if ( !my_face[face_type] )
		my_face[face_type]=([]);

	if ( face_type==FACE_ORIGIN ||
		   face_type==FACE_FACT ) 
  {
	  my_face[face_type]["name"]=name;
	  
	  if ( face_type==FACE_ORIGIN )
	  	my_face[face_type]["id"]=id;
	  else
	  	my_face[face_type]["id"]=my_face[FACE_ORIGIN]["id"];
	  
	  if ( sizeof(long)>5 )
	  	my_face[face_type]["long"]=({long+"\n"});
	  	
	  if ( sizeof(gender)>1 )
	  	my_face[face_type]["gender"]=({gender});
	  	
	  if ( face_type==FACE_ORIGIN ) 
	  {
	  	my_face[FACE_FACT]=([]);
	  	my_face[FACE_FACT]+=my_face[FACE_ORIGIN];
	  }
	  else
	  	restore_face(FACE_FACT);
	}
	else 
	{
//多层脸谱添加，当添加的脸谱在底层脸谱存在的时候返回失败
		if ( my_face[FACE_MASK] &&
			   my_face[FACE_MASK]["mask"]!=face_type &&
			   my_face[face_type] &&
			   sizeof(keys(my_face[face_type]))>0 ) 
	  {
		  printf("同一种脸谱不能进行多层叠加。\n");
    	return 0;
    }
    
    if ( !complex )
    	error("虚假脸谱必须设置脸谱的复杂度。\n");

		my_face[face_type]["name"]=({name});
		
		if ( stringp(id) && sizeof(id)>1 )
			my_face[face_type]["id"]=({id});
		else if ( arrayp(id) && sizeof(id)>=1 )
			my_face[face_type]["id"]=id;
		else
			my_face[face_type]["id"]=({my_face[FACE_ORIGIN]["id"]});
			
		if ( sizeof(long)>5 )
	    my_face[face_type]["long"]=({long+"\n"});
	    
	  if ( sizeof(gender)>1 )
	  	my_face[face_type]["gender"]=({gender});
	  else
	  	my_face[face_type]["gender"]=({query("gender")});
	  	
	  if ( age>=14 )
	  	my_face[face_type]["age"]=({age});
	  else 
	  	my_face[face_type]["age"]=({query("age")});
	  
	  if ( !shen )
	  	my_face[face_type]["shen"]=query("shen");
	  else
	  	my_face[face_type]["shen"]=shen;
	  
	  if ( !m_class )
	  	my_face[face_type]["class"]=query("class");
	  else
	  	my_face[face_type]["class"]=m_class;
	  
	  if ( !title )
	  	my_face[face_type]["title"]=query("title");
	  else
	  	my_face[face_type]["title"]=title;
	  
	  if ( family )
	  	my_face[face_type]["family"]=family;
	  	
	  my_face[face_type]["complex"]=complex;
    
//设置一层新的虚假脸谱
		if ( !my_face[FACE_MASK] ) 
		{
	  	my_face[face_type]["previous"]=FACE_FACT;
	  	my_face[FACE_MASK]=([]);
	  	my_face[FACE_MASK]+=my_face[face_type];
	  	my_face[FACE_MASK]["mask"]=face_type;
	  }
//更新当前虚假脸谱
	  else if ( my_face[FACE_MASK]["mask"]==face_type ) 
	  {
	  	my_face[FACE_MASK]=([]);
	  	my_face[FACE_MASK]+=my_face[face_type];
	  	my_face[FACE_MASK]["mask"]=face_type;
	  }
//多层脸谱添加
    else 
    {
	  	my_face[face_type]["previous"]=my_face[FACE_MASK]["mask"];
	  	my_face[FACE_MASK]=([]);
	  	my_face[FACE_MASK]+=my_face[face_type];
	  	my_face[FACE_MASK]["mask"]=face_type;
    }
    
    mask_act();
	}
	return 1;
}

//激活虚假脸谱信息，成功返回1，失败返回0。
//仅支持虚假脸谱的信息激活
int mask_act()
{
	if ( !my_face[FACE_MASK] )
		return 0;

	delete_temp("apply/name");
	delete_temp("apply/id");
	delete_temp("apply/long");
	delete_temp("apply/age");
	delete_temp("apply/shen");
	delete_temp("apply/class");
	delete_temp("apply/gender");
	delete_temp("apply/family");
	delete_temp("apply/short");	
	set_temp("apply/name",my_face[FACE_MASK]["name"]);
	set_temp("apply/id",my_face[FACE_MASK]["id"]);
	
	if ( my_face[FACE_MASK]["long"] )
		set_temp("apply/long",my_face[FACE_MASK]["long"]);
	else
		delete_temp("apply/long");
		
	if ( my_face[FACE_MASK]["gender"] )
		set_temp("apply/gender",my_face[FACE_MASK]["gender"]);
		
	if ( my_face[FACE_MASK]["age"] )
		set_temp("apply/age",my_face[FACE_MASK]["age"]);
		
	if ( my_face[FACE_MASK]["shen"] )
		set_temp("apply/shen",my_face[FACE_MASK]["shen"]);

	if ( my_face[FACE_MASK]["class"] )
		set_temp("apply/class",my_face[FACE_MASK]["class"]);
	
	if ( my_face[FACE_MASK]["family"] )
		set_temp("apply/family",my_face[FACE_MASK]["family"]);
	
	if ( my_face[FACE_MASK]["title"] ) 
	  set_temp("apply/short", my_face[FACE_MASK]["title"] + " " + name() + "(" + capitalize(mask_id()) + ")");
	else
		set_temp("apply/short", name() + "(" + capitalize(mask_id()) + ")");
		
	return 1;
}

//清空所有脸谱信息
nomask void reset_face()
{
	my_face=([]);
}

//恢复真实脸谱信息，仅支持FACE_ORIGIN和FACE_FACT两种方式
void restore_face(string face_type)
{
	mapping face_buf=([]);
	
	if(face_type!=FACE_ORIGIN&&face_type!=FACE_FACT)
		error("恢复真实脸谱信息函数仅支持FACE_ORIGIN和FACE_FACT两种脸谱类型。\n");
	
	delete_temp("apply/name");
	delete_temp("apply/id");
	delete_temp("apply/long");
	delete_temp("apply/age");
	delete_temp("apply/shen");
	delete_temp("apply/class");
	delete_temp("apply/gender");
	delete_temp("apply/family");
	delete_temp("apply/short");
	set("name",my_face[face_type]["name"]);
	set("id",my_face[face_type]["id"]);
	
	if ( my_face[face_type]["long"] )
		set("long", my_face[face_type]["long"]);
	else
		delete("long");
		
	if ( face_type==FACE_ORIGIN ) 
	{
		my_face[FACE_FACT]=([]);
		my_face[FACE_FACT]+=my_face[FACE_ORIGIN];
	}
	
	if ( my_face[FACE_MASK] ) 
	{
		face_buf[FACE_ORIGIN]=([]);
		face_buf[FACE_FACT]=([]);
		face_buf[FACE_ORIGIN]+=my_face[FACE_ORIGIN];
		face_buf[FACE_FACT]+=my_face[FACE_FACT];
		my_face=([]);
		my_face+=face_buf;
	}
}

//除去一层面具
void uncover_mask()
{
	string mask;
	
	if ( !my_face[FACE_MASK] )
		restore_face(FACE_FACT);
	else if ( my_face[FACE_MASK] && 
		   my_face[FACE_MASK]["previous"]==FACE_FACT )
		restore_face(FACE_FACT);
	else 
	{
		mask=my_face[FACE_MASK]["previous"];
		map_delete(my_face, my_face[FACE_MASK]["mask"]);
		my_face[FACE_MASK]=([]);
		my_face[FACE_MASK]+=my_face[mask];
		my_face[FACE_MASK]["mask"]=mask;
		mask_act();
	}
}

//返回脸谱的复杂度
varargs int query_face_complex(string face_type)
{
	if ( !face_type )
		return my_face[FACE_MASK]["complex"];
	else if ( face_type==FACE_ORIGIN ||
		        face_type==FACE_FACT )
		return 0;
	else
		return my_face[face_type]["complex"];
}

//检查面具下面的真实面孔，外部调度的时候一定不要给
//mask_type变量赋值
//level 为0的时候直接返回当前脸谱信息，大于0的时候返回一直钻探到第LEVEL层的脸谱
//level 为-1的时候直接返回原始脸谱
//当level大于0的时候就需要输入complex来和已经戴上的脸谱复杂度进行对抗，只有
//你掌握的技能比脸谱复杂度高才能够对抗成功，成功获得更加真实的用户信息。
varargs mapping check_mask(int level, int complex, string mask_type)
{
	if ( !my_face )
		return 0;

	if ( !my_face[FACE_MASK] && level>=0 )
		return my_face[FACE_FACT];

	if ( !level )
		return my_face[FACE_MASK];
	else if ( level<0 )
		return my_face[FACE_ORIGIN];
	else if ( level>0 && !complex )
		return my_face[FACE_MASK];
	
  if ( mask_type && !my_face[mask_type] )
  	return 0;
  
  if ( !mask_type ) 
  {
  	if ( complex<query_face_complex() )
  		return my_face[FACE_MASK];
  		
  	if ( my_face[FACE_MASK]["previous"]==FACE_FACT )
  		return my_face[FACE_FACT];
  	else if ( level==1 )
  		return my_face[my_face[FACE_MASK]["previous"]];
  	else
//多层面具底层面具增加上层面具复杂度带来的增益
//by seagate@pkuxkx 2010/12/06
 		  return check_mask(level-1, complex - query_face_complex()/2, my_face[FACE_MASK]["previous"]);
  }
  else 
  {
  	if ( complex<query_face_complex(mask_type) )
  		return my_face[mask_type];
  		
  	if ( my_face[mask_type]["previous"]==FACE_FACT )
  		return my_face[FACE_FACT];
  	else if ( level==1 )
  		return my_face[my_face[mask_type]["previous"]];
  	else
//多层面具底层面具增加上层面具复杂度带来的增益
//by seagate@pkuxkx 2010/12/06
 		  return check_mask(level-1, complex - query_face_complex(mask_type)/2, my_face[mask_type]["previous"]);
  }
}

//检查是否佩戴面具
int is_mask()
{
	if ( !my_face)
		return 0;

	if ( my_face[FACE_MASK] && 
		   my_face[FACE_MASK]["name"]=query_temp("apply/name") )
	  return 1;
	else
		return 0;
}

//校验是否可以识破伪装（仅校验表层伪装）
int can_anti_disguise(int complex)
{
	if ( complex>query_face_complex() )
		return 1;
	else
		return 0;
}