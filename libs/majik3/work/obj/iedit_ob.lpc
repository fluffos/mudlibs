/*
 * Item Editor v1.0             (c) Dazzt
 * 
 * [15.12.97]:  Initial version
 * 
 * */

#include <message.h>

inherit BASE;

#define VERSION "v1.0"

#define DISPTEXT(x) ((x != "" && x != 0) ? "\n" + x : "-")
#define DISPSTR(x) (x != "" ? x : "-")
#define DISPINT(x) (x ? sprintf("%d", x) : "-")
#define DISPYN(x) (x ? "yes" : "no")

/* --- -- - variables - -- --- */

string item;

string i_name, *i_aliases, i_short, i_long, i_smell, i_taste, i_listen;
int i_xdim, i_ydim, i_zdim, i_weight, i_hp, i_max_hp, i_no_get, i_light;
mapping i_materials;

string hook_var, hook_call;
int hook_counter;
string str, *strs;
int i;

/* --- function prototypes --- */

void init_variables();
void disp_mainmenu();
void disp_descmenu();
void disp_savemenu();
void disp_attrmenu();
void process_mainmenu();
void process_descmenu();
void process_savemenu();
void process_attrmenu();
void save_item();
void input_str_hook();
void input_yn_hook();
void input_int_hook();

/* --- -- - functions - -- --- */

main(string args)
{
	if (!args)
	{
		notify_fail("usage:  iedit <filename>");
		return 0;
	}

	if (!absolute_path(args))
		args = THIS->query_cwd() + args;
	
	item = resolve_path(args);
	init_variables();
	disp_mainmenu();
	
	return 1;
}

//  void init_variables()
//                                loads variables from object

void init_variables()
{
	if (file_size(item) >= 0)
	{
		if (item->query_iedit() != VERSION)
		{
			u_line("\n");
			u_line("^cRThe object (^cW/" + item + "^cR) is not compatible with this version of Iedit!" +
				   " Saving the object may cause loss of code and/or item functionality!^c0");
			u_line("\n\n");
		}
		i_name = item->query_name();
		i_aliases = item->query_aliases();
		i_short = item->query_short();
		i_long = item->query_long()[0..<2];
		i_smell = item->query_smell();
		i_taste = item->query_taste();
		i_listen = item->query_listen();
		i_xdim = item->query_dimensions()[0];
		i_ydim = item->query_dimensions()[1];
		i_zdim = item->query_dimensions()[2];
		i_materials = item->query_materials();
		i_weight = item->query_weight();
		i_hp = item->query_hp();
		i_max_hp = item->query_max_hp();
		i_no_get = item->query_no_get();
		i_light = item->query_light();
	}
	else
	{
		i_name = "";    i_materials = ([ ]);
		i_short = "";	i_long = "";	i_smell = ""; 
		i_taste = "";   i_listen = "";  i_aliases = ({});
	}
	if (!i_materials)
		i_materials = ([]);
}
	
	

disp_mainmenu()
{
	string str;
	
	str = sprintf("-- Item file      : [^cc/%s^c0]\n" +
				  "^cg1^c0) Names   (id's) : ^cy%s^c0\n" +
				  "^cg2^c0) Short desc     : ^cy%s^c0\n" +
				  "^cg3^c0) Long desc      : ^cy%s^c0\n" +
				  "^cg4^c0) Additional descriptions\n" +
				  "^cg5^c0) Item attributes\n" +
				  "^cgQ^c0) Quit\n", 
				  item,
				  DISPSTR(implode( (({ i_name }) + i_aliases), ", ")),
				  DISPSTR(i_short),
				  DISPTEXT(i_long)
				  );
	u_line(str);
	u_prompt("Enter choice : ");
	hook_var = "str";
	hook_call = "process_mainmenu";
	input_to("input_str_hook");
	
}

