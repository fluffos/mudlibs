/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** more_ob.c
**
** Standard object for providing "more" type functionality.
**
** Originally written by Justice, I believe.
**
** Converted to the new modal input system by Deathblade on 8/16/94.
** Big rewrite and cleanup.
** Beek added ANSI support
** Rust made it check your shell's MORE variable
** Rust added more_lines(lines, chunksize) for intentionally small more's.
*/

#include <mudlib.h>
#include <more.h>

inherit M_INPUT;
inherit M_ACCESS;

private string current_search;
private string last_search;
private int direction;
private string * file_list;
private int file_index;
private string * lines;
private int line_index;
private int chunk_size;
private function continue_func;
private int output_flags;

private nomask string query_prompt()
{
    string prompt = "";
    int last = line_index + chunk_size;
    int percent;
    
    if (last > sizeof(lines)) {
    last = sizeof(lines);
    percent = 100;
    } else {
    percent = last*100/sizeof(lines);
    }
    
    if (file_list && file_index < sizeof(file_list) && wizardp(this_user()))
    prompt = "\"" + file_list[file_index] + "\" ";
    prompt += sprintf("(%i-%i %i%%) [h]:", line_index + 1, last, percent);

    return "%^MORE%^" + prompt + "%^RESET%^";
}

/* returns 1 if no more files are available */
private int next_file()
{
    file_index += direction;
    if ( file_index < 0 || file_index >= sizeof(file_list) )
        return 1;

    if (direction == -1)
    printf("more: going back to file \"%s\"\n", file_list[file_index]);
    else
    printf("more: going on to file \"%s\"\n", file_list[file_index]);
    lines = 0;
    return 0;
}

private void print_help()
{
        write(
          "More 的帮助文件：\n\n"
          "    a : 重新显示当前页。\n"
          "    / : /<字符串>，正向搜索字符串。\n"
          "  h,? : 本帮助。或 ?<字符串>，逆向搜索字符串。\n"
          "    d : 切换显示方向。(正向或逆向)、\n"
          "    b : 回到文件开头。\n"
          "    e : 显示文件末尾。\n"
          "    n : 显示在现行显示方向中的下一个文件，如果有的话。\n"
          "    q : 退出。\n"
          "    s : s <字符串>，设定或取消搜索的字符串。\n"
          "\n"
          "回车或其他字符则进入下一页。\n");

}

private void finish()
{
    modal_pop();

    if ( continue_func )
    evaluate(continue_func);

    destruct(this_object());
}

