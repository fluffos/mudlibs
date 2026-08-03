// app3.h
// ss 3 代 master

void attempt_apprentice(object ob)
{
	if (ob->query_skill("hanbing-zhenqi",1) < 100){
		command("say 你的寒冰真气还不够娴熟，再回去练练吧。");
                return;
        }
	if (ob->query_skill("force",1) < 100){
		command("say 你的基本内功还不够娴熟，再回去练练吧。");
                return;
        }
        command("say 好吧，你就暂且在我手下学武艺，记得要勤奋练功，光大我派。");
        command("recruit " + ob->query("id"));
}