disp_descmenu()
{
	string str;
	
	str = sprintf("-- Item file      : [^cc/%s^c0]\n" +
				  "^cg1^c0) Smell          : ^cy%s^c0\n" +
				  "^cg2^c0) Taste          : ^cy%s^c0\n" +
				  "^cg3^c0) Sound          : ^cy%s^c0\n" +
				  "^cgQ^c0) Return to main\n",
				  item,
				  DISPTEXT(i_smell),
				  DISPTEXT(i_taste),
				  DISPTEXT(i_listen)
				  );
	u_line(str);
	u_prompt("Enter choice : ");
	hook_var = "str";
	hook_call = "process_descmenu";
	input_to("input_str_hook");
}

disp_savemenu()
{
	u_prompt("Save object? (y/N) : ");
	hook_var = "str";
	hook_call = "process_savemenu";
	input_to("input_str_hook");
}

disp_attrmenu()
{
	string str, mat;
	int i;
	
	mat = "";
	for (i = 0; i < sizeof(keys(i_materials)); i++)
		mat += keys(i_materials)[i] + " (" + values(i_materials)[i] + "%), ";
	mat = mat[0..<3];
	if (!mat)
		mat = "";
	
	str = sprintf("-- Item file      : [^cc/%s^c0]\n" +
				  "^cg1^c0) Weight         : ^cy%d grams (%d kg)^c0\n" +
				  "^cg2^c0) Size (X,Y,Z)   : ^cy%d x %d x %d cm^c0\n" +
				  "^cg3^c0) Material       : ^cy%s^c0\n" +
				  "^cg4^c0) Hp / Maxhp     : ^cy%d / %d^c0\n" +
				  "^cg5^c0) Light emission : ^cy%s^c0\n" +
				  "^cg6^c0) Plr can't get  : ^cy%s^c0\n" +
				  "^cgQ^c0) Return to main\n",
				  item,
				  i_weight, i_weight / 1000, 
				  i_xdim, i_ydim, i_zdim,
				  mat,
				  i_hp, i_max_hp,
				  DISPINT(i_light),
				  DISPYN(i_no_get)
				  );
	u_line(str);
	u_prompt("Enter choice : ");
	hook_var = "str";
	hook_call = "process_attrmenu";
	input_to("input_str_hook");
}
	

process_mainmenu()
{
	switch (lower_case(str))
	{
		case "1" :
		u_line("Enter name(s) you wish the object to be called, one per line.");
		u_line("Type '.' on empty line when done.");
		u_prompt("1> ");
		i_aliases = ({});
		hook_var = "i_aliases";
		hook_call = "process_aliases";
		input_to("input_array_hook");
		break;
		case "2" :
		u_prompt("Enter new short description:\n> ");
		hook_var = "i_short";
		hook_call = "disp_mainmenu";
		input_to("input_str_hook");
		break;
		case "3" :
		u_line("Enter new long description. Type '.' on empty line when done.");
		u_prompt("1> ");
		i_long = "";
		hook_var = "i_long";
		hook_call = "disp_mainmenu";
		input_to("input_text_hook");
		break;
		case "4" :
		disp_descmenu();
		break;
		case "5" :
		disp_attrmenu();
		break;
		case "q" : 
		disp_savemenu();
		break;
		default :
		disp_mainmenu();
	}
}

process_descmenu()
{
	switch (lower_case(str))
	{
		case "1" :
		u_line("Enter new smell description. Type '.' on empty line when done.");
		u_prompt("1> ");
		i_smell = "";
		hook_var = "i_smell";
		hook_call = "disp_descmenu";
		input_to("input_text_hook");
		break;
		case "2" :
		u_line("Enter new taste description. Type '.' on empty line when done.");
		u_prompt("1> ");
		i_taste = "";
		hook_var = "i_taste";
		hook_call = "disp_descmenu";
		input_to("input_text_hook");
		break;
		case "3" :
		u_line("Enter new sound description. Type '.' on empty line when done.");
		u_prompt("1> ");
		i_listen = "";
		hook_var = "i_listen";
		hook_call = "disp_descmenu";
		input_to("input_text_hook");
		break;
		case "q" :
		disp_mainmenu();
		break;
		default :
		disp_descmenu();
		break;
	}
}

