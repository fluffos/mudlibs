// edit.c
#include <ansi.h>

int edit(function callback)
{
    write("结束离开用 'x'，取消输入用 'q'，使用内建列编辑器用 'e'。\n");
    write( DASH_LINE_LF );
    input_to("input_line", "", callback);
    return 1;
}

void input_line(string line, string text, function callback)
{
    if( line=="x" ) {
	(*callback)(text);
	return;
    } else if( line=="q" ) {
	write("输入取消。\n");
	return;
    } else if( line=="e" ) {
    } else
	text += line + "\n";
    input_to("input_line", text, callback);
}
