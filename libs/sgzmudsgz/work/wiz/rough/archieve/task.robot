---
作者: 阿洛(row)
题目: robot test
日期: Tue Feb  1 20:21:53 2000
seems we have to increase the chance of robot testing..


---
作者: 烈火(fire)
题目: about robot test
日期: Sat Jan 29 01:10:17 2000
I think robot test in this mud is a very interesting
topic, and it still not perfect, so I think we can
open this task board for the discussion about robot problems


---
作者: 玄冰(ice)
题目: about literate
日期: Fri Jan 28 11:59:31 2000
(转载自wiz.com)
b4 robot test is for prevent player only rely on robot, however,
later it's changed to be a standard of evaluation, so the former
way is not so fit for current situation.  I think we should make it a
aggressive
formula. I'll give a draft one in the next post.:P, discuss discuss bah.:P


---
作者: 玄冰(ice)
题目: about literate formula
日期: Fri Jan 28 13:45:35 2000
(转载自wiz.com)
first I suggest to change the "cmd robot" to the following way:
智能测试：　测试总次数　　  失败次数　　最近状况
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
          四千一百七十一次   十二次     十次弱智

my idea is that devide the robot test frequency into different
levels: (F=frequency of job per robot test)

lv 0  -> if sb who give the wrong answer to the robot question 
         more than 10 times in a row, he will be set in this level.
      -> F= 7-8

lv 1  -> when a player gives the right answer to robot question
         >=5 times and <10 times in a row.
      -> F= 6

lv 2  -> when a player gives the right answer to robot question
         >=10 times and <20 times in a row.
      -> F= 5

lv 3  -> when a player gives the right answer to robot question
         >=20 times in a row, or when a player is 
         totally new in this mud.
      -> F= 4

the penalty will be also aggressive:

if give wrong answer >=1 time and <5 times in a row, the penalty is
deduct 2 literate each time.

if give wrong answer >=5 times and <10 times in a row, the penalty is
deduct 3 literate each time.

if give wrong answer >10 times in a row, the penalty is deduct 4 
literate each time. (* grin)

example:
1. in the worst situation, assume a new player wanna settle and he
   has given some wrong answer to the robot question, like 4 times,
   he will have to do 4*28=112 jobs in order to settle.:P
2. in the best situation, assume a player never gives wrong answer
   to the robot questions, he will have 4000 literate by doing 16,000
   jobs.:P, not that easy to achieve high literate anyway.:P

In addition, the possibility of robot question type what will be asked
can be allocated with the following frequency:(L=literate, Q=robot question)

             common Q      zi Q       map Q       sentence Q
     L<=30     100%
  30<L=<200    50%         50%
 200<L=<500    30%         40%         20%           10%
 500<L=<1000   20%         30%         30%           20%
1000<L=<2000   10%         30%         40%           20%
2000<L                     30%         40%           30%

how do u guys think about it?
well, maybe I am just thinking from the simple way, pardon me..:P



