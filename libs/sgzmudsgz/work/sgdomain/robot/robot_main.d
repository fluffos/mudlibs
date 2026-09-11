// robot_test
// robot.c
#define MAX_TIME 180
inherit M_ACCESS;
string answer="";
void no_answer(object usr,function f,mixed p)
{
   object o;
    string p_id;
 if(!objectp(usr)) return;
    o=usr->query_body();
    if(!objectp(o)) return;
     p_id=o->query_id()[0];
    tell_user(p_id,"超时算错\n");
   o->set_robot(1);
   find_user(p_id)->modal_pop();
   evaluate(f,usr,p);
   destruct(this_object());
}
void input_answer(object usr,function f,mixed p,string right_answer,string str)
{
    if(!objectp(usr->query_body())) {remove_call_out("no_answer") ;return;}
    if(str==right_answer)
    {
        usr->query_body()->set_robot(0);
        find_user(usr->query_body()->query_id()[0])->modal_pop();
        remove_call_out("no_answer");
        evaluate(f,usr,p);
	destruct(this_object());
        return;
    }
    if((str=="1")||(str=="2")||(str=="3")||(str=="4"))
    {
        usr->query_body()->set_robot(1);
        find_user(usr->query_body()->query_id()[0])->modal_pop();
        remove_call_out("no_answer");
        evaluate(f,usr,p);
   	destruct(this_object());

        return;
    }
    write("请回答1,2,3或4\n");
}
void robot_test(object usr,function f,mixed p)
{
   string right_answer;
   object o_id;
   int is_robot,robot_test,robot_times;
   if(!objectp(usr->query_body())) return;
   o_id=usr->query_body();
   is_robot=o_id->query_robot();
   robot_test=o_id->query_robot_test(); // how many times tested
   robot_times=o_id->query_robot_times(); // how many times as robot 

   if((!is_robot)&&(robot_test>4)&&((robot_times*5)<robot_test)&&random(2))
   {
	   string p_id=o_id->query_id()[0];
	   tell_user(p_id,"由于你纪录良好，免除智能测试。\n");
       evaluate(f,usr,p);
	   destruct(this_object());
	   return;
   }
   call_out("no_answer",MAX_TIME,usr,f,p);

   if(usr->query_body()->query_literate()>=30) {
	switch(random(6)) {
		/*case 0 :
	          right_answer=(__DIR__+"zi")->test(usr->query_body()->query_id()[0]);
		  break;
		case 1 :
	          right_answer=(__DIR__+"area")->test(usr->query_body()->query_id()[0]);
		  break;
		case 2:
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;*/
		default:
	          right_answer=(__DIR__+"sen")->test(usr->query_body()->query_id()[0]);
		  break;

	}
   }

   else if(usr->query_body()->query_literate()>20) {
	switch(random(4)) {
		case 0 :
	          right_answer=(__DIR__+"zi")->test(usr->query_body()->query_id()[0]);
		  break;
		case 1:
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;
		default:
	          right_answer=(__DIR__+"sen")->test(usr->query_body()->query_id()[0]);
		  break;

	}
   }
   else {
	switch(random(2)) {
		case 0:
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;
		default:
	          right_answer=(__DIR__+"sen")->test(usr->query_body()->query_id()[0]);
		  break;
	}
   }

   set_this_player(find_user(usr->query_body()->query_id()[0]));

   find_user(usr->query_body()->query_id()[0])->
     modal_push((: input_answer,usr,f,p,right_answer :),
        "请输入正确答案(1,2,3 or 4)：");
   return;
}
void create() {
    set_privilege(1);
}
