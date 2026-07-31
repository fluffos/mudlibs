// file.c
#include <ansi.h>
#include <zjmud.h>

void cat(string file)
{
	if (previous_object())
		seteuid(geteuid(previous_object()));
	else
		seteuid(ROOT_UID);
	write(read_file(file));
}
void assure_file(string file)
{
	string path, *dir;
	int i;

	if (file_size(file) != -1) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");

	if (file[strlen(file) - 1] != '/')
		// the file is refer to a file, not directory
		dir = dir[0..sizeof(dir)-2];

	path = "/";
	for (i = 0; i < sizeof(dir); i++)
	{
		path += dir[i];
		mkdir(path);
		path += "/";
	}

	dir = 0;
}

void log_file(string file, string text)
{
	seteuid(ROOT_UID);
	assure_file(LOG_DIR + file);
	write_file(LOG_DIR + file, text);
}

void log_ufile(object me, string file, string text)
{
	seteuid(ROOT_UID);
	assure_file(LOG_DIR + file);
	write_file(LOG_DIR + file, CHINESE_D->chinese_date(time(),1)+":"+me->query("name")+"("+me->query("id")+")"+text);
}


string base_name(object ob)
{
	string file;

	if (sscanf(file_name(ob), "%s#%*d", file) == 2)
		return file;
	else
		return file_name(ob);
}

string color_filter(string content)
{
	if (! content)
		return "";

	// Foreground color
	content = replace_string(content, "$BLK$", BLK);
	content = replace_string(content, "$RED$", RED);
	content = replace_string(content, "$GRN$", GRN);
	content = replace_string(content, "$YEL$", YEL);
	content = replace_string(content, "$BLU$", BLU);
	content = replace_string(content, "$MAG$", MAG);
	content = replace_string(content, "$CYN$", CYN);
	content = replace_string(content, "$WHT$", WHT);
	content = replace_string(content, "$HIR$", HIR);
	content = replace_string(content, "$HIG$", HIG);
	content = replace_string(content, "$HIY$", HIY);
	content = replace_string(content, "$HIB$", HIB);
	content = replace_string(content, "$HIM$", HIM);
	content = replace_string(content, "$HIC$", HIC);
	content = replace_string(content, "$HIW$", HIW);
	content = replace_string(content, "$NOR$", NOR);

	// Background color
	content = replace_string(content, "$BBLK$", BBLK);
	content = replace_string(content, "$BRED$", BRED);
	content = replace_string(content, "$BGRN$", BGRN);
	content = replace_string(content, "$BYEL$", BYEL);
	content = replace_string(content, "$BBLU$", BBLU);
	content = replace_string(content, "$BMAG$", BMAG);
	content = replace_string(content, "$BCYN$", BCYN);
	content = replace_string(content, "$HBRED$", HBRED);
	content = replace_string(content, "$HBGRN$", HBGRN);
	content = replace_string(content, "$HBYEL$", HBYEL);
	content = replace_string(content, "$HBBLU$", HBBLU);
	content = replace_string(content, "$HBMAG$", HBMAG);
	content = replace_string(content, "$HBCYN$", HBCYN);
	content = replace_string(content, "$ZJOBLONG$", ZJOBLONG);
	content = replace_string(content, "$ZJOBACTS$", ZJOBACTS);
	content = replace_string(content, "$ZJOBACTS2$", ZJOBACTS2);

	content = replace_string(content, "$U$", U);
	content = replace_string(content, "$BLINK$", BLINK);
	content = replace_string(content, "$REV$", REV);
	content = replace_string(content, "$HIREV$", HIREV);
	content = replace_string(content, "$BOLD$", BOLD);

	return content;
}

// filter color
string no_color(string arg)
{
        if ( !arg ) return "";

        arg = replace_string(arg, BLK, "");
        arg = replace_string(arg, RED, "");
        arg = replace_string(arg, GRN, "");
        arg = replace_string(arg, YEL, "");
        arg = replace_string(arg, BLU, "");
        arg = replace_string(arg, MAG, "");
        arg = replace_string(arg, CYN, "");
        arg = replace_string(arg, WHT, "");
        arg = replace_string(arg, HIR, "");
        arg = replace_string(arg, HIG, "");
        arg = replace_string(arg, HIY, "");
        arg = replace_string(arg, HIB, "");
        arg = replace_string(arg, HIM, "");
        arg = replace_string(arg, HIC, "");
        arg = replace_string(arg, HIW, "");
        arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BOLD, "");
        arg = replace_string(arg, BLINK, "");
        return arg;
//#endif
}

void color_cat(string file)
{
	if (previous_object())
		seteuid(geteuid(previous_object()));
	else
		seteuid(ROOT_UID);

	write(color_filter(read_file(file)));
}

int file_lines(string file)
{
#ifdef DOING_IMPROVED
	return efun::file_lines(file);
#else
	int i;
	int jmp;

	i = 65536;
	jmp = i / 2;

	while (jmp)
	{
		if (read_file(file, i, 1)) i += jmp; else
					   i -= jmp;
		jmp /= 2;
	}

	return i - 1;
#endif
}
