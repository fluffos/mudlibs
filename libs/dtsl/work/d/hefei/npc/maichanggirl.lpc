
inherit NPC;

int do_show();

void create()
{
   set_name("卖唱姑娘",({ "gu niang","niang","girl" }) );
   set("gender", "女性" );
   set("age", 18);
   set("long", "她是一名卖唱的姑娘。\n");
       
   set("combat_exp", 10000);
   set("per", 25);
   
   set("inquiry",([
   	"嫁人":"小女子不知何时才能找到一个如意郎君啊！",
   	"卖唱":(:do_show:),
   	]));
   
   setup();
   add_money("coin", 50);
}

void init()
{

	::init();
	if(!living(this_object()))
		return;
	
	call_out("welcome",1);
	
}

void welcome()
{
 
switch(random(2)){
		case 0: 
			command("say 各位客官请听小女子给各位唱个小曲。");
			break;
		case 1: 
			command("say 何时天下能够太平，也让小女子嫁得一如意郎君？");
		
}
remove_call_out("welcome");
return;
}

int do_show()
{
if(query("showing")){
	command("say 客官请等等，奴家正准备唱呢。");
	return 1;
}
set("showing",1);
command("say 既然客官要听，我就唱一曲给客官听听吧！");

call_out("do_show2",2,0);	

return 1;
	
}

string *poem=({
	"长相思、长相忆",
	"珠泪纷纷湿绮罗，少年公子负恩多"
	});

void do_show2(int i)
{
command("say "+poem[i]);
if(i>=1){
	command("say 小女子只记得这么多，献丑了！");
	delete("showing");
	return;
}
call_out("do_show2",2,i+1); 	
	
}
