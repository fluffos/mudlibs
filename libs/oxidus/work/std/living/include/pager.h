#ifndef __PAGER_H__
#define __PAGER_H__

protected varargs void page(mixed text, mixed *cb, int no_colour);
protected void continue_page(string input, string *text, mixed *cb, int no_colour, int more_lines, string page_display, int num, int curr);

#endif // __PAGER_H__
