// hslj.c
//by yuer
inherit NPC;

#include <ansi.h>;

void fighting(object ob1, object ob2);
int trace(string str1,string str2);
int do_halt();
int do_fight();
int decide(object ob);
int do_continue();
int do_order(object me);
object board;
void create()
{
 	
        set_name("论剑主持：金大侠", ({ "hslj zhuchi", "zhuchi" }) );
        set("gender", "男性");
        set("age", 60);
        set("long",
               "这就是大家众所周知的金大侠，公正无私。中原以及西域等各\n大门派都推举他为华山论剑主持。\n");
        set("combat_exp",10000000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("apply/attack", 100);
        set("apply/defense", 100);
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("sword",500);
        set_skill("parry",500);
        set_skill("tongtian-xuangong", 80);
	map_skill("force", "tongtian-xuangong");
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}
void init()
{
        add_action("do_halt", "halt");
}


int start(object me)
{
  	if(me->query("hslj"))

	 {
  	command("hslj " +"现在开始第"+CHINESE_D->chinese_number(me->query("num"))+"次华山论剑!!。");
	command("hslj " +"请报名人员在十分钟内到场");
	call_out("do_start",500,me);

	}

	return 1;
}

int do_start(object me)
{

	object ob;
	 string *line,str1,str2,file,temp;
	int i,num,hslj_num;
	
        board = present("board", environment());

	file = "/hslj/order";
	line = explode(read_file(file), "\n");

	i=sizeof(line)-1;
	
	command("hslj " +"现在开始华山论剑!!。");
	if(i==0) 
	{
	sscanf(line[i],"%s",str1);
	if (!(ob = present(str1,environment(me))) )
	{
	command("hslj " + "所有人都没到,华山论剑结束!");
	num = me->query("num")+1;
	hslj_num = me->query("hslj_num");
	temp = hslj_num + "\n" + num +"\n0\n huashanlunjian";

	READWRITE_D->file_write("/hslj/huashanlunjian",temp, 1);
	board->do_record("本次华山论剑没有人参加!");
	board->do_record("下次时间:"+ctime(hslj_num));
	READWRITE_D->file_rm("/data/board/hslj_b.o");
	destruct(me);
	return 1;
	}
	 
	remove_call_out("decide");
	call_out("decide",0,ob);
        }

		
	sscanf(line[i],"%s",str1);
	sscanf(line[i-1],"%s",str2);
	call_out("trace",0,str1,str2);
	
        return 1;
}

int trace(string str1,string str2)
{


  object ob1,ob2,me;
   me = this_object();

  if (!(ob1 = present(str1,environment(me))) )
		{
 			command("hslj " + str1 + "没到,取消参赛资格!");
		 	 if (!(ob2 = present(str2,environment(me))) )
			{
			remove_call_out("decide");
 			call_out("decide",0,me);
			return 1;
			}
	  		 else
			{
			 command("hslj " +ob2->query("name")+"胜!");
			remove_call_out("decide"); 
			call_out("decide",0,ob2);
			 return 1;
			 }
			
		}
 else if (!ob2 = present(str2,environment(me)) )
		{
		
		command("hslj " +str2 + "没到,取消参赛资格!");
		remove_call_out("decide");
		call_out("decide",0,ob1);
		return 1;
		}
	

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
        remove_call_out("check");
        call_out("check",0, ob1, ob2);
       ob1->set("qi",(int)ob1->query("max_qi"));
       ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);
	return 1;
}


void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("hslj " + ob1->query("name")
                + "与" + ob2->query("name") + "，现在开始比武论剑！\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
        object ob;
        if(ob1->is_fighting())
        {
		call_out("observe",1,ob1,ob2);
                return 1;
        }
        this_object()->delete_temp("busy");
        if ( !present(ob1, environment()) )
        {
                command("hslj " + ob1->query("name") + "落荒而逃了！判"+ob2->query("name")+"胜!\n");
		call_out("decide",0,ob2);
                return 1;
        }
        if ( !present(ob2, environment()) )
        {
                command("hslj " + ob2->query("name") + "落荒而逃了！判"+ob1->query("name")+"胜!\n");
		call_out("decide",0,ob1);
                return 1;
        }
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("hslj " + ob1->query("name") +
                       "中途放弃比武！判"+ob2->query("name")+"胜!\n");
		call_out("decide",0,ob2);
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("hslj " + ob2->query("name") +
                       "中途放弃比武！判"+ob1->query("name")+"胜!\n");

		call_out("decide",0,ob1);
                return 1;
         }

	 if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi")) {
                        command("hslj " + ob1->query("name")
                                + "与" + ob2->query("name") + "比武不分胜负！继续再比!\n");
			 remove_call_out("trace");
	 		call_out("trace",0,ob1->query("id"),ob2->query("id"));
                        return 1;
                }
                command("hslj " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                 	call_out("decide",0,ob1);
			return 1;
        }
        else
        {
                command("hslj " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
         		call_out("decide",0,ob2);      
			return 1;
        }



        return 1;
	
}


