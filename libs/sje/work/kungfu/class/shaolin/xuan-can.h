#include <ansi.h>

void preparing(object, object);

string ask_me()
{
        mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();
        my_fam  = me->query("family");

        skl = fighter->query_skills();
        sname = keys(skl);
        if( !fighter->query("luohan_winner") )
                return RANK_D->query_respect(fighter)+"连罗汉大阵都没过，也想进堂值勤？";
        if(sizeof(skl)<15)
                return RANK_D->query_respect(fighter)+"少林功夫没学几样，也想来值勤?";      
        if ( mapp(fam = fighter->query("family"))
          && fam["family_name"] != "少林派")
                return RANK_D->query_respect(fighter)+"开玩笑吧？少林岂容的下外派高手？";
        if ( (int)fighter->query("guilty") > 0 )
                return RANK_D->query_respect(fighter)+"你累犯数戒，身带重罪，我如何能准许你在罗汉堂效力?！";
        if( fighter->query_condition("gb_mission")
         || fighter->query_condition("xx_task")
         || fighter->query_condition("dali_songxin"))
                return "你现在正忙着做其他任务呢！";

        say("\n玄惭说道：好吧，你就在罗汉堂里训练武僧吧，若有外敌入侵，你们负担着护寺重任。\n");

//      fighter->set("short","罗汉堂值勤教习");
        fighter->set_temp("lh_teacher",1);
        fighter->apply_condition("lh_job", 10);
                return "到了武僧堂，ask monk about 武技。\n";
}

