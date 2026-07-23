// change.c
// Created By Numa@SJ 2000.9.13

inherit F_CLEAN_UP;

#define NID_PATH "/data/"
#define ID_PATH "/data/"

int change_id(string file, string id, string nid)
{
        string stat;
        
        stat = read_file(file);
	stat = replace_string(stat, "\"id\":\""+id+"\",", "\"id\":\""+nid+"\",");
        if (!write_file(file, stat, 1)) {
                write("文件 "+ file +" 存储失败。\n");
                return 0;
        }
        return 1;
}

int copy_file(string id, string nid, int t)
{
        if (t) {
                if (cp(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION, 
                        ID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION)
                 && cp(NID_PATH +"user/" + id[0..0] +"/"+ id + SAVE_EXTENSION, 
                        ID_PATH +"user/" + id[0..0] +"/"+ id + SAVE_EXTENSION))
                        return 1;
                else
                        return 0;
        }
        if (cp(NID_PATH +"login/" + id[0..0] +"/"+ id + SAVE_EXTENSION, 
                ID_PATH +"login/"+ nid[0..0] +"/"+nid + SAVE_EXTENSION)
         && cp(NID_PATH +"user/"  + id[0..0] +"/"+ id + SAVE_EXTENSION, 
                ID_PATH +"user/" + nid[0..0] +"/"+nid + SAVE_EXTENSION))
                return 1;
        else
                return 0;
}

int del_file(string id)
{
        if (rm(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION)
         && rm(NID_PATH +"user/" + id[0..0] +"/"+ id + SAVE_EXTENSION))
                return 1;
        return 0;
}

int check_legal_id(string id)
{
        int i;
        i = strlen(id);
        if( i < 3 || i > 8 ) {
                write("对不起，新ID必须是 3 到 8 个英文字母。\n");
                return 0;
        }
        while(i--)
                if( id[i] < 'a' || id[i] > 'z' ) {
                        write("对不起，新ID只能用小写英文字母。\n");
                        return 0;
                }
        return 1;
}

int main(object me, string arg)
{
        object ob;
        string id, nid;

        seteuid(ROOT_UID);      
        if (!arg)
                return notify_fail("指令格式：change <ID> <new ID>.\n");
        if (sscanf(arg, "%s %s", id, nid) != 2) {
		id = arg;
		nid = arg[0..7];
	}
	if (strlen(id) < 9) return notify_fail("只有超过 8 个字母的 ID 才需要转换。\n");
        if (!check_legal_id(nid))
                return notify_fail("指令格式：change <ID> <new ID>.\n");
        if (file_size(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0)
                return notify_fail(capitalize(id) +" 登录档案不存在，无法更换ID。\n");
        if (file_size(NID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0)
                return notify_fail(capitalize(id) +" 数据档案不存在，无法更换ID。\n");
        ob = new(LOGIN_OB);
        ob->set("id", nid);
        if (ob->restore()) {
                destruct(ob);
                return notify_fail(capitalize(nid) +"已经存在，请更改新ID重新转换。\n");
        }
        destruct(ob);
        ob = new(LOGIN_OB);
        ob->set("id", id);
        if (!ob->restore()) {
                destruct(ob);
                if (copy_file(id, id, 1))
                        return notify_fail(capitalize(id) +" 无须更改，文件拷贝成功，"+
                                capitalize(id) +"可以直接登录。\n");
		return notify_fail(capitalize(id) +" 无须更改，文件拷贝失败。\n");
        }
        destruct(ob);
// changing login data id
	if (!change_id(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION, id, nid))
                return notify_fail("登录文件更改ID失败。\n");
// changing user data id
	if (!change_id(NID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION, id, nid))
                return notify_fail("数据文件更改ID失败。\n");
        if (!copy_file(id, nid, 0))
                return notify_fail("复制文件失败。\n");
        if (!del_file(id))
                return notify_fail("删除原始文件失败。\n");
        write("玩家"+ capitalize(id) +"已经更改为"+ capitalize(nid) +"。\n");
// log file
        log_file("CHANGE",sprintf("%s %s(%s) 将 %s 更改为 %s .\n", ctime(time())[4..19], me->name(1), geteuid(me), id, nid));
        return 1;
}

int help()
{
        write(@HELP

指令格式：change <ID> <new ID>.

此指令用来更改玩家ID，请慎重使用。

HELP
        );
        return 1;
}

