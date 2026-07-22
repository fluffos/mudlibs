// app4.h
// ss 4 代 master

void attempt_apprentice(object ob)
{
	if(ob->query("shen") < 0 && ob->query("combat_exp") < 10000){
		command("say 你这邪魔外道，还敢来我嵩山派？快滚！");
		return;
	}
	command("say 好吧，师傅正要我多培育一些弟子来发扬嵩山派呢。");
	command("recruit " + ob->query("id"));
}
