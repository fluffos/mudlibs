/*  mudlib.h

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#ifndef __MUDLIB_H
#define __MUDLIB_H

/* 这个是 mudlib 的名称，除非你徵询过原作者的同意，否则你不应该修改这个
 * 名称。这个名称除了用来识别 mudlib 的系统之外，也用在 intermud 协定中
 * 的 es 频道，作为各 MUD 间沟通讯息之用。
 */
#define MUDLIB_NAME		"Eastern Stories"

/* 这个是 mudlib 的版本号码，ES2 mudlib 在释出新版的时候会提升其版本号码
 * 中的数字部分，数字后面接的字母其意义如下：
 *	p: 原型版 (prototype)，实验用。
 *	a: 内部测试版 (alpha)，释出供有架站经验者测试用。
 *	b: 公开测试版 (beta)，释出供一般使用者测试用。
 *	(无): 正式版，含 mudlib 函数说明及介面规格。
 */
#define MUDLIB_VERSION_NUMBER	"2.1.3a"

#define MUDLIB_VERSION		(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)

/* 这是你的 MUD 使用的中文编码系统，预设为台湾地区常用的 BIG5，大陆地区通
 * 常使用 GB 码，ES2 mudlib 释出时以 BIG5 码为主，如果有人愿意转码成 GB 版
 * 欢迎和我联络。
 */
#define MUDLIB_LOCALE		"BIG5"

/* 这个名称是在 intermud 上的 mud 名称，由于 intermud 会和国际上的其他 mud
 * 相通连，所以请勿使用 ASCII 以外的字元(中文码)。
 */
#define INTERMUD_MUD_NAME	"Celestial Empire"

#endif	/* __MUDLIB_H */
