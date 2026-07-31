// bo.h
void attempt_apprentice(object ob)
{
        object me;
        me=this_player();
         string *prename =
	 ({ "容","慕" });
        string name, new_name;
//	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say 好吧，既然" + RANK_D->query_respect(ob) + "有我儿的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。");
           name = ob->query("name");
           new_name = prename[random(sizeof(prename))] + name[0..1];
	   ob->set("name", new_name);
           command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
           command("recruit " + ob->query("id"));
           command("chat* 淡淡一笑，谁言 以彼之道 还施彼身 绝迹江湖！");
           command("chat* haha"); 
         }
        else
          command("say 我慕容博岂能随便收徒!");
        return;
           
}