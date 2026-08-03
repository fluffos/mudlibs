string long()
{
	string fam,str;
	if( this_object()->query("name")=="魔物" )
	{
		str = @LONG
一个头四臂巨大魔物。四只黑紫色妖目，毫无感情的盯着你。

LONG;
		str+= "他的境界与你相比，似乎"MAG"旗鼓相当"NOR"。\n";
		str+= "他"HIR"面目狰狞，不似人类。\n"NOR;
		str+= "他"HIB"整个笼罩浓浓的魔气之中"NOR"。\n\n";
		str+= "他身上带着：\n";
		str+= HIC"  □"HIR"天魔甲"NOR"(Tianmo jia)\n";
	}	
	else if( !stringp(fam=this_object()->query("family/family_name")) )
		return "\n";
	switch(fam)	
	{
		case "百花谷" :
			str = @LONG
    百花谷主一直是个迷一样的人物，甚至仍然有人说她是仙子。大
约五十年前，一个采药的小童在林间迷路，在饥渴绝望的时刻，花丛
中翩翩飘下一美丽女子，为他指明了出去的道路。时间飞逝，当年的
小童也变成了白发老翁，但在他心中一直把当年救她的女子当成上天
派下来拯救他的仙子，因为她在花间飞舞那轻盈的身姿，根本就不象
凡人......。
她看起来约三十多岁。
LONG;
			str+= "她的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "她"HIM"灿若明霞，宝润如玉，恍如神妃仙子。 \n"NOR;
			str+= "她"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "她身上带着：\n";
			str+= HIC"  □"HIB"兰叶"NOR"(Lan ye)\n";
			str+= HIC"  □"HIB"卧龙"NOR"(Wo long)\n";
			str+= HIC"  □"HIB"晓月当帘"NOR"(Xiaoyue danglian)\n";
			break;
		case "阎罗地府" :
			str = @LONG
面如朱玉，大耳垂肩，一脸肃静。他便是主管阴曹地府，天下鬼魂的地藏王菩萨。
他看起来约一千八百多岁。
LONG;			
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"HIC"鹤发童颜，仙风道骨。\n"NOR;
			str+= "他"HIY"整个笼罩在"HIW"七"HIR"彩"HIM"祥"HIC"云"HIY"之中。。\n\n"NOR;
			str+= "他身上带着：\n";
			str+= HIC"  □"HIB"揽月摘星"NOR"(Lanyue zhaixing)\n";
			str+= HIC"  □"HIB"卧龙"NOR"(Wo long)\n";
			str+= HIC"  □"HIB"晓月当帘"NOR"(Xiaoyue danglian)\n";
			break;
		case "将军府" :
			str = @LONG
这是一位鹤发童颜的老人。他看起来似乎很老的样子，
但偏又是红光满面。看到你打量他，他对你和蔼地笑了
一笑。

他看起来约一百多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"HIC"慈眉善目，神态非凡。 \n"NOR;
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;	
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIR"白发老人之符祝锏"NOR"(Fuzhu bian)\n";
			break;
		case "方寸山三星洞" :
			str = @LONG
大觉金仙没垢姿，西方妙相祖菩提
他看起来约一百多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。\n";
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIB"森罗棍"NOR"(Senluo gun)\n";
			str+= HIC"  □"HIB"烟波"NOR"(Yan bo)\n";
			str+= HIC"  □"HIB"铁叫盔"NOR"(Tiejiao kui)\n";
			str+= HIC"  □"HIB"苏绣直裰"NOR"(Suxiu zhizhui)\n";
			str+= HIC"  □"HIB"轻尘履"NOR"(Qingchen lv)\n";
			str+= HIC"  □"HIB"阴符玄衣"NOR"(Yinfu xuanyi)\n";
			break;
		case "月宫" :
			str = @LONG
西华至妙生伊川，穆王八骑访昆仑。
她看起来约四十多岁。
LONG;
			str+= "她的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "她面色红润，满脸福态。\n";
			str+= "她"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "她身上带着：\n";
			str+= HIC"  □"HIB"增运符"NOR"(Zengyun fu)\n";
			str+= HIC"  □"HIB"玫瑰戒"NOR"(Meigui jie)\n";
			str+= HIC"  □"HIB"远游冠"NOR"(Yuanyou guan)\n";
			str+= HIC"  □"HIB"绣花鞋"NOR"(Xiuhua xie)\n";
			str+= HIC"  □"HIB"巨阙"NOR"(Ju que)\n";
			str+= HIC"  □"HIB"玄武战袍"NOR"(Xuanwu zhanpao)\n";
			break;
		case "南海普陀山" :
			str = @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
她看起来约三十多岁。
LONG;
			str+= "她的境界与你相比，似乎"HIW"深不可测"NOR"。\n";	
			str+= "她"CYN"俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。 \n"NOR;
			str+= "她"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "她身上带着：\n";
			str+= HIC"  □"HIY"九环锡杖"NOR"(Nine-ring staff)\n";
			str+= HIC"  □"HIY"锦镧袈裟"NOR"(Jinlan jiasha)\n";
			break;
		case "盘丝洞" :		
			str = @LONG
她就是通天教主座下得意门生：金灵圣母，在这里替紫霞仙子教教徒弟。
她看起来约二十多岁。
LONG;	
			str+= "她的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "她"HIM"宛如"HIW"玉雕冰塑"HIM"，似梦似幻，已不再是凡间人物。 \n";
			str+= "她"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "她身上带着：\n";
			str+= HIC"  □"HIB"日月符"NOR"(Riyue fu)\n";
			str+= HIC"  □"HIB"脉脉"NOR"(Mo mo)\n";
			str+= HIC"  □"HIB"夜明盔"NOR"(Yeming kui)\n";
			str+= HIC"  □"HIB"百喻履"NOR"(Baiyu lv)\n";
			str+= HIC"  □"HIB"舞风拂"NOR"(Wufeng fu)\n";
			str+= HIC"  □"HIB"百华浣尘"NOR"(Baihua wanchen)\n";
			break;
		case "东海龙宫"	: 
			str = @LONG
敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。
他看起来约六十多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他面目古奇，龙角冲天。\n";
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIM"(灵)龙神之紫蔓"NOR"(Zi man)\n";
			str+= HIC"  □"HIM"(灵)龙神之通天手"NOR"(Tong tian shou)\n";
			str+= HIC"  □"HIM"(灵)龙神之仙客戒"NOR"(Xianke jie)\n";
			str+= HIC"  □"HIM"(灵)龙神之缎袖氅"NOR"(Duanxiu chang)\n";
			str+= HIC"  □"HIM"(灵)龙神之猿啸冠"NOR"(Yuanxiao guan)\n";
			str+= HIC"  □"HIM"(灵)龙神之鸳鸯鞋"NOR"(Yuanyang xie)\n";
			str+= HIC"  □"HIM"(灵)龙神之帅字甲"NOR"(Shuaizi jia)\n";
			str+= HIC"  □"HIM"(灵)龙神之之天罡拳套"NOR"(Tiangang quantao)\n";
			str+= HIC"  □"HIY"蟒龙袍"NOR"(Long pao)\n";
			break;
		case "蜀山派" :
			str = @LONG 
蜀山派现任掌门，主执天枢宫。满头白发的老人，两眼炯炯有神。
他看起来约六十多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"HIC"鹤发童颜，仙风道骨。\n"NOR;
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIR"蜀山之琥珀龟背甲"NOR"(Hupo guibei jia)\n";
			str+= HIC"  □"HIR"蜀山之掩日"NOR"(Yan ri)\n";
			str+= HIC"  □"HIR"蜀山之细鳞盔"NOR"(Xilin kui)\n";
			str+= HIC"  □"HIR"蜀山之广袖流仙"NOR"(Guangxiu liuxian)\n";
			break;
		case "大雪山" : 
			str = @LONG
这位大鹏明王的确大有来历，说起来跟佛祖如来也有点亲戚关系，
算是如来的“舅舅”。他不似其兄孔雀明王作恶多端，却也并非善类，
且因其兄之故跟佛门结下深仇。生平最讨厌的就是和尚。
他看起来约四十多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"MAG"面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIR"断水(Duan shui)\n";
			str+= HIC"  □"HIR"气吞牛斗(Qitun niudou)\n";
			str+= HIC"  □"HIR"碧月秋光铠(Biyue qiuguang kai)\n";
			str+= HIC"  □"HIR"晓月当帘(Xiaoyue danglian)\n";
			break;
		case "陷空山无底洞" : 
			str = @LONG
她就是这无底洞的洞主了。她从修道成人行以来，吃人无数，
也不知为什么玉皇还未曾派兵来围剿。听说她在天宫有亲，也
不知真假。
她看起来约二十多岁。
LONG;
			str+= "她的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "她"CYN"俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。 \n"NOR;
			str+= "她"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "她身上带着：\n";
			str+= HIC"  □"HIR"软狸裘(Ruanli chang)\n";
			str+= HIC"  □"HIR"狮尾盔(Shiwei kui)\n";
			str+= HIC"  □"HIR"木棉戒(Mumian jie)\n";
			str+= HIC"  □"HIR"裂帛符(Liebo fu)\n";
			str+= HIC"  □"HIR"虎虎生威(Huhu shengwei)\n";
			str+= HIC"  □"HIR"癸鬼袍(Guigui pao)\n";
			str+= HIC"  □"HIR"飞镰(Fei lian)\n";
			break;
		case "火云洞" :
			str = @LONG
七大圣之首，一双牛蛋眼正煞神一般瞪着你。
他看起来约七十多岁。
LONG;
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"HIC"骨骼清奇，气宇不凡。\n"NOR;
			str+= "他"HIB"身边围绕着一朵妖云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIB"森罗棍"NOR"(Senluo gun)\n";
			str+= HIC"  □"HIB"铁叫盔"NOR"(Tiejiao kui)\n";
			str+= HIC"  □"HIB"轻尘履"NOR"(Qingchen lv)\n";
			str+= HIC"  □"HIB"阴符玄衣"NOR"(Yinfu xuanyi)\n";
			break;
		case "五庄观" :
			str = @LONG
交游遍三界，桃李漫五行。好一位地仙之祖！
他看起来约六十多岁。
LONG;	
			str+= "他的境界与你相比，似乎"HIW"深不可测"NOR"。\n";
			str+= "他"HIC"鹤发童颜，仙风道骨。\n"NOR;
			str+= "他"HIY"身边围绕着一朵祥云。\n\n"NOR;
			str+= "他身上带着：\n";	
			str+= HIC"  □"HIC"戒尺"NOR"(Ruler)\n";
			str+= HIC"  □"HIB"仙袍"NOR"(Xian pao)\n";
			break;			
	}	
	return str;		
}

