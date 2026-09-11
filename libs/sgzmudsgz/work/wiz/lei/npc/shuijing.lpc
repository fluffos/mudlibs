umors;news;shouming;money)");
			return;
		case "help" :
			this_object()->simple_action("$N微微一笑。\n");
			this_object()->simple_action("$N说道：“是新玩家吧，问我可问对了。”\n"+
"要想了解三国世界，得先读读新闻(news)。\n");
			return;
		case "news" :
			this_object()->targetted_action("$N对$T笑到："+  
"当今正逢乱世，小兄弟心怀大志，当可成一番霸业。\n",who);
			return;
		case "rumors" :
		    this_object()->targetted_action(
"$N对$T小声说到：听说三国网络游戏创作组正在招收新巫师，有兴趣的话赶快去报名吧。\n",who);
			return;
			
		case "money" :
			p_money=who->query_amt_money("bank");
			p_money=p_money+who->query_all_con_money();
			if (p_money>50000)
			{
				this_object()->targetted_action(
"$N对$t说到：“小兄弟家资颇丰，只怕看不上老朽这点钱吧。”\n",who);
				return;
			}
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				this_object()->targetted_action(
"$N对$t遗憾地说到：“老朽这点家底已全给小兄弟了，唉 . . .”\n",who);
				return;
			}
			name_list+=({ p_id });
			ob=new(M_GOLD);
			ob->set_m_num(3);
			ob->move(who);
			this_object()->targetted_action(
"$N对$t说到：“你能找到这里，也算缘份。这点薄资望能助小兄弟早就霸业。\n",who);
			this_object()->targetted_action("$N给$t一些黄金\n",who);
			return;
		case "shouming" :
			p_money=who->query_shouming();
			s_tmp=chinese_number(p_money);
			this_object()->simple_action("$N掐指算了算。\n");
			this_object()->targetted_action(
"$N对$t小声说到：“小兄弟乃有福之人，当可有寿"+s_tmp+"载。”\n",who);
			return;
			
	}
}
