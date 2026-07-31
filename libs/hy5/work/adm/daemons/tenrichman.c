//以下是/adm/daemons/tenrichmand.c定义了一些基本函数：

//tenrichmand.c
////////////////////////////////////////////////////////////////////////////////
//
//1997.5.20 finished
//by maxim@nju_mud
//1997.12.1重新整理
////////////////////////////////////////////////////////////////////////////////
//
#include <login.h>
string *gaoshou_status;
string gaoshou_id_min;
string gaoshou_name_min;
int gaoshou_exp_min;
int gaoshou_number_min;
string gaoshou_title_min;

void create()
{
seteuid(geteuid());
}

// This function returns the status of an uid.
int set_rich(mixed ob, int exp)
{
string uid, gaoshou_id,gaoshou_name,gaoshou_title;
string now_id,now_name,now_title;
string *gaoshoulist,gaoshoulist2;
int i,j,gaoshou_exp,now_exp;

if( userp(ob) ) uid = getuid(ob);
else if(stringp(ob)) uid = ob;
else
return 0;



gaoshoulist = explode(read_file(RICHMAN), "\n");

//RICHMAN is the file to be read
//在/include/login.h中有定义。
//由于没有判断文件读错的代码，所以事先要保证
//文件的格式正确。

gaoshou_status = allocate(sizeof(gaoshoulist));
for(i=0; i<10; i++) {
if( sscanf(gaoshoulist[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,
gaoshou_exp)!=4 ) continue;
gaoshou_status[i] = (string)gaoshou_id+" "+
(string)gaoshou_name+" "+
(string)gaoshou_title+" "+
(string)gaoshou_exp;
}

for(i=0; i<9; i++){
for(j=0;j<9-i;j++){
if( gaoshou_status[j][0]=='#'
|| sscanf(gaoshou_status[j], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if( gaoshou_status[j+1][0]=='#'
|| sscanf(gaoshou_status[j+1], "%s %s %s %d", now_id,now_name,now_title,now_exp)
!=4 ) continue;
if(gaoshou_exp < now_exp){
gaoshou_status[j]=now_id+" "+now_name+" "+now_title+" "+(string)now_exp;
gaoshou_status[j+1]=gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp;
}
}
}

gaoshou_exp_min=3000000000000;
//最富的人的钱要少于这个数目
sscanf(gaoshou_status[4], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp) ;
gaoshou_exp_min=gaoshou_exp;

//取得关键码最小值的数据信息
for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(gaoshou_exp < gaoshou_exp_min){
gaoshou_id_min=gaoshou_id;
gaoshou_number_min=i;
gaoshou_name_min=gaoshou_name;
gaoshou_title_min=gaoshou_title;
gaoshou_exp_min=gaoshou_exp;
}
}

for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(uid == gaoshou_id){
gaoshou_id_min=gaoshou_id;
gaoshou_number_min=i;
gaoshou_name_min=gaoshou_name;
gaoshou_title_min=gaoshou_title;
gaoshou_exp_min=gaoshou_exp;
break;
}
}


gaoshou_name=(string)ob->query("name");
gaoshou_title=(string)ob->query("title");

//更新已经存在的人的数据，或者把最小值的人的数据替代
if( (int)exp > (int)gaoshou_exp_min || uid == gaoshou_id) {
gaoshou_status[gaoshou_number_min]=
uid+" "+gaoshou_name+" "+gaoshou_title+" "+ (string)exp;

//由于数据已经改变，此处是重新排序
for(i=0; i<9; i++){
for(j=0;j<9-i;j++){
if( gaoshou_status[j][0]=='#'
|| sscanf(gaoshou_status[j], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if( gaoshou_status[j+1][0]=='#'
|| sscanf(gaoshou_status[j+1], "%s %s %s %d", now_id,now_name,now_title,now_exp) !=4 ) continue;
if(gaoshou_exp < now_exp){
gaoshou_status[j]=now_id+" "+now_name+" "+now_title+" "+(string)now_exp;
gaoshou_status[j+1]=gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp;

}
}
}
//以下为写文件
for(gaoshoulist2 = "", i=0; i<10; i++){
if( gaoshou_status[i][0]=='#'
|| sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;

gaoshoulist2+= gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp+"\n";
}

rm(RICHMAN);
write_file(RICHMAN, gaoshoulist2);

//记录更新信息
log_file( "static/tenrich", capitalize(uid)
+ " become 十大富翁之一: " + exp + " on " + ctime(time()) + "\n" );

//准备返回此玩家最新排名值
for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(uid == gaoshou_id){
break;
}
}

return (i+1);
}
else return 0;

}

