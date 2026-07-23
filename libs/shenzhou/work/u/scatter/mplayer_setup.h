void do_mp_setup()
{
	object me;
	string msgout;
	int i, totalexp, expavg, z;


	msgout = "\n***********************\n门派工作系统 之 多人参与工作系统\n被选取玩家名单如下(BETA 巫师测试版):\n***********************\n";
	for(i=0;i<k;i++)
	{
		plist[i]->start_busy(5);
		plist[i]->set_temp("family_job/rplace", base_name(environment(plist[i])));
		plist[i]->move("/family_job/counter_attack/gate");
		plist[i]->delete_temp("family_job/killnpcnum");
		
		msgout = msgout + plist[i]->query("name") + " (" + plist[i]->query("id") + ")\n";
		
		totalexp = totalexp + plist[i]->query("combat_exp");
	}

	expavg = totalexp / k;

	msgout = msgout + "\n玩家选取完毕, 等待玩家中\n";

	CHANNEL_D->do_channel(this_object(), "sys", msgout);

	call_out("do_mp_npc_setup", 3, totalexp, expavg);
}

void do_mp_npc_setup(int totalexp, int expavg)
{
	object me;
	object *ob1, *ob2, *ob3, *ob4, *ob5, *ob6, *ob7, *ob8, *ob9, *ob10, *ob11, *ob12, *ob13, *ob14, *ob15, *ob16, *ob17, *ob18;
	string msgout, fname, pdata;
	int i, j, exp, *lvl1, *lvl2, *lvl3, *lvl4, *lvl5, *lvl6, *lvl7, *lvl8, *lvl9, *lvl10, *lvl11, *lvl12, *lvl13, *lvl14, *lvl15, *lvl16, *lvl17, *lvl18, answer, m, comexp;
	int maxkillnum;

	msgout = "玩家/NPC难易度计算中\n";

	for(i=0;i<k;i++)
	{
		exp = plist[i]->query("combat_exp") / 1000;

		j = i + 1;
		msgout = msgout + "------------------------------------------\n";
		msgout = msgout + "Player " + j + ". " + plist[i]->query("name") + " (" + plist[i]->query("id") + ") 个人资料\n";
		msgout = msgout + "经验直 = " + exp + "K  内力 = " + plist[i]->query("max_neili") + "  精力 = " + plist[i]->query("max_jingli") + "\n";
	}

	exp = totalexp / 1000;
	msgout = msgout + "**************** 计算细节 ****************\n";
	msgout = msgout + "总经验直   : " + exp + "K\n";

	exp = expavg / 1000;
	msgout = msgout + "平均经验直 : " + exp + "K\n";
	msgout = msgout + "******************************************\n";

	//Pre-Sets
	ob1 = allocate(sizeof(plist));
	ob2 = allocate(sizeof(plist));
	ob3 = allocate(sizeof(plist));
	ob4 = allocate(sizeof(plist));
	ob5 = allocate(sizeof(plist));
	ob6 = allocate(sizeof(plist));
	ob7 = allocate(sizeof(plist));
	ob8 = allocate(sizeof(plist));
	ob9 = allocate(sizeof(plist));
	ob10 = allocate(sizeof(plist));
	ob11 = allocate(sizeof(plist));
	ob12 = allocate(sizeof(plist));
	ob13 = allocate(sizeof(plist));
	ob14 = allocate(sizeof(plist));
	ob15 = allocate(sizeof(plist));
	ob16 = allocate(sizeof(plist));
	ob17 = allocate(sizeof(plist));
	ob18 = allocate(sizeof(plist));

	lvl1 = allocate(sizeof(plist));
	lvl2 = allocate(sizeof(plist));
	lvl3 = allocate(sizeof(plist));
	lvl4 = allocate(sizeof(plist));
	lvl5 = allocate(sizeof(plist));
	lvl6 = allocate(sizeof(plist));
	lvl7 = allocate(sizeof(plist));
	lvl8 = allocate(sizeof(plist));
	lvl9 = allocate(sizeof(plist));
	lvl10 = allocate(sizeof(plist));
	lvl11 = allocate(sizeof(plist));
	lvl12 = allocate(sizeof(plist));
	lvl13 = allocate(sizeof(plist));
	lvl14 = allocate(sizeof(plist));
	lvl15 = allocate(sizeof(plist));
	lvl16 = allocate(sizeof(plist));
	lvl17 = allocate(sizeof(plist));
	lvl18 = allocate(sizeof(plist));
	
	//Calculation Segment

	for(i=0;i<k;i++)
	{
		lvl1[i] = plist[i]->query("combat_exp")* 90 / 100;
		lvl2[i] = plist[i]->query("combat_exp");
		lvl3[i] = plist[i]->query("combat_exp")* 110 / 100;
		lvl4[i] = plist[i]->query("combat_exp")* 120 / 100;
		lvl5[i] = plist[i]->query("combat_exp")* 130 / 100;
		lvl6[i] = plist[i]->query("combat_exp")* 140 / 100;
		lvl7[i] = plist[i]->query("combat_exp")* 150 / 100;
		lvl8[i] = plist[i]->query("combat_exp")* 160 / 100;
		lvl9[i] = plist[i]->query("combat_exp")* 170 / 100;
		lvl10[i] = plist[i]->query("combat_exp")* 180 / 100;
		lvl11[i] = plist[i]->query("combat_exp")* 190 / 100;
		lvl12[i] = plist[i]->query("combat_exp")* 200 / 100;
		lvl13[i] = plist[i]->query("combat_exp")* 200 / 100;
		lvl14[i] = plist[i]->query("combat_exp")* 210 / 100;
		lvl15[i] = plist[i]->query("combat_exp")* 220 / 100;
		lvl16[i] = plist[i]->query("combat_exp")* 280 / 100;
		lvl17[i] = plist[i]->query("combat_exp")* 290 / 100;
		lvl18[i] = plist[i]->query("combat_exp")* 300 / 100;
	}

	for(i=0;i<k;i++)
	{
		msgout = msgout + "************* NPC 设定细节 ***************\n";
		msgout = msgout + "Player " + i + ") " + lvl1[i] + "(L1) " + lvl2[i] + "(L2) " + lvl3[i] + "(L3) " + lvl4[i] + "(L4) " + lvl5[i] + "(L5) " + lvl6[i] + "(L6) " + lvl7[i] + "(L7) " + lvl8[i] + "(L8) " + lvl9[i] + "(L9) " + lvl10[i] + "(L10) " + lvl11[i] + "(L11) " + lvl12[i] + "(L12) " + lvl13[i] + "(L13) " + lvl14[i] + "(L14) " + lvl15[i] + "(L15) " + lvl16[i] + "(L16) " + lvl17[i] + "(L17) " + lvl18[i] + "(L18)\n";
	}
	
	msgout = msgout + "******************************************\n";
	msgout = msgout + "资料处理中...";
	
	CHANNEL_D->do_channel(this_object(), "sys", msgout);


	for(i=0;i<k;i++)
	{
		ob1[i] = new("/family_job/skeleton");
		ob2[i] = new("/family_job/skeleton");
		ob3[i] = new("/family_job/skeleton");
		ob4[i] = new("/family_job/skeleton");
		ob5[i] = new("/family_job/skeleton");
		ob6[i] = new("/family_job/skeleton");
		ob7[i] = new("/family_job/skeleton");
		ob8[i] = new("/family_job/skeleton");
		ob9[i] = new("/family_job/skeleton");
		ob10[i] = new("/family_job/skeleton");
		ob11[i] = new("/family_job/skeleton");
		ob12[i] = new("/family_job/skeleton");
		ob13[i] = new("/family_job/skeleton");
		ob14[i] = new("/family_job/skeleton");
		ob15[i] = new("/family_job/skeleton");
		ob16[i] = new("/family_job/skeleton");
		ob17[i] = new("/family_job/skeleton");
		ob18[i] = new("/family_job/skeleton");
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl1[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		
		ob1[i]->set("combat_exp", lvl1[i]);
		ob1[i]->set_skill("cuff", answer);
		ob1[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob1[i]->set("nickname", plist[i]->query("name"));
		ob1[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl2[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;

		ob2[i]->set("combat_exp", lvl2[i]);
		ob2[i]->set_skill("cuff", answer);
		ob2[i]->set_skill("dodge", answer);
		ob2[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob2[i]->set("nickname", plist[i]->query("name"));
		ob2[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl3[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;

		ob3[i]->set("combat_exp", lvl3[i]);
		ob3[i]->set_skill("cuff", answer);
		ob3[i]->set_skill("dodge", answer);
		ob3[i]->set_skill("force", answer);
		ob3[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob3[i]->set("nickname", plist[i]->query("name"));
		ob3[i]->set("max_qi", plist[i]->query("max_qi"));
	}



	for(i=0;i<k;i++)
	{
		comexp = lvl4[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;

		ob4[i]->set("combat_exp", lvl4[i]);
		ob4[i]->set_skill("cuff", answer);
		ob4[i]->set_skill("dodge", answer);
		ob4[i]->set_skill("force", answer);
		ob4[i]->set_skill("strike", answer);
		ob4[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob4[i]->set("nickname", plist[i]->query("name"));
		ob4[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl5[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;

		ob5[i]->set("combat_exp", lvl5[i]);
		ob5[i]->set_skill("cuff", answer);
		ob5[i]->set_skill("dodge", answer);
		ob5[i]->set_skill("force", answer);
		ob5[i]->set_skill("strike", answer);
		ob5[i]->set_skill("parry", answer);
		ob5[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob5[i]->set("nickname", plist[i]->query("name"));
		ob5[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl6[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;

		ob6[i]->set("combat_exp", lvl6[i]);
		ob6[i]->set_skill("cuff", answer);
		ob6[i]->set_skill("dodge", answer);
		ob6[i]->set_skill("force", answer);
		ob6[i]->set_skill("strike", answer);
		ob6[i]->set_skill("parry", answer);
		ob6[i]->set_skill("finger", answer);
		ob6[i]->set_temp("fjob/target", plist[i]->query("id"));
		ob6[i]->set("nickname", plist[i]->query("name"));
		ob6[i]->set("max_qi", plist[i]->query("max_qi"));
	}
	
	for(i=0;i<k;i++)
	{
		comexp = lvl7[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob7[i]->set("combat_exp", lvl7[i]);
		ob7[i]->set_skill("cuff", answer);
		ob7[i]->set_skill("dodge", answer);
		ob7[i]->set_skill("force", answer);
		ob7[i]->set_skill("strike", answer);
		ob7[i]->set_skill("parry", answer);
		ob7[i]->set_skill("finger", answer);
		ob7[i]->set_skill("taiji-shengong", answer);
		ob7[i]->set_skill("taiji-quan", answer);
		ob7[i]->set_skill("mian-zhang", answer);
		ob7[i]->set_skill("tiyunzong", answer);
		ob7[i]->set_temp("fjob/target", plist[i]->query("id"));
		
		ob7[i]->map_skill("force", "taiji-shengong");
		ob7[i]->map_skill("cuff", "taiji-quan");
		ob7[i]->map_skill("strike", "mian-zhang");
		ob7[i]->map_skill("dodge", "tiyunzong");
		ob7[i]->prepare_skill("strike", "mian-zhang");
		ob7[i]->prepare_skill("cuff", "taiji-quan");
		ob7[i]->set("nickname", plist[i]->query("name"));
		ob7[i]->set("max_qi", plist[i]->query("max_qi"));
	}



	for(i=0;i<k;i++)
	{
		comexp = lvl8[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob8[i]->set("combat_exp", lvl8[i]);
		ob8[i]->set_skill("cuff", answer);
		ob8[i]->set_skill("dodge", answer);
		ob8[i]->set_skill("force", answer);
		ob8[i]->set_skill("strike", answer);
		ob8[i]->set_skill("parry", answer);
		ob8[i]->set_skill("finger", answer);
		ob8[i]->set_skill("huagong-dafa", answer);
		ob8[i]->set_skill("sanyin-zhua", answer);
		ob8[i]->set_skill("chousui-zhang", answer);
		ob8[i]->set_skill("zhaixinggong", answer);
		ob8[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob8[i]->map_skill("force", "huagong-dafa");
		ob8[i]->map_skill("claw", "sanyin-zhua");
		ob8[i]->map_skill("strike", "chousui-zhang");
		ob8[i]->map_skill("dodge", "zhaixinggong");
		ob8[i]->prepare_skill("claw", "sanyin-zhua");
		ob8[i]->prepare_skill("strike", "chousui-zhang");
		ob8[i]->set("nickname", plist[i]->query("name"));
		ob8[i]->set("max_qi", plist[i]->query("max_qi"));
	}



	for(i=0;i<k;i++)
	{
		comexp = lvl9[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob9[i]->set("combat_exp", lvl9[i]);
		ob9[i]->set_skill("cuff", answer);
		ob9[i]->set_skill("dodge", answer);
		ob9[i]->set_skill("force", answer);
		ob9[i]->set_skill("strike", answer);
		ob9[i]->set_skill("parry", answer);
		ob9[i]->set_skill("finger", answer);
		ob9[i]->set_skill("huagong-dafa", answer);
		ob9[i]->set_skill("sanyin-zhua", answer);
		ob9[i]->set_skill("chousui-zhang", answer);
		ob9[i]->set_skill("zhaixinggong", answer);
		ob9[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob9[i]->map_skill("force", "huagong-dafa");
		ob9[i]->map_skill("claw", "sanyin-zhua");
		ob9[i]->map_skill("strike", "chousui-zhang");
		ob9[i]->map_skill("dodge", "zhaixinggong");
		ob9[i]->prepare_skill("claw", "sanyin-zhua");
		ob9[i]->prepare_skill("strike", "chousui-zhang");
		ob9[i]->set("nickname", plist[i]->query("name"));
		ob9[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl10[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob10[i]->set("combat_exp", lvl10[i]);
		ob10[i]->set_skill("cuff", answer);
		ob10[i]->set_skill("dodge", answer);
		ob10[i]->set_skill("force", answer);
		ob10[i]->set_skill("strike", answer);
		ob10[i]->set_skill("parry", answer);
		ob10[i]->set_skill("finger", answer);
		ob10[i]->set_skill("huagong-dafa", answer);
		ob10[i]->set_skill("sanyin-zhua", answer);
		ob10[i]->set_skill("chousui-zhang", answer);
		ob10[i]->set_skill("zhaixinggong", answer);
		ob10[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob10[i]->map_skill("force", "huagong-dafa");
		ob10[i]->map_skill("claw", "sanyin-zhua");
		ob10[i]->map_skill("strike", "chousui-zhang");
		ob10[i]->map_skill("dodge", "zhaixinggong");
		ob10[i]->prepare_skill("claw", "sanyin-zhua");
		ob10[i]->prepare_skill("strike", "chousui-zhang");
		ob10[i]->set("nickname", plist[i]->query("name"));
		ob10[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl11[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob11[i]->set("combat_exp", lvl11[i]);
		ob11[i]->set_skill("cuff", answer);
		ob11[i]->set_skill("dodge", answer);
		ob11[i]->set_skill("force", answer);
		ob11[i]->set_skill("strike", answer);
		ob11[i]->set_skill("parry", answer);
		ob11[i]->set_skill("finger", answer);
		ob11[i]->set_skill("huagong-dafa", answer);
		ob11[i]->set_skill("sanyin-zhua", answer);
		ob11[i]->set_skill("chousui-zhang", answer);
		ob11[i]->set_skill("zhaixinggong", answer);
		ob11[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob11[i]->map_skill("force", "huagong-dafa");
		ob11[i]->map_skill("claw", "sanyin-zhua");
		ob11[i]->map_skill("strike", "chousui-zhang");
		ob11[i]->map_skill("dodge", "zhaixinggong");
		ob11[i]->prepare_skill("claw", "sanyin-zhua");
		ob11[i]->prepare_skill("strike", "chousui-zhang");
		ob11[i]->set("nickname", plist[i]->query("name"));
		ob11[i]->set("max_qi", plist[i]->query("max_qi"));
	}

	for(i=0;i<k;i++)
	{
		comexp = lvl12[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob12[i]->set("combat_exp", lvl12[i]);
		ob12[i]->set_skill("cuff", answer);
		ob12[i]->set_skill("dodge", answer);
		ob12[i]->set_skill("force", answer);
		ob12[i]->set_skill("strike", answer);
		ob12[i]->set_skill("parry", answer);
		ob12[i]->set_skill("finger", answer);
		ob12[i]->set_skill("huagong-dafa", answer);
		ob12[i]->set_skill("sanyin-zhua", answer);
		ob12[i]->set_skill("chousui-zhang", answer);
		ob12[i]->set_skill("zhaixinggong", answer);
		ob12[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob12[i]->map_skill("force", "huagong-dafa");
		ob12[i]->map_skill("claw", "sanyin-zhua");
		ob12[i]->map_skill("strike", "chousui-zhang");
		ob12[i]->map_skill("dodge", "zhaixinggong");
		ob12[i]->prepare_skill("claw", "sanyin-zhua");
		ob12[i]->prepare_skill("strike", "chousui-zhang");
		ob12[i]->set("nickname", plist[i]->query("name"));
		ob12[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl13[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob13[i]->set("combat_exp", lvl13[i]);
		ob13[i]->set_skill("cuff", answer);
		ob13[i]->set_skill("dodge", answer);
		ob13[i]->set_skill("force", answer);
		ob13[i]->set_skill("strike", answer);
		ob13[i]->set_skill("parry", answer);
		ob13[i]->set_skill("finger", answer);
		ob13[i]->set_skill("huagong-dafa", answer);
		ob13[i]->set_skill("sanyin-zhua", answer);
		ob13[i]->set_skill("chousui-zhang", answer);
		ob13[i]->set_skill("zhaixinggong", answer);
		ob13[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob13[i]->map_skill("force", "huagong-dafa");
		ob13[i]->map_skill("claw", "sanyin-zhua");
		ob13[i]->map_skill("strike", "chousui-zhang");
		ob13[i]->map_skill("dodge", "zhaixinggong");
		ob13[i]->prepare_skill("claw", "sanyin-zhua");
		ob13[i]->prepare_skill("strike", "chousui-zhang");
		ob13[i]->set("nickname", plist[i]->query("name"));
		ob13[i]->set("max_qi", plist[i]->query("max_qi"));
	}



	for(i=0;i<k;i++)
	{
		comexp = lvl14[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob14[i]->set("combat_exp", lvl14[i]);
		ob14[i]->set_skill("cuff", answer);
		ob14[i]->set_skill("dodge", answer);
		ob14[i]->set_skill("force", answer);
		ob14[i]->set_skill("strike", answer);
		ob14[i]->set_skill("parry", answer);
		ob14[i]->set_skill("finger", answer);
		ob14[i]->set_skill("huagong-dafa", answer);
		ob14[i]->set_skill("sanyin-zhua", answer);
		ob14[i]->set_skill("chousui-zhang", answer);
		ob14[i]->set_skill("zhaixinggong", answer);
		ob14[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob14[i]->map_skill("force", "huagong-dafa");
		ob14[i]->map_skill("claw", "sanyin-zhua");
		ob14[i]->map_skill("strike", "chousui-zhang");
		ob14[i]->map_skill("dodge", "zhaixinggong");
		ob14[i]->prepare_skill("claw", "sanyin-zhua");
		ob14[i]->prepare_skill("strike", "chousui-zhang");
		ob14[i]->set("nickname", plist[i]->query("name"));
		ob14[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl15[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob15[i]->set("combat_exp", lvl15[i]);
		ob15[i]->set_skill("cuff", answer);
		ob15[i]->set_skill("dodge", answer);
		ob15[i]->set_skill("force", answer);
		ob15[i]->set_skill("strike", answer);
		ob15[i]->set_skill("parry", answer);
		ob15[i]->set_skill("finger", answer);
		ob15[i]->set_skill("huagong-dafa", answer);
		ob15[i]->set_skill("sanyin-zhua", answer);
		ob15[i]->set_skill("chousui-zhang", answer);
		ob15[i]->set_skill("zhaixinggong", answer);
		ob15[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob15[i]->map_skill("force", "huagong-dafa");
		ob15[i]->map_skill("claw", "sanyin-zhua");
		ob15[i]->map_skill("strike", "chousui-zhang");
		ob15[i]->map_skill("dodge", "zhaixinggong");
		ob15[i]->prepare_skill("claw", "sanyin-zhua");
		ob15[i]->prepare_skill("strike", "chousui-zhang");
		ob15[i]->set("nickname", plist[i]->query("name"));
		ob15[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl16[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob16[i]->set("combat_exp", lvl16[i]);
		ob16[i]->set_skill("cuff", answer);
		ob16[i]->set_skill("dodge", answer);
		ob16[i]->set_skill("force", answer);
		ob16[i]->set_skill("strike", answer);
		ob16[i]->set_skill("parry", answer);
		ob16[i]->set_skill("finger", answer);
		ob16[i]->set_skill("huagong-dafa", answer);
		ob16[i]->set_skill("sanyin-zhua", answer);
		ob16[i]->set_skill("chousui-zhang", answer);
		ob16[i]->set_skill("zhaixinggong", answer);
		ob16[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob16[i]->map_skill("force", "huagong-dafa");
		ob16[i]->map_skill("claw", "sanyin-zhua");
		ob16[i]->map_skill("strike", "chousui-zhang");
		ob16[i]->map_skill("dodge", "zhaixinggong");
		ob16[i]->prepare_skill("claw", "sanyin-zhua");
		ob16[i]->prepare_skill("strike", "chousui-zhang");
		ob16[i]->set("nickname", plist[i]->query("name"));
		ob16[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	for(i=0;i<k;i++)
	{
		comexp = lvl17[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob17[i]->set("combat_exp", lvl17[i]);
		ob17[i]->set_skill("cuff", answer);
		ob17[i]->set_skill("dodge", answer);
		ob17[i]->set_skill("force", answer);
		ob17[i]->set_skill("strike", answer);
		ob17[i]->set_skill("parry", answer);
		ob17[i]->set_skill("finger", answer);
		ob17[i]->set_skill("huagong-dafa", answer);
		ob17[i]->set_skill("sanyin-zhua", answer);
		ob17[i]->set_skill("chousui-zhang", answer);
		ob17[i]->set_skill("zhaixinggong", answer);
		ob17[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob17[i]->map_skill("force", "huagong-dafa");
		ob17[i]->map_skill("claw", "sanyin-zhua");
		ob17[i]->map_skill("strike", "chousui-zhang");
		ob17[i]->map_skill("dodge", "zhaixinggong");
		ob17[i]->prepare_skill("claw", "sanyin-zhua");
		ob17[i]->prepare_skill("strike", "chousui-zhang");
		ob17[i]->set("nickname", plist[i]->query("name"));
		ob17[i]->set("max_qi", plist[i]->query("max_qi"));
	}

	for(i=0;i<k;i++)
	{
		comexp = lvl18[i];
		comexp = comexp * 10;
		for(m=0;comexp>m*m*m;m++)
			answer = m + 1;
		ob18[i]->set("combat_exp", lvl18[i]);
		ob18[i]->set_skill("cuff", answer);
		ob18[i]->set_skill("dodge", answer);
		ob18[i]->set_skill("force", answer);
		ob18[i]->set_skill("strike", answer);
		ob18[i]->set_skill("parry", answer);
		ob18[i]->set_skill("finger", answer);
		ob18[i]->set_skill("huagong-dafa", answer);
		ob18[i]->set_skill("sanyin-zhua", answer);
		ob18[i]->set_skill("chousui-zhang", answer);
		ob18[i]->set_skill("zhaixinggong", answer);
		ob18[i]->set_temp("fjob/target", plist[i]->query("id"));

		ob18[i]->map_skill("force", "huagong-dafa");
		ob18[i]->map_skill("claw", "sanyin-zhua");
		ob18[i]->map_skill("strike", "chousui-zhang");
		ob18[i]->map_skill("dodge", "zhaixinggong");
		ob18[i]->prepare_skill("claw", "sanyin-zhua");
		ob18[i]->prepare_skill("strike", "chousui-zhang");
		ob18[i]->set("nickname", plist[i]->query("name"));
		ob18[i]->set("max_qi", plist[i]->query("max_qi"));
	}


	//*********************************
	//*       NPC SETUP COMPLETE      *
	//*********************************

	//*********************************
	//* START TO MOVE NPC TO POSITION *
	//*********************************

	for(i=0;i<k;i++)
	{
		ob1[i]->move("/family_job/counter_attack/hill1");
		ob2[i]->move("/family_job/counter_attack/hill2");
		ob3[i]->move("/family_job/counter_attack/hill3");
		ob4[i]->move("/family_job/counter_attack/hill4");
		ob5[i]->move("/family_job/counter_attack/hill5");
		ob6[i]->move("/family_job/counter_attack/hill6");
		ob7[i]->move("/family_job/counter_attack/hill7");
		ob8[i]->move("/family_job/counter_attack/hill8");
		ob9[i]->move("/family_job/counter_attack/hill9");
		ob10[i]->move("/family_job/counter_attack/hill10");
		ob11[i]->move("/family_job/counter_attack/hill11");
		ob12[i]->move("/family_job/counter_attack/hill12");
		ob13[i]->move("/family_job/counter_attack/hill13");
		ob14[i]->move("/family_job/counter_attack/hill14");
		ob15[i]->move("/family_job/counter_attack/hill15");
		ob16[i]->move("/family_job/counter_attack/hill16");
		ob17[i]->move("/family_job/counter_attack/hill17");
		ob18[i]->move("/family_job/counter_attack/hill18");
		maxkillnum = maxkillnum + 18;
	}

	fname = "fjob/mp/killnum";
	pdata = "0";
	SAVE_NPC->do_save(fname, pdata);

	fname = "fjob/mp/maxkillnum";
	pdata = "" + maxkillnum;
	SAVE_NPC->do_save(fname, pdata);
}