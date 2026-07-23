/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : secure.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */
// 權限定義
#define READ            (1 << 0)
#define WRITE           (1 << 1)
#define COMPILE         (1 << 2)
#define LIST            (1 << 3)
#define MKDIR           (1 << 4)
#define RM              (1 << 5)
#define CHILD_OWNER     (1 << 6)

// 巫師等級
#define STANDARD        (1 << 0)
#define PLAYER          (1 << 1)
#define GUEST           (1 << 2)
#define WIZARD          (1 << 3)
#define ADVISOR         (1 << 5)
#define ADMIN           (1 << 6)
#define ROOT            (1 << 7)
