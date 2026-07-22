inherit F_DBASE;
inherit F_SAVE;
inherit F_CLEAN_UP;

string filename;

string query_save_file()
{
        return filename;
}

int main(object me, string arg)
{
        mapping *notes;
        string *file;
        int num, i, j, k, l, m;

        file = get_dir("/data/board/");
        i = sizeof(file);
        if (!i) return 0;
	if (arg) {
		sscanf(arg, "%d", num);
		num--;
		if (num < 0 || num >= i)
			return notify_fail("没有这个留言板。\n");
		return me->force_me("goto "
			+ ("/clone/board/"
			+ file[num][0..<3])->query("location"));
	}
        for (j = 0;j < i;j++) {
                filename = resolve_path("/data/board/", file[j]);
                if (!restore()) return notify_fail("没有这个文件。\n");
                notes = query("notes");
		k = me->query("board_last_read/" + query("board_id"));
		for (l = 0, m = sizeof(notes) - 1; m>=0; m--, l++)
			if (notes[m]["time"] <= k) break;
                write(j+1 + ". " + query("name"));
		if (sizeof(notes))
			write("共有" + chinese_number(sizeof(notes)) + "条留言");
		else write("没有留言");
		if (l) write("，" + chinese_number(l) + "张未读");
		write("。\n");
        }
	write("用 board xx 去看你想看的留言板。\n");
        return 1;
}
