#ifndef _CLIENT_DEFS_H
#define _CLIENT_DEFS_H

#define	CLIENT_NONE	0
#define	CLIENT_NONE_ID	({ "0", "none", "" })
#define	CLIENT_NONE_NAME	"<none>"
#define	CLIENT_MURDER	1
#define	CLIENT_MURDER_ID	({ "murder" })
#define	CLIENT_MURDER_NAME	"MurderMud-client"

#define	CLIENT_TAG_BEGIN	"<"
#define	CLIENT_TAG_END		">"
#define	CLIENT_TAG_NEGATE	"/"

#define	CLIENT_TAG_INV		"INV"
#define	CLIENT_TAG_ITEM		"ITEM"
#define	CLIENT_TAG_RDESC	"RDESC"
#define	CLIENT_TAG_EXITS	"EXITS"
#define	CLIENT_TAG_RINV		"RINV"
#define	CLIENT_TAG_RITEM	"RITEM"

#define	CLIENT_DO_TAG_BEGIN(x)	CLIENT_TAG_BEGIN x CLIENT_TAG_END
#define	CLIENT_DO_TAG_END(x)	CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE x\
				 CLIENT_TAG_END

#endif
