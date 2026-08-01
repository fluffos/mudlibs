#include <ansi.h>

void preparing(object, object);

string ask_me() {
  mapping fam, my_fam, skl;
  object fighter, me;
  string *sname;

  fighter = this_player();
  me = this_object();
  my_fam = me->query("family");

  skl = fighter->query_skills();
  sname = keys(skl);
  if (fighter->query("combat_exp") > 2000000)
    return RANK_D->query_respect(fighter) + "的经验已经不浅，还是做点其它更有挑战性的工作吧。\n";

  if (fighter->query_condition("lh_job"))
    return "你刚才不是已经问过了吗？";

  if (fighter->query_condition("job_busy"))
    return "你正在忙着做其它任务呢。";

  if (fighter->query("job_name") == "训练武僧")
    return "你刚训练武僧结束，还是先休息一会吧。";

  if (!fighter->query("luohan_winner"))
    return RANK_D->query_respect(fighter) + "连罗汉大阵都没过，也想进堂值勤？";

  if (sizeof(skl) < 15)
    return RANK_D->query_respect(fighter) + "少林功夫没学几样，也想来值勤?";

  if (fighter->query("family/generation") > 36)
    return RANK_D->query_respect(fighter) + "辈分太低，只怕罗汉堂弟子不听你的管教。\n";

  if (mapp(fam = fighter->query("family")) && fam["family_name"] != "少林派")
    return RANK_D->query_respect(fighter) + "开玩笑吧？少林岂容的下外派高手？";

  if ((int)fighter->query("guilty") > 0)
    return RANK_D->query_respect(fighter) + "你累犯数戒，身带重罪，我如何能准许你在罗汉堂效力?！";

  if (fighter->query_condition("job_busy"))
    return "你现在正忙着做其他任务呢！";

  say("\n玄惭说道：好吧，你就在罗汉堂里训练武僧吧，若有外敌入侵，你们负担着护寺重任。\n");

  //      fighter->set("short","罗汉堂值勤教习");
  fighter->set_temp("lh_teacher", 1);
  fighter->add("job_time/少林", 1);
  fighter->add("job_time/罗汉堂", 1);
  fighter->delete_temp("meetmotou");
  fighter->set("job_name", "训练武僧");
  fighter->apply_condition("lh_job", 15);
  fighter->apply_condition("job_busy", 9);
  return "到了武僧堂，ask monk about 武技。";
}
