// by fire on Jan 8 1998
// dunjia.c 遁甲天书
#include <ansi.h>
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_STUDYABLE;
int study_book()
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("qmdj",30);
  switch(p_res)
  {
        case TOO_TIRED:
		this_body()->simple_action("$N想研究奇门遁甲，可瞌睡得连眼睛都睁不开。\n");
                return 0;
	case LESS_EXP:
                this_body()->simple_action("$N把书翻了半天，总是领会不了其中的奥妙。\n");
                return 0;
        case TOO_EASY:
                this_body()->simple_action("$N发现这本书太简单了。\n");
                return 0;
        case CAN_LEARN:
                p_st=SG_SKILL_D->query_get("qmdj");
                this_body()->simple_action(p_st);
                return 1;
        default :
                write("不知为什么你学不会，问问巫师吧。\n");
  }
  return 0;
}
void setup() {
    set_adj("破烂不堪的");
    set_unit("本");
    set_id("book", "《遁甲天书》第一卷");
    set_long("一本破烂不堪古书，看上去很有年头了。\n");
    set_getmsg("$N 检起法术书，激动得双手发抖"); 
    set_study_action((: study_book :));
    set_gettable(1);
}
