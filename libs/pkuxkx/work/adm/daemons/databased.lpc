// databased.c
// by 发现号(Find@TX).

#include <station.h>
#include <database.h>

class target
{
	string host;
	string user;
	mapping quest;
}

#ifdef STATIC_LINK
protected int db_handle = 0;
#endif

protected mixed *all_target = ({});
protected int max_repeat = 3;
protected void broadcast(string sql);

protected void init_target()
{
	if(!sizeof(all_others_db))
		return;

	foreach(string h,string u in all_others_db)
	{
		class target one;

		one = new(class target);
		one->host = h;
		one->user = u;
		one->quest = ([]);
		all_target += ({ one });
	}
}


protected void log_error(string func,mixed err)
{
	log_file("database",sprintf("%s ERROR ** %s\n%O\n",func,ctime(time()),err));
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
	mixed n;

	n = db_connect(DB_HOST, DATABASE, DB_USER);

	if(intp(n) && (n > 0))	// 连接成功
#ifdef STATIC_LINK
	{
		db_handle = n;
		return;
	}
#else
		return n;
#endif

	else
	{
		log_error("db_connect",n);
#ifdef STATIC_LINK
		call_out("connect_to_database",30);
		return;
#endif
		return 0;
	}
}

protected void close_database(int db)
{
	mixed ret;

	if(!intp(db) || (db < 1))
		return 0;

	ret = db_close(db);

	if(intp(ret) && (ret == 1))
		return;

	else
		log_error("db_close",ret);
}

protected void create()
{
	seteuid(ROOT_UID);
#ifdef STATIC_LINK
	connect_to_database();
#endif
	init_target();
}

protected int valid_caller()
{
	if( !previous_object()
	|| (previous_object() != find_object(SIMUL_EFUN_OB)) )
		return 0;

	else
		return 1;
}

// 查询中文名是否可用
int db_permit_add_cname(string name)
{
	int db;
	mixed ret;
	string sql;

	if(!valid_caller())
		return 0;

	if( !stringp(name) || (name == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE name = \"%s\"",REGISTERED_TABLE,name);
	ret = db_exec(db,sql);
	if(!intp(ret) || ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("permit_add_cname.db_exec",ret);
		return 0;
	}

	sql = sprintf("SELECT id FROM %s WHERE name = \"%s\"",TEMP_TABLE,name);
	ret = db_exec(db,sql);
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error("permit_add_cname.db_exec",ret);
		return 0;
	}

	return !(ret);
}

// 查电子邮件地址能否注册
int db_permit_reg_email(string email)
{
	int db;
	mixed ret;
	string sql;

	if(!valid_caller())
		return 0;

	if( !stringp(email) || (email == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE email = \"%s\"",REGISTERED_TABLE,email);
	ret = db_exec(db,sql);
	if(!intp(ret) || ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("permit_reg_email.db_exec",ret);
		return 0;
	}

	sql = sprintf("SELECT id FROM %s WHERE email = \"%s\"",TEMP_TABLE,email);
	ret = db_exec(db,sql);
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error("permit_reg_email.db_exec",ret);
		return 0;
	}

	return !(ret);
}

// 查询指定时间未成功注册的玩家
string *db_query_exceed_reg_time()
{
	int db,i,n;
	string sql,*player;
	mixed ret;

	if(!valid_caller())
		return 0;
#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE station = \"%s\" AND (UNIX_TIMESTAMP() - UNIX_TIMESTAMP(dtime)) > %d",
		TEMP_TABLE, local_station, reg_time);
	ret = db_exec(db,sql);
	if(!intp(ret) || !ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("query_exceed_reg_time.db_exec",ret);
		return 0;
	}

	player = allocate(ret);
	for(i=1; i <= ret; i++)
		player[i-1] = db_fetch(db,i)[0];

	foreach(string id in player)
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"", TEMP_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error("query_exceed_reg_time.db_exec(DEL)",ret);
			log_file("database",sprintf("%O\n\n",player));
		}

		n = db_affected(db);
		if( n < 1 )
			log_error("query_exceed_reg_time.db_exec(DEL)",sprintf("Can not del (%s)",id));

		broadcast(sql);
	}

#ifndef STATIC_LINK
	close_database(db);
#endif

	return player;
}

