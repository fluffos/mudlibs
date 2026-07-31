// Room: /u/xiaozhen/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "тс╩Уфл");
	set("long", @LONG
уБйгр╩╪рп║п║╣дтс╩Уфлё╛сисз╣ь╢╕╧ьдзмБ╣д╫╩╫Г╢╕ё╛иЗрБ╣╫
╨эпкб║ё╛╢СоДп║оД╤яакр╩╣ьё╛╦Вжж╩УнОс╕сп╬║сп║ёсисзюо╟Ехкт╣
╨э╨цё╛песЧв©жЬё╛п║п║╣д╣Йфл╬╧ЁиакдзмБ╩УнО╣д╪╞и╒╣ь║ёуф╧Я╣д
юаяСяС╣ьлитзр╩ж╩лирниоё╛п║╩О╪фуп╨Твею╢мЫ╣д©мхк║ёх
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/seller" : 1
]));
	setup();
	replace_program(ROOM);
}
