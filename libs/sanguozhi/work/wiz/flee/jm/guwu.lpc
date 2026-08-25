// 鼓舞
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob);
int p_id,p_skill;
string p_name;
void main(object ob)
{
	int i;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);
	p_name=this_body()->query_id()[0];
        if(!(CHAR_D->get_char(p_name,"skills")))
        {       write("你不会鼓舞之计。\n");
                return;
	}
	if(!p_skill=CHAR_D->get_char(p_name,"skills")["guwu"])
        {       write("你不会鼓舞之计。\n");
                return;
        }
	if(!p_id){
                write("只有身在军中才能鼓舞士气。\n");
                return;
        };	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.

	ob->simple_action(SG_SKILL_D->query_use("guwu"));
	ob->start_busy(10, "你正忙于鼓舞士气呢。");

	call_out("show_result", 5+random(5), ob);
}
void show_result(object ob)
{	
	int mora;
        int kill;
        int damage;

        kill = p_skill*2/3;
        kill = random(kill);
        ob->stop_busy();
        if( kill>50)
        {
                ob->simple_action(SG_SKILL_D->query_succ("guwu"));
                mora = random (20) +10;
        }
        else
        {     if(kill>15)
                {
                ob->simple_action(SG_SKILL_D->query_succ("guwu"));
                mora = random (10) + 5;
                }
              else
		{
		ob->simple_action(SG_SKILL_D->query_fail("guwu"));
		mora = random (-5) - 1;		
		}
	}
	
	TROOP_D->add_morale(p_id,mora);
	TROOP_D->recover_troop(p_id);
	return;
}
