#ifndef __SCHOOL_H__
#define __SCHOOL_H__

//索引号定义
#define INDEX_PFMFLAG   "flag"      //解谜标志(多个标志用;分隔)
#define INDEX_SKILLS    "skills"    //门派技能map

#define INDEX_BASICSKILL    "basic"     //基本技能
#define INDEX_SKILLWEAPON   "weapon"    //武器类型
#define INDEX_HELPCMD       "prepare"   //支持命令(比如需要激发parry、dodge等，多条命令使用;分隔)
#define INDEX_JUEZHAO       "special"   //绝招定义

#define INDEX_JZEFFECT      "effect"    //绝招的效果，第一组
#define INDEX_JZEFFECT2     "effect2"   //绝招的效果，第二组
#define INDEX_PREPARE       "prepare"   //放绝招前的准备动作
#define INDEX_POSTACT       "postact"   //放绝招后的恢复动作

//技能类型定义
#define JZ_BUSY         0x00000001  //BUSY对方
#define JZ_WEAPON       0x00000002  //打武器技能
#define JZ_KEEPHY       0x00000004  //气血物理攻击
#define JZ_KEECHE       0x00000008  //气血化学攻击
#define JZ_FORCE        0x00000010  //化内力
#define JZ_MANA         0x00000020  //化法力
#define JZ_CONDITION    0x00000040  //毒
#define JZ_ESCAPE       0x00000080  //逃跑
#define JZ_EQUIP        0x00000100  //打防具技能
#define JZ_SENPHY       0x00000200  //精神物理攻击
#define JZ_SENCHE       0x00000400  //精神化学攻击
#define JZ_POWERUP      0x00000800  //强化类
#define JZ_HELPER       0x00001000  //护法类
#define JZ_KILL         0x00002000  //会触发叫杀
#define JZ_SELFBUSY     0x00004000  //自己有可能busy
#define JZ_SELFNOMOVE   0x00008000  //自己有可能no move
#define JZ_KEEWOUND     0x00010000  //气血上限攻击
#define JZ_SENWOUND     0x00020000  //精神上限攻击
#define JZ_HEAL         0x00040000  //疗伤
#define JZ_NOMOVE       0x00080000  //对方no move
#define JZ_FENGMO       0x00100000  //对方封魔
#define JZ_BIQI         0x00200000  //对方闭气
#define JZ_JINZHOU      0x00400000  //对方禁咒
#define JZ_PUSH         0x00800000  //对方走开
#define JZ_PEACE        0x01000000  //解除战斗
#define JZ_GROUP        0x02000000  //群体攻击
#define JZ_SUICIDE      0x04000000  //拼命
#define JZ_GINPHY       0x08000000  //精力物理攻击
#define JZ_GINCHE       0x10000000  //精力化学攻击
#define JZ_ATMAN        0x20000000  //化灵力

#define JZ_GINWOUND     0x40000001  //精力上限攻击
#define JZ_CURE         0x40000002  //解毒

#endif

