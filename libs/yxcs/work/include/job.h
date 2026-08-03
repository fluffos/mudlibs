// job.h

/***** Written by ken@yxcs2. All rights reserved. *****/ 
/******************************************************/
/* 为了把任务系统更加规范化，同时亦方便日后对JOB奖励  */
/* 的调整，这样对JOB的平衡有了结构性的改善。          */
/* 函数的调用方法是 me->add("combat_exp", ajob(me));  */
/* 算法是当玩家未满十八岁前是于级数的random(exp)      */
/* 而当玩家满十八岁后exp会是exp / age / AGE_RATE      */
/* 建议在调整奖励时修改全局变量的值就可以。 BY KEN@NT */
/******************************************************/
#pragma save_binary

// 对任务系统奖励作出规范
#define  AJOB_EXP     200
#define  BJOB_EXP     500
#define  CJOB_EXP     1000
#define  DJOB_EXP     2000
#define  EJOB_EXP     3000

// 当玩家年龄满十八岁后所
// 加的奖励会是JOB_EXP / (AGE / AGE_RATE) 
#define  AGE_RATE     10

// 由于要实现早期练功容易，后期难的效过，所以我们加入了
// AGE 越大，所得奖励越少的算法。 但有可能当玩家EXP太大
// 时所得EXP和新手相差太远，固加入"底薪" 。
#define  DEXP         100 

int ajob(object player)
{
        int   exp = AJOB_EXP;
        
        (player->query("age") < 18)?
        (exp = random(exp)) :
        (exp = (exp / (player->query("age") / AGE_RATE )));
                
        return (exp + DEXP);    
}

int bjob(object player)
{
        int   exp = BJOB_EXP;

        (player->query("age") < 18)?
        (exp = random(exp)) :
        (exp = (exp / (player->query("age") / AGE_RATE )));
                
        return (exp + DEXP);    
}

int cjob(object player)
{
        int   exp = CJOB_EXP;
                
        (player->query("age") < 18)?
        (exp = random(exp)) :
        (exp = (exp / (player->query("age") / AGE_RATE )));
                
        return (exp + DEXP);    
}

int djob(object player)
{
        int   exp = DJOB_EXP;
                
        (player->query("age") < 18)?
        (exp = random(exp)) :
        (exp = (exp / (player->query("age") / AGE_RATE )));
                
        return (exp + DEXP);    
}

int ejob(object player)
{
        int   exp = EJOB_EXP;
                
        (player->query("age") < 18)?
        (exp = random(exp)) :
        (exp = (exp / (player->query("age") / AGE_RATE )));
                
        return (exp + DEXP);    
}

