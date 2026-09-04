1.pker处理
  pker可以到miao zhu 那里捐钱赎罪，和kar一样。设定的是3个mudage不pk,
  可以捐钱增加一点PK_penance,当PK_penance>PK数是，名字后面不出线 杀人犯。
   
  修改 /adm/daemons/combatd.c 加入killer->set("PK_time",time());

       /d/city/npc/keeper.c修改（以前哪个不加kar的，现在改了）

       /feature/name.c  增加了PK_penance判定。


2.体重
   /adm/daemons/race/human.c  增加了性别判定同等str下，女性是男性体重的2/3

3.perform huche

  修改了/cmds/std/perform.c

        /daemon/class/pfm/talk/huche.c

  胡扯神功 可以将对方kee 降低500,本身kee ,sen都减100；
	   通过随机数判定成功，
           literate 50-100 成功率是20%
		    100-200      是40%
		    200-	 是60%；
           如果不成功，将busy 2-4个回合。同时kee,sen减50；
       	

4。云阳
   将master yunyang旁边的xiao dao 更改为lingtai hufa,专门拦截外人，yunyang 以后只负责
   门派任务。
 
    修改 /d/lingtai/jingtang.c
         /d/lingtai/npc/hufa.c


5.sldh相关文件全部好了，如有bug只有再调。可以使用与1vs1的比赛中。
  具体可以看相关的help sldhdoc,help fajiang.
 
  修改   /d/kaifeng/obj/sldhdoc.c
	 /d/kaifeng/obj/sldhtai.c 
	 /d/kaifeng/npc/baomingshi.c
	 /d/kaifeng/ground2.c

6.copyequip

  可以复制对方的所有装备。
   修改  /cmds/adm/copyequip.c


7.wizlist1.c
  显示wiz在线和离线时间及任务。任务通过renwu id 内容分配。
  修改  /cmds/usr/wizlist1.c
        /cmds/arch/renwu.c
