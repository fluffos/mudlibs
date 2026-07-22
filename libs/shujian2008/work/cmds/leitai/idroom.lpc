inherit F_CLEAN_UP;

#define NID_PATH "/log/data/"
#define ID_PATH "/data/"

private int check_passwd(string id, string passwd)
{
	string pass;

	sscanf(read_file(NID_PATH+"login/"+id[0..0]+"/"+id + SAVE_EXTENSION), "%*s\"password\":\"%s\",", pass);
	return (crypt(passwd, pass) == pass);
}

private string change_id(string stat, string id, string nid)
{
	return replace_string(stat, "\"id\":\""+id+"\",", "\"id\":\""+nid+"\",");
}

private int copy_file(string id, string nid)
{
	if (write_file(ID_PATH+"login/"+nid[0..0]+"/"+nid+SAVE_EXTENSION,
	change_id(read_file(NID_PATH+"login/"+id[0..0]+"/"+id + SAVE_EXTENSION), id, nid),
	1) &&
	write_file(ID_PATH+"user/"+nid[0..0]+"/"+nid+SAVE_EXTENSION,
	change_id(read_file(NID_PATH+"user/"+id[0..0]+"/"+id + SAVE_EXTENSION), id, nid),
	1))
		return 1;
	return 0;
}

private int del_file(string id)
{
	if (rm(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION)
	&& rm(NID_PATH +"user/" + id[0..0] +"/"+ id + SAVE_EXTENSION))
		return 1;
	return 0;
}

private int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if( i < 3 || i > 8 ) {
		write("新 ID 必须是 3 到 8 个英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i] < 'a' || id[i] > 'z' ) {
			write("新 ID 只能用小写英文字母。\n");
			return 0;
		}
	return 1;
}

void do_change(string id, string nid, string passwd)
{
	if (wiz_level(id) || wiz_level(nid))
	{
		write("噶哈……你想噶哈！\n");
		return;
	}
	if (file_size(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" 登录档案不存在，无法更换 ID。\n");
		return;
	}
	if (file_size(NID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" 数据档案不存在，无法更换 ID。\n");
		return;
	}
	if (!check_passwd(id, passwd))
	{
		write("密码不对。\n");
		return;
	}
	// 如果没有此玩家，不准换 id
	if (file_size(ID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0 ||
	file_size(ID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0)
	{
		if (id != nid) write(capitalize(id) + " 无人占用，忽略更换 ID 的请求，继续使用原 ID。\n");
		nid = id;
	}
	else if (file_size(ID_PATH +"login/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) >0
	&& file_size(ID_PATH +"user/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) > 0)
	{
		write(capitalize(nid) +" 已经存在，请选择新 ID 重新转换。\n");
		return;
	}
	if (!check_legal_id(nid)) return;

	write("正在转换 "+id+" -> "+nid+" ... ");
	if (!copy_file(id, nid))
	{
		write(" 失败\n");
		log_file("CHANGE", sprintf("%s %s -> %s 拷贝失败\n", ctime(time())[4..19], id, nid));
		return;
	}
	write(" 成功\n删除原始数据 ... ");
	if (!del_file(id))
	{
		write(" 失败\n");
		log_file("CHANGE", sprintf("%s %s -> %s 删除失败\n", ctime(time())[4..19], id, nid));
		return;
	}
	write(" 成功\n转换完毕\n");
	log_file("CHANGE", sprintf("%s %s -> %s 成功\n", ctime(time())[4..19], id, nid));
}

private void create()
{
	seteuid(getuid());
}
