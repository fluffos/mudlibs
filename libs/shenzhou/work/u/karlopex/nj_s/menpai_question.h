//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//********************   Menpai QUESTION Star Here   **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void menpai_question(object me, string strName, string strId, string strFName, int intExp)
{
	object npc;
	string strMsg, answer, qn;
	int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
	r1 = random(5) + 5;
	r2 = random(5) + 10;
	r3 = random(5) + 15;
	r4 = random(5) + 20;
	r5 = random(5) + 25;
	r6 = random(5) + 30;
	r7 = random(5) + 35;
	r8 = random(5) + 40;
	r9 = random(5) + 45;
	r10 = random(5) + 50;
	r11 = random(5) + 55;
	r12 = random(5) + 60;
	r13 = random(5) + 65;
	r14 = random(5) + 70;
	r15 = random(5) + 75;
	r16 = random(5) + 80;


	switch(random(9))
	{
	case 0:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
			strMsg = strMsg + "**************************\n";

			answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

			tell_object(me, strMsg);
			tell_object(me, HIW"以上是某门派的阵形，如果要破解必须在四条线内将一到九全部碰到\n一但完成这个阵就不攻自破了，你有六十秒的时间思考"NOR);
			tell_object(me, NOR"\n回答方法使用点对点方式，如果从一碰到三然后三碰到九然后九碰到七最后七到一，指令为 ans 1t3 3t9 9t7 7t1，\n"NOR);
			tell_object(me, NOR"请在这里回答 (起始直是 2)\n"NOR);
			qn="G1";
			break;
		}
	case 1:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "一夫，二郎，三吉，四祥，五平五个人，是青梅竹马的好朋友，如今长大成人，\n";
			strMsg = strMsg + "各自当上面包店老板，理发师，肉店老板，菸酒经销商和公司职员。\n\n";
			strMsg = strMsg + "1.面包店老板不是三吉，也不是四祥。\n";
			strMsg = strMsg + "2.菸酒经销商不是四祥，也不是一夫。\n";
			strMsg = strMsg + "3.此外，三吉和五平住在同一栋公寓，隔壁是公司职员的家。\n";
			strMsg = strMsg + "4.三吉娶理发师的女儿时，二郎是他们的媒人。\n";
			strMsg = strMsg + "5.一夫和三吉有空时，就和肉店老板，面包店老板打牌。\n";
			strMsg = strMsg + "6.而且，每隔十天，四祥和五平一定要到理发店修个脸。\n";
			strMsg = strMsg + "7.但是，公司职员则一向自己刮胡子，从来不到理发店去。\n\n";
			strMsg = strMsg + "问题 : 请将这五个人的职业按照顺序写出来，用空格来分开\n";
			strMsg = strMsg + "(使用 ans <一夫的职业> <二郎的职业> <三吉的职业> <四祥的职业> <五平的职业>\n";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			answer = "理发师 公司职员 菸酒经销商 肉店老板 面包店老板";
			qn="L2";
			break;
		}
	case 2:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 100 = K\n";
			strMsg = strMsg + "\n问题请问 : K 的数值是多少?\n";
			strMsg = strMsg + "使用 ans <答案>\n";
			answer = "88";
			qn="M3";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}
	case 4:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "1 + Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 12 + 100 = K\n";
			strMsg = strMsg + "\n问题请问 : K 的数值是多少?\n";
			strMsg = strMsg + "使用 ans <答案>\n";
			answer = "101";
			qn="M4";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 5:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + " ****1**** \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " 2       3 \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " ****4*******8**** \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " 5       6       9 \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " ****7******10**** \n\n";
			strMsg = strMsg + "以上是某门派武功的攻击招术所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪两边才可以产生四个同样的长方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二>    注意: 数字请从最小排到最大\n";
			
			answer = "5 7";
			qn="G5";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 6:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "         ****1**** \n";
			strMsg = strMsg + "         *       * \n";
			strMsg = strMsg + "         3       6 \n";
			strMsg = strMsg + "         *       * \n";
			strMsg = strMsg + " ****2****       * \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + "12      13       16\n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " *       ****5*******8***** \n";
			strMsg = strMsg + " *       *                *\n";
			strMsg = strMsg + "14       7                9\n";
			strMsg = strMsg + " *       *                *\n";
			strMsg = strMsg + " ***15******10******11*****\n";
			strMsg = strMsg + "以上是某门派武功的防守招术所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪三边才可以产生六个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三>    注意: 数字请从最小排到最大\n";
			answer = "8 9 11";
			qn="G6";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 7:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "****1****\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "2       3\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "****4****\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "5       6\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "****7*******8*******9****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "10      11      12      13\n";
			strMsg = strMsg + "*       *       *       * \n";
			strMsg = strMsg + "***14******15******16**** \n";
			strMsg = strMsg + "以上是某门派武功的剑法所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪四边才可以产生四个一样大个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三> <数字四>    注意: 数字请从最小排到最大\n";
			answer = "5 6 8 15";
			qn="G7";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}


	case 8:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "****1*******2*******3****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "4       5       6       7\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "****8*******9******10****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "11      12      13      14\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "***15******16******17****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "18      19      20      21\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "***22******23******24****\n";
			strMsg = strMsg + "以上是某门派武功的掌法所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪四边才可以产生五个一样大个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三> <数字四>    注意: 数字请从最小排到最大\n";
			answer = "2 11 14 23";
			qn="G8";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}


	default:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
			strMsg = strMsg + "**************************\n";

			answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

			tell_object(me, strMsg);
			tell_object(me, HIW"以上是某门派的阵形，如果要破解必须在四条线内将一到九全部碰到\n一但完成这个阵就不攻自破了，你有六十秒的时间思考"NOR);
			tell_object(me, NOR"\n回答方法使用点对点方式，如果从一碰到三然后三碰到九然后九碰到七最后七到一，指令为 ans 1t3 3t9 9t7 7t1，\n"NOR);
			qn="G1";
		}
	}

	me->start_busy(3);
	npc = new("/family_job/ansnpc");
	npc->set("aid", me->query("id"));
	npc->move(environment(me));
	npc->set("correctans", answer);

	CHANNEL_D->do_channel(this_object(), "sys", sprintf("工作目标: %s(%s)  工作NPC: %s  工作型态: 智慧型问题  题目编号: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
	
	add_temp("menpai_count", 1);
	get_player();
	return;
}