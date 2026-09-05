
#include <ansi.h>

int move_money(int amount);
int write_money_log(object room,int amount);
int get_number();
int get_write_number();
void write_log(object room_o,string number);
int del_log(string x);

int move_money(int amount)
{
	string *path = ({
        "/d/huashan/",//"华山",
        "/d/wudang/",//"武当山",
        "/d/shaolin/",//"少林寺",
        "/d/yuewangmu/",//"岳王墓",
        "/d/gumu/",//"古墓",
        "/d/luoyang/",//"洛阳",
        "/d/lingzhou/",//"灵州",
        "/d/dalunsi/",//"大轮寺",
        "/d/shenlongdao/",//"神龙岛",
        "/d/yashan/",//"牙山",
        "/d/pker/",//"杀手帮",
        "/d/taishan/",//"泰山",
        "/d/xiangyang/",//"襄阳",
        "/d/xingxiu/",//"星宿",
        "/d/quanzhou/",//"泉州",
        "/d/village/",//"小山村",
        "/d/quanzhen/",//"全真",
        "/d/taohuadao/",//"桃花岛",
        "/d/pingxiwangfu/",//"平西王府",
        "/d/riyuejiao/",//"日月神教",
        "/d/gaibang/",//"丐帮",
        "/d/baituo/",//"白驼山",
        "/d/mingjiao/",//"明教",
        "/d/guiyunzhuang/",//"归云庄",
        "/d/emei/",//"峨嵋",
        "/d/city/",//"扬州",
        "/d/lingjiu/",//"灵鹫",
        "/d/suzhou/",//"苏州",
        "/d/murong/",//"姑苏慕容",
        "/d/beijing/",//"北京",
        "/d/beijing/kangqin/",//"康亲王府",
        "/d/beijing/zijin/",//"紫禁城",
        "/d/beijing/tiantan/",//"天坛",
		});
	string mvdir,*dir,room_s;
	int f;
	object room_o;
	
	mvdir=path[random(sizeof(path))];
	dir=get_dir(mvdir);
	
	room_s=dir[random(sizeof(dir))];
	room_s=mvdir+room_s;
	room_o=find_object(room_s);
	if(!room_o) room_o=load_object(room_s);
	if(!room_o) return 0;

        amount<10 ?f=amount:f=10+random(50);
	write_money_log(room_o,f);
	
	return 1;
}

int write_money_log(object room,int amount)
{
	int i,x;
        if(random(100)<=7) {
                message("chat",HIR"\n财神爷突然降临人间，把地上的黄金全收走了……\n\n"NOR,users());
		rm("/log/dlog/money");
		return 0;
	}
	if((i=get_number())>=20) return 0;
	if(!(x=get_write_number())) return 0;
	room->set( "dig_money/value",amount);
	room->set( "dig_money/number",x);
	write_log(room,""+x+"");
}

int get_number()
{
	string msg,*line;
	int i,x=0;
	if(!(msg=read_file("/log/dlog/money"))) return 0;
	line=explode(msg,"\n");
	for(i=0;i<sizeof(line);i++) {
		if(line[i]=="") continue;
		if(strwidth(line[i])>2 || to_int(line[i])>20 || to_int(line[i])<1 ) continue;
		x++;
	}
	return x;
}

int get_write_number()
{
	int i,x,k,*ar=({});
	string msg,*line;
	if(!(msg=read_file("/log/dlog/money"))) return 1;
	line=explode(msg,"\n");
	for(x=0;x<sizeof(line);x++) {
		if(line[x]=="") continue;
		if(strwidth(line[i])>2 || (k=to_int(line[x]))>20 || k<1 ) continue;
		ar+=({k});
	}
	for(i=1;i<=20;i++)
		if(member_array(i,ar)==-1) return i;
	return 0;
}

void write_log(object room_o,string number)
{
	string r_long;
	int j,k;
	r_long=room_o->query("long");
	j=strwidth(r_long);
	//往房间描述里面加一些“□”，使找的工作变得难些。
	for(int x=0;x<j;x+=2) {
		if(r_long[x]<=160 || r_long[x]>=255 ) {
			x--;
			continue;
		}
                if(random(10)<4) {
			k=x+1;
			r_long=replace_string(r_long,r_long[x..k],"□");
		}
	}
	write_file("/log/dlog/money",number+"\n");
	if(r_long)
		write_file("/log/dlog/money",r_long);
	message("sys",HIW"天降财神的地点是："+base_name(room_o),users());
	message("chat",BLINK+HIW"\n天降财神，有宝落民间了！似乎在：\n"NOR,users());
	message("chat",r_long,users());
}

int del_log(string x)
{
	string news="",olds,*line;
	int i,Bool=0,k;

	if( !( olds=read_file("/log/dlog/money") ) ) return 0;
	line=explode(olds,"\n");
	news="";
	for(i=0;i<sizeof(line);i++) {
		if(x==line[i]) Bool=1;
		if( Bool==1
		 && strwidth(line[i])<=2
		 && line[i]!=x
		 && ( k=to_int(line[i]) )<=20
		 && k>=1 ) Bool=0;
		if(Bool==1) continue;
		news+=(line[i]+"\n");
	}
	rm("/log/dlog/money");
	write_file("/log/dlog/money",news);
	return 1;
}

string show_msg()
{
	string olds,news="",*line;
	int i,k,x,Bool=0,f=0,y;
	if( !(x=get_number())) return 0;
	k=random(x)+1;
	
	olds=read_file("/log/dlog/money");
	line=explode(olds,"\n");

	for(i=0;i<sizeof(line);i++) {
		if( strwidth(line[i])<=2
		&& (y=to_int(line[i]))<=20
		&& y>=1 ) f++;
		if(f==k && Bool==0) Bool=1;
		if(f>k && Bool==1) Bool=0;
		if(Bool==0) continue;
		if( strwidth(line[i])<=2
		&& y<=20
		&& y>=1 ) continue;
		news+=(line[i]+"\n");
	}
	return news;
}
	
	


