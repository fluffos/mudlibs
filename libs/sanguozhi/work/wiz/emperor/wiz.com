---
作者: Fire
题目: play
日期: Sun Dec 20 04:25:42 1998
近期工作计划
圣诞节马上到了，完了就是新年，这一短时间几位WIZ不能来。
而我们计划明年一月正式开放测试版，为了不使这一计划再度
延期，我们需要把下一步的工作明确一下。
首先明确一点，测试版不是正式版，不需要完成所有的部分，
只需要完成玩家能够从新手成长到中手所需的部分内容就行了。
等最早一批新手成为中手，这一过程大约为一到两月，我们应该
又完成了一些新的内容。
从现在到正式版，我们还需要充实完善以下部分：
1 帮助系统。
1.1 负责从新整理所有的玩家帮助文件。补充缺少的部分，尽量
使帮助文件完整，连贯。
1.2 在新的部分完成后，开发WIZ必需附带相应的玩家帮助。
1.3 调整帮助指令，使之方便实用。
2 Basic JOB
计划有10种不同的基础JOB，主要奖励是金钱，附带一点声望和技能。
3 MId level JOB
中级JOB分几大类：战争类(征兵，训练，剿匪)。生产类(包括农业与
工业两部分，牧业？)，商业贸易(买卖商品，商业投资)，特殊任务
(侦查，巡逻，送信，访问贤人，修行)。
4 宣传
介绍性文章，主页。。
因为时间紧，我们不可能完成更多的内容，只要上述四项工作可以完
成80%，就足以开放测试版了。
任务安排：
我将负责帮助系统，同时写一些介绍性文章，我不善于作主页，也许
可也请JAKEY帮忙。等介绍文章写好了，就可以拿到各MUD，BBS，讨
论组中去散。
初级JOB已经有了五个，剩下的五个基本上可以照搬，这些主要由ROW
负责，我和FLEE会尽量支持。FLEE的救火，和最早得游泳可以改进一
下当两个JOB。ROW正在设计草鞋。这些都完成后只需在加两个就可完
成计划(XIXI)
中级工作比较复杂，我将负责战争类和商业贸易。FLEE的土地开发很
有意义，我们需要玩家在完成任务的同时不仅提高个人的技能修养，
还要提高地区(甚至国家)的实力。FLEE将负责生产类的中级JOB，我们
希望中级JOB能够尽可能地与现有的char_d,area_d,等系统相互溶合，
这也许在开始设计时有些困难，但对于长远的发展是有益的。因此我
会尽量支持FLEE，使生产类JOB能与现有系统相溶合。Task_d 比较麻烦
而且不太稳定。但char_d设计得较可靠。关于特殊任务，谁的既定任务
先完成，谁就负责吧。
关于新WIZ，主要完善地区房间。
现阶段工作主要就是这些，addoil all


---
作者: Tset
题目: temp leave
日期: Sat Dec 19 21:26:02 1998
leave about 1 month...maybe back earlier :)


---
作者: Tset
题目: fishing job done
日期: Wed Dec 16 01:26:26 1998
as title...please check
ask of the 重复最小时间间隔：约五分钟...this latency
period should be default...hope flee can add it in JOBD
somewhere, since feedgoat, chopwoods, waterflower, and
now fishing all assume this


---
作者: Tset
题目: >good work tset
日期: Wed Dec 16 01:22:09 1998
void stop_busy()
	stops busy time


---
作者: Stefan
题目: >any comments?
日期: Mon Dec 14 17:44:06 1998
This sounds terrific!!!!

Microsoft wants to buy out TMI-2 and LPC, and want all the existing
LPC based mud to cease operation, that is VERY FUNNY!!!

This memo was dated august 1998, what is current status?
I am eager to know more...

Let's see if Microsoft can dominate the MUD world.


---
作者: Tset
题目: about busy time
日期: Sat Dec 12 22:27:38 1998
void start_busy(int n, mixed msg)
    n - busy length
    msg - busy message to be shown to user

eg, start_busy(30, ({ "你忙得很呢。"", "分心多用？不可能。" }))

mixed query_busy(int shown)

Right now all verbs are disabled if user are busy, so
can't move, can't do score, etc, but commands are not
disabled, so user can chat and talk.  Note this will create
some problems with commands under /cmds/player/, a way
to solve the problem is in the command, use the function
check_condition(), and if it doesn't return 0, return what
that function returns.  This can be applied to fly.c (you
cannot fly when you are busy).  Also, anyone needs a way
to interrupt busy time?


---
作者: Flee
题目: good work tset
日期: Sun Dec 13 22:02:01 1998
yeah, i need the way to interupt one's busy.. :)
addoil test.


---
作者: Stefan
题目: I will be back
日期: Wed Dec 16 16:26:37 1998
Early January. I will be on holiday leave.

stefan


---
作者: Yuner
题目: Leave
日期: Sat Dec 26 06:20:59 1998



---
作者: Tset
题目: posts from the other sanguo mud(6)
日期: Sun Nov 29 21:48:42 1998
[29] 一些不属于三大国的将领                   柳随风(darken)(Thu Nov 12)
----------------------------------------------------------------------
                     一些不属于三大国的将领

不在三国中的将领正史中写的不多，好简单写点。

攻击

赵云  子龙一段时间是公孙赞的，所以也写一写。赵
云算是全能形的将领，有谋略，也有勇力，且忠心，
为百姓着想。建议在襄平或北平找到，有蜀国可用。
str 90，int 80，def 80

颜良  袁绍的勇将，和文丑齐名，极好气派，常坐在
有鹱盖装饰的马车，也因次行动不便，被关羽斩杀
。建议到邺城附近找找便能找到。
str 90，int 20，def 30

文丑  与颜良齐名的猛将，颜良被斩後心浮气躁，
被张辽一阵杀後丧命。建议到邺城附近找找便能
找到。
str 90，int 30，def 30

沙摩柯  南方的异族领袖，有勇力，三国志中记载他
使一铁棘砾，建议到成都南方去找。
str 80，int 50，def 40

严颜  刘璋将领，在和张飞单挑打的不分上下後，接受
张飞，降了刘备。建议在成都附近走走，打赢了就能
得到。
str 80，int 70，def 60

张任  刘璋将领，在落凤破以伏兵、箭雨杀了庞统，被
捕後至死不降，乃忠心的智将。建议到江陵去找，若中
了他的伏兵还活下来，便会加入。(好可怕:))
str 60，int 80，def 70

庞德  马腾部将，在汉中养伤是被曹操找到而降曹。在
三城追逐战时，被关羽的水计散，独身一人冲上关羽
的小船，刺杀关不成而被捕，宁死不降，被关所杀。
建议在汉中找到，且等一季(养病)後才能使用。
str 90，int 40，def 30

防守

张合  袁绍将领，後来降了曹操。在阳平关防守，时夏侯
渊刚死，又受到蜀军五虎将连攻，却能支撑到曹操大军来
救。建议在南皮附近找到。
str 80，int 70，def 80

郝昭  郝昭是魏的将领，应该不在这写的，是突然想到
以前忘了写他，需要补偿一下 :)  郝昭在孔明出歧山时守
陈仓，以三千兵马将孔明的三四十万人当在陈仓以南，使
之粮草补给困难而退兵。yeg 说暂时不加，就不写建议了。
str 60，int 80，def 80

高干  袁军中最杰出的将领，防守并州，在壶关与曹操的
大军抗战月余，重伤曹军猛将乐进，後因曹军的策反而出
亡，被羌人所杀。建议在晋阳附近找到。
str 70，int 70，def 80

内政

田丰  袁军谋士，直言不讳，而让袁绍所杀。曹操在官渡胜
利後，感叹道：“若本初用别驾之计，胜负由未可知。”
是连曹操也忌惮三分的谋士。建议在南皮附近找到。
str 20，int 90，def 30

沮授  袁军谋士，是袁军中紧次于田丰的智囊，却也不被重
用。屡屡献奇计而不被接纳。官渡兵败後宁死不屈，被曹操
斩首。建议在陈留处寻找。
str 30，int 80，def 20

卢植  汉末的海内大儒，身高九尺，声如洪钟，因放对董卓
的废立，被赶出宫廷，後病死。建议在长安找到。
str 50，int 90，def 30

荆良、荆越  刘表的宾客，荆州名士，在荆州降曹後投降曹操
，是荆、襄一带的大儒，极有名气。建议在襄阳一带找到。
str 20，int 80，def 20

有关治理
       若有长于内政的 npc 随行，manage 的速度便回已其能力
而有不等的加快，或增加lsp。


---
作者: Fire
题目: about money
日期: Mon Nov 30 16:26:30 1998
Now i have adjust sth for the money.
so a ppl can not give money to other
ppl and npc and can not drop money.
If we need some npc can accpet money and
for quest and job (such as Kong Yiji) 
then we can use the function set_accept_money(1);
in the setup of that npc and this can also
be call after the object is created
if an living( can be npc and player) has been
set as accept money others can use give amt monty to sb
(emaple: give 5 silver to kong) to give that
living money
cheers


---
作者: Fire
题目: the new warroom desc
日期: Tue Dec  1 15:43:59 1998
Tset has finished the new desc of war room, all I can
say that it is amazing and splendid.
But there are still something that can be added
to improve the display. for example. now
a ppl can see the approxmate number of solider
in this ceil, but he can't see how many troops
and which troops are in this cell. later
we will add cmd so that two troop can merge into one
and one troop can split to two and also 
can send command to NPC controled troop
and we will discuss that later
thank tset
admire tset
addoil tset


---
作者: Fire
题目: char's auto action
日期: Tue Dec  1 17:39:50 1998
I have make npc char can auto move and do
semote in fact we can do it more complex
this is in /sgdomain/modules/m_charnpc/m_charaction.c
any suggestion ?


---
作者: Fire
题目: huayin viliage moved !!!
日期: Wed Dec  2 16:28:42 1998
I have moved huayin viliage (the viliage when ppl login)
to /sgdomain/area/guan/huayin/ so all the sanguo area
now is under /sgdomain/area. Now it seem ok, If 
someone find something wield, please let me know.

Thanks


---
作者: Fire
题目: About yizhan
日期: Wed Dec  2 16:33:27 1998
Group has done a very nice work.
Sweat group
But there are something need to be noticed
1 huayin viliage (the start point) doesn't have yizhan
2 luoyang has two yizhan (one is old fake one) one is 
  new one
3 all the area map doesn't show the position of yizhan

Could Group please concern them and solve them as soon
as possible. when these are done. the fly will become
the wizards luxury. grin
addoil group


---
作者: Row
题目: about yizhan
日期: Wed Dec  2 20:06:51 1998
驿站 
    这里便是天水城的驿站了，一片忙忙碌碌的气象，人喊马嘶，车
辕辘辘。跨过门槛靠左面是一个柜台，后面的伙计正忙不迭地招呼客
人，柜台后的墙上贴着张纸，上面标着到各地的价目。而右面不时有
车夫走进走出，那里还停放着各种待用的马车。从这里出去就是东大
街了。

hi group,

there is yizhan in some cities which i made b4 to put mafu and
carter, now it's ur work :), i would like u put them in the original
yizhan, coz i already had them shown in the map. for those cities
i did not put yizhan, please rewrite the map and copy the desc
from the original ones. i know this will bring u extra work, but i
will be appreciated if u do it. thank u very much.

                                         row


---
作者: Fire
题目: the files under /daemons
日期: Sat Dec  5 13:28:29 1998
I clear all the back up files under /daemons in order to
make i rest clear and find that there are two files
stranger under /daemons
one is [get]  another is [get *] don't know what are these 
and can't use more to check. 
could stefan please have a check and if useless please remove
them?
thanks


---
作者: Fire
题目: about the clean up
日期: Wed Dec  9 17:37:11 1998
I am not sure how the clean_up works, but
it really keep the total number of the objects
in a reason range. for my obversion. now the total
number of objects is keep about 1000 or so in the
system. If there are much more than 1000 objects
in the memory, then the system will high possible
use clean_up to destroy some objects
this is harmful to some job systems and war, since
because some time the object record some situation 
and if this object disapperad and reappear some setting
may be not right. for example, if you ask somebody
for a job, then your name is recorded as the employee
in the employer object. but then if this employer
is destoried and reappear, you can't be remember as
his employee. this will cause bugs.
Now I have make some adjustment in the object.c
and container.c and add two functions
int query_clean_up()
void set_clean_up(int p)
the first one we don't bother it in most case( the
system will handle)
but for the second one, if you don't want your object
be clean_uped so just add
set_clean_up(1); in your object's code.
then it will not be destoried unless you intend to
do so (hope this works)
please check:
/sgdomain/job/digsoil/sir.c and
/sgdomain/job/digsoil/soil.c for reference
best regards


---
作者: Group
题目: water flower
日期: Thu Dec 10 05:16:42 1998
waterflower job has been finished. 
i put the hua jiang in luoyang ly_dhl
the directry is waterflower/
please check it. if no problem, i will finish the help file soon.


---
作者: Fire
题目: about feedgoat
日期: Thu Dec 10 15:26:31 1998
that is a very good work, addoil flee
but there is a little bug
1 when you give grass to goat and if you don't have grass
then will give error message
like this
[errors] (firex) Error logged to /log/runtime
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/job/feedgoat/goat#7564 at line 38
if you have two grass withyou will cause similar bugs
2 from the employee the message is :
> 小羊在测试的脚下绕来绕去，大概是渴了。
shoud be > 小羊在你的脚下绕来绕去，大概是渴了。

anyway this is a very nice job
addoil flee


---
作者: Fire
题目: >water flower
日期: Thu Dec 10 15:35:00 1998
On Thu Dec 10 05:16:42 1998 Group wrote post #281:
> waterflower job has been finished. 
> i put the hua jiang in luoyang ly_dhl
> the directry is waterflower/
> please check it. if no problem, i will finish the help file soon.
good group,
write your help about this job and let's players
to test
addoil xixi


---
作者: Tset
题目: >water flower
日期: Thu Dec 10 18:21:44 1998
it seems to be that you should "turn bottle", instead of
"turn bowl", 倒水壶, 不是倒花盆


---
作者: Fire
题目: about the chopwoods
日期: Thu Dec 10 20:46:39 1998
the chopwoods is a very nice job finished by row
now we have three basic jobs
and tset and group are develop two more
I think that about 10 basic job is enough
then we can move to medium level jobs
addoil all


---
作者: Group
题目: re 259
日期: Thu Dec 10 21:51:12 1998
actually what i want to use is "water bowl".
when i ask flee, he said that better not increase more verbs, hence i use
turn instead of water. if turn bowl is not that good, i will think ti improve
it.


---
作者: Tset
题目: any comments?
日期: Sat Dec 12 18:43:25 1998
just saw this somewhere...wonder what you guys all think
about this issue...comments?


Time:    Wed Apr  1 02:00:52 1998                Post-id: 4 (15 Last)
Poster:  Blue
Subject: Important (driver-related and other)

Dear all,

I have received the following email on which I'd be interested in  
your comments.  Please read my notes at the bottom before following
up.


From s-craigb@microsoft.com  Tue Mar 31 16:32:04 1998
Message-ID: <C83BD0BB1BBED01198AF00805F196034312507@WSH-03-MSG>
From: "Craig Barham" <s-craigb@microsoft.com>  
To: "'Leigh Caldwell'" <BLUE@INTERNATION.CO.UK>
Subject: FWD: RE: TMI-2 product and LPC licence
Date: Tue Mar 31 16:31:25 -0800
X-Priority: 2
X-Mailer: Internet Mail Service (5.0.1458.30)

Mike Barber wrote:
> I think we should go ahead and begin negotiations.  I've discussed
> it with Legal and they say that the issues are real but
> surmountable.  We had a similar situation with <name of other
> product deleted> and it was settled with no major ramifications.
> My estimated budgets are quoted below.


Dear Mr. Caldwell

As you know from your discussions with Mike and Nassad over recent 
weeks, I am the Strategy Director for the Online Community Group at
Microsoft, and as such I am the person you'll be dealing with in  
the proposed acquisition or license of your TMI-2 product and
associated interpreter software.  My aim will be to find a way in
which both of our strategic objectives for the development of this
sector can be served.

Mike has given you an idea of some of the potential that we've been
seeing here, but to give you a coherent idea of how we see this
developing, here is my own take on each topic.


  COMMUNITY INTEGRATION - Hotmail/MSN
  -----------------------------------

As you know, our strategy for MSN is shifting from content
production to community-building.  The recent acquisition of
Hotmail was initiated for this reason, but we also intend to offer
several facilities and technologies unique to MSN and not readily
duplicated by others in the market.  One of these will be a
realtime interactive environment.  In order to reach market quickly
and create the potential that we believe exists, we need an
existing environment, easily configured and with a developer base.
TMI-2 fits.

We intend to host TMI-2 environments on all Hotmail and MSN
servers, with a Windows-based frontend client.  Of course, we need
to be reassured that the technology can handle traffic of between
20,000 and 50,000 simultaneous users at any time, but the
demonstrations you have shown to my colleagues have satisfied them  
that the only limit will be the NT backend's user capacity.  With
input from our own engineers, we feel confident that the product
can be optimized to ensure fast response at these levels.


  LANGUAGE TOOLS
  -------------- 

As a leader in the development tools market, Microsoft wishes to   
continue to expand its Visual products range with new languages.   
In addition, we will need development environments for the new    
community facilities on Hotmail/MSN, and as the major development
languages for the TMI-2 product, LPC and LPscript appear to be the
appropriate starting points.

In order to enable Community Operators on Hotmail and MSN to create
the kind of applications that we believe will build the realtime   
user base, we propose to create Visual LPC and Visual LPscript 
packages.  While development tools are not my area of expertise, my
conversations with executives from that division indicate that our
Visual C++ and/or Visual J++ products can easily be adapted to
LPC and that Visual Interdev will provide a suitable base for 
LPscript integration.


  TECHNOLOGY POSITION
  -------------------

The final reason behind our proposed acquisition is the need for
Microsoft to maintain its position at the forefront of software
technology.  Our position has always been to develop or acquire
the leading product in every market, and it is as a continuation of
our technology policy that we propose to integrate TMI-2, the
leader in easy-to-build, highly extensible realtime environments,
into our product range and service offering.  It is crucial that   
we remain informed of further technological developments in the   
MUD sector, in order that we can ensure TMI-2 benefits from the
advances gained by competitive, second-tier products.  We will  
aggressively market TMI-2 to ensure that its commercial position
remains unchallenged, but it will be your role as
technology
consultants to the project to ensure that any and all new ideas
that emerge in the sector are integrated into our product
sufficiently quickly to destroy any lead another product might
gain.  Where source code is available in the public domain or
where its licensing terms are unenforceable, we will incorporate
technology directly.  Otherwise, you will be expected to
duplicate functionality as necessary.


  LICENSING
  ---------

Of course one of the issues that needs to be resolved ASAP is that 
of the license.  Our understanding is that you and Mr. Wouters have
control of the license for TMI-2, but that the licenses for the
primary interpretation software for the TMI-2 language LPC are not 
held solely by you.  We will expect you to expedite the process of
gaining control of these licenses, and the budget available is
commensurate with the urgency of this task.  Our legal advisers'
analysis of the source code in question indicates that there are
four parties, primarily Mr. Hollebeek and Mr. Pensj|, and secondarily
Mr. Garnett and Mr. Richards, who have a legally defensible claim on
the source code for the "MudOS" implementation of the LPC API.  We
believe that the other contributors have no legal rights in the
source code as it currently stands, as the extent of their
contribution in the current code is negligible.  We are prepared to
defend this position in court if necessary.

However, as we have indicated to you, exclusivity is extremely 
important to us.  We therefore wish to examine the rights of others
to create and promote compatible technology.  In particular, I
understand that a Mr. Rennecke and a Mr. Croes have compatible
products.  With Mr. Pensj|'s rights purchased, we will attempt to
prevent these parties from distributing their product, but funds   
will be available for purchase of that intellectual property if   
necessary.

On a similar theme, we will also expect all MUD servers currently
using TMI-2 or LPC technology to cease operation by the end of

August 1998.  However, as a gesture of goodwill to the community,
we will be willing to rebrand a number (around 12) of these as
Microsoft Community Games and to allow them to continue to operate
on MSN servers.


  BUDGET
  ------
  
The figure that you quoted to Nassad as an estimate for the overall
licensing costs is simply beyond our means.  And as an acquisition
of this kind by Microsoft has a very significant PR and marketing  
value for a company such as yours, we would expect that to be taken
into account in determining a purchase price.  However, we are 
willing to make available US$5.5 million for the outright purchase 
of all rights in TMI-2 and the interpretation software mentioned  
above.  There will be a separate budget to finance the development
of individual community environments on MSN/Hotmail; this will be
in the region of US$120,000 per annum for each environment.

Please get back to me this week with a status report on the above
issues, and a signed NDA.


Regards,
        Craig Barham
        Strategy Director, Online Community
        Microsoft


-------------- Forwarded message ends --------------


Basically I want to know: what do you think of this?  I haven't   
signed the nondisclosure agreement yet, and so I am still free to
post this.  I have to admit I am not sure of their legal ground,
but there is plenty of money available and we are willing to
discuss a settlement with anyone with a genuine copyright claim.

I need to respond to them by Friday, so make any comments as soon
as possible.

Of course I'll be contacting Lars, Beek, Truilkan and Cygnus
directly, and Dworkin and Amylaar shortly afterwards.  Any other
interested parties would be advised to provide information as soon
as possible.

Regards,
        Leigh Caldwell
        Blue@TMI-2


--
------------------------------------------------------------------------
  information        |  Leigh Caldwell, managing director, Internation.
    innovation       |   Allied House, 45 Hatton Garden, London, U.K.
      integration    |          +44-171-242-3200 (fax 3033)
        Internation. |  blue@internation.co.uk   www.internation.co.uk
------------------------------------------------------------------------
(181-199 100%) [h]:
(driver.misc:4:#4) 11 unread [q?lLmghsSprRfFncUMDut#g] >


---
作者: Tset
题目: posts from the other sanguo site(5)
日期: Sun Nov 29 21:48:00 1998
[26] ＴＯＰ  武将                             柳随风(darken)(Tue Nov 10)
----------------------------------------------------------------------
                              ＴＯＰ　　武将


防守
魏、张辽
       张辽字文远，原为丁原部将，吕布叛董卓後，丁原被杀，张
辽遂加入吕布阵营。曹操灭吕布後，深爱张辽才，故劝其降之
。张辽擅长骑射，且富谋略、指挥能力，是曹操最重用的降将之
一。合肥之役，以八百骑兵大破孙权亲领的十万大军，威名大振
。在关羽降曹後与之结成好友。我的建议是加个吕布 dummy npc
在小沛，魏国将领若能杀掉吕布，再向曹操请示後，便可拥有张
辽。张辽守的城难攻，且不 refresh (yeg 的 idea)。建议的 stat
如下：
功击 80，智慧 70，防守 100，长于防守、守城。
lsp 80 至 100

治理
这方面枣祗和孔明不分上下，因此一并提出魏、枣祗
       枣祗原为曹操羽林指挥官，建议曹操采屯田政策，是曹操能
够强大的第一因素。彻底解决了曹军庞大的粮草问题。长于经营
管理，负责，是曹操最重要的后勤部。建议必须有曹操的明令，
并到陈留一带找寻，便能得到。建议的 stat：
攻击 20，智慧 90，防守 20，长于治理、计谋。
lsp 50 左右。

蜀、孔明
       孔明就不用多说了吧，一流的经营管理人才，在垅中时便能
在刘备三顾茅庐(是真有此事)的口试中提出三国鼎立的一流策。
更重要是他能辅助刘禅这废人把蜀治理的井井有条，才能可见
一般。建议在得道刘备命令後到徐州一带找巡，再到襄阳便能
得到。建议的 stat：
攻击 30，智慧 100，防守60，长于治理、计谋
lsp 60 - 80 左右。

阻挡
虽然刘延羽比关羽延稍强，但关羽也不能忽视。

魏、刘延
       刘延时官渡之战时曹军西线指挥官，独自以极少的兵力抵当袁
军中第一智将高干，将他阻在白马数月，减轻曹操在官渡主战场的
压力。建议在邺城附近逛逛，运气好就能找到。建议的 stats：
攻击 70， 智慧 70，防守 90，长于阻挡。
lsp 80 -- 100 左右。
蜀、关羽
       关羽在江陵时一度独自抵当孙、曹联军，并连续打败曹军于禁
、曹仁、庞德及吴的潘璋、朱然等，不愧勇将之名。一直到有周亚夫
再世之称的徐晃加入战场和陆逊的暗度陈仓之计方兵败被杀。建议一
开始蜀军就能向刘备要人。建议的 stats
攻击 90，智慧 70，防守 80，长于阻挡。
lsp 100 左右。

伏兵
伏兵一道，自然是东吴最佳拍挡吕蒙、陆逊的拿手好戏。

吴、吕蒙
       吕蒙是智勇双全的明将，在鲁肃死後任东吴的西线都督。和陆
逊以奇兵施展暗度陈仓之计，使得有战神之称的关羽败亡。建议一
开始便能向孙权要人。建议的 stats：
攻击 80，智慧 80，防守 50，长于伏兵、间谍。
lsp 100 左右。

吴、陆逊
       吕蒙与陆逊败关羽之事不在赘述。荆州争夺战时，使用伏兵及
以逸待劳之计击败刘备、法正军，让本来没什么名气的吕逊一夜间
声名大噪。建议有吕蒙之后，在柴桑一带可以找到。建议的 stats：
攻击 20，智慧 90，防守 30，长于伏兵、间谍。
lsp 80 左右。
突破

魏、乐进
       乐进字文迁，身材短小，胆量却奇大，大战时总在第一线都战
，作战时专注又有耐心，不知道疲劳。是曹操的常任前锋。在葫关
对高干，阳平关对张卫，赤壁对周瑜，官渡对袁谭，全是以身赴险
，一马当先，在骑兵突击上的指挥力仅次于曹操和赵云。建议一开
始便能向曹操要人。建议的 stats：
攻击 80，智慧 30，防守 50，长于突击、突围。
lsp 80 左右。

为什么大部分是魏国将领？这不是我偏心，一则曹操会用人，二来
我对曹军较了解，是以如此。有建议或反对，就 post 出来打架
参考参考吧。



---
作者: Tset
题目: posts from the other sanguo site(4)
日期: Sun Nov 29 21:47:16 1998
[24]   排行榜 -- 统帅篇 (by 柳随风(darken))   叶公(yeg)(Mon Nov 09)
----------------------------------------------------------------------
                           排行榜 -- 统帅篇

        统帅基本上合我们现有的统驭力差不多，不过统帅包涵了
计谋、急智、冷静、判断，不像我们是靠经验，架打多就强 ：)
也许 wiz 考虑加上这些来决定战阵的胜败。

魏

曹操  不用多说，曹操是三国时最有名的军事家，连孔明也甘拜
下风，说道：“曹操用兵，彷弗孙武。”曹操善于用兵，也善于
用人，因此部下能人不少。在官渡以十分之一的兵力打倒当时
的首席盟主袁绍，便是由于用人和用兵如神。他写的魏武注孙子
(又称为孟德新书)便是有史以来最高的著作，可惜被刘璋使者
张讥笑，一气之下烧掉了，因而失传。(*slogan zhangsong :))

曹仁  曹营中少见的谋略形将领。曹操由于自己用兵高超，因此
总把部下留在身边指挥，却没有给他们独当一面的练习机会，所
以曹营的将官多半不能做总指挥。曹仁却是异于常人，文武双全，
骑射和谋略都有相当的造意，如蜀汉的赵云。

张辽  前面的post以提到张辽以八百骑兵破东吴十大军，他的
统帅可见一番。

张  袁绍阵营的降将。定军山是为副指挥，主将夏候渊被斩毫
不惊慌，立刻一边向曹操报信，一边自行接下防务，十分冷静，
暂时保住了汉中、巴郡。

徐晃  杨奉阵营的降将。他和张辽是曹操引以为傲的最大收获。
对华北地形极为熟悉，惯打游击战。

于禁和程昱  曹营的两大智将，极受曹操信任，也经常独当一面。
一次于禁的士兵告他谋反，一向有猜疑心的曹操也表示决不相信。
受了诬陷也不急找曹操分辨，将战中的防御做好候才晋见曹操。
程昱在上篇以提过，此不加赘述。

蜀

赵云  又提道赵云了。。还好这人不多，不然要写到什么时侯 :)
赵云算是全能形的将领，各方面的能力都不差，统帅自然不错。

关羽  关羽和孙坚并称为三国时代的“战神”当然是当统兵大将的
良材。此外关极富个人魅力，军队中对他的崇拜也是统驭力高的
原因。

姜维  搞什么。。怎么蜀这么多文武双全的 ：)
姜维本是天水骑兵队长，崇拜孔明而加入蜀。孔明晚年更将兵法
传授给他，加起来便是一个十分强的将军。

吴

陆逊  陆逊本是书生，由于精通谋略而被吕蒙委派为将领，如曹魏的
程昱、李典。陆逊以儒生带兵擒杀有战神之称的关羽，不可小看。

吕蒙  吕蒙本是武夫，但受孙权和鲁肃的规劝，闭门苦读兵书，后来
成就非凡，常有人们意想不到的见解。

周瑜  周是难得一见的人才，在用兵方面可以与曹操、孔明并论，以
五兵士破了曹操南下的百大军，可惜在襄樊争夺战时被曹仁、
徐晃军流矢所中，不幸身亡。



---
作者: Tset
题目: posts from the other sanguo site(3)
日期: Sun Nov 29 21:46:44 1998
[22] 排行榜  --  谋士篇                       柳随风(darken)(Sun Nov 08)
----------------------------------------------------------------------
                          排行榜  --  谋士篇
        自古兵法便道“不战而屈人之兵”是兵法最高成就，这就
说明了谋士的重要。

魏

曹操  本人的偶像，当然多写点 :)  曹操本身便是他自己最好的参
谋长，部下也很多这样的人才。曹操年少时便酷爱兵书，常常手
不释卷，这点和孙式三代很像，比刘备强多了。刘备年青是不务
正业，吊儿浪当。。离题了，是乘机损一下刘备而已 :)

郭嘉  十分出色的参谋，但不幸早死。全方位的谋士，在战阵、
内政、外交都有极佳的表现。智慧直逼天才型的孔明、司马懿，
曹操在赤壁大败时，叹道：“若是郭奉孝在此，便不会如此大败
了。”可见曹操对郭嘉的倚重。

荀欲  我的输入法找不到那个字，好随便用一个。文若是魏的元
老级谋臣，许多曹营的精英都是他推的，如荀攸、戏志才、郭嘉
等等。本身长于内政，曹操出外远征是，总是让他守大本营。

荀攸  荀文若的侄子，长于战场规，曹操南征北战，总是有他在
幕僚中。唯一一次荀公达没有随军是在赤壁，曹操却在这打了个大
败仗。

贾翔  又找不到字了。。曹军谋士的名字都怪。。。
贾文和原是李榷谋士，李榷灭亡後投靠张绣，再一齐投降曹操。也
长于战场，与程昱是最佳拍挡。赤壁之战时反对进攻东吴而留守江
陵，曹操兵败後悔不听文和之言，对之更加信任。

蜀

诸葛亮  曹操、司马懿最重要的对手。曹操攻徐州是与家人分散，故
定居荆州。(曹操差一点就得到了。。如果曹曹有孔明。。。)刘备死
後以丞相身分担齐重任，以当时蜀、魏的实力对比，还能和魏国有守
有攻，实在是当时之人才。

庞统  与孔明和称卧龙和凤雏的明士，不知正史上极少记载他的事迹，
说到他在落凤坡被流矢所中而死。

马良、马谡  也是有明的谋士，但正史上著墨及少，之道他们是荆州
的名士，也许是陈寿是魏国的，不想写别国的良臣？ :)

吴

周瑜  吴国谋臣首推周瑜，在赤壁一带以五万军队打败曹操纵横华北
的百万大军，且有极强的记忆力，时人道：“曲有误、周郎顾。”

鲁肃  虽然在三国演义中被描写成到处受欺负的老好人，但是他是史
上最成功的外交家。他的“借荆州”战略是十分高明的，非常有国际
眼光。当时曹军极强，而刘备部下、谋臣也极佳，但没有自己的地盘，
因此他连蜀抗魏，可惜孔明、孙权眼光较短浅，无法长期维持盟约。

张昭、张弘  和称江东二张的明士，在行政、内政方面极强，是因为
亲曹而不怎么被重用。



---
作者: Tset
题目: posts from the other sanguo site (2)
日期: Sun Nov 29 21:46:08 1998
[17] 排行榜 -- 防守篇                         柳随风(darken)(Thu Nov 05)
----------------------------------------------------------------------
                                  排行榜 -- 防守篇
      现在大家都喜欢抢了城市再扔一堆士兵来守城，所以先写写防守。

排行以能力越高越前面，并以国家分开。

魏

张辽  吕布阵营的降将，在曹操西争刘备时守合肥，以八百骑兵大破东吴
孙权亲率的十万大军，曹操事后观察地形，赞道：“文远真非常人也。”

刘延  可以说是魏极优秀的防守将领，不知为何默默无名。官渡之战时，
刘延以不到两千步卒，在白马渡口成功的抵挡袁军的杰出将领高干上万
军队许久，减轻曹军左翼不少压力。

程昱  很多人都认为成昱是参谋，其实他是将军出身，因计谋百出而被
曹操选为幕僚。他和于禁和称为曹营的两大智将。曹操东争徐州时，陈
宫和张邈迎吕布，策动全兑州(当时曹操的大本营)反叛，程昱与剩下不到
十分之一的城市共同防犯吕布，撑到曹操大军回来，功劳不小。 

蜀

赵云  不容至疑的是三国最杰出的将领之一，定军山之战，黄忠斩了夏侯
渊侯，被张颌追击，逃到赵云营帐中，赵云兵少，不敢出战，就打开营门，
单骑站在门口，曹军怕有计，乃退。赵云趁机杀，令曹军招收不少损失。 

吴

周瑜  赤壁之战时，曹操百万大军南下，周瑜以地形(长江)跟气候(赤壁一带
的地形风，因长江激流形成)的优势，用五万人把曹操百万军打回长江以北，
功不可默。

周泰  周泰和孙权是年青时是同乡，那时孙策将一个小城交个权管理，正好
山贼来攻权和泰无兵，好撤退，山贼约千於人，周泰以不到二十人疑兵断
後，并以身相护权，兵力悬殊下竟能让权全身而退。



---
作者: Tset
题目: posts from the other sanguo site
日期: Sun Nov 29 21:44:11 1998
anding    安定    郭汜   
ba        巴      吴懿
chaisang  柴桑    文俜
fa        樊城    蔡瑁
fu        涪      严颜
gongan    公安    傅士仁
henei     河内    王匡
hengyang  衡阳    袁胤
hongnong  弘农    华雄
hu        吴      严百虎
huiji     会稽    王朗
ji        蓟      刘虞
jiangzhou 江州    张任
jianning  建宁    李恢
jinyang   晋阳    杨奉
luo       雒      马超
pingyuan  平原    沮授
puyang    濮阳    吕布
runan     汝南    何仪
shangyong 上庸    吴兰
tianshui  天水    姜维
wudu      武都    杨怀
xiapi     下邳    陈登

[31] 讨董联军                                 柳随风(darken)(Fri Nov 13)
----------------------------------------------------------------------
                讨董联军
渤海太守、袁绍
河内太守、王匡
冀州牧、邺太守、韩馥
豫州刺史、孔柚
兑州刺史、刘岱
陈留太守、张邈
广陵太守、张超
东郡太守、桥瑁
山杨太守、袁遗
济北相、鲍信
辽东太守、公孙度
奋武将军、曹操
後将军、南阳太守、袁术
陈留孝廉、卫兹

以下军团并没有正式参加，可是也给董卓一点压力 :)
左将军、皇甫嵩
幽州牧、刘虞
河南尹、朱隽
京兆尹、盖勋
杨州刺史、陈温
丹阳太守、周歧


[32] 18路猪侯征董。                           夜郎(nightboy)(Fri Nov 13)
----------------------------------------------------------------------
1. 后将军南阳太守袁术
2。冀州刺史韩馥
3。豫州刺史孔妯
4。兑州刺史刘岱
5。河内太守王匡
6。陈留太守张邈
7。东郡太守乔瑁
8。山阳太守袁遗
9。济北相鲍信
10。北海太守孔融
11。广陵太守张超。
12。徐州刺史陶谦
13。西凉太守马腾
14。北平太守公孙瓒
15。上党太守张扬。
16。乌程侯长沙太守孙坚。
17。渤海太守袁绍
18。曹操



---
作者: Fire
题目: demote yue
日期: Sun Nov 29 18:23:54 1998
yue has been demoted becouse hasn't worked here for
a long time and abuse wiz power.
she is the first wiz demoted by the decision of
wiz committee ( the vote results is 4:1)
she will continue work in the old site and when



---
作者: Fire
题目: leave of ccc
日期: Sun Nov 29 16:56:54 1998
ccc will take a month of leave


---
作者: Yue
题目: what happened?
日期: Sun Nov 29 09:50:31 1998
when i login today i was in:
监狱 出口：west
    这里黑沉沉的，即无一丝光亮，也无半分声息。四壁摸上去冰
凉，且极硬，似乎都是钢铁铸成，只有南北幸坏佬∶牛派开了个巴掌大的洞，象是送饭用的。
what happened? what did i do? sigh


---
作者: Fire
题目: about the path
日期: Thu Nov 26 14:17:59 1998
关于路径：
这个MUD是一个集体创造的MUD。现在每一个巫师都有一个
个人路径。此路径主要用于测试，和学习。当一个东西成熟
后应该把它移到/sgdomains/下的相关路径或其他系统路径下。
这样将便于整体的管理和协调。现在有许多房间，NPC等在
/wiz/fire/路径下，这主要出于历史原因。同时由于现阶段事情
太多，腾不出手来搬运(将来还是要把他转移到合适的地方)。
但对于新些出的代码，除非是纯粹个人的小玩具，其他的应
尽量放到/sgdomains/之下。另外我们有一个文件/include/path.h
定义了许多关于路径的宏，为了规范，请尽量实用这些宏。
Best regards，
fire


---
作者: Fire
题目: new suggestion about mache and mafu
日期: Wed Nov 25 16:52:47 1998
Now i have added two function 
get_distance(string beg,string end)
and get_all_distance(string beg)
in area_d.c
for get_distance(beg,end) the beg and end are two areas
if one is not exist return -1 if from beg can not
reach end ( this should be impossible) return -2
else return the distance between them
if beg== end return 0
the get_all_distance will return a mapping
which show the distance to all area which can be reached
to test them just use
@AREA_D->get_distance("changan","luoyang")
@AREA_D->get_all_distance("changan")
it is very simple to use so I strongly suggest
to use them to improve the mache system
therefore the price and busy time for one
ppl go from one area to another area should
depends on the distance
Addoil flee and group


---
作者: Fire
题目: about mache and mafu
日期: Wed Nov 25 15:33:17 1998
the mache and mafu which flee has designed are very
nice, Here is some of my suggestion
1 create a modle file for mafu and mache and put them 
 under /sgdomain/modules
2 create some mafu npc under the path of /sgdomain/npc/mafu
 which inherited m_mafu
3 create some mache obj under the path of /sgdomain/obj/mache
  this maybe not unnessary, but can make some variety
4 in eace area, select a suitable room (if don't have then create one)
and put a mafu in
5 create some random display in the process of mache's moving
6 after that I will disable fly for player. . . 

NOTE: 1,2,3,5 just suggestion :) may be your guys have better
ideas. But 4 is necessary and i hope we can do 6 ASAP :)
addoil flee and group

one more thing if we don't want look the beauty desc for some
npc such as: 马夫(mafu)唇红齿白，身材挺拔，好一个英俊少年！
just add one sentence in the obj file: set_sg_rongmao(-1);


---
作者: Flee
题目: 马车 finished
日期: Wed Nov 25 04:28:15 1998
马车 for transport finished.
马车 --> /wiz/flee/misc/mache.c and 
mafu --> /wiz/flee/misc/mafu.c.
if two area r directly connected, the time cost
is 10 seconds and money cost is 10 silver.
otherwise, time cost is 20 seconds and money
cost is 20 silver.


---
作者: Fire
题目: current tasks
日期: Tue Nov 24 22:27:33 1998
1. finish low level jobs and mid level jobs (flee and row)
2. Add merchant sell horse and bow and food and stuff (fire)
3. Add 驿站 system so change fly to wiz and advanced player (group)
4. add cmd so the general can control npc troop's action (fire)
5. manual arrange troops (fire)
6. new desc for warroom (tset)
7. new suggestion on localmeeting such as buy horse, buy buy bow (fire)
8. buy stuff become a job (fire)
9. train troops as a job 
10. national meeting
11. auto movement for offline chars


---
作者: Fire
题目: mergeable object
日期: Tue Nov 24 22:16:18 1998
mergeable objects can auto merge together when
in one place such as array and firewoods
to use it just inherit M_MERAGEABLE 
and please refer /sgdomain/job/chopwoods/firewoods.c
the module is in /sgdomain/modules/m_merageable.c


---
作者: Fire
题目: >re last application
日期: Tue Nov 24 15:09:45 1998
On Tue Nov 24 01:26:50 1998 Lei wrote post #255:
> All applications sound very nice... However, we know there are 
> only a few good wizards...
> 
> maybe we should promote them as temp wizard... 1 month later evaluate their
> work and give final
> decision, ok?
> 
That is a good suggestion
I will add this in the wizard rules
thanks lei
xixi


---
作者: Fire
题目: welcome new wizards
日期: Tue Nov 24 16:16:39 1998
now ccc and laoda are new wizards
according to the wizard rules they will
have two weeks learn time
and after one month, the wizard committee
will exam their thier work to see if they
are qualified as wizards here


---
作者: Fire
题目: JOB JOB
日期: Fri Nov 13 15:14:22 1998
Job System Design
Job system includes four parts:
1. a module file
   Because one ppl's job record can include a lot of information
so it is unpractical to keep all this information in the char_d,
which will keep on memory all the time. so we need a m_job.c as
a module file which define the ppl's job record and all the related
functions. The record include the number of one kind job this ppl
has finished, the last time of this kind of job has been finished
and the situation of current doing jobs.
2. a main job daemon
   We will have many different types of jobs so the situation can
be very complex therefor we need a daemon to handle all the most 
common information and behaviors for the jobs. These information
will include these following information.
Job ID: each kind of job has one identical english name
Job Name: a chinese name for this job
Requirement: some job need a certain requirement, some can be set as
          numbers some may need a function to define the requirement
Reward: The reward is the most important part for the job system
        In fact a player does all this mainly for the reward. In order
        to keep the reward fair and blance. we can check this file to
        manage the whole picture of the rewards.
3. seperate job process contral files
   The jobs can cover a lot different actions. For one job it usually
includes following steps:
   The first step is ask for the job.
   The second and the main step is do the job, this may include several
   sub steps
   The last step is finish job and go ask reward or resign the job (
some time got penishment)
The real process for different jobs could be quite different. So we need
a lot of creative and imaginable work here.
4. robot checking
In order to make the job more attractive and reward the real player, we 
need a robot checking program. each time when a player finish a job, the
system will give him one question. if he can get the right answer then get
the reward if not fail.
Task arrangement
For the job system, I suggest the following task arrangement:
I will do the module file coding. Flee will be responable to the daemon file
Row finish the first several small jobs (such as chop firewood and shoulder 
water). and we will exchange the ideas frequently and make the whole system
run. after the frame is finished then we can develop more job and insert in
this system (like plug in ?)
File allocation:
model file: /sgdomain/modules/m_job.c
daemons file: /daemons/job_d.c
process file: /sgdomain/job/<jobname>/*.*
Previous work:
Flee has done two jobs already the extinguish fire and spy. when the
frame work
is finish those two jobs need got a little modify and fit in the whole system
Schedule:
before the end of November,1999 finish the frame work


---
作者: Fire
题目: new feature for char
日期: Thu Nov 12 22:35:18 1998
new feature localcontribution has been added
in char_d.c
use function get_char(p_id,"localcontribution") 
and set_char(p_id,"localcontribution",p_val) to operate it
and if for other area use :
setchar_localcontribution(string p_id,int para_value,string p_area)
and getchar_localcontribution(string p_id,string p_area)


---
作者: Fire
题目: depromote wizard
日期: Tue Nov 10 18:25:00 1998
ziguang   紫光      巫师  离线：三十四天         166.111.5.7
according to the wiz rule,
ziguang will be depromote from wizard


---
作者: Fire
题目: about the job
日期: Tue Nov 10 18:22:48 1998
任务与玩家个人参数。
玩家个人参数有以下几种：
序号   名称          上限           备注
1      金            无
2      声望          100000000
3      地区贡献      10000000
4      国家贡献      10000000
5      基本技能等级   100           受玩家天赋限制(三项)
6      阵法等级      100           (九项或更多)
7      计谋等级      100           (五项或更多)
8      特殊技能      100           (五项或更多)
9      忠诚          100           (对本国是忠诚，对他国是关系)
10     官职          9             国王
玩家阶段：玩家的整个过程可分为以下阶段：
1 初级：成为角色但未能当官之前
2 中级：地方官员
3 高级：地方首领或朝廷(国家)官员
4 顶级：成为国王
玩家在不同的阶段其目标，任务与策略都不会相同。
1 初级：
目标：早日当关。
任务：种田、砍柴、放羊、挑水等(初级工作：挣钱用于学习)
送信、送货、守门、打探等等（中级工作1：提高忠诚度，声望，地区贡献）
当官的基本条件：
1 基本技能等级全部大于30
2 地区贡献大于10
3 声望大于10
4 忠诚(对某国的关系)大于50
基本公式：
工作类别   回报        大约时间 最短间隔时间 最多重复次数 条件
初级工作   10silver   1-5min   1 min      5(每天)     当官前
中级工作1：地区贡献 1  1-5min   1 min      5(每天)     当官前
          声望 1   
          忠诚 2
解释：
1 最多重复次数是指具体某一项工作而不是某一类。
2 取消水境的给钱功能，每一分钱都必需自己挣。
3 对于player取消声望忠诚自动增加功能，相反要让声望自动降，如果长时间不
 上线声望就会降到很低从而丢掉官职给新玩家让位。
5 新手进入学习基本技能的学费约 150 silver 所以大约需要干15次初级工作
  可以挣够学费
6 新手大约需干10次中级工作1达到当官的最低要求。


---
作者: Row
题目: fomular for job
日期: Tue Nov 10 00:26:51 1998
  Basic fomular for job system in SanGuo

  Job category 1: provided at the starting status

  Requirements: none

  Rewards: 1000 * ( N - n ) + 100 * random(10)

  Purnishments: none

  1000: basic currency unit
  N: total lenth of time limit
  n: time used by player to finished the job

  Note: if N = n, ( N - n ) part will not be counted.

  eg: If a player finishs his job in 4 mins (he was asked
  to finish it within 6 mins, or we can count it  as  mu
  day in order to be more realistic), his rewards will be:
  (random(10) assumed to be 4)
           1000 * ( 6 - 4 ) + 100 * random(10)
         = 2000 + 400
         = 2400
         = 24 silver

  Job category 2: provided when a player becomes a char.

  Requirements: player as a char.

  Rewards:
  1. Money: 2500 * ( N - n ) + 100 * random(10)
  2. Loyalty: 2 * ( N - n ) + 1 * random(3)
  3. Reputation: 2 * ( N - n ) + 1 * random(2)
  4. Local distribution: 2 * ( N - n ) + 1 * random(3)
  5. Skill point: 5 * ( N - n ) + 1 * random(2)

  Purnishments:
  1. Loyalty: 2 * random(5)
  2. Reputation: 2 * random(3)
  3. Money (optional): 1500 * random(4) + 50 * random(5)

  Job category 3: provided when a player becomes a med-
  ranked officer.

  Requirements: player as a med-ranked officer, loyalty
  80+, reputation 200+, local distribution 300+, skills
  lvl 20+.

  Rewards:
  1. Money: 10000 * ( N - n ) + 500 * random(10) + salary
            * random(2)
  2. Loyalty: 2 * ( N - n ) + 1 * random(3)
  3. Reputation: 4 * ( N - n ) + 2 * random(3)
  4. Local distribution: 4 * ( N - n ) + 2 * random(4)
  5. Skill point: 10 * ( N - n ) + 2 * random(4)

  Purnishments:
  1. Loyalty: 2 * random(8)
  2. Reputation: 4 * random(5)
  3. Money (optional): 5000 * random(8) + 250 * random(5)

  Job category 4: provided when a player becomes a high-
  ranked officer.

  Requirements: player as a high-ranked officer, loyalty
  100, reputation 2000+, local distribution 3000+, skills
  lvl 60+.

  Rewards:
  1. Money: 50000 * ( N - n) + 3000 * random(10) + salary
            * random(3)
  2. Loyalty: 3 * ( N - n ) + 1 * random(4)
  3. Reputation: 10 * ( N - n) + 5 * random(5)
  4. Local distribution: 10 * ( N - n) + 5 * random(8)
  5. Skill point: 20 * ( N -n ) + 5 * random(8)
  6. Misc (optional): certain special objects.

  Purnishments:
  1. Loyalty: 5 * random(10) + 1 * random(5)
  2. Reputation: 10 * random(10) + 1 * random(10)
  3. Money (optional): 25000 * random(10) +1500 * random(10)
                       + salary * random(2)
  4. Misc (optional): certain special objects.

  Job category 5: provided when a player becomes mayor or
  jeneral of a city.

  Requirements: player as mayor or jeneral-ranked, loyalty
  100, reputation 10000+, local distribution 15000+, skills
  lvl 90+.

  Rewards:
  1. Money: 100000 * ( N - n ) + 5000 * random(10) +
            salary * random(4)
  2. Loyalty: 5 * ( N - n ) + 2 * random(4)
  3. Reputation: 20 * ( N - n ) + 10 * random(5)
  4. Local distribution: 20 * ( N - n ) + 10 * random(10)
  5. Nation distribution: 10 * ( N - n ) + 5 * random(5)
  6. Skill point: 40 * ( N - n ) + 10 * random(10)
  7. Misc (optional): certain special objects, certain
                      city.

  Purnishments:
  1. Loyalty: 5 * random(10) + 1 * random(10)
  2. Reputation: 20 * random(10) + 3 * random(10)
  3. Money (optional): 50000 * random(10) + 2500 * random(10)
                       + salary * random(3)
  4. Misc (optional): certain special objects, certain city.

  Job category 6: provided when a player becomes a king.

  Requirements: player as a king, reputation 50000+, local
  distribution 100000+, nation distribution 10000+, skills
  lvl 120+.

  Rewards:
  1. Money: 500000 * ( N - n ) + 20000 * random(10) +
            salary * random(5)
  2. Reputation: 50 * ( N - n ) + 10 * random(10)
  3. Local distribution: 40 * ( N - n ) + 20 * random(10)
  4. Nation distribution: 20 * ( N - n ) + 10 * random(10)
  5. Skill point: 100 * ( N - n ) + 15 * random(10)
  6. Misc (optional): certain special objects, certain
                      title from the emperor.

  Purnishments:
  1. Reputation: 50 * random(10) + 7 * random(10)
  2. Money (optional): 250000 * random(10) + 10000 *
                       random(10) + salary * random(4)
  3. Misc (optional): certain special objects, certain title.

  Note: For there are many ranks in SanGuo, so in each category,
  we could plus 1 to ( N - n ) for a higher rank.  Same manner in
  purnishments.

  As I do not understand other fomular in SanGuo very well and
  my mathsmatics is also not good :P, this fomular may be too
  simple or unreasonable, so I only provide my idea, hope some-
  one else could optimize it. :)


---
作者: Fire
题目: supplement for the job system
日期: Fri Nov 13 19:07:54 1998
Supplement of the Job
Two more tasks.
for the Daemon we need a menu to operate with the daemon database(
such as insert, delete, modify and check)(Flee's work)
For the module we need a cmd used for player to check the current
job situation and history record. (Fire's work)


---
作者: Ultra
题目: stefan 是否可以作成对npc做动作得,
日期: Tue Nov 17 15:06:45 1998
chat* kick xxx之类得
比较有意思


---
作者: Fire
题目: depromote wizard
日期: Sat Nov 21 01:46:08 1998
bamboo    竹竿      巫师  离线：三十天           202.98.119.215
according to wizrule
bamboo is depromoted to player


---
作者: Ultra
题目: 关于任务系统.
日期: Sat Nov 21 07:44:33 1998
以下是我个人关于任务系统的一些想法,希望大家提出可行的方案共同讨论.

一.强迫性给任务:

当玩家做官以后.所谓当官不为民做主不然回家卖田薯.
由领导者会在一定时间内分给你一定的任务,同时也可能
通过一定的游戏过程产生一定的任务.
如:
  投票通过了"开仓放粮"的建议后,这样管理内政的玩家就可以被
分配到"开仓放粮",这个工作,只要完成就有奖励,如果主管这个项目
的玩家不在,或者不接受这个任务,这样其他玩家就可以申请这样的任务
如果玩家很久没有接受任务,这样的话就会被降等级.反之就有奖励.

这样给任务的方式一般是根据玩家的等级和玩家的官衔来划分.做的官
越大完成的任务就也高级.如果玩家做大官还可以把任务分派给自己的手下
反正功劳还是自己的,当然如果任务失败的话,可能就会被惩罚.

这种方式也可以主动申请,ask 领导 about work.当然也可能出现目前没有
事情出现处理的情况.这样要求玩家可以主动的通过某些决议来增加自己的
工作能力.
工作任务方式:
   
   工作描述:	即需要完成的工作
   要求条件:    即只有某些人才可以完成的限定条件
   时间    :	需要在多长时间内完成
   完成条件:	可以是一个函数指针,以判断是否完成.
		或者是
                "条件" : "数值"
                这样的结构,
                只要条件"变量"="数值"就表示满足.

  
   基本上如果是任务相关的使用"quest/work/变量",这样只要完成判断这
些变量就可以.


1.领导自动给工作
     (1).接受工作
         <1>.自己完成.
         <2>.让自己手下完成.如果是将工作转派,则完成工作后,将要把完成的
            条件，结果设定到玩家本身,也就是可以做成,你的手下完成后
            回来见你,或者报告完成情况,这样变量就复制到你自己身上. 
            一旦完成后,你去见君主,君主就可以给你奖励.

     (2).拒绝工作
         <1>.无人接手
	 <2>.要求接手该工作

     领导也可能强制要求工作,这样只有接受 


2.通过决议,领导提出工作,这样的工作可以是所有人都可以接手,或者是固定某些人
   可以做的.
      (1).主动提出要求工作.
      (2).被指派工作.  
二.传统任务
一般我们打rpg.大概建立在这样的运行轨迹上.

1.拿某物给某人,交换某物或者信息
2.替某人做某事,满足后会得到信息或者东西
3.自己完成某事,可以得到东西
4.和某人配合完成某事,共同得到某物或信息

大概得对应任务如下:

    拿某物给某人:
                ask sb about st(what are you want)
                这种方式与fy的quest基本相同	

                "物件名"   :  某人需要的东西
                "时间"     :  完成任务的时间

                fy中基本上都是固定一个人来接受所给的东西.但我想在这里只要
		继承QUESTS的npc都可以.

    消息的获得:
                消息在Mud中非常重要,如果发生一些事件,可能玩家不一定知道,
                这样在mud中做一个专门提供消息的人.
                当事件发生后,就把消息放在消息库中.
                 
                 例子:
                      Npc allknow(天知道)
                    
                      一个npc(lu bu)拿到了宝物(bao wu),这样系统将lu bu 拿到
　　　　　　　　　　　宝物的消息存入信息库中。同时将附件的某个char的
id存到信息库


                      一个玩家．
                      ask allknow about bao wu
　　　　　　　　　　　(系统开始寻找在线的char,或者寻找靠lu bu最近的c
har,或者根据
　　　　　　　　　　　信息库中的char) 得到一个id,
                      allknow 告诉你　char 可能知道这个消息．
                      玩家找到char后
                      ask char about baowu ,这样char 就根据数据库得
数据告诉玩家．
                      当然也可能将这个信息转给另一个char.这样玩家就
需要在寻找下一个
　　　　　　　　　　　char .知道完成．

                      "问题"     :   玩家ask xxx aobut 问题
                      "答案"     :   返回给玩家得答案

      连锁任务:
                 要建立一个递归的结构．这样玩家完成每一步就可能从目
前的char得到下一个
		 任务.只要把任务apply 给下一个char,这样就可以接着完成任务．


      替某人做某事:
                 
                 ask npc about can i help you 
                 npc告诉你，老江欠我五十两银子你帮我拿回来吧．这是借据
                 npc give u jieju 
                 go laojiang 
                 ask laojiang about 还钱   
                 give jieju to laojiang
                 laojiang give u 50 silver
                 goto npc
                 give 50 silver to npc
                 npc tell u goto xiaman u can find ultra
                 恭喜你，任务完成．

                 以上是一个例子，主要是看任务的设计，要设计成什么方式而已．
   

      自己完成某事：
                
                 象原有的想法
                 种田、砍柴、放羊、挑水等(初级工作：挣钱用于学习)
                 送信、送货、守门、打探等等 之类的。

 
       配合完成：     

                 需要两个或两个以上得玩家，再一定时间内同时完成．由于条件方面
　 　　　　　　　得限制，一个玩家可能不能同时完成两个相关得任务，这样得话如果
　   　　　　　　和其他玩家配合,这样就更有意思，也就更容易融合，成就敢更强．

                
信息的重要性：

       mud中有一个核心的信息库存放的是各种的信息.
       每个玩家得到一个信息，可以放到自己得信息库中．
　　　 这样得话，玩家就可以买卖信息．
 
                "标示"      :    "具体内容"

       ask ultra about "标示"
          <1>.Ultra估计对"标示"也没有什么认识
          <2>.这条信息估计要价100 gold

       price "标示" 1000 (1000为钱，单位为coin,这样再做转化)
          为消息定价

       buy "标示" from ultra
       sell "标示" to mm

       buy要seller同意，也就是seller要做出sell才有效．但以buy得时候定价为主．



---
作者: Fire
题目: a wiz application
日期: Sun Nov 22 19:11:40 1998
fire
    我是一个专业程序员，主要负责程序编写及项目管理工作。使用的开发工具
是VC5.0.我自己家里有一台电脑，目前安装的操作系统是linux,不过只是在摸索
过程中。我玩mud主要是在中网的es2,不过现在已经不去了，在那里的id 是xyk.
目前由于我负责几个项目的实施，所以工作比较忙，每天大概可以有1到1.5个小时
的空闲时间，另外星期天也可以。
    主要情况就是如此,谢谢。
以前已经发过相同的内容，由于一直未收到回音，所以重发一次。另外，我在
玩的时候发现声望一直为0，可又没有可以增加的办法，开会，捐赠都必须做官
以后，平民好象目前没有办法加声望，请指教。（守城门不行）
                                HU JIONG

what are your guy's ideas ?
please


---
作者: Fire
题目: JOB系统设计规范
日期: Sun Nov 22 20:39:58 1998
目前最紧迫的任务之一就是JOB系统。FLEE已经完成了三个
JOB，我也写了一个，另外ROW也正在着手一项JOB。JOB将
成为本MUD最为重要的系统之一，为保证JOB系统的公证，
完整与平衡，现设计以下规范，在设计新的JOB时，希望遵守
规范，对于已完成的JOB如果不合乎规范，在改动不大的前题
下，请修改使之遵守规范。
规范文件在 /help/wizard/sanguo/jobrules
请用help jobrules查阅


---
作者: Fire
题目: about the wizard committee
日期: Sun Nov 22 21:30:22 1998
the plan of the wizard is announced more than one week
seem nobody respond and commont on it. is this silence
means support or against ?
I hope all wizards can be active to the development
and the management of this MUD  too.
wake up, all. If your guys continues keeping on
silience I will assume you all support what I have
planed. :)
so please don't regret later :)


---
作者: Fire
题目: a new wizard application
日期: Mon Nov 23 18:22:16 1998
申请成为巫师
姓名：LaoDa(在mud中）
性别：男
年龄：29
学历：大学本科
外语：英语，大学里考过四级六级，但这些年的工作都是与日本人打交道，英语
　　　自然退步不少，另外懂日语，可能对你们没什么用．
软件：自大学毕业以来，一直从事编程工作，精通UNIX，精通C，C++。当然也做过
      不少别的，象VB，FORTRAN之类。
目的：不太了解MUD是台何编出来的，因此想好好学习一下，所以才提出此申请。
上网：每天可用于贵MUD的时间大至不少于3小时，除了节假日。
三国：当然精通了。更精通历史上真实的三国。
EMAIL：yulei@eastmail.com


---
作者: Lei
题目: re last application
日期: Tue Nov 24 01:26:50 1998
All applications sound very nice... However, we know there are 
only a few good wizards...

maybe we should promote them as temp wizard... 1 month later evaluate their
work and give final
decision, ok?



---
作者: Fire
题目: about the job
日期: Mon Nov  2 19:50:44 1998
关于三国的设计方向：
本三国是一个全新的MUD，除了采用不同的MUD LIB外，最主要的特点是游戏概念
的创新。
不同于以往的武侠类与解迷类MUD，本MUD的侧重点是“动态”和“合作”。
以往的MUD，重点在于个人的修养。例如西游记，对于一个玩家，最要紧的是
个人的道行，武功等级，法力，内力等等。个玩家之间处于相对独立的状态。
一个人只要足够聪明，发愤苦练就可以成为一代大侠，玩家间的友谊，摩擦
往往出于个人的喜好，与游戏的角色没有太大关系。但在此MUD我们在保留
个人参数的同时，重点强调地区和国家的参数。作为一名玩家，不仅需要努力
提高个人的各项等级，更重要的是提高地区与国家的实力。这样属于同一国家
的玩家就会有长久而紧密的关系。同时为了维持一个强大的国家，单靠一两个
玩家是不行的。玩家间的团结与集体智慧是成功的关键。
因此，在本MUD中的高手将不会那些会找BUG会写程序的ROBOT而是能够协调
团结本国玩家，同时又能周旋于个敌对国之间的具有战略与外交才能的真实玩
家。
为了实现这样的游戏设想，我认为：任务系统主要适用于低级和中级阶段，
等玩家到了高级阶段，要么是国君，要么是重臣。这时那些个人参数的意义将
会相对减弱。而最主要的工作是管理下级官员，开疆阔地，早日统一。
关于ROW设计的任务系统，我基本赞同。希望ROW能够给出一个各项参数的有
效范围以及个类任务对个不同参数调整范围等较具体的数据与公式。


---
作者: Tset
题目: >wizlist
日期: Mon Nov  2 18:29:51 1998
On Wed Oct 28 05:17:48 1998 Lei wrote post #233:
> Could any1 write a wizlist?
> Since we promote and depromote wiz often... We can't tell who is wiz by
> typing ls /wiz leh...
> 
i added the wizlist to /cmds/player, this is a temporary
solution only, and this command takes some time to run,
this is the scale down version of listuser, which scans
all user data (note listuser is wiz only command now).


---
作者: Row
题目: ideas -- about job system
日期: Mon Nov  2 18:10:51 1998
在三国MUD 中，工作系统（也可称为任务系统）尤其重要，因为三国不会如同
其它武侠游戏那样将大部分精力花在练功比武上，所以我们为玩家提供的工作
系统必须非常周密、完备以及丰富，而且需要根据玩家的发展过程不断的调整
及变更，以配合玩家的脚步。我认为三国中的工作系统必须与官阶系统、战争
系统、学习系统等紧密地联系在一起，以下是我对工作系统结构的一点设想，
供大家参考、讨论。

当玩家刚进入三国世界的时候，可以说是身无分文、默默无闻，所以可先设计
些初级工作使玩家对这个游戏有些初步的熟悉。设想中会将华阴村作为玩家的
启始地点，不联结任何城池，也就是说是一个独立的地点。只有当玩家在华阴
村内达到一定等级，方可离开到外面的世界去闯荡。初级工作可以参考三国时
代的历史，让玩家从最低阶级的佃农或者乡勇做起，种种田、砍砍柴、放放羊
什么的，从中赚一些钱，以便到学堂中学习一些基本的技术，例如初级的兵法
及战术等，或者是到训练所（应该有个更合乎历史的称呼）中去学习基本的武
艺，枪法、刀法等。也就是说，让玩家在初期为自己今后的发展方向定下一个
目标——从文还是习武（我们可以将文武两种技能设计得互相克制，也就是当
玩家第一个学到的技能是文类的，再学武类的技能时就相当的困难，需要花十
几倍甚至几十倍的精力，也就使得他今后一直朝着从文的方向发展。当然他可
以弃文从武，而那时的损失就留待玩家自己权衡了。这样设计主要是不让那种
“文武兼备”的全才充斥整个三国，也为今后的分工打下基础。当然在如此设
计之后而产生的全才必定是花了相当的工夫的了）。等到玩家达到了所要求的
等级，便可以通过设在村内的驿站（路费相当昂贵哦！呵呵）去他们所希望去
的州郡进一步发展。

初级工作：

工作种类：种田、砍柴、放羊、挑水等（细节另定）
所需条件：无
工作回报：钱

当玩家到了他们的根据地，便可到当地的征兵所谋求一个职位，文，可以做门
客；武，可以做步弓手或马弓手等。那时的玩家尚处于提高基本技能的阶段，
所以这个阶段所能领取的工作也是一些比较简单的种类（建议在玩家属性中增
加“贡献”一栏，可分为地区贡献及国家贡献，为地区完成任务或工作便增加
地区贡献，而完成国家分配的任务就会增加国家贡献。“贡献”也将作为玩家
官位升降的评判标准）。

中级工作一：

工作种类：送信、送货、守门、打探等等（希望能有更多的种类）
所需条件：从政或从军
工作回报：钱、忠诚度、名望、地区贡献

当玩家经过一段时间提升自己的技能及各项属性，便可以升官了。而此阶段所
领取的工作也将相应提高难度。比如文官可以安排他在三天之内购买到一万石
粮食，当然这得与贸易系统联系起来，玩家必须调查哪里的粮价相对便宜，而
政府发给玩家的买粮钱只会少，不会多，那多出来的部分只能自己承担，买完
粮之后还必须负责押运回城，路上出了什么乱子的话又会吃不了兜着走。武官
可以安排他负责在三天内督造五百支弓箭，所需的木材及铁料都得自己一手操
办。

中级工作二：

工作种类：买粮、督造兵器等等
所需条件：等级超出中级工作一规定的上限
工作回报：钱、特殊物品、忠诚度、名望、地区贡献

玩家的官越当越大，工作也越来越复杂。此时将会指定玩家一个比较综合的目
标来让玩家完成。例如，指定玩家在规定时间内使得当地的农业开发度上升某
个点数，或者是在规定时间内将士兵的训练度提高到多少多少等等。

中级工作三：

工作种类：内政开发、征兵、训练、寻宝等等
所需条件：超出上一级工作规定上限
工作回报：同上

当玩家的官够大，掌握了一定的兵权以后，就会指使玩家去攻城拔寨，也就是
为你的国家卖命出力了，当然在前几个阶段中玩家也会参加战役，只不过都是
以附属的形式，而现在就可以以主将的身分开打了。而准备一场战役会相当复
杂，需要各方面条件的充分配合方可稳操胜算。

高级工作一：

工作种类：攻城拔寨、友好亲使等等
所需条件：担当高级的职务
工作回报：同上、国家贡献、赐城

玩家拥有自己的城市，就可以实行管理，这也是一种工作，其中的复杂自不待
言。等到玩家的实力够强（必须自己拥有二级以上的城池），便可以独立称王
称霸了，当然创业的初级将会非常艰辛，旧主将会不停的讨伐你，其它的国家
也会趁火打劫，不过这对你的霸业完成也是一种考验。等你立足已稳的时候，
你的主要任务就是分派那些你以前做过的工作，而东汉的皇帝也会不时地偈见
你，给你一些任务去完成，比如他认为哪国不听话，让你去讨伐；或者派你去
平息某国与某国之间的战乱；或者让你在规定的时间内上交金银资帛粮食物产
以供他吃喝玩乐；或者是让你去为他寻找某种听也没听说过的奇珍异宝等等。

高级工作二：

工作种类：皇帝偈见密令等等
所需条件：称王
工作回报：同上、赐爵封侯

以上便是玩家在三国中成长发展所经历的数个阶段及所接受的任务，当然现在
这只是一个相当粗略的框架，工作的等级等各方面有待进一步充实和完善。但
对于工作系统来说，比较低等级的工作平时就可以领取，而较高等级的工作必
须在某种特定情况下方能领取（比如在地区会议上）。所有的工作都不可以重
复完成，也就是说玩家完成了他的上一个任务，必须休息一段时间（强迫的，
呵呵）以后才可以领取下一个任务，而且这个任务不会和上一个相同，因为我
们不能使玩家有机会可以做一些机器人之类的来玩三国，而且玩家完成任务，
得到了回报以后也必须有时间去修炼自己，所以如何将工作系统设计得合理完
备，需要我们的细心筹划和构思。

本人抛砖引玉，希望各位巫师能集中讨论一下这个问题。



---
作者: Lei
题目: wizlist
日期: Wed Oct 28 05:17:48 1998
Could any1 write a wizlist?
Since we promote and depromote wiz often... We can't tell who is wiz by
typing ls /wiz leh...



---
作者: Stefan
题目: >ideas(about money and channal)
日期: Wed Oct 21 21:02:37 1998
关于金钱，其实这里的人又不吃东西，没必要让新手都有钱在身上。
温饱问题已经不是问题了，钱只会用在兵器装备和其它军事用途上。
这就应该让玩家去做 quest 了，比如带兵平寇，征收粮草，就象太
阁立志传中，可以让主公给你钱去买粮，遇到好价钱，可以赚一笔。
通过帐户交易也是必需的，比如俸禄等，但是信用透支就大可不必了。有本事的去
借钱嘛。

另外，我想目前用谣言发布消息是比较合适的，如果每项信息都准
确的话，难度会降低的，而且有人假冒谣言挑拨离间也是可以容忍的。古时候的消
息哪会这么灵通，西凉刚沦陷，洛阳就收到消息了？虽然不可能在 mud 里做到时间上
的推迟，但是让消息传播的渠道有一定的水分，并不过分。要想确认
某件事是否真实，可以问在场的其他玩家，或者派探子打探都可以。


---
作者: Group
题目: re 204
日期: Wed Oct 21 20:58:14 1998
need thank me first, it is me who catch nono from xkx...
grin


---
作者: Fire
题目: new wizards
日期: Wed Oct 21 16:30:32 1998
now we have a new wizards: nono
he is pretty good at the history of sanguo
so I am sure he will contribute a lot in this mud
let's give him(her?) a warm welcome
xixi


---
作者: Row
题目: ideas(about money and channal)
日期: Wed Oct 21 03:58:25 1998
关于金钱：

现今许多MUD 新手刚登录的时候是两手空空的，必须向老玩家
要或者通过打工什么的来赚钱，这两种方法相对而言都比较麻
烦，所以在这里我们放了一个水镜先生，使新玩家可以讨钱，
但是这隐含着一个trick ，也就是某人可以登录无数新人，讨
钱，然后将所有的钱都交给一个id，这样很快那个id就会变得
相当富，要知道钱在这里是非常有用的，那样的话，这个使用
trick 的id会占很多便宜，而久而久知，很多玩家都会知道这
个trick ，然后。。。。呵呵，我想，这也就是为什么侠客行
取消了歆手登录后钱庄存有10 silver 的主要原因吧。所以，
为了防止这一点，我建议取消固有的财政制度，采取先进的划
帐、信用制度，也就是说，取消实在的金钱，所有的买卖都只
是在你的钱庄帐户里划帐，当然帐户里没钱的时候就不能进行
交易了，这样一来，我们还可以考虑透支，如果你的信用度够
好的话。那么是不是钱庄的存在就不必要了呢？不是，我们可
以让玩家只有在钱庄的时候才能查帐，还可以让玩家进行短期
贷款等等，总之以后玩家之间就不会发生任何金钱关系了。任
何的交易都可以通过划帐来进行了，虽然这是一个比较现代的
方法，但不失为一个方便的窍门。

关于系统发布的信息：

现在一般系统发布的信息，比如某人升迁，开地区会议，发生
战争什么的，都会以谣言的形式发布，但玩家是可以使用谣言
频道的，如果有些无聊的玩家利用这点发布假信息的话，可能
会造成其他玩家的损失。设想一下，当你正在遥远的蜀地修行
的话，突然看到谣言说自己的都城洛阳要打仗了，可当你巴巴
地赶回去的时候，却发现风平浪静，这真的是一个谣言！你会
怎么想？是不是很气呀？所以，我建议将所有这类的信息归到
一个玩家不能使用的频道发布：如：【三国志】诸葛亮被封为
四川军师。这样就不会造成混淆了，当然，以后也就不存在用
谣言来破坏某些机器人的行动了，但我想，这样做的好处还是
大于坏处的，而且总会有别的办法对付机器人的。

以上建议可否施行，希望各巫师同仁发表看法。


---
作者: Fire
题目: about thw warroom.c
日期: Mon Oct 19 19:07:49 1998
each area has a warroom.c please becareful
don't delete it


---
作者: Stefan
题目: lib broken
日期: Mon Oct 26 16:51:54 1998
machine crashed, and last backup is not new enough.
Fire, if you can fix it, just try your luck, otherwise, I will
replace data file with old ones from the backup.


---
作者: Stefan
题目: >lib broken
日期: Mon Oct 26 17:00:37 1998
On Mon Oct 26 16:51:54 1998 Stefan wrote post #230:
> machine crashed, and last backup is not new enough.
> Fire, if you can fix it, just try your luck, otherwise, I will
> replace data file with old ones from the backup.

It seems very strange to me that countries.o actually contains
data from an empty troops.o, while troops.o contains gabage data.

I replaced countries.o with the backup on 22nd September. And cleared
troops.o to empty.

Any recently updates to countries.o since 22nd Sep has been lost.
Sorry for this, I should keep a backup every week.

stefan


---
作者: Fire
题目: good job flee
日期: Tue Oct 27 16:27:44 1998
flee has done very good job
addoil all
I am sorry that i have to prepare my exam
so can just come here for idling and fix bug
I will be free after exam (if i can pass them)
then will be a long holiday, very nice
addoil all
sorry for the delay


---
作者: Stefan
题目: verb parsing
日期: Thu Oct 29 03:56:23 1998
I did a heavy investigation to the driver's verb parsing machenism,
and finally conclude that it is NOT THE RIGHT WAY of handling this.

I will rewrite all verbs, and all other wizards, please do not make
changes to verbs from now on, until this rewriting is finished.
The estimated time for this is 1 month, because my parents are
coming to visit me, so my time are booked by them :P 

Sorry for any inconvenience it may cause, and thanks for coopration!

stefan


---
作者: Fire
题目: >verb parsing
日期: Thu Oct 29 16:56:37 1998
how about the cmd ?
i mean the command in /cmds/player and /cmds/wiz and /sgdomain/cmd ?
where those affect your work ?


---
作者: Stefan
题目: >>verb parsing
日期: Fri Oct 30 23:03:17 1998
cmd will not affect my work.
I will try to do it at another place, after it is stable,
I will merge back changes to here.


---
作者: Fire
题目: welcome new wizards
日期: Wed Oct 14 16:36:30 1998
Now bamboo has been promoted as a new wizard
welcome and hope a nice time



---
作者: Fire
题目: depromote wizards
日期: Wed Oct 14 16:31:32 1998
ryan      中文      巫师  离线：四十四天         newgate.mitel.com
according to wizrules
ryan has been depromoted to player

fire


---
作者: Row
题目: to group
日期: Fri Oct  9 06:36:27 1998
group, check your mail (in lima) please.


---
作者: Stefan
题目: fire.h
日期: Wed Sep 30 05:31:19 1998
Last crash was due to a careless editing of /include/mudlib.h
I believe fire added fire.h to mudlib.h, but in fire.h, there is
a Macro definition of min and max, which conflicts with simul_efun
definition of min & max in simul_efuns/misc.c 

Note that mudlib.h is a system wide include file that used by all
programs, even a small conflict there will cause everything to hang.
I've removed "fire.h" from "mudlib.h", simply because "fire.h" is only
San Guo specific including file, it is not a system wide thing.

It is obviously a simple thing to add 'fire.h' to 'mudlib.h' so as
to avoid "#include "/wiz/fire/fire.h" everywhere. But, please remember
good structure always comes before convenience consideration.

I also suggest that fire.h shall have another name, for example,
"sanguo.h" and shall be moved to /include instead of fire's own dir.
It is already used heavily under every sanguo related code, not only
fire's own including file already.

By removing 'fire.h' out of 'mudlib.h', some code may be broken, 
all wizs please check if anything is wrong...

stefan


---
作者: Lcm
题目: trade + ideas
日期: Mon Sep 21 11:40:29 1998
Design for business
-------------------

goods to trade:
horse, bow, rice(food)

Objectives
----------
1 allow country or area to manipulate their resources
2 allow player to improve their skills and reputation

Other ideas (optional)
3 use traders to distribute quests (sell quests)
4 combine with a bandit system, goods can be stolen by 
  bandits in the area
traders will request the help
  to retrieve the goods -> initiate a war to bandits


Details
-------
only areas that are level 3 to 5 have traders

nw - longxi, xiliang, tianshui
nc - qinchuan, anding, xianyang, jingyang
c  - changan, hongnong, luoyang
ne - taiyuan, shangdang

The areas are grouped into regions
to facilitate the traders route.
Each trader in general will visit each region in random order
and then visit each area in the region in random order

due to a higher demand of goods sold by the trader
certain areas are avoided because of war or the safety level
is low - bandits)

we may allow the adjustment of traders frequencies to test
the system, whether there are sufficient traders.

When each trader moves to a new area, their new location
will be announced.
Officers (players) in the area can ask for a local meeting
to decide whether to sell or buy certain goods.
In the meeting, the officers will vote whether to approve
the suggestion, if approved, the player who suggests will
get the task. 
and how much goods

Once approved, the trader will be summoned to the meeting place
to begin the trading.

The trader can be classified into 2 types:
- money-minded 奸商
- normal

Each trader may deal with only 1 type of good or all types.


For the money-minded, his selling price quote is always high
price may be based on the demand for the good, the safety
level and the finance of the area.

The player can accept the price. (Trade done)
or refused and suggest another price.
If the suggested price is low, the trader may left (Trade incomplete)
If price is close to trader price, trader may accept (Trade done)
otherwise, trader will give player a second chance.

The player should now suggest a price in-between. (normal to high)
The trader will consider this price based primary on your
negotiation skill(we can use meili) and also other factors.

If trader accept new price (Trade done)
If refused (Trade incomplete)
--- Trade over ---


For the normal trader, his selling price may be high or normal
price based on demand for the good, the safety level

The player can accept the price. (Trade done)
or refused and suggest another price.
If the suggested price is low (selling price normal), or
if the suggested price is normal (selling price high),
the trader may left and refused to come back for a year
Trade incomplete, -> player is auto-demoted

If price is close to trader price, trader may accept (Trade done)
otherwise, trader will give player a second chance.

The player should now suggest a price in-between.
The trader consider this price based primary on your
negotiation skill(a lesser factor this time)

If trader accept new price (Trade done)
If refused (Trade incomplete)
or refused to come back for a year (price is not close)
 -> player is auto-demoted
--- Trade over ---

Optional scenario after trade done:
Leader ask for any other matter.
If another player thinks the price is too high,
he can lodge a complain to the leader to demote the first player(buyer)

The leader figures out the finance condition and the price
and decide whether the price is indeed too high.
If it is, the player(buyer) is demoted (this will not apply
 to a player that uses the second chance to agree on the price)
If it is not, the player who complains may be demoted

--- Complain over ---

Benefits, punishments

accept immediately - reputation up, trader give a quest
trader accept 1st quote - reputation, meili up
trader accept 2nd quote - reputation, meili, zhimou up
trader left - reputation, meili down
demoted(auto) - reputation drop a level, meili, zhimou down

--- ---

The traders may now sell the quest
ask trader about quest

Quite similar flow if player sell goods to trader

Do we have a quest system now?
How about bandits? (Player can be bandits)

lcm


---
作者: Stefan
题目: >help
日期: Mon Sep 21 22:22:51 1998
It is not a bug in your fire extinguisher, it is the problem with
current verb parsing system. You have to specify "first" "second"
object when there are more than one in the room.

I will redo the verb parsing system, dunno when can finish.


---
作者: Stefan
题目: >trade + ideas
日期: Mon Sep 21 22:31:38 1998
Lcm's plan says: price is determined by the regional demand of the
goods, and safty etc. I think can also add in another factor,
that is the trader's own 收支平衡。 If they trader has many to sell,
he would offer it at
a lower price, if he has already sold a lot, he would not care to
negotiate already.


---
作者: Stefan
题目: wrap to be disabled?
日期: Mon Sep 21 22:49:25 1998
Because wrap is unable to wrap colored text correctly, should it
be disabled? Anybody is using wrap now?


---
作者: Fire
题目: support stefan
日期: Mon Sep 21 22:50:13 1998
disable wrap is a great idea


---
作者: Tset
题目: >wrap to be disabled?
日期: Wed Sep 23 23:55:48 1998
i remember wrapping tends to add an indent after the
first line, which used to give me great troubles in
simpterm :( 


---
作者: Fire
题目: re fire.h
日期: Wed Sep 30 20:55:01 1998
It is my mistake to make the system crush
I appology for my mistake
now i have done the following thing to
solve this problem. hope it will not cause
further problem
1 i cp fire.h into /include as sanguo.h
now the fire.h just include one sentence
#include <sanguo.h>
2 since min and max are function in misc.c
so i rename the macro min and max as bmin and bmax
3 i still make the mudlib.h inherit sanguo.h
the reason is that :
a we can use the macro in sanguo.h in cmd line
that will be very nice for testing
b some files may need the macro in sanguo.h
to work properly, now we don't have time
to correct them all
c in order to avoid the same problem
again i suggest that we don't add anything
in the sanguo.h. and when we have energy to
arrange the code then we can move the macros
in the sangou.h to the suitable place


---
作者: Flee
题目: how can force a npc do a command ?
日期: Sun Oct  4 02:10:36 1998
seems do_game_command, do_game_commanda and force_me
functions do not apply for npcs.


---
作者: Fire
题目: network problem
日期: Mon Oct  5 02:57:11 1998
hi every one
I should make the player can fight
in the war already, but recently
i am pretty busy, and our university
has install new firewall software
so sometime i can't access the internet properly
sorry for the delay


---
作者: Flee
题目: ask responda
日期: Mon Oct  5 03:33:51 1998
i find that for some cmds in /cmds/verbs and /cmds/player
do not apply for the function responda.
such as go.c 
why and how can sovlve it ?


---
作者: Fire
题目: re: about the responds
日期: Mon Oct  5 21:31:31 1998
that is true for responda it has its limit
because it need the shell to parse the command
and then run it. some time may cause conflict with
the system secure. so in order to make the npc
act, the best way is to call the action function
directly
for example if you want an npc to go to some place
just call
ob->do_go_somewhere(str)



---
作者: Fire
题目: about the move of npc char
日期: Mon Oct  5 21:36:15 1998
now i make the npcchar also inherit 
m_smartmove so it can move now
> @CHAR_D->find_char("benben")->responda("go out")
小东西朝外面离开了。


---
作者: Flee
题目: help
日期: Mon Sep 21 04:39:38 1998
there a bug in fire extinguisher.
for example, if two person, each of them bring an
extinguisher, when one of them try to turn it.
the driver will ask him ' which one u want to turn'
seems that the two is on one person.

why ?


---
作者: Flee
题目: can not learn jbhj
日期: Sat Sep 19 09:04:11 1998
in the daemon "/daemons/learncheck_d" does not have
that choice, learn jbhj is prohabited now :(.

can fire add this.
thx


---
作者: Fire
题目: start war
日期: Tue Sep 15 00:49:37 1998
now i modified part of flee's map_d and move it to
/daemons 
this file is used to handle map part of the war
the room part will be handle by
/sgdomain/modules/war_grid.c (hasn't finished)
we still need troop_d.c to handle the troops
and many works in task_d.c
addoil all


---
作者: Flee
题目: about war
日期: Mon Sep 14 09:38:24 1998
have a look at /wiz/flee/txt/war1


---
作者: Fire
题目: depromte wizs
日期: Mon Sep 14 02:23:48 1998
according to the wiz rules
testing, softwind and shaoyng are
depromote to player for not appearing for more than
30 days


---
作者: Fire
题目: i find a mud with 598 players online, what a world
日期: Wed Sep  9 05:53:25 1998
donot know if our system can support so many ppls


---
作者: Stefan
题目: plan on DMS
日期: Tue Sep  8 09:53:28 1998
Document Management System (DMS)

DMS maintains 4 kinds of documents:

1. posts on bulletin board. (currently we call it news)
2. mails of every players.
3. help files on specific topics.
4. help files automatically generated from source codes.

DMS has a completely different presentation from current system.
DMS will work with documents written in Simple Markup Format.
DMS enables documents browsing on WWW.
DMS is easy to update, and easy to maintain.

(I). User Interface.

    1. User type 'bbs' to read bbs, 'mail' to read mail, 'help' 
       to browse 'help', or type 'dms' to go to DMS directly.

    2. Generally, DMS behaves the same way as current help, but
       it will show ⑴⑵⑶⑷⑸⑹⑺⑻⑼⑽⑾⑿⒀⒁⒂⒃⒄⒅⒆⒇
       to mark any "links" the user can follow. (just like HTML)
       On one page, 20 such markers should be enough already.
       Users can type in digits to go to that link. Marked links
       will show up in BOLD so as to get attention.
       Therefore DMS will use a different MORE to view documents.

    3. WWW interfacing.
       DMS will has a CGI component that act as a document locator
       on the Web. Links will be shown as HTML links, and user
       just have to click to go on.

(II). Document Serial Number (DSN) & Markers.

    1. All documents will have a DSN assigned, so that it will 
       be uniquely identified by that DSN. DSN does not include  
       auto-generated documents, which will only use markers. 
       DSN is generally hidden from the presentation, but if a
       user wants it, he/she can still check it out and use it
       as a reference to existing posts/documents.

    2. Markers will have the form "<R=...> some subject </R>".
       Pure <R> </R> will only hightlights "some subject" by
       bolding the font. the ... will be the actual link, either
       a DSN or something of the form:
          POST/boardname/.../articlenumber
          HELP/player/.../help file name
          HELP/wizard/.../help file name
          HELP/admin/.../help file name
       Note that MAIL is supposed to be private and can not be
       referenced in the marker.
    
    3. Because of such markers, all documents will be wrapped
       automatically. In order to do a correct wrapping, two
       other markers are needed:
          <P>       another paragraph   
          <T> </T>  4-space indentation 
       All HELP files shall follow this format. 
       But for POST, especially for user's post, plain text is
       also acceptable. But once some text contains a marker,
       it will be treated as a MARKED text instead of PLAIN text.


(III). Documents Auto Generated From Source Code.
       In every program, you can write your own inline documentation
       that will be collected by DMS. In any program's comments,
       you write:

        //:MODULE
        //This is the description of this module.
        //$$ Note: helpsys style directives can be included
        //see: another_module

        //:FUNCTION funcname
        //This is the doc for function funcname

        //:COMMAND
        //This is the doc for the command

        //:HOOK
        //This documents a hook called with call_hooks

        //:EXAMPLE
        //This is an example to illustrate some code.

       When DMS goes to collect all inline documentations, it
       will automatically catergorize your comments into help files
       for modules, for functions, for command, for hooks, for  
       code examples etc. Actually, this is what current doc_d.c
       does. We (document group wizs) will help to add helps to  
       all commands in this way. But it will be really helpful   
       if you write such inline comments in any of your programs.


(III). Schedule.
    1. Write DMS menus & parsers.
    2. Make news & mail working.
    3. Write help files.
    4. Get inline docs to all commands.
    5. Get WWW cgi part working.

    2, 3 & 4 can be done at the same time. And we need more wizs
    to join us in writing help files. 5 has the lowest priority,
    let's finish 1 - 4 first :)

Any suggestions or comments?

stefan


---
作者: Stefan
题目: help files
日期: Sun Sep  6 22:06:14 1998
Welcome any of you to write help files, please put them in /help/player/
and make sure:
1. It does not confict with existing help file name, or you want to
    replace the existing one.
2. At the last line, add "last reviewed: <your name>"

We (me & yue) will review all help files after new document system is up.


---
作者: Tset
题目: back
日期: Mon Sep  7 04:00:37 1998
Wow, so many new messages, addoil everyone!
Just get back from my summer (my modem is too lag), seems
I will start shifting through all new changes.  So I
guess I would like to take responsibility for number 7,
七， 测试 , since I personally can't stand typos (being
as picky as I am) and bugs.  I will help out in the 
OBJECT (#4) and #5, maybe even #6, if I do find time
to do those.
The GRID_SERVER needs to add a lot, my personal idea is
to add associated points to each place, ie, 地形.  Maybe
even movement cost.  Otherwise, I suggest use such system
for most non-critical room development, and it is very
easy to make a maze out of it :).


---
作者: Fire
题目: the help
日期: Wed Sep  9 07:20:18 1998
I moved all the help file from sgdomain/txt/help
to /help/player/sanguo/
now most help files can be access from cmd help
and help 
for map and fly
there are some difference 
since if you use map and fly will display all the
help txt and the availiabel fly and map area
and they are dynamical so the help fly and help
area just display a hint info


---
作者: Row
题目: lvl 1 area all finished
日期: Fri Sep 11 02:25:31 1998
now all lvl 1 areas have been finished, including :
jieting, tongguan, hangu, didao, chencang.
please test.
now move to lvl 2 areas.:)


---
作者: Fire
题目: nice work, row
日期: Fri Sep 11 02:50:05 1998
addoil row


---
作者: Flee
题目: works
日期: Thu Sep 17 04:31:03 1998
i will write some place for ppl improve skill :)
and i want to access the /sgdamain/area/ so i can 
directly make changes.

thx.


---
作者: Fire
题目: flee is add to the Mudlib
日期: Thu Sep 17 20:38:02 1998
as title


---
作者: Fire
题目: 谁最近动ask.c 了？
日期: Fri Sep 18 09:08:25 1998
前一端时间我修改了ask.c使在问settle,position,
zgxy,bfxy and wxxy时实用恰当的汉语句子而不是简单
的 你向测试打听关于<settle>的消息。
但不知道谁把新的ask.c给删除了换了一个非常旧的版本
如果能找到新版本，最好换回来．
最后我要强调一点，对一个文件，不要做太多拷贝，有时
相互覆盖会很麻烦．
谢谢


---
作者: Fire
题目: about the help
日期: Sun Sep  6 08:41:22 1998
sorry, i move it to /help/player/newbie


---
作者: Fire
题目: about the rumor
日期: Sun Sep  6 01:02:08 1998
today, i disable the announce of the sender after a
rumor, since that extra announce make us disturbed
if in the future we find some guys realy always use
rumor to send nausty message then we can add this feature
back

cheers


---
作者: Fire
题目: about title
日期: Sat Sep  5 07:58:28 1998
the usage of cmd is a little confused
the first time i design it is because i don't
want to create so many verb or cmmd under /cmds
so make some new commend (especially those just used for
sg under) cmd.
now i find the cmd is easy to manay and document.
because you can use cmd list to list all the
cmd and use cmd help <cmd> to display the help file
and also it is related a little easier to write a new
command in this way. 
so i have a idea, in current stage we will not increase
more verbs( since we already have enough verbs)
chat* shake
if need some new commend just put it under /sgdomain/cmd
of couse this will make player input 3 more chars
but in this mud, player will not input as many cmd as
in other muds, this will not cause much unconvinent
the problem of title in menu has been fixed


---
作者: Stefan
题目: map in html :)
日期: Sat Sep  5 00:43:00 1998
This is a fantastic idea :)

Since we have HTTP server, and CGI can be wrote in LPC, why not
write a CGI that shows current sanguo map? which city belongs to whom,
how to go from one to another... We can even use some graphics,
some colors.

We can shift some of our mud helps/docs/queries to the web.

what do you guys think?


---
作者: Stefan
题目: about cmd
日期: Sat Sep  5 00:10:57 1998
I thought cmd is only meant for San Guo military/country related
commands. Things like 'cmd nick' should be directly 'nick' ba?

Also, is 'cmd' a temporary thing? Since we shall move towards menus.


---
作者: Stefan
题目: about title
日期: Sat Sep  5 00:03:16 1998
I feel that 字 something is not aproperiate. Old lima's title is flexible, 
and es2 style title is also okey. Actually I prefer es2 style.

Also, fire please be sure you changed all related stuff with title,
not only by removing command 'title'. for example, player can
still use 'menu' to set title, in which $N will still appear.


---
作者: Fire
题目: about the task
日期: Fri Sep  4 22:40:57 1998
use help tasklist to check the list of task
we have noticed that the following wizards don't have
register any task yet
yuner     云儿      巫师  离线：十四小时         delta.ntu.edu.sg
tset      苑璧      巫师  离线：二天三小时       128.42.75.29
ultra     少年街霸  巫师  离线：二天七小时       202.101.104.246
net       彩云深处  巫师  离线：二天二十三小时   165.91.210.69
benben    小东西    巫师  离线：三天十七小时     203.127.166.57
roc       至尊为吾  巫师  离线：四天十七小时     202.96.158.246
ryan      中文      巫师  离线：五天五小时       newgate.mitel.com
group     国题      巫师  离线：六天十七小时     leonis.nus.edu.sg
testing   名名      巫师  离线：二十二天         mirage.irdu.nus.edu.sg
shaoyng   猪香亭    巫师  离线：二十八天         141.217.54.11
softwind  和风      巫师  离线：三十天           202.99.8.123

hope you can regist a task within this month




---
作者: Row
题目: about title
日期: Fri Sep  4 09:15:13 1998
其实可以采用其他mud使用比较多的who模式:
单键入who, 只显示所有在线玩家的中文id及英文id,如:阿洛(row)  烈火(fire)
而键入who -l便列出所有在线玩家的简单信息,如:
【问鼎天下】  长安城左将军「天下无敌」阿洛 字「白夜」(row)
 (声望)  (所在及身份)(自定的绰号)(中文id) (字)  (英文id)

加入必要的ansi颜色加以区分,以达到醒目的目的.

键入who -w便列出所有在线巫师的id.
另外也可以增加其他的参数列出分类信息.

至于在room中的描述:
长安城左将军「天下无敌」阿洛

希望其他人有更好的建议.


---
作者: Stefan
题目: DMS report
日期: Wed Sep  2 22:15:55 1998
Currently, Yue & I are doing DMS (document management system).
Here is a short plan for all wizs to review:

TITLE: Document Management System
Hmm, let's classify those documents first, here are several 
categories I have in mind:
1. player commands help.  
2. General mud help.                                
3. San Guo help.
   This is specifically to this San Guo mud.

The above is for players, now for wizs:
1. Rules, regulations, notices, etc.
2. General help on mud building.
3. LPC help.
4. Lima specific help on functions, securities, etc.
5. San Guo construction reports/plans/progress/subjects/etc.   
    
Above are only meant for helps, now for general documents:
1. Code documentation. Coders should write it, but need us to remind them.
2. News archive. News system shall be rewritten to fit in with our 
   general document system. Currently News group will blow up soon
   when news become larger & larger.
3. Mail archive. Current mail system works fine already, but might
   need some changes in order to integrate together with the document
   management system.
Any good suggestions? What I plan to do is such a system that:
* enables user to quickly browse through documents of any kind,
  of course, depending on his/her privileges, and easy to make
  references.
* has a powerful search tool to get to answers of any problems.    
* will be something like HELP in Windows, but of course, we can    
  not have links for users to click, but we can do it in some
  other way, for example, use annotations such as ①②③ to mark  
  links, and user just has to type 1 2 3 to go to that link...

Addoil!



---
作者: Fire
题目: where is it
日期: Wed Sep  2 21:40:00 1998
stefan, what is the address for another sanguo


---
作者: Stefan
题目: just had a look of the other sg
日期: Wed Sep  2 03:15:56 1998
It is still LP mud. Descriptions look cool :)
Have not got time to play deeply, but already saw a lot of things
such as typos, simple errors, etc.

I feel pretty messy there. 


---
作者: Fire
题目: depromte wizards
日期: Tue Sep  1 03:02:03 1998
according to current wiz rules
pickle, super and testjig didn't come here
for more than one month without any reason
so will depromote them to player,
if they still want to work here as wizards
need to re-apply


---
作者: Fire
题目: new wiz
日期: Thu Aug 27 03:36:13 1998
now ryan is accepted as a new wizard,
welcome ryan
liz can't work here for some time
as he asked, we change him back as a player
when he has time and want to work here again
will re-promote him
addoil every one.


---
作者: Fire
题目: lei will be responsible to the 八， 宣传       
日期: Thu Aug 27 03:47:51 1998
addoil lei
hope to see your page soon
addoil lei


---
作者: Fire
题目: new wizard
日期: Sun Aug 30 20:11:45 1998
as lcm asked, we promote him back to wizard again
his first task is help row to do some area code


---
作者: Fire
题目: help for player
日期: Sun Sep  6 08:35:44 1998
now i begin to write help for players
the first one is /help/player/starts
can stefan suggestion will to put them and is there
any special requirement


---
作者: Flee
题目: about task
日期: Tue Aug 25 06:22:03 1998
i will will continue working at war system, but i am
very very busy now. MID-TERM EXAM and three project
which have to be finished by the end of next month :(
anyway, i will try my best to finish in the coming recess.


---
作者: Stefan
题目: >tasklist
日期: Tue Aug 25 05:10:39 1998
I would like to take the Person-In-Charge post for MUD OS 与底层MUD LIB
And also 文档整理。



---
作者: Fire
题目: tasklist
日期: Tue Aug 25 03:43:30 1998
please use help tasklist
to check current tasklist
very important,


---
作者: Fire
题目: the day of open
日期: Tue Aug 25 03:06:41 1998
we will do our best to open this mud a test version
by the day of 1/11/1998
I am very sorry for nearly haven't done anything the
past few days.( really busy)
but i will give a clear tasklist by the end of this
week, and all wizs if still want to work here can
try to find some suitable tasks.
addoil every one


---
作者: Fire
题目: to all wizs
日期: Sun Aug 23 22:00:06 1998
please don't change players parameters just for fun
if for test popuse, after test, then change it back
to original status.
some time the change will cause the system in
confused situation and will lead to bug
this mud current has many potental bug, so we
need make sure it can run in normal situation
propoly and then test some unusual situation
if now, some change will lead illegual change
to some data will cause the system in quite
conflict status and cast a lot time to find
the reason. i really don't want to limit
some wiz's power just for he(she) misuse his(her)
power. but i will give a warning here, if i find
any wiz modify data just for fun and cause
this system in confused situation, i will depromote
him to player.


---
作者: Fire
题目: about the email address
日期: Thu Aug 20 20:34:23 1998
all wizards please give you email address
so that if you didn't can't login here
and we also have sth to inform, that will be
a good way to contact


---
作者: Fire
题目: about the document system
日期: Tue Aug 25 18:39:55 1998
the document part of current tasklist has three tasks
one is about the 1， 统一完善HELP系统
i think this could be document system.
now in this mud there has some conflict about the
document. one is the location, the other is the
access method. the old lima put all the document
in /help. but we have put some of our own document
in /sgdomain/txt.
the other conflict is about the access
for the old lima it use help <subject> to
display the document's content but for some of
our help file we use different way 
for example we use fly and map to display
the help file of "fly" and "map" and use
map <id> or map <here> to display a content of certain
map. and use cmd help [subject] to display the help
file for certain command.
so I think that we'd need to re-arrange the document system
and I also suggest that we can keep both way to access
the documents, since that will be more convinent for
players.
anyway, I believe stefan will do very good job
and he will be responsible to the document part and
i will help him to write some player help files
addoil


---
作者: Fire
题目: about the war
日期: Tue Aug 25 18:41:52 1998
the war is very hard part for this mud
and i think flee will have a very busy time
and if don't mind, i will help him in some part
for the war, and he will be responsible for
the war system
addoil


---
作者: Yue
题目: task
日期: Tue Aug 25 21:18:23 1998
i take 六， 文档


---
作者: Row
题目: my task
日期: Tue Aug 25 22:41:04 1998
i will be responsable for part 4: area building.
welcome for any assisstance.
thx


---
作者: Stefan
题目: >task
日期: Tue Aug 25 22:54:34 1998
那就是说 yue 以后和我吃一碗饭喽 :)

目前的情况有如 fire 所说，summarize 如下：
1. 我们有两套 help，一套在 /help 另一套在 /sgdomain，其实这样的
分开也好，它把 lima 和 sg 的不重复部分划开了。当然在做 help 时
要考虑两个部分。
2. 很多 help 文档需要重写，不仅是因为从前的是英文，而且因为很多已经
不适用了。这里还分玩家和巫师的 help，两者都需要整理。
3. 自动文档的产生。doc_d 会定期查询部分的源码，并从中摘取按规定
格式写在 comments 中的 help 内容。这是一个很好的 feature, 不过还
有点 bug，建议巫师们在写 code 时把 help 也写在 comments 中，这会
省去很多 update help file 的工作。
4. 巫师的 help 目前来说比玩家的要重要，比如 ultra 就跟我说 lima
与 es2 有很大程度上的差别，没有合适的 help，根本无从下手。

Yue, 我会 mail 给你来讨论一下分工的问题，如果还有想做文档的来和
我说。

-stefan


---
作者: Fire
题目: tasklist updated
日期: Tue Aug 25 23:13:50 1998
I will do 二， 事件与事务   
and help document and war in some parts
and balance the progress of different parts


---
作者: Stefan
题目: changes in messages and emotes
日期: Wed Aug 26 04:20:32 1998
I noticed that "verb LIV" if LIV is yourself, it is replaced by "STR",
but I do not think this is a good change, because "emote yourself" is
just a tradition inherited from ESII style, nothing really fundamental.
I believe to simplify such message will be better. So I changed it
back. And now if "stefan hit stefan", it will use the rule for "hit LIV".

Though many emotes currently may turn to strange message if you do actions
to yourself, I am editing all emotes, and will remove all "verb STR" in
the emotes. Therefore, after I am done, it will not cause trouble again.

I made changes to m_messages.c and made a similar rule as for the
original Lima LIB, and also compatible to fire's change. Please see
/sgdomain/txt/other/newemoterule.txt for details.

Any suggestions are welcome.


---
作者: Lei
题目: webpage and advertisement
日期: Wed Aug 26 05:19:58 1998
I will be incharge of HomePage and Advertisement
The HomePage will be finished in mid-Nov which I think is not late
for the openning.
On the other hand, I will write some posts in BBS and other muds to
advertise ourselves.



---
作者: Stefan
题目: emote updates
日期: Wed Aug 26 11:30:39 1998
Please note that I deleted some emotes which I think not 
very approperiate... 

If you made that and you want it back, just add it back 
using new emote rule. I would appologize for that.



---
作者: Stefan
题目: ansi color again
日期: Wed Aug 26 11:33:58 1998
Well, actually I logged changes in didlog already, but for those
who do not read didlog (why ignore it when you login?)...

/include/ansi.h is changed to map to lima's color scheme.
There are some colors missing compared to the original ansi.h,
which are mainly background and composite colors.

Sorry if it happens to break your code. Please notify me if anything
goes wrong...


---
作者: Fire
题目: about the m_messages
日期: Tue Aug 18 20:53:44 1998
that system has been used for a long time
please refer the post on progress [6]
 6. the semote system                   [Fire       on Dec 31]


---
作者: Fire
题目: who has changed m_messages recently
日期: Tue Aug 18 20:44:50 1998
please change it back
please use showemote temote to check
the defination of all the chars
or see the file /sgdomain/txt/other/semoterule.txt
to get details
all the semote and the action has been build
on such rules
if not familiar with it, at least can ask
change without compitable will cause countless bugs


---
作者: Fire
题目: re: bugs
日期: Tue Aug 18 20:24:21 1998
that bug about the long long list has been fixed.
in /sgdomain/modules/m_ask.c


---
作者: Stefan
题目: bugs
日期: Tue Aug 18 05:26:48 1998
cat /data/players/c/cdd.o, look at the long long list, too many
duplicates.. something bad in the code ?


---
作者: Stefan
题目: >about war
日期: Tue Aug 18 05:19:36 1998
我认为 fire 的 plan 还是和下棋大同小异，我非常讨厌棋盘式的
RPG 战斗模式。Anyway, just my personal feeling.

建议大家玩玩我 upload 在这儿的卧龙传，它就没有棋盘式棋盘式战斗，
而且简单易玩，很大程度上胜利是取决与如何派兵从何处出击，
从这种意义上讲两国交战可以变得非常复杂。不象普通的三国，
无非是省份之间的攻击，空把棋盘式的战斗做得很复杂，并没
有很多的运筹帷幄在其中。

当然我尊重大多数人的意见，如果大家基本上觉得棋盘式的战斗可
行，我并不反对朝那个方向做下去。

另外，也请各位巫师轻启尊口，发表发表意见吧 :)


---
作者: Fire
题目: about war
日期: Mon Aug 17 23:14:28 1998
setfan 的建议有些道理
现在关于战争系统有如下设想，望大家多提建议
主要设想：
1 战争将主要由房间系统表示．
2 保留现有Map设计，Map将用于玩家查阅当前战
事的全局情况和辅助系统的ＡＩ系统．房间构造
与Map一一对应．
3 每一参战角色对应一支部队．（也可能一支部
队中包括数名角色．
4 每一部队有一定的机动力，当部队在房间中移
动或发动攻击时将消耗一定的机动力，机动力不
足将无法移动和攻击，机动力恢复的快慢将由部
队的士气和训练度决定．
辅助设想：
5 为增强系统的可玩性，尚有以下辅助设想
1 攻击分为四种：
A 远程攻击：弓箭 跨越一间房间或斜角
  我方部队位于M，可用弓箭攻击位于CGIKOQSW
  处的敌人
B 普通攻击如我方位于M
  可普通攻击位于HLNR的敌人
C 强攻 攻击范围同普通攻击
D 单挑 攻击范围同普通攻击
  ABCDE
  FGHIJ
  KLMNO
  PQRST
  UVWXY  
图 1
2 视觉范围：眉一部队都有一定的视觉范围
范围大小取决部队将领的智谋。
使用地图查阅时，将显示全部地形，全部我
方部队，和全部我方部队视觉范围内的敌方
部队。(埋伏部队除外)
3 包围：
  一个房间只有上下左右四个出口，如某一
方有敌方部队，则不能向此方移动(除非
把敌人灭掉)如一个房间四方都有敌人则处于
被包围状态。
4 撤退：
  如一部队移动到地图边缘，同时该地区
有本国的相邻地区，则可选择撤退。
5 主帅可下达指导形命令，
非玩家控制的部队由系统AI根据其指导性
命令决定部队的具体行动。


---
作者: Fire
题目: addoil stefan
日期: Mon Aug 17 17:55:43 1998
sweat stefan


---
作者: Stefan
题目: verb parsing
日期: Mon Aug 17 07:14:06 1998
This is tough :( The code inside the driver is really messy, and I plan to
code a parser in LPC, let's pray the it will not affect the speed.


---
作者: Stefan
题目: 对 map 类战争的异议
日期: Mon Aug 17 00:56:46 1998
我认为在 MUD 中的战争没有必要用 map 来做。原因是：
1. 它没有增加可玩性，玩家需要反复看 map 来决定下一步的移动，这
相当吃力，并且对与有点 lag 的玩家是无法忍受的。
2. 它没有提供更多的功能。所谓的行军布阵，所谓的用计放火，全都可
以用现行的房间系统来实现，没有必要在房间系统之上又建立一个虚拟的
map 系统。
3. 它不适合 realtime。轮流按步行动的方式没有 realtime 所要求的
既时性。如果说把它做成不是轮流动作的形势，那么势必增加 map 中行
动冲突的可能性，这会给玩家又带来麻烦。如果是轮流动作，那和在 MUD
里下棋有什么两样，象棋，五子棋，黑白棋的 MUD script 比比皆是，为
什么没有人玩，就是因为要反复查 map，太麻烦。
4. 它不能实现战争的复杂化。从 map 上一眼望去，敌人的行动一目了然，没有
秘密可言，缺少 realtime 的隐蔽性和刺激性。
5. 它有违文字 MUD 的本性。文字 MUD 最不擅长的就是图形化，简单的
ASCII 图案用来博君一笑还可以，用来传达信息和表述如火如荼的激烈战
斗明显不足，如果要做 map，不如去作图形 MUD 更好，免得吃力有不讨
好。
6. 它从制作的角度出发，更有无数的烦恼。而利用现有的房间系统，不
但简少了复杂度，而且其一个战场的战斗，也可以继续划分，就象两国之
间的战争可以被划分成数个战场的战斗一样。而从 map 的角度，一个 map
上发生的战斗就是最小的单位了。
7. 用 map 来处理，无法把行军同单挑同步起来，一次单挑可能化上数
十倍与普通的行军或是自动构セ魉ǖ氖奔洌诎turn 轮流的 map 作
战中，别的玩家只好看着等单挑结束才继续。

虽然用现有房间的形式做战也有一些待解决的问题，但是：
1. 解决这些问题花费的代价要远小于用 map 所花费的。
2. 所有用 map 实现的功能，它都可以实现。
3. 更贴近事实，比如一次攻城，你可以四个城门一起打，那是四个不
同的战斗。而用 map , 一个门要等另一个门的打完了再打，不然城里
的武将全被招到另一个门的战斗中去了，无法在两个或多个 map 的战
斗中适当交换兵力。

综上所述，我认为用 map 的形式在文本 MUD 中实现战争不是一个
实际可行的方案。


---
作者: Fire
题目: re:flee about the map_d
日期: Sat Aug 15 20:39:39 1998
hi flee, you have done a very good work
I checked your code and find most are very good
here i have some suggestion:
1 if you can input chinese, it's better to make
the return message in chinese, since we are now
is developing a chinese version lima mudlib
but this is not a big problem, since most the
return message from the daemon just used for the wizs
2 about the int get_full_map(string city_name)
in fact this is used to display the map to the viewer
I think this part need more sophisticated
onec the map has been loaded, it usually not need
to change the content of cells. for example
if a cell is grass, it should be grass all the
time. when an army occupy that cell, when you display
this map, you should display the army in that position
but in your map, you should know that part is still grass
. so when that army moves to other place, you should
display that part grass again. In this case, we should
disign the view of map in that way, if no army occupy
in one cell, just display that cell as the original content
if we find that an army is in that cell, the view should
display the armies . . .
and we also hope that the view part can show the frame and
some basic hints for commond
3 about the char of map
I have designed the character code for warmap
please refer /sgdomain/txt/other/warmap.txt for details
if you want to add something new or modify it
please inform me
thanks


---
作者: Flee
题目: about war
日期: Sat Aug 15 10:12:39 1998
i have write a map daemon for map managerment, now 
it can add a map of a city by reading in a txt file,
delete a city map from save data file,
by given x ,y coordinate number, return where there is,
set coneten of x , y point, 
printf the map from save data file,



---
作者: Fire
题目: re: stefan
日期: Thu Aug 13 20:33:50 1998
sorry to use english,
because input chinese is really hard.
about stefan's suggestion, i have the following explain
1 about the char_d
in fact the char_d.c is just another copy of semote_d.c
i used exeractly the same technology for the system to 
handle the semotes.
stefan suggested to make seperate plain txt file to
hold all the data for all chars( player and npc)
just like current file system to hold all the players
information. 
now i will try to list the advantage and disadvantage
1) current system will keep two copy for the player chars
data.
that is right, some data will be kept in both the chars.o
and the players own files. This is due a problem but if 
when the replicated data are quite small, it is also under
control
2) current system will keep more data in the memory
that is ture. because when the system is reboot
it will load all the data into the memory. but this
is not a serious problem. as i have mentioned before
a record in char_d just about the same size of a semote
and we know in the lima bean, it has 2345 semotes, that
means it has 2000 record of semote in the memory and will
not cause any problem of memory shortage, so, we don't need
to mind much about the memory useage about the records of chars
since we can use some methords to limit the total number of chars
3) current system is easy to manage.
if we want to add a new field, it's quite easy to write a small
program to make sure that all the record have been updated.
4) easy to program
In char_d.c there are some function quite easy to use
they are:
get_char(<char_id>,<parameter>)
set_char(<char_id>,<parameter>,<value>)
put_char(<char_id>,<file name of the room>)
find_char(<char_id>)
remove_char(<char_id>)
so it is quite easy to use these function for program
5) conculsion
I think stefan's suggestion is quite good,
if it can make still keep the advantage of current advantage
as mentioned in 3) and 4) it will be a good attempt to optimize
the system. any way if just modify the char_d and create some
new files then we can try to realize his suggestion. but if it
will make us to adjust many other files such in /sgdomain/event
and /sgdomain/cmd and other daemons, I think perhaps we can
keep this feature in our next version.
2 about objects
In old lima, when one player quit , he 
will keep all his stuff. now it is me to add the feature
for ppl to lost most of his stuff. the reason for that is
seem the clean_up doesn't work, so if not in this way , we 
will have more and more rubbish in this mud, unless wizs to 
update a room or reboot or dest some objects. any reason is
that we don't have a good parse of object. so if we have one
object more that two, will sometimes cause confused problem.
and i still keep one way to solve this problem is one player
really want to keep some kind of stuff
wizs can add     set_is_keeping(1); in that object's file
then that object will not be thrown when ppl quit.
so all the 宝物 can be set to that feature.
3 about NPC char 在天黑后就打道回府 (实际上你在府里都找不到他) 
that is just a minor feature to test the system's ability to 
handle the npc chars, so it quite easy to disable and we can
keep this discuss in later time
4 about the mud
for sg mud, we can have two methods to play, one is　stratage method
another is tactics. for stratage, a player will stand in a higher
position to view the whole picture and to player just like most
sg pc game, in that case what a ppl concer is the development 
of an area, the useage of chars and the relations to other country
and the war. but for a tactics view (just like in most current mud)
what a ppl concern is to buy food( even chicken lag) to drink to
sleep to recover hp, and find npc to fight . . . 
so that is quite different from here.
In this mud we will most focus on the stratage part, and just put 
a litter force on the tactics part. so when a ppl become a char and
get a position, he will have salary even he is offline, and a char
should not concern about his common armor and weapon and horse,
all of this will be automatally loaded when he need that.
In this mud, the relationship among players will be very very important
in other chinese mud, all the 个人英雄.
a ppl can become a high hand without others,( unless need others to tell
some secret or help to broke npc's weapon) but in this mud, one ppl must
join a country to develop. and he must learn how to cooperate with other
ppl in this country and to realize a same dream. one who want to success
in this mud must know how to support others and how to keep others support
him. so it is really exciting and new. . . .
I still have some other ideas about the wiz committee and player committee
In this mud, I hope we can deal the conflict between players and wizs 
fairly. I hope all players come here come enjoy this game and dont' get
harmed by playing this mud. . . .


---
作者: Flee
题目: question
日期: Sat Aug 15 03:10:24 1998
mapping test = ([ ({ x, y }): .... , .....]) 
is this kind of map allowed ?
it seems that i can not get the value by
test[ ({ x, y }) ],

why ?


---
作者: Flee
题目: war 2
日期: Sun Aug 16 03:42:31 1998
please read /wiz/flee/txt/war, there are some
of my ideas about map_d.


---
作者: Fire
题目: re:flee
日期: Sun Aug 16 04:28:57 1998
seem a good idea
addoil
one suggestion:
if you use cell to install all the information
so it's better change the type of each cell from
string to mixed. 
so it can store different type of information
if just a map, then use a char or a int to install
the basic message, if include more complex informatin
then use a map to hold it.
anyway, the mixed will give the developer maxmum
flexible and will not consumre much resource


---
作者: Stefan
题目: Who changed m_messages.c ?
日期: Thu Aug 13 03:06:06 1998
I found that things like $No1 $No2 etc does not work any more.
This is bad, next time, please be careful about the original features
when you change something, better keep old features if you do not
know what exactly they are..

Anyway, I have to find a copy from one of the backups, then
compare, then make those changes properly fit...


---
作者: Stefan
题目: weather made a channel
日期: Thu Jul 30 01:41:10 1998
As title. And also, I removed all individual color in day_d.c and
channel/cmd.c
If you want to use color, please set ansi.

tset, please note that no_weather_msg etc will be obsolete from now on.

I removed weather.c because it is no longer used.


---
作者: Stefan
题目: 谁来做 menu ?
日期: Sat Jul 25 04:08:52 1998
太多的命令不好记，不好用，痘啡埔桓鑫侍獾拿钭詈米龀menu。

任务有：
1. 管理 feelings (emote) 的 menu.
2. 管理 char 的 menu. (setchar, etc. etc.)
3. 管理地理的 menu. (setcountry, listcountry, listarea, setarea, etc.etc.)

可以参照现有的几个 menu 来做，比如 mail, imenu, news, admtool 等等。

新手巫师大显身手的好机会，快来报名啊！(post 一个 news 说你来做就好了)


---
作者: Fire
题目: a very good area: jieting
日期: Thu Jul 16 22:42:53 1998
jieting is a very good area,
other wizs can refer it to write your areas
because jieting is just a level 1 area
so 5 rooms are pretty suitable to it
here i will give a table for wizs to
refer
level   rooms
1      4-7
2     4-10
3    5-15
4    10-20
5    20-50
the room number here just a suggestion
if anywizs have his own ideas about his
area, can adjust this number
here i want to mention several things
need to concern:
1 about set_area
in each area, we need all the rooms
in that area include one sentence
set_area("<area_id>")
and the area_id should keep the same
for all the rooms in this area
for example, all the room in jieting
need include one sentence:
set_area("jieting")
2 path
for areas with level 4 and 5
place path under /sgdomain/area/cities/<area_id>
for example changan will be in
/sgdomain/area/cities/changan
for areas with level 3
please put in under /sgdomain/area/town/<area_id>
for areas with level 1 and level 2
place it under /sgdomain/area/guan/<area_id>
to check a area's level please use:
listarea /1;
or info a <area_id>
2
3 meeting room and fly room
for each area, we need at least two important rooms
meeting room and fly room
the meeting room is an in_door room
and the fly room in a out_door room
meeting room is the place where all the local meeting
are hold and in sometime the leader of this area will
stay
the fly room is used for player to use fly <area_id>
to fly to that place, and used for that place to
distrubite army
4 map
each area need a local map
with the name is <area_id>.map
and should be placed on /sgdomain/txt/maps/
5 setarea
when one area has been or halfly has been finished
use setarea to install the information into the
system
useage:
setarea <area_id> map <area_id>
setarea <area_id> fly <fly_room>
setarea <area_id> meeting <meeting_room>
setarea <area_id> path <the path>
for example
setarea jieting map jieting
setarea jieting fly jt_area
setarea jieting meeting jt_ysht
setarea jieting path /sgdomain/area/guan/jieting/
setarea jieting area jieting

6 any wiz has any problem about writing areas
please ask me or just post here
thanks


---
作者: Fire
题目: about events
日期: Sun Jul 19 22:19:51 1998
About the event
This is a dynamical mud, and all the dynamic data will be stored in
three tables, and these tables will be handled by three basic
daemons char_d.c area_d.c and country_d.c. To modify these dynamical
data will be and will only be through calling the functions in these
daemons. Well, since these data will become more and more and the
relationship will become extremely complex with the process of the
construction. It becomes quite hard and unreliable to put all the
codes in the three daemons. Now, a new concept will be introduced
into our mud. That is event.
What is event? 
An event is something happened which will cause the system to update
the dynamic data of this mud.
Elements of event
An event has following elements: trigger, condition check, result,
announcement, and code position.
Triggers:
In this mud, there will be 3 different kinds of trigger:
1 triggers issued by wizards
 This is just used when some data will be initialised, corrected, or
tested. Now wizards can send certain command to launch nearly all
events, from the most complex one to the simplest one, that is quite
convenient for the testing, but may sometime cause the system data
in confused situation. In the following development some limitation
will be added to reduce the probability of these errors.
2 triggers by the system
The system will atomically trigger many events, such as the local
area development and the unemployed npc char move from an area to
another.
3 triggers by the players or half by player and half by the system
This is the most complex situation, many events will be trigged by
players certain action. For example, if a player want to establish a
new country. 
Condition Check:
When a trigger has been sent, the system need to check if the
condition is suitable for such an event, or sometime, with the same
trigger, under different situation, different events will happened.
Result:
I think that no explanation needed for this part.
Announcement:
It includes two parts: the target and the method.
When a certain event has happened, the system need use certain
method to inform certain players. 
Code Position:
Currently, all the code for the existed events are put in that three
daemons, as we know, there will be perhaps nearly one half hundred
event designed, so put all these code in that three daemon will be
quite inconvenient, so a new path /sgdomain/event/
Will be used to store all the new code for events, and for most
events (especially for those complex ones) , it is suggested to use
one separate program to handle just one event.
Fire
July 20, 98


---
作者: Fire
题目: list for events
日期: Sun Jul 19 23:32:03 1998
List of event
1
Name: adjust_product_level
Trigger: day_d->ai_d
Condition the third day of every month
Result: update the level of product( agriculture, industry, and
business) for every area
Announcement: None
Code Position: country_d and area_d
2
Name: adjust_safe_level();
Trigger: day_d->ai_d
Condition the first day of every month
Result: update the level of safe for every area
Announcement: None
Code Position: country_d and area_d
3
Name: adjust_military_level();
Trigger: day_d->ai_d
Condition the fifth day of every month
Result: update the level of military (moral and train) for every area
Announcement: None
Code Position: country_d and area_d
4
Name: adjust_population();
Trigger: day_d->ai_d
Condition the 9th day of every month
Result: update the pupulation for every area
Announcement: None
Code Position: country_d and area_d
5
Name: area_check and char_check
Trigger: day_d->ai_d
Condition the second day of every month
Result: check the integrity of char and area database
	May trigger the certain events:
Such as auto local leader promotion
And the reduce of safe level for a certain areas
Announcement: None or chat
Code Position: country_d and area_d
Note: this event need further concern
6
Name: LEADER_APPEAR 
Trigger: day_d->ai_d
Condition the 1th hour of every day
That area has no special event such as war or local meeting
That char is an npc or a offline char
That char does not do other business such as war or meeting
Result: The leader of local area will appear in the meeting room 
Of that area
Announcement: to that room in simple_action
Code Position: area_d
7
Name: LEADER_DISAPPEAR 
Trigger: day_d->ai_d
Condition the 3rd hour of every day
That area has no special event such as war or local meeting
That char is an npc or a offline char
That char does not do other business such as war or meeting
Result: The leader of local area will disappear in the meeting room 
Of that area
Announcement: to that room in simple_action
Code Position: area_d
8
Name: save_data
Trigger: day_d->ai_d
Condition every hour
Result: The database will be saved if there has some thing changed
Announcement: None
Code Position: area_d, char_d, country_d
9
Name: LOCAL_INCOME & NATION_INCOME
Trigger: day_d->ai_d
Condition 10th day of every month
Result: the local officer will get pay, the local area will get
harvest gold and product
(If in September also food ) and also calculate the consume of local
food gold and product, is not enough will cause the lose of local
soldier and reduce the loyalty of local officer. 
Announcement: chat to all user and rumor to all user(if not enough goods)
Code Position: area_d, country_d
10
Name: EVENT_NPCCHAR_MOVE
Trigger: ai_d-> event_creater
Condition random based. 
Probability :1 over EVENT_MAX
Result: an unemployed npc char moves to an neighbour  area
Announcement: rumor to all user 
Code Position: area_d


---
作者: Fire
题目: about event
日期: Sun Jul 19 23:33:50 1998
the post about event is stored in /sgdomain/text/other/
please go there to check the last updated files
about the events


---
作者: Flee
题目: menus
日期: Mon Jul 27 05:41:03 1998
i have code a menu for emote which located at
my home dir with name emotemenu. it wasn't finished
because all the functions of semote.c , addemote.c
and delemote.c are declared as private.
and i can not solve it via soul_d.c for soul_d.c have
a previous_object check.

PLZ check it, if it is OK, i will start code the
following two.


addoil all


---
作者: Flee
题目: emote menu finished
日期: Wed Jul 29 10:13:22 1998
i finish emote menu today.
now the menu can list, find, delete and edit emote now.
which is overlaped cmds such as addemote.c, rmemote.c,
semote.c and feelings.

info me if any bug inside.


---
作者: Fire
题目: admire stefan
日期: Fri Jul 31 21:58:12 1998
can you tell me where did you find that "?"
beg stefan
thank stefan


---
作者: Fire
题目: about areas
日期: Fri Jul 31 22:49:08 1998
now most areas in the northwest part has
its own meeting room and fly room
so it can make the system to do the next development
but some areas don't have map, so
any wiz, if you are developing one area
please finish your map first
today i have find 2 very good maps
one is didao and one is chencang
but i am pretty sorry i don't know who made
them
so if any one finish some work, don't forget
put your name at the bein of that file
and i find ultra has made nearly all the rooms
for didao already, so i select ultra's didao version
then the old didao map will be still reserved 
perhaps for other areas, and the chencang
i find the map, but seem no body has made the rooms
so i just make two empty room there for meeting
and fly purpose
the wiz who finish the map of chencang
please contact me and i expect that you can
finish the whole area
thanks
fire


---
作者: Flee
题目: char menu finished
日期: Tue Aug  4 06:35:48 1998
i have finish character managerment menu located
at /wiz/flee/menu/charmenu. u can use /wiz/flee/cmds/char
to check it out.

but i still doubt that when i set my wuli to 100,
my wuli change to 244 in factor. why ?


---
作者: Stefan
题目: wizards management
日期: Tue Aug 11 06:02:26 1998
这个管理的问题很不好办，我因为工作的关系，不常在这里出现；
fire 因为是主要的写 code 干将，也没有很多工夫来问问各位巫
师都做得怎么样了。

我看不如这样：

1. 每个巫师无论职位高低，无论能力如何，每人都在自己的目录
下建一个名为 report 的文件，用来记录你做过的事情，有个大概
就行，不用太详细。

2. 这个 report 文档我或是 fire 每半个月检查一下，一方面了
解一下大家的进度，另一方面也可以让大家自我督促一下。连着
一个月什么也不干，未免面子上也说不过去吧 :)

今时不同往日，以前纯是 Lima 的时候，我是根本不过问的，各
位自由来去。现在做三国，好歹也是个目标，而且已经小有成果
了，我们也都希望能够组织一个实干型的 team 认真开发开发。

时间不是个理由，时间再少，你一个月总有个四五个小时能为三国
做一点儿事情吧？四五个小时可以帮着写好几个 help 文档呢。
要是一个月四五个小时也拿不出来，你申请个 wiz 不是逗我们玩儿吗?

请各位对这个建议提提意见，如果没有什么大意见，那就执行了。
作为一个 server 的提供者和最初的 mudlib 提供者，我一直对于
作巫师这件事提供很大的自由度，可是总是这样也不是办法，不能
让 fire 累到吐血吧?? 也希望大家支持。如果实在是有困难做不
到的，我也接受巫师的离职申请 :)

-stefan


---
作者: Stefan
题目: 我对于目前 char 问题的异议
日期: Tue Aug 11 07:03:04 1998
不过是一些个人的看法，说错了尽管 slap 我 :)

首先统一一下名称，主要的 NPC 人物，比如君主，武将等，以下用 NPC Char 代替。
玩家还是叫 player，但是如果申请了定居而在 logout 时作为 NPC 保留下来的，以
下称之为 NPC player.

1. 目前的 char_d 在管理 NPC Char 和 NPC player 的所有 data，并且统一存起
来。我认为这样做有一些弊病。首先，NPC player 还有一份 data 是做为正常
player 而存起来的，这与 char_d 有可能会产生冲突。当然在正常情况下，可以
在 load player 和 switch 两者的时候予以检查来避免 data 不一致的情况发生，
可是一个 mud 它会 crash, disk failure 等等的问题，如果同种 data 存两份，
一方面浪费空间，另一方面不方便管理。虽然目前 data 还不算多，可是实际的
情况很难讲，为什么不在最初的设计时避免掉可能发生的问题呢？第二个弊病是关
于 NPC char，如果一旦有需要把他们的另一个参数放在考虑之内，那么整个 char_d
就要作修改，而且注意，这个修改必需考虑到旧 char_d save 的 data，因为新
char_d 的 array 都不同了，旧 data 必需通过一个转换的过程才能为新 char_d
所用。或许没有什么参数是我们漏掉的，但是这样的方式不方便管理。第三个弊病
还是关于 NPC char，如果我想重新设置一些参数，我必需通过 char_d，而不能直
接在 NPC object 上改动，这虽然不是个大问题，可是它与 NPC player 的处理却
大不相同，既然我们说 NPC player 与 NPC char 是等同的概念，为什么处理的方
式不同呢？

我的建议：
让 NPC char 进一步接近 NPC player，把 NPC char 的 object data 直接 save
到 /data/players/ 里面去。而 char_d 的功能还是相同，但是它不 save 自己的
data，而是充当一个 cache 形式的缓冲，以避免每次 clone 一个 NPC char 却只
为了其中的一个数据。当你向 char_d 要数据时，char_d 首先在目前的 memory
里面找，如果找到了，就直接 query 它然后把数据传给你；如果没有找到，那么
说明这个 NPC char 或 NPC player 还没有被 load，char_d 就去检查自己的 data
cache，如果里面有你要的这个 object 的数据，就把它传给你，如果没有那就去
clone 一个，再把数据传回。当 char_d 处理 query 时，它都应该 update 它的
data cache。这个 cache 实质上无异于目前的 array，只不过是不存储在硬盘上
的。这样以上的三个弊病都没有了。而且专对 performance 而言，这样做实际上
并不会增加多少不必要的 clone，因为这个 cache 的 size 是可调的，可以放到
很大，那和目前的情况就没有区别；如果 cache 超过 100k，那么可以用 FIFO
的算法 clear 掉旧的。总之在 performance 上非常灵活。

不仅仅如此，这样的一个 char_d 可以增加很多功能，是目前无法做到的。比如
在 player logout 时的 inventory loss, 可以完全被避免掉。尤其这种 inventory
loss 目前在 player 转成 NPC player 时是无法避免的，这非常没有道理。还有
就是在对于 char 的 query 上可以做到任意的 query，这由于目前的 array 不
能太大也是无法达到的。而且我们可以拒绝新玩家选用以有的 NPC char 或 NPC
player，甚至 player 的中文名字，这在目前也作不到。

以上为我的第一点异议。接下来...

2. 我认为目前 NPC char 在天黑后就打道回府 (实际上你在府里都找不到他) 很
不合逻辑，而且没有增加任何可玩性，就象侠客行的城门一样，只会带来 frustration.
夜行军总听说过吧，而且你不能让我找一个 NPC char 切搓武艺时半路他来一句
告辞就消失无踪了吧? 而且一在地 clone remove clone remove 也不是什么好事。
你可以让会议在天黑时停止，但让 NPC char 消失就过分了一点点。

3. 我坚持所有 inventory 全被 save。我认识很多 English mudder, 他们一听
说 logout 时东西要掉掉，根本就没兴趣玩中文 MUD．这是一个经常被忽略的死
角，西游记的法宝或许解决了一点问题，但是其根本是：为什么要都掉掉？
或许有什么 unique item 你不想 player 拿到了就据为私有，可是我们的 MUD
是 player 变成 NPC player 继续留在游戏里，你要夺宝找他夺吗，更合逻辑，也
更有趣些。不然为什么要叫 dynamic mud? 而且如果说为了不让等级低的 player
用好的 armor or weapon, 那么可以在 armor 或 weapon 上限制，只能拥有而
不够级别使用就成了。如果说 ES2 based mud 一次身上带一大批东西不合理，
那是 ES2 lib 写的不和理。Diablo 都玩过吧，那么多好 armor 好 weapon, 可
就是不可能都带在身上。

写了很多，不知大家有没有耐心读完？ :-) 给点意见吧...

stefan


---
作者: Stefan
题目: >我对于目前 char 问题的异议
日期: Tue Aug 11 07:09:32 1998
补遗... :)

ES2 lib 之所以有 inventory loss 这个问题，其根本是没有办法作到 recursive
objects saving。而 Lima 本身就有这个功能，多好啊 :)


---
作者: Fire
题目: i can't read my mail
日期: Tue Jul 14 08:39:20 1998
>>你有新邮件！<<
你进入三国志。
--烈火的家-- [出口：out]
    烈火是个不爱回家的人，要想在这儿见到他可不容易，家里好象
没什么值钱的东西嘛。对了墙上好象有一张条字，可以看看。
一张纸条(zhitiao)
烈火留言板【共有76条留言】
> mail
--- LimaLib Mailer ---
Current headers:
N 70  stefan          (Tue Jul 14) disk failure
[70 of 70] 信件：
*Bad argument 1 to explode()
Expected: string Got: 0.
Trace written to /log/runtime
[errors] (fire) Error logged to /log/runtime
[errors] *Bad argument 1 to explode()
         *Expected: string Got: 0.
[errors] /secure/obj/mailers/standard#9 (secure/obj/mailers/mailer.c
) at line 105

this is what i got
i know that stefan send me an mail
but when i try to read it
it got some error message
i  shutdown and try again
the same thing happened
can stefan have a check. what cause this problem
thanks


---
作者: Stefan
题目: >shaoying's application
日期: Sat Jul  4 01:15:57 1998
I agree with fire that we are still in recruiting wizs stage, and 
we need more active working wizs :) 

-stefan


---
作者: Fire
题目: you are right
日期: Mon Jun  1 10:03:44 1998
lity's suggestion is right
now i am designing the struct of player and npc
then will be the cities and countries
currently, we can post some ideas about country and
country
when these ideas become mature and the npc
and player's struct nearly determined
we will begin design the cities and countries


---
作者: Ljty
题目: 关于结构
日期: Sun May 31 15:15:36 1998
我认为除了NPC和player的结构外, 还要有城市的结构.
也就是城市的资料了.

另外player的结构有两方面, 一是个人, 二是部队.

现今的npc是inherit monster的, 要重新做.

just 建议.

* addoil


---
作者: Stefan
题目: Task list
日期: Sun May 31 08:07:48 1998
help tasklist

如果有要补充的，或是你觉得你可以作哪一项的负责人或工作人，请直接
改动 /help/wizard/tasklist 文件，加入你的名字就行了。

(注意它的 format, 保持整洁 :)

-stefan


---
作者: Yue
题目: about semote
日期: Sun Jun  7 23:28:20 1998
i use random to check some semote
i find a semote r big-5 coded
who ever made that, tell me about that semote, thanks
Yue


---
作者: Lei
题目: testjig
日期: Mon Jun  8 07:32:55 1998
I propose to promote Testjig as a wizard.
Testjig is a EE final year student. As i know, he will be 
free in coming 6 months. Testjig is also very interested in mud writing.
I believe he is good enough to be one of us. 
PS: Testjig is from the same school with yuner and me and same city with 
Stefan and Benben. It is convenient for our work.



---
作者: Fire
题目: support lei
日期: Tue Jun  9 05:37:39 1998
welcome testjig


---
作者: Stefan
题目: testjig promoted to wiz
日期: Thu Jun 11 04:03:09 1998
Addoil to testjig!


---
作者: Fire
题目: shaoying's application
日期: Wed Jul  1 20:55:58 1998
Hi, every one, i have just received shaoying's
application for joining our development team
I think we need new wizs to join, because
in the soon future we will have a lot of works to do
so, please post here to disscuss his application
thanks

shaoying's applicaiotn
Hi Larry,
Should I write a much former application letter to be a wizard?
I like SG since I was a kid. Shang Hai Tu Shu Chu Ban She has published a
set of picture-book of SG. The pictures attracted me deeply. I played the
most original SG when I was in my sophomore. SG, XYJ are the 2 topics I
like very much.
I also have strong background in C/C++/Java. So, it would not be very
tough for me to get well along with MUD programming, which I desired to
learn long time ago.
And I do think that SG, a strategy MUD has a wonderful prospective since
this is the 1st, as I know, MUD that bravely explores in a newer topic of
MUD. I have read some articles from BBS about strategic MUD, some
proposals etc. So I have some basic idea on that and would love to
contribute my knowledge and time in it.
Thank you for your consideration. 


---
作者: Fire
题目: cdd want to apply wiz's position
日期: Mon Jul  6 07:48:06 1998
is there any one support him ?


---
作者: Fire
题目: new application
日期: Thu Jul  9 07:30:35 1998
Hi,请问如何正式申请当编辑？我为计算机本科毕业，每天上网超过3小时，不知还要
有什么条件？（我在三国的id为zc)
                    流浪狗敬上
how about this guy,
anyone has any ideas ?


---
作者: Fire
题目: shaoyng and benben are added into Mudlib domain group
日期: Thu Jul  9 09:32:49 1998
because they need write some code for new areas
they have been granted the priviliate


---
作者: Fire
题目: suggestion about the name of file
日期: Sun Jul 12 02:22:50 1998
in order to make the contral easier.
when wizs design new obj( a room, npc, or obj)
please don't make the length of the file name
no more than 10 letters
thanks


---
作者: Stefan
题目: 卧龙传
日期: Tue Jul 14 23:01:04 1998
I put a copy of cracked 卧龙传 in /ftp/pub, check it out!!!
It is a zipped file of 1.9M, should be easy to download by Modem...

It is a real time game, unlike most 三国 games, and I think the
战争方式 is a very good example for our mud.

For PC only, not for Mac :)

-stefan


---
作者: Ultra
题目: sorry to all
日期: Thu Jul 16 09:13:12 1998
今天过来仔细的开了以下post才知道我已经是巫师了。
thank
我想我比较善长的就是client server的东东
具体有什么需要可以mail me 
wink
addoil


---
作者: Fire
题目: thank you all
日期: Sat May 30 18:59:20 1998
thank you all for you trust and support
Before I came here, I knew nothing about mud programming
Now, I have learned sth at here, but to the whole system
I only know a little. without all wizards help and support
I can do nothing.
hope we can work together happily and open this mud at
a sooner future.
thanks all
bow

fire


---
作者: Stefan
题目: >need more priviliage
日期: Sat May 30 09:32:13 1998
Fire is promoted to Admin. Let's all wish he'll do well enough
to keep Admin.

Fire: be careful not to get anything screwed :)

-stefan


---
作者: Fire
题目: need more priviliage
日期: Fri May 29 19:26:42 1998
Now i begin to develop the mudlib,
and find that i meet many inconvenience because
many paths such as /trans, /includes, and /data that
i have no right to write.
I apply the position of admin. 
I will use this power to contribute this mud
I have done sth for this mud
but unfortunatly that I haven't finished it
I will continune work here until the day that
the Chinese MUD 三国 opened offically for players
please consider my application and please consider
the current situation of this mud.
thanks


---
作者: Fire
题目: simplity the system
日期: Fri May 29 08:58:23 1998
according to sg's requirement
many thing in player's files are useless
nearly all in race.c and human.c are deleted
and some in body.c also been delete
please notice is there anything wrong
thank


---
作者: Fire
题目: plan of work of next step
日期: Tue May 26 04:27:22 1998
Plan for next work:
draft of plan for the work of next step.
1. rewrite the struct of the players and npc.
delete those unused para and give a full docu
of these paras
2. modify the cmd system
reduce the number of cmds and simplity the useage
of cmds and give standard of cmds
3. help system.
include help for player and help for wizards
4. the struct of cities and country
and the struct of centra_contral system and AI  system

details:
1. we will have three kinds or level of npcs
1.1 simple npc
this kind of npc is used as store keepers, servant girl
kids. . .
it can't fight, perhaps can answer question and decorate
cities. (fight means fight in the war )
1.2 fight npc
the difference from this npc to the simple npc is that
this kind of npc can fight, so it has much more gifts
but it will not be controled by the centre contral 
system. some brigand and officer belong to this kind
1.3 full document npc
this kind of npc has nearly as much paras as players
and they will be controled by the centre control
system.
all the famous general and officer will belong to
this kind
1.4 players. some ppl will become npc in certain situation
this will be discuss later.
1.5 relation of npcs and players
player inherit full document npc inherit fight npc 
inherit simple npc.
2 cmds
2.1 all cmds will have help and examples
use <cmd> ? will display the help and example
2.2 simplity and reduce the number of cmds
2.3 add several menu based cmd used for
check information and give complex cmds such as
rearange the army and genernals
2.4 add one universial cmd "use"
which can be used for many objects
3 help system
3.1 the first part is help for wizs
this help should include detailed plan and desc for
all different systems. and when some new parts
are modified, will use sth similar autodocu to
update the help documents
3.2 cmd and menus based help system for player
this will make play to find and read help
quickly and easily
4. centre control
4.1 struct of country and cities
this is the core of this game. all ppl and npc should work
for one city or country except a little 无国籍人
the system will update the data of all country and cities
regularly. based on some suiteable formula.
the development of a city will depend on the ability
of the leader of the country and the city and other officers
in this city. the king and mayor can adjust some police
of the city, but most of these will be done automatically.
so.
4.2 AI and central control
for NPC country and cities. this game will give a reasonalbe
AI to make them deal with some situation
any wizs interested in any part of this plan, please post your
ideas.
I will begin this work within next week .


---
作者: Stefan
题目: WIZ Shell
日期: Mon May 25 02:25:36 1998
Pickle, Yuner, Yue have been granted to use Wiz shell. If anyof you 
has any trouble logging in, let me know.

-stefan


---
作者: Yuner
题目: 我的一点建议
日期: Wed May 13 07:26:17 1998
看了大家的时间表，实在是很难凑到一起，我中午也有事，要做IHPT，
所以我想大家能到当然很好，要是不能到全，就请主持人把议点写在
post中，然后大家随时进，随时看，随时发表意见，不知这样能否弥补
大家不能到全的缺憾？


---
作者: Pickle
题目: response to fire
日期: Wed May 13 02:22:04 1998
烈火的心情我也理解，申请当巫师然后没反应，换谁都受不了。
以前的过去就过去了，无所谓。但以后我觉得大家最好还是讨论
一下子．．．烈火所说的“if i am under this situation again,
i am sure i will do what i have done exactly.” 我就不太
理解了。那意思是说如果有别的巫师申请，你还是会吸收么？

我不想婆婆妈妈的，但我觉得吸收巫师是非常重要的，我希望我
们不要太忽视这一点。一个新巫师有没有编程技术并不重要，但
“but on the other hand, will also not harm to this mud”
是不对的．．．如果巫师内部关系不好，将会很难一起合作，写
的东西也是互相矛盾，比如甲写了个天下无敌的盾牌，然后做了
一堆广告，这样大家都喜欢这盾牌了，然后乙想也不想就写了个
矛，一下就能穿过这个盾牌。那么这游戏就自相矛盾了。只是简
单举个例子，真正可怕的还不是这点小事，但我也不细说了。而
且如果一个巫师长时间待在队伍上而不干活，对我们没有任何的
意义，而如果有玩家了，他们看到了自然会觉得我们是巫师乐园，
而且我们还没法解释。最后再提一点。新的巫师申请时没人理会
很难过，不错。但是新的巫师丝毫不知道游戏的构造，一点不懂
lpc 语言，就来写东西，那往往会写出一些不甚令人满意的东西。
这时候我们如果显出不满，一样会很令人伤心的。我知道，因为
我有个人经验。

好了，我废话也说得够多了。打了这办个小时的字，只是希望大
家能足够认识到巫师队伍团结的重要性。千万不要觉得随便收个
人就算没好处也不会有坏处——在一个diverse 的世界里，没好
处大概就是坏处了。

pickle



---
作者: Fire
题目: re pickle
日期: Wed May 13 21:49:06 1998
看来你对我的post理解的与我期待的不太一样
没关系，我想等我们多处一段时间就会更加了解
我会尊重你的意见，同时再有重要的事情，我
会征求你的意见。
xixi


---
作者: Fire
题目: the first wiz meeting
日期: Thu May 14 01:10:28 1998
the first wiz meeting
just pickle, yuner and i were here
and nothing can be decided
sigh


---
作者: Fire
题目: agree stefan
日期: Thu May 14 06:30:19 1998
we need work together to build the base part
then others can be consider later


---
作者: Stefan
题目: Site shiftment
日期: Fri May 22 04:52:15 1998
这里将会用作开发时的 site，别找太多的玩家来，对我来说不方便 :)

我已经设立了 Wiz Shell ， port 是 3001. 要用它的巫师通知我一声，
我会给你一个帐户，名字密码都和这里相同。

不过， Wiz Shell 的 security 不能和 Lima 兼容，所以任何巫师只能 edit 你自己
目录下的东西，或是 /open 和 /tmp. 这样会造成一定的不便，因为你
需要先把要改动的文件 copy  到你自己目录下，改过之后再 copy 回去。
然后才能 update .

我本人喜欢用 ed 而不是 vi :) 所以我不会使用 Wiz Shell，如果有
什么问题 mail 给我就好了。

-stefan


---
作者: Stefan
题目: >plan of work of next step
日期: Fri May 29 03:16:50 1998
关于 fire 的计划，基本上我同意，我也有一些工作的项目列表，我
想应该开始给每个人分个工，谁做什么，大家都清楚，而且出了问题
好找人来骂 :)


我的以下一些也是需要做的：

1. Newsgroup rebuild. 现在的 newsgroup 采取的方法是所有文档都
存在一个文件里，这样不太好，尤其是当文档越来越多时，不好管理。
我的想法是，每一个文档一个文件，用一个 news id 来作文件名，而
且要提供一个现有的 newsgroup 到新方案的 migration.

2. 系统用语的统一。比如 domain, group, channel 等等似乎存在不同
的中文译法，为了避免造成混乱，有必要统一一下。

3. Ansi color clean-up. 禁止直接使用 color code，一律改为 user
configurable 的颜色方案。

4. Verb parsing. 要用 much much smarter 的方法来处理，比如：
wield sword 首先是看自己身上的 sword，但是 pick up sword 显然是
先看地上的 sword. 而且需要允许 my sword, my 1st sword 之类的定语
来限定 sword 的范围。

5. 一些小问题的处理，比如 inactive 的命令存在，却没有任何地方用到
这个 flag. 还有 verbose 的问题，即使把 verbose 关掉，more 到 100% 的
时候它还是会停住等你敲 enter, 这在 ls 时极为不便。

还有很多要做的，一时也难以列全。各位巫师可以也列出一些要改进的
地方，然后我们大家来分工。加上 fire 的 plan, 可是有够我们忙
一阵的啦...

-stefan



---
作者: Fire
题目: my work
日期: Fri May 29 05:07:57 1998
from now i will begin to arrange the paras of players and npcs
and i will give a detailed list of all the paras
, functions and the relations among them
about stefan's plan, i support hime
I think perhaps stefan is the best person
to do these work
addoil stefan


---
作者: Pickle
题目: 也来说两句
日期: Tue May 12 03:04:46 1998
既然烈火提起互相尊重的事，我也多两句嘴。

记得最开始时我们大家一起定的规则，要求吸收新巫师前
要整个天神组的大多数同意，而如果大多数反对则不会收。
也许是我记错了，不过似乎烈火本人曾经不止一次单独做
主张吸收新巫师，而且将大家同意开除的巫师重新提拔，
这．．．

还有就是写程序。我也知道大家都忙，但希望以后大家写
比较重要的程序时先留言讨论一下。比如现在的功夫系统
我就不特别赞同，．．．

in any case, i don't intend to sound very hostile,
if i do, that's because my chinese is very poor. :(
i just want to discuss opinions, and hope that in
the future we all respect each other. :) i know
that i haven't been around all that much and i probably
have no business 指手画脚 about others' hard work. :(
i had a very rough semester, please forgive my lack
of attendance. i will return to china for several
weeks after the end of my term, dunno whether i can
come to the mud when i'm in china. i hope i can. if
not, then y'all will hear a bunch from me in the next
week and then hear nothing until the end of july le.:(

pickle



---
作者: Ljty
题目: new site is very fast
日期: Mon May 11 04:27:27 1998
This site to me is also ok, not lag, but new site is 
really fast to me. I like it.

这一段都有点忙, 没做多少. sigh, 时间是最大的问题.
sorry, addoil all.


---
作者: Yue
题目: another question
日期: Sat May  9 11:01:51 1998
 list
本处现有下列物品： 

--------------------------------------------------------
          货物名称             价钱
      羊皮酒袋(skin)          一两银子。
一身霓羽长裙(skirt)          十两银子。
飞龙二珠冠(zhu)          五两银子。
豹头掣行靴(xue)          五两银子。
美伦美奂的霓裳羽衣(yuyi)          二十两银子。
          布衣(buyi)          三两银子。
--------------------------------------------------------
看看你需要点什么
why those message r so messy?


---
作者: Stefan
题目: My apology to Fire and Ljty
日期: Sat May  9 22:43:08 1998
First of all, I have to apologise to you two that I did not inform
you before I repositioned all the wizards. I spoke to lei, yuner, pickle
about the change before I did it, and I did not see objections

Secondly, a little explanation of what I did...

As the person who setup this lima, I warned Lei before he organized
a team to build a mud upon lima that, please do not do any
naughty things that will break the base mudlib. Then I gave him the
right to build a mud here and I did not interfere anything you guys
after that, until one day I checked the ftp log and found Pier ftped
back all source codes. I was wondering why this could happen if everything
is on the track, so I checked security system and found all security
protections were broken.

I realised that nobody really understood the security in lima yet,
and there were too many admins around, one su to another reading emails,
and other naughty things ( I wont mention here cause I am not sure
whether what I was told is true or not ). I would not care what you
guys do among yourself, but I was very angry that the whole source
codes were stolen and yet nobody was aware of that. So I decided to
fix the security hole. I posted these things before I did the fix.

After the fix, I thought about giving back Admin to those who owned
it, but then I dismissed the idea because I do not want to see anyone
who do know how the security system works to be the admin here, it
will surely harm the mudlib. So I decided to hold back the Admin position.

I hope I am understood here, the whole intention is to protect this
mud, as I said again and again, I will not participate in your 三国
domain building and will not disturb you guys in any manner. But I will
make sure the mud is not messed up.

In fact, after the change, does anyone really feel very inconvenient
when coding things? The parts protected by Admin privilege are not
supposed to be touched under normal circumstances. The only thing really
different is that you need to get my approval to change those "core" codes
of the mudlib and you are not allowed to fumble with security any more.

I am not concerned of any surreal power or position illusions, like
the 'arch' position before. It did nothing but made a nice description
in finger. Do read the security documentions if you really want
to know how security system works here.

Actually, I like fire's post, he asked me to apologise openly. Everyone
please speak up if you have something to say.

-stefan


---
作者: Stefan
题目: new site
日期: Sun May 10 02:57:46 1998
A new site is up at sing.wistar.upenn.edu 5000.

Keep it as a secret :) I do not want Upenn people to find out.

But a trouble is, I can not set up intermud communication between
these two muds. We need a Imud3 router to do so, but I asked in the 
Lima Bean site, they are not going to reveal the source code of it.

So, it is hard for us to keep consistent between two muds, especially
news and mail. I am thinking of shutting down current one and only 
focus at the other one. 

What do you guys think? How is the speed over there? Please do not 
post things there or changes codes there, I might transfer all the things
here to there again.

-stefan


---
作者: Pickle
题目: other site
日期: Sun May 10 17:24:18 1998
the other site is incredibly fast for me, especially when compared
to this site. :( i hope we switch... *addoil stefan


---
作者: Yue
题目: new site
日期: Sun May 10 18:13:26 1998
then newsite is so so fast
fell like localhost, snicker
* addoil


---
作者: Yue
题目: here's ftp only can upload 400 k max
日期: Sun May 10 21:22:18 1998
as title


---
作者: Stefan
题目: >here's ftp only can upload 400 k max
日期: Sun May 10 22:48:43 1998
Yeah, I noticed already. I'll fix it up ASAP.


---
作者: Ljty
题目: to pickle
日期: Tue May 12 04:49:45 1998
pickle也别怪fire吸收新wiz. 也许就是新鲜血液吧. 说实
话真正做工作的不太多. 吸收新wiz也许会有新的转变. fire
吸收wiz我想是合理的, 在程序前有//modified by stefan
外, 大部分都是//by fire . 同意吗. 他有这个权力, 不是在
于他的权限大小, 而在于他的工作. 别人我想没多少能望其
项背的. 多劳多得, 如果我们还大锅饭, 凭级别与干部制度
来说话, 效率太低, 毕竟大家都是自愿的, 谁也不拿工资.
我们时间都很紧, 能在这上面花时间做工作, 本身就是让人
尊敬的. 当然我不否认wiz组讨论更好. 但我不希望什么都讨论,
效率太差, 我们平时难得一见. 要讨论太难, 搞的不行修改
就是了.

希望stefan在管理问题上下点功夫.



---
作者: Pickle
题目: re ljty
日期: Tue May 12 05:51:28 1998
hmm.. 我不是发牢骚，而且不在乎烈火是否道歉，这些都不重要。
但是我认为吸收巫师是件非常重要的事情。如果巫师之间关系不和
那将给 mud带来极大不便。也许是我paranoid，但是我在西游记的
经验使我十年怕井绳。

这是从游戏角度来看。从个人方面来讲我觉得更值得讨论一些。在
这里跟大家一起干就要互相尊重，不能觉得「嗯，因为我收的巫师
由我自己管，就不用跟别人打招呼了」。也许在游戏里这是对的，
但这是一种对别人的不尊重。如果你觉得别人的意见不太重要，那
就把他降级，从巫师降到平民。不要答应了和他讨论然后置之不理。

有关讨论游戏设计的事情，我同意：不可能样样都讨论。但我只是
指那些重要的事情，比如说战斗系统。这种根本设计如果大家不同
意，那么将来再写新东西时会步步荆棘。反之如果先讨论好了，把
可能考虑到的东西都考虑过了，那么将会事半工倍。

又：我这些话纯是心中感想，不是针对烈火而发的牢骚，别误会。

pickle



---
作者: Ljty
题目: 同意pickle
日期: Tue May 12 10:07:02 1998
我想我们是要加强一下管理, pickle你说的也有道理.
我们的meeting是需要.

sorry, addoil.


---
作者: Fire
题目: bigman stefan
日期: Tue May 12 20:33:02 1998
after i made my last post, i feel a litter upset
perhaps i am too rude to ask stefan to apologize openly
but to my surprise, he realy did that
so bigman stefan
no matter what one does probably will cause some ppl
unhappy, it's quite nature and can't avoided
but if we can discuss openly and can admit it oneself's
mistake then everything is ok
I like stefan's style, and i will work here.
sw
becuase he is a honest person and be worth of trust
to pickle's complain, i feel very sorry for that
I know some times i disobey what we have agreed before
especially to recruit new wizs.
before i come here, i apply to be wizs in other muds
but receive no respond, i am very sad with that experience
so when other ppl ask, i really know his feeling and
I just didn't want to hurt him. I know, in most case
new wizs without suitable programming background and
enough time will contribute few to our mud
but on the other hand, will also not harm to this mud
so, it's really hard for me to refuse his application
of course, i should discuss this with other admines.
but during sometime, it's quite hard to find other admines
to discuss. so. . .
I know this is my mistake, if there is a penalty system here
i would be glad to undertake that, but anyway, if i
am under this situation again, i am sure i will do
what i have done exactly.
sorry pickle
perhaps i am not a suitable person to do administation work
so, as stefan modify this system, this will never happen
snickle


---
作者: Fire
题目: new lima is super fast
日期: Tue May 12 21:00:05 1998
admire stefan
xixi


---
作者: Yuner
题目: hoho
日期: Sat May  9 03:20:19 1998
How about do the webpage after the basic frame is done?


---
作者: Lei
题目: hmm...
日期: Sat May  9 01:24:32 1998

For something really bad, I won't go back to China this June:(
So I will have enought time to work here. 2 things I want to do:
1. The detailed plan mentioned by fire
2. A webpage of this mud
I think the plan should be quite important and everybody has own ideas
about that. Pls post our your ideas completely if you are interested, 

About the webpage... You may think it is to early to do that now. Anyway
I am very interested in writing webpage now:) Also if you have any ideas 
about webpages, just feel free to speak out pleas.



---
作者: Fire
题目: Re: Yue about bug
日期: Fri May  8 23:59:52 1998
I check the code and find 3 problems.
1 in /std/modules/m_wearable.c
  when one remove the cloth
  the ppl will release the slot
  but for none cloth not within living object
  this will cause error
  i have add some code to fix that
2 the jia.c in /wiz/yue/obj/ is not
  an object for this mud
  much code are not compitable with mudlib
  here. so i remove it out off the list
  of add_object in ly_zahp.c
3 the third problem is about the code style
  now i hope all code to be wich the same style
  so we have special path for all objects
  it's better to put your object in the suitable
  path and if you refer this object
  use macro defined in /include/path.h to
  replace the absolute path such as /wiz/yue/obj.
  the detail paths macro, please refer 
  /include/path.h
thank you yue
bow
kiss yue


---
作者: Stefan
题目: HTTP server
日期: Thu May  7 22:14:57 1998
check out our Web server.

http://guanine.krdl.org.sg:5080/

Lei, you can set up our Web page now :)


---
作者: Pickle
题目: lag
日期: Thu May  7 02:13:04 1998
my connection to this site is extremely lag, if we can open
another place, that would be great...


---
作者: Stefan
题目: Wizard Panel
日期: Wed May  6 23:04:31 1998
Now, lei, yuner, fire, ljty, tset, pickle, yue are members of Mudlib domain.

Lei becomes domain lord, with the title 总编.
All others become 主编.

I think we should open discussion to all, so that we can sort out
things before it gets screwed. That is what this newsgroup wiz.com is for.

Notice that, newsgroups with the name wiz.* will only be readable by
wizards. Players can not read them by using "news". Although we have some
"wizard only" messages in other newsgroups, I think for the time being,
just let it be, since we are still under development. But, if you 
have something that is only supposed to be read by wizards, please 
post it here.

-stefan


---
作者: Stefan
题目: security stuffs
日期: Mon May  4 01:20:13 1998
Because I've not tested all, if you encounter any problem with
the security system, just drop me a mail. 

Welcome any doubts regarding the security things, you can 
send me mail or post your question, I will try to clear your doubts.

-stefan


---
作者: Yue
题目: i have same problem b4
日期: Sat May  2 16:01:54 1998
as title.


---
作者: Fire
题目: about mail
日期: Fri May  1 22:06:52 1998
today i check my mudmail here
I find a mail that even i didn't read it 
but also marked readed 
so must some one login  as fire or su fire to do
so
even this system can't support definate secure for
private
but, i think we'd better do it by ourselves
thanks guys


---
作者: Fire
题目: now wizard can't shutdown
日期: Mon May  4 18:46:54 1998
as title
sigh
slogan


---
作者: Stefan
题目: yue became member of Mudlib domain
日期: Tue May  5 03:43:19 1998
Now Mudlib domain has the following members:

yuner, fire, lei, pickle, tset, ljty, yue

Anybody wants to take the domain lord position? -:)


---
作者: Yue
题目: too lag
日期: Tue May  5 21:26:32 1998
here is too lag for working, b4 i fell good, what happened?


---
作者: Fire
题目: sorry from fire
日期: Fri May  8 02:58:45 1998
I am sorry for do nothing for this mud for several weeks.
I am really a little busy these days about my study,
but i will continue to do my best here
Now, several wizs are quite familiar with this mudlib
so i think it's not quite difficult to write
code for certain matters. Now the most ergent thing
we need is a detailed plan
I have promised to give a draft
and i will continue to do it.
ljty will give a plan for war.
These days, Stefan has changed something for the system.
as he suggested, we need discuss openly.
So i have sth to say.
I know he has enough reasons and right to do
what he has done.
but i can't say that i dn't feel even a littler unhappy for that.
now, except himself, all other arches has beed depromoted 
to wiz.
perhaps this will contribute to the safety of this mud
and also I hope it can contribute to the building of this mud
but, I think before he changed that, he should have
enough time to discuss with us or at least inform us. 
I dn't know others, but at least i didn't hear anything
from that.
I think that we are all members in a whole group
the uniform aims for all of us is just to make a
wonderful mud. And we are equal in someway.
I think it's quite rude to do such a big thing without discussing
with other members in this group.
I am sorry to say that.
but I hope to hear of his open appologize 
To do like a man to do !
fire


---
作者: Yue
题目: about npc's hp
日期: Fri May  8 19:23:03 1998
in the code i typed in
        int hp = random(150);
        hp += 200;
        set_cur_hp(hp);
        set_cur_max_hp(hp);
        set_max_hp(hp);
buy when i clone it out
hp first bing
不能从新设置年龄。
气血：   0 /   0 (   0 )  士兵：    0 /    0
兵种：( ---- ) 士气：  0  战斗力：0 
军资：    零两黄金        粮草：    零石

something wrong in set_hp()...


---
作者: Yue
题目: bug!
日期: Fri May  8 21:25:57 1998
update here
(i''m in /sgdomain/area/cities/luoyang/ly_zahp)
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
v
[errors] (yue) Error logged to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/buyi#261 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/yuyi#262 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/xue#263 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/zhu#264 (std/modules/m_wearable.c) at line 57

## ------- wiz/yue/obj/jia.c:4
## Cannot #include command.h
## #include <command.h>
## ------- wiz/yue/obj/jia.c:6
## parse error
## inherit CLOTH;
##              ^
what happened to that room?
i checked everything but still cant find out what's wrong


---
作者: Yuner
题目: Announcement
日期: Wed Apr 29 08:42:10 1998
 I am sorry that seems the mail system here has no security. Everyone can use
su to do the user-change. So if you want to talk very private
things, i suggest
u to use other mail systems.
#bell
#bell
  再过些日子，我就考完了，也就能投入工作了.:) *jump


---
作者: Stefan
题目: security system broken
日期: Mon Apr 20 03:47:57 1998
When did this happen? It is too bad that I just noticed it.
I'll fix it up ASAP. 

I urge you guys to be considerate, do not do bad things intentionally.

And also, pier, please send me an email explaining
that why you ftped all the source code back?

I have to say, you can extract all the info from the source code
but you can not set up another lima with it.



---
作者: Ljty
题目: 关于攻守城
日期: Fri Apr 10 07:44:05 1998
接受月神建议，攻城系统将增加用云梯登城楼作战.
但守方可落石, 但必须会落石skill. 和石头.

另外还将增加掘地道作战，守方可挖长沟应付.如果
城外有护城河则不如掘地道.掘地道是比较危险的.

具体指令与系统安排等完成后, 我会再post 出来.

如大家有什么攻守城idea.请mail ljty或最好post
出来, 我们争取把好的idea code 出来. thanks.



---
作者: Ljty
题目: 补充:关于战争
日期: Wed Apr  8 04:13:51 1998
   我想还要设部队的移动能力这个参数. 不同的阵法
A/D不一样, 移动能力也不一样. 这相当于个人的精力.
如果不顾实际赶路则会使士兵逃亡. 这三个参数.A/D
and 移动力, 可充分体现阵法不动. 而且各兵种也不
一样, 如骑兵与步兵消耗就不应一样. 但骑兵必须要
买马, 弓兵必须买弓箭.等等.



---
作者: Ljty
题目: 战争
日期: Tue Apr  7 16:03:22 1998
我有一点关于战争的想法. 我现在要做npc. 所以
我希望讲一些战争上的事.

我认为要加现有兵力，带兵能力，训练度，士气
，还有勇名与军师能力.

带兵能力由官职定, 现在兵力必须向君主要或征兵
, 募兵. 但君主不会常给, 或很少, 而征兵声望会
降, 而募兵要gold. 打死的兵不会recover. 只有这
三种方式, 但训练度可训练提高, 与勇名, 军师能力
有关, 高的话就训练的快, 而士气随时间recover, 但
必须在军响与粮草充足的情况下. 赏军可加强士气.

训练度高, 士气高还有勇名与军师能力影响打仗, 阵
前可单挑, 对方答应, 则如杀死对方, 可胜战争, 如
打败对方, 对方士气降. 如对方不愿单挑则对方士气降.
最多叫阵三次. 哪一方士兵打完了, 就败, 主将将被活
捉.命运就由对方决定了.

而单挑用对方, 对方的兵三分之一可归顺你, 如要则训
练度与士气均稍降. 另三分之一回国. 还有三分之一逃
走不见.
我想我可以来编这个warfight, zhenbing,(征兵),
mubing募兵.这几个file.如果大家同意的话.

如果这个解决了, npc也好编了.


---
作者: Fire
题目: welcome new wiz
日期: Tue Apr  7 05:01:42 1998
with the agreement of lei
now, we have a new wiz, xuan
he is an admin of xkx in peking university
his join will greatly improve our wiz team force
chat* welcome xuan
chat* addoil xuan


---
作者: Fire
题目: good job, ljty
日期: Tue Apr  7 04:54:40 1998
horse is another lift of fighter
ljty has done such a good job within so short time
thank ljty
addoil ljty


---
作者: Yue
题目: about es2's mudlib
日期: Sun Apr  5 00:51:06 1998
i upload my es2 mudlib to w web site
is in http://www.freeyellow.com/members3/mudsoftware/es2.tgz
use winzip to open it


---
作者: Row
题目: weapon produced
日期: Sat Mar 28 02:01:25 1998
based on the weapon database, i produced several weapons.
pls check the files at /wiz/row/obj/weapon .

你身上带着：
  一柄七星刀(qixing dao)
  一杆铁脊蛇矛(tiejishe mao)
  一柄三尖两刃刀(sanjianliangren dao)
  一柄青龙偃月刀(qinglongyanyue dao)
  一柄单刀(blade)
  一柄钢刀(gang dao)
  一柄大砍刀(dakan dao)
  一对铁蒺藜骨朵(tiejili guduo)
  一杆虎头钩镰枪(hutougoulian qiang)
  一柄大斧(da fu)
  一杆丈八蛇矛(zhangbashe mao)
  一对双铁戟(shuangtie ji)
  一对流星槌(liuxing chui)
  一杆方天画戟(fangtianhua ji)
  一杆长枪(chang qiang)
  一柄宣花斧(xuanhua fu)
  一杆亮银枪(liangyin qiang)
  一杆长戟(chang ji)

haha.
                           row


---
作者: Fire
题目: thank row
日期: Wed Mar 25 07:44:31 1998
thank row for your very good work
could you please make weapons with your desc
you can consult files under /sgdomain/obj/weapon
perhaps you need write some fight information for 
some kind of weapon such as 斧
this should check the file of /daemons/messages_d.c
thanks
bow row


---
作者: Fire
题目: about race
日期: Wed Mar 25 07:26:22 1998
the old lima has many races, but infact most
of them are useless for current sg
now in the sg, for NPC there are mainly two types
one is inherit from LIVING and
the other is inherit from MONSTER
in fact MONSTER is inherited from LIVING
so all the features that livings have will be
included in MONSTER
the main different from monster and living is
that the monster can fight but
the living can't
so you can kill 老黄牛 and 吕布 because
they are inherited from monster but 
you can't kill 牧童 and 店小二 because they 
inherit living
In this Mud, currently the animal would not
be considered (except horse) since no much
animals in the book of 三国
about the 老黄牛，it's just a test object
don't take it seriously, from every aspect
it is a common NPC.
most of the hp and other setup functions
are in the file /sgdomain/modules/m_sggift.c
you can use this function to initiate the feature
of a npc 
for example add set_sg_max_hp(100); in your npc file
will make the npc has the max_hp 100
but since there are many many data need to be 
initiated for a NPC, so we will develop
the classify function to seperate
the NPC into several groups
then just use several fun can performe all 
the initiation for a certain NPC
but this work will be done later.
I am sorry that i didn't give detailed
help file for mudlib functions that i have
introdued. I think some sample obj files can
solve this kind of problem better.
after the fight system, i will give a set
of samples to demonstrate the useage of most
mudlib function that need to be frequently used
thanks

fire


---
作者: Row
题目: about npc's hp
日期: Mon Mar 23 05:17:44 1998
i think human NPC's hp should like players, but it is
unreasonable that a animal like an ox will has the hp like
humam being. so...just like other mud, make a animal race, gather
all animals into one category. that will be more clear to identify.

                                          row
,


---
作者: Row
题目: about fight msg
日期: Thu Apr  2 08:30:36 1998
我认为在三国中的fight msg 可以参照ES2 系统所设定
的那样，例子如下：

影武者手握啃得精光的鸡腿骨头，眼露凶光，猛地对准郎中的右臂挥了过去！
(this line is hit msg)                                ^^^^
结果造成轻微的*挫伤*！
(this line is result msg)
( 郎中受伤过重，已经奄奄一息，命在旦夕了。 )
(this line is status msg)
郎中注视著影武者的行动，企图寻找机会出手。
(this line is wait msg)
郎中往影武者的右手狠狠地踢了一脚！
(this line is hit msg)
但是被影武者格开了。
(this line is parry msg)
影武者见郎中攻击失误，趁机发动攻击！

可以仿造ES2 分出不同的攻击部位，如例子中“^^^^”
记号所指的，每次攻击都会随机指定一个部位，而“*
 ***”所指代的就是伤害类型了。不同武器所造成的伤
害也是不同的。如剑类大多造成刺伤，刀类大多造成砍
伤，锤类大多造成淤伤等等。如此一来，所组合起来的
fight msg 也会比较丰富，而不太会翻来复去，千篇一
律了。另外我觉得可以采用ES2 的武功(skills)系统。
不管如何，三国中的武将还是需要武功支持的，可不能
任何人拿了一样的兵器都会使出同样的招数，造成同样
的伤害了。但如何解决枯燥乏味、浪费时间、精力的练
功，这就是后话了，总之，利用skills系统来区分武将
等级是可行的。

所以，现有的fight system还必须经过更多的调整才能
完善，希望大家多提好建议。

                                  row


---
作者: Yue
题目: agree row!
日期: Thu Apr  2 22:57:37 1998
i agree row i have lots combat file on ES2 if u guys want
made combat like ES2 i can support.
Yue


---
作者: Pickle
题目: wizshell
日期: Mon Apr 27 20:58:55 1998
stefan,

is there anyway you can install wizshell in this machine?
i'm very very lazy. :PPP i don't like ftp in and out and
update and edit->ftp in again if there's a small error...
anyway, i think it isn't _too_ difficult to get a wizshell
installed?

give it a shot?

*joythank stefan

pickle


---
作者: Yue
题目: NPC's hp ...
日期: Mon Mar 23 00:30:40 1998
老黄牛(niu) (i cloned out this NPC)
> hp niu
气血：   0 /   0 (   0 )  士兵：    0 /    0
兵种：( ---- ) 士气：  0  战斗力：0 
军资：    零两黄金        粮草：    零石
hmm
NPC should have hp like players ...


---
作者: Row
题目: more weapon database
日期: Sun Mar 22 07:26:21 1998
weapon database is basically set up.
pls check /wiz/row/txt/weapon.txt
any better suggestion is welcomed.

                    row.


---
作者: Yue
题目: a good site about mud 编辑技巧
日期: Sat Feb 21 15:07:58 1998
i just found out a really good site about mud 编辑技巧
http://www.etic.net.cn/mud/
enjoy!


---
作者: Xiaoxi
题目: 拜年
日期: Fri Feb  6 10:51:47 1998
过完春节了 给大家拜个晚年
xixi


---
作者: Row
题目: 新增地图
日期: Wed Jan 14 07:04:49 1998
《三国时代总地图西南部分》已经完工。

/wiz/row/txt/main_map1.txt


                         row


---
作者: Row
题目: 自绘地图
日期: Tue Jan 13 07:55:22 1998
参考光荣公司出品的《三国志IV》，本人绘制了《三国
时代总地图》，现西北部分已经完工，但由于本人的地
理知识不够丰富，诸多地点无法一一标出，也许还漏了
不少重要的地区，希望大家指正。

谨做参考：/wiz/row/txt/main_map.txt

                                      row


---
作者: Yue
题目: where have list of 'inherit'?
日期: Sat Jan 10 20:54:28 1998
as title


---
作者: Row
题目: 洛阳城地图初稿
日期: Mon Jan  5 10:08:16 1998
洛阳城地图初稿完成：/wiz/row/txt/luoyang-map.txt
时间仓促，必有欠缺，希望大家指出，以便改进。

                                         row


---
作者: Jiezhao
题目: bug
日期: Fri Jan  2 17:29:16 1998
errors ((none)) Error logged to /log/runtime
errors *Owner (/obj/pshell#821) of function pointer is destructed.
errors none (0) at :0
that is every time sb logon and quit i saw this


---
作者: Row
题目: about channel
日期: Fri Jan  2 08:42:47 1998
本人认为可以借鉴纵横的channel 标识方法，摈弃传统
的【闲聊】，取代于类似【论道江湖】等更文学化的词
汇。
以下为本人想的一些词汇，仅做参考。

newbie可以用【初涉三国】来替换。
tell及reply 可以用【密谈】来替换。
chat可以用【论尽三国】来替换。
say 可以【各抒己见】来替换。
时间可以用【日月星辰】或【昼夜变幻】来替换。
本人还建议可引入天气状况的设定，这样可以限制用计
的成功率及其他作用，可以用【阴晴变化】来替换。

抛砖引玉，希望大家可以提供更好的词汇及想法。

                                  row


---
作者: Jiezhao
题目: sanguo's webpage
日期: Mon Dec 29 19:02:13 1997
大家好！
我和月神做了个三国的家页，
仍在初级阶段，如果大家有身麽提议
请告诉我。

webpage address: http://members.aol.com/sanguozhi/sanguo.html
everyone please go there and check it out
tell me what you think.

P.S. it's still under construction :)


---
作者: Xiaoxi
题目: 想法
日期: Sat Jan 10 11:01:26 1998
对于三国，我发表一下想法。hehe
首先我认为，想把三国写成一个战略的MUD，
难度是很大的。不如先有个过度，先写个给
玩家，自由度很大的MUD，我的设想如下。
1. 抛弃 fight 练功方式，提高金钱的能力，
玩家的武功不是再以fight 增长。
具体一下：开设几个武馆，玩家习武是以
交钱为方式，钱的多少决定你能学多少，
钱的来源：新玩家可以通过杀一些野生动物
卖钱得来。老玩家可以通过完成任务和野生
动物卖钱得来。
2. 提高钱的重要性是为了使玩家可以选择，
经商。也就是加入一个商人的系统，商人
可以经过倒买倒卖的钱，（掺照大航海系统）
城市之间的物价不是固定的，比如粮价，
是以天气的好坏来决定的，也就是城市之间
的天气是不一样的。当然钱是不好争的。
商人有钱后，可以雇保镖，可以请杀手。
不定期的朝廷要收税，比如：刘备要进
行一次战争，为购军需，可以向商人布施
3. 加入任务系统，任务由各方将领给予，
还以刘备为例：新玩家可以向刘备的将领
领取任务，任务完成后，长勇名（暂定）
得金钱，刘备的信任度上升，当勇名达到
一定程度，才可以向高一级将领要任务，
任务由简变难，比如：刚开始，可以以
本将军要喝酒，杀一野兔为任务，到
最后，以攻下某座城为一任务。
4。再系统中，允许玩家自立为王，比如：当
玩家杀了某个城市的守城将领，玩家可
以自立为王，但系统控制的三个国家会
派人抢夺地盘。hehe
先写这么多吧！头有点晕！想法很大，不知冲
和说起，大家问我吧！提提问题！ok???;   


---
作者: Yue
题目: ...
日期: Wed Feb 11 00:22:22 1998
i want work on inherit(weapon)
where have list of inherit?
i want write come new inherit like blade whip ...
Yue.


---
作者: Row
题目: 关于《三国》中的军队
日期: Sun Mar  8 07:48:09 1998
对于以国与国之间的战争为主线的《三国》MUD 来说，军队是一个
举足轻重的要素。与目前流行的武侠MUD 不同的是，《三国》绝对
不是一个凭借一己之力便可以打天下的世界。如果你想单枪匹马与
五百名铁甲钢刀衮牌兵相抗衡的话，结果不说也明白，你将会死的
很难看 (除非你是在曹军中几进几出的赵云？但大家都清楚，赵云
有这么好的运气，完全是因为曹操的爱才) 。所以拥有一支强有力
的军队，将是在《三国》中成功的关键。

但从编程的角度上来看，如何处理军队这样一个比较复杂的物件，
确实是非常棘手的。就我个人的观点，玩家不会满意自己的军队只
在HP值里用两三个简单的数字来表现，也更不会接纳疆场上殊死的
搏杀只通过几个数字的增减来体现，起码这太抽象了。所以若要使
军队这个概念变得直观，就应该让玩家能够“活生生”地看到自己
所带领的军队，并且可以按照自己的意愿来支配军队的行动。如此
一来，将“军队”设计成一种特殊的NPC 或者OBJ 会比较理想。但
由于军队中士兵的数目将会因各种情况而发生变化，所以就必须区
别“军团”和“士兵”。可以规定，50名以上的“士兵” (具体数
字可以另定) 组合在一起便可称之为“军团”，将会拥有比较显著
的团体攻击力及防御力等，那样的话，50人便是“军团”士兵数的
下限，而上限可以定为5000人或10000人。 当某将领所拥有的士兵
数不到50人，那他的手下就不能作为一个军团而实施有效的行动，
并且不会拥有相当于“军团”的攻击、防御力。而作为一个军团，
可以接收“军团指令” (Military Group Cmds)，如原地待命、侦
察、摆阵、突击等等。当然，我们可以允许玩家将一个5000人的军
团分割成若干个较少数目的军团，以便实施更加灵活机动的行动，
但同时为了防止玩家利用这点滥造出100 个50人军团，我们可以规
定每个军团都必须由一名以上，三名以下的将领带领，而找齐这么
多将领就不容易了，俗话说：千军易得，一将难求嘛。

至于如何设置军团的各类属性，我认为，可以先精心设计单个士兵
的属性，如攻击力(attack power)、攻击性(attack ability)、防
御力(defend power)、防御性(defend ability)、灵活性(dexter-
ity) (此项属性的设置有关于士兵的疲劳度，而我认为正如《侠客
行》中精力的设置，《三国》中疲劳度的出现将会使游戏变得更有
真实性，每个人每做一件事，每走一步路都会增加一定的疲劳度，
这样就使得适时休息更为重要，由于《三国》内不可能出现使用内
力恢复的现象，所以就不会发生几天甚至几月不睡觉得荒谬局面。
在《三国》里，你天生的属性及所佩带的装备及所使用的工具都将
会影响疲劳度增加的多少及恢复的快慢。很明显，一队轻甲骑兵的
灵活性无疑比一队重甲步兵来的大得多，休憩的间隔也将长得多，
但同时防御力会小得多。当然灵活性高，防御力也能得到额外的补
充，但以上的例子也表面了各种兵种，装备属性的相生相克、互有
长短的特点。) 、士气(moral) 等等，同时设置一些便于玩家直观
了解的属性，如国籍(nationality) 、所属(subordinate of)、装
备(armed with)、目前接受的指令(current status)、相应的描述
(describe)等等。设置完了单个士兵单位，便可以通过军团人数简
单的推算出军团的各类属性，并可以相对乘上一些浮动的百分比使
其更加合理，而且领导军团的将领本身的能力也可以对军团的属性
有额外的作用，如猛将张飞所率领的骑兵就会有更强的突击能力。

发动一场战争，需要各类兵种的相互配合，需要淋漓尽至地发挥每
位将领的个人能力及士兵的团体属性，需要灵活多变的战术及有效
的策略，这样才能成为战局的主导。

以上是本人对军队设计的一些简单看法，关于各类军种及详细属性
等设计将会在以后提出。希望能够抛砖引玉，与各位共同创造一个
宏大的策略战争多线型MUD 。

                                                  row


---
作者: Yue
题目: why i can save my file at my own dir?
日期: Mon Dec 29 18:58:00 1997
as title


---
作者: Yue
题目: please keep my job
日期: Fri Dec 26 18:19:13 1997
wiz told me about i'm kid can't be wiz
sigh
whynot
i really want be a wiz
i need learn C here
here is very good place to learn C
so i really want be wiz
so please keep my job


---
作者: Dan
题目: 三国
日期: Tue Dec 23 06:40:58 1997
我没法发完整的文章我只好把自己的想法放在/wiz/dan/note/sanguo.c里
大家可以自己去看或谁帮忙发在这儿


---
作者: Stefan
题目: Directory Structure
日期: Wed Apr 16 04:20:14 1997
(转载自documentation)
        ----secure    Objects that need high security level, such as
        |             master.c and security daemon, etc.
        |             
        |--daemons    all the daemons besides those in /secure
        |
        |--include    include files used by all the lib programs.
        |
        |-----data    player data, mail data, news data and etc.
        |
        |------std    all the standard objects and modules which is
        |             designed to be inherited.
        |             
        |------obj    some ready to use objects at the mudlib level,
        |             such as mailbox, shells etc. 
(root)--|             
        |-----cmds    all player and wizard commands.
        |
        |----trans    objects that needs to bypass security check.
        |             (transparent to security manager)
        |             
        |--domains    all the rooms, npcs, objects of individual areas.
        |
        |------wiz    all the wizard directories.
        |
        |------log    all the system log files.
        |
        |------ftp    the ftp directory for anonymous ftps.
        |
        |-----help    help files for commands, efuns, and wizard tools.
        |
        |------WWW    WWW related stuffs.
        |
        -------tmp    just a trash bin.


---
作者: Lei
题目: color
日期: Thu Dec 25 04:37:58 1997
can set color now.
add #include <ansi.h> first.
then like "+HIW+" to color and end by "+NOR+"
You can go to /wiz/lei/txt/color.txt to get what color we can use.



---
作者: Yuner
题目: wiz rules
日期: Sun Dec 28 10:10:41 1997
Wiz rules are ready now, all wizs including Admin please follow the rules,
if anything happened, please settle it according to the rules, for
more details
please go through /wiz/yuner/WIZ_RULE.
After that i have to leave here as i said 2 weeks ago, lei, fire and
pickle will
in charge the whole mud, after i quit, my opinion will not be
counted into Admin
's discuss unless i come back and join the group again. Addoil all!


---
作者: Row
题目: about addemote
日期: Mon Dec 29 00:57:47 1997
在寂寞英雄中，addemote是如下设置的：
指令格式 : addemote 0 0 emote
 
这个指令可以修改 emote 或列出其内容. 

-p 参数则会列出指定 emote 的内容. 列出的顺序与编
辑 emote 时相同.

-d 能删除此emote. 当然只有你是WIZ或是该emote是自己写的。
 
输入 emote 讯息时有三个项目: 没有目标, 指定目标或是对自己. 若
不想有某项讯息, 则直接在空白行输入 '.' 跳过.
 
 
编辑 emote 时可以用以下的符号来表示:
 
      $N              - name of emoter 作动作的人的名字
      $n              - name of target 目标的名字
      $P              - pronoun of emoter 作动作的人的代称
      $p              - pronoun of target 目标的的代称
      $S              - 对自己的尊称 query_self
      $s              - 对自己的贱称 query_self_rude
      $C              - 对自己的辈分关系
      $c              - 对别人的辈分关系
      $R              - 对别人的尊称 query_resprct
      $r              - 对别人的贱称 query_resprct_rude

可以参考下。

                                      row
                                     97,12,29


---
作者: Yuner
题目: To all new wizs
日期: Sun Dec 21 21:46:39 1997
At start, please ask those senior wizs if u have any problem, don't try to
clone those *.c which is not a moveable obj and don't mistype the filetype
espically the *.c (eg. WELCOME is a txt file, don't type the name as welcome.c
which can cause system fault). To get familar with here, the best
way is to ask
other wizs, read the news, know the structure of directories first, then the 
files in the dirs and their uses, after that, u can try to do some simple 
rooms, npcs or objs, for higher level, u can try some new features which u 
think can use in our 三  国  志 :) , but remember, if u want to
change anything
related to important system files, please discuss with Admin first,
and remember
to do a backup file, if u are using edit, please use I command to
log all u did
into log file, then if sth is wrong, we can know where is wrong and fix it
三 国  志 is a exciting topic and a whole new area in the world of mud, it
is a 战略型游戏，并继承其它优秀pc game的优点，将会使所有的人耳目一新，可以说
是开了文字Mud的先河，大家可以在这里发挥丰富的想象力，将它建设的多姿多采，
所有的这一切都有赖于大家的努力! *addoil all!


---
作者: Lei
题目: login.file
日期: Sat Dec 20 01:28:45 1997
                 中文Lima之三国
欢迎大家来到中文Lima之三国的世界。
我们这个游戏还处在建造当中。同时我们也需要您的帮助
与支持。如果您对三国这个题材很有兴趣，并且有一定的
UNIX和C，C++的基础，那么我们很欢迎欢迎你加入我们的编辑队伍。
当然你只是有一些好的点子，也可以写下来冣我们。
请mudmail冣Lei or Fire.我们会在一个兴起之内冣您答复。



---
作者: Fire
题目: 我的三点意见：
日期: Sat Dec 13 17:41:35 1997
1. 取消pot
pot的概念很奇怪，在现实中很难有真正相对应的东西。
徒弟可以时时向师傅学习，(只要有足够的精神)学习的速度与可达到的最高等级
由经验(道行)来定。另外，刚学到的东西由于只是理论上的，威力当不是很大。
只有在充分地实践后，威力才能真正显示出来。
2. 取消战斗长经验的方式。
在其他MUD中，经验主要从战斗中得，所以，一般战斗总是持续的时间越长越好。
我任为经验应在杀死对手或打败对手时或得，这样玩家才会尽量学最利害的法术
同时要求速胜。
3.我们虽然叫封神榜，可从原作中提取一些素材，但不必仅限于次，也不必太
结合原作。这样可能使没看过此书的玩家处于很不利的地位
终究《封神榜》不及《西》和《金》流行。
4. 特殊招术要专门学，因为有许多master可从不同的master学不同的招术
不一定要拜师，但可能要完成一些quest或task才能学到，另外基本等级要达
到一定成度才行。
学会高级的招术，低级的就可以adadon掉。


---
作者: Lei
题目: 封神榜的发展方向
日期: Fri Dec 12 07:04:10 1997
现在的新泥巴重出不穷。而封神榜如果想在中文泥巴领域闯出一片天空就
不得不另辟奚径了。也因为如此，我们选择了Lima作为基础，而没有跟随
其他的泥巴用ES2。毕竟ES2是十年前的产物，而Lima只不过三岁而已。在
程序上Lima有很多先进的地方，因为我不在行，也不必多说。

我这里想谈的是怎样使封神榜在故事主题，得经验的方法，和游戏目的上
做的别出心材。现在看来，老的靠打架涨经验的方法已经落伍，而且因为
这样很难防止玩家使用机器人，所以我们肯定不会使用。
目前较为吸烟玩家的有XYJ的NK系统，风云的TASK和QUEST系统。我个人认
为NK结合TASK是最好的选择。对一个新玩家，TASK是很合时的。我们可以
设计一些诸如送信之类的任务，每个门派都会有不同的若干任务。一个新
手可以通过完成这些任务熟悉地形，且顺利过度到中低手的阶段。我还设
想应该强调GROUP WORK(不知程序上要求如何)。这之后一个玩家就可以完
成一些诸如杀强盗土匪之类的任务。这不可以被称作NK，还是属于TASK范
围。真正的NK应该是在成为中高手之后杀哪些有名有姓的NPC。反正封神榜
的NPC多得很，又都爱打好斗。从这时起，玩家便可以完全靠NK来涨经验。
听起来和风云很类似，但实际上却大相径庭。这是由故事背景决定的。

封神榜里主要是三大教：阐教，西方之教和截教，二正一邪。还有两大组
织：西歧周文武王，朝歌商纣王。一正一邪。我设想，一个玩家在选择师
门时拥有自己的自由，而以后也可以任意选择弃暗投明或是助纣为虐。出
山之前，主要完成师傅布置的任务，同时NK。加入组织以后，为组织出力。
甚至可以出阵邀战。

游戏的终极目的可以学学西游记。把每个战役理解成一个QUEST，玩家完成
一定QUEST后便可自动升级成编辑(巫师)。像西歧方一高手，终于帮助武王
攻下朝歌，逼死商纣王后也就完成了历史使命，可以退休了，同时他她的
名字也会永记史册。我们当然会把过程做的难一点。

下一篇我会写封神榜法术的设想。老话一句，有什么意见请赶快贴上来，
我们好一起讨论，以决定最好的方案。


---
作者: Stefan
题目: >About Score
日期: Thu Dec 11 23:54:45 1997
why nobody try to see what's here in lima already? the gifts, the hp, etc...
You'll be surprised if you look into the gifts here :)


---
作者: Lei
题目: About Score
日期: Thu Dec 11 07:35:22 1997
I think no need to display XYJ's. Here I want to show you 寂寞英雄.
膂力：[ 17]     胆识：[ 15]     悟性：[ 22]
道缘：[ 23]     佛缘：[ 22]     根骨：[ 21]
Seems 身法 is not important which is not mentioned in XYJ either.
Becoz these gift is about how to get exp. and fighting system will
be written by Kane. So it'd better to decide what we need after Kane
come back.
Anyway I think 膂力：[ 17] 悟性：[ 22]道缘：[ 23]  根骨：[ 21]
are needed in FSB. Do you think anything else should be added?
Another part of score is quite interesting... It also can attract
players to work for it.
----------------------------
In XYJ: 战斗攻击力 9527 (+0)           战斗防御力 10766 (+2)
(I dislike this. Becoz in real fight, anything can happened... If we
keep these figures, players will keep qurying why... can beat ...)
ＰＫ道行增加： 五十一年十五天六时辰
ＰＫ道行减少： 十七年一百八十九天三时辰
ＮＫ道行增加： 三十三年四十五天九时辰
This is quite interesting...
We definetely will use M-#M-NM-#M-KM-5M-@M-PM-P since player will
get exp mainly by
this way when he or she is a mid-highhand. About ＰＫ道行增加：, I prefer
whole wiz group to make a decision.
----------------------------
In XKX : 神  ：     206  江湖阅历： 140    (It is about what kind of
NPC you kill)
你到目前为止总共杀了 312 个人，其中有 36 个是其他玩家。

你到目前为止总共死了 17 次，其中 10 次是正常死亡。
(This is an old way... but not attractive... XYJ does not have it
at all, but I will prefer 寂寞英雄 style.)
---------------------------
寂寞英雄 : 死亡次数： 1                上次死于 李春来 之手
^^^^^^^
(This is quite interesting, Make you remember who killed you)
江湖名望： 0  [0/0] (sounds better than 江湖阅历: )
And we may use another name which relates to FSB
Need how Fengyun works... Sunnie may help to add FY's resource...
My idea is we will follow other muds, but not follow a pecific mud...
We will choose best and most reasonbale hp, score to our players...
This is just my opinions, I hope other wiz will have better ideas. If
we can make sth spcecial, that is real 突破。
Anyway, pls post your idea any time, and then we can discuss:)



---
作者: Lei
题目: HP system
日期: Thu Dec 11 02:41:31 1997
Now I am beginning to write hp and score.
First of all, we need to make sure what we need.

About HP
2 most popular mud's hp as following:
About 侠客行
----------------------------------------------------
精： 765/  765 (100%)    精力：  966 /  966 (+1)
气： 661/  661 (100%)    内力： 1164 / 1164 (+0)
食物： 241/  300         潜能：   16 /  133
饮水： 261/  300         经验： 109716
----------------------------------------------------
About 西游记
----------------------------------------------------
气血： 196/  196 (100%)    内力：    0 /    0 (+0)
精神： 169/  184 (100%)    法力：    0 /    0 (+0)
食物： 256/  240           潜能： 82
饮水： 196/  240           道行： 五十八天
----------------------------------------------------
We can see 精：气：食物：饮水： all are basic elements...
潜能：经验： are same with 潜能： 道行： which also is basic elements.

在这几个元素上看来我们不得不跟随前人的脚印。当然如果有谁能想到别的来取
待，那将是我们的一大突破。兄弟姐妹，加油啦！

Pots and Exp also is basic elements, which we must have. However, we
can say it in a different way in Chinese.

内力法力是最值得作文章的地方。我个人认为内力是可以不要的。因为在封神榜
没有特殊武功，不存在加力的问题。而内力帮助读书，练功，吸气的功能都可以
由法力来取代，也就是说把二者合一。这里我们可以借鉴老侠客行的模式。以前
侠客行的精力形同虚设。内力有一切作用。后来精力有用是侠客行编辑们增大游
戏难度所为。

也就是说我理想中封神榜的模式应该是:
精： 0/    0 (100%)
气： 0/    0 (100%)
法力： 0 /    0 (+0)
食物： 0/  240           潜能： 100
饮水： 0/  240           道行(经验)： 0
-------------------------------------------------------



---
作者: Fire
题目: about semote
日期: Thu Dec  4 08:47:26 1997
i am writing new semotes
there must be many mistakes and shortages
anyone has any ideas or find anything wrong
please post here
thank for your help
xixi


---
作者: Lei
题目: 小村
日期: Mon Dec  8 04:33:41 1997
在烈火的努力工作下，新的整套semote已经完成，这里我代表其他所有
编辑向他表示诚挚的谢意。
另外烈火也发起建造封神榜自己的第一个房间。这是一个编辑们的度假
村。放置这样一个小村的目的是让新编辑们熟悉编写房间和一些简单NPC的程
序。目前主要是烈火和苑壁在进行建造工作。不论是谁都可以加入帮助他们。
当然因为他们是新编辑，工作上难免会有一些瑕纰，所以希望老编辑们，
如STEFAN, SNOWCAT,PICKLE可以伸出援手，看一看哪些地方需要该进，哪些
程序用另一种方法会更好。
下一部是等KANE会来后编写SKILLS&FIGHT&KILL的程序。在此之前，希望
STEFAN可以先做一点，并不要求你做完，你做一点，日后马龙的工作就容易上
手一些。加油干吧，多谢了。



---
作者: Lei
题目: 三国
日期: Mon Dec 15 03:58:03 1997
These several days I was adviced to write Mud of Sanguo, and I think it is 
a good idea. Reasons following:
1: Mud based on ES2 can hardly beyond XKX,XYJ,FY. These 3 muds have their 
own features, and a lot wiz have worked for it for a long time...hmm...
So if we want to explore a new theme, it is very difficult to dingstinguish 
with these 3 muds and very difficult to beyond them.
2: FSB is not a bad idea. FSB book supplys us a full background, we need not
to think about new ideas. However, it is not so pupular as Jingyong books.
As we all known, XKX is most successful chinese mud until now. I think its 
success partly comes from well-known Jingyong novels. Although FSB
has a strong
background, it is still lack of 知名度。
3: Sanguo also has a very good 知名度 for its successful PC games. I supporse
that every1 plays mud who also play PC games. To a chinese PC game
player, there 
is less 10% possibilities who has never played Sanguo games.
4. Fire mentioned Sanguo may be too difficult to do. Yes, it is.
   But just now I realize that why we have not used ES2 as our
mudlib but Lima?
becoz every1 of here want to make a good mud, but not follow others.
If we just 
try to write FSB, and we also want to beyond XKX,XYJ,FY... I think it is also 
a very difficult work, not a bit less difficult than Sanguo.
So we not focus our energy on a new topic? Nobody do that before.

Addoil... I will post completely steps what we will do for Sanguo if
you support 
my opinion. If any1 of you think FSB is still better, just post ur opinions or
send me a mudmail.
Regards!



---
作者: Sunnie
题目: @_@
日期: Tue Dec 16 04:56:34 1997
拜读了几位巫师的留言后，颇受启发，不由的也想班门弄斧，谈谈自己的想法。
封神榜作为游戏的内容，知名度稍差。不仅远不如金庸，古龙小说的情节，
人物那样为大众所熟悉，也比不上西游记。从吸引玩家的角度来讲，这不能不算
是个缺憾。但是从另一方面，可能反而能给游戏的设计者更大的发挥余地。以金
庸小说为蓝本的侠客行，以古龙小说为基础的风云，以及根据唐僧取经改编的西
游记，均有其独到之处，但未免受原著情节的限制，游戏设计者稍做一些与原著
不符的改动，极易招致批评。窃以为若仍走这条路，不仅珠玉在前，难以超越，
也很难有任何新意。此时，我不得不要提一下东方故事系列。事实上东方故事并
非取材于某部知名的小说，但不论是情节的设计，武功的构思，都极尽巧思，令
人有眼前一亮的感觉。在当时来说，它是以完全不同以往的面貌出现的。我们的
游戏是否能开创一个崭新的天地，首先就是取材。为什么我们一定要以某部已为
人所知的小说为内容呢？各位巫师天纵奇才，当可编写我们自己的故事。艺术源
于生活，一花一世界，一叶一如来，信手拈来，处处皆是文章。就当大家集体创
作一部小说吧。至于小说的内容，似乎行侠仗义，正邪争斗是中文泥巴永恒的主
题，中间穿插些英雄气短，儿女情长之类。若是哪位能有脱出武侠巢窠的想法及
构思，那再好不过。
匆匆数言，盼能抛砖引玉。


---
作者: Yuner
题目: about sanguo
日期: Sun Dec 21 01:15:50 1997
Stefan has pointed out the difficulty of doing sanguo,but lei fire have a good
solution to take the bing as a variable of player, just like the old version 
of san guo pc game. The problem is, there is only 1 type of bing, or 1 group  
of bing belong to u, if u want to define 3 groups of bing as a gift of player
,how to order them to act different things? But i believe this pro
can be solvved
if we can think and dicuss it carefully, other problems such frame
or how to combine pc game with mud, how to distinguish the pc game with 
mud,since for pc game, play once, then game over,but for mud, we need players
to continue their play, this is also a pro. Lei mentioned another pro, if we 
follow the form of TK(tai ge li zhi zhuan),1 player can have 1 city
if he is strong,but when he is not on line, how to deal with his
city? put a dummy? or close his city?also a problem....so we need
all wizs to give ur suggestions to solutions to those problems,if we
can do this job, we will be another annihilator grouup since we make
a whole new area of mud!addoil!


---
作者: Stefan
题目: A Short Introduction To LPmud Programming For Newbie Wizard
日期: Wed Apr 16 04:17:09 1997
(转载自documentation)

        Maybe you are new to mud programming, but you should already
have some experiences of playing mud. I assume that you know what is
a mud and how a mud interacts with players. This introduction does  
not cover LPC programming, for which you can always refer to the books
I put in the /help/LPC directory.


How does a LPmud work?

        A LPmud consists of two parts, one is the driver (we are
using MudOS driver) and the other one is the LPC library. When a mud
is started up, the driver will load an object called master.c and
master.c will tell the driver to load some other objects into memory
and run them. The driver will keep running until a shutdown()
function call or a bug makes the driver crash.

        A driver is merely to keep running LPC bytecode (if bytecode is
not in memory, the driver will compile LPC program into bytecode first)
and to provide system calls to LPC objects, such as an incoming connection
request or heartbeat and call_out pending functions (refer to LPC
books if you need to know what are heartbeat and call_out).

        All the LPC programs form a so-called mud library, or in short,
mudlib. There is no particular rules on how the lib should be coded, but
all existing LP mudlibs follow the same structure, more or less.

    master.c    It is the first object loaded into memory, it initializes
                the whole mud, defines system routines and starts up
                daemons. If it fails, the mud won't start up.
            
simul_efun.c    It provides functions that override existing efuns (
                external functions, provided by the driver), defines
                new functions that will act as if they were efuns
                through out all the LPC programs in the mud. They are
                called simulated efuns. 
                
     daemons    Daemons are programs (LPC objects) that provide basic
                services to all other LPC objects, there may only exist
                one object for each daemon (daemons are not clonable). 
                Things like listening to the port to accept outside
                connections, security management and combat processing,
                are all written as daemons.
            
     objects    An LPC program can create an object. If there is a call
                to an object before it exists in memory, the driver will
                compile its program to bytecode, load it into memory and
                then execute the function call. It is called a master
                copy of that object. If this object is cloned, the driver
                does not compile the program one more time, instead, it  
                creates a copy of the master copy and use it. Objects    
                form the world of LPmud.


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Group
题目: thanks a lot
日期: Sat Mar  6 01:27:42 1999



---
作者: Fire
题目: row and group's wiz position have been re assigned
日期: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
作者: Fire
题目: about the area 名称
日期: Thu Mar 11 02:53:05 1999
I change the area in to be the same as area_id
this will reduce lots of troubles


---
作者: Fire
题目: about the path
日期: Sun Mar 14 03:44:56 1999
for current mudlib construction
most files are under /sgdomain
but still some important files under /daemons
and /std, 
for /std the most interesting part is /std/modules
so I think that we probably need make them
under Mudlib:sth and so on


---
作者: Stefan
题目: about security level here
日期: Sun Mar 14 01:36:21 1999
Since the mud crashed, part of the security system is not up to date,
I am rearranging it...

/sgdomain is under privilege Mudlib:sanguo, which has been added
to group and flee, you two please check if you can modify things
under /sgdomain. 

Other 'alive' wizs, if you want it also, please let me know.

PS: /monster, I think should be moved to under /sgdomain

stefan


---
作者: Fire
题目: 地区整理的建议。
日期: Tue Mar 16 05:12:03 1999
目前，在测试版里的19个地区大部分已经完工，但是longxi,
taiyuan, xianyang 三个城市还是只有两个房间。特别是太原连
地图都没有。为了准备尽快推出测试版，我们需要尽早完成这些
区域建设。
具体工作如下：
1 完成上述三个地区的房屋编写。描述可以简单。
2 调整一些地区的房屋，尽量使每一个房间有一定的功能。同时使
  地区的房间数量分配尽量与下面的参考表相符。
3 删除没有连接的出口
4 加入NPC和一些OBJ (这需要与其他系统协调)
地区房屋屋数量参考表:
地区类型      大城市   中等城市    城镇     村庄    关卡
会议室          1        1          1        1       1
集合场          1        1          1        1       1
驿站            1        1          1        1       1
饭店            1        1          1        1       1
客店            1        1          1        1       1
银行            1        0          0        0       0
当铺            1        0          0        0       0     
马场            1        1          1        0       0
服装店          1        1          0        0       0
兵器店          1        1          0        0       0
铠甲店          1        0          0        0       0
裁缝店          1        0          0        0       0
铁匠铺          1        0          0        0       0
书店            1        0          0        0       0
花店            1        0          0        0       0
珠宝店          1        0          0        0       0
药店            1        0          0        0       0
房间总数       30-50    30-40      15-30     10-20   10-20 
非角色NPC数    10-15    5-10       5-10      2-5     2-5


---
作者: Fire
题目: 三月中工作计划与总结
日期: Thu Mar 18 18:30:32 1999
1 middle level job and basic level job
现在已经有了六个太守派发的中级任务和一
个太守派发初级任务。但是我们还需要更多
的任务。我认为主要是中级任务。因为玩家
当官前的时间很短。所以我们希望在一到两
周内再增加六个太守派发的中级任务和两个
太守派发的初级任务。
一些帮助可见 man jobrules 和 man jobhint
任务的开发要由flee,rou和group 负责。fire
将协助编程和测试。
2 三国角色NPC。
最近在yuyin 的努力下，角色NPC的数量已经
达到了53个(用 listchar /1 /v is_tmp 0 /v type 0)
查询。yuyin将主要负责增加角色NPC的工作。
争取在两周内使角色NPC的数量达到100个。这
也许是测试板可以接受的数目。我们有19个地区
平均一个地区五名角色NPC还是合理的。
3 三国主页。
在jams(swallow) 的努力下，我们终于有了一个
主页和一个很不错的地址：http://sgz.yesite.com/
开通才几天，访问人数就达到80(期中包括我的
10次，hoho)。这对我们今后的宣传一定大有好处。
jams的工作将主要集中在主页上，早日完成图形板，
并增添新的内容。同时建议使用lima提供的CGI，使得
玩家在主页上可以直接完成都lima的帮助(这可以节省
一大堆的文本更新工作)；直接读lima留言板。甚至可
以已一个特定角色的身份，如水境先生来看到MUD
的当前景向。
4 玩家帮助
我们知道，本三国MUD虽在创新方面享有很高声誉，但
“玩家人数始终徘徊在1-5之间，所有中文MUD中没有比
这更惨的了”(引自加拿大三国)。但现在我们终于有了
十名左右的玩家。这对我们这个尚未成熟的系统，是一
个很大的考验。我们有很多没有经过玩家检验的设计，
如果这些新玩家对这些设计感到满意，对我们将来的
发展一定大有好处。反过来，如果由于我们的疏漏，使
新玩家不能充分了解我们的设计，产生误解，可能会对
我们的将来产生负面影响。因此我们提升guanfeng为巫
师，专门从事介绍新玩家和帮助新玩家的工作。但由于
我们的核心开发还没有完，所以还不适宜大规模宣传，
介绍太多新玩家。能保持十多名玩家在线就可以了。
5 安全系统。
自从上次当机后，系统部分总有些不爽快。
a finger 不能显示中文名。
b 玩家也可以用finger 查到所有信息
c 不能 cmd suicide 了。
d 在提拔新巫师时，新巫师的auto logout ， auto login
  和su 命令有严重的BUG 希望stefan抽空把这些BUG fix
一下。
6 地区建设。
地区建设我已经写了一个方案，见 man areahint。毫无疑问
地区建设和写描述是件枯燥的差事，所以在此我特别感谢row
和group和benben他们顽强地完成了许多枯燥的地区建设和战
争地图的设计。下面我将和benben 玩成余下的地区。并作一
些房间功能，地区平衡，地图更新的工作。同时希望对此工作
感兴趣的WIZ帮助参预，这虽然是一件枯燥的工作，但也是一
件相对简单，容易上手，见效快的工作。hoho
7 简单NPC
我们的大部分地区荒芜人烟，走在街上，心理毛毛的，可以设计
一些简单的NPC。女丫鬟，店主等。这个工作不太麻烦，就由我
来作好了。谁要喜欢，也可以让给你。
8 特殊NPC。
这些NPC不同于角色NPC如(刘关张)也不同于简单NPC如店小二，
水境等。他们由CHAR_D直接控制，但不参预三国的争斗。这种
NPC包括商人，小男孩，闲人，强盗，小偷等。这种NPC设计较
复杂，但由于由CHAR_D控制，可参预复杂的JOB系统。同时具有
非常大的灵活性。对于设计中级JOB的巫师，最好可以掌握设计
这种NPC的技巧。
9 物品系统
这个系统我们一直比较薄弱，但由于我们的角色与地区系统已经
趋于成熟(这两部分非常重要，是本MUD的精华，新WIZ请花时间了
解。核心文件是/daemons/char_d.c /daemons/area_d.c 以及
/daemons/char_d/ /daemons/area_d/下的所有文件。现在我们计
划物品系统。它包括几个部分：
a 饮食部分
b 服装装甲部分
c 兵器部分
d 马匹部分
e 书籍部分
f 宝物部分
这部分和战斗系统，HP系统和SKILL系统有非常大的关系。由fire
作初期设计和协调工作。
10 国家会议，国家战争和玩家力国
这是一个非常大而且与其他部分关系非常复杂的一部分。等上面大部分
工作都已经明了。在开工吧。


---
作者: Stefan
题目: 错字及标点
日期: Fri Mar 19 23:38:36 1999
这个问题比较影响美观 :)
请个位写的时候多留意啦...

另外所有的 feelings 我从前都整理过，后来新加的一些有不少错字和标点的问题，是谁
加的，请以后多留点心 :)

标点如果出现在中文当中请尽量用全角标点，句号请用。而不是．



---
作者: Stefan
题目: 错字及标点
日期: Fri Mar 19 23:38:36 1999
这个问题比较影响美观 :)
请个位写的时候多留意啦...

另外所有的 feelings 我从前都整理过，后来新加的一些有不少错字和标点的问题，是谁
加的，请以后多留点心 :)

标点如果出现在中文当中请尽量用全角标点，句号请用。而不是．



---
作者: Stefan
题目: 错字及标点
日期: Fri Mar 19 23:38:36 1999
这个问题比较影响美观 :)
请个位写的时候多留意啦...

另外所有的 feelings 我从前都整理过，后来新加的一些有不少错字和标点的问题，是谁
加的，请以后多留点心 :)

标点如果出现在中文当中请尽量用全角标点，句号请用。而不是．



---
作者: Row
题目: about 错字及标点
日期: Sat Mar 20 07:16:23 1999
申请纠正错字及修改标点的工作。:)
chat* raise row


---
作者: Fire
题目: 三月中工作计划与总结
日期: Thu Mar 18 18:30:32 1999
1 middle level job and basic level job
现在已经有了六个太守派发的中级任务和一
个太守派发初级任务。但是我们还需要更多
的任务。我认为主要是中级任务。因为玩家
当官前的时间很短。所以我们希望在一到两
周内再增加六个太守派发的中级任务和两个
太守派发的初级任务。
一些帮助可见 man jobrules 和 man jobhint
任务的开发要由flee,rou和group 负责。fire
将协助编程和测试。
2 三国角色NPC。
最近在yuyin 的努力下，角色NPC的数量已经
达到了53个(用 listchar /1 /v is_tmp 0 /v type 0)
查询。yuyin将主要负责增加角色NPC的工作。
争取在两周内使角色NPC的数量达到100个。这
也许是测试板可以接受的数目。我们有19个地区
平均一个地区五名角色NPC还是合理的。
3 三国主页。
在jams(swallow) 的努力下，我们终于有了一个
主页和一个很不错的地址：http://sgz.yesite.com/
开通才几天，访问人数就达到80(期中包括我的
10次，hoho)。这对我们今后的宣传一定大有好处。
jams的工作将主要集中在主页上，早日完成图形板，
并增添新的内容。同时建议使用lima提供的CGI，使得
玩家在主页上可以直接完成都lima的帮助(这可以节省
一大堆的文本更新工作)；直接读lima留言板。甚至可
以已一个特定角色的身份，如水境先生来看到MUD
的当前景向。
4 玩家帮助
我们知道，本三国MUD虽在创新方面享有很高声誉，但
“玩家人数始终徘徊在1-5之间，所有中文MUD中没有比
这更惨的了”(引自加拿大三国)。但现在我们终于有了
十名左右的玩家。这对我们这个尚未成熟的系统，是一
个很大的考验。我们有很多没有经过玩家检验的设计，
如果这些新玩家对这些设计感到满意，对我们将来的
发展一定大有好处。反过来，如果由于我们的疏漏，使
新玩家不能充分了解我们的设计，产生误解，可能会对
我们的将来产生负面影响。因此我们提升guanfeng为巫
师，专门从事介绍新玩家和帮助新玩家的工作。但由于
我们的核心开发还没有完，所以还不适宜大规模宣传，
介绍太多新玩家。能保持十多名玩家在线就可以了。
5 安全系统。
自从上次当机后，系统部分总有些不爽快。
a finger 不能显示中文名。
b 玩家也可以用finger 查到所有信息
c 不能 cmd suicide 了。
d 在提拔新巫师时，新巫师的auto logout ， auto login
  和su 命令有严重的BUG 希望stefan抽空把这些BUG fix
一下。
6 地区建设。
地区建设我已经写了一个方案，见 man areahint。毫无疑问
地区建设和写描述是件枯燥的差事，所以在此我特别感谢row
和group和benben他们顽强地完成了许多枯燥的地区建设和战
争地图的设计。下面我将和benben 玩成余下的地区。并作一
些房间功能，地区平衡，地图更新的工作。同时希望对此工作
感兴趣的WIZ帮助参预，这虽然是一件枯燥的工作，但也是一
件相对简单，容易上手，见效快的工作。hoho
7 简单NPC
我们的大部分地区荒芜人烟，走在街上，心理毛毛的，可以设计
一些简单的NPC。女丫鬟，店主等。这个工作不太麻烦，就由我
来作好了。谁要喜欢，也可以让给你。
8 特殊NPC。
这些NPC不同于角色NPC如(刘关张)也不同于简单NPC如店小二，
水境等。他们由CHAR_D直接控制，但不参预三国的争斗。这种
NPC包括商人，小男孩，闲人，强盗，小偷等。这种NPC设计较
复杂，但由于由CHAR_D控制，可参预复杂的JOB系统。同时具有
非常大的灵活性。对于设计中级JOB的巫师，最好可以掌握设计
这种NPC的技巧。
9 物品系统
这个系统我们一直比较薄弱，但由于我们的角色与地区系统已经
趋于成熟(这两部分非常重要，是本MUD的精华，新WIZ请花时间了
解。核心文件是/daemons/char_d.c /daemons/area_d.c 以及
/daemons/char_d/ /daemons/area_d/下的所有文件。现在我们计
划物品系统。它包括几个部分：
a 饮食部分
b 服装装甲部分
c 兵器部分
d 马匹部分
e 书籍部分
f 宝物部分
这部分和战斗系统，HP系统和SKILL系统有非常大的关系。由fire
作初期设计和协调工作。
10 国家会议，国家战争和玩家力国
这是一个非常大而且与其他部分关系非常复杂的一部分。等上面大部分
工作都已经明了。在开工吧。


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 马匹的设计
日期: Mon Mar 22 22:57:33 1999
马匹：
level  =  att_abi    value         名称
1           1        100000-       矮脚马，小红马
2           2        500000-       黄膘马，枣红马
3           3        1000000-      伊犁马, 黑骏马
4           4        5000000-      大宛马，战马
5           5        10000000-     千里马，
------------以下是宝马，全是unique-----------------------
6           6
7           7                      的卢
8           8                      绝影
9           9                      爪黄飞电
10          10                     赤兔       

名称仅供参考


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: 马匹的设计
日期: Mon Mar 22 22:57:33 1999
马匹：
level  =  att_abi    value         名称
1           1        100000-       矮脚马，小红马
2           2        500000-       黄膘马，枣红马
3           3        1000000-      伊犁马, 黑骏马
4           4        5000000-      大宛马，战马
5           5        10000000-     千里马，
------------以下是宝马，全是unique-----------------------
6           6
7           7                      的卢
8           8                      绝影
9           9                      爪黄飞电
10          10                     赤兔       

名称仅供参考


---
作者: Fire
题目: 马匹的设计
日期: Mon Mar 22 22:57:33 1999
马匹：
level  =  att_abi    value         名称
1           1        100000-       矮脚马，小红马
2           2        500000-       黄膘马，枣红马
3           3        1000000-      伊犁马, 黑骏马
4           4        5000000-      大宛马，战马
5           5        10000000-     千里马，
------------以下是宝马，全是unique-----------------------
6           6
7           7                      的卢
8           8                      绝影
9           9                      爪黄飞电
10          10                     赤兔       

名称仅供参考


---
作者: Fire
题目: cl 用法
日期: Mon Mar 22 21:59:04 1999
cl 命令的用法。
cl 是一条专对D_OBJ(daemons object)设计的巫师指令。
它有以下用途:
cl                    显示所有物品清单
cl <type|sub_type>    显示所有该类或该子类物品清单。
   例如：
   cl food            显示所有食物
   cl blade           显示所有刀类武器
cl <id>               复制一重物品
   例如：
   cl shaobing        复制一烧饼
为避免冲突，物品的ID不要与类或子类相同。例如blade,food等。


---
作者: Mimi
题目: 武器参数
日期: Mon Mar 22 17:31:49 1999
level     att_abi    att_pow   size   value            名称
1          1         1-5       20-80  500-             单刀
2          1-2       3-8              2000-10000       钢刀
3          1-3       5-10             50000-100000     马刀
4          2-4       8-15             200000-500000    长刀
5          3-5       10-20            1000000-         战刀
----------------六级以上为宝物，全是unique-------------------
6          4-6       20-30              
7          5-7       25-35
8          6-8       30-40                   
9          7-9       35-45
10         10        50                        青龙青龙偃月刀
武器重量=size/2


---
作者: Fire
题目: 新的OBJ系统: daemon OBJ
日期: Sun Mar 21 04:32:14 1999
为了加强OBJ系统的管理，现引入一个新的OBJ系统。
主要由daemon 文件 /daemons/obj_d.c和master OBJ
文件构成。同时为了便于巫师的管理，还要开发一个
集增，删，改，查为一体的一个管理工具。下面分几
个方面来介绍一下这个新的daemon OBJ系统(简称：
D-OBJ系统)。
优点：
1 便于查询
在一个以文件为基础的OBJ系统中，如果要问你这个系
统中有多少种不同的食物，多少种不同的剑或铠甲。
相信通常这是一个不容易回答的问题。特别是当各种
物件散落到不同的路径时，这个问题就更难。但在
D-OBJ中。查询这个问题只需一条指令就可以得到最新
的准确的信息。
2 便于平衡调整参数。
由于所有物品的参数都存储在一个主daemon数据库中。
增加参数和平衡参数都会非常简单。
3 非常容易实现在线增加新的物品。由于大部分的OBJ
都只是数据库中的一条记录，加起来就非常容易。这对
于玩家自设计宝物将非常容易。
4 巫师更容易clone物品，不需要找路径，查文件名，
直接cl id 就行了。
5 在文件中需要生成新物品也会方便许多。
缺点：
1 需要调整多个系统，如VALUE，inventory, home desc
store and dangpu. keeping 
2 不同物品必需用不同的主ID
3 复杂物品还需要传统文件OBJ系统支持。
结论：
在本MUD中我们将同时使用两个OBJ系统。少数复杂OBJ用
文件OBJ，绝大多数OBJ用D_OBJ。
程序：
最主要的工作在/daemons/obj_d 中，还要参考所定义的
master OBJ文件。如/sgdomain/obj/foodandrink/woutou.c
巫师命令现在用cl 复制和查询物品。等新的菜单作好了在
公布。


---
作者: Fire
题目: admire guanfeng
日期: Tue Mar 23 21:46:50 1999
guanfeng creat so many great objects
good work guanfeng

addoil all


---
作者: Fire
题目: great work, flee
日期: Wed Mar 24 21:32:18 1999
admire flee
addoil
and let's jams make a link from main homepage to here
and we perhaps still need a like from the help to
our main home page
hoho


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Yuyin
题目: agree fire and agree yolk
日期: Tue Apr  6 03:06:47 1999
addoil fire, addoil yolk


---
作者: Yuyin
题目: agree fire and agree yolk
日期: Tue Apr  6 03:06:47 1999
addoil fire, addoil yolk


---
作者: Yuyin
题目: 一点关于 fight 系统的建议 
日期: Sat Apr  3 03:38:55 1999
现在的 fight 系统我觉的还大大的没做好.
1 我觉得应该加一点绝招，例如我的“神风腿”。
2 应该能学一点武功，但并不要多。


---
作者: Fire
题目: an example of the cgi
日期: Tue Mar 30 22:47:56 1999
I have modified the 
/WWW/help.html and /WWW/cgi/sg_help.c
so they use the tricky extension of cgi in the 
reference. 

When you code more cgi and html use cgis, please
follow this way.

xixi


---
作者: Fire
题目: about the cgi
日期: Tue Mar 30 22:44:43 1999
because in some browser, the extension of .c
is connected with download a c sourcefile or plug in.
so our cgi can not work poparly in all the browsers.
now i have made some change, hope this can solve this
problem.

1 the cgi file still put in the /WWW/cgi/ with the extension
  of .c
2 to reference use /cgi/*.cgi

I have adjust the convert code in http_d.c
  so the daemon will auto replace cgi with c.
  but this will make the browsers feel comfortable
if due with .cgi

hoho

addoil


---
作者: Fire
题目: about the cmd of cl
日期: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
作者: Fire
题目: the color of chat and weather
日期: Thu Apr  1 18:51:47 1999
some players complain that the color for those
two channel too dim, so i changed them to high light color
hoho :)


---
作者: Fire
题目: about special stuff
日期: Thu Apr  1 19:59:31 1999
look zhang fei
张飞呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。
他看上去有三十多岁。
只见张飞：
手持小斧(xiaofu)。
头戴皮帽(pimao)。
脚踏灰姑娘的夜光鞋(yeguangxie)。
身穿布衣(buyi)。
外套一身巫师工作服(workcloth)
laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
作者: Fire
题目: 上一POST有一点错误
日期: Fri Mar 26 17:45:15 1999
对于工匠，其is_tmp=1
。


---
作者: Fire
题目: great work, flee
日期: Wed Mar 24 21:32:18 1999
admire flee
addoil
and let's jams make a link from main homepage to here
and we perhaps still need a like from the help to
our main home page
hoho


---
作者: Fire
题目: 衣服盔甲的参数设计
日期: Thu Mar 25 00:47:32 1999
铠甲 "armors"
level   att_abi     def_pow      size      value    名称
1	 0	     8           20        10000    藤甲
2       -1           10          50        50000    铁甲
3       -1           15          60       100000    铜甲 
4       -2           18          70       500000    银甲
5       -2           20          80      1000000    金甲
-----------------------------------------------------------------
6       -1           22          70       无价      未定 
7       -2           24          80       无价      未定
8       -2           26          80       无价      未定
9       -1           28          50       无价      未定
10      0            30          40       无价      未定
上衣 "torso"
level    def_pow    size    value     名称
0        1          5       0         布衣
0        2          5       1000      长袍
1        2          5      10000      官服
2        3          5      50000      丝绸官服
3        4         10     100000      锦绣官服
4        5         10     500000      斑斓官服
5        5         10    1000000      龙袍 (必需是国王)
------------------------------------------------------------------
6
7
8
9  
10     暂缺
头盔 "head"
level    def_pow    size    value     名称
0        1          5       0         布帽
0        2          5       1000      皮袍
1        2         10      10000      铁盔
2        3         10      50000      铜盔
3        4         15     100000      银盔
4        5         15     500000      金盔
5        5         15    1000000      王冠 (必需是国王)
------------------------------------------------------------------
6- 10 暂缺
鞋 "feet"
level    def_pow    size    value     名称
0        0          5          0      草鞋
0        1          5       1000      布鞋
1        1          5      10000      官靴
2        2          5      50000      皮靴
3        2          5     100000      云靴
4        3          5     500000      战靴
5        3          5    1000000      龙靴 (必需是国王)
------------------------------------------------------------------
6- 10 暂缺
胸饰 "brest" 如玫瑰等
护碗 "arms"  
戒指 "hands"
下装 "legs" 裙子等，
这些不是必需的，可以任意设计，基本没什么特殊用途。
主要用于quest和丰富市场。
def_pow    size    value     名称
0-2        5-10       0-100000

以上名称仅供参考，可以新增许多新的物品。
但希望物品参数不要有太大偏离。


---
作者: Fire
题目: 制作匠人
日期: Fri Mar 26 00:12:39 1999
maker 参数
maker 是一种工匠，具体可以是一个鞋匠，铁匠或制衣匠，甚至是训马师。
他是一类特殊角色NPC，(也由char_d控制)，比起角色NPC，他有以下特殊
参数：
1 is_maker (int) = 1 表示是 maker       不能更改
2 is_tmp   (int) = 0 表示是 非角色NPC   不能更改
3 ask_list (string) 玩家向其打听他能制做什么的用语。
  有缺省值，但为了对话自然，最好专门设计。
  缺省值: $N对$T招了招手：$m，让$S看看你这儿都能做些什么货。\n
4 ask_buy  (string) 玩家向其买东西的用语。
  有缺省值，但为了对话自然，最好专门设计。
  缺省值: $N对$T招了招手：$m，$S想买件东西。\n
5 ask_order  (string) 玩家向其定做东西的用语。
  有缺省值，但为了对话自然，最好专门设计。
  缺省值: $N对$T招了招手：$m，$S想定做件东西。\n
6 ask_fix  (string) 玩家向其要求修改东西的问语。
  有缺省值，但为了对话自然，最好专门设计。
  缺省值: $N对$T招了招手：$m，$S这儿有件东西，你能不能帮忙改一改。\n
7 ask_good  (string) 玩家向其要求取货的用语。
  有缺省值，但为了对话自然，最好专门设计。
  缺省值: $N对$T招了招手：$m，$S的东西好了吗？\n
8 long :  (string) 该工匠的外表，
  有缺省值，但为了自然和增加变化，最好专门设计。
  缺省值: 一个正忙得团团转的工匠。\n
9 m_ack:  (string array) 该工匠的一些特殊动作和言语。这一设计可以让
该NPC显得生动。
  如对于一个铁匠可设计成：
  ({
      "$N拎起大锤，叮叮铛铛地打起铁来。\n",
      "$N操着一口山东口音道：洒家打出来的刀，无一不是削铁如泥的宝刀。\n",
      "$N拿起一柄刚刚淬火的刀，赞道：好刀，好刀。\n",
  })
  句子的数量风格没有限制。但就算只有一句，也一定是数组型式。
  缺省值: "一个正忙得团团转的工匠。\n"
10 shd_room: (string) 工匠所在的房间。如果没有这一项，他的所在房间无法确定。
11 goods: (string array) 该工匠所能制作的东西。
   如对于一个最小的制衣匠，可以是：
   ({ "buyi", "changpao",})
12 orders: (mapping) 玩家定买的记录，由系统自行维护。
匠人ID，因为由char_d控制，所以每一个匠人的ID都是唯一的，同时最好每
个ID由两部分组成。如：
张铁匠(zhang tiejiang)，宝剑王(baojian wang)，小鞋匠(xiao xiejiang) ..
等。


---
作者: Fire
题目: 匠人系统
日期: Sat Mar 27 03:28:04 1999
匠人系统：maker system
匠人系统是一个与D_OBJ系统紧密相关的特殊非角色NPC系统。它是char_d
的一个子系统，其核心文件是/sgdomain/modules/m_charnpc/maker.c。
一个匠人就是一个可以制造物品的NPC，他的具体身份可以是一个裁缝，
一个鞋匠，一个铁匠，一个厨师甚至一名训马师。从一名匠人那里，玩家
可以进行如下活动：
1 购买物品，和在商店买相似，但比商店系统要灵活，他有以下好处。
  a 系统知道什么东西在什么地方有卖的。
  b 可以在程序过程中增减某一匠人可制作的物品种类。
  c 由a b 的特性，可以出算命先生查在何处购买何物品，可设计复杂的
    JOB
2 定制物品。玩家可在匠人处专门为自己定制物品。定制的物品要比买的
  贵，但因为是为自己特定的，所以不能卖，不能丢也不能给人。但在退
  出从新连线后，系统会自动加载。换句话说，就是不丢。一个玩家对一
  类(或一子类)物品只能有一件是定制。也就是说如果你先定了一件布衣，
  下回又定了一件长袍。那么布衣就不在是特定物。在联线就不能自动加
  载。
3 修改物品，这个和定制类似，如果玩家在当铺先买了一把单刀，然后希望
  此单刀不丢，可以前来把此单刀改造成自己的定制物。这样这把单刀联
  线就从新加载。当然，修改物品要比定制便宜一些。
4 可定制的物品和等级：
  可定制的物品有三类，武器，衣甲和马匹(将来也考虑书籍等)
5 等级：
  目前的官有九级(件officer_d)
  物品(武器，马匹和衣物也有11级 0-10)
  百姓(必须settle)只能定 0 级物品
  1,2 级官员只能定 1 级物品
  3,4 级官员只能定 2 级物品
  5,6 级官员只能定 3 级物品
  7,8 级官员只能定 4 级物品
  9级(国王) 只能定 5 级物品
  6-10 级物品全是独一的宝物，只能通过特殊渠道获得。
6 物品的种类数：
  因为中，低级官员要比中，高级官员少得多，所以在物品设计时建议多设计
  低级别的物品，以下是每一类(或子类)物品建议种类数：
  0 级物品 3-5
  1 级物品 3-5
  2 级物品 3-5
  3 级物品 2-3
  4 级物品 1-2
  5 级物品 1-2
  6-10 每级0-1个就行。这样每一类(或子类)物品的种类约在15-30之间。
7 匠人数：
  不同地区根据其地区的等级建议其匠人数目如下：
  地区级别        匠人数
  1,2 关和村庄    1-2
  3 城镇          2-3
  4 中等城市      3-4
  5 大城市        5-
  每一匠人大约可制作3-5种不同的物品。(最好每一匠人都有一绝活，就某物
  品只有他能做。)
8 匠人编辑器(makereditor)
  匠人编辑器是一个非常方便简单的匠人设计工具。具体使用帮助见
  man makereditor


---
作者: Fire
题目: 匠人编辑器帮助
日期: Sat Mar 27 03:51:29 1999
1 用makereditor启动匠人编辑器
2 主要功能：n增加新匠人，e编辑已有匠人。
3 匠人ID必须是两部分，中间有一空格如 yang tiejiang
4 参数解释，  
  m)  编辑工匠名称(m) 不许解释，必须输入
  g)  编辑工匠性别(g) 缺省：男
  a)  编辑工匠年龄(a) 缺省：15-50 之间随即
  l)  编辑工匠外貌(l) 不是必须，但最好单独设计
  r)  编辑工匠房间(r) 工匠所在的房间，缺省就是编辑者在第一次增加次匠人
      时编辑者所在的房间。修改时输入新房间的文间名(包括路径，不包括扩展
      名。如/sgdomain/area/guan/huayin/vzhangda_hu)另一个修改方法是编辑
      者先到为此工匠设想的新的房间，然后在编辑工匠房间时输入here
  o)  编辑工匠物品(o) 这是最重要的一个参数，会进入一个子菜单，其中包括
      增加物品，删除物品和列出物品等功能。一个提示，如果你忘了物品的ID，
      假设你编辑的是一个制刀的铁匠则可在不退出该编辑器的情况下用：
      !cl blade 察看所有刀的清单。注意一定不要忘记"!"
  w)  编辑工匠言行(w) 
      可以使该工匠不时地说一些话或做一些动作，不是必须的但可以增加不少趣味。
  s)  存盘返回(s)         u)  不存盘返回(u)  不用解释拉。
5 让工匠出现。
  到工匠所在房间，如果工匠没有出现，就 update here 工匠就会出现，还不出现
  就是有BUG了。
6 所有工匠列表：
  退出工匠编辑器后用：
  @listchar /1 /v is_maker 1


---
作者: Fire
题目: 巫师帮助
日期: Sat Mar 27 03:53:56 1999
一些与三国MUD有关的帮助文本(中文)我已放在
/help/wizard/sanguo/ 以下欢迎经常察阅


---
作者: Group
题目: fire
日期: Sat Mar 27 05:47:10 1999
i done letter.c in job/letter directry, please check it, and open it for test.


---
作者: Fire
题目: about the new job of letter
日期: Sat Mar 27 07:06:20 1999
group finished a new job, letter.
I think this is not bad.
I modified some code to make the result more simple. 
only a little problem is that this job is called
送信, but we don't have an object of letter.
so a little wicked. anyway, this is a new job.
thank group
addoil all


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Row
题目: >一点建义
日期: Thu Apr  8 05:49:47 1999
there is a cmd called plan..u can write ur plan in it, and ur
progress as well.


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Fire
题目: about plan
日期: Sat Apr 10 21:47:04 1999
wiz can use "man tasklist" to view the plan


---
作者: Flee
题目: permission need
日期: Sun Apr 11 03:19:37 1999
i need the permission of /daemons/ and /cmds/
to modify some code .


---
作者: Flee
题目: >> about tasklist
日期: Sun Apr 11 03:18:35 1999
agree .. :)


---
作者: Fire
题目: about tasklist
日期: Sun Apr 11 02:42:58 1999
>关于献帝宫，三国中有许多“仙人”，象现在有的
>水镜先生，还有管仲，华陀，可以处理成common
>quest system。所有的人都可以向他门要任务。
这个提议很有意思。我计划涉及成如下形象，一些三国
中的先人可以随机出现某一地区
然后用rumor通知
然后玩家找到他学习，他可能会对玩家提一点要求
玩家完成后他就会教给玩家一项技能。
但对一名玩家只教一次，直到他下次从新出现。
这些仙人除了三项基本修养不能教外，其他的通统能教，教一次
涨一级

这样安排怎么样？


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Fire
题目: about tasklist
日期: Sun Apr 11 02:42:58 1999
>关于献帝宫，三国中有许多“仙人”，象现在有的
>水镜先生，还有管仲，华陀，可以处理成common
>quest system。所有的人都可以向他门要任务。
这个提议很有意思。我计划涉及成如下形象，一些三国
中的先人可以随机出现某一地区
然后用rumor通知
然后玩家找到他学习，他可能会对玩家提一点要求
玩家完成后他就会教给玩家一项技能。
但对一名玩家只教一次，直到他下次从新出现。
这些仙人除了三项基本修养不能教外，其他的通统能教，教一次
涨一级

这样安排怎么样？


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Fire
题目: about tasklist
日期: Sun Apr 11 02:42:58 1999
>关于献帝宫，三国中有许多“仙人”，象现在有的
>水镜先生，还有管仲，华陀，可以处理成common
>quest system。所有的人都可以向他门要任务。
这个提议很有意思。我计划涉及成如下形象，一些三国
中的先人可以随机出现某一地区
然后用rumor通知
然后玩家找到他学习，他可能会对玩家提一点要求
玩家完成后他就会教给玩家一项技能。
但对一名玩家只教一次，直到他下次从新出现。
这些仙人除了三项基本修养不能教外，其他的通统能教，教一次
涨一级

这样安排怎么样？


---
作者: Row
题目: tasklist
日期: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as 借东风), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
作者: Row
题目: tasklist
日期: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as 借东风), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
作者: Row
题目: tasklist
日期: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as 借东风), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
作者: Yuyin
题目: 我的homepage 
日期: Mon Apr 12 08:55:16 1999
我的 homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
作者: Row
题目: tasklist
日期: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as 借东风), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
作者: Yuyin
题目: 我的homepage 
日期: Mon Apr 12 08:55:16 1999
我的 homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
作者: Row
题目: tasklist
日期: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as 借东风), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
作者: Yuyin
题目: 我的homepage 
日期: Mon Apr 12 08:55:16 1999
我的 homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
作者: Yuyin
题目: agree yolk
日期: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
作者: Yuyin
题目: 一点建义
日期: Thu Apr  8 01:25:52 1999
我想应该建一个东西让wiz记录下他们的进度


---
作者: Row
题目: >一点建义
日期: Thu Apr  8 05:49:47 1999
there is a cmd called plan..u can write ur plan in it, and ur
progress as well.


---
作者: Fire
题目: plan
日期: Sat Apr 10 21:46:24 1999
三月总结与四月计划
1  job system
   现在有了13个中级JOB，基本够用，但是这些JOB在奖励和过程反面
   尚有些单调。关于JOB的有以下工作：
   a  简化初级JOB，使之更快，更容易上手
   b  改进landlord并开发多个此类型JOB
   c  开发与现有D_OBJ和maker有关的找物，购物JOB
2  NPC。
   现在已经有了101个角色NPC，和31个maker。我们大概需要150个角
   色NPC和60个左右的maker。关于NPC有以下工作：
   a  增加角色NPC。
   b  增加调整maker
   c  完善NPC管理工具。
   d  设计新类型NPC(如算命先生)
3  三国主页。
   现在我们有了两个很不错的CGI和一个图象三国主页首页。关于主页
   有以下计划：
   a  完善图像版，为本MUD设计一个图标。
   b  增加更多的CGI，如查阅三国地图角色地区等。
4  地区建设。
   现在各地区的建设已经基本完毕但还有一些地区的MAP，描述需要加强。
5  物品系统(D_OBJ)
   现在的D_OBJ包括food, weapon, cloth, drink, horse几个大类，同
   时weapon还包括blade, spear, hammer, sword, ji, axe六子类。cloth
   包括armor, brest, torso, head, legs, hands, arms, feet 几个子
   类。这部分的内容还需要加强。
   目前已经有了173种物品，也许需要200-300种物品，同时配合makers
   和JOB系统。
   另外需考虑新的OBJ类如药物，书籍等。
6  战争系统。
   本MUD最复杂的一个系统，有以下工作：
   a 加入单挑
   b 加入计谋
   c 完善战争结果，奖励和惩罚。
   d 完善战争公式。
   e 加入阵法。
   f 加入粮草，退兵等功能。
7  单挑
   a 增加更多，更丰富的描述。
   b 加入校场，玩家可在那里找到合适的NPC练功。
8  新的系统：
   a 神力系统(玩家在某些场合可以获得一定的神力点，有这些神力点在配
     上某些技能，玩家可以有一些特殊能力，如自疗，到某地，增加体力
     等，预报天气，改变天气等。
   b 献帝宫，献帝可随机给玩家和地区国家安排任务，成功后奖励丰厚，还
     可以举办比武大会。
   c 梦幻境：有各种书籍，玩家可在一定范围内选一本书读，使相应的等级
     升一级。进入梦幻境需神力的支持。
   d 国家会议
     国家会议不需要把所有开会者集到一起，而是使用一个专门的国家频道
     来进行。
   e 玩家称为太守
所有WIZ请阅读此计划，并选择自己的工作，选好后，请POST，并POST一个详细
的计划。谢谢。


---
作者: Fire
题目: about plan
日期: Sat Apr 10 21:47:04 1999
wiz can use "man tasklist" to view the plan


---
作者: Fire
题目: about tasklist
日期: Sun Apr 11 02:42:58 1999
>关于献帝宫，三国中有许多“仙人”，象现在有的
>水镜先生，还有管仲，华陀，可以处理成common
>quest system。所有的人都可以向他门要任务。
这个提议很有意思。我计划涉及成如下形象，一些三国
中的先人可以随机出现某一地区
然后用rumor通知
然后玩家找到他学习，他可能会对玩家提一点要求
玩家完成后他就会教给玩家一项技能。
但对一名玩家只教一次，直到他下次从新出现。
这些仙人除了三项基本修养不能教外，其他的通统能教，教一次
涨一级

这样安排怎么样？


---
作者: Fire
题目: 空中司令的建议
日期: Tue Apr 13 11:16:43 1999
关于三国
1)      关于战争
        在三国时，关羽有校刀手，典伟和许(zhu)有虎卫军，甘宁有百羽军
，马超有锦超军，孟获有藤甲兵，公孙钻有百马军，等等都是特别精兵。希望
在 Mud 里能够看到。
建议：
        如何征收这种特殊亲兵？
        现在的玩家，大多数都有10名亲兵。只要有一指令(改装部队)，
凭玩家现有的技能和金钱，玩家就能改装自己所喜欢的部队。一旦改装了，玩
家就不能再改成其他部队。除非玩家完全解雇所有亲兵，然后在重新开始改装
部队。
        只有当上朝廷命官，玩家有足够的钱和技能，就能够训练并强化自己
的精兵。例如：
        特殊精兵        必备品  玩家技能
        校刀手  长刀            刀法和dodge 技能20 以上
        虎卫军  卓戈            卓戈法和骑术20以上
        百羽军  长剑            剑法和基本水计策20 以上
        锦超军  长枪            枪法和骑术20以上
        藤甲兵  藤甲            刀法和基本水计20以上
        这一切都可任您(wiz)改。如何强化？ 只需要买更好的同类武器就可。
        还有，就是每当玩家的技能上5点，精兵就上1级。
        百羽军(1 级)    玩家技能 剑法(20) ， 基本水计 (20)
        百羽军(2 级)    玩家技能 剑法(25) ， 基本水计 (25)
        百羽军(3 级)    玩家技能 剑法(30) ， 基本水计 (30)
        级数上升了，精兵的生命力，攻防力也上升。当然，这种亲兵的每年
费用也比普通亲兵高了很多。
        对了， 古时战争，粮食是一项重要部份。希望下次战争中有运粮官和粮草。
2)      关于阵法
        引用光荣公司(KOEI)三国志5 的阵法。
        控制每一个玩家最多会三门阵法。
        每一个玩家(NEWBIE JUST LOGIN) 一开始就会一门阵法。已在线的玩
家可        从WIZ 里要一门自己喜欢的阵法。
        第2 门阵法可向任何人(NPC OR PLAYER) 学习，第 3
门阵法(特殊阵法)由       WIZ 自创。玩家只有在长期战争中增加战争经验
，当战争经验长到一定水准，就可向WIZ 学习。
3)      修行
        在三国中，诸葛亮，徐庶，庞统，郭嘉，刘哗等都有一段游山玩水的
修行过程，不知能不能把这修行当著一项(JOB)
        (JOB) JOURNEY
        必备马匹，粮食，和亲兵。
        游戏时间一个月。一天知能重复两次
        地点不在任何都市，就像骑马时所见到的小地方
        在这一个月里，玩家带同亲兵游山玩水，提升自己的技能。游山玩水
中，玩家会遇到
        1)      战争难民。      给钱或粮食，            长治国修养
        2)      圣贤对棋。      胜或负                  长兵法修养
        3)      打垮山盗        带同亲兵打山盗          
                                成功                            长武学修养和
                                                               长亲兵训练度
                                失败                            名声下降很多
        4)      河水泛滥        带同亲兵治水            
                               成功                           
长名声和治国修养
                               失败                            名声下降很多
        5)      偶遇圣贤        答对圣贤所问            长阵法经验100
                                                               技能中升1 级 
                                                              
(任何技能，但不是
                                                              
WXXY，BFXY OR ZGXY)
                               答错圣贤所问            一项技能下降1级
        6)      擂台比武        比武胜                  长单挑能力和武学修养
                               比武                            长武学修养
        7)      游江救婴        成功                            长基本水计
                                失败                           
名声，忠诚，水计下降
       8)      打包不平        带同亲兵打市街流氓
                               成功                            长武学修养和
                                                             长亲兵训练度
                                失败                            名声下降
        9)      杀狼救童        成功                           
任何一项技能长经验150
                               失败                           
名声下降                
        以上是一些小提议，WIZ 是否采用， 全由WIZ否决定。


---
作者: Fire
题目: 空中司令的建议
日期: Tue Apr 13 11:16:43 1999
关于三国
1)      关于战争
        在三国时，关羽有校刀手，典伟和许(zhu)有虎卫军，甘宁有百羽军
，马超有锦超军，孟获有藤甲兵，公孙钻有百马军，等等都是特别精兵。希望
在 Mud 里能够看到。
建议：
        如何征收这种特殊亲兵？
        现在的玩家，大多数都有10名亲兵。只要有一指令(改装部队)，
凭玩家现有的技能和金钱，玩家就能改装自己所喜欢的部队。一旦改装了，玩
家就不能再改成其他部队。除非玩家完全解雇所有亲兵，然后在重新开始改装
部队。
        只有当上朝廷命官，玩家有足够的钱和技能，就能够训练并强化自己
的精兵。例如：
        特殊精兵        必备品  玩家技能
        校刀手  长刀            刀法和dodge 技能20 以上
        虎卫军  卓戈            卓戈法和骑术20以上
        百羽军  长剑            剑法和基本水计策20 以上
        锦超军  长枪            枪法和骑术20以上
        藤甲兵  藤甲            刀法和基本水计20以上
        这一切都可任您(wiz)改。如何强化？ 只需要买更好的同类武器就可。
        还有，就是每当玩家的技能上5点，精兵就上1级。
        百羽军(1 级)    玩家技能 剑法(20) ， 基本水计 (20)
        百羽军(2 级)    玩家技能 剑法(25) ， 基本水计 (25)
        百羽军(3 级)    玩家技能 剑法(30) ， 基本水计 (30)
        级数上升了，精兵的生命力，攻防力也上升。当然，这种亲兵的每年
费用也比普通亲兵高了很多。
        对了， 古时战争，粮食是一项重要部份。希望下次战争中有运粮官和粮草。
2)      关于阵法
        引用光荣公司(KOEI)三国志5 的阵法。
        控制每一个玩家最多会三门阵法。
        每一个玩家(NEWBIE JUST LOGIN) 一开始就会一门阵法。已在线的玩
家可        从WIZ 里要一门自己喜欢的阵法。
        第2 门阵法可向任何人(NPC OR PLAYER) 学习，第 3
门阵法(特殊阵法)由       WIZ 自创。玩家只有在长期战争中增加战争经验
，当战争经验长到一定水准，就可向WIZ 学习。
3)      修行
        在三国中，诸葛亮，徐庶，庞统，郭嘉，刘哗等都有一段游山玩水的
修行过程，不知能不能把这修行当著一项(JOB)
        (JOB) JOURNEY
        必备马匹，粮食，和亲兵。
        游戏时间一个月。一天知能重复两次
        地点不在任何都市，就像骑马时所见到的小地方
        在这一个月里，玩家带同亲兵游山玩水，提升自己的技能。游山玩水
中，玩家会遇到
        1)      战争难民。      给钱或粮食，            长治国修养
        2)      圣贤对棋。      胜或负                  长兵法修养
        3)      打垮山盗        带同亲兵打山盗          
                                成功                            长武学修养和
                                                               长亲兵训练度
                                失败                            名声下降很多
        4)      河水泛滥        带同亲兵治水            
                               成功                           
长名声和治国修养
                               失败                            名声下降很多
        5)      偶遇圣贤        答对圣贤所问            长阵法经验100
                                                               技能中升1 级 
                                                              
(任何技能，但不是
                                                              
WXXY，BFXY OR ZGXY)
                               答错圣贤所问            一项技能下降1级
        6)      擂台比武        比武胜                  长单挑能力和武学修养
                               比武                            长武学修养
        7)      游江救婴        成功                            长基本水计
                                失败                           
名声，忠诚，水计下降
       8)      打包不平        带同亲兵打市街流氓
                               成功                            长武学修养和
                                                             长亲兵训练度
                                失败                            名声下降
        9)      杀狼救童        成功                           
任何一项技能长经验150
                               失败                           
名声下降                
        以上是一些小提议，WIZ 是否采用， 全由WIZ否决定。


---
作者: Row
题目: >空中司令的建议
日期: Tue Apr 13 22:47:16 1999
空中司令的建议非常的好，关于特殊亲兵的问题，我记得以前和
fire讨论过，也就是给亲兵配备相应的装备便可以使他们成为相应
的部队；运粮草可以做成一个中级job，还有fire说过战争也会
引进粮草系统；阵法相信flee会尝试的；修行是个非常有趣的提
议，只不过目前似乎都没有时间来完成。:)


---
作者: Fire
题目: 空中司令的建议
日期: Tue Apr 13 11:16:43 1999
关于三国
1)      关于战争
        在三国时，关羽有校刀手，典伟和许(zhu)有虎卫军，甘宁有百羽军
，马超有锦超军，孟获有藤甲兵，公孙钻有百马军，等等都是特别精兵。希望
在 Mud 里能够看到。
建议：
        如何征收这种特殊亲兵？
        现在的玩家，大多数都有10名亲兵。只要有一指令(改装部队)，
凭玩家现有的技能和金钱，玩家就能改装自己所喜欢的部队。一旦改装了，玩
家就不能再改成其他部队。除非玩家完全解雇所有亲兵，然后在重新开始改装
部队。
        只有当上朝廷命官，玩家有足够的钱和技能，就能够训练并强化自己
的精兵。例如：
        特殊精兵        必备品  玩家技能
        校刀手  长刀            刀法和dodge 技能20 以上
        虎卫军  卓戈            卓戈法和骑术20以上
        百羽军  长剑            剑法和基本水计策20 以上
        锦超军  长枪            枪法和骑术20以上
        藤甲兵  藤甲            刀法和基本水计20以上
        这一切都可任您(wiz)改。如何强化？ 只需要买更好的同类武器就可。
        还有，就是每当玩家的技能上5点，精兵就上1级。
        百羽军(1 级)    玩家技能 剑法(20) ， 基本水计 (20)
        百羽军(2 级)    玩家技能 剑法(25) ， 基本水计 (25)
        百羽军(3 级)    玩家技能 剑法(30) ， 基本水计 (30)
        级数上升了，精兵的生命力，攻防力也上升。当然，这种亲兵的每年
费用也比普通亲兵高了很多。
        对了， 古时战争，粮食是一项重要部份。希望下次战争中有运粮官和粮草。
2)      关于阵法
        引用光荣公司(KOEI)三国志5 的阵法。
        控制每一个玩家最多会三门阵法。
        每一个玩家(NEWBIE JUST LOGIN) 一开始就会一门阵法。已在线的玩
家可        从WIZ 里要一门自己喜欢的阵法。
        第2 门阵法可向任何人(NPC OR PLAYER) 学习，第 3
门阵法(特殊阵法)由       WIZ 自创。玩家只有在长期战争中增加战争经验
，当战争经验长到一定水准，就可向WIZ 学习。
3)      修行
        在三国中，诸葛亮，徐庶，庞统，郭嘉，刘哗等都有一段游山玩水的
修行过程，不知能不能把这修行当著一项(JOB)
        (JOB) JOURNEY
        必备马匹，粮食，和亲兵。
        游戏时间一个月。一天知能重复两次
        地点不在任何都市，就像骑马时所见到的小地方
        在这一个月里，玩家带同亲兵游山玩水，提升自己的技能。游山玩水
中，玩家会遇到
        1)      战争难民。      给钱或粮食，            长治国修养
        2)      圣贤对棋。      胜或负                  长兵法修养
        3)      打垮山盗        带同亲兵打山盗          
                                成功                            长武学修养和
                                                               长亲兵训练度
                                失败                            名声下降很多
        4)      河水泛滥        带同亲兵治水            
                               成功                           
长名声和治国修养
                               失败                            名声下降很多
        5)      偶遇圣贤        答对圣贤所问            长阵法经验100
                                                               技能中升1 级 
                                                              
(任何技能，但不是
                                                              
WXXY，BFXY OR ZGXY)
                               答错圣贤所问            一项技能下降1级
        6)      擂台比武        比武胜                  长单挑能力和武学修养
                               比武                            长武学修养
        7)      游江救婴        成功                            长基本水计
                                失败                           
名声，忠诚，水计下降
       8)      打包不平        带同亲兵打市街流氓
                               成功                            长武学修养和
                                                             长亲兵训练度
                                失败                            名声下降
        9)      杀狼救童        成功                           
任何一项技能长经验150
                               失败                           
名声下降                
        以上是一些小提议，WIZ 是否采用， 全由WIZ否决定。


---
作者: Row
题目: >空中司令的建议
日期: Tue Apr 13 22:47:16 1999
空中司令的建议非常的好，关于特殊亲兵的问题，我记得以前和
fire讨论过，也就是给亲兵配备相应的装备便可以使他们成为相应
的部队；运粮草可以做成一个中级job，还有fire说过战争也会
引进粮草系统；阵法相信flee会尝试的；修行是个非常有趣的提
议，只不过目前似乎都没有时间来完成。:)


---
作者: Fire
题目: 空中司令的建议
日期: Tue Apr 13 11:16:43 1999
关于三国
1)      关于战争
        在三国时，关羽有校刀手，典伟和许(zhu)有虎卫军，甘宁有百羽军
，马超有锦超军，孟获有藤甲兵，公孙钻有百马军，等等都是特别精兵。希望
在 Mud 里能够看到。
建议：
        如何征收这种特殊亲兵？
        现在的玩家，大多数都有10名亲兵。只要有一指令(改装部队)，
凭玩家现有的技能和金钱，玩家就能改装自己所喜欢的部队。一旦改装了，玩
家就不能再改成其他部队。除非玩家完全解雇所有亲兵，然后在重新开始改装
部队。
        只有当上朝廷命官，玩家有足够的钱和技能，就能够训练并强化自己
的精兵。例如：
        特殊精兵        必备品  玩家技能
        校刀手  长刀            刀法和dodge 技能20 以上
        虎卫军  卓戈            卓戈法和骑术20以上
        百羽军  长剑            剑法和基本水计策20 以上
        锦超军  长枪            枪法和骑术20以上
        藤甲兵  藤甲            刀法和基本水计20以上
        这一切都可任您(wiz)改。如何强化？ 只需要买更好的同类武器就可。
        还有，就是每当玩家的技能上5点，精兵就上1级。
        百羽军(1 级)    玩家技能 剑法(20) ， 基本水计 (20)
        百羽军(2 级)    玩家技能 剑法(25) ， 基本水计 (25)
        百羽军(3 级)    玩家技能 剑法(30) ， 基本水计 (30)
        级数上升了，精兵的生命力，攻防力也上升。当然，这种亲兵的每年
费用也比普通亲兵高了很多。
        对了， 古时战争，粮食是一项重要部份。希望下次战争中有运粮官和粮草。
2)      关于阵法
        引用光荣公司(KOEI)三国志5 的阵法。
        控制每一个玩家最多会三门阵法。
        每一个玩家(NEWBIE JUST LOGIN) 一开始就会一门阵法。已在线的玩
家可        从WIZ 里要一门自己喜欢的阵法。
        第2 门阵法可向任何人(NPC OR PLAYER) 学习，第 3
门阵法(特殊阵法)由       WIZ 自创。玩家只有在长期战争中增加战争经验
，当战争经验长到一定水准，就可向WIZ 学习。
3)      修行
        在三国中，诸葛亮，徐庶，庞统，郭嘉，刘哗等都有一段游山玩水的
修行过程，不知能不能把这修行当著一项(JOB)
        (JOB) JOURNEY
        必备马匹，粮食，和亲兵。
        游戏时间一个月。一天知能重复两次
        地点不在任何都市，就像骑马时所见到的小地方
        在这一个月里，玩家带同亲兵游山玩水，提升自己的技能。游山玩水
中，玩家会遇到
        1)      战争难民。      给钱或粮食，            长治国修养
        2)      圣贤对棋。      胜或负                  长兵法修养
        3)      打垮山盗        带同亲兵打山盗          
                                成功                            长武学修养和
                                                               长亲兵训练度
                                失败                            名声下降很多
        4)      河水泛滥        带同亲兵治水            
                               成功                           
长名声和治国修养
                               失败                            名声下降很多
        5)      偶遇圣贤        答对圣贤所问            长阵法经验100
                                                               技能中升1 级 
                                                              
(任何技能，但不是
                                                              
WXXY，BFXY OR ZGXY)
                               答错圣贤所问            一项技能下降1级
        6)      擂台比武        比武胜                  长单挑能力和武学修养
                               比武                            长武学修养
        7)      游江救婴        成功                            长基本水计
                                失败                           
名声，忠诚，水计下降
       8)      打包不平        带同亲兵打市街流氓
                               成功                            长武学修养和
                                                             长亲兵训练度
                                失败                            名声下降
        9)      杀狼救童        成功                           
任何一项技能长经验150
                               失败                           
名声下降                
        以上是一些小提议，WIZ 是否采用， 全由WIZ否决定。


---
作者: Row
题目: >空中司令的建议
日期: Tue Apr 13 22:47:16 1999
空中司令的建议非常的好，关于特殊亲兵的问题，我记得以前和
fire讨论过，也就是给亲兵配备相应的装备便可以使他们成为相应
的部队；运粮草可以做成一个中级job，还有fire说过战争也会
引进粮草系统；阵法相信flee会尝试的；修行是个非常有趣的提
议，只不过目前似乎都没有时间来完成。:)


---
作者: Fire
题目: 关于SGSYS
日期: Fri Apr 16 00:03:55 1999
关于SGSYS
  SGSYS是一个非常方便的监控程序，它用于监控某些敏感部分。
  例如对于地区的安定，训练和士气。我们可以强制其最大值是
  200。但是我们可能不会注意到某些使其值突飞的BUG。因此，
  在系统中加上这一句，当其值超过最大值，不仅强制其为最大
  值，同时用SGSYS来提醒在线WIZ注意。注意检查这是一个正常
  的超值还是一个BUG。
SGSYS的用法：
  在程序中直接加上：
  SGSYS("提醒的内容");
例子：(选自 /daemons/area_d.c)
	case "train":
	case "morale":
	case "safe":
		if(para_value>200) {
			SGSYS(sprintf("%s的%s超高，值为:%d，现强制为200",p_id,para_name,
			para_value));
			para_value=200;
		}
       areas[p_id][para_name]=para_value;
       p_ret="地区参数设置成功．\n";
       break;

执行结果：
  【系统】三国监控：xianyang的safe超高，值为:300，现强制为200
来自：/daemons/area_d


---
作者: Flee
题目: agree fire
日期: Sun Apr 18 01:08:11 1999
i feel that the basic job is even
harder than middle job, it surely make
new players hard to start.


---
作者: Fire
题目: about current job
日期: Sat Apr 17 20:32:41 1999
什么是当前最紧迫的工作。
    本MUD从开始汉化到现在已经有两年了。而现在还不能正式开放这对
我们来说是一个不幸。现在，我认为玩家在游戏中成长过程已基本都具备
了。所以我们目前最主要的核心工作是完成必须部分，优化现有部分，简
化新手入门部分。然后使本MUD尽早开放。因此我建议调整计划表，新的
计划表见下：
1   目前唯一必须的较大的新的系统是国家会议，现在已经有了国家频道(na)
    国家会议将在国家频道中进行。国家会议的主要议题是在地区间运送
    粮草物资等。外交虽然有趣，但不是必须的。正式开放后在考虑。
2   目前的战争已经非常复杂，其中有很多潜在BUG，我认为对于战争，当
    前只排除BUG，优化公式，提高NPC部队(尤其是防守方NPC部队)的AI。
    至于计谋，阵法，私人兵种与特种兵种，单挑和被俘将军等涉想一律
    推迟到正式开放后。
3   已有的JOB和QUEST(游泳，灭火)等，全要整理一下，剔除BUG，完整
    HELP文件。
4   简化优化新手联线地区。这也许是目前最重要的工作。我们的MUD对大
    多数新手都太过困难。没有巫师和老手的帮助，很多还没摸到们就知
    难而退了。我想这是我们玩家人数持续不升的一个主要原因。特别是
    POST，一进们就是500+POST，谁能看完？
5   丰富JOB种类，对于D_OBJ，是很容易做出新类型JOB的。
6   地区优化：我们有19个地区，大部分都不错了，但都还有些小问题。
    有的地区没有睡觉的地方，有的没有灌水得地方。和地图不一致等。
    我建议每个WIZ负责两到三个地区的这些问题。保证地区的基本建设。
    保证房间地图的一致。(我将负责华阴，洛阳和长安三地。)
7   主页，一定要好。多用CGI，今后的更新就不是太大的问题了。
大家看看有什么意见。


---
作者: Guanfeng
题目: none
日期: Sat Apr 17 17:34:59 1999
我赞成多兵种的建议,还有我觉得可以增加个城市之间运粮的job
押粮官武官才可以担任，如果有木牛流马，可以大大节省运粮的时间

文官和武官的job应该各有特色，不要太多雷同


---
作者: Fire
题目: >对战争部队的一点提议。
日期: Sat Apr 17 04:41:58 1999
有道理
xixi :)


---
作者: Group
题目: 对战争部队的一点提议。
日期: Sat Apr 17 04:39:43 1999
不知道大家玩过《战争与商人》这个游戏没有，不过我们觉得
这个游戏中关于兵种的设定值得在三国里运用。这种模式大致
是这样的：所有兵一征出来是民兵，当给民兵武器则成为步兵，
给步兵马则成为骑兵，给骑兵甲则成为重骑兵。。。这样整个
兵种的发展就是一种科技树，我们可以通过设计这种科技树来
让玩家自由发展自己的兵种。各种兵种应当由各自的独立文件
来控制，包括攻击力，防御力，各种地形对能力的影响，对计
谋的抵抗力，兵种之间的相克性，统御者所必需的能力，适用
的阵法。。。等等。这样便于管理，也便于发展。另外，有些
城市不妨设计成为有特别兵种，比如西凉的铁骑，建业的飞龙
水军，长安的连弩弓兵等等。我们想如果可以完成这样的一个
兵种系统，对三国的吸引力和可玩性都会有更大帮助，而且能
使玩家注意到除战争之外的发展部分，使游戏更有多样化。
请大家讨论。


flee, group.


---
作者: Row
题目: 1 suggestion
日期: Wed Apr 21 03:05:19 1999
建议在玩家每次连线的时候可以收到游戏在其不在线
的一些信息，比如大事记中的国家建立或灭亡，某地
被某国占领等等，还有巫师对游戏部分的修改，省却
了玩家看post的麻烦。
（巫师现在连线就能收到某某对游戏的改动等等，可
以做成同样形式，系统信息自动张贴，而巫师也可编
写信息。）

大家以为如何？


---
作者: Flee
题目: agree row 
日期: Wed Apr 21 04:59:26 1999
as title.


---
作者: Fire
题目: >1 suggestion
日期: Wed Apr 21 23:04:07 1999
On Wed Apr 21 03:05:19 1999 Row wrote post #346:
> 建议在玩家每次连线的时候可以收到游戏在其不在线
> 的一些信息，比如大事记中的国家建立或灭亡，某地
> 被某国占领等等，还有巫师对游戏部分的修改，省却
> 了玩家看post的麻烦。
> （巫师现在连线就能收到某某对游戏的改动等等，可
> 以做成同样形式，系统信息自动张贴，而巫师也可编
> 写信息。）
> 
> 大家以为如何？

good idea, will add it



---
作者: Row
题目: >一点意见
日期: Fri Apr 23 23:55:30 1999
确实我们缺area，yuyin是否可以参照map southwest和现有的
cities加城市？不过最好把southwest的地图对照三国时期地图
将地名补全。
addoil yuyin


---
作者: Yuyin
题目: 一点意见
日期: Fri Apr 23 23:50:14 1999
我觉得现在的 npc 已经足够了,
因为我们现在多了不少的 player
经常在一座城就有十几二十个隐居贤人
所以我们现在应该把 system 完善,
因为现在的 area 还少,等 area 多了以后,再加 npc 还可以
addoil fire
addoil row
addoil flee
addoil swallow


---
作者: Row
题目: some player's suggestion
日期: Fri Apr 23 01:24:55 1999
1. suggest to make cmd call/(6) functional, but it will cost
u more money compare with findbody thru boy.
2. suggest to add "ban war" in "pos" menu, a taishou should
be about to ban his officer to declare war to others when
he is offline, but may only last for few hours.


---
作者: Fire
题目: for makers
日期: Thu Apr 22 08:09:56 1999
please use "cl list" to check obj maker information


---
作者: Row
题目: checking typo under /help/player/sanguo/
日期: Thu Apr 29 01:49:04 1999
as title.


---
作者: Fire
题目: about OBJ and MAKER
日期: Wed Apr 28 04:28:49 1999
关于OBJ和MAKER
wizard 用 check <obj_id> 可以发现有哪些工匠可以制做
该OBJ。同时用 cl list 和makereditor 中的list 功能可以
列出OBJ与MAKER的对应关系。这些都可以帮助我们平衡他们
的关系。
下面有几个基本原则：
1 只有等级0-5的物品可被工匠制做
2 一个工匠制做的物品数不超过7
3 每一个0-5级的物品至少有一名工匠可做。
4 物品等级与可制做工匠数的对应关系
   物品等级     西北地区可制做工匠数    全国可制做工匠数
   0            3-5                      8-15
   1            2-5                      8-15
   2            1-4                      6-10
   3            1-4                      4-8
   4            1-2                      4-6
   5            0-1                      1-3
这样我们可为玩家分配不同难度的JOB
xixi:)


---
作者: Fire
题目: the bug of random emote for a on line players
日期: Wed Apr 28 00:43:59 1999
has been fixed.
it is in the ev_randdisapp.c
because now I use a new method to judge online or
not so that the old filed "status" in char_d
is obsoluted

xixi

thank row


---
作者: Row
题目: typo
日期: Tue Apr 27 03:27:06 1999
i checked all files under /sgdomain/event/, anybody who
wanna change those files, pls download b4 upload. thx.


---
作者: Row
题目: files under /sgdomain/cmd/ checked over
日期: Tue Apr 27 04:46:21 1999
as title.


---
作者: Row
题目: idea
日期: Wed May  5 03:55:58 1999
目前的城市系统有flyroom和meetingroom，本人建议再
加上一个goroom，专门为旅行者留的，也就是靠马匹及驿
站到达某一城市的玩家。这个goroom一般设在城外，因为
考虑到将来增加难度，玩家将不可以随意进入他国领地，所
以在goroom通往该地的道路上设卫兵，自动检查玩家对该
国的友好程度，若低于某值将不予放行，而此时玩家面临多
重选择：杀卫兵（卫兵很厉害的哦）；贿赂卫兵（魅力值）；
恐吓卫兵（武力值）；迷惑卫兵（假扮该国人士混入，可以设
计一个伪装技能）等等，当然都不是百分百成功的。这样一
来，job的难度增加了，众人发展的速度也不会如此之快了。

各位以为如何？


---
作者: Row
题目: some change
日期: Wed May  5 04:55:39 1999
for the convenience of coding, i moved yizhan files
to /sgdomain/yizhan/...


---
作者: Fire
题目: about the new areas
日期: Wed May  5 23:27:52 1999
now we have about 24 new areas in southwest.
please don't touch them now. I will create a tool
to auto set all the basic things for them. when I finish it (perhaps
today or tomorrow) then I will post here.
addoil


---
作者: Fire
题目: about board
日期: Thu May  6 10:32:49 1999
I adjust sth in the news system.
1 for many not very useful groups, I put all the messages to the
  archie and then remove those groups.
2 for the most frequent news group such as caolu and wiz.com, I
  set the archie time as 90 days, (caolu 30 days) this means any
  message in these group post certain days before will be moved
  to the archie, this will save us a lot memory
3 make news command as wizards command
4 each country will automacally has its own group and the board
  put on every meeting room
5 some change for player's board, detail see help board.


---
作者: Group
题目: 工作声明
日期: Fri May  7 10:00:02 1999
考试已经完成，这段时间我们将完成有关战争的一部分更改
具体工作计划如下：
1。 改进TROOP_D 使其适应于新的部队系统。
2。 完成各种兵种的设计以及分配城市可征的兵种。
3。 具体兵种的能力将在完成后POST出来以供讨论。
4。 完成各种计谋。完成后将POST具体设计。
5。 完成各种阵法以及其对部队的影响。
6。 如果还有时间，将完成一些和部队有关的个人能力。

如果有意见的话，欢迎POST！

flee, group


---
作者: Fire
题目: >工作声明
日期: Mon May 10 20:06:29 1999
On Fri May  7 10:00:02 1999 Group wrote post #362:
> 考试已经完成，这段时间我们将完成有关战争的一部分更改
> 具体工作计划如下：
> 1。 改进TROOP_D 使其适应于新的部队系统。
> 2。 完成各种兵种的设计以及分配城市可征的兵种。
> 3。 具体兵种的能力将在完成后POST出来以供讨论。
> 4。 完成各种计谋。完成后将POST具体设计。
> 5。 完成各种阵法以及其对部队的影响。
> 6。 如果还有时间，将完成一些和部队有关的个人能力。
> 
> 如果有意见的话，欢迎POST！
> 
> flee, group

good, good

just a little suggestion:

1 make the defence part a little strong than the attack part

2 be careful no obvious bug the player controled troop too superior
to npc troops

addoil

:)


---
作者: Fire
题目: about the change of troop_d.c
日期: Wed May 12 02:06:45 1999
hi flee,

Isugggest that you just modify the original troop_d at it's original location
 because i may change it too. if we have two copy, we may cover each
other and caouse conflict.
and because you are not familiar to the troop_d.c
so when you add sth, add the comment on the function or centance you
added. if you remove or modify some
sentence, also make comment so if got confilct, easy to locate and
change back. 
addoil flee


---
作者: Flee
题目: to fire, about troop_d
日期: Tue May 11 23:40:17 1999
i have read the original troop_d and change it a 
little bit, i put the new one under /wiz/flee/
troop/troop_d.c. there are tow featuer i made
first is adding a function called recover energy
instead using warai_d. second is when remove troop
because now troop have many types.
I just found that even testing the new troop_D is 
very difficult, cos too many daemons interact with it .. :(
please have a look.


---
作者: Row
题目: war has bug?
日期: Thu May 13 23:50:40 1999
i put war.c as war.bak now, so that banned war, pls check for the bug

if war a 0 soldier, or 0 npc area, will auto lose however u have more soldiers


---
作者: Fire
题目: about the board of newbie
日期: Wed May 12 23:09:51 1999
the board for newbie will be only used to give
some very nice organized help files, so for general
post, please post in the caolu board.

xixi:)

thanks



---
作者: Group
题目: 升级列表
日期: Wed May 12 23:36:57 1999
兵种升级之列表已完成，在/WIZ/GROUP/TROOPS 下。文件名
为UPGRADE和UPGRADE1。后者是给玩家看的。


---
作者: Group
题目: shutdown
日期: Mon Jun 14 03:10:11 1999
system shutdown 2 times for no reason. 

please check.
group


---
作者: Fire
题目: the color welcome file
日期: Sat Jun 12 02:47:44 1999
ice and i create a new color welcome page
now I put it under /sgdomain/txt/welcome/WELCOME.txt

this is our mud's face, so welome any suggestion and
discussion


---
作者: Fire
题目: reboot without any reason
日期: Fri Jun 11 22:44:15 1999
当地时间                九十九年六月十一日下午十时四十二分
三国启动于              九十九年六月十一日下午十时四十二分
本次运行时间为          四十三秒钟
> 【系统】白梨云进入三国。

say crush ?
say i just reboot several mins before

then it reboot without and message, crush or ?


---
作者: Ice
题目: about 黑名单
日期: Sat Jun 12 12:50:13 1999
if a king travel around in his nation and set all black list in cities,
then seems a little bit 滥用? 


---
作者: Fire
题目: 关于ice的建议
日期: Mon Jun 14 09:07:32 1999
ice 给出了一个非常全面的建议，很有创造性。
这使我想起了以前的一些POST，许多都有很多有意思的设计。
但很遗憾的是我们目前开放能力有限，所以许多建议不能真正
实现。其实这并不是一个我们特有的问题，看看KOEI的三国。
每一板都加些东西，但也得舍去些东西，样样都全的版本是没有的。
我想开发能力，开发时间等限制也是一个因素。


所以我想说的是，我们不能期望开发一个十全十美，样样满意的MUD。
我们必需学会舍取。目前这个版本，其内容已经相当丰富。
之要在做一些调整，和部分系统的补充完善，就可以成为一个完整的MUD。
但这不等于我们就不考虑那些新的，有意思的系统，但我们目前
最主要的任务是：
1  消除BUG
2  填补必需的空白
3  调整一些参数和公式，始其平衡，合理。
4  文档和界面的美化。
5  也可考虑一些相对独立的，有趣的设计。如：灾难，比武大会等

完成这些，我们就可以正式开放了。而那些复杂的，有趣的设计可以放到下一个
版本。


说了这么多，最重要的任务是：排除BUG :)


---
作者: Flee
题目: >> agree fire
日期: Mon Jun 14 09:44:07 1999
agree with fire .. :)
there r many many thing we can use, but for
now, the most important thing is bug-fix and
make formular more reasonable.
of cos, any comments, suggestion and plan are  
welcomed anytime .. :0
addoil all.


---
作者: Row
题目: >>> agree fire
日期: Mon Jun 14 11:41:58 1999
On Mon Jun 14 09:44:07 1999 Flee wrote post #501:
> agree with fire .. :)
> there r many many thing we can use, but for
> now, the most important thing is bug-fix and
> make formular more reasonable.
> of cos, any comments, suggestion and plan are  
> welcomed anytime .. :0
> addoil all.

anyway, i really hope that the new combat sys i
discussed w/ flee can be create in the first version.
addoil all.


---
作者: Row
题目: new bug in war?
日期: Thu Jun 10 23:15:28 1999
the troop's morale become 0 when in battle field...
what happened...flee or fire pls check,
fire, is that becoz of u changed commando's file?


---
作者: Row
题目: 统一？
日期: Thu Jun 10 08:29:29 1999
我已经和cdd 达成协议，他暂时不会灭wdoll、derek、cnl等
以统一全国，但我个人答应他可以灭马腾，擅自作的决定，
不知是否得到大家的认可。所以，我认为现在不必修改任何
的数据，关键是利用这段时间重点考虑一下战争和内政的
平衡关系，修改bug ，完善系统。大家一起努力呀！


---
作者: Fire
题目: 关于宣传
日期: Thu Jun 10 07:23:05 1999
我在三个其他MUD中POST了一下本MUD的一些精彩POST
不只会不会被删掉，也不知会不会有效果。:)


---
作者: Fire
题目: bug ?
日期: Thu Jun 10 06:53:24 1999
today i tested the train and find two thing strange
1 烈火国第一军团
军中大将：
烈火国主公「复苏」烈火，字嘿嘿(fire)
烈火国建宁武官虎口，字啊呜(mimi)
 兵种　  数量　 训练  士气　机动力
 新兵     712    45     0    11 

how the morale becomes 0 ?

2 when i look find the enemty troop display as D
it should be A

strange
strange


---
作者: Fire
题目: 部队移动消耗不合理。
日期: Thu Jun 10 06:45:41 1999
一支部队最大的机动力是30，但一次移动就要消耗20
不合理。同时在水里消耗22，平原消耗20，这个差异也太小。
:)


---
作者: Row
题目: 文武分家
日期: Mon Jun  7 22:40:53 1999
为了使三国志向更真实的方向发展，我建议实行文武分
家，也就是玩家要么从文，要么行武，所面临的也将会
是两条不同的发展道路。

因为在三国世界中，文武双全的人物实在是凤毛鳞角，
少之又少，而看看目前我们的玩家，基本上都是兵法修
养和武学修养齐头并进，故在不久的将来，武力及智谋
均在90以上的官员随处可见，人人都是多面手，既能领
两军交战，单挑杀敌，又能开发内政，巧施计谋。这似
乎与理不合。

所以我建议将系统重新定义一下。目前天赋限制技能等
级的功能保留。武学修养对应武力，是武官的升级依据
及主要修炼对象；兵法修养对应智谋，是文官的升级依
据及主要修炼对象；而治国修养对应魅力，既是文官也
是武官的升级依据及修炼对象。武学及治国修养达到31
级就可当武官，而兵法及治国修养达到31级就可以当文
官。在此必须要提醒玩家的是，做了武官，则获得兵法
修养经验的机会将会减少，而兵法修养升级所需花费的
经验也将会是升级武学的三至四倍，文官的情况也是一
样，但治国修养没有限制。

既然技能上文武分了家，那么工作系统上也需要分家。
文官所做的工作与武官所做的不同。文官主要从事内政
开发，武官从事征兵打仗，而寻访贤人、游说敌将等工
作主要是看魅力的高低，两者都可以做。这样便可以实
现目标明确，文武合作治理地区的局面。

再来看看战争。为了公平起见，我们可以将最有意思的
计谋部分也分一下工。也就是说，文官所会的计谋与武
官所会的不同。文官的计偏向于巧妙，如：流言、混乱
等等；武官的计谋偏向于刚猛一路，如：鼓舞、奋发等
等；而一般的计谋如火计、水计、落石、伏兵、陷肼等
等只要外部条件允许，文武官员皆可使用。但武将有单
挑的特权，文官则有特殊计谋的本事。如此，在战场上
也可以实现文武合作，共同杀敌的局面了。

以上意见，希望大家讨论并补充完善。


---
作者: Fire
题目: >about history_d.c
日期: Mon Jun  7 19:48:24 1999
On Mon Jun  7 00:24:53 1999 Row wrote post #478:
> 现在的history好象是后发生的事先显示出来，似乎不太
> 合阅读的先后顺序，是不是改为按照早发生的事先显示
> 比较好一点？

support row ;)


---
作者: Group
题目: about emperor
日期: Mon Jun  7 01:35:19 1999
fire, it seems emperor still cant be refreshed when the system
reboot, p check it..:)

group


---
作者: Stefan
题目: suicide
日期: Tue Jun  8 02:25:15 1999
command suicide now works. I moved it from /sgdomain/cmd/ to /cmds/player
and it is the USER_D that handles the suicide, there is no longer a 
SUICIDE_D. 


---
作者: Flee
题目: >>文武分家
日期: Tue Jun  8 03:23:32 1999
agreed.
classify officers to two type, each of them
have their own goodpoints and shortpoints.
so the only way to success is coorpation
this will be our game more intresting and attrative.


---
作者: Ice
题目: about soldier amount after war
日期: Tue Jun  8 18:30:06 1999
luoyang has 38k b4 war, and because liyu just used 1 soldier to 
defend, after war, there are still 38k soldier in luoyang,
pls notice this problem when fire and flee check the war files
8O~~


---
作者: Fire
题目: >about soldier amount after war
日期: Tue Jun  8 20:14:57 1999
On Tue Jun  8 18:30:06 1999 Ice wrote post #485:
> luoyang has 38k b4 war, and because liyu just used 1 soldier to 
> defend, after war, there are still 38k soldier in luoyang,
> pls notice this problem when fire and flee check the war files
> 8O~~

this bug fixed


---
作者: Fire
题目: two systems of troop types
日期: Tue Jun  8 20:47:59 1999
I examed group's code and find it hastwo systems
1 is that we just recruit footman and under certain condition
  it can updated to  other types of troop and other type can continue update
2 the second system is that we can recruit certain type of troops
  in certain area.

both systems are good, but we will mainly stick on the first
system and the second system will be considered later.


---
作者: Group
题目: about upgrade
日期: Wed Jun  9 02:26:44 1999
there actually only got 1 system
all troops recruited will be footman, and when it's morale and train
increased,
and there are enough equip to use, they can upgrade to 2nd level troops.
same as 3rd type. 
but for 4th level troops, they are limited by some area. that means
the 3rd level troops which can be only upgraded in certain city.
we set the special cities all around the whole map to ensure the balance. 
this is the way to limit the number of most powerful troops.

if got other quetions, please post it..:)

group


---
作者: Group
题目: about the move 
日期: Fri Jun 11 09:10:45 1999
actually the difference of the moving consuming is dependent on troop types,
and since there are quite a number of troops and we design that higher troops
should be better than lower troops, there are some unbalance about
the moving consuption.
and now the recover mostly dependent on the morale and train, which
makes the troops recover very fast.
fire, you can just balance the consuption as well as the recover to
a reasonable speed, and which can show the different advantages for 
different troops.

actually i think maybe use 100 as the up limit maybe better, since
can have more difference between troops. 

hope can see the upper level troops moving in the war...:P

addoil..:)
group


---
作者: Flee
题目: >>about history_d.c   
日期: Mon Jun  7 01:00:17 1999
changed.
..


---
作者: Row
题目: about history_d.c
日期: Mon Jun  7 00:24:53 1999
现在的history好象是后发生的事先显示出来，似乎不太
合阅读的先后顺序，是不是改为按照早发生的事先显示
比较好一点？


---
作者: Ice
题目: about multi-log in war
日期: Sat Jun  5 10:28:59 1999
Let me give an example,
yunnan used to have over 2k armies, and jianning has 800,
a player control 2 ids, one in jianning, and one in yunnan,
then in 1 min, yunnan is over, because he use the id in yunnan 
to use the least army he can use.  At that time, some players jumped, 
query me that if multi-log in war is legal, then i talked to that 
player, he said because some players used this method to get cities
from his nation, he just followed the same way to do it.
I think if we don't try to control this problem, it might become a 
very bad circulation, because this kind of actions is erasing our meaning
of war, just like we play SAN5, if we control all king ID, we can unify
in 30 mins then finish the game, but that's meaningless.
I think we can use the pos
add an option like forbid war or make some kinds of low lv id cannot get
involve in war so easy.
That's it.


---
作者: Fire
题目: about war
日期: Sat Jun  5 09:41:54 1999
about war, I will do the following adjustment
1 create a daemon ttype_d.c to handle all the defination about troops
  this ttype_d.c can be called by warai_d->query_troop()
  so many code still keep compitable
  this function also read all infos from group's troops files
2 define the upper limite of a char's max number of soldiers
3 arrange and document all the fomula for the war system
4 give a detailed help file


---
作者: Fire
题目: about the desc in room
日期: Sat Jun  5 07:50:57 1999
I adjust the display in room
so a player with long name and many colors will not get his name 
displayed in two lines.
xixi ;), so row can change his guard's desc to his original designs :)


---
作者: Fire
题目: about the war
日期: Sat Jun  5 07:09:27 1999
我仔细看了看flee 和 group 关于战争和多兵种的code
其中许多设想和构思都不错。
但是由与原设计在思路上有些差异
@CHAR_D->get_char("cdd","colth")

但是有些地方与以前的设计有些不一致
所以引起了一些明显和潜伏的BUG。
现在我计划用一周左右的时间整理一下现有的战争系统。
在保留flee,group新加的内容的基础上，对整个战争系统做一
次规范化和一致化的调整。
同时给出完整的文档。
同时关于新的系统设计和系统升级希望参照以下的开放步骤：
1 系统构思，这里面包括系统目的和主要过程，例如对于一个
  新的JOB，系统构思主要指该工作的等级，对象，工作申请，
  执行和领取报酬的大致过程，和指令
2 公式，公式一定要明确，特别是对于例如战争，单挑这样
  有着复杂运算的系统，一定要把公式先列出来。
3 实现方法，一个系统可有多种实现方法，在具体编程之前
  要想一想用什么方法实现最为合理，高效，可靠。需要列出一
  个新增文件和需要修改的文件清单。
4 第4步才是编写代码。
5 不要忘记测试和给玩家的帮助文件：:)



---
作者: Fire
题目: >about multilog in war
日期: Sat Jun  5 05:48:21 1999
On Fri Jun  4 15:16:53 1999 Ice wrote post #470:
> multilog in war made a lot of trouble, so I hope we can post
> a serious warning in caolu, or in the history_d, otherwise will
> discourage players to continue playing this mud.  I think we will make it
> not so easy to multilog to win a war, but now, we don't want to lose our
> player as well, so please consider to make a serious warnning for the
present
> situation.

what is the serious of mult-login in war ?
can you explain it more specific, so let's see can we don some thing
to solve this problem :)


---
作者: Flee
题目: about fight
日期: Sat Jun  5 01:51:48 1999
the damage of hit in fight should be reconsidered,
cos most players got good armor, the damage now is
less than player's recover. today, i saw cdd fight with
cnl, they fight for around 5 mininutes, both kee is
still higher than 200.


---
作者: Ice
题目: about multilog in war
日期: Fri Jun  4 15:16:53 1999
multilog in war made a lot of trouble, so I hope we can post
a serious warning in caolu, or in the history_d, otherwise will
discourage players to continue playing this mud.  I think we will make it
not so easy to multilog to win a war, but now, we don't want to lose our
player as well, so please consider to make a serious warnning for the present
situation.


---
作者: Fire
题目: about ftp
日期: Thu Jun  3 09:39:17 1999
when you upload and download, please remember to use
ascii mode. 
ascii mode. 
thank :)


---
作者: Fire
题目: the bug in the war about attack no leader area
日期: Thu Jun  3 09:22:32 1999
is fixed
please report other bugs :)


---
作者: Flee
题目: more about war
日期: Thu Jun  3 09:09:47 1999
cmd retreat is located at /sgdomain/cmd/retreat
upgrade and divide cmds is still under my dir
not test yet .. :)


---
作者: Fire
题目: i try war one more time
日期: Thu Jun  3 08:22:50 1999
seem that bug of can't retrieve soldier's number is fixed

addoil


---
作者: Fire
题目: another bug in war
日期: Thu Jun  3 08:16:46 1999
when look, some time i find our side's troop
got enemy troop's color
:P


---
作者: Fire
题目: about the bug in the war
日期: Thu Jun  3 08:06:08 1999
some times the function int get_soldier_total_number(int p_id) in
troop_d seems got wrong answer.
now i have make some adjustment,
see the result in one war is right
some time if we test if one mapping or an array is empty
we use if(!maping) and so, seem this function is not very safe
the safest way is use if(!sizeof(maping))
addoil :)


---
作者: Flee
题目: about war
日期: Sun Jun  6 02:06:24 1999
1) Area_d
   the troops are stored use a mapping.
2) Troop_d
   which controls a mapping, it stores all information about 
   all troops. key is it serials number, value is a mapping
   too, in this mapping, keys are general, side, ... ect. and 
   soldier, which is also a mapping, keys are the troops type,
   values are detailed information such as energy, .. ect.
3) Ttypes_d
   which store detailed information of various type of troops. 
   such as energy recover in deffirrence satuation, requeirment 
   of upgrading and basic attack value, .. ect.
4) Warai_d
   which controls the interaction of troops, attack, deffence
   .. etc. it inherit condition.c and apply.c these are used 
   to control some special properties of troops
5) Process of war.
   a) At localmeeting, declare war, create a war task controled
      by task_d.
   b) After localmeeting, go to attack arrange stage.
   c) Use AREA_D->query_area(x,"troop") to get al troops availble.
      and all generals for attack.
   d) Input.c which controls the input process.
   e) If no general left, no troop left or the leader decide, attack
      arrange stage over, def_arrange.c create troops based on 
      informantion stored in task_d.
   f) All troops of attack are moved to the warmap of deffence city
   g) Defence arrange step starts, similar as attack arrange, but
      defence site has one more type of troop, citizen.
   h) Defence troops are moved to the warmap, war starts.
   i) Troop_d check all troops are legal or not(decided by task_d).
      if not, remove that troop. at the same time, it will recover
      troop's energy via ttype_d. and update troop's condition via
      warai_d.
   j) Warai_d takes care of troop move, and use troop_d to substrate
      the energy need by using ttype_d.
   k) Attack is controled by warai_d, when send a attack cmd, warai_d
      first check whether it is possible, then check the type of attack
      and calculated the damage based on informantion from troop_d and
      ttype_d, and also query the troop's condition and applied damage,
      after that, get the deffence ability of defence troop via troop_d
      and ttype_d plus condition and applied defence. finally do attack
      and check NO of soliders. if it is zero, remove that troop.
   l) During the war process, check_result.c of ev_war keep checking
      both side of troops. if no defence troop left, declare attack
      site win; if no attack troop left or the no leader' troop,
      declare deffence site win.
   m) At end of war, all troops are removed by troop_d, soldier then
      stored use area_d.
6) About apply.c and condition.c
   Both of them are part of warai_d.c, apply.c is used to add some
   temporary properties of troop and will upgraded by troop_d at 
   troop checking. condition can be treated as a complex apply.
7) types of war
   Now only two type of wars, one is bandit attack, another is city
   attack, we can add more type of wars by changing check_result.c


---
作者: Fire
题目: about the war
日期: Thu Jun  3 07:20:59 1999
hi flee,
what is the command for update troop,
seperate troop and retreat ?
thanks :)


---
作者: Fire
题目: what is this ?
日期: Thu Jun  3 06:55:56 1999
◎三国大事记◎
三国二百零九年七月下旬
第一届三国武将争霸大赛结束，包包(babu)在等级四比赛中获胜，特奖励
黄金十两，名望100点，忠诚10点。望众人继续努力，来年再争高下。

is it a new system, or just a rumor :)


---
作者: Flee
题目: changes of war
日期: Thu Jun  3 00:31:01 1999
1) area_d, change the data type of solider from 
int to mapping;
2) troop_d, change remove_troops and create new
function recover_eng instead of use warai_d;
3) warai_d, change check_move, the energy cost
will depends on the type of troops;
4) files under /sgdomain/event/war
modify four files, def_input, def_arrange, att_input 
and att_arrange.
remove all parts of max_soldier, max_horse .. ect
instead use area_d to get the troop availble

   



---
作者: Fire
题目: about the query_ilog_time()
日期: Wed Jun  2 22:22:28 1999
now i updated it so players can also use that function
so the time login will be recorded :)
cheers


---
作者: Ice
题目: 关于朝廷官职及州郡官职
日期: Wed Jun  2 22:21:56 1999
三国时行三公九卿之制，以及一群征XX将军、镇XX将军等等等等，

丞相：百官之长，如曹操、诸葛亮之流，掌管一切内政军机大事。
      丞相下设两长史，相当于秘书长，以及数名参军。

侍中：又称散骑常侍，出从皇帝车骑，入侍左右，得以亲近政事，
      可分为侍中、常侍、与黄门侍郎，可于尚书共平奏事。

御史：主事为御史大夫，副手为御史中丞，下属治书侍御史、给书
      执法御史、侍御史、殿中侍御史。其职督司百吏，有违法宪
      者，皆可弹劾。

尚书：主事为尚书令，下辖左右仆射二人。共有尚书五名，称五曹
      尚书，掌管殿内文书。

中书省：主事为中书令监，下设中书侍郎、中书通事舍人及著作郎。
      主管朝廷之机要秘密文书诏令的传达而不经由尚书。

秘书监：主事为秘书令丞，专掌艺文图书，下设秘书郎和校书郎。

P.S. 若要分等级，因只是部分摘录，其顺序为丞相、御史中丞、
     侍中、尚书令，中书令监、秘书监。

大将军：主掌军事，下设长史，出战时成为将兵长史。

骠骑将军、车骑将军和卫将军：位在大将军之下。

前、后、左、右将军：因一般在战时才设立将军称号，所以将军名
    还是取短的好了。如要深究，此四位皆在四征、四镇、四平将
    军之下。（征东、征西、征南、征北...blah blah）


州郡官制：

刺史：掌管一州的军政大权。下辖别驾、治中、主簿、功曹、督邮
      等。

By considering we need to show info n xxx in one scroll, I 
just take some names for short, hope u all can have a discussion
on it.



---
作者: Fire
题目: about the new limitation in learn
日期: Wed Jun  2 22:07:42 1999
I have checked the code, that is right
in order to learn skills from level 42 to level 43 need literate of 61
and since shampoo just have literate of 58, so can't learn
now becase even player has enough exp, if not enough
literate, can't update, so i make the update
will not consume all the exp, in case many exp have to be wasted
about the color of exp, it is designed for average level of gift, as 21
if player's skill is more than 21 can learn even the exp is not blue
if the gift is less than 21, may can't learn even the color is blue
I may adjust this later

xixi :)


---
作者: Fire
题目: >about history_d
日期: Wed Jun  2 21:54:02 1999
On Wed Jun  2 08:32:47 1999 Flee wrote post #456:
> it works for wizard, but when i use a dummy to test
> he can get all the messages, seem the function query_ilog_time
> not work for players.
> can fire check that.
> BTW, the following event will be recorded
> independence, war victory, war defeated, country distroied

I will check that.
any problem is the order of dispay msg
it seems not sorted, I am not quite sure :)


---
作者: Fire
题目: about login
日期: Tue Jun  1 21:08:38 1999
for the login, i have done the follow adjustment
1 set the max length of chinese name and id to 8
2 set the player can't use id such as "here", "me" and "who"
3 players can't use current real npc char's name as chinese 
  name, such as 张飞 
4 new comers will have full hp , food and drink


---
作者: Flee
题目: to fire
日期: Wed Jun  2 00:50:11 1999
i have created a history daemons and put it at
/daemons/histroy_d.c. which is use to record historic
event and wiz can post some very important message
in order to do this, should modify the /std/body.c
function finish_enter_game(), so players can see what
happend when they wear off line. PLZ check if any bugs.
and about the war, there r two obvious bugs, one is if
the deffence area does not have soldier or generals, the
attck site will auto lose. the other bug is TROOP_D can
not get the correct number of soilders, although, by using
troop_d->query_troops() can see the correct number. inf u
have time. please check that.


---
作者: Stefan
题目: >about login
日期: Wed Jun  2 03:01:55 1999
On Tue Jun  1 21:08:38 1999 Fire wrote post #448:
> for the login, i have done the follow adjustment
> 1 set the max length of chinese name and id to 8
> 2 set the player can't use id such as "here", "me" and "who"
> 3 players can't use current real npc char's name as chinese 
>   name, such as 张飞 
> 4 new comers will have full hp , food and drink

The original code is more flexible in banish ids, you can use
admtool to setup what are the ids to ban, just "here" "me" and "who"
are not sufficent... Please consider it :)


---
作者: Fire
题目: about war
日期: Wed Jun  2 06:32:08 1999
Hi flee,
when i have time, I will begin to check the updated 
war system, 
now i am not quite sure what you have done.
could you please write a help file about the update
now i know that troops can updated, but not
very clear how to do it, and don't have much time
to search, so please write a clear help

about the history_d, I think it's better to set a cmd
to read. if not, when login, especially for newbies
will have too many msg.


---
作者: Fire
题目: about ban names
日期: Wed Jun  2 06:36:23 1999
stefan is right, we have that function in admtool :)
so anyone has any suggestion for what kind of id should
be baned ?
xixi :)


---
作者: Flee
题目: war and history_d
日期: Wed Jun  2 06:38:33 1999
i will write a ducument about recently change of war
about history_d, i still think we should force players
to see. cos lots of players doesn't read post, they
may miss some important change and keepings asking wiz.
and in history_d, the news will be filtered, players can 
only see the msg posted when they r off line.
for newbies, it true that the history log will be quite
long, since we use sb->more() to force players read, 
if they really don't want to, they can just type  
'q' to quit from long log.


---
作者: Fire
题目: about the history_d
日期: Wed Jun  2 07:11:05 1999
I have add two macros for quick use those function
for wiz announce, use WIZ("information")
for history event use HIS("information")
when a player login, those information will be displayed
xixi :)


---
作者: Ice
题目: about login new id
日期: Wed Jun  2 08:00:28 1999
avoid to use same name of objs, otherwise "eat mantou",
"你好像咬不动馒头呀。",
when sb use mantou as his id....:PP
*smirk


---
作者: Flee
题目: about history_d
日期: Wed Jun  2 08:32:47 1999
it works for wizard, but when i use a dummy to test
he can get all the messages, seem the function query_ilog_time
not work for players.
can fire check that.
BTW, the following event will be recorded
independence, war victory, war defeated, country distroied


---
作者: Fire
题目: add color for 三国真实人物
日期: Tue Jun  1 19:56:18 1999
now for real char in sanguo,
if you use CHAR_D->get_char(id,"name") will
return colored name, this will help players to
identify who is the real sanguo char and who is a player
for some function if we just want the name and don't
want any color information. please use
CHAR_D->get_char(id,"r_name")
but for most code, use colored name is fine
:)


---
作者: Fire
题目: char_d 减肥
日期: Mon May 31 21:09:18 1999
chat_d is used to store the bigest mapping in this mud.
some information is useless for some tmp chars
such as loyalty, gift and skills
I have add some code in char_d and events
to remove those useless data
some of the code will be active during further calls
so let's hope the size of char_d can decrease some
:0


---
作者: Fire
题目: a typical bug for array operation
日期: Mon May 31 19:20:36 1999
please see the bug
 *result of array addition is greater than maximum array size.
/sgdomain/job/zuoci/zuo_tool#91370 at line 153

the code is :  main_rooms = main_rooms + ({ tmp_main_rooms });
this is a very common bug for array operation.
because if just use array add, it may have duplicated entries in one array
so a safe way is 先减，再加。
the code should be:
main_room-=({tmp_main_rooms});
main_room+=({tmp_main_rooms});

be careful for this common bugs

:)


---
作者: Fire
题目: about the jail
日期: Sun May 30 20:56:20 1999
hi row,
please write the player's help file for your jail
system :)

we need a full document for the job and new system.
hoho 


---
作者: Fire
题目: about king system
日期: Sun May 30 20:59:48 1999
I have add one call in ev_guy.c
and that call will be called regularly
so we can be sure we have a king in our system all the time
to drive the king system going

addoil group :)


---
作者: Fire
题目: admire flee
日期: Sun May 30 21:37:22 1999
admire flee, 
I have checked your code for zuoci
the idea and the way to realize is so great
admire flee
addoil flee :)


---
作者: Flee
题目: >>关于于吉quest
日期: Sun May 30 21:49:12 1999
the items wanted r less than level 4, it should
not be very expensive. however, i only check for
a few items, not sure about the average prize .. :)


---
作者: Fire
题目: a little suggestion about the xian ren's job
日期: Sun May 30 21:51:39 1999
1 when the job is finished, the tools should be removed
2 when look the tool, should give some hint and desc
rather than 青竹棒(zhu bang)看起来没什么特殊的xixi :)


---
作者: Flee
题目: >a little suggestion about the xian ren's job
日期: Sun May 30 21:55:56 1999
On Sun May 30 21:51:39 1999 Fire wrote post #436:
> 1 when the job is finished, the tools should be removed
> 2 when look the tool, should give some hint and desc
> rather than 青竹棒(zhu bang)看起来没什么特殊的> xixi :)
1) cos some player may quit during job, they may lost
their tool at that time, in such case they can not finish
their job. so i make all tools valueable, players can sell
them after job. others may buy from pawnshop.
2) will add some descption soon .. :)


---
作者: Fire
题目: about lose of obj
日期: Sun May 30 21:59:37 1999
for an obj, if we don't want it is lost during
the quit or disconnect, can just add one sentence in that obj
set_is_keeping(1);
then this obj will be kept after login


---
作者: Fire
题目: about give sth to npc
日期: Sun May 30 22:17:57 1999
in the xian ren's jobs
there is a cmd as give sth to <xianren>
after that process, that obj should be destruct
if not, then what will npc will be overweight
then might cause bugs and increase system burden

xixi :)


---
作者: Fire
题目: about put_prison
日期: Mon May 31 07:04:59 1999
I have modified a little in catch.c and yuzu.c
so now we use one call to send a char to prison
it is in /daemons/char_d/appear.c
the function is:
//:FUNCTION put_prison
// put a char to prison, 
// para p_id the id of the prisoner, it must be given
// p_time how long in jail, default is 5
// p_area in which jail, default is the area of current room of the char
// p_msg the message to put in jail has default value
// so the easiest way to send a char to prison is 
// CHAR_D->put_prison(p_id);

so for further development, please call CHAR_D->put_prison
to send a char to prison.
xixi :)


---
作者: Fire
题目: about xianren xitong
日期: Mon May 31 09:28:01 1999
I add a file /sgdomain/modules/m_charnpc/xianran/xianren_act.c
for xianren to inherit, this module will enable xianren to do
semote, do chat, do say, do moving and move among areas
for xianren in order to have a full feature
please refer /sgdomain/event/huatuo/huatuo.c
I also modifed the /sgdomain/event/ev_xianren.c
so it will be maintain 


---
作者: Group
题目: kingwar ready
日期: Mon May 31 10:09:48 1999
秘召系统，大家help kingwar
有BUG请报告。
any idea any please tell me.
group


---
作者: Fire
题目: about the sg_skilllearn_d.c
日期: Mon May 31 23:39:46 1999
I have updated the sg_skilllearn_d.c
the most important change is that now the skill level
is related to the literate.
and also the consume of experience is realted to the gift


---
作者: Fire
题目: about help
日期: Mon May 31 23:45:54 1999
感谢group在完成了kwar后及时提供了help文档。
最近我们新怎和改动了许多系统，希望负责的WIZ及时提供
和更新相关的help文档。
另外注意就是在加入help 文件后。
还要update /daemons/sghelp_d.c 
最后还要用helpediter加入主题名称和建立相关分类关系。
谢谢：)


---
作者: Stefan
题目: CPU Usage
日期: Fri May 28 16:51:18 1999
Recently there are some complains on the mud speed, I think we should give it
some attention.

First of all, this server is not dedicated to this MUD alone, some 
other people are also using it for their own purposes. 

Secondly, this server is not fast machine, but we get the access for
free. The network connection is generally fast enough.

Regarding CPU load, it was not like this before, I think it is our
program that adds some burden to the servers, too many loaded objects
in the memory, complicated and highly frequent call_out(), etc. etc.
If the memory usage goes up too high, it will tend to use swap space
for virtual memory, which involves heavy disk access and slows down
the overall speed.

I've discussed with fire a year or two ago regarding this matter, 
at that time we do not have any statistics to project our future 
system load, and it was a hard task to manage. But now, seems that
we are running into this problem, it is time for us to re-think about 
it.

Here are my suggestions to reduce system load:
1. avoid disk access as much as you can. For example, if you are going
to save something onto the disk, dont save unnecessary data; when you
dont have to save something, or you can save it later on, use the economic
method if you can.

2. avoid compilcated calculation in one function call. MUD is not
a multi-threaded system, if one of your code takes too much time to
execute, it will appear very lag to other players. For instance, currently
DOC_D is such a program that scans all programs for documentation,
it is executed
once after several hours, and when it is running, after it scans one
file, it uses call_outs for the next one.
In such a way, it gives chances for other program to be executed "on time". 

3. avoid complicated call_out. If you can do something efficently without
call_out, do so. If you can combine several call_outs together, do so. 
If you can delay a call_out to a later time, do so. Currently there are often
40 to 50 call_outs pending when less than 10 people online. And many
of them requires execution in a very short time (1 or 2 seconds). If
we are going to handle 70 people,
I don't know how many call_outs will be there, but it is not a small
number.

4. avoid loading unused objects into the memory. Though there is a clean_up
function to clean up most rooms, I have found it quite strange. We should
not always depend on the clean_up to remove the object from memory for
the time being, until this problem is solved by me :PP (*addoil stefan)
One way is to avoid loading objects, another way is to dicard objects
once they are not needed.

It is time for us to optimise our own code, otherwise, somebody please
find a faster machine with good internet connection? :-)


---
作者: Ice
题目: about "who"
日期: Fri May 28 16:46:02 1999
【粗通文字】太原城隐居贤人乐乐(joy) [发呆 4 小时]                   
           

总人数1个。
─────────────────────────────────────
─────────────────────────────────────


but not in list


---
作者: Stefan
题目: quest
日期: Fri May 28 16:24:45 1999
Ice 提到的一些意见很不错，我还有个想法，就是有关 quest 的帮助应该
放到游戏当中去，player 应当不用查 help 就可以知道下一步做什么。
至于首先 player 怎么知道这些 quest，我想最好融合到游戏里去，
在某些地方给些提示，而不是全部写到 help 文档里。


---
作者: Ice
题目: about new changes
日期: Fri May 28 14:56:27 1999
今天用ccbb经历了一下新手的成长过程，有一些觉得需要改进的地方。

第一，我们的帮助文件更新不够及时，好多时候不得不要新手看post，
但三国榜文现在有超过200，所以比较困难。我想我可以整理一下现在的帮助，但
不知道怎么code。 *blush  anyone has time, show me bah...:)

第二、现在多了好多好好玩的工作，还有皇帝召见(but seems now still has bug..;()
我想我们是不是该做一个help quest，因为以前是没有help quest的，全部要老玩家
告诉才行，除了waterflower..:PPP，问题是，既然是quest，是不是又不该做那么样的he
lp？
让它只当quest？呵呵，但我觉得既然做了就该让人清楚该怎么样才能完成...:)
so waiting for ur comments, if no objection, let me try create the topic
and work on it

第三、当玩家的时候真的没有什么信息，如果没有人在同时做那些quest，连仙人在
什么地方也不知道，还有贤人的购买工作，确实比较难完成，特别是现在的城市多了，
玩家在城市之间没有目标的闲逛是很难找到某些物品，所以需要做一些hints，
是不是可以增加boy的功能，或增加一个类似的包打听，让玩家可以打听到仙人和物品的
的地点，设想是问一次需要50两银子， *grin，然后说出在某州或某国，在那个缩小了
的范围里面让玩家自己找，现在的物品一般都不只在一个城市可以买到，只需要随机找
出一个州或国家就可以了。为什么会要50两银子？因为其实我把现有的除食品和饮料之外
的物品都以比较有逻辑的方式分布，象只有益州一带卖的ajhorse等等，既然不愿意想，
那么就给银子喽。然后，为什么要是国家和州？因为州郡制现在只有了一个框架，离完成
我想还有比较长的一段日子，所以需要用国家来应应急，以后州郡制完成了可以并行。
再然后，如果用boy的话，给50两银子又似乎太多了一点，能不能让boy专门找人，收费低
廉，
包打听可以提供物品信息和仙人的踪迹，仙人嘛，收费一两黄金好了，*smirk。

第四是关于quest zuo ci 的，今天领了一个工作，从狄道一直跑到长安还说是西南的城
市，
是不是能改成如果目标房间在同一个城市内的就用“在西南的方向”，如果不是，就用
“在周围的城市”，以免造成误导，让玩家觉得那个提示没有什么用。

嘻嘻， *handshake


---
作者: Row
题目: about prison
日期: Fri May 28 05:39:27 1999
with the help of flee and ice, i finally finished the
prison and make every area has one. the file is under
/sgdomain/prison/yuzu.c
pls check if has bug.

and...i think prison can be used in many ways, after catch
the player, just set two para of player, and move him
to prison then it will block him from certain time.
CHAR_D->set_char(<id>,"in_prison",<time period>)
CHAR_D->set_char(<id>,"be_caught",<time>)
in_prison indicates the time period that the prisoner 
should stay in the prison, and the be_caught indicates
when the player is being caught.

now every area has a "prison" room.


---
作者: Row
题目: about prison again
日期: Fri May 28 05:40:19 1999
only work for char


---
作者: Ice
题目: Reseted something
日期: Fri May 28 08:45:20 1999
Changed 驿站，官宅和其他一些 INDOOR 和 OUTDOOR room 的设置，
以便让采药的不用到驿站去挖坑。

Reseted most SW cities' population as the following:
Lv 1  2000
Lv 2 5000
Lv 3 10000
Lv 4 50000
Lv 5 100000



---
作者: Ice
题目: SW national tax adjusted
日期: Fri May 28 09:36:49 1999
I adjusted it as 10 of each city


---
作者: Ice
题目: 关于西南城市发展及城市总体发展
日期: Fri May 28 19:40:24 1999
今天看到祁山被马腾攻占，然后当地没钱没粮，有动念头要把西南一些
参数较低的城市改一下，但转念一想，就算改了也未必管用，因为现在的
状况来看，小城市基本上是跳板，并不存在有野心的占大城，没有什么
野心占小城的现象，所以我们是不是该认真考虑一下，将来的城市该如何平衡
因为如果所有玩家只愿意到有保障的大城市工作，将会造成好的城市越好，
烂的越烂，我想这不是我们希望看到的现象。

其实在西南还没有建设好的时候，我就觉得不应该让玩家进驻，那样会造成
许多混乱，如今我们又要着手开放东南和东北，除非我们决定在所有地图
完成之后把整个三国的数据全部重置，否则，还是不要让玩家进驻的好。
是不是把连接东西的城市的neighbour取消就可以了？还有，如今西南的
问题是不是该有个了断，大家讨论一下吧，我还不敢改。.... :PPPP



---
作者: Ice
题目: 关于于吉quest
日期: Sun May 30 06:26:41 1999
一点点小建议，因为牵涉到物品的暗号，所以必须拥有那件物品，
那么如果需要暗号是“皇冠”，玩家需要花一百金购买皇冠来完成，
似乎得不偿失，是不是改成食物和饮料类的可以让他们接受得了，
因为就算如果买下的不是太贵重的，如“眉尖刀”，那如果他们练
的不是刀法也没有用，食物还可以吃会儿。 ....:)


---
作者: Group
题目: sorry
日期: Sun May 30 11:33:28 1999
these days got a little busy in communications...hence sorry...
i will finish the war job as soon as possible in next week.

sorry again for the delay..:P

group


---
作者: Group
题目: about king
日期: Sun May 30 11:37:25 1999
there is a little problem about king.
since the ev_king is called by the object "king",
when the mud is just began, there is no "king" actually, because the
room of the king
is never refreshed since no player can get to the place.
is that possible to make the room to be loaded whenever the mud is reboot?
hence the event can auto begin.

please help..:)

group


---
作者: Fire
题目: >CPU Usage
日期: Sun May 30 20:13:42 1999
I will do the following things to reduce the system burden.
1 add self_hide in the char_d
so that most npc chars when no ppl go around
can hide and discard the related room

2 change the m_age, now we use a call_out for each
player to grow his age, this will be changed as hp system
the age will be update until when you are checking it


---
作者: Fire
题目: >关于西南城市发展及城市总体发展
日期: Sun May 30 20:16:21 1999
On Fri May 28 19:40:24 1999 Ice wrote post #424:
> 今天看到祁山被马腾攻占，然后当地没钱没粮，有动念头要把西南一些
> 参数较低的城市改一下，但转念一想，就算改了也未必管用，因为现在的
> 状况来看，小城市基本上是跳板，并不存在有野心的占大城，没有什么
> 野心占小城的现象，所以我们是不是该认真考虑一下，将来的城市该如何平衡
> 因为如果所有玩家只愿意到有保障的大城市工作，将会造成好的城市越好，
> 烂的越烂，我想这不是我们希望看到的现象。
> 
> 其实在西南还没有建设好的时候，我就觉得不应该让玩家进驻，那样会造成
> 许多混乱，如今我们又要着手开放东南和东北，除非我们决定在所有地图
> 完成之后把整个三国的数据全部重置，否则，还是不要让玩家进驻的好。
> 是不是把连接东西的城市的neighbour取消就可以了？还有，如今西南的
> 问题是不是该有个了断，大家讨论一下吧，我还不敢改。.... :PPPP
> 

MUD is a very complex self-contain system
so we don't need worry too much about the initial value
if the formula for the self-development is reasonable
it will reach a suitable balance status.
now we open the SW for players, then we can observe
our development, see if it reliable. and if has
bug to crush this system. so don't worry too much
about it lah.

xixi


---
作者: Fire
题目: about the xianren's job
日期: Sun May 30 20:20:10 1999
it's amazing for flee to develop so many xianren's job
so, please give the related help files :)
and those xianren's job well be in one certan class of help as special_job

xixi


---
作者: Fire
题目: for the CPU concersion
日期: Sun May 30 20:51:45 1999
I add a function my_clean in m_m_charaction.c to
force the char call environment clean up
in siteration situation, hope this can help to reduce the cpu useage
xixi :)


---
作者: Fire
题目: new functions
日期: Thu May 27 22:11:07 1999
this_body()->query_literate() return literate value
this_body()->query_literate_str() return string desc of literate value

CHAR_D->get_char(id,"level") 返回官职大小 0 to 9


---
作者: Row
题目: to flee & group
日期: Thu May 27 20:57:14 1999
seems we still has bug in war and train, since war
is very important, pls check. thx.


---
作者: Fire
题目: >>> bug or ?
日期: Mon May 24 18:40:22 1999
On Mon May 24 07:10:30 1999 Flee wrote post #398:
> no sure about the reason, but for the bug cnl
> encounter, it is beacuse the city he attacked
> does not have a warroom.c under city dir.
> so the attack troop can not move the warfield
> TROOP_D will remove thire troop and ev_war:check_result
> determine that attack troop are defeated
> 
> i check all the cities and add warroom.c for those
> do not have.

there is a cmd in /wiz/fire/cmds/ can auto all the warroom
sorry don't mention that before



---
作者: Ice
题目: 三国州郡列表
日期: Tue May 25 19:36:28 1999
本三国将共计有十七州九十九郡。

幽州：（共六郡）
代县，蓟城，易京，北平，白狼山，襄平。

冀州：（共四郡）
南皮，平原，清河，界桥。

青州：（共三郡）
济南，渤海，北海。

兖州：（共五郡）
邺，陈留，定陶，濮阳，白马。

豫州：（共四郡）
许昌，谯，汝南，官渡。

徐州：（共五郡）
徐州，小沛，下邳，广陵，琅邪。

并州：（共四郡）
太原，上党，雁门关，晋阳。

司隶：（共七郡）
洛阳，虎牢关，壶关，渑池，弘农，宛，博望坡。

雍州：（共八郡）
长安，五丈原，武关，函谷关，潼关，华阴，泾阳，咸阳。

凉州：（共八郡）
西凉，陇西，天水，狄道，街亭，安定，秦川，陈仓。

梁州：（共八郡）
汉中，祁山，下弁，阳平关，定军山，剑阁，梓潼，涪城。

益州：（共六郡）
成都，绵竹关，江州，永安，建宁，云南。

北荆州：（共七郡）
襄阳，上庸，新野，澶溪，长坂坡，江夏，赤壁。

南荆州：（共八郡）
江陵，夷陵，公安，华容，武陵，零陵，长沙，桂阳。

郢州：（共六郡）
庐江，西塞山，丹阳，鄱阳，柴桑，豫章。

扬州：（共七郡）
建业，寿春，合淝，淮阴，濡须口，吴郡，会稽。

交州：（共三郡）
南海，桂林，庐陵。


因为各州大小不一，所以我想以后设计州牧刺史的时候他们的权力也应该不同。
*smirk


---
作者: Fire
题目: about ice's suggestion
日期: Tue May 25 20:55:54 1999
ice's suggestions are very nice.
we will try to introduce some in our system later
addoil :)


---
作者: Group
题目: 汉献帝系统：
日期: Wed May 26 07:29:06 1999
help king.
please give comments.

group


---
作者: Fire
题目: about the ev_king
日期: Wed May 26 23:21:20 1999
group's king is very nice, 
it's amazing that he can finish that
in such a short time.
I have checked the code, it is very nice.
just a little problem.
if there is a player connected but not login then
will have ask 0 to come etc, I have modified a little in the auto_run
and make comment, hope can solve this problem. another problem is
that if a player is on a meeting or on war.
he perhaps can't come within 10 mintues
so need to check if that player is on task
this can be done by check !(EV_CHAR_D)->get_char(id,"task")
perhaps need check that.
anyway, good job group
addoil
another problem is for the install of help
now i use help new and find emperor don't have a chinese title
so need use helpediter to edit for suitable title and links
xixi :)


---
作者: Ice
题目: ideas about new jobs
日期: Thu May 27 01:20:07 1999
中级工作纵火：

ask taishou about job,answer arson to taishou
太守对你说道，麻烦你到成都放一把火。

接受任务后到华阴买火把，到厨房点燃，在火把熄灭以前
到达成都完成纵火。

能纵火的房间只有一个，可以随机从目标城市的房间抽取
一个，纵火需要cmd arson here，象cmd spy here一样，
需要一至两秒busy time，找不对可以纵火的房间就显示：
纵火失败。找对了就显示纵火成功，如纵火成功，目标城市
安定下降2，物资、金、粮食损失1－5%。

成功奖励可以取决于目标城市的房间数目，可参照spy的奖励。

低级工作救火：

ask taishou about job,answer fireman to taishou
太守对你说道：好！好！本城正需要找人救火，那么你看看是
哪里着火了，赶快去扑灭把。

如果没有被纵火，太守回答：本地区现在没有火灾。或者随机
当场放一把火，嘿嘿。

救火程序如现在的长安衙门救火程序，将长安衙门的官员改成
发放水龙的，并需要在每个城市设置一个明显可见的可以装水
的地方。

奖励可以相对固定一些，参照findbody，加上基本火计的奖励，
如现有的救火job，原救火job cancel，officer 只用以提高基
本火计和提供水龙。



---
作者: Ice
题目: btw, arson can be caught
日期: Thu May 27 01:22:30 1999
arson job can be caught, and I think the current cmd catch xxx has some bugs
ppl in patrol sometimes cannot catch thief or player spying and whispering


---
作者: Fire
题目: about the job of arson
日期: Thu May 27 01:24:57 1999
a very nice job,
who want do it ?
addoil :)


---
作者: Ice
题目: about cmd resign a job
日期: Thu May 27 01:42:17 1999
for example, if sb get a job from xu zijiang, to search buyi,
then player feel hard to do it, then they cmd resign that job
until the xian ren ask him to search a mantou, then it's not reasonable

but if it's only for mid-lv job, that's fine, otherwise may do some adjustment
to xu zijiang's job

if the ppl choose to resign a job, or he missed the xian ren, make
it available
again for player 20-30 mins later

btw, just now a player complain that he gave up the xian ren job,
but wait 1 hour
still cannot do the same quest again, so flee pls consider to change
it bah...:)


---
作者: Ice
题目: about the current merchant settings
日期: Thu May 27 01:47:37 1999
because we have many new stuffs on sale now, sometimes it's hard to buy sth
like food and stuffs, which are important to keep a city

so I suggest to devide the merchant selling to 2 categories
each merchant may bring 1-2 kinds of basic goods like food, stuffs, horse,
bow, or some basic upgrade stuffs that is not so expensive
the advanced category has also 1-2 kinds of higher lv of upgrade stuffs


---
作者: Fire
题目: about the obj
日期: Thu May 27 02:30:56 1999
we need a npc can give players the hint where to find
certain obj, 
this is not a free service :)
hoho


---
作者: Group
题目: re fire
日期: Thu May 27 06:10:17 1999
xixi, first should thank flee for his help.
i add 1 more function in to check whether the body 
got is wiz or not. later emperor will not call wiz at all
and i change the delay time to 30 minutes according to the 
players in war and  train.

and i want to add a function to make the rumor call the player 
every 2 minutes.

xixi
group


---
作者: Flee
题目: about xu zijiang
日期: Thu May 27 06:25:08 1999
i make xu a character now, who has property is_tmp = 1
and is_xianren = 1. and code a event ev_xianren, which
will random place this xianrens. in order to do that,
i modifed ai_d.c


---
作者: Stefan
题目: For those who want to know LPC
日期: Thu May 27 14:13:43 1999
There is a recently development of LPC, or similar to LPC, a
programming language
called PIKE. If you are interested, you can take a look at
http://pike.idonex.se/



---
作者: Group
题目: 商人加了
日期: Mon May 24 07:41:42 1999
现在所有升级用的物品已经加入到了商人的买卖单中。
请大家提意见

group..:)


---
作者: Flee
题目: >> bug or ?
日期: Mon May 24 07:10:30 1999
no sure about the reason, but for the bug cnl
encounter, it is beacuse the city he attacked
does not have a warroom.c under city dir.
so the attack troop can not move the warfield
TROOP_D will remove thire troop and ev_war:check_result
determine that attack troop are defeated

i check all the cities and add warroom.c for those
do not have.


---
作者: Flee
题目: >> about commando
日期: Mon May 24 07:06:18 1999
now I change it back to original formulor,
the nuumber of commando is the minumum of 
safe*100 and population/10

xixi .. :)


---
作者: Ice
题目: 关于帮助文件及其他
日期: Sun May 23 22:14:19 1999
我将做三个锦囊帮助文件，目的是这样的：
分为三个文件，分别是 help jinnang1, help jinnang2, help jinnang 3
有刚开始在本mud活动，当官，当官后三个部分，
主要是象新手post那样作指南作用。
我希望能让新手刚进入草庐时，shuijing就用醒目的字句显示以下的话：
请先阅读help newbie 和 help starts，
如果还是觉得有困难，我这里有三个锦囊，你们在必要的时候才好打开来看呀。
%^H_YELLOW%^锦囊一%^RESET%^ (help jinnang1) 初入三国，如何是好
%^H_MAGENTA%^锦囊二%^RESET%^ (help jinnang2) 当官必读
%^H_BLUE%^锦囊三%^RESET%^ (help jinnang3) 宦海沉浮

如果可能，我会尽量保持更新这些文件，但需要sb help me to put it in
sanguo domain

另外，我觉得如果有了锦囊，草庐新手帮助版是不是可以改为系统信息发布，
将一些最新的更动在那里通知，就不会和三国post混淆不清，而且现在的新手帮助版
似乎没有起到应有的作用，每次都要我 trans player there to see

再另外，landlord 的 帮助文件是不是需要更新一下，我想新手没有一个看得懂，
全都要我告诉他们 d 1 1, d 2 2, d 3 3, q



---
作者: Fire
题目: about the shortage of food, gold and stuff
日期: Sun May 23 20:36:46 1999
for an area, if the food, gold and stuff are not enough to
support the troop, i think the soldiers should leave rather
than just reduce the morale and train.

what you guys think about this

xixi :)


---
作者: Fire
题目: >关于食物和饮料
日期: Sun May 23 20:04:58 1999
On Sun May 23 10:48:20 1999 Ice wrote post #392:
> lv 0 for those food and drinks for fun
> lv 1 is the most common food for ppl, like mantou, blah blah
> lv 2 is for mid lv income ppl to eat and drink, if they want
> lv 3 food are the most expensive, for ppl who really want to eat them....:P
> 
> I don't mean to add some new categories, just seperate them by prices
> and I will try to add some new food and drinks according to the coming
> 献帝宫 new quest
> 
> *smirk

good point
addoil :0


---
作者: Ice
题目: P.S.
日期: Sun May 23 11:39:37 1999
I respect the payout of who made those objs, 
I modify them just to make them in sequence,
(mostly to guanfeng, i guess...:P)
anyway, sorry to bring any inconvenience.


---
作者: Ice
题目: 关于食物和饮料
日期: Sun May 23 10:48:20 1999
lv 0 for those food and drinks for fun
lv 1 is the most common food for ppl, like mantou, blah blah
lv 2 is for mid lv income ppl to eat and drink, if they want
lv 3 food are the most expensive, for ppl who really want to eat them....:P

I don't mean to add some new categories, just seperate them by prices
and I will try to add some new food and drinks according to the coming
献帝宫 new quest

*smirk


---
作者: Fire
题目: bug or ?
日期: Sun May 23 09:51:51 1999
你道：诸位将军、大人，请速到军营点兵出征。
你来到了军营。
准备出征，请输入同行的将军。
有效值有：「cctv,mimi,guanfeng」
缺省值是：「cctv」
mimi,guanfeng
请输入步兵人数。
有效范围：「0--6154」
缺省值是：「879」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
组成新军团。请输入该军团将军。
有效值有：「cctv,mimi,guanfeng」
缺省值是：「cctv」
【闲聊】玫瑰：混蛋，真混
请输入步兵人数。
有效范围：「0--6154」
缺省值是：「1025」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：明珠何在？
明珠答道：卑职在！
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
组成新军团。请输入该军团将军。
有效值有：「mimi,guanfeng」
缺省值是：「mimi」
你对明珠说到：速点一千零二十五兵马待命出发。
明珠答道：得令。
请输入步兵人数。
有效范围：「0--5129」
缺省值是：「1025」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：虎口何在？
虎口答道：末将在！
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
你对虎口说到：速点一千零二十五兵马待命出发。
虎口答道：得令。
组成新军团。请输入该军团将军。
有效值有：「guanfeng」
缺省值是：「guanfeng」
请输入步兵人数。
有效范围：「0--4104」
缺省值是：「1026」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：雅典娜何在？
雅典娜答道：卑职在！
你喝道：全体将士定要奋勇杀敌，寡人自有重赏！
你领将士进入战场。
【谣言】某人：烈火领三千零七十六兵士向成都杀来！！！
> 
> 你对雅典娜说到：速点一千零二十六兵马待命出发。
雅典娜答道：得令。
【谣言】某人：法正率军奋勇征战，把烈火打得丢盔弃甲，狼狈逃窜。成都军
民欢喜庆功！
【闲聊】法正：烈火匹夫，暂且放你一条狗命，若还有下次，定叫你有来无回！
【闲聊】烈火：法正臭贼，休要如此猖狂，我定会卷土重来！哼！

I just finish the arrange troop and didn't war
yet, then it announce i am defeated 
so is that a bug, or i make any mistake in the arrange 


---
作者: Fire
题目: bug or ?
日期: Sun May 23 09:50:02 1999
你道：诸位将军、大人，请速到军营点兵出征。
你来到了军营。
准备出征，请输入同行的将军。
有效值有：「cctv,mimi,guanfeng」
缺省值是：「cctv」
mimi,guanfeng
请输入步兵人数。
有效范围：「0--6154」
缺省值是：「879」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
组成新军团。请输入该军团将军。
有效值有：「cctv,mimi,guanfeng」
缺省值是：「cctv」
【闲聊】玫瑰：混蛋，真混
请输入步兵人数。
有效范围：「0--6154」
缺省值是：「1025」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：明珠何在？
明珠答道：卑职在！
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
组成新军团。请输入该军团将军。
有效值有：「mimi,guanfeng」
缺省值是：「mimi」
你对明珠说到：速点一千零二十五兵马待命出发。
明珠答道：得令。
请输入步兵人数。
有效范围：「0--5129」
缺省值是：「1025」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：虎口何在？
虎口答道：末将在！
是否成立新兵团？
有效值有：「Yes|No」
缺省值是：「Yes」
你对虎口说到：速点一千零二十五兵马待命出发。
虎口答道：得令。
组成新军团。请输入该军团将军。
有效值有：「guanfeng」
缺省值是：「guanfeng」
请输入步兵人数。
有效范围：「0--4104」
缺省值是：「1026」
请输入部队驻守位置。
有效值有：「城东：e 城西：w 城北：n 城南：s 」
缺省值是：「e」
你喝道：雅典娜何在？
雅典娜答道：卑职在！
你喝道：全体将士定要奋勇杀敌，寡人自有重赏！
你领将士进入战场。
【谣言】某人：烈火领三千零七十六兵士向成都杀来！！！
> 
> 你对雅典娜说到：速点一千零二十六兵马待命出发。
雅典娜答道：得令。
【谣言】某人：法正率军奋勇征战，把烈火打得丢盔弃甲，狼狈逃窜。成都军
民欢喜庆功！
【闲聊】法正：烈火匹夫，暂且放你一条狗命，若还有下次，定叫你有来无回！
【闲聊】烈火：法正臭贼，休要如此猖狂，我定会卷土重来！哼！


---
作者: Fire
题目: about commando
日期: Sun May 23 08:38:26 1999
In flee's post:
2) Add commando to defence troop. the defence army
will get commando. the number of it is 10% of city's
population

In the old war system, the number of commando still
related to the safe level of that city and also has
a upper limit. I think that is more reasonable
xixi :)
and when the new war system is ready
please make a detailed help file in chinese
and please headline the difference from the previous
version. thanks



---
作者: Ice
题目: 关于献帝宫quest及其他
日期: Sat May 22 20:09:45 1999
我觉得献帝宫的quest会比较有趣，我有一些想法，;问题是不知道能不能code。。。

首先，要做这个quest的玩家必须有2级以上的地方
官职（即书爷或武将）才能到献帝宫申请晋见。同时
可以在献帝宫门口设置些障碍，如卫兵或近臣，可以
设置成要先打通关节才能晋见，如果任务失败，那么
那些钱算白花了。*grin

第二，做这个quest的赏赐丰厚，譬如每次成功之后赏赐十两黄金到五十两黄
金不等，由所需要购买的
东西和完成的效率决定。（因为各个地区连上来的速
度不一样，所以我觉得时间和效率比较难控制），另
外还有声望（譬如1000）和修养的增加（如一次500），
以高回报来吸引玩家在献帝宫门口通宵排队。*smirk

第三，做这个quest可以向一些异人求教在哪里可以买
到献帝那小子想要的东西，我觉得他们光说在XX城市附
近没有那么好玩，把我的想法举个例子，如果玩家找到
紫虚上人，给了他一两黄金之后得到如下回答：大闸蟹
么，听说在荆州一带可以买到。然后玩家就要到荆州的
几个城市里面去list，进而找到需要买的物品，然后回
去交差。不知道这样会不会让人更觉得是在三国时代的
场景。

在我的巫师申请里面讲到要协助完善郡县制度，也是和
上面的第三点对应的，三国时代的州郡就如现在的省，
都有自己的地方首领，可以拥有一定的自主权。为什么
我会觉得需要这个制度呢？因为在当李煜的时候，刚开
始还可以精忠团结，到后来因为国土的扩大不完善的官
职制度造成人心离散，这和三国志的游戏目的不符。要
想在这个游戏成功，除了需要有能力，有眼光之外，还
要有一批合作的手下，要让他们团结在自己周围就要赋
予他们一定的权力，如可以选拔地方太守等。

如果觉得可以引进这种郡县制度，我可以做资料搜集，
将游戏内现存（或将会存在）的城市以三国时代的划分
分成州，然后再做coding。我对游戏语言真的一无所知，
所以不知道这样会不会带来很大困难。

剩下的构思都是在这个制度的基础上的，譬如使用命令
info p list 可以查看各州的名称，又如只有当一个国
家占领了一个州的所有城市，该国国王才能任命XX州牧
或XX州刺史等。


噢，还有还有，如果做献帝宫quest就要多多搜集资料
做一大堆obj让他们去找，在做maker的时候才觉得适用
的obj好少，总是重复来重复去，如果我可以做obj的话，
嘿嘿。。。。但是今天做了个”巧克力“。。。就是吃

好了，大家看完记得快给response呀，六月考试又快到
了，*fear, *escape




---
作者: Fire
题目: about set_msgs
日期: Fri May 21 19:51:14 1999
@.me->set_msgs("clone","$N对空长呼：神啊，赐予我$o吧。\n$O从天而降。\n")
this is set the msg for clone.
for more msg, please use review

and $O is used for the name of obj, it is a little different from
$o


---
作者: Fire
题目: about $O
日期: Fri May 21 20:19:50 1999
$O means:
"一"+unit+name


---
作者: Fire
题目: about the cpu
日期: Fri May 21 22:38:37 1999
because now we have more and more npc char.
the old way to make them auto_action is use
call_out in each npc obj. 
but this will make system more than 300 call_out
it used a lot cpu and memory resouce.
some time the cpu usage is up to 10%
now I changed this machine from a daemon called
charheart_d.c under /daemons/
now the npc useage is below 2%
hoho :)


---
作者: Fire
题目: 恭喜 flee and group
日期: Sat May 22 09:31:56 1999
you guy do very quick work.
very good. 
now i change a little in area_d
so the AREA_D->get_area(<a_id>,"soldier") will
return the summary of number of all troops
so the info and list will return the real number of solderis

addoil :)


---
作者: Fire
题目: some suggestion about the war and troops
日期: Tue May 18 20:16:20 1999
It is obviously that the war system is the most complex 
system in this mudlib. so it is very common to get confused and
cause bugs when
try to install some new features.
I am sorry that I can't give more help recently because I am
too busy, and update this system need more concertrated.
Here I have some suggestion, hope they can help flee and group
to update the war and troop system.

1. about the soldier number.
   the soldier number for a certain area is stored in the area_d.
and there are many programs call them. but most are inqure and just
a few are set. for the inquire. they use function as:
AREA_D->get_area(a_id,"soldier");
and in area_d, this function can be overrided by a specific function.
so you need modify the area_d. in the get_area function. when the
parameter is soldier. then call another function such as
get_area_soldier(a_id).
and in this function return the summary of troop numbers.
so many program need to check the soldier numbers don't need to be
modified. and we will remove the parameter of soldier in the area_d
databased.

2 for the set soldier number function, it is much more difficult.
I still don't know what your guys idea. 
so you need write very clear and seperate functions to handle this process
and also about the troop changes. so I suggested you
write a seperate file under /daemons/area_d/ and this file will be
inherited by area_d.c
3 about the troop type.
  I have checked groups files under /wiz/group/troops
I think use seperate file to define seperate troop type is not a good idea
because if we want to add a common parameter for all the troops,
then we need update all the files and we may miss some files
and some files may have bugs but because that type of soldier not appear
frequently, so we didn't notice that.
and so on. 
so I strongly suggest to use a daemon to handle all the different
types of troop. we have many samples for this skill.

4 anyway, it is nice to try to modify the most complex part of the mudlib
but be careful and discuss more if make big decision.

addoil :)


---
作者: Fire
题目: >localmeeting
日期: Tue May 18 20:01:24 1999
On Tue May 18 11:50:46 1999 Row wrote post #375:
> some player said he was called to attend meeting while
> he was doing a job(spy), sure he cannot get back and lost
> sth....is player supposed to be set to no need to attend
> meeting while doing job? pls check.

This is a little difficult. because the system hard to know if
the player is doing jobs or not.
but for our meeting system, it does have some problems.
so in the future, we probably need a parameter means
can't attend meeting.
but that need further consideration


---
作者: Row
题目: localmeeting
日期: Tue May 18 11:50:46 1999
some player said he was called to attend meeting while
he was doing a job(spy), sure he cannot get back and lost
sth....is player supposed to be set to no need to attend
meeting while doing job? pls check.


---
作者: Fire
题目: about the war bug
日期: Tue May 18 08:40:32 1999
because of the war bug,
I disabled the bandit attack temporaly
when the bug fixed, then re open
addoil all


---
作者: Row
题目: serious problem
日期: Tue May 18 01:01:15 1999
now the bug of war is becoming more serious, after several
bandits attacking, the soldier of an area was exceeding to
100000+
and used up the food and good of that area, whoever fire
or flee is online, pls look into it ASAP, thx


---
作者: Flee
题目: current work
日期: Mon May 17 03:21:10 1999
i use a mapping to store various typs of troops
and at the same time, the number of solider is 
still stored as integer. that is why the No of 
solider increase after bandit attack.
in order to solve this, there r many files got to
be modified.
about the strage file under /sgdoamin/event/war,
that is a reult of greping in that directory.
i have tried to remove it, but failed .. :(
i will try to fix that bug as soon as possible
and report any change in time .. :)

addoil all 


---
作者: Fire
题目: a new wiz tools
日期: Mon May 17 00:54:41 1999
a new wizard tool buzzer is created under
/cmds/wiz/ this is used to quick create rooms for sanguo area
test in new areas and see how it works, hoho
:)


---
作者: Fire
题目: what is it?
日期: Sun May 16 20:20:39 1999
when I use ls command under the path of /sgdomain/event/war/
then there is a file called "set_task("task_id". . . . .".
what is it ?
who create it ?


---
作者: Fire
题目: flee, please check your code
日期: Sun May 16 20:36:44 1999
Hi, flee

Please check your code for the war arrangement.
during the war arrangement, if we have 1000 soldiers
and we arrange 500 for the war, then this area will just have
500 soldiers left. then after the war, if we have 200 soldier
survived after the war, then our area should have 700 soldiers 
totaly. but now, your code doesn't submit the soldiers after the
arrangement. so this area will have 1200 soldiers after the war, 
This is a BIG BUG.
please fix it as soon as possible.
recently, my computer is broken, and I am terribley busy,
so I am sorry that i can't help you to fix this bug.
In fact, I dont' that it is a good idea to modify war system
now, bucause it is too complex now, and to write a new one will be
easier than modify old codes
I am sure that our war system need more features, but to add them
need a fully understand of the
old code's struture. but if you really like to imporve war system,
that is also fine.
just be careful and fully test the new stuffs. and be aware of that
some modification may cause other systems working incorrectly.

addoil :)


---
作者: Row
题目: 守卫
日期: Wed May 19 23:01:15 1999
建议在每个地区入口处加一个守卫，一是便于加强
管理，二是增加工作的难度，这样玩家就不能在地

主要功能如下：
当玩家起马或乘马车到达某地后，键入进地区的方
向时，检查其是否为当地官员或隐居人士，若是，
则安全通过；若否，则被告知ask guard about enter

ask guard about enter 以后，检查玩家与当地的
国家关系，若高于40(可以另定)则安全通过，若低
于40，则出现选单，玩家可选择贿赂守卫，金额从
10两至50两黄金不等，结合其治国修养，随机取值
判断；威吓守卫，结合武学修养、官位高低及其装
备等级，随机取值判断；劝诱守卫，结合兵法修养、
官位高低随即取值判断。若成功则放行，若不成功
则停留原地(或投入监狱，需要设计一个监狱)。

为保证自由通商，凡是取得购买任务的玩家将会从
太守处得到一块令牌，到目的地时，若有需要便可
以向守卫出示，便可自由进入(令牌出示后便消失)。

另外还可增加一些相关的指令，如一国主公可以设
定不欢迎名单，一次三名，期限为五天，七天后才
允许重新设定。如此在不欢迎名单之列的玩家就不
能进入该国。


---
作者: Group
题目: war system
日期: Thu May 20 00:44:49 1999
we will try our best to finish the thing in a week, but cant garentee....
if we cant finish it in a week, is that possible to open a test site
in another
port of same machine for testing?

hope can be done.
group


---
作者: Fire
题目: about the char_d
日期: Thu May 20 22:32:38 1999
I have modified char_d.c and char_obj.c
hope can fixed the bug in the char system.
please keep an eye on it, if still have the similar bugs


---
作者: Ice
题目: 私は 玄冰てす。
日期: Fri May 21 08:47:25 1999
终于，看完了所有所有的POST，开始对这个游戏有了更深的了解，
也发现有好多在当PLAYER时不知道的IDEA，*grin
我之所以申请当巫师，是想把这个游戏更加完善和贴近史实，
问题是我。。。是历史上最papaya的wiz，因为看了语言就头大，
所以我想我的最大作用是做一些 dirty jobs and some suggestion,
刚看完所有post，还没有消化，所以还没有能整理出什么看法...:P
anyway, I am new here..:)
And my current task is to make maker in all SW cities
That's it.

请多多关照。


---
作者: Row
题目: 界面
日期: Fri May 21 12:42:57 1999
游戏的界面是很重要的，所以可能有必要重新设计一下我们的现在的
界面，以下是我个人的意见，希望大家也把各自的意见贴出来讨论。


%^H_YELLOW%^『磨房』%^H_CYAN%^◎出口：east◎%^RESET%^

    这是一间相当陈旧的磨坊，磨坊中间有一只沉重的石磨，看样子
拉磨的驴再也找不回来了，只有靠自己来推磨了，你不由想起了那句
有钱能使。。。的俗话。从磨坊的门看出去能看到一棵高大的槐树。

%^H_GREEN%^【天色】%^H_RED%^太阳正高挂在天空上。%^RESET%^


---
作者: Tset
题目: >界面
日期: Fri May 21 12:50:09 1999
On Fri May 21 12:42:57 1999 Row wrote post #382:
> 游戏的界面是很重要的，所以可能有必要重新设计一下我们的现在的
> 界面，以下是我个人的意见，希望大家也把各自的意见贴出来讨论。
> 
> 
> %^H_YELLOW%^『磨房』%^H_CYAN%^◎出口：east◎%^RESET%^
> 
>     这是一间相当陈旧的磨坊，磨坊中间有一只沉重的石磨，看样子
> 拉磨的驴再也找不回来了，只有靠自己来推磨了，你不由想起了那句
> 有钱能使。。。的俗话。从磨坊的门看出去能看到一棵高大的槐树。
> 
> %^H_GREEN%^【天色】%^H_RED%^太阳正高挂在天空上。%^RESET%^
the room exit color is user definable, if u really
want to overwrite it, at the end of set_brief add the colour code.
Also, there is always some of us that don't support full
chinese characters...thos special ones are 乱码, maybe
use some more general ones?

row's 设计 is pretty good actually :)


---
作者: Fire
题目: >连线bug
日期: Tue Jun 15 20:14:45 1999
On Tue Jun 15 10:00:40 1999 Zhanpu wrote post #503:
> 你已经在线上了!;你确定要替换吗？n
> ──巫师列表──  总人数3个。;──────────────────────
──
> ─────────────;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(
zhan
> pu)                 ;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(zhanpu
)   
>              ;【小有文采】烈火国建宁镇太守玄冰，字千年(ice)             
   
>    ;───────────────────────────────────
──
> 
> 这样就可能出现几个相同的id
> 我试了几次，都有这种现象,不是偶然的
> 怎样消除这种bug

Wiz 可以同时登录多次。
这是本MUD的一个特点。玩家是不行的。
不过对于我们的char系统，登录两次会引起BUG
所以不建议登录两次或以上。:)


---
作者: Stefan
题目: >连线bug
日期: Tue Jun 15 16:14:51 1999
On Tue Jun 15 10:00:40 1999 Zhanpu wrote post #503:
> 你已经在线上了!;你确定要替换吗？n
> ──巫师列表──  总人数3个。;──────────────────────
──
> ─────────────;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(
zhan
> pu)                 ;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(zhanpu
)   
>              ;【小有文采】烈火国建宁镇太守玄冰，字千年(ice)             
   
>    ;───────────────────────────────────
──
> 
> 这样就可能出现几个相同的id
> 我试了几次，都有这种现象,不是偶然的
> 怎样消除这种bug

这个不是 bug，为了方便起见，巫师是可以同时 login 多个人的，玩家就不行了。


---
作者: Zhanpu
题目: 连线bug
日期: Tue Jun 15 10:00:40 1999
你已经在线上了!;你确定要替换吗？n
──巫师列表──  总人数3个。;────────────────────────
─────────────;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(zhan
pu)                 ;【小有文采】末日帝国华阴书爷「我玩我玩」白梨云(zhanpu)   
             ;【小有文采】烈火国建宁镇太守玄冰，字千年(ice)                 
   ;─────────────────────────────────────

这样就可能出现几个相同的id
我试了几次，都有这种现象,不是偶然的
怎样消除这种bug


---
作者: Group
题目: applyleave
日期: Tue Jun 15 23:21:43 1999
need go back to China for holiday, hence have to leave for 
almost 1 month. i will try to access here when i at home.

addoil all..:)


---
作者: Fire
题目: 如何增加新地区：
日期: Wed Jun 16 01:32:04 1999
1 add area
@AREA_D->add_area(<a_id>)
2 set level
@AREA_D->set_area(<a_id>,"level",<level>)
3 set name
@AREA_D->set_area(<a_id>,"name",<name>)
4 set path and so on
/cmds/area/initarea
5 create warroom
/cmds/area/createwarroom
其中4,5两项可在许多地区加入后，一次执行。
6 用buzzer建造房间
7 设置meeting,fly,go,market,prison等。


---
作者: Fire
题目: about 闲职
日期: Wed Jun 16 01:11:51 1999
地方官职的一个解决办法。
随着开法，越来越多的功能需要官员变换地区。
但是对于地方官职，由于受到官职空缺和认官
资格德限制，实现一些功能很麻烦，而且容易
有BUG。现在引入闲职这一概念，可以大大地简
化编程难度。
闲职的ID是 R_SG, 数值为 1000
具体用法：
CHAR_D->set_char(<id>,"ranklocal",R_SG);


---
作者: Fire
题目: >applyleave
日期: Wed Jun 16 00:18:48 1999
On Tue Jun 15 23:21:43 1999 Group wrote post #506:
> need go back to China for holiday, hence have to leave for 
> almost 1 month. i will try to access here when i at home.
> 
> addoil all..:)

hi group,

have a good time :)

we are waiting for you, addoil :)


---
作者: Row
题目: sample hp
日期: Sat Jun 19 02:14:44 1999
〓〓〓〓状〓〓〓〓态〓〓〓〓

⊙气血⊙   340 / 340 ( 340 )
⊙精神⊙   484 / 484 ( 484 )
⊙食物⊙     0 / 200
⊙饮水⊙     0 / 200

〓〓〓〓〓〓〓〓〓〓三国志〓


---
作者: Fire
题目: about char
日期: Sat Jun 19 07:20:51 1999
because we have about 100 area
so we have about 100 boy, 100 guard and 300 guy
ids in char_d. that is about 500 records
which will cause the char_d operation much slower
so i change them, so there will be no record for
boy, guard and guys. and i have also adjust most
related job file and body files this may cause
some bug. please keep one eye on it
:)


---
作者: Row
题目: save memory and finish job
日期: Sat Jun 19 01:36:51 1999
fire, u compress the npc's action, but seems player cannot finish job
leh, coz everytime they wanna find a npc, the boy will tell him
there r a lot of xxxx becoz of the npc is sleeping, pls check it.


---
作者: Row
题目: sample score
日期: Sat Jun 19 01:20:31 1999
◎＝＝＝＝＝＝＝＝〖个  人  档  案〗＝＝＝＝＝＝＝＝◎
‖                                                  ‖
‖【年    龄】：二十三       【性    别】：男       ‖
‖【武    力】：18           【智    谋】：29       ‖
‖【魅    力】：50           【容    貌】：50       ‖
‖【单挑武功】：37<+9>       【杀 伤 力】：13<+50>  ‖
‖【抵 抗 力】：28<+43>                             ‖
‖【结义兄弟】：无           【结发妻子】：无       ‖
‖【所 属 国】：烈火国       【定 居 地】：建宁     ‖
‖【朝廷官职】：副军师       【地方官职】：建宁闲职 ‖
‖【俸    禄】：5            【忠    诚】：100      ‖
‖【声    望】：逐鹿中原(18911)                     ‖
‖【文学修养】：粗通文字(11)                        ‖
‖                                                  ‖
◎＝＝＝＝＝＝＝＝＝《三  国  志》＝＝＝＝＝＝＝＝＝◎

i've tried to add color in it, but the display always messed
up, anyway, is this pattern good? if so, i will try to adjust
the score lah. hehe..


---
作者: Fire
题目: a useful function
日期: Fri Jun 18 21:32:02 1999
我们MUD的CPU开销比其他MUD的CPU开销大得多
一个有用的函数是：time_expression
你一拱手道：时辰不早，诸位有事明日再谈。
你起身快步离开了。
这个函数用于测量另一个函数的执行时间。例如：
@time_expression(CHAR_D->find_char("zhang fei"))
可以测量CHAR_D->find_char("zhang fei") 的执行时间。
优化前的执行时间约：5xxx micro second
优化后的执行时间约：4xx micro second
快多了。:)


---
作者: Stefan
题目: Graphics MUD 
日期: Fri Jun 18 14:45:37 1999
http://www.pchome.com.tw/news/880421/19990421-6.html

This is an old news, but it mentioned graphics  San Guo from KOEI.
Recently GKK (Graphics King of Kings) will be publicly released in Taiwan,
and they will charge users for playing it.


---
作者: Fire
题目: compare our mud with xyj
日期: Thu Jun 17 07:14:44 1999
xyj has about 60 players online and
with the status is :
共有 71 位玩家连线中，系统负担：19.55 cmds/s, 1.67 comp lines/s

our mud with about 10 ppl on line
the status is:
0.75 cmds/s, 80.77 comp lines/s

our comp lines/s is much bigger than XYJ's



---
作者: Fire
题目: the stuffs in area_d
日期: Thu Jun 17 06:33:36 1999
because there are many types of stuff in area_d
so i change it to a map "st" in area_d
can use AREA_D->get_area(<id>,"st") get the whole thing in one area
the old function AREA_D->get_area(<id>,<stuff id>)
and AREA_D->set_area(<id>,<stuff id>,<num>) still working


---
作者: Stefan
题目: about crash
日期: Wed Jun 16 15:55:58 1999
Our driver log shows a lot of pending messages for net_dead users,
I have changed user object so that messages sending to net_dead user
will not be sent out. 

This obviously is not the direct cause for crashes, if you witnesses
a crash, please describe what you saw :)


---
作者: Stefan
题目: >error caught in log
日期: Wed Jun 16 15:52:37 1999
On Wed Jun 16 15:48:11 1999 Stefan wrote post #512:
> object /sgdomain/area/guan/huayin/vkitchen: eval_cost too big 1000000
> object /secure/simul_efun: eval_cost too big 1000000
> object /sgdomain/obj/foodanddrink/shuihu#32453: eval_cost too big 1000000
> 
> This means there is infinite loop, and may cause everything else to hang.

I've looked at those files, both vkitchen and shuihu are just inheriting
other modules or objects under std/. This means something fundemental
is screwed up. This kind of error is hard to trace... :(

All please be careful to avoid infinite loops in your coding.


---
作者: Stefan
题目: error caught in log
日期: Wed Jun 16 15:48:11 1999
object /sgdomain/area/guan/huayin/vkitchen: eval_cost too big 1000000
object /secure/simul_efun: eval_cost too big 1000000
object /sgdomain/obj/foodanddrink/shuihu#32453: eval_cost too big 1000000

This means there is infinite loop, and may cause everything else to hang.


---
作者: Fire
题目: the command of cpu
日期: Thu Jun 17 07:28:13 1999
I updated the command of cpu
so it will give more information


---
作者: Row
题目: about area development
日期: Thu Jun 17 23:23:41 1999
前一阵和桃桃聊的时侯，他提到了关于地区发展中一些属性的
修改，我个人认为相当好。由于桃桃比较忙，就由我来解释并
补充一下，希望没有差错。

现在的地区发展公式相当的复杂，其中工业、商业、农业等值
应该是占比较重的比例的(没有仔细看公式，不知道是不是)，
但目前玩家并没有一些积极的方法来提高这些指数。所以我们
可以加一些工作来实现，比如开发新田的工作就可以提高农业
值等等。为了令发展留有余地，建议将单个值的模式改成类似
于玩家技能值的等级/ 积累值模式。完成工作将提高相应积
累值，当积累值达到要求以后，则等级提升。关键是如何设计
公式，既不能太难也不能太容易。烈火的意见是：等级数* 等
级数* 调节值。

至于通过什么工作来发展相应的值的问题，需要多考虑考虑。
我会在近期内写个计划。


---
作者: Fire
题目: a new wiz tool
日期: Fri Jun 18 10:17:52 1999
cutter used for create npc char quickly
just type "cutter", all is easy


---
作者: Fire
题目: I will begin the stuff and base system (物资和生产基地)
日期: Fri Jun 18 10:19:14 1999
the main daemons is /daemons/stuff_d.c


---
作者: Row
题目: something in war
日期: Wed Jun 16 12:12:46 1999
fire, maybe becoz u changed pos, now attacking part in war,
only 主将 can see warinfo, not others
and...after war, only the officer in the leader's troop will
be assign as the occupied area's officer and get rewards.
is that the right thing?


---
作者: Row
题目: >基地、产品
日期: Tue Jun 22 04:58:13 1999
this file is:
/sgdomain/txt/stuff_sys.txt

can check it anytime and adjust it.
addoil


---
作者: Row
题目: 基地、产品
日期: Tue Jun 22 04:39:30 1999
在ice的帮助下，我整理了一下基地、物品的清单：
基地：

一级：原料生产场地，自动产出一级原料：

林场、采石场、铜矿、铁矿、猎场、牧场、农场、果园

二级：加工工场，加工送进来的原料，成为半成品：

锯木场、凿石场、冶铁场、炼铜场、屠宰场

三级：成品工场，进一步组合送进来的配料，成为成品：

军工场、驯马场、码头、酿酒场、藤具场

产品：

一级：原料，从各个基地生产出来：

原木、石料、铜矿石、铁矿石、猎物、幼马、粮食、水果、藤条

二级：半成品，经过加工：

木材、方石、圆石、精铁、熟铜、兽皮、兽肉、兽筋

三级：成品，经过组合出来的可以直接使用及升级军队的必
      备品：

木杆、弓、弩、铁钉、铁片、铜片、箭簇、马鞍、战马、酒、
藤甲、藤牌


至于何种基地产出何种产品是非常清楚的，下面就列一下各种成品
的组合及其用途：

枪头+木杆-->长枪：升级长枪兵；
铁片+兽皮-->铁甲：升级步兵；
铁片+木杆-->刀：升级朴刀兵；
藤牌：升级藤牌兵；
兽皮+兽筋+铁皮-->马鞍：升级游击骑兵；
战马：升级骑兵；
铜片+铁片+兽皮-->重甲：升级重甲骑兵；
弓+木杆+箭簇-->弓箭：升级弓兵；
十份木材+十份铁钉+十份铁片-->战船：升级战舰；
兽皮+兽筋-->皮甲：升级带甲弓兵；
兽皮-->水靠：升级水兵；
弩+兽筋-->强弩：升级弩兵；
精铁+木杆-->短刃：升级山贼；
精铁-->利刃：升级水贼；

(以上是二次升级部队所需要的所有物品，至于三次升级，可以另行
组合)
如：圆石+木材-->发石车

酒+兽肉+水果+粮食+金：犒赏三军及所有官员，军队升士气，官员升
忠诚。

建议加入城防度：利用方石+木材+金可以坚固城防，每一次经过战争
或破坏，城防度降低。

若有可能的话，加入城市升级系统。在原有等级的水平上，达到一定
的要求，比如商业等指数到多少，并花费一定的资金物品，就可升到
下一级，共有三级(A、B、C) ，每个等级各项指数都有限制。2C的指
数大于3A是有可能的。若烈火觉得可行，具体可以讨论。

以上是简单的关于物品及基地的清单，至于具体的数量、时间、限制
等等需要再讨论。若有遗漏或不合理的地方，请及时指出。

至于对应的工作等资料，可以另行给出。


---
作者: Row
题目: >some ideas about gini
日期: Tue Jun 22 00:27:07 1999
agree ice


---
作者: Ice
题目: some ideas about gini
日期: Tue Jun 22 00:07:54 1999
I dun know the functions that fire may plan to add on gini,
just some personal ideas here..:O~

gini
你从怀里掏出一盏阿拉伯神灯，用袖子擦了擦. . . . 
一股篮烟从灯中冒出，慢慢地化成一个蓝色大怪精灵。

gini help
精灵说我可以给你以下的提示：
1、我刚来，没钱，怎么办？：gini money
2、我该怎么涨个人修养呢？：gini skills
blah blah

gini money
大精灵说：没钱呀，当然要工作挣钱啦，哪儿有免费的午餐呀，
不劳而获的事情这里好像没有，看看help money吧。
大精灵又偷偷告诉你：听说如果完成一些仙人的工作会有金子
的酬劳哟，看看help xianren吧。

gini skills
大精灵说：你是新手呀？那你得在华阴工作一段时间才能出师喽，
先赚点钱，找孔已己请教一下学问，还有如果有张家帖的话，可以
找张员外学学武学修养，到30级有效。之后嘛，还要学就只有当官喽。
blah blah

this kind of help is not formal help file, but can be indicators,
so just for get the idea of 锦囊, gini can do it now..:)
how do u guys think about it?


---
作者: Fire
题目: >关于仙人工作
日期: Mon Jun 21 23:57:43 1999
On Mon Jun 21 23:52:05 1999 Ice wrote post #536:
> 我觉得仙人工作是很适合新手做的，因为新手一般不熟悉地图和城市，
> 仙人工作使他们有机会在全国范围内周游，而且现在的华阴工作好像
> 不长声望了，而找人的工作一般会随机加声望或贡献，因此我觉得该
> 大力推广仙人工作。现在的问题是没有相适应的帮助文件和物品购买
> 的指导，我会在这两天完成帮助文件，但是物品购买的指导需要先设
> 置州郡制度，然后设置一个包打听在的NPC，可以告诉玩家哪个州有他
> 需要的东西，包打听可以在每个州的治所设置一个，他会指导玩家在全
> 国范围内物品的分布。
> 
> but the point is need code the province system first, then create
> the NPC, but seems now everyone is busy... :PPP, so who can code it yah?
> * fool

* point ice :)


---
作者: Ice
题目: 关于仙人工作
日期: Mon Jun 21 23:52:05 1999
我觉得仙人工作是很适合新手做的，因为新手一般不熟悉地图和城市，
仙人工作使他们有机会在全国范围内周游，而且现在的华阴工作好像
不长声望了，而找人的工作一般会随机加声望或贡献，因此我觉得该
大力推广仙人工作。现在的问题是没有相适应的帮助文件和物品购买
的指导，我会在这两天完成帮助文件，但是物品购买的指导需要先设
置州郡制度，然后设置一个包打听在的NPC，可以告诉玩家哪个州有他
需要的东西，包打听可以在每个州的治所设置一个，他会指导玩家在全
国范围内物品的分布。

but the point is need code the province system first, then create
the NPC, but seems now everyone is busy... :PPP, so who can code it yah?
* fool


---
作者: Fire
题目: >gini 错别字真多
日期: Mon Jun 21 21:27:18 1999
On Mon Jun 21 16:50:54 1999 Stefan wrote post #534:
> 而且非常 annoying，说话的频率太高。
*blush

I will adjust it
can row please help to correct some words :)



---
作者: Stefan
题目: gini 错别字真多
日期: Mon Jun 21 16:50:54 1999
而且非常 annoying，说话的频率太高。


---
作者: Fire
题目: 关于内务系统
日期: Mon Jun 21 06:29:36 1999
看了flee关于内务系统的设想，感到基本构思很好，与我和ROW，ICE前几天
讨论的系统基本是相兼容的，只是在部分细节上有一些变化。现在我想补充
一些建议。
1 关于采集业和加工业：
      实际上，这两个是很相似的系统，其基本点都是有一个可以输出的基
  地(在采集业中是牧场，矿场，在加工业中是工厂，作坊，船厂)，和可以
  生产的物资。所不同的是，加工基地需要原料，而采集基地则不需要原料，
  加工基地可以在大部分地区建造，而采集基地有一些地域限制。但这点小
  的不同可以在参数设置上区分，不用另建系统。整套系统的对象有两大类，
  生产基地和生产物资。其数据格式如下：
      物资的定义格式：
        spear :   // 长枪
         ([  "name" : "长枪",
             "base" : // 可以生产长枪的基地
                ({  : // 此处用数组主要考虑某些物资多种基地都可制造
                   ([ "type" : "weapon plant", // 兵工厂
                      "level" : 2 // 该兵工厂的最小等级
                   )]
                )}
             "quality" : 20, // 一次生产的最基准数
             "consume" :     // 生产需要消耗
               ([ "gold" : 10 // 十两金
                  "spear pole" : 20  // 枪杆
                  "spear head" : 20  // 枪头
                  "power" : 500 // 所需生产力，这是一个虽抽象但很
                                // 重要的参数，不同的工厂，由于其
                                // 规模不同，其单位时间所能提供的
                                // 生产力也不同，如果一个工厂的单
                                // 位生产力是50，那么就需要十个单
                                // 位时间来生产10杆长枪。关于生产
                // 力的计算，需要一个复杂平衡的公式，需要综合工厂
                // 的等级，地区人口，地区官员数量，技能等级，玩家
                // 的JOB得因素。
                ]),
           ])
                           
     基地定义格式：
       "ironmine" : // 铁矿
          ([ "name" : "铁矿",
             "area" : ({ "taiyuan","jianning",. . .}),
                    // 可建该类基地的地区，如果没有，则表示不受地
                    // 区限制。
             "level" : 3 // 可建立此类基地的最低地区等级。
             "lev1" :  // 建造一级需要的条件
                ([ "population" : 10000, // 当地人口一万以上
                   "safe" : 70, // 当地安定度 70 以上
                   "gold" :10000, // 需要金 10000
                   "energyout" : 10, // 基本生产力
                   "time" : 600, // 需要600秒完成建设
                ]),
             "lev2" :  // 升到二级需要的条件
                ([ "population" : 15000, // 当地人口一万五以上
                   "safe" : 90, // 当地安定度 90 以上
                   "gold" :10000, // 需要金 10000
                   "energyout" : 20, // 基本生产力
                   "time" : 600, // 需要600秒完成升级
                ]),
             "lev3" :  // 升到三级需要的条件
                ([ "population" : 20000, // 当地人口两万以上
                   "safe" : 100, // 当地安定度 100 以上
                   "gold" :10000, // 需要金 10000
                   "energyout" : 30, // 基本生产力
                   "time" : 600, // 需要600秒完成升级
                ])
          ]) // 可能还需要定义一些其他参数。
2 关于私有和公有。
  这是一个很有趣的设想，但需要更仔细的定义。例如：
      a. 谁可以拥有私人产业。
      b. 如何拥有私人产业。步骤是什么。
      c. 拥有私人产业的好处是什么。
      d. 有没有弊病。
      e. 数据存储位置，格式。
      f. 和共有产业的关系。
3 生产方式：
  生产方式可以有三种：
      a. 全自动：如目前的粮食生产，到时就有，不需玩家费事。
         优点：设计简单，不容易产生BUG。
         缺点：玩家没有太多的参与。
         适合初期玩家较少，一名玩家要照顾大部分地区的情形。
      b. 全手动：如目前的征兵系统
         优点：强调玩家参与，产出的结果与玩家的付出成正比。
         缺点：NPC变得基本没有价值，系统机构不太平衡。
         适合玩家非常多的情形，各地区的发展由玩家的相互合作，
         相互制约达到平衡。
      c. 半自动：有些向目前的战争系统。玩家对自己的部队有全权
         控制，但NPC部队也有相当的战斗力。
         优点：灵活，合理，是本MUD的理想模式。
         缺点：开发难度大，容易有BUG
    我认为将要开发的内务系统最好采用第三种生产摸式。在没有玩家干预
    或玩家只给很少干预的前提下，系统也会根据地区安定度，人口，NPC官
    员的技能等级等因素，地区也能完成一定的生产。但如果有玩家干预，
    玩家通过各种JOB，可以使产量更高，产品结构更丰富。但设计和编程难
    度一定不小。
4  关于商业和运输业
   flee提出的由店小二等maker进行的商业行动很有创意，但我认为这应该
   只是一个针对玩家个人活动的一个小的商业系统。大规模的商业活动还是
   应该通过以国家商队为代表的商业系统。关于运输，我想提以下建议：
     a. 运输必需在本国内进行。
     b. 运输起终点必需相邻。
     c. 运输要由国家会议批准。
     d. 运输过程中，参与官员的地区设为0，地区官职设为R_SG(=1000)，这
        样就不会受诸如地区会议，战争的骚扰。
5  人选
   我本来想负责这一部分的设计，但现在老板回来了，没有太多时间，所以我
   将主要致力于玩家帮助精灵(gini)的设计，所以这一部分就请flee负责，row
   ice和group参加，我做一些和其他系统兼容性的调整工作。希望能能向今天flee
   多做一些详细的POST:)另外还有帮助文件等文本。如果修改老的数据结构，请
   override一些老的函数，使他们还可以工作正确，这样就可以减少许多函数的
   调整工作。


---
作者: Fire
题目: a very difficult bug
日期: Sun Jun 20 05:33:29 1999
a very difficult bug has be catched in char_d
sweat :)
char_d is the core daemon, should be bug free !!


---
作者: Flee
题目: about bao dating
日期: Sat Jun 26 03:23:49 1999
ok now, check it at /sgdomain/modules/m_charnpc/xianren


---
作者: Row
题目: >结义(cmd jieyi)
日期: Wed Jun 23 05:00:46 1999
上篇输入过程中有误，缺了点东西：
结义必需物品：
雕花小刀：在某地铁匠铺买到，人手一把，用来刺胳膊:)，
          将血滴入海碗；
。


---
作者: Row
题目: objects for jieyi
日期: Wed Jun 23 05:48:38 1999
i have created 香炉 and 香：
/wiz/row/obj/xianglu.c
/wiz/row/obj/incense.c

fire check check to see see if they r useful bah..xixi.


---
作者: Fire
题目: >objects for jieyi
日期: Wed Jun 23 06:53:03 1999
On Wed Jun 23 05:48:38 1999 Row wrote post #545:
> i have created 香炉 and 香：
> /wiz/row/obj/xianglu.c
> /wiz/row/obj/incense.c
> 
> fire check check to see see if they r useful bah..xixi.

good point, will consider it next week :)



---
作者: Fire
题目: to row
日期: Wed Jun 23 07:29:30 1999
sorry row,
I upload the gini_d.c
and i forget to download it first, so may be 
some 错别字又回来了。
sorry

when you have time, can you help me to fix them again :)


---
作者: Ice
题目: 关于rumors的建议
日期: Thu Jun 24 19:35:40 1999
设想是这样的：

首先建立了州制度，以及一个独一的包打听，包打听是会到处走的，象
现在的仙人一样。他知道所有物品在什么地方可以买到。

在boy里加一项功能：ask boy about rumors

ask boy about rumors
你向调皮小男孩问到：“不知最近有没有听说什么消息？
调皮小男孩嘻嘻一笑：倒是听到过一些，你想知道什么呀？
调皮小男孩说：想知道下面这些人的行踪吗？
1：包打听，2：华陀，3：许子将，4：于吉，5：左慈。
请出入你的选择：1
调皮小男孩道：包打听呀，好像听说过，不过。。。
调皮小男孩又不说话了。
请输入对策：1、给钱，0、算了。
1
//if give money, it can be randomly range from 5 to 10 silver
你拍拍调皮小男孩的头说：给你八两银子，你爱怎么花就怎么花吧。
调皮小男孩高兴地跳了起来。
你给调皮小男孩八两银子。
调皮小男孩说道：听说包打听最近到洛阳去了。
0
//if not give money
你对调皮小男孩道：算了，这么一点小事也要钱，哼！
调皮小男孩一脸的不满：哼，小器，以后别找我。
调皮小男孩上前劈胸将你一把抓住，两眼圆睁，呲牙咧嘴地将你往死里掐。

加询问boy谣言是为了让玩家可以找到包打听或需要做仙人工作的时候，不
苦苦等几十分钟的谣言，或者我们还可以加入寻找商队的选项，与现存的谣
言频道一起使用。


//go luoyang, find 包打听
ask bao dating about something
你向包打听深深一鞠躬道：小可欲购一物件，但苦不知何处可得，盼先生指教。
包打听慢理斯条地说：你要找什么东西呀？
请输入要找物品的ID
你打算找什么物品：buyi
你道：我想找布衣。
包打听听了「嘿嘿」一笑：这我当然知道，只是这个。。。这个。。。
包打听望了你一眼，没有说下去。
请输入对策：1、给钱，0、放弃。
0
//no money no talk
你犹豫了一下，对包打听说：实在不好意思，小可最近手头比较紧。
包打听「哼」了一声，一脸不满的样子：那你自己慢慢找吧，别烦我。
1
//if give money, random from 10 to 50 silver
你满脸堆笑，连忙把一个早已准备好的红包放进包打听的怀里。
你给了包打听三十六两银子。
包打听两眼马上放光了：好！就告诉你吧，布衣在雍州（yongzhou）一带可以买到。

info p yongzhou
长安（changan），         五丈原（wuzhangyuan），
武关（wuguan），          函谷关（hangu），
潼关（tongguan），        华阴（huayin），
泾阳（jingyang），        咸阳（xianyang）。

事实上布衣不止在雍州可以买到，但包打听会从有该物品售卖的州（province）里
随机挑一个出来。
包打听的作用在于缩小做仙人任务的玩家的搜索范围和提供物品信息给需要定做某
些物品的玩家。




---
作者: Ice
题目: 州郡列表
日期: Thu Jun 24 19:36:32 1999
本三国将共计有十七州九十九郡。

幽州：（共六郡）
代县，蓟城，易京，北平，白狼山，襄平。

冀州：（共四郡）
南皮，平原，清河，界桥。

青州：（共三郡）
济南，渤海，北海。

兖州：（共五郡）
邺，陈留，定陶，濮阳，白马。

豫州：（共四郡）
许昌，谯，汝南，官渡。

徐州：（共五郡）
徐州，小沛，下邳，广陵，琅邪。

并州：（共四郡）
太原，上党，雁门关，晋阳。

司隶：（共七郡）
洛阳，虎牢关，壶关，渑池，弘农，宛，博望坡。

雍州：（共八郡）
长安，五丈原，武关，函谷关，潼关，华阴，泾阳，咸阳。

凉州：（共八郡）
西凉，陇西，天水，狄道，街亭，安定，秦川，陈仓。

梁州：（共八郡）
汉中，祁山，下弁，阳平关，定军山，剑阁，梓潼，涪城。

益州：（共六郡）
成都，绵竹关，江州，永安，建宁，云南。

北荆州：（共七郡）
襄阳，上庸，新野，澶溪，长坂坡，江夏，赤壁。

南荆州：（共八郡）
江陵，夷陵，公安，华容，武陵，零陵，长沙，桂阳。

郢州：（共六郡）
庐江，西塞山，丹阳，鄱阳，柴桑，豫章。

扬州：（共七郡）
建业，寿春，合淝，淮阴，濡须口，吴郡，会稽。

交州：（共三郡）
南海，桂林，庐陵。




排在第一的郡可以作为治所或首府什么的。 * fool


---
作者: Ice
题目: 州郡分布图
日期: Thu Jun 24 19:37:33 1999
                      【三国时代各州分布图】
◎＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝◎
‖                              ┌────────────────┐‖
‖      ┌┐          ┌────┤       幽              州       │‖
‖      │└─┐      │ 并  州 ├───┬────┬────┬──┤‖
‖  ┌─┘    │      │  ┌──┘      │兖      │冀      │ 青 │‖
‖  │凉    州├───┴┬┘        隶  │      州│      州│ 州 │‖
‖  └┬──┬┘ 雍     │ 司       ┌─┴─┬──┴────┴──┤‖
‖    │    └┐     州 │          │豫  州│    徐        州    │‖
‖    │梁  州├────┴─────┤  ┌─┴────────┬─┘‖
‖┌┬┘      │ 北                 └─┤   扬               │    ‖
‖│└────┤           荆           ├───┐       州   │    ‖
‖│ 益       ├────────┐  州  │  郢  ├────┐  │    ‖
‖│          │                └┬──┘      │        │  │    ‖
‖│       州 │南   荆   州┌──┴──┐      │        └─┘    ‖
‖│          │            │ 交    州 │  州  │                  ‖
‖└─────┴──────┴─────┴───┘                  ‖
◎＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝◎


draft


---
作者: Fire
题目: 支持州的设计
日期: Fri Jun 25 02:18:11 1999
我将写代码，ICE输入信息


---
作者: Ice
题目: 建议仙人工作的修改
日期: Fri Jun 25 10:48:40 1999
1. 于吉工作的暗号，should be goods available in makers
today i tried yuji's job, but it required 朴刀, which i just made yesterday, 
not in makers yet;
2. 提高仙人工作的金子奖励
xuzijiang -> 2 gold //because need travel in many cities, need
entrance fee for officers
huatuo -> 2 gold //because need travel in cities
zuoci -> 2 gold //same as above
yuji -> 4 gold //because need both travel and buy objs

3. yuji's job's objs should be changed to lv 0 -> lv 2, which may
sell after job done

addoil flee
* smirk


---
作者: Ice
题目: some comments of gini old
日期: Fri Jun 25 20:34:29 1999
我想 gini old 的目的是正确的，但是是否方法上可以改进一下。
每个玩家都有权利选择帮不帮助新手，以及如何帮，如果非要在帮
就获得利益，不帮就有损失之间选择，这似乎剥夺了玩家一部分的
权利，譬如他们正不想被别人打扰要专心做某一件事情的时候，一
下子被抓去了，有种哭笑不得的感觉。
此外，有新手判断帮助是否有效，是非常主观的问题，如果辛辛苦苦
费了半天口舌，最后被新手一句话否决了，那。。。

建议先将这个选项隐藏，直至有新的设想或改进才公开使用。

addoil.:P


---
作者: Ice
题目: suggestion of gini
日期: Tue Jun 22 22:38:53 1999
//After login

突然冒起一股篮烟，烟雾中，一个蓝色大精灵递给你一盏神灯，说道：
我是你的保护神，当你需要我时，只要输入 %^H_BLUE%^gini%^RESET%^ 我就会帮助你。

//then gini auto hide, or add a sentence as following
蓝色大精灵说：如果你觉得现在不需要我，只要输入 %^H_BLUE%^gini
away%^RESET%^ 我就
会回到神灯里。

//gini appear
gini
你一擦神灯，蓝色大精灵急忙从远处飘来。
蓝色大精灵看着你，叹了口气：好吧，我可以给你下面这些提示：
1、我是新手，怎么玩？：%^H_BLUE%^gini newbie%^RESET%^
2、我刚来，没钱，怎么办？：%^H_BLUE%^gini money%^RESET%^
3、我该怎么增加个人修养呢？：%^H_BLUE%^gini skills%^RESET%^
4、什么工作好做呀？：%^H_BLUE%^gini job%^RESET%^
5、我要打架，我要增加武功！：%^H_BLUE%^gini fight%^RESET%^
6、我要当官！：%^H_BLUE%^gini dangguan%^RESET%^
7、我当官了，然后呢？%^H_BLUE%^gini officer%^RESET%^
8、我要打仗！怎么打？%^H_BLUE%^gini war%^RESET%^

//gini's tips
gini newbie
蓝色大精灵轻轻拍了拍你的头，新来的呀，先看看 %^H_BLUE%^help newbie%^RESET%^ ，
和 %^H_BLUE%^help starts%^RESET%^ 吧，好好记住一些命令，譬如 map, ask

gini money
蓝色大精灵说：没钱呀，当然要工作挣钱啦，哪儿有免费的午餐呀，
不劳而获的事情这里好像没有，看看 %^H_BLUE%^help money%^RESET%^ 吧。
蓝色大精灵又偷偷告诉你：听说如果完成一些仙人的工作酬劳很高哟。

gini skills
蓝色大精灵说：你是新手呀？那你得在华阴工作一段时间才能出师喽，
先赚点钱，找孔已己请教一下学问，还有如果有张家帖的话，可以找
张员外学学武学修养，到 30 级有效。之后嘛，还要学就只有当官了。
最好先看看 %^H_BLUE%^help learn%^RESET%^ 。

gini job
蓝色大精灵说道：工作的事情你最好还是先看看 %^H_BLUE%^help basicjob%^RESET%^，
这里的工作难度不一样，不过如果你净挑容易的做的话，嘿嘿，那么
你的文学修养就很难涨了，看看 %^H_BLUE%^help robot%^RESET%^吧。
蓝色大精灵皱了皱眉头，又对你说：我是没有干过活的，不过。。。
蓝色大精灵压低了声音：听说砍柴和锄地工作最容易，还有张家帖，
但是。。。如果只干这两种工作的话，文学修养一定不够，所以。。。

gini fight
蓝色大精灵对你一拜说到：现在真是后生可畏呀，年纪轻轻就要出人头
地了。不过只有当你定居了之后才能打架，如何定居 %^H_BLUE%^help
settle%^RESET%^ 。
定居了之后，可以看看 %^H_BLUE%^help fight%^RESET%^，加油呀！

gini dangguan
蓝色大精灵赞许地摸着你的头：这孩子真有志气，将来一定大有前途。
好吧，看看 %^H_BLUE%^help position%^RESET%^ 吧。
蓝色大精灵又拉着你到一边说：当官要先定居，如果你的修养太低了，
没有谁会要你的，还有，你的声望要达到%^H_RED%^小有名声%^RESET%^才能当官的。

gini officer
蓝色大精灵对你一拱手道：恭喜恭喜。
蓝色大精灵笑容一敛，正色道：当官不止是为自己，还要为国家，为
黎民百姓着想，当昏官是没有好下场的。
蓝色大精灵的脸色缓了一缓：先看看 %^H_BLUE%^help midjob%^RESET%^ ，然后努力
工作，增加自己的修养和经验，才能成为职位更高的官员。
蓝色大精灵眼睛好像开始变绿了：当官每个月都有薪俸，用 %^H_BLUE%^info
me%^RESET%^
就可以查到，如何提取薪俸可以看看 %^H_BLUEhelp money%^RESET%^ 和
%^H_BLUE%^help myarmy%^RESET%^，
有了薪俸还可以有自己的亲兵。
蓝色大精灵说道：是不是总是在谣言里面看到某某地方正在召开地方会
议，如果你要开会的话，认真看看 %^H_BLUE%^help meeting%^RESET%^里面所有相关的
帮助文件吧，你不看完并记住是没有人帮的了你的。

gini war
蓝色大精灵皱了皱眉头：要打仗？你参加过训练嘛？要是没有的话，我
劝你还是先看 %^H_BLUE%^help train%^RESET%^ 和 %^H_BLUE%^help war%^RESET%^，
里面的帮助，先练练再打仗吧。

         chat talking, now xianren's chat talkings are too simple, and gini's
         talking is meanless to player, because no one will notice them and no
         on will like to keep him flooding his screen.
         of gini's talking, it should be shown like the help.
//it's a draft version, but i think it can be put as urgent use at
present, I will
  try add more related tips to newbie later, and i will adjust the
related help.

how are u guys' comment?
* fool



---
作者: Row
题目: 结义(cmd jieyi)
日期: Wed Jun 23 03:29:36 1999
我已经在平原北城门出口往北造了一座桃园，专门为玩家结
义而设。至于结义的具体过程，设想如下：

结义所需要的物品及器皿：
香：可以在某地的香烛里找到，人手一根，可以light ，焚
    香，然后插入香炉；
香炉：就放在桃园里，用来插香，烧一次持续三十分钟，也
      就是说结义只能每三十分钟一次；
          将血滴入海碗；
海碗：内有酒，在某地酒馆内买到，人手一只，结义的时侯
      还可以盛玩家刺臂后的鲜血，以示诚心。

结义步骤：
带齐所有物品(香、雕花小刀、海碗)，来到桃园；
其中一人键入：cmd jieyi；
提示问：与谁结义？
输入：id1,id2(一个id也可，最多两个，以下以两个为例)，
      同时发信息给另外两人：某某、某某想与你结义，是
      否答应？
若不同意，终止过程；若同意，则检测三人物品是否带齐，
若符合要求，以下过程全部自动进行(三人都设busy)：

系统计算三人年龄，然后排序，年长的先行动：
甲取出一枝香，在香炉上点燃。
乙取出一枝香，在香炉上点燃。
丙取出一枝香，在香炉上点燃。
甲、乙、丙一齐双手举香过顶，单膝跪地，朗声道：念甲、乙、
丙，虽然异姓，既结为兄弟，则同心协力，救困扶危；上报国
家，下安黎庶；不求同年同月同日生，只愿同年同月同日死。
皇天后土，实鉴此心。背义忘恩，天人共戮！
誓毕，以甲为兄，乙为次，丙为弟。三人相视而笑，将香插入
香炉，于徐徐香烟中各端起海碗，并拔出雕花小刀于臂上一刺，
将鲜血滴入，仰头一饮而尽，从此三国路上不再寂寞！

完了后将香、刀、碗摧毁，香炉设三十分钟期限，若有人来用：
此炉香烟燎绕，看来刚有人用过，必须等一下。

以上是大概的想法，若有补充或改动，请指出。


---
作者: Fire
题目: about the guard
日期: Tue Jun 29 23:21:19 1999
in order to save our cpu resource
I make the guard like a common npc
and remove the call   "/sgdomain/event/ev_guard"->aut_appear() from
ai_d.c to reduce the cpu burden
but now we need ice help to add the guard to all the go rooms
you can check the code in huayin's go room

if not finish this and no gurad appeard in 
some areas we can use the command
  "/sgdomain/event/ev_guard"->aut_appear() manualy to create those guards

addoil ice

escape


---
作者: Ice
题目: some changes i have made and going to make
日期: Sun Jun 27 16:11:13 1999
added the gold reward for most xianren jobs, from N -> N+random(N).
because nowadays xianren jobs cannot attract enough player to do it
frequently, and actually these jobs are very nice, can make newbie be
more familiar with the maps and functions of finding ppl and objs, and for
most low level officer can make it as a income resource.

I will update most helps with colored cmds.


---
作者: Fire
题目: 重要事项
日期: Sun Jun 27 07:36:35 1999
有人报告壶关士兵多日来数量并没有下降。
我检查代码后发现是area_d中的一个函数set_area_soldier
不见了。我相信这是我几天前新增的一个函数，他的消失
很可能是谁不小心用一个较旧的版本upload时把它个覆盖掉了。
这种现象我以前也观察到几次，我个人也犯过此类错误:)
现在由于工作WIZ较多，这种情况就更容忍发生。
所以请注意：再更新文件前一定要
%^H_RED%^先download,再修改，再upload%^RESET%^。
同时有多名WIZ再线时要%^H_RED%^了解彼此在做什么。%^RESET%^

adddoil :)


---
作者: Fire
题目: admire ice
日期: Sun Jun 27 07:02:40 1999
今天才发现ice update 了如此多的help文件
addmire ice:
)
下次update help 后可以给一个短短的 post :)
addoil


---
作者: Fire
题目: a little bug in xianren
日期: Sun Jun 27 06:55:12 1999
> [errors] (eata) Error logged to /log/runtime
[errors] *Array index out of bounds.
[errors] /sgdomain/job/xuzijiang/xianren#6496 at line 147

I checked the code seem because one of the maker
have no goods, so cause that bug


---
作者: Fire
题目: the bug about outof data in black list
日期: Sun Jun 27 05:57:21 1999
when a player enter this city
the list will be updated and remove out of data chars
so this will be not a big problem

the bug about 本国官员 can't removed from black list
is fixed


---
作者: Ice
题目: some suggestion of current existing jobs
日期: Sun Jun 27 02:03:32 1999
仙人左慈

因为在不同的城市不能以方向定位，所以造成比较大的困扰，
因此是否能将如果目标房间不是在所在城市的时候，显示：

似乎在周围极近的城市。 neighbour cities
似乎在周围不远的城市。 more than 1 linked cities in between
似乎在极远的城市。 all others


仙人华陀

有案例：锄头断了，但手头最后一棵药草却不是符合要求的，
负重没有超过 100% ，是不是系统判断药草挖到了，但是由于
不知什么原因（可能是负重问题），药草没有上身。
P

suggest change：
你挖到一棵无色无味的药草，发现不是你要找的，
又把它丢了。
then dest yaocao

and at the point player got yaocao, chutou will be broken, and
will add yaocao, then the loadings won't be a problem, i guess..:D

浇花

如果某一个玩家拿到了浇花的工作，又不去做的话，其他玩家
似乎要等比较久才能去做，set the busy time shorter?

addoil yah .....:O~~


---
作者: Fire
题目: a big improvement in char_d
日期: Tue Jun 29 07:33:04 1999
char_d 有本MUD最大的mapping.
其中最耗时的一个函数是check_char
这条指令是用来检测符合某一条件的角色清单
例如： check_char("area","luoyang") 将返回所有定居在
洛阳的角色清单。这一函数非常有用但因为要检索
全部数据库因而非常耗时。
我怀疑我们MUD的周期性当机和此条指令有关。
因为为了实现动态操作角色的功能，在所有房间
当update时，都要利用上述函数到char_d中查找当前在本房间
的角色清单，因为我们有上千的房间，多次的查询会对系统造成巨大
的压力，我很怀疑因此引起多次当机。
现在我在char_d中增加了一个新的mapping用于改善检索
房间角色清单的性能，改进后的检索函数
比原来的函数快了300到400倍:)
比原来的函数快了300到400倍:),可以用下面方法测试：
@time_expression(CHAR_D->check_char("room","daf"))
比较 @time_expression(CHAR_D->check_char("name","daf"))
就会发现房间的检索速度会得多。
希望这个可以减少意外当机事件。
注：因为采取了函数override技术，所有其他的程序不需调整。
addoil :)


---
作者: Fire
题目: 关于战争
日期: Sat Jun 26 12:14:09 1999
没有战争，本MUD就没有生机
建议在下周五，开放战争一日
一方面刺激市场，另一方面观察BUGS


---
作者: Fire
题目: help need
日期: Sat Jun 26 11:41:17 1999
jail and guard are two interesting system
please give player's help document :)


---
作者: Row
题目: 开发东部
日期: Sat Jun 26 13:46:18 1999
我打算在东部拿几个等级三的地区出来招聘太守，但有
一定条件，大家看如何？


---
作者: Ice
题目: agree row
日期: Sat Jun 26 15:20:35 1999
as title


---
作者: Flee
题目: >>agree row
日期: Sun Jun 27 00:38:21 1999
as title .. :)


---
作者: Ice
题目: suggest change of local positions
日期: Thu Jul  8 15:12:32 1999
pls check /wiz/ice/txt/local_position.txt out, for some
unknown reasons, some parts cannot be shown while i post
it, sorry for any inconvenience...:P


---
作者: Ice
题目: an idea about safety after war
日期: Thu Jul  8 13:44:16 1999
suddenly get an idea of safety after war, though i didn't check
the formula, in my observation, safety will drop to about 30 sth
after war, but it sounds too average.

suggest to change to this way:

I think safety is a kind of 拥护度 of that city, so higher safety
b4 war, after the enemy get the city, lower safety remaining
by
contrast, lower safety b4 war, higher after:

I think it can be (300-safety)/5 after war, or we can add a +random(10)

* smirk

addoil ..:)



---
作者: Fire
题目: some char_d function updated
日期: Thu Jul  8 00:13:34 1999
I updated the following function
CHAR_D->check_char("area",<a_id>)
CHAR_D->check_char_area(<parea>,<value>,,<a_id>)
CHAR_D->check_char("nation",<n_id>)
CHAR_D->check_char_nation(<parea>,<value>,,<n_id>)
AERA_D->get_area(<a_id>,"leader">

so those functions now are 100 - 300 times quicker than before

but the first time to run them, maybe the same speed as before
if the second or following times to run them, much quicker

don't know if any potential bugs :(
addoil


---
作者: Fire
题目: about check_char
日期: Wed Jul  7 22:36:08 1999
because check_char is a very very time consuming function
I have adjusted following events to avoid it
1 npc_move is moved from char_d to a seperate event
 ev_npc_move and it is called by the npc's heart
 so much quicker
2 ev_position, it is used called by ai_d
  now it is directly called by the npc's heart
  so quicker
3 ev_leave it is the same as ev_position
4 ev_donate
  for npc donate, i adjust the auto_donate
  now it is 10 times quicker than the old one


---
作者: Ice
题目: about money
日期: Wed Jul  7 13:39:18 1999
I think money should have weight, when a player get too much money
on hand, he is supposed to suffer heavy weight, like carrying 20k gold
on hand, it's not possible for a humanbeing.  

well, on the other hands, nowadays more and more player kings, and I think
we have to notice that king can keep withdrawing gold from national reserve
while a city's safety is 0.  Being king now sounds like a way to get
fast money
and good equipments, i think that's not our orginal wishes...:P
suggest to change to the following possible ways:
1. add a limit that king can withdraw from national reserve,
  for example, a king can withdraw at most 10 times per mudday, and the safety
   will drop using the currently existing method.
2. when an area's safety drop to 0, it will cause a 暴乱， which can expand to
   its neighbourhood cities, make their safety drop in a higher
speed than normal.
3. when safety of that city drops to 0, king cannot withdraw there anymore.
4. or some other ways, (* grin), when a king withdraw too much, all
cities belong
   to him will drop safety .....:P

well, liyu complained that king has no money and now ice complain
king should have
limits of withdrawing....:PPP
* escape


---
作者: Ice
题目: a discovery of landlord job
日期: Wed Jul  7 13:26:44 1999
I think the idea of reward workers to increase their efficiency
is nice, but it makes a way to give money between players, like this

你对乱马说道：好好干，本将军赏你二百万两银子。;乱马沉思了片刻，加倍
努力的干起活来。
乱马身上带着如下物品(负重：0%)：
  十八文钱(coin)
  二万零十二两金子(gold)
  一个神灯(gini lamp)
  十九两银子(silver)


* fool, addoil ..:P


---
作者: Fire
题目: 战争要开了.
日期: Tue Jul  6 05:51:10 1999
这一周的任务重地是排除已知的战争BUG，同时加一些有利于防守的特性。


---
作者: Fire
题目: 三国的兴旺
日期: Sun Jul  4 03:16:33 1999
※ 三国 ※  （当地时间：九十九年七月四日上午三时十五分）
─＝ID列表＝─  目前总人数：45人
─────────────────────────────────────
小白(xiaobai)      兔子(rabbit)       乐乐(erfolg)       天机老人(tianji)
凉粉草(cool)       玄冰(ice)          小鹏(sue)          蓝精灵(blueelf)
天云(york)         英雄(yingx)        流星(liuxing)      兔子(bunnys)
无困(frake)        孤帆(boat)         笔者(coo)          惘然(remorse)
随便(firea)        小鹏(boney)        叶儿(yer)          梦幻家(sabah)
云飞扬(eata)       别忘存盘(sbboy)    爪蛙(java)         朱迪(zudi)
无双(loney)        大江(dajiang)      寻爱(wqin)         皇帝(king)
忘(dpn)            白开心(hahaha)     美美(meimei)       英名(pcm)
烈火(fire)         无虑(fearless)     绿箫(flute)        无忧(carefree)
无名(hhrr)         连连(lsz)          阿浪(beddog)       勇敢(braver)
火花(thjo)         游戏帮助(helpm)    大火球(xixixi)     团结(grouper)

*great
*addoil :)


---
作者: Ice
题目: agree flee
日期: Sat Jul  3 10:51:33 1999
how about this

if keep enter in chatting 3 time the same sentence, the player's channel will
be tuned, need 5 player's votes to reopen, vote will appear in rumor.

ps: i think the color of welcome page is nice..:)
   when i got up and saw my system reconnect, the welcome page was changed,
   I thought i was still in dream, u did an incredible job..:)
admire, fool


---
作者: Flee
题目: about flooding
日期: Sat Jul  3 04:27:34 1999
should change CHAT and other channels to prohibat flooding.


---
作者: Flee
题目: about logo page
日期: Sat Jul  3 00:37:05 1999
yestoday i had created some new welcome page .. :)
i put them under /sgdomain/txt/welcome. there are
logo1.txt, logo2.txt .. etc. of the four, i prefer
logo4.txt and i think it is the best of the all
so i use the logo4.txt as the new welcome page
but the color used is not so good .. :(
can ice do something to improve 

addoil ice


---
作者: Flee
题目: cmd wizlist ok now
日期: Sat Jul  3 02:19:22 1999
those wizards did not login for more than 30 days
will be highlighted with red .. :)


---
作者: Ice
题目: 工作系统化的小建议
日期: Sat Jul  3 23:52:42 1999
由于现在的新手越来越多，另一方面大米也越来越多，建议将现存和
将来可能会存在的工作作一些系统的分类：

1、现存的初级工作：

基本现在在张家村（华阴）的工作只提供金钱和文学修养，我想这一
方面不用更改，只是需要增加一些工作地点和工作类别。我想如果新
手的数目激增，只有一个华阴将远远满足不了需求，并且增加一些工
作，如替厨娘挑水（从池塘打水，挑水的每一步有busy time 之类）
blah blah 的工作(* doubt)，但是前提是要先除掉 （负重 -%1000）
这个大虫虫。

2、仙人工作

现在仙人工作基本是用来赚钱和声望的，如果令之成为新手唯一增加
声望的过程，新手会比较容易对地图熟悉和上手(* grin)。其实现在
仙人工作只要依照帮助和玩家自己的努力，基本上不难。前提又是除
虫虫，许子将的贤人没露面就不见了，于吉要求的暗号物品有些还只
是「此物只应天上有，人间能得几回闻」，（最好是0至1级的物品，
因为如果将2级的物品也设置成can_sell的话，又有变相的大白兔奶糖

3、找人工作

重点了重点了，这才是我想说的。在现在的状况下，所有的官员都可
以在本国内自由求职，这似乎不太合理，要调职应该要经过国王的批
准吧，所以建议在申请官职的设定里增加地区贡献的要求，现在如果
要担任朝廷官职，应该要相应的国家贡献，那么地方官职也该依据地
区贡献吧。如果是新手，那么可以通过做找人工作增加地区贡献，将
文官和武官的要求设成10好了，只要新手做完找人工作（只增加地区
贡献和银两），就可以成为当地官员。至于其他在职官员，则要向国
王申请调职，玩家国君的自己申请好了，ＮＰＣ国家的则要向国君提
出调令或者由国师调动，如当地太守设置了不会自动录取，则调动失
败。(* smirk)

4、中级工作

好像重点说完了，没有什么要再补充的。(* face)




---
作者: Ice
题目: about login name
日期: Sun Jul  4 00:15:25 1999
I think login chinese names should include cannot use the 
current existing NPC names and player names, otherwise make
pretty confusing to all.


---
作者: Fire
题目: >about login name
日期: Sun Jul  4 00:17:24 1999
On Sun Jul  4 00:15:25 1999 Ice wrote post #581:
> I think login chinese names should include cannot use the 
> current existing NPC names and player names, otherwise make
> pretty confusing to all.

this is a good suggestion,
but there is no good way yet to test
if a chinese name has been used or not by other players
unless that player has settle down.

maybe later, will try to build some thing to track all the used
chinese id


---
作者: Ice
题目: changed some setting of xianren job
日期: Sun Jul  4 13:52:41 1999
because the zuo_tool and hua_tool are frequent used tools,
and their hp consumption seems too high to newbie, i set
zuo_tool from hp-25 to hp-15, hua_tool from hp-25 to hp-10.
see see if it's reasonable..:PPP


---
作者: Fire
题目: about the load of daemons
日期: Mon Jul  5 07:30:53 1999
I find that during reboot, because oud mud has to load
a lot daemons and many daemons includes big mapping
so it is quite time consuming. and during this time
if some players login (this is quite often, becuase once
the mud is crashed and reboot, all players want to relogin
as quick as possible) then because not all daemons has been
initialized propoly, then may cause a lot bugs.

for daemons, because they don't have environment, so if
called by the clean_up, may be destroyed (not quite sure) then
if need reload it may take a long time, so I add clean_up
with return 0 (means never clean_up) in most big daemons
don't know if this may help our muds speed or crash problems
some way.



---
作者: Fire
题目: 发呆者乐园
日期: Mon Jul  5 07:42:10 1999
-------------------------------------------------------------------------
Reice snores majesticly  [idle 8h]                         
Crystal Meth  [idle 6h]                                    
Antilles has the right to remain silent.  [idle 22h]       
Lucy in the Sky with Diamonds!  [idle 4d]
Fire Fire  will burn all the world.         
Hellmonger (ok ok) contemplates becoming 'Fatty Spice Who Can't  [idle 16h]
Weed, Midhir, and fifteen naked women.  [idle 2h]          
Ket can't beat her computer at chess, so she tried kickboxing  [idle 6h]
Wodan sleeps  [idle 2h]                                    
Rassilon  [idle 9h]                                        
Yaynu goto reddragon.org 3000  [idle 1w]                   
Danatos  the Devil Prince  [idle 6h]                
Everyone could use a little more Beer.  [idle 14h]         
-------------------------------------------------------------------------

this is what i see in the lima bean (our mudlib's birth place)

you can see all ppl are idling, most several hours, 1 for 1 day
and 1 even got 1 week !. 
that is really a paradise of idlers :)
but anyway i find the help file about lima in that place are much more
than here. so if you guys have time, it's a good idea to go there and
have a look. read their post and browse the help files
or just idle there :)

the address is %^H_RED%^lima.mudlib.org%^RESET%^



---
作者: Fire
题目: the port is %^H_RED%^7878
日期: Mon Jul  5 07:43:36 1999
sorry, forget in last post :(


---
作者: Fire
题目: 一个真正有效的debug 工具。
日期: Mon Jul  5 08:15:28 1999
我刚刚在咱们MUD中发现一个非常有效的debug工具
具体帮助见：%^H_RED%^man dbx%^RESET%^


---
作者: Fire
题目: about zi
日期: Tue Jul  6 23:02:53 1999
we have two npc's zi are same,
both liu ba and sima wang's zi are 子初
so cause that bug
consider


---
作者: Row
题目: base&job
日期: Wed Jun 30 23:14:24 1999
在桃桃的努力下，终于物品系统的第一个基地和工作
完成了。
admire flee
addoil flee
我看了一下，发觉我们可以把开发新田(landlord)和
种植庄稼(farming) 这两个工作联系起来( 其实桃桃
说两者已经是有内在联系的) ，比如在种植庄稼的那
块地，它的肥沃程度取决于当地农业值的高低，而农
业值除了一小部分是由当地的NPC 、安定、人口等因
素所控制，主要还是靠开发新田来长( 请参先前的有
关将农业值等改为xxx/xxx的形式的帖子)。新田开发
得越多，农业值越高，能够种植庄稼的那块地的面积
就越大，也越肥沃，产值也就越高。

关于种植庄稼的工作，有些建议不知道能不能实现。
为了使此工作更加真实，利用我们现在的季节系统，
只有在春季及夏季可以种植庄稼( 春耕夏补，不知道
对不对？：P)，到了秋天，系统自动测试庄稼地状态
以确定收成。并且在种植庄稼的工作里多加上一些实
际性的工作，比如播种、除草等。而平时会发生一些
天灾人祸什么的，不能太频繁，需要玩家及时处理。

关于基地和工作希望大家多讨论，使其完善。


---
作者: Flute
题目: byebye all
日期: Wed Jun 30 11:40:30 1999
去也终须去，往又如何往，水起水落会有时,回看云深处

青山不该，绿水长流，咱们后会有期。
             水云国君水孩儿留笔 
            ＭＵＤ时间：三国志二百二十九年十二月上旬．


---
作者: Flee
题目: problem of start_busy
日期: Wed Jun 30 08:32:19 1999
if use user->modal_push( function, "xxx"),
then the function will take care of use's input,
start_busy is useless in this case

can fire fix this


---
作者: Flee
题目: first job of new stuff system 
日期: Wed Jun 30 08:36:49 1999
farm is ready now, all the files r under
/wiz/flee/farm/. to check it. first @.xx->add_job("do_farm")
then ask farmer about order, the job will start.
the most important part is the function do_reward which
is at the end of /wiz/flee/farm/farmer.c. the function
control the gold cost and food obtain. please check 
whether it is reasonable or not


---
作者: Flee
题目: some ideas
日期: Wed Jun 30 08:46:08 1999
在stuff_d中每一种资源以一个mapping记载拥有这种
资源的地区。farm:([ "area":(["changan":1000, ...
其中1000是一定时间内可以取得这种资源的最大值
具体数字有地区的相关因素决定，比如：农业开发
度，npc character，etc。由一个call_out来控制，如
果过度开发或从不开发，地区的对应数字会下降。
比如过度使用农场将减低地区的农业开发度。


---
作者: Flee
题目: why disable cmd save ?
日期: Thu Jul  1 06:55:19 1999
as title .


---
作者: Ice
题目: a little discovery
日期: Fri Jul  2 15:12:50 1999
maybe bcoz the guard is changed from char to obj, the cmd of
ask xianren about entry is useless, now can ask xianren about enter,
i have adjusted the help xuzijiang.


---
作者: Fire
题目: about maker
日期: Sun Jul 18 05:31:19 1999
> 店小二悄悄地附在你耳边说：您可来巧了，今天店里刚来了一批新鲜的野味。
list
你对店小二招了招手：店小二，让本将军看看你这儿都有些什么货。
店小二道：不知将军需要些什么？
物品名称             购买价          定做价          修改价
--------------------------------------------------------------------
馒头(mantou)         一两银子        --------        --------
剑南春(jnchun)       五两银子        --------        --------
地点： 【蓟城地图】
货物和对话应该有些关系吧:)


---
作者: Fire
题目: about bugao
日期: Sun Jul 18 04:38:58 1999
row's suggestion is good, but now not easy to create
a suitable basic level job. I have adjust the bugao
a little. 
1 the interval time chagnd form 30-60 to 60-120 second
2 dispalyer from 4 - 7 times
3 affect, 25 % no harm , 25 % drop 1 25 % increase 1 25 % incrase 2
  so the average harm is drop 0.25 per time and the total
  harm is about 1 - 1.7 safe drop per job
from 1 - 3 it become less harmful and less flood

when we have other suitable  job we can consider 
replace it, but now because the process of this job
is very easy, so it is suitable for basic level
players :)
addoil


---
作者: Row
题目: 关于布告
日期: Sat Jul 17 23:44:57 1999
现在的布告工作由于是当官以前的，所以似乎特别容
易，玩家开始抱怨这是一个鼓励dummies 的工作，而
且，十次的谣言和过快的频率造成了flood ，所以我
建议修改一下这个job ，比如将这个工作改成midjob，
然后在guard 处设计一下，guard 会随机抓住身上带
有布告的人（原本想设计一个伪装的技能，但可以先用
随机性来代替一下）。
又及：当官以前的job 最好是那些对自己地区有益但对
其他地区无害的工作，主要是增加自己的地区贡献和名望
等等，要不然，极其容易纵容dummies。
fire看看如何？


---
作者: Fire
题目: >about requirements of settle
日期: Sat Jul 17 05:38:38 1999
On Sat Jul 17 04:16:40 1999 Ice wrote post #630:
> now the standard of settle and be officer r almost the same, suggest to
> lower the settle requirement from 30, 30, 30 to 20, 20, 20.

the require for settle is not high 
20 20 and 20 is the average new login level :)

the problem is increase the requirement for become an officer

addoil


---
作者: Fire
题目: Virtual room system
日期: Fri Jul 16 12:42:02 1999
because i think the crash may caused by the number of room files
we have about 100 areas so i think we will have more than 2000
room files. 
now i change it to virtual file system. the main server is
"/a/area_server.c"
in order to get a list of an area's file
use : AREA(<a_id>)->get_room("list")
I will add some tools for the new room system, it is quite like
our daemons but a lilttle different. it will be more flexible
addoil :)


---
作者: Row
题目: war_idea.txt
日期: Fri Jul 16 04:20:16 1999
last post is saved in /wiz/row/txt/war_idea.txt


---
作者: Ice
题目: formula of safety after war
日期: Fri Jul 16 10:38:28 1999
被攻击城市：

被攻陷：  （400 - safety b4 war） / 10
防守成功：safety b4 war + 20

主攻城市：

攻击成功：no change
攻击失败：safety b4 war - 30

助攻城市：

攻击成功：no change
攻击失败：safety b4 war - 20

协防城市：

协防成功：safety b4 war + 10
协防失败：safety b4 war - 10



认栽了， slogan row, row said he would did it..:(


---
作者: Row
题目: >formula of safety after war
日期: Fri Jul 16 23:16:33 1999
maybe i forgot that...sorry ice..:P


---
作者: Ice
题目: emote on obj
日期: Sat Jul 17 03:42:28 1999
when emote target is obj:
$n -> 它
$R -> 宝物
$r -> 废物

* escape


---
作者: Fire
题目: >emote on obj
日期: Sat Jul 17 03:45:03 1999
On Sat Jul 17 03:42:28 1999 Ice wrote post #628:
> when emote target is obj:
> $n -> 它
> $R -> 宝物
> $r -> 废物
> 
> * escape

有道理
有道理


---
作者: Ice
题目: about requirements of settle
日期: Sat Jul 17 04:16:40 1999
now the standard of settle and be officer r almost the same, suggest to
lower the settle requirement from 30, 30, 30 to 20, 20, 20.


---
作者: Ice
题目: about info a <a_id>
日期: Sat Jul 17 07:26:20 1999
if this body is a king, he is supposed to see all available info
of each city in his nation


---
作者: Fire
题目: about zuo ci's job
日期: Sat Jul 17 07:56:40 1999
I have updated zuo ci's job to fit in
the new area system :)


---
作者: Fire
题目: 难见的长命，看来玩家越多越不稳定。:(
日期: Sat Jul 17 20:21:29 1999
who
※ 三国 ※  （当地时间：九十九年七月十七日下午八时十八分）
─＝ID列表＝─  目前总人数：21人
─────────────────────────────────────
小子(xiaozi)       小白(xiaobai)      闭月(biyue)        无虑(fearless)
小根(wurzeln)      兔子(rabbit)       草包师爷(cbshiye)  爪蛙(java)
孤帆(boat)         爱赛特(eyesight)   玄冰(ice)          星云(lsk)
烈火(fire)         呆头鹅(daitoue)    无双(loney)        江山美人(reverie)
小天(lgun)         王玲(wangling)     无忧(carefree)     婷儿(richel)
cpu
CPU usage: 6.32%
Mud status is
Sentences:                            48      768
Objects:                            6265  3254280
Prog blocks:                         805  1290352
<Array statistics disabled, no information available>
Mappings:                          93237  8126476
Mappings(nodes):                  168267
Interactives:                         21   133140
Obj table overhead:                 6004   432028
call out:                            220     6160 (current length 102)
                                         --------
Total:                                   13243204
load average:
2.82 cmds/s, 6.05 comp lines/s
物品数量：
@sizeof(objects())
5924
> time
当地时间                九十九年七月十七日下午八时十七分
三国启动于              九十九年七月十七日上午六时二十四分
本次运行时间为          十三小时五十三分五十四秒钟


---
作者: Row
题目: 战争，永远的主题。
日期: Fri Jul 16 04:16:42 1999
以下观点主要为玄冰提供，阿洛稍做修改。

                       战争攻方
                                 
                       国家宣战 N-->cannot cmd war
                          │Y
                   进攻城市召开会议
            ┌──────┼──────┐
         安定90       钱粮可支持   训练度和士气
            │        现有士兵数   都超过60。
            │        一年以上。        │
            └──────┼──────┘
                         Y│N--> cannot cmd war
            ┌──────┼──────┐
        目标城市邻近   单独出兵    目标城市邻近
        有本国城池，      │       有盟国城池，
        共同进攻。        │       邀请共同进攻
            │            │       盟国Y│N-->非盟国，over
        助攻城市会议      │       助攻城市会议
      ┌──┴──┐      │      ┌──┴──┐
 安定90   训练士气超过60  │   安定90    训练士气超过60
      └──┬──┘      │      └──┬──┘
           Y│N, over     │           Y│N,over
      cmd assistwar    cmd war     cmd assistwar
            ├──────┼──────┤
           分兵     分兵，带粮，金     分兵
      over N│Y          Y│N,all over.Y│N,assist over
            └──────┼──────┘
         进入战场后全部消耗主战部队的粮食、金
                          │
                          战
        ┌────────┴────────┐
      攻方胜                       攻方败或主攻主将撤退
主战部队占领城池，其余         所有未被歼灭之部队撤回原驻地，
助攻部队撤回原驻地，战         主战城市安定下降，助攻城市安定
后被占领区安定为15。           亦然，惩罚减半。
        └────────┬────────┘
                       war over

一、宣战：国君可以在pos 里设置多少时间内不得战争。如果国君是玩
    家并且在线，地区会议同意后再征求国君的意见，如果不回答就默
    认不同意；如果不在线则根据pos 的设定。如果为NPC 国就是国师
    的事了。
二、带兵：限制官员带兵的数量，公式可以这样定：
    主要修养*50+地方官位等级*50+国家官位等级*50+特殊称号系数*50
    等级后乘以的数字可以改动，主要是看修养的高低，官位系数是为
    了能区别强弱，由于官位的升迁是有严格要求的，所以也不会出现
    太离谱的情况。主要修养是这样的：文官取兵法修养，武官取武学
    修养，这样就可以令玩家有目的的发展，国君分派官位也更有方向
    性了。
三、携带军粮和金：相应提高战争的难度与真实性，建议战争必需携带
    军粮、金或物资(可选，特殊用途)，每五分钟消耗的粮食、金，具
    体数量比例待定。金和物资可以用于计策，每施一计需要花钱，有
    些计策需要消耗物资，比如：落石需要带圆石，这里的物资是具体
    的。钱粮一旦消耗殆尽，每五分钟士兵逃跑，比例待定，最好不要
    下降士气，因若在战场士气为零就死翘翘了。
    另：针对与每30秒降一点士气的问题，当然在战后应该恢复，战胜
    方还应增加相当的士气，是否可以在战争时加一些可以(暂时)增加
    士气的计策，比如鼓舞等等。如果所有的设定都是为了给玩家增加
    难度的话，可能会使他们丧失信心，所以可以适当正面抵消一下。
四、共同进攻：只可以要求邻近目标地区的附合出兵条件的同国地区共
    同进攻，待主战地区分兵完毕之后，被邀请地区再自动召开会议，
    决定是否出兵，谁领兵等等(拉开时间差)。
五、若目标城市周围有盟国地区时，可要求盟国助攻，将送去一定数量
    的金、粮、物资、或特殊物品。盟国收到邀请后召开会议讨论，若
    达不到出兵要求则直接拒绝，若通过则出兵。
六、主战部队携带粮、金、物资应该有上限，以可以维持战争一小时为
    限(应该设定若战争到一小时不分胜负，则改日再战)。若无上限，
    则富庶的地区出兵可横扫全国，因为可以不停开仓赈粮，固定上限
    则限制出兵数目，故有此议。
七、加入探敌：现有的cmd warinfo 能提供敌友军几乎所有状况，包括
    所在区域，士兵数，主将数目等，与真实战争不符，也降低了战争
    的难度。因此，可在战争中增加一个刺探敌情的命令：cmd scout。
    派一支小分队出去刺探( 考虑用个人的亲兵，呵呵，兄弟们也上战
    场了，一次十人，失败则减去，成功则恢复。无人指挥 )，其实是
    随机的，如：探子遭遇敌军，被全部歼灭。或，探子巧妙迂回，探
    得敌军情报。每次该指令将消耗一定的金，成功机率以所有参战官
    员的天赋为标准，探得的情报可以保持十五分钟。只有探敌成功才
    能用cmd warinfo 看敌我情报，以及使用cmd warmap看部队方位，
    不然，只能看见友军方位，敌军只有进入视野后才能看见，也就是
    在房间描述里。另外，探敌只能五分钟一次，若上次成功则必须等
    失效后才能再探。
八、攻方战胜后，如果能在短期内达到安定90，再度出兵的条件似乎不
    太正常，所以各项能够大幅度提高安定的建议或工作应该重新考虑
    下：
    税率：限定每次调整幅度不可超过20，另外可设成税率每个月只能
          调整一次。
    探访：没有问题。
    开仓：没有问题。
    巡逻：没有问题。
    裁军：裁军令士兵解甲归田，所裁部分纳入当地人口，可增加地方
          安定。

                       战争防守

         邻近敌国城市宣战，立即召开紧急防御会议
            ┌──────┼──────┐
        本城市邻近     单独防守    本城市邻近
        有本国城池，      │       有盟国城池，
        共同防守。        │       请求共同防守
            │            │       盟国Y│N非盟国，over
        协防城市会议      │       协防城市会议
      ┌──┴──┐      │      ┌──┴──┐
 安定60   训练士气超过60  │   安定60    训练士气超过60
      └──┬──┘      │      └──┬──┘
           Y│N, over     │           Y│N,over
            ├──────┼──────┤
           分兵          分兵          分兵
      over N│Y           │           Y│N,assist over
            └──────┼──────┘
     进入战场，所有防守部队消耗该城市所拥有的钱粮
              ┌─────┴─────┐ 
      主力防守部队在           协防部队出现方式与
      主帅帐或城池内           进攻部队类似，随机
      进入战场。               分布在野外。
              └─────┬─────┘
                          战
              ┌─────┴─────┐ 
     防守成功，安定上升。  防守失败，协防部队撤回原驻地
                           协防城市安定不变。
              └─────┬─────┘
                       war over

一、若防守地区周围有本国地区，决定请求协防，分兵完毕后，协防
    地区自动召开会议。若达到出兵条件则参加协防。
二、主力防守部队的分兵需要作部分改动：
    1、 设定最小带兵量，例如为部队总数的20% ，民兵数量从安定
        和当地人口推算出来。这样可以防止某些大米们在防守时作
        弊只带极少量部队防守，因为在防守会议上系统自动设定在
        线的官员统领部队。
    2、 不必所有官员全部参战，现在似乎如果是 NPC领军的话，所
        在线或NPC官员全部编进军团建制里面。
三、城池攻防战：建议在地区内加上防御度的设定，则防守部队可以
    地区的地形上得益。并且将城墙设置为实质阻挡物，防御度便是
    地区防御度，可在平时增加修筑城墙的工作，上限为200 。现在
    有两种想法，一是将城墙设置成防守方可以任意穿越或停留，攻
    方则必须将城墙的防守度降为0 才能通过，这样会相应提高防守
    的质量，而防守方在城墙上可以直接攻击攻方，这个想法的优点
    是编程比较简单，但不会耐玩；二是编程可能比较复杂的，一如
    San3和San4，城墙和城门为高于平地的阻挡物，防守方从内侧登
    上城墙后，将不能直接出城和以直接攻击的方式进行攻击，可以
    用弓箭或落石计，其他需要接敌或需要在同一平面上的计谋亦不
    能使用，而且只能从内侧才能退下城墙，防守方通过城墙可以用
    cmd entercity，或者由友军部队从内侧cmd opendoor ，才能进
    入；相对而言，攻方部队可以选择将一处城门击破，然后从该缺
    口进入，到达另一城门内侧，也使用cmd opendoor来开城放入友
    军部队，这样会增加战争的对抗性和协作性。当然如果是野战的
    话就不必考虑了。
四、俘虏的问题：目前的战争基本上是败了就当贤人，没有俘虏这一
    概念，但因为已经有了牢房，这俘虏的问题应该可以实现。无论
    攻防，被击溃的军团将领都有机会成为敌方俘虏，然后被俘的将
    领将在牢房里呆上一段时间。然后敌国可以劝降，本国可以赎回
    俘虏，但监期一满，则该俘虏成为闲人。

                     非战争直接相关项

结盟：因为现在的发展趋势已经主要成为玩家国君的国家，所以如果
      以敌对度或友好度来衡量似乎是没有用的，建议先将结盟设置
      成不能朝令夕改的制度，如若结了盟，则不能互相宣战，可以
      作战，当然，因为是玩家国君，可以随时解约，而我想我们并
      不希望盟约成为儿戏，那么就可以设置一些惩罚。
      譬如，结盟上限为10年，下限为1 年，如果有一方在同盟期间
      解约，则全国安定下降5%，所有将领官员忠诚度下降5%，所有
      军队士气下降10等等。关于敌对度或友好度，可以在进行破坏
      工作时体现出来，如果官员申请有关散布谣言、策反、破坏、
      间谍、纵火等等的工作，高敌对度的国家将会成为优先考虑对
      象，敌对度和友好度判定由该国官员被捕次数或者由该国官员
      的平均与敌国关系来作为标准待决。
      进贡或援助近期内该不设为考虑范围，因为国库功能尚未完善，
      运输亦然，所以难免以期两个友好国家之间互相狂进贡，关系
      奇好，但大家只是把钱粮运来运去，什么损失也没有。

天灾：每个历史时期都有天灾，尤其三国游戏里，几乎没一代没有天
      灾的，所以应该加入天灾以影响城市的指数。
      天灾有洪水、蝗虫、瘟疫、飓风等等，各种损失都不同，唯一
      相同的就是一定会影响当地安定，而如果在天灾的情况下做某
      些加强安定的工作，效果可能加倍或减半。
人祸：现在的土匪们太小规模了，缺乏有组织的领导，群龙无首，还
      停留在小打小闹的阶段，需要我们大力发展壮大。首先，我们
      可以分开流匪和悍匪两类，流匪则是我们曾经有的土匪和黄巾
      军，大城无害，小城遭殃；悍匪则是我们应大力引的有名有姓
      的好同志，如张角、程远志，还有孟获同志严格来说应该是名
      好土匪，这一类的悍匪手握重兵，随时可能抢粮草，稀里糊涂
      加入某些战役，将某些久不治理的城市洗劫一空等等，总之一
      句话来说，土匪们将对三国的贡献巨大。

破坏工作：现在的破坏基本是没有目的，没有效果的，因为根本找不
          到具体的指向，纯粹为个人指标而努力，建议作些区域限
          制，譬如，国君可指定向某些州进行破坏，当然，可以在
          国君专用的menu里面悄悄设置，国君总有一点点点特权。
          以下是一些破坏工作：
    谍报：现在基本没有问题。
    煽动：降低敌国敌城的安定，无疑是为进攻或防止敌国进攻而做，
          同样需要目标性。
    策反：没有问题。
    新的想法：
    谣言：从太守处领命，从而出发到目标城市到处造谣，遇到ppl就
          造谣，遇到officer 也造谣，可以设置成如果对ppl造谣成
          功，则当该城官员探访居民时失败的机率增加，对officer
          造谣成功，则会延迟NPC捐钱弥补自己不忠的时间，从而使
          敌城人才流失以致凋零。
    纵火：纵火降安定、降城市指数、降钱粮物资。
    破坏：破坏是尽量破坏敌国的城防度，以及说不定可以顺手牵羊偷
          滚石檑木回来。
    赎俘：召开地方会议，派出官员与俘虏所在城太守交涉。

其他一些有关的系统：
物品系统：将是一个振奋人心的新系统，addoil flee！
运输系统：需要讨论。


---
作者: Fire
题目: %^H_RED%^The real bug
日期: Fri Jul 16 04:06:24 1999
%^H_RED%^Too many open files
we need reduce the number of files in our mud.

addoil :)


---
作者: Row
题目: not crash?
日期: Thu Jul 15 21:35:15 1999
本次运行时间为          十二小时二十七分三十三秒钟

does that indicates the train cause the crash?


---
作者: Fire
题目: >about recruit
日期: Wed Jul 14 19:21:20 1999
On Wed Jul 14 18:15:36 1999 Ice wrote post #612:
> hmm, recruit 1 ppl in city will drop 1 safety, is that too much?
> or we can use drop more population instead of drop safety?
> like 1% drop of current population, bcoz most ppl recruit in small city,
> but no one manage in small city, the safety will drop to 0 in no time.

that is a point, will set can't recruit if safety small than
20 and population less than 500

is this ok ?


---
作者: Ice
题目: about recruit
日期: Wed Jul 14 18:15:36 1999
hmm, recruit 1 ppl in city will drop 1 safety, is that too much?
or we can use drop more population instead of drop safety?
like 1% drop of current population, bcoz most ppl recruit in small city,
but no one manage in small city, the safety will drop to 0 in no time.


---
作者: Ice
题目: about morale after war
日期: Tue Jul 13 23:48:36 1999
now war will drop morale every 30 secs, it's fine, but after
the war wins, system adds only 20 morale on the remaining
morale after war, it sounds not so convenience.

suggest to change to this way:
if war wins, the winner side will get morale as morale b4 war + 20
bcoz nowadays train is too hard to add, one train adds only 4-5 points
even tasks all finished, or we can make the train add morale little bit
faster ....:P


---
作者: Ice
题目: about chat to npc and obj
日期: Tue Jul 13 22:21:51 1999
I think if set to can chat * with NPC or obj in the same room
will be better, otherwise it's kind of confusing, and ppl may
use it for some other usage

【闲聊】吃豆豆一脚踢在丹阳小伙的屁屁上，印出一个清楚的鞋印。
【闲聊】吃豆豆一脚踢在淮阴闲人的屁屁上，印出一个清楚的鞋印。
【闲聊】无忧无聊地用手指戳了戳壶关居民，可他象根木头一样毫无反应。
【闲聊】亮眼睛(smiling)：all screen messy now

so fire pls consider to change it, dun make it for unproper usage bah

like "set notell" bah..:P

btw: make a vote system to control flooding bah, and add a setting
like "set notell" bah..:P

oh, they poke for recruiting..:P


---
作者: Fire
题目: very serious bug
日期: Wed Jul 14 07:32:31 1999
today, when i login i find the system is in the mess
a very serious bug come
it has many unusually things
1 system will give error messge every 1 second
  the screen is full of errors, so i have to
  turn off the errors channel
2 when i use who i find two players without id
─────────────────────────────────────
小白(xiaobai)      风翔四海(aeolus)   雷动九天(0)        中文(gb)
一拉(yila)         玩玩(hotdog)       阿凡(afan)         男狼(dun)
真君子(zhjz)       飞鹰(ying)         拜访(dubai)        兔子(rabbit)
烈火(fire)         云飞扬(roro)       落雁(luoyan)       神鹰(zhiwei)
梦幻家(sabah)      逍遥天下(wslu)     凉粉草(cool)       子龙(zlong)
兰特(zxcs)         萧杰(xiaojie)      小子(xiaozi)       
白开心(hahaha)     两个(two)          如花(pcc)          
月神(luna)         英名(pcm)          惘然(remorse)      

then some time later, one is disappeard but still one player without id
3 all system call can't work
 I can't use cmd such as cpu, dbxwhere and even update
 all give full screen error message
4 but players can continue play, strange

5 can't shutdown

6 at last I have to login the unix and kill the process
7 then all information in channel.o gone
  we still have all the channel but information gone
  in this case, mean every can listen wiz and announce
 if they use chan wiz /on
the whole process is very strange, i think
our system should crash, but so wrong, even can't crash
. . . . . .

let's keep an eye on the system and catch that mysterious
bug asap. 


---
作者: Fire
题目: about the crash
日期: Wed Jul 14 21:11:57 1999
the unreason crash is a real headache for this mud
now i use day_d to create a log for this mud
the log file is in /data/daemons/daylog
it will record some system information every 4 mins
hope it can help to catch the reason of crashing
any part is let's try to disable some function
to test if they caused the crash

I think war system is suspected and xianren's job
  also have a little suspected. so let's begin from
  this two system, first will disable xianren for one
 day if still crash, then disable trian, war for one or two days
 if still crash, then will try to disable other systems
 until find the right reason
 and do your guys have any suggestions ?
 
addoil :)


---
作者: Ice
题目: agree fire
日期: Wed Jul 14 21:15:58 1999
as title


---
作者: Row
题目: >about the crash
日期: Wed Jul 14 21:47:20 1999
agree fire, the crash for no reason really frastrated
everybody, we need to clear it...
addoil:)


---
作者: Ice
题目: about crash
日期: Wed Jul 14 22:05:23 1999
last time tset asked me to warn stefan that the "^M" at the end
of every line caused crash, and asked stefan find a way to remove them.
take it as reference bah
addoil ...:)


---
作者: Ice
题目: introduction of fate system
日期: Thu Jul 15 01:06:15 1999
I think the fate system can give a good control of where will
have disaster, fortune, or even bandit instead of totally random
spreadout.

pls more /wiz/ice/txt/fate.txt to check it out.

ps: it might be different of the real fate in life, i know only little
about the real one, just took some info that may help us out, so don't
show it out, * blush, * escape


---
作者: Row
题目: >not crash?
日期: Thu Jul 15 21:44:40 1999
On Thu Jul 15 21:35:15 1999 Row wrote post #620:
> 本次运行时间为          十二小时二十七分三十三秒钟
> 
> does that indicates the train cause the crash?

grrr...several mins later, crash again...seems
there is other reason....


---
作者: Fire
题目: about the black list
日期: Tue Jul 13 09:34:47 1999
i find a bug in the pos for black list
i fixed it, hope it is because that cause the problem of
disappear of blacklist


---
作者: Fire
题目: about ice's suggestion
日期: Mon Jul 12 22:42:02 1999
ice's suggestion is good in some aspect,
but i still prefer make player guess who
is spy by the players action in the mud
rather than information other than the game itself

so i against his suggestion :)

now the result is 2:1 need 1 or two vote to
give final decision
addoil


---
作者: Fire
题目: goto 命令更新了
日期: Mon Jul 12 10:05:50 1999
现在goto可到以下地方：
1 goto <player>
2 goto <char> 例如：goto diao chan
3 goto <file name of room>
4 goto <obj_id> 例如：goto luzi (到有炉子的房间)
goto han di 到汉帝的宫殿等。


---
作者: Fire
题目: %^H_RED%^请一定注意%^RESET%^
日期: Mon Jul 12 08:54:05 1999
因为我们现在工作WIZ较多。
许多文件大家都可能修改，
所以在update文件前，一定要先download
特别是event,daemons,modules,jobs等。
%^H_RED%^切记，切记。


---
作者: Fire
题目: 关于ev_lincome
日期: Mon Jul 12 08:11:28 1999
系统的一打开销就是每月计算地区国家收入，
给官兵发晌，官员给亲兵发晌。
过去的作法是一口气全算完，这样经常会出现
too long eval错误。
现在采用call_out来控制，一个地区一个地区
地计算，把过去要求一瞬间完成的工作延续到
六到七分钟的时间，缓冲了系统瞬间计算压力
希望可以使系统更加稳定。

另外在国家收入中，国家只受金，地区则受金，粮和物资。



---
作者: Ice
题目: suggestion of king withdrawals
日期: Sun Jul 11 15:50:49 1999
add a restriction that if the area's safety is <30, cannot withdraw
gold from reserve.  however, king is supposed to withdraw gold
anytime, but it can related the king's private asset with his city's
status more tightly.


---
作者: Ice
题目: a sudden idea about spy job
日期: Sun Jul 11 19:17:21 1999
since nowadays spy job and cmd catch job is not hot, got an
idea about changing spy job:

when get the area of spy job, add a 50% random chance to spy
the neighbourhood cities, might be more competitive.

btw: I think we need add a time limit of cmd spy info, as i was
player, when i planned to take over changan, i got a chance to do
spy there, then not report back to my taishou, then i kept the most
updated spy info until i do another or report after 2 weeks, got to
change it.....:PPP  hmm.......how about 30 mins....:)


---
作者: Flee
题目: >> about help cgi
日期: Wed Jul 21 00:47:41 1999
i have modified it, adding backgroup image
and replace all the ansi color code to html
color code, all use red 
too lazy to check all the correspoding color leh .. ^_^


---
作者: Ice
题目: about marriage
日期: Mon Jul 19 08:05:26 1999
I think some words need to be 润色.:P, and try to make it fun for marriage
addoil tit


---
作者: Fire
题目: about marriage
日期: Mon Jul 19 08:02:53 1999
ice's marriage system sounds good
can tit finish it ?
we will all help you in some way
addoil tit


---
作者: Ice
题目: 人生乐事：金榜题名时。。。洞房花烛夜。。。
日期: Mon Jul 19 07:39:35 1999
结婚要求：
一男，一女
年龄超过16岁，未婚
男方声望超过10000

结婚地点、主婚人：
吴郡->甘露寺->乔国老

结婚证物：
戒指->subtype：hands
（all objs in this subtype is lv 0）

结婚准备：
购买戒指：在某些珠宝店内可以买到，但不提供order服务

结婚过程：
到甘露寺，找到乔国老；
ask qiao guolao about zhuhun
（check if both party meet requirement：gender, age, marital
status,ring in both body）

//if same gender
乔国老勃然大怒：你们两个来搅局的是吧，来人哪，给我抓起来！
乔国老的随从一拥而上，把烈火和阿洛捆了起来，送进了当地大牢。

//if age not qualify
乔国老「嘿嘿」一笑：你们俩还小哪，来日方长。。。。。。
乔国老轻轻拍了拍烈火和阿洛的头，说道：等你们长大再来吧。

//if one party is married
乔国老对烈火「哼」了一声：想重婚？门都没有！抓起来！
乔国老的随从一拥而上，把烈火捆了起来，送进了当地大牢。
乔国老轻声地安慰阿洛：别急，别急，以后还能找到更好的。。。

//if no rings in both body
乔国老「嗯」了一声，一副欲言又止的模样：你们还有点东西没准备好吧？
乔国老望着烈火和阿洛幽幽地叹了一口气：连戒指都没有就想结婚？

->all qualified
乔国老点点头：嗯，好，那我问你们，你们可是真心相爱？
fire：answer yes to qiao guolao
烈火一边望着阿洛，一边猛向乔国老点头：是，是，是。。。
row：answer yes to qiao guolao
阿洛羞红了脸，轻轻地点了点头。
//last chance to regret, if 30 secs no response
乔国老叹了口气说道：唉，看来你们还是。。。。。。
烈火和阿洛对望了一眼，耸了耸肩，各自走开了。

->marriage
乔国老哈哈一笑：好，好，好！
乔国老正色向烈火问道：烈火，你可愿娶阿洛为妻？
烈火使劲地点头：愿意，我愿意！
乔国老又向阿洛问道：阿洛，你可愿嫁与烈火？
阿洛红着脸，望了烈火一眼，说道：我愿意！
乔国老一拍大腿：好！！！
【闲聊】乔国老：烈火与阿洛正式结为夫妻（blah blah, sb add it）
//underground actions
set ring on each body as ordered obj, rings cannot order or fix from makers。

->follow-ups
你换上了一身大红蟒袍，在喜娘的引领下进入一间喜堂。
（virtual room->xitang）
//look（hmm, sb can think of some better desc?）
    这里举行婚礼专用的喜堂，堂内张灯结彩，台上高点红烛，一些
歌女舞娘正随乐而舞，四五个小丫鬟麻利的上菜送酒。周围坐满了前
来祝贺的客人，热闹非凡。

你被几个丫鬟拉到厢房，换上了华丽的凤冠霞帔，铺上了盖头，接着
被领到了一间人声嘈杂的屋里。
//look
你忍不住想掀开盖头看看周围，手刚举起来，忽然被一只温暖的手握住了。

->拜堂
在一旁的喜娘高声宣唱道：一拜天地！
（bai tiandi）
烈火和阿洛朝外跪地拜了一拜。

//male id action only, if female id want to act, will be shown this
新郎还没有动静呢，你急什么？

在一旁的喜娘高声宣唱道：二拜高堂！
（bai gaotang）
烈火和阿洛又齐齐拜了一拜。

在一旁的喜娘高声宣唱道：夫妻对拜！
（duibai）
烈火和阿洛相对拜了一拜。

在一旁的喜娘最后高声宣唱道：入洞房！

->洞房
烈火和阿洛在丫鬟的引领下进到了洞房。
（virtual room->dongfang）
//look
    丫鬟们和喜娘都已经退了出去，而且顺手带上了门，屋里只有一
对大红烛发出轻微「噼啪」的响声。屋子中间是一张小圆桌，上面摆
着一壶酒和两个小酒杯。屋子的最里面是一张龙凤大床，大红的帐子
上挂着大大的“喜喜”字。

掀盖头
烈火傻笑着轻轻掀开了阿洛的盖头，轻轻地在阿洛红红的脸蛋上亲了一下。

合欢酒：
（drink hehuan）
//male id action only, if female id want to act, will be shown this
新郎还没有动静呢，你急什么？

烈火倒了两杯酒，轻柔地在阿洛耳边说道：娘子，我们一起干了这杯酒吧。
阿洛「嘤咛」一声，羞红了脸，接过酒杯，端在右手，与烈火右手转了个钩，
彼此的额头轻轻抵着，一起喝下了合欢酒。

圆房：
（yuan fang）
烈火轻轻地抱起阿洛。。。。。。
一夜无话。。。。。。。。。。。
//30 secs busy time

翌日：
//force out of dongfang

（if disconnected or no response, process will be cancelled in 30 secs
  but marital status will be changed to married）
（in each step, will display a hint that how to do next）

how do u guys think about it?



---
作者: Fire
题目: virtual room's two use macro
日期: Mon Jul 19 07:39:20 1999
virtual rooms are more flexible, here has two use
macro used to design rooms
1 GETHERE(<what>)
  例如：
  @GETHERE("b") 查当地的brief
  @GETHERE("") 查当地房间的所以甚至
  @GETHERE("o") 查当地房间的物品设置
  @GETHERE("e") 查当地房间的出口设置
2 SETHERE(<para>,<value>)
  例如： @SETHERE("b","%^YELLOW%^小路%^RESET%^")  把当前房间的short
设成%^YELLOW%^小路%^RESET%^
 @SETHERE("o" , ([ "/sgdomain/modules/m_board.c" : ({ 1,
"%^H_GREEN%^新手指南%^RESET%^","newbie"}), "/sgdomain/area/guan/huay
in/npc/shuijing.c" : 1 ,]) )
 加水境和留言板

addoil


---
作者: Fire
题目: >re: tit
日期: Mon Jul 19 06:41:15 1999
On Mon Jul 19 06:22:29 1999 Ice wrote post #647:
> hmm, about war movements, we have troops upgrade projects ahead,
> conditions will be changed after it's implemented
> 
> about emote, it's different from LPMUD, emotes r devided into 2 catagories:
> no targe, and with target
> 
> hmm, about the sentences of rumor, i think we can adjust it later
> now we need to debug and develop some urgent projects

in fact, we have designed the semote like other mud before
no target, to others and to self. but, stefan change it back
sigh 


---
作者: Ice
题目: re: tit
日期: Mon Jul 19 06:22:29 1999
hmm, about war movements, we have troops upgrade projects ahead,
conditions will be changed after it's implemented

about emote, it's different from LPMUD, emotes r devided into 2 catagories:
no targe, and with target

hmm, about the sentences of rumor, i think we can adjust it later
now we need to debug and develop some urgent projects


---
作者: Tit
题目: can change this rumor?
日期: Mon Jul 19 05:52:16 1999
疽パ浴磕橙耍喊卓姆獍卓奈裆５奶亍change to 
*** king take over *** taishou.
pls consider.


---
作者: Fire
题目: about player's number
日期: Mon Jul 19 01:49:35 1999
when the number of players more than 50
then if use update here
will have bugs
seem 50 is a key point


---
作者: Row
题目: >about player's number
日期: Mon Jul 19 01:56:35 1999
that is aweful, how to solve it?


---
作者: Tit
题目: can change this rumor?
日期: Mon Jul 19 04:29:16 1999
【谣言】某人：白开心将白开心派到丹阳。
This sounds not quite nice.
can change this to 
*** king "chu xun" or "xun shi" to somewhere?
pls consider.


---
作者: Tit
题目: what emote!
日期: Mon Jul 19 05:06:35 1999
chat* kick tit
鞠辛摹磕愕闹形囊唤盘咴谒约旱钠ㄆㄉ希〕鲆桓銮宄男　it seems not reasonable bah
kick 自己的屁屁出一个清楚的鞋印?
may change to something else?
like 鞠辛摹刻煸埔唤畔蚩罩刑呷ィ恍⌒呐ち俗约旱慕拧just like kick nothing
pls consider.


---
作者: Tit
题目: about move points
日期: Mon Jul 19 05:17:52 1999
can we make that with the trainnig, the max movepoint of the troop can 
increase. some special area will cost a lot move points. maybe greater than 
the usually footman's max movepoints. so players have to train a lot 
increase movepoint or change to horseman to decrease movepoint cost.
just a suggestion.
pls consider.


---
作者: Tit
题目: about base&job
日期: Tue Jul 20 02:52:39 1999
开发新田 need some 人口 to do so.
so as a part of the 开发新田 job, can let player to find people to do so 
at first?
just like sanguo caocao 's "tun tian"?
and can be divide as "jun tun" and "ming tun".
just a idea, pls consider.


---
作者: Ice
题目: about 税率与民生
日期: Tue Jul 20 04:13:20 1999
现在的城市在苛捐杂税（10 taxnation,70 taxlocal）之下依然蓬勃
发展，现在开放国家会议，在国税可调的情况下，恐怕这种现象会愈
演愈烈。建议设置如下：

1、 国税与地税之和不大于100%，以为合理。
2、 现地税调整幅度为10-70%，建议国税为 5-50%，国税上调一点则
    全国安定下降五点，下调一点则全国安定上升一点。
3、 如果一个地区的税率之和为100，人口每月下降一半；
    大于80，人口每月下降四分之一；
    小于80大于60，人口每月下降十分之一；
    小于60大于40，人口稳定无增长或小幅度增长；
    小于40大于15，人口正常增长。




---
作者: Row
题目: about cmd job stat
日期: Sun Jul 18 22:05:36 1999
should we make cmd job stat the wiz-only cmd?
seems it provides too much info to player lah.


---
作者: Row
题目: yu ji job is ok now
日期: Sun Jul 18 22:11:08 1999
test ok


---
作者: Ice
题目: suggestion about non-navy troops' loss in water
日期: Sat Jul 24 16:21:34 1999
1. if step in water, each step will lose 1/50,
2. if stay in the same water room more than 5 secs, lose 1/20 every 5 secs.


---
作者: Ice
题目: >about train
日期: Sat Jul 24 16:07:48 1999
let me take an example:

now i am officer in longxi, there r 5 officers in the meeting(4 npc),
and i cmd train, only 1 npc cmd me. it means that i can lead at most
9k troops,
if player don't login dummies, they cannot even hold a 12-task
train, so they have
to login dummies to cmd me then quit them as npc, i dun think it's a good way
to encourage player to do train jobs, i have the following suggestion:

1. if we r not willing to make all the officer in the meeting
involve in the train,
   (though I think it's reasonable.:P at most 10 officers in a
meeting, not too much)
   we can make the NPC in wuguan position must cmd me if he attends
the meeting,
   it's their job...:P

2. since commando's train and morale r fixed, I dun think it's
necessary to let
   them train, however, they will attend if it's a bandit attack or
war, but seems
   no need appear in train.

a good example of large troops r impossible to train with is
luoyang, it has 80k,
but each traini can at most take 20k, after averaged, add only 1
traini and morale
each train, which discourage players.


---
作者: Fire
题目: about maker and obj
日期: Fri Jul 23 10:04:08 1999
for a certain obj, if we want to find who can make it
the right function is OBJ_D->get_obj_maker(<obj id>)
now i add a static mapping for that, so it is very quick
but for later dynamical obj system, may need a update function


---
作者: Fire
题目: 角色系统的更新
日期: Thu Jul 22 11:03:38 1999
1 角色所处房间的更新由move中的hook完成，比原来在smartmove中加code
  的方法更加可靠。
2 所有的npc角色由虚拟服务器/sgdomain/modules/char_server(CHAR_SERVER)
  产生，这样会使得角色身体的搜寻更加快速可靠。缺点是没有办法使用
  children(<body file>)的方法得到活动角色清单。但从系统的可靠性来说
  这样的改进大大值得。由此更新可能会引起一系列BUG，我已经修复了boy,
  guy中的一些相关BUG，但是由于不能用children来查询，charheart_d 将
  无法工作，现在的这些角色将无法自动活动。(这个BUG回头修理。)，另外
  肯定还会有许多其他相关BUG，请注意观察汇报，以便及时修理。
 


---
作者: Ice
题目: an idea about ring of marriage
日期: Wed Jul 21 16:08:20 1999
we provide the name of rings, only brief long and wear/rm msg,
after ppl buy the rings, they can write their own desc and wear/rm msg
b4 going to marriage, and after the marriage is processed, it's set.

* smirk


---
作者: Tit
题目: today many players war a each other to get anding for the starting cities
日期: Thu Jul 22 03:15:57 1999
today many players war each other to get anding for the big cities and get
some other rewards.
e.g. changsha and chaisang war chibi many times.
e.g. changsha and chaisang war chibi many times.
war is not a easy thing, i beleive.
so i suggest that whoever start a war, attacker side and defence side should
both
drop anding. just like Civillization II.
of course if war win, get back some anding, but in total, should drop anding
for both side.
of course if war win, get back some anding, but in total, should drop anding
for both side.
e.g.
attacker win drop anding 20
attacker lose drop anding 50
defencer win anding donot change.
defencer lose anding drop to 30

this is just to avoid the "bug". just a suggestion. pls consider.


---
作者: Row
题目: >today many players war a each other to get anding for the starting cities
日期: Thu Jul 22 03:19:35 1999
agree tit.
and player only use 1 soldier to attack intend to add morale or train of
the target area, so we should set a lower limit of troop number of war.


---
作者: Tit
题目: or give more punishment to loser side
日期: Thu Jul 22 03:26:17 1999
continue with last post
when attacker lose one war, just like being pked in other mud.
everyone on line attend the war drop 1 lel skills.
and players in the same country donot attend the war, but one line drop half
lel skills.
defending side lose a war, attend war on line players drop 1 lel skills. not
attend the war drop half lel skills.
or for defending side punishment half of above, that is:
on line players and attend the war lose, drop half lel skills.
not attend the war drop 1/4 lel skills.
just let players be more careful when they want to war.
just a suggestion, pls consider.


---
作者: Ice
题目: >>today many players war a each other to get anding for the starting cities
日期: Thu Jul 22 04:15:07 1999
agree


---
作者: Ice
题目: suggestion about recent changes of war
日期: Thu Jul 22 18:26:04 1999
1、 战争进入时间

现在的战争进入时间相对的不合理，攻守双方兵力相当，防守方会比
进攻方晚进入战场，造成攻方有利的条件。建议将进攻方分完兵进入
战场的时间延迟一分钟（saying that 部队正在行军前往敌城 or 正
在进入战场），以实现公平的原则。或者用另一种方法，如果其中一
方未能进入战场，另一方则显示「正在进入战场」（防守方如果迟迟
不分兵完毕，系统会自动将兵力分配完毕，以防止防守方故意延迟），
这样为以后的支援和协防作一些铺垫，只有主攻和主防的部队首先进
场，所有辅助部队只有在会议通过同意派兵支援之后才开始自荐参战，
这又要一段时间，谁的辅助部队先进场就看造化了。

2、 部队进场的位置

现在部队的进场基本是随机的，除了防守部队会在城周围部署之外，
进攻部队根本难以在短时间内集结或甚至了解自己部队的分布。建议
在每个战场设置一些进攻部队出现的区域，如A1-T1，A1-A16等，也即
部队将出现在同侧的边缘一带，并且彼此相邻，出现在哪个方向可以
随机，但部队总在同一侧就是了。（本想根据城市进攻的方向决定进
R5至R9的地方一下子出现了，呵呵，神出鬼没了一点。

3、 机动力的修改

现在的机动力最大值是30，限制了玩家部队的机动性，而且在将来的
兵种升级后，不同兵种在不同地形的差别不容易分辨出来，显示不出
各兵种在擅长地形的优势。建议将机动力最大值设置成100，以便让
部队可以「静如处子，动如脱兔」，以后各兵种之间的差别和优势也
相对容易设置。（呃，btw，今天看阿洛拿着9个民兵跑，不知道是我
的系统反应慢还是busy time 取消了，总之看着他一口气在2秒内挪
了三步。呵呵）相信busy time 可以防止机动力多而到处乱跑的情况。

4、 部队进入河流地形时的损失

现在基本所有部队都可以进入河流，但是他们没有船呀，桥是拿来摆
的呀，几万旱鸭子在水里横冲直撞回来毛都没有少一根，呃，不合理
吧。建议更改，除了水军部队之外，其余所有部队在进入河流地形一
次，损失1/n的兵力，n的大小可以根据兵种特色而不同，嗯，不过全
部设成1/10也没有什么问题，反正没有船，就该淹死一点。这样迫使
玩家在战术运用的时候考虑更多的地形问题，而不是视地形于无物或
只重视攻击效果。

5、 战争与安定的进一步建议

在原有基础上，如tit所说，进攻方城市的居民会因战争而引起恐慌，
导致安定下降，而相邻的本国城市失守，地区的安定也应该会下降，
正所谓人心惶惶，嘿嘿。

（tit的公式似乎狠了一点），建议公式：

决定进攻某城：safety - 10 （无论成功与否，或分兵失败）

进攻某城成功：no change

进攻某城失败：safety b4 loss / 2 
        （某城居民见烈火铩羽而归，大失所望，当地安定下降了）

相邻的本国城市失守：safety - 30
（防止天水/赤壁时间再次上演，并且以后支援功能出现了，相邻的
本国城市应当承担相当责任）

6、 战争与训练士气

单纯的降低进攻失败方的安定并不能根本地解决使用少量兵力提高
相邻的友国城市训练士气的发生，因为可以轻易地开仓赈粮。建议
如下：

进攻失败方城市的训练 / 2，士气 / 2
（呃，只有当war_idea里面的训练和士气成为出兵条件时才有效）

7、 进攻城市提高安定手段的调整

问题是手段，如果想要持续进攻，就必须做工作来提高，而不是单
坐在会议室里开会就可以解决的。建议如下：

降低税率：在war_idea里面提过，税率的调幅有限制，如每次调整
          不能超过20，调整的间隔也应该有，譬如每个月城市只
          能调整一次税率。

开仓赈粮：现时能开仓的条件比开战还低，如果在安定89时开仓，
          只要放两倍于人口的粮安定就变119了。建议将开仓的
          标准提高，只有当安定低于60时才能赈粮，如果开战的
          条件是100，那么至少还要做一些工作才能顺利开战。
（really dun think war is a easy stuff, so if want war, work hard）

8、 战争奖励的调整

由于现在全部地区都开放了，战争由原先较没有目的或不明确转变
成为今天有战略目的的攻城略地（除了某些别有用心的战争），我
觉得现在就算没有整整一级的修养奖励玩家也会主动攻击，而这个
为了鼓励多打仗的重赏也可以降下帷幕了，建议如下：

进攻方胜利：
主将：          random skill + 1000
进攻的玩家：    random skill + 500
共同进攻的主将：random skill + 600
共同进攻的玩家：random skill + 300

防守方胜利：
主将：          random skill + 800
防守的玩家：    random skill + 400
协防的主将：    random skill + 600
协防的玩家：    random skill + 300

顺带提一下关于天赋限制修养增长的想法，天赋决定修养的最高等
级，并不代表修养绝对不能超过天赋所限，人定胜天嘛，只是很难
很难很难而已。。。。。。建议如下：

当修养达到天赋所限时，升级公式为：

%^GREEN%^exp = %^H_CYAN%^10 * %^GREEN%^lev * lev * 20 / (gift)%^RESET%^
（嘿嘿，很难吧。。。）

pls raise ur doubts, and if i am here, talk to me bah ..:)


---
作者: Fire
题目: the automatically act of npc chars are added
日期: Thu Jul 22 20:37:21 1999
don't know if more bugs :(

I will begin to adjust war next step
addoil all :)


---
作者: Ice
题目: basicjob: babysitter
日期: Fri Jul 23 01:06:46 1999
ask zhang about job

玄冰向张员外打听「工作」的事情。
张员外说：犬子正愁无人管教，请先生/小姑娘帮我带一下他吧。

//this job is unique, if some one is doing, no one else can do

张员外招招手，一个调皮的小男孩一蹦一跳地跑了过来。

look

华阴有名大富豪，张员外(zhang yuanwai)
张家小少爷（zhang shaoye）

张家小少爷对玄冰说道：少爷我要到华阴村的牢房去玩。
//all destination of this kid is inside huayin, so fire need remove
  the 密道 and 老槐树 in huayin, i can remove it in map.:P

ask zhang shaoye about w
张家小少爷犹犹豫豫地向西边走去。
//use same idea as xuzijiang, and can be a preparation of xu's job..:P

//到了地头
ask zhang shaoye about arrive
你弯腰对张家小少爷说道：少爷，到了，还有什么吩咐？

//if not right room
张家小少爷大嚷大叫：你骗谁！根本不是这里！

//if more than 200 secs not arrive, job failed, cannot do it in 30 mins
张家小少爷对玄冰「哼」了一声，径自跑开了。

//if arrive in the right room within 200 secs
张家小少爷「哦」了一声：原来就是这里呀，还以为是什么好玩的地方呢。
张家小少爷一拍脑袋：啊，我还想去池塘边看看。

//repeat the same process, same 200 secs limit
张家小少爷「嗯」了一声。
张家小少爷对玄冰说道：好啦，没你的事啦，别跟着我，要请赏找我爹去！
张家小少爷一溜烟地跑不见了。

//back to zhang
华阴有名大富豪，张员外(zhang yuanwai)

ask zhang about pay
//if job failed
张员外一把揪住你的领口：你还有脸来找我讨赏？一边去！

//job succeeded张员外拍拍你的肩膀：总算有人能陪他开心玩一会儿了，来，看赏！
//robot test and tiezi same random as chopping and digging
你被赏了十两银子。




---
作者: Ice
题目: basicjob:buyfood
日期: Fri Jul 23 01:31:33 1999
后堂 
    这个厅便是后堂了，不算很大，但布置得非常齐整而又精致，也
许是因为张小姐的闺房就在楼上的缘故。靠着墙依着一张水柳木的方
桌，上面摆着一套茶具，桌子边上是两张高背木椅。椅子旁安着只小
巧的木几，上面是一只细瓷花瓶。你可以看到一边有楼梯通向二楼。

张员外的元配 张夫人（zhang furen）

ask zhang furen about job
玄冰向张夫人打听「工作」的事情
张夫人笑笑说：难得你这么有心意，就去帮我买点东西回来吧。
张夫人说道：你可千万要听好了，我可只说一遍，我要的是
北平聚贤楼之店小二卖的烤鸭 和 豫章水果摊之小贩卖的苹果。

//target obj will be food and drinks only
//cmd job will only show the target obj, the location won't be shown any more

//cannot finish or some other problem
ask zhang furen about cancel
玄冰哭丧着脸对张夫人说道：小的对不起夫人，小的对不起夫人。。。
张夫人板着脸，眼角都不扫玄冰一下。

ask zhang furen about pay
//if no target obj in this body
张夫人一手叉腰，一边用手指顶着玄冰的额头大骂：就凭你？想耍我！哼！

//if right obj
张夫人把玄冰买回来的 烤鸭 和 苹果 都尝了一下，满意地点了点头：

//same robot test, tiezi random as chopping and digsioil
好，看赏！
玄冰被被奖励了五十两银子。

//since no more than 1/5 of the food and drink is over 40 silver, we can
  set the money reward of this job random from 30 to 60, it's a fair
  chance to get profit or loss, however, they can hold the food
  and drink, which are clean and ready to eat..:P


---
作者: Ice
题目: about train
日期: Sat Jul 24 12:48:06 1999
although fire said we'll add a midjob to increase local morale, i think
we need to change train a little bit.  now if a player cmd train, 
no more than 3 officers will auto join, which can at most bring 20k
each train,
so if a city has more troops, the train almost means nothing but
adding 1 each time.

i suggest to change the npc's auto cmd me, make it possible to train
with all possible
NPC in meeting will cmd me to train.


---
作者: Yuyin
题目: bug 报告
日期: Sun Jul 25 02:00:13 1999
今天中午，xixixi说 chibi 打仗的时侯有 bug
现在 chibi 的【士    兵】
与  【人    口】
等全没了
还有大火球说道：如果在分兵时cmd over.
就会出现bug
但我还没有试过,请fire 看一下


---
作者: Stefan
题目: driver udpated
日期: Sun Jul 25 04:24:54 1999
We are now using a new driver 22.2a21.

If you check /log/log, there are just a lot of warnings, somebody
please fix it :)

I hope this time SanGuo should be more stable, but dunno... 

Because of the driver update, there may be some code broken, if any wiz
finds any broken code, please report.



---
作者: Group
题目: faint
日期: Wed Jul 28 06:27:07 1999
guwu is for permenant increase of morale? faint....
the function i used is the same which call all the troops decrease 1
morale for 1 heart beat during wars...is that one also pemenant?
if the answer is yes.... hmm... i will try to find a way to decrease temp one.
fire, please give a answer for this...thanks

group


---
作者: Ice
题目: about boy
日期: Wed Jul 28 06:32:06 1999
hmm, if boy ask for specific food or drink depending on target,
it sounds tough, bcoz if ppl need to find sb, he has to find out
that kind of food first, then need ask boy about xianren, then ask
baodating....
a too complex way, how about this?

make boy's request depending on area, that is, if i go luoyang, luoyang boy
will ask for one kind of food for all comers, which can make it easier and
more fun.  and we need to make the boy's request refresh in a certain time,
hmm, how about every one sg month, boy changes his taste month to month,
hmm, and on the other hand, we can make ask boy about xianren will cost only
mantou, bcoz xianren dun belong to any area, and highhands always no need to
do that job.

by the way, i think we need to increase or change the reward of findbody,
otherwise if find a ppl need 15 silver food, but get paying 5 silver, no one
will do it..:P


---
作者: Ice
题目: about midjob
日期: Wed Jul 28 06:45:33 1999
now most midjobs r targetless, like fanpeople, whisper.....
well, in KOEI's game, player can have freedom to choose which
target officer or city he would like to go, though we cannot
do the same here, i think we should change those nasty job's
method of getting area like spy job's, depending on the distance..:P


---
作者: Fire
题目: >faint
日期: Wed Jul 28 08:08:41 1999
On Wed Jul 28 06:27:07 1999 Group wrote post #688:
> guwu is for permenant increase of morale? faint....
> the function i used is the same which call all the troops decrease 1
> morale for 1 heart beat during wars...is that one also pemenant?
> if the answer is yes.... hmm... i will try to find a way to decrease temp
one.
> fire, please give a answer for this...thanks
> 
> group

now the morale just has one variable to hold it so all the act
on it is permenant. we may need introuce a temp morale later
but now just use it. I think it is ok.
make sure we use the same function, so if we need adjust later
just adjust that function but don't need adjust those code call
that function. 
about guwu, I think we need related skills to it
I will make a place for players to learn such skill

addoil ):


---
作者: Fire
题目: >about midjob
日期: Wed Jul 28 08:10:03 1999
On Wed Jul 28 06:45:33 1999 Ice wrote post #690:
> now most midjobs r targetless, like fanpeople, whisper.....
> well, in KOEI's game, player can have freedom to choose which
> target officer or city he would like to go, though we cannot
> do the same here, i think we should change those nasty job's
> method of getting area like spy job's, depending on the distance..:P

bugao has been designed related to the distance like spy
others will adjust later :)


---
作者: Ice
题目: redo of local positions
日期: Wed Jul 28 16:20:25 1999
城市官阶：

lv 1

□主将：━━ 
□书爷：━━ 
□文官：━━ ━━ ━━ 
□武将：━━ 
□武官：━━ ━━ ━━ 

lv 2

□村长：━━ 
□书爷：━━ ━━ 
□文官：━━ ━━ ━━ 
□武将：━━ ━━
□武官：━━ ━━ ━━ 

lv 3

□镇太守：━━ 
□镇军师：━━ 
□书爷：━━ ━━ ━━ ━━ 
□文官：━━ ━━ ━━ ━━ ━━ ━━ 
□牙将：━━ 
□武将：━━ ━━ ━━ ━━ 
□武官：━━ ━━ ━━ ━━ ━━ ━━ 

lv 4

□太守：━━ 
□军师：━━ 
□书爷：━━ ━━ ━━ ━━ ━━ 
□文官：━━ ━━ ━━ ━━ ━━ ━━ ━━ 
□大将：━━ 
□牙将：━━ ━━ ━━ 
□武将：━━ ━━ ━━ ━━ ━━ 
□武官：━━ ━━ ━━ ━━ ━━ ━━ ━━ 

lv 5

□太守：━━ 
□军师：━━ 
□副军师：━━ ━━ ━━ 
□书爷：━━ ━━ ━━ ━━ ━━ 
□文官：━━ ━━ ━━ ━━ ━━ ━━ ━━ 
□大将：━━ ━━ ━━ 
□牙将：━━ ━━ ━━ ━━ 
□武将：━━ ━━ ━━ ━━ ━━ ━━ 
□武官：━━ ━━ ━━ ━━ ━━ ━━ ━━ 

note：in the currently existing local positions, 武将 in lv 3 city is a kind
      of confusing with 武将 in lv 1 and lv 2 cities
on the other hand, no.
      of positions in city differs the cities levels, i changed some numbers
      of positions. I erased all 副将 position and replaced it as 牙将, and
      put 武将 in lv 4 and lv 5 cities, to standardlize the positions.


地方官职要求：

文官

rep：                     200
local contri：            10
loyalty：                 50
skills：                  bfxy 30 zgxy 30
salary：                  1


武官

rep：                     200
local contri：            10
loyalty：                 45
skills：                  bfxy 30 wxxy 30
score：                   att_abi 10
salary：                  1

书爷

rep：                     2000
local contri：            200
loyalty：                 55
skills：                  bfxy 35 zgxy 35
salary：                  2

武将：

rep：                     2000
local contri：            200
loyalty：                 50
skills：                  bfxy 35 wxxy 35
score：                   att_abi 20
salary：                  2

镇军师/副军师：

rep：                     10000
local contri：            500
loyalty：                 65
skills：                  bfxy 50 zgxy 50
salary：                  3

牙将：

rep：                     10000
local contri：            500
loyalty：                 60
skills：                  bfxy 50 wxxy 50
score：                   att_abi 30
salary：                  3

军师：

rep：                     20000
local contri：            1000
loyalty：                 75
skills：                  bfxy 70 zgxy 70
salary：                  5

大将

rep：                     20000
local contri：            1000
loyalty：                 70
score：                   att_abi 40
skills：                  bfxy 70 wxxy 70
salary：                  5

闲职：

rep：                      -
local contri：             -
loyalty：                  -
skills：                   -
salary：                   1

太守：

level 1： 
rep：                      -
local contri：             -
loyalty：                  50
skills：                   -
salary：                   2

level 2：
rep：                      -
local contri：             -
loyalty：                  60
skills：                   -
salary：                   3

level 3：
rep：                      -
local contri：             -
loyalty：                  70
skills：                   -
salary：                   4

level 4：
rep：                      -
local contri：             -
loyalty：                  80
skills：                   -
salary：                   6

level 5：
rep：                      -
local contri：             -
loyalty：                  90
skills：                   -
salary：                   10

note： 

1、added local contri as a requirement, basicjob->findbody need to be
adjusted,
   thus player officer cannot change his city unless his king or 国师
permited.

2、added loyalty of taishou position, when a taishou or a king wanna pos the
   taishou position to an existing officer, has to consider his loyalty first,

   otherwise the officer cannot be taishou, hope it can help to solve the
dummy
   taishou a little.

3、suggest to add a requirement of officers transfering, for example, if a
king
   named sb as taishou, or transfer an officer to a new city, this taishou or 
   officer cannot be transfered again within 1 mud year.  if a real taishou
pos
   his taishou position to an officer in his city, he is supposed that he
cannot
   get it back within 1 mud month.

4、added att_abi in score to restrict the 武官's position，hmm, since 武官
need
   to war mainly, should consider his fight ability in his position
requirement.
   the requirement of officials should be higher than officers, since they dun
   need to fight.



---
作者: Fire
题目: >redo of local positions
日期: Wed Jul 28 19:48:57 1999
thank ice's post
I have check it and find most are very nice
the only problem is can anyone find some 
good chinese name (sound like sg time) to replace the current name ?
thanks


---
作者: Ice
题目: names of local positions
日期: Wed Jul 28 23:49:54 1999
城市官阶：

lv 1

□主将：━━ 
□参军：━━ 
□随军：━━ ━━ ━━ 
□监军：━━ 
□护军：━━ ━━ ━━ 

lv 2

□村长：━━ 
□书爷：━━ ━━ 
□通事：━━ ━━ ━━ 
□典军：━━ ━━
□武卫：━━ ━━ ━━ 

lv 3

□镇太守：━━ 
□别驾：━━ 
□从事：━━ ━━ ━━ ━━ 
□议曹：━━ ━━ ━━ ━━ ━━ ━━ 
□裨将：━━ 
□牙将：━━ ━━ ━━ ━━ 
□领军：━━ ━━ ━━ ━━ ━━ ━━ 

lv 4

□太守：━━ 
□主簿：━━ 
□治中：━━ ━━ ━━ ━━ ━━ 
□决曹：━━ ━━ ━━ ━━ ━━ ━━ ━━ 
□偏将：━━ 
□部将：━━ ━━ ━━ 
□监将：━━ ━━ ━━ ━━ ━━ 
□都尉：━━ ━━ ━━ ━━ ━━ ━━ ━━ 

lv 5

□太守：━━ 
□军师：━━ 
□参谋：━━ ━━ ━━ 
□吏曹：━━ ━━ ━━ ━━ ━━ 
□功曹：━━ ━━ ━━ ━━ ━━ ━━ ━━ 
□副将：━━ ━━ ━━ 
□曲将：━━ ━━ ━━ ━━ 
□典将：━━ ━━ ━━ ━━ ━━ ━━ 
□校尉：━━ ━━ ━━ ━━ ━━ ━━ ━━ 


---
作者: Ice
题目: another heaven of idlers
日期: Sun Jul 25 23:17:49 1999
目前总人数：6人
─────────────────────────────────────
【粗通文字】建业隐居贤人看板娃娃(dolly)                             
           
【下笔千言】水梦国宛城文官凉粉草(cool) [发呆 5 小时]                
           
【落笔有神】龙之国白狼山闲职「复苏」烈火，字嘿嘿(fire) [发呆 1 小时] -离线中-
【粗通文字】帝国汉中文官「碧血铁胆」阿洛，字向飞(row) [发呆 36 分钟]
【下笔千言】龙之国邺城太守美美，字猪猪(meimei) [发呆 18 分钟]       
           
【小有文采】龙之国襄平村长「发呆中，zｚZＺ」玄冰，字尾生(ice)


---
作者: Ice
题目: about 【远程】
日期: Sun Jul 25 22:48:01 1999
when player use gini to do 【远程】 emote, it's supposed to show
then gini id instead of the name, otherwise it can be unfriendly
bothering......



---
作者: Stefan
题目: >another two bugs caused by the new mudos
日期: Sun Jul 25 22:10:10 1999
On Sun Jul 25 08:29:12 1999 Fire wrote post #677:
> 1. in the verb parse
>    the parse of "STR" does't recognize Chinese strings
> 2. can't do semote to players in another room, 
> stefan, please have a look :)

I'll fix the verb in a few days.


---
作者: Fire
题目: seem the new mudos is more stable
日期: Sun Jul 25 19:57:51 1999
addoil :)


---
作者: Fire
题目: another two bugs caused by the new mudos
日期: Sun Jul 25 08:29:12 1999
1. in the verb parse
   the parse of "STR" does't recognize Chinese strings
2. can't do semote to players in another room, 
stefan, please have a look :)


---
作者: Fire
题目: 关于MUDOS升级
日期: Sun Jul 25 07:31:30 1999
非常感谢stefan的mudos 升级
I hope this new mudos will solve our crash problem.
now i find two different between the new os and the old one
1, the compile are more strict, will give wrong to the
   unreference variable, (may be this is a swich in some place
    but i think this feature is good, can help us to find potental
    bugs)
2, the call_out is much faster than before
   in the code of thief, i usually use 
   call_out("escape",random(2)) then find it is too slow so
   i change to call_out("escape",random(1))
   in fact random(1)=0; so the call_out will be execute immeatately
   but in old os, it still has some delay, so it is just sutable for
   players to catch thieves, but in the new os, it is much faster
   so thief will disappear at no time, so have to change it back
   to call_out("escape",random(2))
   there may have more difference, but let hope this new os
   can help to solve the serious crash problem :)


---
作者: Ice
题目: faint
日期: Mon Jul 26 06:08:58 1999
目前有 22 位玩家、0 位巫师在游戏中，还有 1 位正在连线。
目前有 12 位从 202.102.66.221 上线的玩家:
wispy, gods, snowcc, ybing, bamboo, young, goda, snowqq, dummya, dummyb,
dummyc, dummyd.



---
作者: Fire
题目: another differece between the two mudos
日期: Mon Jul 26 08:51:08 1999
for old mudos
we use get_dir(<dir>) to retrieve all the file names
under that dir, now for the new mudos
have to sue get_dir(<dir>+"*.c") to get the result
this may cause some program don't work properly


---
作者: Yuyin
题目: bug 汇报
日期: Mon Jul 26 11:12:30 1999
na $nationtax qiao 20
【聂风国】聂风：诸位爱卿，朕以为目前国库空虚，当可将谯城的国家税率由十增加到二
十
 【谣言】某人：聂风国将谯城的国家税率由十增加到二十。
na #agree yuyin
*Bad argument 2 to member_array()
Trace written to /log/runtime


---
作者: Ice
题目: about cast guwu
日期: Mon Jul 26 16:46:05 1999
group, seems now cast guwu increase morale for permanent,
i casted guwu in war, then after war the rest morale + 20..:P
remember to change it to temp..:)

* escape


---
作者: Row
题目: i hate exam
日期: Tue Jul 27 21:17:31 1999
becoz of my academic work, i will be buzy and 
absent from here for around 2 weeks, sorry
for the delaying of my work, i'll pick it
up again when back.

                              row.


---
作者: Fire
题目: >i hate exam
日期: Tue Jul 27 21:18:16 1999
On Tue Jul 27 21:17:31 1999 Row wrote post #686:
> becoz of my academic work, i will be buzy and 
> absent from here for around 2 weeks, sorry
> for the delaying of my work, i'll pick it
> up again when back.
> 
>                               row.

addoil row, we are waiting the jiebai system :)


---
作者: Ice
题目: suggest change the name of ranknation
日期: Fri Jul 30 06:34:49 1999
丞相，侍中，长史
大将军，中郎将，牙门将


---
作者: Ice
题目: about obj level and officer level
日期: Fri Jul 30 06:30:26 1999
now players said they r confused by the lv of obj and position,
and then dunno which they can order.

i think we can make this point clear, first in obj(maker)

你对王铁匠招了招手：王铁匠，让草民看看你这儿都有些什么货。
王铁匠道：不知先生需要些什么？
物品名称             购买价          定做价          修改价         物品等级
------------------------------------------------------------------------------
小铁戟(xiaotieji)    五两银子        十五两银子      十两银子           零
blah blah

second, i'll make a help level file to let player check their
level of position.

how do u guys think about it?

hmm, where can i check the position level yah?.:P * blush


---
作者: Stefan
题目: ed fixed
日期: Fri Jul 30 02:14:54 1999
as title :)


---
作者: Fire
题目: 关于计谋的设计规范，
日期: Thu Jul 29 23:37:08 1999
现在group设计了一个计谋guwu。我认为这是一个新系统
的很好的开端。为了便于今后的发展和与其他系统统一协调
我建议对于计谋的设计采用以下规范：
1   所有的计谋用 cast 驱动：执行命令为：
    cast <jm_id> [target]
2   所有计谋的定义与过程文件放在：
    /sgdomain/jimou/ 路径下。文件名称与计谋ID一致
3   每一计谋与一相应的(或多个skill挂钩。
4   设计一个module file，用于存储玩家(包括npc)的
    计谋什么情况。例如：某一计谋使用的次数，上一次
    使用时间等。
5   同一角色在使用同一计谋时必需有最短间隔。
6   其他限制：
    1. 天气情况
    2. 经济情况
    3. 地形情况
7   一计谋使用后，根据该角色的相关skill的高低，外界条件
    (如部队士兵的数量，训练，士气，敌方角色的参数等)
    和天赋决定：
    1. 计谋是否成功
    2. 计谋的效果大小
    3. 消耗。其中包括
        1 物质方面： 如gold,stuff等
        2 时间。(busy time)
        3 部队的(busy time)
        4 blood and spirit
8   计谋使用后果：
    分两大类，成功，失败。
    成功会有好处，失败要有一些反面作用(但要注意平衡和
    潜在bug)。如果是在线玩家，相应技能的经验要增加。
9   计谋技能的学习：
    1  从汉帝的书房
    2  特别的quest
    3  和基本技能一样，30级之前没有经验的限制，高于
       30级要有一定经验才行。
10  一些NPC有技能，可以自动使用。


---
作者: Ice
题目: about guwu
日期: Thu Jul 29 20:12:39 1999
你振臂高呼，试图激起士兵的斗志。
你振臂高呼，试图激起士兵的斗志。
你振臂高呼，试图激起士兵的斗志。
士兵们群情激奋，士气高涨。
士兵们群情激奋，士气高涨。
士兵们群情激奋，士气高涨。

busy time only work for other actions, if take the same
action, no restriction at present, group pls add it.

and the upcoming trickies should be designed in the same way.:P

addoil..:)


---
作者: Fire
题目: ed has problem
日期: Thu Jul 29 19:29:55 1999
now use ed can't display Chinese properly.
so, Stefan please fix this problm bah, xixi :)


---
作者: Fire
题目: >sth wrong with ed(at least on ice's body)
日期: Thu Jul 29 19:20:04 1999
On Thu Jul 29 15:41:18 1999 Ice wrote post #700:
> when i use more <file_name>, everything is normal and ok;
> but if i use ed <file_name>, i cannot read chinese at all,
> only show characters like the following
>    set_long("
> ^T^S^U^N^D^Z^I^O^O^B^U^F^[^P^[^T^[^M^C^L^P^K^C^[^J^L^N^@^V^D^W^S^K^F^U^X^U
^^^T
> ^Z^V^\^N^G^A^C^U^N^D^Z
> ^X^W^P^T
> 
> blah blah, dunno what's wrong with edit or i am not doing in
> the proper way, hmm, and there r lots of "^M" at the end of each line
> in most of the files..:(  pls check it.:(

i think this is because this file has been transferd by wrong
mode during ftp. 
so I strongly suggest when use ftp, turn on asicc mode


---
作者: Ice
题目: sth wrong with ed(at least on ice's body)
日期: Thu Jul 29 15:41:18 1999
when i use more <file_name>, everything is normal and ok;
but if i use ed <file_name>, i cannot read chinese at all,
only show characters like the following
   set_long("
^T^S^U^N^D^Z^I^O^O^B^U^F^[^P^[^T^[^M^C^L^P^K^C^[^J^L^N^@^V^D^W^S^K^F^U^X^U^^^T
^Z^V^\^N^G^A^C^U^N^D^Z
^X^W^P^T

blah blah, dunno what's wrong with edit or i am not doing in
the proper way, hmm, and there r lots of "^M" at the end of each line
in most of the files..:(  pls check it.:(


---
作者: Stefan
题目: FTP and HTTP fixed
日期: Thu Jul 29 12:57:47 1999
socket was much updated in the new driver, which caused them to fail.
Now FTP and HTTP should work.


---
作者: Fire
题目: the name of local officer
日期: Thu Jul 29 07:41:24 1999
now the local officer use the name as ice given
admire ice, how could get so much names
addoil :)


---
作者: Fire
题目: >http server can not work
日期: Thu Jul 29 07:39:39 1999
On Thu Jul 29 04:18:25 1999 Flee wrote post #696:
> is it because of the new MudOs ?

now the ftp and http either works properly, stefan, please have
a check.



---
作者: Flee
题目: http server can not work
日期: Thu Jul 29 04:18:25 1999
is it because of the new MudOs ?


---
作者: Ice
题目: about trickies skill's learning methods
日期: Sun Aug  1 14:29:08 1999
1、 study bing shu by han di's call
2、 while use that trick will add some exp, (succeed add 5, fail add 1)
    then can ask officer in the same nation about this skill, if this
    officer has higher skill, can learn, about the real NPCs, i think we
    can use bfxy ask the same level of his trick skills level, hmm, about
    the tricks used in war by NPC, need design carefully..:P
3、 some kind of skills can learn from doing some jobs, like jbsj, hmm,
   i think we should change the fire_officer provide 灭火之计 instead of
   jbhj..:D, and we can add some more jobs like repair the city walls, 
    trapping, blah blah....


---
作者: Ice
题目: additional note of trickies skills
日期: Sun Aug  1 19:48:52 1999
奋发之计

指挥部队向四周的敌人同时进攻，成功则按攻击公式计算，失败则陷入混乱。

乱射之计

弓兵部队专用，向射程范围内的所有部队射箭，不管是敌军或友军，成功则
按公式，失败则混乱。

以上两个计谋可以和wxxy联系，其余的应该和bfxy联系。

特殊技能：
天变、风变、占卜、奇门遁甲应为特殊技能，特殊招法应该是指单挑时的绝招。
有关修复城墙、挖陷井、堆放柴火等不确定该算什么。。。。:(



---
作者: Tit
题目: it seems that all the stuffs here are all too expensive 
日期: Mon Aug  2 02:45:52 1999
the gold here seems to worth nothing.
1 spear cost 1000 gold!!!!
too terrible.
maybe can we check the price of all the stuffs and low down the price.
1 spear even not cost 1000 coin bah in that time.
pls consider.


---
作者: Ice
题目: >it seems that all the stuffs here are all too expensive 
日期: Mon Aug  2 06:49:35 1999
the max price for a weapon or cloth is 300 gold, pls recheck,
i think the price is ok, and later obj will have it's life of
recycle, ppl need to replace his weapon or cloth while it's
too old. however, so far as i know, only 3 objs exceeds 1000 gold,
hxbma, dwhorse, wuzhuima, that's it.


---
作者: Fire
题目: a bug of socket
日期: Tue Aug  3 11:01:40 1999
[errors] ((none)) Error logged to /log/runtime
[errors] *could not release: Descriptor out of range
[errors] /secure/obj/socket#1 at line 219
【系统】龙卷风断线了。
【系统】龙卷风离开了三国。
【系统】雪断线了。
【系统】雪离开了三国。
【系统】蔡君断线了。
【系统】蔡君离开了三国。
【系统】方齐山断线了。
【系统】方齐山离开了三国。
【系统】小龙断线了。
【系统】小龙离开了三国。
【系统】寻飞断线了。
【系统】寻飞离开了三国。
【系统】方齐山进入三国。
dbxwhere last
Tue Aug  3 11:00:09 1999
*could not release: Descriptor out of range
Object: /secure/obj/socket#1 at line 219
#0: 'listen_callback' at /secure/obj/socket#1 at line 219
dbxframe last 0
------secure/obj/socket.c:219 - listen_callback(-19)
locals: -5
----------------------------------------------------------------
    s = new(SOCKET, SKT_STYLE_INT_ACQUIRE, read_func, close_func);
SKTLOG("listen_callback: new sock",s);
    err = socket_release(fd, s, "release_callback");
SKTLOG("listen_callback: err",err);
    if ( err < 0 )
=>      error("could not release: " + socket_error(err) + "\n");
}
//### need a way to protect this from random writes
varargs nomask void send(mixed message, string address)
{


---
作者: Fire
题目: about the types of troop.
日期: Tue Aug  3 11:04:54 1999
now i have created a daemon "/daemons/troop_type_d.c". I think we
will use this daemon to handle most the information of the different
troops.
this daemon has scaned most information in groups troops file. so
it keeps most the information similar to that defined in groups 
file.
for some function, which involve to the weather and zhengxin of
the troop, we will try to introduce extra fields to handle this
problem. so we can realize functions that  certain troop is more
suitable to certan zhangxi under certain weather. for this daemon
"info t" will give most common information and wiz can  use
@TROOP_TYPE_D->get_troop_d([id],[what]) to retreve all the information
stored in this daemon. and we will develop more function to help
wiz manage and edit this troop type datebase. 
for the war system, I will gradually move most functions which
related to the troop types attached to this daemon.
addoil


---
作者: Tit
题目: about the price
日期: Wed Aug  4 03:44:12 1999
ask kong rong merchant about goods
你对孔融国商人一拱手道 [0m孔融国商人答到：本部有以下存货：
 [0m货物      价钱              数量     
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
红缨枪    一千六百两金子    五十三
长枪      一百三十七两金五十两银子  六十六
皮甲      一百五十两金子    一百六十六
 [0m用 ? 取得帮助>  [0m


---
作者: Tit
题目: follow 355
日期: Wed Aug  4 03:45:53 1999
i mean the price of the goods at merchant.
it seems too expensive lah.
that is all.


---
作者: Fire
题目: about cast jimou
日期: Wed Aug  4 07:22:07 1999
I moved cast.c from /wiz/group/ to /cmds/player
disable /cmds/verbs/cast.c
and group will put two jimou under /sgdomain/jimou/
let's see how these two jimou (used by cast) going.
addoil :)


---
作者: Ice
题目: about the width in new driver
日期: Fri Jul 30 18:03:35 1999
seems now all player's width is 79, stefan pls do sth to change
it bah, supposed to be even number bah..:P


---
作者: Ice
题目: about wizlist
日期: Fri Jul 30 17:29:18 1999
seems now wizlist won't have the list resort by time any more,
unless system reboot.  hmm, i remember b4 it can resort bah,
longer time no log in will be put upper.........


---
作者: Flee
题目: >> about wizlist.c
日期: Sat Jul 31 02:33:00 1999
wizlist will not resort the list unless u 
update /cmds/player/wizlist.c.
because it use LOGIN_D to obtain that list
which is very cpu time consuming.


---
作者: Flee
题目: >> about 霎时地动山摇，天翻地覆，整个世界毁于一旦！
日期: Sat Jul 31 02:34:46 1999
it is a crash called by the /secure/master.c.
so evrey player is forced to quit b4 crash.


---
作者: Flee
题目: About my curren works
日期: Sat Jul 31 02:36:45 1999
i am very busy for these weeks, hope i can be
a little bit free next week .. 


---
作者: Ice
题目: about jobs using the new driver
日期: Sat Jul 31 14:38:52 1999
seems now most jobs' setting need to be adjusted, the new driver
works more efficiently, thus the delay in the past jobs r useless.

for example, visitpeople, it used to be 1-2 secs for each option,
but now, no delay in between at all, i think we should re-consider
the time of delay.

ps: about the multipatrol and thief, i think we need to do sth more,
if 3-5 ppl patrol in a city, and if thief appears, system start to
be lag bcoz all ppl cmd catch thief, and the thief is sneaky, thus
player keep pressing cmd catch thief and make the system lag.
how about this, make cmd catch has busy time, and delay the thief's
runaway trigger, make it more balance


---
作者: Yuyin
题目: bug 报告
日期: Sat Jul 31 20:14:16 1999
我刚 login 就
大自然 *call_other() couldn't find object
Trace written to /log/runtime


---
作者: Ice
题目: about job after position changed
日期: Sat Jul 31 22:51:49 1999
when a player changed his position from one city to another,
his job record should be consider done related to that city,
otherwise player can choose their whipser, spy obj or so,
like the following:

//it's the snoop log of xixixi
%> %%你对城市浪子答到：＂whisper＂
%城市浪子对你道：最近听说风云国的卢植心存不满。
%> %%ask dead about position%
%不死鸟对你笑道：小将军正合此职，可喜，可贺呀。
【谣言】某人：小琴被封为琅琊武卫。
%你向不死鸟打听关于<job>的消息。
%> %%你对不死鸟答到：＂whisper＂
%不死鸟对你道：最近听说北平雪国的胡遵心存不满。
%你向城市浪子打听关于<position>的消息。
【谣言】某人：小琴被封为官渡护军。
%> %%你对城市浪子答到：＂whisper＂
%城市浪子对你道：最近听说风云国的王累心存不满。
> %ask dead about position%
【谣言】某人：小琴被封为琅琊武卫。
blah blah

thus i suggest to change to if the job related to the former city,
the job record should be consider this quote is done.

and later we can make player cannot change his city easily unless
his king permits.


---
作者: Ice
题目: 关于计谋
日期: Sat Jul 31 23:20:33 1999
1、 火计，jbhj

    天气、风向、地形、距离影响成功率和损失，物资系统可以提供
    生产一些火种和木材，战争时携带以使用火计，如果携带大量的
    木材和火种，被烧的损失犹为严重。风向弄错了则引火烧身。:P
    呃，是否可以将warmap做成可以看到拿一个房间是有火的，并且
    火势会蔓延或减弱，着火的房间无法进入，如果部队被大火包围，
    将无法移动，除非使用「灭火」之计。（见后）

2、 水计，jbsj

    地形的影响最为重要，如果敌军在相邻或相近的房间，可以开闸
    放水。（这个计谋的使用和描述比较特别，因为光荣里的水计或
    水神都比较神奇，小心点做的好。:D）

3、 鼓舞，guwu

    鼓舞军中士气，失败则下降。当技能级别够高的时候，还可以鼓
    舞邻近部队的士气。（类似KOEI的激励之计）

4、 混乱，hunluan

    使处于相邻房间的敌军部队陷入混乱，无法移动及攻击，以及当   
侦察系统完善后，无法探敌；失败则本部队陷入混乱，但混乱时
    间缩短一半，混乱期间移动力无法恢复。

5、 内讧，neihong

    使敌军相邻的两支部队陷入busy并且互相攻击，（不论这两支部
    队的移动力能否互相攻击，总之显示两支部队都减少兵力就是了）
    失败则部队陷入混乱，时间同混乱失败。

6、 收拾，shoushi

    使本部队或相邻房间的部队脱离混乱状态，失败则混乱时间增加
    1/3。

7、 埋伏，maifu

    敌军无法侦察到部队的位置、状况等，但本部队不能移动和使用
    计谋，埋伏有一定时限，时间一过则会被敌军探子侦察到。埋伏
    期间如果敌军停留在相邻的房间，则可以进行攻击，从埋伏状态
    攻击一次之后恢复正常状态，但这一次的攻击力加倍，并且使被
    攻击的敌军陷入混乱；失败则本部队陷入混乱。

8、 奇兵，qibing

    敌军无法侦察到部队的位置、状况等，本部队可以移动，有一定
    时限，时限过后恢复正常状态，限制是部队的数量不能超过某一
    限度，如 500，奇兵状态下可以使用计谋和攻击，一旦使用则会
    恢复正常状态，被敌军发现；失败则陷入混乱。

9、 落石，luoshi

    部队携带圆石，并且本部队处于山的地形，可以对相邻房间的敌
    军实施落石之计，成功则敌军损失一定数量的部队以及较短时间
    的混乱，失败则浪费圆石和陷入较短时间的混乱。

10、叫骂，jiaoma

    对相邻或邻近的敌军部队使用叫骂之计会降低敌军士气，失败则
    敌军士气不降反增。

11、灭火，miehuo

    扑灭本部队所处房间的火势或相邻房间的火势，失败则火势保持
    或蔓延，部队陷入混乱或损失较少的一定数量。

12、谎报，huangbao

    防守方专用，对相邻的敌军部队谎报军情，使该部队误以为己方
    城市收到攻击，仓皇撤退或士气大跌（完全成功则撤退，不完全
    则降士气）；失败则部队陷入短暂混乱。
//thus i think we need to redo the task structure..:P

13、假传命令，fakeorder

    只能对非指挥官所在部队使用，假传指挥官命令，以现有的指挥
    系统发出行军到某处或在某处待命的命令，有一定时限，如果是
    玩家控制的部队，将暂时丧失控制权；失败则部队陷入混乱。

14、沉着，chenzhuo

    可以对被假传命令的本部队或相邻的部队使用，成功则恢复控制
    权；失败则目标部队的士气下跌。

15、天变，tianbian

    作法引起天气的变化，成功则天变，失败则被雷劈，体力、精神
    完全降为 0，无法对部队发出命令（如果部队还有其他玩家则另
    当别论）。

16、风变，fengbian

    改变风向，成功则风向改变，失败则同天变。

由于有一些其他的技能如奋发（被包围后激励士兵同时向相邻的敌人
进攻）、乱射、修复城墙、挖掘陷井、堆放柴火等可以归类成特殊技
能，将用另外一个帖子。还有关于侦察（warinfo）的改动也将另外
贴出。


---
作者: Ice
题目: 关于防守方撤退
日期: Sun Aug  1 00:47:40 1999
1、 防守方需要退到地图的边缘地带或某一特定房间才能撤退；
2、 防守方撤退后兵力损失一半或以上；
3、 士气降低一半，并于撤退目的地的士气和训练度加权平均；
4、 防守方撤退的官员成为撤退目的地的闲职；
5、 损失声望。


---
作者: Fire
题目: >关于防守方撤退
日期: Sun Aug  1 01:47:17 1999
On Sun Aug  1 00:47:40 1999 Ice wrote post #717:
> 1、 防守方需要退到地图的边缘地带或某一特定房间才能撤退；
> 2、 防守方撤退后兵力损失一半或以上；
> 3、 士气降低一半，并于撤退目的地的士气和训练度加权平均；
> 4、 防守方撤退的官员成为撤退目的地的闲职；
> 5、 损失声望。

ice's idea is right, will try to put it
in some where


---
作者: Ice
题目: about jbsj&jbhj
日期: Sun Aug  1 08:51:11 1999
jbsj: can learn from shuijing till level 20, can learn from bing shu
      from taijian till 30
jbhj: i think we can set fire_officer in each level 5 city thus won't
      make changan the only city can learn this, and limit can learn
      from officer till level 20, from taijian level 30


---
作者: Ice
题目: >about the troop number
日期: Tue Aug 10 04:40:18 1999
well, it's reasonable to keep a large amount of troops in the 
nation's border, and I think most guan are main warfields
if we have enough players to play later on. let's consider it
from the complete viewpoint(after the troops and stuffs transfer
completed), at first, i think guan's usage is mainly for defence,
but not for recruiting soldiers in the guan area, if the nation
need to defence at a guan or prepare attacking from, troops may
be transferred there, except only recruiting from the area, so
if a nation want to concentrate on some important cities, they should
transfer soldiers there, so i still think the limitation of recruiting
is reasonable for any cities.  anyway, i think we can make the following
adjustments:

1. implement the recruit limitation after transfer system completed;
2. extend the period of the people rebel if too many troops in the area,
   for example, extend from my planned 3 months to half year.
// i think half year is enough for a nation to make up its mind to
suppress the people or transfer them to a nearby larger area to stand by,
and i think if the assist_war/defence completed, those small areas dun
need to keep a very large amount all the time, however, they can keep
transferring the troops b4 that area's people rebel.

let me take a papaya example, zhuge liang sent ma su to defence jieting
while he heard that sima yi is on his way of attacking, so i think those 
small areas should keep a large amount of troops when it's necessary, but
not all the time.


---
作者: Ice
题目: about black namelist
日期: Tue Aug 10 02:24:56 1999
(1 )0           艾尔托沙(lionking)    仍有效

can block settled char? even not officer?

* doubt


---
作者: Group
题目: about the troop number
日期: Tue Aug 10 01:59:31 1999
i agree that for cities the the troop number should be limited for
recruiting. but i think that the number limited for a city is not
depended on the city population. this is because for some low level
cities, country need them store a number of troops to defend on
enemies since most of these cities are on the boundage between
countries. this can be done by transfer the soldiers and troops
between cities. the punish for store a huge number troops should be
rduced.


---
作者: Ice
题目: about bandit system
日期: Mon Aug  9 20:17:17 1999
另外还需要一个控制土匪的时间表，在每年开始的时候就设定，
其使用与作用如下：

1、 当年头为天道之年的时候，悍匪们会出动到某州作乱，直至
    被完全消灭或新的一年开始；平常的时候只有一般土匪作乱，
2、 控制土匪的出现不至于太频繁，一般土匪每年随机攻击20个
    城市，悍匪每个月攻击州内的1－2个城市，直至被消灭。
3、 每州有一至两个悍匪待选，当天道之年的时候，选取2－3个
    州出现悍匪。


一、一般土匪：

目的：攻占帅帐，掠夺某城市。
特点：没有明确的领导，数量较少。
数量：为被攻击城市驻军与民兵之和的 1/4，最多不超过 5000。
     （如果象从前的每个土匪头子都只带500兵似乎不太够）

二、悍匪：

目的：在某一个州内流窜，烧杀抢掠，无恶不作。
特点：有明确的领导者，数量较多，有组织。
      （如张角等）
数量：5000－20000，当出现时为某一数量，不会因每次出场而
      随机改变，只会越战越少，直至被完全消灭。

I may start to collect the names and status of strong bandits
if all of us think it can be implemented.



---
作者: Ice
题目: about disaster system
日期: Mon Aug  9 20:15:59 1999
在每一年开始的时候设置一个福祸时间表，如果当年受影响的是“福”，
那么只从“降福”中抽取，反之亦然。使用时间表控制的使用和作用如下：

1、 不用每个月计算是否发生灾祸，只要依照本年度的时间表就可以了；
2、 避免同一个城市或地区同时遭受多场灾祸；
3、 当好年头的时候为福，坏年头的时候为祸，无影响的年头则不过不失，
    灾祸的影响不会太过于频繁；
4、 以后的占卜可以用以预告灾祸在何时何地发生，只要从时间表上抽取
    就可以了；
5、 除了丰收和歉收可能在每年都发生之外，其他的不会过于频繁；
6、 每年开始的时候，只要从相应的天灾或降福中抽取一至两种发生，并
    避免洪水和旱灾同时发生。


我想天灾人祸还是采用现在的发饷的独立计算的方法较好，会比较快和不
会同时flood太多。

时间->在某一季节可能发生。
预防->可作预防措施，如提高治水度，放火度。。。
地区->有可能发生的区域。

一、天灾

1、 地震

影响：城墙防御度下降 50%，城市指数下降 10%，人口，驻军损失 10%，
      城市黄金、粮食、物资损失 10%，安定下降 30。
      （当城内有工场时，工场全部摧毁）
时间：任意。
预防：无。
地区：全部。
发生：【谣言】某人：某州发生强烈地震，州内各城市遭到严重损毁。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 1 个州
      为发生地震的。

2、 洪水
影响：治水度下降 30%，城市指数下降 ((200 - 治水度) / 2)%，
      城市黄金、粮食、物资损失 ((200 - 治水度) / 2)%，
      人口、驻军损失 ((200 - 治水度) / 4)%，安定损失 20。
      （当城内有工场时，工场被摧毁或降一级）
时间：春、夏。
预防：治水度高，损失较小。
地区：中、东、南部。
发生：【谣言】某人：某地被洪水淹没，当地损失惨重。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 5 个城市
      为发生洪水的。

3、 大旱
影响：农业指数下降 10%，粮食损失 20%，人口损失 5%，安定损失 20。
      （当城内有工场时，与农业有关的工场被摧毁或降一级）
时间：夏、秋。
预防：无。
地区：全部。
发生：【谣言】某人：某地久旱不雨，当地百姓叫苦连天。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 5 个城市
      为发生洪水的。

4、 蝗虫
影响：农业指数下降 10%，粮食损失 20%，安定损失 10。
时间：夏、秋。
预防：无。
地区：全部。
发生：【谣言】某人：某地忽然出现大批蝗虫，当地农业遭受严重损失。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 5 个城市
      为发生蝗灾的。

5、 失火
影响：防火度下降 30%，城市指数下降 (200 - 防火度) / 2)%，
      城市黄金、粮食、物资损失(200 - 防火度) / 2)%，
      人口、驻军损失 (200 - 防火度) / 4)%，
      （当城内有工场时，工场被摧毁或降一级）
时间：任意
预防：防火度高，损失较小。
地区：全部。
发生：【谣言】某人：某地因防火不足，当地发生严重火灾，损失惨重。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 5 个城市
      为发生失火的。

6、 歉收
影响：农业指数下降 20%，粮食收获只有 50%，安定损失 30。
时间：秋。
预防：无。
地区：全部。
发生：【收获】收获的季节到了。
      【谣言】某人：某地粮食歉收，当地百姓怨声载道。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 10 个城市
      为歉收的。

7、 飓风
影响：城市指数下降 20%，人口、驻军损失 5%，安定损失 30。
      （当城内有工场时，工场被摧毁或降一级）
时间：夏。
预防：无。
地区：全部。
发生：【谣言】某人：某州遭飓风侵袭。城市遭到严重破坏，百姓多有死伤。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 1 个州
      为发生飓风的。

8、 瘟疫
影响：城市指数下降 10%，人口、驻军损失 20%，安定损失 50。
时间：任意。
预防：无。
地区：全部。
发生：【谣言】某人：某州爆发瘟疫，一时人心惶惶，百姓纷纷迁离。
      如果当年天干地支的影响是“祸”，则在受影响的地区中抽取 1 个州
      为发生瘟疫的。


二、人祸

1、 暴乱
影响：城市指数下降 10%，人口损失 10%，驻军损失 10%，安定损失 30。
时间：每个月上旬结算时。
预防：镇压。（cmd suppress in localmeeting）
      当百姓开始议论后，可以在当地会议上提议镇压百姓，镇压后安定损失 30，
      人口损失 random(5%)，驻军损失 random (5%)。
      恢复到第一个月时的状态，如果该城市继续保留超量的军队，暴乱仍然会
      发生。
      【谣言】某人：玄冰率军镇压某地百姓，平息了当地的流言。
地区：任意。
发生：当某个地区的驻军数量超过当地所能拥有的驻军数量时，
      第一个月：
      【谣言】某人：某地百姓不满当地苛政，议论纷纷，一时民心大乱。//酝酿中
      第二个月：
      【谣言】：某地百姓不满当地苛政，议论纷纷，一时民心大乱。//酝酿中
      第三个月：
      【谣言】：某地百姓愤然揭竿而起，发动了暴乱。

2、 匪祸
影响：如果被攻占，
      城市指数下降 5%，人口损失 5%，城市的黄金、粮食、物资损失 10%，
      安定损失 20，士气损失 20。
      （如果当地有工场，则工场被摧毁或降级）
      如果战胜：
      安定上升 20，士气上升 20。
时间：任意。
预防：无。
地区：任意。
发生：详见post about bandit。


三、降福

1、 丰收
影响：农业指数上升 10%，粮食产量为 200%，安定上升 20。
时间：秋。
地区：任意。
发生：【收获】收获的季节到了。
      【谣言】某人：某地喜获丰收，当地百姓欢天喜地。
      如果当年天干地支的影响是“福”，则在受影响的地区中抽取 10 个城市
      为丰收的。

2、 瑞雪
影响：农业指数上升 10%，安定上升 10。
时间：冬。
地区：北、中、西。
发生：冬季的第一个月的上旬。
     【谣言】某人：某地降下瑞雪，当地百姓额手称庆。
      如果当年天干地支的影响是“福”，则在受影响的地区中抽取 5 个城市
      为降瑞雪的。（在北、中、东三区内，如果不在则不发生。）

3、 祥瑞
影响：城市指数上升 10%，安定上升 30，人口上升 10%。
时间：任意。
地区：任意。
发生：【谣言】某人：某地百姓发掘出某物，纷纷视为祥瑞。
      如果当年天干地支的影响是“福”，则在受影响的地区中抽取 2 个城市
      为发生祥瑞的。
      某物：前朝的铜鼎、铜雀、blah blah

really cannot find out more good deeds the god can do..:(



---
作者: Ice
题目: about fate system
日期: Mon Aug  9 20:15:21 1999
I think the implementation of fate system is complex, however, 
I think this system has a great potential for our future development,
it'll be easier to handle many events for us if we use it.

that's all of my promotion of the fate system, pls consider it
seriously bah..:P


---
作者: Ice
题目: plan of implementation of fate system
日期: Mon Aug  9 20:11:58 1999
一、天干地支的设立：
                                                            
天干＝（10|"甲","乙","丙","丁","戊","己","庚","辛","壬","癸","）
地支＝（12|"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥）

两者依次配合成六十个单位 （通称"六十甲子"）, 
循环使用. 具体顺序如下:

甲子   乙丑   丙寅   丁卯   戊辰   己巳   庚午   辛未   壬申   癸酉
甲戌   乙亥   丙子   丁丑   戊寅   己卯   庚辰   辛巳   壬午   癸未    
甲申   乙酉   丙戌   丁亥   戊子   己丑   庚寅   辛卯   壬辰   癸巳    
甲午   乙未   丙申   丁酉   戊戌   己亥   庚子   辛丑   壬寅   癸卯    
甲辰   乙巳   丙午   丁未   戊申   己酉   庚戌   辛亥   壬子   癸丑   
甲寅   乙卯   丙辰   丁巳   戊午   己未   庚申   辛酉   壬戌   癸亥

公元184年＝甲子年

ＭＵＤ时间：三国志一百八十四年一月上旬，甲子年。

二、天命之年：

天道循环，凡事皆有自然之道，万物皆有始至终，由生至死。是命理中不变的真理。
天道命理学中，六十年为一甲子，一甲子中，有些年份是天道大盛之年，紫微星斗
必光旺，就是天干为甲，丙，戊，庚，壬。地支为寅，申的年份。

共计有：

丙寅 壬申 戊寅 甲申 庚寅 丙申 壬寅 戊申 甲寅 庚申

作用：

1、 在这些天道之年中独立的玩家，可以获得所在城市官员不离职的便利。
2、 在天道之年开始时（一月一日），拥有最多城市、最多人口、最多官员等的国
    可以获得声望或其他的奖励。（如new rep = old rep * 1.5）。
3、 只有在天道之年才能称帝。（俗称黄道吉日 * fool）
4、 悍匪们会假借好年头趁机作乱，详见post about bandit；
5、 其他（还可以加）

三、天道与地理：

天道对地理有一定的影响力。自然万物都有五行，地理亦然。与每一年的天干五行
属性相同的地理方向也必有些城市特别繁荣。

天干之五行属性表：
------------------
木 ： 甲，乙，东方。
火 ： 丙，丁，南方。
土 ： 戊，己，中央。
金 ： 庚，辛，西方。
水 ： 壬，癸，北方。

三国方位分布：

东方：兖州，青州，徐州。
南方：扬州，郢州，交州，南荆州。
中央：司隶，豫州，北荆州。
西方：益州，梁州，凉州，雍州。
北方：并州，冀州，幽州。

作用：

1、 在同一年份里攻陷不同方位的城市可以获得不同的奖励，举个例子，当天干为
    甲、乙时，攻陷在东部州内的城市，参与战争的玩家可以获得加倍的经验奖励。
2、 当商人系统完善后，可以以年份为商队停留的依据，当年份为甲、乙时，商队
    会在东部的随机城市停留。（原本的商队设想是哪里的商业值高，或太守提出
    一定的条件以吸引商队，但如此一来，穷的城市就越穷，还是让商队自由选择
    似乎为好）
3、 其他（还可以加）


四、天道与福祸：

天道对地理有一定的影响力还表现在降灾降福上。幸运和灾难的发生，也因年份的
改变而容易集中在某些地带，简单来说，两者的发生由于五行的相冲相生相化所造
成的。影响两者的最大因素是年份的地支，道理与年份的天干影响地理一样。灾难
和幸运的发生刚好是相反的。灾难和幸运的发生刚好是相反的。

详见关于福祸（天灾）系统的post和/wiz/ice/txt/fate_table.txt




---
作者: Ice
题目: about the max amount of troops each city can recruit
日期: Mon Aug  9 18:18:45 1999
I think each city should have a limitation about how many troops
can be recruited in that city, i think maybe we can use fomula like this:

max no. of troops can be recruited
= (current population / 10 * (safety / 200))

in this case, a 1M city with full safety can recruit 100k troops, 
which is supposed to be enough to defence any proper attack, and if
a city has more troops exceed this limitation for one month, ppl may
rebel, pls see my upcoming disaster post for detail about this point.


---
作者: Fire
题目: today's work:
日期: Mon Aug  9 10:21:14 1999
1 reduce the time for feedgoat to make it easier
2 fix several bugs in war
3 add the function for boy to destroy empty rooms


---
作者: Ice
题目: changed a few names in ranknation
日期: Sun Aug  8 14:20:25 1999
军师 -> 总军师
主簿 -> 长史

to avoid confusion with ranklocal


---
作者: Fire
题目: about the super lag in war
日期: Sat Aug  7 08:31:56 1999
now the war seem super lag.
i have checked and find that there are two reason
1, the defence part use pursue the attack's leader
  if there are many defence troop the speed will be very slow
2 our system's memory seem run out, so have to use
  a lot virtual memory, this seem a reason
  when i reboot the system and try war
  even still lag but seem much faster than before


---
作者: Ice
题目: about book in palace
日期: Sat Aug  7 21:52:57 1999
hmm, sounds that if a ppl's skills is 31, still cannot learn
book volume 2 now, even enough literate....:(

when fire has time, pls check it bah.:D

addoil.:P


---
作者: Ice
题目: about ordered objs
日期: Sun Aug  8 01:35:23 1999
I think now it's the time to make cmd call's option 5 available.
bcoz nowadays money has weight, and player is trying to order better
obj, thus we can make the player can give his ordered obj to qb, means
only he dest that obj, nothing will be added in qb's status, since qb
no morale parameter.:P


---
作者: Fire
题目: >about book in palace
日期: Sun Aug  8 03:10:15 1999
On Sat Aug  7 21:52:57 1999 Ice wrote post #731:
> hmm, sounds that if a ppl's skills is 31, still cannot learn
> book volume 2 now, even enough literate....:(
> 
> when fire has time, pls check it bah.:D
> 
> addoil.:P

if over 30, need get some experence


---
作者: Fire
题目: reduce the obj in system
日期: Sun Aug  8 05:26:03 1999
In order to reduce the obj numbers in system, following
adjustments have been added.
1. when npc auto move, will check if the target room is
   already in system, if not will not move to that room
2. npc char will just add one cloth
3. add one timer m_char in m_charnpc to show how long this
   npc has lived, if too long will auto_disappear.
4. cpu command updated so wiz can check obj numbers more easily
5. further work will try to clean_up unused rooms


---
作者: Fire
题目: a strange bug
日期: Sun Aug  8 08:11:25 1999
some players such as flyee and xmzy can't
see the chat of them selves, this
happened before to some other players, is
it a very strange bug ?


---
作者: Fire
题目: 关于房间的几个系统调用。
日期: Tue Aug 10 09:21:50 1999
1. 显示各地区的房间，加载到内存的房间，和所有该地区加载到内存
   的物品(npc,player,obj)统计：
@"/a/area_stat"->dis_all()
2. 显示所有内存中的战争房间：
@objects((:$1->is_gridroom():))
3. 清除一地区内的所有战争房间。
@MAP_D->destruct_area("chenliu")
  注意：在没有BUG的情况下，一地区的战争房间应在该地区
        战争或训练结束后自动清除。所以如果没有BUG，不要
        手动使用此指令。
4. 改进了war后自动清除战场的功能，同时加强了boy的清理不用房间
   的功能。系统负担降低不少。:)


---
作者: Ice
题目: made little change about ev_king/king.c
日期: Tue Aug 10 16:33:40 1999
1. changed to if arrive within 2 mins, will get extra rewards;
2. changed to if money > 3000 will be robbed by han di;
3. changed if rep > 100k, will be rewarded little bit more;
4. changed if localcontri > 1000, will be rewarded skills.

* escape


---
作者: Ice
题目: about lack of gold on hand
日期: Tue Aug 10 18:13:03 1999
since now player cannot hold 3k gold on hand, thus player
king cannot order hxbma without wiz's help..:(
how about use the method of cmd donate:

while a player asks maker about order, he will be check if he
has enough gold on hand, if not, the make will say the following:

紫髯伯奇怪地看了你一眼，道：将军的钱好像没带够。
紫髯伯皱了皱眉头，低声说道：既然将军这么急切，我倒有个办法。。。
紫髯伯继续道：我可以叫人到将军府上取钱，不过要加百分之十的手续费，将军意下如何
？
回答：（yes/no）
//yes
y
紫髯伯从你的帐上划走了三千三百两黄金。
紫髯伯对你点点头，道：活儿我已经接下，待汗血宝马完成后即刻通知将军验取。
//no
紫髯伯无奈地耸了耸肩：既然将军不急，那还是改天再来吧。

gold will be deducted from either bank account or salary account.:D


---
作者: Ice
题目: something about the char
日期: Tue Aug 10 23:10:32 1999
1. today ztian ind in changsha, 关羽 has national rank, so he
   should be sent to be 闲职 in the remaining cities, but he wasn't.

2. xixixi war runan, runan lost, but all former officers in
   runan keep their position, their ranklocal, area, nation blah blah
   all not changed, thus those officers still occupying the positions,
   and even 2 leader.

is that bcoz fire changed sth? fire pls check.:P


---
作者: Yuyin
题目: help
日期: Sun Aug 15 08:02:19 1999
row and group
i use cuteftp
i can connect our MUD
but i can't see the file in our MUD
是不是 setting 错了 ?
是的话应该怎么设
我看了一些主页也不知到是什么原因
请 mail 给我
thanks


---
作者: Fire
题目: about clean_up
日期: Sat Aug 14 06:59:17 1999
in order to save memory, the boy call room's clean up
regularly, if you want an obj don't be destroied
by the clean_up, in the obj add one function as below

int query_clean_up() {
    return 1;
}

then this obj will not be clean up even in a box or in sth


so a very useful function, isn't it ?
:)


---
作者: Ice
题目: about private buy
日期: Fri Aug 13 21:00:32 1999
bcoz the salary can only be withdrawn but cannot be put back
any more, and actually the merchant should transfer gold from
player's bank account..:P so i think it'll be better change the
private buy consume bank account only, thus player can use
a more modern way for shopping, and they may deposit their money
in the bank, make the bank meaningful.

btw, i think we can just change the ask maker about order to
consume bank account only as well, thus player don't need to hold
that large amount of money on hand and we can enlarge the limit
of bank account from 1000 to 3000, no need to change much then.:P

actually i cannot find the bank is useful now..:P


---
作者: Ice
题目: to stefan:a very strange bug
日期: Fri Aug 13 14:53:43 1999
i think maybe sth wrong, but dunno what's wrong, let me post
the log here for reference:

> 【闲聊】康熙(kings)：我看不见我说的话
snoop kings;成功。
' say sth in chat;你说道：say sth in chat.;%玄冰说道：say sth in chat.
> %chat 我看不见我说的话%
【闲聊】康熙(kings)：我看不见我说的话
%【闲聊】康熙(kings)：我看不见我说的话
' i saw u can yah;你说道：i saw u can yah.;%玄冰说道：i saw u can yah.
%chat I can't%
【闲聊】康熙(kings)：I can't
%【闲聊】康熙(kings)：I can't

I think snoop is whatever he can see, i can see, but he insist he cannot,
same bug occured time to time, but sometimes after relog, it disappeared,
and he can see all else channels, except gossip, i think there was a post
by fire talking about the same problem, and seems not appeared while using
the old driver, stefan pls take some time to check bah..:P


---
作者: Ice
题目: about absense of localmeeting
日期: Fri Aug 13 01:40:15 1999
I tried to be absent for localmeeting, and i think the former
setting is 20 secs not in meeting room will be counted absent,
but the first time i stay outside, it costs 40 secs to say i am
absense, and the 2nd time, i give out a suggest of localbuy, then
it last 3 mins without announcing any absent msg.

who has time check check it bah.:P

* escape


---
作者: Fire
题目: about the horse
日期: Thu Aug 12 08:20:32 1999
now the formula is
time = 5 + (speed * distance) * 0.2
the speed for mache is 15


---
作者: Fire
题目: about the horse system
日期: Thu Aug 12 07:10:06 1999
名称    等级 价钱  攻击力 消耗金/粮 速度 耐力
马车                                 15   --
骡子      0   1      0     0/20      20   4
矮脚马    1   10    +1     0/10      12   5
小红马    1   15    +1     0/12      11   4
花斑马    1   20    +1     0/10      11   4
灰鬃马    1   30    +1     0/15      11   5
黄膘马    2   80    +2     1/20      10   6
黄鬃马    2   100   +2     1/35      10   7
黑鬃马    2   120   +2     1/40       9   7
褐鬃马    3   200   +3     2/40       8   8
胭脂马    3   250   +3     2/45       8   8
青骢马    3   300   +3     2/50       7   8
乌骓马    4   400   +4     3/50       7   9
大宛马    4   450   +4     3/55       7   9
汗血宝马  5   1000  +5     4/55       6  10
的卢      7   -     +7     5/60       6  12
绝影      8   -     +8     5/70       5  14
爪黄飞电  9   -     +9     5/75       5  15
赤兔马   10   -     +10    10/80      4  17
公式：t=时间，d=距离, s=速度。k调节系数，目前取0.5
t=10+(d*s)*k


---
作者: Fire
题目: >estimated horse list
日期: Thu Aug 12 06:53:50 1999
about the horse
ice's data is right, but for the mache
still need a little consideration, it should be
slower than 12, because it can reach the target directly
so i suggest it is 15.
because for long distance journey, the time become more
and the journey has been broken several times
so need add some adventures in the way.
for example, when pass a froest and the player
hear some strange sound, then system ask if the player
want go and find out what is there, if input no, continue 
travel, if yes, enter the froest and may find something
interesting, of cause need overcome some difficult
and get special reward
for the speed, i think need adjust a little
the speed from level 1 to level 5 go
from 12 to 6, and for level 5 to level 9 go from
5 to 4, this may be mroe reasonable, or i will post
a new list :)


---
作者: Ice
题目: estimated horse list
日期: Thu Aug 12 05:07:23 1999
名称    等级 价钱  攻击力 消耗金/粮 速度 耐力
矮脚马    1   10    +1     0/10      12   5
小红马    1   15    +1     0/12      11   4
花斑马    1   20    +1     0/10      11   4
灰鬃马    1   30    +1     0/15      11   5
黄膘马    2   80    +2     1/30      11   6
黄鬃马    2   100   +2     1/35      11   7
黑鬃马    2   120   +2     1/40      10   7
褐鬃马    3   200   +3     2/50      10   8
胭脂马    3   250   +3     2/45      10   8
青骢马    3   300   +3     2/60      9    8
乌骓马    4   400   +4     3/80      8    9
大宛马    4   450   +4     3/75      8    9
汗血宝马  5   1000  +5     4/100     7    10
的卢      7   -     +7     5/150     6    12
绝影      8   -     +8     5/180     5    14
爪黄飞电  9   -     +9     5/200     4    15
赤兔马   10   -     +10    10/400    3    17


mache's speed is 12 bah, slow enough, and maybe double the
transport fee, thus make buying horse more worthy.

*grin


---
作者: Yuyin
题目: fire
日期: Wed Aug 11 08:12:44 1999
我想结婚，请尽快把 marry system 做好
addoil fire


---
作者: Yuyin
题目: bug 报告
日期: Wed Aug 11 07:45:58 1999
我 clone /wiz/yuyin/obj/bed.c
 ------- /wiz/yuyin/obj/bed.c:26
 Warning: Function inherited from 'std/modules/m_mountable.c' does not match
current function in return type ( void vs int )
int mount_it_already()


---
作者: Ice
题目: adjustment of localtax
日期: Sun Aug 15 16:47:35 1999
1. if((p_safe<30)||((p_safe-(p_tax-p_oldtax)*2)<=30))
2. if(p_tax-p_oldtax>20||p_oldtax-p_tax>20)

cannot change tax.

hope it can restrict player use tax and sendfood only to raise
the safety a little bit.  however, i think we may add a time limit,
like an area cannot change tax more than once in the same day,
it's a kind of 朝令夕改 bah.:P, or we can set if they insist to change
more than once in the same day, the increase of tax will be - 4* safety,
the decrease of tax will be + 0.5* safety.

* grin


---
作者: Row
题目: >to stefan:a very strange bug
日期: Sun Aug 15 21:55:07 1999
On Fri Aug 13 14:53:43 1999 Ice wrote post #758:
> i think maybe sth wrong, but dunno what's wrong, let me post
> the log here for reference:
> 
> > 【闲聊】康熙(kings)：我看不见我说的话
> snoop kings;成功。
> ' say sth in chat;你说道：say sth in chat.;%玄冰说道：say sth in chat.
> > %chat 我看不见我说的话%
> 【闲聊】康熙(kings)：我看不见我说的话
> %【闲聊】康熙(kings)：我看不见我说的话
> ' i saw u can yah;你说道：i saw u can yah.;%玄冰说道：i saw u can yah.
> %chat I can't%
> 【闲聊】康熙(kings)：I can't
> %【闲聊】康熙(kings)：I can't
> 
> I think snoop is whatever he can see, i can see, but he insist he cannot,
> same bug occured time to time, but sometimes after relog, it disappeared,
> and he can see all else channels, except gossip, i think there was a post
> by fire talking about the same problem, and seems not appeared while using
> the old driver, stefan pls take some time to check bah..:P

maybe its the problem of color setting...


---
作者: Fire
题目: about the bug in job quote
日期: Tue Aug 17 02:54:56 1999
that is a problem, but he can't get personal
reward for finish so many jobs
so i will fix this when we got enough types
of jobs for diffent level of jobs
thank ice
we all miss you, come back when possible :)
and we will keep your wiz position as you have
contribute so much to our mud.


---
作者: Ice
题目: about job record
日期: Tue Aug 17 01:51:51 1999
oops, just wanna post a message forget to tell b4 i leave, then
it crashed..:(
 
本次运行时间二小时三分钟。
你被国产长征三型火箭送回到巫师大厅！
> post
请输入留言主题， . 表示放弃。
留言主题：霎时地动山摇，天翻地覆，整个世界毁于一旦！
你离开了三国。

kick, this time not me leh bah..:(

well, anyway, got say it here.

about the job record, I snooped xixixi when he keep transferring
himself very often, and i found there is a bug in the job record,
when a player ask for a job in A area, and then he finish that job
and doesn't report to the leader, he transfer to B area, and ask 
for the same job, the former job is not counted in the job record.
with this way, i found xixixi's id did around 40 visitpeople within
30 mins, totally ignored our job quote..:P

so I think when ask for job in an area, it should be recorded, even
the player changes his area, it should be counted.

well, it might be my last report anyway, won't have much time any
more..:P

nocry, nosigh, we have a tough and innovative wiz team, I expect
sanguo will be perfect and completed in no time.:)

thanks for everyone's support..:D

addoil all!


ps. I will try to be back whenever i can.:)


---
作者: Fire
题目: about the message of fight
日期: Thu Aug 19 05:34:24 1999
yuyin has written three fight message for ji, sword and unarmed
it seems that the unarmed has bug in it, so 
please fix the bug first
I have installed the ji.c and sword.c
they works well, addoil
another thing is that when you use ftp to upload and
download, please use ASCII mode.
thanks :)


---
作者: Yuyin
题目: bug
日期: Thu Aug 19 11:23:28 1999
mail fire
------- /secure/obj/mailers/mailer.c:291


---
作者: Group
题目: about the channel
日期: Fri Aug 20 03:47:44 1999
recently there are some bad players use gossip channel to say dirty
words and flood.

i think there should be a cmd to force close these players channel,
or even ban the ip.
is there got 1? if no, can do it at once? it is not possible to hope
all players come here are polite..sigh

group


---
作者: Stefan
题目: >>to stefan:a very strange bug
日期: Wed Aug 18 08:18:50 1999

I guess it could be caused by color, or mud client.
Tintin or zmud can sometime gag some information.
for example, zmud will gag the password. If the password matches some
color code or some string in the chat message,
it will be gagged. 

dunno if it helps. But one thing for sure is that the message did get
through, it is the player's client did not show it correctly.


---
作者: Ice
题目: about transferring
日期: Wed Aug 18 07:27:06 1999
I think now we r using simple transfer is fine at present, later
we will turn it to a task anyway, but .......

i haven't tested any transferring, so far as i saw, war became too
simple if no restriction of transferring.

1. national meeting can hold any time thus a 100k troops might be
   transferred from the northest to the southest city within 20 mins
   without any loss if train and morale both full, is it too fast?
2. transfer has some kind of loss, but as xixixi posted, if train and
   morale both 200, it's no loss anyway, is that too simple for transferring?
3. if a nation get an area, then transfer back all troops, then sendfood,
   till the safety can war again, it's kind of tricks can be used..:P

so for the simeple mode now, may be we can make the following adjustment:

1. each transfer will lose some morale, like 10 each time;
2. make national meeting or transferring has some limits, like
   at the same day can only hold one national meeting or, if A area
   transfer troops to B area, B area cannot transfer troops immediately,
   at least in the same day;
3. transferring stuff, gold, and food need rely on the troops in the startup
   area, if the proportion of food/troop, gold/troop blah blah is in some
   certain number, and/or safety in both area both high, the loss
will be less.

cannot help to post..:P

* escape


---
作者: Yuyin
题目: i want make a wiz_cmds help for chinese
日期: Fri Aug 20 15:43:41 1999
由于现在我的英文水平还不太高
所以我想一些巫师也不会比我好很多
so 我想做一个 wiz_cmds help for us
希望各位巫师能给我多一点的帮助
chat* thank


---
作者: Ice
题目: >about the channel
日期: Sat Aug 21 01:54:51 1999
strongly agree, add a vote block channel bah..:)
and a block tell


---
作者: Flee
题目: >> about the channel
日期: Sat Aug 21 01:55:15 1999
agree ..
.'


---
作者: Ice
题目: additional notes about transfer
日期: Sat Aug 21 02:02:14 1999
1. when A area wants to transfer troops to B area, check B's
   safety, if lower than 100, can say:
   当地民心不稳，再进驻军队恐怕要引起暴乱呀。
2. check B area's existing food, gold, stuff, if cannot support
   the troops for 3 months, it'll say:
   当地黄金/物资/粮食不足，难以维持军队的补给。


---
作者: Ice
题目: additional note about 国师
日期: Mon Aug 23 13:18:30 1999
1. 国师cannot pos on NPC king, that is cannot transfer king to
   another area, cannot get taishou from king, king is always
   the leader of capital;
2. 国师 cannot 迁都，I think later capital is an important part,
   just like in SAN6, if a city doesn't have link with capital,
   it cannot hold localmeeting and nation meeting, what player
   can do there is only do normal job, thus the rest player will
   have to work hard to get back the link from capital to that
   blocked city.


---
作者: Ice
题目: about the bug in chenghu_d
日期: Mon Aug 23 13:10:18 1999
I think it's the emote with $n0a or $p0a sth got bug...:P
check check bah...:P
addoil


---
作者: Ice
题目: about horse status
日期: Sat Aug 21 11:40:42 1999
differentiate the 坐骑挨饿零个月 and 没有坐骑 bah,
confused..:P


---
作者: Ice
题目: about city walls
日期: Sat Aug 21 18:18:47 1999
I think larger cities should have larger or boarder city walls,
like city size can be 4*4 for lv 5 cities, can be 3*4 or 4*3 for
lv 4 cities, and maybe some 护城河 around it, grin.....

the point is larger cities r supposed to be harder to occupied,
actually in my memory, if the defence troops insist to defence
inside the city, the attack side have to use more troops than
defence side to get the city, and have to pay more if the wall
is strong enough.

well, maybe should implement all warmaps first then adjust them.:P

* pusha row
* escape


---
作者: Ice
题目: add a board in qiao guolao's room bah
日期: Sun Aug 22 09:27:14 1999
add a board or some displays in qiao guolao's room showing that

烈火与小百合与三国志某年某月喜结连理。
梦幻家与汝琳于三国志某年某月喜结连理。

just for showing the marriage record, and displays the most recent
10 couples.:)


---
作者: Ice
题目: 婚礼礼金
日期: Sun Aug 22 18:20:53 1999
天下有雪恭恭敬敬收下黄金四千四百五十三两。

faint, I think if we don't change it, female id will be a trend
of making dummies..:P

suggest to make the following suggestion:

1. if the 礼金 over 300, 礼官 will say:
   礼官大吃一惊：这，这，这。。。这礼太重了吧。。。。
2. after the wedding is over, the bride will receive 60% of the gold:
   扣除婚宴费用和杂项，天下有雪恭恭敬敬收下黄金xxx两。
（bcoz there will be a NPC providing unlimited food in the wedding hall,
  and it charges the newly wedding couple, hmm, i made the NPC but cannot
   move obj from the NPC to the player, sb help to change it bah..:)
  it's /wiz/ice/npc/xiaosi.c, thanks..:) * pure ）


---
作者: Ice
题目: 关于结婚和结义后emote的称呼
日期: Sun Aug 22 20:10:45 1999
       结婚          结义
$R  贤妻，相公。  贤弟，大哥。
$r  浪货，混帐。   ?  ，  ?

hmm, i think it should be added sooner or later, together with
the objs..:P it's not a good sample anyway, change it to a better
one bah.:D

* wink




---
作者: Ice
题目: about business after unify
日期: Mon Aug 23 02:49:30 1999
if we are planning to use NPC countries as initial setting, I
think we have to adjust the 国师制度：

just let system random pick sounds not so fair to every player,
I think maybe we can use work more will be selected, and can be
changed time to time. The npc king will select from the highest
3 national contribution officer, and choose from one of them
quarterly, semiannually or annually, i think it could be more
fair than just keep not falling to 0.

so the process of restart a game will be if player join a NPC 
nation, he have to keep work hard to gain enough contri to be
competitive, and the player king will have less pressure but also
less officers work for them.

some additional notes of transfering, i think now the simple mode
transfer is still too simple, it's hard to be a smooth transition
towards the pro mode, i think we can make it as the following:

1. make the max safely transfering is 80% or 75% sth, it's always
   not safe enough to transfering things and stuffs without player
   leader, so for troops with 200 200, it can be a possibility to
   be 80%, or less.  xixixi's unify is benefited from the safe
   transfering, i think we are not hoping to see a flash unify
   every real month anyway. with the observation of the recent
   2 weeks, war becomes the only important part of our game.
2. while pro mode of transfering is completed, we can offer 2
   choice, to use a simple mode to take risk of loss, or use
   manual control to transfer with less risk.
3. I think transferring should has some limitation, however, we can
   add some later, what i hope is not to make it as KOEI's game,
   what i saw recently was exactly the strategy used in KOEI's 
   series, only the frontier has large size troops, all cities in
   the back are empty, and troops can be transferred continuously.
   so i think for the simple mode at present, we can say our point
   is, if u just dun care about the loss, u can keep on transfering,
   if u cannot bear the loss, go make the frontier cities better,
   however, war is not the only business in our mud.

that's it, hope xixixi won't unify too soon, i need some time to
arrange the initial list..:(



---
作者: Ice
题目: lost of chars
日期: Mon Aug 23 04:16:36 1999
共查到：420个角色。
faint, we lost around 20 chars, how come...:(


---
作者: Fire
题目: about unarm.c
日期: Mon Aug 23 10:44:04 1999
still has bug
sigh


---
作者: Stefan
题目: description
日期: Tue Aug 24 00:00:06 1999
我想是不是让各城太守挑起为本城做城市建设的重任，
完成未完成的 descrption. :)


---
作者: Stefan
题目: 有关 balance 的问题
日期: Tue Aug 24 00:40:51 1999
目前面对称帝的问题，我想还有一个有关新手和老手 balance 的问题。
就算重新划分了天下，如果老手继续朝统一奋斗的话，几轮过后，整个
mud 里的老手就会越来越强，新进来的人一点希望都不会有。

解决方法有好几种：

1. 统一后马上 cut skill，cut exp, 但是给老手的心理打击比较大。
可能因此失去一些玩家。

2. 自然更换法，什么也不做，等着老手疲倦了相继离开。不过也没个    
准，即使离开的话，其角色做为一个 NPC 也是很强的，最后会多出
来一堆全能的 NPC。

3. 全体 reset，大家一律从头开始。打击最大。

4. 设定上限，最后每个老手都一样厉害，并不太好。

我觉得这些方法没有解决根本问题，那就是难易成度于成就感应该成
比例。所以我有个建议，供大家参考..

skill 和 exp 都用一个整体的 rate 来调整，不设上限。打个比方说，如
果目前整体的 skill 都比较高，那么新手 skill 成长就更快。因为真正 
matter 的是相对的 skill 和 exp，所以只是缩小绝对值成长的速度，相
对值成长不变。比如目前要达到 80 级，需要花上 50 个小时成长，而 80
级在目前可以让你在整个 mud 中排第五名；后来所有人的平均水平都提高
了，要排第五名需要有 160 级，这时候一个新手要成长到 160 级，还是
只需要 50 个小时。这样表面看来，似乎新手占了便宜，其实在付出了 50
个小时之后，得到相对水平(第五名)是一样的。

当然一个负面影响是绝对值不断增大，最后会不会成为天文数字？很难预料..
还有个问题是算这个 rate 的时候是不是应当考虑一下整体水平的分布图，
是低手多还是高手多，不同地位的时候 rate 不同，等等。


---
作者: Ice
题目: initial list of restart
日期: Tue Aug 24 03:29:00 1999
10 player area:
qinchuan, yunnan, lingling, xinye, luling,
poyang, jinyang, qinghe, kuaiji, beihai.

NPC area:

1、马腾国
king: ma teng
xiliang: ma chao, pang de, ma tie
didao: ma dai, ma xiu

2 cities, 6 officers.

2、韩遂国
king: han sui
longxi: zhang heng, yang qiu
tianshui: liang xing, cheng yi
jieting: cheng yin
qishan: ma wan

4 cities, 7 officers.

3、董卓国
king: dong zhuo
changan: li su, li ru, dong cheng, zhang liao
anding: zhu juan
chencang: song xian
xianyang: lv bu, chen gong
jingyang: wei xu
huayin: guo si
tongguan: hou cheng
wuzhangyuan: gao shun
wuguan: fan chou
hangu: zhang ji
hongnong: hua xiong, wang yun
mianchi: zhong you
luoyang: lu zhi, huangfu song, yang biao
huguan: zhang xiu
hulaoguan: xu rong

15 cities, 23 officers.

4、何进国
king: he jin
taiyuan: pan feng, han fu
shangdang: xin pi
yanmenguan: xin ping

3 cities, 4 officers

5、张鲁国
king: zhang lu
hanzhong: yan pu, zhang song
xiabian: zhang wei
yangpingguan: zhang yin

3 cities, 4 officers.

6、刘璋国
king: liu zhang
chengdu: zhang song, deng xian, li hui, xu jing
dingjunshan: zhang ren
jiange: lei tong
zitong: wu lan, zou jing
fucheng: huang quan
mianzhuguan: fei shi
jianning: wu yi, dong he
jiangzhou: yang huai
yongan: yan yan, liu ba

9 cities, 16 officers.

7、刘表国
king: liu biao
xiangyang: liu zong, kuai liang, zhang yun, huo jun
shangyong: cao mao, kuai yue
chanxi: wen pin, fu yi
changbanpo: gan ning, su fei
jiangxia: liu qi, huang zu

5 cities, 13 officers.

8、刘备国
king: liu bei
jiangling: zhuge liang, wei yan, liu feng, yi ji
yiling: zhang fei, zhang bao
gongan: huang zhong, yin mo
huarong: guan yu, xu shu, wang fu
wuling: zhao yun, ma liang, jian yong

5 cities, 15 officers.

9、刘度国
king: liu du
changsha: xing daorong, liu xian
guiyang: pan rui
guilin: gong zhi
nanhai: bao long
chibi: zhao fan

5 cities, 7 officers.

10、袁术国
king: yuan shu
wan: ji ling, lei bo
runan: yuan yin
bowangpo: lv fan

3 cities, 5 officers

11、孙坚国
king: sun jian
chaisang: zhou yu, zhu zhi, zhang zhao, lu ji
yuzhang: sun quan, huang gai
xisaishan: lv meng, han dang
danyang: sun jing, sun yu
lujiang: sun ce, li yi
ruxukou: lu xun, ling cao

6 cities, 15 officers.

12、刘繇国
king: liu you
shouchun: chen heng, chen wu
hefei: yan xing
huaiyin: ze rong
jianye: taishi ci
wujun: zhang ying

5 cities, 7 officers.

13、曹操国
king: cao cao
xuchang: guo jia, xun you, xun yu, dian wei, cao ren, xiahou en, man chong
qiao: yu jin, liu ye
dingtao: cao ang, che zhou
puyang: xu huang, chan jiao
baima: cao hong, cao chun
ye: xiahou chun, cheng yu
chenliu: xiahou yuan, chen qun
guandu: li dian, yue jin

8 cities, 22 officers.

14、袁绍国
king: yuan shao
nanpi: yan liang, wen chou, zheng he, chunyu qiong, ju shou
daixian: guo tu
jicheng: yuan tan, tian feng
yijing: chen zhen
jieqiao: gao lan
pingyuan: yuan shang, feng ji
jinan: yuan xu, chen lin
bohai: shen pei

8 cities, 16 officers.

15、陶谦国
king: tao qian
xuzhou: chen gui, chen deng, sun gan
xiaopei: zang ba
xiapi: cao bao
guangling: mi fang
langya: mi zhu

5 cities, 8 officers.

16、公孙瓒国
king: gongsun zan
beiping: gongsun gong, yan gang
bailangshan: gongsun yue
xiangping: gongsun du

3 cities, 5 officers.

Total: 89 areas, 168 officers.

NOTE:
The first city is capital, king is always leader of capital.


---
作者: Fire
题目: >description
日期: Tue Aug 24 20:28:46 1999
On Tue Aug 24 00:00:06 1999 Stefan wrote post #785:
> 我想是不是让各城太守挑起为本城做城市建设的重任，
> 完成未完成的 descrption. :)

that is a good idea :)


---
作者: Ice
题目: about player data after unificationi
日期: Tue Aug 24 07:25:01 1999
I think we can keep player's skills, and not change at all.
however, I think we do need change erase all the local
contributions..:P


---
作者: Ice
题目: an idea of wounded soldiers
日期: Tue Aug 24 07:08:03 1999
If sb remembers the SAN5, there was a 伤兵 para in troops,
I think we can also implement this idea.

change the attacked msg to 伤亡 instead of 损失

when a troop is attacked, part of them died, and part of them
wounded, thus added a new type in the current troops called
wounded soldiers, and their train and morale will be fixed at
50 50, just like commando.

and further more, we can set it as a permanent type, wounded
soldiers cannot involve in attacking, they can only involve in
defence, and they will recover after some time, the recover rate
can be fixed now and later maybe we can add a base of hospital
in large cities, with those hospitals, wounded soldiers can
recover faster.  after the wounded soldiers recovered, they will
be considered as footman.

then we can add a skill called healing, and a trick of healing.
while in war, the player can heal his wounded soldiers if he has
enough herbs and enough skills.:P

that's it.



---
作者: Ice
题目: >description
日期: Tue Aug 24 05:08:04 1999
I think it'll be better that the king or area leader take
charge of that.  I visited a mud named 万国之国，it's a BIG5
version, and player can establish a nation, then design the map,
and room description and NPCs, after the wiz approved the setting,
it's his nation.

however, we cannot do exactly the same thing, bcoz our game is
more or less related to the history, so I think we should find out
a way to let player make descriptions by themselves and not just
giving out skills reward...:P

I think we have 80 areas without room description, it's a large large
work, how about giving out unique objs?


2 lv 1 or lv 2 cities with rooms total less than 30 will be reward a lv 6 obj
blah blah..:P or sth else, just find out a way to finish the descriptions.:D


---
作者: Fire
题目: sorry about the wrong para
日期: Wed Aug 25 19:10:19 1999
should be checkemote * /c


---
作者: Fire
题目: how to set one room to be a bank
日期: Wed Aug 25 22:26:56 1999
@SETHERE("t",3)


---
作者: Row
题目: 关于restart
日期: Wed Aug 25 23:06:03 1999
关于先前大家针对重启的post，我基本都同意，特别是将汉献帝改
成xixixi的建议，非常有趣，而且也相当合理。本来xixixi就是
皇帝了，让他没事召召人也可以，其实就是把名字改掉，也算是
统一的奖励吧。
至于纪念馆，也是一个好主义，将所有对三国有贡献的玩家及
巫师放进去，有可能的话，给每个人写个小小的自传评论什么
的（经常来的自己写，已经不来的就只好让巫师代劳了）。将纪
念馆安在华阴显眼的地方，让所有重启后进入三国的玩家都有机
会去观摩观摩。
城市的reset照ice的做应该没有什么问题，而玩家的reset就要考
虑清楚了，尽量不要伤害老玩家的感情，建议某些耗时很大而得
来得skills就不要砍了，如基本武功什么的。基本的观点是，让老
玩家在等级上不占太大优势，因为他们对系统的熟悉已经是个很
大的优势了。
另外，可以考虑给统一的国君及将领一些终身不掉的纪念品，好象
NBA的冠军戒指，hoho，大家考虑一下。


---
作者: Fire
题目: the bug about $n0p ?
日期: Tue Aug 24 22:52:29 1999
when will this bug appear, i can't find it :(


---
作者: Fire
题目: 关于重新启动：
日期: Wed Aug 25 00:05:14 1999
1 ice 的NPC国list 非常好，准备采用
2 玩家参数除reputation, loyalty , localcontribution and nationcontribution
  外全部保留。三国不同于其他MUD，高的skills没有决定性的作用。
  一个老玩家如果保持积极的参与，毫无疑问要比新手占一定的便宜(这在哪个MUD
  中都如此)但如果一但放松，很快就被淘汰。这是本MUD的一个特点，除非你始终
  保持积极活动，否则很快就不得不从新来。高的skills和reputation没有太大便
  宜。而新手一旦过了一个门槛，和高手就没有太大的区别。而国王间比较的最主
  要的是人缘。
3 建议本周末从新启动。
4 调整visitwise and searchwise 降低他们的成功率。
5 关于国师，只有nationcontribution > 500 (这值可以调整) 才能当NPC国的国师。
6 地区参数
   1 物资除粮草外全部清零
   2 地区训练和士气全部为50
   3 士兵数：地区等级   兵数
                 5      500
                 4      400
                 3      200
                 2      100 
                 1      300
   4 其他参数不变
7 每一玩家国由系统自动陪备两个NPC。
 


---
作者: Ice
题目: >关于重新启动：
日期: Wed Aug 25 00:45:05 1999
agree to restart this weekend.


---
作者: Flee
题目: >关于重新启动：
日期: Wed Aug 25 01:43:43 1999
agree


---
作者: Fire
题目: about the semote_cgi
日期: Wed Aug 25 19:08:32 1999
it is not bad, but if can display the rela massge such
烈火友善地和玄冰打了个招呼。 
rather than $N blah blah $t will be better
you can check "checkemote * /s" for similar method, thanks :)


---
作者: Ice
题目: >about the semote_cgi
日期: Wed Aug 25 19:09:34 1999
if can add the emoteapropos as well, will be much better..:)
emoteapropos is a player cmd

addoil flee..:D


---
作者: Fire
题目: about recover
日期: Thu Sep 23 22:24:16 1999
很不幸我们又遭遇一次重大的硬盘事故。这次我们最新的backup
是一个月前的。因此我们丢失了一个月的开发成果和一个月的玩
家最新数据。幸运的是我和row的机器上有这最后一个月的部分文
件。希望其他wiz的机器上也有类似的文件。这样我们可以很快恢复。
我和row已经恢复了部分文件。以下是部分还需要恢复文件：
1  汉帝 封爵位, flee's work
2  score.c 加上 marriage and jieye situation. group's work
3  /sgdomain/home/pic/*.pic, fire's work
4  add and adjust home information in house_d ice's work
其他部分的开发如计谋等，主要是flee and group的工作，希望你
们有拷贝，能尽快恢复。


---
作者: Stefan
题目: machine was hacked and all data lost
日期: Thu Sep 23 00:18:33 1999
This is surely a sad news, I should not have used this machine because
it was not well maintain at all. Now I am thinking of moving the mud
to a new machine. Will update you guys after it is setup.

The backup I've got is the one just before reopen. It is about one
month old, that means no data in the month was kept. I hope this does
not mean too much lost to most of you. The webpage was also lost.

Any inconvenience caused is much regretted.


---
作者: Stefan
题目: player login temporarily closed
日期: Thu Sep 23 00:20:26 1999
players should not be able to login unless we got things fixed up.
*addoil fire
*addoil flee
*addoil row
*addoil ice

To reopen player login, edit /include/config.h, change #define NO_PLAYERS
to #undef NO_PLAYERS, then reboot the mud.


---
作者: 烈火(fire)
题目: two new function for robot test
日期: Thu Sep 30 03:33:56 1999
set_robot_time(int num) set the number of roboting
set_test_time(int num) set the number of testing


---
作者: 某某(group)
题目: the last city for war
日期: Tue Oct  5 02:08:28 1999
i change the /sgdomain/cmd/war.c hence player can destroy NPC
country, hope that is ok.
group


---
作者: 烈火(fire)
题目: how to check an obj's memory consume
日期: Sun Oct  3 02:35:19 1999
help, help


---
作者: 阿洛(row)
题目: beware!
日期: Thu Oct  7 22:48:20 1999
i dunno why, this site is becoming more and more lag, but its fine when
it was just restored. i remember that we experiencing the same situation
b4 the hacker attacked, so pls beware.....
maybe i think too much of it.


---
作者: 阿洛(row)
题目: area_d
日期: Fri Oct  8 00:06:22 1999
i changed stat_me a bit, so an ordinary officer cannot see
the important info of a area, hope it can prevent some spy work.


---
作者: 烈火(fire)
题目: about the lag
日期: Fri Oct  8 05:41:52 1999
I will download a whole copy next week, sigh:(


---
作者: 阿洛(row)
题目: bug of bugao
日期: Sat Oct  9 00:09:48 1999
liuxiong told me that bugao job got bug:
when someone drop the bugao, he will be busy for awhile,
and just at this moment, if another keep on typing "get bugao".
this guy will be rewarded 20 loyalty again and again, so
that is unreasonable, fire pls test on it.


---
作者: 阿洛(row)
题目: man tasklist
日期: Sat Oct  9 04:53:40 1999
fire update the tasklist bah.
hoho.


---
作者: 烈火(fire)
题目: about the bug in bugo
日期: Mon Oct 11 07:49:22 1999
Hi row, thanks for your report
when you have time, can you help me to help
a check about that bug
the files is under /sgdomain/job/bugao/

thanks


---
作者: 烈火(fire)
题目: welcome new wizard.
日期: Wed Oct 13 07:32:08 1999
Now roro become a new wizard.
I think he can learn first, try to read
as many as helps under /help/wizard
and read some files under/sgdomain/job/
when he is familar to this system, I think
maybe he can try to design some new basic and mid
level jobs


---
作者: Fire
题目: >about bugao job
日期: Wed Oct 13 07:20:42 1999
On Tue Oct 12 23:05:50 1999 阿洛(row) wrote post #816:
> i changed the file :/sgdomain/obj/other/sdpk.c on the call_out("dissap")
> part, i think maybe becoz of the delay of 1 sec, player is allowed to input
> several get bugao within a short time which will cause bug. now i change
> it directly to remove(), so the bugao will be destruct as soon as someone
> get it, flee said it may cause some problem of get.c, but i tried and find
> its ok.  but please still keep an eye on it.

烈火泣不成声地抱着阿洛说：好你个蠢才真有出息哇！大人我总算盼到了这一天呐


---
作者: 阿洛(row)
题目: about bugao job
日期: Tue Oct 12 23:05:50 1999
i changed the file :/sgdomain/obj/other/sdpk.c on the call_out("dissap")
part, i think maybe becoz of the delay of 1 sec, player is allowed to input
several get bugao within a short time which will cause bug. now i change
it directly to remove(), so the bugao will be destruct as soon as someone
get it, flee said it may cause some problem of get.c, but i tried and find
its ok.  but please still keep an eye on it.


---
作者: 聂风(yuyin)
题目: about a new application for wiz
日期: Tue Oct 12 05:26:37 1999
绝对支持 fire 的意见,


---
作者: 你的中文(tit)
题目: i decide to quit from all mud
日期: Thu Oct 14 21:39:19 1999
as title
sorry to all


---
作者: 阿洛(row)
题目: gj_menu has bug.
日期: Sat Oct 16 22:18:48 1999
the 花名册 function has bug.
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/home/npc/gj_menu#891953 at line 62


---
作者: 烈火(fire)
题目: bugs in secure/simul_efun/string 
日期: Sat Oct 16 20:12:12 1999
the iwrap function seem not work properly


---
作者: Row
题目: >about new wizard
日期: Wed Oct 20 18:54:20 1999
that is right, but i think the reputation should be 100000...hehe.


---
作者: 烈火(fire)
题目: about new wizard
日期: Wed Oct 20 03:19:01 1999
i think for new wizard, can we add some limit such as
reputation more than 10000, literate more than 2000 ?

if so, that means he is at least a good player and like
this mud and also know a lot about this from the view of
players, what you guys think ?


---
作者: 阿洛(row)
题目: bug report
日期: Tue Oct 19 22:25:40 1999
rulin reparted some bugs:
1. e.g.: when a play ask for a searchwise job, when he finishes the
job, he doesnt go back and ask for pay, he may let taishou pos him to
another city, then he could ask for the same job again (he will not be
rewarded), if he is a nation officer, he doesnt need to let taishou pos
at all. this bug makes him do unlimited mid-job, the area and nation will
get the credit such as safety and npc, except the player himself receives no
credit, but it doesnt matter espcially in some rob-npc actions.
2. the result is nearly the same as the first bug, that is, ask for
job, finish
it, cmd resign the job after 10mins (the job record doesnt add),
then can ask for
job again.
3. that is about the house system's zhangfang.  normally player is allowed to 
have 5k gold in bank, 1k gold in salary, but the zhangfang fuction make this
limitation meaningless, ppl may transfer his money from his bank
accound to the
zhangfang, then he could get more than 6k gold. for the example, try
"money rulin".

for the first 2 bugs, i suggest ppl be set job record finished as soon as he 
finishes the job.
for the 3rd bug, fire pls check it further bah....xixi.

ps: rulin ask for some rewards for the reporting of these bugs: special horse,
better house, some equipments, i dont think that is much so i agreed, what r
ur guys opnions?


---
作者: 阿洛(row)
题目: about basic job
日期: Tue Oct 19 19:45:44 1999
我突然想到向玩家征集idea加些新的初级工作，一方面服务玩
一方面也可以给新来的wiz一个联系的机会。大家看如何？


---
作者: 阿洛(row)
题目: suggestion about 州牧
日期: Tue Oct 26 20:31:53 1999
i think in every area's info, u may find the 州牧：id， so
that is more clear.


---
作者: 阿洛(row)
题目: suggestion about house
日期: Tue Oct 26 20:35:51 1999
fire, since those servants r all naked, and we have a 赏赐 option,
so why not when player give cloth or other things to servants, then he
or she can dress it up?  hehe...


---
作者: Fire
题目: >suggestion about house
日期: Wed Oct 27 04:05:08 1999
On Tue Oct 26 23:35:51 1999 阿洛(row) wrote post #827:
> fire, since those servants r all naked, and we have a 赏赐 option,
> so why not when player give cloth or other things to servants, then he
> or she can dress it up?  hehe...

I have though about it, need some time to implement




about the display of zhoumu, you can adjust it if you think
it is more clear :)


---
作者: 玄冰(ice)
题目: somewhat I did with this mud
日期: Wed Oct 27 12:19:19 1999
all files associate with this mud I did with is in
/wiz/ice/sanguo
those are all copies I had, because most of the time
I used ED, so.....

I think most of them are rubbish, except the colored
house, update it bah, took me much effort..:P

addoil.:)


---
作者: 阿洛(row)
题目: suggestion
日期: Wed Oct 27 21:15:11 1999
when someone tell ur or reply u, there should be his eng id follows
his chinese name,
it will be more clear.


---
作者: 烈火(fire)
题目: about color house
日期: Thu Oct 28 04:34:55 1999
that is good, ice. but i got some problem
1 in lima or unix system. how could we change a group of
file's extension. because in the house system we use *.pic
I got big trouble to change the name of groups so i download
them to localmachine and under dos use cp *.txt *.pic to change
them and upload back. is this method silly ?

2 still several house not color :)

3 I move all your *.txt to the *.pic but still need
install to the house system. when you have time
can you do it ? addoil :)



---
作者: 阿洛(row)
题目: ack
日期: Mon Nov  1 17:25:31 1999
what the hell is going on?


---
作者: 阿洛(row)
题目: new basicjob: choppork
日期: Mon Nov  8 23:24:02 1999
i just created a new basic job -- choppork, all relevant files including
help r under /sgdomain/job/choppork/.  so anyone please test it, if there
is no problem.  i hope fire could register it into the JOB_D.  thx.

any bugs, pls inform me.

row.


---
作者: 聂风(yuyin)
题目: 我的一些意见
日期: Sun Nov  7 03:34:13 1999
我觉得有必要在中国开一个
mirror
所以,我觉得可以和 fire 写信的那个人交流一下
可能会对我们的发展有帮助
因为我觉得现在我们的 server 的速度真的十分慢
而硬盘也经常出问题,
这样对我们发展 player 有一定的困难
而如果我们能发展一个 mirror 的话
对 player 和我们来说也应该是一件好事
所以我比较赞成开放一个 mirror

addoil fire
addoil all wiz


---
作者: 烈火(fire)
题目: about the new job
日期: Tue Nov  9 02:58:47 1999
seem has a little bug

I can't find zhang, so clone one at the river
辛勤捕鱼的渔夫(yu fu)
河边的一个养鱼塘(pound)
「华阴第一快刀」张屠户(zhang tuhu)
ask zhang about job
你对张屠户道：这位先生，小人我想找些活干。
张屠户对你道：嗯，这么多肉俺一人还真忙不过来。俺最少要二十块猪肋排，喏，这
块肉给你，切得要整齐，不好的俺可不收。要是不巧肉用完了，就再问俺拿。
(ask zhang about meat)
张屠户交给你一柄剔骨刀和一片大猪肋。
> i
你身上带着如下物品(负重：44%)：
□青州长刀(longblade)
□钻戒(diamondring)
□斑斓官服(blguanfu)
  一柄磨得雪亮的剔骨刀(tigudao)
  一把小钥匙(key)
  四百七十一两金子(gold)
can't find the meat ?
l
木桥 [出口：north]
    这是一座窄窄的木桥，看上去似乎刚造不久，要不然走上去还真
有点心惊胆战呢。从桥上往下看，是一条清清的小河，水静静地流淌
着，清澈无比，你还可以看到有许多鱼儿在水底嬉戏。桥上还站着一
个人，看打扮是个渔夫。
辛勤捕鱼的渔夫(yu fu)
河边的一个养鱼塘(pound)
「华阴第一快刀」张屠户(zhang tuhu)
ask zhang about meat
你对张屠户道：张师傅，您给我的肉用完了，您看能不能再给些？
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/runtime
[errors] (fire) Error logged to /log/runtime
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/job/choppork/zth#166486 at line 196
dbxwhere
Tue Nov  9 05:54:44 1999
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Object: /sgdomain/job/choppork/zth#166486 at line 196
#0: '<function>' at /secure/user#166205 (<function>) at :0
#1: 'dispatch_modal_input' at /secure/user#166205 (secure/user/input
sys.c) at line 305
#2: '<function>' at /trans/obj/wish#166212 (<function>) at :0
#3: 'shell_input' at /trans/obj/wish#166212 (secure/obj/shell.c) at line 130
#4: 'execute_command' at /trans/obj/wish#166212 at line 293
#5: 'do_game_command' at /std/race/human#166211 (std/body/cmd.c) at line 60
#6: 'do_ask_str_about_wrd' at /cmds/verbs/ask at line 74
#7: 'do_ask_liv_about_wrd' at /cmds/verbs/ask at line 66
#8: 'be_asked' at /sgdomain/job/choppork/zth#166486 (sgdomain/module
s/m_ask.c) at line 170
#9: 'special_answer' at /sgdomain/job/choppork/zth#166486 at line 47
#10: 'ask_meat' at /sgdomain/job/choppork/zth#166486 at line 196
dbxframe 10
------sgdomain/job/choppork/zth.c:196 - ask_meat()
locals: 0, 0, NULL
----------------------------------------------------------------
        {
           this_object()->targetted_action(
           "$N嘴一撇，对$T道：刚才给你的肉还没切完，怎么又向俺要了？\n",usr);
           return;
        }
=>        if(pork->query_count()>20||pork->query_count()==20)
        {
            this_object()->targetted_action(
            "$N拍拍$T的头，道：哎，你已经切完了，不必再向俺要肉了(as
k zhang about pay)。\n",usr);
           return;
        }


addoil row


---
作者: 阿洛(row)
题目: choppork
日期: Tue Nov  9 19:02:54 1999
i verified the code and correct the bugs, i hope there will be no problem...
xixi, pls test again.


---
作者: 阿洛(row)
题目: sth wrong with robot test
日期: Wed Nov 10 00:40:42 1999
some player still get literate if they make wrong answer....fire pls check.


---
作者: 烈火(fire)
题目: 关于战争信息
日期: Mon Nov 15 04:27:13 1999
我计划设计一个小程序，记录下尽可能多的战争信息。
然后系统自动POST出来。
作用：
  1 保留历史资料。
  2 有助于发现战争中的BUG与欺骗行为
  3 满足公众的好奇心:)


---
作者: 阿洛(row)
题目: about tasklist
日期: Mon Nov 15 05:11:39 1999
i have no problem about it, will finish them asap.


---
作者: 斯坦福(stefan)
题目: mudlib public release
日期: Thu Nov 11 07:46:34 1999
I am cleaning up a base mudlib release of chinese lima. I removed all San Guo 
related things from this base lib. But some more work has to be done.

I am also trying to clean up the library a little bit, I would be very
careful not to break existing things... but in case I do, please
pardon me :)


---
作者: 斯坦福(stefan)
题目: release plan
日期: Fri Nov 12 07:02:16 1999
我初步起草了一个时间表，如下：
( lima mudlib 指的是所有和三国本身没有直接联系的 code )

十一月底：完成三国主页，公布 lima mudlib 的中文 release。
十二月底：开设第一个三国分站，采取加密形式。
明年四月：公开三国志的基础架构，以方便其他 SLG 的 MUD 开发

由于 lima 的 license 限制，不能够发行任何商业版，所以我打算
用 GPL 来发行汉化后的 lima mudlib 和三国 mudlib，任何基于这
些 mudlib 的开发都必须公开所有的 source code。

之所以这样做的原因是，无论多好的加密总会被破掉，西游记是个很
好的例子。既然总有一天 code 会被公开，还不如从开头就公开，这
样还可以把基于此上的开发集中起来，一方面可以迅速繁荣起来，另
一方面加速了开发进程。

与此同时，我会开设一个专门用于 lima mudlib 的网页来协助这个
过程。

三国本身还有很多潜力没有挖出来，所以我把日期推迟到明年四月，
希望到时候能够达到一个比较成熟的阶段。

不知道各位巫师有什么建议，可以公开讨论一下 :)

*addoil


---
作者: Fire
题目: >release plan
日期: Fri Nov 12 23:29:38 1999

stefan's suggestion is good

I think the best way to protect us is to open us
then anyone can get source code from us open page
and if they are interested can join our development team.

In this situation we can keep good development force

our ppl can download our code and if make some good
development we can ask them to feedback. perhaps we can
use CVS to manage the code version.

but the first important thing is to create a good
web page and clear our policy.

addoil


---
作者: 聂风(yuyin)
题目: 我个人的一些想法
日期: Sat Nov 13 00:39:17 1999
我觉得 stefan 所说的非常不错
而 fire 所说的我也十分赞成
因为由于本人一直搞的都是 lpc 的西游记和 侠客行
对 lama 和三国的 mudlib 都不是十分熟 
如果要长时间的在线看 mudlib 的话
我又没法支持这么大的开销,本来就只是消费者吗
如果能公开的话,我想 download 一分以做学习
因为我一直想为大家作出一点实际一些的工作
但就是应为以上所说的原因未能做到
请 fire 和 stefan 考虑一下
请 fire 和 stefan 考虑一下


addoil fire
addoil stefan
addoil all 


---
作者: Row
题目: >release plan
日期: Sat Nov 13 03:10:13 1999
i agree with stefan.
we still have lots of things to do b4 we can open the lib
to public for further development, so all of us have to
work hard to archive such target.  to open a mirror site
in china mainland as a first step is absolutly necessary,
especially for advertisement and test.  in addition, we may
recruit some new programmer from that site into our wizard
team to speed up our progress.  of coz, Sanguo's future is
free for all, i think its the way that all the chinese mud
have to go, especially for those develop based on public mudos.
anyway, sanguo is prosperous, lez do our best.


---
作者: 桃桃(flee)
题目: >> release plan
日期: Sat Nov 13 05:49:47 1999
agreed.


---
作者: 数据(group)
题目: release plan
日期: Sun Nov 14 01:17:24 1999
agreed..:)


---
作者: 桃桃(flee)
题目: tasklist
日期: Sun Nov 14 19:56:09 1999
fire, post a new tasklist bah .. :)


---
作者: 烈火(fire)
题目: the memory useage
日期: Mon Nov 15 02:52:47 1999
> time
当地时间                九十九年十一月十五日上午五时四十四分
三国启动于              九十九年十一月七日下午一时四十一分
本次运行时间为          七天十六小时三分十三秒钟


>cpu
CPU usage: 13.57%
Mud status is
Sentences:                            49      784
Objects:                            4912  1871320
Prog blocks:                         942  1193636
Arrays:                            30733 11576164
Mappings:                          66862  6522788
Mappings(nodes):                  150645
Interactives:                         22   139392
Obj table overhead:                 6004   284644
All strings:                    1345947 36436050 + 5516492 overhead
call out:                            200     5600 (current length 48)
                                         --------
Total:                                   %^H_RED%^63546870%^RESET%^
load average:
3.55 cmds/s, 8.79 comp lines/s
物品总数：3870
生命总数：627
室内房间总数：331
户外房间总数：456
daemon 物品总数：263

how come, our obj number just 3870, the cpu useage is 63K

*doubt


---
作者: 烈火(fire)
题目: 关于tasklist
日期: Mon Nov 15 03:44:44 1999
如果我们的目的就是完成一个MUD，然后让它能够正常运转。可以说我们的目
的已经达到了。但是如果我们的目的是做一个最好的中文MUD，那我们的路还
很漫长。现在我们的MUD在游戏内容上基本已经画完了一个圆。所有关键性的
内容基本都有了。虽然BUG还是不少，但是影响游戏正常运行的致命BUG已经不
多了。只要玩家人数不超过50(短时间内似乎不用担心)，我们系统正常转三四
天不成问题，稳定性似乎已经超过了微软的所有操作系统:)。至于下一步的工
作，因为没有什么特别紧急的事，所有大家可以根据兴趣，多加一些自由发挥。
同时把个人手头的几个工作尽快完成。剩下最为关键的就是关于公开代码和分
站的问题。这件事因为我们都没有经验，所以不用操之过急。
现在我把手头的几个工作在重复一下：
1 fire: 房间系统，NPC雇员系统
        多兵种系统
2 flee,group: 计谋，阵法，landlord，one on one
3 stefan: Web page, Open lib
4 row: 还有一个初期工作和两个中级工作。
5 yuyin: 读读row的code，争取设计一个简单的工作。
6 等上面这几项都基本完成了，可以考虑类似simcity的生产基地系统。
以上都是一些老的话题，大家看怎么样。



---
作者: Stefan
题目: >the memory useage
日期: Mon Nov 15 23:27:18 1999
> All strings:                    1345947 36436050 + 5516492 overhead

Here is the problem... I am wondering why the strings have caused
42M memory... 
could there be some serious memory leak in MudOS?

> how come, our obj number just 3870, the cpu useage is 63K
> 
> *doubt


---
作者: Ice
题目: >release plan
日期: Tue Nov 16 15:41:09 1999
I agree the plan, all things seems alright except one point
if we open a mirror site in china, how will we manage the
development in 2 different sites? or we just let it go
to different direction?.:P


---
作者: Ice
题目: >关于tasklist
日期: Tue Nov 16 15:47:25 1999
me ...... :(
mnn, if I can have time this week, I'll finish the house
level identification, but I have forgotten the cmd to
do it.:(

give me an example to do it like this:
@HOUSE_D->set_house("xxx","name","天堂")
para=name,level,room.....

呜~~


---
作者: 烈火(fire)
题目: kick ice
日期: Wed Nov 17 02:02:54 1999
got ISP lah.
welcome back :)
the command is in /daemons/house_d.c
you check the code and try to find the cmd bah :)



---
作者: 烈火(fire)
题目: 关于宝物的问题
日期: Wed Nov 17 02:26:09 1999
我们现在有许多宝物，但玩家没有正常的途径得到。
ice 有什么好点子？


---
作者: Row
题目: >关于宝物的问题
日期: Wed Nov 17 05:33:13 1999
On Wed Nov 17 05:26:09 1999 烈火(fire) wrote post #854:
> 我们现在有许多宝物，但玩家没有正常的途径得到。
> ice 有什么好点子？
当然是通过quest或者完成特殊的job啦，这个艰巨的任务
就由ice 来承担吧。grin....


---
作者: Row
题目: >war info
日期: Thu Nov 18 06:40:30 1999
On Thu Nov 18 08:26:43 1999 斯坦福(stefan) wrote post #856:
> would it be better if we open another board for all those warinfo instead
> of caolu board?
i have the same suggestion as stefan, then players can read post
selectively. we may put a board named 战争风云录 at each gate of
areas, and caolu is still the board for players opinion and suggestions, etc.

is that ok, fire?


---
作者: 斯坦福(stefan)
题目: war info
日期: Thu Nov 18 05:26:43 1999
would it be better if we open another board for all those warinfo instead
of caolu board?


---
作者: 阿洛(row)
题目: 今天怎么了？
日期: Thu Nov 18 21:07:58 1999
今天的速度突然恢复了以往的水平，非常非常得快，好久都没有这么爽了，很
多大陆的玩家都有同样的感觉。是stefan在服务器上动了手脚了？嘿嘿，还是
中国电信突然开恩，放宽出口了呢？总之是好事，希望能保持。


---
作者: 烈火(fire)
题目: Ice is the best ppl to do the map
日期: Sat Nov 20 19:06:23 1999
addoil :)


---
作者: 烈火(fire)
题目: about the strings in the area_server
日期: Sat Nov 20 19:08:44 1999
stefan is right, the server load all the desc in
the memory. I will change it so use different
files to hold the string information.
this is the same as warmap, home and semotes :)

and all other daemon datebase system. 
it is terrible :(


---
作者: 烈火(fire)
题目: about the string
日期: Sat Nov 20 19:24:46 1999
I think the area server and other daemons may be
not the real reason for so many string memory useage
because most daemons will be loaded when the system bootpu
and the rest daemon data will be loaded within the
first sevaral hours of the system's reboot. but
the memory usuage seem increase forever. so must
sth wrong with the OS. 


---
作者: 桃桃(flee)
题目: about catch bug(?)
日期: Fri Nov 19 23:22:35 1999
here is the record of leeye
"recruit" : ([ /* sizeof() == 7 */
"beg_time" : 943080844,
"count" : 365,
"memo" : "征400兵",
"left" : 400,
"finish_time" : 943080844,
"area" : "lujiang",
"lasttimes" : ({ /* sizeof() == 50 */
943054169,
943054195,


---
作者: 斯坦福(stefan)
题目: cpu usage and area_server
日期: Sat Nov 20 09:18:33 1999
The primary overhead comes from strings (as fire posted a CPU info).
I checked the area_server thingy, seems that all rooms
are loaded into memory, just imagine all the descriptions,
those are long strings, which surely add up to a lot of
memory space.

Is there a method to clean up unused rooms so that those memory
gets released? 


---
作者: 玄冰(ice)
题目: about whole_map.jpg
日期: Sat Nov 20 09:43:08 1999
fire, I think you may still have the map files I sent to you,
pls send those to me to let me see if I can draw one for
stefan bah, my new email now is tom811@163.net, but seems it's
not work well time to time.:(, any way, if got time, i'll
try to do it, after all the whole_map is made by me.:P


---
作者: 玄冰(ice)
题目: ack
日期: Sat Nov 20 10:22:40 1999
## Undefined variable 'HOUSE_D'
inn, just one sentence bah, fire, how to add...
* beg


---
作者: 玄冰(ice)
题目: about war_post
日期: Sat Nov 20 11:29:48 1999
war_post is a nice try, but I have the following thoughts:

1. I think in acient time, people cannot get war result info
   and detail that much.
2. according to the first point and the post by tit b4,(about
   the spy ability), I think we can set some limitations to
   the war post.
3. set a para called sa(spy ability), and the sa has different
   levels regard to the nation's most recent 3 months' spy job
   number, if sa reach some certain level, the officers in that 
   nation can read some certain war_post.(here officers exclude
   闲职).
4. suggestion of sa level and war_post level:
   spy jobs done    sa level    war_post readable level
 in last 3 months
   150               30                all
   145               29     all except last half year
   140               28     all except last half year
   ...
   100               20     all except last half year
    95               19     only those concern to its nation
   ...
    50               10     only those concern to its nation
    45                9     none can be readable
   ...
     0               0      none can be readable

隐居闲人cannot read.:P

how do you guys think.:P


---
作者: 烈火(fire)
题目: about the area_server
日期: Sun Nov 21 01:42:20 1999
the total information (include the desc, short and obj list exit
list and so on) are stored under /data/area/
I find the total size of these data files is 336605
it is about 300K, so not very big. therefore
it may not the reason for that huge string memory
useage.



---
作者: 桃桃(flee)
题目: >> about hua tuo
日期: Thu Nov 25 23:37:20 1999
the yao cao is quite heavy .. :)
if player carry too many stuff, the right one may not
move to him ..
i will reduce the weight of yao cao, anyway .. :)


---
作者: 桃桃(flee)
题目: >> whose char is this?
日期: Thu Nov 25 23:35:44 1999
it is my char .. used to test jimou and zhenfu ..


---
作者: 阿洛(row)
题目: hua tuo job
日期: Thu Nov 25 21:18:17 1999
hi flee, some players said that hua tuo job cannot be done properly, the tool
broke but hua tuo didnt accept none of the yao cao, would u please check?


---
作者: 烈火(fire)
题目: about run out of file descriptor
日期: Thu Nov 25 02:43:02 1999
I think that is the reason why i have changed the 
area room's from common file to virtual room
so for area, we just need open 2 files :)
but seem this doesn't help :(
anyway that is a strange bug. because as i know, there
is not a file close commond in this mud. so how could
close a file after open ?


---
作者: 斯坦福(stefan)
题目: run out of file descriptors
日期: Wed Nov 24 20:52:22 1999
Recently (yesterday and today), when the online players went up to around 50,
many system command fails to load because the mudos runs out of file
descriptors. I have increased the limit from 64 to 1024 now,
there should not be any problem for the moment. 

But the question is, how can we run out of file descriptors? there
must be some
thing wrong. Open a file but forgot to close? Should fix
things around.


---
作者: 斯坦福(stefan)
题目: System Development
日期: Mon Nov 22 05:25:12 1999
MudOS is already a dead project, nobody is really developing it. I am
afraid we have to shift our code base to the new LPC engine: Pike.
Pike is almost the same as LPC, but it is a complete and mature language.
It can be found at http://pike.idonex.se. Roxen is a great web server
written in Pike, and can be found at http://www.roxen.com. Both Pike
and Roxen are under GPL.
 
There are several reasons for doing this:
 
1. MudOS does not support access to database. 
 
   Our SanGuo mud has already shifted from traditional "one file one object"
   to a systematical daemon management system, such as the warmaps (442K),
   char daemon (700K), history daemon (174k), objects (151k). rooms (746k),
   news daemon (500k). MudOS is not designed for such kind of things, when
   it gets complicated, MudOS simple crashes. A database will boost the
   system performance by seperating out the data management part, Pike
   supports database connectivity to the database server MySQL.
 
2. MudOS does not intergrate well with Web.
 
   The HTTP daemon in Lima sucks because MudOS does not support
   multi-threading, and a simple query will greatly slow down the whole MUD. 
   Right now I am using Roxen to serve the San Guo's web page. It supports
   multithreading, and is the yet most flexible web server I've ever seen. 
   It performs very well, fast and stable. Have you seen the dynamic SanGuo
   newsgroup on the web page? I wrote it in Pike, which directly reads the
   "news_d.o" and "recent" under /data/news/ in our mud, without connecting
   to SanGuo mud.
 
3. MudOS prevents all MUDs based on MudOS from being commercialized.
 
   This is not a problem today, but will be a problem tomorrow, especially
   if we are moving towards a Graphical San Guo client, which is not a very
   hard job in my humble opinion. A Java Applet based client is quite easy
   to work out, and as you may have seen the Telnet Applet on SanGuo's web
   page, the display and input problem both have been solved. A simple idea
   to start with is to have a graphics+text combo. For example, the first
   graphical thing can be the map, and the war can be done graphically too
   (since it is already semi-graphical right now :), and the command and
   chat part we leave it as text based. Later this combo can be improved to
   a full graphical client.
 
However, with all the above said, it can not be done quickly in the near
future. We need some time to research all the possibilities. I think 
to open up Lima Lib and manage an open source project is the first step.
We will learn, and we will get the experience. If it goes well as expected,
we can move into the next era of San Guo development, i.e., to have a 
Pike based library running on a real database engine.
 
Though I mentioned graphical client and commercializing SanGuo, it would not
be an easy task, and that is also why I think open source is the model to
go. Unless there are enough solid developers of all sorts, ranging from
programmers and graphics designer to story writers, it will not be a
success. We are doing an Internet project, we need people to participant,
and by open source, we all benefit.
 
Hope we can meet the schedule and open up San Guo by April next year.


---
作者: 烈火(fire)
题目: cpu useage
日期: Tue Nov 23 05:35:35 1999

> CPU usage: 29.49%
Mud status is
Sentences:                            50      800
Objects:                            3664  1730048
Prog blocks:                         775   988784
Arrays:                            33447  1707748
Mappings:                          71738  6963740
Mappings(nodes):                  158947
Interactives:                         44   278784
Obj table overhead:                 6004   261964
All strings:                     108353  2530182 + 552748 overhead
call out:                            200     5600 (current length 128)
                                         --------
Total:                                   15020398
load average:
6.84 cmds/s, 32.44 comp lines/s
物品总数：3555
生命总数：673
室内房间总数：506
户外房间总数：778
daemon 物品总数：353
> time
当地时间                九十九年十一月二十三日上午八时三十三分
三国启动于              九十九年十一月二十三日上午七时十三分
本次运行时间为          一小时二十分七秒钟


---
作者: 斯坦福(stefan)
题目: cpu
日期: Tue Nov 23 18:29:36 1999
CPU usage: 20.15%
Mud status is
Sentences:                            54      864
Objects:                            3697  1716280
Prog blocks:                         843  1079836
Arrays:                            32040  1735848
Mappings:                          70153  6827388
Mappings(nodes):                  156327
Interactives:                         46   291456
Obj table overhead:                 6004   255628
All strings:                     115211  2503762 + 584764 overhead
call out:                            200     5600 (current length 87)
                                         --------
Total:                                   15001426
load average:
6.01 cmds/s, 10.36 comp lines/s
物品总数：3467
生命总数：678
室内房间总数：500
户外房间总数：715
daemon 物品总数：320


---
作者: 斯坦福(stefan)
题目: possibly the new server
日期: Tue Nov 23 18:55:46 1999
please ping  63.194.210.134, and mail me the statistics you got.
Is it faster than the current one? 

It could be our new server, provided most wizs are happy with it :PP


---
作者: 桃桃(flee)
题目: >possibly the new server
日期: Tue Nov 23 23:54:41 1999
ok for me, ... A_A


---
作者: 阿洛(row)
题目: about qb
日期: Wed Nov 24 00:15:31 1999
now the qb is replaced by sc, but they r still taking salary, could fire
change it?


---
作者: 阿洛(row)
题目: about login numbers
日期: Wed Nov 24 19:40:40 1999
today we met the same situation again, when ppl over 50, wiz cmds not working
anymore and bunchs of errors pop up, thats horrible.  so could stefan solve
this problem or just simply make the limit of login number, that is to say,
when there is 50 inside the game, no one is able to login any longer. is that
feasible, pls consider.
its urgent coz we r having more and more player everyday!!


---
作者: 阿洛(row)
题目: about login
日期: Wed Nov 24 19:42:29 1999
its wierd that system counts someone in login process as a normal player
in the game, is that causing problem?


---
作者: 斯坦福(stefan)
题目: re : file descriptor
日期: Thu Nov 25 05:22:11 1999
I rechecked the driver.log, seems that the file descriptor problem
is related to socket fd, but not file fd. I made some change to
the driver, hopefully it shall not happen again.


---
作者: 斯坦福(stefan)
题目: whose char is this?
日期: Thu Nov 25 07:37:12 1999
info c fdummy
〓〓〓〓〓人〓〓〓〓〓物〓〓〓〓〓资〓〓〓〓〓讯〓〓〓〓〓

■一般资讯：
【角色代号】fdummy  【姓    名】三国    【   字   】━━  
【性    别】女      【年    龄】14      【容    貌】26
【 所属国 】云之国(lsls)                【忠    诚】71
【 所在地 】许昌(xuchang)
【朝廷官职】━━    【地方官职】太守    【俸   禄】20
【武    力】100     【智    谋】100     【魅   力】100
【地区贡献】0       【国家贡献】0       【声   望】初露锋芒(345)
【类    型】玩家    【状    态】活动    【事   务】正常    
■与他国关系：
【大唐帝国】： 31   【  联合国】： 19   【    民国】： 59 
【  噪音国】： 28   【  枫之国】： 39   【  刘度国】： 59 
【  烈火国】： 29   【    穷国】： 15   【末日帝国】： 57 
■私人武装：
【亲兵数量】0                           【训   练】1
【马    匹】0       【弓    箭】0       【粮   食】0       
【坐    骑】：无
※坐骑挨饿：零个月。


---
作者: 阿洛(row)
题目: 关于噪音禅让
日期: Fri Nov 26 23:30:58 1999
大家都读过噪音的留言了吧？噪音由于特殊原因放弃，而他国的玩家
们经过讨论希望由赵子龙继任。鉴于我们现在还没有禅让这个功能，
所以我们有两个选择：
一、立刻做出禅让，flee已经做出surrender了，禅让也不会太麻烦吧？massage flee...
二、利用现有的投降：先让赵子龙在某地独立，然后暂时放宽投降要求，以
便让噪音国举国投降。

噪音对本游戏的影响是比较大的，所以我个人希望能满足他的要求，让赵
子龙即位。大家觉得如何？



---
作者: 斯坦福(stefan)
题目: sanguo map
日期: Sun Nov 28 03:57:51 1999
I've put up a simple map on the web page, please take a look.
Because it is too simple, it does not look very nice. It will
be better if somebody can use a real map from sanguo game or some
other places to be the background. Or draw borderlines to 
distinguish provinces.

Ice can take over from here? :-)


---
作者: 玄冰(ice)
题目: about the whole_map
日期: Tue Nov 30 03:02:33 1999
I'll try to take it over, but don't expect I can finish it by next century..:P
Bcoz I cannot have much time to login, if u have some urgent msg to me, like
site moved, ice's been taken by hacker... blah blah.... mail me at
tom811@163.net
I may check mail at least every week...:P
God bless me that i can deal with photoshop ...:)
addoil all guys 
yours
ice


---
作者: 桃桃(flee)
题目: about chanrang
日期: Mon Nov 29 23:01:16 1999
i have coded a chanrang program, which is a new function
of national meeting. check /wiz/flee/chanrang.c for details.
it is not finish yet, cos i dunno how the /secure/daemons/suicide_d
works .. 
please check it for any potential bugs.


---
作者: 阿洛(row)
题目: about old posts
日期: Mon Nov 29 01:17:52 1999
today i downloaded the archive of caolu's old posts, a 652k txt
file...faint...
i checked half of it and now i am a little bit dizzy..:( i found
some posts r messed
up but i hope we didnt missed some good ones. i copied several lines
and saved for
record. after finishing the adjustment, i will email them to stefan
to help him to
implement the history affair part of sanguo's web page.

p.s. from those posts i can see a mud from a very beginning growing up to a
under-mature one, what a exciting experience!


---
作者: 玄冰(ice)
题目: I checked the current whole map in web
日期: Tue Nov 30 22:21:53 1999
A graphical map will be much better but...
seems cannot perform the color difference by different country
as map main can do now into the graphical map..:P
forgive me..:P


---
作者: Stefan
题目: >I checked the current whole map in web
日期: Wed Dec  1 08:07:19 1999
On Wed Dec  1 01:21:53 1999 玄冰(ice) wrote post #889:
> A graphical map will be much better but...
> seems cannot perform the color difference by different country
> as map main can do now into the graphical map..:P
> forgive me..:P

oh? I thought that map on web is leady using color to differentiate
countries? 


---
作者: 林冲(lch)
题目: kick ice
日期: Thu Dec  2 03:10:46 1999
kick ice
nip ice
bite ice


---
作者: 斯坦福(stefan)
题目: board bug
日期: Thu Dec  2 08:51:13 1999
seems board does not check for the permission put on the newsgroup.
If you use news, groups "wiz.*" will only be read by wizards.
how come lch can read the board here? :)
*slogan lch


---
作者: 桃桃(flee)
题目: bug log
日期: Wed Dec  8 20:24:24 1999
[errors] ((none)) Error logged to /log/runtime
[errors] *Array index out of bounds.
[errors] /daemons/warai_d (daemons/warai_d/automatch.c) at line 11


---
作者: 桃桃(flee)
题目: findfile -u
日期: Tue Dec  7 23:03:15 1999
it semms that findfile's data is out of date
can any admin update it .. *hoho


---
作者: 烈火(fire)
题目: to row
日期: Sat Dec  4 15:38:04 1999
Hi, row
I copied m_pushable.c to /std/modules
you can test now :) addoil
in fact you can test even the m_modules under your directory
just in the inherit give the full directory.

anyway, if you need the privilege for /std/modules
just tell me.


---
作者: 阿洛(row)
题目: training has bugs?
日期: Sun Dec  5 01:48:20 1999
several players reported that training got bugs, such as:
missed enemy troops, cannot order npc troops, pls look into it.


---
作者: 玄冰(ice)
题目: suggestion ofinfo h
日期: Fri Dec 10 18:53:41 1999
1. should be viewed by the order of levels.
2. the price should be viewed together with unit of gold, otherwise player can
say that's silver.:P

I am interested to make some rules of real estate agency later, after I finish
the ma on web

using telnet now, maybe not so good posting.:P
excuse me.


---
作者: 玄冰(ice)
题目: who can give me a 中国地形图
日期: Fri Dec 10 10:56:48 1999
I cannot find it by myself, if sb can find it, pls
send to me in jpeg format.:P
I think draw on real map will be better.:)


---
作者: 聂风(yuyin)
题目: %^RED%^what is this %^RESET%^
日期: Mon Dec 13 21:13:14 1999
请各位到   sg.sq.sh.cn 看一下
这是不是我们的镜象
*wa
*oh


---
作者: Fire
题目: >%^RED%^what is this %^RESET%^
日期: Tue Dec 14 02:23:22 1999
On Tue Dec 14 00:13:14 1999 聂风(yuyin) wrote post #901:
> 请各位到   sg.sq.sh.cn 看一下
> 这是不是我们的镜象
> *wa
> *oh

I think that is the canada sanguo's page.



---
作者: 聂风(yuyin)
题目: something
日期: Tue Dec 21 02:53:52 1999
i think loveui  爱又如何
他简直就是太放肆了
竟然 post 这么多东西侮辱 wizard
我觉得这太让人忍无可忍了
我们都是抽时间和钱来为大家建设我们的 mud 世界
可能有时候做事会过了一点
但我们绝对可以道歉
但 loveui 却一直都在辱骂 wiz
请 fire 给一点什么惩罚，否则我们的就都不用混了
我从来都不曾对游戏做任何的改动
因为。。。。。。。。。。funtion 我都不记得
而 fire row flee group ice 等更加不可能做任何的更改
so i think 这应该是一常误会
sigh
请 fire 查一下


---
作者: 阿洛(row)
题目: ideas
日期: Mon Dec 20 19:37:37 1999
记得以前洛阳有个工作叫救火，现在由于某些原因出了错然后就
搁在那里了。现在不如拿回来，稍加改动，还可以增加一些其他
相关联的工作，比如相对的放火等等。
主要的想法是这样的：可以编一个叫「潜行」(stealth) 的技能，
一旦使用成功，就能掩盖原来的身分，成为另外一个人，就好象
「侠客行」里面具的功能一般。具体可以这样做( 如果不涉及安
全性的话，因为修改id可能会引起大bug)：当玩家cast stealth
时，跳出一选单，列出玩家想装扮成的人物：调皮小男孩(boy)、
长者顾双(oldman)、小姑娘李小翠(girl)等等，选择后，将其作
为一个参数设在CHAR_D中：
CHAR_D->set_char(id,"ste_tar","调皮小男孩(boy)")
然后，如果其他玩家使用look或id命令时，检测如果该房间内有
人使用了stealth 技能的话，就使用该参数代替使用者的title、
name及id。该技能的用处是可以隐蔽地执行一些特殊的任务，比
如破坏敌国地区的任务，逃避cmd catch 。当然，相对的还可以
编一个「探测」(probe) 的技能，一旦使用成功，该房间内的所
有隐藏人物全部现身。
这样，可以引出的工作就很多了：具实际破坏性的在城内放火、
在水源中下毒等等，及相应的救火、解毒。
另外在每个区域设一个拘头(相当于巡捕)，在破坏工作中，将有
可能失手，失手的话就会被通缉，被拘头碰到就抓起来，关久一
些。而玩家过了一小时后就可以到某地去取消通缉的记录。

不知道以上所写的是否可行。



---
作者: 玄冰(ice)
题目: one strange thing
日期: Mon Dec 20 12:39:06 1999
so far in my mind, LULING is not a very large city, and
I remember in my orginal city setting and map drawing it
should be a lv 2 city sth, bcoz I am drawing the web-map,
I found it's different from the orginal setting.
I think lv 2 is reasonal able lv for LULING, so if sb 
has time, pls change it to lv 2 in @AREA_D and LULING.map bah

I'll draw it in web-map as lv 2 city at present, if sb can
persuade me that it should be a lv 4, I'll take my difficulty
to change it in my web-map then.:P

ps. I think there can be many relative things to be changed if
change LULING's lv, like officers' position para, take care bah.:P


---
作者: 烈火(fire)
题目: disable and enable players channel privilige
日期: Mon Dec 20 05:45:33 1999
@.xxx->disable_chan() to disable
@.xxx->enable_chan() to enable

addoil;)


---
作者: Flee
题目: >about the whole map
日期: Fri Dec 17 20:35:27 1999
On Fri Dec 17 11:42:05 1999 玄冰(ice) wrote post #904:
> Since seems no one can provide me a chinese ground map, I will
> have to do it by adjusting the Koei's game map now, pls don't
> scold me if it's ugly...:P
> 
> btw  I am now really very very interested in the real estate business,
> and I'll write a plan about it in detail.:)
> 
addoil ice, massage ice, hurry ice


---
作者: 玄冰(ice)
题目: about the whole map
日期: Fri Dec 17 08:42:05 1999
Since seems no one can provide me a chinese ground map, I will
have to do it by adjusting the Koei's game map now, pls don't
scold me if it's ugly...:P

btw  I am now really very very interested in the real estate business,
and I'll write a plan about it in detail.:)



---
作者: Ice
题目: >%^RED%^what is this %^RESET%^
日期: Fri Dec 17 08:38:33 1999
It is mirror site of canada sanguo's homepage, and it's closed.:P


---
作者: 玄冰(ice)
题目: about mysterious
日期: Sat Dec 25 13:05:12 1999
韩逊对你道：没问题，仙丹应该不难做，将军能不能给我二两金子，我出去买些原料来配
配看。
bcoz now the cooker can copy food obj, the mysterious is unlimited
food, thus I removed this obj, but in the cooker's record, it's still
there but cannot be made.  fire, can u remove all the record
of mysterious from cookers who know how to copy it?


---
作者: 玄冰(ice)
题目: seems a bug in marriage
日期: Sat Dec 25 12:44:15 1999
seems jiaofu tou cannot move northeast......
answer northeast to jiaofu tou, 杨哮天对轿夫头答道：northeast
轿夫头笑道：好，好，咱们就往northeast方向走。
[errors] ((none)) Error logged to /log/runtime
[errors] */sgdomain/modules/char_server/jiaofu tou is not known by the parser.
 Call parse_init() first.
[errors] /sgdomain/modules/char_server/jiaofu tou (sgdomain/modules/m_char.c)
at line 39
answer northeast to jiaofu tou, 杨哮天对轿夫头答道：northeast
轿夫头笑道：好，好，咱们就往northeast方向走。
[errors] ((none)) Error logged to /log/runtime
[errors] */sgdomain/modules/char_server/jiaofu tou is not known by the parser.
 
Call parse_init() first.
[errors] /sgdomain/modules/char_server/jiaofu tou (sgdomain/modules/m_char.c)
at line 39

fire pls chack it bah


---
作者: 玄冰(ice)
题目: about changing data
日期: Sat Dec 25 11:45:56 1999
There is a player called 杨哮天(eat) asked me to change his age.
he said he was 18 but nothing married to him, and by accident his
passwd was pirated by others, and that char suicided, now he 
got a lover and wanna marry, but his new age is only 15, he asked me
to change, he said group recover his data except contribution and
age, after I got the reason, I changed the data.

Bcoz I am not familiar with cmds.:(  I used my dummy "Bingo" to test,
that's it.:P


---
作者: 玄冰(ice)
题目: to stefan
日期: Sat Dec 25 10:14:30 1999
I have sent a package of pics to fire, pls check it if u
have got it.  There are some files in the zip file, one is 
main map, but it's without indication of different nations,
it's just a map..:P  and the 5 cities pics can be used to 
indicate different city levels, there is also a flag pic for
u if u need it to indicate different nations by using cgi,
I hope it can work for u.:)


---
作者: Flee
题目: >how could there are two new npc countries ?
日期: Sat Dec 25 06:56:22 1999
On Sat Dec 25 06:46:13 1999 烈火(fire) wrote post #926:
> hi, everyon
> hi, everyone.
> today I find that there are two new npc countries
> ma wan and shen pei. How could npc create new nations
> anyone has any ideas ?
> 
> xixi:)
i guess player chan rang to npc .. hoho


---
作者: Flee
题目: >关于战争
日期: Sat Dec 25 06:54:59 1999
On Sat Dec 25 06:04:13 1999 烈火(fire) wrote post #925:
> 我也知道计谋，和多兵种会给战争增色许多。
> 但因为战争部分很复杂，一点修改都可能带来
> 许多BUG。所以如果要进行升级，必须要有充分
> 的时间和精力。现在我没有时间。flee和group
> 一直在做计谋。详细已经基本查不多了。所以
> 如果认为成熟，就可以正式开放。如果flee还
> group还有精力，就请继续进行多兵种设计。我
> 可以帮忙消除一下BUG。我再尽快完成house系统
> 后想着手生产基地和商业。
> row如果有时间，可以进行fate系统。
> regards
new semester starts next week, i and group will
be busy on our projects ... 
anyway, i will try stay online for at least one hour
per day.
about jimou, i agree with fire, there must be some unexcpetion
and may cause serious results ..
i plan to open jimou one by one, so we can reduce the damage ..
hehe

addoil all and will all of u a happy new mellinnium


---
作者: 烈火(fire)
题目: how could there are two new npc countries ?
日期: Sat Dec 25 03:46:13 1999
hi, everyon
hi, everyone.
today I find that there are two new npc countries
ma wan and shen pei. How could npc create new nations
anyone has any ideas ?

xixi:)


---
作者: 烈火(fire)
题目: 关于战争
日期: Sat Dec 25 03:04:13 1999
我也知道计谋，和多兵种会给战争增色许多。
但因为战争部分很复杂，一点修改都可能带来
许多BUG。所以如果要进行升级，必须要有充分
的时间和精力。现在我没有时间。flee和group
一直在做计谋。详细已经基本查不多了。所以
如果认为成熟，就可以正式开放。如果flee还
group还有精力，就请继续进行多兵种设计。我
可以帮忙消除一下BUG。我再尽快完成house系统
后想着手生产基地和商业。
row如果有时间，可以进行fate系统。
regards


---
作者: 斯坦福(stefan)
题目: sanguo's web page
日期: Fri Dec 24 23:24:48 1999
sorry to row, the history part was not updated yet... 
Row has handed over to me quite a lot of material long time ago, I was
too papaya to make them on the web...*blush

Also, the map on the web currently got problem when countries
are more than 8.. I am debugging :PP


---
作者: 斯坦福(stefan)
题目: I am back :)
日期: Fri Dec 24 23:22:45 1999
Sorry for the long delay of pacakaging up mirror sites...
I am just back from a business trip, got sometime before year
end, so I guess I am now able to do something.

1. I've found a hosting place for San Guo, actually I've made my current
company to support San Guo hosting, so .. San Guo soon will be hosted
at one of the fastest internet datacenter : above net.

2. I was trying to get a website setup to host open source development,
but it was delayed quite significantly because I was too busy with work.
The web site should be up after new hosting site is confirmed.

3. Regarding mirror release, I will see if I can work out something 
before end of the year, initially we will only release encrypted mirrors.

4. Regarding our future development, the model will be what we've discussed
before, i.e., open up lima mudlib first, and see how it goes, also we
can accumulate some experience in managing open source development.
Later we will think of graphics java client or new server end based on pike.


---
作者: Flee
题目: >to flee
日期: Thu Dec 23 21:53:20 1999
On Thu Dec 23 11:45:55 1999 阿洛(row) wrote post #919:
> there is a bug in learning skills from xianren, if player doesnt
> have enuf money to learn the skills and still type "yes" when asked,
> system says "你没有那么多钱" but player still get skills point...
> flee pls check it.
> btw: only works for under 30 levels study
fixed .. hoho


---
作者: 阿洛(row)
题目: 现在兵种太单调
日期: Thu Dec 23 21:48:27 1999
前两天和一些老玩家们聊，他们份份表示现在征兵--训练--战争的三步
曲太单调，时间一长玩家难免失去兴趣。我想，计谋系统已经差不多好
了，开放的话必将丰富战争过程，希望下星期能开。我们还可以根据玩
家的建议多设计几种征兵的方式。另外，兵种系统是不是要等基地系统
完成后再开放？能否先开放骑兵和弓兵呢？毕竟我们以前有过，也应
该能丰富一下战争系统。烈火，你看如何？


---
作者: 分钟(group)
题目: login
日期: Thu Dec 23 21:06:06 1999
hmm.. it seems that some one try to login group from same place where i am at
Nov 18, it is quite strange... i have change the passwd.

group


---
作者: 阿洛(row)
题目: to flee
日期: Thu Dec 23 08:45:55 1999
there is a bug in learning skills from xianren, if player doesnt
have enuf money to learn the skills and still type "yes" when asked,
system says "你没有那么多钱" but player still get skills point...
flee pls check it.
btw: only works for under 30 levels study


---
作者: Row
题目: >>about wan's reward
日期: Thu Dec 23 08:04:26 1999
ok, no problem, so group set it bah.
btw, have to make a post to let players know, or they will...hehe
escape


---
作者: Ice
题目: >about party
日期: Thu Dec 23 04:19:55 1999
I think party in particular time is reasonable.:P
and if only regulate it by time from one to another, ppl can
gain food too much by changing his city.:P


---
作者: Ice
题目: >ideas
日期: Thu Dec 23 04:17:26 1999
I suggest if use "cast stealth", this id should have some kind of slowness
in action, bcoz if the officer in the city wanna catch him, he have to
"probe" first, and probe should cost some time, so it'll be more fair to both
sides.:P
*support row
:P


---
作者: 烈火(fire)
题目: about wiz's passwd be hacked
日期: Thu Dec 23 03:08:53 1999
I think it is better to check if you are hacked
or not
goto to the /log directory
use the following command
find -in "xxx 进入游戏，" logins
xxx is the your id. 
then you will get a list of all login record and
check if there is some one login from other
site. 

if find that, please report and change the 
passwd immediately


---
作者: Fire
题目: >about wan's reward
日期: Thu Dec 23 03:02:52 1999
On Thu Dec 23 04:36:34 1999 分钟(group) wrote post #913:
> i have agreed that give her a chinese garden house for her data of
> clothing, and i think 
> row also knows that. it is ok to give her the house? or cut the
> house to about 15 rooms?
> wait for answer. thanks
> 
> group

for person reward, that is ok lah :)


---
作者: 分钟(group)
题目: about wan's reward
日期: Thu Dec 23 01:36:34 1999
i have agreed that give her a chinese garden house for her data of
clothing, and i think 
row also knows that. it is ok to give her the house? or cut the
house to about 15 rooms?
wait for answer. thanks

group


---
作者: 分钟(group)
题目: re party
日期: Wed Dec 22 06:13:56 1999
can be sure... i put the limitation in the certain month it is because 
it is easy to control and give players a time feeling..:) if you
want, i can change it 
to time duration for sure..:)


---
作者: 烈火(fire)
题目: about party
日期: Wed Dec 22 05:02:55 1999
I think we may just limit the time span from one party to
another, unnessary must be in perticula month

how about this, group :)


---
作者: 烈火(fire)
题目: new log file
日期: Wed Dec 22 04:42:05 1999
the file /log/call record all the direct call
from wiz.


---
作者: 烈火(fire)
题目: about the nation reward
日期: Mon Dec 27 16:33:13 1999

that is right, when a player change to new country
his nation contribution will begin from zero but
the record of how much contribution has been award will
keep. this will couse that player lose some award after changing
nation. it is a way of penlty for betray. But maybe too much
later we will modify it so it is more fair.


---
作者: 分钟(group)
题目: about login player
日期: Sun Dec 26 22:43:02 1999
today when i finger, find a example
Login          player      56m  63.194.20.87
is that possible to idle 1 hour when login?....or something wrong?

group


---
作者: 阿洛(row)
题目: a bug in pos/i
日期: Sun Dec 26 07:10:17 1999
there is a bug in king rewardind player function, i didnt check
the code, but i think fire might stored the old nationdistribution
in a para and match the new one each time, if bigger than 50, then reward.
the problem is, when a player changes his nation, his nationdistribution
will be re-count, so he have to wait for his record catching up the old
data to get the reward, that is surely a bug.  since we never deduce
nationdistribution, so i suggest, when the new nationdistribution is less
than the old record stored in the para, make the old record as zero.
dunno if its workable, fire pls check it.


---
作者: 斯坦福(stefan)
题目: is it our code?
日期: Sun Dec 26 06:00:10 1999
标  题: 看大家都换我也换.  讨论区：Mud_Wizard[ 天神议事厅]  

作者: onlymud (只爱泥巴)  日期: 1999.12.25 20:18  
-------------------------------------------------------------------------
手上有套朋友给的lima 架构的三国,新板的,可以进行说服,拉拢市民等任务, 
值得wizs学习,想换sj的lib,欢迎来信交换/交流lpc经验.
chat* welcome all     
※ 来源:．网易虚拟社区 http://club.netease.com．[FROM: 202.102.254.80] 
--------------------------------------------------------------------------

xwin saw it and forwarded it to me. 

currently I do not think this is a big problem because we are going to open it
anyway.
But somehow it is still quite bad, at least hurt all wizs' feelings :P


---
作者: 斯坦福(stefan)
题目: encrypted mirror
日期: Sun Dec 26 05:44:24 1999
So far, I've successfully encrypted the *.c files and compiled a special
driver to run the encrypted mudlib. Those *.h files are not affected.

Also I need to get intermud protocol setup so that we will
know who are our mirrors. but that has got some problem :P lima bean
refuses to release their IMUD-3 server source code. I think I have
to work around it, maybe join current English IMUD-3, but filter out
English muds.

Thirdly, I am not sure how to clean up those daemon data files,
i.e., those *.o in /data, which should be reset, which should not?
need help later when I test the mirror site :)


---
作者: 烈火(fire)
题目: a new command to check current tasks
日期: Wed Dec 29 03:28:10 1999
task


---
作者: 玄冰(ice)
题目: bug in servant
日期: Thu Dec 30 09:19:33 1999
when u call ur servant, only b&c works, all others say there
are bugs......:(
fire pls check it.:P


---
作者: Row
题目: >bug in servant
日期: Sat Jan  1 00:55:00 2000
sorry, its me who edited the file for servants, free_menu.c, gj_menu.c
and nwj_menu.c, i tried to let the married couple have the same
previlage to order the servant, but seems there is sth i cannot figure
out.  fire pls check it for me and tell me whats wrong. thanks.
sorry for bringing inconvenience.


---
作者: Row
题目: >web page
日期: Sun Jan  9 19:01:22 2000
where is my novel....:(
since the first edition of posts is ok, i'll put my hands on second one lah.

BTW: i think the dark background is good.  somehow remind ppl that sanguo
is a serious topic...hehe, how do u think?


---
作者: 烈火(fire)
题目: good work, stefan
日期: Sun Jan  9 14:34:57 2000
addoil


---
作者: 斯坦福(stefan)
题目: web statistics for fun :)
日期: Sun Jan  9 10:20:27 2000
page             view
------------    ------
history.html      253
enter.html        371
news.html         523
index.html       1308
map.html         3239
post.html        4638
help.html       17148

seems most people are only interested in help files :P


---
作者: 斯坦福(stefan)
题目: web page
日期: Sun Jan  9 10:12:18 2000
Just uploaded the history part of the web page.
Up to now, the web page has all parts, some improvement are still
needed. But roughly, the whole structure is like that.

I feel that the background is too dark, anybody share the same
feeling? Is it a good thing or bad thing? When I started, I followed
the old page to use dark background, but after browsing through
XKX and XYJ's pages, I feel ours is pretty dark :P

also the presentation needs more work, e.g., some graphics, nicer
layout and color arrangement, etc etc. I am not a web page specialist
and I need help!

anyway, let's leave it there until re-open. I am still bugging the
system admin to get server located and set up before 14th.
We shall see the outcome.

finally, thank row for the hard work in organizing all the
historical documents!


---
作者: 烈火(fire)
题目: the restart part is ok
日期: Wed Jan  5 03:43:22 2000
not test yet, and can't test now :(


---
作者: 玄冰(ice)
题目: about reallocation of nations in restart
日期: Sun Jan  2 10:40:33 2000
Well, I do think only 3 nation in sanguo world can be a good
phase, maybe we can have multi-allocation restart plans later.
However, I don't think I can have enough time to design a 3 nation
allocation right now, bcoz I have got many tasks in my job and I
have to finish them as soon as I can.  So I am afraid that I
cannot finish that plan in time by 15th Jan, how about just let
those former player nation be taken by NPC randomly, or make them
to randomly assign to wiz.:P

Anyway, I will try, but it'll be better to prepare both hands by
restarts.

regards
Ice


---
作者: 玄冰(ice)
题目: about nationmeeting
日期: Fri Jan  7 12:46:48 2000
I think players r familiar with nationmeeting now, and I found
one thing that can ignore the voting effects:
bcoz in the beginning of introducing nationmeeting, we didn't
set any limit on nationmeeting and no reward nor penalty for
suggestion approved or denied, so if a player insist to
do some transfers, he can just keep using nationmeeting
to achieve his goal, which can totally ignore the voting 
effects in meeting.

I suggest to add a time limit for nationmeeting,
like at most once per day or 2 days...:P
how do u guys think?


---
作者: Row
题目: >house bug
日期: Wed Jan 12 19:41:11 2000
On Wed Jan 12 21:12:56 2000 阿洛(row) wrote post #957:
> player reported house upgrade doesnt cost money, maybe a bug, pls check.

i tested, updating from palate to castle only cost me 10 gold...


---
作者: 阿洛(row)
题目: house bug
日期: Wed Jan 12 18:12:56 2000
player reported house upgrade doesnt cost money, maybe a bug, pls check.


---
作者: 玄冰(ice)
题目: about document in web
日期: Wed Jan 12 15:34:43 2000
the structure of document in web seems too flat,
when I open all sub-directory, the web page becomes too
long and seems it's hard to find exactly what i want.
I think maybe we can use the structure of yahoo,
like when u browse a subdir, u'll get into it, and
all subdir or documents under that dir will be shown,
and there is a return button in each page, thus when the
reader wanna back, press "return" then will goto the
upper dir.

I am not familiar with web developing, just advise.:P


---
作者: 玄冰(ice)
题目: bug? bug? bug?
日期: Wed Jan 12 14:55:24 2000
> 抚一回答你：有 bug 吧， 任何人可以独立，任何人可以当高级国家官员
info c fyi
抚一回答你：还是 fire 卖大包 ？ ：)
*smirk
......


---
作者: 斯坦福(stefan)
题目: server relocation
日期: Wed Jan 12 03:18:07 2000
I am sorry that the server can not be changed this week.
Because there are some technical difficulties and lots of things
are happening, it is significantly delayed. 

I guess we have to stick to current server for the moment, the
reopen can be on 15th, but still with current machine.



---
作者: Fire
题目: >a serious bug in job system
日期: Tue Jan 11 04:44:32 2000
On Tue Jan 11 03:33:14 2000 阿洛(row) wrote post #950:
> today pangtong reported a serious bug in job system:
> when a player asks taishou for credit after finishing his job, the taishou
> disconnect(they use dummy as taishou, so they do it intently), but the
> player still get questions to answer and will be rewarded. thereafter,
> they login taishou again and ask for the same job, they will get another
> chance to be questioned and rewarded. so they keep doing it for adding about
> 100 literate and skills exp as much as they want.  i think this is aweful,
> fire pls test and correct it bah.

this bug is fixed, but haven't test yet. counld you please
ask pangtong to test if he want the 5 level stuff.
cheers :)


---
作者: 烈火(fire)
题目: the bug for system can't clear house
日期: Tue Jan 11 04:36:00 2000
has been fixed by adding some clean function in llb


---
作者: Fire
题目: >re-open
日期: Tue Jan 11 03:57:58 2000
On Mon Jan 10 21:32:19 2000 斯坦福(stefan) wrote post #949:
> fire, would you please list down the steps for clearing accounts, reset
> deamons, etc?
> Because I am preparing mirrors, need to reset everything, but dont really
> know what are the things to be reset.
> 
> Thanks!

The process of clear up
1  use admtool to purge all the users
2  modify the function of clear_players() in 
   /daemons/restart_d.c to enable it.
3  run @"/daemons/restart_d"->clear_player(), maybe need
   several times if you meet too long evaulate error, when you
   receive the message done, then it will be ok
4  run @"/daemons/restart_d"->restart()
Bugs: 
1 some users may login before our system's crush and
  haven't login anymore, his record may can't be purged
  by admtool's purge according offline date
2 the record of house can't be cleard by purge the player
  or remove the char from char_d. we may need some clear code
  in 鲁木匠
3 several functions in the restart_d haven't been test, they
  may have bugs
Suggestion:
1 first time we just open one mirror, and stefan and I will
  have admin account in the mirror for at least 1 month to 
  handle problems.
2 for the following mirrors, I think for each mirror, we need
  take care of it, if it run badly, it will hurt our reputation.
  so I think at least one of our wizs should have an admin account
  in there and deal with bugs and other problem.


---
作者: 阿洛(row)
题目: a serious bug in job system
日期: Tue Jan 11 00:33:14 2000
today pangtong reported a serious bug in job system:
when a player asks taishou for credit after finishing his job, the taishou
disconnect(they use dummy as taishou, so they do it intently), but the
player still get questions to answer and will be rewarded. thereafter,
they login taishou again and ask for the same job, they will get another
chance to be questioned and rewarded. so they keep doing it for adding about
100 literate and skills exp as much as they want.  i think this is aweful,
fire pls test and correct it bah.


---
作者: 斯坦福(stefan)
题目: re-open
日期: Mon Jan 10 18:32:19 2000
fire, would you please list down the steps for clearing accounts, reset
deamons, etc?
Because I am preparing mirrors, need to reset everything, but dont really
know what are the things to be reset.

Thanks!


---
作者: Stefan
题目: >about the rules for opening mirror
日期: Fri Jan 21 11:07:58 2000
On Thu Jan 20 18:10:56 2000 烈火(fire) wrote post #993:
> I agree with stefan's post
> but don't know how could control the mirror if it
> doesn't following our rules?
> do we have any way to terminate the mirror ?

the internal thing works this way:
1. driver hard codes the mudname and ip of the server;
2. mudlib requires frequent auto-update;
3. if a mudlib is not updated in 1 month, the mud will refuse to start;
4. if a mudlib is runing on a different ip, the mud will refuse to start;
5. if somebody runs a pirated copy, cases would be:
5.1. if he connects to internet, his ip will be different from the original;
5.2. if he does not connect to internet, he has to modify his machine time;
5.3. if he does not connect to internet, and he modifies his 
     machine time, just let him run the pirated copy :)
5.4. if a pirated copy every gets on the internet, it will leave a 
     record in the intermud data, we will be able to find out which
     copy he has got from, because we have the mudname.
6. the least and worst case would be somebody actually decrypted
   the whole thing, and start to distribute free copies :PP


---
作者: 阿洛(row)
题目: a potential bug in war system
日期: Fri Jan 21 00:06:11 2000
when attacking general assigning troops, if he put 0 soldier in
his group, which will not terminate the assigning progress at all, there
will be a problem when he finishes all and enters the battle field.
becoz the system checks if the leader got 0 soldier left, he fails
the war.  that is not a error in code, but i think there should be
some way to prevent this from happening. so we need to set a lower limit
of soldier numbers, 50, or 100...since we need at least 2000 soldiers to
attack.


---
作者: 烈火(fire)
题目: panttong's bug
日期: Thu Jan 20 15:09:37 2000
I got pangtong's two bugs
first bug:
庞小统说道：第一个是如果我分兵第一军团成功后，转成分兵第二军团的时候
我reconnect,嘿嘿
> 庞小统说道：可以看见我的第一军团进了战场，而我可以看见敌人的所有分布，这个
时候我还可以继续分兵。
庞小统说道：你是wiz，你知道这意味着什么？
你说道：don't know.
庞小统说道：如果我是进攻方，我进入了战场，但是我的兵力没有分完。系统
不会提示我"带领xxxxx兵士向xxx杀来。"
庞小统说道：而且可以看见敌军的兵力分配。这就占了很大的先机。
庞小统说道：我可以针对敌人的位置继续分兵。
庞小统说道：以我这样级别的战争老手来说，有了这个bug，我们根本就战无
不胜，而且可以减少不少的损失。(当然，实力差距太大的除外。)
庞小统说道：cmd warinfo.
second bug:
庞小统说道：关键是在军营分兵的时候有NPc移动的现象，比如某NPC离开了军
营，往别的方向移动就会出错。
I don't think these two bugs are so fatal as pangtong claimed,
anyway I will check them and fix them soon
and give him two level of skill is good enough lah :)


---
作者: 烈火(fire)
题目: about the rules for opening mirror
日期: Thu Jan 20 15:10:56 2000
I agree with stefan's post
but don't know how could control the mirror if it
doesn't following our rules?
do we have any way to terminate the mirror ?


---
作者: 阿洛(row)
题目: war bug plus
日期: Thu Jan 20 17:45:40 2000
进攻方在分兵的时侯，防守方抢先进入战场，然后撤退。进攻方虽然得到
城池，但所有已分配的军队丢失。应该是个bug。


---
作者: Fire
题目: >war bug plus
日期: Thu Jan 20 18:18:51 2000
On Thu Jan 20 20:45:40 2000 阿洛(row) wrote post #994:
> 进攻方在分兵的时侯，防守方抢先进入战场，然后撤退。进攻方虽然得到
> 城池，但所有已分配的军队丢失。应该是个bug。

I can't find this bug
can anyone test to check if it always this case, or this bug caused by
some other reason


---
作者: Fire
题目: >bug log
日期: Wed Jan 19 15:49:12 2000
On Wed Jan 19 00:24:38 2000 阿洛(row) wrote post #985:
> 可以多人同时探访、慰问、煽动同一个NPC，好象不太好。

I think can't, can it?



---
作者: 阿洛(row)
题目: to fire
日期: Wed Jan 19 05:05:40 2000
pls read mail.


---
作者: Stefan
题目: >about loveyou's hack event
日期: Wed Jan 19 03:41:29 2000
On Tue Jan 18 17:50:13 2000 烈火(fire) wrote post #984:
> I checked loveyou's login records
> and find before monday, all login from 202.100.41.*
> and on monday and tuesday the login from 61.128.*.* and the last
> login record goes back to 202.100.41.*;
> seem his account has been returned. 
> anyway this is a serious problem :(

I already asked him, his previous password was "12345". That is why
easily guessed by the hacker. Actually, not hacker at all,
they are schoolmates :)


---
作者: 阿洛(row)
题目: bug log
日期: Tue Jan 18 21:24:38 2000
可以多人同时探访、慰问、煽动同一个NPC，好象不太好。


---
作者: 阿洛(row)
题目: is info o's restriction working now?
日期: Sun Jan 16 22:47:22 2000
as title.


---
作者: Fire
题目: >is info o's restriction working now?
日期: Mon Jan 17 02:05:51 2000
On Mon Jan 17 01:47:22 2000 阿洛(row) wrote post #976:
> as title.

it supposed to work now, if you find it doesn't work
in some case, there must be a bug there.
addoil


---
作者: Row
题目: >>is info o's restriction working now?
日期: Mon Jan 17 18:03:31 2000
On Mon Jan 17 05:05:51 2000 Fire wrote post #977:
> On Mon Jan 17 01:47:22 2000 阿洛(row) wrote post #976:
> > as title.
> 
> it supposed to work now, if you find it doesn't work
> in some case, there must be a bug there.
> addoil

there is a bug, i found that every player with skills at 30 can
be pos to national officer which means the info o is not working.


---
作者: 烈火(fire)
题目: I got the bug for position requirement
日期: Mon Jan 17 19:28:07 2000
please 
hope it is fixed :)


---
作者: 烈火(fire)
题目: the task system and exception handling
日期: Mon Jan 17 20:11:13 2000
the task system is the most tricky part in this mud.
because a task is not a simple event, it is a sequence
of events and usually last several mins to even one
hour. And it may envolve many chars many players. and
it may affect their behaviors. In this situation, if we
except a task go through the way as we excepted, we need
to write our code very carefully. And in our system, a
char can't be within two tasks at the same time. so we need
to handle the priority problem. For example, when a ppl is
in a meeting, and other area open a war to this area, the
new war task will temerinate the meeting task immediately.
and the real situation may be even more complex. 
Currently, we just have following tasks, they are:
localmeeting, train, war and party. 
Because of the complexity of task system, it is full of
bugs. most bugs are created by exceptions. and a most
serious bug is that a task may can't terminated. such as
players are traped in the warfield for several hours and
a party last several SG month. In order to solve those exceptions
I have following suggestions
1 when you use an object (for example a body) should always check
  if it is still a vilid object. write code like:
  Example:
     if(objectp(o_officer)&&objectp(me))
         o_officer->targetted_action("$N smiles to $T\n",me);
2 for mapping, don't forget to check if it is a map unless you are 
  100% sure.
  Example:
     mapping trps=AREA_D->get_area("changan","troop");
     if(mapp(trps)) // don't forget this line
        footnum=trps["footman"];
3 for arrays make sure it is not an empty array. the following code
  is risky:
     chars=TASK_D->get_task(t_id,"chars");
     foreach(string s in chars) {
	....
     }
   a more safe way is:
     chars=TASK_D->get_task(t_id,"chars");
     if(sizeof(chars)) // don't omit this line, it may save many bugs
       foreach(string s in chars) {
3 and 4 will come tomorrow, boss is coming,
fear


---
作者: 斯坦福(stefan)
题目: a bug found by xfan
日期: Tue Jan 18 06:14:03 2000
反町隆史告诉你：发现个bug
反町隆史告诉你：我任名一名太守(村长)后，我再改回来。然
后再任命
then two chiefs appear.


---
作者: Row
题目: >a bug found by xfan
日期: Tue Jan 18 06:19:03 2000
do they have the same power, or the fake one will be erased
after system refresh?


---
作者: 阿洛(row)
题目: rob's bug report
日期: Tue Jan 18 06:35:53 2000
rob said when he was assigning troops to attack wan, the defend party
retreated, then after rob took wan, he found all his attack troops
were lost, is that a hidden bug in war system? fire check? hehe.


---
作者: 烈火(fire)
题目: about loveyou's hack event
日期: Tue Jan 18 14:50:13 2000
I checked loveyou's login records
and find before monday, all login from 202.100.41.*
and on monday and tuesday the login from 61.128.*.* and the last
login record goes back to 202.100.41.*;
seem his account has been returned. 
anyway this is a serious problem :(


---
作者: 斯坦福(stefan)
题目: reward demand from pangtong
日期: Thu Jan 20 07:11:59 2000
庞小统告诉你：有一个比较严重的bug，是用于战争的。
庞小统告诉你：不过我要奖励g也很大。
庞小统告诉你：我要的奖励是保持我现有先天属性的情况下增加我的先天天赋。
你回答庞小统：还是要个别的奖励吧
庞小统告诉你：那我要我现在的武学修养到70级。
庞小统告诉你：虽然胃口大了一点，但是我认为我提供的bug绝对是值得的。
庞小统告诉你：三国出来两年多，还有这个bug出现，可见wiz在安全的防卫下
              面还有这么大的漏洞？确实应该自我检讨。
庞小统告诉你：战无不胜，你知道这个bug的价值了吗？
庞小统告诉你：也就是说就算你们不奖励，我只要不报告这个bug，达到我想要
              的也只是时间问题而已。甚至更多。

so how? fire, make a decision bah :)


---
作者: 斯坦福(stefan)
题目: mirror regulation for review
日期: Thu Jan 20 09:11:30 2000
                      有关设立三国志分站的条例已及规范


三国志分站申请条例

1. 申请者必须拥有一台与 Internet 连接的 Unix 工作站 (Solaris, Linux,
   FreeBSD) 等。速度越快，带宽越大越好。申请者必须事先获得此工作站的
   所属机构对运行三国志游戏的许可，才可以提出申请。

2. 申请者有遵守三国志总站公布的分站运行规范的责任。

3. 所有分站将运行于加密后的代码，分站申请者有责任保证所下载的游戏软
   件不得以任何形式泄露出去。三国志的游戏软件只能用于各分站的游戏用
   途，分站不得将其转让他人或作它用。

4. 三国志分站的设立完全取决于总站和申请者双方的意愿，所以任何一方都
   拥有向对方提出终止分站运行的权利，而对方有责任给予全面支持。提出
   终止分站运行的一方将保有解释权。


三国志分站运行规范

1. 分站申请者有权指定帮助分站管理的巫师人选，包括申请者在内，最多不
   得超过五人。除此之外，总站将会提供两名巫师给予技术上的支持，将代
   表总站保留对分站管理的决策权。

2. 分站巫师专门负责分站上的玩家事务管理，并不参与编程及三国志本身的
   发展事务。

3. 因为 MudOS 的版权问题，分站不得直接参与任何形式的商业活动以谋取商
   业利润。

4. 分站巫师有义务协助提高三国志游戏的知名度，并为参入分站游戏的玩家
   提供最好的服务，包括：维持分站正常运行，公正处理玩家纠纷，等等。
5. 分站之间不得受理任何传送玩家档案的申请。

6. 如果要改换分站所运行的 IP 地址，需要向总站提出正式申请。

7. 总站目前不会提供与三国游戏配套的网页支持，分站巫师可以自行设计与
   分站相关的网页内容，其网页与总站之间没有直接的责任关系。


三国志分站申请过程

1. 申请人应该写一封正式的申请信，包括：所属机构，自我介绍，申请原因，
   还有用于分站游戏的服务器的配置，IP，以及网络状况，并附上对分站条
   例和规范表示遵守的字样。然后寄给：support@gime.com

2. 在总站巫师就有关事项询问具体细节时，申请人应该及时给予答复。

3. 在申请被批准之后，将会收到设立三国志分站的软件包。

4. 按照软件包中的说明，正确安装并下载三国志游戏。软件包中会提供必要
   的工具帮助游戏的运行，更新以及维护。


---
作者: 斯坦福(stefan)
题目: any comments?
日期: Thu Jan 20 09:13:03 2000
Sorry for the long delay of our server relocation, will be done in these few
days.


---
作者: 阿洛(row)
题目: 游戏规则
日期: Thu Jan 13 18:51:20 2000
到其他mud中取经后我对ice的帖子作了修改，大家看看如何。

    制定本游戏规则的目的是：保证绝大多数玩家的利益，维护一个
相对公平竞争的游戏环境。有对本游戏规则的不同意见者敬请使用三
国留言板或泥潭邮件的方式向我们提出。一旦进入本游戏，您必须遵
守本规则，否则会受到处罚。  

    以下是本游戏目前的规则：

◎  故意破坏游戏运行的玩家，将被宣布为不受欢迎者，而相关ＩＰ
    地址将会被拒绝连线。
        
◎  请勿故意使用和游戏人物或其他玩家同样的名字，请勿故意使用
    带有迷惑性、侵犯性或侮辱性的名字，巫师保留修改或删除玩家
    名字的权力；

◎  请勿在公用或私人频道谈论隐私问题；

◎  严禁在公用或私人频道发布垃圾信息（ＦＬＯＯＤ）；

◎  严禁在公用或私人频道、留言板辱骂其他玩家，进行人身攻击或
　　散布违法言论；
    
◎  严禁一个玩家同时使用超过两个以上的角色（ＭＵＬＴＩ－ＬＯ
    ＧＩＮ）进入三国，由此造成的损失巫师不负责赔偿；

◎  严禁两个或两个以上的玩家使用同一个游戏角色（ＳＨＡＲＥ－
　　ＩＤ），由此造成的损失巫师不负责赔偿；

◎  严禁利用ＢＵＧ牟利，知ＢＵＧ不报，由此造成的损失巫师不负
　　责赔偿；

◎  严禁滥用投票选举权骚扰其他玩家的正常运作；

◎  违反以上游戏规则的玩家在巫师协会讨论通过后将可能受到以下
    惩罚（可以为其中一种或以上）：

　　　具体惩罚：

永久或暂时关闭聊天频道（不能由投票打开）；

所有相关指数扣除百分之十；

扣除所有金钱；

摧毁装备及房屋；

暂时或永久拒绝玩家站点连线的权利（ＢＡＮ　ＳＩＴＥ）；

清除此玩家所有档案（ＰＵＲＧＥ）。

■　对本游戏作出贡献者（如绘制地图、设计迷题等）或提出的意见
　　建议被采纳者将获得奖励；

■  举报ＢＵＧ者，将可能获得奖励；

　　　具体奖励：

增加玩家当时拥有金钱的１０％到５０％（金钱总数不得超过
　　　６０００黄金）；

增加玩家的任何三种或三种以下指数的５％到１０％（上限为
　　　１００）；

升级玩家所拥有的一种或一种以上装备（五级以上无效）；

升级玩家所拥有的房屋（五级以上无效）；

奖励装备或房屋；


注：三国巫师协会拥有以上所有游戏规则及奖惩条例的最终解释权。



---
作者: 斯坦福(stefan)
题目: mirror
日期: Thu Jan 13 20:55:14 2000
开分站的事情我这两天再整理一下，估计等 server 弄好了就
马上开。


---
作者: 斯坦福(stefan)
题目: document listing
日期: Thu Jan 13 20:59:22 2000
I will take ice's suggestion and combine them toteogether and make
some changes. I think one good thing about current method is that I can
actually listed out whatever I want to see in
one page.


---
作者: 斯坦福(stefan)
题目: agree with row on rob affair
日期: Thu Jan 13 21:25:40 2000
rob is not a bad guy in the first place. Also the whole thing was not
really started by him according to those who witnessed. I am tired
of finding out who is right who is wrong. Both rob and rulin said something
disgraceful, so I agree with row to close their chat for 1 week.

I think this can be a warning before the rule comes out, later we just stick
to
the rules.


---
作者: 玄冰(ice)
题目: about the penalty
日期: Thu Jan 13 21:46:25 2000
since our rules is not ready in public, I agree
it can be a warning, just deduct some gold bah.:P


---
作者: 玄冰(ice)
题目: about restart
日期: Thu Jan 13 21:48:01 2000
无花告诉你：what time new open?
have we announced b4?
* doubt


---
作者: 阿洛(row)
题目: a bug
日期: Thu Jan 13 21:59:43 2000
info c xiahou shang
this npc's skills suddenly drop to a unreasonable level, whats wrong?


---
作者: Flee
题目: >about the penalty
日期: Fri Jan 14 01:14:24 2000
On Fri Jan 14 00:46:25 2000 玄冰(ice) wrote post #966:
> since our rules is not ready in public, I agree
> it can be a warning, just deduct some gold bah.:P
agree with stefan and ice ..


---
作者: 烈火(fire)
题目: about y2k
日期: Fri Jan 14 02:32:36 2000
当地时间    一百年一月十四日上午五时三十分
seem our system can't calculate current date
grin :)


---
作者: 烈火(fire)
题目: 三国MUD宪章
日期: Fri Jan 14 04:27:34 2000
三国MUD宪章
    欢迎加入我们的三国梦幻泥潭。作为我们三国大家庭中的一名玩家，你需要
    了解本MUD的宪章。要有资格在此游戏，你必须无条件地接受本宪章的全部
    内容。
    如果你认为你无法接受本宪章的所有规定，请你立刻离开本游戏；如果你继
    续在此游戏，表示你已经接受本宪章的所有内容。
宪章总纲：
    所有玩家是平等的，他们生而具有在此追求胜利，成功和幸福 的权力。
玩家特权：
    1 拥有在本MUD正常运行时自由联线进行游戏的特权。
    2 拥有在本MUD中利用公开和私人频道自由交流的特权。
    3 拥有在指定的留言板留言的特权。
    4 拥有使用MUD mail的特权。
    5 拥有在遇到BUG的前提下，请求恢复损失的特权。
    6 拥有在受到其他玩家(或巫师)的超出游戏范围的人身攻击或不公正待遇时向
      巫师协会申诉的特权。
玩家职责：
    1 不得进行任何影响本MUD安全运转，干扰其他玩家正常游戏的活动。
      例如：hack其他玩家和巫师的密码，flood等。
    2 不得利用任何交流频道，留言板和MUD mail对其他玩家或进行超出游戏范围
      的威胁和各种人身攻击。
    3 在巫师进行编程和测试时，服从巫师的安排，必要时协助巫师工作。
    4 发现BUG，及时利用留言板或MUD mail向巫师汇报。不得利用BUG牟利。
    5 遵守巫师协会制定的所有游戏规则。
基本条例：
    1 玩家在公开频道的言论和留言板的个人创作的文章，其版权归创造的玩家和
      巫师协会共同所有。巫师协会有权在任何媒介上发表和出版这些作品。
    2 对于违犯玩家职责的玩家，巫师协会会进行警告，削减玩家参数和取消部分
      或全部玩家特权的处罚。量刑标准详见《处罚条例》
    3 对于本MUD有特殊贡献的玩家，巫师协会可以给予一定奖励，奖励细节见《
      奖励条例》
    4 本宪章的制定权，修改权和解释权都属于三国巫师协会。


---
作者: 烈火(fire)
题目: 关于宪章的解释
日期: Fri Jan 14 04:46:41 2000
row和ice写的玩家规则都非常好，不足之处就是和其他MUD的
方式基本一致，我想咱们的MUD以创新为特点，在此我们是不
是也可以试验一下其他的形式呢。
我的设想是创造一套更为复杂的法律形式，目前先有一个宪章
然后还可以有《刑法》，《婚姻法》，《战争法》，<地产法》
等等，最后成立由玩家组成的法庭和陪审团系统。我相信在这
方面我们拥有很大的创作空间。
相信一点，玩家间的矛盾是MUD中最好的兴奋剂。grin:)
另外我与row和ice观点不同的是关于multi-login，技术上禁止
multi-login是不大可行的，另外目前multi-login并没有带来
特别大的灾难，在一定程度上，multi-login对我们MUD还是有
利的，所以我不希望把它直接加到规则中去禁止。也许将来，等
有了陪审团系统后，我们可以把这一限制加进去，就是一名玩
家只能有一个ID成为陪审团成员，你们看怎么样？


---
作者: 斯坦福(stefan)
题目: a suggestion from wzc
日期: Fri Jan 14 19:46:44 2000
today 小宝(wzc) asked me to help him with the askjob. Because
he mis-typed an answer, he used up his job quota but still could not get 
any promotion. So he has to wait another day.

I turned down his request. But he is proposing
a suggestion:
小宝告诉你：再说，这样每天只能有一种任务才能加地方贡献，只要一错就没办法，不是
很不利于新手玩吗？小宝告诉你：你们应该改改的，至少应该一天可以多作几次，或者有
多种任务可以加的！
小宝告诉你：这样游戏的可玩性才会高的！


---
作者: 斯坦福(stefan)
题目: changes
日期: Sat Jan 15 05:35:18 2000
I was cleaning up some files, and made the following changes:
1. changed #include "/wiz/fire/fire.h" to #include <sanguo.h> in some files;
2. copied fire's diaochan.c to /sgdomain/npc/, so that
   ./cmds/player/checkemote.c will not use object in /wiz/;
3. copied /wiz/flee/menu/charmenu.c and /wiz/flee/menu/warmenu.c
   to /sgdomain/menu/ so that ./cmds/wiz/chareditor.c and
   ./sgdomain/cmd/warcmd.c will not use object in /wiz/;
4. removed #include "/wiz/ljty/ljty.h" from all horses under
   /sgdomain/obj/horse/. Those horses orignally inherited M_HORSE_1
   were changed to inherit M_HORSE instead. Some adjustment are also made.
   I am not sure I did a right thing here, can anyone confirm is there
   any use of ljty's M_HORSE implementation?
5. /wiz/fire/obj/wear/skirt.c and /wiz/nono/obj/changpao.c are copied
   to /sgdomain/obj/cloth/torso/ because they are used in NPCs involved
   in marriage.
6. removed #include "/wiz/ljty/ljty.h" from ./std/indoor_room.c
And the following are still in question:
1. there is a string path = "/wiz/group/troops/" in /daemons/troop_type_d.c
   is there any particular reason for that?
2. ./sgdomain/npc/fire_officer.c still uses flee's extinguisher.c and
   fire.c, but they can no longer be found under flee's directory. I believe
   this error has caused lots of lines in the runtime logfile. Flee,
   please make some adjustment bah :)


---
作者: 阿洛(row)
题目: bug info
日期: Sat Jan 15 22:24:33 2000
pls check this player--rowcry's info, he has unreasonable high
reputation and literate, he told me he used a bug but didnt tell
me the detail when i asked. so pls check his data and try
to find out the bug...

ps: this guy's main char is grow, he suicided but asked for recover
then, no wiz agreed...hehe


---
作者: 玄冰(ice)
题目: draft of help rules
日期: Thu Jan 13 07:35:13 2000
    制定本游戏规则的目的是：保证绝大多数玩家的利益，维护一个
相对公平竞争的游戏环境。有对本游戏规则的不同意见者敬请使用三
国留言板或泥潭邮件的方式向我们提出。一旦进入本游戏，您必须遵
守本规则，否则会受到处罚。  

    以下是本游戏目前的规则:

◎  故意破坏本游戏运行的玩家，将被宣布为不受欢迎者，而相关IP
    将会被拒绝连线。
        
◎  严禁在公用频道、留言板辱骂其他玩家，进行人身攻击或散布违
    法言论；
    
    严禁一个玩家同时使用超过两个以上的角色进入三国；

    严禁两个或两个以上的玩家使用一个三国的角色；

    严禁利用 BUG 牟利，知 BUG 不报；

    严禁滥用投票选举权骚扰其他玩家的正常运作；

◎  违反以上游戏规则的玩家在巫师协会讨论通过后将可能受到以下
    惩罚（可以为其中一种或以上）：

        永久或暂时关闭聊天频道（不能由投票打开）；

所有相关指数扣除百分之十；

扣除所有金钱；

摧毁装备及房屋；

        拒绝玩家站点连线进入三国的权利；

清除此玩家所有档案（PURGE）。

◎  举报bug者，将可能获得以下的奖励：

        增加玩家当时拥有金钱的10%到50%；

        增加玩家的任何三种或三种以下指数的5%到10%；

        升级玩家所拥有的一种或一种以上装备（五级以上无效）；

        升级玩家所拥有的房屋；

        奖励装备或房屋；


    三国巫师协会拥有以上所有游戏规则及奖惩条例的最终解释权。


discuss discuss bah.:P


---
作者: 斯坦福(stefan)
题目: to flee and group
日期: Sun Jan 23 21:07:14 2000
this server seems to be very fast for Singapore players, come on guys,
do some advertisement in NUS and NTU lah! 

Addoil!


---
作者: 烈火(fire)
题目: About task boards.
日期: Sun Jan 23 19:41:30 2000
We will seperate the development into different tasks. for each tasks,
we will have seperate task news group. It will be easier to monitor
the process of that task. If the tasklist in the wizcommit got no 
objection. I will create several task news group for current tasks.


---
作者: 烈火(fire)
题目: About wiz countries
日期: Sun Jan 23 19:32:36 2000
For testing purpose, I suggest we put all the wiz countries together
Now we have 3 wiz countries, they are located in xiangping, dingjunshan
and yunnan. I think it will be better to transfer the wiz country from
yunnan to beiping. can anyone to negotiate with the players to give the
beiping to wizs?
escape


---
作者: 斯坦福(stefan)
题目: 叶公告诉你：huayin有33个房间吗????
日期: Sat Jan 22 01:28:13 2000
guess this is the most frequently asked question :)


---
作者: 分钟(group)
题目: hunluan move
日期: Fri Jan 21 21:06:38 2000
fixed. now in hunluan condition cant move.


---
作者: 威少爷(suicide)
题目: 大家好
日期: Thu Feb 10 21:18:27 2000
刚刚成为巫师，请
大家多多关照！
i will do my best here.
addoil
)


---
作者: Fire
题目: >about guard
日期: Mon Feb  7 17:52:07 2000
On Mon Feb  7 14:44:54 2000 玄冰(ice) wrote post #1039:
> according to a player's post b4, I do agree the guard should be
> called 城门校尉, so should we change the name of guard to it?
> it's just 2 characters in changing guard.c bah, i guess.:P
> if no one has objection, I may do it later.:P

just do it :)


---
作者: 烈火(fire)
题目: new ideas
日期: Fri Feb 11 10:30:29 2000
this is part from other mud
> 【故事传闻】玉皇大帝：老君，你那儿有没有治笨病的药？
> 【故事传闻】太上老君：有，有，我这儿新研制了一种仙丹，可以使人变聪明。
> 【故事传闻】玉皇大帝大喜道：好，快给我两颗。
> 【故事传闻】太上老君疑惑道：莫非......
【故事传闻】玉皇大帝长叹一声：不是不是，我们家那口子是越来越不行了，
潘桃园亏惨了！还不及弼马温管呢。
> 【故事传闻】太上老君掏出一葫芦：喏，这儿。
> 【故事传闻】玉皇大帝：哎呀！
> 【故事传闻】太上老君：不好，怎么掉了，马上派人去找找。
> 【故事传闻】玉皇大帝：算了算了，不就一仙丹嘛，再给我一颗就是了。
> 【故事传闻】听说天庭遗落了一枚仙丹。


---
作者: 玄冰(ice)
题目: about guard
日期: Mon Feb  7 14:44:54 2000
according to a player's post b4, I do agree the guard should be
called 城门校尉, so should we change the name of guard to it?
it's just 2 characters in changing guard.c bah, i guess.:P
if no one has objection, I may do it later.:P


---
作者: 玄冰(ice)
题目: about prohabiting hackers
日期: Mon Feb  7 14:14:13 2000
I think the way used in FY is good to prevent from hackers to hack
player/wiz's passwd easily.
when a new player logon the server, he will be asked to enter a
passwd that contains with Capitalized characters, uncapitalized
characters and numbers all together, it must increase the difficulties
of hacking other ppl's passwd.  If a player missed some of the above
requirements, he cannot enter the game.

PS. sth that's not involved with hacker:
as i indicated before, the same names of player with different id
may make the ppl confused, since our mud is going to spreadout all
over the chinese mud area, I strongly suggest to add a same-name-check
while a new player is trying to logon our mud.(ofcoz it can be the
same in different mirror or the host server.


---
作者: 烈火(fire)
题目: help,help
日期: Fri Feb  4 05:25:55 2000
the mud just crush every several hours, and can't
auto reboot. what's wrong ?


---
作者: 烈火(fire)
题目: small bug
日期: Sat Jan 29 15:36:17 2000
还有就是我的豆腐做完了，结果另一个同时做工作的人ask guan about
pay就抢了我的任务了。这算不算是bug?


---
作者: 阿洛(row)
题目: 分站
日期: Sat Jan 29 08:35:41 2000
今天上线一看，浙江站的人比这里的多一半，呵呵。
分站的速度对国内来说绝对有吸引力，所以我们必须在主站作好
国外玩家的广告工作，把国外玩家拉过来。


---
作者: 烈火(fire)
题目: tips about clean up
日期: Sat Jan 29 03:51:15 2000
if we want some obj (npc) not be auto clean up by
system. we need add one function in that obj(npc)
  int query_clean_up() {
         return 1;
  }
be careful to use this function, don't use it unless
it is necessary. because it can't be auto clean up
by the system. it will keep there all the time until
you dest it :(. so for obj of this type, make sure
the number of it cna't be big and the code will finally
destroy it


---
作者: 烈火(fire)
题目: about task goups
日期: Sat Jan 29 02:01:24 2000
now we have 8 tasks
and we will make more soon. so wizs
please post your post on related task group
and when you enter news
just type "go task" will list all the task groups
addoil


---
作者: 烈火(fire)
题目: about the job of findbody
日期: Sat Jan 29 01:59:44 2000
I checked the code and find it has no silver reward
I changed it so it will reward 3 - 10 silvers now
ice, please update the help file bah :)


---
作者: Fire
题目: >>sgdomain/event/ev_bwdh/ev_bwdh.o
日期: Fri Jan 28 23:16:59 2000
On Fri Jan 28 22:02:20 2000 Flee wrote post #1023:
> On Fri Jan 28 01:10:27 2000 斯坦福(stefan) wrote post #1018:
> > Seems that BWDH's data is stored there, I think it is
> > not a good place to hold data. Why not move it to somewhere in /data ?
> agree, since not a few of events have a data file, i suggest
> create a event dir under /date dir, and put all event data file
> there.

I creaed the dir, :) 
addoil flee:)


---
作者: 斯坦福(stefan)
题目: serious crash fixed
日期: Sun Jan 30 10:13:21 2000
ZJ site repeated crashed because of a MudOS bug, and now
it is fixed, both ZJ site and here are updated :)



---
作者: Row
题目: >small bug
日期: Sun Jan 30 10:45:11 2000
On Sat Jan 29 15:36:17 2000 烈火(fire) wrote post #1029:
> 还有就是我的豆腐做完了，结果另一个同时做工作的人ask guan about
> pay就抢了我的任务了。这算不算是bug?

i will check it.


---
作者: 玄冰(ice)
题目: about some NPC.:P
日期: Sun Jan 30 10:54:53 2000
【谣言】某人：张角好象投奔宛城去了。
hmm, seems he and his brothers should be bandit yah.:P
and other names in bandit should be reserved to be bandit that
lead the bandit war.:P


---
作者: 阿洛(row)
题目: update
日期: Sun Jan 30 21:37:30 2000
i changed /sgdomain/job/makedoufu/gfz.c and /sgdomain/job/digsoil/sir.c;
please update in mirror.


---
作者: 阿洛(row)
题目: bug log
日期: Mon Jan 31 01:51:22 2000
taishou will leave when player doing robot test, should prevent this
from happening..


---
作者: 斯坦福(stefan)
题目: to fire
日期: Mon Jan 31 02:28:33 2000
In case I am away, this server should always be up running... If not,
please drop me an email at paul@theV.net
1. backup is automatically run everyday, you may want to FTP to your
   own machine and keep a copy.
2. mirror update only happens every half an hour, which means every
   modification you made will appear in the mirror server every 30
   minutes. If you want ZJ site to update his local copy, ask xfan
   to run the "update.sh" in his directory. The relation is as
   follows:
   [our lib] ---------> [mirror server] ---------> [ZJ site]
           every 1/2 hour               update.sh
3. I also promised tiany to let him host our second mirror at Fu Zhou.
   But xfan is bugging me that he needs a leading time of at least
   one month. I think it is reasonable, so I am telling tiany that
   he will not be able to set up SanGuo mirror until late Feburary.
I may be able to check San Guo status when I am at home, and I
will come back to work on 17th Feb.


---
作者: Fire
题目: >to fire
日期: Mon Jan 31 17:10:41 2000
On Mon Jan 31 02:28:33 2000 斯坦福(stefan) wrote post #1035:
> In case I am away, this server should always be up running... If not,
> please drop me an email at paul@theV.net
> 1. backup is automatically run everyday, you may want to FTP to your
>    own machine and keep a copy.
> 2. mirror update only happens every half an hour, which means every
>    modification you made will appear in the mirror server every 30
>    minutes. If you want ZJ site to update his local copy, ask xfan
>    to run the "update.sh" in his directory. The relation is as
>    follows:
>    [our lib] ---------> [mirror server] ---------> [ZJ site]
>            every 1/2 hour               update.sh
> 3. I also promised tiany to let him host our second mirror at Fu Zhou.
>    But xfan is bugging me that he needs a leading time of at least
>    one month. I think it is reasonable, so I am telling tiany that
>    he will not be able to set up SanGuo mirror until late Feburary.
> I may be able to check San Guo status when I am at home, and I
> will come back to work on 17th Feb.

no problem,
have a nice holiday :)
wave


---
作者: Flee
题目: >sgdomain/event/ev_bwdh/ev_bwdh.o
日期: Fri Jan 28 22:02:20 2000
On Fri Jan 28 01:10:27 2000 斯坦福(stefan) wrote post #1018:
> Seems that BWDH's data is stored there, I think it is
> not a good place to hold data. Why not move it to somewhere in /data ?
agree, since not a few of events have a data file, i suggest
create a event dir under /date dir, and put all event data file
there.


---
作者: 玄冰(ice)
题目: about the waterflower bowl
日期: Fri Jan 28 11:56:22 2000
it's supposed to disappear by watered by another player who
complete the waterflower job actually.  for example, if row get
that job, after some watering, he goes to sleep, then I step in
to continue water, the bowl will be finished by me.:P
however, it could be a reason that it's virtual room thus bowl
may disappear if long time no one visit there.:)

I remember the shui hu didn't have time limit to disappear, thus
player can water whenever he find there is a bowl there, it doesn't
sound so good.:P  maybe we can add a time limit in the obj->shui hu,
make it only can be kept for 30 mins sth, like the incense.:P


---
作者: 斯坦福(stefan)
题目: sgdomain/event/ev_bwdh/ev_bwdh.o
日期: Fri Jan 28 01:10:27 2000
Seems that BWDH's data is stored there, I think it is
not a good place to hold data. Why not move it to somewhere in /data ?


---
作者: 阿洛(row)
题目: to group
日期: Fri Jan 28 00:51:11 2000
the waterflower's bug: bowl will disappear by no reason.
maybe it is becoz that the room is virtual, so if nobody be there for
certain time, the room will be cleared from system's memory, so
make the bowl always be there, and make it unaccessable for none-job
player bah...
that's my guess, dunno right or not...hehe.


---
作者: Flee
题目: >huayin
日期: Thu Jan 27 21:04:51 2000
On Thu Jan 27 18:37:54 2000 苑璧(tset) wrote post #1014:
> foxer reported a bug about zuoci job:
> >cmd job foxer
>  24  仙人左慈  zuo ci          41    1  执行 七分钟前     华阴(雍州)
> 
> more /sgdomain/job/zuoci/zuo_tool.c
> 57        here = env->get_area();
> 58        if( !here||here==""||!stringp(here)||here == "huayin" ) {
> 59                write("很显然，不是这儿。\n");
> 60                return 1;
> 61        }
> 
> shouldn't huayin be not appearing in zuo's job totally? someone plz check.
it is not a bug, the huayin in memo just mean that 
the target city is near huayin, not necessorily is huayin.


---
作者: 阿洛(row)
题目: bug log
日期: Thu Jan 27 20:44:25 2000
this always happens:
taishou left b4 player answer robot question, then player get nothing.


---
作者: 苑璧(tset)
题目: huayin
日期: Thu Jan 27 18:37:54 2000
foxer reported a bug about zuoci job:
>cmd job foxer
 24  仙人左慈  zuo ci          41    1  执行 七分钟前     华阴(雍州)

more /sgdomain/job/zuoci/zuo_tool.c
57        here = env->get_area();
58        if( !here||here==""||!stringp(here)||here == "huayin" ) {
59                write("很显然，不是这儿。\n");
60                return 1;
61        }

shouldn't huayin be not appearing in zuo's job totally? someone plz check.


---
作者: 斯坦福(stefan)
题目: huayin.o changed
日期: Wed Jan 26 13:09:25 2000
I changed everything starting with /wiz/fire to be under /sgdomain/.
those npcs and objects are moved to /sgdomain/npc and 
/sgdomain/obj/other/.

it was causing some problem with the mirror site because it does not
have /wiz/fire :)

hope I did not make any mistake to the current mud.


---
作者: 阿洛(row)
题目: a bug
日期: Wed Jan 26 01:55:00 2000
sometimes, li guan (the guy who charge money for marriage) will
appear in some area, then he will cause problems...is this kind of
npc should be removed if there is no celebration?


---
作者: 阿洛(row)
题目: to fire
日期: Tue Jan 25 21:33:01 2000
鉴于目前官位要求提高了，是否相应提高智能测试的机率？或者
干脆取消免除测试的做法，你认为如何？


---
作者: Fire
题目: >to fire
日期: Wed Jan 26 17:28:23 2000
On Tue Jan 25 21:33:01 2000 阿洛(row) wrote post #1008:
> 鉴于目前官位要求提高了，是否相应提高智能测试的机率？或者
> 干脆取消免除测试的做法，你认为如何？

consider
I will calcualte and give a new formula


---
作者: Fire
题目: >a bug
日期: Wed Jan 26 17:28:51 2000
On Wed Jan 26 01:55:00 2000 阿洛(row) wrote post #1009:
> sometimes, li guan (the guy who charge money for marriage) will
> appear in some area, then he will cause problems...is this kind of
> npc should be removed if there is no celebration?

that's right, I will check it


---
作者: 烈火(fire)
题目: 飞鹰告诉你：why 主页无法进去？
日期: Wed Jan 26 19:26:44 2000
web server down ?
how to start it?
xixi:)


---
作者: 烈火(fire)
题目: About task news groups
日期: Mon Jan 24 19:21:12 2000
Now I created 6 news groups
1   task.base
2   task.house
3   task.jimou
4   task.law
5   task.mirror
6   task.multitroop
They are current tasks, so for any post regard these
tasks, please post in related news group. Because some tasks
will go a long term, this will help to maintain the documents.
when we new tasks, we will create related news group too :)
addoil all


---
作者: Row
题目: >About wiz countries
日期: Mon Jan 24 02:04:15 2000
my nation is at bailangshan, it is the closest area to xiangping
and its a level 1 only area, not much affect to players.


---
作者: 阿洛(row)
题目: to stefan
日期: Sun Feb 13 01:40:58 2000
pls add (id) right after the name while someone tell or reply u.


---
作者: 威少爷(suicide)
题目: Can give me the write right in help dir?
日期: Sat Feb 12 23:11:40 2000
like topic.
)


---
作者: 威少爷(suicide)
题目: update help file about who
日期: Sat Feb 12 22:37:00 2000
I have updated the help about about who.
It is in dir of "wiz/suicide",if it is ok please remove it to right dir.


---
作者: 威少爷(suicide)
题目: sth about unify
日期: Sat Feb 12 22:35:35 2000
   After I had seen the archieve news yesterday i found
that the countries in our mud had been unified once by xixixi and
our mud had to be reopened. In my opinion frequent unify is not very
good,so i think if we can have a idea to avoid this or prolong this.

   In the discuss before someone had suggested to dec the efficiency
of transfer or prolong the time of transfer , i still  have  got 3
ideas,let's discuss bah...
   1) 可以创建一或两个机器人控制的国家(例如:匈奴或日本),
它们部队的兵种级别高战斗力相对比玩家的强.这些国家平时玩家可以忽略它
们的存在.而当某个玩家国家过分强大时,它们就会
出兵袭扰攻占该玩家的两到三个城池,造成大兵临境之势,迫使玩家不敢过分屯
兵一处攻打其他弱小的玩家国家,使其两面作战.就算在这种情况下某玩家也统
一了其他玩家国家,我们也可以使他没有大功告成的感觉,因为他下一个面临的
任务就是努力发展base系统升级自己部队的兵种,使之能和机器人控制的国家
抗衡,最终消灭它们.(想想如果某玩家能攻占日本,然后再来一场东京大XX,那
是一件多么有成就感的事).
    2) 某玩家国家的君主亡国后,可以四处流亡,并且可保留其最后国库中一
定比例的金粮物质.当某个太守被其劝说愿意独立时他就可以用这笔资金来资
助这位太守,并且流亡君主可以增加一召集旧部的指令,在帮助独立时可以一次
性募集一定数量的兵力用于提高城池的防守力量,假如独立在周围兵力防备空
虚的地方,甚至可以短时间内攻占一些地方.这时太守要独立因不受限制,哪怕
他的资格没有达到独立的要求.这样即使一个玩家王国后他还有一个东山再起
的机会.
     


---
作者: 烈火(fire)
题目: bug in who
日期: Sat Feb 12 09:49:14 2000
who @三国志浙江站
向“三国志浙江站”发送讯息，请稍候。
[errors] ((none)) Error logged to /log/catch
[errors] *Bad type argument to +. Had array and string
[errors] /daemons/imud_d (daemons/imud/who.c) at line 55


---
作者: Fire
题目: >To fire
日期: Sat Feb 12 09:14:30 2000
On Sat Feb 12 01:35:26 2000 威少爷(suicide) wrote post #1046:
> Hi fire:
>   I have some confusion with writing help file job. My job is to write new
> help files about base system or those help files that up to date?
F
both :)


---
作者: Stefan
题目: >who.c
日期: Sat Feb 12 05:03:33 2000
On Fri Feb 11 21:25:55 2000 桃桃(flee) wrote post #1044:
> i have made some modification on command who.c
> 1) make -m work, to list all idlers;
> 2) -<country id> to list player in the given country;
> 3) @<mirrors> to list users in other sites, in order to do that
> i have make some change on /daemons/imud/who.c, since i am not
> fimilar with the inter mud suffs, can stefan or fire check these
> code, whether there any potential bugs or not.
> i have backuped the original files as /cmds/player/who.flee and
> /daemons/imud/who.c

finger @<mirror> already works for the mirror site. There should not be
any changes needed for /daemons/imud/who.c, please check again :)


---
作者: 威少爷(suicide)
题目: To fire
日期: Sat Feb 12 01:35:26 2000
Hi fire:
  I have some confusion with writing help file job. My job is to write new
help files about base system or those help files that up to date?


---
作者: 威少爷(suicide)
题目: some declaration
日期: Sat Feb 12 01:28:22 2000
Sadlife is my dummy,I use her to test.
So maybe i will call her data.
And for being familiar with this mud soon i will download some file
to see when i am offline.


---
作者: 桃桃(flee)
题目: who.c
日期: Fri Feb 11 21:25:55 2000
i have made some modification on command who.c
1) make -m work, to list all idlers;
2) -<country id> to list player in the given country;
3) @<mirrors> to list users in other sites, in order to do that
i have make some change on /daemons/imud/who.c, since i am not
fimilar with the inter mud suffs, can stefan or fire check these
code, whether there any potential bugs or not.
i have backuped the original files as /cmds/player/who.flee and
/daemons/imud/who.c


---
作者: 烈火(fire)
题目: set_notell([msg|1|0])
日期: Mon Feb 14 23:02:00 2000
set_notell(1) will disable tell
set_notell(msg) will return the msg for not tell
set_notell(0) will enable tell


---
作者: Fire
题目: >bug log
日期: Thu Feb 24 04:36:53 2000
On Wed Feb 23 23:22:28 2000 阿洛(row) wrote post #1087:
> now player can "put" sth which cannot be given in someone, so maybe
> we have to modify the code of put.c
nod row


---
作者: 斯坦福(stefan)
题目: call has no log
日期: Thu Feb 24 09:02:33 2000
better add a log so that any call history can be checked.


---
作者: 玄冰(ice)
题目: typo of sb
日期: Fri Feb 25 07:43:42 2000
> 【谣言】某人：徐州出现煽动性布告，居民议论份份，当地安定下降了。

it's  纷纷 bah
sb change it bah.:P


---
作者: 烈火(fire)
题目: the troop object
日期: Wed Feb 23 07:20:00 2000
I change that to virtual object like virtual char
this way will be easier to find the right object
don't know if get in any bugs


---
作者: 威少爷(suicide)
题目: 大家研究一下
日期: Wed Feb 23 02:31:43 2000
今天中午我和row突然都无法从国内连线到总站.
但当时stefan在总站并且他告诉我们总站运行良好,但只剩5个玩家.
同时我ping总站不同,但有时能受到总站stefan测试的sgz频道信息.
不知何故?
以下log在三国志测试站取得.
> mudlist
在 5 个 MUD 中有 5 个对应的，其中 4 个正在开放。
用 mudinfo <mudname> 来获取更多的信息。
Up  Mud              Address                 Lib           Open Status       
----------------------------------------------------------------------------
U   三国志测试站     130.91.8.120     5000   Lima 1.0a2    open              
U   三国志福州站     210.34.53.200    5000   Lima 1.0a2    open              
U   三国志浙江站     202.96.109.11    5000   Lima 1.0a2    open              
U   三国志总站       208.184.73.226   5000   Lima 1.0a2    open              
> who @三国志总站  
向“三国志总站”发送讯息，请稍候。
> no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
网际频道告诉你：Hidden Names: There are currently
14 heroes wandering the lands.  Names are withheld to protect their
anonymity.
[another mud we don't know?]
no infomation availble!
no infomation availble!
网际频道告诉你：bad-pkt: Packet is of incorrect size.
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
※ 三国志测试站 ※  （当地时间：二千年二月二十二日下午十一时三十六分）
─＝ID列表＝─  目前总人数：2人
─────────────────────────────────────
斯坦福(stefan)     威少爷(suicide)
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
网际频道告诉你：bad-pkt: Packet is of incorrect size.
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
※ 三国志浙江站 ※  （当地时间：二千年二月二十三日上午十二时三十六分）
─＝ID列表＝─  目前总人数：56人
─────────────────────────────────────
小龙(fanwf)        不知道(alter)      情雯(cllin)        无唯子(maodsa)
杀手(seaking)      李歧(lvshui)       萧秋水(zzzzzz)     霸王(bawang)
天子(sunson)       天宇(yan)          二子(erzi)         泥巴(niba)
浪子(zxiaol)       大火球(xixixi)     二月(eryuee)       妖女(seagirl)
无十三(aniu)       武君(wujun)        上官闻樱(slay)     武田晴信(wutian)
不要(buyao)        文武(sos)          请给(bbbbaaaa)     强强(chamcham)
个(aaaabbbb)       恨你(hateyou)      秋风起(aha)        上官闻樱(http)
冬日夕雨(drxy)     阿洛(row)          狂风(kuangf)       黄河(qwe)
冰封(storm)        时代(age)          闪闪动人(giving)   独孤凯(dgkai)
弹弓(zrd)          六翼天使(sixwing)  净明(ate)          风色幻想(fantasy)
风之逝(gone)       威少爷(suicide)    独孤飞雪(feixue)   
黄雄(hxx)          哈哈(zhangke)      扬州王(jianxu)     
泼皮皮(pppp)       陈风名(chili)      汝琳(rulin)        
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
※ 三国志福州站 ※  （当地时间：二千年二月二十三日上午十二时四十五分）
─＝ID列表＝─  目前总人数：39人
─────────────────────────────────────
雨虹(rainbow)             飞翔鸟(ufu)               蚱蜢(locust)
龙狼(ahwoo)               林子(showlin)             笑三少(llf)
另一个人(other)           成吉思汗(china)           曲宁儿(queen)
熊猫 (zcr)                若海(shining)             杜杀(bsc)
幻灵(pulldrag)            小荣(lpr)                 老板张(zzj)
柴贞(ttk)                 好人(kindzcr)             任逍遥(slamdunk)
白发(basten)              时代(xzhao)               蓝欣(aiai)
建御雷(leishen)           冰王子(marco)             孙文(szs)
小马超(hujiang)           傅红血(hrc)               龙儿(oic)
八爪鱼(octopus)           独舞冰场(sofronie)        袭邪(xixie)
云镜(story)               力王(liwang)              无双(wings)
西哈(xiha)                风信子(wcb)               连城笑(qcsjxrds)
吹雪(roc)                 云(linf)                  
l
巫师大厅 [出口：northwest, south, east, north, up, down]
欢迎来到 LIMA，这里是巫师们讨论和发表与 LP MUD 和 MudOS
相关问题的论坛。你也可以在这里询问一些有关中文 MUD 的技术性问题。由
于汉化还不够充分，LIMA 仍有许多的地方有待完善，欢迎大家多提意见。
        使用新闻系统，请用 news 命令。
        使用玩家选单，请用 menu 命令。
        使用邮件系统，请用 mail 命令。
北面墙上镶着一个闪光的轮回台，可以去往人间。西面是静室，它的门正关着。
一个魔法木棍(torch)放在地上，没有人注意。
笑谈天下事【共有0条留言】(board)
隐居贤人斯坦福(stefan) [发呆 4 分钟]
> 【天色】已经是子夜了，周围的一切都笼罩在黑暗之中。
who @三国志浙江站
向“三国志浙江站”发送讯息，请稍候。
> 
※ 三国志浙江站 ※  （当地时间：二千年二月二十三日上午十二时三十八分）
─＝ID列表＝─  目前总人数：55人
─────────────────────────────────────
小龙(fanwf)        不知道(alter)      哈哈(zhangke)      汝琳(rulin)
杀手(seaking)      李歧(lvshui)       情雯(cllin)        无唯子(maodsa)
天子(sunson)       天宇(yan)          萧秋水(zzzzzz)     泥巴(niba)
浪子(zxiaol)       大火球(xixixi)     二月(eryuee)       关雷(tongz)
无十三(aniu)       武君(wujun)        上官闻樱(slay)     妖女(seagirl)
不要(buyao)        文武(sos)          冰封(storm)        武田晴信(wutian)
个(aaaabbbb)       恨你(hateyou)      请给(bbbbaaaa)     强强(chamcham)
冬日夕雨(drxy)     阿洛(row)          秋风起(aha)        上官闻樱(http)
弹弓(zrd)          时代(age)          狂风(kuangf)       黄河(qwe)
风之逝(gone)       六翼天使(sixwing)  闪闪动人(giving)   风色幻想(fantasy)
黄雄(hxx)          威少爷(suicide)    独孤飞雪(feixue)   
泼皮皮(pppp)       萧秋水(xws)        扬州王(jianxu)     
who @三国志福州站
向“三国志福州站”发送讯息，请稍候。
> 
※ 三国志福州站 ※  （当地时间：二千年二月二十三日上午十二时四十六分）
─＝ID列表＝─  目前总人数：40人
─────────────────────────────────────
雨虹(rainbow)             飞翔鸟(ufu)               笑三少(llf)
龙狼(ahwoo)               林子(showlin)             曲宁儿(queen)
另一个人(other)           成吉思汗(china)           杜杀(bsc)
熊猫 (zcr)                若海(shining)             老板张(zzj)
幻灵(pulldrag)            小荣(lpr)                 任逍遥(slamdunk)
柴贞(ttk)                 时代(xzhao)               蓝欣(aiai)
白发(basten)              冰王子(marco)             孙文(szs)
建御雷(leishen)           傅红血(hrc)               龙儿(oic)
小马超(hujiang)           独舞冰场(sofronie)        袭邪(xixie)
八爪鱼(octopus)           力王(liwang)              清儿(qinga)
云镜(story)               风信子(wcb)               无双(wings)
西哈(xiha)                云(linf)                  连城笑(qcsjxrds)
吹雪(roc)                 蚱蜢(locust)              霸王(bawang)
who @三国志总站
向“三国志总站”发送讯息，请稍候。
> 「Fang@Myth and Lore」告诉你：testing
[how this message come?]


---
作者: 烈火(fire)
题目: about the /a/*.c
日期: Tue Feb 22 19:18:41 2000
stefan's suggest is right. I will change the /a/*.c into one or few files.
another  thing is about the soldier lost due to reboot and crash.
I will write sth to record and auto recover in case soldiers lost. then
we can avoid the trouble to recover the lost soldiers. I truely believe
some ppl lie for their lost. but we have no proof :(



---
作者: 烈火(fire)
题目: about the setting in char_d
日期: Tue Feb 22 17:43:15 2000
  "nation" : "group", 
  "name" : "烈火",
  "room" : "/a/xiangping/xp_yst", which room current in, this maybe
removed later
  "type" : 1,  // 1 player, 0 npc
  "hon" : 1246, // honour point
  "status" : 2, // online, sleep or active. obsolute
  "gold" : 2278, // salary money
  "nc" :  national contribution mapping
  "lo" :  relationships with all countries. mapping
  "zi" : "嘿嘿", zi
  "myarmy" : ([ ]), // players own army. need further develop. now nouse
  "gift" : gifts. mapping
  "h" : player's house information
  "literate" : 96008, //
  "catch_area" : "didao", where you can be catch, temp variable set
when you can be caught
                    // still other funcitons all begin with catch
  "wear" : what the player have, mapping
  "ju" : 1, jue wei.
  "lc" : localcontribution mapping
  "skills" : skills mapping 
  "ranklocal" : 180,  the rest are easy to understand
  "reputation" : 97850,
  "age" : 36,
  "gender" : 1, 
  "area" : "xiangping", settle area
   pre_mar is someone you are going to marry
   mar is your spouse
   re_mar is designed by row, maybe a flag to show that this is not
your first marriage


---
作者: 斯坦福(stefan)
题目: >> virtual room
日期: Tue Feb 22 08:06:43 2000
One class occupies more memory than data in the mapping :)

here is the theory:

1. a class file took more than 1k, depends on its program size;
2. a object of a class took more than 16bytes, depends on the variable
space used in the object;
3. a string only take whatever length it is;

So often you would see replace_program(..) in rooms of a MUD. because
each room is often programed as a file, it would be considered
as a different object from the /std/room.c, therefore it would
take up the space of the size of a class, and its first instance, that
is the object of that particular room, would still take the space of
a room object. replace_program() is used in such rooms to replace
the class with its parent, i.e., the /std/room, but still keeps
its own variable in the object itself. 

as a result of replace_program(), all the rooms would take up
object space of their own, but only share one class space of 
/std/room.c. Compared with one room with one class and one object,
it saves a lot.

so that is the theory behind rooms. I believe current virtual room
implementation already saved a whole lot, but I have not checked if
replace_program() is implemented in all the rooms or not. The other
way to save memory is to implement all rooms of San Guo under one class :P



---
作者: Fire
题目: >regular restart
日期: Tue Feb 22 00:59:28 2000
On Mon Feb 21 22:55:48 2000 斯坦福(stefan) wrote post #1078:
> what about a regular restart every two days?
> actually, xfan mentioned this to me. I think it is not
> a bad idea. 
> 这样玩家和和巫师都不用紧张 crash 了。

this is a good idea. better stop all the train, war before restart :)


---
作者: Fire
题目: >virtual room
日期: Tue Feb 22 00:58:28 2000
On Mon Feb 21 22:57:29 2000 斯坦福(stefan) wrote post #1079:
> those rooms under /a are indeed virtual rooms for
> each city. 
> But look at them again, they are all similar. Why not
> integrate all the cities to be in one virtual room
> just like integrating all rooms into one city?
> 
> 
> any comments?

to use one virtual room server to create all the virtual
rooms is possible
but the file name each individual virtual room may be
several character longer. Because we are using char_d
to store all char's current room. so the daemon file for
char_d may be bigger. so it is quite hard to judge few files
bigger daemons and more files smaller daemons, which way is
better?


---
作者: 斯坦福(stefan)
题目: virtual room
日期: Mon Feb 21 22:57:29 2000
those rooms under /a are indeed virtual rooms for
each city. 
But look at them again, they are all similar. Why not
integrate all the cities to be in one virtual room
just like integrating all rooms into one city?


any comments?


---
作者: 斯坦福(stefan)
题目: regular restart
日期: Mon Feb 21 22:55:48 2000
what about a regular restart every two days?
actually, xfan mentioned this to me. I think it is not
a bad idea. 
这样玩家和和巫师都不用紧张 crash 了。


---
作者: Fire
题目: >cmd leave
日期: Mon Feb 21 17:31:33 2000
On Mon Feb 21 08:13:57 2000 分钟(group) wrote post #1076:
> (转载自reporter.bugs)
> mirror site got ppl use leave and rejoin to gain prize
> i add in the clear of nc for cmd leave.
> 
> please check it in ev_leave.c

that's right. and you can also set it to 0 :)


---
作者: 分钟(group)
题目: cmd leave
日期: Mon Feb 21 08:13:57 2000
(转载自reporter.bugs)
mirror site got ppl use leave and rejoin to gain prize
i add in the clear of nc for cmd leave.

please check it in ev_leave.c


---
作者: Fire
题目: >add a new news group bah
日期: Mon Feb 21 17:25:01 2000
On Mon Feb 21 06:46:18 2000 玄冰(ice) wrote post #1074:
> fire, add a new news group called "finance" bah..:P
done, addoil ice


---
作者: 玄冰(ice)
题目: add a new news group bah
日期: Mon Feb 21 06:46:18 2000
fire, add a new news group called "finance" bah..:P


---
作者: 黄帝(emperor)
题目: 我对fate也很感兴趣，but suicide has programed fate system
日期: Sat Feb 19 23:12:48 2000
fate system is very complex system,addoil suicide.


---
作者: Ice
题目: >>>下一步开发计划
日期: Sat Feb 19 20:21:04 2000
no one interest of the fate system?.:(
cry
nip row


---
作者: 阿洛(row)
题目: bug log
日期: Wed Feb 23 23:22:28 2000
now player can "put" sth which cannot be given in someone, so maybe
we have to modify the code of put.c


---
作者: 黄帝(emperor)
题目: 我来做家庭系统
日期: Fri Feb 18 11:49:43 2000
家庭系统是个很复杂的工作，脑子里已有了些思路，正好这两天休息
我仔细想想，先拿个方案出来，给大家看看。


---
作者: 威少爷(suicide)
题目: 请假
日期: Fri Feb 18 05:04:43 2000
我们单位的网今天出问题了，这一阵无法经常上线
特告假数日，忘批准。
:)


---
作者: 烈火(fire)
题目: to suicide,
日期: Fri Feb 18 04:28:21 2000
你的积极申请的精神很好。但基地系统是一个我们已经花了近一年
时间酝酿的系统。到现在才开工，并不完全是因为编程难度大，更
主要的原因是涉及的方面多。从基地，到物资，到商业，到多兵种，
到战争平衡到JOB系统，奖励，角色地区的平衡这里面的关系太复杂。
所以这部分不适宜一个才开始适应我们环境的新手。而我们目前对
你的能力和思路还不十分了解。所以我建议：如果你想要快速对全局
有一个了解。最好从事HELP的整理更新工作。如果想尽快编程，最
好选一个相对较独立的系统如玩家semote或家庭系统(那部分和基地
在程序上有很大的相似处)。另外天灾系统也是一个很有挑战的系统。
如果你特别对基地系统感兴趣，你可以POST一些你的构想，或等我
把核心完成后，来制作一些管理工具，或整理一些资料。你提供的
ascii art图形很好，我还会请你提供很多:)
addoil suicide


---
作者: 烈火(fire)
题目: 任务补充。
日期: Fri Feb 18 04:13:51 2000
还有两个任务：
  1 玩家设计semote的功能。
    基本要求：和现在的semote系统兼容。但是系统可以检索出
    那些是玩家设计的semote，作者是谁。以及使用频率等。玩
    家设计的semote，只有该玩家本人和WIZ可以删改。玩家不
    能删改目前已经有的semote。定期，wiz协会将那些设计较
    好的semote转为正式semote同时对设计者一定奖励。
  2 增加汉帝和各国的关系参数。
    关系越高，对该国官员召见的机会就大。同时召见多半会有
    些好处。关系越差，机会越少，即使召见多半也是训斥一顿。
    搞好关系的方法就有：连年进贡，当然现在可以是金钱，将
    来还有许多物资如：美酒或宝物等。另外就是完成汉帝的任务
    (现在的密召似乎没有启动)。另外如比武大会获胜国，官员
    结婚以及在联合国表现出色等都可以成为增加关系的条件。
    另外对于屡屡侵犯他国，或者国家治理不当，都可以成为降
    关系的借口。
  3 一个提了多次的天灾系统。
任务很多，欢迎目前还没有具体任务的玩家申请。


---
作者: Fire
题目: >>下一步开发计划
日期: Fri Feb 18 01:40:58 2000
On Fri Feb 18 01:32:29 2000 Row wrote post #1061:
> objective clear :) and i apply for taking part in the design
> work for event of 称帝.

so you have to major tasks:)
addoil
sweat row


---
作者: Row
题目: >下一步开发计划
日期: Fri Feb 18 01:32:29 2000
objective clear :) and i apply for taking part in the design
work for event of 称帝.


---
作者: 威少爷(suicide)
题目: 申请加入基地系统开发.
日期: Thu Feb 17 22:46:40 2000
　　我想加入fire负责的基地系统的开发，因为我成为巫师后的开头
工作就是整理撰写基地系统的help文档，现在对整个基地系统的架构
和程序组成运作都有了一定的了解．
　　只要fire发一份基地系统的下一步开发纲要步骤给我，我得到后
马上就可以开始投入编程开发工作．


---
作者: 烈火(fire)
题目: 下一步开发计划
日期: Thu Feb 17 22:11:26 2000
现在我们有了两员新的干将(emperor 和 suicide)开发力量大增。可以实现
许多新的设想。在此我将下一步的工作计划整理一下。不当之处，欢迎讨论。
1 flee&group的计谋系统已经基本完成，这一部份难度很大(admire flee,
  grop)，但还需要一些测试，文档和善后工作。具体我能想到的有以下一些：
  A 为方便测试和平衡，请整理并公布一下公式。同时设定一些参数便于平衡
    个计谋的威力和试用难度等。
  B 关于计谋的学习，除了在宫廷读书外就是向仙人学(向仙人学的细节我不
    了解，听玩家说很贵)。希望能把学习的方法整理一下加到HELP中去。另
    外我建议增加一个新的等级增加办法，就是一个计谋在使用中增加经验，
    当经验达到一定程度可以在自己家里(必须有书房)通过研习提高等级。
  C 完成火计。flee说的对，火计是最难设计的一种计谋，但如果运用的好
    也应该是杀伤力最大的计谋。
  计谋系统我不太了解，上面只是我的一些建议。具体情况请flee和group
  自己掌握。基本原则是实用，合理。
2 联合国系统：
  这是本MUD独一无二的新功能。这一部份由ROW全面负责。我的观点是要从
  可行性出发，先完成简单的，再慢慢完善。ICE的POST非常具体，也很实
  际，可以参考。另外，我和flee可以在编程上帮助一下。但这一部份的重
  点在于构思和过程，另外各种官话和描述也非常重要，而这正是ROW的强项
  。相信这次ROW一定会给我们一个惊喜：)
3 基地系统：
  这是内政部份的基础，下一步就是物资，商业和多兵种。关于这部份，我
  的核心  思路已经成熟。其几本点就是有很强的管理性和扩充性。等核心
  程序完成后，增加新的基地，物资品种，兵种等只需要使用一些菜单就可
  以了。另外大部分的参数和综合效果可以很容易地列表查询，这样就方便
  了今后的平衡工作。还有就是emperor的POST很好，许多地方和我的设想
  不谋而和。也有一些我没有想到的，例如民居。我会尽量把这些好主意吸
  收进来。但为了能够尽快使用，一些好的想法要迟一些才能实现。
4 国王称帝：
  称帝的思想我已经有了一个POST。其最根本的结果是可以拥有更多的国家
  职位，现在还想象不出如何能取代汉帝的功能。我想第一步也不需要考虑。
  从技术上来讲，把一个国家变成帝国只需要call一个函数(COUNTRY_D->
  set_country(c_id,"level",1))就可以了。但这一部份的重点是过程
  和场面。一个国家要想统一是非常困难的，所以能够成为帝国也是一个了
  不起的成就。和暴机没有太大的区别。所以我希望过程一定要充实，场面
  一定要宏大。能使该国的玩家都得到一些实惠和相当的成就感。资料一定
  要永久保留。现在我还没有精力来作这一部份，另外需要许多精巧的设计
  和大手笔的场面描述也不是我的强项。你们谁感兴趣就报名吧：)
5 家庭建设：
  目前我们的家庭系统已经有了一个雏形。但还有许多不合理和不完善的地
  方。例如：
  A 除了厨房和帐房外，其他房间的功能还没有作。
  B 不能同房和生子。
  C 房地产事业还没有搞起来。
  我希望能有一个WIZ来继续家庭系统的建设。这是一个非常重要的系统。
  它可以在我们这个以国家利益为主的游戏中增加一些人情味。这一点可以
  可以打动许多特别是女性玩家的心。使我们MUD变成一个丰富，多元，神
  奇的虚拟世界。同样，谁感兴趣就报名吧。
6 IMUD和WEB
  这主要是stefan的工作了，我们的第一个MIRROR很成功，但也有些问题。
  相信再开其他分站会容易很多。下面是我关于这方面工作的一些建议，仅
  作参考。
  A 增加一个新改动留言板。WIZ只需要把最新改动POST在总站，所有分站
    的相应的留言板会自动更新。
  B 对DAEMON数据分类。
    1 有些DAEMON数据是总站分站同步一样的，如BASE_D。
    2 有些是完全没有联系的如：TASK_D和TROOP_D。
    3 有些是需要先拷贝过去在初始话的如：CHAR_D。
    DAEMON数据出错会导致严重的系统错误甚至宕机。
  C IMUD间使用SEMOTE。
  D 在WEB上显示个站在线人数，用图形显示个站一天内不同时辰的平均在
    线人数；最后就是用图形显示一段时间内(如一个月)每天的平均在线人
    数。不知道这样一个东西好不好做。    
7 HELP的整理。我们的许多HELP都需要更新，还要补充一些。也许HELP的
  结构还要调整。这个工作交给. . . . point ....
目前的基本工作就是这些，请目前还没有具体任务WIZ挑选自己喜欢并能胜
任的工作然后POST具体PLAN。



---
作者: Fire
题目: >help system
日期: Thu Feb 17 21:29:19 2000
On Thu Feb 17 19:48:50 2000 斯坦福(stefan) wrote post #1056:
> I think the help system has to be clean up, many players are complaining
> that the levels and relations in current help system are not 
> that clear to follow...
> 
> any idea?

the helpediter can easily to manage the
change of the help structure. the only problem
is we need a wiz to rearrange the who helps
anyone interested in this job ?


---
作者: 斯坦福(stefan)
题目: help system
日期: Thu Feb 17 19:48:50 2000
I think the help system has to be clean up, many players are complaining
that the levels and relations in current help system are not 
that clear to follow...

any idea?


---
作者: 斯坦福(stefan)
题目: sgz server
日期: Sat Feb 19 00:08:19 2000
The reason that current server connection seems slow is
because the server is not officially in above.net yet :P
Right now it connects to above.net backbone through a DSL
connection, which limits the bandwith and performance.

Soon it will be placed into above.net and connects to the internet
backbone, then it would be faster.


---
作者: 烈火(fire)
题目: the help for jimou
日期: Thu Feb 17 04:51:13 2000
I have installed group's help for jimou
help jimou


---
作者: Fire
题目: >帮助系统
日期: Sat Feb 26 02:10:32 2000
On Sat Feb 26 01:08:18 2000 斯坦福(stefan) wrote post #1098:
> 我觉得目前的帮助系统需要整理一下，提议按以下分类：
> 
> 最近更动  新手上路  角色成长  国家建设  
> 
> 战争系统  人文地理  常用命令  游戏管理
> 
> 其中还可以细分，尽量做到系统化和一目了然最好。谁接手这份工作呢？
> 或者可以让有闲工夫的玩家帮忙，比如 rulin 等 :)     

that's great, point . . . .
escape


---
作者: 斯坦福(stefan)
题目: for reference :)
日期: Sat Feb 26 10:30:35 2000
http://akiratsai.hypermart.net/disappoint-san-internet.html


---
作者: 桃桃(flee)
题目: findfile
日期: Wed Mar  1 08:18:20 2000
>findfile test.c
Badline ... 

fire or stefan, please upgrade it ..


---
作者: 烈火(fire)
题目: about the hook of object_meet.
日期: Wed Mar  1 06:25:49 2000
I checked your code, it's great. But I have some concern. With
the hook of object_meet, whenever an object move to another 
environment it will check the hook of every object in this
environment. I don't know how much cpu power it will used. And
in fact, most the checks will be no result. I think perhaps we
can just add one hook of object_arrived in the rooms, and to check
if the arriving is a player and if the room has some one want to
welcome and so on. I think this way will be much saving. 
Another thing is about the function of init. I don't know much thing
about es2, so don't know what the useage of init() in es2. but in
this mud, we have used a lot of init and samilar function for the
initialization. And to use it as an welcome trigger may cause some
conflicts. So perhaps we can choise another name for this function.
anyway, this is just a small issue. for the system part, I am not
quite familar, maybe stefan and flee can give some better suggestions :)


---
作者: 烈火(fire)
题目: about recover soldiers
日期: Wed Mar  1 05:42:48 2000
now i modified the ev_war ,train and area_d
so before each war and train, the number of soldier in the
area will be saved in area_d with type of ssoldiers
the ssoldiers will store two records one is old
one is new, when new record come, the old new become old
and the new comer will become new, so this will help
us to recover. sigh


---
作者: 威少爷(suicide)
题目: no title
日期: Wed Mar  1 01:57:50 2000
fire :
  have u seen the program i had pasted about init().
please reply me ur opinion soon.
admire fire
massage fire


---
作者: 烈火(fire)
题目: 三国MUD的一点感想
日期: Wed Mar  1 00:02:06 2000
很高兴能看到我们MUD今天的成就。虽然我们还远不是最POPULAR
的中文MUD，但我相信我们是中文MUD中最好的。
我说我们MUD是最好的中文MUD并不是因为我们的任务系统比其他
的MUD要好，也不是说我们的战争系统是独一无二的，甚至都不仅
仅因为我们实现了动态MUD的构想。我说我们MUD是最好的原因是
我们的MUD是建立在一个理想上，而我们的MUD实现了这一理想。
我所说的这个理想有两个方面：
1 我们的MUD提倡团结合作的精神。。
2 我们的MUD不引入个人仇恨。不利用人性中黑暗的一面来增加
  游戏的可玩度。
这是我们最开始构思MUD的基本理想。基于这个理想就很容易理解
为什么我们的MUD在一开始就表明没有PK，淡化SKILL的设计，把
通常MUD中SKILL二百的上限减少到一百。取消了潜能的概念。这
样的设计是带有风险性。很多MUD都意识到PK是一个不好的因素，
在很多情况下可能会真正伤害玩家的关系甚至部份玩家的心里，所
以制定了许多对PKER限制的游戏规则，但都不敢完全拿掉PK，不敢
放弃这个利用人性黑暗面为游戏增添刺激和可玩性的机会。而我们
MUD完全放弃了这一点，而且放弃的非常漂亮。
在我们MUD中，玩家的最高追求已经不再是个人技能的得失，玩家间
的矛盾也不再是个人之间的恩恩怨怨，而是升华到一个国家利益的
高度。同时(不知道你们听过没有，我是经常听说)有人认为中国人
缺少合作精神，就是个人能力再强，放在一起也是一团散沙，甚至
互相拆台。无论这个传闻是真是假，这个MUD都是对这个传闻的一种
挑战。读一读HEI国和LEEYE国的POST，中国人完全可以合作，可以
团结，可以为一个共同的目标奋斗。同时，如果真的有些玩家原本缺
乏合作精神的话，我也希望这个MUD可以增强他们在这方面的素质。
只是不知道他们能不能体会到这一点，如果能体会到这一点，我就是
累死，也感到生有所值了。
下面谈一谈WIZ队伍的情况。既然我们的MUD是以强调团结合作为主题，
我们的WIZ队伍更应该如此。我是一个心直口快没有城府的人。而且相
当固执。在很多情况下不被认为是一个容易合作的人。但在这个MUD中
我们所有的人都合作的很好，在此我非常感激大家对我的谅解和支持。
特别是STEFAN，有数次我们在意见上有很大的分歧，但他都不计较我
有时过激的言语，最后能导致意见的统一。同时我还要感谢ROW，他是
我永远相信的朋友。另外flee,ice,group,tset都是非常难得的合作
夥伴。新来的suicide,emperor我们相处时间还短，不能算很了解，
但我相信也都是可以合作的夥伴。我们之所以能够合作的这么成功，一
方面是我们的WIZ都具有很高的个人修养，另外最主要是和我们的公平
自由的开发环境有关。但无论在什么样的环境下，对于什么样的人，
分歧与不满总是存在的。如何处理这些问题而不使其伤害我们的合作，
我有以下建议：
1 不要隐瞒和压制不满。怎么想就怎么说，不必在意有些不满情绪和
  自身的利益有关。我们都是人，彼此都了解人性的弱点。
2 对他人的意见保持尊重。无论某些事，匝一看是多么荒谬，如果我们
  能真从提意见者的角度出发，这些意见都有其合理的一面。
3 建立完善管理制度，我们有WIZ COMMITTEE，但当时定的一些规则
  现在大都被遗忘。同时有些也许已经不再适合目前的状态。所以我
  建议能从新整理一下，讨论后再公布执行。
罗唆了一大篇，如果你们眼睛还没有看累的话，我手已经输入累了:)




---
作者: 威少爷(suicide)
题目: can move na.c from /cmds/verbs/ to /cmds/player
日期: Tue Feb 29 23:33:42 2000
for ppl can't use na when riding horse.


---
作者: 威少爷(suicide)
题目: A example from my own lima(no modify to fit this system)
日期: Tue Feb 29 22:25:34 2000
//filename: /domains/yangzhou/npc/xiaoer.c
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit LIVING;
inherit M_CONVERSATION;
inherit M_VENDOR;
#define OBJS "/domains/yangzhou/obj/"
void init(object ob)
{ if (environment(ob)==environment())
     do_game_command("mpolite "+ob->query_primary_id());
}
void buy_thing()
{
  write("客官可以用<list>命令察看我可以卖的东西!\n");
}
void setup() {
    set_id("xiaoer");   //开头字母必须为小写，否则无法Look
"/domains/yangzhou/npc/xiaoer.c" (1-20 23%) [h]:
    set_name("店小二");
    set_gender(1);
    set_long("店小二殷勤地站在店里，随时等候为客人服务.");
/* Determines what type of currency we'll use */
    set_currency_type("gold");
/* Tells vendor we will sell things */
    set_for_sale(1);
/* Tells vendor we will buy things */
//    set_will_buy(1);
/* itemization of what we sell initially filename : #
   if # is set to -1, it will sell an infinite # of that item
*/
    set_sell(([
     OBJS "mantou" : -1,
     OBJS "doujiang" : -1,
     ]));
"/domains/yangzhou/npc/xiaoer.c" (21-40 46%) [h]:
/*   We would set this so that the vendor stores weaps/armor in a storage
   room.  See help on set_unique_inventory.  storage.c in the rooms subdir has
   been set up to work.
    set_unique_inventory(__DIR__ "rooms/storage");
*/
  /* We would set this if we wanted EVERYTHING to be stored in a storage
   room.
   set_all_unique(1);
*/
    
    set_options( ([
        "hello" : "Hello!",
        "greeter" : "What do you do?",
        "where" : "Where do I get LIMA?",
        "problems" : "I'm having problems setting up LIMA.",
        "compilation" : "Where should I report MudOS compilation problems?",
"/domains/yangzhou/npc/xiaoer.c" (41-60 69%) [h]:
        "intermud" : "How do I get on intermud (I3)?"
    ]) );
    set_responses( ([
        "hello" : "Hello, and welcome to the LIMA mudlib!  I'm
designed to answer some
basic questions you might have about it.",
        "greeter" : "I help people with basic questions and problems
with the LIMA
mudlib.  I also demonstrate LIMA's M_CONVERSATION module, which makes building
NPCs who can hold intelligent conversations a snap!  Feel free to
read my code,
its in " + __FILE__ + ".",
        "where" : "LIMA, like almost all MudOS libs, is available at
ftp.imaginary.com,
and its mirror aragorn.uio.no.  Look in the /pub/LPC/lib/LIMA directory.",
        "problems" : "I can help you with compilation problems, and
getting your MUD on
the intermud network.@@intermud,compilation",
        "compilation" : "Problems compiling MudOS should be reported to
mudos-bugs@imaginary.com.",
        "intermud" : "First, edit config.h and make sure ADMIN_EMAIL
is set correctly. 
If it isn't, you will not be permitted to connect.  Then do 'update
/daemons/imud_d'.  You should be on the net.  You can check with
'mudinfo <your
mud name>' from here.  Use 'igossip /on' and 'icode /on' to turn on
the standard
channels."
    ]) );
    set_start( ({ "hello", "greeter", "where", "problems" }) );
    set("inquiry", ([
     "name":"连我你都不认识？大名鼎鼎的店小二就是我。", 
     "here" : "鬼知道这是什么地方！我只负责卖点东西混口饭吃。",
     "buy" : (: buy_thing :),
   ]) );
 
    add_hook("object_meet",(:init:));
   // unguarded( 1, (: restore_object , file_name()[0..<3] :) );
}


---
作者: 威少爷(suicide)
题目: way of init()
日期: Tue Feb 29 22:22:37 2000
对/std/object/move.c的修改:
1 在function varargs mixed move(mixed dest, string where) 
  的 return MOVE_OK;  前追加以下code:
    //:HOOK object_meet
    //Called by the obs in the new envirionment where an object move to 
    //The return value is ignored.
     obs = all_inventory(dest)-({this_object()});
     call_out((:do_meet,obs,this_object():),1);
 
2 增加函数do_meet()
  void do_meet(object *obs,object ob)
{
  obs->call_hooks("object_meet",HOOK_IGNORE,0,ob);
  for (int i=0;i<sizeof(obs);i++)
      ob->call_hooks("object_meet",HOOK_IGNORE,0,obs[i]); 
}


---
作者: Fire
题目: >>hook is the way to go
日期: Tue Feb 29 21:51:14 2000
On Tue Feb 29 20:31:22 2000 Suicide wrote post #1123:
> i agree with stefan .
> i have added the init() func in my lima bean by using hook.
> for all obj's move use modules m_move's func move()
> i add a hook called "obj_meet" in it.
> when some obj need to  do sth when interacted  it just only need 
> to write a func link to hook obj_meet()
> i think this hook is useful in writing RPG game program.
> i think it is better to add some RPG thing in our mud later.

that's good,
can you put the code under your directory and let use
have a look, if it compible with our current mudlib and
don't consume too much cpu power, we can use it :)


---
作者: Suicide
题目: >re: emperor
日期: Tue Feb 29 20:45:12 2000
disagree "text mud got no future"
I think if we can code a friendly client that ppl needn't input sth
All cmd and suggest can be chosen by the mouse then the text mud
will live forever.
For graphic game the art design is the most important thing .
We ,as a programmer, can do nothing without the pic to code a graphic game.
I had tried to code a pc graphic game ,but soon i gived up for i
have no pic to use.
And can't find sb who is familair art and computer to help me.
So i disagree " text mud got no future"
I had thought the life of the text mud for a long time.
I think if we can code 友号的客户端
免玩家烦琐的命令输入,所有的命令可由菜单条用鼠标选择,那么
LONG LIV TEXT MUD.

xixi:)


---
作者: Suicide
题目: >hook is the way to go
日期: Tue Feb 29 20:31:22 2000
i agree with stefan .
i have added the init() func in my lima bean by using hook.
for all obj's move use modules m_move's func move()
i add a hook called "obj_meet" in it.
when some obj need to  do sth when interacted  it just only need 
to write a func link to hook obj_meet()
i think this hook is useful in writing RPG game program.
i think it is better to add some RPG thing in our mud later.


---
作者: 斯坦福(stefan)
题目: re: emperor
日期: Tue Feb 29 12:00:50 2000
thanks for posting related stuff :) Lima has gone dead
for a few years, I really hope they can come back :P 

I never tried DGD, but I would guess its license is not that
"great" at all, still no good for commercial mud.

I am writing a new engine, and I have already informed each
individual in this sanguo wiz group. That is also why I
dont really have time to put effort on the web pages.


I will release it as GPL, soon everyone can take a look,
see wheather the design is better or not :)

text mud got no future.


---
作者: 黄帝(emperor)
题目:  Mudlib for DGD
日期: Tue Feb 29 09:38:31 2000
 Mudlib for DGD
The latest version of the Melville mudlib is stored in this directory.

Melville is a mudlib written by Stephen Schmidt (Mobydick) for the DGD
driver. It is a small starter mudlib which you can use to organize a
group of wizards for your own coding projects. It has a working mail
system, bulletin board, channel daemon, and room system so that you can
communicate as a group, a player/wizard/admin hierarchy of wizards to
organize code access, and support for most traditional LP features like
object inventories, command paths, object-defined commands, emotes and
soul commands, and so forth. It does not have any game features such as
combat, magic, races, or levels. This makes the mudlib more suitable
for non-game applications as well as leaving you free to implement any
game features you want in your own fashion. It has 49 commands,
23 for players and the rest for wizards or admins.

The current version of the lib, 0.9, takes up 89k compressed and will
uncompress to 399k; it contains 141 files. It unpacks to a single directory
calld melville which contains all of the code and supporting documentation.
To use it, you need to download and compile the DGD driver, which is probably
available on the same site as this. Version 0.9 of Melville should work
with version 1.1 of DGD.

Questions and feedback on Melville can be directed to Mobydick at
schmidsj@union.edu.




---
作者: 黄帝(emperor)
题目: lima1.0a9 is release now
日期: Tue Feb 29 09:17:25 2000
as title.


---
作者: 黄帝(emperor)
题目: LPMUD FAQ之一
日期: Tue Feb 29 09:16:39 2000

    Can I charge players to play my mud?
    
   If you write the server from scratch AND you wrote your mudlib from
   scratch and you have agreements with the coders who wrote areas on
   your mud, the answer, of course, is yes. The above will take roughly
   3-5 years of full-time work to accomplish as well.
   
   If you do not wish to go through all of that time to write your own
   server and object library, then you may only user DGD. Of course, you
   will have to get express permission from Dworkin. The only object
   library you may use for such purposes is LPMoo.
     


---
作者: 斯坦福(stefan)
题目: about mirrors and admins
日期: Tue Feb 29 08:11:15 2000
Just some explanation behind the mirror and admin arrangement..

I am controlling mirror application, but if somebody can help to
give any advice, I would really appreciate it. I am not very familar
with China's network situation, and ZJ site is open because it is
on 169 net, FZ site is open because it is on eduation net, TW site
is open because there is no other TW applicant, and I think it is
better to have some exposure in TW than none. Row and Emperor
have given me some advice on it, thanks.

The admin in mirrors. I feel terribly sorry after reading Fire's
email. I have to say it was not my intention to put myself as the
only Admin in the mirrors. The reason is PASSWORD. I chose not to
put any main site wizs' data files in the mirror package because
I am afraid when any of us types password, it would be snooped by
the mirror's root user, and would end up with main site being
hacked through wiz account. And I specially chose another password
for myself in the mirror package and change it immediately after
the mirror first booted up so that I have different password at
every single mirror site.

It has been suggested that every wiz here can take care of some  
of the mirrors by being Admin there, and I fully agree. But it is
dangerous for me to choose a password on your behalf, and I thought
it would be easier after I go in and promote the mirror-admin-to-be.
If this has offended any of our wizs, I would sincerely apologize.

I always feel quite delighted when seeing our wizs group can work
together in a happy and seamless fashion, and it is my fault that
I did not notice my action could have cause such a mis-understanding.
I never took it for granted that this mud is owned by me or by anybody.
All the wizs, as a group, are the owner. If you have ever contributed
some effort, even a single line of code, you are deserved to have
the joy of the success of this mud. It is also why earlier on I
dismissed the opinion of charging mirror sites for money in return.
Think about it, if we have $100 income, who gets $10 who gets $50?
Without any legal bound between us or a legal person to represent
the right, I would rather choose to have no income.

And also my thanks to fire, who pointed out my fault up and straight.
which is the way I always like when he deals with things.

I will post out mirror arrangement in a later post.

stefan


---
作者: 斯坦福(stefan)
题目: hook is the way to go
日期: Tue Feb 29 07:23:52 2000
If we had designed things more clearly :)


---
作者: 烈火(fire)
题目: about trigger
日期: Tue Feb 29 05:20:51 2000

flee is right, you can use /std/modules/m_trigers.c
but i don't think m_triggers.c is very good
if want better performance, perhaps just directly override
the receive_outside_msg and receive_private_msg.
however all this kind of things may make misjudge, because if 
you say something which matchs the patten, it will also react, 
but for common npc, that is ok. in order to make the parse of 
incomeing object more correctly better to use hook, but that 
may need adjust the environment so perhaps don't worth for 
this simple case


---
作者: Fire
题目: >>>> 请教
日期: Tue Feb 29 05:17:58 2000
On Tue Feb 29 02:42:43 2000 桃桃(flee) wrote post #1114:
> i think the init() is disabled in lima lib
> for the functionality of it, such as suicide refered 
> 触发器, m_trigger servers the same purpose ..
> it should be located at /std/modules/m_trigers.c //not sure .. 

flee is right, you use /std/modulesm_trigers.c
but i don't think m_triggers.c is very good
if want better performance, better directly override
the receive_outside_msg and receive_private_msg
but all this kind of may make misjudge, because if you say something
match the patten, it will also react, but for common npc, that is
ok. in order to make the parse of incomeing object more correctly
better to use hook, but that may need adjust the environment
so perhaps don't worth for this simple case


---
作者: 桃桃(flee)
题目: >>> 请教
日期: Tue Feb 29 02:42:43 2000
i think the init() is disabled in lima lib
for the functionality of it, such as suicide refered 
触发器, m_trigger servers the same purpose ..
it should be located at /std/modules/m_trigers.c //not sure .. 


---
作者: Suicide
题目: >>请教
日期: Tue Feb 29 02:39:18 2000
create() can only be called when obj first created.
but init() can be called when interacted by other things.
For example :
  when i enter a 客栈 the 小二 object that had beed created before
can just say sth instead of using a random time to say .

inti() just like a 触发器.
if our mud haven't open this func i'd like to do it.
i have finished it in my own chinese lima bean.
xixi.


---
作者: 桃桃(flee)
题目: about 三国排名
日期: Tue Feb 29 02:11:54 2000
i suggest use XKX's style, top 100 players will be
announced each week, however, only top 10 will be
recodered as history .. 


---
作者: Flee
题目: >请教
日期: Tue Feb 29 02:10:19 2000
On Mon Feb 28 23:12:23 2000 威少爷(suicide) wrote post #1110:
> women 
> 我们的mud中有类似es2中的init()函数吗?
try create()


---
作者: 威少爷(suicide)
题目: 请教
日期: Mon Feb 28 23:12:23 2000
women 
我们的mud中有类似es2中的init()函数吗?


---
作者: Group
题目: >to group
日期: Mon Feb 28 01:51:33 2000
On Sat Feb 26 06:07:18 2000 玄冰(ice) wrote post #1102:
> > 白子(kdkk)告诉你：qing feng cant searchwise
> > 白子(kdkk)回答你：那我们会领到任务的
> > 白子(kdkk)回答你：那我们会领到任务的
> 白子(kdkk)回答你：浪费任务个数 :(
> consider to do sth bah.:P
before i create them, i have set that whisper can not performed to
group's country.
seems i need adjust some code to make sure leave dont happen to my
npcs as well..

thank you for the bug..^^


---
作者: 分钟(group)
题目: about the leave
日期: Mon Feb 28 02:22:06 2000
is that reasonable to make those high loyalty and high skilled npcs
have very low 
leave rate? in sanguo time, this kind of npcs almost never move around..^^

group


---
作者: Fire
题目: >帮助系统
日期: Sat Feb 26 02:10:32 2000
On Sat Feb 26 01:08:18 2000 斯坦福(stefan) wrote post #1098:
> 我觉得目前的帮助系统需要整理一下，提议按以下分类：
> 
> 最近更动  新手上路  角色成长  国家建设  
> 
> 战争系统  人文地理  常用命令  游戏管理
> 
> 其中还可以细分，尽量做到系统化和一目了然最好。谁接手这份工作呢？
> 或者可以让有闲工夫的玩家帮忙，比如 rulin 等 :)     

that's great, point . . . .
escape


---
作者: 斯坦福(stefan)
题目: 帮助系统
日期: Sat Feb 26 01:08:18 2000
我觉得目前的帮助系统需要整理一下，提议按以下分类：

最近更动  新手上路  角色成长  国家建设  

战争系统  人文地理  常用命令  游戏管理

其中还可以细分，尽量做到系统化和一目了然最好。谁接手这份工作呢？
或者可以让有闲工夫的玩家帮忙，比如 rulin 等 :)     


---
作者: Fire
题目: >strange thing
日期: Sat Feb 26 00:18:32 2000
On Fri Feb 25 15:36:18 2000 玄冰(ice) wrote post #1092:
> I tried put gold in another body, then it got lost, it's reasonable.
> however, i dest myself then relog, the system says illegal copy 
> and then i found my gold back to my body.
> is that strange?.:P

the reason is you dest yourself, if quit will not have this problem


---
作者: Ice
题目: >好象正在训练的兵力并不计算在侦察结果中
日期: Fri Feb 25 22:50:34 2000
right, i think it's reasonable though it might be not our original
propose.  just like 珍珠港事件, enemy cannot spy if the troops r out
to train.:P


---
作者: 威少爷(suicide)
题目: 好象正在训练的兵力并不计算在侦察结果中
日期: Fri Feb 25 21:43:01 2000
as title


---
作者: 玄冰(ice)
题目: war bug bah
日期: Fri Feb 25 21:11:50 2000
> 天山(san)告诉你：we attack changan from xianyang
天山(san)告诉你：we spyed a few minutes before war
天山(san)告诉你：the troop in changan is 10k
天山(san)告诉你：they have 20k mingbing and 20k+ troopin war

seems nowadays wiz not war at all? sb start a war to see see bah.:P


---
作者: 玄冰(ice)
题目: about info
日期: Fri Feb 25 20:47:27 2000
nowadays the info become longer and longer, I think info a and info c
can be devided by using sub-order like the following:
info here/a will show basic info like weather,name,neighbours..
info here/a t will show troops info in detail
info here/a s will show stuffs here in detail
info me/c will show basic detail
info me/c r will show the relations....
blah blah
maybe later i can give a sample view of it.:P
how do u guys think about it?


---
作者: 玄冰(ice)
题目: strange thing
日期: Fri Feb 25 15:36:18 2000
I tried put gold in another body, then it got lost, it's reasonable.
however, i dest myself then relog, the system says illegal copy 
and then i found my gold back to my body.
is that strange?.:P


---
作者: 斯坦福(stefan)
题目: bug report from yesh
日期: Fri Feb 25 11:36:04 2000
高欢(yesh)告诉你：I guess there is some bug
高欢(yesh)告诉你：we spy shouchun yesterday, they had only 20k+
高欢(yesh)告诉你：but today they has 40k+
高欢(yesh)告诉你：会不会有bug
高欢(yesh)告诉你：还有 我们上次偷袭 changan
高欢(yesh)告诉你：战前 30 分钟不到的spy 他们才 10K+
高欢(yesh)告诉你：打时确有 20K+
高欢(yesh)告诉你：很奇怪的
高欢(yesh)告诉你：我不相信wiz会给他们加兵
高欢(yesh)告诉你：不过好象有bug
高欢(yesh)告诉你：我半年前在longxi 就莫名其妙的多出来兵
高欢(yesh)告诉你：一天之内要在一个城征两万兵几乎不可能的
高欢(yesh)告诉你：当时我马上要quit了
高欢(yesh)告诉你：那时每天上来就忙裁兵
高欢(yesh)告诉你：longxi 原来就只有 10k
高欢(yesh)告诉你：一夜之间 多出来 20k
高欢(yesh)告诉你：搞得粮食 金 都不够了
高欢(yesh)告诉你：好几天之后才停止自然增兵


---
作者: 烈火(fire)
题目: about call
日期: Sat Feb 26 05:49:20 2000
now the use of call is also loged as @
in /log/call
addoil


---
作者: Ice
题目: >>帮助系统
日期: Sat Feb 26 05:51:41 2000
point
blink


---
作者: 玄冰(ice)
题目: to group
日期: Sat Feb 26 06:07:18 2000
> 白子(kdkk)告诉你：qing feng cant searchwise
> 白子(kdkk)回答你：那我们会领到任务的
> 白子(kdkk)回答你：那我们会领到任务的
白子(kdkk)回答你：浪费任务个数 :(
consider to do sth bah.:P


---
作者: 斯坦福(stefan)
题目: for reference :)
日期: Sat Feb 26 10:30:35 2000
http://akiratsai.hypermart.net/disappoint-san-internet.html


---
作者: 玄冰(ice)
题目: about txt mud
日期: Thu Mar  2 11:20:57 2000
I think txt mud won't die for the near future, at least i like
the txt mud.:P  suicide is right, we dun have graphical designer
in our team bah.:P  if need to develop a graphical version, we
need at least half dozen wiz to work for the graphic
on the other side, i apperiate graphical version bcoz it's more
visible, and more attractive .:P
however, in my experience, I have seen a mud died bcoz the wiz team
r emphasize to develop the graphical version, then both project died...
* fear
if we r intending to develop a graphical version, we need to state
clearly the task allocation, otherwise we'll get in the same way of
the dead canada sanguo mud.:P
regards.:)


---
作者: 玄冰(ice)
题目: about development
日期: Thu Mar  2 11:27:03 2000
today i logged in then queried by player.:(
they query that why qibing is changed to less useful now, it wasted
me a lot of time to explain it.  and a player said that why we put
some not mature projects in the game......
it reminds me a little, we r socalled "officially opened" now bah,
thus we cannot announce it's a developing mud, it's a test version...
so i think maybe we can work in this way, we can establish a test
site for test only, player are welcome to login that site, but will
be warned that all the data in that site is just for test, however, 
they have rights to test the latest developing project there, it can
be called our lab there.:P
just a thought in mind, how do u guys think about that?


---
作者: 斯坦福(stefan)
题目: graphics and text
日期: Thu Mar  2 13:16:08 2000
A good MUD does not die because it is text based, but
its future is definitely limited due to the text contraint,
due to the underlining engine, be it a LPmud or DGD.

A good point that ice mentioned is about the team and the 
focus. I totally agree with that. So far I have seen
XYJ, XKX and FY being successful, but all of them have stopped
development more or less. Why? There isn't much space left :)
Also, wizs come and wizs go, people get lazy when a MUD
gets to a certain stage. 

Graphics sure takes a lot of effort to develop, and not every
mud got that resource, especially human resource. I would not
think it is a easy task to accomplish. But again, compared to a
graphics mud, the text based mud is much limited. I appreciate
the beauty of literature, but how many people actually pay 
attention to the room description after playing for a month? :)

Being a compromise to both sides, I would envision
a mud that supports both text and graphics, independantly. 
It is pointless to talk about graphics mud without a good engine
to support it, and that is just the engine alone, for the 
 graphics mud to be successful, the client is very crucial.

If any mud ever gets from a text based to that stage, it
is either converted to a real company with finacial support, 
or a complete open source project where everybody works for
free, but definitely not the current style where only wizards
hold the code and players never get them. The current style
suffers from the license problem. All of XKX, XYJ, FY and SGZ 
have this problem, but ES2 and Lima do not because their
source code is released to everyone.

An example is Graphics King of Kings. GKK can be found
at http://www.lager.com.tw/gkk/ and its ancestor KK
can be found at http://www.lager.com.tw/muds/kk/, which
was originally based on ES2. They run into license
problem.


---
作者: 烈火(fire)
题目: about findfile
日期: Thu Mar  2 19:19:57 2000
The reason for findfile can't build up a search database
properly is under the /data/M, there are about 15356 files.
so the mud's file system can't hold too many files under
one directory.
The files under this directory are all the mudmails. one
mail will create one file. And i don't know if a ppl suicide
or purged, still his mails keep here or not. Now I let the 
findfile skip this directory. so findfile is ok. But later
we may need improve lima's mudmail system.



---
作者: Row
题目: >about development
日期: Thu Mar  2 20:49:33 2000
as the matter of fact, our sanguo is officially open though we
didnt exclaim that. players play this mud for real and really enjoy
their moments here, which is a great honor of all of our wizs. however,
this doesnt mean a stop to development but more like a push, we need to
keep our mud a fresh and wonderful world so that it may attract more ppl.
as the problem pointed out by ice, it is true and was surfaced b4, but,
as far as i can see, players r busy here (as we hoped :P) and wont have
enuf time to spend in another test site although it wont be troublesome
for us to open such one. so, the current situation demands our wiz team
to consider very carefully b4 releasing any new projects, besides, we need
to set the changes to the minimum in order not to cause big loss in case there
r bugs. anyway, the current situation is satisfying, players r cooperative
and know how to raise their suggestions at proper way and time.

God bless us.


---
作者: 阿洛(row)
题目: about national officer positions
日期: Thu Mar  2 21:23:56 2000
部分老玩家抱怨国家官员的位置太少，附合要求的人多。
我认为虽然我们不能令每个人都能当上国家官员，但也
可以适当考虑增加三五个职位。大家以为如何？


---
作者: Suicide
题目: >>about development
日期: Thu Mar  2 21:39:41 2000
I agree with row.
If we add a new development site how to attract ppl to just help us test?
So the right way is still develop at this site. 
But we could post a title at the caolu to tell ppl that what condition 
we met. When we add some new function here we have to need there test.
For we can't test the new function anywhere else.
Get their understanding i think thry will support us.


---
作者: 阿洛(row)
题目: 分站玩家的意见
日期: Thu Mar  2 22:06:23 2000
zj站玩家抱怨忠诚为100的npc 下野几率太大，是否应该
改为先搜索忠诚不满100的npc下野，然后再轮到100的。


---
作者: Fire
题目: >about national officer positions
日期: Thu Mar  2 22:27:41 2000
On Thu Mar  2 21:23:56 2000 阿洛(row) wrote post #1141:
> 部分老玩家抱怨国家官员的位置太少，附合要求的人多。
> 我认为虽然我们不能令每个人都能当上国家官员，但也
> 可以适当考虑增加三五个职位。大家以为如何？

it is you who is undertaking the development of emperor country
hehe row
addoil row
when they got empire, they should have enough position lah
hoho row
massage row


---
作者: Fire
题目: >分站玩家的意见
日期: Thu Mar  2 22:28:05 2000
On Thu Mar  2 22:06:23 2000 阿洛(row) wrote post #1143:
> zj站玩家抱怨忠诚为100的npc 下野几率太大，是否应该
> 改为先搜索忠诚不满100的npc下野，然后再轮到100的。

now it is the way mah
xixi


---
作者: Row
题目: >>about national officer positions
日期: Thu Mar  2 23:58:18 2000
On Thu Mar  2 22:27:41 2000 Fire wrote post #1144:
> On Thu Mar  2 21:23:56 2000 阿洛(row) wrote post #1141:
> > 部分老玩家抱怨国家官员的位置太少，附合要求的人多。
> > 我认为虽然我们不能令每个人都能当上国家官员，但也
> > 可以适当考虑增加三五个职位。大家以为如何？
> 
> it is you who is undertaking the development of emperor country
> hehe row
> addoil row
> when they got empire, they should have enough position lah
> hoho row
> massage row

faint, i didnt finished union yet....sigh


---
作者: 烈火(fire)
题目: the meet event
日期: Thu Mar  2 04:31:53 2000
suicide has introduced the idea about when you enter 
a room the npc should greet the players. that's good
But I think suicide's method may use more cpu power
than necessary. I have created three modules can handle
this problem. The three modules are
1 M_MEETPLACE /sgdomain/modules/m_meetplace.c
2 M_GREETER /sgdomain/modules/m_greeter.c
3 M_GUEST /sgdomain/modules/m_guest.
for example, if you enter a store and the keeper will
auto welcome you. then, the room should inherit the
m_meetplace, the keeper inherit the m_greeter and you
inherit m_guest. then in order to make the hook work
the m_meetlace should be started by using set_can_meet(1)
Now i make the base_room inherit the m_meetplace and
body inherit the m_guest and all the makers inherit
the m_greeter so you will be welcomed when you enter a
store:) and there is still another event called do_send
that will happened when you leave the store. this kind
of functions can also be used to other objects.
addoil:)


---
作者: 阿洛(row)
题目: about post
日期: Tue Mar  7 00:48:10 2000
我同意由巫师提名优秀post，由联合国官员评定奖项。
大致意思是，巫师将所有读到的好文章转载到特定的board，由
jury member阅读，然后针对奖项投票。如果能由广大玩家投票
就最好，不过由于dummy的问题不容易解决，就改成由联合国官
员参与吧，他们应该能够代表广大玩家的意见，wiz应当也可
以投票。至于多久评一次，一周的话可能好文章不多，一月
的话可能时间间隔太长，二周如何？决出周奖后还可以进行
月奖的评选(两个月一次)，现在电视台不是经常搞这一套吗？
个人意见，请参考。


---
作者: 威少爷(suicide)
题目: i met the same thing as tking and zeda
日期: Mon Mar  6 08:52:08 2000
who -w
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/runtime
※ 三国志总站 ※  （当地时间：二千年三月六日上午八时四十七分）
─＝巫师列表＝─目前总人数：5人
─────────────────────────────────────
【晋阳关内侯】吴国晋阳议曹「至尊玉」威少爷，字呵呵(suicide)
【   白身   】琅琊隐居贤人「t」黄帝(emperor)
【  枫之王  】枫之国主公分钟(group) [发呆 2 分钟]
【襄平关内侯】枫之国卫将军「有色心没色胆」烈火，字嘿嘿(fire)
─────────────────────────────────────
>l
Can't use verb with no body.
when i reconected half a min later.
i am in /domains/std/void.c


---
作者: 威少爷(suicide)
题目: 补充
日期: Mon Mar  6 08:53:55 2000
我是因为突然象断线一样无法输入也无屏幕刷新的情况下,reconect 的.
但是同时我的其他网络联结正常.


---
作者: 斯坦福(stefan)
题目: web page development
日期: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
作者: 阿洛(row)
题目: about post
日期: Tue Mar  7 00:48:10 2000
我同意由巫师提名优秀post，由联合国官员评定奖项。
大致意思是，巫师将所有读到的好文章转载到特定的board，由
jury member阅读，然后针对奖项投票。如果能由广大玩家投票
就最好，不过由于dummy的问题不容易解决，就改成由联合国官
员参与吧，他们应该能够代表广大玩家的意见，wiz应当也可
以投票。至于多久评一次，一周的话可能好文章不多，一月
的话可能时间间隔太长，二周如何？决出周奖后还可以进行
月奖的评选(两个月一次)，现在电视台不是经常搞这一套吗？
个人意见，请参考。


---
作者: 斯坦福(stefan)
题目: web page development
日期: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
作者: 阿洛(row)
题目: about post
日期: Tue Mar  7 00:48:10 2000
我同意由巫师提名优秀post，由联合国官员评定奖项。
大致意思是，巫师将所有读到的好文章转载到特定的board，由
jury member阅读，然后针对奖项投票。如果能由广大玩家投票
就最好，不过由于dummy的问题不容易解决，就改成由联合国官
员参与吧，他们应该能够代表广大玩家的意见，wiz应当也可
以投票。至于多久评一次，一周的话可能好文章不多，一月
的话可能时间间隔太长，二周如何？决出周奖后还可以进行
月奖的评选(两个月一次)，现在电视台不是经常搞这一套吗？
个人意见，请参考。


---
作者: 威少爷(suicide)
题目: CVS will be supported in which OS?
日期: Mon Mar  6 10:26:33 2000
as title.


---
作者: 斯坦福(stefan)
题目: web page development
日期: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
作者: 烈火(fire)
题目: hp rob
日期: Mon Mar  6 06:06:52 2000
〓〓〓〓状〓〓〓〓态〓〓〓〓
⊙气血⊙   318 / 318 ( 318 )  
⊙精神⊙  -87287 /-198 (-198 )  
⊙食物⊙   114 / 200  
⊙饮水⊙   114 / 200  
〓〓〓〓〓〓〓〓〓〓三国志〓

flee, please check the formula for spirit


---
作者: 威少爷(suicide)
题目: 关于悬赏.
日期: Mon Mar  6 05:46:55 2000
为了让玩家也能加入到这个mud的创作中
建议设立一个悬赏公告版,由巫师来向玩家收集有关资料用.
玩家提供的资料被采纳后给予一定的奖励.
奖励在征集公布前就确定,保持透明度.
这样可以减轻巫师一些收集资料,创作asc image 的压力


---
作者: 分钟(group)
题目: firework
日期: Mon Mar  6 05:35:41 2000
firework done. /wiz/group/firework.c
add it in marriage ba


---
作者: Row
题目: >几点建议,大家多发言
日期: Sun Mar  5 22:50:46 2000
its a really good suggestion.


---
作者: 威少爷(suicide)
题目: kick fire
日期: Sun Mar  5 20:49:22 2000
reply具体点吗.


---
作者: Fire
题目: >几点建议,大家多发言
日期: Sun Mar  5 20:45:35 2000
aggree suicide, 


---
作者: 烈火(fire)
题目: 你口吐白沫，昏倒在地。
日期: Sun Mar  5 18:59:56 2000

who -n
※ 三国志总站 ※  （当地时间：二千年三月五日下午六时四十七分）
─＝按国家排序＝─目前总人数：27人
────────────────────────────────────
─
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
【   白身   】泾阳隐居贤人思汉云(zeda) [发呆 11 分钟]
────────────────────────────────────
─

思汉云走了过来。
思汉云朝西边离开了。
思汉云走了过来。
思汉云向你打听关于<job>的消息。
你对思汉云笑道：小兄弟想找点事干？这个卑职可做不了主，得去问本地村长。
faint
你口吐白沫，昏倒在地。
思汉云说道：hi.
say how could you login so many copy ?
你说道：how could you login so many copy ?
whoip zeda
目前有 9 位从 216.154.8.66 上线的玩家:
(login), zeda, zeda, (login), zeda, zeda, zeda, zeda, zeda.
> 思汉云说道：is a problem on net.
思汉云说道：sometime when i log in it didnt show chinese.
你说道：what problem ?
你说道：then ?
> 思汉云说道：some i have to keep try.
思汉云说道：it happen again.
你说道：can you order other copies of your self ?
思汉云说道：i m reading 乱吗
你说道：oh.
你说道：do you select gb ?
> 思汉云说道：so i can see what u writting.
你说道：do you select gb or big5 ?
snoop zeda
成功。
> %s%ay wait here ill try agian and we will see
%你说道：wait here ill try agian and we will see.
思汉云说道：wait here ill try agian and we will see.
你点了点头。
%烈火点了点头。
> snoop
成功。
> l
【系统】赵子龙进入三国志总站。
泾阳隐居贤人思汉云(zeda) [发呆 15 分钟]
泾阳隐居贤人思汉云(zeda)
思汉云离开了三国志总站。
【系统】思汉云离开了三国志总站。
思汉云一抱拳：要换班了。
【系统】思汉云进入三国志总站。
思汉云一抱拳：要换班了。
思汉云进入三国志总站。
l
军营 [出口：west, south]

    这里便是泾阳城驻军营地，一顶顶白色帐子排列得整整齐齐，帐
顶七彩的旌旗迎风飘扬，煞是壮观。营地内士兵们有的在空地处列队
操练，有的受命巡逻，有的忙着生火做饭，相比下来，这儿倒是泾阳
城最热闹的地方了。军营的西面有一间屋子，是将官们议事的地方。

三国榜文【共有219条留言】(board)
赵国泾阳牙将杨祚(yang zuo)
赵国偏将军陈青，字無□(chenqing)
赵国泾阳议曹石苞，字仲容(shi bao)
赵国泾阳议曹费观，字子梦(fei guan)

泾阳隐居贤人思汉云(zeda) [发呆 16 分钟]
泾阳隐居贤人思汉云(zeda)
你点点头，轻轻的「哦」了一声，似乎明白了什么，又好像没懂。
你说道：can you read chinese this time ?
> 思汉云离开了三国志总站。
【系统】思汉云离开了三国志总站。
思汉云一抱拳：要换班了。
【系统】思汉云进入三国志总站。
思汉云一抱拳：要换班了。
思汉云进入三国志总站。
l
军营 [出口：west, south]

    这里便是泾阳城驻军营地，一顶顶白色帐子排列得整整齐齐，帐
顶七彩的旌旗迎风飘扬，煞是壮观。营地内士兵们有的在空地处列队
操练，有的受命巡逻，有的忙着生火做饭，相比下来，这儿倒是泾阳
城最热闹的地方了。军营的西面有一间屋子，是将官们议事的地方。

三国榜文【共有219条留言】(board)
赵国泾阳牙将杨祚(yang zuo)
赵国偏将军陈青，字無□(chenqing)
赵国泾阳议曹石苞，字仲容(shi bao)
赵国泾阳议曹费观，字子梦(fei guan)

泾阳隐居贤人思汉云(zeda) [发呆 16 分钟]
泾阳隐居贤人思汉云(zeda)
> 思汉云说道：k.
say ok ?
你说道：ok ?
思汉云说道：what u think is prblem.
whoip zeda
目前有 9 位从 216.154.8.66 上线的玩家:
zeda, zeda, (login), zeda, zeda, zeda, (login), zeda, zeda.
你说道：dunno.
你说道：can you order all the zedas or just one zeda ?
思汉云说道：will i hop all but one.
你笑得气都喘不过来了，倒在地上直打滚。
你说道：ok, please logout and let me dest all the zeda.
你说道：then you login again after 5 mins ok ?
> 思汉云说道：what is prper way to log out.
你说道：quit.
> 思汉云说道：just close?
你点了点头。
> 思汉云离开了三国志总站。
【系统】思汉云离开了三国志总站。
思汉云一抱拳：要换班了。
你说道：then wait 5 min then login again.
> l
【系统】思汉云断线了。
【系统】思汉云离开了三国志总站。
思汉云断线了。
【系统】思汉云断线了。
思汉云离开了三国志总站。
【系统】思汉云离开了三国志总站。
思汉云一抱拳：要换班了。
【系统】思汉云断线了。
【系统】思汉云离开了三国志总站。
【系统】思汉云断线了。
【系统】思汉云离开了三国志总站。
【系统】思汉云断线了。
【系统】思汉云离开了三国志总站。
【系统】思汉云断线了。
【系统】思汉云离开了三国志总站。
whoip zeda
没有人从那个地址连线。
你口吐白沫，昏倒在地。
你说道：all leave at one moment.



---
作者: 玄冰(ice)
题目: 2 bugs setback after hacked
日期: Sat Mar  4 00:31:27 2000
1. yuzhang south gate is not accessable by player( cannot s from
   south street)
2. luling is a lv 1 area, but it's now lv 4!.:(
pls fix it


---
作者: 烈火(fire)
题目: marriage bug in mirror
日期: Fri Mar  3 23:00:21 2000
分站结婚部分的BUG主要是因为
分站的角色里没有li guan,si ye等NPC。
我调整了程序，不在需要他们是角色了。
分站应该可以正常结婚了。


---
作者: 阿洛(row)
题目: change chinese id
日期: Thu Mar 23 08:16:48 2000
如何修改一个id的中文名字，如果两个id重名的话？


---
作者: 烈火(fire)
题目: about rumor
日期: Thu Mar 23 06:50:45 2000
now wiz can view the sender's id as well as the name :)


---
作者: Row
题目: >train bug
日期: Thu Mar 23 06:34:30 2000
On Thu Mar 23 05:50:19 2000 烈火(fire) wrote post #1275:
> 同名的id进行训练会使兵力加倍，
> 偶尔一次还是次次如此，测试过没有？
> doubt

we can test...:)


---
作者: 烈火(fire)
题目: train bug
日期: Thu Mar 23 05:50:19 2000
同名的id进行训练会使兵力加倍，
偶尔一次还是次次如此，测试过没有？
doubt


---
作者: Suicide
题目: >npc
日期: Thu Mar 23 03:32:37 2000
agree row;


---
作者: 阿洛(row)
题目: npc
日期: Wed Mar 22 23:10:38 2000
嗯，我还是认为NPC流动的几率太大了些，而且letter的功能太强。
是否考虑忠诚95以上的NPC无下野几率，但每三国月所有NPC自动降1-2点
忠诚，letter成功可以大幅度降NPC忠诚，但只有对忠诚小于70的NPC
造成弃官。烈火以为如何？


---
作者: 玄冰(ice)
题目: ?
日期: Wed Mar 22 00:27:03 2000
【系统】噪音进入三国志总站。;【系统】嘿嘿进入三国志总站。
i used whoip and idfind, get only 1 body get in, so ...
what's wrong?


---
作者: 烈火(fire)
题目: about nanhua
日期: Tue Mar 21 21:56:22 2000
because for a new xianren, need update the data
in char_d, but char_d can't auto update because it 
includes so many player related data, so in each mirror
the wiz need to do the following things to update the
nanhua

call /daemons/char_d,add_char,nanhua laoxian
call /daemons/char_d,set_char,nanhua laoxian,name,南华老仙
call /daemons/char_d,set_char,nanhua laoxian,body,xianren/nanhua
call /daemons/char_d,set_char,nanhua laoxian,is_xianren,1
call /daemons/char_d,set_char,nanhua laoxian,is_tmp,1

addoil :)


---
作者: Fire
题目: >move new discard.c
日期: Tue Mar 21 21:48:24 2000
On Tue Mar 21 19:23:00 2000 威少爷(suicide) wrote post #1268:
> I have made a little mistake with "||" in if sentence.xixi
> It should be "&&".I have modified it in /wiz/suicide/discard.c.
> pls move it to /cmds/verbs.
> by the way can give me the write right of "/cmds/verbs"?
> So i can do it as soon as i finished it.

i will move the discrad.c and give you the write priviliage later :)
addoil suicide


---
作者: 威少爷(suicide)
题目: move new discard.c
日期: Tue Mar 21 19:23:00 2000
I have made a little mistake with "||" in if sentence.xixi
It should be "&&".I have modified it in /wiz/suicide/discard.c.
pls move it to /cmds/verbs.
by the way can give me the write right of "/cmds/verbs"?
So i can do it as soon as i finished it.


---
作者: Row
题目: >about the rumor
日期: Tue Mar 21 09:17:27 2000
On Tue Mar 21 05:04:04 2000 烈火(fire) wrote post #1266:
> now wiz can see who is sending rumors
> sigh

better add id after chinese name...
sweat fire


---
作者: 烈火(fire)
题目: about the rumor
日期: Tue Mar 21 05:04:04 2000
now wiz can see who is sending rumors
sigh


---
作者: 烈火(fire)
题目: about discard
日期: Tue Mar 21 04:41:45 2000
I have modified the new_d
so a king has right to remove his nation's post

so suicide just focus on the discard.c bah xixi


---
作者: 威少爷(suicide)
题目: about discard.c
日期: Tue Mar 21 04:19:40 2000
Can i add a new func called "force_remove_post" in news_d
for emperor using to discard the title posted by others?
Then it will affect nothing about any other code using func of news_d.


---
作者: Fire
题目: >about info
日期: Tue Mar 21 02:02:54 2000
On Tue Mar 21 00:57:11 2000 玄冰(ice) wrote post #1259:
> 【巫师】玄冰(ice)：info s;没有这种物资。;> info s all;没有这种物资。
> 【巫师】玄冰(ice)：so do info n...
> 【巫师】玄冰(ice)：so add a info x all?
> 【巫师】玄冰(ice)：or info xa ...
> just like the info n, info a b4, can show all the brief?
info s list
xixi


---
作者: 玄冰(ice)
题目: a typo.:(
日期: Tue Mar 21 01:08:00 2000
info j
the lv 10 need 2000000 repu, seems it was my typo.:(
how about change it to 1m rep?
* fool
i have forgotten the cmd to change it, fire tell me again?
* escape


---
作者: 玄冰(ice)
题目: runan warmap
日期: Tue Mar 21 01:01:33 2000
cmd warmap runan
is it that default warmap b4?
seems it's not updated.:P
sb just draw one bah
and if have time, pls check if there is some left is using default
warmap bah.:)
* addoil



---
作者: 玄冰(ice)
题目: about info
日期: Tue Mar 21 00:57:11 2000
【巫师】玄冰(ice)：info s;没有这种物资。;> info s all;没有这种物资。
【巫师】玄冰(ice)：so do info n...
【巫师】玄冰(ice)：so add a info x all?
【巫师】玄冰(ice)：or info xa ...
just like the info n, info a b4, can show all the brief?


---
作者: Row
题目: >a discovery
日期: Tue Mar 21 00:38:03 2000
On Tue Mar 21 00:36:31 2000 玄冰(ice) wrote post #1257:
> if I do xu zijiang's job, then I don't need to take any transportation
> tool to my destination anyway, bcoz the xian ren trans me to the
> destination at that time, so he is my horse? it takes no time from
> yunnan to bailangshan .:P
> * snicker

yeah, this trick may be found by players already, they just dont report
as they always did...hehe.


---
作者: 玄冰(ice)
题目: a discovery
日期: Tue Mar 21 00:36:31 2000
if I do xu zijiang's job, then I don't need to take any transportation
tool to my destination anyway, bcoz the xian ren trans me to the
destination at that time, so he is my horse? it takes no time from
yunnan to bailangshan .:P
* snicker


---
作者: Fire
题目: >info a
日期: Mon Mar 20 17:29:01 2000
On Mon Mar 20 07:08:46 2000 阿洛(row) wrote post #1255:
> the info aa got problem, may be caused by disable ev_merchant.
> pls check.

yes, it is, i will fix it asap :)
sorry for that


---
作者: 阿洛(row)
题目: info a
日期: Mon Mar 20 07:08:46 2000
the info aa got problem, may be caused by disable ev_merchant.
pls check.


---
作者: 威少爷(suicide)
题目: 加入南华老仙预测fate
日期: Mon Mar 20 03:27:33 2000
file have move to /sgdomian/modules/m_charnp/xianren/nanhua.c
pls check and open it.


---
作者: Fire
题目: >a bit triuble with discard
日期: Mon Mar 20 02:32:28 2000
On Sun Mar 19 23:40:53 2000 威少爷(suicide) wrote post #1251:
> Fire:
>     For in news_s it still has a limit to delete the others title 
> i can't finish the new discard.c unless rem some judgement code in the
news_d.
>    To modified the news_d i think it should get ur agree for maybe my doing 
> will bring some bug about news.
>    Do u have some idea to avoid this?
let me check your code first :)
addoil


---
作者: 斯坦福(stefan)
题目: discard
日期: Sun Mar 19 23:47:23 2000
maybe the right way is not to "discard" it, just "hide" it.
Still needs to modify news_d, but can avoid accedental mistakes.


---
作者: 威少爷(suicide)
题目: a bit triuble with discard
日期: Sun Mar 19 23:40:53 2000
Fire:
    For in news_s it still has a limit to delete the others title 
i can't finish the new discard.c unless rem some judgement code in the news_d.
   To modified the news_d i think it should get ur agree for maybe my doing 
will bring some bug about news.
   Do u have some idea to avoid this?


---
作者: Stefan
题目: >用聊天频道造成crash是字符串的长度不能超过大概512字节
日期: Sun Mar 19 10:20:07 2000
On Sun Mar 19 07:55:41 2000 黄帝(emperor) wrote post #1246:
> 用聊天频道造成crash是字符串的长度不能超过大概512字节
> 和行数好象无关

I fixed it the other day to make maxum input line to be 240 characters.
But seems fire found that "to" command also causes this
bug, better fix it some time later.

but anyway, "to" is only used by wizs, we just be cautious :)


---
作者: 斯坦福(stefan)
题目: player recovery
日期: Sun Mar 19 10:13:59 2000
We have backups since January. The backup works this way..
Every month there is a backup.
Every week there is a backup, the last week's backup
will replace that month's monthly backup.
Every day there is a backup, the last daily
backup becomes a weekly backup.

All together, only 7 daily backups from Sunday to Saturday.
For past months, only monthly backup exists;
for past weeks, only weekly backup exists.

So, I can get both rical and leeye's data back,
but may not be the most recent one.


---
作者: 黄帝(emperor)
题目: 用聊天频道造成crash是字符串的长度不能超过大概512字节
日期: Sun Mar 19 07:55:41 2000
用聊天频道造成crash是字符串的长度不能超过大概512字节
和行数好象无关


---
作者: 烈火(fire)
题目: a crash
日期: Sun Mar 19 05:37:47 2000


use to chat or to sgz can cause crash
so if we have to use to chat or to sgz
please make sure the input no more than 5 lines
if it is more than 5 lines, it's better seperate it
into several parts. hoho :)


---
作者: 威少爷(suicide)
题目: modify discard.c
日期: Sat Mar 18 21:32:12 2000
Today hei told me if the emperor can delete the useless title in
their own country.
So i modify the discard.c .
But i have no right to write /cmds/verbs to replace the old file.
Please help me remove /wiz/suicide/discard.c /cmds/verbs if can .


---
作者: Flee
题目: >>bug log
日期: Fri Mar 17 19:58:30 2000
On Fri Mar 17 06:30:16 2000 Fire wrote post #1242:
> On Fri Mar 17 06:28:58 2000 阿洛(row) wrote post #1241:
> > 如果在系统发饷计算粮食消耗的时候，把兵带出去训练，那么
> > 粮食就不减了。
> 
> this is a bug, maybe we can fix it in the future
> that troop will consume food and gold in train and war
that's right, troop will consume more food and gold in
train and war than in rest ... *hehe


---
作者: Fire
题目: >bug log
日期: Fri Mar 17 06:30:16 2000
On Fri Mar 17 06:28:58 2000 阿洛(row) wrote post #1241:
> 如果在系统发饷计算粮食消耗的时候，把兵带出去训练，那么
> 粮食就不减了。

this is a bug, maybe we can fix it in the future
that troop will consume food and gold in train and war


---
作者: 阿洛(row)
题目: bug log
日期: Fri Mar 17 06:28:58 2000
如果在系统发饷计算粮食消耗的时候，把兵带出去训练，那么
粮食就不减了。


---
作者: Group
题目: >the warmap bug
日期: Fri Mar 17 01:26:18 2000
On Thu Mar 16 08:02:48 2000 烈火(fire) wrote post #1239:
> group fixed it ?
> oh, great, addoil :)
yap..forgot to post..:P

group


---
作者: 烈火(fire)
题目: the warmap bug
日期: Thu Mar 16 08:02:48 2000
group fixed it ?
oh, great, addoil :)


---
作者: Fire
题目: >a small bug
日期: Thu Mar 16 02:27:19 2000
On Thu Mar 16 01:49:31 2000 阿洛(row) wrote post #1236:
> a bug of digsoil, when the field is ok, a player can turn mutong, and then
> he will have busy time, but if he try to dig the soil once more and get
> the msg that its no necessary to dig the soil anymore, he is able to
> dig the soil rightaway, seems its the bug of busy time.

yes it is :P
I will try to fix it
addoil


---
作者: 阿洛(row)
题目: the shutdown bug
日期: Thu Mar 16 01:59:49 2000
urgent!!! i think this should be solved the first, someone just wanna
destroy sanguo by keep on rebooting...sigh


---
作者: 阿洛(row)
题目: a small bug
日期: Thu Mar 16 01:49:31 2000
a bug of digsoil, when the field is ok, a player can turn mutong, and then
he will have busy time, but if he try to dig the soil once more and get
the msg that its no necessary to dig the soil anymore, he is able to
dig the soil rightaway, seems its the bug of busy time.


---
作者: 阿洛(row)
题目: to fire
日期: Wed Mar 15 23:59:33 2000
how to change a player's password, i mean as an admin.


---
作者: 烈火(fire)
题目: I know a way to crash the mud
日期: Wed Mar 15 18:23:54 2000
to chat a long article (100 lines or so)
especially there are about 50 ppl onlines
tset also got some way to crash our mud, I forget the
detail, seem find sth from the core dump



---
作者: 斯坦福(stefan)
题目: mudos
日期: Wed Mar 15 11:35:27 2000
the mudos used here is fairly unstable, I already fixed
quite a few, but since row has found more, there
could be many others :PP 

Simply by dropping objects in a room won't cause ES2
MudoS (an old version) to hang, Iremembered that
I tested in lima too, no such bug. but I am not sure :P

if a player post a too long article, it would usually cause a buffer
overflow, MudOS should discard the buffer to avoid overflow..
dunno why it will kill the mudos, this could be a really serious
bug.

Bombing ports, well, no way to protect MudOS against this,
simple cure maybe to restrict concurrent connection from
the same IP. It would not work if they guy is issuing millions
of open TCP connection from his own machine :P

anyway, current mudos is just too hard to fix, anybody got any idea
when new mudos is going to be released?


---
作者: 阿洛(row)
题目: hmm...
日期: Wed Mar 15 00:57:57 2000
today, i talked with a player in zj site, he is the guy who reported those
two reboot bugs. he said there r many potential OS bugs in sanguo, and gave
example that keep on logining new id will hang on the system too. in addition,
he said he found there is a guy used to attack sanguo by bombing the port,
so i am worried about the security of the system.

stefan has any better solutions?


---
作者: 烈火(fire)
题目: admire row
日期: Tue Mar 14 23:47:28 2000
i will check these bugs


---
作者: 阿洛(row)
题目: a bug which can add soldier after reboot
日期: Tue Mar 14 23:41:50 2000
use two ids with same chinese name, then announce a war. put 1 id
as general and assign certain number of troops, then cause shutdown,
when system is restarted, that 2 ids can both take the same number of
troops back to the city.


---
作者: 阿洛(row)
题目: the bugs cause shutdown
日期: Tue Mar 14 23:37:18 2000
1, if a player intends to post a very long article, the system
cannot handle and will shutdown immediately.
2, in the kitchen of huayin, if a player keep on ask chu niang
about food and drop the food, soon that room will get too many objects
and also cause the system to shutdown.


---
作者: 威少爷(suicide)
题目: 补充
日期: Tue Mar 14 23:05:30 2000
我不是说catch有问题,该抓而且应该抓.
我的意思是是否可以修改catch的效果,稍微降低一下.


---
作者: Row
题目: >修改建议
日期: Tue Mar 14 22:57:07 2000
我认为catch本身没有什么问题，而catch到本国做破坏工作的
玩家也基本属于正常情况。一个mud 游戏里不能是一团和气，
因为那样就失去了竞争的意义，当然我们要防止的是出现过激
的局面，比如骂脏话，使用非法手段搞破坏等等。


---
作者: 威少爷(suicide)
题目: 修改建议
日期: Tue Mar 14 22:52:54 2000
由于最近出现不好因为玩家被catch而不愉快的事件发生.
是否可以考虑减少被抓的损失和抓获的奖励.
或者增加catch的难度,例如先fight或者有亲兵才行.


---
作者: 阿洛(row)
题目: 盗用帐号
日期: Tue Mar 14 20:52:55 2000
zj站又出现了盗用帐号的事：有人盗用其他国君帐号裁兵及开除玩家。
我想用find指令查询某id的login状况，但是：
*(s)printf(): BUFF_SIZE overflowed... (arg: 1);

please advise.


---
作者: 阿洛(row)
题目: 光荣出品的《三国志七》
日期: Tue Mar 14 20:50:02 2000
新浪网游民部落上有《三国志七》的全功略，可以参考其中的
物品，计某设置，不可不看。
http://games.sina.com.cn/handbook/0003/03091514.shtml

游民部落地址：
http://games.sina.com.cn/


---
作者: 玄冰(ice)
题目: add a busy time for add and rm blacklist
日期: Tue Mar 14 10:57:47 2000
it floods in rumor all the time, everyone can check it out
any time.
* slogan


---
作者: 阿洛(row)
题目: hmm...serious bug
日期: Tue Mar 14 08:42:57 2000
in zj, when its night, the system will reboot by no reason.
some players report there is someone intended to shutdown it
by certain bug to gain some benefits, for instance, when
the sanguo restarts, han di will call a player immediately.
is there a way to track the inproper shutdown and check the cause?
please advise.


---
作者: 分钟(group)
题目: faint
日期: Tue Mar 14 01:20:11 2000
forgot to take the disk...tomorrow i will upload in...

escape...



---
作者: 烈火(fire)
题目: improvement of fight
日期: Mon Mar 13 07:18:55 2000
1 for a room if set("no_fight",1) then it is a no fighting room
  if set("no_fight",<msg>) when a player try to fight will show
  him the msg, which usually means the reason why can't fight here
2 if fight a player, need both side fight the other then can fight
3 if two ppl fighting and move to a no fight room the fight will
  auto stop


---
作者: 阿洛(row)
题目: to fire
日期: Mon Mar 13 01:13:08 2000
i rmed put.c in zj site, but when the site is rebooted, put.c returns and
is loaded by system, which means its useless by only removing.
what else can i do?


---
作者: 阿洛(row)
题目: bug log
日期: Sun Mar 12 23:54:01 2000
寄信人 ：tking
日期   ：Mon Mar 13 12:59:26 2000
题目：有关两个人同时用一个ID的BUG 
---------------------------------------
刚才我用yesl来下bl,状态是在POS中，结果这时yesl自己也连了
然后他也可以下bl
而我这里却没有quit,可以继续操作.
我没有做重复测试，不知道这是个偶然现象，还是BUG



---
作者: 阿洛(row)
题目: bug of xuzijiang
日期: Sun Mar 12 22:02:14 2000
i changed the file of /sgdomain/job/xuzijiang/xianren.c, hope it will
fix the bug.


---
作者: 烈火(fire)
题目: a little suggestion for row
日期: Sun Mar 12 19:41:29 2000
comfort row,
In a Mud, I think the most difficult thing is to deal problems with players :(
Because they are so different, sometime is pretty hard to be
justify. So in this
special situation. I may suggest you don't cut a players' skill until 3 chars 
from different ips and different countries prove that he has used
bug to increase
his skill and also give the number how many levels he has got from the bug.
When you got this proof, you cut down his skill. So either side got
complains, 
it is not your mistake :). 
This is only my personal suggestion, you may find some better solutions. 
addoil row
sweat row


---
作者: Suicide
题目: >> 疑问. 
日期: Sun Mar 12 19:24:44 2000
When the player's data gets saved periodically, the online time
can be saved together. If crash, all data should revert
to the last saved data. 

So now we should discuss how to saved the online time periodically.

It still need a period call to update all ppl's online time.
What should we use and how to do it?
Let's discuss Bah...


---
作者: 阿洛(row)
题目: whats wrong
日期: Sun Mar 12 11:13:03 2000
霎时地动山摇，天翻地覆，整个世界毁于一旦！

zj site shutdown several times in a few minutes without any
reasons, whats wrong???


---
作者: 阿洛(row)
题目: bug...
日期: Sun Mar 12 11:09:02 2000
i am really depressed now...players just intend to use bug to 
get benefit instead of reporting...i posted in zj site for the
purpose that i want them to report how much they got from the bug
but, seems its useless...no one is really consider from the game
developing aspect, they just want their own good....

that makes me angry.  pls advise where and how can i track those
bug user, and i will CUT or PURGE!
i am not a harsh person but they really disappointed me.


---
作者: 阿洛(row)
题目: bug log
日期: Sun Mar 12 10:54:59 2000
another bug same as cmd leave. in pos, king dismisses a player, then
the player ask about position again, the nationcontribution will
not decrease.


---
作者: 斯坦福(stefan)
题目: > 疑问. 
日期: Sun Mar 12 01:30:56 2000
The adversary object is only in recent Lima Lib, but not here..

Also age computation does not need "log" files :) If you take a look
at old ES2 files, each player's .o data has a field indicates how long
the player has spent in the mud. So this data
is actually with each player, not in the log file. Also 
the computation could be "smarter" to avoid crash problem...
for example:

When the player's data gets saved periodically, the online time
can be saved together. If crash, all data should revert
to the last saved data. 

I would agree with fire, because some other things are also done in the
age_beat()
besides the age calculation, need to take care of those things as well.


---
作者: Flee
题目: >>suggestion
日期: Sun Mar 12 00:05:16 2000
On Sat Mar 11 15:09:23 2000 Ice wrote post #1201:
> since row talked about fight, can we think of give back the weapons
> to the NPC's? 
> just for not easy to fight with lv bu sth.:P
> 
> btw, if use set_no_fight(1), and if I am following row to fight with
> him, when he move in no_fight room, will the fight stop?
env->set("no_fight", 1)
then players can not start fight in the room .. 
but i am not sure about the case ice metioned .. 
*fool


---
作者: 烈火(fire)
题目: the bug about leave and rejoin and get reward
日期: Sat Mar 11 23:18:22 2000
is due to when i edit ev_leave.c, I was using a old
copy. Now i change it back, sorry for this bug


---
作者: 烈火(fire)
题目: about age_beat
日期: Sat Mar 11 23:01:49 2000
1 now it is using call_out for each ppl, this may use more
  memory resource than necessary.
2 use heart_beat, because heart_beat calls every 2 second,
  but our age_beat takes about 240 second. so heart_beat 
  may use more cpu power.
3 use calculation on call method. just like the hp system, 
  system will calculate the hp, mp, food and drink when it 
  is called. This method is very skillful. However our age_beat
  also triggles some other actions such as the use's home events.
  Therefore to use this way may miss some trigger if no other
  request ask for the system to calculate players age. 
4 Triggered by other periodical daemons like day_d. By using this
  method, each period system needs do the following things:
  a get a list of all online players
  b run the age_beat method on each player by using for loop
  This method may cause a peak cpu useage in a short time every
  perodical time. And all the events triggered by the age_beat
  may happen at the same time. So it still hard to say this is
  the best method.
Compared the 4 different method, my personal feeling is method
3 is the best. But we need to find a good and realiable trigger
for the calculation.
  
  


---
作者: Fire
题目: >a doubt
日期: Sat Mar 11 22:32:44 2000
On Sat Mar 11 15:27:41 2000 玄冰(ice) wrote post #1202:
> can □总军师：飘雪 act as king?
> 【谣言】某人：飘雪封飘雪为祁山的主将。
> ...
> * fool

he is a 州牧


---
作者: 威少爷(suicide)
题目: 分站今天出现leave bug.
日期: Sat Mar 11 22:07:56 2000
玩家利用cmd leave then reposition.
all nationcontribution remains and can get reward for 君主 time and time.
All player in zj site r using this bug to get reward and reward now.
Fire maybe we should recover the data of zj site of yesterday.
Have we?


---
作者: 威少爷(suicide)
题目: 疑问.
日期: Sat Mar 11 21:48:03 2000
我们的mud中的ppl平时都没有心跳吗?
是不是只在fight时才有心跳.?
另外据我所知lima bean中在adversary这一类才引入heart_beat的
并不是所有的物件都继承heart_beat().
我觉得用log计算age虽然可以,但是实现起来并不容易.
第一:意外down机.
第二:log文件不能删除,必须保留,而且会越来越大.
第三:log文件没有排序,非常乱,要计算一个玩家age就需要扫描整个log文件.
    耗时也不小.
以上是我的一些想法,也许错误,敬请指正.


---
作者: Suicide
题目: >>>关于age_beat()
日期: Sat Mar 11 21:39:42 2000
we can just turn on the heart_beat of ppl.
我知道在lima bean中是在adversary类中才有heart_beat的
并不是所有的obj都有心跳,况且我们可以只打开玩家的心跳.


---
作者: 玄冰(ice)
题目: a doubt
日期: Sat Mar 11 15:27:41 2000
can □总军师：飘雪 act as king?
【谣言】某人：飘雪封飘雪为祁山的主将。
...
* fool


---
作者: Ice
题目: >suggestion
日期: Sat Mar 11 15:09:23 2000
since row talked about fight, can we think of give back the weapons
to the NPC's? 
just for not easy to fight with lv bu sth.:P

btw, if use set_no_fight(1), and if I am following row to fight with
him, when he move in no_fight room, will the fight stop?


---
作者: 阿洛(row)
题目: suggestion
日期: Sat Mar 11 12:21:19 2000
we used to have a set_no_fight(1), dunno if i get it right
i suggest to set all meeting room cannot fight, coz player will
flood there to interrupt others. and fly_room, etc


---
作者: Stefan
题目: >>关于age_beat()
日期: Sat Mar 11 00:29:46 2000
On Fri Mar 10 03:51:15 2000 Fire wrote post #1198:
> On Fri Mar 10 03:05:15 2000 威少爷(suicide) wrote post #1197:
> > 今天我测试fate_d.c时无意发现系统竟然每个ppl都有一个age_beat的call
> > 这好像是不是会影响系统性能?
> > 我在我自己的lima bean实现age的增长时好像避开了这点.
> > 利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
> > 利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
> > 有兴趣
> > 的话讨论讨论.
> 
> that is a good point, we may change the design style later
> hoho

I am not sure what is done within age_beat, but the best
way to increase age is to calculate it whenever the age number
is needed.

for example, if "score" shows age, age should only be
calculated when the "score" command is typed by the player.
If in some program, the age of a player has to be obtained, 
it can also be calculated by calling compute age function.
The age itself can be computed from the sum of a player's 
online time. Online time can be obtained by recording
linkdead/logoff/login time. Unless there are other things
that must be done with a call_out in age_beat, otherwise, to
compute age itself does not need call_out.

Most things that seem to require periodical call_out can
also be avoided in similar ways.

The worst case is heart_beat() function, it is called every
second for every interactive object, that surely wastes quite
a lot of CPU. That is why Lima eliminate heart_beat() in the
first place.


---
作者: Fire
题目: >关于age_beat()
日期: Fri Mar 10 03:51:15 2000
On Fri Mar 10 03:05:15 2000 威少爷(suicide) wrote post #1197:
> 今天我测试fate_d.c时无意发现系统竟然每个ppl都有一个age_beat的call
> 这好像是不是会影响系统性能?
> 我在我自己的lima bean实现age的增长时好像避开了这点.
> 利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
> 利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
> 有兴趣
> 的话讨论讨论.

that is a good point, we may change the design style later
hoho


---
作者: 威少爷(suicide)
题目: 关于age_beat()
日期: Fri Mar 10 03:05:15 2000
今天我测试fate_d.c时无意发现系统竟然每个ppl都有一个age_beat的call
这好像是不是会影响系统性能?
我在我自己的lima bean实现age的增长时好像避开了这点.
利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
利用系统会自动定时调用的heart_beat函数来实现, 这样就避免了上述的情况.
有兴趣
的话讨论讨论.


---
作者: Row
题目: >suggestion about info a
日期: Fri Mar 10 02:18:42 2000
agree...i'll do the modification.


---
作者: 烈火(fire)
题目: suggestion about info a
日期: Fri Mar 10 02:17:26 2000
Now the info aX is good, the only problem is not easy to remember them
and will hard to read the help info page (that help include too much
informations). So I suggest:

1 add a info aa to display all the information like the old info a.

2 info a will display the useage of all the info aX.

3 add info aX here to display current area's information. 

PS X could be one of m, g, f, a . . .


---
作者: 烈火(fire)
题目: %^H_RED%^A very stange bug
日期: Thu Mar  9 18:18:58 2000
today, when I login and find the system just reboot and then it
crash. So I relogin and it crash again, I try to restart the server
It still the same. After some observation, I find the crash is 
caused when 疏忽(wji) login. Please check the log.Usually when
the system reboot, it can last about 1 min and when wji login
it will crash immediately. So I suspect wji's data got some problem.
I goto the server and copy all the wji.o to wji.o.back and then
plan to purge him when login, then miracle happens, the system not
crash anymore. faint. Is it because I have copy some of his data file
solved the strange crashes or sth else. Anyone has any ideas
PS: the log about the crash
【系统】疏忽进入三国志总站。
霎时地动山摇，天翻地覆，整个世界毁于一旦！
【系统】疏忽进入三国志总站。
霎时地动山摇，天翻地覆，整个世界毁于一旦！
> 【系统】疏忽进入三国志总站。
【系统】勇敢进入三国志总站。
霎时地动山摇，天翻地覆，整个世界毁于一旦！
【系统】疏忽进入三国志总站。
※ 三国志总站 ※  （当地时间：二千年三月九日下午五时三十七分）
─＝ID列表＝─  目前总人数：8人
─────────────────────────────────────
烈火(fire)   疏忽(wji)    爪蛙(java)
> 霎时地动山摇，天翻地覆，整个世界毁于一旦！
【系统】疏忽进入三国志总站。
霎时地动山摇，天翻地覆，整个世界毁于一旦！
> 【系统】疏忽进入三国志总站。
霎时地动山摇，天翻地覆，整个世界毁于一旦！



---
作者: 烈火(fire)
题目: Hi suicide
日期: Wed Mar  8 22:13:01 2000
你的POST我全认真看了，你的建议并非没有道理。有些实际上还是
很有吸引力的。我只是在考虑到某些设计可能引起的弊端所以才反对
的。但是一个设计的好与坏要在最后实践中检验才有说服力。比如我
原来设计的gini，我认为很有意思同时也下了很大代价去CODE，但结
果很不理想，虽然调整多次最后还是取消了。所以关于POST的这个部
份，你还是去作。可能虽然有漏洞，但未必是不可以修补的，同时也有
可能你的设想是正确的。而我的忧虑完全是多余。
另外关于我们这里的工作方式，虽然大家都是平等自由的。但我们还是
要有一个中心的管理和组织才可以让这个系统正常的运转。现在这里的
核心是wiz committee，重要的决定要在那里进行。关于WIZ的具体工作
安排。主要是我在设计tasklist，其它的WIZ对它进行补充和讨论。并不是
哪一个WIZ，有了一个点子，就可以立即让另一个WIZ去作的。个种设计和
点子我们都欢迎，但由于许多原因，不可能马上就去作。特别是那些涉
及到许多其它系统的设计，在采纳点子时更要谨慎。关于城市升级，土匪
和帝国设计。实际这些在技术上都不困难。一条指令就可以让一个国家
成为帝国或者让一个地区升级。而土匪，只要把一条语句的comment去掉，
马上就可以活跃起来。但因为在设计的平衡上，有些问题还没有完全理顺，
或者相关的设计还没有完成，所以这些好的东西不得不退迟一下。因为你
来这里没多久，许多东西还不熟悉，产生误会也不怪你。
实际上，我很欣赏你积极的工作态度和快捷的工作速度。但在一个集团里
我们还要注意整体的配合。你的一个问题可能是觉得目前没有什么编程
工作好干。其实这是一个误会，单是你的FATE系统就远没有完成，下面我
列出一些可以改进的地方。
1  一个季节的灾难，不应该同时一瞬间突然出现。
2 灾难的描述过于简单，应该有预兆(可以是多次)，几次中间过程，结束。
3 灾难要有具体的内容，比如说火灾，玩家应该可以看到火在具体的房间里。
  也可以用一些方式来进行灭火。FLEE作过一个这样的JOB，你可以去参考一下
4 有些灾难如地震，洪水和蝗虫。不应该只在一个城市。相邻城市也要受到波及。

5 可以在做一个仙人管络，玩家可以向他来问本年的吉凶。也可以问一下破解之法。

   破解之法包括：破财，烧香进恭，裁剪士兵等等。具体还可以更多，有些需要等

   庙宇完成，但有些也可以现在就做。
上面只是一些我的随便建议，具体怎么做还可以有更多的内容。总之，作东西不能

只求速度。质量更重要。我很欣赏ROW，他在细节刻划上一直是一丝不苟。同时
emperor的CODE质量也非常高。相比之下我的CODE就粗糙一些，所以经常要
修修补补。我前面的一些POST的语气也不太好，在此我也表示道歉。总之我们
在一起合作，其最终目的都是一致的，就是创作出最好的游戏。愿我们的梦想
早日成真。


---
作者: 烈火(fire)
题目: about post
日期: Wed Mar  8 18:40:23 2000
关于SUICIDE的POST的设计，有些细节我的意见是反对的。理由
已经说过了。但是我的意见不一定是正确的。一些涉及整个系统
的设计，意见上有分歧的时候，是需要由委员会来讨论决定的。
但象POST这样一个和其它系统关系不是特别密切的设计，开发的
WIZ有一定的创作自由。所以SUICIDE可以去尝试，如果最后的结
果比较理想，那就这样作。


---
作者: 玄冰(ice)
题目: to suicide
日期: Wed Mar  8 10:08:23 2000
I can suggest and suggest, u need code and code, so should we make
a team?.:P
however, our plan will be discussed.:P
well, I am going to make some plan in mind for long for u to code,
I have no idea of coding.:(
so, i'll just provide without being afraid that no one will be free
to code it.:)
* sing
* massage suicide


---
作者: 威少爷(suicide)
题目: To row 
日期: Wed Mar  8 08:26:00 2000
你说的城市升级系统的帖子我都看了.
你说的城市升级系统的帖子我都看了.
要定一个合理的公式太难了，还需大家探讨细化才能动手．
我再考虑考虑．
谢谢你的建议．:)
admire row.


---
作者: 威少爷(suicide)
题目: :)
日期: Wed Mar  8 07:40:19 2000
This afternoon row ask me about that hwo about bandit.
So i think if i can add the old bandit event into fate system.
if it is not a good idea i give up.
:)
i am just free. i need code and code.


---
作者: Ice
题目: >>关于bandit
日期: Wed Mar  8 05:04:23 2000
On Wed Mar  8 04:35:33 2000 Fire wrote post #1186:
> On Wed Mar  8 01:43:11 2000 威少爷(suicide) wrote post #1185:
> > fire:
> >   　我看程序发现以前系统就有自动的bandit袭击，只是后来被封了．
> > 请问我可不可以把他加入fate系统，在fate系统中调用以取代以前在
> > ai_d中的调用？
> 
> fate系统目前只是一个框架。内涵基本上还没有。
> bandit涉及到战争。而战争目前已经够复杂了。等多兵种完成后要做
> 大幅度调整。(核心部分要从写)。所以bandit目前就先不要动了。

faint, suicide, so if u want, let's discuss but not execute it bah.
* fool


---
作者: Ice
题目: >关于bandit
日期: Wed Mar  8 05:03:23 2000
bandit had bugs b4, it's better recheck it b4 implement it
and i had a plan about bandit, so pls read it in fate.com bah
if u r not clear enough, post ur doubts.:)
I'll be pleasure to discuss it any time.:P


---
作者: Fire
题目: >关于bandit
日期: Wed Mar  8 04:35:33 2000
On Wed Mar  8 01:43:11 2000 威少爷(suicide) wrote post #1185:
> fire:
>   　我看程序发现以前系统就有自动的bandit袭击，只是后来被封了．
> 请问我可不可以把他加入fate系统，在fate系统中调用以取代以前在
> ai_d中的调用？

fate系统目前只是一个框架。内涵基本上还没有。
bandit涉及到战争。而战争目前已经够复杂了。等多兵种完成后要做
大幅度调整。(核心部分要从写)。所以bandit目前就先不要动了。


---
作者: 威少爷(suicide)
题目: 关于bandit
日期: Wed Mar  8 01:43:11 2000
fire:
  　我看程序发现以前系统就有自动的bandit袭击，只是后来被封了．
请问我可不可以把他加入fate系统，在fate系统中调用以取代以前在
ai_d中的调用？


---
作者: Fire
题目: >bug report from zj
日期: Wed Mar  8 00:12:33 2000
On Tue Mar  7 23:56:59 2000 阿洛(row) wrote post #1182:
> 有玩家说可以利用手御的bug在书房将计谋一下学到很高级。
> 估计是put的问题，但不排除其他bug，请明查。
I will disable put
hehe


---
作者: Fire
题目: >to fire
日期: Wed Mar  8 00:12:17 2000
On Tue Mar  7 23:46:39 2000 阿洛(row) wrote post #1181:
> 由于NPC不断下野，造成其声望损失，而他们又不会做工作
> 加声望，导致由于声望不够而当不了官，请fire考虑下野并不
> 影响NPC的声望，并弥补已经造成的损失。
NPC的声望是会自动长的。
不用操心：)


---
作者: 阿洛(row)
题目: bug report from zj
日期: Tue Mar  7 23:56:59 2000
有玩家说可以利用手御的bug在书房将计谋一下学到很高级。
估计是put的问题，但不排除其他bug，请明查。


---
作者: 阿洛(row)
题目: to fire
日期: Tue Mar  7 23:46:39 2000
由于NPC不断下野，造成其声望损失，而他们又不会做工作
加声望，导致由于声望不够而当不了官，请fire考虑下野并不
影响NPC的声望，并弥补已经造成的损失。


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: 威少爷(suicide)
题目: close war time of zj site.
日期: Thu Mar 23 19:31:07 2000
Row:
  Have u promised ppl in zj site that u will close the war time?
This morning a ppl coming from zj site told me about it.
:)


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: 威少爷(suicide)
题目: apply for mirrow
日期: Sat Apr  1 07:36:22 2000
A guy coming from tsinghua ask me about their apply for mirroe.
he tell me that stefan promise that he will reply him before april.
He is eager to know the result.
Stefan if u have time Can u mail him?


---
作者: 斯坦福(stefan)
题目: imud problem
日期: Fri Mar 31 23:07:28 2000
it is because the router is down. We are using the 
international router, have to find out why...


---
作者: 烈火(fire)
题目: it seems our intermud stuff got bugs
日期: Thu Mar 30 23:40:17 2000
news

news
who -w



---
作者: 威少爷(suicide)
题目: addoil all
日期: Thu Mar 30 03:49:08 2000
最近上线很少碰到大家,好像都很忙吗.
在此对大家到一声工作学习顺利


---
作者: Ice
题目: >where is the modules about fight?
日期: Wed Mar 29 21:02:34 2000
is it in daemons/fight_d/ and fight_d.c?
* addoil suicide


---
作者: 烈火(fire)
题目: busy
日期: Wed Mar 29 06:50:44 2000
these days our company is pretty busy,
the market stuff need delay several days
sorry, addoil all :)


---
作者: 威少爷(suicide)
题目: where is the modules about fight?
日期: Tue Mar 28 19:13:28 2000
for my lima bean version is a little different from here.
So i can't find it quickly.pls help me.


---
作者: Suicide
题目: >>about anti-robot
日期: Tue Mar 28 19:12:35 2000
can we add anti-robot question before job instead of finishing job.
then the ppl still nedd finish only one question according to finishing
one job.


---
作者: Ice
题目: >about anti-robot
日期: Tue Mar 28 06:04:45 2000
I think it's a not bad idea, however, if the player's net is lag, he
will have to suffer
from each time he cannot get the job bcoz they dun have enough time
to answer the
anti-robot questions.


---
作者: 威少爷(suicide)
题目: about anti-robot
日期: Mon Mar 27 20:32:48 2000
BSW: we can also add question before recruit and other important job for 
   ppl.
xixi .


---
作者: 威少爷(suicide)
题目: about anti-robot
日期: Mon Mar 27 20:29:07 2000
In caolu runner say that if we could add a anti-robot question 
before whisper or letter.I think it is a good idea.
What do u sthink so?


---
作者: Suicide
题目: >about my absence
日期: Sun Mar 26 22:40:37 2000
poor fire
addoil fire


---
作者: 烈火(fire)
题目: about my absence
日期: Sun Mar 26 21:00:52 2000
Because my University's network got some problem. So
I could't login last weekends. Sorry for my absence,
I have to find another free ISP :(


---
作者: Ice
题目: >about buy
日期: Sun Mar 26 01:18:58 2000
I tried to make maker use bank account to complete the deal, but..
my programming skill is too weak to ...
so just change it, it's simple for u guys.:P
* esacpe


---
作者: 桃桃(flee)
题目: about buy
日期: Sun Mar 26 00:01:39 2000
today noise want to a hxbma, but he is too weak to
carry 3k gold .. so i just dest 3k gold from him and
add a hxbma for him.
can we withdraw money from bank account directly, 
instead of carrying so many gold .. 


---
作者: 黄帝(emperor)
题目: to stefan
日期: Sat Mar 25 19:19:15 2000
现在网上有非常多的free email，玩家可以用free email来
得到注册密码，我就注册了上百个free email，所以谁向
我要email address，我随便给个就行。根本不用担心
会引来什么麻烦，如果这个email被轰炸，我换个email就行
了。


---
作者: 斯坦福(stefan)
题目: email registration
日期: Sat Mar 25 10:53:20 2000
I think a better way is to force email registration after a 
player settle. This way will be better for fresh newbies.

For myself, I am always scared when asked for email address :)

Should we post a privacy statement?? 


---
作者: 黄帝(emperor)
题目: 更完善的注册密码系统
日期: Sat Mar 25 06:02:26 2000
1.老玩家连接三国时，需要注册email，然后利用该email得到
新的密码才能进入游戏；
2.新玩家在注册ID时将需要注册真实的email来得到新的密码
才能进入三国；
3.当玩家密码丢失，或被hack后，在线WIZ可以利用smtp命令
给该玩家发送新的密码邮件。如果该玩家的旧注册信箱不能
使用时，经过WIZ确认，可以给该玩家新的注册信箱发送
密码邮件。
4.smtp命令用法：
假设玩家：黄帝(emperor)
当其次原有注册信箱sufeng@990.net还可以使用时
在线WIZ可以使用：smtp emperor来给其发送密码邮件；
当原来注册信箱sufeng@990.net不能使用时，可向黄帝
要新的信箱，如：sufeng@ynmail.com，则在线WIZ
可以使用命令：smtp emperor sufeng@ynmail.com
来给黄帝发送新的注册密码邮件；
5.以上功能均已实现，如果我在线，大家可到我的
单机MUD里测试。
;看看还需要什么补充吗？


---
作者: Ice
题目: >关于注册密码
日期: Sat Mar 25 02:50:14 2000
so nice
* great emperor


---
作者: 黄帝(emperor)
题目: 关于注册密码
日期: Sat Mar 25 01:34:54 2000
我在自己的机器上成功的测试了玩家必须通过真实电子信箱注册
来得到ID的密码程序。玩家要进入程序必须使用发送给他的密码
来得到ID的密码程序。玩家要进入三国必须使用发送给他的密码
而且以后玩家丢失了密码后，可以向在线WIZ申请，在线WIZ可以
通过使用一个命令后，三国可以自动再发一封新密码的信件
给他原来的注册信箱，这样可以有效地解决玩家丢失密码的
问题。
你们认为这可以吗？


---
作者: 分钟(group)
题目: bug
日期: Fri Mar 24 09:28:00 2000
【   白身   】隐居贤人分钟(groupone)
【   白身   】隐居贤人分钟(groupone)
if create together, you can have 2 totally same id in the mud 
this is maybe the reason for the train bug
fire please check


---
作者: 玄冰(ice)
题目: ...
日期: Fri Mar 24 09:17:28 2000
read leeye's post 509...


---
作者: 玄冰(ice)
题目: suggest to add a cmd of set_notell for player
日期: Fri Mar 24 09:15:43 2000
for avoiding player disturb another to earn benefits, I think add
the cmd of set_notell
for player to handle it themself will be fine.

here is the log of discussion by some player...
【吴国】建基：哦，带颜色的告诉他就行了
【吴国】建基脸上露出邪恶的笑容，不知道哪里想歪了。
【吴国】星石：破坏他们的trigger
【吴国】建基：给他加上颜色检验，grin

...


---
作者: 黄帝(emperor)
题目: 改中文名
日期: Fri Mar 24 09:01:07 2000
用@ USER_D->set_variable("emperor","chinese_id","凰帝")
可以修改玩家的中文名，不过我没试过。
xixi:)


---
作者: 玄冰(ice)
题目: an old old problem
日期: Fri Mar 24 05:16:56 2000
duplicated chinese name and dummy problems were old problems,
for some reasons, we didn't fix it at that time, but for now, seems
it's becoming barriers for our growth, think a way to deal with it?

dummies and robots r problems of all mud...:(
duplicated chinese name is hard to fix bcoz there r many duplicated
names already existing...

think about it

* addoil


---
作者: Fire
题目: >change chinese id
日期: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 阿洛(row) wrote post #1278:
> 如何修改一个id的中文名字，如果两个id重名的话？
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
作者: Stefan
题目: >apply for mirrow
日期: Sat Apr  1 21:49:17 2000
On Sat Apr  1 07:36:22 2000 威少爷(suicide) wrote post #1305:
> A guy coming from tsinghua ask me about their apply for mirroe.
> he tell me that stefan promise that he will reply him before april.
> He is eager to know the result.
> Stefan if u have time Can u mail him?

there are four applications from tsinghua, I am always confused :P
I will settle it, but all of them are not officially permitted, 
hard to decide which one to choose.


---
作者: Suicide
题目: >about block_tell
日期: Sat Apr  1 21:12:17 2000
fire have add a function to block tell lah...
.id->set_notell(xxx)
All thing we have to do is add the function to a verb file.
But i don't know if fire want to open this.
So i will not do this by myself.
:)


---
作者: 玄冰(ice)
题目: about block_tell
日期: Sat Apr  1 08:53:03 2000
I think set the block tell as a player function is necessary, today
I found a post in
shanghai mirror, a player flood another player with tell for 1 hr.:P
so fire pls make it possible for player to block tell


---
作者: Fire
题目: >bug log
日期: Mon Apr  3 23:46:52 2000
On Mon Apr  3 22:49:56 2000 阿洛(row) wrote post #1313:
> if a player ask xxx idler/guy/resident about getppl when he doesnt got
> a getppl job, the ppl will be set busy and wont leave as long as that
> player stay in the same room, nobody can ask that ppl about visit or fan.
> until someone come and recruit them.
i will check it
hoho :)


---
作者: 阿洛(row)
题目: bug log
日期: Mon Apr  3 22:49:56 2000
if a player ask xxx idler/guy/resident about getppl when he doesnt got
a getppl job, the ppl will be set busy and wont leave as long as that
player stay in the same room, nobody can ask that ppl about visit or fan.
until someone come and recruit them.


---
作者: Suicide
题目: >>apply for mirrow
日期: Mon Apr  3 20:15:18 2000
sweat stefan
addoil stefan.


---
作者: 玄冰(ice)
题目: about yuyin's suggestion
日期: Sun Apr  2 15:57:35 2000
I think maybe we can add a position in our mud like "immortal"?
then the wizs and admins in mirror can login for the discussion
and meeting time to time.

here is the desc of immortal in a mud webpage:
immortal)---他们是介于玩家和巫师之间的等级，一般为观察员，帮忙找;些bug。

I think it can be assigned in this way:
every wizs and admins in mirror will have a id as immortal automatically
in main, the id and passwd will be mailed to their own mudmail account
or email account;
the rights they can have r: auto having the announce,wiz,bug channels,
can used a cmd "immo" to go to a special discussion room called
discussion room sth, then they can post in the "discussion" board
about their idea, the difference of immortal and player is they
will be able to have direct discussion/private discussion with main
site's wizs about development or bugs.
they cannot view the codes and read the wiz.com and tasks...


in the current condition, I think there will be too less communication
among the mirror's wizs and also main->mirrors' wizs.

consider?
/


---
作者: 玄冰(ice)
题目: yuyin's suggestion
日期: Sun Apr  2 15:41:27 2000
时间:  Sun Mar 26 20:17:52 2000                Post-id: 28 (39 Last)
作者:  聂风(yuyin)
题目:  有关管理上的一些提议
----------------------------------------------------------------------
有关管理上的一些提议

加入 sg 不经不觉的已经有一年了，从开始的只有几个 area 一直到
现在的大地图，从20-30个npc到现在的200多个npc，我们的 sg 经过
了多少的风风雨雨，终于的到了现在的成就，这也是非常值得我们去
高兴的。但是大家可曾想到过在刚开始的时候，由于站点只有一个，
所以管理起来会比较简单，但现在我们却有 5 个分站了，而各个分站
的管理和开发也几乎是有 fire 和 row , stefan 一力承包，是否会
觉得力不从心或分身乏术呢 ？ 在此，我想提出一点小意见。
    我们是否可以加设一个统筹来进行各站之间的通知跟管理。

有关工作：
    1   与总站保持密切的联系，总站的所有更新必须及时向所在站点
        的 admin 汇报，并安排更新和重启时间。（由于 sg 的特点所致
        每一个很小的改动都会影响到 player 的正常游戏，并不象 lpc
        所以，当有了沟通以后就可以定出一个最好的 update 时间和
        方法）
        
    2   把本站的一些大事情进行一些汇总，并协助 admin 进行 player
        之间的纠纷和解，和站点的一些重大决策的安排。（因为每一个
        分站都有它自己的文化，这是其它站点的 wizard 所不知道的，
        又由于我们 sg 的特点所致，有很多的事情可能是其他站点已遇到
        过，但本站却没有遇到过，这样一来在处理上就可以方便的与其它
        站点的 wizard 取得联系，而制订一个更好的处理方法）
    
    3   每两个月与其他分站的统筹进行初商，定出开发计划，并根据
        其所在站点的 wizard 和 admin 的开发能力，安排好每一位
        admin 与 wizard 的开发工作。（因为每一个站点的实际情况
        都会有不同，如 player 的需要，wizard 的数量等等问题，
        这样一来可以合理的安排开发，使 fire 和 row ,stefan 能
        等能全力的进行开发工作，另一方面，也可以顾及到分站 player
        的需要）。


以上几个方面只是我的一些小意见，但大家也值得考虑一下。




---
作者: 玄冰(ice)
题目: about yuyin's data
日期: Sun Apr  2 07:34:13 2000
since yuyin now is a player, I suggest to cut his skill and reputation down to
a
normal stage.
if no one has objection, I'll mail yuyin to deal with this case.


---
作者: Ice
题目: >about no tell
日期: Tue Apr  4 06:06:25 2000
let's try with it first, if it still happens that player got flood,
release the no_tell function bah.:P


---
作者: Suicide
题目: >about no tell
日期: Tue Apr  4 02:26:02 2000
I think "  set can't tell a player the same thing within 10sec"
is a good idea .
To have a short busy time is a bothering thing.
:)


---
作者: 烈火(fire)
题目: about no tell
日期: Mon Apr  3 23:56:15 2000
Yes, we have a function find_body(id)->set_notell(xxx) to disable tell.
But at first I just want this used by wizs who can avoid repeatly disturbed
by players. But for players, I think our mud encourage them to communation
so don't want to release this feature to players. But we meet some problems
that some players use tell to flood. so what do you guys think, to open
no_tell for players or set can't tell a player the same thing within 10sec
and each tell has a short busy time to avoid flooding(just like
chat). So which 
way do you guys think it's better?



---
作者: 烈火(fire)
题目: recover wujun
日期: Tue Apr  4 19:32:53 2000
the function to recover an areas soldier is:
@AREA_D->set_area("wujun","troop",AREA_D->get_area("wujun","ssoldier
s")["new"]["troop"])

but some time need to check if got commando there :)


---
作者: Fire
题目: >>about no tell
日期: Tue Apr  4 19:31:58 2000
On Tue Apr  4 02:26:02 2000 Suicide wrote post #1316:
> I think "  set can't tell a player the same thing within 10sec"
> is a good idea .
> To have a short busy time is a bothering thing.
> :)
it is not a real busy time
just you can't tell twice within 1 second
because if we tell, need spend some time to input
so unless a ppl use robot or trigger, it is impossible to
tell twice within 1 sec, hoho


---
作者: Fire
题目: >bite's home file is corrupted.
日期: Wed Apr  5 22:27:28 2000
On Tue Apr  4 20:31:36 2000 威少爷(suicide) wrote post #1320:
> Today when i online bite tell me she can't home and can't cmd call.
> I checked her home file /data/home/b/bite.o i found i even can't more it.
> The error is just like we try to more file in mirror.
> So i delete the bite.o file and let her rebuild a home.
> She tell me she will lose 750 gold for this and ask me for money.
> So i add her golds to build new house.
> I asked her if she know what's wrong she had do her house.
> She tell me when crash she is in her own home when relogin she can't 
> home any more.
> 
> Am I wrong to add her golds to rebuild home?

I think what you done is right :)


---
作者: Fire
题目: >cut of yuyin's skill
日期: Wed Apr  5 22:08:37 2000
On Wed Apr  5 00:35:17 2000 玄冰(ice) wrote post #1324:
> i cannot find anyone interested to reply my post, so i go ahead with
> cut yuyin's skill for the reason that his skills was set when he was
> wiz, now he is an ordinary player, so should not be special.

right, just do it :)


---
作者: 斯坦福(stefan)
题目: re: qinghua mirror
日期: Wed Apr  5 08:17:02 2000
Actually I replied all of them that no confirmative answer will
be given until mid of April. But they just kept sending emails, often
same email repeated 4 times, which made me too lazy to answer :PPP

I will follow up with this guy later, but which application is his? I
am still confused :PP


---
作者: 玄冰(ice)
题目: cut of yuyin's skill
日期: Wed Apr  5 00:35:17 2000
i cannot find anyone interested to reply my post, so i go ahead with
cut yuyin's skill for the reason that his skills was set when he was
wiz, now he is an ordinary player, so should not be special.


---
作者: 威少爷(suicide)
题目: To Stefan
日期: Wed Apr  5 00:28:19 2000
糊涂说道：还是关于分站的事
糊涂说道：怎么一直没有stefan的回信呀
糊涂说道：我都快急死了
糊涂说道：suicide? 发呆？
你点了点头。
糊涂(yuera)告诉你：怎么还没有stefan的回信呀
糊涂说道：到底出什么问题了？
你说道：stefan said there r 4 ppl in tsinghua applying for mirror.
糊涂说道：不同意我们的申请？
你说道：He is confused and don't know how to use.
糊涂说道：我知道，那他打算怎么做？
糊涂说道：对了，要说明一下
糊涂说道：其中有一个要和我们和申
你说道：We can only choose 1 .
你说道：and none of it is official site.
糊涂说道：就是说4个当中有一个要和我们一起申请
糊涂说道：官方？
糊涂说道：什么算官方？
糊涂说道：我们都开xyj2000这么久了
你说道：清华的官方站点
糊涂说道：还不可以？
糊涂说道：现在我们xyj换到新站了
你说道：i don't know how stefan will choose.
糊涂说道：那要怎么样才可以呢？
糊涂说道：可是stefan面也见不到已
糊涂说道：他也不回信
你说道：u can mail him and tell hime sth in detail .
糊涂说道：我发过3封了又
糊涂说道：一封都还没回
糊涂说道：所以我很着急
你说道：ok. i will tell him about this again.
>糊涂说道：我们要和4个中的另外一个合起来申请
你点了点头。
>糊涂说道：我们之间正在协商具体事务。
糊涂说道：希望我们和起来之后，能够获取申请
糊涂说道：另外，我不大明白你说的官方是什么意思
糊涂说道：我们xyj2000能开，是得到批准的
糊涂说道：但是，我想说一下，作为学校，不可能明白的支持
你点了点头。
你说道：i will post him right now.
你说道：' bye.
糊涂说道：我们开xyj的时候，和上面说过，


---
作者: 威少爷(suicide)
题目: bite's home file is corrupted.
日期: Tue Apr  4 20:31:36 2000
Today when i online bite tell me she can't home and can't cmd call.
I checked her home file /data/home/b/bite.o i found i even can't more it.
The error is just like we try to more file in mirror.
So i delete the bite.o file and let her rebuild a home.
She tell me she will lose 750 gold for this and ask me for money.
So i add her golds to build new house.
I asked her if she know what's wrong she had do her house.
She tell me when crash she is in her own home when relogin she can't 
home any more.

Am I wrong to add her golds to rebuild home?


---
作者: Row
题目: >cut of yuyin's skill
日期: Wed Apr  5 23:14:03 2000
sorry ice, these days got some personal problem...
anyway, i support you just as b4.


---
作者: Ice
题目: >war time
日期: Thu Apr  6 16:23:30 2000
could be a way for now.:)


---
作者: 斯坦福(stefan)
题目: war time
日期: Thu Apr  6 09:44:16 2000
how about make it rotate every 20 hours, so eventually it will come to
morning, afternoon, evening, midnight, etc.

Or similar concept :)


---
作者: 玄冰(ice)
题目: seems sth got to be changed
日期: Thu Apr  6 08:56:55 2000
时间:  Thu Apr  6 07:48:41 2000                Post-id: 625 (632 Last)
作者:  孤星(lonestar)
题目:  关于sg
----------------------------------------------------------------------
本来早就想走
只是由于我请来了好多newbie
所以不得不坚持
但在我国连续由于没人在线而失守xiapi lujiang
而同样兵力我们第一次防守lujiang成功的消灭了xixixi 30k
让我深深的感到无奈
由于我和yesl个人原因
上线时间有限制
根本没法做到能长期和xixixi国半夜对抗
对sg mud的这个设计感到无力回天
所以我个人决定放弃sg@zj
也许sg游戏比的是谁能24 hour在线吧


from this post, I think we should stop to consider this matter,
i dun think make a player 24 hrs on line will be our purpose, but
actually, it is.:(
however, every mud has the same problem, more time, a higher highhand,
but I think we can have an advantage against other wuxia muds, our
war system can be rewrite to make this kind of problems better.:)
so ...  * addoil fire
* escape


---
作者: Ice
题目: >yuyin'skill
日期: Thu Apr  6 08:51:17 2000
On Thu Apr  6 02:49:43 2000 分钟(group) wrote post #1330:
> ice, it seems that what you did does not get the effect^^
> you must ensure that yuyin is online, then you can reduce his skills
> by the way you use^^
> 
> best regards

faint, i'll try to do it when he is online.:(
* fool


---
作者: 分钟(group)
题目: yuyin'skill
日期: Thu Apr  6 02:49:43 2000
ice, it seems that what you did does not get the effect^^
you must ensure that yuyin is online, then you can reduce his skills
by the way you use^^

best regards


---
作者: Suicide
题目: >re: qinghua mirror
日期: Wed Apr  5 23:50:29 2000
I also don't know which id he use to apply for mirror.
But when i met home again i will ask hime about it.


---
作者: Suicide
题目: >war time
日期: Thu Apr  6 20:16:14 2000
agree .


---
作者: 威少爷(suicide)
题目: add a mail list.
日期: Thu Apr  6 20:21:46 2000
Can we use the smtp daemons that had been finished by emperor to
be a mailist server?
Then if we met some good articles we could use a cmd to let smtp daemons
to mail these articles to all the ppl who have registered here.
So every ppl registered here can get the new things happened here even
without login here when they r busy.


---
作者: 威少爷(suicide)
题目: war time
日期: Thu Apr  6 20:18:33 2000
But the best way i think is that we should open war everytime.
So we have to addoil to strong the war system.
addoil .


---
作者: 威少爷(suicide)
题目: To fire :
日期: Tue Jul 25 19:42:31 2000
  太守制度的所有code我都写好调试基本无误了,现在官员升迁降职还差一个国家官员
的升值问题(NPC国王),请问采用何种方式?一:玩家达到资格就就向国王要
二:系统自动挑选,向汉帝召见差不多,fire你决定一种方式吧.


---
作者: 烈火(fire)
题目: Re suicide
日期: Tue Jul 25 16:11:26 2000
勤奋度的建议不错，可以用来对NPC国进行一定的
考核。但是NPC的支持度我还不太了解如何实现。
我建议对于NPC国的太守，可以采用suicide的勤奋
度考核法由系统自动产生，但是对于国师，我建议
采用选举的方法。每一个官员，根据其国家贡献和
勤奋度计算一个权值，另外在将目前的vote系统扩充
一个专门用来选举国师。国师可以有届数，五个三
国年选一届。如果要当国师必须有一定的支持度和
支持比例。在重新启动的头两三周，因为大家的勤奋
都和国贡都不高，不可能产生国师。用一个大米当
国师绝对不可能。等许多地区有了玩家自动太守同时
该国的玩数量，等级达到一定程度时，该国将有两个发展
方向：
1， 民主选举国师。因为国家要强大，必须有核心的
      领导。如果选不出国师，下一步发展必然受限制。
2， 部份玩家太守独立。也许可以 修改独力的要求，加上
    在本地有一定比例和数量的玩家(勤奋度和地区贡献要
    有要求)的支持，才可以独立。
基本分别是，玩家国是帝王制，NPC国是议会制，这样
也有可能由喜欢曹操的玩家联合起来，帮助曹操一统天下
哈哈。
所以，suicide可以先把NPC自动太守部份搞好，下一步
再考虑国师问题。addoil suicide



---
作者: 威少爷(suicide)
题目: To fire
日期: Tue Jul 25 06:41:38 2000
Did u rm the file of npcai_d.c in /daemons dir?
I have upgraded it and put it in the dir /wiz/suicide,check it bah...
The 2nd copy add the function of 官员的自动免职.


---
作者: 威少爷(suicide)
题目: 工作进度
日期: Tue Jul 25 04:36:23 2000
/sgdomain/event/ev_position.c的第四次修改
1)  所有角色第一次成为闲职时,设定初始勤奋度tsx为200
/daemons/npcai_d.c的第二次修改
1)  轮巡NPC控制地区(国王为NPC且没有玩家国师)的官员职位调整,没轮巡一
次官员的勤奋度
    减15,当勤奋度小于0时,被解职,如果玩家身兼地方国家官员,先解职国家
官员,下一轮如勤
    奋度仍为负,则才解职其地方官员职位,官员被解职时,声望和国贡各减1/5
(不知是否太多,
    请建议),被解职后初始勤奋度恢复成100,防止玩家在勤奋度为负时在此任
职又被解职,造成
    更大损失.
2)  太守被解职也是声望和国贡各减1/5.
3)  NPC主公(且没国师)但玩家为太守时,只考察国家官员,不考察地方官员.


---
作者: 烈火(fire)
题目: about suicide's code
日期: Tue Jul 25 00:52:00 2000
I haven't check your idea clearly.
seem not bad, I will check them tomorrow and 
give comment asap.

admire suicide

addoil sucide.
bow


---
作者: 黄帝(emperor)
题目: 一些建议
日期: Mon Jul 24 08:18:18 2000

一些建议

1、 现在三国里只要一个玩家在重启后第一个完成所有JOB，
那就意味着他能第一个在他所在的地区独立。而完成所有
JOB 对一个有全套机器人的玩家来说那是轻而易举的。
    即使象SUICIDE 建议用太守和国师并存制度，还是不能
解决根本问题。
    所以我建议增加一些JOB， 这些JOB 是给其他玩家用来
降低目前处于国师或太守的国家贡献（因为SUICIDE 辛辛苦
苦做了太守和国师并存的CODE，我想还是采用吧），先假定
每天这些针对国师和太守的JOB至多降低500国家贡献。这种
JOB 相当于历史上的进谗言，如岳飞对南宋的国家贡献再大，
不也被秦烩几句谗言而冤死在风波亭；诸葛亮被黄皓几句谗
言一进，就被刘禅从前线召回，导致西出祁山的又一次失败。
历史上类似这个现象很多。
    我设想了一个这样的JOB：
        玩家可持别 500两黄金去贿赂已敌对玩家所在国的某
个NPC ，请这个NPC 向国王进敌对玩家的谗言，每进一次谗言，
这个敌对玩家的国家贡献降低 50。或者考虑根据黄金数量来
降低相应数量的国家贡献。这样也就让玩家囤积的黄金又有了
个好去处，免得有了管家后，黄金多得没地方用。
    具体过程：
    A。 玩家首先向所在国国王要个实施谗言工作；
    B。 所在国国王表示同意，让玩家输入诋毁哪个玩家（NPC
不能被实施）；
    C。 所在国国王判断是否是另外一个国家的玩家。如果是，
就让申请玩家去贿赂某个NPC ，这个NPC 当然是敌对玩家所在
国的官员，可与被诋毁的玩家在一个城市，也可以不在一个城
市。这样一来被诋毁玩家想BLOCK都不行。
    D。 玩家找到这个NPC 后，ask 某某 about dihui，这个
NPC 嘿嘿笑了几声，问道：你愿意出多少黄金（100-1000）？
（我想括号内黄金数量取决于玩家身上的黄金数量，但不能少
于100 GOLD，府库内黄金没用，如果带的黄金数量少于100 或
者输入的黄金数量少于100或者random（2）==0 或者大于身上
的黄金数量的话，则该玩家被NPC 关进牢房）；
    E。 如果没被关进牢房，则根据输入的黄金数量相应扣减
被诋毁玩家的国家贡献，并在谣言频道内显示：某某NPC 在国
王面前进了一些谗言，某某玩家的国家贡献被降低了。同时做
这个JOB 的玩家的国家贡献相应提高一些数值。
    F。 被诋毁玩家每半天（12小时）之内的国家贡献至多被
减少500（这是假设值）

    我想有了这个JOB ，玩家间更会变得勾心斗角，而且也能
解决抢国师的问题。同时也会在国师问题上要学会耍计谋，也
许一些玩家在降低了某个ID的国家贡献后，却疏忽了另外一个
ID。再想去减少第二个ID时，却发现黄金已经不够了。如何攻
击别人而又不让自己的ID在独立前不被敌人降下来，我想这够
让想独立玩家头疼的。而且因为自己的手下玩家常常被谗言所
进而不能发展自己的势力，这更让人头疼了。
    这个JOB 适用对象是任何已成为官员的玩家，不仅仅是国
师或太守。
    

2、suicide的npcai_d在巡查时应该对每个玩家官员进行判断，
看其是否具备任现在职务的条件。不满足的话， 应该被自动降
为闲职或变成隐居闲人。
    在玩家国也是一样。

3、建议战争结束时，随机选一些NPC 和玩家被抓。被抓的NPC
过一段时间变成隐居闲人。在这之前在地区信息里增加一项：
战俘：某某、某某。而玩家被抓后，则一律被砍头，相应减少
减少所有修养一级和所有技能一级。同时减少其地方贡献等指
标。免得三国里所有玩家全部升为NPC。
    

同时这也能防止玩家在两个城市间war来war去，快速提高经验。
如果他们再war来war去，可能会得不偿失了。只有真正统一全国
的玩家才能获得更高经验的奖励，这才合理。
的玩家才能通过war获得更高经验的奖励，这才合理。


---
作者: 威少爷(suicide)
题目: /daemons/npcai_d.c的修改备忘录：
日期: Mon Jul 24 00:12:55 2000
功能说明：
    以城市为单位，每MUD时间的一天(16分钟)，按顺序对99个地区进行轮巡（
所有地区轮巡一遍所化的时间是16*99=1584分钟，即一天多144分钟)，对于是
玩家太守或玩家国王国师的地区跳过什么也不做，对于NPC控制的地区执行以下
智能判断：
    1）没有玩家太守，挑选玩家太守，条件是国家贡献>（500*地区level）的
    该地区所有玩家的前三名根据个人国家贡献高低按一定几率挑选。
    2）有玩家太守，考察其勤奋度，当玩家被挑选为太守时，初始值为200，其
    后每轮巡一次降20（该值可以讨论），当勤奋度降为0后就会被解职，勤奋度
    的增长通过做某些对城市发展重要的job（讨论）来实现，每做一个job长一
    点也就是说如果玩家太守保持每天（实际时间）做20个重要job勤奋度就会不
    升不降，如果成为太守后什么重要Job未做，10次轮巡也就是11天后就会自动
    被解职，我们通过调整每次轮巡降的值（现在暂时是20)就可以控制一个勤奋
    的玩家太守一天该做多少job.
    3)考虑是否对临近兵少的城市开战。（暂时没做，以后可以扩充）。
    4)考虑本地区是否有什么随机时间发生，如兵变，民变，土匪袭扰等等。(未实现)
测试: (我已初步调试通过希望大家测试)
      1  利用add_country("dong zhuo","xiangping")在襄平先建立一NPC董桌国。
      2  投奔该NPC国，设置自己的国家贡献。
      3  @ "/daemons/npcai_d"->test_npc_taishou("xiangping")就可以进行测试了。
      4  勤奋度的参数为"tsx".
      5  update该程序后会有一定时call,测试完成后最好用命令
         @ "/daemons/npcai_d"->remove()将其删除.
      
可能会导致BUG的情况考虑:
      1  玩家太守暂让太守后的撤职问题已考虑测试通过。
          
对系统其他程序的影响：
  需要调整JOB系统，增加奖励勤奋度这一要素。(修改/daemons/char_d/loca
lcontribution.c
判断当太守增加国家贡献时，同时加一点勤奋度).
  
  如果这一点完成，实际上我们就已经可以实行开放太守制度了。然后在太守
制度的基础上我们
可以在玩家做了太守后可以抢国师，条件是所属国2/3的NPC角色支持，没有抢
的国师的太守如果
得到本地2/3NPC官员的支持，可以无法被国师撤职甚至独立，得不到就会被国
师的亲信替代。这
样我们就把国师和太守制度融合到一起了。
  如果fire同意我这样的更改，我就马上修改localcontribution.c,这样我们
就可以在下一代正
式开放太守制度了。
      
以上是我现在做的方法，有不到或歧误之处，希望大家能及时给与指正！！


---
作者: 威少爷(suicide)
题目: /sgdomain/event/ev_position.c的第三次次修改
日期: Mon Jul 24 00:12:37 2000
1)  为了保持和原来国师code的兼容性，当太守为NPC角色时,判端国家
    有没有国师，我现在在太守制度的基础上有了一点新的想法，就是
    做了太守后可以抢国师，条件是所属国2/3的NPC角色支持，没有抢
    的国师的太守如果得到本地2/3NPC官员的支持，可以无法被国师撤
    职甚至独立。综上所属所以我在新的code里保持了对国师code的兼
    容性，减少以后修改的工作量。


---
作者: 黄帝(emperor)
题目: king of kings
日期: Fri Jul 21 21:14:08 2000
万王之王的GB站点： www.kok.com.cn


---
作者: 威少爷(suicide)
题目: To fire
日期: Thu Jul 20 21:34:28 2000
Open a new newsgroup bah,call it task.guoshi and move all about it
in wiz.com there
massage fire
hoho fire
:)


---
作者: Suicide
题目: >>To fire:
日期: Thu Jul 20 21:33:14 2000
I will modify the code of ev_ncpcountry to random select taishou,but i will
add a limit that the play that can be taishou must should fit the
qualification of the taishou.


---
作者: 威少爷(suicide)
题目: Finish Ev_position.c
日期: Thu Jul 20 21:28:10 2000
I have finished the code of ev_position and had install in /sgdomain/event.
I had test all the situation what i can think out and u guys had
mentioned to me , 
to avoid big bugs.welcome to check it.
If there are still sth i can't think ,pls tell me.


---
作者: 威少爷(suicide)
题目: /sgdomain/event/ev_position.c的第二次修改
日期: Thu Jul 20 21:19:26 2000
1)  当太守为NPC角色时,判断是不是玩家太守暂让的或国王是不是玩家.


---
作者: Fire
题目: >To fire:
日期: Thu Jul 20 16:48:16 2000
On Wed Jul 19 22:36:13 2000 威少爷(suicide) wrote post #1601:
> 我希望不是系统随机挑选国工>500的玩家做太守,可不可以改成,当
> 玩家达到太守标准后向NPC国王申请做太守
> ,这样在小城容易快一点做太守而大城的太守就要当的慢一点,比较平衡,
> 如果你同意这样,将尽快拿出向国王申请太守的code.
>  .
> 
> 
> 
> 

TI think random is a little better.
If player ask the position, once he got thatrequirement, he can
become localleader immediately.
so it maybe easy for dummies to get all the local's leader position
after several days of restart.
If we choice the random, The dummy may not so easy to
get the position. and we can make the assign of new local leader
last for about 2 weeks or even longer
it may give more chance for real players.

However, your suggestion about different requirement
for different level of city is very good.
You can give a list of the different requirement and then modify 
the ev_npccountry.c

about the ev_position.cI am not sure about the bug you metioned.
If it has that bug, please fix it bah, hoho :)

addoil suicide.


---
作者: 威少爷(suicide)
题目: To fire:
日期: Wed Jul 19 22:36:13 2000
我希望不是系统随机挑选国工>500的玩家做太守,可不可以改成,当
玩家达到太守标准后向NPC国王申请做太守
,这样在小城容易快一点做太守而大城的太守就要当的慢一点,比较平衡,
如果你同意这样,将尽快拿出向国王申请太守的code.
 .






---
作者: Suicide
题目: >Re suicide about ev_position.
日期: Wed Jul 19 22:30:33 2000
I know that the old code in ev_position will display a menu
and ask the user to choice which position he wants to apply.
But it has a big big bug ,when player input the officer id,system will 
not check if it is valid,even the officer id isn't in that area or is a nation
officer,so i had modified the code to fix this bug.
I had modified that only the localleader is a npc ,then player can ask
higher local postion,but forgot to judge if the king is player or Npc
localleader is granted by player,so i will fix it.:)

Fire, Have u check my code of ev_position.c that i have installed 
in system and now only can be tested by wiz for asking postion.
Check it bah,hoho,give me ur suggestion.

In ur post u said that will we disable guoshi when next restart,
Will we use the new ev_position ,if it is ,pls tell me,
I will delete the limited code (which only open new function to wiz)
before restart.:)


---
作者: Row
题目: >The san7
日期: Wed Jul 19 19:48:14 2000
On Wed Jul 19 18:58:44 2000 烈火(fire) wrote post #1597:
> I just can't believe what ice send to me is only a copy of the
> files under his computer's san7. How can I just run them without
> the installation. I believe every big software as san7 can work
> only when you install it properly in your computer and during 
> this processit may copy some dll under windows directory or 
> register some environment constants. Kick ice, 
> 
> It took me so much time in vain
> 
> Sigh
> 
laugh, comfort fire, just let ice EMS the CD to you.
or re-ftp up the installation file.


---
作者: 烈火(fire)
题目: The san7
日期: Wed Jul 19 18:58:44 2000

I just can't believe what ice send to me is only a copy of the
files under his computer's san7. How can I just run them without
the installation. I believe every big software as san7 can work
only when you install it properly in your computer and during 
this processit may copy some dll under windows directory or 
register some environment constants. Kick ice, 

It took me so much time in vain

Sigh



---
作者: Ice
题目: >something strange in news system
日期: Wed Jul 19 18:45:56 2000
I think we may have a dual way system anyway, both rules have
its own adv, also disadv, then we can choose sth in between.:P
later I'll try to make it together and post it up.


---
作者: 烈火(fire)
题目: something strange in news system
日期: Wed Jul 19 16:44:54 2000
I find I can't read the post in progress from
news command but can read it from board. It is strange,
some the msg id got some error so it cause the confused
problem. The post in progress can't be viewd by news
is 
1：国师制度的调整。                    【烈火(fire) Jul 17】
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
本代三国看来很快就要统一，现对国师制度作以下临时调整。不合理只处
还请多提意见。
1 NPC国家将不在自动产生国师。
2 系统会随机地把一些NPC国的玩家晋升为太守，条件是：
  a 国家贡献大于500。
  b 当地没有玩家太守(也没有玩家委任的NPC太守)。
这只是一个临时修改方案。不排除再次调整的可能性。


---
作者: 烈火(fire)
题目: Re suicide about ev_position.
日期: Wed Jul 19 16:17:22 2000

In fact, the old code in ev_position will display a menu
and ask the user to choice which position he wants to apply.
but that one caused the dummy spy problem. So all the new
position has limited to R_SG. Now I think suicide can modify
the code and when the king and localleader are both npc
then the system will display a menu for the player to choice
position. Otherwise only grant R_SG position. However, please
also check if the localleader is assigned by a player localleader.
you can find some example code in the sgdomain/menu/pos.c
cheers, :)



---
作者: 烈火(fire)
题目: about about san7.zip
日期: Wed Jul 19 16:10:26 2000
I finally got that file. It took me about 24,300 seconds to download
in my office's computer. I have delete it from ice's directory.
The next task for me is try to burn a CD in my office so I can
install it on my home's computer. 
hoho :)
thanks ice


---
作者: 玄冰(ice)
题目: grrr....
日期: Wed Jul 19 05:33:21 2000
I am exhausted involved in unlimited arguement...:(
I am going to pay a visit to my friend and drink sth today,
after that I'll resoncisder the whole topic, and provide some
other detailed plan.
suddenly remember some other reasons of we changed the former
rules to guoshi rules, and I think our former rules works as
suicide's anyway.  btw, do suicide know our former rules of
local rank? if u dun know, errr, I dunno where to chekc it.:(
if u meet me or fire, ask to explain then.
addoil all.


---
作者: Suicide
题目: >>To stefan
日期: Wed Jul 19 04:52:51 2000
好可怜哦，重要的东西有备份
好可怜哦，重要的东西有备份吗？
我没有发到sina.com啊
我的邮件地址是suicide75@wx88.net,我试一下还是不行，stefan，再帮忙检查一下把！
。


---
作者: Stefan
题目: >To stefan
日期: Wed Jul 19 03:27:25 2000
On Wed Jul 19 02:07:51 2000 威少爷(suicide) wrote post #1589:
>    Pls help me debug the smtp_d.c bah,i still can't use it.It is very
poerful
> for me. For i want that i can read those good posts after i offline.
>   To keep a mass log is a mass thing.
> 
> Beg stefan
> Massage Stefan
> Sweat stefan

前天不小心把自己的 laptop 重新格式化了，半年的东西瞬间化为乌有...
心情真是差到极点 :( 
SMTP 我上次改完忘了试，因为新机器的 domain name 没弄好，你发到
sina.com 就会被拒，现在应该好了，请再试试看 :)


---
作者: 威少爷(suicide)
题目: To stefan
日期: Wed Jul 19 02:07:51 2000
   Pls help me debug the smtp_d.c bah,i still can't use it.It is very poerful
for me. For i want that i can read those good posts after i offline.
  To keep a mass log is a mass thing.

Beg stefan
Massage Stefan
Sweat stefan


---
作者: 威少爷(suicide)
题目: ev_position.c的修改备忘录： 
日期: Wed Jul 19 00:31:49 2000
功能更改说明：O--旧功能　N--新功能
Ｏ：用ask taishou about postion,玩家只能成为闲职官员，更高的地方官员职位
　　需要直接由太守来指定．
Ｎ：如果太守为玩家角色，同旧功能．但当还没有玩家成为太守，只是由NPC 角色
　　担当太守时，玩家如果升级条件满足，可通过ask taishou about position自
　　动得到有空缺的地方官员职位．
程序模块增加：check_area_vacancy(p_area,officer_id)
功能：用于检查玩家申请升职的职位在本地区是否存在和有空缺，原程序只是搜索
　　　本地区的空缺职位供玩家挑选，但当玩家输入不在此列的官职后，不做合法
　　　性检查，这样可能导致玩家得到他所需要的所有官员职位．增加该模块后，
　　　该问题解决．
测试: (我已初步调试通过希望大家测试)
      我在程序中增加了下面code,所以在未开放前只有巫师可以测试,不会影响现
      有系统.
      if (!wizardp(who)) //在未开放前只有巫师可以测试
  
对系统其他程序的影响：
1 　现在各官职的要求对地区贡献度和声望的要求太低或不协调，象大城太守之职，
　　地贡只需700即可，村长的地贡只需100，声望只需1000，所以希望fire或ice 
    仔细检查一下，调整一下官职条件要求．
2   考虑当玩家一旦定居成为角色后，加入一勤奋度的数值，当完成不同的工作时，
　　根据任务的不同（正常情况下所耗的时间的不同）增加一定的勤奋度，我们估
　　算一固定时间段内正常情况下玩家应该有的勤奋度增长差值，每隔这一固定时
　　间系统自动轮询某地区的所有玩家官员的勤奋度增长值，（[玩家实际增长值]
　　－[正常估算增长值]）的差值为负值，系统给与警告，警告达到一定次数玩家
　　自动被系统解除职务.如果对我这种做法无异议，我下一步就开始做勤奋度判断
　　的系统．
以上是我现在做的方法，有不到或歧误之处，希望大家能及时给与指正！！
　　
 


---
作者: 玄冰(ice)
题目: dission between suicide and me
日期: Tue Jul 18 19:02:28 2000
as suicide wish, I post the dission of guoshi here, grrr, not a good job
for me anyway.:P

【巫师】威少爷(suicide)：ice,u mean when should write a vote system first?
【巫师】威少爷(suicide)：But I think vote taishou is not a good thing.
> 【巫师】威少爷(suicide)：当太守还是要看实力,最先达到太守
【巫师】威少爷(suicide)：当太守还是要看实力,最先达到太守要求的人做太守!
> 【巫师】威少爷(suicide)：你看这样行不行?
【巫师】威少爷(suicide)：和抢国师一样
> 【巫师】威少爷(suicide)：要勤奋的工作抢先一步达到太守的条件
【巫师】玄冰(ice)：if I log 2 days after restart, I have no chance?
【巫师】威少爷(suicide)：But too many cities
【巫师】玄冰(ice)：taishou position is not permenant
【巫师】威少爷(suicide)：我想可以通过一定时间跨度太守完成的任务数来判断他是否
会被撤职
【巫师】玄冰(ice)：then we need to design some taishou job then
【巫师】威少爷(suicide)：Just let taishou can also do job ,then ok?
【巫师】玄冰(ice)：if taishou is so important, he is supposed to do some
higher lv of jobs
【巫师】玄冰(ice)：but we didn't have any high lv jobs yet
> 【巫师】威少爷(suicide)：If he is out to do job,can left his 幕僚 in meeting
room.
【巫师】威少爷(suicide)：和国王搞好关系
【巫师】威少爷(suicide)：JOB1 拍国王马匹!
【巫师】威少爷(suicide)：所以我的意思是我先做起来
【巫师】威少爷(suicide)：你和fire多给我提建议,我会不断汇报精度.
【巫师】威少爷(suicide)：我马上先做地方官员升级制度
> 【巫师】威少爷(suicide)：我会汇报我改了什么程序,注意了什么方面
【巫师】威少爷(suicide)：你们就可以一边帮我测试,一边提醒我还需要注意的方面

* sweat


---
作者: 威少爷(suicide)
题目: Re :ice
日期: Tue Jul 18 08:45:15 2000
From Ice:
>我想如果在不做太大改动的情况下，可以这样更改：
>1、将国师的选拔制度改成从该国国家贡献超过500的玩家中挑选3名最高
>   国家贡献的让国王进行挑选，每人的机会为他的国家贡献占入选者的
>   国家贡献的比率。如果没有人超过500，则不存在国师；如果超过500
>   的玩家不足3人，计算方法一样，入选者少了，成功的机会大了，失败
>   的机会也相对大了。
   
Re: Ice你所说的方法和我们现在实行的方法完全一样,而且我们现在国贡
    的限制已达到1000,但还是有国师制度的弊端.
   
>2、国师重选期限改为2年由国君重新筛选一次，方法同选拔制度。应该不
>   存在不国师不能连任或一直连任的问题，谁的工作勤奋机会就大，至于
>   政策的延续问题，那就要由官员之间来协调了，毕竟三国游戏不是一个
>   人说了就算的游戏。（重新筛选后落选的国师不会丧失任何东西）
>3、如果在两年期内国师的信任度降到0，一样会被国君解除国师职位，并且
>   在1个月后重新进行筛选，被解除国师职务的玩家国家贡献减半（这可能
>   由违fire设定国家贡献为线性函数的初衷）。
Re: 实际上第一个得到国师的人由于拥有人事大权,所以他完全可以排除异己
    就算可以重选,那些可能会抢班夺位的玩家也会在现任国师的压制下无法
    得到机会,而且现在的玩家好像都有点结队思想,这一代我帮你,下一代你
    帮我,所以抢国师成了一种群体行为.只要是一伙的你抢我国师也是换汤不
    换药,不是一伙的就用人事权进行打击,使其抢夺国师的可能性为0,而且即
    使敌对方的国师当选,他也不会得到原国师手下的支持,并且他本身也会利
    用人事权队打击原国师方的玩家,重用自己方的玩家,这样对不停奋斗的原
    国师方玩家也很不好.结果变成国师不变也不好,老变更不好的境地.
    
>4、在pos里进行对国师权力的一些限制：
>   1 每解雇一名官员的职务，信任度降50；
>   2 每调动一名官员，信任度降20，每调动一次国君，信任度降50；
>   3 每调整一名官员的国家职位，信任度降10；
>   4 每任命一名太守，信任度降20，任命自己当太守，信任度降50；
>   5 地区太守不能调动，只有先任命其他官员当太守才能调动，防止每次
>      把地区调空，然后无人防守。
>5、调整工作的贡献度，使一些对国家有利的工作与一些不痛不痒的工作有
>   较大的差异。如搜索贤人、访问贤人等成功后的贡献度加倍。
Re : 削弱国师的权力的确是个好方法,但是本来国师的初始信用度就不高,而
     人事权是国师最大功效所在,如果对国师的人事权进行这样严格的限制,
     使玩家正常的人事调动也大受影响就不如不要国师.
     
以上是我的一点意见,也不知是否偏颇,敬请指正,另外谢谢ice这么快就写出这个
帖子,对我帮助很大.在考虑ice帖子的时候我又产生了几点想法,望大家发表意见:
1 取消国师,实行以前的官衔升级制度,玩家不停的成长一直到成为太守,太守最后
  直接独立立国.这样就会导致很多以单个城市为基础的国的出现,统一天下就会变
  的很难,不致于现在最快半个月天下大局就定了.而且由官衔升级制度的恢复,会
  给大多数喜欢不断升级的玩家带来更多的乐趣,由一个城市发展到统一全国会使
  玩家更有成就感.
2 取消国师需考虑的方面:(我考虑很不周,望大家多提醒)
   2.1地方官职的分配:
     a 在没有玩家太守前,当资格达到且又有空缺时向NPC太守主动申请.当玩家成
       为太守后由玩家分配.
     b 由于地方官员职位有限,对于那些得到职位后又长时间不上线的玩家的处理
       提议引入和国师信任度一样概念的勤奋度概念,勤奋度为0被解职.
   2.2国家官员的作用和分配
     a 分配和解职同地方官员,只不过向国王申请.
     b 由于取消国师后的采用太守制度,一个城可以等同与一个国家,原有的国家官
       员的作用就不大了,但是我们可以考虑一些新的功能.(得到更多的薪水,到前
       线城市帮助作战,某一城的国家官员多可以在向国王调粮调钱的会议上得到更
       高的成功率,可以增加一些王国任务只有国家官员可以做等等)
   2.3由于国家已城为单位,所以要允许等级小的城市可以升级到5级城(当然有很大
      难度),不然小城市的太守就一点梦想也没有了.
   2.4news是否要为单个城建立一个新的组,还是共用国家留言版,但增加一个标志只
      有同城的才能看到.
   
   
       
       
   
   


---
作者: 威少爷(suicide)
题目: To stefan
日期: Tue Jul 18 07:25:21 2000
  Stefan :
   The function of transfering news to email is still not
working,can u check it?
I need this function very much.thx.
                              suicide


---
作者: 玄冰(ice)
题目: about guoshi
日期: Tue Jul 18 03:54:03 2000
guoshi should not be able to change the name of country as well.


---
作者: 玄冰(ice)
题目: mudlist
日期: Tue Jul 18 01:37:57 2000
> mudlist
在 9 个 MUD 中有 9 个对应的，其中 6 个正在开放。
用 mudinfo <mudname> 来获取更多的信息。
Up  Mud              Address                 Lib           Open Status       
----------------------------------------------------------------------------
U   璣动         203.133.98.184   7878   Lima 1.0a9    mudlib translat   
U   三国志上海站     61.129.64.138    5000   Lima 1.0a2    open              
U   三国志台湾站     211.72.114.51    5000   Lima 1.0a2    open              
U   三国志浙江站     202.96.109.11    5000   Lima 1.0a2    open              
U   三国志重庆站     61.128.193.35    6666   Lima 1.0a2    open              
U   三国志总站       209.249.156.100  5000   Lima 1.0a2    open              


errr, what's that


---
作者: 玄冰(ice)
题目: a funny program about sg
日期: Tue Jul 18 01:36:11 2000
I found a funny question program, it has about 600 questions,
every time randomly choose 25 questions, the answering way is
similiar to our robot test, but those questions r just too tough,
how ever, take a look.
it's in /wiz/ice/sgyy.exe.
ps I used ftp/auto to upload and download, if works, dunno should
use binary or acsii.:P


---
作者: 玄冰(ice)
题目: about guoshi
日期: Tue Jul 18 01:16:53 2000
国师制度出炉的目的在于增强NPC国家与玩家国的抗衡，但在当时起到了
一定的历史作用，现在来看，似乎现有的国师制度已经不能满足需要了。
我观察到的国师制度主要弊端如下：
1、当一名玩家当上国师以后（且不论是否大米），除非他完全不不干活，
   否则信任度是不会降到0的，换句话说，就是其他玩家完全没有机会
   取而代之。更何况现在处心积虑抢国师的人，基本上是multilog而且
   跑机器人的，更加不可能被取代，所以有了重启后谁抢的国师多谁
   的势力就大，特别是抢到一些如董卓、袁绍等的国师，统一只是时间
   问题。
2、国师的权力基本上是等同于国君的，除了不能禅让、提金等之外，几
   乎无所不能，而由于国师不是国君，他所做的事情并不一定是为了他的
   国家好的，所以国师做一些有害于国家的事情的时候并没有什么惩罚。
3、当一个国师要独立的时候，他可以把国君发配，然后自己在国内最富庶
   的地方独立，而且独立了以后，用INFO N查看以前国家的情况时，他
   仍然在国师的职位上，虽然他不再行使该国国师的职能，但一样要等到
   信任度降为0别的玩家才有机会当上国师。

我想如果在不做太大改动的情况下，可以这样更改：
1、将国师的选拔制度改成从该国国家贡献超过500的玩家中挑选3名最高
   国家贡献的让国王进行挑选，每人的机会为他的国家贡献占入选者的
   国家贡献的比率。如果没有人超过500，则不存在国师；如果超过500
   的玩家不足3人，计算方法一样，入选者少了，成功的机会大了，失败
   的机会也相对大了。
2、国师重选期限改为2年由国君重新筛选一次，方法同选拔制度。应该不
   存在不国师不能连任或一直连任的问题，谁的工作勤奋机会就大，至于
   政策的延续问题，那就要由官员之间来协调了，毕竟三国游戏不是一个
   人说了就算的游戏。（重新筛选后落选的国师不会丧失任何东西）
3、如果在两年期内国师的信任度降到0，一样会被国君解除国师职位，并且
   在1个月后重新进行筛选，被解除国师职务的玩家国家贡献减半（这可能
   由违fire设定国家贡献为线性函数的初衷）。
4、在pos里进行对国师权力的一些限制：
   1 每解雇一名官员的职务，信任度降50；
   2 每调动一名官员，信任度降20，每调动一次国君，信任度降50；
   3 每调整一名官员的国家职位，信任度降10；
   4 每任命一名太守，信任度降20，任命自己当太守，信任度降50；
   5 地区太守不能调动，只有先任命其他官员当太守才能调动，防止每次
     把地区调空，然后无人防守。
5、调整工作的贡献度，使一些对国家有利的工作与一些不痛不痒的工作有
   较大的差异。如搜索贤人、访问贤人等成功后的贡献度加倍。


---
作者: Row
题目: >马又吃草了吗?
日期: Mon Jul 17 02:50:56 2000
On Sun Jul 16 22:02:49 2000 威少爷(suicide) wrote post #1579:
> 【谣言】某人：庞小统不给坐骑足够金粮，汗血宝马俄死了。

应该是存款用完了吧。


---
作者: 威少爷(suicide)
题目: 马又吃草了吗?
日期: Sun Jul 16 22:02:49 2000
【谣言】某人：庞小统不给坐骑足够金粮，汗血宝马俄死了。


---
作者: 威少爷(suicide)
题目: To stefan
日期: Sun Jul 16 20:53:35 2000
   The function of transfering news to email isn't work,can u check
the smtp log?


---
作者: Fire
题目: >tai yuan base
日期: Sun Jul 16 16:33:28 2000
On Sun Jul 16 08:49:46 2000 斯坦福(stefan) wrote post #1576:
> noise reported that ganjin of taiyuan's base always drops
> from 100 to 29 suddenly, I am not sure what is the reason.

I think that may caused the data of taiyuan happenly connected
with other base. But don't know which one and how they connected
each other. escape


---
作者: 斯坦福(stefan)
题目: tai yuan base
日期: Sun Jul 16 08:49:46 2000
noise reported that ganjin of taiyuan's base always drops
from 100 to 29 suddenly, I am not sure what is the reason.


---
作者: Emperor
题目: >about san7
日期: Fri Jul 14 05:54:14 2000
On Thu Jul 13 23:45:26 2000 烈火(fire) wrote post #1571:
> hi ice, I don't have san7, can you ftp it back
> to the lima ?
三国志七代我感觉不好玩，比四代要差。七代的参数设置非常简单，我选了“华驼”
这个角色来玩的，不需要花多长时间，就能统一全国。七代有个大BUG，我觉得太没意思
，远不如四代好玩。光荣的三国现在是一代不如一代，poor koei。


---
作者: 玄冰(ice)
题目: >about san7
日期: Fri Jul 14 05:40:30 2000
ack, the full size of the game is 240MB, I think if I zip it it'll still
be 100MB sth, anyway, I think ICQ will be better to trans big files point to
point, so next time I meet u, fire, we can try.
errrr, this weekend I won't show up, hope next week the server work well then.
addoil


---
作者: Stefan
题目: >about san7
日期: Fri Jul 14 00:08:44 2000
On Thu Jul 13 23:45:26 2000 烈火(fire) wrote post #1571:
> hi ice, I don't have san7, can you ftp it back
> to the lima ?

oh NO! It will add too much space to the backup :PPP We are having
a backup size of 15M zipped ....


---
作者: 烈火(fire)
题目: about san7
日期: Thu Jul 13 23:45:26 2000
hi ice, I don't have san7, can you ftp it back
to the lima ?


---
作者: 玄冰(ice)
题目: I can connect to internet leh
日期: Thu Jul 13 22:34:58 2000
well, I finally got an internet connection in my room.:)
couple of days ago I just cannot log to the main even the main's status
in other mirror is open, but now the speed for me is like flying in the air
compared to PRC..:(
and I'll start to show up after this weekend, i can be reached
by the email "finger ice"(free) and mobile phone +31615351046 (costly):P
or the ICQ number stated in the former post.


---
作者: Ice
题目: >about the guo shi
日期: Thu Jul 13 22:22:20 2000
On Thu Jul 13 20:59:20 2000 烈火(fire) wrote post #1565:
> the reason to have guo shi is to give the npc country a chance
> to survive if it got a very good guoshi. hoho :)
> But seems this feature is misused. I will modify the system to make
> it more fair. thank your suggestion, suicide. :)

fire have san7? take it as a reference bah.:)
if u dun, I have a HD version in my laptop, I can use ICQ to transfer to u
if u wish, my ICQ number is 13104091, needs authorization, state u r then.:)
ps it's a JP version, but can still play with since there still some
chinese chars within, no difficulties at all.:)

about guoshi, I think it's not suitable for the current situation, I think
we need to do sth to deal with the NPC's kings AI in managing a country,
like changing cities, changing positions etc. the king should have his
own mind as well, sometimes player asks for change, sometimes he changes it
by his own willing, if not agree to obey, decrease loyalty or be fired.:P
sth like that.


---
作者: Ice
题目: >re: emperor
日期: Thu Jul 13 22:15:20 2000
On Mon Jul 10 17:38:24 2000 斯坦福(stefan) wrote post #1555:
> 实际上，这些消息里的水分蛮大的，人在江湖的确是在做分布集中式的 server
matrix，
> 不过不是这个人在江湖的游戏，而是他们的下一个项目。而且不是金智塔的项目。
> 万王之王是和 263 合作的，还有其它的几个 MUD 几乎都是砍砍杀杀
> 的 RPG 类，没有大前途，光他们自己之间竞争就很激烈了。真正做的好的现在可能
> 只有日本的石器时代和 Sony 的 Ever Quest，石已经是 20 台服务器同时跑了，不
过还
> 是
> 遇到很严重的瓶颈问题，目前已经在台湾香港运转，还没有到大陆来。
> 
> 基本上，国内游戏圈就这么大，稍微接触一下就都认识了 :)

我来荷兰之前看了一些杂志，上面有智冠的网络三国的消息，来了以后也去了
他们的网站，已经进入了倒数的测试期，（网站好象在cn.yahoo.com可以找到）
不过到此为止我的感觉是他们的游戏内容不够丰富，也可能因为没有接触过
游戏本身，所以只是臆测。
我在着手做图形三国的游戏框架企划，（不包括程序部分.:P）不过思绪太多，
需要好好整理才行.:)另外我不确定是否所有部分都要做一个详细的企划，
还是等大家把框架讨论定下来了才再往细致的方向讨论。


---
作者: Suicide
题目: >>昨天当机的时的出错信息
日期: Thu Jul 13 21:09:59 2000
agree with stefan .I also saw the disk wrong err last time.
pls change server quickly bah.
And i want to be the admin here for my seldom meeting fire here.
And i want to code to solve the guoshi question.


---
作者: 威少爷(suicide)
题目: To stefan
日期: Thu Jul 13 21:06:30 2000
Pls change the smtp address to this machine in /secure/daemons/smtp_d.c
I can't transfer news now lah..


---
作者: 烈火(fire)
题目: about the guo shi
日期: Thu Jul 13 20:59:20 2000
the reason to have guo shi is to give the npc country a chance
to survive if it got a very good guoshi. hoho :)
But seems this feature is misused. I will modify the system to make
it more fair. thank your suggestion, suicide. :)


---
作者: Fire
题目: >>post all lost?
日期: Thu Jul 13 20:56:49 2000
On Tue Jul 11 20:03:51 2000 Suicide wrote post #1558:
> Maybe still caused by the new_d .
> Fire change it back bah.It always lost new post when posts up to 200.
I will check the new_d, but I think the reason of lost news may be
caused by other reason.
because I have chnage the new_d a long time ago. and it doesn't
cause much trouble
the trouble only happened when other system error happened. so
anyway, I will double check my code :)


---
作者: Stefan
题目: >昨天当机的时的出错信息
日期: Thu Jul 13 20:29:45 2000
On Tue Jul 11 20:05:50 2000 黄帝(emperor) wrote post #1560:
> 昨天我在post后用"."结束编辑时，说没有权限appand留言
> 在/data/daemons/news.o文件里，同时其他玩家也在聊天
> 频道里贴出同样信息，还有所有设计到/data/目录下的保存
> 都出现错误，然后服务器就没任何信息发送过来了。重新
> 连接总站，只能连接，不能出现WELCOME信息。以后一直
> 是这样。是不是/data/目录在安全系统中的权限设置有问题？

The crash is due to a disk lost. I saw the message last
time , and when it appeared, the second disk of the machine
is lost. This error is not specifically related to news or 
our mud.

We are going to shift to another machine, and hope it
will solve the problem.


---
作者: 威少爷(suicide)
题目: TO emperor
日期: Tue Jul 11 21:00:09 2000
Emperor:
   Sorry!!!!!!!When i disconnect to phone i lost ur phone number which pasted 
in the notebook without save by mistakes. So i can't phone u that time.
When i connect here again try to find u ,but i failed.Sorry!!!!!!!!!!!!!!
                       suicide


---
作者: 威少爷(suicide)
题目: To fire:
日期: Tue Jul 11 20:12:30 2000
Fire :
  R u very busy these days?if u r free can u change the 国师制度 to 太守制度,
When restart all player 抢太守而不是抢国师,这样是不是好一点,能够消除
国师制度的弊端?
想法:
  1)所有玩家定居后当变成闲职后向国王申请做地方官员.
 2)当国贡地贡达到一定时,向向国王申请做太守.
 3)再到一定时可独立.
 4)这样玩家就算抢7,8个城也不算太有利,况且不能保证每个城相连.

我不知道大家是不是忙着搞新计划,但是我希望这个文字mud还是能正常运行,
解决国师制度吧.


---
作者: 黄帝(emperor)
题目: 昨天当机的时的出错信息
日期: Tue Jul 11 20:05:50 2000
昨天我在post后用"."结束编辑时，说没有权限appand留言
在/data/daemons/news.o文件里，同时其他玩家也在聊天
频道里贴出同样信息，还有所有设计到/data/目录下的保存
都出现错误，然后服务器就没任何信息发送过来了。重新
连接总站，只能连接，不能出现WELCOME信息。以后一直
是这样。是不是/data/目录在安全系统中的权限设置有问题？


---
作者: 黄帝(emperor)
题目: 昨天当机的时的出错信息
日期: Tue Jul 11 20:04:19 2000



---
作者: Suicide
题目: >post all lost?
日期: Tue Jul 11 20:03:51 2000
Maybe still caused by the new_d .
Fire change it back bah.It always lost new post when posts up to 200.


---
作者: 斯坦福(stefan)
题目: post all lost?
日期: Tue Jul 11 19:45:56 2000
What has happend to the old posts? 


---
作者: 烈火(fire)
题目: the server becomes more frigle
日期: Tue Jul 11 14:57:50 2000
Today, when I get to office, I find our MUD is down.
Then I login the Unix server and start the MUD and quit.
then I try to connect the game, I find it is still down.
so I log in the UNix again and start the mud and try to
connect. It seems ok. 
However, after about 5 mins, when I think everything is stable
I quit the Unix. However, at the same time the game is down without
any warning message. 
is it very strange. Should I keep connected to the Unix server
all the day. I don't know if the Unix will kick me out if I idle
for a whole day :)


---
作者: 斯坦福(stefan)
题目: re: emperor
日期: Mon Jul 10 17:38:24 2000
实际上，这些消息里的水分蛮大的，人在江湖的确是在做分布集中式的 server matrix，
不过不是这个人在江湖的游戏，而是他们的下一个项目。而且不是金智塔的项目。
万王之王是和 263 合作的，还有其它的几个 MUD 几乎都是砍砍杀杀
的 RPG 类，没有大前途，光他们自己之间竞争就很激烈了。真正做的好的现在可能
只有日本的石器时代和 Sony 的 Ever Quest，石已经是 20 台服务器同时跑了，不过还
是
遇到很严重的瓶颈问题，目前已经在台湾香港运转，还没有到大陆来。

基本上，国内游戏圈就这么大，稍微接触一下就都认识了 :)


---
作者: 斯坦福(stefan)
题目: server problem
日期: Mon Jul 10 17:31:24 2000
It seems that FreeBSD can not take heavy load on its Dual CPU
configuration. So it goes down very often :PP

Now one of the CPU is disabled, we will see how it works out.


---
作者: 烈火(fire)
题目: hi stefan
日期: Mon Jul 10 15:03:33 2000
some players complain this new server.
I am not sure what are the problems.
sigh.


---
作者: 烈火(fire)
题目: hi emperor
日期: Mon Jul 10 15:01:56 2000
where did you get all your news,
could you please post the URL of those news ?
thanks

fire


---
作者: 黄帝(emperor)
题目: 他们的速度真快
日期: Mon Jul 10 07:40:15 2000
           中文图形MUD《万王之王》免费赠送报名开始

　　《万王之王》为台湾知名全中文3D图形RPG大型网络游戏，可同时容纳
万人联机，在台湾有很好的游戏群体，为了推广这一优秀网络武侠游戏，
华彩软件决定开拓大陆市场，为酷爱网络游戏的玩家提供真正具有中国武侠
文化和3D界面的优秀作品。现在，面对中国大陆地区用户免费游戏光盘赠送
活动全面开始，前500名报名者都可获得免费邮寄的游戏光盘。 

　　报名网址： http://210.78.145.16/temp/ 




---
作者: 黄帝(emperor)
题目: 又一个在大陆发行的图形MUD
日期: Mon Jul 10 07:37:45 2000
            万王之王“King of Kings”隆重登场（2000.6.28)

　　业界第一个全中文图形MUD---万王之王“King of Kings”隆重登场了。
这款由游戏开发商雷爵资讯(Lager)、港台地区最大软件发行商--华彩软件
主推的图形MUD，27日在长城饭店举行了隆重的首发仪式。这款游戏由中国
人自行开发，将传统文字MUD转成动态的网络图形实景，是世界第一套全中
文3D图形RPG大型网络游戏，可同时容纳万人在线联机，让酷爱联机游戏的
你一下被它迷到死。万王之王强大的游戏功能，不仅支持数目庞大的万家联
机游戏，而且绚丽逼真的3D魔法效果更让你觉得这是一款传统RPG游戏。联
机进入游戏你就会置身于中古欧洲的魔幻世界里，由此可以看出这个游戏的
目标不仅是中国市场它的目标更看向了中国以外的世界其他地区。 

　　游戏以真实世界60倍的时间运行，日夜更替均有条不紊。自主的角色
安排，任由玩家随意设置扮演角色的造型，从性别、服装、发型、胡须……
到构建城邦王国的一草一木，完全可自行规划。领土扩张、载种树木、设镇
造乡、设定任务、研发武器、建立防御工事等，充分体现玩家的人个风格。
游戏中独特的城邦系统，满足玩家一步步辛苦建立个人王国的梦想。超过百
种以上的情绪指令，可真实表达玩家内心喜怒感受，从此面对的不再是冰冷
的计算机，而是父子、君臣、夫妇、兄弟、朋友，如同真实世界的人际互动。
每一个动作，每一个参与都充满情感，线上所有玩家的动作，都将在第一套
全中文万人联机“King of Kings万王之王”网络游戏的历史中留下痕迹，让
玩家们真实而丰富的互动，决定这个世界每一时刻的未来！ 

　　这一切是不是很让你激动？那还不快加入万王之王的虚拟世界！7月首
发平装版仅需19元，超低售价充分满足你对游戏的渴求！ 




---
作者: 黄帝(emperor)
题目: 消息
日期: Mon Jul 10 07:17:21 2000
           金智塔公司有奖征集图形MUD游戏策划案 

　　来自金智塔公司的消息：金智塔公司现在全面征集图形MUD游戏
《非常男女》的策划案。初步计划游戏为一款以现实的生活为基础。 
通过网络虚拟社会进行成长生活、恋爱工作等等虚拟现实的图形MUD 
游戏。 
一、奖品设定
第一名：奖金5000元 终身免费享有金智塔公司游戏产品赠送
第二名：奖金3000元 终身免费享有金智塔公司游戏产品赠送
第三名：奖金1000元 终身免费享有金智塔公司游戏产品赠送

二、基本要求
1.体现虚拟社会特点，构思新颖，题材丰富。
2.策划案条理清晰，思络明确，游戏性好。
3.突出游戏的主旨，中心思想突出，要有积极向上的意义。


        《非常男女》策划案征集活动圆满结束 


　　金智塔公司自7月初在网站上发布公开征集图形MUD《非常男女》
策划案的消息以来，在广大媒体的宣传和众多朋友的支持下，引起
了很大的社会反响。截止到10月31日，金智塔公司已经陆续收到了
近200篇应征策划稿，其中包括为数不少的来自港澳台以及国外朋友
的稿件。金智塔公司专门为此设置了征集活动评选小组，负责处理
《非常男女》策划案来稿的回复和稿件的初步筛选工作。 

　　经过征集活动评选小组的初步筛选，金智塔公司初步选出了20篇
比较优秀的图形MUD《非常男女》的策划稿，并将在明天公布这批入
选作品的名单。同时金智塔公司将在网站的回音壁栏目中每天公布
一篇入选作品，请广大的朋友来参与我们的评选活动，大众论坛也将
相应开辟专门的版块供大家来对这些作品进行评论发言。金智塔公司
会在所有20篇入选作品全部公布之后，在网站上开设专门的投票评选
栏，公开由所有玩家来对这些作品进行评选，最终决定产生3名入围
作品。 

　　金智塔公司将会邀请国内知名媒体和专家参与此次评选活动，并
对这次活动的公正性、公开性进行监督。同时金智塔公司也将从此次
参与评选活动的玩家中随机产生10名幸运玩家，终身免费享有金智塔
公司游戏产品的赠送。希望广大玩家踊跃参加我们《非常男女》策划
案的评选。 



---
作者: 黄帝(emperor)
题目: 金字塔公司的服务器模式很值得参考！
日期: Mon Jul 10 07:13:00 2000



---
作者: 黄帝(emperor)
题目: 又一个图形MUD
日期: Mon Jul 10 07:11:28 2000
        图文：国内首款3D图形MUD游戏《人在江湖》即将登台

　　2000年4月，深圳金智塔公司将正式发布开发两年之久的国内款3D图形
MUD游戏《人在江湖》。游戏的故事脚本贯穿着中国的传统武侠思想，玩家
将在其中扮演一名武林中人，并遭遇一系列的江湖事 件。所谓江湖豪杰满
腔热血，心存道义，一串令人唏嘘不已的遭遇，一段可歌可泣的故事， 要
谨记— —英雄泪，不轻弹！玩家是我行我素、浪迹天涯，还是开山立派、
扬我威望，一切的一切都任由自己 选择！在这些方面，《人在江湖》可说
是实现了全开放、高自由的游戏情节，所有的剧情都由玩家自 己演绎，这
便是MUD游戏的魅力所在。 

　　速度问题是所有玩家最关心的问题，而《人在江湖》采用了最新的网络
技术，便是将所有的图像声音文件安装在客户端，在客户端，常用指令采用
鼠标输入，对所有命令进行过滤传输，节约客户输入指令的时间。聊天时则
采用分主题的模式，将客户机转化为聊天服务器，由此减轻主服务器的网络
负担，在整体上提高了网络通讯速度。《人在江湖》还采用了分布集中式网
络服务系统，可在主服务 器上开设二、三级副服务器，并依此类推， 将所
有玩家的数据保存在主服务器上，玩家在线时数据通过副服务器传输，这样
同时在线人数便能增加，最多同时登录数可超过几万人！ 



---
作者: 黄帝(emperor)
题目: 又一个图形MUD
日期: Mon Jul 10 06:51:09 2000
        图文：盘古开拓新天地--《中国故事MUD》 


　　《中国故事MUD》是由盘古公司耗时数载开发的一款可通过INTERNET
联网，五千人同时进行的中文图形MUD游戏。 

　　游戏选取的是古代的中国为背景，游戏中的所有人物、建筑、物品全
为3D制作。大到气势恢宏紫禁城，小到桌上的茶壶、酒杯无不一一再现其
原来的面貌，将给玩家提供一个最好的游戏场景。游戏提供了数十种不同
类型与功能的建筑物，如：各种商店、官府、当铺、书院、武馆、易容店
等，玩家可以通过综合运用这些商店，实现各种复杂的玩法，大大的丰富
游戏的内容，玩家将在其中得到许多新的乐趣。 

　　在游戏中玩家可以从近20种职业中挑选一种自己喜欢的，其中有擅斗
的战士、灵敏的小偷、工匠，也有文弱的教师、商人、可怜的乞丐等，当
一个江湖郎中也行，甚至可以做一个清修的和尚。配合职业，提供了40多
种相关技能，当然技能的掌握是和你的职业有关的。游戏中的各种道具种
类有数千种，其中既有神兵利器，也有灵芝仙丹，还有各种生活用品，玩
家在游戏中会不断的有新发现。 

　　游戏中玩家需要吃东西来补充体力，玩家可从事各种职业来获得金钱，
用于发展事业、救世济民，或者养家糊口、娶妻生子。 

　　本游戏的另外一个特点，就是游戏所提供的近4万屏的地图， 涵盖中国
数十城市，一百多个村庄、岛屿、山洞，为玩家提供了一个巨大的游戏空间。
精致的全三维场景和对象，会让玩家身临其境。游戏中还设有 400个各种
类型的任务让玩家去完成，所有任务都可以用二种以上的方法完成，完全
根据玩家智能，如：到药谷寻灵药，无所顾忌的玩家可偷、可骗、可抢，
想当君子的可以以德服人，灵药自然会到手。 



---
作者: 威少爷(suicide)
题目: about nationmeeting
日期: Sun Aug  6 02:27:27 2000
引入太守制和国师制并存后,一国可能存在多派不合作的势力,如果对现在的国
家会议不做更改,
那么国师派会因为国家官员居多利用国家会议的nationtax和tran轻易搞垮敌
对的地方太守
但是对于怎么更改我现在都没想到简单易行的方法,希望大家帮我想象,多提建议:
1) 对于nationtax可以设定成只有本地太守可以提议,国师或国家官员都无权,
这也比较符合
   实际情况.
2) 对于tran,不只怎么办,大家帮帮忙拉!!!!!!


---
作者: 威少爷(suicide)
题目: /sgdomain/modules/m_board.c的第一次修改：
日期: Sat Aug  5 23:52:45 2000
1) 为配合太守制，增加本城机密、绝密的post方式。
2) @--表示本城机密，只有本城玩家可以阅读。
   @@-表示本城绝密，只有本城官员可以阅读。
3) @(本城机密)和*(本国机密)的符号不同时解释，
   post的第一个字符为@则理解为本城机密，随后出现的*认为是post内容，
   反之依然。
4) 由于这个部分在未重启前开放对系统无任何影响，我测试成功后已经开放，
   请大家检查测试。code要生效，需要update board所在房间。


---
作者: 斯坦福(stefan)
题目: complains about jimou
日期: Fri Jul 28 23:56:47 2000
【闲聊】苍凉(magi)：stefan你自己想吧，一个2人的部队被杀死2M是什么样的程序能写
出来的……
【闲聊】斯坦福(stefan)：有这样的事吗?
【闲聊】凉粉草对斯坦福点了点头。
【闲聊】凉粉草(cool)：基本水计
【闲聊】苍凉(magi)：多了
【闲聊】苍凉(magi)：jbsj neihong
【闲聊】苍凉(magi)：都是
【闲聊】苍凉(magi)：jbsj是记录保持者
【闲聊】凉粉草(cool)：部队越小，杀伤力越大
【闲聊】苍凉(magi)：二百万以前是四十万，上海站的记录
【闲聊】苍凉(magi)：二百万的记录是我创造的，我可以保证
【闲聊】苍凉(magi)：还有一万多，三千五千的都不在话下


---
作者: 斯坦福(stefan)
题目: to group (player's complain)
日期: Fri Jul 28 23:34:38 2000
to group (player's complain)
【闲聊】苍凉(magi)：上次我投诉说军师计不合理
【闲聊】苍凉(magi)：杀伤力太低
【闲聊】苍凉(magi)：拿武将计的fenfa做了一个比较
【闲聊】苍凉(magi)：结果他不去改它不合理的东西
【闲聊】苍凉(magi)：到直接把fenfa除了一个3
【闲聊】苍凉(magi)：或许是4
【闲聊】苍凉(magi)：这是干吗呢？
【闲聊】苍凉(magi)：是不是想告诉我们说：你不是说这个不合理吗？我就都给你不合理
看看！
【闲聊】阿绣(foxer)：最起码改动什么东西通知一下
【闲聊】苍凉(magi)：计谋的成功率也明显低了
【闲聊】阿绣(foxer)：一句话不说就瞎改
【闲聊】苍凉(magi)：可是我们也没证据
【闲聊】苍凉(magi)：他不承认我也没办法

hoho, so please take care of it :)


---
作者: Suicide
题目: >about guoshi
日期: Thu Jul 27 21:01:52 2000
好吧.我来做选举国师的 code,另外降skill的idea fire你同意的话,我也想象办法.
可以在restart_d中设置一个变量表示是三国的第几代,同时在角色的数据项中
也增加对应项.
当三国重启后,玩家一登陆,login.c就判断系统几代的值和玩家的是否一致,如果不一致
就降低玩家的技能,然后将玩家对应代数的参数设置称和 restart_d中一致即可.


---
作者: 烈火(fire)
题目: about guoshi
日期: Thu Jul 27 19:09:29 2000
没有国师，国王管理部份的功能全都没法用，同时群龙无首，
竞争多半会出于不利地位。
议会制度是一个大的设想，其结果如何目前还很难料定，但
其前景值得一试。


---
作者: Fire
题目: >how about lower players' lv
日期: Thu Jul 27 19:02:41 2000
On Wed Jul 26 22:35:13 2000 分钟(group) wrote post #1620:
> when re open, is that ok to lower the skills lv of the players. then
> we can say it is a begining.
> and i think this is a way to reduce the guoshi's problem

it has a little technique difficult.
because if a player don't on line, can't cut his
skills because it is stored in the body.


---
作者: Emperor
题目: >>关于国家官员，
日期: Thu Jul 27 04:21:24 2000
agree suicide,还是不用议会制的为好。


---
作者: Suicide
题目: >关于国家官员，
日期: Thu Jul 27 00:33:15 2000
我仔细思考了以下,觉得NPC国就是没有国师,各地区的太守只要同心协力,也不定
国家就会衰弱阿,我觉得一个国家是否会强大,不一定非要有国师阿.
不知道我理解的对不对.可以这么说,实行太,就算一个国家不推选出国师,只要几个
太守一独立不就可以任命国家官员了马.况且在一个国家当太守的各个玩家说
不定也不是一个战壕的,怎么能要求他们推选出国师呢?


---
作者: 分钟(group)
题目: how about lower players' lv
日期: Wed Jul 26 22:35:13 2000
when re open, is that ok to lower the skills lv of the players. then
we can say it is a begining.
and i think this is a way to reduce the guoshi's problem


---
作者: 烈火(fire)
题目: 关于进谗
日期: Wed Jul 26 22:04:24 2000
皇帝的设想不错，但我认为这只是一个有新意的JOB，完全依靠
它来解决国师问题是不可能的。但可以丰富我们的JOB系统同时
也解决一些平衡问题。如果皇帝有时间的话，可以把这个JOB做
一做。
addoil emperor


---
作者: 烈火(fire)
题目: 关于国家官员，
日期: Wed Jul 26 21:47:19 2000
因为国家官员可以自由地在本国内更换地区，我想还是等
有了国师后由国师来任免。如果一个NPC国没有国师，那
就各个地区自由为政，这样必然国家会衰弱，要想强大，
必须早日选出国师，这种设计也许会建立一个良性循环。
勤奋度的设计是很不错的。关于和NPC的亲密度，这个概念
虽然很好，但实现时要有仔细的设计。我们有600左右NPC
500左右玩家角色，如果每一之间都建立关系的话，数据量
是300，000。这在实现上不太现实。所以要设计关系度，一
定要有清晰的设计来决定涨，降和清除。


---
作者: 黄帝(emperor)
题目: 勤奋度的概念
日期: Tue Jul 25 22:16:41 2000
昨天晚上和suicide在电话里讨论了两个小时，我基本赞同
suicide的思路。
    suicide的勤奋度的概念适用于所有国家的玩家官员。
勤奋度除了用来太守、国师的选拔外，还用于对玩家上线情况
和工作情况的考察（这是针对超过二级以上官员和国家官员的）。
现在三国存在着光占着地方官员、国家官员和帝国官员的位置而既不
做工作又不上线的却又拿俸禄囤积黄金的不良现象。而引进勤奋度这个
指标，可以有效地防止以上现象的发生。如果一个玩家居于高位但不谋其职
的话，他的勤奋度自然会降下来，从而通过npcai_d来罢免其职位。也给
其他玩家一个申请高位的机会。
    另外suicide想引进三国志中“亲密度”这个概念。通过玩家与NPC之间
亲密度的关系来使自己得到大部分官员的拥戴而成为太守或国师。而亲密度
的增加通过做一些增加亲密度的JOB来实现。例如写信、拜访等，这些工作现在
三国里都有现成的，稍微修改一下就能满足亲密度增加的需要。


---
作者: 烈火(fire)
题目: stranges in post
日期: Mon Aug  7 16:03:46 2000
I find some strange bugs in post yesterday.
When I login i find i have 1 post not read in the wiz.com
but after I type news. it said no new post
I think it is this bug remove the news group of task.guosi

about npcai_d.c, I have a little suggestion.

I think itself should not have a call_out. It better
to use ai_d.c to trigger the npcai_d.c so our system
have a certer heart that is day_d and a single
thinking circle that is ai_d.c, 

I have copy the npcai_d.c to /daemons, so
suicide please change it trigger by ai_d.c
and I don't think that it need to be added in the preload
it can be started by ai_d as well. 

addoil suicide :0


---
作者: 玄冰(ice)
题目: 重新设定被灭国的惩罚的建议
日期: Mon Aug  7 05:54:41 2000
独立或称帝以后的种种灭国所带来的后果应该是不同的，建议如下：

1、独立后被武力灭国的国君：
   声望减少30%；
   金钱减少30%
   与该国关系降为1。
   （当以后发展了战争可以抓俘虏以后，坚持到最后不投降的君主可能会被
     抓获砍头，被砍头会减技能但是名节还在，投降就没有什么名节了，只
     能说是为了保身保命，声望将大幅下降。）

2、称帝后被武力灭国的国君：
   声望减少50%；
   金钱减少50%
   与该国关系降为1。

3、独立后禅让的国君：
   声望减少50%；
   金钱减少50%；
   成为该国闲职官员。
   （普通国家被禅让的玩家必须声望达到20000，帝国的则必须达到50000。）

4、独立后投降的国君：
   声望减少50%；
   与该国关系减半，但成为该国闲职官员；
   金钱减少50%。

5、称帝后投降的国君：
   声望减少80%；
   与该国关系减半，但成为该国闲职官员；
   金钱减少80%。

至于房子和装备，我认为应该不用进行剥夺，房子似乎不容易剥夺，而装备在
抓俘虏出现以后由战胜国处理，这些应该不联系到国家灭亡的问题。

提出这个建议的原因是zeda被灭国了，连结婚戒指都丢了，又不能定做，我在
扣了他双倍的金子之后给他加回去了，但是我觉得这样似乎不太合理，所以就
提出了以上建议。


---
作者: 玄冰(ice)
题目: 重新设定独立要求和形式的建议
日期: Mon Aug  7 05:18:07 2000
独立的条件从可以称王以来一直没有进行修改，而亡国或禅让、投降之后
的惩罚似乎也没有什么不同。同时独立的形式也并不那么理想，一如当年，
独立就要先练好一堆大米，独立之后还要斟酌那些与自己关系高的才能先
投奔过来，然后才能开始工作。建议的修改将并不能减少大米，只是可以
不必被迫使用大米来协助独立，举个例子来说，以现在的情况，如果我和
row是比较熟的，而且在同一个城市担任官员，而以现在的独立形式，我
独立之后row未必就可以协助我进行工作，只能找合适的大米先投奔了过
来才能开始。

在suicide已建立国师系统和效忠功能的前提下，建议作以下修改：

1、独立的要求：（必须满足所有条件）
   a.必须是当地真正太守；
   b.地区贡献为500*地区等级；
   c.声望为10000*地区等级；
   d.必须有3名或以上当地玩家官员效忠；
   e.该地区不能为一级地区；
   f.该地区安定必须超过150；
   g.该地区军队必须为1000*地区等级；
   h.该地区军队训练士气必须超过100；
   i.该地区金钱必须超过10000。
   （没有技能要求）

2、独立的形式：

由一名已宣誓效忠的当地非闲职官员向当地太守ask xxx about independent，
某人趋近某太守身边小声说道：如今天下大乱，君上不如就此揭竿，南面称王吧。

如果问的人不是当地官员，则太守回答：这不是阁下要操心的事吧。程序返回。
如果问的人是当地闲职官员，则回答：阁下是意图造反吗？此事万万不可。
如果被问的不是太守或当地真正太守，则回答：卑职/小人无权无势，何以称王呀。
如果被问的太守地区贡献不足，则回答：吾亦有此意，只恐怕此地民心不服。
如果被问的太守声望不足，则回答：吾亦有此意，可惜声威不足，难以服众呀。
如果被问的太守没有足够的当地官员效忠，则回答：吾亦有此意，可惜人手不足呀。
如果被问的太守所在为一级地区，则回答：此地难以发展，称王之事休要再提。
如果被问的太守安定不足，则回答：此地人心涣散，恐怕难以成事。
如果被问的太守军队不足，则回答：连举事的军队都不够，何以夺权呀。
如果被问的太守训练士气不足，则回答：此时军心不稳，官兵不勤，恐怕难以成事。
如果被问的太守地区金钱不足，则回答：没有足够的金钱，恐怕还成事不足。
如果被问的太守是已独立的玩家，则回答：你白痴呀，寡人已经南面而朝了，
来人哪。。。

如果被问的太守所有条件成立，则太守会对建议者使用emote "ok" ，并回答：
某太守拍案而起，沉声说道：好，此时不反，更待何时！
（其余沿用现有的gossip里的信息）

3、独立以后的变化：

a.独立的国君声望加倍；
b.宣誓效忠的当地官员成为当地闲职；
c.宣誓效忠的当地官员忠诚加倍（在系统随机产生的与新国家的关系度的基础上）
d.宣誓效忠的当地官员声望增加20%；
e.当地军队士气上升50；
f.所有NPC官员回到原国家任意地区任闲职；
g.当地的金钱减少10000；（独立时花费用的）
h.该国国君与效忠的官员与原国家的关系降为1。



---
作者: 威少爷(suicide)
题目: about nationmeeting
日期: Mon Aug  7 03:09:33 2000
/daemons/nation_channel_d/nationtax.c的第一次修改:
1) 只有本城太守才能提议调整本城税率
/daemons/nation_channel_d/tran.c的第一次修改:
1) 满足以下三个条件中的一个，调动提议才可讨论：
   a)建议人和被调动地区太守为同一人。
   b)被调动地区太守效忠建议人。
   c)被调动地区太守和建议人效忠同一人。


---
作者: 威少爷(suicide)
题目: To fire
日期: Mon Aug  7 02:14:39 2000
fire :
   由于现在magi已经统一了,我可不可以install所有的程序到正常系统并开放,
在重启前的时间内供大家测试如何?请尽快给我答复.
                                 suicide


---
作者: 威少爷(suicide)
题目: 最近的修改
日期: Mon Aug  7 02:12:35 2000
/daemons/char_d.c的第一次修改:
1) 修改get_char的函数，当角色没有效忠信息时返回不是0，而是角色自己的id，
   目的是为了防止出现当两个角色都没有宣誓效忠信息时，如果比较两者的效忠
   信息，因为get_char的返回值都是0， 而带来结果是一致的情况。
/sgdomain/cmd/fealty.c的第二次修改：
1) cmd fealty 用于察看自己效忠情况
   cmd fealty none用于撤销效忠
   cmd fealty <id>用于宣誓效忠，效忠的对象必须是本国的国师或国王。防止玩家
   临时宣誓效忠反对派太守来达到调动对方物质军队的目的


---
作者: 玄冰(ice)
题目: about history
日期: Mon Aug  7 02:07:42 2000
stefan found out that the new id login makes the system lag may
be caused by the too long history for a new player, I think it's not
so necessary to set all history while a player login, bcoz if he
didn't login for a period of time, there may be a long history flooding
the screen thus he might omit some important msg in the beginning like
"u have been failed to login x times" or "u have got mail" sth.

I suggest to make the normal history to another board.:P
(sg is coming to have more and more boards), the only thing left is
then progress board has news, remind a player to go read progress board.
so that player can concentrate on important msgs after login, and if he
is interested to see the history, check the board out.
it'll also ignore the cause of new id login make system lag.:)


---
作者: 威少爷(suicide)
题目: about progress
日期: Sun Aug  6 20:15:42 2000
等我完成nationmeeting的部分应该就可以重启了,
另外fire请把/wiz/suicide/npcai_d.c转移至/daemons并且加入到preload中(
准备重启前)
我将在两天内完成nationmeeting的code.


---
作者: 威少爷(suicide)
题目: 对于/daemons/restart_d.c的修改
日期: Sun Aug  6 20:10:40 2000
增加初始化地区时,系统自动挑选NPC地区太守


---
作者: 玄冰(ice)
题目: national meeting
日期: Sun Aug  6 19:42:14 2000
well, task.guoshi is gone, i have to post here.:P
suicide asked me about the comment of national meeting after
the new guoshi system is done.  I think to enhance the leader
's power who didn't cmd fealty to the guoshi, we can make national
meeting that if transferring sth from the area which is not fealty
to the guoshi, the leader will have 3 votes in natinoal meeting,
or can make a 1 vote objection of the leader, if he dun agree,
nothing can be transferred from his area.  but so there need to make
sth in pos.c, to let the taishou make his vote always positive to the
nation's decision or negative. that's my idea.

btw, players r eagerly willing to have a restart these days, will suicide
announce ur progress so that admin can all a restart.:)
addoil


---
作者: 玄冰(ice)
题目: call log
日期: Sun Aug  6 18:33:12 2000
with fire's expectation, i added 2 wxxy lv for jianran for his bug report.


---
作者: 威少爷(suicide)
题目: /daemons/ai_d.c的第一次修改
日期: Sun Aug  6 18:02:55 2000
1) 注释掉原来的系统自动挑选国师的code.即不再调用/ev_npccountry.c


---
作者: 威少爷(suicide)
题目: TO fire 
日期: Sun Aug  6 18:01:41 2000
Fire :
   It is so strange that the newsgroup of task.guoshi is disappear,why?
Is it a bug?


---
作者: 威少爷(suicide)
题目: To ice
日期: Mon Aug  7 18:00:35 2000
Ur post about ind , i will do it as quickly as i can.
Thx for ur post.


---
作者: Suicide
题目: >stranges in post
日期: Mon Aug  7 17:48:29 2000
Why i add call_out in npcai_d directly is because I am afraid of
error of "evaluation too long" caused by call 嵌套的 function in
diffrent files.


---
作者: 烈火(fire)
题目: to suicide
日期: Mon Aug  7 16:05:14 2000
when will you finish your nation meeting ?
How about we restart at this weekend ?


---
作者: Ice
题目: >>>RE : ice's post about 独立和灭国  
日期: Thu Aug 10 03:30:46 2000
well, that's fine, i m not asking to do it now, but just starting
to ignore some option of lv 1 area, so that later we dun have to adjust
many codes if we make up our mind to change lv 1 area to just-war area.


---
作者: 威少爷(suicide)
题目: To stefan
日期: Thu Aug 10 01:44:14 2000
stefan :
    fhxy提到的现在shutdown后有一些bug 出现，我在重庆站reboot时也碰到了，当时是
无法pos 和ask postion ，我于是在重庆站update这几个对应的文件pos.c 和ev_postion
发现无法update成功包错，好像是文件corrupt 了，我后来重新reboot更新程序好几次都
没有成功，最后还是从zj mirror ftp 了这几个文件才行，你能帮我检查一下是什么原因
吗？如果是传输中数据误码也不会我每次reboot更新都无法恢复正常啊。而且我发现我们
的code 的.c 文件才加密，而我们在总站的.c文件的备份文件传到分站后可以直接看到源
码，是不是在我们的加密设定中就是这样定义的，防止数据文件在分站加密后无法使用？
    另外关闭计谋的提议我赞成ice 和你的意见，不能随意停止，不然玩家意见大了，我
看还是另想对策吧。


---
作者: 威少爷(suicide)
题目: Who can adjust war map
日期: Wed Aug  9 22:27:18 2000
1  每个关口都有天险,易守难攻,这样关口地区才有其存在的意义.
2 不是关口的地区应该尽量没有天险,最多城墙厚一点,大一点吗.


---
作者: 威少爷(suicide)
题目: To fire
日期: Wed Aug  9 21:18:44 2000
Fire :
   我想找我一个同学来加入我们的巫师小组,参加程序开发,你看可以吗?
如果可以,我就开始联系,这样可以加大我们的开发力量.
  而且可以信任,不用怕有些东西泄密,你看啦?


---
作者: Suicide
题目: >>RE : ice's post about 独立和灭国  
日期: Wed Aug  9 21:16:30 2000
Ice :
  关于lvl 1地区的问题,我暂时搁置的原因是因为解决它需要涉及的code很多很复杂,
其实我是很同意你的想法.
  现在我还在考虑在关口做太守的玩家怎么获得粮食来养军队,难啊.
 这个问题我们暂时搁置好不好?


---
作者: Suicide
题目: >about vote xxx close/open
日期: Wed Aug  9 20:54:50 2000
不如这样吧,我把系统设定成一个IP只能登陆4个角色.
(我想利用网吧或代理同时上线的玩家应该不超过4个把


---
作者: 玄冰(ice)
题目: about vote xxx close/open
日期: Wed Aug  9 16:43:17 2000
can we add a same IP limitation of vote, if sb choose to vote sth,
check if this ip has voted about the same thing or not, if this IP
has voted, then any other id from the same IP cannot vote for the
same thing any more.  I dun like to watching those guys playing jokes
in this way anyway.  how do u guys think about it?


---
作者: Ice
题目: >RE : ice's post about 独立和灭国  
日期: Wed Aug  9 14:43:45 2000
1、独立的要求：（必须满足所有条件）
   a.必须是当地真正太守；                
     同意，但是我想如果暂代太守也可以独立的话，是不是更有趣？这说明真正
     的太守用人不当啊，活该。
well, i dun have objection of that.:P up to u.

   e.该地区不能为一级地区；
     暂时不同意，因为如果这里的太守不能独立，而他又不愿依附国师，岂不是永
     无出头之日？在我们给他设计个出路前就让他也可以独立吧，只不过灭国后加
     大损失，他就不敢随便独立了。
no, in my mind, the lv 1 area is not a city at all. lv 1 area should NOT
have population, bcoz it's only somewhere for war/defence only, holding
it is to protect the major cities beside or, some important geographic
location. that's y i also suggest to remove lv 1 area from the fate table.
lv 1 area is mostly working for war, not for manage. lv 1 area should not
have production, it should be just a dead area, must need somewhere else
like big cities beside to support it's troops there. so i still insist it
should not be included in the ind-able list.:P
     
   i.该地区金钱必须超过10000。
     同意，但是不是也改成3000*地区等级更好?
that's fine, money is not a big deal, up to u.
     
3、独立以后的变化：
   a.独立的国君声望加倍；
     同意，但是被灭国后是不是应该声望至少奖60%，不然就算独立后再灭国，声望
     仍然比独立前高。
so change to after ind, add 50%, if ruined, decrease 50%, it must be lower.:P
     
   c.宣誓效忠的当地官员忠诚加倍（在系统随机产生的与新国家的关系度的基础上）
     同意，但是在系统随机产生的与新国家的关系度的基础上这个涉及的东东太多，
     不知是否可以改成60+random(40)?
no objection.
     
   f.所有NPC官员回到原国家任意地区任闲职；
     同意，但是好得给新国家留几个吧，是不是可以和现在一样，国家官员回去，
     其他的random(2)留下做隐居贤人。
i have no idea about the current mode, just think that there may be some
technique difficulties for making it random stay in the new nation. but if
u think it's possible, just make it by ur mind.
   
   g.当地的金钱减少10000；（独立时花费用的）
     同意，少3000*地区级别
no objection.
     
独立或称帝以后的种种灭国所带来的后果应该是不同的，建议如下：
(现在玩家立国再投降被灭，都有点儿戏，我认为对灭国的国王应该从严处罚，辅助
 玩家则不需太严)
 
1、独立后被武力灭国的国君：
   声望减少30%；       我认为应该>50%,起码是70%
   金钱减少30%         我认为应该>50%,起码是70%
   与该国关系降为1。
   
2、称帝后被武力灭国的国君：
   声望减少50%；       我认为应该>50%,但因为能成帝说明付出很多，所以保持50%
   金钱减少50%         恢复到独立前，不知道成帝会不会声望加倍，不然应该多砍点
   与该国关系降为1。

3、独立后禅让的国君：
   声望减少50%；       同意
   金钱减少50%；       同意
   成为该国闲职官员。
   （普通国家被禅让的玩家必须声望达到20000，帝国的则必须达到50000。）

4、独立后投降的国君：
   声望减少50%；       我认为应该>50%,起码是70%
   金钱减少50%。       我认为应该>50%,起码是70%

5、称帝后投降的国君：
   声望减少80%；       同意
   金钱减少80%。       同意

about the penalties, it's up to u.:) that's it.


---
作者: 威少爷(suicide)
题目: apply for a test.
日期: Wed Aug  9 01:48:53 2000
So busy these days, and my brain is always in a confusion condition.
So i will have a rest and finished the 亡国惩罚.


---
作者: Stefan
题目: >Still about heart beat
日期: Tue Aug  8 21:23:27 2000
On Tue Aug  8 20:00:51 2000 威少爷(suicide) wrote post #1666:
> 虽然heart_beat每 tick被调用一次,但因为它是由mudos直接调用所以我认为
> 使用它比现在使用的age_beat要好,因为实际上过多的call out由系统调度对
> 系统性能的损耗更大,不知stefan,fire意下如何?向ES2 mudlib构架下的
> mud都是直接用的hear_beat,kk的系统同时有几百人都没有问题.
call_out is also invoked by mudos directly, it is not an issue.
I believe heart_beat is disabled for good reasons, mostly because
wizs tend to produce 'lazy' code when heart_beat is around :)

KK is a different thing, nobody looked at their code, not sure
if any hack was there to make MUDOS stable.

To support a few hundred people is not a problem for lima
either, just that time_consuming things should be carefully
avoided, or arranged to happen pbit by bit.


---
作者: 威少爷(suicide)
题目: Still about heart beat
日期: Tue Aug  8 20:00:51 2000
虽然heart_beat每 tick被调用一次,但因为它是由mudos直接调用所以我认为
使用它比现在使用的age_beat要好,因为实际上过多的call out由系统调度对
系统性能的损耗更大,不知stefan,fire意下如何?向ES2 mudlib构架下的
mud都是直接用的hear_beat,kk的系统同时有几百人都没有问题.


---
作者: 威少爷(suicide)
题目: npcai_d's callout has been modified
日期: Tue Aug  8 19:55:53 2000
I have used ai_d to call npcai_d->act() at hour 3 per day 


---
作者: 烈火(fire)
题目: modification in history_d
日期: Tue Aug  8 16:55:02 2000
I move all the histroy data older than 4 weeks
into another mapping oldhistory, so when a player
come in he will auto read the history no more than
4 weeks. This will solve the problem of lag
when a new player register. But for the old
his data, we haven't have an interface to read them.
Anyway, they are kept. when we find a good solution
to display them, it is on the way.
addoil :)



---
作者: 烈火(fire)
题目: 题目:  RE : ice's post about 独立和灭国  
日期: Tue Aug  8 16:24:08 2000
The design is not bad. The problem in old system
is all of these are seperated in many files
so quite hard to balance. So if we apply the
new system. put them all in one file and disable
some of the old code. If we need adjustment, we know
where to find it out.


---
作者: 烈火(fire)
题目: about call_out
日期: Tue Aug  8 16:22:04 2000

call_out will not be handle separately by the system.
so will not cause too long parse problem even called from
another program. ai_d has been carefully designed, should
not have this kind of problem.


---
作者: 玄冰(ice)
题目: system unusual lag
日期: Tue Aug  8 14:49:40 2000
当地时间                二千年八月八日下午二时四十七分
I checked cpu usage, it's pretty low as 2.33%, and there is not unusual
msg appeared in system channel or bug, it's just lag for all players
as well. stefan pls check what's happened? or there is sb trying to attack
or hack sg again...

ps. to suicide, i'll give u a response of ind post later.


---
作者: 威少爷(suicide)
题目: RE : ice's post about 独立和灭国  
日期: Tue Aug  8 07:15:47 2000
Ice :
    对于你的独立和灭国的post我仔细的思考后，有以下一些想法和你,fire讨论讨论：
1、独立的要求：（必须满足所有条件）
   a.必须是当地真正太守；                
     同意，但是我想如果暂代太守也可以独立的话，是不是更有趣？这说明真正
     的太守用人不当啊，活该。
     
   b.地区贡献为500*地区等级；
     同意
     
   c.声望为10000*地区等级；
     同意
     
   d.必须有3名或以上当地玩家官员效忠；
     同意
     
   e.该地区不能为一级地区；
     暂时不同意，因为如果这里的太守不能独立，而他又不愿依附国师，岂不是永
     无出头之日？在我们给他设计个出路前就让他也可以独立吧，只不过灭国后加
     大损失，他就不敢随便独立了。
     
   f.该地区安定必须超过150；
     同意
     
   g.该地区军队必须为1000*地区等级；
     同意
     
   h.该地区军队训练士气必须超过100；
     同意
     
   i.该地区金钱必须超过10000。
     同意，但是不是也改成3000*地区等级更好?
     
3、独立以后的变化：
   a.独立的国君声望加倍；
     同意，但是被灭国后是不是应该声望至少奖60%，不然就算独立后再灭国，声望
     仍然比独立前高。
   
   b.宣誓效忠的当地官员成为当地闲职；
     同意
     
   c.宣誓效忠的当地官员忠诚加倍（在系统随机产生的与新国家的关系度的基础上）
     同意，但是在系统随机产生的与新国家的关系度的基础上这个涉及的东东太多，
     不知是否可以改成60+random(40)?
     同意
     
   d.宣誓效忠的当地官员声望增加20%；
     同意
     
   e.当地军队士气上升50；
     同意
     
   f.所有NPC官员回到原国家任意地区任闲职；
     同意，但是好得给新国家留几个吧，是不是可以和现在一样，国家官员回去，
     其他的random(2)留下做隐居贤人。
   
   g.当地的金钱减少10000；（独立时花费用的）
     同意，少3000*地区级别
     
   h.该国国君与效忠的官员与原国家的关系降为1。
     同意
     
独立或称帝以后的种种灭国所带来的后果应该是不同的，建议如下：
(现在玩家立国再投降被灭，都有点儿戏，我认为对灭国的国王应该从严处罚，辅助
 玩家则不需太严)
 
1、独立后被武力灭国的国君：
   声望减少30%；       我认为应该>50%,起码是70%
   金钱减少30%         我认为应该>50%,起码是70%
   与该国关系降为1。
   
2、称帝后被武力灭国的国君：
   声望减少50%；       我认为应该>50%,但因为能成帝说明付出很多，所以保持50%
   金钱减少50%         恢复到独立前，不知道成帝会不会声望加倍，不然应该多砍点
   与该国关系降为1。
3、独立后禅让的国君：
   声望减少50%；       同意
   金钱减少50%；       同意
   成为该国闲职官员。
   （普通国家被禅让的玩家必须声望达到20000，帝国的则必须达到50000。）
4、独立后投降的国君：
   声望减少50%；       我认为应该>50%,起码是70%
   金钱减少50%。       我认为应该>50%,起码是70%
5、称帝后投降的国君：
   声望减少80%；       同意
   金钱减少80%。       同意
至于房子和装备，我认为应该不用进行剥夺，房子似乎不容易剥夺，而装备在
抓俘虏出现以后由战胜国处理，这些应该不联系到国家灭亡的问题。
同意.
Fire and ice ,consider about my opinion bah, if u all agree i will do this.
   


---
作者: Suicide
题目: >>>a little bug
日期: Tue Aug  8 07:15:09 2000
Have fixed lah but set loyalty to 80 when auto select taishou by system


---
作者: Ice
题目: >>a little bug
日期: Tue Aug  8 06:37:33 2000
hmm, i think if he is leader, he cannot cmd leave any time, so maybe
need a restriction to let system know when a NPC leader's loyalty
is lower than some certain level, NPC king will get another new taishou
and also if there is guoshi and player king, he'll receive a msg that
leader is having low loyalty. however, I think leader should be forced
not able to cmd leave, i remember the cmd leave for player has limited
this way, dunno if it's changed or not.


---
作者: Ice
题目: >>about ranks
日期: Tue Aug  8 06:33:31 2000
must be officer in order to be listed in rank? hmm, in my mind,
the target of playing this game is not only being a good officer
or a king, being xianren can still have many things or objective to 
achieve.:P so maybe change it to not necessary to be officer?


---
作者: Suicide
题目: >a little bug
日期: Tue Aug  8 06:11:58 2000
It is caused by the NPC taishou's low loyalty,So i modified /daemons/area_d.c
/head.c . When system auto head to select NPC atishou  ,the NPC
taishou's loyalty
will inc to 80.
Then Npc taishou who is auto selected will not be cmd leave frequently.


---
作者: 威少爷(suicide)
题目: To fire
日期: Tue Aug  8 06:03:48 2000
How many ticks = 16min(1 day in mud) ah???
Is is 240?


---
作者: Suicide
题目: >about ranks
日期: Tue Aug  8 05:57:14 2000
rob was not an officer when the rank was generated.
This is the result that he wasn't in rank.
hoho


---
作者: 玄冰(ice)
题目: about ranks
日期: Tue Aug  8 03:48:52 2000
i read the most recent ranks, but surprised to find that rob
was not in any rank list, though he is 88 yrs old, he's not in the
oldest players' list.:P and none of other lists included him.
suicide pls spare some find to find out why?
rob was not an officer when the rank was generated.


---
作者: 玄冰(ice)
题目: a little bug
日期: Tue Aug  8 03:39:54 2000
NPC taishou of bailangshan cmd leave by himself.:P  i think it's
supposed not to happen, bcoz if a taishou cmd leave, and the system
doesn't come to that area to check, players in that area cannot do
any job.
btw, i added another NPC taishou for bailangshan.


---
作者: 威少爷(suicide)
题目: To fire
日期: Tue Aug  8 01:33:12 2000
Fire:
   For flee and group all devote in project of GIME,can we hire some new wiz?
How about starrock's apply?


---
作者: 威少爷(suicide)
题目: about 勤奋度
日期: Tue Aug  8 01:28:30 2000
由于train,等一些meeting的工作不属于ev_job中的job,所以用我以前修改ev_job.c
在reward奖点前增加勤奋度,那么不停train的玩家就无法张勤奋度,所以我现在改成
在/char_d/localcontribution.c中当玩家增加地区贡献,且地区贡献大于等于3时,涨一点
勤奋度.但是visitpeople类的job好像reward的设置有点不对,玩家如果找到guy,什么都
不选,只选10退出,回去交差就能得到6点地贡,而一半其他一些job全部完成却
只有3点地贡,
好像有点不平衡吧,可不可以调整以下?


---
作者: Suicide
题目: >small bug...
日期: Tue Aug  8 01:15:30 2000
I will adjuest when i am free.
Thx row.
:)


---
作者: 阿洛(row)
题目: small bug...
日期: Mon Aug  7 22:52:56 2000
when i ask gongsun zan about position, gongsun zan answers:
公孙瓒对你说：让我先考虑考虑。
  代号      官职
公孙瓒对你道：你考虑妥当了吗？想好了就请输入 answer <代号> to gongsun zan

i guess i dont meet the requirement of the next position, so the code and the
name of the position wont be shown. well, for such situation, a sentence
as: 阁下尚未达到下一官职要求，请继续努力。 will not cause confusion.
am i right?


---
作者: Ice
题目: >stranges in post
日期: Mon Aug  7 22:19:51 2000
i met that bug often, is it fixed?


---
作者: 威少爷(suicide)
题目: To fire
日期: Mon Aug  7 18:02:05 2000
I have install all code into system,u can check and debug lah...
I haven't modify the call_out of npcai_d.c for those error maybe caused.
But if u confirm that will not happen i will modified it.


---
作者: Ice
题目: >>about vote xxx close/open
日期: Thu Aug 10 03:33:32 2000
hmm, b4 I didn't agree to this idea much... but, now i think it's
fine to deal in this way.  since i dun want to see sb login 12 ids
to run robot while there r 20 players online including me.:P


---
作者: 烈火(fire)
题目: limitation of login number from 1 ip
日期: Thu Aug 10 22:13:26 2000
the way to avoid multi login by ip is not a
realiable way. so should avoid this kind of limitation
until it is ergent


---
作者: 威少爷(suicide)
题目: guoshi info 
日期: Thu Aug 10 21:14:20 2000
I have fixed guoshi info when he cmd leave or inf.
or ind.pls check bah...


---
作者: Suicide
题目: >how about restart tomorrow
日期: Thu Aug 10 19:34:47 2000
Ok,restart tomorrow.
I will try my best to be online tomorrow,and when u will restart?


---
作者: Suicide
题目: >re suicide
日期: Thu Aug 10 19:34:01 2000
1  limit only 4 char can login from 1 IP is to void run too many
robot by one people.
2 ABout new wiz i will contact with him.


---
作者: 烈火(fire)
题目: how about restart tomorrow
日期: Thu Aug 10 16:49:17 2000
suicide, is that ok ?


---
作者: 烈火(fire)
题目: re suicide
日期: Thu Aug 10 16:48:39 2000
>不如这样吧,我把系统设定成一个IP只能登陆4个角色.
>(我想利用网吧或代理同时上线的玩家应该不超过4个把
I think this is a big issue. I think maybe
limit the vote right for each ip is better.

>   我想找我一个同学来加入我们的巫师小组,参加程序开发,你看可以吗?
>如果可以,我就开始联系,这样可以加大我们的开发力量.
That's good, so you can ask him to login and try to contact me
or other wiz members when we are online, so we can have a chance
to know each first :). If he can get 1 other wiz's recommandation,
then we can discuss his application.



---
作者: Ice
题目: >>about guoshi's requirement
日期: Thu Aug 10 14:21:31 2000
你向公孙瓒打听关于<guoshi>的消息。;公孙瓒对你怒道：这么重要的国家大
事，凭你的身份还插不上嘴，叫你们太守亲自来吧。
liyu is xianzhi, so cannot ask for guoshi? faint...


---
作者: Ice
题目: >>about cmd fealty
日期: Thu Aug 10 14:20:19 2000
no, just add it. u may not see it when u r online, unless u r 24 hrs
online.:P so just add it, or make it like the chat rules, cannot repeat
in 10 secs.


---
作者: 威少爷(suicide)
题目: To ice
日期: Thu Aug 10 07:19:43 2000
If u want liyu to be guoshi u must let him to be taishou first
and ask gongsun zan about guoshi to open vote.


---
作者: Suicide
题目: >about guoshi's requirement
日期: Thu Aug 10 07:17:49 2000
Now is 4k now ,not 10k lah....
Have u use liyu to ask king about guoshi????


---
作者: Suicide
题目: >about cmd fealty
日期: Thu Aug 10 07:16:57 2000
Let's check it if it just appear i will add time limit.
:)


---
作者: 玄冰(ice)
题目: about cmd fealty
日期: Thu Aug 10 05:27:49 2000
there should be a busy time or cannot cmd fealty in a certain time,
otherwise will make flood in rumor.


---
作者: 玄冰(ice)
题目: about guoshi's requirement
日期: Thu Aug 10 05:05:53 2000
maybe the nc requirement is too high, it's hard for a player to work
till 10k nc to gain guoshi, maybe u should lower it to 2k or so will be
more suitable. btw, i called liyu's nc and rep, so that it might be possible
to make him the guoshi when system check xiangping, then let's see if there is
still some other bug, if there isn't obvious bug, let's restart
these 2 days bah.


---
作者: Suicide
题目: >Help,
日期: Fri Aug 11 00:41:24 2000
In our mud ,We can convert BIG5<-->GB code ah...
Can u check it ,实际上只是个字符对照表的问题


---
作者: 烈火(fire)
题目: Help,
日期: Thu Aug 10 23:47:40 2000

Anyone know how to thans big5 code to unicode and gb code?
Please Help.

Regards,




---
作者: 烈火(fire)
题目: Welcome dreamfly.
日期: Thu Aug 10 23:44:44 2000

We have a very strict process for promoting a new wizard.
But because both Stefan and I are pretty busy this moment,
and this new member is a close friend of suicide, I promote
him without asking his application and voting in our wiz
committee. However, I think we still need dreamfly to give
some introduction of himself and give a plan for what he
like to do and may contribute to this mud within two weeks.

Addoil :)


---
作者: Row
题目: >welcome new wiz dreamfly
日期: Thu Aug 10 22:29:48 2000
welcome


---
作者: 威少爷(suicide)
题目: welcome new wiz dreamfly
日期: Thu Aug 10 22:22:22 2000
He is my best friend and classmate.
大家多多照顾!


---
作者: 玄冰(ice)
题目: about my post 4650 in caolu
日期: Sat Aug 12 19:12:06 2000
@CHAR_D->set_char("taishou id","grant",0)

this cmd will fix that. it's bcoz the current NPC leader r exactly
the same as b4 restart, and restart didn't remove the grant data.


---
作者: Suicide
题目: >about lower the speed of unify
日期: Sat Aug 12 18:41:24 2000
Is that "about fhxy's mail"?
I have transfered it to my email ,but i haven't read it for less time.
I will read and consider it tomorrow,then reply ur post,hoho
I will read and consider it tomorrow,then reply ur post,hoho


---
作者: 玄冰(ice)
题目: about lower the speed of unify
日期: Sat Aug 12 18:11:02 2000
any one read my post in task.war? do some change or not? or
any comment? or just simply cannot find that post? if so, i'll
post it here. and pls fix the bug in task group first bah.:P


---
作者: 玄冰(ice)
题目: about restart
日期: Sat Aug 12 18:10:04 2000
after restart, all bn in all area is not cleaned, so that the
blacklist in all cities remain the same as last generation.
better fix it now, hoho.


---
作者: 分钟(group)
题目: chinese name
日期: Fri Aug 11 12:07:50 2000
today there is a player login with a extremly long name
hmm... is there a limit for the length of chinese name?
if dont have, better add a limit ba


---
作者: 玄冰(ice)
题目: about task group
日期: Fri Aug 11 07:45:39 2000
faint, i wrote a post on task.war, but seems no one have read
it, after i finish that post, i cannot found there is any news
as well, fire check the task group again? addoil


---
作者: 玄冰(ice)
题目: about multilog
日期: Fri Aug 11 07:38:31 2000
since not many of us wanna limit the login of same IP, so sb make
vote for the same thing every IP has only 1 vote bah, it's not a big
issue leh bah.:P
addoil


---
作者: 玄冰(ice)
题目: help of new system
日期: Fri Aug 11 06:37:23 2000
though there is a post in progress, I think we still need a help
to let others check when necessary, suicide make it bah


---
作者: Ice
题目: >welcome dreamfly
日期: Fri Aug 11 06:31:25 2000
welcome dreamfly, i think u need some time to know this game first,
i suggest u to read some of the players' help, to have a brief idea of
this game, then if u still have some questions, try ask me if i m online,
i'll show u what i know.:P


---
作者: Ice
题目: >about 国师独立
日期: Fri Aug 11 06:28:49 2000
1. this idea is interested.
2. can give the taishou a choice, like when he is login after that guoshi
beep
is ind, he will be informed to make a choice, then after the system check
the city, if the taishou didn't login for a long long time, thus he won't
choose y/n to follow guoshi's ind or not, make it nothing happen, he'll still
belong to the old king.
3. answers of 2.

another question, no one can ind in NPC's capital, that's for sure,
that's y i need u to make guoshi cannot transfer king to anyother area,
and also change capital is not possible unless there is a comparable status
of the old city and the new city. but for now, just make it not able to change
capital and trans king for guoshi, so that no one can ind in capital.


---
作者: 分钟(group)
题目: welcome dreamfly
日期: Fri Aug 11 03:59:29 2000
welcome ^^ 
welcome ^^ 

recently quite busy in reading code...*_^
if no special things happen, i should be able to finish the code for 
npc auto cast

regards
group


---
作者: Stefan
题目: >Help,
日期: Fri Aug 11 01:03:26 2000
On Thu Aug 10 23:47:40 2000 烈火(fire) wrote post #1697:
> Anyone know how to thans big5 code to unicode and gb code?
> Please Help.
> 
> Regards,
> 
> 
ftp.cuhk.hk
in ifcss/software directory you can find quite a lot of
chinese software. A unix package called "utf7" actually
does translation between unicode, utf7, utf8 and gb, big5.


---
作者: Stefan
题目: >limitation of login number from 1 ip
日期: Fri Aug 11 01:01:40 2000
On Thu Aug 10 22:13:26 2000 烈火(fire) wrote post #1693:
> the way to avoid multi login by ip is not a
> realiable way. so should avoid this kind of limitation
> until it is ergent

agree. from NUS all have same IP , and probably > 10 :P


---
作者: 威少爷(suicide)
题目: about 国师独立
日期: Fri Aug 11 00:41:46 2000
国师独立的几种方式:
   1 一旦国师独立,那么所有fealty他的太守的地区都脱离原NPC国王转为他的地盘.
   2 只有国师自己掌握的地区独立,其他太守的城都归属于NPC国王.
   3 开始只有国师自己掌握的地区独立,但是fealty他的太守可以选择是响应倒戈
     还是效忠原来的国王?
   
   还有一个问题,就是国王所在的那个城怎么处理,因为国王在玩家无法独立.
   
   请大家提提意见,ok?


---
作者: 分钟(group)
题目: about auto cast
日期: Mon Aug 14 01:30:19 2000
i just finished auto cast code, it seems working well on my 
computer, but not sure whether it is good enough or not.

in every 7 minutes, system will random choose a NPC troop,
can then random choose a jimou for cast.

mainly there are 3 types, base on wuli, base on zhimou, base on meili.

if wuli is chosen, fenfa will be checked first. if can fenfa, the troop
will fenfa, otherwise it will check whether can jiaoma, and last
it will choose one from qibing and sugong.

if zhimou is chosen, the system will check whether hunluan and
shidu can be used.

if meili is chosen, system will try jiedu and shoushi first. then will
be guwu and zhanbu.

other jimou like neihong, huangbao, luoshi, jbsj will be added in later
however, i need do a mess change for the jimous.

fire, please check check the ftp server, it is not working for me 
and flee....:~(

regards


---
作者: Row
题目: >>about NPC leave
日期: Mon Aug 14 00:40:30 2000
/sgdomain/event/ev_donate.c is responsible for npc's donate, which will
add loyalty and reputation randomly. the new npcai_d can call it.


---
作者: Row
题目: >about NPC leave
日期: Mon Aug 14 00:27:04 2000
On Mon Aug 14 00:11:04 2000 威少爷(suicide) wrote post #1727:
> I have done nothing with NPC leave.
> NPC just leave for its low loyalty,And many NPC now has low loyalty.
> I don't know why ? 
NPC's loyalty is decreased for assorted reasons, been lettered, been
whispered, been posed to a lower position (maybe), havent received salary...
its hard for NPC to maintain higher loyalty becoz there are so many dummies
doing so many jobs...hoho, anyway, i think we may add more job to add
NPC's loyalty, since we only have visitofficer have such function.


---
作者: 威少爷(suicide)
题目: about NPC leave
日期: Mon Aug 14 00:11:04 2000
I have done nothing with NPC leave.
NPC just leave for its low loyalty,And many NPC now has low loyalty.
I don't know why ? 


---
作者: Fire
题目: >>>>>about war
日期: Sun Aug 13 20:36:40 2000
On Sun Aug 13 20:03:24 2000 Ice wrote post #1725:
> there is a time limit for defence arrange troops bah, i remember,
> if so, that's fine, otherwise it'll be a trick of the defender.:P
> and b4 defence party enter the warfield, the morale of attacker
> should not decrease anyway.

yes it is, if the defence leader idle then the system will
auto arrage the troop. so don't worry about that :)


---
作者: Ice
题目: >>>>about war
日期: Sun Aug 13 20:03:24 2000
there is a time limit for defence arrange troops bah, i remember,
if so, that's fine, otherwise it'll be a trick of the defender.:P
and b4 defence party enter the warfield, the morale of attacker
should not decrease anyway.


---
作者: 烈火(fire)
题目: thank stefan and suicide
日期: Sun Aug 13 19:59:52 2000
for your help and information.
regards,


---
作者: Fire
题目: >>>about war
日期: Sun Aug 13 19:52:52 2000
On Sun Aug 13 19:43:20 2000 Suicide wrote post #1722:
> I think if we can set a flag which used to judge if defense side had
> entered the warfield.
> When defense side haven't entered warfield it will suggest attack side
> "你正在领兵快马加鞭向XX杀去...".

yes, now i use this method.
we can use TASK_D->get_task(id,"start_war") to check, if return
value is "yes", then the energy will auto recover. if not can't recover
energy so the attack side need to wait until the defence finish their
arrangement :)


---
作者: Suicide
题目: >>about war
日期: Sun Aug 13 19:43:20 2000
I think if we can set a flag which used to judge if defense side had
entered the warfield.
When defense side haven't entered warfield it will suggest attack side
"你正在领兵快马加鞭向XX杀去...".


---
作者: Stefan
题目: >the name
日期: Sun Aug 13 14:17:57 2000
On Sun Aug 13 02:18:15 2000 分钟(group) wrote post #1717:
> the name is iiiiiiii
This problem is now fixed.


---
作者: 玄冰(ice)
题目: about npc leave
日期: Sun Aug 13 10:09:54 2000
players complain that npc will leave even he is in 100, and now
no one "tanqin", also they said they observed that when more npc r
not officer, the leaving rate is higher.


---
作者: 玄冰(ice)
题目: hmm
日期: Sun Aug 13 10:00:06 2000
fix task group now bah, otherwise wiz.com will be full of all
posts.

and i have a suggestion about cmd honour, if sb cmd leave the nation,
or ind, or be fired, or system restart, the honour should be cleaned
to 0, i think. bcoz the honour is mostly related to the nation, if sb
lose the nation, honour will be meaningless.:P

ps. a thought in mind long ago, i think honour is just like pots in other
wuxia mud anyway.


---
作者: Ice
题目: >about war
日期: Sun Aug 13 08:04:57 2000
i agree group's opinion.
but also try change the defence part's delay as well, it's really
unfair to the defence party.


---
作者: 分钟(group)
题目: the name
日期: Sun Aug 13 02:18:15 2000
the name is iiiiiiii


---
作者: Stefan
题目: >chinese name
日期: Sun Aug 13 00:30:59 2000
On Fri Aug 11 12:07:50 2000 分钟(group) wrote post #1708:
> today there is a player login with a extremly long name
> hmm... is there a limit for the length of chinese name?
> if dont have, better add a limit ba

I think we do have a limit, let me know who has got long name.


---
作者: 分钟(group)
题目: about war
日期: Sat Aug 12 23:25:33 2000
please change the war part.
if it is the npc country, only taishou can lead war.

i think the war record is a good verify for that.


---
作者: 威少爷(suicide)
题目: call log
日期: Sat Aug 12 22:05:54 2000
For Jianran's bug report,I reward him of dec 5 year older.


---
作者: Ice
题目: >to group
日期: Thu Aug 17 21:12:09 2000
i support to increase the time between using 2 same jimou.:)


---
作者: 威少爷(suicide)
题目: to group
日期: Thu Aug 17 21:06:05 2000
是否可以加大使用两次计策之间的间隔时间,来减少玩家使用的次数?
或者玩家使用计谋的次数由该计谋的对应的基本技能值确定?
25 一次 50 两次 75 ...100...  我想如果这样做的话,现在打仗就是比计谋
的情况就可以
解决一点,what do u think?


---
作者: 威少爷(suicide)
题目: about 相性
日期: Thu Aug 17 20:13:47 2000
A good idea ,we can use it to make 谜提
if a guy's 相性 is different from npc who can teach special skill
,then that guy can't learn from it,or can lah...
I will think about it and make it as quick as i can.


---
作者: Suicide
题目: >report type
日期: Thu Aug 17 20:12:03 2000
On Thu Aug 17 09:00:44 2000 玄冰(ice) wrote post #1764:
> cmd report
> 
> 命令格式：
> cmd report local      太守专用的本地情况报告
> cmd report nation     国家官员的国家情况报告
> 
> 注释：
> 只有相应职位的玩家才能使用该命令，由于国家官员的职能尚未详细分工，
> 暂时以统一报告的格式进行。
> 
> 相关参数：
> cmd report local/nation last <num_mon> 查看过去几个月的报告集合。
> 参数缺省的默认为查看上个月的报告。<num_mon> 范围从1到12。
> 
> 报告相关：
> 太守查看本地报告，每次每月报告需消耗本地黄金100两，即如果查看过去一年
> 的报告需消耗本地金钱1200。
> 国家官员（含国君）查看国家报告，每次每月需消耗国库黄金200，即如果查看
> 过去一年的报告需消耗国库金钱2400。
> 
> 报告格式：
> cmd report local
> 〓〓〓〓〓〓地〓〓〓〓〓区〓〓〓〓〓报〓〓〓〓〓告〓〓〓〓〓〓
> 【名    称】<地区名称>    【 所属国 】<国家名称>
> 本地现有士兵：<士兵数目>
> 从本地输送到外地的士兵数目：<士兵数目>*
> 从外地输送到本地的士兵数目：<士兵数目>*
> 本地现有黄金：<黄金数目>
> 从本地输送到外地的黄金数目：<黄金数目>*
> 从外地输送到本地的黄金数目：<黄金数目>*
> 本地现有粮草：<粮草数目>
> 从本地输送到外地的粮草数目：<粮草数目>*
> 从外地输送到本地的粮草数目：<粮草数目>*
> 本地现有木材：<木材数目>#
> 从本地输送到外地的木材数目：<木材数目>*
> 从外地输送到本地的木材数目：<木材数目>*
> （其他物资报告同木材）
> 本地现有农场：<农场数目>#
> 新建设农场数目：<农场数目>*
> 新拆毁农场数目：<农场数目>*
> （其他基地报告同农场）
> 本地建议征兵数量：<建议数量>*
> 本地建议裁兵数量：<建议数量>*
> 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓三国志〓〓〓
> * 如没有发生此类变化，则不显示在报告上。
> 
> cmd report nation
> 〓〓〓〓〓国〓〓〓〓〓家〓〓〓〓〓资〓〓〓〓〓讯〓〓〓〓〓
> 本国现有兵力：<士兵数目>
> 本国各地现有黄金：<黄金数目>
> 本国各地现有粮食：<粮食数目>
> 本国攻陷了以下地区：
> 地区、地区……
> 本国丧失了以下地区：
> 地区、地区……
> 国家会议的表决结果：
> <年><月>由<角色名称>提议，**
> 实际从<地区一>输送<物资/金/粮/士兵>到<地区二>。**
> 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓三国志〓〓
> ** 发生了该类提议则显示在报告上，没有则不显示。
It is a very good idea,but maybe very complex for we should keep a track 
of everything what happened before,and if we do this we should consider
the different of the nation officer ,and do all in a whole big project,
or later we still need to do more about it.
So who can give a suggestion which officer can see what?
BTW: fire,how about to absorb starrock to be a wiz who give plan ?
     For now i get to know that the plan is the headest work than 
     code,we need more more wiz to make plan.


---
作者: Ice
题目: >about base
日期: Thu Aug 17 19:24:25 2000
our mines r not function now yet, so still time to adjust that.:P
we dun even have a good way to allocate mines resource yet, so need to
consider it, maybe later.:P


---
作者: 威少爷(suicide)
题目: about base
日期: Thu Aug 17 19:00:51 2000
Today i read the comments of 三国演义三,and found that
对于各种矿产的在各个地区
每月的最大产量是不同的，因为个个地方各种矿物资源的贫富是不均匀的，我们是
不是也加上这个参数？


---
作者: Suicide
题目: >addoil suicide's relation_d
日期: Thu Aug 17 18:56:21 2000
wx88.net信箱接收现在这个server的mail有问题，我以前用wx88.net也有问题，换了个
elong.com的速度很快，你试一下.


---
作者: 玄冰(ice)
题目: report type
日期: Thu Aug 17 09:00:44 2000
cmd report

命令格式：
cmd report local      太守专用的本地情况报告
cmd report nation     国家官员的国家情况报告

注释：
只有相应职位的玩家才能使用该命令，由于国家官员的职能尚未详细分工，
暂时以统一报告的格式进行。

相关参数：
cmd report local/nation last <num_mon> 查看过去几个月的报告集合。
参数缺省的默认为查看上个月的报告。<num_mon> 范围从1到12。

报告相关：
太守查看本地报告，每次每月报告需消耗本地黄金100两，即如果查看过去一年
的报告需消耗本地金钱1200。
国家官员（含国君）查看国家报告，每次每月需消耗国库黄金200，即如果查看
过去一年的报告需消耗国库金钱2400。

报告格式：
cmd report local
〓〓〓〓〓〓地〓〓〓〓〓区〓〓〓〓〓报〓〓〓〓〓告〓〓〓〓〓〓
【名    称】<地区名称>    【 所属国 】<国家名称>
本地现有士兵：<士兵数目>
从本地输送到外地的士兵数目：<士兵数目>*
从外地输送到本地的士兵数目：<士兵数目>*
本地现有黄金：<黄金数目>
从本地输送到外地的黄金数目：<黄金数目>*
从外地输送到本地的黄金数目：<黄金数目>*
本地现有粮草：<粮草数目>
从本地输送到外地的粮草数目：<粮草数目>*
从外地输送到本地的粮草数目：<粮草数目>*
本地现有木材：<木材数目>#
从本地输送到外地的木材数目：<木材数目>*
从外地输送到本地的木材数目：<木材数目>*
（其他物资报告同木材）
本地现有农场：<农场数目>#
新建设农场数目：<农场数目>*
新拆毁农场数目：<农场数目>*
（其他基地报告同农场）
本地建议征兵数量：<建议数量>*
本地建议裁兵数量：<建议数量>*
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓三国志〓〓〓
* 如没有发生此类变化，则不显示在报告上。

cmd report nation
〓〓〓〓〓国〓〓〓〓〓家〓〓〓〓〓资〓〓〓〓〓讯〓〓〓〓〓
本国现有兵力：<士兵数目>
本国各地现有黄金：<黄金数目>
本国各地现有粮食：<粮食数目>
本国攻陷了以下地区：
地区、地区……
本国丧失了以下地区：
地区、地区……
国家会议的表决结果：
<年><月>由<角色名称>提议，**
实际从<地区一>输送<物资/金/粮/士兵>到<地区二>。**
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓三国志〓〓
** 发生了该类提议则显示在报告上，没有则不显示。


---
作者: Ice
题目: >>转贴
日期: Thu Aug 17 07:51:51 2000
yap, i think gini is the same function of guan pig.:P although gini
is a little bit annoying sometimes, it's purpose is nice.:) suicide can take
a look of the gini's code.


---
作者: Ice
题目: >角色之间关系度的程序/daemons/relation_d.c完成:
日期: Thu Aug 17 07:48:21 2000
Well, i think suicide did a good job.:) b4 he announced this, i have
another idea to implement simple relationship, that's koei's 相性 or can be
called 缘分, that's a hidden para. the range can be from 0-999, and it can
be randomly allocated to different char. the relationship about it is, if a
char's xiangxing is 123, another one is 124, they 2 may have very
good relation
with each other, if the third one have 789, then he will have bad relationship
with those 2. anyhow, i think this idea from koei is interested, it explained
一些后天无法解释的缘分.:P maybe after the relation system is done,
we can think
about it.

about suicide's relationship code, i dun have many ideas yet, but I think if
system restarts, all relationship can be cleaned 0, then the system load won't
be too heavy. and every char's relation among others is starting
from 0, except,
those family relationship and jiebai, marry relationship, i think we need to
set a fix para for them, both NPC and player, if in those cases, the
relationship
won't be changed.


---
作者: Row
题目: >转贴
日期: Thu Aug 17 07:38:33 2000
we have gini...point fire...hoho


---
作者: 黄帝(emperor)
题目: addoil suicide's relation_d
日期: Thu Aug 17 07:26:59 2000
为何news中我不能发送post到我的信箱中，每次提示发送成功，每次都收不到
wx88.net的信箱应该没问题


---
作者: 威少爷(suicide)
题目: 转贴
日期: Thu Aug 17 00:51:17 2000
1。新人上路
其实我觉得三国志里面这部分是最有自己特色，但是也是最不利于上手的部分。
每个第一次玩三国的人，都要花很多时间在这儿，所以如果不让这部分变得很
有趣，是不容易吸引人的。以三国的素质，绝对应该在中文mud上是最好的之一
，但是上的人不多，还有很多是每个站都有id的除了网速的关系，其实很多人都
是在这儿被挡了出去。显得枯燥了许多。要让新手上手其实用一个npc帮忙就可以
了，比如我一出来就应该有一个引路猪（guan pig）跟着我，然后主动教一些东西
给我。还可以回答一些问题，相当于help.这样就亲和了许多。然后还可以提醒我
什么，“你应该吃饭了，不妨去厨房问问厨娘试试”。最好是可以带路，你去问他
ask guan pig about 厨房，他就自动带你去厨房，那该多好。还可以和玩家娱乐、
练练训兽术什么的，等玩家离开了华阴，这只npc就离开他了，挥泪告别什么的。
反正我觉得初期这些东西在代码上难度不大，关键是巫师关不关心真正的新人的感受。
2. 技能
还是从新人的角度出发说说，我觉得三国这方面要象网络创世纪学习一下你说新人辛
苦的砍木头，目的居然是张张家贴，怎么甘心？uo上面也有砍木头，但是他上面玩家
砍木头会长伐木技能，虽说用处不大，只能用于提高伐木成功率，但是多少也给玩家
一点成就感。我觉得还应该增加挖矿、打铁、切菜等等工作，让玩家也可以打兵器、
当厨师……
丰富各种有用没用的技能，比如有的人训兽厉害，可以去偷马。有的人医术好可以疗伤
……
现在的三国，技能太单调了。
而且打的兵器什么的可以换钱，多好！
3。理想
这儿也涉及到重起的问题，还有巫师极力希望玩家们努力统一，但是每个人有每个人
的理想就象三国中有的人的理想是割据，有的人的理想是称霸，有的人的理想是天下
第一名将，有的人的理想是天下第一首富，有的人就想当个官守着俸禄混日子，有的
人渴望和平……
为什么一定要统一呢？而且重起缺乏游戏的延续性。
其实我很想在三国里面做一个天下第一的铁匠，打出一把天下无双的宝刀给别人用，
但是没有这样的职业呀。游戏逼着我们每天visitofficer、fanpeople……，实在是不
喜欢的工作职业可以丰富一点，不要都是当官的！我相信好的铁匠、医生、训兽师都会
受人尊重。就是做生意也很好，三国之中没有商人真是可气！
4。 其他要是还可以租房子卖东西就好了！比如 我设置商品(cmd addselllist xxx)后，
别人问我的list就会看到我要卖的东西、数量和价钱，然后可以交易。当然可以限定一
个房间只准限定一定的类型的商品，还可以卖东西给我。我退出后，就象太守一样，白
天呆在屋里，晚上失踪进行交易。这样丰富市场，又可以赚钱，好事呀！
只是最近觉得三国有点枯燥了。限制太死太多，没有很多的空间，违背了一个
mud的原则。
又玩了uo后觉得少了中国文化背景，所以有一种结合的想法。巫师们多多努力，让我们觉
得更加好玩吧


加个带路猪的想法满有意思的吗?说不定玩家还能对他产生感情.
好像lima mudlib里面有个小恐龙,可以改改哦


---
作者: 威少爷(suicide)
题目: 角色之间关系度的程序/daemons/relation_d.c完成:
日期: Thu Aug 17 00:17:21 2000
角色之间关系度的程序/daemons/relation_d
功能: 用于保存角色之间的关系度，为以后程序发展人际关系的核心程序
方法: 由于角色众多，两两对应的关系值的数据很多，如果是简单的全部
　　　保存在内存中必然会消耗很多的内存，如果全部保存在磁盘中只在
　    需要时载入内存，使用完从内存中卸出，那么磁盘就会频繁的被读
　　　写，加重磁盘的负担．综上所诉，我于是采用了磁盘与内存cache 
　　　相结合的方式，使程序的性能达到一个理想的效果．
      下面我就介绍一下我的方法：
      对于数据的保存，我没有采用一般dameons 的集中保存数据在一个
      文件中的方式，而是象body，link的按角色ID分开保存的方式，并
      且在内存中设定一块内存做cache ，当需要查询两个角色之间的关
      系度时，程序会先试图从cache 中寻找是否存在，如果没有就根据
      角色的ID读数据文件将这个角色的对应数据装入cache ，并且纪录
      装入的对应时间为初始访问时间．对于己在cache 中的数据就直接
      从cache 中获得，同时也更改它的访问时间．对于cache 的管理我
      设定了一个条目溢出阀值和一个条目长期不被访问的最大失效时间
      程序每隔一定时间（暂设置为两小时四十分）会自动清除cache 中
      那些已失效的角色数据，另外当程序试图装入新的角色数据而导致
      cache 中的条目数大于条目溢出阀值，程序也会强行清除部分角色
      数据．这样就有效的防止了长时间不被访问的无效数据占用过多的
      系统内存，导致系统性能下降，而且也因为cache 的存在减少了磁
      盘的频繁读写装入卸出数据．
      
计算: 我的程序中保存一条两个角色之间的关系值平均需要十个字节，假设
　　　平均一个角色会和３００个其他角色产生关系值，那么对于一个角色
　　　而言他所占的内存数据量为10*300=3000 约为3k，所以cache 的溢出
　　　阀值最大为150 ,那么整个这个系统最大会占用的150*3=450k 的内存
　　　空间，对于数据量很大的一个系统而言这个值我想还是可以接受，当
　　　然我们还可以通过调整阀值来调节他最大能占用的内存空间．
格式: 一个角色的数据文件格式是:
      (["data":(["suciide":10,"fire",15]),"time":xxxxxxx])
      cache的数据格式是:
      "<角色id>":[角色数据]
      
函数: get_relation(<主id>,<从id2>) 用于获得两个角色间的关系值．
　　　add_relation(<主id>,<从id2>,int) 用于设定两个角色间的关系值．
　　　stat_me(0)  用于获得cache中的条目数
　　　stat_me(1)  用于获得当前被访问的角色数据
      stat_me(2)  用于获得cache中所有数据
调试: 在我的机器上已经全部调试成功，并上传文件到/dameons目录下．但是
　　　大家要是测试或使用，需要fire在/data目录下建立一个新目录relation
      并在/data/relation下建立a.b.c.d.e.....z的子目录．
      
最后才是最重要的，就是虽然这个核心程序完成了，怎么围绕它开放一些有趣的
关于人际关系的系统，就需要大家多多策划多多建议啦．
给点掌声好不好？:)      
.c完成:


---
作者: Ice
题目: >转贴
日期: Wed Aug 16 21:43:04 2000
hmm, i dun really get it... but it's sounds like the situation to
enable chengdi in san7.:P
anyhow, i think it's not bad to implement an idea that increase some
importance of some certain areas, as some special bases do.
dun have clear idea of it now yet.


---
作者: 威少爷(suicide)
题目: 转贴
日期: Wed Aug 16 21:34:00 2000
时间:  Thu Aug 17 07:02:50 2000                Post-id: 591 (591 Last)
作者:  重装兵(ghb)
题目:  我有一个好的建议
----------------------------------------------------------------------
我在想是不是把挟天子以令诸侯加进去。
把带兵逼宫加进称帝里去
如果亲兵数目超过500人，官拜丞相，或是控制了changan的诸侯
且将领的忠心都不低于90,就可以带兵逼宫，要求称帝
今后还能挟天子以令诸侯
战略上出于有利地位，这样似呼更有意思。
其他称帝的条件不变
han di的文章应该作一点把


---
作者: 威少爷(suicide)
题目: To group
日期: Wed Aug 16 06:52:24 2000
鞠低场咳嗫兀簄o NPC troops in the war. 来自：/sgdomain/event/ev_cast
【系统】三国监控：no NPC troops in the war. 来自：/sgdomain/event/ev_cast
【闲聊】其二(ptwo)：war system should be the core of this game, not doing jobs
【系统】小纯(chun)离开了三国志总站。
cmd war time
距下次战争开放时间：十六小时二十五分五十四秒钟。

Group:
   在非war time也检查NPC troop吗?


---
作者: 黄帝(emperor)
题目: 有关网络三国的
日期: Wed Aug 16 05:27:40 2000
狂賀本站08/10單日流量突破八千人次，感謝玩家熱烈支持！ 
　 賀網路三國第一批出貨十八萬套全部搶空，第二批無敵威力加強版即將推出！ 
   

stefan,看到了吗，100种武器的图片高达几十M



---
作者: 黄帝(emperor)
题目: 有关网络三国的
日期: Wed Aug 16 05:25:00 2000
【三國訊】三國最高執行政府於今日公告，全國所有武器店即日起將販售武器及 
裝備增為一百種，但由於所需圖檔高達數十MB，於更換新增裝備時身上圖樣可能 
無法同步更新圖樣顯示，此點請玩家見諒。本公告自即日起生效！ 

【三國訊】三國最高執行政府經過連日來觀察，發現有許多玩家為圖一己私利使用外掛 
程式，此舉除破壞遊戲公平性外，更因大量攔截訊息極易造成人物資料錯亂，包括目前 
發現之生命力 1 之動物群、能力消失、經驗值消失、屬性錯亂等，最高執行政府除呼籲 
玩家不要因為自己的私慾而影響其他玩家外，明定處罰辦法如下： 
　1. 初犯者經查獲後直接砍檔為全新玩家。 
　2. 經查獲兩次者鎖 ID，所有損失由玩家自負。 

 

 
 



---
作者: 威少爷(suicide)
题目: about war field map
日期: Wed Aug 16 01:56:41 2000
Any one can make a change at war field map.
At least make those 关口 as the real area which is hard to attack
and easy to defend
.给那些关口地区加些天险吧 ...


---
作者: Suicide
题目: >>about fight
日期: Wed Aug 16 01:54:41 2000
I will just do as urs ah..
hoho


---
作者: 玄冰(ice)
题目: about localleader
日期: Wed Aug 16 01:28:09 2000
【闲聊】受当地官员推举，张华成为许昌的太守
【闲聊】玄冰(ice)：maggy was xuchang taishou?
> 【闲聊】小辣椒乖乖地坐在玄冰身旁，听她讲故事。
【闲聊】玄冰(ice)：by b or by c?
> 【闲聊】小辣椒(may)：pos e to huguan
【闲聊】玄冰口吐白沫，昏倒在地。

faint, we omited this point, qiandu auto switch the capital localleader
to the new capital, then the former one is no leader actually, so maybe
make moving capital won't move localleaders/king to the new capital
automatically, let them do it themselves bah.


---
作者: 玄冰(ice)
题目: about war again
日期: Tue Aug 15 22:15:40 2000
I think the situation now is exactly like long b4, cdd got changan
from taiyuan war with dummy, now ppl can ask for position if NPC
nation dun have guoshi and area dun have player taishou, then he
can cmd war an area, also his dummy may cmd me in defence war and arrange
troops for the defence party. I saw u guys posted an idea some
days ago, it's about if there is no local player leader chosen yet,
and the nation has no guoshi, make the NPC leader defaultly the defence
leader, I think we must do it now, bocz my last post in caolu must remind
them to use this way.:P pls do it as soon as possible.
otherwise it'll ruin suicide's work.


---
作者: Ice
题目: >about fight
日期: Tue Aug 15 22:07:38 2000
faint, suicide, would u pls try use my plan? i think it'll be
not hard to expand to urs, or wait for others discuss a little bit
more first? I think if u started it now, it's not too easy to
change later anyway, the later the harder.:P


---
作者: 威少爷(suicide)
题目: about fight
日期: Tue Aug 15 21:49:36 2000
先说不如先做,我先做一个啦,大家试试,不行再改啦


---
作者: 玄冰(ice)
题目: about dantiao
日期: Tue Aug 15 21:33:28 2000
说到单挑系统，我在草庐也提到过，以前我们曾经有一个想法，也曾经
深入讨论了，但现在回想起来似乎有点象互耍一套拳，谁碰着了算谁的，
好象又不太妥当。前几天castor和我说了一下，他说，文字mud的单挑
要做好是非常难的，看koei的单挑，在其设置的模式之后，还有相当的
声光效果在后面支持，所以他说，我们不如不要弄这个单挑系统，吃力
不讨好。想想，他的话有一定道理，我们如果花大力气做了个复杂的单挑
系统出来之后，如果难以被玩家接受或者无人感兴趣，那么力气可能白
花了，但我认为，三国还是需要一个单挑系统，只是，不需要那么复杂。

先说SUICIDE的题外话，我认同他的观点，三国的最终目标应该是成为
一个虚拟的三国社会，一如我在HELP NEWBIE里面写过的，玩家应该向
他所希望成长的目标奋斗，最终的目的未必是成为统一的国君，高技能
的将领，而是可以成为富甲一方的商人、地主、医师等。但在现时，我
无法不承认，我们的战略和战争部分做得并不够，所以应该优先更改的
应该是战争系统和整个三国的NPC AI系统。现在的NPC主要都是被动的，
没有主动性的NPC，这个游戏丧失了不少乐趣。至于使三国成为一个虚拟
社会的目标，是应该在首先实现上面的系统的基础上实现的。

单挑系统，我的认知是应该不等同与现有的打斗（fight）系统，打斗
是用于在平时进行增加技能的，属于练功，我认为应该不需要进行过多
的修改，反正练功，放个机器人好好练得了，三国没有什么技能是机器
人练不到的。如果将之改为需要动手动脑的练，反而可能没有什么吸引
力，因为反正这里没有死亡，受伤也没有地方可以恢复，要是非逼着那
样复杂地练功，玩家可能没有什么兴趣。除去打斗系统外，我觉得新的
单挑系统的试验阶段可以放在比武大会上，如果效果满意了，再将其融
合到战争中去。单挑也只是战争手段中的一种，主要的战斗还是战术的
运用和士兵的战斗。

我觉得单挑系统暂时不适合做的那么复杂庞大，先做一个可以让玩家手
动控制的单挑系统就够了。在做这套系统之前，应该考虑到由于网速的
不同，如果要做到玩家每发出一个指令就做一个动作是不太可行的，试
想如果象SAN7一样每用完一招要再考虑下一招用什么，假设双方美人用
30秒，那打到其中一个人倒下大概天都黑了。所以，还是耍拳比较适合
现在的情况，如果将其解释为套路的话，大概还可以接受吧。

对于SUICIDE对武器不同用途的区分，我有点别的意见，至今为止，使用
什么武器（除了空手之外）是根据个人的爱好，游戏是虚拟的，想象自己
喜欢用什么武器就用什么，我想这点应该不用象武侠游戏一样加上功利的
色彩。现在还是先不急着加上了吧。

每种武器要有不同的招式倒是真的，只是要想许多不同的描述就有点头疼，
不过如果要进行单挑系统的话是必须要的。特殊招式的学习应该通过解谜
来进行，但要进行解谜又是要动用到大批人力的方案，我觉得每种武器都
有几种特殊招式，然后先由玩家随机使出算了。

根据以前的想法，我想还是可以采用的。

可以使用的招式：
攻上、攻中、攻下、防上、防中、防下、休息、特殊招式。
攻击（上、中、下）：攻击时，自身抵抗力下降20%；
防守（上、中、下）：如果对方攻击的正是自己防守的位置，抵抗力增加
50%，如果对方攻击的不是自己防守的位置，则抵抗力不变；
休息：休息恢复剩下气血的30%，但休息时抵抗力下降30%。

可以使用的套路：（总共5个）
自行编制，（在一分钟内，否则系统自行选择，选择的范围不不包括休息
和特殊招式）。休息和特殊招式只能在每个套路中选取不能超过一次。

战斗损伤：
以玩家当时的杀伤力为基本值，结合对方的套路，以及对方的抵抗力，计算
出对方的损伤值。

战斗恢复：
在单挑开始时应中止体力自动恢复，只有当玩家选择休息时方能恢复体力。

特殊招式的应用：
我想特殊招式每种兵器都有几种，而这几种特殊招式分三类：
1、全力一击：在实施全力一击时自身的抵抗力下降80%，即如果对方也在
攻击的话，计算的公式中抵抗力将减少80%，但自身的杀伤力加倍。
2、强力攻击：在实施强力攻击时自身的抵抗力下降60%，自身杀伤力增加
30%。
3、取巧攻击：在实施取巧攻击时自身的抵抗力下降20%，自身杀伤力是
RANDOM（150%），成功达到150的话与全力一击相当，但受伤的机会减少，
同时如果不成功的话，也可能伤不了对方一根寒毛。
只有特殊招式才能使对方受伤，普通的攻击只会减少气血。

单挑回合数：
单挑总共有3个回合，3个回合之后如果没有分出胜负，以剩余气血占自身
应有气血的比例大的为胜。如我本来400，对方本来300，而战后我剩下
100，他也剩下100，那么是对方胜出。

解释：
1、提供手动的单挑模式给玩家，并提供以弱胜强的机会。
2、可以安排NPC参加比武大会，并予以玩家挑战NPC的机会，spig和lv bu
打谁赢还不知道。
3、相对不复杂的设计，应该不用投入过多的精力，单挑目前并不是最紧急的，
我们可以利用这个系统提供一个玩家之间、与系统之间斗智斗力的机会。
4、改善现在比武大会不再有吸引力的情况。
5、可以作为以后进一步单挑系统伸展的基础。

hope u guys can consider it smoothly.:) * support


---
作者: Ice
题目: >>My idea about jimou
日期: Tue Aug 15 19:19:29 2000
要设计一个完美的AI是不可能的，因为人的行为永远有不可预知性，而
电脑的判断是基于程式设定的if...then...，所以永远只有最复杂的
if...then...才能成为比较成熟的AI，我以为。

NPC的计谋使用应该分为两种情况，第一种是玩家不在线时的NPC，这个
NPC的计谋使用应该仅限于他所学会的计谋，第二种是三国NPC，由于如
果要对NPC进行计谋技能的设置相当困难，所以其计谋技能现时应该只能
随机取得，（将来，哦，将来可以象KOEI一样将每个NPC会的技能单独设
置，但现在还是先随机吧）而现时的NPC计谋应该侧重于直接攻击与防守
性强的计谋，而一些如占卜、天变等的就先不用考虑了吧，毕竟现在这些
还没有真正起到作用。

应该只有军团首领才能使用计谋（在现时情况下），否则会变成一团乱。
如果一个军队又有玩家又有NPC的，只有军团首领才能使用计谋，这样就
限止了出现几个将领同时使用计谋造成混乱的情况，而不用设定只有纯NPC
军团才能使用计谋了。我想要同时要做cmd cast的更改，使当玩家不是
军团首领时无法使用计谋。

再然后，我想GROUP也应该已经做了的，就是当NPC本身所在部队遭到一些
限制性的攻击时，会相应地使用一些计谋来解除限制。而攻击性的计谋则
需要相当多的if...then...，还是先根据GROUP的提案提些修改

if wuli is chosen, fenfa will be checked first. if can fenfa, 
the troop will fenfa, otherwise it will check whether can jiaoma, 
and last it will choose one from qibing and sugong.
我想奋发可以做成TRIGGER，当被收到信息被围攻的时候可以选择奋发，
反正现在的NPC被围攻了也不会选择逃跑。而武力计谋的顺序大概可以
改成速攻、叫骂。奋发是TRIGGER，而奇兵则可以在战争一开始时进行
检查部队是否符合奇兵的要求，符合就奇兵，然后根据现在的NPC AI，
他大概会衔枚疾走直奔对方主将。速攻是战争中比较重要的一环，所以
顺序应当提前。

if zhimou is chosen, the system will check whether hunluan and
shidu can be used.

这个没有意见，先混乱，后施毒。

if meili is chosen, system will try jiedu and shoushi first. 
then will be guwu and zhanbu.

先收拾，后解毒吧，然后鼓舞，占卜……呵呵，比较可怕。

我想在没有设定NPC各自的计谋技能前，是不是在开战的时候让系统给
他们随机抽几个算了，不然，我没有能想到让他们有机使用计谋的方法。
如果照GROUP的方案，每7分钟随机抽取一个部队来实施计谋，这不太
符合现在的战争状况，7分钟的时间我想足够一个玩家军团把自己的精神
全部用完了。

我想SUICIDE的克制提议应当比较容易实现，在实施成功率中加上被施用
对象的因素，无疑应该更接近真实情况。

哦，想不到太多了。


---
作者: 玄冰(ice)
题目: 三国城市等级点
日期: Tue Aug 15 17:53:17 2000
三国的人物已经有了三国等级点，我想如果再设立一个城市等级点的话，
可以让玩家之间互相攀比成就，并且作为迁都是否合理的评定标准。

三国城市等级点=
城市等级*200 + 城市人口 /（城市等级*1000） + 是首都(300)
（工业 + 农业 + 商业 + 安定）*城市等级/2 + 基地数目*10

举例：如果洛阳有100万人口，所有指数全部满的话，加上10个基地
并且是首都 =1000 + 200 + 300 + 800*5/2 + 100 = 3600

如果弘农有20万人口，所有指数全满，加上10个基地,但不是首都
=600 + 667 + 800*3/2 + 100 = 2567

这个指数的考虑是这样的，首先城市等级是首要的,越大的城市越占优势，
然后因为每个等级的城市都有相当的人口上限，因此需要根据城市等级
来计算人口的加权比重，接着如果是首都，应该比较占优势，再然后因为
越大的城市，在管理城市上需要更多的官员担任地区官职，所以也加上了
根据地区不同而加权的参数，最后是基地，因为商业系统没有最终明确，
我想暂时先根据基地数目来计算吧，所以没有加权。

如果一个国家要迁都，起码是要往更好的城市迁吧？那么，如果玩家国君
进行迁都，则应该出现一个提示，该城市的状况（城市等级点）比现有国都
要差，如果坚持要迁都的话，全国的安定下降，官员忠诚下降。如果目标
城市的状况比现在的好的话，则迁都顺利。如果是NPC国家的国师要求进行
迁都，如果目标城市的状况好，则迁都成功，如果差的话，国师的信任度
将大幅度下降。

此外，还需要在info里面加上城市等级点的显示，方便查询。

国都的重要性将在以后逐步实现，因此，迁都将会成为举足轻重的决定，
现在先做准备工作吧.:P


---
作者: 玄冰(ice)
题目: about taishou in na meeting
日期: Tue Aug 15 16:28:19 2000
I think maybe piaox's report is right, bcoz only taishou can
suggest the transition between 2 areas, so I think when a 
transit-destination taishou ask for the meeting to transfer sth
to his area, it's possible now.  so maybe change to taishou can only
suggest to transfers out of his area, otherwise must be national
officer.:)


---
作者: 威少爷(suicide)
题目: still about fight
日期: Mon Aug 14 23:04:18 2000
 和row 关于战斗系统讨论了一个中午,虽然有分歧,但是也达到了一定的
共识，简单的介绍一下：
　　１）我和row 都认为我们的战斗系统应该脱离过去武侠游戏由系统全自动
　　　　控制的模式，改成由玩家人为控制，但是因为网速的原因我们让玩家
　　　　全人工控制，因为这样显然对网速慢的玩家不公平．我们最后达成共
　　　　识就是半自动半人工，玩家如果不人工输入指令，系统也能按默认的
　　　　简单攻防进行，而玩家也可以根据实际情况适时输入指令调整自己的
　　　　攻防模式．
    
    我和row 的一些分歧也简单介绍一下：
    １）默认战斗模式：
    ROW:由玩家事先设定好自己的默认攻防套路．
    ME :在我的设计中，玩家会那些攻防套路并不是由他的技能级别控制的，
    　　而是他在武学修行时在碰到NPC 武士根据机缘巧合随机学来了，也
    　　就是说可能大多数玩家可能什么特殊攻防套路都不会，而只有基本
    　　技能等级，所以我认为默认的攻防套路就是现在系统已有的战斗系统，
    　　无需做任何改变，而玩家也不用设定．
    
    ROW:对于攻防套路，不要采用其他武侠游戏的perform 形式，而改用街霸
        等打斗游戏上中下三路的攻防模式．
    ME :我认为好的东西就要吸收，不能因为我们是战略游戏，要与武侠游戏
    　　完全不同，而拒绝使用武侠类的perform 概念．实际上战斗系统是武
    　　侠类的精华所在，我们应该把他好的一面吸收过来加以改进，变成更
    　　有特色的系统，做到人有我有，人无我更有，这样才能吸引更多的玩
    　　家．在我的想法中只是引用perform 的概念，而不是其具体形式．如
    　　我的上篇所说，我引入的每个特殊攻防招式都有其防守最薄弱的部位
    　　和进攻最强的部位，实际上也可理解为就是攻”上中下”三路，当然
    　　部位有可能划分的更细，每个攻击特殊套路会加强自己的攻击力的同
    　　时也会给自己带来某个部位防守的薄弱，而如果对方恰巧有攻击这个
    　　薄弱部位最强的套路做反击的话，自己就会反而受到重大损失．这样
    　　双方单挑是否了解对方所会的套路和自己是否有克制的招数会对整个
    　　战斗的结果带来偶然性，了解对方的套路也变成了个重要的事情．
    
    说到这里，还有一些题外话，也一并提一提，我对我们这个MUD 的发展方
向是想把他设计成一个大而全的虚拟三国社会而不仅仅是一个战略MUD 游戏，
而不是为了保持他的战略游戏的特色而弱化其他系统的建设，我希望到我们这
儿来玩的玩家都能找到他喜爱的角色(将军，谋士，武士，商人等等．．．就象
我们以前写的游戏介绍那样)而不仅仅只能做一个攻城掠地的将军．角色多样化
才能使我们的游戏更有吸引力和竞争力，不知道大家对这个是怎么想的？
    
    


---
作者: Row
题目: >about fight
日期: Mon Aug 14 19:52:53 2000
武功并不应该在我们这个战略泥巴游戏中占据很大分量，但是
构思独特，设计巧妙的打斗系统将肯定为本游戏增色不少。现
在我们已经有了和其他武侠游戏相似但简单得多的战斗系统，
可不足的是，三国特色之一----单挑，我们至今还无法做到。
话说回来，单挑冲其量应该是一个武将计，在战争中使用挑发，
若对方应战，则开始单挑，胜者军队士气大升，败者军队士气
大减并且所带部队自动撤退。我们应该将单挑设计得具有不可
预测性，武力八十的也有机会可以赢九十的，但当然六十对九
十是毫无机会的。这样，单挑计的使用将具有冒险性，因为一
旦成功，收效甚大，但也不会被滥用，因为失败的机率同样很
大。另外，平时想要过单挑瘾的，可以等到比武大会，现在的
比武似乎毫无刺激性，而采用新的单挑系统，将可能会提高玩
家参与的兴趣。

关于系统的设计，我以前早就有个设想，分钟也做过一个简单
的程序，但不知道放在哪里了，可以拿出来参考一下。威少爷
这里也应该有那个设想的帖子，可以针对它进行修改。主要的
目的是，完全摒弃旧有的打斗系统，引入新的模式，增加玩家
在战斗是的参与度，而不是坐在屏幕前看刷屏，或者拼命地施
放perform 。

只要大方向的构思定了，具体的设计也就好办了。大家有什么
意见，欢迎提出。


---
作者: 威少爷(suicide)
题目: about fight
日期: Mon Aug 14 18:13:49 2000
　　考虑了好几天的战斗系统，到现在也没有得到一个成熟的方案，唯一
的收获是脑袋更昏了．由于实在想不小去，就先把我脑海中的只鳞半瓜的
想法先写出来，抛砖引玉一下，说不定集大家之长会有一个很好的方案．
    
    1)现在我们系统有空手、剑、刀、枪、戟、锤、斧七种武器，战斗系
    统的第一步是要让不同的武器有不同的效果，我的初步构想是：
    空手　－－　单独使用时攻防很差，但是达到一定级别后，玩家可以
    　　　　　　达到身剑合一的地步，可以用任何武器使用任何武器的
    　　　　　　特殊招式．
    剑　　－－　守最强，攻最弱，使用攻招消耗精神最少．在精神相同
    　　　　　　且不恢复的情况下能使用的攻招次数最多，但攻击力，
    　　　　　　伤害力最低，以下的兵器以次类推为刀－＞枪－＞戟－＞
    　　　　　　斧－＞锤．
    　　
    2)每种武器都有其特殊的招式，可以根据各人该武器技能等级再细分成
    　几个级别，当然招式的名称也不同．特殊招式可分为攻招和守招，两
    　者可相生相克，把人体分成若干部位，每个攻招具有对某个部位攻击
    　效果最佳，对某个部位攻击效果最低的特性，同时守招也具有对某个
    　部位防守最佳和最低的特性，这样两者相遇就可以碰到相生相克的效
    　果．使用攻招可以加强自己的攻击力同时一段时间内自身的防守降低
    　给对方的反击造成可乘之机，而使用守招可以加强自己的防守力同时
    　一段时间内自身的攻击降低，但是在此时间内可以恢复自己使用攻招
    　而消耗的精神达到在此使用攻招的地步．攻招越厉害消耗的精神越多
    　且降低防守越多，守招越厉害攻击力越低但精神的恢复速度越快．
    
    3)特殊招式的学习，武将必须向太守告假要一个武学修行的任务，在此
    　期间内可以四处巡游，寻找随机出现的武士比武，在某种条件下武士
    　可以把自己会的特殊招式交给玩家．在武学修行的时间内武将无法参
    　加战斗和内政建设等其他和国家有关的任务，造成个人和国家利益之
    　间的一个小小矛盾，我想我们以后的系统应该多多这样设计，制造个
    　人和国家利益间的冲突，让玩家自己去取舍，这样是不是更有意思？
    　
    
    
    以上就是我的一些想法，非常非常不成熟，欢迎大家多多回音．:)


---
作者: Suicide
题目: >>about auto cast
日期: Mon Aug 14 18:13:05 2000
But i can use ftp server ah,why?


---
作者: Ice
题目: >>about auto cast
日期: Mon Aug 14 16:39:38 2000
faint, fire didn't use ultraedit bah, seems i m not the last guy.
fire wanna try that? edit on ftp server, without using the ed here.:P


---
作者: Fire
题目: >about auto cast
日期: Mon Aug 14 16:34:54 2000
On Mon Aug 14 01:30:19 2000 分钟(group) wrote post #1731:
> i just finished auto cast code, it seems working well on my 
> computer, but not sure whether it is good enough or not.
> 
> in every 7 minutes, system will random choose a NPC troop,
> can then random choose a jimou for cast.
> 
> mainly there are 3 types, base on wuli, base on zhimou, base on meili.
> 
> if wuli is chosen, fenfa will be checked first. if can fenfa, the troop
> will fenfa, otherwise it will check whether can jiaoma, and last
> it will choose one from qibing and sugong.
> 
> if zhimou is chosen, the system will check whether hunluan and
> shidu can be used.
> 
> if meili is chosen, system will try jiedu and shoushi first. then will
> be guwu and zhanbu.
> 
> other jimou like neihong, huangbao, luoshi, jbsj will be added in later
> however, i need do a mess change for the jimous.
> 
> fire, please check check the ftp server, it is not working for me 
> and flee....:~(
> 
> regards

great group, for the ftp server, it can't go through fire wall.
So I can't use ftp either. I always use ed, cut and paste. sign


---
作者: Fire
题目: >about NPC leave
日期: Mon Aug 14 16:33:00 2000
On Mon Aug 14 00:11:04 2000 威少爷(suicide) wrote post #1727:
> I have done nothing with NPC leave.
> NPC just leave for its low loyalty,And many NPC now has low loyalty.
> I don't know why ? 

I think because of restart all the loyalty are random assigned. hoh


---
作者: Group
题目: >My idea about jimou
日期: Mon Aug 14 04:18:58 2000
1. this skills comparison is there already, the thing need to
consider is the formula.

2 now the limitation comes from the jing sheng. since only 
sleep can recover it, a player can only use limit number of 
jimou within a war time.

about the times limitation... hmm... maybe can appears from the jing sheng
formula.

3. yap, that is the same thought as me, so when i can update the jimou
system, all this comparison will be added in.

xixi
regards


---
作者: 威少爷(suicide)
题目: My idea about jimou
日期: Mon Aug 14 03:02:58 2000
     Group已经开始修改计谋系统了,在此我说说我的看法，对于
     计谋的code我没什么细看，就想到那说道那，也许有些想法
     现在系统已经实现了．
     .
     1 计谋的要互相克制，我大概看了一下计谋的code，如果是
     　对敌的计策，在计算成功性和杀伤率时基本上没有考虑防
     　守方的因数，(比如防守方武将这项计谋的等级，防守方武
     　将的智谋武力），我想如果能考虑上防守方武将的这些因素
     　是不是会更有意思？比如，进攻方(A方)对防守方(B方)施某
     　项计谋(C计），如果B方有武将的C计等级比A方的还高，那么
     　该计就不应该成功，如果低的话根据等级的相差数相应调整
     　杀伤力的效果，这样就可以简单的建立一种相互克制的方式．
     
     2 计谋对于战争来说永远应该只是一种辅助手段，而不是主体，
     　现在玩家上阵就用计显然就有点偏离了方向，是不是可以根据
     　玩家的智谋值确定一次战役玩家最多可以使用的次数，我想
     　最多不应超过四次．
     
     3 武将计  --在特定情况下增加杀伤力的计谋，和双方的军对人数
     　　　　　　对比比例有关．
     　智将计  --在特定情况下使敌方部队暂时丧失进攻或行动能力，
     　　　　　　和双方武将的智谋对比比例有关．
     　魅将计　--在特定情况下对自己使用以提高自己部队某些数值的能
     　　　　　　力，和自己的魅力值有关.　　


---
作者: 烈火(fire)
题目: 关于relation_d
日期: Tue Aug 22 17:08:14 2000
I have readed suicide's relation_d.c, it is a very good programming.
I think for 
those who want to learn some program skills, it is a very good sample:)

Here is some of my suggestions:
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
Anyway, relation_d is an excellent work, addoil suicide :)



---
作者: 烈火(fire)
题目: 关于relation_d
日期: Tue Aug 22 17:08:14 2000
I have readed suicide's relation_d.c, it is a very good programming.
I think for 
those who want to learn some program skills, it is a very good sample:)

Here is some of my suggestions:
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
Anyway, relation_d is an excellent work, addoil suicide :)



---
作者: 烈火(fire)
题目: suicide的设计不错，但是无法，
日期: Tue Aug 22 16:44:42 2000
解决一个人又爱财又爱色的问题。
另外性格中的注重义气和反复无常也
无法表现出来。所以可能需要一
点更复杂的设计。



---
作者: Fire
题目: >>初步对性格角色关系系统的设想:
日期: Tue Aug 22 16:16:18 2000
On Mon Aug 21 19:14:54 2000 Row wrote post #1793:
> 这是一个相当有意思的设计。玩家的性格特点如何确定呢？是完全随机的
> 吗？

the design is interesting, but lack the flexible to expand.
hmm.


---
作者: 玄冰(ice)
题目: about boy
日期: Tue Aug 22 11:05:41 2000
I think most of us knew this b4, that's if sb keep asking a boy
about somebody or xianren, then the boy will be busy, and then
all others cannot do job related to the city's NPC.

i tried to read the code, and i didn't find any time limit if
not answering boy's question.
I think we can make 2 changes if there is not time limit at present:
1. add time limit, like 20 secs sth.
2. if the time limit reached, then the boy will kick the player
and move to the next room.

though it's not the best way, but i think can be little bit
better bah.:)


---
作者: 黄帝(emperor)
题目: 我想我的设想和suicide的都有个好处，不需要专门保存CHAR间的关系度
日期: Tue Aug 22 07:30:04 2000
节约内存的消耗量，只是需要CPU运行一下测算关系度的函数来得个值。


---
作者: 黄帝(emperor)
题目: 性格建议
日期: Tue Aug 22 07:17:52 2000
suicide的设想很好，很有新意
但我想还是变化一下为好，简单的建议如下：
假设一共有9种僻好--好钱、好名、好马、好文、好武、好酒、好食、好色、
好穿。
在restart时可以随机生成一个NPC有几种爱好，从一种到几种。
玩家刚注册时也随机生成含有几种爱好。
当玩家之间或玩家和NPC间没有任何一种爱好是相同的，
则属于性格完全不同；
有一种相同的，则有些相容；
有二种相同的，有些差异；
有三种相同的，性格差不多
全部相同的，性格完全相同。


当然了以上分配方法要想配成性格完全相同的概率是极低的。
当然了以上分配方法要想配成性格完全相同的概率是极低的。

另外一种方法是：
假定有15种爱好，而每个玩家和NPC都具有10种爱好，
然后再用以上的性格匹配方法来测算他们之间性格关系。
但为了实现性格上的格格不入，需要爱好总数是CHAR的爱好数的两倍才行。
这样出现性格完全不同的概率是非常低的，便于玩家的游戏。

至于设置有多少种爱好总数，这需要用概率论来算一下，再来测算出
性格差异程度的区间划分，我想这就非常科学了。

如果只考虑玩家和NPC都只有一种爱好，那太单调了。

以上只是一些偶感，大家参考发挥。



---
作者: Ice
题目: >对于打斗系统的改动（所有code调试安装成功）
日期: Tue Aug 22 04:07:28 2000
fight also should not be available in fly_room.:) otherwise
can flood while sb is trying to arrange troops b4 war.
and I think attack can be only possible in the attacker's own
area, so that it can be said defence his own area if sb trying to
do some hurting job to his area.
hmm, or we should make it only when sb is jailed, only can attack in
the attacker's jail and the attackee must be a prisoner.


---
作者: Ice
题目: >vote close fix lah
日期: Tue Aug 22 04:03:22 2000
great.:)
massage suicide


---
作者: 威少爷(suicide)
题目: 对于打斗系统的改动（所有code调试安装成功）
日期: Tue Aug 22 02:18:43 2000
1  原fight指令和以前一样，只能在室外且需要对方答应才可．
2  现在增加一条attack 的指令，可以在任何时候任何地方（
　 不包括议事厅，我判断如果在议事厅则不允许attack）打斗，
　 且不需要对方答应．
3  fire在/std/monster/heart_beat.c 中的start_fight 函数
　 判断在室内时将没有打斗心跳，我需要注释掉这段判断的代
 　码，你可以开放这个目录的权力给我吗？或者把我放在/wiz
   /suicide目录下的heart_beat.c复制过去，源码没有改动，
   只是注释掉了那段判断语句．因为这个判断是重复的，在
   fight.c和attack.c中都已经做过判断了．　


---
作者: 威少爷(suicide)
题目: vote close fix lah
日期: Mon Aug 21 21:10:51 2000
ice
   I have fixed the vote close channel ,now 1 IP only can vote once.


---
作者: Suicide
题目: >>初步对性格角色关系系统的设想:
日期: Mon Aug 21 21:04:45 2000
nod row.
all random.


---
作者: Row
题目: >初步对性格角色关系系统的设想:
日期: Mon Aug 21 19:14:54 2000
这是一个相当有意思的设计。玩家的性格特点如何确定呢？是完全随机的
吗？


---
作者: 威少爷(suicide)
题目: 初步对性格角色关系系统的设想:
日期: Mon Aug 21 18:31:46 2000
取值范围:1-100  共100种
根据物品系统的种类,可以把这些性格分成十个大类,不同性格的角色
爱好不同的物品,以后拉拢武将就可以加入馈赠他所喜爱的物品,向太
阁立志传一样.
01-10     好钱   喜欢金钱
11-20     好名   喜欢声名
21-30     好马   喜欢马匹
31-40     好文   喜欢书籍
41-50     无求   随和,比较容易交往
51-60     无求   随和,比较容易交往
61-70     好武   喜欢武器
71-80     好酒   喜欢喝酒
81-90     好食   喜欢品尝各种美味
91-100    好穿   喜欢衣着
对于判断两个角色的性格的相似程度时,分为一下几等:
假设角色A的性格为a,角色B的性格为b
level0 if  a=b       性格完全相投  
level1 if |a-b|<10   性格基本差不多
level2 if |a-b|<20   性格有细小的差异
level3 if |a-b|<30   性格一些差异
level4 if |a-b|<40   性格不少差异 
level5 if |a-b|<40   性格很多差异,但是还能相容
level6 if |a-b|>=50  格格不入  
这样在我们判断角色A试图拉拢B的时候,效果的判断就可以用上面的等级lvl来判断,
if lvl=6  失败,无法成功
if lvl<6  then
   if random(lvl+1) ==0  成功
   else                　失败  
在我们的角色关系系统中,还有一个重要的概念是:
A和B的关系度(可理解为熟悉程度,当然这个值的增加难易由a和b决定)
怎么把关系度和性格揉和在程序判断中,我是这样考虑的:
对于前面性格相似程度等级的判断公式改为:
等级 = bmin(|a-b|,(100-关系值)),也就是取两者的绝对值.
举个例子:
如果|a-b|=60实际上意味着两者性格很不合,但是如果角色A和角色B的关系度为80,
那么100-80=20,bmin(60,20)=20,也就是说最后的结果是等级为3,而不是等级6,那
么角色A试图对角色B进行拉拢时,就不会是全失败而是一个随机random(3+1)
这样做的意图时:
    现实生活中也不是性格不同的人就无法成为朋友, 由于在我们的策划中角色的
性格在每代中是固定的, 而关系度是可变的, 如何仅仅因为是性格差异较大而使两
个角色无法走到一起, 实在有点偏颇, 如果加入考虑关系度的话, 我们可以通过设
置一些特殊的事件让两个性格相差太大的角色之间的关系度得到增加以弥补两者性
格差异过大而无法相容的弊端.
    举个最简单的应用例子，假设男角色A和女角色B试图结婚，我们可以先判断两
者的性格差异是否太大，如太大则无法结合，但是这时可以安排一些事件，让男角
色A去完成来感动女角色B，从而增加两者的关系度，最后可以冲破性格的阻碍而达
到结合的目标．
以上是我的一些想法，欢迎大家提建议．　:)
如果大家没有意见的话，我准备初步把这个系统应用在whisper和visitofficer两个
JOB上.


---
作者: Suicide
题目: >re suicde
日期: Mon Aug 21 18:30:54 2000
I have put it in /daemons lah,It isn't working now.
U can check it lah.


---
作者: 烈火(fire)
题目: re  about officer_d
日期: Mon Aug 21 16:23:50 2000
----------------------------------------------------------------------
>我觉得现在的官职要求不太合理，看现在有些新手或者一些大米，
>由于官职的要求经常是独沽一味，经常可以看到修养是75 30 30
>的角色。我记得曾经有官职要求的计划，是包含修养和天赋来决定

同意对官职要求进行一定的调整。必然作为将军，除了武力
要求外，也可以适当增加点智力和魅力的要求。但要更合理。
另外我认为不必考虑天赋，因为修养成长的速度直接和天赋有关的



---
作者: 烈火(fire)
题目: about starrock
日期: Mon Aug 21 16:18:32 2000
If anyone meet him, can ask if he is still interested
in becoming a wiz here.


---
作者: 烈火(fire)
题目: re suicde
日期: Mon Aug 21 16:17:58 2000
about the relationships' design,
please put your code under your directory first and
let us have a brief check. then we can implement
in a suitable time. 
addoil suicide :)


---
作者: Ice
题目: >更改机器人测试的时刻
日期: Mon Aug 21 02:21:34 2000
hoho, but if i just want to get literate, i just need to answer
about 10 wrong, then just keep asking for job and resign, will get
literate yah.:) better consider it in more details.:P


---
作者: 威少爷(suicide)
题目: 更改机器人测试的时刻
日期: Mon Aug 21 02:20:14 2000
【闲聊】泰山(tazan)：change to all robot test at ask job mah
【闲聊】泰山(tazan)：all same as waterflower
【闲聊】威少爷点了点头。
【闲聊】威少爷(suicide)：It is a good idea.
【闲聊】泰山(tazan)：but a lazy idea:)
【闲聊】威少爷(suicide)：No answer true No get job
【闲聊】泰山(tazan)：easy to change yah:)
【闲聊】泰山(tazan)：no job and add job counter

And change all robot-test style to sentence-style,which style i had explained 
that can not make robot to overcome,then we can control multilog.
How do u guys think about?


---
作者: 玄冰(ice)
题目: about officer_d
日期: Mon Aug 21 01:01:34 2000
我觉得现在的官职要求不太合理，看现在有些新手或者一些大米，
由于官职的要求经常是独沽一味，经常可以看到修养是75 30 30
的角色。我记得曾经有官职要求的计划，是包含修养和天赋来决定

我想重新定义官职要求的技能和天赋要求，但是需要在程序上作修改，
需要加上天赋相加和技能相加的函数，而在我定义完成后，可以取消
原来的技能函数。

我需要增加的函数大概是这样：
@OFFCER_D->set_officer(61,"gift",(["wuli"+"zhimou":30]))
我知道这个格式不对，但大概意思就是这个。

大致计划是这样的：
地方官员不衡量天赋，即天赋方面的要求相加的函数可以缺省为0，
地方武将为wxxy+bfxy
地方文官为zgxy+bfxy
国家官员除了衡量技能相加的要求之外，还要加上天赋的要求
国家武将为wxxy+bfxy及wuli+zhimou
国家文官为zgxy+bfxy及meili+zhimou
地方首领（不含初始时的太守选择）要求三项修养的相加总和。
（地方首领也未必要三项，两项也可以）

基本上是这样，如果修改完成的话，我会通过
@OFFICER_D->set_officer 来重新定义官职的要求了

同时info o xxx 的格式也需要作修改


---
作者: Ice
题目: >Re fire
日期: Sun Aug 20 23:31:36 2000
errr, sth about starrock's apply, i think we should firstly ask
his willing of joining wiz team now, then our admin have to do sth
b4 promote him, that's we must move all the posts about commercial
move into an achieve. well, maybe i take it too serious, but i think
if a fresh wiz knows this, especially he's promoted from a player, i
think it's a must do.
btw, pls move this post to achieve as well, or i should discard it.:P
regards


---
作者: 威少爷(suicide)
题目: Re fire
日期: Sun Aug 20 22:39:51 2000
1 关于fight：可以把要求对方同意才可以fight的限制取消。
  但要增加在分兵场所不能fight的限制。
RE: Agree . I will modify the code later.
  
7 关于suicide的关系度的设计。设计在技术上很有技巧性。
  但我希望能和目前的角色于国家的关系保持一致。同时也
  可以考虑加入角色性格的参数。不过这是一个大题目。
  
RE: 因为国家id实际上就是国王的id,所以保持一致很容易，
　　但是考虑到以前代码的兼容性，不然可能要修改不少
　　code，而且可能一些我们会遗漏造成不必要的麻烦，所
　　以我的想法是，保存原来角色与国家关系的结构，认为
　　它是角色和国家的一种效忠度，另外对于角色和国王而
　　言我设计的关系度就是角色对国王私人而言的关系度，
　　我想一个角色对国家和对国家的领袖有不同的忠诚度还
　　是符合实际情况的，当然角色和国王私人关系度的值大
　　小可以影响角色对国家忠诚度的增长。不知fire你以为
　　怎样，另外对于角色性格参数，我已经和ice 讨论过不
　　少了，ice 建议引入一个koei称为相性也就是性格的参
　　数，范围在1-(xxx) 之间，两角色数值相近的也就意味
    趣味相投，相差太大就意味着性格格格不入。
    
    如果你同意我以上的观点，我想我所有的code基本都已经
    准备好了，下面最重要的就是如何围绕它设计出有趣的东
    东啦。我的初步想法是在重起后，我们把NPC国王的初始性
    格按一定规则做设定，玩家的性格被重新初始后只能投靠
    性格相近的国王为官，那么就可以避免在初期就形成的一些
    大团伙减少游戏的竞争性。而且性格这个参数还可以等同与
    一种命运产生很多有意思的东西，例如玩家八字不合就无法
    结婚。。。grin。
4 关于starrock的巫师申请，我没有反对意见。如果没有人
  反对同时他还希望加入那么就吸收他好了。
RE: 我们可以给他一个考试项目，就是根据我们的关系和性格系统
　　设计一个大的有趣的plan，如果通过我们就可以吸收他做巫师
　　，这个建议怎么样?


---
作者: 玄冰(ice)
题目: jimou table
日期: Sun Aug 20 17:36:41 2000
ＩＤ          等级  使用间隔        使用要求    基本修养
jiedu         二    100            十二级      治国修养
chenzhuo      二    一秒            一级        治国修养
zhanbu        四    四百秒          三十二级    治国修养
shidu         三    300            三十级      兵法修养
fakeorder     三    400            三十五级    兵法修养
fengbian      四    三百四十秒      三十八级    兵法修养
shoushi       二    60             二十级      治国修养
scout         三    三十秒          二十五级    治国修养
tianbian      四    四百秒          四十级      兵法修养
hunluan       二    200            二十级      兵法修养
guwu          一    150            一级        治国修养
qibing        三    400            三十级      武学修养
neihong       三    300            三十级      兵法修养
sugong        三    300            三十三级    武学修养
luanshe       三    300            四十级      武学修养
fenfa         三    300            三十五级    武学修养
huangbao      三    二百秒          三十五级    兵法修养
luoshi        二    250            十五级      武学修养
jiaoma        一    100            一级        武学修养
maifu         三    三百秒          三十级      兵法修养
jbsj          二    300            十级        兵法修养

1. I cannot find the mp consumption formula, so do group.
so I think we may use the level of the jimou to indicate the
comsumption. there r 4 levels, and group expect that the
average mp of players r around 300, so we can make a basic
unit of consumping mp25, multiply by the level of jimou, so
that the jimou can be used in war should be around 6-8 times
per war, hope this can be more balanced. or adjust it later.
2. I changed some of the internal time, it's shown in the above
table.


---
作者: 烈火(fire)
题目: Re: 
日期: Sun Aug 20 16:48:00 2000
1 关于fight：可以把要求对方同意才可以fight的限制取消。
  但要增加在分兵场所不能fight的限制。
2 关于计谋：增加计谋使用次数是一个好办法。最好能
  限制为整个战役一方的计谋的使用次数而不是一员将
  的计谋使用次数。这样可以强化总统的指挥。
3 关于anti-robot，我新加了两个句子测试题库。其实构造
  新的句子题库很简单。只要在/sgdomain/robot/sentence/
  下新加一个*.txt文件。每个文件不超过十行。每行由几个
  句子组成。每个句子之间用中文逗号分开。这样就增加
  了一个新的题库。注意一点，所有的字符都要是全角的。
4 关于starrock的巫师申请，我没有反对意见。如果没有人
  反对同时他还希望加入那么就吸收他好了。
5 关于国师的设计，因为新的国师是玩家选的。所以是它
  国DUMMY的可能性不大，可以考虑适当加大国师的权利。
6 分兵问题。防守方故意慢速分兵时目前的系统是可以自动
  切换成自动分兵，所以不会造成太大的损失。至于这段
  等待时间，进攻方减低士气的问题，我会尽快解决。
7 关于suicide的关系度的设计。设计在技术上很有技巧性。
  但我希望能和目前的角色于国家的关系保持一致。同时也
  可以考虑加入角色性格的参数。不过这是一个大题目。
  addoil suicide :)



---
作者: Ice
题目: >about war
日期: Sun Aug 20 00:53:01 2000
On Sun Aug 20 00:14:17 2000 分钟(group) wrote post #1779:
> when the war begins, there should be a time limit for
> defender finish his fenbing, otherwise there will be no end 
> for the war. and when attacker waiting for the defender enter,
> there should no drop for shiqi.

support group... players complained about this, hmm, but i remember
fire said there is time limit for defence party arrange troops and during
that period, morale won't drop...

well, if it's really the same as players said, i think we need to do
the following:
1. defence party have to finish arrange troops in 8 mins, that means half day
in mud, meeting the due system will take over the arrange job and arrange as
soon as it can.
2. b4 denfence party enter warfield, attacking side's morale won't drop.


---
作者: 分钟(group)
题目: about war
日期: Sun Aug 20 00:14:17 2000
when the war begins, there should be a time limit for
defender finish his fenbing, otherwise there will be no end 
for the war. and when attacker waiting for the defender enter,
there should no drop for shiqi.


---
作者: Suicide
题目: >>about anti-robot
日期: Sat Aug 19 19:46:16 2000
多.那你提一个实际点的马上可行的啦.
admire


---
作者: Emperor
题目: >about anti-robot
日期: Fri Aug 18 06:39:48 2000
不能做robot,玩家会更少
想不让玩家做机器人的方法太多了，xixi



---
作者: Ice
题目: >about anti-robot
日期: Fri Aug 18 05:29:15 2000
hoho, if i know how to make a totally auto robot, i won't always try to
do repeating jobs by hands. i think change robot question is one of the
ways, another way is making more fun jobs, though it's a hardly achieved
goal...


---
作者: 威少爷(suicide)
题目: about anti-robot
日期: Fri Aug 18 01:11:22 2000
今天和zmud的robot高手谈了一下午,终于找到了anti-robot的方法.
几乎现在所有的机器人回答问题都是用穷举法来进行,那么对付它的方法就是
我们的问题每天一变,不要循环,那就ok啦.我看了一下现在的robot测试程序,发现
找sentence中不对的字的程序就可以现成利用,我们只要每天使用不同的语句
来源文件就可以了.
对这个我可以马上做一个简单的程序,从我机器庞大的小说堆中随机选取片断并按日期名
上传就可以了,这样就语句永远不会重复了.

当然,我不是说禁止一切robot,我只是想控制robot的使用方面,如果我们有些
重要de 
job觉得不应该让玩家使用robot我们就可以使用上面的测试程序让玩家回答,
这样不就可以控制了吗,对于我们认为玩家可以使用且可以减轻玩家负担的job
robot 我们就可以不使用这种测试程序.
robot 我们就可以不使用这种测试程序.

不知道大家对这个有什么看法,多多发言,如果同意我就写那个产生语句片断的程序,
并且希望大家提议那些东东我们应该控制玩家使用robot,我好做一定的更改.


---
作者: 分钟(group)
题目: about the jimou
日期: Fri Aug 18 01:05:34 2000
beside longer the duration, there is another way,
which is to increase the use of jingsheng for cast.
now the lv 1,2,3,4 jimou cost jingsheng is
15,20,25,30. 
ice, please summarize it and give me a plan for the cut, the duration
are list in info jimou. 
commonly player have around 200-250 jingsheng, highest condition 
is around 390-400


---
作者: Suicide
题目: >>>to group
日期: Thu Aug 17 22:24:23 2000
我想我们的目的是:
不要降低计谋的效果,否则玩家会有很大意见,但是我们可以大大限制它的可使用次数.
我想最厉害的一场战斗最多能用4次,当然这需要玩家的某项值为100.grin


---
作者: Row
题目: >>to group
日期: Thu Aug 17 21:27:19 2000
there should be time interval for 2 cast of different jimou.


---
作者: Suicide
题目: >about relation
日期: Wed Aug 23 18:32:40 2000
I am considering about it.


---
作者: 分钟(group)
题目: about relation
日期: Wed Aug 23 04:33:52 2000
suicide 的关系系统相当有趣，个人觉得是很有必要建立的。有
关多元爱好的问题，似乎可以用一个计算公式来解决。
就好比三国五的相性，由相性差别决定人物关系。
这个相性则是由喜好所决定。让每个玩家在建立资料的
时候从九种基本喜好中选择三种，然后根据这三种喜好
的相对数值--由系统预先设定或范围设定，再进行计算
以确定综合的数值。NPC则是任意选取三种，当然也要
注意NPC本身的历史，如果让关羽爱钱。。。似乎说不
过去。这一项相性值基本不会变化，在计算交流成功率
的时候再加入关系度好了。



---
作者: 威少爷(suicide)
题目: bug of whisper
日期: Tue Aug 22 22:43:51 2000
不好意思原来没有和大家交待清楚,关于whisper的问题,
因为现在whisper只要选1 2 3 4就可以降很多忠诚, 所以大家
在做whisper job的时候要主意一下,如果是建国和macro美国
那里的whisper job,请不要选1 2 3 4 , 直接选10就可以了,
如果是用的robot请每次更改设置. 谢谢.

<以上转自maggy国的 board>
我检查了一下code,有一个小bug,现在解决拉


---
作者: 威少爷(suicide)
题目: To stefan about cq site
日期: Tue Aug 22 21:25:41 2000
作者:  雨情(rainm)
题目:  to suicide
----------------------------------------------------------------------
我已经和朋友联系了，请他们提供server,如果能够成功
不知道suicide 是否同意open new site? 并将所有的cq id 转到新站？
               ------------ rainm


---
作者: 威少爷(suicide)
题目: Re fire about relation_d
日期: Tue Aug 22 21:10:33 2000
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
RE:It is a two way relation between any chars.
  
  
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
RE: I have modified the code by add a new function called:
    add_both_relation(id1,id2,add)
    now it runs like this lah.
  
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
RE:I have modified the code ,now it runs like this lah.
  
  
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
RE: Can we consider about this later for coding such a functon will be so
    technical ,we should consider deeply about it. I think the most important
    thing now is to plan how make this relationship into apllication.:)
    
  
  
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
RE:I have used exploade function in my code lah,but implode is not used.


---
作者: Suicide
题目: >关于relation_d
日期: Tue Aug 22 19:20:09 2000
I will consider about this.

BTW: ice, i have added no attack in fly room. Now both fly room and
meeting room
     can't attack lah..


---
作者: Stefan
题目: >to stefan
日期: Tue Aug 22 18:36:37 2000
On Tue Aug 22 18:09:32 2000 威少爷(suicide) wrote post #1807:
> Cq mirror's local admin want to close my mud for system resource lack.
> Can u communicate with xyx to get a idea how to settle those guys
> playing in cq mirror
> All put them to zj site?

actually chengdu guys are contacting me to set up 
mirror. I think I will negotiate a mirror transfer.
But not sure yet.


---
作者: 威少爷(suicide)
题目: to stefan
日期: Tue Aug 22 18:09:32 2000
Cq mirror's local admin want to close my mud for system resource lack.
Can u communicate with xyx to get a idea how to settle those guys
playing in cq mirror
All put them to zj site?


---
作者: 威少爷(suicide)
题目: cq site will close
日期: Tue Aug 22 17:49:46 2000
suicide你好：
    三国是个很好的mud，构思新颖，设计独到。它开创了MUD的新纪元。
    希望你能体谅我这边的处境。三国消耗的硬盘空间和内存空间已经
危机到了WLZB。而且WLZB的玩家不断增加，SGZ也在不断的膨胀。现在服
务器空闲资源所剩无几。
    就我个人而言希望SGZ能一直开下去。但是由于种种原因，我不得不
做出痛苦的决定，关闭三国重庆分站。请处理善后事宜，并通知我具体
闭站时间。
    这些时间我们合作非常愉快，希望有机会再次合作。


---
作者: 烈火(fire)
题目: about heart_beat
日期: Tue Aug 22 17:16:18 2000
I commented that code according to suicide's suggestion.
so to check if can fight will start from the cmd
not from the fight itself, this maybe a good idea. but becareful :)


---
作者: Fire
题目: >to fire
日期: Sun Aug 27 16:23:20 2000
On Thu Aug 24 19:19:56 2000 威少爷(suicide) wrote post #1821:
> fire:
>   add a time limit bah when defence side arrange troop,or when war
> defence side
> will 拖延时间.

Now there is a time out for each input, seem we still need a time
for the whole process. I will modify it. addoil :)


---
作者: 玄冰(ice)
题目: about wiz.committee
日期: Sun Aug 27 07:42:07 2000
no one go wiz.committee to give opinion of promoting chun?


---
作者: 威少爷(suicide)
题目: about whisper job
日期: Sun Aug 27 06:52:33 2000
我想对whisper再做一次修改,想法如下:
1,2,3 de 
1,2,3的恭维天赋的选项只和npc的天赋挂钩,和他的忠诚无关.
6,7,8的判断条件都是一样的,属于重复,我准备修改其中一项死亡威胁
为促膝谈心,判断条件是双方的性格差异值.

不知大家有何意见?
另外我已经假如了性格这个参数,我按照ice的意思给了个"八字(bazi)"的属性id.
@ CHAR_D->get_char("suicide","bazi") 范围暂时是1-100,如果角色还没有该
值系统会自动初始一个产生.


---
作者: Stefan
题目: >To stefan
日期: Sun Aug 27 05:03:46 2000
On Sat Aug 26 07:24:01 2000 威少爷(suicide) wrote post #1825:
> It is so strange that when mirror reboot ,always some files
> corrupt,thus they can't be used
> Cause a lot of bug,can u check why?This condition has appear for some times.
> Now even i am afraid of rebooting at mirror.

But I think I've fixed this bug? For unknown reasons, some
files on our main server concerning mirror setup always
get corrupted :PPP I've added some fix to it, not sure ihow well it works
now...


---
作者: 威少爷(suicide)
题目: To stefan
日期: Sat Aug 26 07:24:01 2000
It is so strange that when mirror reboot ,always some files
corrupt,thus they can't be used
Cause a lot of bug,can u check why?This condition has appear for some times.
Now even i am afraid of rebooting at mirror.


---
作者: Stefan
题目: >to stefan
日期: Fri Aug 25 21:53:48 2000
On Wed Aug 23 23:27:27 2000 威少爷(suicide) wrote post #1816:
> One guy in cq mirror want to apply a server to transfer all data
> there,if cq mirror will close
> ,stefan,would agree this sute?
> 题目：about apply mirror 
> ---------------------------------------
> 我朋友那里的工作站是SUN U1
> 我刚看过有关三国的mirror site apply ,可以是Solaris呀
> sun 工作站装不了linux ,但我想solaris 没问题吧，
> 请suicide 考虑，如果我不在线，请去cq 站找zhenzhue 或是guoyi都可以
> 多谢了。thank suicide
>  ----- rainm

We can not support Solaris currently, because the old
machine was removed :PP


---
作者: Ice
题目: >sth about suggestion
日期: Fri Aug 25 04:22:02 2000
On Fri Aug 25 00:14:05 2000 威少爷(suicide) wrote post #1822:
> 今天我发现有些玩家，在短时间内通过localmeeting的localtax 和sendfood
> 还获得honour,现在我们对suggestion的限制是一人一天最多提21个建议，
> 那么他就能在很短的时间内获得4k honour,所以不知道大家觉得这需不需要
> 调整一下，把对人的限制改成对地区的限制，譬如某地一天只能提21个建议
> 大家怎么看？

i think 10 per person, and 20 per area will be fine.:)
however, the actual limit of 10 will be 11, also 20 will be 21.:P


---
作者: 威少爷(suicide)
题目: sth about suggestion
日期: Fri Aug 25 00:14:05 2000
今天我发现有些玩家，在短时间内通过localmeeting的localtax 和sendfood
还获得honour,现在我们对suggestion的限制是一人一天最多提21个建议，
那么他就能在很短的时间内获得4k honour,所以不知道大家觉得这需不需要
调整一下，把对人的限制改成对地区的限制，譬如某地一天只能提21个建议
大家怎么看？


---
作者: 威少爷(suicide)
题目: to fire
日期: Thu Aug 24 19:19:56 2000
fire:
  add a time limit bah when defence side arrange troop,or when war
defence side
will 拖延时间.


---
作者: 威少爷(suicide)
题目: what's wrong?
日期: Thu Aug 24 19:18:44 2000
 61                               *** 邮件丢失！ ***
 62                               *** 邮件丢失！ ***


---
作者: 烈火(fire)
题目: please read post in
日期: Thu Aug 24 16:15:36 2000
wiz.committee
it seem you can't auto read it if use news
hoho :)


---
作者: Suicide
题目: >about attack
日期: Wed Aug 23 23:39:13 2000
If changing code like u said ,it will be a large work,so trouble.
So can we just let it be? If some guy abuse using this then i try to 
limit it ,ok?


---
作者: 威少爷(suicide)
题目: my idea
日期: Wed Aug 23 23:35:41 2000
我想把所有job的效果和玩家的某项技能挂钩,但是成功率的公式不变.
这样newbie或则dummy做job的收效就会不大,但是还能成长,用来减少过多dummy的危害
不知大家有什么意见?


---
作者: 威少爷(suicide)
题目: to stefan
日期: Wed Aug 23 23:27:27 2000
One guy in cq mirror want to apply a server to transfer all data
there,if cq mirror will close
,stefan,would agree this sute?
题目：about apply mirror 
---------------------------------------
我朋友那里的工作站是SUN U1
我刚看过有关三国的mirror site apply ,可以是Solaris呀
sun 工作站装不了linux ,但我想solaris 没问题吧，
请suicide 考虑，如果我不在线，请去cq 站找zhenzhue 或是guoyi都可以
多谢了。thank suicide
 ----- rainm


---
作者: 玄冰(ice)
题目: about attack
日期: Wed Aug 23 19:24:40 2000
I think attack now is just like fight b4, can fight inside and
outside, and can also attack npc to gain exp. I think it's just
erasing the effort of fight.
the effort of fight is:
1. fight npc to gain exp.
2. cannot fight in indoor room.
3. fight online player will need opponent's agreement.
I think attack should not be the same as fight, so i have
2 alternative suggestions:
1. attack is only can be used in jail room, and the attackee must
be caught by sb, so the meaning of attack is like 严刑拷打.

2. make attack cannot gain exp anyway, and also it'll be better
can only attack others in the attacker's own area. socall his
地头，可以横行无忌。


---
作者: Fire
题目: >分析数据包的软件是NetXray.
日期: Thu Oct  5 18:03:22 2000
On Thu Oct  5 06:46:37 2000 黄帝(emperor) wrote post #10008:
> 《天下》的图形不错啦。在ping的速度差不多的情况下，他的速度要比KK快多了。
> 只是人物的图片frame做得太少，而且没有象KK那样华丽的魔法效果。但总体感觉
> 比《人在江湖》做得强许多。《天下》比KK要流畅，只是内容没KK的好，内容策划
> 显得杂乱无章。图形MUD的客户端还是有其可取之处的。
> 用个HEX文件编辑器看看tx.exe，能看到客户端设计的许多内容。

thanks ;P


---
作者: 黄帝(emperor)
题目: DirectX7.0a是个好东西。
日期: Thu Oct  5 06:56:03 2000
DirectX7.0a支持Visual Basic，下载个完整SDK包，里面含有
详细的VC和VB的帮助文件。
用VB设计图形MUD的client，我想要比VC的简单。我现在正在仔细
阅读directX的VB方面的help。
感兴趣的可看看。


---
作者: 黄帝(emperor)
题目: 分析数据包的软件是NetXray.
日期: Thu Oct  5 06:46:37 2000
《天下》的图形不错啦。在ping的速度差不多的情况下，他的速度要比KK快多了。
只是人物的图片frame做得太少，而且没有象KK那样华丽的魔法效果。但总体感觉
比《人在江湖》做得强许多。《天下》比KK要流畅，只是内容没KK的好，内容策划
显得杂乱无章。图形MUD的客户端还是有其可取之处的。
用个HEX文件编辑器看看tx.exe，能看到客户端设计的许多内容。


---
作者: 烈火(fire)
题目: help suicide.
日期: Wed Oct  4 23:09:02 2000
hi suicide,
I find a piece interesting vc code on the internet
the url is http://tech.sina.com.cn/soft/2000-09-28/778.html
but when i test it, I find it miss some part and I don't
know how to fix it. When you have time, could you please
try this and if you can fix the problem, please email me
a copy. hoho :)

Regards,



---
作者: Fire
题目: >>一个武侠图形MUD
日期: Wed Oct  4 21:02:02 2000
I played it. 
It's not too bad, only the movement is a little bit slow
compared to diablo, the play is not so fluent.


---
作者: Stefan
题目: >一个武侠图形MUD
日期: Wed Oct  4 19:16:45 2000
On Wed Oct  4 08:07:01 2000 黄帝(emperor) wrote post #10003:
> 这两天花了7个小时从http://www.21cntx.com下载了
> 武侠图形MUD的客户端。并上线玩了7、8个小时，同时分析
> 了这个MUD的通讯协议。这个MUD从今年年初开始设计，花了
> 9个月的时间做成的效果和万王之王差不多，但还有一些差距
> 。但这个MUD给我们带来的启示很大。值得去看看。现在我手
> 上有了两个MUD的数据通讯协议。我想我们还得加油呀。

I played it about two weeks ago, but the site was directing me to
netease.com :PPPP

Anyway, it is not an very interesting mud, graphics is the
worst compared to KK and SanGuo.


---
作者: Fire
题目: >一个武侠图形MUD
日期: Wed Oct  4 15:52:47 2000
On Wed Oct  4 08:07:01 2000 黄帝(emperor) wrote post #10003:
> 这两天花了7个小时从http://www.21cntx.com下载了
> 武侠图形MUD的客户端。并上线玩了7、8个小时，同时分析
> 了这个MUD的通讯协议。这个MUD从今年年初开始设计，花了
> 9个月的时间做成的效果和万王之王差不多，但还有一些差距
> 。但这个MUD给我们带来的启示很大。值得去看看。现在我手
> 上有了两个MUD的数据通讯协议。我想我们还得加油呀。
它的通信协议是什么样的，能不能简单介绍一下。
另外，用什么工具可以劫获一个软件通信的输入
和输出。
拜托啦。:)


---
作者: 黄帝(emperor)
题目: 一个武侠图形MUD
日期: Wed Oct  4 08:07:01 2000
这两天花了7个小时从http://www.21cntx.com下载了
武侠图形MUD的客户端。并上线玩了7、8个小时，同时分析
了这个MUD的通讯协议。这个MUD从今年年初开始设计，花了
9个月的时间做成的效果和万王之王差不多，但还有一些差距
。但这个MUD给我们带来的启示很大。值得去看看。现在我手
上有了两个MUD的数据通讯协议。我想我们还得加油呀。


---
作者: Group
题目: >>about news_d
日期: Wed Sep 27 01:17:22 2000
that is not bug lah, rRfFis only for the post you read, so
not necessary to appear before you read any post.


---
作者: Ice
题目: >about news_d
日期: Wed Sep 27 01:06:14 2000
(wiz.com:1851) 201 条留言 1 条未读 [q?lLmgpnc] > 
//it's b4 I read this post...
(wiz.com:10000) 0 条剩余 [q?lLmgprRfFncMD] > 
//it's after... still some bugs mah
addoil


---
作者: 烈火(fire)
题目: about news_d
日期: Wed Sep 27 00:42:06 2000
I make some modification in news_d
the two big part is
1 use a new mapping to hold the last id, it is better to use the group
  to host last id
2 i find the time to save the whole post is not too much so 
remove the function of save recent. it make the program too difficult
to read.



---
作者: Suicide
题目: >about farm news
日期: Thu Sep 21 19:45:55 2000
agree with fire.
every updateing area_d.c will cause the areas turn changed maybe.
In my npcai_d.c , i keep a log of all areas in data file,
so its turn will never changed.


---
作者: 烈火(fire)
题目: about farm news
日期: Thu Sep 21 19:09:31 2000
I think that bug may come from area d
in area_d it has a function to retrieve an area id.
this list may be affected by some other program so some times an
area can't be retrieved
or some area has been retireve more than one times during one rand.
in order to solve that problem. we can update area_d.
but why that list is affected is still mysterious.
hmm


---
作者: 分钟(group)
题目: bug in farm
日期: Thu Sep 21 00:55:55 2000
as templar reqest, i can be vitness that changan farm's ganjing drops
extremely fast. as i saw at 2:40 this afternoon, it is 100, when i saw it
at 3:40, it becauses 28.

please check check bah... i looked the code and cant find where is
the place...:P

addoil

group


---
作者: 斯坦福(stefan)
题目: bug
日期: Wed Sep 20 23:37:13 2000
题目：你像是疯了般地大喊：完了，全完了！ 
---------------------------------------
changan farm has bug again, like the previous one in noise's taiyuan last
generation
鼓干劲has no use
now we get back hanzhong, otherwise changan xiangyang 100K footman will starve
to death
i have told group, ice but still no response
pls check and help to solve this bug
beg
bow
                                      templar


---
作者: 威少爷(suicide)
题目: about 胜利条件
日期: Wed Sep 20 17:09:52 2000
你说道：不过进攻方要杀死敌方全部部队太苛刻了.
你说道：应该攻入城墙就算胜利
你呵呵地笑了几声。
明月说道：可以设个比例
>明月说道：杀2/3以上再占城市就算胜利


---
作者: 威少爷(suicide)
题目: about tune gold incoming
日期: Wed Sep 20 16:30:18 2000
明月说道：4级城市,满人口满安定金入大概15000
明月说道：减少为5000,就很吃紧了
明月说道：满员农场占1000
你点了点头。
明月说道：剩下4000养40000兵,或者只好发展商业


---
作者: 黄帝(emperor)
题目: ?
日期: Sun Sep 17 08:30:57 2000
用lima来连接数据库怎么样？我在自己机器上成功编译了MUDOS+mSQL.


---
作者: 烈火(fire)
题目: sorry about the post
日期: Fri Sep 15 00:45:32 2000
this week really no time.
I will do it next week.
sorry to all


---
作者: Stefan
题目: >the web server
日期: Thu Sep 14 21:01:49 2000
oops, that was a mistake, I've put it back :PPP


---
作者: 烈火(fire)
题目: the web server
日期: Thu Sep 14 17:57:55 2000
now i find the www.gime.org and sgz.gime.org direct to the same place
so where is the sgz's main site ?


---
作者: 黄帝(emperor)
题目: graphical mud
日期: Wed Sep 13 03:15:55 2000
石器时代： www.waei.com.tw
网络三国： www.chinesegamer.net
人在江湖： www.gameking.net.cn/rzjh-new/
万王之王： www.kok.com.cn
天堂    ： www.lineage.com.tw
永恒任务： www.station.sony.com/everquest/
Asheron's Call ：www.microsoft.com/games

在www.waei.com.tw还能找到其他图形MUD的连接

其他一些忘了


---
作者: 斯坦福(stefan)
题目: to emperor
日期: Tue Sep 12 21:58:18 2000
please post those graphical mud address again, thanks!!


---
作者: 烈火(fire)
题目: about posts
日期: Tue Sep 12 17:11:28 2000
hi all,
I find that our news sysem is really sucked
I will rewrite the news_d and make it clear in this week
cheers


---
作者: Ice
题目: >addoil suicide and chun
日期: Wed Aug 30 17:13:55 2000
On Wed Aug 30 15:58:29 2000 烈火(fire) wrote post #1836:
> make the gini more fun and useful. hoho :)

addoil addoil.:) 


---
作者: 烈火(fire)
题目: addoil suicide and chun
日期: Wed Aug 30 15:58:29 2000
make the gini more fun and useful. hoho :)


---
作者: 威少爷(suicide)
题目: to ice
日期: Tue Aug 29 23:54:23 2000
I check the file of /log/help_miss,then i know u had faq 定居 ....
So i have added a hint of 定居, u can check again.
From this u can know how the gini helper works.
:)


---
作者: 威少爷(suicide)
题目: about 新手帮助精灵
日期: Tue Aug 29 23:33:37 2000
新手帮助精灵程序修改完毕.
为了方便新手入门，特别是那些英文差的新手，chun和我在fire的精灵系统
上做了一些改动，完成了现在的新手帮助精灵．
功能: 每隔一段时间，精灵自动进行随机动作或说提示．为了防止flood，我
　　  把精灵的心跳调慢，现在基本上是两分钟一次，并且除了精灵的动作外
　　　其他所有的显示只有精灵的主人能看见．另外我为了帮助英文不好的玩
　　　家查阅help，特地增加了一个gini faq的功能，我们把一些经验之谈的
　　　中文句保存在gini_d的hints 中，这样当新手试图查阅主题时就会先从
　　　sghelp系统中查找，如果没有再从hints中查找有无对应的单词，如果有
　　　则把对应的hint句子显示出来，如果两者都没有查到则新手试图查找的
　　　主题会保存在/log/help_miss中，这样我们巫师每天上线可以查阅这个
　　　log 文件，并且增加对应的hint到gini_d中，这样随着hints 的不断增
　　　长我们的精灵就等于有了半自动学习功能，并且能够越来越有效根据新手
　　　输入的中文主题给出对应的help．
为了把这个hint学习的事情说清楚我现在举个例子：
    假设现在有个英文很差的新手来到了我们mud ，他首先可能想知道钱的来源，
但由于他不知道钱的英文是money ，那么他肯定就无法用help money来获得他想
要得到的信息．这是他可以利用精灵 gini faq 钱  来查询，在我们的hints 中
我已经加入了这样一项：
　　”这个mud上的金钱，玩家之间不能互相给与，只能靠自己做工作或者以后做
官拿薪水。详细情况你可以参见：help money   help job  help basicjob”
    那么玩家输入的钱这个主题在这句话中可以得到匹配，于是这个hint就会显示
给玩家，他同时也就知道可以用help money help job help basicjob去获得更详细
的信息了．
    假如玩家这是又输入 gini faq 食物，而我们的hints 中没有有关食物的项，并
且在sghelp中也因为是中文主题肯定无法获得，这是精灵就会提示：
    "主人，你问我的东西我也不太懂哦，不过我可以帮你问巫师．
    "估计你下次上线的时候就可以知道了."
    
并且同时纪录一条失败查找纪录到/log/help_miss 文件中并且同时出现在announce频
道中，这样我们巫师就可以增加一条新的hint:
    "食物主要是靠钱买的，在你没有钱的时候可以找华阴村的厨娘要(ask chu niang 
     about food )，另外当你以后做大官发了财还可以雇厨师提你做．详细情况可以
     参见：help 
    
这样随着我们hints 的不断增长，我们的精灵就可以基本上回答新手大多数问题．
说明：对于精灵系统原来对玩家开放的一些功能象：更换精灵类型、命令精灵做事等等
　　　我都暂时禁止了，因为这些对于新手帮助精灵都用不上，我准备在宠物系统的二
　　　期扩展项目时才陆续开放这些功能给玩家，并且再增加一些有趣的功能。另外我
　　　现在还禁止玩家把新手帮助精灵带出华阴，免得大家搞的都是精灵。在以后宠物
　　　系统的扩展中可以撤销这个限制，让玩家把宠物带回家，没事可以玩玩宠物养成
　　　类游戏。;)
精灵类型：由chun设计，现在刚刚加了个小狗，以后希望chun能陆续加入一些有趣的动物
　　　猫、鹦鹉、老鹰、大象、狮子、老虎、蛇等等等等。
不知大家对这有什么意见，欢迎大鸣大放，我好及时更改。如果没有什么意见，我就准备
设计向新登陆的玩家开放了。
　　　


---
作者: 威少爷(suicide)
题目: re chun about how to set multilines describe of gini 
日期: Mon Aug 28 23:12:41 2000
if u want to set the setting of birth use like this :
"to gini addact birth" ,then just input multilines,it should be ok.


---
作者: 威少爷(suicide)
题目: about whisper
日期: Sun Aug 27 21:37:05 2000
把"高官诱惑"改成了"促膝谈心",判断两个角色的性格八字来判断成功率.


---
作者: 威少爷(suicide)
题目: about whisper
日期: Sun Aug 27 21:33:49 2000
把"高官诱惑"改成了"促膝谈心",判断两个角色的性格八字来判断成功率.


---
作者: Row
题目: >>about create discussing group.
日期: Sat Oct  7 08:50:54 2000
On Fri Oct  6 23:08:35 2000 Ice wrote post #10013:
> ice_sgz@elong.com
> 
> addoil suicide.:)
> 
> btw, I bought a 网络三国 today, didn't try it yet, but I heard it
> need 2G HD space.^_*, anyone wanna try it, i can mail it away...
raise row
what's the basic configration of that game?


---
作者: Row
题目: >about create discussing group.
日期: Sat Oct  7 08:49:32 2000
my e-address: lau_roger@hotmail.com


---
作者: Stefan
题目: >about create discussing group.
日期: Fri Oct  6 23:08:55 2000
On Fri Oct  6 22:22:16 2000 威少爷(suicide) wrote post #10012:
> Hi! all guys:
>    I will create a discussing group for our wiz group in egroups.com.
> I need ur email address to make u be the member of this group.
>   Can u guys post ur own email address here ,so i will add it,
> then we can discuss problems just using email,even no need  
> login here to post .
>    I think it can improve the efficiency of our groups.

I created a group a long long time ago, was never used
by anyone. we can use that :P


---
作者: Ice
题目: >about create discussing group.
日期: Fri Oct  6 23:08:35 2000
ice_sgz@elong.com

addoil suicide.:)

btw, I bought a 网络三国 today, didn't try it yet, but I heard it
need 2G HD space.^_*, anyone wanna try it, i can mail it away...


---
作者: 威少爷(suicide)
题目: about create discussing group.
日期: Fri Oct  6 22:22:16 2000
Hi! all guys:
   I will create a discussing group for our wiz group in egroups.com.
I need ur email address to make u be the member of this group.
  Can u guys post ur own email address here ,so i will add it,
then we can discuss problems just using email,even no need  
login here to post .
   I think it can improve the efficiency of our groups.


---
作者: Suicide
题目: >help suicide.
日期: Fri Oct  6 03:14:00 2000
I will try to do this after the nation's holidays.


---
作者: 威少爷(suicide)
题目: To emperor
日期: Thu Oct 19 18:38:50 2000
How about ur newbie system?
Andwhy not i can't hear ur voice in egroups?
I need ur help!!!!!!!!!!!!


---
作者: Emperor
题目: >train系统分析
日期: Thu Oct 19 06:16:57 2000
agree suicide.
预先分兵有好处。但应该避免一些由此带来的新问题。


---
作者: 威少爷(suicide)
题目: train系统分析
日期: Wed Oct 18 18:46:48 2000
train的过程:
为方便叙述,DIR定义如下:
   WAR    目录=/sgdomain/event/war
   WARAI  目录=/daemons/warai_d
   EVENT  目录=/sgdomain/event
   DAEMONS目录=/daemons
   LOCALMT目录=/sgdomain/event/ev_localmeeting
   SGCMD  目录=/sgdomain/cmd  
1 SGCMD/train.c start()函数
2 LOCALMT/suggestion.c get_suggestion()函数
3 EVENT/ev_localmeeting.c  meet_over()函数
4 WAR/train.c train()函数
  train()函数功能:
  a)  创建TT_TRAIN的task
  b)  初始化战争log(WARAI_D->create_inf(t_num) 见WARAI/display.c)
  c)  增加战争地图(MAP_D->add_city(p_area))
  d)  设置task的初始步骤为TRAIN_BEG
  e)  调用train_arrange函数(见WAR/train_beg.c),功能简介:
      e.1)继续做task的初始设置def_general_left参数
      e.2)调用def_pre_arrange函数(见WAR/def_arrange.c),功能简介:
          e.2.1)用来设定task中的初始部队参数,如果时TT_WAR的task计算民兵数
5 由TASK_D调用train.c中的train_process函数启动train各个步骤:
  a)第一步TRAIN_BEG:
    a.1)调用train_collect函数(见WAR/train_beg.c),功能简介:
        a.1.1)根据task中def_general_left参数,将所有参加训练的将领移到兵营
    a.2)设置task的第二个步骤为TRAIN_PROCESS.
  b)第二步TRAIN_PROCESS:
    b.1)累加task中的curtime值,该参数用于检查训练任务是否超时.
    b.2)调用check_question函数(见WAR/train_check.c),功能简介:
        b.2.1)检查训练中各个任务问题的完成执行情况,得到返回值:
        b.2.2)根据返回值,做不同的处理
              QUESTION_PROCESS:   训练任务正在执行中,继续轮训.
              QUESTION_OVER_DUE:  训练任务完成超时,产生新的训练任务
              QUESTION_FAIL:      部队因故未进入战场,进入TRAIN_END步骤
              QUESTION_SUCCESS:   训练任务完成成功,产生新的训练任务
              NO_QUESTION:        现在没有任务,产生新的训练任务
        b.2.3)试图产生新的训练任务,成功则人在TRAIN_PROCESS阶段,因为所有
              训练任务都已经完成而造成无法产生新训练任务,则进入TRAIN_END
              阶段
    b.3)question_new任务产生函数(见WAR/train_new.c)功能简介:
        b.3.1)根据训练任务类型设置该任务的完成限定时间和其他有关参数.
        b.3.2)对一些特定的任务类型调用一些特定的入口.
              第一个训练任务分兵arrange任务,调用man_input(p_leader,t
ask_id,"d")
              函数(见/sgdomain/menu/warinput)
  c)第三步TRAIN_END阶段:
    c.1)调用train_over函数(见WAR/train_over.c),功能简介:
        c.1.1)调用release_army函数(见WAR/abort.c),删除所有troop object,
              并且纪录下进攻和防守双方的最后兵力.删除战场地图MAP_D->
destruct_area(area);
        c.1.2)设置task进入AFTER_TRAIN步骤.
        c.1.3)检查训练任务的完成成功和失败次数,如果前后着差值<=0,则
              简单的删除该task结束否则回答robot_test问题,调用big_reward
              函数(见WAR/train_over)奖励训练主将和参与训练的将军,然后删
              除该task.
              
  d)第四步AFTER_TRAIN阶段:
    d.1)调用release_army函数(见WAR/abort.c),删除所有troop object,并且
        纪录下进攻和防守双方的最后兵力.删除战场地图MAP_D->destruct_area(area);
    d.2)删除该训练任务.
  (实际上第四步是不可达的,因为它是在TRAIN_END步骤后10分钟才被执行,而
   第三步即使因为回答超时后才删除task所要的时间远远不到10分钟,task在
   10分钟不到的时间内被删除,所以第四步永不可达,况且如果可达的话反而会
   因为第三第四步都试图删除task而导致程序出错bug)
fire,不知我上面的分析又有什么疏漏或错误的地方,望斧正.
ice, 可以帮我收集收集平常在训练碰到的还没解决的bug吗,这样我希望我在第
     一步的train改造项目中解决它.
对于train系统基本上我不做什么改动,不过会调整个函数在程序中的分布位置,
达到易读易理解的目的,war系统有许多bug都出自与分兵系统,我想把它改造成
--预分兵系统,也就是说部队的分配不是战时临时分配,而是在平时就将部队交
于将军统领,向过去的老三国三代一样,这样上战场时只要指定上阵的将军就行
了,不知大家意下如何?


---
作者: Stefan
题目: >>wiz site is created
日期: Sat Oct 14 04:53:26 2000
On Thu Oct 12 19:25:26 2000 Suicide wrote post #10028:
> I can't login with id "suicide" ah,can u cp our data file their stefan?

problem solved, please try again :)


---
作者: Suicide
题目: >wiz site is created
日期: Thu Oct 12 19:25:26 2000
I can't login with id "suicide" ah,can u cp our data file their stefan?


---
作者: 斯坦福(stefan)
题目: wiz site is created
日期: Thu Oct 12 05:46:20 2000
on port 5454.

No player login, no new player registration. 

All please try, if you have problems, please let me know.


---
作者: Suicide
题目: >>>>To fire
日期: Tue Oct 10 17:44:08 2000
nothing.hoho.addoil.
BTW:Have u recieved my mail from egroups?


---
作者: Fire
题目: >>>To fire
日期: Tue Oct 10 16:53:54 2000
On Tue Oct 10 02:57:41 2000 Suicide wrote post #10024:
> I have put it in /wiz/suicide,named src.zip
I got it, thank you.
hoho:)
the problem i meet is I don't know splashwnd is inserted
by a predefined conmponent.
I think I should create a class of that. blash.

Thank you very much. xixi :)


---
作者: Suicide
题目: >>To fire
日期: Tue Oct 10 02:57:41 2000
I have put it in /wiz/suicide,named src.zip


---
作者: Fire
题目: >To fire
日期: Mon Oct  9 15:52:44 2000
On Sat Oct  7 21:31:52 2000 威少爷(suicide) wrote post #10017:
> Fire:
>     I have modified that code u told me to check,it runs ok now.
> I just modified serveral sentence.
>   There is a 笔误 in sentence :
>     strcpy(lf.lfFaceName,sFaceName.GetBuffer(sFontName.GetLength()));
>  *** sFaceName should be sFontName
>  *** And u should declare the function "DrawText() and WindowProc" 
>  *** in head file Splash.h,then everything will ok.
> 
> BTW: fire,just try bah,if u still have problem,just tell me,
>     I will mail u the source code.

Hi suicide
, the typo you metioned I know already but it still not working.
please send me your source code bah :)
xixi
thank
bow


---
作者: 分钟(group)
题目: email
日期: Sun Oct  8 22:51:54 2000
snow_zf@hotmail.com
sorry, a little busy recently


---
作者: Row
题目: >>>>about create discussing group.
日期: Sun Oct  8 22:07:42 2000
escape ice


---
作者: Ice
题目: >>>about create discussing group.
日期: Sun Oct  8 17:10:04 2000
kick row, u can buy it in 连邦 just for RMB 29 mah. I was talking to those
guys overseas...
nip
ps. I was meaning ordinary mail delivery, but not email...


---
作者: 威少爷(suicide)
题目: to all
日期: Sat Oct  7 21:45:18 2000
请问大家有没有收到我给大家发的第一封egroups的mail?
我用的是finger你们得到的email地址，group没有，所以不会收到


---
作者: 威少爷(suicide)
题目: To fire
日期: Sat Oct  7 21:31:52 2000
Fire:
    I have modified that code u told me to check,it runs ok now.
I just modified serveral sentence.
  There is a 笔误 in sentence :
    strcpy(lf.lfFaceName,sFaceName.GetBuffer(sFontName.GetLength()));
 *** sFaceName should be sFontName
 *** And u should declare the function "DrawText() and WindowProc" 
 *** in head file Splash.h,then everything will ok.

BTW: fire,just try bah,if u still have problem,just tell me,
    I will mail u the source code.


---
作者: 分钟(group)
题目: careful
日期: Tue Nov 21 22:34:47 2000
today the guy who steal xiaobai and others passwd come and ask my passwd.
he pretend to be 斯坦福(ste)回答你：小钟
.... dont want to waste time on him, however please be careful 
sigh
oh, his ip is 61.136.141.81


---
作者: 威少爷(suicide)
题目: to stefan
日期: Tue Nov 21 19:42:36 2000
Pls reboot bah when u login, it is a long time that it haven't reboot .


---
作者: 威少爷(suicide)
题目: about install auto arrangement
日期: Fri Nov 10 20:49:33 2000
I have added a switch in new arrangement system to decide if a
area uses new arrangement system.

if @AREA_D->set_area(p_area,"arrange_type",1) then will use new system
else @AREA_D->set_area(p_area,"arrange_type",0) then will use old system


---
作者: 威少爷(suicide)
题目: auto arrangement system modified ok
日期: Fri Nov 10 20:47:55 2000
修改备案:
def_arrange.c,//修改自动分兵的算法,使其达到最高效率
train.c,        //将train_beg.c中的void train_arrange(int task_id)
                //函数移至train.c中,并且按武力sort参加训练的将军
def_meeting.c , //按武力sort参加战争的将军
def_meeting.c , //按武力sort参加战争的将军
train_beg.c ,   //注释掉void train_arrange(int task_id)函数
def_input.c     //sort兵种,保证分兵的次序按兵种ID顺序排列.


---
作者: Suicide
题目: >to chun
日期: Sun Nov  5 17:11:06 2000
My english is not very well , if u don't get my meanings, pls tell me


---
作者: 威少爷(suicide)
题目: to chun
日期: Sun Nov  5 17:10:08 2000
There r two function related things what we want to keep it when relogin.
One is set_is_keeping(1),this allow u will not auto drop this when u quit.
Another important one is no_give_npc(),this allow u will not auto give this 
thing to ur alternative npc when u quit, then this thing will be kept
in ur body object.
Thus when u relogin this thing will be kept. You can check these 2 functions
in /sgdomain/home/homekey.c

chat haven't finish yest.
You maybe think i haven't used these 2 funnctions ,why it works well ah?
Actually ur code doesn't work wellm let me explain it.
When u quit,u will auto give lamp to ur alternative npc,then u relogin,
for ur alternative npc object is still in, u will auto swap 
from npc to body,then lamp will transfer from ur npc object to ur body.
But if before u relogin, i dest ur npc object,then u relogin
u will find ur lamp will disappear, u can try it.

Your another question about "不显示哨子而显示神灯" is that u should 
added some judge before set_id , for example :
private gini_type
if gini_type == "dog"  set_id("shao zi","哨子");
else set_id("gini lamp","神灯")

add_save("gini_type");
add_save("gini_type");

void set_type()
{
gini_type = xxxx
}


---
作者: 烈火(fire)
题目: busy and busy
日期: Thu Nov  2 23:48:42 2000
I will be very busy next month
a demo for December
so I may not come frequently
sorry all


---
作者: 小纯(chun)
题目: I got it, suicide :)
日期: Wed Nov  1 20:36:23 2000
Thanks very much to suicide :).
I have cleaned gini.o to remove a accidentally added void type.
I will use the test site for add more types, this really
make things easier to be done :).

chun


---
作者: 威少爷(suicide)
题目: to stefan
日期: Wed Nov  1 19:19:49 2000
Hi stefan:
    Can u add a link dir here to connect the test site dir, then we
could easy 
move what we have modified from test site to main site.
   How do u think about it?


---
作者: 威少爷(suicide)
题目: to chun
日期: Wed Nov  1 19:18:27 2000
I have added the writing right of /daemons and /sgdomain to u
Just check ,but more careful, if u meet some problem ,pls tell me.


---
作者: Suicide
题目: >The gini ...
日期: Tue Oct 31 22:34:44 2000
ok, i will open right for u in test site.
when u meet me online.


---
作者: 小纯(chun)
题目: The gini ...
日期: Tue Oct 31 22:08:40 2000
Bow :),
I wonder if I could get some write privilege on the gini files, which are
gini.o, gini_d.c, gini.c, it will be great if I can do some test on
it on the wiz mud ...
Maybe ... can I?....
Well, just asking ...
papaya chun
escape
thank
bow
mobai all


---
作者: Suicide
题目: >I forget the ftp port No.
日期: Tue Oct 31 17:54:40 2000
4999


---
作者: 小纯(chun)
题目: I forget the ftp port No.
日期: Tue Oct 31 06:51:48 2000
bow :),
Sorry, I already forget the ftp port no lah... anyone can
help tell me? 

Thanks :)


---
作者: 斯坦福(stefan)
题目: Ban IP
日期: Mon Oct 30 22:58:35 2000
All IP starting with 166.127 is now banned because of
fhj and asf's annoying behavior.

If you are so unlucky and from the same IP range, please email
me.


---
作者: Suicide
题目: >Really sorry :( I am not reponsible
日期: Mon Oct 30 17:53:51 2000
Actually,Warmly welcome u back first.:)
I miss u very very much.


---
作者: 小纯(chun)
题目: Really sorry :( I am not reponsible
日期: Mon Oct 30 13:53:27 2000
Hi,

	Sorry I haven't been here for quite a long time,
I am really not an responsible wiz. I guess I might not fit ...


---
作者: Stefan
题目: >the I3 router got problems?
日期: Tue Oct 24 04:38:46 2000
On Tue Oct 24 00:37:48 2000 烈火(fire) wrote post #10035:
> can't communicate with mirrors. shrug.
I've updated main site's I3 server IP to 
point to the latest server. But seems all other mirrors are
still using old ones. They have not updated their lib :PPP


---
作者: 烈火(fire)
题目: the I3 router got problems?
日期: Tue Oct 24 00:37:48 2000
can't communicate with mirrors. shrug.


---
作者: 威少爷(suicide)
题目: to emperor
日期: Sun Oct 22 17:48:13 2000
You said u would post ur plan about newbie system here,but i still
can't see ah...
addoil emperor!!!!!!!!!!1


---
作者: 威少爷(suicide)
题目: a little modification
日期: Thu Jan 11 21:45:58 2001
modify the welcome login display.
give some comment to mirror players num.


---
作者: 威少爷(suicide)
题目: to stefan
日期: Thu Jan 11 21:41:22 2001
为什么现在cq mirror可以看到总站是开放的,而总站却看不到cq分站?
是哪一方哪个配置需要修改阿?


---
作者: 威少爷(suicide)
题目: to stefan
日期: Thu Jan 11 21:16:10 2001
【三国志】威少爷(suicide)：i>网际频道告诉你：bad-channel: not
listening to imud_sgz


---
作者: Suicide
题目: >row's article is pirated!
日期: Tue Jan  9 18:30:16 2001
Maybe we can communicate with that publisher by this,
then we maybe can get help of advertisement for our new Graphic mud
with even no money need.
Isn't it a good idea?


---
作者: 斯坦福(stefan)
题目: row's article is pirated!
日期: Tue Jan  9 17:27:52 2001
A very new magzine called 网络游戏 featured our MUD and
row's article 宛城之战。

But seems the magzine never informed anyone of us.


---
作者: 斯坦福(stefan)
题目: piger to be NPC
日期: Wed Jan  3 02:42:45 2001
bite is asking for this, but I don't know how to do.
So if fire sees this, please help :)


---
作者: Ice
题目: >>Season's Greeting!
日期: Mon Dec 25 05:02:13 2000
On Sun Dec 24 21:09:59 2000 Suicide wrote post #10091:
> It is so long a time that we haven't recieved ur message ,what r u doing
now?
> Fire had come to sh ,but dunno how to contact u, it is so pity.
> )

ppy row was caught by ET from Mars in the past a few weeks leh bah..:P
Well, still in X'mas now, Merry X'mas and Happy another New century.:)
addoil all


---
作者: Suicide
题目: >Season's Greeting!
日期: Sun Dec 24 21:09:59 2000
It is so long a time that we haven't recieved ur message ,what r u doing now?
Fire had come to sh ,but dunno how to contact u, it is so pity.
)


---
作者: 阿洛(row)
题目: Season's Greeting!
日期: Sun Dec 24 18:37:21 2000
Merry X'mas & Happy New Yeah to all u guys!


row


---
作者: 玄冰(ice)
题目: sorry for disturbing...:P
日期: Sun Dec 17 16:33:56 2000
It's so nice to see u guys finally, and I felt guilty when I saw ur tired
faces...
Pardon me ......
Waiting for u guys' good news.
addoil


---
作者: 黄帝(emperor)
题目: name
日期: Fri Dec 15 05:23:56 2000
                    %^B_RED%^        %^RESET%^
                    %^H_WHITE%^三国演义%^RESET%^
                    %^ORANGE%^逐鹿中原%^RESET%^
                    %^B_RED%^        %^RESET%^


---
作者: 黄帝(emperor)
题目: name
日期: Fri Dec 15 05:18:12 2000
                    %^RED%^        %^NOR%^
                    %^HIG%^三国演义%^NOR%^
                    %^YEL%^逐鹿中原%^NOR%^
                    %^RED%^        %^NOR%^


---
作者: Emperor
题目: >our mud's name
日期: Fri Dec 15 05:13:42 2000
On Thu Dec 14 23:50:45 2000 威少爷(suicide) wrote post #10082:
> How about :
> 风云三国
> 逐鹿三国
起名：
三国志--逐鹿中原


---
作者: 威少爷(suicide)
题目: our mud's name
日期: Thu Dec 14 23:50:45 2000
How about :
风云三国
逐鹿三国


---
作者: 黄帝(emperor)
题目: gime太浪费内存！
日期: Thu Dec 14 21:06:29 2000
gime太浪费内存！


---
作者: Suicide
题目: >>>I will go to shanghai
日期: Wed Dec 13 17:01:54 2000
U'd better contact me earlier as possible as u can,


---
作者: Ice
题目: >>>I will go to shanghai
日期: Wed Dec 13 07:34:11 2000
On Wed Dec 13 02:29:21 2000 Fire wrote post #10078:
> On Mon Dec 11 00:24:22 2000 Suicide wrote post #10076:
> > My mobile phone is 13901583882
> > office phone: (025) 5404463 或 (025) 5407271-260
> > Pls contact me if u reach shanghai .
> 
> I will stay in Shanghai for 1 day and Guangzhou for 1 day
> but the schedule may change in the last minuite
> anyway, I will contact you and stefan when I get there.

GZ for 1 day? hmm, I planned to go to SZ this weekend, if u
and stefan group flee r coming to gz, I dun have to take that trip.:P
my MP number is 13922231112, contact me when u fix the day.
ps. didn't I tell anyone here I lived in GZ?  ...:(


---
作者: Fire
题目: >>I will go to shanghai
日期: Wed Dec 13 02:29:21 2000
On Mon Dec 11 00:24:22 2000 Suicide wrote post #10076:
> My mobile phone is 13901583882
> office phone: (025) 5404463 或 (025) 5407271-260
> Pls contact me if u reach shanghai .

I will stay in Shanghai for 1 day and Guangzhou for 1 day
but the schedule may change in the last minuite
anyway, I will contact you and stefan when I get there.


---
作者: 斯坦福(stefan)
题目: to emperor
日期: Mon Dec 11 18:27:01 2000
The gime version you have is not up-to-date, please
check out the most recent version from sourceforge CVS.


---
作者: Suicide
题目: >I will go to shanghai
日期: Mon Dec 11 00:24:22 2000
My mobile phone is 13901583882
office phone: (025) 5404463 或 (025) 5407271-260
Pls contact me if u reach shanghai .


---
作者: 烈火(fire)
题目: I will go to shanghai
日期: Sun Dec 10 23:55:49 2000
hi row, how can I contact you.
and also suicide, maybe we three
can have a dinner together.
I think row is the landlord
so he may like to treat us. hoho :)


---
作者: 黄帝(emperor)
题目: to stefan
日期: Sun Dec 10 06:42:08 2000
现在的BUG是:
creating table ... schema mismatch for zone daemon.emote, ([ /* 2 elements */
  "id":"varchar(32)",
  "rules":"blob"
]) vs ([ /* 2 elements */
  "id":"char(32)",
  "rules":"blob"
])
c:\gime\engine/module/drink.pike:26:Couldn't include file.
c:\gime\engine/module/food.pike:26:Couldn't include file.
c:\gime\engine/user/module/login.pike:54:Couldn't include file.
error execution query UPDATE object_room SET exits='?ke0a eastobject.room.l
iv
ing_room' WHERE id='wiz_room';
error execution query UPDATE object_room SET exits='?ke0a westobject.room.w
iz
_room' WHERE id='living_room';
done.
You may now run ./start.pike again to start GIME.

在room往object_room表中update exits列时出错，好象是quote_value(
([object.room.living_room]), z->schema["exits"] )出现了问题，不知道
是什么原因？


---
作者: 黄帝(emperor)
题目: to stefan
日期: Sun Dec 10 00:29:47 2000
现在在95下面可以运行gime了，但在init_zone时，daemon.emote的id的数据
类型不匹配。
且/engine/module/food.pike and /engine/moudel/drink.pike中的include
<sgz/sgzdaemon.h>
因为sgz/sgzdaemon.h文件不存在而出错。
就发现这些BUG。


---
作者: 威少爷(suicide)
题目: about quarreling in caolu
日期: Sat Dec  9 18:47:14 2000
For it is so silence these days,so i add some 花絮.
Now and so much posts in caolu,hoho.
I reached my aim,and i will keep silence le.
:)


---
作者: 黄帝(emperor)
题目: to stefan
日期: Sat Dec  9 04:02:17 2000
现在可以连接mysql了，但在创建几个数据库表时出错。
error execution query SELECT * FROM class;
error execution query SELECT * FROM daemon_news__group;
error accessing daemon.news._group
Starting GIME done.
no matched zone table to store data for msg.user.module.login.welcome
no matched zone table to store data for msg.user.module.login.welcome
no matched zone table to store data for msg.user.module.welcome
no matched zone table to store data for msg.user.module.welcome
no matched zone table to store data for msg.user.welcome
no matched zone table to store data for msg.user.welcome

不知道是不是windows operation system的缘故，我在查。
你也帮我查查，ok?


---
作者: 分钟(group)
题目: name
日期: Thu Dec  7 22:32:21 2000
三国有游戏用了.


---
作者: Suicide
题目: >name
日期: Thu Dec  7 01:10:50 2000
不叫三国吗?


---
作者: 分钟(group)
题目: name
日期: Thu Dec  7 00:57:26 2000
hihihi, please consider a name for our new designed game..:P

push ice
push fire
push suicide
push emperor
push row
push push push

giggle


---
作者: 威少爷(suicide)
题目: to stefan
日期: Tue Dec  5 16:49:46 2000
Need reboot lah,Can u promote me ?
For fire will not come here in a long time.


---
作者: 威少爷(suicide)
题目: replace new robot sentence txt files
日期: Tue Dec  5 16:47:22 2000
This is all produced by the little program i have written.
Just random select sentence from my big txt download Dir.
:)


---
作者: Emperor
题目: >to empoeror
日期: Tue Dec  5 03:44:12 2000
On Mon Dec  4 02:47:51 2000 斯坦福(stefan) wrote post #10064:
> I have to try it myself in order to debug :PPP
> My guess is, did you have test DB in your MySQL?
> You can try Pike command line, just type in:
> Sql.sql("mysql://localhost/test")
> and see what happens. It should return you an object.
> 
我早就这样试过了，还是没用


---
作者: 斯坦福(stefan)
题目: to empoeror
日期: Mon Dec  4 02:47:51 2000
I have to try it myself in order to debug :PPP
My guess is, did you have test DB in your MySQL?
You can try Pike command line, just type in:
Sql.sql("mysql://localhost/test")
and see what happens. It should return you an object.



---
作者: Emperor
题目: >to stefan
日期: Sun Dec  3 03:48:09 2000
我把gime的start.pike中object db;改为Sql.sql db也没用。


---
作者: 黄帝(emperor)
题目: to stefan
日期: Sun Dec  3 03:45:43 2000
我安装了Roxen 2.1.158，运行很成功。
我成功地add Sql module in Roxen,并显示
连接mysql成功，同时显示我机器上的mysql版本。
但在运行gime时，用mysql://localhost/test却产生
不了db object，你能帮我找到关键所在吗？

我是在win95上安装roxen2.1的，roxen没任何问题。

我看了roxen的 server/modules/database/sqldb.pike
文件，没什么特殊代码。

sqldb.pike的部分代码如下：
  mapping sql_urls = parse_table(QUERY(table));

  string res = "";

  if (sizeof(sql_urls)) {
    res += "<table border=\"0\">\n";
    foreach(sort(indices(sql_urls)), string s) {
      Sql.sql o;

      mixed err = catch {
        o = Sql.sql(sql_urls[s]);
      };

      if (o) {
        res += sprintf("<tr><td>Connection OK</td>"
                       "<td><tt>%s</tt></td>"
                       "<td>%s server on %s</td></tr>\n",
                       Roxen.html_encode_string (s),
                       Roxen.html_encode_string (o->server_info()),
                       Roxen.html_encode_string (o->host_info()));
      } else if (err) {
        res += sprintf("<tr><td><font color=red>Connection
failed</font>: %s</td>"
                       "<td><tt>%s</tt></td><td>&nbsp;</td></tr>\n",
                       Roxen.html_encode_string (describe_error (err)),
                       Roxen.html_encode_string (s));
      }

我在roxen的add modules后，成功出现了"Connection ok"



---
作者: Emperor
题目: >to emperor
日期: Sat Dec  2 03:23:27 2000
On Fri Dec  1 20:48:31 2000 斯坦福(stefan) wrote post #10060:
> I've put it at http://www.gime.org/roxen-2.1.185-nt4sp6.exe
> 
> Not sure if it supports MySQL.
> I've not tried it myself.
thank stefan.


---
作者: 斯坦福(stefan)
题目: to emperor
日期: Fri Dec  1 20:48:31 2000
I've put it at http://www.gime.org/roxen-2.1.185-nt4sp6.exe

Not sure if it supports MySQL.
I've not tried it myself.


---
作者: 威少爷(suicide)
题目: 关于官员升迁
日期: Thu Nov 30 21:07:19 2000
现在系统对于玩家国的官员,不进行资格是否合适的检查,
对此,我们准备开放这个资格检查功能,形成资格不后
会自动降职的,对此大家有什么意见,请建议?


---
作者: 黄帝(emperor)
题目: to stefan
日期: Mon Nov 27 04:33:05 2000
Roxen WebServer 2.1.185, 128 bit crypto, Windows NT 4.0 Service Pack 6 Binary
stefan,这个版本支持Mysql吗？能不能放在www.gime.org，我连接
download.roxen.com的速度太慢了。
thx stefan.


---
作者: 烈火(fire)
题目: hello all
日期: Sun Nov 26 18:45:54 2000
havn't login for serveral weeks. really busy this moment
but it's lucky that my project progressed better even
than expected. 

I will goto Macro next month and may goto China as well
but not sure.

I think we may need a new admin here to manage this site
I am too busy to do that job.

anyway, I am very happy to find we are still running. 
addoil all.



---
作者: 斯坦福(stefan)
题目: good website - for game designers
日期: Thu Nov 23 22:30:45 2000
www.costik.com

This guy is a game designers, there are many interesting writings
concerning multiuser games and games in general.

A very good one is "I Have No Words & I Must Design" under his 
writing page.  It talked about what makes it a game, and the important
aspects of a good game. One point very relavant to us is that
in our MUD, after the great tension period where there are three equally 
strong countries, there isn't much tension when one country has
the obvious advantage to beat all others. This is why everyone
is asking to restart even when no one unifies the whole country.


---
作者: 分钟(group)
题目: oh
日期: Tue Nov 21 22:35:21 2000
last num is 108, not 81... :P


