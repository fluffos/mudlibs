// by fire@sgz on 27 May 1999
// zyuanwai.c  张员外
inherit LIVING;
int learn_wxxy(object who)  //武学修养
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_wuli",30);
  switch(p_res)
  {
	case LESS_EXP:
	this_object()->targetted_action("$N对$T笑到：“你经验不足，学不懂！”\n",who);
		return;
        case TOO_TIRED:
                this_object()->targetted_action
          ("$N对$T笑到：“你太累了，休息会儿再来学吧。”\n",who);
                return 0;
        case TOO_EASY:
                this_object()->targetted_action
          ("$N对$T笑到：“你该找个更高明的老师了。”\n",who);
                return 0;
                case LESS_LITERATE:
                        this_object()->targetted_action("$N对$T道：你的文学太差，听不懂这些。\n",this_body());
                        return 0;
        case CAN_LEARN:
           this_object()->targetted_action("$N向$T传授了一些基本武学技法。\n",who);
           p_st=SG_SKILL_D->query_get("sk_wuli");
           who->simple_action(p_st);
           return 1;
        default :
            write("不知为什么他不教你，问问巫师吧。\n");
  }
  return 0;
}
void setup()
{
    set_name("zhang yuanwai", "张员外");
    set_proper_name("张员外");
    set_in_room_desc("华阴有名大富豪，张员外(zhang yuanwai)");
    set_gender(1);
    add_id("zhang");
    set_age(50);
    add_question("rumors","rumors");
    add_question("wxxy","wxxy");
    set_sg_rongmao(-1);
}
string long() {
    return "张员外，个头不高，但却很有一些威严。\n";
}
void special_answer(object who, string matt)
{
     string p_id;
     object ob;
     string s_tmp;
     switch(matt)
     {
         case "rumors":
             this_object()->targetted_action
              ("$N对$T道：兵荒马乱的，不学两手拳脚防身怎么能行。\n",who);
             break;
         case "wxxy" :
             ob=present("zhan_jishaoxin",who);
             if(!objectp(ob)) {
                 this_object()->targetted_action
                  ("$N对$T道：$S这点功夫，虽然粗浅，但也只传家人。\n",who);
                 break;
             }
             else {
                 this_object()->targetted_action
                  ("$N对$T道：$R在$s家劳累辛苦，这点粗浅功夫，想来$R日后还是用得上。\n",who);
                 if(learn_wxxy(who))
                     destruct(ob);
                 break;
             }
     }
}
