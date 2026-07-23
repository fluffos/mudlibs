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


        switch(random(270))
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
                        qn="知识问答题";
                        break;
                }
                case 1:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《笑傲江湖》中日月神教的右使是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "向问天";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 2:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 石破天的玄铁令是从那里得来的?  ans 物品名\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "烧饼";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 3:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝在哪儿长大?  ans 建筑名\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "丽春院";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 4:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 金庸的原名是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "查良镛";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 5:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 金庸最后一部武侠小说是哪一部?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "鹿鼎记";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 6:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段誉有几个妹妹?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "5";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 7:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝娶了几个老婆? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "7";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 8:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 请问在《射雕英雄传》中曾中欧阳锋蛇毒的地球生物有几个?  ans 数量描述\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "无数";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 9:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖在一开始拜谁为师?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "江南七怪";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 10:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 情花毒用什么药可解?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "断肠草";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 11:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄蓉的丈夫是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郭靖";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 12:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 洪七公吃黄蓉的第一顿是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "烧鸡";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 13:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 虚竹娶的是那国的公主?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "西夏";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 14:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁喝了玄冰碧火酒? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "石破天";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 15:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 胡一刀是怎么死的?  ans 一个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "毒";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 16:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 第二次华山论剑谁较厉害?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "欧阳峰";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 17:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过的母亲是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "穆念慈";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 18:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过用的是什么兵器?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "玄铁剑";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 19:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《射雕英雄传》中郭靖骑的马是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "汗血宝马";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 20:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《射雕英雄传》中最初说话的是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张十五";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 21:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段誉和阿朱是什么关系?  ans 两个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "姐弟";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 22:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 东方不败的武器是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "绣花针";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 23:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过的手是谁砍断的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郭芙";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 24:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳不群最后被谁所杀? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "仪琳";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 25:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 虚竹的妈妈是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "叶二娘";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 26:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 何足道是哪一派的创始人?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "昆仑派";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 27:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《笑傲江湖》中最先出场的是 \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "林平之";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 28:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “飞雪连天射白鹿，笑书神侠倚碧鸳”共说了几本书? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "14";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 29:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 萧峰在辽国是何官职? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "南院大王";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 30:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《天龙八部》中“咱们学武之人，第一不可滥杀无辜”这句话出自谁口? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "乔峰";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 31:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 李文秀的师父是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "瓦耳洛齐";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 32:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过是何派弟子?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "古墓派";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 33:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲是向谁学会独孤九剑的?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "风清扬";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 34:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 东邪是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黄药师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 35:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 林平之家传剑法是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "辟邪剑法";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 36:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁解开了珍珑棋局? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "虚竹";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 37:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄河老祖是谁?  ans 人名和人名，年纪大的在前\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "老头子和祖千秋";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 38:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “千秋万载，一统江湖”是那一派的切口?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "日月神教";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 39:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 侠客行中的石破天，是谁的儿子?  ans 人名和人名，男的在前\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "石清和闵柔";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 40:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 金庸14部小说中是单一女主角的是哪本? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "白马啸西风";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 41:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝在鳌拜家中抄得多少两银子? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "二百三十五万";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 42:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《四十二章经》共几本? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "8";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 43:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝何许人氏? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "扬州";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 44:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过的师傅是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "小龙女";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 45:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 东方不败是死在谁手里?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "任我行";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 46:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝跟谁上北京的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "茅十八";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 47:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲的易筋经是谁所受? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "方证";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 48:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄容的爹是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黄药师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 49:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 东邪是指谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黄药师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 50:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 鸳鸯双刀，一刻“仁者”另一刀刻?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "无敌";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 51:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳不群练的是么内功?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "紫霞神功";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 52:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 张三丰90岁生日时，他哪一位弟子被砍段手脚? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "俞岱岩";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 53:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 萧峰最后是怎么死的? ans 两个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "自杀";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 54:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 桃谷仙人一共有几个?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "6";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 55:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过的姑姑是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "小龙女";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 56:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 王重阳有几个弟子? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "7";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 57:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 五仙教用什么生物帮令狐冲补血? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "水蛭";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 58:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 与岳不群争夺“五岳盟主”之位的是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "左冷禅";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 59:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 江南七怪之首是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "柯镇恶";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 60:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁发明了“左右互搏术”? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "周伯通";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 61:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖和黄蓉共有几个女儿?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "2";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 62:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “飞雪连天射白鹿，笑书神侠倚碧鸳”中“连”指的是什么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "连城诀";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 63:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黯然消魂掌由谁所创? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "杨过";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 64:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《鹿鼎记》中主人公是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "韦小宝";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 65:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 吴六奇是天地会哪个堂的香主?  ans 堂名香主名\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "洪顺堂红旗香主";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 66:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳不群的妻子叫甚么名字?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "宁中则";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 67:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 第一个向杨过传授武功的人是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "穆念慈";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 68:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中玄冥二老分别是? ans 人名和人名，翁在前\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "鹤笔翁和鹿杖客";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 69:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《射雕英雄传》中西毒欧阳锋曾使用那一种毒药杀海中的鲨鱼? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "化尸粉";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 70:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 山西一窟鬼中的长须鬼原名叫甚么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "樊一翁";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 71:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 顺治在给康熙的《四十二章经》首页中写了句甚么话?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "永不加赋";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 72:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 鹿杖客的最大弱点是甚么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "好色";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 73:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 赏善罚恶令的使者最初以甚么化名出现?  ans 人名和人名，按照一般通俗的排序\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张三和李四";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 74:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 胡一刀妻子的表哥所居的山庄叫甚么名字?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "玉笔山庄";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 75:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 峨嵋的第二代掌门是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "风陵";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 76:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 狄云杀了几个人? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "3";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 77:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中丐帮掌钵龙头的姓是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "翁";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 78:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 金蛇锥有多长? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "二寸八";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 79:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 华山论剑前，洪七公自称生平杀过多少人?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "231";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 80:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “源思英儿，巴巴西洛着，雪陆文兵”这句话是哪里的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "九阴真经";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 81:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 射雕英雄专中描写天下至柔的拳术是？  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "空明拳";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 82:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 第二次华山论剑中，欧阳峰咬了黄药师什么部位?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "右手食指";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 83:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梁子翁是哪部小说中的人物?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "射雕英雄传";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 84:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖擒裘千丈，点中他的什么穴道?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "天突穴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 85:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 东天龙门北宗新接任的掌门人是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "曹云奇";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 86:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 笑傲江湖里林平之是什么镖局的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "福威镖局";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 87:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《天龙八部》中与，段誉在无量山上学到的功夫是什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "凌波微步";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 88:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 丐帮范帮主曾以什么功夫抓死两头猛虎?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "龙爪擒拿手";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 89:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 「返腕翼德闯帐」是谁的剑招? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "苗人凤";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 90:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 田青文的师哥是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "曹云奇";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 91:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 保定帝座下大理国司空是？\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "巴天石";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 92:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 在天龙寺段誉哪个穴位被大轮明王拿住尔被擒?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "神封穴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 93:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 萧峰被辽国皇帝囚于铁笼，有多少士兵看守?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "100";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 94:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 看守萧峰的士兵，拿什么武器? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "长矛";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 95:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 天龙八部中守雁门关的宋军将领姓什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 96:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谢逊的义子是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张无忌";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 97:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梅超疯是谁的徒弟?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黄药师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 98:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁一直暗恋着令狐冲? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "仪琳";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 99:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄药师的大弟子是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "陆乘风";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 100:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖第一个杀死的人是谁？  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "陈玄风";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 101:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭啸天是被谁杀死的？\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "段天德";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 102:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 陆冠英是谁的儿子？\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "陆乘风";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 103:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 李文秀几岁失去父母? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "8";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 104:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 哈卜拉姆是哪部小说中的人物? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "白马啸西风";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 105:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲第一次打倒田伯光，用的是什么招? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "金玉满堂";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 106:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 陈禹是哪部小说中的人物?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "飞狐外传";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 107:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 王剑英是那个门派的高手? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "八卦门";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 108:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 桃谷四仙杀人是抓起人的四肢，抬起后再撕开四份，书中他们抬起多少人? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "10";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 109:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 瑛姑姓什么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "刘";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 110:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 莫大先生的剑藏在什么东西里?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "胡琴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 111:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 以下哪一种是恒山派的治伤良药?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "天香断续胶";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 112:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 曲波是曲非烟的什么人?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "爷爷";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 113:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 全世界有几个朱睛冰蟾?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "2";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 114:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 周止若母亲姓什么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "薛";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 115:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 天龙八部中虚竹是少林寺的第几代第子?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "第三十七代";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 116:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 天龙八部中阿碧的师傅是？ \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "康广陵";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 117:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 绰号“小东邪”的是?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郭襄";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 118:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 卫天望是哪部小说中的人物?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "倚天屠龙记";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 119:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中，少林寺罗汉堂首座是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "无色禅师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 120:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 张三峰生日是农历? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "四月初九";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 121:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谢逊第一次出场，手上拿着什么武器? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "狼牙棒";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 122:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 曲洋擅长什么乐器?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "七弦琴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 123:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 木婉清的座骑的名字是什么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黑玫瑰";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 124:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 萧峰在少林寺的授业恩师是谁?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "玄苦";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 125:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 一灯大师的徒弟排位是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "渔樵耕读";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 126:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过让郭襄说了几个“大英雄”?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "5";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 127:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 九尾灵狐是谁养的?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "瑛姑";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 128:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 慈恩大师是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "裘千仞";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 129:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过给了郭襄几支金针?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "3";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 130:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭襄用了杨过的几支金针?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "3";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 131:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过给郭襄的第二件礼物是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "烟花";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 132:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 金轮法王曾说自己的法名?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "珠穆朗玛";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 133:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 七个老婆中，韦小宝最先结识的是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "沐剑屏";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 134:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝的七个老婆之中，最变态的是? ans 四个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "建宁公主";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 135:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝的七个老婆之中，最温顺体贴的是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "双儿";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 136:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 玄冥神掌留在张无忌身上的掌印是什么颜色的?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "碧绿";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 137:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “东西永隔如参商”是哪部小说中的章节?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "倚天屠龙记";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 138:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中行刺张三丰的少林和尚是?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "空相";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 139:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “吉藏凶，凶藏吉”这句话是谁唱的?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "小昭";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 140:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 张无忌答应赵敏的第三件事是：\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "画眉";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 141:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 邵鹤属于哪个团体? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "青海三剑";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 142:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 雁翎飞天刀姓什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "邱";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 143:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “杀龟大会”的“龟”是指?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "吴三桂";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 144:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 假太后的父亲叫?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "毛文龙";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 145:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 胖头陀变瘦的原因是服用了什么药物?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "豹胎易筋丸";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 146:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 阿珂是谁的女儿？ \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "李自成";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 147:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中峨嵋派静字辈共有多少尼姑? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "12";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 148:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 明教厚土旗掌旗使是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "颜垣";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 149:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中神秘黄衫女子救谢逊时带了几个随从?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "8";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 150:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “铁鞭镇八方”是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "周威信";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 151:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 流星赶月花剑影是哪部小说中的人物? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "鸳鸯刀";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 152:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 史亿刀是谁的别名?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "石破天";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 153:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 克制雪山派‘苍松迎客’的招术是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "开门揖盗";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 154:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 与陆菲青交手的罗信使用什么武器?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "钢鞭";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 155:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 武当长拳共有多少式? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "32";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 156:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 苗人凤与辽东大侠胡一刀在何处比武? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "沧州";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 157:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 王语嫣与段誉在哪相爱? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "枯井";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 158:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《倚天屠龙记》中创立峨嵋派的是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郭襄";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 159:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁第一个教张无忌武功?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张翠山";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 160:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 第一次华山论剑谁胜出? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "王重阳";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 161:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 笑傲江湖中嵩山派仙鹤手姓氏名谁?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "陆柏";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 162:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 常伯志是何门派? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "青城";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 163:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 关东六魔的老五是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "阎世魁";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 164:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 戴永明是干什么职业的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "镖师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 165:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 锐金旗掌旗使是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "吴劲草";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 166:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《入道四行经》是谁作的?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "达摩";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 167:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 虚竹在哪个部位中了生死符?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "阴陵泉";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 168:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “山门护法”属什么掌法? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "韦陀掌";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 169:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 萧远山第一次潜入少林寺，偷到的武功是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "无相劫指";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 170:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《神雕侠侣》第一回中，陆无双和程英所遇见的“怪伯伯”是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "武三通";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 171:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 魔教哪位长老临死前在华山思过崖上刻了尽破恒山剑法几个字? ans 人名和人名，范在前\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "范松和赵鹤";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 172:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖在蒙古有什么别称? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "金刀驸马";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 173:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 天龙八部是什么宗教的名词?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "佛教";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 174:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 锺灵豢养的是何种灵物? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "闪电貂";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 175:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 昆仑三圣由几个人组成? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "1";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 176:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 张无忌出生在哪个岛上? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "冰火岛";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 177:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨康的父亲是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "杨铁心";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 178:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天剑中藏着哪部武学秘集 \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "九阴真经";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 179:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 小龙女的师傅是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "林朝英";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 180:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 紫薇软剑后来下场如何? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "落入山谷";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 181:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 指笔功是全真七子中谁的武功?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "谭处端";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 182:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 穆易是谁？ \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "杨铁心";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 183:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “桃花影落飞神剑”的下一句是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "碧海潮生按玉箫";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 184:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄河四鬼中谁第一个死？\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "马青雄";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 185:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 孙不二的道袍上绣了什么图形？  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "骷髅";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 186:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过自创的掌上绝学名叫什么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "黯然消魂掌";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 187:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲是那一派的掌门? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "恒山派";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 188:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黑玉断续膏在哪一部中出现? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "倚天屠龙记";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 189:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 慕容复是哪国后裔?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "燕";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 190:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 九难神尼的手臂是谁砍段的?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "崇祯皇帝";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 191:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁是丐帮污衣派的长老?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "鲁长老";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 192:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 裘千仞的师父是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "上官剑南";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 193:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 华山派共收了几个女弟子?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "7";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 194:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳不群住处叫什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "有所不为轩";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 195:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 华山派第四戒是什么? ans 四个字，四个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "同门嫉妒，自相残杀";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 196:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁杀了王惟忠将军? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "陈大方";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 197:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 胡斐幼年在商家堡不敌王剑杰是谁指点了他? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "赵半山   ";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 198:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝最初的志向是什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "开妓院";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 199:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “空明拳”是谁所创?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "周伯通";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 200:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 林平之的外公是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "王元霸";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 201:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖和黄容一共有多少个儿女? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "3";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 202:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝他妈的名字?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                            answer = "韦春芳"; 
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 203:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《射 雕 英 雄 传》小说中最初说话的是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "张十五";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 204:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 张翠山是张三风的第几弟子?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "5";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 205:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 耶律洪基封萧峰为什么元帅?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "平南大元帅";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 206:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过的“过”是什么意思?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "改之";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 207:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 云中鹤是四大恶人的老几? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "4";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 208:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “要切肉，总得有肉可切；要砍柴，总得有柴可砍。”是谁说的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "风清扬";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 209:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 袁承志的第一个师傅是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "穆人清";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 210:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 在《神雕侠侣》中，公孙止勾搭上了的婢女的名字是甚么?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "柔儿";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 211:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 第一次华山论剑和第二次华山论剑相隔几年? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "25";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 212:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 左冷禅时期的嵩山派共有几路剑法?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "17";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 213:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲比岳灵珊大几岁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "8";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 214:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 史火龙会几招降龙十八掌?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "12";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 215:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 华山后洞中破恒山派剑法的魔教长老是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "范松";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 216:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “天上星，亮晶晶”是哪本书上的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "天龙八部";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 217:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 吕希贤是哪部小说中的人物? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "飞狐外传";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 218:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过与小龙女相隔几年未见? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "16";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 219:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 《天龙八部》中“无恶不作”指的是四大恶人中的谁?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "叶二娘";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 220:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 江南七怪中唯一的女性人物是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "韩小莹";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 221:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 丘处机与江南七怪在何处比武? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "烟雨楼";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 222:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梯云纵是哪派武功? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "武当";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 223:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳老三是谁的徒弟? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "段誉";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 224:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 要浇甚么才能种活七心海棠?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "酒";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 225:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 血刀老祖是被谁杀死的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "狄云";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 226:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 石破天会哪种功夫?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "太玄经";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 227:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 降龙十八掌第一式是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "亢龙有悔";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 228:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 倚天屠龙记中，昆感仑派何太冲的夫人是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "班淑娴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 229:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : “老顽童”自创的武功叫什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "左右互搏术";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 230:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过在襄阳城下杀死的蒙古可汗是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "蒙哥";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 231:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 虚竹是什么门派的掌门?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "逍遥派";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 232:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 香香公主是怎么死的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "自杀";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 233:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梅超疯是被谁打死的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "欧阳峰";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 234:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 周伯通是哪个门派的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "全真教";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 235:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 岳不群的辟邪剑法是谁教他的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "自学";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 236:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 南帝和东邪分别是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "一灯和黄药师";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 237:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段誉真正的父亲是谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "段延庆";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 238:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝最恨谁?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郑克爽";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 239:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 虚竹真正父亲是谁?  ans 两个字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "玄慈";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 240:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 苗人凤和胡菲一战谁胜了? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "不知道";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 241:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 全真七子中谁的武功最高?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "丘处机";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 242:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 南帝的原名是什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "段智兴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 243:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段天德是被谁杀死的?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "杨康";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 244:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梅超风练功用的骷髅是怎么摆的?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "上一中三下五";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 245:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 郭靖一共有几个师父?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "9";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 246:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 用一阳指为别人疗伤，几年内武功尽失?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "5";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 247:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 林平之的坐骑叫什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "小雪龙";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 248:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 青城派余沧海所住的道观叫什么? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "松风观";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 249:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 梁发在华山派众弟子中排名第几? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "3";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 250:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 刘正风选在哪一个时刻洗手? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "午时";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 251:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段誉的母亲的道号是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "玉虚散人";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 252:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 段誉在无量山中学的一种吸人功力的武功是什么?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "北冥神功";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 253:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 以下哪个是慕容复在西夏一品堂时的化名?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "李延宗";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 254:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杨过在走出石阵后，碰到的吹萧女子是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "程英";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 255:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 公孙绿萼死在谁的手里?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "公孙止";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 256:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 黄蓉骗杨过南海神尼几年来中原一次?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "16";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 257:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 蒙古军灭掉大理时，当时的大理王是?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "段兴智";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 258:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 谁杀了尼摩星? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "杨过";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 259:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 最后一个向耶律齐挑战的是? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "霍都";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 260:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 霍都是被谁杀的? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "达尔巴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 261:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 杀死黑龙鞭史松的是谁? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "韦小宝";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 262:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝杀史松用的是什么招数? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "撒石灰";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 263:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝最先跟谁学过功夫？\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "海老公";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 264:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 康熙父亲的年号为? \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "顺治";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 265:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 韦小宝的七个老婆之中，年纪最大的是?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "苏荃";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 266:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 玉林是哪个寺的主持?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "清凉寺";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 267:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 顺治出家后的法号为?  \n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "行痴";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 268:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 国姓爷的二公子叫郑克爽，那么大公子呢?\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "郑经";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                case 269:
                {
                        strMsg = HIW"你的一个师弟风尘仆仆地跑到你面前作了个揖，毕恭毕敬地问道：掌门人有问题托我来请教您：\n"NOR;
                        strMsg = strMsg + "\n请问 : 令狐冲做恒山派掌门是在哪月哪日?  ans 中文数字+月+中文数字\n";
                        strMsg = strMsg + "警告：请绝对不要在公共频道中谈论此题，以免泄漏本派机密。\n";
                        answer = "二月十六";
                        qn="知识问答题";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"在这里用 ans <答案> 来回答，比如 ans 3 或者 ans 屠龙刀\n"NOR);
                        break;
                }
                
	}
        me->start_busy(3);
        npc = new("/family_job/ansnpc");
        npc->set("aid", me->query("id"));
        npc->move(environment(me));
        npc->set("correctans", answer);

        CHANNEL_D->do_channel(this_object(), "alarm", sprintf("工作目标: %s(%s)  工作NPC: %s  工作型态: 智慧型问题  题目编号: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
        return;
}
