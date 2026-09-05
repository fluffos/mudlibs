
代码均在单机版XKX2001上编译通过（MudOS v22pre11）。

没有关键谜题

火种的动作没有写。实在是不知道怎么写了。

所有NPC的武功都需要调整，以配合关键谜题。

地图中的王府府门和僻静小巷的 south 均连接ct


NPC:
//NPC:门房2个		OK
    ITEM:仆人服		OK

//NPC:大轮寺经师1名	OK
    ITEM:紫红袈裟	OK

//NPC:老王妃1名		OK
    ITEM:红宝石戒指	OK = 15 GOLD
    ITEM:红绢姑姑冠	OK = 2 GOLD
    ITEM:大红织锦团衫	OK = 5 GOLD

//NPC:美女N个		OK
    ITEM:淡黄丝裙	OK
    ITEM:淡绿丝裙	OK
    ITEM:天蓝绸裙	OK
    ITEM:薄纱白裙	OK

//NPC:美艳胡姬1名	OK
    ITEM:宽褶长裤	OK = 10 SILVER
    ITEM:玛瑙腰带	OK = 3 GOLD
    ITEM:波斯纱巾	OK = 12 SILVER
    ITEM:宝石项链	OK = 6 GOLD
    ITEM:火种		HALF

//NPC:内宅总管太监1名	OK
    ITEM:总管服		OK

//NPC:前院总管太监1名	OK
    ITEM:总管服		OK
    ITEM:铁钥匙		OK

//NPC:王府仆人2名	OK
    ITEM:仆人服		OK

//NPC:王府卫士4个	OK
    ITEM:辫线袄		OK
    ITEM:钢刀		Clone from /clone/weapon/gangdao

//NPC:王府卫士4个	OK
    ITEM:辫线袄		OK
    ITEM:钢刀		Clone from /clone/weapon/gangdao

//NPC:王府卫士4个	OK
    ITEM:辫线袄		OK
    ITEM:钢刀		Clone from /clone/weapon/gangdao

//NPC:卫士长1个		OK
    ITEM:柳叶甲		OK
    ITEM:辫线袄		OK
    ITEM:钢剑		Clone from /clone/weapon/gangjian

//NPC:王府侍女2名	OK
    ITEM:半臂		OK
    ITEM:襦裙		OK

//NPC:执事处执事1名	OK
    ITEM:执事服		OK



设计了几个小关卡
1.门岗和卫士营不让带兵刃
2.回事厅太监把门不让进
3.内宅太监把门不让进
4.王府后门的跳进跳出和unlock
5.燕怡堂美女有随机动作

2009-06-21更新：

//NPC:韦一笑		PART
    ITEM:青色斗篷	OK

//NPC:苦头陀--范遥	PART
    ITEM:灰色长袍	OK


降低了胡姬和王妃身上物品的价值，贪心人太多了……

新增一僻静小巷，用于解谜出韦一笑。与王府后门的僻静小巷连接。

新增一水牢，解谜后，出口在流水亭。要测试哦，出了人命，我可管不了……

流水亭 set("no_fight",1)

在东卧房fight，会被抓入水牢。

宜宾馆 set("sleep_room",1)。

在西卧房久留，会晕倒（有迷人烟雾），醒来会在水牢。

万安寺部分地图更新。

以下地图需要更改实际出口的连接点
wanansi/xiaojiuguan.c
wanansi/caiyuan.c
wanansi/xiaoyuan.c
ruyang-wangfu/lane2.c