varargs int information(object who)
{
	string fam,*fams;
	if( this_object()->query("created") )
		return 0;
	this_object()->set("created",1);
	fams = ({"百花谷","阎罗地府","将军府","方寸山三星洞","月宫","南海普陀山","盘丝洞","东海龙宫","蜀山派","大雪山","陷空山无底洞","火云洞","五庄观",});	
	if( !who )
		fam = fams[random(sizeof(fams))];
	else if( !stringp(fam=who->query("family/family_name"))
	       || member_array(fam,fams)==-1 )
		fam = fams[random(sizeof(fams))];
	this_object()->create_family(fam,1,"");	
	switch(fam)
	{
		case "百花谷" :
			this_object()->set_name("凝眸仙子",({"ningmou xianzi","ningmou","xianzi",}));
			this_object()->set("gender","女性");
			this_object()->set("title",HIM"百花谷主"NOR);
			message_vision(HIY"\n随着一阵花香飘过，$N"HIY"的身影出现在一阵花雨中.....\n"NOR,this_object());
			break;
		case "阎罗地府" :
			this_object()->set_name("地藏王菩萨",({"dizang pusa","dizang","pusa",}));
			this_object()->set("gender","男性");
			this_object()->set("title",HIR"地狱不空 誓不成佛"NOR); 
			message_vision(RED"\n忽然间悲风飒飒，惨雾迷迷，阴云四合，风过数阵，“啪”的一股黑烟升起,$N"RED"从黑烟中走了出来…… \n"NOR,this_object());
			break;
		case "将军府" :
			this_object()->set_name("白发老人",({"lao ren","lao","laoren","ren","baifa","immortal","master","shifu"}));
			this_object()->set("gender","男性");
			this_object()->set("title", HIY"神仙"NOR); 
			message_vision(HIG"\n忽听得空中有一阵异香仙乐，飘飘而来,空中飘落一朵七彩祥云，$N"HIG"拨开云端走了出来……。\n"NOR,this_object());
			break;
		case "方寸山三星洞" :
			this_object()->set_name("菩提祖师",({"master puti","puti","master"}));
			this_object()->set("gender","男性");
			this_object()->set("title", HIC"斜月三星"NOR);
			message_vision(HIG"\n忽听得空中有一阵异香仙乐，飘飘而来,空中飘落一朵七彩祥云，$N"HIG"拨开云端走了出来……。\n"NOR,this_object());
			break;
		case "月宫" :
			this_object()->set_name("西王母",({"xi wangmu","xi","wangmu","master"}));
			this_object()->set("gender","女性");
			this_object()->set("title", HIW"月宫祖师"NOR);
			message_vision(HIM"\n只听得半空中仙乐齐鸣，垂珠璎珞，一阵香风缥渺，异味芳馨氤氲，$N"HIM"飘然而至…… \n"NOR,this_object());
			break;
		case "南海普陀山" :
			this_object()->set_name("观音菩萨",({"guanyin pusa","guanyin","pusa"}));
			this_object()->set("title","救苦救难大慈大悲");
			this_object()->set("gender","女性");
			message_vision(HIY"\n刹那间祥云缭绕，佛光万丈，莲花万朵，络绎不断，$N"HIY"踏着莲花宝座，徐徐降落尘间………\n"NOR,this_object());
			break;
		case "盘丝洞" :
			this_object()->set_name(HIY"金灵圣母"NOR,({"jinling shengmu","jinling","shengmu"}));
			this_object()->set("gender","女性");
			this_object()->set("title", HIB"坎宫斗母正神"NOR); 
			message_vision(MAG"\n但见霞光万道，瑞彩千条，光婵灿烂，映目射眼，一道彩虹从天空划过，$N"MAG"随彩虹飘然而至…… \n"NOR,this_object());
			break;
		case "东海龙宫"	: 
			this_object()->set_name("敖广",({"ao guang","ao","guang","longwang","wang",}));
			this_object()->set("gender","男性");
			this_object()->set("title",HIY"东海龙王"NOR);
			message_vision(HIC"\n但见云光缥缈，半空中仿佛冲出一条水柱，$N"HIC"从水柱上稳稳跳落地下……  \n"NOR,this_object());
			break;
		case "蜀山派" : 
			this_object()->set_name("剑圣",({"jian sheng","sheng","jiansheng",}));
			this_object()->set("gender","男性");
			this_object()->set("title","蜀山派第三代掌门");
			message_vision(HIC"\n一道蓝光闪过,$N"HIC"从剑上跳了下来。 \n"NOR,this_object());
			break;
		case "大雪山" : 
			this_object()->set_name("大鹏明王",({"dapeng mingwang","dapeng","mingwang","wang"}));
			this_object()->set("gender","男性");
			this_object()->set("title", "雪山之祖");
			message_vision(HIW"\n霎时间，大雪纷飞，雪花翩翩如雾卷云腾，冷气侵人，$N"HIW"亦如晶莹剔透的雪花随风飘下…… \n"NOR,this_object());
			break;
		case "陷空山无底洞" : 
			this_object()->set_name("玉鼠精",({"yu shu","yushu","shu","monster",}));
			this_object()->set("gender","女性");
			this_object()->set("title","地涌夫人");
			message_vision(HIB"\n悲风四起，杀气漫空，黑暗暗俱是些鬼哭神嚎，伴随着冷森森的笑声，$N"HIB"如魑魅般从黑暗中出现…… \n"NOR,this_object());
			break;
		case "火云洞" :
			this_object()->set_name("牛魔王",({"niumo wang","niumo","wang"}));
			this_object()->set("gender","男性");
			this_object()->set("title","平天大圣 「"HIR"大力王"NOR"」");
			message_vision(RED"\n一团红色的烟雾涌了过来,$N"RED"突然从里面蹦了出来。\n"NOR,this_object());
			break;
		case "五庄观" :
			this_object()->set_name("镇元大仙",({"zhenyuan daxian","zhenyuan","daxian"}));
			this_object()->set("gender","男性");
			this_object()->set("title", "五庄观观主"); 
			message_vision(HIC"\n一阵清风吹来，$N"HIC"从空中降落…… \n"NOR,this_object());
			break;
	}
	return 1;
}