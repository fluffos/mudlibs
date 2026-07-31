
#include <ansi.h>
inherit F_CLEAN_UP;
#define PAT "/log/adm/mrt"
int main(object me, string arg)
{
int diff=0;
int i,ii,iii,qd,times;
string is,msg,skills,name,*line;
object npc,where,room;
mapping skill;
where = environment(me);
room = load_object("/d/city/mingrt");
qd=room->query("mrt")*100;
if(!arg){
iii=file_size(PAT);
log_file("adm/mrt",sprintf(""));	
if(iii<1)
return notify_fail(HIR"暂时没有人挑战名人堂，指令：kills 开始挑战！\n"NOR);		
is = read_file(PAT);	
line = explode(is,"\n");
msg="本轮名人堂战况："ZJBR;
for(i=0;i<10;i++){
sscanf(line[i],"%s=%d",name,times);
msg+="第"+(i+1)+"击："+name+"，用时 "+times+"秒"ZJBR;
}
msg=ZJOBLONG+msg+"目前名人堂高手强度%"+to_int(qd)+"，技能强度%100"ZJBR"你确定进行挑战吗？\n";
msg+=ZJOBACTS2+ZJMENUF(1,1,9,32);
msg+="挑战:kills\n";
write(msg+NOR);
}

return 1;
}


