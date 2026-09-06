#ifndef _TELL_ME_H
#define	_TELL_ME_H

#define	TELL_NO_WRAP			1
#define	TELL_TYPE_MASK			0xFFFF00

#define	TELL_TYPE_SAY			(1 << 8)
#define	TELL_TYPE_WHISPER		(2 << 8)
#define	TELL_TYPE_TELL			(3 << 8)
#define	TELL_TYPE_SHOUT			(4 << 8)
#define	TELL_TYPE_PARTY			(5 << 8)
#define	TELL_TYPE_HIT_BY		(6 << 8)
#define	TELL_TYPE_MISSED_BY		(7 << 8)
#define	TELL_TYPE_HITTING		(8 << 8)
#define	TELL_TYPE_MISSING		(9 << 8)
#define	TELL_TYPE_DEATH			(10 << 8)
#define	TELL_TYPE_ROOM_BRIEF		(11 << 8)
#define	TELL_TYPE_ROOM_DESC		(12 << 8)
#define	TELL_TYPE_TERMINAL_COLOUR	TELL_TYPE_ROOM_DESC
#define	TELL_TYPE_ROOM_ITEM		(13 << 8)
#define	TELL_TYPE_ROOM_SMELLS		(14 << 8)
#define	TELL_TYPE_ROOM_SOUNDS		(15 << 8)
#define	TELL_TYPE_INVENTORY		(16 << 8)
#define	TELL_TYPE_INV_ITEM		(17 << 8)
#define TELL_TYPE_BROADCAST		(18 << 8)
#define	TELL_TYPE_INFO			(19 << 8)
#define	TELL_TYPE_MORT			(20 << 8)
#define TELL_TYPE_NEWBIE		(21 << 8)
#define TELL_TYPE_OOC			(22 << 8)
#define	TELL_TYPE_LORD			(23 << 8)
#define	TELL_TYPE_GUILD			(24 << 8)
#define	TELL_TYPE_HOUSE			(25 << 8)
#define TELL_TYPE_FACTION		(26 << 8)
#define TELL_TYPE_ORDER			(27 << 8)
#define	TELL_TYPE_WIZ			(28 << 8)
#define	TELL_TYPE_ARCH			(29 << 8)
#define	TELL_TYPE_ADMIN			(30 << 8)
#define	TELL_TYPE_RESERVED		(40 << 8)

#define	TELL_BEGIN			0x20000000
#define	TELL_END			0x40000000

#define	TELL_MIN_X			20
#define	TELL_MIN_Y			10
#define	TELL_STD_X			80
#define	TELL_STD_Y			25

#define	TELL_UPDATE			-1
#define	TELL_RETURN_NONE_USED		-1
#define	TELL_RETURN_CLIENT_IN_USE	-2

#endif
