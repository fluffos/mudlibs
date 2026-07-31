int accept_object(object me, object obj)
{
      object ob;
      me=this_object();
      ob=this_player();
        if ( obj->query("id") != "secret letter" )
            {  command("say 你这么大老远跑来就为了送这个？这东西我要来没用。");
		 return 0;
	      } 
       if (ob->query("title") != "大理国镇南王府随从")
         {
           command("say 你不是大理国的随从，怎么会送镇南王手谕的信给我？");
           return 0;
         }
       if (!ob->query_temp("dali_songxin"))
            {  command("?");
	        command("say 这是大理国镇南王府亲自交给你,要你送的？你是不是从别人那里抢来的？");
               return 0;
	      }
       if ( ob->query_temp("songxin_target_name") != me->query("name"))
            {  command("shake");
               command("say 这封信不是给我的，你是不是送错了？");
                           return 0;
                     }
       else {
               command("nod");
               command("say 辛苦你了，你可以回去覆命了!");
               ob->delete_temp("songxin_target_name");
               ob->set_temp("dali_songxin_ok",1);
        	return 1;
              }
}
