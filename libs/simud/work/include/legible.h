// include file for legible items (books, paper, signs, etc...)

#define L_WRITING	 1	// normal text, variable length
#define L_SIGNATURE	 2	// name of player, 1 line
#define L_DRAWING	 3	// ascii art, impossible to copy, variable length
#define L_SPELL		 4	// name of spell, variable length
#define L_SKILL		 5	// name of skill, 30 lines
#define L_DEED		 6	// unique identifier of property described, ?? lines
#define L_LICENSE	 7	// government-specific description, ?? lines
#define L_MONEY		 8	// bank-issued,
#define L_RECIPE	 9	// name of recipe described, 10 lines
#define L_TECH		 10	// name of technology, ?? lines
#define L_CODE		 11	// a closure?

// page length constants
#define PAGE_SHORT	20
#define PAGE_MEDIUM	40
#define PAGE_LONG	60

// different options for the details flag
#define L_HAND		0x0001	// is this handwritten?
#define L_PRINT		0x0002	// is this printed?
#define L_BLACK		0x0004	// is this black ink?
#define L_COLOUR	0x0008	// is this colored ink?
#define L_FORGERY	0x8888	// is this document counterfit?

struct page_contents_struct {
	int category;	// what sort of stuff is in this section?
	int length;		// how much space (in lines) does this section occupy?
	int details;	// more details of the document (L_HAND | L_BLACK, etc...)
	string language; // what language (if any...) is this written in?
	mixed contents;	// specific data stored in this particular bit of paper
};