// 删除一个未注册玩家
int db_del_temp_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("del_temp_user(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
	if(n < 1)
		log_error(sprintf("del_temp_user(%s).db_exec",id),"Fail to del.\n");

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// 删除一个正式注册玩家
int db_del_reg_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",REGISTERED_TABLE, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("del_reg_user(%s).db_exec",id),ret);
		return 0;
	}
	n = db_affected(db);
	if(n < 1)
		log_error(sprintf("del_reg_user(%s).db_exec",id),"Fail to del.\n");

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// 删除玩家状态未知
int db_del_unknow_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	// 先查询 TEMP_TABLE
	sql = sprintf("SELECT id FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("select (%s) from tmp_table.db_exec",id),ret);
		return 0;
	}

	if(ret) // 找到
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error(sprintf("del_temp_user(%s).db_exec",id),ret);
			return 0;
		}

		broadcast(sql);

		n = db_affected(db);
		if(n < 1)
			log_error(sprintf("del_temp_user(%s).db_exec",id),"Fail to del.\n");
#ifndef STATIC_LINK
		close_database(db);
#endif
		return n;
	}

	else
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",REGISTERED_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error(sprintf("del_reg_user(%s).db_exec",id),ret);
			return 0;
		}
		n = db_affected(db);
		if(n < 1)
			log_error(sprintf("del_reg_user(%s).db_exec",id),"Fail to del.\n");

		broadcast(sql);

#ifndef STATIC_LINK
		close_database(db);
#endif
		return n;
	}
}


/************************
 *  新玩家的三个操作
 ***********************/

int db_newbie_buildup(string id,string name)
{
	int db, n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == "")
	|| !stringp(name) || (name == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_buildup(%s).db_exec",id),ret);
		return 0;
	}

	if(ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",NULL,NOW(),\"%s\")",TEMP_TABLE,id,name,local_station);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("newbie_buildup(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif

	return n;
}