int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}


int decide(object ob)
{
       
	object ob1,ob2;
	string *line,str,str1,str2,file;
	int i;


	file = "/hslj/order";
	line = explode(read_file(file), "\n");


	
	if(!(str = ob->query("id"))) str = "";
	if( ob->query("id") == "hslj zhuchi" ) str = "";
	
	str2 = "";
	
	for(i=0;i<sizeof(line)-2;i++)
	{
	sscanf(line[i],"%s",str1);

	str2 = str2+str1+"\n";
	}

	if(str != "") str2 = str2 + str +"\n";

	READWRITE_D->file_write(file,str2,1);
	remove_call_out("do_continue");
	call_out("do_continue",2);	         

	return 1;
}

int do_continue()
{

	object me,obj,obj1,obj2;
	string *line,str,str1,str2,file,temp;
	int i,num,hslj_num;
	mapping *notes = ({});

	me = this_object();
	file = "/hslj/order";


	line = explode(read_file(file), "\n");
	if(sizeof(line)<=1) 
	{
	sscanf(line[0],"%s",str);
	command("hslj " +"现在华山论剑结束,!!。");
	command("hslj " + str+"最终胜利!!。");
	num = me->query("num")+1;
	hslj_num = me->query("hslj_num");
	temp = hslj_num + "\n" + num +"\n0\n huashanlunjian";

	READWRITE_D->file_write("/hslj/huashanlunjian",temp, 1);
	board->do_record(str + "为本次华山论剑第一!");
	board->do_record("下次时间:"+ctime(hslj_num));

	obj = load_object("/clone/board/hslj_b");
	obj->set("notes",notes);
	obj->save();
	if( obj1 = find_player(str) )
 	 {
 	  command("hslj " +obj1->query("name")+"不愧为武林第一人，现将赏善罚恶令将其保管！");
 	  obj2 = new("/d/xiakedao/obj/shangshanfae-ling");
 	  obj2->move(obj1);
 	  }
//	READWRITE_D->file_rm("/data/board/hslj_b.o");
	destruct(me);
 	return 1;
	}

	i=sizeof(line)-1;
			
	sscanf(line[i],"%s",str1);
	sscanf(line[i-1],"%s",str2);

	 remove_call_out("trace");
	 call_out("trace",3,str1,str2);
	return 1;

 }

int do_order(object me)
{


	mapping *notes;
	int num,i;
	object *ob = ({});
	object obj,user;
	string str,file;

	i = 0;
	file = "/hslj/order";
	obj = load_object("/clone/board/hslj_b");
	
	notes = obj->query("notes");

  	for(num = 1; num<=sizeof(notes); num++)
	{

	if(!(user = find_player(notes[num-1]["register_id"])))
	  command("hslj "+notes[num-1]["register"]+"没到!取消参赛资格!!");
	else{
	
		ob += ({ user });

	     }	
	
	}

	for(i=0;i<sizeof(ob);i++)
		
//排序
	for(i=0;i<sizeof(ob);i++)
	   for(num=i+1;num<sizeof(ob);num++)
		{
		if( ob[i]->query("combat_exp")< ob[num]->query("combat_exp"))
			{
			  user = ob[i];
			  ob[i]=ob[num];
			  ob[num]= user;
			}
		}
	
	str = "";
	for(i=0;i<sizeof(ob);i++)
	{
	str = str + ob[i]->query("id")+"\n";
		
	}
	if(str == "") str = "no";
	 READWRITE_D->file_write(file,str,1);
	
	
	remove_call_out("start");
	call_out("start",1,me);
		
return 1;
}
