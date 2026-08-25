//*************************************************************
// hp.c *******************************************************
// by fire on Dec 29 1997
// this is not very good, need changed to like score
#include <ansi.h>
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
private void hp_print(object who)
{
    int p_hp,p_max_hp,p_cur_max_hp;
    int p_tmp;
    string s_tmp;
    int p_food,p_drink;
	int p_maxfood,p_maxdrink;

    p_hp=who->query_cur_hp();
    p_cur_max_hp=who->query_cur_max_hp();
    p_max_hp=who->query_sg_max_hp();
    if (p_max_hp)
    {
    	p_tmp=(p_hp*100)/p_max_hp;
    }
    else
	p_tmp=0;
	s_tmp=get_disp_color(p_tmp);
    printf("%%^ORANGE%%^〓〓〓〓%%^H_CYAN%%^状%%^RESET%%^%%^ORANGE%%^〓〓〓〓%%^H_CYAN%%^态%%^RESET%%^%%^ORANGE%%^〓〓〓〓%%^RESET%%^\n\n"),

    printf("%s%%^H_YELLOW%%^⊙%%^H_RED%%^气血%%^H_YELLOW%%^⊙%%^RESET%%^  %s%4d /%4d (%4d )  %s\n",
	 NOR ,s_tmp, p_hp,p_cur_max_hp,	p_max_hp,NOR);

    p_hp = who->query_cur_mp();
    p_cur_max_hp = who->query_cur_max_mp();
    p_max_hp = who->query_sg_max_mp();
    if( p_max_hp ) p_tmp=(p_hp*100)/p_max_hp;
    else p_tmp=0;
    s_tmp=get_disp_color(p_tmp);

    printf("%s%%^H_YELLOW%%^⊙%%^MAGENTA%%^精神%%^H_YELLOW%%^⊙%%^RESET%%^  %s%4d /%4d (%4d )  %s\n",
         NOR ,s_tmp, p_hp,p_cur_max_hp, p_max_hp,NOR);

	p_food=who->query_sg_food();
	p_drink=who->query_sg_drink();
	p_maxfood=200; p_maxdrink=200;
	s_tmp=get_disp_color(p_food*100/p_maxfood);

    printf("%%^H_YELLOW%%^⊙%%^H_WHITE%%^食物%%^H_YELLOW%%^⊙%%^RESET%%^  %s%4d /%4d  %s\n", s_tmp, p_food,p_maxfood,NOR);
	s_tmp=get_disp_color(p_drink*100/p_maxdrink);
    printf("%%^H_YELLOW%%^⊙%%^H_WHITE%%^饮水%%^H_YELLOW%%^⊙%%^RESET%%^  %s%4d /%4d  %s\n\n", s_tmp, p_drink,p_maxdrink,NOR);
	printf("%%^ORANGE%%^〓〓〓〓〓〓〓〓〓〓%%^B_RED%%^%%^H_YELLOW%%^三国志%%^RESET%%^%%^ORANGE%%^〓%%^RESET%%^\n");

}
void do_hp()
{
	object who;
	who=this_body();
	hp_print(who);
}
void do_hp_str(string str)
{
   object ob;
   if(!(wizardp(this_body()->query_userid())))
   {
      printf("只有巫师才可以透视别人的状况\n");
      return;
   }
   else
   {
       ob = present(str, environment(this_body()));
       if (!ob) ob = find_body(str);
       if (!ob) {
             write("你要察看谁的状况？\n"); 
             return;
       }
       if (!ob->is_living()) {
            write("察看物件的健康？\n"); 
            return;
	   }
        hp_print(ob);
   }
}
mixed * query_verb_info()
{
    return ({ ({ "", "STR", }),({  }) });
}
