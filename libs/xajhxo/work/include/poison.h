#ifndef POISON_H
#define POISON_H

#define TYPE_KEE (1)
#define TYPE_GIN (1<<1)
#define TYPE_SEN (1<<2)

#define TYPE_YIN (1<<3)
#define TYPE_YANG (1<<4)
#define TYPE_ZHONG (1<<5)

#define TYPE_DAMAGE (1<<6)
#define TYPE_WOUND  (1<<7)

int SetMsg(string msg);
int SetTtl(int ttl);
int SetPoisonDamage(int type, int hurt);
//class Poison GetPoison();
int eventUse(object who);

#endif

