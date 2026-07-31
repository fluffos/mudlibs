//Cracked by Kafei
//函数说明文件
文件函数:
文件名称:
	job_family_master.h  //定义master的描述信息.
变量:
	static mapping family_master 			//	每个门派master的称号
	static mapping family_master_place		//    每个门派 master的地点
	static mapping *wudang_message
	static mapping *xingxiu_message
	static mapping *huashan_message        //，每个门派master说的话
	static mapping *taohua_message
	static mapping *gaibang_message
	static mapping *emei_message
	static mapping *baituo_message
	static mapping *quanzhen_message
	static mapping *xueshan_message
	static mapping *dali_message
	static mapping *shaolin_message

文件名称:
	job_area.h			//地域定义文件
变量:
	string *zhongyuan	//每个地域所包含的地区
	string *jiangnan
	string *nanjiang
	string *xiyu
	string *dongbei

	string *cant_go_room //不能进入的房间列表
函数:
	string *get_arearoom(string area)//获取指定区域的房间文件名列表
	int judge_room(string room_name)//鉴定所选取的房间是否合乎条件(比如是否是nofight room...)
	string get_room(string area)//从一个区域中获得做任务的房间

	
文件名称:
	oppose_pker.h				//产生oppose_pker类型任务的文件
函数:
	int	oppose_pker(object master,object player,mapping job)//产生oppose_pker的主函数
	void out_killer(object player,object place)//killer出现的函数
	int job_oppsse_pker_start(object player)//到达地点后开始准备出现killer
	int award_oppose_pker(object player)//oppose_pker的奖励函数

文件名称:
	job_produce.h   //任务产生器的基本函数定义文件

函数:
	
	int assign_job(object master,object player,mapping map) //根据map指派任务
	int finish_job(object player)//任务完成的函数
	int master_tell_player(object player)//master向player下达任务的函数
	int award_job(int exp_lim,int pot_lim,int time1,int time2,int luck,
		int neili,int jingli,int skills_lim,object player,object master)
	//奖励函数
	void job_punish(object player,string job_kind)//惩罚函数
	int del_job(object player)//删除任务

文件名称:
	produce.c //产生任务的主函数
变量:
	string menpai_name;//产生任务的门派 
	string strategy_produce;//选择门派产生的策略名称。
	string menpai_area_power;//选择门派产生任务的区域。
	static object job_data;	//这个任务的相关数据文件
	static mapping job_map;		

	

函数:
	object choose_user(string menpai_name)//从在线的用户中选择任务的执行者
	int do_check_user(object ob,string menpai_name)//判断用户是否满足条件的子函数
	int do_check_job_player(object ob,string *list)//判断当前用户是否属于任务的执行者的子函数
	int choose_job(object player)//选择任务
	int check_finishjob_place()//判断完成任务后是否回到master palce.
	int check_askjob_place()//判断接到下达命令的人是否到达 master place
	int check_oppose_pker_place()//检查执行者的所在地，是否为oppose_pker place
	int check_player_place()//一个控制全面job执行这的函数//定时检查所有的xkx online player，做出相应的处理。
	int job_tell_player(object player)//任务产生后，告诉执行任务的玩家相关信息
	void create()
	string query_save_file()
	int produce_job(string p_name)//产生任务的主函数
	int choose_menpai()//选择门派
	int choose_strategy(string menpai)//选择门派下达任务的策略
	int choose_area_power(string menpai)//选择执行任务的区域


	message.h
	int job_oppsse_pker_prompt(object player)//提示执行者去完成oppsse_pker任务.
	int master_msg(object master,object player,string state,string command_mode)
	//从数据库中获得massage并进行名称替换






