private nomask void do_more(mixed arg) {
    int x;
    string tmp;

    if (arg == -1)
      destruct(this_object());
    if (arg)
    switch(arg[0]) {
    case '?':
        current_search = arg[1..];

        if (current_search != "") {
        direction = -1;
        last_search = current_search;
        break;
        }
        if (last_search) {
        current_search = last_search;
        direction = -1;
        line_index += chunk_size * direction;
        if (line_index < 0 || line_index >= sizeof(lines)) {
                 if ( next_file()) {
            finish();
            return;
            }
        }
        break;
        }
        //write("more: illegal syntax, type \"h\" for help.\n");
        write("用法错误，用 h 来取得帮助。\n");
        return;
    case 'h':
        print_help();
        return;
    case 's':                           // Set search string
        if (arg != "s") {
        current_search = arg[1..];
        //write("more: search set to \"" + current_search + "\"\n");
        write("more: 设定查找字符串为：" + current_search + "\n");
        } else {
        current_search = 0;
        //write("more: search off\n");
        write("more: 关闭查找。\n");
        }
        return;
    case '/':
        current_search = arg[1..];
        if (current_search != "") {
        direction = 1;
        last_search = current_search;
        break;
        }
        if (last_search) {
        current_search = last_search;
        direction = 1;
        line_index += chunk_size * direction;
        if (line_index < 0 || line_index >= sizeof(lines)) {
            if ( next_file() ) {
            finish();
            return;
            }
        }
        break;
        }
        //write("more: illegal syntax, type \"h\" for help.\n");
        write("用法错误，用 h 来取得帮助。\n");
        return;
    case 'd':                           // Toggle Direction
        direction = -direction;
        write(//"more: now scanning " +
                  "more: 现在显示方向为：" +
                  (direction == 1 ? //"forward" : "backward"
                                    "正向" : "逆向") + "\n");
        return;
    case 'n':                           // Next file if any
        if (sizeof(file_list) > 1)
        file_index += direction;
             if (!sizeof(file_list))
            {
                finish();
                return;
            }
        if (file_index < 0 || file_index >= sizeof(file_list)) {
            write(//"more: no more files "
                      "more: 没有文件在" +file_list[file_index - 1]
                      + (direction  == 1 ? //"after" : "preceding"
                      "之后" : "之前")
                        + "\n");
            file_index -= direction;
            return;
        }
        else
            lines = 0;
        break;
    case 'q':
        finish();
        return;
    case 'b':
        line_index = 0;
        break;
    case 'e':
        line_index = (sizeof(lines) - chunk_size >= 0 ?
              sizeof(lines) - chunk_size : 0);
        break;
    case 'a':
        break;
    default:                            // Next chunk
        if (last_search)
        current_search = 0;
        line_index += chunk_size * direction;
        if (line_index < 0 || line_index >= sizeof(lines)) {
        if ( next_file() )
            {
            finish();
            return;
            }
        }
        break;
    }
    while(1) {
    if (!lines) {
            string contents;

        if (!file_list || !sizeof(file_list))
        break;
        if(wizardp(this_user()))
        write("filename: "+file_list[file_index]+"\n");
        if (file_size(file_list[file_index]) == -1) {
             write(//"more: no such file "
                      "more: 无此文件：" + file_list[file_index] + "\n");
                if ( next_file() )
                    break;
        continue;
        }
            contents = read_file(file_list[file_index]);
            if ( !contents || !sizeof(lines = explode(contents, "\n")) )
            {
             write("more: 文件为空：" + file_list[file_index]);
                if ( next_file() )
                    break;
        continue;
        }
        if (direction == -1)
        line_index = (sizeof(lines) - chunk_size >= 0 ?
          sizeof(lines) - chunk_size : 0);
        else
        line_index = 0;
    }
    if (current_search) {
        for(;line_index < sizeof(lines) && line_index >= 0;
          line_index += direction)
        if (regexp(lines[line_index], current_search))
            break;
        if (line_index < 0 || line_index >= sizeof(lines)) {
            write("more: " + current_search + //" not found in "
                      (file_list ? "在文件 " + file_list[file_index] 
                        + " 中" : "")+ "找不到。\n");
                if ( next_file() )
                {
                    /* oops. not found. back up and get some input. */
                    file_index -= direction;
                    return;
                }

                /* refill the list of lines */
                continue;
        }
    }
    for(x = line_index;x < sizeof(lines) && x < line_index + chunk_size; x++)
        tell(this_user(), lines[x] + "\n", output_flags);
      if (x < sizeof(lines) || (file_list && sizeof(file_list) > 1))
      {
        /* return to prompt about more lines/next file */
        return;
      }

    /* break: we're done, so finish up */
    break;
    }

    finish();
    return;
}

void create(int kind, mixed arg, int c, function continuation,
        int of) {
    set_privilege(1);

    switch (kind) {
    case 0: // blueprint
    return;
    case MORE_FILES:
    file_list = arg;
    file_index = 0;
    break;
    case MORE_LINES:
    lines = arg;
    break;
    default:
    error("Bad argument 2 to new(MORE_OB, ...)\n");
    }
    direction = 1;
    chunk_size = c;
    continue_func = continuation;
    output_flags = of;
    modal_push((: do_more :), (: query_prompt :));
    if (catch(do_more(0))) modal_pop();
}
