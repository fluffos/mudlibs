/*
 * Wizards handbook v1.0              by Dazzt
 * 
 * */

inherit ITEM;

#define PAGE        0
#define TABLE       1

/* --- -- - variables - -- --- */

int which;               /* 0 - page   1 - table */
int current_page;
string *pages;
string *tables;

/* --- -- - functions - -- --- */

create_item()
{
	set_name(({ "book", "handbook" }));
	set_short("a very thick and ragged book");
	set_long("This dark-red book is very thick and has surely seen better" +
			 " days. Its covers has been made from animals leather and the" +
			 " paper used has already started to turn yellow." +
			 " On the front cover a label with dull gold letters has been attached."
			 " It reads 'Wizards guidebook to MAJIK programming, 1st edition'.\n");
	
	set_weight(4234);
	set_dimensions(40, 30, 10);
	set_material("paper");

	current_page = 1;
	pages = ({ 	"/doc/majik/handbook/contents", 
			"/doc/majik/handbook/introduction",
			"/doc/COPYRIGHT", 
			"/doc/majik/handbook/filestructure",
			"/doc/majik/handbook/workroom",
			"/world/README"
	});
	tables = ({  "table_monsterrace" });
}

long()
{
	
	return long_desc[0..<2] + 
		(which ? " Table number '" + (sprintf("%c", current_page + 'A')) + "'" : 
		 " Page number " + i2s(current_page)) + 
		" is currently open.\n";
}

init()
{
	add_action("do_read", "read");
	add_action("do_turn", "turn");
}

string i2s(int i)
{
	string *numbers = ({ "zero", "one", "two", "three", "four", "five", "six", 
			"seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
			"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", 
			"twenty" });
	
	if (i <= 20)
		return numbers[i];
	else 
		return sprintf("%d", i);
}

do_read(string str)
{
	string s;
	
	if (member_array(str, ({ "book", "guide", "handbook", "guidebook" })) == -1)
	{
		notify_fail("Read what?\n");
		return 0;
	}
	
	if (THIS->query_security() == 0)
	{
		notify_fail("You aren't godly enough to read that!\n");
		return 0;
	}
	
	if (which == PAGE)
		"/command/immortal/more"->main(pages[current_page - 1]);
	if (which == TABLE)
	{
		s = call_other(THOB, tables[current_page]);
		message("0", s, THIS);
	}
	
	return 1;
}

do_turn(string str)
{
	string s;
	int to, i;
	
	if (!str)
	{
		notify_fail("Turn what?\n");
		return 0;
	}
	
    if (sscanf(str, "to page %d", to) != 1)
		if (sscanf(str, "to table %s", s) != 1)
		{
			notify_fail("Usage: turn to <page|table> #\n");
			return 0;
		}
	
	if (to)
	{
		if (to >= 1 && to <= sizeof(pages))
		{
			message("environment", "You turn to page " + i2s(to) + ".\n", THIS);
			current_page = to;
			which = PAGE;
			return 1;
		}
	}
	
	if (s)
	{
		s = lower_case(s);
		sscanf(s, "%d", i);
		if (s[0] >= 'a' && s[0] <= ('a' + sizeof(tables)))
		{
			message("environment", "You turn to table '" + upper_case(sprintf("%c", i + 'A')) + "'.\n", THIS);
			current_page = s[0] - 'a';
			which = TABLE;
		}
		return 1;
	}
	
	notify_fail("But there are only " + i2s(sizeof(pages)) + " pages in this book!\n");
	return 0;
}

/* --- various tables --- */

string table_monsterrace()
{
	string races, s;
	string *file;
	int i;
	
	file = explode(read_file("/data/monster/races"), "\n");
	
	races = "";
	
	for (i = 0; i < sizeof(file); i++)
	{
		if (file[i][0..0] != "#")
		{
			s = file[i][0..22];
//			while (s[<1..<1] == " ")
//				s = s[0..<2];
			races += capitalize(s) + "\n";
		}
	}
	
	return "^c1AVAILABLE MONSTER RACES IN MAJIK^c0\n\n" + sprintf("%#-78s", races) + "\n";
}
		
