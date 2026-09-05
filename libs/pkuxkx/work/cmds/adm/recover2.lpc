//recover.c

int main(object me,string arg)
{
	object ppl;
	mapping skills;
	string *key,*value;
	if(!arg||arg=="") return 0;
	if(!objectp(ppl=find_player(arg))) return 0;
	skills=ppl->query_skills();
	if(sizeof(skills)==0) return 0;
	key=keys(skills);
	for(int i=0;i<sizeof(key);i++)
	{
		ppl->set_skill(key[i],skills[key[i]]*2);
	}
//        shout(ppl->name()+"武功恢复，技能加倍。\n");
	log_file("wiz/recover",ppl->name()+"恢复技能两倍，时间："+ctime(time())+"\n"+
	"执行人："+getuid(me)+"\n");
	ppl->save();
	return 1;
}
