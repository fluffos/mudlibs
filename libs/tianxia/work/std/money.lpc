// money.c
// by Find.

inherit COMBINED_ITEM;

#ifdef WIZARD_FLAG
void set_amount(int v)
{
	if(previous_object()
	&& sscanf(file_name(previous_object()),"/wiz/%*s")
	&& !query_wiz_flag())
		return;
	else
		return ::set_amount(v);
}
#endif