process_aliases()
{
	i_name = i_aliases[0];
	i_aliases -= ({ i_aliases[0] });
	disp_mainmenu();
}

process_savemenu()
{
	if (!str)
		disp_savemenu();
	if (lower_case(str[0..0]) == "y")
	{
		save_item();
		u_line("Saved /" + item + ".");
	}
	else
		u_line("Object not saved.");
	destruct(THOB);
}

process_attrmenu()
{
	string *mats, mat;
	
	switch (lower_case(str))
	{
		case "1" :
		u_prompt("Enter weight in grams : ");
		hook_var = "i_weight";
		hook_call = "disp_attrmenu";
		input_to("input_int_hook");
		break;		
		case "2" :
		u_prompt("Enter dimensions in 'X Y Z' form, ie. '10 15 24' > ");
		hook_var = "str";
		hook_call = "process_dimensions";
		input_to("input_str_hook");
		break;
		case "3" :
		u_line("^ccCurrently available materials are:^c0");
		mats = MATERIAL_D->query_all_materials();
		mat = implode(mats, "\n");
		u_line(sprintf("%#-78s", mat));
		u_line("Enter materials in material, amount pairs, ie. 'wood 90% silver 10%'");
		u_prompt("Enter material(s) : ");
		hook_var = "str";
		hook_call = "process_material";
		input_to("input_str_hook");
		break;
		case "4" :
		u_prompt("Enter hitpoints in 'hp/maxhp' form, ie. '15/20' > ");
		hook_var = "str";
		hook_call = "process_hp";
		input_to("input_str_hook");
		break;
		case "5" : 
		u_prompt("Enter light value (-2 to 2) > ");
		hook_var = "i_light";
		hook_call = "disp_attrmenu";
		input_to("input_int_hook");
		break;
		case "6" :
		u_prompt("Don't allow this item to be picked up? [y/n] > ");
		hook_var = "str";
		hook_call = "process_get";
		input_to("input_str_hook");
		break;
		case "q" :
		disp_mainmenu();
		break;
		default:
		disp_attrmenu();
	}
}

process_dimensions()
{
	int x, y, z;
	
	if (sscanf(str, "%d %d %d", x, y, z) != 3)
		u_line("Invalid entry.");
	else
	{
		i_xdim = x; i_ydim = y; i_zdim = z;
	}
	
	disp_attrmenu();
}

process_hp()
{
	int i, j;
	
	if (sscanf(str, "%d/%d", i, j) != 2)
		u_line("Invalid entry.");
	else
	{
		i_hp = i;
		i_max_hp = j;
	}
	
	disp_attrmenu();
}

process_material()
{
	string mat, rest;
	int amt, i;
	mapping mats;
	
	rest = str;
	mats = ([]);
	while ((i = sscanf(rest, "%s %d%% %s", mat, amt, rest)) >= 2)
	{
		if (member_array(mat, MATERIAL_D->query_all_materials()) == -1)
			u_line("^cRInvalid material '" + mat + "'.^c0");
		else
			mats[mat] = amt;
		if (i == 2)
			break;
	}
	
	amt = 0;
	for (i = 0; i < sizeof(values(mats)); i++)
		amt += values(mats)[i];
	
	if (amt != 100)
	{
		u_line("^cCAmount of material(s) doesn't equal 100%^c0");
		mats = ([]);
	}
	i_materials = mats;
	
	disp_attrmenu();
}
		
process_get()
{
	if (lower_case(str[0..0]) == "y")
		i_no_get = 1;
	else
		i_no_get = 0;
	disp_attrmenu();
}