int db_newbie_reg(string id, string email)
{
	int db, n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == "")
	|| !stringp(email) || (email == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("UPDATE %s SET email = \"%s\" WHERE id = \"%s\"",TEMP_TABLE,email,id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("newbie_reg(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

int db_newbie_success_reg(string id)
{
	int db,n;
	string sql,*res;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT name,email FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_success(select %s).db_exec",id),ret);
		return 0;
	}

	if(!ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("newbie_success.db_exec",sprintf("can not find (%s) from tmp_table",id));
		return 0;
	}

	res = db_fetch(db,1);

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("newbie_success.db_exec",sprintf("can not delete (%s) from tmp_table",id));
		return 0;
	}
	n = db_affected(db);
	if(n < 1)
		log_error("newbie_success.db_exec",sprintf("did not delete (%s) from tmp_table",id));

	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",\"%s\",\"%s\")",REGISTERED_TABLE,id,res[0],res[1],local_station);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_success(insert %s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

/************************
 *  newbie_buildup, newbie_reg, newbie_success
 ***********************/

// 改名
int db_change_chinese_name(string id,string to)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if( !stringp(id) || (id == "")
	|| !stringp(to) || (to == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("UPDATE %s SET name = \"%s\" WHERE id = \"%s\"",
		REGISTERED_TABLE, to, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("change_chinese_name(%s.to%s).db_exec",id,to),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// 计算所有的正式注册玩家数量
int db_count_reg_user()
{
	int db;
	mixed ret,*res;

	if(!valid_caller())
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT COUNT(*) FROM %s",REGISTERED_TABLE));
	if(!intp(ret) || (ret < 1))
	{
		log_error("count_reg_user",ret);
		return 0;
	}

	res = db_fetch(db,1);
#ifndef STATIC_LINK
	close_database(db);
#endif

	return res[0];
}

// 查询玩家所在的分站
string db_query_register_station(string id)
{
	int db;
	mixed ret,*res;

	if(!valid_caller())
		return 0;

	if( !stringp(id) || (id == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT station FROM %s WHERE id = \"%s\"",TEMP_TABLE,id));

	if(!intp(ret))
	{
		log_error("query_register_station",ret);
		return 0;
	}

	if(ret > 0)
	{
		res = db_fetch(db,1);
		return res[0];
	}

	ret = db_exec(db,sprintf("SELECT station FROM %s WHERE id = \"%s\"",REGISTERED_TABLE,id));

	if(!intp(ret))
	{
		log_error("query_register_station",ret);
		return 0;
	}

	if(ret > 0)
	{
		res = db_fetch(db,1);
		return res[0];
	}

	else
		return 0;
}

/******************
 * 典当部分的查询 *
 ******************/

//检索出某一特定玩家所当过的，未超期的所有物品。
mixed *query_user_all_pob(string id)
{
	int db,time;
	mixed ret, *res;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !id
	|| !stringp(id) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	time = time();
	ret = db_exec(db, sprintf("SELECT * FROM %s WHERE id = \"%s\" AND ptime > %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error("query_user_all_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	res = allocate(ret);
	for(int i=1;i<=ret;i++)
		res[i-1] = db_fetch(db,i);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return res;
}

// 计算一个玩家已典当物品的总数量
int query_count_user_pob(string id)
{
	int db,n;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !id
	|| !stringp(id) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db, sprintf("SELECT COUNT(*) FROM %s WHERE id = \"%s\"",PAWN_TABLE,id));
	if(!intp(ret))
	{
		log_error("query_user_all_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	n = db_fetch(db,1)[0];
#ifndef STATIC_LINK
	close_database(db);
#endif

	return n;
}

// 典当一件物品
int pawn_one_object(mixed *pob)
{
	int db,n;
	string sql;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !pob
	|| !sizeof(pob) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

//                                            master, pob,time, shop, long
	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",%d,\"%s\",\"%s\")",
		PAWN_TABLE,
		pob[0],pob[1],pob[2],pob[3],pob[4]);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
		log_error("pawn_one_object",ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return (n > 0);
}

// 赎回一件物品
int retrieve_one_object(string id,int time)
{
	int db,n;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !stringp(id)
	|| (id == "")
	|| (time <= 0) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT id FROM %s WHERE id = \"%s\" AND ptime = %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error(sprintf("retrieve_one_object(%s,%d)",id,time),ret);
		return 0;
	}

	if(ret < 1)
		return -1;

	ret = db_exec(db,sprintf("DELETE FROM %s WHERE id = \"%s\" AND ptime = %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error(sprintf("retrieve_one_object(%s,%d)",id,time),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif

	return (n > 0);
}

// 清除一个玩家所有的典当品
void del_user_all_pob(string id)
{
	int db;
	mixed ret;

	if(!valid_caller())
		return;

	if(!stringp(id) || (id == ""))
		return;

#ifdef STATIC_LINK
	if(!db_handle)
		return;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return;
#endif

	ret = db_exec(db,sprintf("DELETE FROM %s WHERE id = \"%s\"",PAWN_TABLE,id));
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error(sprintf("del_user_all_pob(%s)",id),ret);
		return;
	}
}

// 输出所有到期未赎回的物品
string *query_all_exceed_pob()
{
	int db,time,all,n;
	mixed ret,*res;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	time = time();
	ret = db_exec(db,sprintf("SELECT obj FROM %s WHERE ptime <= %d",PAWN_TABLE,time));
	if(!intp(ret))
	{
		log_error("query_all_exceed_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	res = allocate(ret);
	for(int i=1; i<= ret; i++)
		res[i-1] = db_fetch(db,i)[0];

	all = ret;

	// 我这写法恐怕有些问题
	ret = db_exec(db,sprintf("DELETE FROM %s WHERE ptime <= %d",PAWN_TABLE,(time+2)));
	if(!intp(ret))
		log_error(sprintf("del_all_exceed_pob(%d)",(time+2)),ret);

	n = db_affected(db);

	if(n < all)
		log_error(sprintf("del_all_exceed_pob(%d)",(time+2)),sprintf("except %d, get %d.\n",all,n));

	return res;
}

#ifdef STATIC_LINK
void remove(string id)
{
	if(!valid_caller())
		return;

	close_database(db_handle);
}
#endif

protected void broadcast(string sql)
{
	if(!all_target || !sizeof(all_target))
		return;

	foreach(class target one in all_target)
		one->quest += ([ sql : 0 ]);

	if(find_call_out("do_broadcast") == -1)
		call_out("do_broadcast",3);
}

protected void do_broadcast()
{
	mixed n;
	int flag = 0;

	if(!sizeof(all_others_db) || !sizeof(all_target))
		return;

	foreach(class target one in all_target)
	{
		if(sizeof(one->quest))
		{
			n = db_connect(one->host, DATABASE, one->user);
			if(intp(n) && (n > 0))	// 连接成功
			{
				foreach(string sql,int num in one->quest)
				{
					mixed ret;
					ret = db_exec(n,sql);
					if( intp(ret) && (db_affected(n) > 0) )
					{
						map_delete(one->quest,sql);
						continue;
					}
					else if( ++one->quest[sql] >= max_repeat )
					{
#ifdef STATIC_LINK
						if(!db_handle)
							log_error(sprintf("Fail add fail cmd to: %s",one->host),sql);
						else
							db_exec(db_handle,sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\")",
								FAIL_CMD_TABLE, one->host, sql));
							
#else
						int db;

						if(!(db = connect_to_database()))
							log_error(sprintf("Fail add fail cmd to: %s",one->host),sql);
						else
							db_exec(db,sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\")",
								FAIL_CMD_TABLE, one->host, sql));
#endif
						map_delete(one->quest,sql);
					}
				}
				db_close(n);
			}
			if(sizeof(one->quest))
				flag++;
		}
	}

	if(flag)
		call_out("do_broadcast",10);
}
