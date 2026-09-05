//addcname.c
//made by jason@indeed for vworld
//2001.3.16

int main(string me,string arg)
{
	string cname,id;
	if(sscanf(arg,"%s %s",cname,id)!=2)
		return notify_fail("指令格式：addcname 中文名 id\n");
	if(CNAME_D->add_cname(cname,id))
		write("中文名:"+cname+"("+id+")添加成功！\n");
	else
		write("中文名:"+cname+"("+id+")添加失败。\n");
	return 1;
}