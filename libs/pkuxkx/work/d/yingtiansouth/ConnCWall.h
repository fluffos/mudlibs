int valid_leave(object me,string dir)
{
	if (query("exits/"+dir)&&load_object(query("exits/"+dir))&&load_object(query("exits/"+dir))->query("is_CityWall"))
	return notify_fail("城墙不许随便攀爬。\n");
	return ::valid_leave(me,dir);
}