input_str_hook(string str)
{
	set(hook_var, str);
	call_other(THOB, hook_call);
}

input_int_hook(int i)
{
	if (stringp(i))
		sscanf(i, "%d", i);
	set(hook_var, i);
	call_other(THOB, hook_call);
}

input_array_hook(string str)
{
	if (str != ".")
	{
		set(hook_var, query(hook_var) + ({ str }));
		u_prompt((sizeof(query(hook_var)) + 1) + "> ");
		input_to("input_array_hook");
	}
	else
		call_other(THOB, hook_call);
}

input_text_hook(string str)
{
	if (str != ".")
	{
		while (str[<1..<1] == " ")
			str = str[0..<2];
		set(hook_var, query(hook_var) + str + " ");
		u_prompt((sizeof(explode(query(hook_var), "\n")) + 1) + "> ");
		input_to("input_text_hook");
	}
	else
	{
		set(hook_var, query(hook_var)[0..<2]);
		call_other(THOB, hook_call);
	}
}
	
	
string dump_mapping(mapping m)
{
	int i;
	string s;
	
	if (!m || m == ([]))
		return "([ ])";
	
	s = "";

	for (i = 0; i < sizeof(keys(m)); i++)
		s += "\"" + keys(m)[i] + "\" : " + values(m)[i] + ", ";
	s = "([ " + s[0..<3] + " ])";
	return s;
}

// void save_item()
//                                saves item data into a file
				  
void save_item()
{
	string str;

	write("Saving ..\n");
	
	str = 
		"/////        file           /" + item + "\n" +
		"////  description           Generic item created using Iedit " + VERSION + "\n" +
		"/// last modified           " + ctime(time())[4..15] + " by " + THIS->query_cap_name() + "\n" +
		"//\n" +
		"\n" +
		"inherit ITEM;\n" +
		"\n" +
		"create_item()\n" +
		"{\n" +
		"    set_name(({\"" + i_name + (sizeof(i_aliases) ? "\", \"" + implode(i_aliases, "\", \"") : "") + "\"}));\n" +
		"    set_short(\"" + i_short + "\");\n" +
		"    set_long(\"" + i_long + "\\n\");\n" +
		"\n" +
		(i_taste ? "    set_taste(\"" + i_taste + "\");\n" : "") +
		(i_smell ? "    set_smell(\"" + i_smell + "\");\n" : "") +
		(i_listen ? "    set_listen(\"" + i_listen + "\");\n" : "") +
		"\n" +
		(i_xdim || i_ydim || i_zdim ? "    set_dimensions(" + i_xdim + ", " + i_ydim + ", " + i_zdim + ");\n" : "") +
		(i_weight ? "    set_weight(" + i_weight + ");\n" : "") +
		((dump_mapping(i_materials) != "([  ])") ? "    set_material(" + dump_mapping(i_materials) + ");\n" : "") +
		(i_light ? "    set_light(" + i_light + ");\n" : "") +
		(i_no_get ? "    set_no_get();\n" : "") +
		(i_hp != 0 ? "    set_hp(" + i_hp + ");\n" : "") +
		(i_max_hp != 0 ? "    set_max_hp(" + i_max_hp + ");\n" : "") +
		"}\n" + 
		"\n" +
		"string query_author()\n" +
		"{\n" +
		"    return \"" + THIS->query_name() + "\";\n" +
		"}\n" +
		"\n" +
		"// IF YOU MANUALLY ADD YOUR OWN CODE TO THIS FILE, REMOVE THIS FUNCTION !!\n" +
		"string query_iedit()\n" +
		"{\n" +
		"    return \"" + VERSION + "\";\n" +
		"}\n" +
		"\n";
	
	rm(item);
	write_file(item, str);

	/* compile object */	
	if (find_object(item))
		destruct(find_object(item));
	call_other(item, "???");
	
}


		
				  
				  
				  
				  


				  
				  
	
